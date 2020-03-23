#include <iostream>

using namespace std;

template <typename T>T *CopyArr(T *arr1, size_t size) {
	T* array = new int[size + 1];
	for (size_t i = 0; i < size; i++) {
		array[i] = arr1[i];
	}
	delete[] arr1;
	return array;
}
template <typename T>bool RepeatElm(T *array1, T index, int sizeArray1) {
	for (size_t i = 0; i < sizeArray1; i++) {
		if (index == array1[i]) return false;
	}
	return true;
}


template<typename T>T *GetArr(T *arr, int size) {
	for (size_t i = 0; i < size; i++) {
		arr[i] = rand() % 10;
	}
	return arr;
}

void Task1() {
	size_t n, m, k = 1;
	cout << "Enter N = "; cin >> n;
	int *A = new int[n];
	A = GetArr(A, n);
	cout << "Enter M = "; cin >> m;
	int *B = new int[m];
	B = GetArr(B, m);
	int* C = new int[k];
	if (m == 0) {
		for (size_t i = 0; i < n; i++) {
			if (RepeatElm(C, A[i], k)) {
				C[k - 1] = A[i];
				C = CopyArr(C, k);
				k++;
			}
		}
	}
	else {
		for (size_t i = 0; i < n; i++) {
			for (size_t j = 0; j < m; j++) {
				if (A[i] == B[j]) {
					break;
				}
				if (j == (m - 1)) {
					if (RepeatElm(C, A[i], k)) {
						C[k - 1] = A[i];
						C = CopyArr(C, k);
						k++;
					}
				}
			}
		}
	}
	cout << "Array A = { ";
	for (size_t i = 0; i < n; i++) {
		cout << A[i] << " ";
	}
	cout << "}" << endl;
	cout << "Array B = { ";
	for (size_t i = 0; i < m; i++) {
		cout << B[i] << " ";
	}
	cout << "}" << endl;
	cout << "Array C = { ";
	for (size_t i = 0; i < k - 1; i++) {
		cout << C[i] << " ";
	}
	cout << "}" << endl;
	cout << "\nSize of the resulting array = " << k - 1 << endl;
	delete[] A;
	delete[] B;
	delete[] C;
}
int main() {
	Task1();



	return 0;
}