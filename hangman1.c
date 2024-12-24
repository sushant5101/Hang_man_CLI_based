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
void MEDIUM_LEVEL();
void HARD_LEVEL();

//==================================================adding some global variables=============================

int iLength_of_random_selected_word = 0,
    iIncorrect_count = 0,
    iCorrect_count = 0,
    iRemaining_guesses = 0;

char cUsed_letter[20],
    cUser_guessed_letter; //--to store the user current entred letter---

bool bIf_matched = false,
     bIf_used = false;

//=================================================creating structure to hold details for repetative task====

// struct DUPLICATE_LETTER
// {
//     char cCharacter;
//     int iCount;
// };
// struct DUPLICATE_LETTER data[10];

//================================================begining of the main function==============================

int main()
{

    int iLevel_index = 0;

    printf("Welcome to Hangman!\n");
    printf("Choose a proper index according to the following list:\n");
    printf("1.Easy\n2.Medium\n3.Hard\n");
    scanf("%d", &iLevel_index);

    //============================================calling the apropriate function according to the user input====

    switch (iLevel_index)
    {
    case 1:
        EASY_LEVEL();
        break;

    case 2:
        MEDIUM_LEVEL();
        break;

    case 3:
        HARD_LEVEL();
        break;

    default:
        return 1;
        break;
    }

    //=====================================================for now just ending the main function=================

    return 0;
}

//======================================declaring function to handel easy level==============================

