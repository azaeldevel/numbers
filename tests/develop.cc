
#include <iostream>
#include <vector>

using namespace std;

// Calculate the determinant of a matrix
double determinant(vector<vector<double>>& matrix) {
    int size = matrix.size();

    // Base case: 1x1 matrix
    if (size == 1) {
        return matrix[0][0];
    }

    // Base case: 2x2 matrix
    if (size == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }

    double det = 0.0;

    // Iterate over the elements of the first row
    for (int j = 0; j < size; j++) {
        // Create a submatrix by removing the current row and column
        vector<vector<double>> submatrix(size - 1, vector<double>(size - 1));
        for (int i = 1; i < size; i++) {
            for (int k = 0; k < size; k++) {
                if (k < j) {
                    submatrix[i - 1][k] = matrix[i][k];
                } else if (k > j) {
                    submatrix[i - 1][k - 1] = matrix[i][k];
                }
            }
        }

        // Calculate the determinant of the submatrix recursively
        double submatrixDet = determinant(submatrix);

        // Multiply the current element by the determinant of the submatrix
        // and add it to the det variable
        det += matrix[0][j] * submatrixDet;
    }

    return det;
}

int main() {
    // Example usage
    vector<vector<double>> matrix = {{1, 2, 3},
                                     {2,1,3},
                                     {3,1,2}};

    double det = determinant(matrix);

    cout << "Determinant: " << det << endl;

    return 0;
}
