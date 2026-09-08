_This project has been created as part of the 42 curriculum by becanals_


# PHILOSOHERS 
_Love knowledge but also eating spaghetti_


## Description
This project is aimed at learning how to use and coordinate threads through mutexes.
To do so, the program must create a number of threads (the philosophers) determined by the user. They will have access to a shared resource (the forks) and must take turns blocking them in a syncronized matter.
In adition, the program will have to log the states changes of the threads (eg "philosopher 4 has taken a fork") prefixed with the simulation running time.
Each thread will run through three states:
	- **Thinking**: during this state, the philosoher will try to their two specific (but shared) forks.
	- **Eeating**: Once the philosopher has taken (and so, mutexed) their two forks, they will start to eat. The amount of milisecons that this state takes is preset by the user.
	- **Sleepping**: After eating, the philosopher will surrender their two forks and start doing nothing. The time taken by this step is also chosen by the user calling the program.
	- **DEATH!**: A philosopher will die if a certain amount of time has passed since the last time they have started eating and they aren't eating again. This amount of time is set by the user too.

If a philosopher dies, the simulation stops.

## Instructions
The user is expected to set the number of philosophers (threads), the eating time, sleeping time, and time to die.
All time arguments are given in miliseconds.
Adittionally, the user may set a number of meals. Once all philosophers have reached the set number of meals, the simulation will stop. This argument is optional.
All the arguments must be given in numeric characters only.

> [!TIP]
> number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]

If an invalid input is given while calling the program, it will not execute and show a helping prompt.

## Resources
### Similar projects
This code was highly inspired in my colleagues' projects:
	- [encarbassotnopot](https://github.com/artesiita/philosophers)
	- [atresiita](https://github.com/encarbassotnopot/42_philosophers)

### Articles
I also took some ideas and found helping [this article](https://github.com/encarbassotnopot/42_philosophers)

### AI
AI was used only for debuigging in a moment of deep desperations.
Claude  was given my code to help me identify why the philosophers kept dying whenever the number of threads was odd. This didn't produce a direct solution but pointed me to the designing issue that was blocking me.
