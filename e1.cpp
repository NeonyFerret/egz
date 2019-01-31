/*
   Dany jest ci�g liczb ca�kowitych zako�czony zerem.
   Napisz program, kt�ry wypisze te liczby, dla
   kt�rych suma kwadrat�w cyfr >= od iloczynu cyfr.
   Sum� kwadrat�w i iloczyny obliczaj za pomoc� funkcji.
   Komunikacja przez parametry.
*/
#include < iostream >
using namespace std;
int kw(int x) {
  int k = 0;
  if (x < 0) x = -x;
  while (x != 0) {
    k = k + (x % 10 * x % 10);
    x = (x - x % 10) / 10;
  }
  return k;
}
int il(int x) {
  int l = 1;
  if (x < 0) x = -x;
  while (x != 0) {
    l = l * (x % 10);
    x = (x - x % 10) / 10;
  }
  return l;
}
main() {
  int x;
  cout << "Podaj liczby ('0' aby zakonczyc)" << endl;
  cin >> x;
  while (x != 0) {
    if (kw(x) >= il(x)) cout << "W liczbie " << x << " suma kwadratow jej cyfr jest wieksza badz rowna iloczynowie jej cyfr!" << endl;
    cin >> x;
  }
}
