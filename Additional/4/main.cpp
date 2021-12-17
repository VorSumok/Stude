#include <iostream>
// спасибо zumers c Хабр за разбор теории
int main()
{
    int N;
    std::cin >> N;

    long long ArrSize = (N / 2) * 9 + 1;
    long long* Arr = new long long[ArrSize];
    long long* ArrCounter = new long long[ArrSize];

    for (int i = 0; i < ArrSize; i++)
    {
        Arr[i] = 0;
        ArrCounter[i] = 0;
    }

    for (int i = 0; i < 10; i++)
    {
        ArrCounter[i] = 1;
    }
    Arr[0] = 1;
    for (int i = 2; i <= N / 2; i++)
    {
        for (int j = 1; j <= i * 9; j++)
        {
            if (j < 10)
            {
                for (int posJ = j; posJ >= 0; posJ--)
                {
                    Arr[j] += ArrCounter[posJ];
                }

            }
            else
            {
                for (int posJ = j; posJ > j - 10; posJ--)
                {
                    Arr[j] += ArrCounter[posJ];
                }
            }
        }

        for (int j = 0; j < ArrSize; j++)
        {
            ArrCounter[j] = Arr[j];
        }
        for (int i = 1; i < ArrSize; i++)
        {

            Arr[i] = 0;
        }
    }

    long long CountLuckyTickets = 0;
    for (int j = 0; j < ArrSize; j++)
    {
        CountLuckyTickets += ArrCounter[j] * ArrCounter[j];
    }
    std::cout << CountLuckyTickets << std::endl;
}

