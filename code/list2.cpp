#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

int main()
{
  using std::cin;
  using std::cout;

  std::vector<int> list;

  int number;
  while (cin >> number)
  {
    list.push_back(number);
  }

  std::sort(list.begin(), list.end(), std::greater<int>());

  // create an iterator on stdout that will use newline as separator
  std::ostream_iterator<int> outputIterator(cout, "\n");

  // copy list to stdout using std::copy
  std::copy(list.begin(), list.end(), outputIterator);
  return 0;
}
