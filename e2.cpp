/*
   Dana jest tablica kwadratowa NxM.
   Napisz program, który policzy stosunek
   sumy elementów zewnêtrznych (brzegowych)
   do sumy elementów wewnêtrznych.
   U¿yj funkcji. Komunikacja przez parametry.
*/

#include < iostream >
using namespace std;
void enter(int n, int m, int ** tab) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << "Tab[" << i << "][" << j << "] = ";
      cin >> tab[i][j];
    }
  }
}
float stosunek(int n, int m, int ** tab) {
  int sz = 0, sw = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (i == 0 || j == 0 || i == n - 1 || j == m - 1) sz += tab[i][j];
      else sw += tab[i][j];
    }
  }
  cout << "Zewnetrzne = " << sz << endl << "Wewnetrzne = " << sw << endl;
  return (float) sz / (float) sw;
}
main() {
  int n, m;
  cout << "Podaj wymiary tablicy" << endl << "N = ";
  cin >> n;
  cout << "M = ";
  cin >> m;
  int ** tab;
  tab = new int * [n];
  for (int i = 0; i < n; i++) tab[i] = new int[m];
  enter(n, m, tab);
  cout << "Stosunek = " << stosunek(n, m, tab);
  for (int i = 0; i < n; i++) delete[] tab[i];
  delete[] tab;
}
