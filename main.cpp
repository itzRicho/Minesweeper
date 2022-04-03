#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
	cout << "Welcome to Minesweeper \n";
	cout << "There are 20 mines to find." << endl;


	return true;
}

// Function responsible for rendering the game board on the screen.
void gameBoard() {
	// Two nested 'for loops' to consecutively determine the array formation.
	// populationArray is the array responsible for populating the game board.
	// mineArray is the array responsible for placing the 'X' over the mines and numbers on the screen.
	// All spaces on the game board are populated with numbers.
	// Nine is the highest possible value, this represents the mine on the game board.
	
	// 'i' represents the row index. (x axis)
	// 'j' represents the column index. (y axis)
	int populationArray[10][10];
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			populationArray[i][j];
		}
	}

	string  line = "     0    1    2    3    4    5    6    7    8    9";

	// Displays the placeholder value of 'X' on the game board.
	// This places them across the horizontal and vertical axis.
	char bufferArray[10][10];
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			bufferArray[i][j];
		}
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			populationArray[j][i];
		}
	}

	// Use srand as a seed generator to fill the spaces in the grid.
	srand(time(NULL));

	// Dynamically load the mines on the board.
	for (int m = 0; m < 9; m++) {
		int xEntry = rand() % 9;
		int yEntry = rand() % 9;

		// Utilises a 2D array to populate values all over the board.
		// Variable 'x' and xEntry represents the row index.
		// Variable 'y' and yEntry represents the column index.

		// This line is responsible for placing the mines on the board.
		populationArray[xEntry][yEntry] = 9;

		// The board generation is broken into eight zones.

		// Zone 1 - Right portion.
		if (xEntry < 9 && populationArray[xEntry + 1][yEntry] != 9) {
			populationArray[xEntry + 1][yEntry]++;
		}

		// Zone 2 - Top left portion.
		if (xEntry > 0 && yEntry > 0 && populationArray[xEntry - 1][yEntry - 1] != 9) {
			populationArray[xEntry - 1][yEntry - 1]++;
		}

		// Zone 3 - Left portion.
		if (xEntry > 0 && populationArray[xEntry - 1][yEntry] != 9) {
			populationArray[xEntry - 1][yEntry]++;
		}

		// Zone 4 - Bottom left portion.
		if (xEntry > 0 && yEntry < 9 && populationArray[xEntry - 1][yEntry + 1] != 9) {
			populationArray[xEntry - 1][yEntry + 1]++;
		}

		// Zone 5 - Bottom portion.
		if (xEntry > 9 && populationArray[xEntry + 1][yEntry - 1] != 9) {
			populationArray[xEntry + 1][yEntry - 1]++;
		}

		// Zone 6 - Bottom right poriton.
		if (xEntry < 9 && yEntry < 9 && populationArray[xEntry + 1][yEntry + 1] != 9) {
			populationArray[xEntry + 1][yEntry + 1]++;
		}

		// Zone 7 - Top centre portion.
		if (xEntry > 0 && populationArray[xEntry][yEntry - 1] != 9) {
			populationArray[xEntry][yEntry - 1]++;
		}

		// Zone 8 - Top right portion.
		if (xEntry < 9 && yEntry > 0 && populationArray[xEntry + 1][yEntry - 1] != 9) {
			populationArray[xEntry + 1][yEntry - 1]++;
		}
	}

	// While loop is implemented to keep the game open until the player fines a mine.
	// gameRunning loop is true until the condition changes.

	bool gameRunning = true;

	while (gameRunning) {
		cout << line << endl << "0";
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				cout << "    " << populationArray[j][i];
			}

			// Generates the column indexes from 0 to 9.
			cout << "\n";
			if (i < 9) {
				cout << i + 1;
			}
		}

		// Implementation of while loop keeps the game running until a player fines a mine.
		// Declaration of gamRunningInput variable is instantiated by default until a condition changes it.

		bool gameRunningIntput = true;

		// User input object.
		char userValue;

		// Mine object.
		int mine;

		int x, y;
		cout << "  \n";
		cout << "  \n";

		cout << "Would you like to (r)eveal or (m)ark? \n";
		while (gameRunningIntput) {
			cin >> userValue;
			if (userValue == 'r') {
				gameRunningIntput = false;
				cout << "You have chosen to reveal. \n";
				cout << "  \n";

				cout << "What column do you want to reveal? \n";
				cin >> x;

				cout << "What row do you want to reveal? \n";
				cin >> y;

			}
		}
	}
}