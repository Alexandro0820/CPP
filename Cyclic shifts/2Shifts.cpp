//Замена элемента массива на число введённое пользователем
//с увеличением размера массива и циклическими сдвигами на  С++

#include <iostream>
#include <string>

using namespace std;

void Print(int* arr, int& size) {
    for (auto i = 0; i < size; i++) {
        cout << *(arr + i) << " ";
    }
}

void Func(int*&arr, int& size, int point, int number) {
    int* arr2 = new int[size + 1];
    for (auto i = 0; i < size; i++) {
        arr2[i] = arr[i];
    }
    arr2[size] = 0;
    point--;
    for (auto i = size; i > point; i--) {
        swap(arr2[i], arr2[i - 1]);
    }
    size++;
    cout << "Освобождение места в массиве: ";
    for (auto i = 0; i < size; i++) cout << arr2[i] << " ";
    cout << endl;
    arr2[point] = number;
    delete[] arr;
    arr = arr2;
    cout << "Ваш новый массив: ";
    for (auto i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    int size = 5;
    int* arr = new int[size] {1, 2, 3, 4, 5};
    cout << "Ваш исходный массив: "; Print(arr, size); cout << "\n\n";
    int point, number;
    cout << "Укажите номер числа из массива (нумерация начинается с 1 - ы): "; cin >> point;
    cout << "Укажите число - замену: "; cin >> number;
    Func(arr, size, point, number);
    cout << "\n\nЗавершение программы!\n\n";
    delete[] arr;
    return 0;
}