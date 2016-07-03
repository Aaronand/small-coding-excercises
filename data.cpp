#include "data.h"
#include <algorithm>
#include <cmath>
#include <memory>
#include <stdexcept>

std::vector<int>::size_type bigInt::size() const
{
	if (data.size() == 0) return 0;
	else
	{
		return data.size() - 1;
	}
}

void bigInt::output()
{
	for (std::vector<int>::size_type i(0); i != data.size(); i++)
		std::cout << data[i];
}

bigInt operator+ (const bigInt &a,const bigInt &b)
{
	bigInt c;
	
	if (a[0]==b[0])
	{
		c.data.push_back(a[0]);
		std::vector<int>::size_type i = 1, len_a = a.size(), len_b = b.size();
		if (a.size() > b.size())
		{
				for (; i != len_b + 1; i++)
				{
					c.data.push_back((a[i] + b[i] + flag) % 10);
					flag = ((a[i] + b[i] + flag) > 9);
				}
				for (; i != len_a + 1;i++)
				{
						c.data.push_back((a[i] + flag) % 10);
						flag = ((a[i] + flag) > 9);
				}
		if (flag)
			c.data.push_back(1);
		}
		else
		{
			for (; i != len_a + 1; i++)
			{
				c.data.push_back((a[i] + b[i] + flag) % 10);
				flag = ((a[i] + b[i] + flag) > 9);
			}
			for (; i != len_b + 1; i++)
			{
				c.data.push_back((b[i] + flag) % 10);
				flag = ((b[i] + flag) > 9);
			}
			if (flag)
		c.data.push_back(1);
		}
		return c;
	}
	else
			return c= a - (-b);
	

}

bigInt operator- (const bigInt &a, const bigInt &b)
{
	bigInt c;
	//符号相同
	if (a[0]==b[0])
	{
		c.data.push_back(a[0]);
		std::vector<int>::size_type i = 1,len_a = a.size(), len_b = b.size();
		int flag = 0;
		if (absv(a) > absv(b))
		{
			for (; i != len_a + 1; i++)
			{
				if (i <= len_b)
				{
					c.data.push_back((a[i] - b[i] - flag + 10) % 10);
					flag = (a[i] - b[i] - flag) < 0;
				}
				else
				{
					c.data.push_back((a[i] - flag + 10) % 10);
					flag = (a[i] - flag) < 0;
				}
			}
		}
		else
		{
			for (; i != len_b + 1; i++)
			{
				if (i <= len_a)
				{
					c.data.push_back((b[i] - a[i] - flag + 10) % 10);
					flag = (b[i] - a[i] - flag) < 0;
				}
				else
				{
					c.data.push_back((b[i] - flag + 10) % 10);
					flag = (b[i] - flag) < 0;
				}
			}
		}
	
		while (c.size() > 1 && c[c.size()] == 0) c.data.pop_back();

			if (a < b)
				c.data[0] = 1;
			else
				c.data[0] = 0;
		return c;
	}
	else
		return a + (-b);
}

bigInt operator* (const bigInt &a, const bigInt &b)
{
	if (a == 0 || b == 0)
		return 0;
	bigInt c(0);
	std::vector<int>::size_type len_a = a.size(), i = 1;
	for (; i != len_a + 1; i++)
	{
		bigInt temp = (a[i] * b);
		for (std::vector<int>::size_type j(1); j != i; j++)
			temp.data.insert(temp.data.begin()+1,0);
		c = c + temp;
	}
	c.data[0]=(b[0] != a[0]);
	return c;
}

bigInt operator* (const int a, const bigInt &b)
{
	bigInt c; int flag = 0;
	c.data.push_back(b[0]);
	std::vector<int>::size_type len_b = b.size(),i=1;
	for (; i != len_b + 1; i++)
	{
		c.data.push_back(((a*b[i]) % 10 + flag)%10);
		flag = ((a*b[i]) + flag) / 10;
	}
	if (flag != 0)
		c.data.push_back(flag);
	return c;
}

bigInt operator/ (const bigInt &a, const bigInt &b)
{
	if (b == 0)
		throw std::domain_error ("除数不得为0！");
	if (absv(a) < absv(b))
		return 0;
	else {
		bigInt c(0), d(0), a1 = absv(a), b1 = absv(b); int i, n;
		while (a1 >= b1)
		{
			n = 1, i = 0;
			while (a1 > (10 * b1))
			{
				b1.data.insert(b1.data.begin() + 1, 0);
				n *= 10;
			}
			while (a1 >= b1)
			{
				a1 = a1 - b1;
				i++;
			}
			bigInt counter(i*n);
			c = c + counter;
			b1 = absv(b);
		}
			c.data[0] = (a[0] != b[0]);
			return c;
	}
}

bigInt operator% (const bigInt &a, const bigInt &b)
{
	bigInt c, a1 = absv(a), b1 = absv(b);
	c = a1 - (a1 / b1)*b1;
	if (a[0] == 0)
		return c;
	else
		return -c;
}


std::ostream& operator<<(std::ostream& os, const bigInt& a)//常记引用
{
	if (a.data[0] == 1)
		os << "-";
	for (std::vector<int>::size_type i = a.data.size() - 1; i != 0; i--)
		os << a.data[i];
	return os;
}

std::istream& operator>>(std::istream& in, bigInt& a)
{
	char x;
	while (in.get(x) && isspace(x));
	a.data.clear();
	if (in)
	{
		if (x == '-')
		{
			a.data.push_back(1);
			in.get(x);
		}
		else
			a.data.push_back(0);
		do
		{
			a.data.push_back(x-'0');
		} while (in.get(x) && !isspace(x));
	}
	
	std::reverse(a.data.begin()+1, a.data.end());
	return in;
}

bool operator== (const bigInt &a, const bigInt &b)
{
	if (a.size() != b.size())
		return false;
	for (std::vector<int>::size_type i = 0; i != a.size() + 1; i++)
	{
		if (a.data[i] != b.data[i])
			return false;
	}
	return true;
}

bool operator!= (const bigInt &a, const bigInt &b)
{
	return !(a == b);
}

bool operator> (const bigInt &a, const bigInt &b)
{
	if (a == b)
		return false;
	if (a.data[0] != b.data[0])
	{
		if (a.data[0])
			return false;
		else
			return true;
	}

	else
	{
		if (a.data[0] == 0)
		{
			if (a.size() > b.size())
				return true;
			if (a.size() < b.size())
				return false;
			if (a.size() == b.size())
			{
				for (std::vector<int>::size_type i = a.size(); i != 0; i--)
				{
					if (a.data[i] > b.data[i])
					{
						return true;
					}
					if (a.data[i] < b.data[i])
					{
						return false;
					}
				}
			}
		}
		else
		{
			if (a.size() < b.size())
				return true;
			if (a.size() > b.size())
				return false;
			if (a.size() == b.size())
			{
				for (std::vector<int>::size_type i = a.size(); i != 0; i--)
				{
					if (a.data[i] < b.data[i])
					{
						return true;
					}
					if (a.data[i] > b.data[i])
					{
						return false;
					}
				}
			}
		}
	}
	return true;
}

bool operator< (const bigInt &a, const bigInt &b)
{
	return !((a > b)||(a == b));
}

bool operator>= (const bigInt &a, const bigInt &b)
{
	return !(a<b);
}
bool operator<= (const bigInt &a, const bigInt &b)
{
	return !(a>b);
}
bigInt absv(bigInt a) 
{
	a.data[0] = 0;
	return a; 
}

bigInt operator- (bigInt b) 
{
	b.data[0] = b.data[0] ? 0 : 1;
	return b;
}



