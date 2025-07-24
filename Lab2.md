Practice Tasks
-------------
1. To complile SFML programs, SFML needs to be downloaded, added to your VS Studio project, and linked so your code can use its graphics, window, and system features. Doing this before you complete each lab task will be time consuming, therefore a default SFML project template is provided for you to use, and specific starter projects will be provided for some tasks. Download the tutorial starter project using this link or through Moodle. Extract the project, and start it by executing the .sln file in the project folder. If the code editor is blank, open Solution Explorer, select the Source Files folder and double click main.cpp.

2. Create and draw a `sf::CircleShape` named `ball` with a radius of 100. Remember to declare it in the initialisation section, and draw it in the game-loop. Set its origin to its centre, and display it perfectly in the centre of your program window.

3. Use arrow keys to reposition ball so that pressing `sf::Keyboard::Left` moves it along the x-axis to the left wall of the window, pressing `sf::Keyboard::Right` moves it along the x-axis to the right wall of the window, pressing `sf::Keyboard::Up` moves it along the y-axis to the top wall of the window, pressing `sf::Keyboard::Down` moves it along the y-axis to the bottom wall of the window, and pressing `sf::Keyboard::Enter` re-centres to the middle of the window.

4. Now create a sf::Sprite named car, set its texture to car.png (remember to load the image first using an sf::Texture object). Position and draw it at the top-left corner of your program window.

5. Make the car move slowly along the x-axis from one end of the window to another. I suggest using a variable in the initialisation section to store the speed of the car and another to store the direction (i.e. 1 or -1).

6. Toggle the car movement on mouse click i.e. if the car is moving and the left mouse button is clicked, then it should stop, and if it si stopped and the left mouse button is clicked then it should start moving. Hint: change the value of teh car speed variable on mouse click.

7. Use variable timestep to make sure the car moves from one end of the window to the other in 5 seconds.

8. Play sound.oog when the car is moving.

9. Create an array of `sf::Sprite` with 50 elements (all elements should have the same block.png texture). Use a for loop to position elements of the array so that you create various shapes e.g. a pyramid, stairs, and a rectangular wall.  
   
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

2. Run the program below. What error does the compiler show? Can you tell why the error occurs and how it can be fixed?
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
5. Write a function with the name `squareNumber` which takes in a single integer number as its parameter and squares it. Test it in the `main` function of your program. If you need help starting, use the `timesTwo()` example function from the lecture slides.
6. Write a function with the name `powerNumber` with two parameters, a double number and an integer power. Test it with some small input values, e.g. `powerNumber(2.0, 3)` means 2.0 to the power of 3 (expect 8.0) and `powerNumber(3.0, 4)` means 3.0 to the power of 4 (expect 81.0). Hint: Use a loop inside the function.

    Side Quest. See what happens if you give it some larger numbers, for example, 13.0, 12 (expect 23298085122481.0). Is the answer now incorrect, and if so, can you work out why this is?

7. Write a C++ program that continuously prompts the user for input and only stops running when the user types the string "end". Hint: Use a while loop.

8.	Write a program that tracks the user's position on a 2D grid starting at coordinates (0, 0). When the user enters "north", "south", "east", or "west", update the coordinates accordingly. The program should continue to prompt for input and display the current position until the user enters "end", which will terminate the program.
   
9.	Write a C++ program to display the following shapes using asterisks (*): a right-angled triangle, a pyramid, and a diamond. Use nested for loops and the modulus (%) operator; the maximum size of the shapes should be 20 by 10 characters.

10.	Refactor the code from the above task so that you have a drawShape function which takes a shape and a character and draws the selected shape using the provided character.
    
#### Optional Practice Tasks
1.	Write a program that asks the user for an integer number as input, then tests whether the number is a prime number. There are some ways to speed this calculation up, but for now just use the ‘brute force’ method of test division. Test your program with some known values (e.g. primes 3, 5, 13, 1327, not primes 2, 15, 20, 1323). Test how large you can go with your inputs.

2.	Write a program that asks a user for an integer number, then uses a loop to identify prime numbers between 1 and the input number. Each identified number should be stored in a vector, and the program should print out the content of the vectors at the end of the program.

Main Activity - Tic Tac Toe
------------
BY the end of this activity you should have created a Tic-Tac-Toe game that runs in the console. The program will have while loop in the main function that will keep calling functions that aks for player input, update the board, and check for the win/loss/draw condition, continously until a player wins or there are no more valid moves.
1. In the main function, declare a 9 element `char` array named `board`, this will be used to represent the game board; use a for-loop to initialise all elements of `board` to ' '. Then declare a `char currentPlayer` and initialise it to 'x', and a `boolean gameover` and initialise it to `false`'

2. Outside of the main function, define a function named `drawBoard`. The function should have one paramter, a `char` array named `board` and return void. Inside the funtion, print `board` to the console as a 3 by 3 grid of char (first row elements: 0 1 2, second rowelemnts: 3 4 5, third row elemnts: 6 7 8). To simplify our task, we will assume that the `board` will always have 9 elements. Hint: use a for loop and the % operator to print `board`.

3. Test `drawBoard` by drawing a board intialised with random chars, make sure it works before moving to the next step.

4. Now define another function called `makeMove` which takes has the following paramters: `char currentPlayer`, `int position`, and  `char board[]` and returns a boolean. First it checks to see that position is non-negative and it is less than 9, if not it prints out a message to say an invalid move has been made and returns false. Then it checks the `board` element in `position`, if it its ' ', then it is replaced by `currentPlayer` and the function returns true, else it it prints out a message to say an invalid move has been made and returns false.

5. Let's now test the above method to see that it works. In your main method, after `drawBoard` is called, define a boolean named `validMove` initialised to false and add a while loop that executes as long as `validMove` is false. Inside the while loop print out an apporpriat message to prompt the current player to choose a position for their next move (use the value of currentPlayer to determine whose whethe its it x's or o's turn). Then use `cin` take the user input, store it in a local int called `pos`, and call `makeMove` with `currentPlayer`, `pos`, and `board` as arguments while assigning the boolean it returns to `validMove`. Outside the of while loop, update the value of currentPlayer - if its X update it to O, if its O update it to X.

6. Run the program to test it. Inputting invalid moves will lead to an invalid move message being printed out, followed by a drwawing of the board and a prompt to make another move. Valid moves on the other hand, will end the program - let's fix that in the next step.

7. To make sure the game does not end after every valid input, we will create a game-loop by moving all the code we have added after initialising the board array into a while loop that runs as long as `gameover` is false. Your main function will now look something like this

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
		//call to drawBoard
		//while loop that calls makeMove
		//updating currentPlayer
	}
}
~~~
8. But what happens if a player wins the game or if there are no more valid moves? Define another function called `checkBoard` which takes in a char array `char board[]` as its only parameter and returns a boolean. The function checks to see if the chacraters in [0,1,2], [3,4,5], [6,7,8], [0,3,6], [1,4,7], [2,5,8], [0,4,8] and [2,4,6] are the same (and not ' '), if so its prints that the character has won and returns true. Else it checks to see if at least one element in `board` is ' ' and return false if that's the case, else that means there are no more moves left so it prints that the game has ended in a draw and returns true.

9. The final thing to do is to call `checkBoard` in the game-loop after updating `currentPlayer` and assigning the boolean it retuens to the `gameover` variable. This will keep the gameloop running until a player wins or the game ends in a draw. 

Extra Activity
------------
1. Create your own text adeventure
2. Create a hangman game
3. Create a simple calculator



   
