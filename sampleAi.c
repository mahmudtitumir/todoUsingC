#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define MAX_TASKS 10

// Structure to represent a task
struct Task
{
  char description[50];
  int completed;
};

// Function to display the menu
void displayMenu()
{
  printf("\n----- To-Do List Menu -----\n");
  printf("1. Add Task\n");
  printf("2. View Tasks\n");
  printf("3. Mark Task as Complete\n");
  printf("4. Exit\n");
  printf("---------------------------\n");
}

// Function to add a task to the to-do list
void addTask(struct Task tasks[], int *taskCount)
{
  if (*taskCount < MAX_TASKS)
  {
    printf("\nEnter task description: ");
    fflush(stdin); // Clear input buffer
    gets(tasks[*taskCount].description);
    tasks[*taskCount].completed = 0; // 0 indicates task is not completed
    (*taskCount)++;
    printf("Task added successfully!\n");
  }
  else
  {
    printf("To-Do list is full. Cannot add more tasks.\n");
  }
}

// Function to view the to-do list
void viewTasks(struct Task tasks[], int taskCount)
{
  if (taskCount == 0)
  {
    printf("\nNo tasks in the to-do list.\n");
  }
  else
  {
    printf("\n----- To-Do List -----\n");
    for (int i = 0; i < taskCount; i++)
    {
      printf("%d. %s - %s\n", i + 1, tasks[i].completed ? "[Completed]" : "[Pending]", tasks[i].description);
    }
    printf("-----------------------\n");
  }
}

// Function to mark a task as complete
void markComplete(struct Task tasks[], int taskCount)
{
  if (taskCount == 0)
  {
    printf("\nNo tasks in the to-do list.\n");
  }
  else
  {
    int taskNumber;
    viewTasks(tasks, taskCount);
    printf("Enter the task number to mark as complete: ");
    scanf("%d", &taskNumber);

    if (taskNumber > 0 && taskNumber <= taskCount)
    {
      tasks[taskNumber - 1].completed = 1; // Mark task as complete
      printf("Task marked as complete!\n");
    }
    else
    {
      printf("Invalid task number.\n");
    }
  }
}

int main()
{
  struct Task tasks[MAX_TASKS];
  int taskCount = 0;
  int choice;

  do
  {
    displayMenu();
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      addTask(tasks, &taskCount);
      break;
    case 2:
      viewTasks(tasks, taskCount);
      break;
    case 3:
      markComplete(tasks, taskCount);
      break;
    case 4:
      printf("\nExiting program. Goodbye!\n");
      break;
    default:
      printf("\nInvalid choice. Please try again.\n");
    }

    // Wait for user to press a key before clearing the screen
    printf("\nPress any key to continue...");
    getch();
    system("cls"); // Clear the screen

  } while (choice != 4);

  return 0;
}
