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

  // creo un iteratore che stampi su standard output i numeri
  // separati da un newline
  std::ostream_iterator<int> outputIterator(cout, "\n");

  // copio list su stdout attraverso outputIterator
  std::copy(list.begin(), list.end(), outputIterator);
  return 0;
}
