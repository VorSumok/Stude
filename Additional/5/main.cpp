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
			mas[t] = 0;// �������� �������

		count = -1;
		k = i;// �������� ����������
		raznie = true;
		polidrom = true;

		while (k != 0)// ���������� ���� �� �����
		{
			mas[k % 10] += 1;
			k = k / 10;
		}

		for (int t = 0; t < 10; t++)// ����� ����� ������?
		{
			if (mas[t] > 1)
				raznie = false;
		}

		if (raznie == false) // ���� ���, �������
		{
			std::cout << i << ' ';
		}

		for (int t = 0; t < 10; t++)
			mas[t] = 0;// �������� �������

		k = i;
		while (k != 0)// ���������� ���� �� �����
		{
			count = count + 1;
			mas[count] = k % 10;
			k = k / 10;
		}


		for (int t = 0; t < count; t++)  // ��� ����� ��������?
		{
			if (mas[t] != mas[count - t])
				polidrom = false;
		}

		if ((polidrom == true) & (raznie == false))// ��? ���������
		{
			std::cout << i<< ' ';
		}
	}
}



