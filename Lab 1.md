Practice Tasks
--------------
1. Create a new Visual Studio C++ console project; you can use the same project to complete this section, just clean the `main` function after each task and save any code you will like to revisit later in a separate document. Copy the code provided below to the `Source.cpp` file of the project you created, then update it so that a greeting is printed to the console whenever the user inputs a name. For example, if the user inputs the name "Mike", then print "Hi Mike!" or "Good morning Mike!".
   
~~~cpp
#include <iostream>

int main()
{
	std::string name; //string variable to store user name

	std::cout << "What is your name? \n";  //ask user for input
	std::cin >> name;  //store input

	return 0;
}
~~~

2. Run the program below. What error does the compiler show? Why does the error occur and how can it be fixed?
~~~cpp
#include <iostream>

int main()
{
	const int answer = 0;
	int a = 1;
	int b = 2;

	answer = a + b;
}
~~~

3. Write a simple program that simulates a shop menu by asking the user to enter a number to choose an item (for example: 1-Bread, 2-Gloves, 3-Sword), uses an if-else statement to check if the number is associated with a valid item and then print a message to confirm their choice. If the input is invalid, print a message asking the user to select a valid item.
4. Refactor the code from the last task to use a switch statement instead of an if-else statement.
5. Write a function with the name `squareNumber` which has a single integer number as its parameter, and returns the square of the argument it recieves. Test it in the `main` function of your program. If you need help starting, use the `timesTwo()` example function from the lecture slides.
6. Write a function with the name `powerNumber` with two parameters, a double number and an integer power, and a double return type. Test it with some small input values, e.g. `powerNumber(2.0, 3)` means 2.0 to the power of 3 (return 8.0) and `powerNumber(3.0, 4)` means 3.0 to the power of 4 (return 81.0). Hint: Use a loop inside the function.

    Side Quest: See what happens if you give it some larger numbers, for example, 13.0, 12 (expect 23298085122481.0). Is the answer now incorrect, and if so, can you work out why this is?

7. Write a C++ program that continuously prompts the user for input and only stops running when the user types the string "end". Hint: Use a while loop.

8.	Write a program that tracks the user's position on a 2D grid starting at coordinates (0, 0). When the user enters "north", "south", "east", or "west", update the coordinates accordingly. The program should continue to prompt for input and display the current position until the user enters "end", which will terminate the program. Store the cordinates in a 2 element integer array.
   
9.	Write a C++ program to display the following shapes using asterisks (*): a right-angled triangle, a pyramid, and a diamond. Use nested for loops and the modulus (%) operator; the maximum size of the shapes should be 20 by 10 characters.
    
10.	Write a program that asks the user for an integer number as input, then tests whether the number is a prime number. There are some ways to speed this calculation up, but for now just use the ‘brute force’ method of test division. Test your program with some known values (e.g. primes 3, 5, 13, 1327, not primes 2, 15, 20, 1323). Test how large you can go with your inputs.

11.	Write a program that asks a user for an integer number, then uses a loop to identify prime numbers between 1 and the input number. 

Main Activity - Noughts and Crosses
------------
1. By the end of this activity you should have a simple noughts and crosses game that runs in the console. Create a new Visual Studio C++ empty project, add a new file `main.cpp` to the `Source Files` folder and add an empty `main` function to it, you can copy the hello world example from the slides and delete the print statement inside the main function. In the next steps, we will use a `char` array to store the game board, define functions to draw the board in the console, get user input and place player moves on the board, and check the board for win/loss/draw conditions. These functions will be called in a while-loop to keep the game going until a player wins or no more valid moves are left.

2. Declare a 9 element `char` array named `board` in the `main` function. This will be used to represent the game board; use a for-loop to initialise all elements of `board` to ' '. Then declare a `char currentPlayer` and initialise it to 'X', and `boolean gameover` and initialise it to `false`.

3. Outside of the `main` function, define a function named `printBoard`. The function should have one paramter, a `char` array named `board` and return void. Inside the funtion, print `board` to the console as a 3 by 3 grid of `char` (first row elements: 0 1 2, second rowelemnts: 3 4 5, third row elemnts: 6 7 8). To simplify our task, we will assume that the `board` will always have 9 elements. Print the `|` character after the first and second elements in each row, and print `---|---|---` after the first and second rows, this should make the board easier to read. Hint: use a for loop and the % operator.

