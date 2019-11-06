#ifndef STRING_MANIP_H
#define STRING_MANIP_H

#include <string.h>
#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int string_search_naive(char* string, char* pattern) {
    
    int string_length = strlen(string);
    int pattern_length = strlen(pattern);

    for(int i = 0; i < string_length - pattern_length; i++) {
        int j = 0;

        for(; j < pattern_length; j++) {

            if(string[i + j] != pattern[j])
                break;
        }

        if(j == pattern_length) {
            return 1;
        }
    }

    return 0;
}

//MARK:- BOYER MOORE

void bad_character_heuristics(char* string, int bad_character_table[256]) {

    int string_length = strlen(string);

    //initialize all entries to -1
    for(int i = 0; i < 256; i++)
        bad_character_table[i] = -1;

    //Fill last occurence of all characters
    for(int i = 0; i < string_length; i++)
        bad_character_table[(int)string[i]] = i;

}

int string_search_boyer_moore(char* string, char* pattern) {

    int find_index = -1;

    int string_length = strlen(string);
    int pattern_length = strlen(pattern);

    int bad_char_table[256];
    bad_character_heuristics(pattern, bad_char_table);

    int shift = 0;

    while(shift <= (string_length - pattern_length)) {

        int j = pattern_length - 1;

        while(j >= 0 && pattern[j] == string[shift + j])
            j--;
        
        if(j < 0) {
            find_index = shift;
            printf("Pattern found at %d\n", shift);
            //return shift;
            printf("%d\n", bad_char_table[string[shift + pattern_length]]);
            shift += (shift + pattern_length < string_length) ? pattern_length - bad_char_table[string[shift + pattern_length]] : 1;
            //shift++;

        } else {
            shift += max(1, j - bad_char_table[string[shift + j]]);
        }
    }

    return shift;
}



#endif