Practice Tasks
-------------

Main Activity: Simple Pong
--------

1. Download, unzip and run this activity's starter project.
2. In the `Particle.h` file:
  
    a. Update the `Particle` constructor by adding an initialiser list to initalise the `parent`, `position` and `velocity` attributes to the arguments passed to the constructor.
  
    b. Add a public `update` method that returns void, it should be empyt for now.

    c. Add two getters that return the `position` and the `velocity` attributes.

    d. Add a public `draw` method that returns void, has one paramter `sf::RenderWindow& window`, and is empty for now.

4. This should all be fairly obvious as a skeleton class for a particle. The most important thing to note is the second line (`class ParticleSystem`). This is called a forward declaration. It tells the compiler that `class ParticleSystem` exists somewhere, so we can add variables of that type to this class. Why didn’t we just `#include ParticleSystem.h`? Because we want `ParticleSystem.h` to include `Particle.h` and if we did that we would have a circular dependency. It’s one of the messier aspects of C++ that we have to do this. One consequence of that is that we can’t do anything with the `ParticleSystem` class in this header file (like call any member functions) and will need to put any code that does that into `Particle.cpp`.

5. In the `ParticleSystem.h` file:

     a. Add a `std::vector` to store pointers to `Particle` as a private member atrritbute

     b. Update the `ParticleSystem` constructor by adding an initialiser list to initalise the `gravity` and `maxParticles` attributes.

     c. Add a public `update` method that returns void, it should be empyt for now.

     d. Add a public `draw` method that returns void, has one paramter `sf::RenderWindow& window`, and is empty for now.

     e. Add a getter that returns `gravity`.

6. The particle system is responsible for all the rendering. It contains the texture and a draw method which, when we fill it in, will loop over the particles in the system getting the position from each particle and using that to draw a sprite. Note that we use a vector of pointers to `Particle` to store the particles. Check that everything builds and runs with no errors, it won’t do anything yet.

7. Let's add a method to `ParticleSystem` that creates and returns a pointer to a new `Particle`:

     a. Add the declaration `Particle* spawnParticle();` in the private delcartion area of `ParticleSystem.h`.

     b. Add the implementation below in `ParticleSystem.cpp`
     ~~~cpp
     Particle* ParticleSystem::spawnParticle ()
     {
          sf::Vector2f velocity;
          sf::Vector2f position;
      
          random_device rd;
          uniform_real_distribution<float> dist(0.0f, 1.0f);
          position.x = 512.0f;
          position.y = 700.0f;
          velocity.x = -40.0f + 80.0f * dist(rd);
          velocity.y = -100.0 - 400.0f * dist(rd);
          return new Particle(position, velocity, *this);
     } 
     ~~~

     c. In the `ParticleSystem` constructor implementation in `ParticleSystem.cpp`, add a loop that which calls the `spawnParticle` method and pushes each to the `particles` vector until `maxParticles` number of particles have been created.

     d. In the `update` method implemented in `ParticleSystem.cpp`, add a loop that iterates through the `particles` vector and calls the `update` method of each one.

     e. In the `draw` method implemented in `ParticleSystem.cpp`, add a loop that iterates through the `particles` vector and for each particle, it sets the position of the `sprite` member attribute of `ParticleSystem` to the particle's position, and it draws the `sprite` using the reference to the window object passed to the method as an argument (the draw method should take a second argument `sf::BlendAdd` i.e. `window.draw(sprite, sf::BlendAdd)`.

9. Let's bring it all together now:

    a. Make sure to instantiate a ParticleSystem in the main program. You can use the texture “assets/blob.png” for this. You will need to choose a value for gravity (I used sf::Vector2f(0, 150)).

    b. In the main loop, call the update and draw methods of the `ParticleSystem` instance you created inthe game-loop. As last week, use `dt` for the update time.

    c. If everything's been implement correctly, the particles should appear but won't move. To make them move, we need to implement the update method of the `Particle` class. The implementation should add `velocity * deltaTime` to `position` and `gravity * deltaTime` to `velocity`. You will need to use the `getGravity` method from the `parent` to get the gravity vector.

10. To respwan particles that get to the bottom of the window:
   
    a. Update the implementation of the the `update` method in `ParticleSystem` so that after each particle is updated, we check if its y-position is say greater than 700, and if so, we call spawmPartice and replace the pointer to the fallen particle with the newly returned pointer.

    b. The problem with this code we just added is it introduced a memory leak. You can see this slowly happening by watching the memory monitor in Visual Studio as you run (it should slowly climb). Let’s make this more obvious by adding a chunk of memory to the `Particle` class. Add `int dummyMemory[1000];` as a private member attribute to the class definition, which will add 4000 bytes to each particle.

    c. To fix the memory leak, use delete to release the pointer to the fallen particle before assigning a new pointer in its place in `particles`.

11. Let's refactor the code so that it uses smart pointers instead of raw pointers.

    a. Replace the declaration of the `particles` vector in `ParticleSystem.h` so it is now a vector of `unique_ptr`, as follows `std::vector<unique_ptr<Particle>> particles`;

    b. Update `spawnParticle` byt changing its return type is unique_ptr and the last line of the method so that it returns a unique_ptr, as follows `return make_unique<Particle>(position, velocity, *this);`

    c. Remove the use of `delete` that you added ealiers, since its no longer needed when using a smart pointer.

    d. Confirm that the code works and does not leak.

12. You can see that we can overwrite the value of a unique_ptr variable with a new unique_ptr and it then frees the memory allocated to the original pointer. This is because by overwriting the value, we have indicated we no longer need the memory (since nothing in the code has any reference to that object any more). Passing a local unique_ptr variable back as the return value from a function (as we did in Spawn) works - the memory is ‘passed on’ to the new owner. A unique_ptr can only have one owner, and when it no longer has an owner, the memory is deleted.
 
Extra Activity
------------




   
