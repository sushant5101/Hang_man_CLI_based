//===================================================including required libaries==========================
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
// #include <windows.h>

//==================================================defining functions=======================================

void EASY_LEVEL();

//==================================================adding some global variables=============================

int iLength_of_random_selected_word = 0;
char cUsed_letter[10];

//=================================================creating structure to hold details for repetative task====

struct DUPLICATE_LETTER
{
    char cCharacter;
    int iCount;
};
struct DUPLICATE_LETTER data[10];

//================================================begining of the main function==============================

int main()
{

    int iLevel_index = 0;

    printf("Welcome to Hangman!\n");

//================================================logic for getting the correct level index==================

    while (1)
    {
        printf("Choose a proper index according to the following list:\n");
        printf("1. Easy\n2.Medium\n3.Hard\n");
        scanf("%d", &iLevel_index);

        if (iLevel_index > 3 || iLevel_index < 1)
        {
            // system("cls");
            printf("Invalid index. Please try again.\n");
            continue;
        }
        else
        {
            // system("cls");
            printf("finally some worthy opponent\n");

//============================================calling the apropriate function according to the user input====

            switch (iLevel_index)
            {
            case 1:
                EASY_LEVEL();
                break;

            case 2:
                // MEDIUM_LEVEL();
                break;

            case 3:
                // HARD_LEVEL();
                break;

            default:
                break;
            }
            break;
        }
    }

//=====================================================for now just ending the main function=================

    return 0;
}

//======================================declaring function to handel easy level==============================

void EASY_LEVEL()
{
    srand(time(0));
    int iRand_index = rand() % 10; // (rand() % max - min + 1) + min for random array index each time

    bool bIf_matched = false;

    char cUser_guessed_letter[2]; //--to store the user current entred letter---

    const char *cEasy_word[] = { //---words to choose from in easy level
        "apple",
        "chair",
        "happy",
        "house",
        "water",
        "light",
        "music",
        "pizza",
        "river",
        "tiger"};

    printf("%s\n", cEasy_word[iRand_index]); //

    iLength_of_random_selected_word = strlen(cEasy_word[iRand_index]);

    while (1)
    {
        printf("Your word is of 5 letter\n");
        scanf(" %c", &cUser_guessed_letter[0]);

        for (int i = 0; i < 10; i++)
        {
            if (cEasy_word[iRand_index][i] == cUser_guessed_letter[0])
            {
                printf("You have allready guessed the letter : %c\n", cUser_guessed_letter[0]);
                continue;
            }
            else
            {
                cUsed_letter[i] = cUser_guessed_letter[0];
            }
            break;
        }
    }

    for (int i = 0; i < iLength_of_random_selected_word; i++)
    {
        if (strchr(cEasy_word[iRand_index], cUser_guessed_letter[0]))
        {
            printf("Matched !!\n");
            bIf_matched = true;
            for (int j = 0; j < 10; j++)
            {
                if (data[j].cCharacter == cEasy_word[iRand_index][i])
                {
                    data[j].iCount++;
                }
                else
                {
                    data[j].cCharacter = cEasy_word[iRand_index][i];
                    data[j].iCount++;
                }
            }
        }
        else
        {
            printf("did not\n");
        }
    }
}

//