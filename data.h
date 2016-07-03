#ifndef GUARD data_h
#define GUARD data_h


#include <vector>
#include <iostream>
#include <string>


class bigInt {
	friend bigInt operator+ (const bigInt &,const bigInt &);
	friend bigInt operator- (const bigInt &, const bigInt &);

	friend bigInt operator* (const bigInt &, const bigInt &);
	friend bigInt operator* (const int, const bigInt &);
	friend bigInt operator/ (const bigInt &, const bigInt &);
	friend bigInt operator% (const bigInt &, const bigInt &);
	friend std::ostream& operator<<(std::ostream&, const bigInt&);
	friend std::istream& operator>>(std::istream&, bigInt&);
	friend bigInt absv(bigInt);
	friend bigInt operator- (bigInt);
	friend bool operator== (const bigInt &, const bigInt &);
	friend bool operator!= (const bigInt &, const bigInt &);
	friend bool operator> (const bigInt &, const bigInt &);
	friend bool operator< (const bigInt &, const bigInt &);
	friend bool operator>= (const bigInt &, const bigInt &);
	friend bool operator<= (const bigInt &, const bigInt &);
private:
	std::vector<int> data;
	int& operator[] (std::size_t i) 
	{ 
		if (i < 0 || i >= data.size())
			throw std::string("out of bounds");
		else
		return data[i]; 
	}
	const int& operator[] (std::size_t i) const 
	{
		if (i < 0 || i >= data.size())
			throw std::string("out of bounds");
		else
			return data[i];
	}
public:
	bigInt() {};
	bigInt(int a)
	{
		if (a < 0) {
			data.push_back(1);
			a = -a;
		}
		else data.push_back(0);
		if (a == 0)
			data.push_back(0);
		else
		{
			for (; a != 0; a /= 10)
			{
				int b = a % 10;
				data.push_back(b);
			}
		}
	}
	bigInt(size_t n, unsigned int v)
	{
		data.push_back(0);
		for (int i(0); i != n;i++)
		data.push_back(v);
	}

	std::vector<int>::size_type size() const ;
	void output();
	
};


#endif // !GUARD data_h

