#include <iostream>
#include <iomanip>
#include <bitset>
#include <string>


using namespace std;

void printArray( const int arr[], int size );
string charToBinaryString(char c);
char binaryStringToChar(string binary);

int main(int argc, char* argv[]) {
		cout << "aaaaaaaa " << argv[1] << endl;
		const int P10[10] = { 3, 5, 2, 7, 4, 10, 1, 9, 8, 6 };
		const int P8[8] = { 5, 4, 10, 1, 9, 8, 6, 7 };
		const int expected_output_P10[10] = { 0, 1, 1, 1, 1, 1, 0, 1, 0, 0 };

		int initial_key[10] = { 0, 1, 0, 1, 1, 0, 1, 0, 1, 1 };
		int permutated_key[10];
		
		cout << left << setw(20) << "Initial : ";
		printArray(initial_key, 10);

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
		printArray(permutated_key, 10);
		cout << left << setw(20) << "Expected : ";
		printArray(expected_output_P10, 10);

		// gonna play with permutating a string then return to key generation

		string input = argv[1];
		cout << "Original string: " << input << endl;

		string permutatedString;
		for (char c : input) {
			string binary = charToBinaryString(c);
			cout << "Binary of " << c << left << setw(20) << " : " << binary << endl;

			if (binary.length() != 8) {
				cerr << "Error: Binary string length is not 8!" << endl;
				return 0;
			}

			string extendedBinary = "00" + binary;

			//perform permutation
			string permutatedBinary(10, '0');
			for (int i = 0; i < 10; i++) {
				int targetBit = P10[i] - 1;
				permutatedBinary[i] = extendedBinary[targetBit];
			}

			cout << left << setw(20) << "Permuted Binary: " << permutatedBinary << endl;

			permutatedString += binaryStringToChar(permutatedBinary); 
		}

		cout << "Permutated string : " << permutatedString << endl;

		return 0;
}

void printArray( const int arr[], int size ) {

	for (int i = 0; i < size; i++) {
		if (i < 9) {
			cout << arr[i] << ", ";
		} else {
			cout << arr[i] << endl;
		}
		
	}
	return;
}

string charToBinaryString(char c) {
	return bitset<8>(c).to_string();
}

char binaryStringToChar(string binary) {
	bitset<8> b(binary.substr(2, 8));
	return static_cast<char>(b.to_ulong());
}

