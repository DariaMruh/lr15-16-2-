#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>  // Для роботи з файлами

using namespace std;

int main() {
    const int N = 5;
    int matrix[N][N];

    // Ініціалізація генератора випадкових чисел
    srand(time(0));

    // Створення і запис матриці у файл
    ofstream outputFile("matrix.txt");

    if (!outputFile) {
        cerr << "Не вдалося відкрити файл для запису!" << endl;
        return 1;
    }

    // Заповнюємо матрицю випадковими числами та записуємо в файл
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            matrix[i][j] = rand() % 100;  // Випадкові числа від 0 до 99
            outputFile << matrix[i][j] << " ";
        }
        outputFile << endl;
    }

    outputFile.close();  // Закриваємо файл

    // Виведення матриці на екран
    cout << "Матриця згенерована та записана у файл:" << endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    // Знаходження мінімального елемента на головній діагоналі
    int minElement = matrix[0][0];  // Початкове значення мінімуму
    for (int i = 1; i < N; ++i) {
        if (matrix[i][i] < minElement) {
            minElement = matrix[i][i];
        }
    }

    cout << "Мінімальний елемент на головній діагоналі: " << minElement << endl;

    return 0;
}
