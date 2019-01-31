/*
   Do pewnego wi�kszego zadania potrzebujemy przetwarzania danych dotycz�cych miast.
   Dane s� zapisane w pliku. O miastach mamy dane: nazw� i wsp�rz�dne na mapie.
   Napisz program, kt�ry znajdzie miasta najbardziej odleg�e i najbli�sze siebie.
   Ponadto dla danego miasta, kt�rego nazwa jest wczytana klawiatury znajd� miasto
   najbli�ej le��ce i najdalej.
*/

#include < iostream >
#include < cmath >
#include < string >
#include < cstring >
#include < fstream >
using namespace std;
struct miasto {
  char n[20];
  float x;
  float y;
};
main() {
  ifstream p;
  string q;
  int n = 0;
  p.open("e4.txt");
  if (p.good()) {
    while (!p.eof()) {
      getline(p, q);
      n++;
    }
  }
  p.seekg(0);
  miasto m[n];
  for (int i = 0; i < n; i++) p >> m[i].n >> m[i].x >> m[i].y;
  p.close();
  float najb, najd = 0, odl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      else {
        odl = sqrt(pow((m[j].x - m[i].x), 2) + pow((m[j].y - m[i].y), 2));
        if (i == 0 && j == 1) najb = odl;
        else if (odl <= najb) najb = odl;
        if (odl >= najd) najd = odl;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      else {
        odl = sqrt(pow((m[j].x - m[i].x), 2) + pow((m[j].y - m[i].y), 2));
        if (odl == najb) cout << "Najblizej leza " << m[i].n << " i " << m[j].n << endl;
        if (odl == najd) cout << "Najdalej leza " << m[i].n << " i " << m[j].n << endl;
      }
    }
  }
  char sz[20];
  cout << endl << "Do jakiego miasta szukac = ";
  cin >> sz;
  najd = 0;
  for (int i = 0; i < n; i++) {
    if (strcmp(m[i].n, sz) == 0) {
      for (int j = 0; j < n; j++) {
        if (i == j) continue;
        else {
          odl = sqrt(pow((m[j].x - m[i].x), 2) + pow((m[j].y - m[i].y), 2));
          if (j == 0 || j == 1) najb = odl;
          else if (odl <= najb) najb = odl;
          if (odl >= najd) najd = odl;
        }
      }
      for (int j = 0; j < n; j++) {
        if (i == j) continue;
        else {
          odl = sqrt(pow((m[j].x - m[i].x), 2) + pow((m[j].y - m[i].y), 2));
          if (odl == najb) cout << "Najblizej leza " << m[j].n << endl;
          if (odl == najd) cout << "Najdalej leza " << m[j].n << endl;
        }
      }
    }
  }
}
