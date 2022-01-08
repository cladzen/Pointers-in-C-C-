#include "bits/stdc++.h"
using namespace std;

void increment(int z) {
	z = z + 1;
	cout << &z << '\n';
}

void increment_by_reference(int* z) {
	*z = (*z) + 1;
	cout << z << '\n';
}

// arrays are always pased as call by reference
int sum_of_elements(int arr[], int n) { // this is same as int sum_of_elements(int* arr, int n)
	// we cannot use sizeof(arr) / sizeof(arr[0]) here to calculate the size of the array
	// because arr is no the array but a pointer basically and c++ just passes the pointer and not the entire array
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
	}

	arr[0] += 10;

	return sum;
}

int main(int argc, char **argv) {
	cout << sizeof(int) << '\n';
	cout << sizeof(char) << '\n';
	cout << sizeof(float) << '\n';
	cout << sizeof(double) << '\n';
	cout << sizeof(long int) << '\n';
	cout << sizeof(long long int) << '\n';
	cout << sizeof(int64_t) << '\n';
	cout << sizeof(int32_t) << '\n';

	int a = 10;
	int* p = &a; // integer pointer storing address of the int a

	// prints the address stored inside the pointer i.e., address of a
	cout << p << '\n';

	// dereferencing
	cout << *p << '\n';
	*p = 20; // changing values using pointers

	cout << &a << '\n'; // prints the address of the integer variable in the memory
	cout << &p << '\n'; // prints the address of the pointer variable in the memory
	cout << *p << '\n';

	cout << p << '\n';
	cout << p + 1 << '\n';
	cout << *(p + 1) << '\n';

	/* pointers are strongly typed */
	// this is because we not only have to store the address
	// we have to dereference with the help of pointers

	// cout << *p this means look at 4 bytes (in case of integer pointer) starting at index stored in p

	int x = 1025;
	int* ptr = &x;

	cout << *ptr << '\n';

	char* cptr = (char*)ptr;
	cout << *cptr << '\n';
	cout << *(cptr + 1) << '\n';
	cout << *(cptr + 2) << '\n';
	cout << *(cptr + 3) << '\n';

	// void pointer - generic pointer

	void *p0; // this can be used to store addressed of any type
	p0 = &x;
	cout << p0 << '\n';
	// cout << *p0 << '\n'; this will give us an error
	// but we cannot use this to dereference

	// pointer to pointer

	int y = 5;
	int *yptr = &y;

	*yptr = 6;

	int **yptrptr = &yptr;

	**yptrptr = 7;

	int ***yptrptrptr = &yptrptr;

	***yptrptrptr = 8;

	cout << y << '\n';

	// pointers as function arguments - call by reference

	int z = 10;
	increment(z); // this is call by value
	cout << &z << '\n'; // this will have a different address than the one inside the function increment

	increment_by_reference(&z); // this is call by reference
	cout << &z << '\n'; // this will have the same address as the one inside the function increment_by_reference

	// pointers and arrays

	int arr[5] = {1, 2, 3, 4, 5};
	cout << arr << '\n'; // arr stores the address of the starting element of the array
	cout << arr + 1 << ' ' << arr[0] << '\n'; // this is equivalent to *(arr + 0)
	cout << arr + 2 << ' ' << arr[1] << '\n'; // this is equivalent to *(arr + 1)

	// &a[i] is same as a + i
	// a[i] is same as *(a + i)

	// we cannot do a++ because a stores the value of the start of the array and you cannot change it
	// it will give you a compilation error

	int* myptr = &a;
	myptr++; // although this is valid

	// arrays as function argument

	cout << sizeof(ptr) << '\n';

	int n = sizeof(arr) / sizeof(int); // this is one way to calculate the size of an array
	int tot = sum_of_elements(arr, n);
	cout << tot << '\n';

	cout << arr[0] << '\n'; // this will become 11

	cout << ptr[1] << '\n'; // wow i just discovered this 
	// this actually works for all the pointers and not just arrays
	// this means *(ptr + 1)

	return 0;
}
