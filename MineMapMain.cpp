/*
* MineMapMain.cpp
* 
* Date: 5-26-23
* Author: Klaudia Sopas
*/

#include<iostream>
#include<cstdlib>
#include<time.h>

using namespace std;

// Creates a minesweeper map sized 12x24
// Mines are placed randomly each run with a probability of 1 in 6
int main() {
	int col = 12;
	int row = 24;
	int arr[12][24];
	srand(time(0));

	// intialize array
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			// generate random number (-1-5)
			// % # sets probability of a mine
			int r = (rand() % 7) - 1;

			// if r is not -1 set to 0
			// -1 will indicate a mine
			if (r != -1) {
				r = 0;
			}

			// set element equal to r
			arr[i][j] = r;
		}
	}

	// indicate number of mines touching each element
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			if (arr[i][j] != -1) {
				int c = 0;

				if ((i - 1) >= 0) {
					if ((j - 1) >= 0) {
						if (arr[i - 1][j - 1] == -1) {
							c += 1;
						}
					}

					if (arr[i - 1][j] == -1) {
						c += 1;
					}

					if ((j + 1) < row) {
						if (arr[i - 1][j + 1] == -1) {
							c += 1;
						}
					}
				}

				if ((j - 1) >= 0) {
					if (arr[i][j - 1] == -1) {
						c += 1;
					}
				}

				if ((j + 1) < row) {
					if (arr[i][j + 1] == -1) {
						c += 1;
					}
				}

				if ((i + 1) < col) {
					if ((j - 1) >= 0) {
						if (arr[i + 1][j - 1] == -1) {
							c += 1;
						}
					}

					if (arr[i + 1][j] == -1) {
						c += 1;
					}

					if ((j + 1) < row) {
						if (arr[i + 1][j + 1] == -1) {
							c += 1;
						}
					}
				}

				arr[i][j] = c;
			}
		}
	}
	// print array
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			if (arr[i][j] == -1) {
				cout << "X";
			}
			else {
				cout << arr[i][j];
			}
		}

		cout << endl;
	}
	return 0;
}