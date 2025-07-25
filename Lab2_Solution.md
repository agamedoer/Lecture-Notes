Practice Tasks
-------------
1. To complile SFML programs, SFML needs to be downloaded, added to your VS Studio project, and linked so your code can use its graphics, window, and system features. Doing this before you complete each lab task will be time consuming, therefore a default SFML project template is provided for you to use, and specific starter projects will be provided for some tasks. Download the tutorial starter project using this link or through Moodle. Extract the project, and start it by executing the .sln file in the project folder. If the code editor is blank, open Solution Explorer, select the Source Files folder and double click main.cpp.

2. Create and draw a `sf::CircleShape` named `ball` with a radius of 25. Remember to declare it in the initialisation section, and draw it in the game-loop. Set its origin to its centre, and display it perfectly in the centre of your program window.

~~~cpp
#include <SFML/Graphics.hpp>

int main()
{
    constexpr int WIDTH = 800;
    constexpr int HEIGHT = 600;
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML");

    sf::CircleShape ball(25);
    ball.setOrigin(25, 25);
    ball.setPosition(WIDTH / 2, HEIGHT / 2);

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }

       
        window.clear();
        window.draw(ball);
        window.display();
    }
    return EXIT_SUCCESS;
}

~~~

3. Use arrow keys to reposition ball so that pressing `sf::Keyboard::Left` moves it along the x-axis to the left wall of the window, pressing `sf::Keyboard::Right` moves it along the x-axis to the right wall of the window, pressing `sf::Keyboard::Up` moves it along the y-axis to the top wall of the window, pressing `sf::Keyboard::Down` moves it along the y-axis to the bottom wall of the window, and pressing `sf::Keyboard::Enter` re-centres to the middle of the window.

~~~cpp
#include <SFML/Graphics.hpp>

int main()
{
    constexpr int WIDTH = 800;
    constexpr int HEIGHT = 600;
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML");

    sf::CircleShape ball(25);
    ball.setOrigin(25, 25);
    ball.setPosition(WIDTH / 2, HEIGHT / 2);

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //check if the Up key is pressed
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            ball.setPosition(ball.getPosition().x, 0);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            ball.setPosition(ball.getPosition().x, HEIGHT);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            ball.setPosition(0, ball.getPosition().y );
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            ball.setPosition(WIDTH, ball.getPosition().y);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
        {
            ball.setPosition(WIDTH/2, HEIGHT/2);
        }


        window.clear();
        window.draw(ball);
        window.display();
    }
    return EXIT_SUCCESS;
}
~~~
4. Now create a sf::Sprite named car, set its texture to car.png (remember to load the image first using an sf::Texture object). Position and draw it at the top-left corner of your program window.

5. Make the car move slowly along the x-axis from one end of the window to another. I suggest using a variable in the initialisation section to store the speed of the car and another to store the direction (i.e. 1 or -1).
~~~cpp
#include <SFML/Graphics.hpp>

int main()
{
    constexpr int WIDTH = 800;
    constexpr int HEIGHT = 600;
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML");

    float speed = 0.05f;
    int direction = 1;
    sf::Texture carTex;
    carTex.loadFromFile("assets/car.png");
    sf::Sprite car;
    car.setTexture(carTex);

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
        car.move(sf::Vector2f(speed * direction, 0));
        if (car.getPosition().x > WIDTH || car.getPosition().x < 0)
        {
            direction *= -1;
            car.scale(car.getScale().x * direction, 1);
        }
        window.clear();
        window.draw(car);
        window.display();
    }
    return EXIT_SUCCESS;
}
~~~
6. Toggle the car movement on mouse click i.e. if the car is moving and the left mouse button is clicked, then it should stop, and if it si stopped and the left mouse button is clicked then it should start moving. Hint: change the value of teh car speed variable on mouse click.
~~~cpp
#include <SFML/Graphics.hpp>

int main()
{
    constexpr int WIDTH = 800;
    constexpr int HEIGHT = 600;
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML");

    float speed = 0.05f;
    int direction = 1;
    bool moving = true;
    sf::Texture carTex;
    carTex.loadFromFile("assets/car.png");
    sf::Sprite car;
    car.setTexture(carTex);

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
                moving = !moving;

        }

        if (moving)
        {
            car.move(sf::Vector2f(speed * direction, 0));
            if (car.getPosition().x > WIDTH || car.getPosition().x < 0)
            {
                direction *= -1;
                car.scale(car.getScale().x * direction, 1);
            }
            window.clear();
            window.draw(car);
            window.display();
        }
    }
    return EXIT_SUCCESS;
}
~~~
7. Use variable timestep to make sure the car moves from one end of the window to the other in 5 seconds.
~~~cpp
#include <SFML/Graphics.hpp>

int main()
{
    constexpr int WIDTH = 800;
    constexpr int HEIGHT = 600;
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML");

    float speed = WIDTH/2;
    int direction = 1;
    bool moving = true;
    sf::Texture carTex;
    carTex.loadFromFile("assets/car.png");
    sf::Sprite car;
    car.setTexture(carTex);
    sf::Clock clock;

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
                moving = !moving;

        }
        float dt = clock.restart().asSeconds();

        if (moving)
        {
            car.move(sf::Vector2f(speed * dt* direction, 0));
            if (car.getPosition().x > WIDTH || car.getPosition().x < 0)
            {
                direction *= -1;
                car.scale(car.getScale().x * direction, 1);
            }
            window.clear();
            window.draw(car);
            window.display();
        }
    }
    return EXIT_SUCCESS;
}
~~~
9. Play sound.oog when the car is moving.

