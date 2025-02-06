// program to add two matrices together

#include <iostream>

int** get_matrix(int rows, int cols);
void delete_matrix(int **matrix, int rows);


int main()
{
    const int rows = 3, cols = 3;

    int **matrix = get_matrix(rows, cols);

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

    delete_matrix(matrix, rows);

    return 0;      
}


int** get_matrix(int rows, int cols)
{
    int **matrix = new int*[rows];

    for (int i = 0; i < cols; i++)
        matrix[i] = new int[cols];   

    return matrix; 
}


void delete_matrix(int **matrix, int rows)
{
    for (int i = 0; i < rows; i++)
        delete[] matrix[i];
    delete[] matrix;
}