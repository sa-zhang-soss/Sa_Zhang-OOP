#include<iostream>

// prvi
int funk(int* arr, int len,int& min, int& max) {


}
// treci
typedef struct vector {
	int actual_size;
	int logical_size;
	int* array;

	vector new_vector(int len) {
		int* arr = new int[len];

		logical_size = len;
		actual_size = 0;

		array = arr;
	}
	void push_back(int el) {
		array[actual_size] = el;

		actual_size++;
	}

	int front() {
		return array[0];
	}

	int back() {
		return array[actual_size - 1];
	}

}vector;


typedef struct test {
	int a;
	char b;
	int *niz;
}test;

test pov_t(test par) {
	test t = { 5, 'a' };
}

int main() {
	test t;
	t.a = 5;
	t.b = 'c';
	//t.niz = (int*)malloc(10 * sizeof(int));
	t.niz = new int[10];

	int niz[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	test* bbbb = new test[10];
	bbbb->a;


	return 0;
}



// uvod 
int* f(int len, int& a) {

//	int* new_arr = (int*)malloc(len * sizeof(int));
	int* new_arr = new int[10];

	int* new_arr = new int[len];

	delete(new_arr);
	

	new_arr = NULL;

	if (new_arr == NULL) {
		return NULL;
	}
	for (int i = 0; i < len; i++) {
		scanf("%d", &new_arr[i]);
	}
}

int main() {
	int a = 0;
	int* retVal = f(5, a);


	return 0;
}