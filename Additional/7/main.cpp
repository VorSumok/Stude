#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <string>
#include <windows.h>
#include <iomanip>
#include<vector>

int main()
{
	std::vector<int> v1;
	std::vector<int> v2;
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
		v2.clear();

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

		if (raznie == false) // ���� ���, ��������� � ������
		{
			v1.push_back(i);
			len += 1;
		}

		k = i;
		while (k != 0)// ���������� ���� �� �����
		{
			v2.push_back(k % 10);
			k = k / 10;
			count = count + 1;
		}


		for (int t = 0; t < count; t++)  // ��� ����� ��������?
		{
			if (v2[t] != v2[count - t])
				polidrom = false;
		}

		if ((polidrom == true) & (raznie == false))// ��? ���������
		{
			v1.push_back(i);
			len += 1;
		}
	}
	for (int i = 0; i < len; i++)
		std::cout << v1[i] << ' ';
}


