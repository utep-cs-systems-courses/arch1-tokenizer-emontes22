#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

int main ()
{
  char input[50];
  List *history = init_history();

  while(1)
    {
      printf("Welcome, please select from the following options:\n");
      printf("'1' To tokenize a sentence.\n'2' To view the history.\n'0n' To print a specific item from history where 'n' is the number of the item.\n'4' To quit.\n>");

      fgets(input, 50, stdin);
      int choice = atoi(input);
      
      switch (choice)
	{
	case 1:
	  printf("Enter a sentence to tokenize:\n>");
	  fgets(input, 50, stdin);
	  add_history(history, input);
	  char **tokens = tokenize(input);
	  print_tokens(tokens);
	  free_tokens(tokens);
	  break;
	 
	case 2:
	  print_history(history);
	  break;

	case 0:
	  printf(" ");
	  char *getHistory = get_history(history, atoi(input + 1));
	  printf("String from history: %s\n>", getHistory);
	  break;
	  
	case 4:
	  exit(0);
	  break;

	default:
	  exit(0);
	  break;
	}
    }
}
