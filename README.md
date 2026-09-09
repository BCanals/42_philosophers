_This project has been created as part of the 42 curriculum by becanals._


# PHILOSOPHERS 
_Love knowledge but also eating spaghetti_


## Description
This project is aimed at learning how to use and coordinate threads using mutexes.
To do so, the program must create a number of threads (the philosophers) specified by the user. They will have access to a shared resource (the forks) and must take turns locking them in a syncronized manner.
In addition, the program will have to log the states changes of the threads (e.g. "philosopher 4 has taken a fork") prefixed with the simulation running time.
Each thread will go through three main states:

- **Thinking**: During this state, the philosopher will try to take their two specific (but shared) forks.
- **Eating**: Once the philosopher has taken (and therefore, locked) both forks, they will start to eat. The amount of time spent eating is preset by the user.
- **Sleeping**: After eating, the philosopher will release their two forks and start sleeping. The time taken by this step is also chosen by the user calling the program.
- **DEATH!**: A philosopher will die if a certain amount of time has passed since the last time they started eating and they haven't start eating again. This amount of time is set by the user too.

If a philosopher dies, the simulation stops.

## Instructionsa

### Instalation
Just clone the repo

### Compilation
Execute the 'make' command. The Makefile will do the job for you.

The executable will be created in the root of the repo and will be named 'philo'
Object files will we created in a 'build' directory in the same repo. The directory will be created automatically if missing.

The other rules for the Makefile are:

 - make philo: synonim of just 'make'. Will create the necessary object files and compile the program.
 - make clean: will remove the build directory containing the object files.
 - make fclean: will delete the build directory and also the executable philo.
 - make re: will call "make fclean" and "make" in sequence.

### Executions
The user is expected to set the number of philosophers (threads), time to die, time to eat and time to sleep.
All time arguments are given in miliseconds.
Additionally, the user may specify a number of meals. Once all philosophers have reached the specified number of meals, the simulation will stop. This argument is optional.
All arguments must contain numeric characters only.

> [!TIP]
> the expected input is: ./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]

If invalid input is given when calling the program, it will not execute and show a help prompt.

## Resources
### Similar projects
This code was highly inspired in my colleagues' projects:

- [atresiita](https://github.com/artesiita/philosophers)
- [encarbassotnopot](https://github.com/encarbassotnopot/42_philosophers)

### Articles
I also took some ideas and found helpful information in [this article](https://medium.com/@denaelgammal/dining-philosophers-problem-42-project-guide-mandatory-part-a20fb8dc530e)

### Tutorials
I started getting familiarized with threads and mutexes with [this tutorial](https://www.youtube.com/watch\?v\=d9s_d28yJq0\&list\=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2)

### AI
AI was used only for debugging in a moment of deep desperation.
Claude was given my code to help me identify why the philosophers kept dying whenever the number of threads was odd. This did not produce a direct solution but pointed me towards the design issue that was blocking me.

And also for a linguistic check of this README.
