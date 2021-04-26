#include "std_lib_facilities.h"
#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <list>
#include <array>
#include <string>

template<typename Iter>
void increase(Iter first, Iter last, int x)
{

	while(first!=last)
	{
		*first += x;
		++first;
	}
}

template<typename Iter1, typename Iter2>
Iter2 my_copy(Iter1 f1, Iter1 e1, Iter2 f2)
{
	while(f1!=e1)
	{
		*f2 = *f1;
		++f1;
		++f2;
	}
	return f2;
}

int main()
{
	
    array<int,10> ai;
    for (int i = 0; i<ai.size(); ++i) ai[i] = i;
         

	vector<int> vi;
    for (int i = 0; i<10; ++i) vi.push_back(i);
     

	list<int> li;
    for (int i = 0; i<10; ++i) li.push_back(i);
      

	array<int, 10> ai2 = ai;
	vector<int> vi2 = vi;
	list<int> li2 = li;

	increase(ai2.begin(), ai2.end(), 2);
	increase(vi2.begin(), vi2.end(), 3);
	increase(li2.begin(), li2.end(), 5);

    

	my_copy(ai2.begin(), ai2.end(), vi2.begin());
	my_copy(li2.begin(), li2.end(), ai2.begin());



	int value1 = 3;
	int value2 = 27;

	auto p = find(vi.begin(), vi.end(), value1);

	if (p != vi.end())
        cout << "Found at: " << distance(vi.begin(), p) << '\n';
    else
        cout << "Not found\n";

    auto p2 = find(li.begin(), li.end(), value2);

    if (p2 != li.end())
        cout << "Found at: " << distance(li.begin(), p2) << '\n';
    else
        cout << "Not found\n";

	return 0;
}