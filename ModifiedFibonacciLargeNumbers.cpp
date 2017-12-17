#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> add(vector<int> a, vector<int> b)
{
	vector<int> sum;
	int summation, carry = 0;
	if (a.size() > b.size())
	{
		b.resize(a.size(), 0);
	}
	if (a.size() < b.size())
	{
		a.resize(b.size(), 0);
	}
	vector<int>::iterator itr_a = a.begin();
	vector<int>::iterator itr_b = b.begin();
	while (itr_a != a.end() || itr_b != b.end())
	{
		//cout<<*itr_a<<*itr_b;
		summation = (*itr_a) + (*itr_b) + carry;
		if (summation > 9)
		{
			carry = 1;
		}
		else
			carry = 0;
		sum.push_back(summation % 10);
		itr_a++;
		itr_b++;
	}
	if (carry != 0)
	{
		sum.push_back(carry);
	}
	return sum;
}

vector<int> square(vector<int> a)
{
	int carry = 0, count = 0;
	vector<int> res;
	vector<int> mul;
	vector<int>::iterator itr1;
	vector<int>::iterator itr2 = a.begin();
	while (itr2 != a.end())
	{
		itr1 = a.begin();
		mul.erase(mul.begin(), mul.end());
		for (int i = 0; i<count; i++)
		{
			mul.push_back(0);
		}
		while (itr1 != a.end())
		{
			int mult = ((*itr1)*(*itr2)) + carry;
			mul.push_back(mult % 10);
			carry = mult / 10;
			itr1++;
		}
		if (carry != 0)
		{
			while (carry != 0)
			{
				mul.push_back(carry%10);
				carry = carry / 10;
			}
		}
		itr2++;
		count++;
		res.resize(mul.size(), 0);
		res = add(res, mul);
	}
	return res;

}

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int n, x, y;
	cin >> x >> y >> n;
	vector<int> a;
	vector<int> b;
	vector<int> c;
	a.push_back(x);
	b.push_back(y);
	for (int i = 0; i<n - 2; i++)
	{
		c = add(a, square(b));
		a = b;
		b = c;
	}
	reverse(b.begin(), b.end());
	vector<int>::iterator itr = b.begin();
	while (itr != b.end())
	{
		cout << *itr;
		itr++;
	}
	cout << endl;
	return 0;
}

