#include <iostream>
#include <cstdlib>
#define tab cout << "\n\n"
using namespace std;

void PasteStolb(int**& arr, int x, int y, int point) {
	int** arr2 = new int*[x];//выделение памяти под новый 2d - массив
	cout << "Ввод значений в новый столбец: "; cout << endl;
	for (auto i = 0; i < x; i++) {
		arr2[i] = new int[y + 1];//выделение памяти под новый столбец
		for (auto j = 0; j < y; j++) {
			arr2[i][j] = arr[i][j];//копирование предыдущих элементов матрицы в новую матрицу
		}
		cin >> arr2[i][y];//заполнение нового столбца
	}
	// Удаление старой матрицы
	for (auto i = 0; i < x; i++) {
		delete[] arr[i];
	}
	delete[] arr;
	arr = arr2;
	//увеличение кол - ва столбцов
	y++;
	//переносим в указанную позицию
	for (auto i = 0; i < x; i++) {
		for (auto j = y - 1; j >= point; j--) {
			swap(arr[i][j], arr[i][j - 1]);
		}
	}
	cout << endl;
	cout << "Ваша новая матрица: "; tab;
	for (auto i = 0; i < x; i++) {
		for (auto j = 0; j < y; j++) {
			cout << arr[i][j] << " ";
		}
		tab;
	}
}

void DeleteStolb(int**& arr, int x, int y, int point) {
	point--; //уменьшаем значение point
	for (auto i = 0; i < x; i++) {
		for (auto j = point; j < y - 1; j++) {
			swap(arr[i][j], arr[i][j + 1]); //меняем местами столбец, который нужно удалить, с самым последним столбцом
		}
	}
	int** arr2 = new int*[x]; // создаём новый 2d - массив с меньшим кол-ом столбцов
	for (auto j = 0; j < x; j++) {
		arr2[j] = new int[y - 1];
	}
	for (auto i = 0; i < x; i++) {
		for (auto j = 0; j < y - 1; j++) {
			arr2[i][j] = arr[i][j]; // и записываем в него данные
		}
	}
	y--;
	cout << "Ваша новая матрица: "; cout << endl;
	for (auto i = 0; i < x; i++) {
		for (auto j = 0; j < y; j++) {
			cout << arr2[i][j] << " ";
		}
		tab;
	}
	//Чистим память
	for (auto i = 0; i < x; i++) {
		delete[] arr2[i];
	}
	delete[] arr2;
}

int main() {
	setlocale(LC_ALL, "ru");
	//Задание на добавление нового столбца в указанную позицию
	//
	//
	//
	cout << "Первое задание"; tab;
	int x = 5, y = 5, point;
	//Инициализация 2d - массива и вывод его на экран
	int** arr = new int* [x];
	for (auto i = 0; i < x; i++) {
		arr[i] = new int[y];
	}
	cout << "Ваша исходная матрица: "; tab;
	for (auto i = 0; i < x; i++) {
		for (auto j = 0; j < y; j++) {
			arr[i][j] = rand() % 10;
			cout << arr[i][j] << " ";
		}
		tab;
	}
	tab;
	cout << "Укажите в какую позицию вставить ваш новый столбец: "; cin >> point;
	PasteStolb(arr, x, y, point);
	//Чистка памяти
	for (auto i = 0; i < x; i++) {
		delete[] arr[i];
	}
	delete[] arr;
	tab; tab;
	//Задание на удаление столбца в указанной позиции
	//
	//
	//
	cout << "Второе задание"; tab;
	int X = 5, Y = 5, POINT;
	//Инициализация 2d - массива и вывод его на экран
	int** ARR = new int* [X];
	for (auto i = 0; i < X; i++) {
		ARR[i] = new int[Y];
	}
	cout << "Ваша исходная матрица: "; tab;
	for (auto i = 0; i < x; i++) {
		for (auto j = 0; j < y; j++) {
			ARR[i][j] = rand() % 10;
			cout << ARR[i][j] << " ";
		}
		tab;
	}
	tab;
	cout << "Укажите позицию столбца, который нужно удалить: "; cin >> POINT; tab;
	DeleteStolb(ARR, X, Y, POINT);
	//Чистка памяти
	for (auto i = 0; i < X; i++) {
		delete[] ARR[i];
	}
	delete[] ARR;
	tab;
	cout << "Завершение программы!"; tab;
}