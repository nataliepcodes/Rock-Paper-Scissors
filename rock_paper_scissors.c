#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char generateComputerOption(char str[])
{
    srand(time(NULL));

    int randomIndex = rand() % 3;

    if (randomIndex == 0)
        {
            strcpy(str, "rock");
        }
    if (randomIndex == 1)
        {
            strcpy(str, "paper");
        }
    if (randomIndex == 2)
        {
            strcpy(str, "scissors");
        }

        return *str;
}

void compareOptions(char str1[], char str2[])
{
    if (strcmp(str1, str2) == 0)
    {
        printf("It's a draw! Play again!\n");
    }
    else if (strcmp(str1, "rock") == 0 && strcmp(str2, "scissors") == 0)
    {
        printf("You lost! Try again! :)\n");
    } 
    else if (strcmp(str1, "scissors") == 0 && strcmp(str2, "paper") == 0)
    {
        printf("You lost! Try again! :)\n");
    } 
    else if (strcmp(str1, "paper") == 0 && strcmp(str2, "rock") == 0)
    {
        printf("You lost! Try again! :)\n");
    }
    else
    {
        printf("You Won! :)\n");
    }
}

int main()
{
    printf("\n**************************************************\n");
    printf("************** ROCK PAPER SCISSORS ***************\n");
    printf("**************************************************\n\n");
    printf("RULES:\n");
    printf("Rock destroys scissors.");
    printf(" Scissors cut paper.\n");
    printf("Paper covers rock.\n");
    printf("If there's a tie, then the game ends in a draw.\n\n");
    printf("**************************************************\n");

    //initialize a string for computer's option
    char computerOption[9];

    //call a function to generate the random string choice out of 3 choices
    generateComputerOption(computerOption);
    
    //initialize a string for user's input
    char usersInput[9];
    //printf("**************************************************\n");
    printf("\nEnter your choice (rock, paper or scissors): \n");
    scanf("%s", usersInput);
    
    //loop through user's input
    for (int i = 0; usersInput[i] != '\0'; i++)
    {
        //check if input has been entered in capital letters, if so, change it to lower case
        //isupper returns 0 if the condition is false / not uppercase
        //isupper returns x > 0 if the condition is true / char is uppercase
        if (isupper(usersInput[i]) > 0)
        {
            usersInput[i] = tolower(usersInput[i]);
        }
    }
    printf("\n**************************************************\n\n");
    compareOptions(computerOption, usersInput);
    printf("\n**************************************************\n\n");

    return 0;
}