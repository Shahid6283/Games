#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Game ----> Snake,Water,Gun

// s for snake 
// w for water 
// g for gun

// How you can play this game ---->
// if you choose snake and the computer also choose snake then the game draw 
// if you choose water and the computer also choose water then the game draw 
// if you choose gun and the computer also choose gun then the game draw 
// if you choose gun and the computer choose water then you lose 
// if you choose water and the computer choose gun then you win
// if you choose snake and the computer choose gun then you lose
// if you choose gun and the computer choose snake then you win
// if you choose snake and the computer choose water then you win
// if you choose water and the computer choose snake then you lose

// 1 for win , -1 for lose , 0 for draw
int swg(char you,char comp){
    // Condition for Draw 
    // ss
    // ww
    // gg
    if(you==comp){
        return 0;
    }

    // Condition for non-draw
    /* sw
    gs
    wg */

    if(you=='s' && comp=='w'){
        return 1;
    }
    else if(you=='w' && comp=='s'){
        return -1;
    }

    if(you=='g' && comp=='s'){
        return 1;
    }
    else if(you=='s' && comp=='g'){
        return -1;
    }

    if(you=='w' && comp=='g'){
        return 1;
    }
    else if(you=='g' && comp=='w'){
        return -1;
    }
}

int main()
{
    char you,comp;
    int number;

    // This will generate the Random Number 
    srand(time(0));
    number = rand()%100+1;

    if(number<33){
        comp = 'g';
    }
    else if(number>33 && number<66){
        comp = 's';
    }
    else if(number>66){
        comp = 'w';
    }


    printf("Enter 'g' for Gun 's' for Snake and 'w' for Water : ");     // Case Sensitive
    scanf("%c",&you);

    int result = swg(you,comp);

    if(result==0){
        printf("\nGame Draw!\n");
    }
    else if(result==1){
        printf("\nYou Win!\n");
    }
    if(result==-1){
        printf("\nYou Lose!\n");
    }

    printf("\nYou choose '%c' and Computer choose '%c'\n\n",you,comp);

    return 0;
}
