#include "tokenizer.h"
#include <stdio.h>
#include <stdlib.h>

//Return true if char is a space, false if non-space char
int space_char(char c)
{
  if( (c == ' ' || c == '\t') && c != '\0')
    return 1;
  return 0;
}

//Return true if char is a non space character, false if space char
int non_space_char(char c)
{
  if( (c != ' ' && c != '\t') && c != '\0')
    return 1;
  return 0;
}

//Return a pointer to the start of the first char
char *word_start(char *s)
{
  int i = 0;
  while ( space_char (s[i]) )
    i++;
  return &s[i];
}

//Return a pointer to the end of the string
char *word_terminator(char *word)
{
  word = word_start(word); //If word begins with empty space, remove empty space.
  int i = 0;
  while ( non_space_char (word[i]) ) //Checks word until space is found
    i++;
  return &word[i];
}

//Return the number of words on a string
int count_words(char *str)
{
  int i = 0;
  int count = 0;

  //Search the given char to count how many space char follows a non-space char
  while ( str != word_terminator(str) )
    {
      str = word_terminator(str);
      count++;
    }
  return count;
}

//Return a copy of a string
char *copy_str(char *inStr, short len)
{
  int i = 0;
  char *strCpy = malloc( (len+1) * sizeof(char) );
  for ( i = 0; i < len; i++ )
    {
      strCpy[i] = inStr[i]; //Copying content from inStr to strCpy
    }
  strCpy[i] = '\0'; //Set last value of strCpy to '\0'
  return strCpy;
}

//Returns a freshly allocated vector string
char **tokenize(char *str)
{
  int i;
  int wordCounter = count_words(str);    //Set a char pointer for each word in string + 1
  char **tokens = malloc( (wordCounter + 1) * sizeof(char *) );
  char *start = word_start(str);
  char *end = word_terminator(str);
  
  for (i = 0; i < wordCounter; i++) {  //Find length of word
    tokens[i] = copy_str(start ,end - start);
    start = word_start(end); //Get start of next word
    end = word_terminator(start); //Get end of next word
  }
  tokens[i] = 0; //Set last element to null
  return tokens;
}

//Print all tokens
void print_tokens(char **tokens)
{
  int i;
  for (i = 0; tokens[i] != 0; i++) {
    printf("%s\n",tokens[i]); //Print each token
  }
}

//Free all tokens and the vectors containing them
void free_tokens(char **tokens)
{
  int i;
  for (i = 0; tokens[i] != 0; i++) {
    free(tokens[i]); //Free each word in tokens
  }
  free(tokens); //Free the allocated memory for tokens
}
