#include <iostream>

int main()
{
	int Q1, Q2, P1, P2, A, Sum, Sum1, Sum2;
    std::cin >> Q1 >> P1 >> Q2 >> P2 >> A;
    int n1 = A / Q1 + (A % Q1 != 0);
    int mn = 20000000;

    for (int i = 0; i <= n1; i++)
    {
        int a = A - i * Q1;

        int m = (a <= 0 ? 0 : (a / Q2 + (a % Q2 != 0)) * Q2) + i * P1;
        if (m < mn)
        {
            mn = m;
        }
    }
    std::cout << mn << std::endl;
}