void EASY_LEVEL()
{
    iRemaining_guesses = 8;
    srand(time(0));
    int iRand_index = rand() % 10; // (rand() % max - min + 1) + min, for random array index each time

    const char *cEasy_word[] = {//---words to choose from in easy level
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

    // printf("%s\n", cEasy_word[iRand_index]); // just checking

    iLength_of_random_selected_word = strlen(cEasy_word[iRand_index]);

    //================================================Handelling player correct guesses and incorect ================

    while (iRemaining_guesses > 0)
    {
        iIncorrect_count = 0;
        printf("You have %d remaining guesses\n", iRemaining_guesses);
        printf("The word has total of %d letters\n", iLength_of_random_selected_word);
        scanf(" %c", &cUser_guessed_letter);

        for (int i = 0; i < iLength_of_random_selected_word; i++)
        {
            if (cUsed_letter[i] != cUser_guessed_letter && cUser_guessed_letter == cEasy_word[iRand_index][i])
            {
                cUsed_letter[i] = cUser_guessed_letter;
                printf("You found a matching letter\n");
                bIf_matched = true;
                iCorrect_count++;
            }
            else if (cUser_guessed_letter == cUsed_letter[i])
            {
                printf("you allready guessed the word: %c\n", cUser_guessed_letter);
                bIf_used = true;
                break;
            }
            else
            {
                iIncorrect_count++;
            }
        }

        if (iIncorrect_count == iLength_of_random_selected_word)
        {
            printf("%c was not the letter in the word \n", cUser_guessed_letter);
            printf("You lost your one guess\n");
            cUsed_letter[iIncorrect_count] = cUser_guessed_letter;
            iRemaining_guesses--;
        }
        else if (iCorrect_count == iLength_of_random_selected_word)
        {
            printf("congratulation you have found word the word was %s\n", cEasy_word[iRand_index]);
            iRemaining_guesses = 0;
        }
        else if (iRemaining_guesses == 0)
        {
            printf("You have lost all the remaining guess\n");
        }
    }
    //========================================================================================================
}

void MEDIUM_LEVEL()
{
    iRemaining_guesses = 10;
    printf("This is medium level of the game:\n");
    srand(time(0));
    int iRand_index = rand() % 10;

    const char *cMedium_words[] = {//---words to choose from in Medium level
                                   "bicycle",
                                   "compass",
                                   "library",
                                   "mountain",
                                   "mystery",
                                   "popcorn",
                                   "rainbow"
                                   "scissors",
                                   "volcano",
                                   "whistle"};

    iLength_of_random_selected_word = strlen(cMedium_words[iRand_index]);

    //================================================Handelling player correct guesses and incorect ================

    while (iRemaining_guesses > 0)
    {
        iIncorrect_count = 0;
        printf("You have %d remaining guesses\n", iRemaining_guesses);
        printf("The word has total of %d letters\n", iLength_of_random_selected_word);
        scanf(" %c", &cUser_guessed_letter);

        for (int i = 0; i < iLength_of_random_selected_word; i++)
        {
            if (cUsed_letter[i] != cUser_guessed_letter && cUser_guessed_letter == cMedium_words[iRand_index][i])
            {
                cUsed_letter[i] = cUser_guessed_letter;
                printf("You found a matching letter\n");
                bIf_matched = true;
                iCorrect_count++;
            }
            else if (cUser_guessed_letter == cUsed_letter[i])
            {
                printf("you allready guessed the word: %c\n", cUser_guessed_letter);
                bIf_used = true;
                break;
            }
            else
            {
                iIncorrect_count++;
            }
        }

        if (iIncorrect_count == iLength_of_random_selected_word)
        {
            printf("%c was not the letter in the word \n", cUser_guessed_letter);
            printf("You lost your one guess\n");
            cUsed_letter[iIncorrect_count] = cUser_guessed_letter;
            iRemaining_guesses--;
        }
        else if (iCorrect_count == iLength_of_random_selected_word)
        {
            printf("congratulation you have found word the word was %s\n", cMedium_words[iRand_index]);
            iRemaining_guesses = 0;
        }
        else if (iRemaining_guesses == 0)
        {
            printf("You have lost all the remaining guess\n");
        }
    }
}

void HARD_LEVEL()
{
    printf("You are in hard level, Remember the words in the hard level might be the words that you have not heard of \n");
    srand(time(0));
    int iRand_index = rand() % 10;
    iRemaining_guesses = 20;

    //---words to choose from in Hard level
    const char *cHard_word[] = {
        "Ostentatious",
        "Nebulous",
        "Esoteric",
        "Surreptitious",
        "Languorous",
        "Quixotic",
        "Ebullient",
        "Lugubrious",
        "Obfuscate",
        "Sesquipedalian",
    };

    iLength_of_random_selected_word = strlen(cHard_word[iRand_index]);

    while (iRemaining_guesses > 0)
    {
        iIncorrect_count = 0;
        printf("You have %d remaining guesses\n", iRemaining_guesses);
        printf("The word has total of %d letters\n", iLength_of_random_selected_word);
        scanf(" %c", &cUser_guessed_letter);

        for (int i = 0; i < iLength_of_random_selected_word; i++)
        {
            if (cUsed_letter[i] != cUser_guessed_letter && cUser_guessed_letter == cHard_word[iRand_index][i])
            {
                cUsed_letter[i] = cUser_guessed_letter;
                printf("You found a matching letter\n");
                bIf_matched = true;
                iCorrect_count++;
            }
            else if (cUser_guessed_letter == cUsed_letter[i])
            {
                printf("you allready guessed the word: %c\n", cUser_guessed_letter);
                bIf_used = true;
                break;
            }
            else
            {
                iIncorrect_count++;
            }
        }

        if (iIncorrect_count == iLength_of_random_selected_word)
        {
            printf("%c was not the letter in the word \n", cUser_guessed_letter);
            printf("You lost your one guess\n");
            cUsed_letter[iIncorrect_count] = cUser_guessed_letter;
            iRemaining_guesses--;
        }
        else if (iCorrect_count == iLength_of_random_selected_word)
        {
            printf("congratulation you have found word the word was %s\n", cHard_word[iRand_index]);
            iRemaining_guesses = 0;
        }
        else if (iRemaining_guesses == 0)
        {
            printf("You have lost all the remaining guess\n");
        }
    }
}
