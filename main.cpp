#include <iostream>
#include <iomanip>
#include <bitset>
#include <string>


using namespace std;

void printArray( const int arr[] );

int main() {

		const int P10[10] = { 3, 5, 2, 7, 4, 10, 1, 9, 8, 6 };
		const int P8[8] = { 5, 4, 10, 1, 9, 8, 6, 7 };
		const int expected_output_P10[10] = { 0, 1, 1, 1, 1, 1, 0, 1, 0, 0 };

		int initial_key[10] = { 0, 1, 0, 1, 1, 0, 1, 0, 1, 1 };
		int permutated_key[10];
		
		cout << left << setw(20) << "Initial : ";
		printArray(initial_key);

		// FIRST P10 PERMUTATION
		for (int i = 0; i < 10; i++) {
			int targetBit = P10[i] - 1;
			permutated_key[i] = initial_key[targetBit]; 

			// if i = 0, targetBit = 3, permutated_key[0] = initial_key[3];
			// eg: 
			//     initial_key = 11010
			//     p10         = {3,4,5,1,2}
			//     output:     = 01011
		}

		cout << left << setw(20) << "Permutated : ";
		printArray(permutated_key);
		cout << left << setw(20) << "Expected : ";
		printArray(expected_output_P10);

		// P8 PERMUTATION

		return 0;
}

void printArray( const int arr[] ) {

	for (int i = 0; i < 10; i++) {
		if (i < 9) {
			cout << arr[i] << ", ";
		} else {
			cout << arr[i] << endl;
		}
		
	}
	return;
}