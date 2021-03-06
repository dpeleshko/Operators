#include <iostream>
using namespace std;
#define CLASS(AA) AA(){ cout << " ctor "<<\
  #AA<<"()\n"; }\
  AA(int) { cout << "ctor"<<#AA<<"(int)\n"; }\
  virtual ~AA() { cout << "dtor"<<#AA<<"\n"; }

struct A { CLASS(A);
  void* operator new(size_t size) {
    cout << "memory allocation (A) \n";
    return malloc(size);
  }
  void operator delete(void* p) {
    cout << "memory free (A) \n";
    free(p);
  }
};

struct B : public A {
  CLASS(B);
  void* operator new(size_t size) {
    cout << "memory allocation (B) \n";
    return malloc(size);
  }
  void operator delete(void* p) {
    cout << "memory free  (B) \n";
    free(p);
  }
};

int main(void) {
  B* p = new B(5); // виклик перевантаж. опер.
  delete p; // виклик перевантаженого опер.
}
