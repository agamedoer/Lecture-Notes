Practice Tasks
-------------

Main Activity: Pong
--------
1. Download the SFML project template from moodle, unpack the zip file, and open the solution file (the file with .sln extension) in Visual Studio.
2. Click the play button to build and run the project (build must be set to x86 for the project to compile).
3. Let's begin with a `PongBall` class

   a. Create a .cpp file called PongBall in the Source Files folder
   
   b. Declare a class called PongBall. You can use the class template provided here as a starting point, but make sure you update the name of the class to PongBall. The class should have a constructor with no parameters, a draw method with one paramter, and an update method with no paramter. Look at the lecture slides if you are not sure how these methods should be defined. 

   c. For now the class should have the following private member attributes: `sf::CircleShape ball`, `float radius`, `sf::Vector2f velocity`, and `sf::Vector2f position`.

   d. In the construtor, set `radius` to `10.0f` and set it as the radius of `ball`, set the color of `ball` to `sf::Color::White` or `sf::Color(255, 255, 255)`, set the origin of `ball` to its center, set `position` to the center of the window and set it as the position of `ball`.

   e. In the draw method, use the `window` argument passed to draw `ball`.

   f. In the main.cpp file, inside the main function, create an instance of `PongBall`, call its update and draw methods in the game-loop. Test your program and you should see the small white ball at the centre of your window.

   h. Laslty, let's get the ball moving by generating a random velocity in the constructor using the code provided below, and then using it to move `ball` in the update method uisng `ball.move(velocity)`.

   Side Quest: use variable timing instead by generating a random velocity between with x and y values between -600.0f and 600.0f and multiplying that by `deltaTime` which you will need to pass to the update method from the main function.

   i. Running the program should now show a white sphere moving from the centre in a radom direction.

 4. Now we have the ball moving, we can add a bat.

    a. Create a new .cpp file `PongBat` and declare the `PongBat` class in it using the same template class structure you used for `PongBall`.

    b. For now the class should have the following private member attributes: `sf::RectangleShape bat`, `float speed`, `sf::Vector2f size`, and `sf::Vector2f position`.

    c. In the construtor, set `size` to `sf::Vector2f(15.0f, 60.0f)` and `position` to `sf::Vector2f(40.0f, 400.0f)  set it as the radius of `ball`, then set the size of `bat` to `size` and its position to `position`.

    d. In the update method, check for key presses for `sf::Keyboard::Up` and `sf::Keyboard::Down`, then update the `position.y` accordingly by subtracting or adding `speed`. Make sure you update the position of `bat` with the new `position` after.  set the color of `ball` to `sf::Color::White` or `sf::Color(255, 255, 255)`, set the origin of `ball` to its center, set `position` to the center of the window and set it as the position of `ball`.
   
~~~cpp

~~~

Extra Activity
------------




   
