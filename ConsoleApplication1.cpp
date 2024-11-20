#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>  // ��� ������ � �������

using namespace std;

int main() {
    const int N = 5;
    int matrix[N][N];

    // ����������� ���������� ���������� �����
    srand(time(0));

    // ��������� � ����� ������� � ����
    ofstream outputFile("matrix.txt");

    if (!outputFile) {
        cerr << "�� ������� ������� ���� ��� ������!" << endl;
        return 1;
    }

    // ���������� ������� ����������� ������� �� �������� � ����
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            matrix[i][j] = rand() % 100;  // �������� ����� �� 0 �� 99
            outputFile << matrix[i][j] << " ";
        }
        outputFile << endl;
    }

    outputFile.close();  // ��������� ����

    // ��������� ������� �� �����
    cout << "������� ����������� �� �������� � ����:" << endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    // ����������� ���������� �������� �� ������� �������
    int minElement = matrix[0][0];  // ��������� �������� ������
    for (int i = 1; i < N; ++i) {
        if (matrix[i][i] < minElement) {
            minElement = matrix[i][i];
        }
    }

    cout << "̳�������� ������� �� ������� �������: " << minElement << endl;

    return 0;
}
