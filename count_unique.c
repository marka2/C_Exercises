#include <stdio.h>

/*
 *    Author: Mark Arakaki
 *    November 6, 2017
 *    Purpose: This program counts the number of unique characters in a string.
 *
 *    For a further explanation on the strategy behind this:
 *
 *          String = Hello
 *          H vs. H | H vs. e | H vs. l | H vs. l | H vs. o
 *          e vs. H | e vs. e | e vs. l | e vs. l | e vs. o
 *          l vs. H | l vs. e | l vs. l | l vs. l | l vs. o             * common match found
 *          l vs. H | l vs. e | l vs. l | l vs. l | l vs. o             * common match found
 *          o vs. H | o vs. e | o vs. l | o vs. l | o vs. o
 *
 *    Use two for loops to compare every character to every character (including self).
 */

/*
 *    Purpose: Find number of characters in a character array pointer
 *    Return number of characters (int)
*/
int count_chars (char * single_string) {
      int i = 0;
      char elementCharacter;
      while (elementCharacter != '\0') {              // if character read is null stop reading
            elementCharacter = single_string[i];     // read a character at index i
            i++;        // increment character count
      }
      i--;        // Decrement count by 1 because while loop will include null character in count
      return i;   // return the character count (i)
}

int main(int argc, char const *argv[]) {

      char myString[] = "tree";      // this is the string you are trying to analyze
      int num_of_chars = 0;         // variable that will equal the return value of count_chars
      int unique_chars = 0;         // will count the unique characters found

      int commonCount = 0;          // will count the common characters found

      num_of_chars = count_chars(myString);     // I want to collect the num of chars in array for for loops later

      for (int i = 0; i < num_of_chars; i++) {  // outer for loop that will analyze the string in question

            for (int j = 0; j < num_of_chars; j++) {  // inner for loop that will analyze the string in question

                  if (myString[i] == myString[j]) {   // if a character match is found then incrememnt common count
                        printf("");       // Bug for some odd reason line 62 printf won't work without this????
                        commonCount++;    // increment common count
                  }
            }

            if (commonCount < 2) {  // Since a letter will always have a match (itself) then I can assume
                                    // if I found more than 1 match then the char is no longer unique
                  unique_chars++;   // increment unique chars count because only found 1 match.
            }
            commonCount = 0;  // reset the common count counter so that it doesn't interfere with future counts
      }

      printf("%i\n", unique_chars); // print unique_chars
      return 0;
}


// Hello
// Hello
