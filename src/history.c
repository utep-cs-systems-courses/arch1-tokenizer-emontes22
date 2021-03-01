#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

//Initialize the linked list to keep the history
List *init_history()
{
  List *list = (List*)malloc( sizeof(List) );
  list->root = NULL;
  return list;
}

//Add a history item to the end of the list
void add_history(List *list, char *str)
{
  Item *item = malloc( sizeof(Item) ); //Allocating memory for a new item.
  Item *temp = list->root;
  item->str = str; //Set value to the string of new item
  item->next = NULL; //Set value of the next item to null
  int count = 0;
  
  if (list->root == NULL) //If the list is empty the new item becomes the root
    {
      item->id = count;
      list->root = item;
    } else //If the list is not empty, goes to the list until null is found
    {
      count = 1;
      while (temp->next != NULL)
	{
	  count++;
	  temp = temp ->next;
	}
      temp->next = item;
      item->id = count;
    }
}

//Retrieve the string stored in the node
char *get_history(List *list, int id)
{
  
}

//Print the content of the list
void print_history(List *list)
{
  
}

//Free the history list
void free_history(List *list)
{
  
}
