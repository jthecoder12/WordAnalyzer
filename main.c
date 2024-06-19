#include <stdio.h>
#include <string.h>

char checkString(FILE *fptr, char word[35]) {
    for(int i=0; i<strlen(word)/(int)2; i++) {
        if(word[i] != word[strlen(word)-i-2]) {
            return 'n';
        }
    }

    return 'y';
}

int main(int argc, char *argv[]) {
    FILE *fptr;

    fptr = fopen(argv[1], "r");

    char word[35];

    char biggestWord[35] = "";

    int palindromes = 0;

    while(fgets(word, 35, fptr)) {
        char result = checkString(fptr, word);

        word[strlen(word)-1]='\0';

        if(result == 'y') {
            palindromes++;

            if(strlen(word) > strlen(biggestWord)) {
                strcpy(biggestWord, word);
            }

            if(strlen(word) >= 4) {
                printf("%s\n", word);
            }
        }
    }

    fclose(fptr);

    printf("Palindromes: %d\n", palindromes);
    printf("One of the biggest palindromes: %s\n", biggestWord);
    printf("There may be more palindromes with the same number of letters as that one.\n");

    return 0;
}
