#include<iostream>

// prvi
void fun(int* arr, int len, int& min, int& max) {
	for (int i = 0; i < len; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}

		if (arr[i] < min) {
			min = arr[i];
		}
	}

}

int main() {
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int len = sizeof(arr)/sizeof(arr[0]);
	int min = 10000;
	int max = 0;
	fun(arr, len, min, max);

	std::cout << "min je: " << min << std::endl;
	std::cout << "max je: " << max << std::endl;

	return 0;
}