#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

typedef struct node
{
    int number;
    struct node *next;
} node;

int main(void)
{
    node *list = NULL;

    for (int i = 0; i < 3; i++)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            // TODO: free any memory already malloc'd
            return 1; // Memory allocation failed
        }
        n->number = get_int("Number: ");

        n->next = NULL; // Initialize the next pointer to NULL
        // If the list is empty, set the new node as the head
        if (list == NULL)
        {
            list = n; // If the list is empty, set the new node as the head
        }
        // If the list is not empty, traverse to the end of the list
        else
        {
            for (node *ptr = list; ptr != NULL; ptr = ptr->next)
            {
                // If at end of list, append the new node
                if (ptr->next == NULL)
                {
                    ptr->next = n; // Append the new node at the end of the list
                    break;
                }
            }
        }

    }

    //Time passes

   for (node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        printf("%i\n", ptr->number); // Print each number in the list
    }

    //Time Passes

    node *ptr = list
    while (ptr != NULL)
    {
        node *next = ptr->next; // Store the next node
        free(ptr);
        ptr = next; // Move to the next node
    }

    return 0; // Successful execution
}

