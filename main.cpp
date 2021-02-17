#include "Decorator.hpp"
#include <iostream>
#include <string.h>
#include <typeinfo>
using namespace std;

class IceCream : public Decorator {
private:
  string taste_m;
  Decorator *dec_m;
public:
  IceCream (string taste, Decorator *dec){
    dec_m = dec;
    taste_m = taste;
  }
  IceCream (string taste){
    dec_m = nullptr;
    taste_m = taste;
  }
  void Print (){
    cout << taste_m << " ";
    if(dec_m) dec_m->Print();
  }
};

class Tooping : public Decorator {
private:
  string ingredient_m;
  Decorator *dec_m;
public:
  Tooping (string ingredient, Decorator *dec){
    ingredient_m = ingredient;
    dec_m = dec;
  }
  Tooping (string ingredient){
    dec_m = nullptr;
    ingredient_m = ingredient;
  }
  void Print (){
    cout << ingredient_m << " toopinged ";
    if(dec_m) dec_m->Print();
  }
};

class Cone {
private:
  Decorator *dec_m;
public:
  Cone (Decorator *dec){ dec_m = dec; }
  void Print (){
    cout << "This is ";
    if(dec_m) dec_m->Print();
    else cout << "no " << endl;
    cout << "IceCream" << endl;
  }
};

int main(){
  Cone *c1 = new Cone(new IceCream("straeberry", new Tooping("CashwNut")));
  c1->Print();
  Cone *c2 = new Cone(new IceCream("straeberry", new IceCream("lemon", new IceCream("chocolate"))));
  c2->Print();

  return 0;
}
