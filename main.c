#include <stdio.h>

// Function declarations
void print_matrix(int matrix[3][3]);
void modify_matrix(int matrix[3][3]);
void transpose_matrix(int matrix[3][3]);
void find_max_in_each_row(int matrix[3][3]);
int is_symmetric(int matrix[3][3]);
int calculate_determinant(int matrix[3][3]);
void calculate_inverse(int matrix[3][3]);

int main() {
    int matrix[3][3];
    int choice;

    // Input the matrix from the user
    printf("Enter the elements of the 3x3 matrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    do{



    // Menu for choosing operations
    printf("\nChoose an operation to perform:\n");
    printf("1. Modify the matrix\n");
    printf("2. Find the transpose of the matrix\n");
    printf("3. Find the maximum element in each row of the matrix\n");
    printf("4. Check whether the matrix is symmetric\n");
    printf("5. Find the determinant of the matrix\n");
    printf("6. Find the inverse of the matrix\n");
    printf("7. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Perform the chosen operation
    switch(choice) {
        case 1:
            modify_matrix(matrix);
            printf("\nModified matrix:\n");
            print_matrix(matrix);
            break;
        case 2:
            transpose_matrix(matrix);
            printf("\nTransposed matrix:\n");
            print_matrix(matrix);
            break;
        case 3:
            find_max_in_each_row(matrix);
            break;
        case 4:
            if (is_symmetric(matrix)) {
                printf("\nThe matrix is symmetric.\n");
            } else {
                printf("\nThe matrix is not symmetric.\n");
            }
            break;
        case 5:
            printf("\nThe determinant of the matrix is %d.\n", calculate_determinant(matrix));
            break;
        case 6:
            calculate_inverse(matrix);
            break;
        case 7:
            return 0;

        default:
            printf("\nInvalid choice.\n");
            break;
    }
    } while(1);
    return 0;
}

// Function definitions

// Print the given matrix
void print_matrix(int matrix[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Modify the given matrix by adding a constant to each element
void modify_matrix(int matrix[3][3]) {
    int mdf [3][3];
     printf("\nEnter a constant to be multiplied by each element of the matrix: ");
     scanf("%d", &mdf);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
           mdf[i][j] = matrix[i][j]* -1;
           printf("%d\t", mdf[i][j]);
        }
        printf("\n");
    }
}

// Find the transpose of the given matrix
void transpose_matrix(int matrix[3][3])
{
    int i, j;

    for(i=0; i<3; i++) {
        for(j=i+1; j<3; j++) {
            matrix[i][j] += matrix[j][i];
            matrix[j][i] = matrix[i][j] - matrix[j][i];
            matrix[i][j] -= matrix[j][i];
        }
    }
}


// Find the maximum element in each row of the given matrix
void find_max_in_each_row(int matrix[3][3]) {
int max;
for (int i = 0; i < 3; i++) {
max = matrix[i][0];
for (int j = 1; j < 3; j++) {
if (matrix[i][j] > max) {
max = matrix[i][j];
}
}
printf("\nThe maximum element in row %d is %d.\n", i+1, max);
}
}

// Check whether the given matrix is symmetric
int is_symmetric(int matrix[3][3]) {
for (int i = 0; i < 3; i++) {
for (int j = 0; j < i; j++) {
if (matrix[i][j] != matrix[j][i]) {
return 0;
}
}
}
return 1;
}

// Calculate the determinant of the given matrix
int calculate_determinant(int matrix[3][3]) {
int determinant = 0;
for (int i = 0; i < 3; i++) {
determinant += matrix[0][i] * (matrix[1][(i+1)%3] * matrix[2][(i+2)%3] - matrix[1][(i+2)%3] * matrix[2][(i+1)%3]);
}
return determinant;
}

// Calculate the inverse of the given matrix
void calculate_inverse(int matrix[3][3]) {
int determinant = calculate_determinant(matrix);
if (determinant == 0) {
printf("\nThe matrix is not invertible.\n");
} else {
int inverse[3][3];
for (int i = 0; i < 3; i++) {
for (int j = 0; j < 3; j++) {
inverse[i][j] = (matrix[(j+1)%3][(i+1)%3] * matrix[(j+2)%3][(i+2)%3] - matrix[(j+1)%3][(i+2)%3] * matrix[(j+2)%3][(i+1)%3]) / determinant;
}
}
printf("\nThe inverse of the matrix is:\n");
print_matrix(inverse);
}
}
