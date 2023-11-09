#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Функція для генерації матриці
void generateMatrix(int** matrix, int rows, int cols, int min, int max) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % (max - min + 1) + min;
        }
    }
}

// Функція для виведення матриці на консоль
void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

// Функція для обчислення добутку елементів додатних рядків
int multiplyPosRows(int** matrix, int rows, int cols) {
    int product = 1;
    for (int i = 0; i < rows; i++) {
        bool allPositive = true;
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] < 0) {
                allPositive = false;
                break;
            }
        }
        if (allPositive) {
            for (int j = 0; j < cols; j++) {
                product *= matrix[i][j];
            }
        }
    }
    return (product != 1) ? product : -1; // Повертаємо -1, якщо додатніх рядків немає
}

// Функція для знаходження максимальної суми діагоналей
void findMaxDiagonalSum(int** matrix, int rows, int cols, int & maxSum) {

    for (int i = 0; i < rows; i++) {
        int sum = 0;
        for (int j = 0; j < cols; j++) {
            if (i - j >= 0 && i - j < rows) {
                sum += matrix[i - j][j];
            }
        }
        maxSum = max(maxSum, sum);
    }

    for (int j = 1; j < cols; j++) {
        int sum = 0;
        for (int i = 0; i < rows; i++) {
            if (j + i < cols) {
                sum += matrix[i][j + i];
            }
        }
        maxSum = max(maxSum, sum);
    }

}

int main() {
    srand(time(0)); // Ініціалізація генератора випадкових чисел
    int k, n;
    cout << "k = ";
    cin >> k;
    cout << "n = ";
    cin >> n;

    int** matrix = new int* [k];
    for (int i = 0; i < k; i++) {
        matrix[i] = new int[n];
    }

    generateMatrix(matrix, k, n, -5, 20);
    printMatrix(matrix, k, n);

    int product = multiplyPosRows(matrix, k, n);
    if (product != -1) {
        cout << "Product of positive series: " << product << endl;
    }
    else {
        cout << "There are no positive lines:" << endl;
    }
    int maxSum = INT_MIN;

    findMaxDiagonalSum(matrix, k, n, maxSum);
    cout << "Maximum sum of diagonals: " << maxSum << endl;

    for (int i = 0; i < k; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
