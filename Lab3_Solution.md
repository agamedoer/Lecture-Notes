~~~cpp
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <random> 

class PongBall
{
	sf::CircleShape ball;
	sf::Vector2f velocity;
	float radius;

public:
	PongBall(): radius(10.0f)
	{
		ball.setRadius(radius);
		ball.setPosition(400, 300);
		ball.setFillColor(sf::Color::White);
		ball.setOrigin(radius / 2, radius / 2);

		std::random_device rd;
		std::uniform_real_distribution<float> randVel(-0.1, 0.1);
		float velX = randVel(rd);
		float velY = randVel(rd);
		velocity = sf::Vector2f(velX, velY);
	}

	void draw(sf::RenderWindow& window)
	{
		window.draw(ball);
	}

	void update()
	{
		if (ball.getPosition().x < ball.getRadius() || ball.getPosition().x>800 - ball.getRadius()) velocity.x *= -1;
		if (ball.getPosition().y < ball.getRadius() || ball.getPosition().y>600- ball.getRadius()) velocity.y *=-1;
		ball.move(velocity);
	}
};
~~~

~~~cpp
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>

class PongBat
{
	sf::RectangleShape bat;
	float speed;

public:
	PongBat(): speed(0.1)
	{
		bat.setSize(sf::Vector2f(15.0f, 60.0f));
		bat.setPosition(sf::Vector2f(40.0f, 400.0f));
		bat.setOrigin(15 / 2, 60 / 2);
	}

	void draw(sf::RenderWindow& window)
	{
		window.draw(bat);
	}

	void update()
	{
		//check if the Up key is pressed
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && bat.getPosition().y>30)
		{
			bat.move(0, -speed);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && bat.getPosition().y < 570)
		{
			bat.move(0, speed);
		}
	}
};
~~~

### completed
~~~cpp
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>

class PongBat
{
	sf::RectangleShape bat;
	float speed;

public:
	PongBat(): speed(0.1)
	{
		bat.setSize(sf::Vector2f(15.0f, 60.0f));
		bat.setPosition(sf::Vector2f(40.0f, 400.0f));
		bat.setOrigin(15 / 2, 60 / 2);
	}

	void draw(sf::RenderWindow& window)
	{
		window.draw(bat);
	}

	void update()
	{
		//check if the Up key is pressed
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && bat.getPosition().y>30)
		{
			bat.move(0, -speed);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && bat.getPosition().y < 570)
		{
			bat.move(0, speed);
		}
	}

	sf::Vector2f getPosition()
	{
		return bat.getPosition();
	}

	sf::Vector2f getSize()
	{
		return bat.getSize();
	}
};
~~~

~~~cpp
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>

class PongBall
{
	sf::CircleShape ball;
	sf::Vector2f velocity;
	float radius;

public:
	PongBall(): radius(10.0f)
	{
		ball.setRadius(radius);
		ball.setPosition(400, 300);
		ball.setFillColor(sf::Color::White);
		ball.setOrigin(radius / 2, radius / 2);

		std::random_device rd;
		std::uniform_real_distribution<float> randVel(-0.1, 0.1);
		float velX = randVel(rd);
		float velY = randVel(rd);
		velocity = sf::Vector2f(velX, velY);
	}

	void draw(sf::RenderWindow& window)
	{
		window.draw(ball);
	}

	void update()
	{
		if (ball.getPosition().x < ball.getRadius() || ball.getPosition().x>800 - ball.getRadius()) velocity.x *= -1;
		if (ball.getPosition().y < ball.getRadius() || ball.getPosition().y>600- ball.getRadius()) velocity.y *=-1;
		ball.move(velocity);
	}

	float getRadius()
	{
		return ball.getRadius();
	}

	sf::Vector2f getPosition()
	{
		return ball.getPosition();
	}
	
	sf::Vector2f getVelocity()
	{
		return velocity;
	}

	void setVelocity(sf::Vector2f vel)
	{
		velocity = vel;
	}
};
~~~

~~~cpp
#include <SFML/Graphics.hpp>
#include "PongBall.cpp"
#include "PongBat.cpp"
#include <random>

constexpr int WIDTH = 800;
constexpr int HEIGHT = 600;

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

int main()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML");
    PongBall myBall;
    PongBat myBat;

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
        myBall.update();
        myBat.update();
        
        sf::Vector2f batPos = myBat.getPosition();
        sf::Vector2f batSize = myBat.getSize();
        sf::Vector2f ballPos = myBall.getPosition();
        float ballRadius = myBall.getRadius();

        if (checkCollision(batPos, batSize,ballPos, ballRadius))
        {
            sf::Vector2f velocity = myBall.getVelocity();
            myBall.setVelocity(sf::Vector2f(velocity.x * -1, velocity.y));
        }
        window.clear();
        myBall.draw(window);
        myBat.draw(window);
        window.display();
   
    }
    return EXIT_SUCCESS;
}

~~~