4. Test `printBoard` by drawing a board intialised with random `chars`, make sure it works before moving to the next step.

5. Now define another function called `makeMove` which has the following parameters: `char currentPlayer`, `int position`, and  `char board[]` and returns a boolean. First it checks to see that position is non-negative and it is less than 9, if not then it  prints out a message to say an invalid move has been made and returns false. Then it checks the `board` element in index `position`, if its ' ', then it is replaced by `currentPlayer` and the function returns true, else it prints out a message to say an invalid move has been made and returns false.

6. Let's now test the above function to see that it works. In your `main` method, after `printBoard` is called, define a boolean named `validMove` initialised to `false` and add a while loop that executes as long as `validMove` is `false`. Inside the while loop print out an appropriate message to prompt the current player to choose a position for their next move (use the value of `currentPlayer` to determine whose whethe its it X's or O's turn). Then use `cin` take the user input, store it in a local int called `pos`, and call `makeMove` with `currentPlayer`, `pos`, and `board` as arguments while assigning the boolean it returns to `validMove`. Outside the of while loop, update the value of `currentPlayer` - if its `X` update it to `O`, if its `O` update it to `X`. Run the program to test it. Inputting invalid moves will lead to an invalid move message being printed out, followed by a drawing of the board and a prompt to make another move. Valid moves on the other hand, will end the program - let's fix that in the next step.

8. To make sure the game does not end after every valid input, we will create a game-loop by moving all the code we have added after initialising the board array into a while loop that runs as long as `gameover` is false. Your main function will now look something like this

~~~cpp
int main()
{
	char currentPlayer = 'X';
	bool gameover = false;

	char board[9];
	for(int i = 0; i<9; i++)
	{
		board[i] = ' ';
	}

	while (gameover == false) //game-loop
	{
		//call to printBoard
		//while loop that calls makeMove
		//updating currentPlayer
	}
}
~~~
8. But what happens if a player wins the game or if there are no more valid moves? Define another function called `checkBoard` which takes in a `char` array `char board[]` as its only parameter and returns a `bool`. The function checks to see if the `char` in [0,1,2], [3,4,5], [6,7,8], [0,3,6], [1,4,7], [2,5,8], [0,4,8] or [2,4,6] are the same (and not ' '), if so it prints that the player with the `char` has won and returns true. If there is no winner, it checks to see if at least one element in `board` is ' ' and returns `false` if that's the case meaning there is at least one valid move left, else that means there are no more valid moves left so it prints that the game has ended in a draw and returns `true`. Below is one way of checking for wins, it uses a 2D array to store the sets of winning patterns (don't look it you want to try it yourself).

~~~cpp
int array[][3] = {{0,1,2} ,{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8}, {2,4,6}};
for (int i = 0; i < 8; i++)
{
    if (board[array[i][0]] == board[array[i][1]] && board[array[i][0]] == board[array[i][2]] && board[array[i][0]] != ' ')
    {
        std::cout << board[array[i][0]] << " has won!\n";
        return true;
    }
}
~~~

9. The final thing to do is to call `checkBoard` in the game-loop after updating `currentPlayer` and assigning the boolean it returns to `gameover`. This will keep the game-loop running until a player wins or the game ends in a draw. 

Extra Activity
------------
1. Tidy up the the noughts and crosses program. Get rid of all magic numbers, eliminate all assumptions about array size by passing it as a paramter or caluclating it from the array, add error checking for invalid inputs.
2. Create your own text adventure game. You are free to design it however you like, but I suggest sketching out a plan before you start coding. You can store room descriptions, items, options and actions in arrays; 2D arrays can be useful for storing a fixed number of actions and/or options for each room. Use conditionals to check the player’s responses and decide outcomes. Organize your code with functions that you can call as needed, and don’t forget to include a clear win or loss condition.
3. Create a simple console hangman game. Use a `char` array to store a fixed secret word and another array to keep track of the player’s correct guesses. Write functions to display the word with guessed letters and underscores, get the player’s letter guess, and update the word based on whether the guess is correct. Use a while loop to keep the game running until the player either guesses the whole word or runs out of allowed wrong guesses. Track the number of wrong guesses, check for win or loss conditions, and display an appropriate message when the game ends.



   

