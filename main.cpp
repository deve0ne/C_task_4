#include <iostream>
#include <cmath>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "DanglingPointer"
using namespace std;

int **createArr(int columnCount, int rowCount) {
    int **arr = new int *[rowCount];
    for (int i = 0; i < rowCount; ++i)
        arr[i] = new int[columnCount];

    return arr;
}

void deleteArr(int **arr, int rowCount) {
    for (int i = 0; i < rowCount; i++)
        delete[] arr[i];
    delete[] arr;
}

void printArr(int **arr, int columnCount, int rowCount) {
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < columnCount; j++)
            cout << arr[i][j] << " ";
        cout << "\n";
    }
}

int **transformArr(int **originalArr,int rowCount, int newColumnCount) {
    int **transformedArr = createArr(newColumnCount, rowCount);

    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < newColumnCount; j++) {
            transformedArr[i][j] = originalArr[i][j * 2];
        }
    }

    return transformedArr;
}

int main() {
    int columnCount, rowCount;
    cout << "Введите кол-во столбцов: ";
    cin >> columnCount;
    cout << "Введите кол-во строк: ";
    cin >> rowCount;

    int **arr = createArr(columnCount, rowCount);

    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < columnCount; j++) {
            cout << "Введите " << i + 1 << " элемент " << j + 1 << " строки: ";
            cin >> arr[i][j];
        }
    }
    int newColumnCount = columnCount / 2;
    if (columnCount % 2 != 0)
        newColumnCount++;


    int **transformedArr = transformArr(arr, rowCount, newColumnCount);

    cout << "\n" << "Исходный массив: " << "\n";
    printArr(arr, columnCount, rowCount);
    deleteArr(arr, rowCount);

    cout << "\n" << "Трансформированный массив: " << "\n";
    printArr(transformedArr, newColumnCount, rowCount);
    deleteArr(transformedArr, rowCount);

    return 0;
}