10. Create an array of `sf::Sprite` with 50 elements (all elements should have the same block.png texture). Use a for loop to position elements of the array so that you create various shapes e.g. a pyramid, stairs, and a rectangular wall.

Main Activity: Growth Game
--------
1. Create and draw a `sf::CircleShape` named `player` with a radius of 20. Remember to declare it in the initialisation section, and draw it in the game-loop. Set its origin to its centre.
2. Set its initial position to a random x and y points within the size of the window. You can generate and store the random position in a `sf::Vector2f` using the code below in the initialisation section.
3. The `player` should be moveable using arrow keys in all directions, but it should not be possible to move it out of view. Test your program at this point to make sure it works before proceeding.
4. Next, let's create food for `player` to eat. In the initialisation section create an array of 3 `sf::RectangleShape` objects named `foods`. Set the size of each element to sf::Vector2f(2.0f,2.0f), generate random initial positions for them as you did the player, and render them in their positions in the game-loop (use a for loop to inialise and render elemnts of an array). Now when you run the porhgtram you should have the food items and the plyer all positioned in randomw points, with the player being able to move.
5. We now need to check if the player has eaten any of the food items, we will use a simple collision check for this. It may be best to define a simple sphere to point collision function that we can use- this fucntion will take it the position of teh player ad the position of a food object, then check ot see if the distance between teh two is less than the radisu of player, if so then the two are colliding and we will assume that the player has eaten that food object. The code for this function is provided below, copy it and paset it before your main function.

6. In the game-loop, after the code that moves player, check for collision between player and  all elements of foods busing a for-loop to check if checkCollision returns true if you call it with the positon of the player and the position of foods elements. If it does, then increase the radius of player by 0.01% and set the position of the eat foods element a new random position (it may a good idea to create a function that returns a random `sf::Vector2f` positon if you have not done so aleady).
7. Now test your code to see that it works.
~~~cpp
#include <SFML/Graphics.hpp>
#include <random>

constexpr int WIDTH = 800;
constexpr int HEIGHT = 600;

sf::Vector2f generatePosition()
{
    std::random_device rd;
    std::uniform_real_distribution<float> randX(0, WIDTH);
    std::uniform_real_distribution<float> randY(0, HEIGHT);
    float randomXPosition = randX(rd);
    float randomYPosition = randY(rd);
    sf::Vector2f randomPosition = sf::Vector2f(randomXPosition, randomYPosition);
    return randomPosition;
}

bool checkCollision(int playerRadius, sf::Vector2f playerPos, sf::Vector2f foodPos)
{
    float dx = playerPos.x - foodPos.x;
    float dy = playerPos.y - foodPos.y;
    float distance = std::sqrt(dx * dx + dy * dy);

    return distance < playerRadius + 5;
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML");
    sf::CircleShape player(20);
    player.setFillColor(sf::Color::Blue);
    player.setOrigin(20 / 2, 20 / 2);
   
    sf::RectangleShape foods[3];
    for (int i = 0; i < 3; i++)
    {
        foods[i].setSize(sf::Vector2f(5, 5));
        foods[i].setPosition(generatePosition());
        foods[i].setFillColor(sf::Color::Yellow);
    }
   
    player.setPosition(generatePosition());

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //check if the Up key is pressed
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && player.getPosition().y>0)
        {
            player.move(0, -0.02);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && player.getPosition().y < HEIGHT)
        {
            player.move(0,0.02);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && player.getPosition().x > 0)
        {
            player.move(-0.02, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && player.getPosition().x < WIDTH)
        {
            player.move(0.02, 0);
        }

        for (int i = 0; i < 3; i++)
        {
            if (checkCollision(player.getRadius(), player.getPosition(), foods[i].getPosition()))
            {
                player.setRadius(player.getRadius() * 1.1);
                foods[i].setPosition(generatePosition());
            }
        }
       
        window.clear();
        for (int i = 0; i < 3; i++)
        {
            window.draw(foods[i]);
        }
        window.draw(player);
        window.display();
   
    }
    return EXIT_SUCCESS;
}
~~~
8. Next let's provide some visual fedback for our player. USe `sf::Font` to provide a simple HUD at the top right corner of the screen. COlor the text blue, over two lines provide the current raidus of player, and score (use a score variable that is incremented by 1 whenever the use eats food.


Extra Activity
------------
1. Extend the game from the main activity e.g. add support two players (arrow keys for blue player and WASD for green player); one player can eat the other if its radius is at least 50% more; replace coloured spahes with sprites for players, and randomly coloured shapes as food items; add a sprite background.
   
3. Ceate a visual version of the Tic Tac Toe game from lab 1. Use keyboard input as you did last week, but use SFML fonts to visually display the board. 
4. Create a visual version of the hangman game.
