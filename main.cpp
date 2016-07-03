

#include <iostream>
#include <string>
#include <cstdlib>
#include "data.h"
	using std::cin;
	using std::cout;
	using std::endl;


	int main()
	{
		bigInt num1, num2;
		cout << "请输入第一个数字:" << endl;
		cin >> num1;
		cout << "请输入第二个数字:" << endl;
		cin >> num2;
		
		
		cout << endl;
		if (num1 != num2)
			cout << num1 << "!=" << num2 << endl;
		if (num1 == num2)
			cout << num1 << "==" << num2 << endl;
		if (num1 > num2)
			cout << num1 << ">" << num2 << endl;
		if (num1 < num2)
			cout << num1 << "<" << num2 << endl;
		if (num1 >= num2)
			cout << num1 << ">=" << num2 << endl;
		if (num1 <= num2)
			cout << num1 << "<=" << num2 << endl;

		cout << endl;

		cout << "-num1 = " << -num1 << endl;
		cout << "-num2 = " << -num2 << endl;

		cout << endl;

		cout << "absv(num1) = " << absv(num1) << endl;
		cout << "absv(num2) = " << absv(num2) << endl;

		cout << endl;
		cout << "num1 + num2 = " << num1 + num2 << endl;
		cout << "num1 - num2 = " << num1 - num2 << endl;

		cout << endl;
		cout << "num1 * num2 = " << num1 * num2 << endl;
		cout << "num1 / num2 = " << num1 / num2 << endl;
		cout << "num1 % num2 = " << num1 % num2 << endl;

		return 0;
	}
