#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

class ChessBoard {
public:
  enum class Color { WHITE,
                     BLACK };

  class Piece {
  public:
    Piece(Color color) : color(color) {}
    virtual ~Piece() {}

    Color color;
    std::string color_string() const {
      if (color == Color::WHITE)
        return "white";
      else
        return "black";
    }

    /// Return color and type of the chess piece
    virtual std::string type() const = 0;

    /// Returns true if the given chess piece move is valid
    virtual bool valid_move(int from_x, int from_y, int to_x, int to_y) const = 0;
    
    virtual std::string get_mini_char() const = 0;
  };

  class King : public Piece {
  public:
    King(Color color): Piece(color) {}
    
    std::string type() const override {
      return color_string() + " king";
    }
    
    bool valid_move(int from_x, int from_y, int to_x, int to_y) const override {
      int length_x = from_x - to_x; //4->2 = 2, 2->4 = -2
      int length_y = from_y - to_y;
      
      if (length_x > 1 ||  length_x < -1 || length_y > 1 || length_y < -1) {
        return false;
      }
      return true;
    }
    
    std::string get_mini_char() const override {
      if (color == Color::WHITE)
        return "♔";
      else
        return "♚";
    }
  };

  class Knight : public Piece {
  public:
    Knight(Color color): Piece(color) {}
    
    std::string type() const override {
      return color_string() + " knight";
    }
    
    bool valid_move(int from_x, int from_y, int to_x, int to_y) const override {
      int possible_moves[8][2]  = {{from_x-2, from_y+1}, {from_x-1, from_y+2},
                                   {from_x+1, from_y+2}, {from_x+2, from_y+1},
                                   {from_x-2, from_y-1}, {from_x-1, from_y-2},
                                   {from_x+1, from_y-2}, {from_x+2, from_y-1}};
      for (int i = 0; i < 8; i++) {
        if (to_x == possible_moves[i][0] && to_y == possible_moves[i][1]) {
          return true;
        }
      }
      return false;
    }
    
    std::string get_mini_char() const override {
      if (color == Color::WHITE) {
        return "♘";
      } else {
        return "♞";
      }
    }
  };

  ChessBoard() {
    // Initialize the squares stored in 8 columns and 8 rows:
    squares.resize(8);
    for (auto &square_column : squares)
      square_column.resize(8);
  }
  
  function<void(const vector<vector<unique_ptr<ChessBoard::Piece>>> &squares)> after_piece_move;
  function<void(const Piece &piece, const string &from, const string &to)> on_piece_move;
  function<void(const Piece &piece, const string &square)> on_piece_removed;
  function<void(Color color)> on_lost_game;
  function<void(const Piece &piece, const string &from, const string &to)> on_piece_move_invalid;
  function<void(const string &square)> on_piece_move_missing;

  /// 8x8 squares occupied by 1 or 0 chess pieces
  vector<vector<unique_ptr<Piece>>> squares;

  /// Move a chess piece if it is a valid move
  bool move_piece(const std::string &from, const std::string &to) {
    int from_x = from.at(0) - 'a';
    int from_y = stoi(string() + from.at(1)) - 1;
    int to_x = to.at(0) - 'a';
    int to_y = stoi(string() + to.at(1)) - 1;

    auto &piece = squares.at(from_x).at(from_y);
    if (piece) {
      if (piece->valid_move(from_x, from_y, to_x, to_y)) {
        on_piece_move(*piece, from, to);
        
        auto &piece_at_to_pos = squares.at(to_x).at(to_y);
        if (piece_at_to_pos) {
          if (piece->color != piece_at_to_pos->color) {
            on_piece_removed(*piece_at_to_pos, to);
            if (auto king = dynamic_cast<King *>(piece_at_to_pos.get()))
              on_lost_game(king->color);
          } else {
            // piece in the from square has the same color as the piece in the to square
            on_piece_move_invalid(*piece, from, to);
            return false;
          }
        }
        piece_at_to_pos = move(piece);
        after_piece_move(squares);
        return true;
      } else {
        on_piece_move_invalid(*piece, from, to);
        return false;
      }
    } else {
      on_piece_move_missing(from);
      return false;
    }
  }
};

class ChessBoardPrint {
public:
  ChessBoardPrint(ChessBoard &board) {    
    board.after_piece_move = [](const vector<vector<unique_ptr<ChessBoard::Piece>>> &squares) {
      for (size_t i = squares.size()-1; i > 0; i--) {
        cout << "[" << (i+1) << "] ";
        for (size_t j = 0; j < squares.at(i).size(); j++) {
          
          // Check if there is any pieces at the current position
          if (!squares.at(j).at(i)) {
            cout << "- ";
          } else {
            auto &piece = squares.at(j).at(i);
            cout << piece->get_mini_char() << " ";
          }
        }
        cout << endl;
      }
      cout << "   " << " A|B|C|D|E|F|G|H" << endl << endl;
    };
    
    board.on_piece_move = [](const ChessBoard::Piece &piece, const string &from, const string &to) {
      cout << piece.type() << " is moving from " << from << " to " << to << endl;
    };
    
    board.on_piece_removed = [](const ChessBoard::Piece &piece, const string &square) {
      cout << piece.type() << " is being removed from " << square << endl;
    };
    
    board.on_lost_game = [](ChessBoard::Color color) {
      if (color == ChessBoard::Color::BLACK) {
        cout << "Black";
      } else {
        cout << "White";
      }
      cout << " lost the game" << endl;
    };
    
    board.on_piece_move_invalid = [](const ChessBoard::Piece &piece, const string &from, const string &to) {
      cout << "can not move " << piece.type() << " from " << from << " to " << to << endl;
    };
    
    board.on_piece_move_missing = [](const string &square) {
      cout << "no piece at " << square << endl;
    };
  }
};

int main() {
  ChessBoard board;
  ChessBoardPrint print(board);

  //board.squares.at(4).at(0) is the same as board.squares[4][0] but with range check
  board.squares.at(4).at(0) = make_unique<ChessBoard::King>(ChessBoard::Color::WHITE);
  board.squares.at(1).at(0) = make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);
  board.squares.at(6).at(0) = make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);

  board.squares.at(4).at(7) = make_unique<ChessBoard::King>(ChessBoard::Color::BLACK);
  board.squares.at(1).at(7) = make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);
  board.squares.at(6).at(7) = make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);

  cout << "Invalid moves:" << endl;
  board.move_piece("e3", "e2");
  board.move_piece("e1", "e3");
  board.move_piece("b1", "b2");
  cout << endl;

  cout << "A simulated game:" << endl;
  board.move_piece("e1", "e2");
  board.move_piece("g8", "h6");
  board.move_piece("b1", "c3");
  board.move_piece("h6", "g8");
  board.move_piece("c3", "d5");
  board.move_piece("g8", "h6");
  board.move_piece("d5", "f6");
  board.move_piece("h6", "g8");
  board.move_piece("f6", "e8");
}
