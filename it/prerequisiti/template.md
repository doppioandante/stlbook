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
e il suo utilizzo:
```c++
int a = 3;
int b = 5;
swap<int>(&a, &b);

char c1 = 'b';
char c2 = 'z';
swap<char>(&c1, &c2);
```
Per ogni invocazione con diversi _parametri di template_, il compilatore genera
una nuova funzione che si dice _specializzata_; come vedremo dopo, questo
dettaglio ha delle conseguenze importanti.


