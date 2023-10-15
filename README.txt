#READ.ME

Project: CPU Scheduling
by Tyler Edwards and Jack de Bruyn
Added October 2023

Description: Implementation and demonstration of different scheduling algorithms. The scheduler gets a set of tasks, defined in an input file, and "runs" them using a user-specified algorithm. The format of the tasks are: [TASK NAME] [PRIORITY] [CPU BURST].

Language: C 

Reason: For CPSC 380 (Operating Systems)

Successes: By implementing them in C, I gained a better understanding as to how each of the scheduling algorithms function.

Setbacks: Understanding how to weave the implementation into the given base code provided difficult at the start of the project.

Learned: Functions of different scheduling algorithms.


/*
Commands:
gcc ssched.c -o ssched
./ssched [SCHEDULER] TaskList.txt

Four options for [SCHEDULER]:
- fcfs (First-Come, First-Serve)	
- sjf (Shortest-Job-First)
- priority (Priority Scheduling)
- rr (Round-Robin)

Output:
Running task = [Px] [y] [z] for 1 units.
...
*/

- Started from in-class base code
