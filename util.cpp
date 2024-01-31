#include <iostream>
#include <time.h>
#include <string>

#define m 6
#define n 7

using namespace std;

string matrToString(int matrix[][n]) {
	string s = "";
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			s = s + to_string(matrix[i][j]) + "\t";
		}
		s += "\n";
	}
	return s;
}
