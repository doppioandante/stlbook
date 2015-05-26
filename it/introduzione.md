## Cos'è la STL
La STL fa parte della libreria standard del C++ già a partire dalla prima
standardizzazione (1998) e raccoglie strutture dati implementate come _classi
template_ (da cui il nome).<br>
Come vedremo in seguito, la STL offre al programmatore una serie di _container_, che
rappresentano le strutture dati astratte, su cui è possibile lavorare con
un'interfaccia uniforme attraverso gli _iterator_; molti degli algoritmi
principali sono già offerti da `<algorithm>`.

## Quali vantaggi ci sono ad utilizzare la STL?
Ogni programmatore C++ dovrebbe conoscere a fondo ciò che offre la libreria
standard, e in particolare la STL: le buone performance e l'elevata genericità
la rendono utile per la maggior parte degli utilizzi; inoltre il design a cui
si ispira viene fortemente ripreso da altre librerie fondamentali come
[Boost](http://www.boost.org/).

Rispetto al C puro, la presenza della STL permette al C++ di raggiungere
livelli di espressività molto simili a concorrenti decisamente più _high level_:

* I template e l'operator overloading permettono di astrarre facilmente la
  struttura dati rispetto al tipo di dato trattato: non è necessario, come in C,
  ricorrere a `void*`
* La memoria viene gestita automaticamente dalle classi container: si evitano così
  alcuni errori comuni della gestione della memoria dinamica del C
* Non è necessario dover reimplementare ogni volta strutture come array dinamici
  o associativi, risparmiando tempo nella scrittura del codice.

Vediamo un esempio pratico: supponiamo di voler leggere un array di numeri
da stdin e di volerlo stampare con ordinamento decrescente.

In C si potrebbe procedere così:
```c
!INCLUDE "../code/list1.c"
```

A confronto, lo stesso codice in C++:
```c++
!INCLUDE "../code/list2.cpp"
```

Non è necessario capire a fondo i due codici per ora, ma confrontandoli
possiamo osservare le seguenti cose:

* Non c'è bisogno di gestire il ridimensionamento di list, perché vector ci pensa
  al posto nostro; inoltre la memoria viene liberata all'uscita dallo scope
  grazie al distruttore e il programmatore non ha la possibilità di dimenticarsi
  un `free()`
* Non sono necessari cast di puntatori `void*` generici
* Il codice potrebbe essere ridefinito con pochi cambiamenti in modo da lavorare
  con tipi che non siano interi, o addirittura con tipi generici
* I metodi `begin()` e `end()` segnalano l'utilizzo degli iteratori; al posto
  di un ciclo, per la stampa, è stato usato un [ostream_iterator](<http://www.cplusplus.com/reference/iterator/ostream_iterator/),
  che permette di operare in modo uniforme anche sullo standard output
* L'utilizzo del funtore `greater<T>`, contenuto in `<functional>` ci ha permesso
  di non dover definire la nostra funzione di comparazione; in C++11 si sarebbe
  anche potuta usare una lambda

Notiamo infine che sebbene il codice in C++ sia più corto, è di certo più complesso,
poiché più generale; in questo  esempio sarebbe bastata meno sofisticazione,
ma in altri casi questa potenza  espressiva permette soluzioni più pulite
e riusabilii.

