#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <cmath>
#include <set>
#include <numeric>



bool all_chet(uint64_t n)
{
	auto tmp = n;

	while (tmp != 0)
	{
		if ((tmp % 10) % 2 != 0)
			return false;
		tmp /= 10;
	}
	return true;
}
bool simple(uint64_t n)
{
	if (n == 1)
		return false;
	for (auto i = 2; i < int(sqrt(n)) + 1; i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}
bool progress(uint64_t n)
{
	std::vector<uint64_t> digits;

	while (n != 0)
	{
		digits.push_back(n % 10);
		n /= 10;
	}


	for (auto i = 1; i < digits.size(); i++)
	{
		if (digits[i - 1] <= digits[i])
			return false;
	}

	return true;
}
uint64_t fac(uint64_t n)
{
	auto res = 1;

	for (auto i = 1; i <= n; i++)
		res *= i;

	return res;
}
uint64_t summ_digits(uint64_t n)
{
	auto summ = 0;

	while (n != 0)
	{
		summ += n % 10;
		n /= 10;
	}

	return summ;
}
uint64_t count_simple_dels(uint64_t n)
{
	auto count = 0;

	for (auto i = 2; i < std::floor(sqrt(n)) + 1; i++)
	{
		if (n % i == 0)
		{
			if (i * i == n)
			{
				if (simple(i))
					count++;
			}
			else
			{
				if (simple(i))
					count++;
				if (simple(n / i))
					count++;
			}
		}
	}
	return count;
}

// not my class, its from lesson
class MyString
{
public:

	MyString()
	{
		str = nullptr;
		length = 0;
	}

	MyString(const char* str)
	{

		length = strlen(str);
		this->str = new char[length + 1];

		for (int i = 0; i < length; i++)
		{
			this->str[i] = str[i];
		}

		this->str[length] = '\0';

	}
	~MyString()
	{
		delete[] this->str;
	}

	MyString(const MyString& other)
	{
		length = strlen(other.str);
		this->str = new char[length + 1];

		for (int i = 0; i < length; i++)
		{
			this->str[i] = other.str[i];
		}

		this->str[length] = '\0';
	}

	MyString& operator =(const MyString& other)
	{
		if (this->str != nullptr)
		{
			delete[] this->str;
		}

		length = strlen(other.str);
		this->str = new char[length + 1];

		for (int i = 0; i < length; i++)
		{
			this->str[i] = other.str[i];
		}

		this->str[length] = '\0';

		return *this;

	}
	MyString operator+(const MyString& other)
	{
		MyString newStr;

		int thisLength = strlen(this->str);
		int otherLength = strlen(other.str);

		newStr.length = thisLength + otherLength;

		newStr.str = new char[thisLength + otherLength + 1];

		int i = 0;
		for (; i < thisLength; i++)
		{
			newStr.str[i] = this->str[i];
		}

		for (int j = 0; j < otherLength; j++, i++)
		{
			newStr.str[i] = other.str[j];
		}

		newStr.str[thisLength + otherLength] = '\0';

		return newStr;
	}

	void Print()
	{
		std::cout << str;
	}

	int Length()
	{
		return length;
	}

private:
	char* str;
	int length;
};


// my class
class Point
{
public:
	Point()
	{
		x = 0;
		y = 0;
	}
	Point(const int& _x, const int& _y)
	{
		this->x = _x;
		this->y = _y;
	}

	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
	}

	Point& swap()
	{
		auto temp = this->x;
		this->x = this->y;
		this->y = temp;
		return *this;
	}

	Point& operator = (const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		return *this;
	}

	Point operator + (const Point& other)
	{
		Point _result;
		_result.x = this->x + other.x;
		_result.y = this->y + other.y;
		return _result;
	}

	Point& operator += (const Point& other)
	{
		this->x += other.x;
		this->y += other.y;
		return *this;
	}

	Point operator - (const Point& other)
	{
		Point _result;
		_result.x = this->x - other.x;
		_result.y = this->y - other.y;
		return _result;
	}

	Point& operator -= (const Point& other)
	{
		this->x -= other.x;
		this->y -= other.y;
		return *this;
	}

	Point& operator ++ ()
	{
		this->x++;
		this->y++;
		return *this;
	}

	Point operator ++ (int _value)
	{
		Point temp = *this;
		this->x++;
		this->y++;
		return temp;
	}

	bool operator == (const Point& other)
	{
		return (this->x == other.x && this->y == other.y);
	}

	bool operator != (const Point& other)
	{
		return !(this->x == other.x && this->y == other.y);
	}


	void Print()
	{
		std::cout << this->x << ' ' << this->y << '\n';
	}


private:
	int x;
	int y;
};




int main()
{
	setlocale(LC_ALL, "ru");


	Point num;
	Point num1(1, 1);
	Point num2(1, 1);
	num = num1 + num2;
	num1 = num++;
	num2 = ++num;


	num1.Print();
	num2.Print();
	auto result = num1 != num2;


	return 0;
}