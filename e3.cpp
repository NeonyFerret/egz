/*
   Dala jest lista utworów muzycznych zapisana w tablicy,
   której elementy maj¹ strukturê: tytu³, autor,
   czas trwania utworu w sekundach. Napisz program,
   który wypisze najd³u¿sze i najkrótsze utwory oraz te,
   których czas s³uchania przekracza 10 minut.
   U¿yj funkcji.
*/

#include < iostream >
using namespace std;
struct mp3 {
  char tytul[50];
  char autor[50];
  int czas;
};
void wpr(int n, mp3 cd[]) {
  for (int i = 0; i < n; i++) {
    cout << "MP3 nr." << i << endl << "Tytul (bez spacji)= ";
    cin >> cd[i].tytul;
    cout << "Autor (bez spacji)= ";
    cin >> cd[i].autor;
    cout << "Czas trwania w sekundach = ";
    cin >> cd[i].czas;
  }
}
void najd(int n, mp3 cd[]) {
  int cz = 0;
  for (int i = 0; i < n; i++) {
    if (cz <= cd[i].czas) {
      cz = cd[i].czas;
    }
  }
  cout << "Najdluzsze utwory trwaja " << cz << endl;
  for (int i = 0; i < n; i++) {
    if (cz == cd[i].czas) cout << cd[i].tytul << " (" << cd[i].autor << ")" << endl;
  }
}
void najk(int n, mp3 cd[]) {
  int cz = cd[0].czas;
  for (int i = 1; i < n; i++) {
    if (cz >= cd[i].czas) {
      cz = cd[i].czas;
    }
  }
  cout << "Najkrotsze utwory trwaja " << cz << endl;
  for (int i = 0; i < n; i++) {
    if (cz == cd[i].czas) cout << cd[i].tytul << " (" << cd[i].autor << ")" << endl;
  }
}
void naj10(int n, mp3 cd[]) {
  cout << "Utwory trwajace ponad 10min" << endl;
  for (int i = 0; i < n; i++) {
    if (cd[i].czas > 600) cout << cd[i].tytul << " (" << cd[i].autor << ")" << endl;
  }
}
main() {
  int n;
  cout << "Ile utworow wprowadzic = ";
  cin >> n;
  mp3 cd[n];
  wpr(n, cd);
  najd(n, cd);
  najk(n, cd);
  naj10(n, cd);
}
