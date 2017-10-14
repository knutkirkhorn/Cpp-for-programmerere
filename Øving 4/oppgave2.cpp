#include <gtkmm.h>


class Window : public Gtk::Window {
public:
  Gtk::VBox vbox;
  Gtk::Entry entryFirstname;
  Gtk::Entry entryLastname;
  Gtk::Button button;
  Gtk::Label label;
  Gtk::Label labelFirstname;
  Gtk::Label labelLastname;
  
  void checkUserInput() {
    if (entryFirstname.get_text() == "" || entryLastname.get_text() == "") {
      button.set_sensitive(false);
      return;
    }
    button.set_sensitive(true);
  }
  
  Window() {
    labelFirstname.set_text("First name");
    labelLastname.set_text("Last name");
    button.set_label("Combine names");
    button.set_sensitive(false);
    
    vbox.pack_start(labelFirstname);
    vbox.pack_start(entryFirstname);
    vbox.pack_start(labelLastname);
    vbox.pack_start(entryLastname);
    vbox.pack_start(button);
    vbox.pack_start(label);
    
    add(vbox);
    show_all();
    
    entryFirstname.signal_changed().connect([this]() {
      checkUserInput();
    });
    
    entryLastname.signal_changed().connect([this]() {
      checkUserInput();
    });
    
    button.signal_clicked().connect([this]() {
      label.set_text("Names combined: " + entryFirstname.get_text() + " " + entryLastname.get_text());
    });
  }
};

int main() {
  Gtk::Main gtk_main;
  Window window;
  window.set_title("Øving 4 - Oppgave 2");
  gtk_main.run(window);
}