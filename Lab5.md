Practice Tasks
-------------

Main Activity: Simple Pong
--------
1. Download the starter project, unzip it and open it in Visual Studio. It shoudl have two header files `Aquarium.h` and 'PuffFish.h`, in additiont to the `main.cpp` file. For this activity, we will stick to declaring and defing classes in header files ( bbecause we have several of them, but you may want to seprate the declrayion and implementation when you complete the actvitiy ).
2. PuffyFish represents a specific implementation of fish, with a spexifid swim behaviout (replaces update in this example), and it has the template draw method used to draw the fish sprite. Aquarium holds a vector to pointers of PuffyFish, lsitens for a key press to cretae a new puffy fish and add it to the vector, but iyts has a maximum count of fish that can be added to the aquairum. Its draw and update methods call draw and swim methods for all the fish in the puiffyFish vector. In this acitivy, we will add difgerent kinds of fish to the aqurium, starting with an infficient approach, but optimsiing it as we go using polymorphims.
3. RUnning the prohgtram should show a blank screen that's because there is no isntance of Aquarium created in the main, fix that by creating an isntance using Aquarium myAquairum(20) in the initialisation section of the main, to create an auqarium with a max cpacity of 20 fish, and the calling its dupdate and darw methods in the game loop. The `PuffyFish` constructor also needs to be updated, it needs to call the two methods that initialise any new puffy FIsh, the init and position sprite. Once these are done, pressing the P key when you run the program shoudl randoly plaxe a puffy fish on the screen.
4. Lets now add a new type of fish, lets call it RedFish. Create a header file in the Header FIles folder, name it RedFish, and delcare the RedFIsh class in it. We can, for now just copy the code from PuffyFIsh and paset it in Red FIsh (remember to change the name fo teh class).

  a. We also want to change the texture that is loaded to "assests/red_fish.png"

  b. And we want to update the swimming bhevaiour, update the swim method with the code provided belwo
   
~~~cpp
 	void swim()
	{
        float dAngle = ((rand() % 200) - 100) / 1000.0f; 
        float currentAngle = atan2(velocity.y, velocity.x);
        currentAngle += dAngle;

        float speed = std::sqrt(velocity.x * velocity.x + velocity.y * velocity.y);
        velocity.x = cos(currentAngle) * speed;
        velocity.y = sin(currentAngle) * speed;

        // Update position
        sprite.move(velocity);

        sf::Vector2f position = sprite.getPosition();
        // Bounce off walls
        if (position.x < 0) {
            position.x = 0;
            velocity.x *= -1;
        }
        if (position.x > 800) {
            position.x = 800;
            velocity.x *= -1;
        }
        if (position.y < 0) {
            position.y = 0;
            velocity.y *= -1;
        }
        if (position.y > 600) {
            position.y = 600;
            velocity.y *= -1;
        }
	}
~~~

  c. To be able to add a RedFIsh to the Aquarium, we need to add vector of unique pointers to RedFIsh as a member attirbute of the Aqurium class, its should be easy to tdo since a simular vector to Puffy FIsh existsi in the code.

  d. Nxt, we can add an if statement in the update to check if sf::keyboard::R is pressed, if it is and count is less than capacity, hen we can create an new unique pointer to a red fish, and push it to the red fish vector, and increment count.

  e. Still in th eupdate method, we make sure that we have a loop that goes through all the elemenst of teh refish vector, and class swim of all of them (see simular loop for puffy fish)

  f. lastly, in the draw method, we have a loop that iterates through elements of refidh and calls draw in each.

  g. If you run this and press, red you may notice that several red sgih gets created at the same time, this is because we actually want to check key-relase not key press, and sfmk only allsows us to tdo that using events, so  a hack to do this is to delcare a boll variable to track R press i.e. rKeyPress and initilais e false, then set it ti teu whethwhen R is pressed, and have anothee if to check if R is not pressed then set rKeyPRessed ot false.

Extra Activity
------------




   
