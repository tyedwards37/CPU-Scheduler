/// @file ssched.cpp
/// @brief - Runs a task through a given scheduler.
/// @author Tyler Edwards - tk.edwards2003@gmail.com

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "task.h"

#define SIZE    100

Task list[SIZE];
int listPos = 0; 

// Prints the task's information to mimic it "running"
// @input Task, int
// @output N/A
void run(Task *task, int slice) 
{
    printf("Running task = [%s] [%d] [%d] for %d units.\n",task->name, task->priority, task->burst, slice);
}

// Add task into the list of tasks
// @input char, int, int
// @output N/A
void add(char *name, int priority, int burst)
{
   Task t;
   t.name = name;
   t.priority = priority;
   t.burst = burst; 
   list[listPos] = t;
   listPos++;
}

// First-Come, First-Serve Scheduler Implementation
// @input N/A
// @output N/A
void schedule_fcfs()
{
   for(int j = 0; j < listPos; j++)
   {
      for(int i = 0; i < list[j].burst; i++)
      {
         run(&list[j], i + 1);
      }

      printf("\n");
   }
}

// Priority Scheduler Implementation
// @input N/A
// @output N/A
void schedule_priority()
{
   for(int i = 0; i < listPos; i++)
   {
      int min = 99;
      int next = 0;
      for(int j = 0; j < listPos; j++)
      {
         if(list[j].priority < min)
         {
            min = list[j].priority;
            next = j;
         }
      }

      for(int k = 0; k < list[next].burst; k++)
      {
         run(&list[next], k + 1);
      }
      
      list[next].priority = 99;
      printf("\n");
   }
}

// Round-Robin Scheduler Implementation
// @input N/A
// @output N/A
void schedule_rr()
{
   int timeQuantum = 2; // this variable can be changed

   for(int k = 0; k < listPos; k++)
   {
      while(list[k].burst != 0)
      {
         for(int j = 0; j < listPos; j++)
         {
            for(int i = 0; i < 2; i++)
            {
               if(list[j].burst == 0)
               {
                  break;
               }

               run(&list[j], i + 1);
               list[j].burst--;
            }
         }
         printf("\n");
      }
   }
}

// Shortest-Job First Scheduler Implementation
// @input N/A
// @output N/A
void schedule_sjf()
{
   for(int i = 0; i < listPos; i++)
   {
      int min = 99;
      int next = 0;
      for(int j = 0; j < listPos; j++)
      {
         if(list[j].burst < min)
         {
            min = list[j].burst;
            next = j;
         }
      }

      for(int k = 0; k < list[next].burst; k++)
      {
         run(&list[next], k + 1);
      }
      
      list[next].burst = 99;
      printf("\n");
   }
}

// getting the task list form the file
int main(int argc, char *argv[])
{
    FILE *in;
    char *temp;
    char task[SIZE];

    char *name;
    int   priority;
    int   burst;

    if (argc != 3) {
        printf("Usage: %s <sched> <taskList> \n", argv[0]);
        return -1;
    }

    in = fopen(argv[2],"r");
    
    while (fgets(task,SIZE,in) != NULL) {
        temp = strdup(task);
        name = strsep(&temp,",");
        priority = atoi(strsep(&temp,","));
        burst = atoi(strsep(&temp,","));

        // create the task add the task to the scheduler's list of tasks
        add(name,priority,burst);

        free(temp);
    }

    fclose(in);

    // invoke the correct scheduler
    if (strncmp(argv[1], "fcfs", 4) == 0) {
       schedule_fcfs();
    } else if (strncmp(argv[1], "priority", 8) == 0) {
       schedule_priority();
    } else if (strncmp(argv[1], "rr", 2) == 0) {
       schedule_rr();
    } else if (strncmp(argv[1], "sjf", 3) == 0) {
       schedule_sjf();
    } else {
       printf("Error: scheduler '%s' not supported \n", argv[1]);
       return -1;
    }

    return 0;
}
