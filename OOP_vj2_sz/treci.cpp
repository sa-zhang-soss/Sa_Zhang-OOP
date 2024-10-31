#include<iostream>

typedef struct vector {
	int actual_size;
	int logical_size;
	int* array;

	void new_vector(int len) {
		array = new int[len];
		logical_size = len;
		actual_size = 0;
	}

	void delete_vector(){
		delete[] array;
	}

	void push_back(int el) {
		if (actual_size == logical_size) {
			int* new_array = new int[logical_size * 2];

			for (int i = 0; i < actual_size; i++) {
				new_array[i] = array[i];
			}
			delete[] array;
			array = new_array;
		}
		array[actual_size] = el;
		actual_size++;

	}
	
	void pop_back() {
		actual_size--;
	}

	int front() {
		return array[0];
	}

	int back() {
		return array[actual_size - 1];
	}

	int vector_size() {
		return actual_size;
	}

}vector;

int main() {
	vector vec;

	vec.new_vector(5);
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	std::cout << "nakon push_back : " << vec.back() << std::endl;
	vec.pop_back();
	std::cout << "nakon pop_back : " << vec.back() << std::endl;
	std::cout << "prvi element: " << vec.front() << std::endl;
	std::cout << "stvarna velicina: " << vec.vector_size() << std::endl;

	vec.delete_vector();

	return 0;
}