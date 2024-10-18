#include <iostream>
#include <cstdlib>
#define tab cout << "\n\n"
using namespace std;

void PasteLastString(int**& arr, int x, int y) {
	int** arr2 = new int* [x + 1]; //объявление нового динамического массива
	for (auto i = 0; i < x; i++) {
		arr2[i] = arr[i]; //копирование данных из старой матрицы
	}
	arr2[x] = new int[y]; //выделение динамической памяти под последнюю строку
	cout << "Ввод значений в новую строку: "; tab;
	for (auto j = 0; j < y; j++) {
		cin >> arr2[x][j];
	}
	tab;
	x++;
	delete[] arr;
	arr = arr2;
	cout << "Ваша новая матрица: "; tab;
	for (auto i = 0; i < x; i++) {
		for (auto j = 0; j < y; j++) {
			cout << arr[i][j] << " ";
		}
		tab;
	}
}

void PasteFirstString(int**& arr, int x, int y) {
	int** arr2 = new int* [x + 1];
	for (int i = 1; i <= x; i++)
	{
		arr2[i] = arr[i - 1];//копируем и сдвигаем каждую строку вниз на одну позицию исходного массива
	}
	arr2[0] = new int[y];// выделение памяти под первую строку
	cout << "\nВвод значений в новую строку:"; tab;
	for (int j = 0; j < y; j++)
	{
		cin >> arr2[0][j];
	}
	tab;
	x++;
	delete[] arr;
	arr = arr2;
	cout << "Ваша новая матрица: \n";
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			cout << arr[i][j] << " ";
		}
		tab;
	}
}

void PositionString(int**& arr, int x, int y, int point) {
	// Выделение памяти для новой матрицы
	int** arr2 = new int* [x + 1];
	for (int i = 0; i < x + 1; i++) {
		arr2[i] = new int[y];
	}
	point--;
	// Копирование старой матрицы в новую
	for (int i = 0; i < point; i++) {
		for (int j = 0; j < y; j++) {
			arr2[i][j] = arr[i][j];
		}
	}
	// Ввод значений новой строки
	cout << "Ввод значений новой строки: "; tab;
	for (int j = 0; j < y; j++) {
		cin >> arr2[point][j];
	}
	// Копирование оставшейся части старой матрицы в новую
	for (int i = point; i < x; i++) {
		for (int j = 0; j < y; j++) {
			arr2[i + 1][j] = arr[i][j];
		}
	}
	// Удаление старой матрицы
	for (int i = 0; i < x; i++) {
		delete[] arr[i];
	}
	delete[] arr;

	// Обновление указателя
	arr = arr2;

	// Вывод новой матрицы
	cout << endl;
	cout << "Ваша новая матрица: " << endl;
	for (int i = 0; i < x + 1; i++) {
		for (int j = 0; j < y; j++) {
			cout << arr[i][j] << " ";
		}
		tab;
	}
}

void DeleteString(int**& arr, int x, int y, int point) {
	// Выделение памяти для новой матрицы
	int** arr2 = new int* [x - 1];
	for (int i = 0; i < x - 1; i++) {
		arr2[i] = new int[y];
	}
	point--;
	// Копирование старой матрицы в новую (разбиваем на 2 цикла)
	for (int i = 0; i < point; i++) {
		for (int j = 0; j < y; j++) {
			arr2[i][j] = arr[i][j];
		}
	}
	for (int i = point + 1; i < x; i++) {
		for (int j = 0; j < y; j++) {
			arr2[i - 1][j] = arr[i][j]; // Сдвигаем строки на одну вверх
		}
	}

	// Удаление старой матрицы
	for (int i = 0; i < x; i++) {
		delete[] arr[i];
	}
	delete[] arr;

	// Обновление указателя
	arr = arr2;

	// Вывод новой матрицы
	cout << endl;
	cout << "Ваша новая матрица: " << endl;
	for (int i = 0; i < x - 1; i++) {
		for (int j = 0; j < y; j++) {
			cout << arr[i][j] << " ";
		}
		tab;
	}
}

int main() {
	setlocale(LC_ALL, "RU");
	//Задание на добавление строки в конец 2d - массива
	//
	//
	//
	int x = 5, y = 5;
	int** arr = new int* [x];
	//Инициализация и вывод
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
	PasteLastString(arr, x, y);
	//Чистка памяти
	for (auto i = 0; i < x; i++) {
		delete[] arr[i];
	}
	delete[] arr;
	tab;
	//Задание на добавление строки в начало 2d - массива
	//
	//
	//
	int X = 5, Y = 5;
	int** ARR = new int* [X];
	//Инициализация и вывод
	for (auto i = 0; i < X; i++) {
		ARR[i] = new int[Y];
	}
	cout << "Ваша исходная матрица: "; tab;
	for (auto i = 0; i < X; i++) {
		for (auto j = 0; j < Y; j++) {
			ARR[i][j] = rand() % 10;
			cout << ARR[i][j] << " ";
		}
		tab;
	}
	tab;
	PasteFirstString(ARR, X, Y);
	//Чистка памяти
	for (auto i = 0; i < X; i++) {
		delete[] ARR[i];
	}
	delete[] ARR;
	tab;
	//Задание на добавление строки в указанную позицию 2d - массива
	//
	//
	//
	int x1 = 5, y1 = 5;
	int** arr1 = new int* [x1];
	//Инициализация и вывод
	for (auto i = 0; i < x1; i++) {
		arr1[i] = new int[y1];
	}
	cout << "Ваша исходная матрица: "; tab;
	for (auto i = 0; i < x1; i++) {
		for (auto j = 0; j < y1; j++) {
			arr1[i][j] = rand() % 10;
			cout << arr1[i][j] << " ";
		}
		tab;
	}
	tab;
	int point;
	cout << "Укажите в какую позицию вставить вашу строку (нумерование строк начинается сверху, с 1 - цы): "; cin >> point;
	PositionString(arr1, x1, y1, point);
	//Чистка памяти
	for (auto i = 0; i < x1; i++) {
		delete[] arr1[i];
	}
	delete[] arr1;
	tab;
	//Задание на удаление строки в указанной позиции 2d - массива
	//
	//
	//
	int x2 = 5, y2 = 5;
	int** arr2 = new int* [x2];
	//Инициализация и вывод
	for (auto i = 0; i < x2; i++) {
		arr2[i] = new int[y2];
	}
	cout << "Ваша исходная матрица: "; tab;
	for (auto i = 0; i < x2; i++) {
		for (auto j = 0; j < y2; j++) {
			arr2[i][j] = rand() % 10;
			cout << arr2[i][j] << " ";
		}
		tab;
	}
	tab;
	int POINT;
	cout << "Укажите в какую позицию строки, которую нужно удалить(нумерование строк начинается сверху, с 1 - цы): "; cin >> POINT;
	DeleteString(arr2, x2, y2, POINT);
	//Чистка памяти
	for (auto i = 0; i < x2 - 1; i++) {
		delete[] arr2[i];
	}
	delete[] arr2;
	tab;
	cout << "Завершение программы!"; tab;
	return 0;
}