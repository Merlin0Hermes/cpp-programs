// program to add two matrices together

#include <iostream>

int** create_matrix(int rows, int cols); // allocates memory for a rows * cols matrix
void delete_matrix(int **matrix, int rows); // deallocates memory for a matrix 
int** get_matrix(int rows, int cols);   // allocates memory for a matrix and fill the matrix with user inputted values
int** add_matrices(int **marix1, int **matrix2); // adds two matrices together and returns a newly allocated matrix with results



int main()
{
    const int rows = 3, cols = 3;

    int **matrix = create_matrix(rows, cols);

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


int** create_matrix(int rows, int cols)
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


int** get_matrix(int rows, int cols)
{
    int **matrix = create_matrix(rows, cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cin >> matrix[i][j];
        }
    }
    return matrix;
}

int** add_matrices(int **matrix1, int **matrix2, int rows, int cols)
{
    int **result = create_matrix(rows, cols);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return result;

}

