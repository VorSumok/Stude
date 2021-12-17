#include <iostream>

int main()
{
    int n, m;
    std::cin >> n >> m;

    int** matrixA = new int* [n];
    for (int i = 0; i < n; i++)
        matrixA[i] = new int[m];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            std::cin >> matrixA[i][j];

    int nm, min, col;
    col = 0;
    min = 100;

    for (int i = 0; i < n; i++) {
        col = 0;
        for (int j = 0; j < m; j++) {
            if (matrixA[i][j] % 2 == 0) {
                col++;
            }

        }
        if (col < min) {
            min = col;
            nm = i;
        }
    }


    for (int j = 0; j < m; j++)
        matrixA[nm][j] = matrixA[nm][j] * matrixA[nm][j];



    for (int i = 0; i < n; i++) {
        std::cout << std::endl;
        for (int j = 0; j < m; j++)
            std::cout << matrixA[i][j] << " ";
        std::cout << std::endl;
    }
    for (int i = 0; i < n; i++)
        delete[] matrixA[i];
    delete[] matrixA;
}

