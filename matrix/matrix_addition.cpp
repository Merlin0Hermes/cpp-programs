// program to add two matrices together

#include <iostream>

int** create_matrix(int rows, int cols); // allocates memory for a rows * cols matrix
void delete_matrix(int **matrix, int rows); // deallocates memory for a matrix 
int** get_matrix(int rows, int cols);   // allocates memory for a matrix and fill the matrix with user inputted values
int** add_matrices(int **marix1, int **matrix2, int rows, int cols); // adds two matrices together and returns a newly allocated matrix with results
void print_matrix(int **matrix, int rows, int cols); // prints a given matrix


int main()
{
    std::cout << "Enter the size of matrix (rows columns): ";
    int rows, cols;
    std::cin >> rows >> cols;

    std::cout << "Enter first matrix: ";
    int **matrix1 = get_matrix(rows, cols);

    std::cout << "You entered: \n";
    print_matrix(matrix1, rows, cols);

    std::cout << "Enter second matrix: ";
    int **matrix2 = get_matrix(rows, cols);

    std::cout << "You entered: \n";
    print_matrix(matrix2, rows, cols);

    int **result = add_matrices(matrix1, matrix2, rows, cols);

    std::cout << "Sum of matrices: \n";
    print_matrix(result, rows, cols);

    delete_matrix(matrix1, rows);
    delete_matrix(matrix2, rows);
    delete_matrix(result, rows);


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


void print_matrix(int **matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << "\n";
    }
}

