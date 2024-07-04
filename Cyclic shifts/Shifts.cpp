//Циклические сдвиги в С++

#include <iostream>

using namespace std;

inline void Print(int arr[], int size) {
	for (int i = 0; i < size; i++) cout << arr[i] << " ";
}
inline void Left(int arr[], int size, int step) {
	int temp = 0;
	for (int i = 0; i < step; i++) {
		for (int i = 0; i < size - 1; i++) {
			temp = arr[i]; arr[i] = arr[i + 1]; arr[i + 1] = temp;
			/*swap(arr[i], arr[i + 1]);*/ // вариант попроще
		}
	}
}
inline void Right(int arr[], int size, int step) {
	int temp = 0;
	for (int k = 0; k < step; k++) {
		for (int i = size - 1; i > 0; i--) {
			temp = arr[i]; arr[i] = arr[i - 1]; arr[i - 1] = temp;
			/*swap(arr[i], arr[i - 1]);*/ // вариант попроще
		}
	}
}

int main() {
	setlocale(LC_ALL, "RU");
	const int size = 5; int arr[size] = { 1, 2, 3, 4, 5 };
	cout << "Ваш массив: "; Print(arr, size); cout << "\n\n";
	int step; cout << "Введите кол - во шагов: "; cin >> step;
	char sym; cout << "\nВыберите направление (L - влево; R - вправо): "; cin >> sym; cout << "\n";
	switch (sym){
	case 'L':
	case 'l':
		cout << "Направление - влево на " << step << " шаг(-а)\n";
		Left(arr, size, step); 
		cout << "\nВаш новый массив: "; Print(arr, size);
		break;
	case 'R':
	case 'r':
		cout << "Направление - вправо на " << step << " шаг(-а)\n";
		Right(arr, size, step); 
		cout << "\nВаш новый массив: "; Print(arr, size);
		break;
	default:
		cout << "Ошибка ввода!\n";
		break;
	}
	cout << "\n\n";
	return 0;
}