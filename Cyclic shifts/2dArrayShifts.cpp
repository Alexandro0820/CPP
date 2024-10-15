//Циклические сдвиги в 2d - массиве
#include <iostream>
#include <cstdlib>

using namespace std;

void LeftChangeOfStroki(int**&arr, int x, int y) {
	int step;
	cout << "Укажите кол - во шагов: "; cin >> step;
	for (auto f = 0; f < step; f++) {
		for (auto i = 0; i < x; i++) {
			for (auto j = 0; j < y - 1; j++) {
				swap(arr[i][j], arr[i][j + 1]);
			}
		}
	}
	cout << "\n\n";
	cout << "Ваша новая матрица: \n";
	for (auto i = 0; i < x; i++) {
		for (auto j = 0; j < y; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl << endl;
	}
}

void RightChangeOfStroki(int**& arr, int x, int y) {
	int step;
	cout << "Укажите кол - во шагов: "; cin >> step;
	for (auto f = 0; f < step; f++) {
		for (auto i = 0; i < x; i++) {
			for (auto j = y - 1; j > 0; j--) {
				swap(arr[i][j], arr[i][j - 1]);
			}
		}
	}
	cout << "\n\n";
	cout << "Ваша новая матрица: \n";
	for (auto i = 0; i < x; i++) {
		for (auto j = 0; j < y; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl << endl;
	}
}

void TopChangeOfStolbi(int**& arr, int x, int y) {
	int step;
	cout << "Укажите кол - во шагов: "; cin >> step;
	for (auto f = 0; f < step; f++) {
		for (auto i = 0; i < x - 1; i++) {
			for (auto j = 0; j < y; j++) {
				swap(arr[i][j], arr[i + 1][j]);
			}
		}
	}
	cout << "\n\n";
	cout << "Ваша новая матрица: \n";
	for (auto i = 0; i < x; i++) {
		for (auto j = 0; j < y; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl << endl;
	}
}

void BottomChangeOfStolbi(int**& arr, int x, int y) {
	int step;
	cout << "Укажите кол - во шагов: "; cin >> step;
	for (auto f = 0; f < step; f++) {
		for (auto i = x - 1; i > 0; i--) {
			for (auto j = 0; j < y; j++) {
				swap(arr[i][j], arr[i - 1][j]);
			}
		}
	}
	cout << "\n\n";
	cout << "Ваша новая матрица: \n";
	for (auto i = 0; i < x; i++) {
		for (auto j = 0; j < y; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl << endl;
	}
}

int main() {
	setlocale(LC_ALL, "RU");
	int change; char vector;
	const int X = 5, Y = 5;
	//выделение динамической памяти под 2d - массив
	int**arr = new int* [X]; 
	for (int i = 0; i < X; i++) {
		arr[i] = new int[Y];
	}
	//инициализация и вывод
	cout << "Ваша исходная матрица: \n";
	for (auto i = 0; i < X; i++) {
		for (auto j = 0; j < Y; j++) {
			arr[i][j] = rand() % 10;
			cout << arr[i][j] << " ";
		}
		cout << endl << endl;
	}
	//тело программы и весь её функционал
	cout << "Выберите объекты изменений (1 - строки, 2 - столбцы): "; cin >> change;
	switch (change){
	case 1:
		cout << "\nИзменения строк!\n\n";
		cout << "Укажите направление (l - влево, r - вправо): "; cin >> vector;
		switch (vector){
		case 'l':
		case 'L':
			cout << "\nНаправление влево!\n\n";
			LeftChangeOfStroki(arr, X, Y);
			break;
		case 'r':
		case 'R':
			cout << "\nНаправление вправо!\n\n";
			RightChangeOfStroki(arr, X, Y);
			break;
		default:
			cout << "Направление не опознано!";
			break;
		}
		break;
	case 2:
		cout << "\nИзменения столбцов!\n\n";
		cout << "Укажите направление (t - вверх, b - вниз): "; cin >> vector;
		switch (vector){
		default:
		case 'T':
		case 't':
			cout << "\nНаправление вверх!\n\n";
			TopChangeOfStolbi(arr, X, Y);
			break;
		case 'B':
		case 'b':
			cout << "\nНаправление вниз!\n\n";
			BottomChangeOfStolbi(arr, X, Y);
			break;
		}
		break;
	default:
		cout << "Объект не распознан!";
		break;
	}
	//чистка памяти
	for (int i = 0; i < X; i++)
		delete[] arr[i];
	delete[] arr;
	return 0;
}