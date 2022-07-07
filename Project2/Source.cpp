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




// not my class, it's from lesson
class MyString
{
public:

	//конструктор без параметров
	MyString()
	{
		str = nullptr;
		length = 0;
	}

	//конструктор с параметрами, при создании объекта класса необходимо перелать строку которую он будет хранить
	MyString(const char* str)
	{

		length = strlen(str);// функция strlen получает количество символов в строке которую мы передаём в объект

		// выделяем память для динамического массива где будет храниться наша строка
		// +1 символ так как нужно место в массиве под терминирующий 0
		this->str = new char[length + 1];

		// копируем символы строки в массив нашего класса
		for (int i = 0; i < length; i++)
		{
			this->str[i] = str[i];
		}

		//закрываем строку терминирующим нулём
		this->str[length] = '\0';

	}
	// деструктор, отвечает за освобождение ресурвов занятых объектом, вызывается при уничтожении объекта класса
	~MyString()
	{
		delete[] this->str;
	}

	// конструктор копировании, необходим для создании точной копи объекта класса но в другой области памяти
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

	// перегруженый оператор присваивания, вызывается когда необходимо присвоить значение одного объекта другому
	MyString& operator =(const MyString& other)
	{
		// здесь логика похожа на ту которая реализована в конструкторе, за исключением того, что нам нужно позаботиться
		// об освобождении ресурсов объекта если до копирования в него новой строки он уже содержал код
		//+ страндартный синтаксис перегрузки оператора =
		if (this->str != nullptr)
		{
			delete[] str;
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

	//перегруженный оператор сложения, в текущей реализации класса String необходим для конкатенации строк
	MyString operator+(const MyString& other)
	{
		//создаём новый пустой объект где будим хранить результат конкатенации строк и который будет результатом работы
		// перегруженного оператора +
		MyString newStr;
		// получаем количество символов в обеих строках для конкатенации

		int thisLength = strlen(this->str);
		int otherLength = strlen(other.str);

		newStr.length = thisLength + otherLength;

		// выделяем место в динамической памяти под новую строку
		newStr.str = new char[thisLength + otherLength + 1];

		//копируем данные из 2х конкатенируемых строк в новую строку
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

		// возвращаем результат конкатенации
		return newStr;
	}

	// выводит строку в консоль, в идеале для этого необходима перегрузка оператора «
	void Print()
	{
		std::cout << str;
	}

	int Length()
	{
		return length;
	}

	bool operator ==(const MyString& other)
	{
		if (this->length != other.length)
		{
			return false;
		}

		for (int i = 0; i < this->length; i++)
		{
			if (this->str[i] != other.str[i])
			{
				return false;
			}
		}
		return true;
	}

	bool operator !=(const MyString& other)
	{
		return !(this->operator==(other));
	}

	char& operator [](int index)
	{
		return this->str[index];
	}


	MyString(MyString&& other)
	{
		this->length = other.length;
		this->str = other.str;
		other.str = nullptr;
	}


private:
	// Указатель на массив char, хранит символы, которые мы передали в наш объект.
	char* str;
	int length;
};


// my class
class Point
{
public:

	static int count;

	Point()
	{
		x = 0;
		y = 0;
	}

	Point(const int& _x, const int& _y)
	{
		this->x = _x;
		this->y = _y;
		count++;
	}

	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
	}

	Point(Point&& other)
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

	Point& operator = (Point&& other)
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

	~Point()
	{
		x = 0;
		y = 0;
	}



private:
	int x;
	int y;
};

int Point::count = 0;





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
	auto res = num1 != num2;

	

	MyString str("Hello");
	MyString str2("World");

	MyString result;
	result = str + str2;

	std::cout << Point::count << '\n';

	return 0;
}