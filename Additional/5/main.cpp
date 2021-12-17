#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <string>
#include <windows.h>
#include <iomanip>

int main()
{
	int mas[10];
	int count;
	int N;
	int k;
	bool raznie;
	bool polidrom;
	int len = 0;
	std::cin >> N;
	for (int i = 1; i < N + 1; i++)
	{
		for (int t = 0; t < 10; t++)
			mas[t] = 0;// отчистка массива

		count = -1;
		k = i;// отчистка переменных
		raznie = true;
		polidrom = true;

		while (k != 0)// считывание цифр из числа
		{
			mas[k % 10] += 1;
			k = k / 10;
		}

		for (int t = 0; t < 10; t++)// всели цифры разные?
		{
			if (mas[t] > 1)
				raznie = false;
		}

		if (raznie == false) // если нет, выводим
		{
			std::cout << i << ' ';
		}

		for (int t = 0; t < 10; t++)
			mas[t] = 0;// отчистка массива

		k = i;
		while (k != 0)// считывание цифр из числа
		{
			count = count + 1;
			mas[count] = k % 10;
			k = k / 10;
		}


		for (int t = 0; t < count; t++)  // это число полидром?
		{
			if (mas[t] != mas[count - t])
				polidrom = false;
		}

		if ((polidrom == true) & (raznie == false))// Да? дублируем
		{
			std::cout << i<< ' ';
		}
	}
}



