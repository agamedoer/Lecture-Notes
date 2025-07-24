#include <iostream>

void drawBoard(char board[])
{
	for (size_t i = 0; i < 9; i++)
	{
		if (i % 3 == 0) std::cout<<"\n _ _ _\n";
		std::cout <<"|"<< board[i];
	}
	std::cout << "\n";
}

bool makeMove(char currentPlayer, int position, char board[])
{
	if (position >= 0 && position <= 9)
	{
		if (board[position] == ' ')
		{
			board[position] = currentPlayer;
			return true;
		}
		else {
			std::cout << "Inavlid Move Selected! \n";
			return false;
		}
	}
	else
	{
		std::cout << "Inavlid Move Selected! \n";
		return false;
	}
}

bool checkElements(int a, int b, int c, char board[])
{
	if (board[a] == board[b] && board[a] == board[c] && board[a] != ' ')
	{
		std::cout << board[a] << " has won! \n";
		return true;
	}
	return false;
}

bool checkBoard(char board[])
{
	int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 0, 3, 6, 1, 4, 7, 2, 5, 8, 0, 4, 8, 2, 4, 6 };
	for (int i = 0; i < 24; i += 3)
	{
		if (checkElements(arr[i], arr[i + 1], arr[i + 2], board))
		{
			return true; // Found a winner
		}
	}
	
	for (int i = 0; i < 9; i++)
	{
		if (board[i] == ' ') break;
		else if (i == 8)
		{
			std::cout << "Game has ended in a draw! \n";
			return true;
		}
	}
	return false; // No winner found after checking all
}

int main()
{
	char currentPlayer = 'X';
	bool gameover = false;

	char board[9];
	for(int i = 0; i<9; i++)
	{
		board[i] = ' ';
	}

	drawBoard(board);
	while (gameover == false)
	{
		//call to drawBoard
		// while loop that calls makeMove
		//updating currentPlayer
		
		bool validMove = false;
		while (validMove == false)
		{
			std::cout << "Player " << currentPlayer << ": Enter a position to make your move \n";
			int pos;
			std::cin >> pos;
			validMove = makeMove(currentPlayer, pos, board);
		}
		drawBoard(board);
		if (currentPlayer == 'X') currentPlayer = 'O';
		else currentPlayer = 'X';
		gameover = checkBoard(board);
	}

}
