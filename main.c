#ifndef TXT
#define TXT 1024
#endif
#ifndef WORD
#define WORD 30
#endif

#include "header.h"
#include <math.h>
#include <stdio.h>

int main(){
    int i = 0;
    int j = 0;
    char word[WORD] = { '\0' };
    char text[TXT] = { '\0' };
    char ch_w;
    char ch_t;

    //to get the word
    do{
       scanf("%c",&ch_w);
       word[i] = ch_w;
       i++;
    }
    while(ch_w != 9 && ch_w != 10 && ch_w != 32 && i<WORD);

    //to get the txt
     do{
       scanf("%c",&ch_t);
       text[j] = ch_t;
       j++;
    }
    while(ch_t != '~' && j<TXT);


    int gem = 0;
    for (i = 0; i < sizeof(word)/sizeof(word[0]); i++) {
        int num = word[i];
        if (num>96 && num<123){
            gem += num-96;
        }
        if (num>64 && num<91){
            gem += num-64;
        }
    }
    printf("Gematria Sequences: ");
    gematria(gem , text);
    printf("\nAtbash Sequences: ");
    azby(word , text);
    printf("\nAnagram Sequences: ");
    minimal(word , text);

    return 0;
}