#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
bool sidein(char*guess, char creco){
    if(guess == 0) return true;
    for(int i = 0; i < strlen(guess); i++){
        if(guess[i] == creco)
        return false;
    }
    return true;
}
char * inp_code(){
    char *cod = malloc(4);
    int inp = 0;
    srand(time(0));
    while(strlen(cod) < 4){
        char x = rand() % 8 + '0';
        if(sidein(cod, x))
            cod[inp++] = x;
    }
    return cod;
}
int good_p(char *guess1, char *guess2) {
    int good = 0;
    for(int f = 0; f < strlen(guess1); f++){
        if(guess1[f] == guess2[f])
            good++;
    }
    return good;
    }
bool peat_re(char *str){
    for(int i=0; i<strlen(str) - 1; i++){
        for(int s=i++; s<strlen(str); s++){
            if(str[i] == str[s])
            return true; 
        }
    }
    return false;
}
bool wrong_get(char *guess){
    if(strlen(guess) != 4) return true;
    int i = 0;
    while(i < strlen(guess)){
        if(guess[i]>'7' && guess[i]< '0' && peat_re(guess))
        return(true);
        i+=1;
    }
    return false;
}

int lost_j(char *guess1, char *guess2){
    int lost = 0;
    for(int s=0; guess1[s] != '\0'; s+=1){
        if(sidein(guess1, guess2[s]) && guess1[s] != guess2[s])
            lost+=1;
    }
    return lost;
}

 int main(){
     char *secret = malloc(4);
     char *input = malloc(16);
     int num_raunds = 10;
     int round = 0;
     secret = inp_code();
     printf("Will you find the secret code?\n");
     printf("%s -\n", secret);
     while(round < num_raunds){
         printf("- - -\n Round %d\n >", round);

         scanf("%s", input);
         if(wrong_get(input)){
             printf("wrong input !\n");
             continue;
         }
         int gp = good_p(secret, input);
         int lp = lost_j(secret, input);
         if(gp == 4){
             printf("Congratz! You did it\n");
             break;
         }else{
             printf("Well placed pieces: %d\n", gp);
             printf("Misplaced pieces: %d\n", lp);
         }
         round++;
     }
    return 0;
 }