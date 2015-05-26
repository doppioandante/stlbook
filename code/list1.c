#include <stdio.h>
#include <stdlib.h>

int decreasing_cmp(const void* a, const void* b)
{
  return *(int*)b - *(int*)a;
}

int main()
{
  int listCapacity = 1;
  int listLength = 0;

  int* list = malloc(sizeof(*list) * listCapacity);

  // leggo i numeri
  while (scanf("%d", &list[listLength]) != EOF)
  {
    listLength++;

    // Se è necessario, incremento la grandezza della lista
    if (listLength == listCapacity)
    {
      listCapacity *= 2;
      list = realloc(list, sizeof(*list) * listCapacity);
    }
  }

  // ordino i numeri in ordine decrescente
  qsort(list, listLength, sizeof(*list), decreasing_cmp);

  // stampo la lista ordinata
  for (int i=0; i < listLength; i++)
  {
    printf("%d\n", list[i]);
  }

  free(list);
  return 0;
}
