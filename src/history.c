#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

//Initialize the linked list to keep the history
List *init_history()
{
  List *list = (List*)malloc( sizeof(List) );
  list->root = 0;
  return list;
}

//Add a history item to the end of the list
void add_history(List *list, char *str)
{
  Item *item = malloc( sizeof(Item) ); //Allocating memory for a new item.
  Item *temp = list->root;
  item->str = str; //Set value to the string of new item
  item->next = 0; //Set value of the next item to null
  int count = 0;
  
  if (list->root == 0) //If the list is empty the new item becomes the root
    {
      item->id = count;
      list->root = item;
    } else //If the list is not empty, goes to the list until null is found
    {
      count = 1;
      while (temp->next != 0)
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
  Item *temp = list->root;
  
  while (temp != 0)
    {
      if (temp->id == id)
	{
	  return temp->str; //Return string if field found
	}
      temp = temp->next;
    }
  return 0; //Return zero if id not found
}

//Print the content of the list
void print_history(List *list)
{
  Item *temp = list->root->next;
  while (temp != 0)
    {
      printf("%d. %s", temp->id, temp->str); //Print string
      temp = temp->next;
    }
}

//Free the history list
void free_history(List *list)
{
  
}
