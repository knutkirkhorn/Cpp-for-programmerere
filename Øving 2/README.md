# Øving 2

## Teorioppgaver
### Oppgave 2
Når man kjører koden:
```
char *linje = nullptr;   // eller char *linje = 0;
strcpy(linje, "Dette er en tekst");
```
vil man få feilmelding om at man prøver å få tilgang til en adresse som ikke har noen verdi.


### Oppgave 3
Ved følgende kode:
```
char tekst[5];
char *pekeren = tekst;
char letEtter = 'e';
cin >> tekst;
while (*pekeren != letEtter) {
    *pekeren = letEtter;
    pekeren++;
}
```
så kan det oppså feil ved at man skriver inn en tekst som er større enn det tabellen er satt av plass til.
Man vil få segmentfeil.
