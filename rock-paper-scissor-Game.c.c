#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int getrandom_num(int n)
{
    //for getting a random number
    srand(time(NULL));
    return rand() % n;
}
int main()
{
    int userchoice, compchoice;
    int userscore = 0, compscore = 0;
    char username[20];
    char choice[][10] = {"Rock", "Paper", "Scissor"};
    printf("\nWELCOME TO ROCK, PAPER & SCISSOR GAME !!!");
    printf("\nEnter your name : ");
    scanf("%s",username);
    for(int i = 0 ; i < 3 ; i++)   // for loop to play game 3 times
    {
        printf("\nIt's your turn, What you want to choose ???");
        printf("\n1.Rock 2.Paper 3.Scissor");
        printf("\nEnter your choice : ");
        scanf("%d",&userchoice);
       if(userchoice < 1 || userchoice > 3)
        {
           printf("Invalid choice, Try again");
        }
        else
        {
           printf("\nyou chose %s",choice[userchoice-1]);
        }
        printf("\nIt's computer's turn");
        compchoice = getrandom_num(3) + 1; //random num (from 0 to 3) + 1
        printf("\ncomp chose %s",choice[compchoice - 1]);
    // 1]r & p - p wins 2]r & s- r wins 3]p & s - s wins
        if((userchoice == 1 && compchoice == 3) || (userchoice == 2 && compchoice == 1) || (userchoice == 3 && compchoice == 2))
        {
            userscore += 1;
        }
        else if(userchoice == compchoice)
        {
            compscore += 1;
            userscore += 1;
        }
        else
        {
            compscore += 1;
        }
    }
    printf("\n");
    printf("\nIt's time for results, Let's have a look on scoreboard:-");
    printf("\nyou won %d times and computer win %d times\n",userscore,compscore);
        if(userscore > compscore)   //compares the scores of user & comp
        {
           printf("\n!!!!___CONGRATULATIONS___!!!! You win the game");
        }
        else if(userscore == compscore)
        {
           printf("\nIt's a draw!!!");
        }
        else
       {
           printf("\nSORRY (^^_^^), Computer wins the game!!!");
       }
    return 0;
}