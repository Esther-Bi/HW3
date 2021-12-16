#include "header.h"
#include <math.h>
#include <stdio.h>
#include <string.h>

#ifndef TXT
#define TXT 1024
#endif
#ifndef WORD
#define WORD 30
#endif

void removeFirst(char * str, const char toRemove){
    int i = 0;
    int len = strlen(str);

    /* Run loop till the first occurrence of the character is not found */
    while(i<len && str[i]!=toRemove)
        i++;

    /* Shift all characters right to the position found above, to one place left */
    while(i < len){
        str[i] = str[i+1];
        i++;
    }
}
void removeChar(char *str, char garbage) {
    char *src, *dst;
    int once = 0;
    for (src = dst = str; *src != '\0'; src++) {
        *dst = *src;
        if ((*dst != garbage) || (once == 1)) dst++;
        if (*dst == garbage) once = 1;
    }
    *dst = '\0';
}

void gematria(int gem , char text[]){
    int sum = 0;
    int first = 0;
    for (int i = 0; i < strlen(text); i++) {
        if ((text[i]>64 && text[i]<91) || (text[i]>96 && text[i]<123)){
            for (int j = i; j < strlen(text); j++) {
                if (text[j]>96 && text[j]<123){
                    sum += text[j]-96;
                }
                if (text[j]>64 && text[j]<91){
                    sum += text[j]-64;
                }
                if (sum==gem){
                    if (first==0){
                        for (int k=i ; k<=j ; k++){
                            printf("%c" , text[k]);
                        }
                        first = 1;
                        break;
                    }
                    if (first==1){
                        printf("~");
                        for (int k=i ; k<=j ; k++){
                            printf("%c" , text[k]);
                        }
                        break;
                    }
                }
                if (sum>gem){
                    break;
                }
            }
            sum = 0; 
        }
    } 
}

void azby(char word[] , char text[]){
    int first = 0;
    char atbash[WORD] = { '\0' };
    char oppositeAtbash[WORD] = { '\0' };
    for (int i = 0; i < strlen(word); i++) {
        if (word[i]>64 && word[i]<91){
            atbash[i] = ((word[i]-64) + 2*(13-(word[i]-64)) + 1)+64;
            oppositeAtbash[strlen(word)-i-2] = ((word[i]-64) + 2*(13-(word[i]-64)) + 1)+64;
        }
        if (word[i]>96 && word[i]<123){
            atbash[i] = ((word[i]-96) + 2*(13-(word[i]-96)) + 1)+96;
            oppositeAtbash[strlen(word)-i-2] = ((word[i]-96) + 2*(13-(word[i]-96)) + 1)+96;
        }
    }
    for (int i = 0; i < strlen(text); i++) {
        int index = 0;
        int opp = 0;
        int at = 0;
        if ((text[i]>64 && text[i]<91) || (text[i]>96 && text[i]<123)){
            for (int j = i; j<strlen(text); j++) {
                if (j==i){
                    if (text[j]==oppositeAtbash[0]){
                        // printf("\nim in opposite %c\n" , text[j]);
                        opp = 1;
                        index++;
                    }
                    else if (text[j]==atbash[0]){
                        // printf("\nim in atbash %c\n" , text[j]);
                        at = 1;
                        index++;
                        // printf("index is now: %d\n" , index);
                    }
                    else{
                        break;
                    }
                }
                else{
                    if (text[j]!=32){
                        // printf("\nim in , opp: %d , at: %d\n" , opp , at);
                        // printf("text[j]: %c ,atbash[index]: %c ,oppositeAtbash[index]: %c \n" , text[j] , atbash[index] , oppositeAtbash[index]);
                        if (opp==1 && text[j]!=oppositeAtbash[index]){
                            break;
                        }
                        if (at==1 && text[j]!=atbash[index]){
                            break;
                        }
                        else{
                            index++;
                            // printf("\nim in else , index: %d , strlen: %ld\n" , index , strlen(word));
                        }
                    }
                }
                if (index == strlen(word)-1){
                    // printf("\nim in index==strlen(word)\n");
                    if (first==0){
                        for (int k=i ; k<=j ; k++){
                            printf("%c" , text[k]);
                        }
                        first = 1;
                        break;
                    }
                    if (first==1){
                        printf("~");
                        for (int k=i ; k<=j ; k++){
                            printf("%c" , text[k]);
                        }
                    }
                    break;
                }
            }
        }
    } 
}

void minimal(char word[] , char text[]){
    int first = 0;
    for (int i = 0; i < strlen(text); i++){
        if ((text[i]>64 && text[i]<91) || (text[i]>96 && text[i]<123)){
            char copy[strlen(word)];
            strcpy(copy,word);
            for (int j = i; j < strlen(text); j++) {
                if (text[j]!=32 && text[j]!=9 && text[j]!=10){
                    int size = strlen(copy);
                    removeFirst(copy,text[j]);
                    if (strlen(copy)==size){
                        break;
                    }
                    if (strlen(copy)==1){
                        if (first==0){
                            for (int k=i ; k<=j ; k++){
                                printf("%c" , text[k]);
                            } 
                            first = 1;
                            break;
                        }
                        if (first==1){
                            printf("~");
                            for (int k=i ; k<=j ; k++){
                                printf("%c" , text[k]);
                            }
                        }
                        break;
                    }
                }
                
            }
        }
    }
}