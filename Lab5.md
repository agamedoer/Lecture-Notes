Practice Tasks
-------------

Main Activity: Simple Pong
--------
1. Download the starter project, unzip it and open it in Visual Studio. It shoudl have two header files `Aquarium.h` and 'PuffFish.h`, in additiont to the `main.cpp` file. For this activity, we will stick to declaring and defing classes in header files ( bbecause we have several of them, but you may want to seprate the declrayion and implementation when you complete the actvitiy ).
2. PuffyFish represents a specific implementation of fish, with a spexifid swim behaviout (replaces update in this example), and it has the template draw method used to draw the fish sprite. Aquarium holds a vector to pointers of PuffyFish, lsitens for a key press to cretae a new puffy fish and add it to the vector, but iyts has a maximum count of fish that can be added to the aquairum. Its draw and update methods call draw and swim methods for all the fish in the puiffyFish vector. In this acitivy, we will add difgerent kinds of fish to the aqurium, starting with an infficient approach, but optimsiing it as we go using polymorphims.
3. RUnning the prohgtram should show a blank screen that's because there is no isntance of Aquarium created in the main, fix that by creating an isntance using Aquarium myAquairum(20) in the initialisation section of the main, to create an auqarium with a max cpacity of 20 fish, and the calling its dupdate and darw methods in the game loop. The `PuffyFish` constructor also needs to be updated, it needs to call the two methods that initialise any new puffy FIsh, the init and position sprite. Once these are done, pressing the P key when you run the program shoudl randoly plaxe a puffy fish on the screen.
4. Lets now add a new type of fish, lets call it RedFish. Create a header file in the Header FIles folder, name it RedFish, and delcare the RedFIsh class in it. We can, for now just copy the code from PuffyFIsh and paset it in Red FIsh (remember to change the name fo teh class).

	a. We also want to change the texture that is loaded to "assests/red_fish.png"

	b. And we want to update the swimming bhevaiour, update the swim method with the code provided below and add private member attribute `sf::Vector2f velocity`.
   
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

   5. From the above process, you can see that everytime you want to add a new type of Fish then you need to create the approrpiate class, add a vector sto store pointers to it in the aqiuarium class, and have loops to iterate through that vector to call draw and swim. This can lead to bulky reprititve code, especially if most Fish are similar in one way or another. We can address this by reducing duplicate code accross differen FIsh classes, and by treating similar Fish or all FIsh where possinle as one. Lets start with a simple inheritance example.
   6. Say we want to have a RedFIsh variant, the RedZombie FIsh, its the same in every way except that it renders a skeletal red fish sprite. We can do that by creting a class that inheris from RedFish and just changing th ebits we have to.

	a. Create a header for RedZombieFish, and declare the class and make it inherit from `public RedFish`.

	b. The only difference between the RedFish and RedZombieFish is the texture used (mosty inheritance cases are more complex than this, this is just a simpel example). Therefore we want to override the init fucntion; in the RedFish class add teh virtual keyword before the fucntion's return type, and copy the fucntion to the RedZombieFish class (wthout the virtual) and add ovveride after the brackets with its paramters. In the method, update the texture being loaded to "assets/red_zombie_fish".

	c. You will notice that the compiler is showing red lines underneatg the private member arttributes declared in RedFish, this is becuase they are not accessible in RedZOmbieFIsh, fix thsi by changing their visibilityt o pRotexctex in RedFish.

	d. Next, in RedZombieFIsh, add a consyrictur with not paramters, and call init() inside.

	e. Now that we have the class done, we add instances to the aquarium Howver, because RedZombieFIsh is a type of RedFish, we don't need to create a new vector to store its pointers, in fact if you change the code that add unique poitbers to Redfish to the redfish evtor inAqurium, to `redFish.push_back(std::make_unique<RedZombieFish>());` its shoud work just fine and add RedZombie Fish to the redfish vector isntead.

	f. Rather than constantly adding ome type of red fish, ad a simple code that generates either 0 or 1 randombly, and based on that cretaes a redfish or a zredzombie fish when r is pressed.

