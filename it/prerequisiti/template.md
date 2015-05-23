## Perché i template?
I template nascono originariamente per risolvere un problema di riutilizzo del
codice: consideriamo il seguente esempio in C
```c
void swap(int* a, int* b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
}
```
Questa funzione altro non è che la funzione che scambia il contenuto di due
celle di memoria contenenti un dato di tipo int: il problema sorge proprio quando
questo tipo non è un intero, e sarebbe necessario in questo caso riscrivere una
funzione analoga ma con tipi diversi.

I template risolvono questo problema astraendo il tipo di dato:
```c++
template <class T> // oppure template <typename T>
void swap(T* a, T* b)
{
  T tmp = *a;
  *a = *b;
  *b = tmp;
}
```
Per ogni invocazione con diversi _parametri di template_, il compilatore genera
una nuova funzione che si dice _specializzata_; come vedremo dopo, questo
dettaglio ha delle conseguenze importanti.
```c++
int a = 3;
int b = 5;
swap<int>(&a, &b);

char c1 = 'b';
char c2 = 'z';
swap<char>(&c1, &c2);
```
> **Note** La funzione swap esiste effettivamente nella standard library, solo
> che i parametri sono dei reference: [std::swap](http://en.cppreference.com/w/cpp/algorithm/swap)

## Template di classi
Oltre che a funzioni generiche, è possibile ottenere tipi aggregati che siano
generici:
```c++
#include <iostream>

template <typename T>
class AccessCounter
{
private:
  int count;
  T variable;

public:
  AccessCounter(const T& value)
    variable(value),
    count(0)
  {}

  T& accessVariable()
  {
    count++;
    return variable;
  }

  int getCount() const
  {
    return count;
  }
};

int main()
{
  using namespace std;

  AccessCounter<int> ac(42);

  ac.accessVariable() = 43;
  ac.accessVariable();
  cout << ac.getCount() << endl; // output: 2
}
```

