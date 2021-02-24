#include "tokenizer.h"
#include <stdio.h>
#include <stdlib.h>

//Return true if char is a space, false if non-space char
int space_char (char c)
{
  if( (c == ' ' || c == '\t') && c != '\0')
    return 1;
  return 0;
}

//Return true if char is a non space character, false if space char
int non_space_char (char c)
{
  if( (c != ' ' && c != '\t') && c != '\0')
    return 1;
  return 0;
}

//Return a pointer to the start of the first char
char *word_start (char *s)
{
  int i = 0;
  while ( space_char (s[i]) )
    i++;
  return &s[i];
}

//Return a pointer to the end of the char
char *word_terminator (char *word)
{
  word = word_start(word); //If word begins with empty space, remove empty space.
  int i = 0;
  while ( non_space_char (word[i]) ) //Checks word until space is found
    i++;
  return &word[i];
}

//Return the number of words on a char
int count_words (char *s)
{
  int i = 0;
  int count = 0;

  //Search the given char to count how many space char follows a non-space char
  while ( s != word_terminator(s) )
    {
      s = word_terminator(s);
      count++;
    }
  return count;
}