7. We managed to avoid having to deal with another vector for another separte type of fish, but we still treat PuffyFish and the two type sof RedFIsh differnetly, evne though they have similar methods in swim and draw. We can create an abstract base class that they all inherit from call Fish, and have one vector in aqurium that stores fish.

   	a. Create a header file name Fish, and create the Fish class.

   	b. Add protected variables for spawnPos, velocity, sprite and texture.

   	c. Copy the `positionSprite` method and make it a protected member of the FIsh class.

   	d. Add two public methods `virtual void swim() = 0` and `virtual void draw(sf::RenderWindow& window){window.draw(sprite);}. Notice that swim is a pure virtual function because is type of fish is ecpectt o implement its wown, but draw is implemented and could be overridedn, but inheriticng classes can use the base implementation.

	e. Update Fish.h; inlude the FIsh.h file, make RedFish inherit from public Fish, remove attributes that are already decleared in Fish, delete the positionSprite method, add ovveride to the swim method
   	 and delete the draw method.

   	f. Similarly, update PuffFish by making it inherit from Fihs, and deleitng duplicated attributes and methods.

   	h. The program shoud still work as before, but we can improve our code further. In `Aquarium`, replace the multiple vectors for pointers to different fish with one vector `std::vector<std::unique_ptr<Fish>> fish`. In the draw method, there should only be onle loop that draw elements fo `fish`, in the update pointers to newly created fish should be oushded back to `fish`, and the multple loops calling swim on elements of multple vectors shpoiuld be replace by one calling swim on elements of fish. RUn your program now and it should work as before.

8. Let's add a new type of fish to the aquarium, the BlueFish

   	a. Create a new header file, deine teh BlueFish by copybg the PuffyFish class.

   	b. Update the name of teh class and constructor, update the texture to blue_fish.png

   	c. Update the swim funciton so that the blue fish swims horizonatlly from the left to the righ wall and back, the widt h fteh screen is 800, and teh compoennt of the position and evlocity you want to update is the x component. You also need to update `velocity` to `sf::Vector2f(0.02, 0)`.

   	d. Now in `Aquarium.h`, inlcud ethe new class, add a boolean to kep tract of the b Key press. Then in the update method, if the bkey is pressed, add to count and push a pojyter to a new blue fish to the fis vector. That's it , you can now add blue fish to teh aquarium.

9. WHat if one of the fish has a unique functionality not part of the asbtract base class? We can cast up and down remember, lets see what that looks like

	a. In the `BlueFish.h`, add a new private attribute `bool reverse` which should be initialised to `false`, and a public method called onClick with the code below:
	~~~cpp
	void onClick()
	{
		if (!reverse && sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			reverse = true;
			velocity.x *= -1 ;
		}
		else if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{	
			reverse = false;
		}
	}
 	~~~

	b. SInce the onCLick method is not accessible through the base abstract class `Fish`, instances of BlueFish in the `fish` vector need to be downcasted to pointers to BlueFish from pointers to Fish to access the method. Therefore, the un the update method of Aquarium, inside the loop tah class swim on elements of fihs, add code to chek if a downcast is possinle form pointer to fish to pointer to Blue fish (this should only eb possible on lemenst that are inatnces of Blue Fish) if itis then call onCLick omethod on the converted pointer.

Extra Activity
------------
1. Update the asteroid clone game provided to have diverse types of obstacles. Using a base Onbstacle class, implement different obstacle classes with differen behaviours e.g. Asteroid (classic obstacle, drifts & spins, creates a swarm when hit), Comet (faster, maybe leaves a trail), explosive (slow, stationary, explodes if close to players), swarm (2 or 3 tiny obstacles moving together).

2. Create Snake using pointers. The pickups should all inherit from the same base class and be randomly generated with different perks e.g. regular growth, increased speed, decreased speed, invert head, invincibility.




   
