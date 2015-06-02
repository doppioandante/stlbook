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

  // Read the numbers
  while (scanf("%d", &list[listLength]) != EOF)
  {
    listLength++;

    // If necessary, increment list size
    if (listLength == listCapacity)
    {
      listCapacity *= 2;
      list = realloc(list, sizeof(*list) * listCapacity);
    }
  }

  // order list in descending order
  qsort(list, listLength, sizeof(*list), decreasing_cmp);

  // print the list
  for (int i=0; i < listLength; i++)
  {
    printf("%d\n", list[i]);
  }

  free(list);
  return 0;
}
