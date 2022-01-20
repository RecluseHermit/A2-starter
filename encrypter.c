#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 256 // maximum length of a single word

char rotate(char c, int n){
    // index in ASCII
    int charIndex = (int)c;

    // upper case
    if(charIndex >= 65 && charIndex <= 90){
        charIndex = (charIndex + n - 65) % 26 + 65;
    }

    // lower case
    else if(charIndex >= 97 && charIndex <= 122){
        charIndex = (charIndex + n - 97) % 26 + 97;
    }

    // return
    return (char)charIndex;
}

int main(int argc, char* argv[]) {
  char word[MAX_LEN];

  // read file
  FILE* fin = fopen( argv[1], "r" );

  if(fin == NULL) {
    perror("Could not open input file.");
    return 1;
  }

  // basic variables
  int wordCount = 0;
  int number = atoi(argv[2]);
  int current;

  // go over the file and set values
  while ((current = fgetc(fin)) != EOF){
      // space or new line
      if(current == 10 || current == 32){
          // print the reverse
          for(int i = wordCount - 1; i >= 0; i--){
              printf("%c", (char)word[i]);
          }

          // print the last ending space or new line
          printf("%c", (char)current);

          // set to zero
          wordCount = 0;
      }

      // chars in words
      else{
          word[wordCount] = rotate((char)current, number);
          wordCount++;
      }
  }

  // clean up gracefully
  fclose(fin);

  return 0;
}
