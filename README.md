# Philosophers
This project is a training to multi-threads/multi-process programming with the use of mutex and semaphore.
It contains 3 different programs simulating a twist of the famous Dining Philosophers problem, all with the same basic rules.
This project is also a good lesson in C optimization as we need to save every bit of CPU usage we can to ensure the survival of our philosophers.

philo: multi-threads and use of mutex
philo_bonus: multi-processes and use of semaphore

# Status

Under evaluation.

# Usage

Compile with ```make``` inside the folder philo. Philo should now be ready!

Compile with ```make``` inside the folder philo_bonus. Philo bonus should now be ready!

## Executing Philosophers

At execution time, you must specify a number of philo and all the times necessary. You may also provide other optional parameters:

```shell
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
```
```shell
./philo_bonus <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
```
