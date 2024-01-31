#include <iostream>
#include <time.h>
#include <string>

#define m 6
#define n 7

using namespace std;

string matrToString(int matrix[][n]);
string find_columns_with_sequence(int matrix[m][n]);
int get_rows_with_sequence(int matrix[m][n], int* outp);

int main() {
	srand(time(0));
	int matrix[m][n] = {
		{1,2,3,4,5,6,7},
	{2,6,5,4,7,2,9},
	{3,-2,7,-4,9,-6,11},
	{4,4,9,8,11,12,13},
	{5,-6,11,13,13,-2,15},
	{6,7,13,14,15,16,17}
	};
	cout << "Matrix:" << endl;
	cout << matrToString(matrix);

	string columns = find_columns_with_sequence(matrix);
	int rowsI[n];
	int k = get_rows_with_sequence(matrix, rowsI);
	for (int i = 0; i < k; i++) {
		cout << rowsI[i];
	}
	
	cout << "\n\n\nColums with sequence: "  << columns << "\n";


	return 0;
}
string find_columns_with_sequence(int matrix[m][n]) {
	string s = "";
	for (int i = 0; i < n; i++) {
		bool flag = true;
		for (int j = 1; j < m-1; j++) {
			if (!((matrix[j-1][i] < matrix[j][i] && matrix[j][i] < matrix[j+1][i]) ||
				(matrix[j - 1][i] > matrix[j][i] && matrix[j][i] > matrix[j + 1][i]))) {
				flag = false;
				break;
			}
		}
		if (flag) {
			s += to_string(i + 1) + " ";
		}
	}

	return s;
}
int get_rows_with_sequence(int matrix[m][n], int* outp) {
	string s = "";
	int k = 0;
	for (int i = 0; i < m; i++) {
		bool flag = true;
		for (int j = 1; j < n-1; j++) {
			if (!((matrix[i][j - 1] < matrix[i][j] && matrix[i][j] < matrix[i][j + 1]) ||
				(matrix[i][j - 1] > matrix[i][j] && matrix[i][j] > matrix[i][j + 1]))) {
				flag = false;
				break;
			}
		}
		if (flag) {
			outp[k] = i + 1;
			k++;
		}
	}
	return k;
}