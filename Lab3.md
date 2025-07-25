Practice Tasks
-------------

Main Activity: Simple Pong
--------
1. Download the SFML project template from moodle, unpack the zip file, and open the solution file (the file with .sln extension) in Visual Studio.
2. Click the play button to build and run the project (build must be set to x86 for the project to compile).
3. Let's begin with a `PongBall` class

   a. Create a .cpp file called `PongBall` in the Source Files folder
   
   b. Declare a class called `PongBall`. You can use the class template provided here as a starting point, but make sure you update the name of the class to `PongBall`. The class should have a constructor with no parameters, a draw method with one paramter, and an update method with no paramter, all public. Look at the lecture slides if you are not sure how these methods should be defined. 

   c. For now the class should have the following private member attributes: `sf::CircleShape ball`, `float radius`, `sf::Vector2f velocity`, and `sf::Vector2f position`.

   d. In the construtor, set `radius` to `10.0f` and set it as the radius of `ball`, set the color of `ball` to `sf::Color::White` or `sf::Color(255, 255, 255)`, set the origin of `ball` to its center, set `position` to the center of the window and set it as the position of `ball`.

   e. In the draw method, use the `window` argument passed to draw `ball`.

   f. In the main.cpp file, inside the main function, create an instance of `PongBall`, call its update and draw methods in the game-loop. Test your program and you should see the small white ball at the centre of your window.

   h. Laslty, let's get the ball moving by generating a random velocity in the constructor using the code provided below, and then using it to move `ball` in the update method uisng `ball.move(velocity)`.
   ~~~cpp
      std::random_device rd;
      std::uniform_real_distribution<float> randVel(-0.1, 0.1);
      float velX = randVel(rd);
      float velY = randVel(rd);
      velocity = sf::Vector2f(velX, velY);
   ~~~


   i. The `ball` inevitably goes off-screen when you run the program. Make it collide with the walls by checking the position of `ball` before moving it in updateand inverting the `velocity.x` or `velocity.y` if `ball` hits a vertical or horizontal wall respectively. Hint: see the solution to the moving car example from Lab 2, but consider the radius of ball to have a more precise collision detection system.

5. Now we have the ball moving, we can add a bat.

    a. Create a new .cpp file `PongBat` and declare the `PongBat` class in it using the same template class structure you used for `PongBall`.

    b. For now the class should have the following private member attributes: `sf::RectangleShape bat`, `float speed`, `sf::Vector2f size`, and `sf::Vector2f position`.

    c. In the construtor, set `size` to `sf::Vector2f(15.0f, 60.0f)` and `position` to `sf::Vector2f(40.0f, 400.0f)  set it as the radius of `ball`, then set the size of `bat` to `size` and its position to `position`.

    d. In the draw method, use the reference to the `window` object reference to draw `bat`. 

    e. Create an instance of `PongBat` in `main` function in `main.cpp`, call its update and draw methods in the game-loop. A bat should appear on screen, but it does nothing.

    f. In the update method of the `PongBat` class, check for key presses for `sf::Keyboard::Up` and `sf::Keyboard::Down`, then move `bat` accordingly using `bat.move(0, -speed)` or `bat.move(0, speed)` respectively. You should also add checks to make sure the bat cannot be moved off screen (it stops at the top and the bottom of the window).

7. Finally, we can now add collision checks between the `PongBat` and `PongBall` instances.

   a. Update `PongBall` to have getter methods that return the position and radius of `ball`, as well as a setter for `velocity`. 

   b. Update `PongBat` to have getter functions that return the position and size of `bat`.

   c. In `main.cpp`, outside of the `main` function, add the collision detection function provided below. This should be called with the position of the bat and the ball, and it will return `true` if the two are overlapping and `false` if not.
   
~~~cpp
bool checkCollision(sf::Vector2f batPosition, sf::Vector2f batSize, sf::Vector2f ballPosition, float ballRadius)
{
    // we will treat the ball as a square for this collision check
    float x0ball, x1ball, y0ball, y1ball;
    float x0bat, x1bat, y0bat, y1bat;
    x0ball = ballPosition.x - ballRadius;
    x1ball = ballPosition.x + ballRadius;
    y0ball = ballPosition.y - ballRadius;
    y1ball = ballPosition.y + ballRadius;
    x0bat = batPosition.x;
    x1bat = batPosition.x + batSize.x;
    y0bat = batPosition.y;
    y1bat = batPosition.y + batSize.y;

    return !(y0ball > y1bat || x0ball > x1bat || x1ball < x0bat || y1ball < y0bat);
}
~~~

   d. In the game-loop of the 'main' function, after calling the update methods for the 'PongBat' and 'PongBall' instances, use an if-statement to check if a collision has occured , but remember you need to get the position and size of the bat, and the position and radius of the ball first, save them to locak varoiables and pass them as arguments to the checkCollission method. Inside the if block, invert the value of the x componement of the ball's velocity using its setter method.

   e. 

Extra Activity
------------
1. Extend the pong game to have two players, with different keys. A player gets a point if they are able to get the ball to hit the wall behind their opponent. Display the score on the screen and end if any of the players gets 5 points.
2.USe the pong game as a base to create a breakout game.
3. Create a memomry game program.



   
