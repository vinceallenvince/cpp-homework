/**
 * Vince Allen
 * 10-18-2015
 * Quiz1
 *
 * You are given a character string  containing the following prose:
 * "To be or not to be – that is the question: Whether 'tis nobler in the mind to suffer the
 * slings and arrows of outrageous fortune, or to take arms against a sea of troubles and, by
 * opposing, end them. To die, to sleep"
 *
 * Write a program that contains the following functions:
 * 1.	Calculates the length of the string ( int len stringLength( char string[ ])
 * 2.	Calculates the number of times that a white space appears ( int symbol( char string[], char symbol)
 * 3.	Reuse the above function to find out how many times
 *      the word "the" appears (int symbol( char string[], char *symbol)
 * PS – Do not use any  of the  <string.h>  functions except strcmp(char *, char *)
 *
 * OUTPUT:
 * Length: 218
 * Total spaces: 43
 * Total 'the' words: 3
 */

#include <iostream>
#include <string.h>

int len_stringLength(char string[]);
int symbol(char string[], char symbol);
int symbol(char string[], char *symbol);
bool checkNeedleBuffer(char c);
void matchNeedle(char string[], char * symbol, int size, int i, int &check);

char HAYSTACK[] = "To be or not to be – that is the question: Whether 'tis nobler in the mind to suffer the slings and arrows of outrageous fortune, or to take arms against a sea of troubles and, by opposing, end them. To die, to sleep";

char NEEDLE[] = "the";


int main(int argc, const char * argv[]) {
    printf("Length: %d \n", len_stringLength(HAYSTACK));
    printf("Total spaces: %d \n", symbol(HAYSTACK, ' '));
    printf("Total 'the' words: %d \n", symbol(HAYSTACK, NEEDLE));

    return 0;
}

int len_stringLength(char string[])

{
    int i = 0;
    while (string[i]) {
        i++;
    }

    return i;
}

int symbol(char string[], char symbol)

{
    int total = 0;
    int haystackLength = len_stringLength(string);

    for (int i = 0; i < haystackLength; i++) {
        if (string[i] == symbol) {
            total++;
        }
    }

    return total;
}



int symbol(char string[], char * symbol)

{
    int total = 0;
    int needleLength = len_stringLength(symbol);
    int haystackLength = len_stringLength(string);
    int matches;

    for (int i = 0; i < haystackLength - needleLength; i++) {
        matches = 0;
        if (!checkNeedleBuffer(string[i]) || !checkNeedleBuffer(string[i + needleLength + 1])) {
            continue;
        }

        matchNeedle(string, symbol, needleLength, i, matches);

        if (matches == needleLength) {
            total++;
        }
    }

    return total;
}

bool checkNeedleBuffer(char c)
{
    return c == ' ';
}

void matchNeedle(char string[], char * symbol, int needleLength, int i, int &matches)

{
    for (int j = 0; j < needleLength; j++) {
        if (string[i + j + 1] != symbol[j]) {
            return;
        }
        matches++;
    }
}
