// program to add two matrices together

#include <iostream>

int main()
{
    constexpr int rows = 3, cols = 3;
    int **matrix = new int*[rows];

    for (int i = 0; i < cols; i++)
        matrix[i] = new int[cols];

    std::cout << "Enter matrix: ";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cin >> matrix[i][j];
        }
        
    }


    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << "\n";
    }

    for (int i = 0; i < rows; i++)
        delete[] matrix[i];
    delete[] matrix;


    return 0;      
}