#include <iostream>
#include <string>
using namespace std;

bool isWon(char, char[][3]);
bool isDraw(char[][3]);
void displayBoard(char[][3]);
void makeAMove(char[][3], char);
int rows = 3, cols = 3;
string options = "XO";
int main() {
	//
	//	PLEASE DO NOT CHANGE function main
	//
	char board[3][3] = { { ' ', ' ', ' ' },{ ' ', ' ', ' ' },{ ' ', ' ', ' ' } };
	displayBoard(board);
	while (true) {
		// The first player makes a move
		makeAMove(board, 'X');
		displayBoard(board);
		if (isWon('X', board)) {
			cout << "X player won" << endl;
			exit(0);
		}
		else if (isDraw(board)) {
			cout << "No winner" << endl;
			exit(0);
		}

		// The second player makes a move
		makeAMove(board, 'O');
		displayBoard(board);

		if (isWon('O', board)) {
			cout << "O player won" << endl;
			exit(0);
		}
		else if (isDraw(board)) {
			cout << "No winner" << endl;
			exit(0);
		}
	}

	return 0;
}
/* { ' ', ' ', ' ' }, { ' ', ' ', ' ' }, { ' ', ' ', ' ' }

{ 0,0, 0,1, 0,2 }
{ 1,0, 1,1, 1,2 }
{ 2,0, 2,1, 2,2 }

*/

bool isWon(char c, char board[][3]) {
	int rdiag = 0, ldiag = 0, temp = rows - 1;
	for (int i = 0; i < rows; i++) {
		int row = 0, col = 0;
		board[i][i] == c && rdiag++;
		board[i][temp--] == c && ldiag++;
		if (ldiag == rows || rdiag == rows) return true;
		for (int j = 0; j < cols; j++) {
			board[j][i] == c && col++;
			board[i][j] == c && row++;
			if (col == rows || row == cols) return true;
		}
		cout << endl;
	}
	return false;
}

bool isDraw(char board[][3]) {
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++) if (board[i][j] != options[0] && board[i][j] != options[1]) return false;
	return true;
}

void displayBoard(char board[][3]) {
	cout << "-----------" << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) 
			cout << board[i][j] << " | ";
		cout << endl;
	}
	cout << "-----------" << endl;
}

void makeAMove(char board[][3], char input) {
	bool valid_move = true;
	int r, c;
	do {
		valid_move = true; 
		cout << "Enter a row (0, 1, 2) for player " << input << ": ";
		cin >> r;
		if (!cin || r > 2 || r < 0) exit(1);
		cout << "Enter a column(0, 1, 2) for player " << input << ": ";
		cin >> c;
		if (!cin || c > 2 || c < 0) exit(1);
		if(valid_move) for (auto& x : options) if (board[r][c] == x) valid_move = false;
	} while (!valid_move);
	board[r][c] = input;
}