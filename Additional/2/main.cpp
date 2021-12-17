#include <iostream>

int main()
{
	int N, Yers;
	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int k = 0; k < 3; k++)
			std::cin >> Yers;
		if (Yers > 2016)
			Yers = Yers; // можно использовать в тотже год

		else if ((Yers % 4 == 0) & (Yers < 2016))
		{
				while (Yers < 2016)
					Yers += 4;
		}

		else if ((Yers % 4 == 1) & (Yers < 2016))
		{
				while (Yers < 2016)
					Yers += 6;
		}

		else
		{
				while (Yers < 2016)
					Yers += 11;
		}

		std::cout << Yers << std::endl;
	}
}

