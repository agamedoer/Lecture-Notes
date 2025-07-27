Week 1: Introduction to SFML & Game Loop Pattern
=============

Simple and Fast Multimedia Library (SFML)
------------
* SFML provides a simple, fast, cross-platform and object-oriented multimedia (not just games) API through which you can access windowing, graphics, audio and network.
* It is written in C++ (with bindings other languages e.g. C and Python), and the latest stable version is 3.0.0.
* Note that this is a games programming module with SFML chosen as the supporting library instead of full-fledged game engines, e.g. Unity, Unreal or Godot.
* Rather than providing game programming patterns as complete systems out of the box like game engines do, SFML offers low-level control and minimal abstraction, thus providing the opportunity for students to build and understand these systems from scratch.
* Useful official links for SFML

  * [Download](https://www.sfml-dev.org/download/)

  * [Tutorials](https://www.sfml-dev.org/tutorials/3.0/)

  * [Documentation](https://www.sfml-dev.org/documentation/3.0.0/)

* You can find out more on the [official site](https://www.sfml-dev.org/) or [GitHub repo](https://www.sfml-dev.org/).


Simple SFML Program
-----------
* An SFML Visual Studio project template has been created for this module; you can download it through this link or through Moodle.

  * Extra: Try setting up your own [SFML Visual Studio project by following the official SFML guide](https://www.sfml-dev.org/tutorials/3.0/getting-started/visual-studio/).

~~~cpp
#include <SFML/Graphics.hpp>

int main()
{
    //Declare window dimension as constants to avoid magic numbers
    constexpr int WIN_WIDTH = 800;
    constexpr int WIN_HEIGHT = 600;

    // Create the main window
    sf::RenderWindow window(sf::VideoMode({ WIN_WIDTH, WIN_HEIGHT}), "SFML Program");

    //Create a circle of radius 100 and set its fill colour
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    // Start the game loop
    // And keep it running until the window is closed
    while (window.isOpen())
    {
        //Process events
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();     //Clear screen
        window.draw(shape); //Draw circle
        window.display();   //Update screen
    }
}
~~~

SFML Program Structure || Game Loop
----------
* Most game programs have 3 main parts: the initialisation section, the game-loop, and the termination or clean-up section.

* Initialisation

  * Initialise objects e.g. the window object.

  * Load resources  e.g. textures, sounds or fonts.

* Game Loop

  * Handle user input.

  * Update game logic.

  * Clear previously rendered frame.

  * Draw objects in their updated states.

  * Render current frame.

* Termination

  * Code that is executed when the game loop is exited.

  * Cleans up resources as required.

~~~cpp
#include <SFML/Graphics.hpp>
int main()
{
    /* -----------------------INITIALISATION------------------------*/
    //Declare window dimension as constants to avoid magic numbers
    constexpr int WIN_WIDTH = 800;
    constexpr int WIN_HEIGHT = 600;

    // Create the main window
    sf::RenderWindow window(sf::VideoMode({ WIN_WIDTH, WIN_HEIGHT}), "SFML Program");

    //Create a circle of radius 100 and set its fill colour
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    /* -----------------------GAME LOOP------------------------*/
    // Start the game loop
    // And keep it running until the window is closed
    while (window.isOpen())
    {
        //Process events
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();     //Clear screen
        window.draw(shape); //Draw circle
        window.display();   //Update screen
    }

    /* -----------------------TERMINATION------------------------*/
    return EXIT_SUCCESS;
}

~~~

