#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <ctype.h>
#include <unistd.h>
#include <string.h>

// including necessary libaries

int rand_word_picker_and_checker(int);
void HANG_MAN_MANAGER(int, int);
int EASY_LEVEL();
// int REMAINING_GUESSES(char, int);

// declaring functions

int iEntry_count = 0; // creating a global variable for counting the times of entries in  a function

int main()
{
    // srand(time(0));
    int iLevel_difficulty = 1;

    system("cls");

    // printf("%d\n", iWord_index);
    // printf("     |--------\n     O\t     |\n    /|\\\t     |\n    / \\\t     |\n\t     |\n\t  ------");

    printf("\nEnter the coresponding number to manage the level difficulty \n1 --> Easy\n2 --> Medium\n3 --> Hard \n :");
    scanf("%d", &iLevel_difficulty);

    // while (iLevel_difficulty < 1 || iLevel_difficulty > 3)
    // {
    //     printf("\nEnter the coresponding number to manage the level difficulty \n1 --> Easy\n2 --> Medium\n3 --> Hard \n :");
    //     scanf("%d", &iLevel_difficulty);
    //     if (iLevel_difficulty > 3 || iLevel_difficulty < 1)
    //     {
    //         printf("\nEntre proper level index\n");
    //     }
    // } // looping to get the correct level difficulty index

    rand_word_picker_and_checker(iLevel_difficulty); // calling function to pick a random words based on the difficulty selected
    return 0;
}

int rand_word_picker_and_checker(int iLevel_difficulty) // defining random word picker function
{

    printf("%d\n", iLevel_difficulty);
    switch (iLevel_difficulty)
    {
    case 1:
        EASY_LEVEL();
        break;

    case 2:
        printf("you have choosed medium level difficulty");
        break;

    case 3:
        printf("You have choosed hard level difficulty");
        break;

    default:
        break;
    } // using switch to select level based on the given user input
    return 0;
}

// int REMAINING_GUESSES(char a, int c)
// {
// }

void HANG_MAN_MANAGER(int iIncorrect, int iPrevious_incorrect_count) // defining manager function to act on the corect and incorrect inputs
{

    // printf("  O\n/ | \\\n  |\n / \\");
    // printf("     |--------\n     O\t     |\n    /|\\\t     |\n    / \\\t     |\n\t     |\n\t  ------"); // design

    if (iIncorrect > 6)
    {
        printf("You finished your remaining guesses\n");
        sleep(2);
        main();
    }
    // if (iPrevious_incorrect_count == iIncorrect)
    // {
    //     iIncorrect = 0;
    // }
    switch (iIncorrect)
    {
    case 0:
        system("cls");
        // switch (iPrevious_incorrect_count)
        // {
        // case 1:
        //     printf("     |--------\n     O\t     |\n\t     |\n\t     |\n\t     |\n\t  ------"); // design
        //     break;

        // case 2:
        //     printf("     |--------\n     O\t     |\n     |\t     |\n\t     |\n\t     |\n\t  ------"); // design
        //     break;

        // case 3:
        //     printf("     |--------\n     O\t     |\n    /|\t     |\n\t     |\n\t     |\n\t  ------"); // design
        //     break;

        // case 4:
        //     printf("     |--------\n     O\t     |\n    /|\\\t     |\n\t     |\n\t     |\n\t  ------"); // design
        //     break;

        // case 5:
        //     printf("     |--------\n     O\t     |\n    /|\\\t     |\n    /\t     |\n\t     |\n\t  ------"); // design
        //     break;

        // default:
        //     break;
        // }
        printf("\ncorrect\n");
        break;

    case 1:
        system("cls");
        printf("     |--------\n     O\t     |\n\t     |\n\t     |\n\t     |\n\t  ------"); // design
        break;

    case 2:
        system("cls");
        printf("     |--------\n     O\t     |\n     |\t     |\n\t     |\n\t     |\n\t  ------"); // design
        break;

    case 3:
        system("cls");
        printf("     |--------\n     O\t     |\n    /|\t     |\n\t     |\n\t     |\n\t  ------"); // design
        break;

    case 4:
        system("cls");
        printf("     |--------\n     O\t     |\n    /|\\\t     |\n\t     |\n\t     |\n\t  ------"); // design
        break;

    case 5:
        system("cls");
        printf("     |--------\n     O\t     |\n    /|\\\t     |\n    /\t     |\n\t     |\n\t  ------"); // design
        break;

    case 6:
        system("cls");
        printf("     |--------\n     O\t     |\n    /|\\\t     |\n    / \\\t     |\n\t     |\n\t  ------"); // design
        break;

    default:
        printf("\nhello\n");
        break;
    }
}

int EASY_LEVEL() // defining function for easy level
{
    int iWord_index = 0,
        iIncorrect = 0,
        iTemp_count = 0,
        iRemaining_guesses = 8,
        iPrevious_incorrect_count = 0,
        iChoosed_word_length = 0,
        iLetter_matched_count = 0,
        iPast_uses_letter_length = 1;
    char cUser_guessed_letter,
        cIndivisual[10],
        cPast_used_letter[iPast_uses_letter_length];

    system("cls");

    printf("\n<========= you are in easy level ========>\n");

    iWord_index = (rand() % 10 - 0 + 1) + 0;

    const char *cEasy_words[] = {"Apple", "Chair", "Happy", "House", "Water", "Light", "Music", "Pizza", "River", "Tiger"}; // words for easy level

    strcpy(cIndivisual, cEasy_words[iWord_index]);

    iChoosed_word_length = strlen(cEasy_words[iWord_index]);
    printf("\nyour word is of %d letter better be accurate \n", iChoosed_word_length);

    // srand(time(0));

    // printf("     |--------\n\t     |\n    \t     |\n    \t     |\n\t     |\n\t  ------\n"); // design

    while (iRemaining_guesses != 0)
    {
        printf("\nYour word is %s\n", cEasy_words[iWord_index]);
        printf("remaining guesses %d\n", iRemaining_guesses);

        scanf("%c", &cUser_guessed_letter);

        // -----------------------------------_Printing the choosed random word for testing-----------------------------

        // for (int i = 0; i < iChoosed_word_length; i++)
        // {
        //     printf("%c\n", cIndivisual[i]);
        // }

        // ------------------------------------checking if the letter has been entred previously or not -----------------

        for (int i = 0, l = iPast_uses_letter_length + 1; i < l; i++)
        {
            scanf("%c",&cUser_guessed_letter);

            // while (isalpha(cUser_guessed_letter) == 0) // checking if the entred number is a alphabet or not
            // {
            //     printf("enter a valid alpabet:\n");
            //     scanf("%c", &cUser_guessed_letter);
            // }

            while (cUser_guessed_letter == cPast_used_letter[i]) // checking if the letter has been entered previously or not
            {
                printf("you have alerady guessed the letter %c guess \n", cUser_guessed_letter);
                scanf("%c", &cUser_guessed_letter);
            }
        }

        cPast_used_letter[iPast_uses_letter_length] = cUser_guessed_letter;
        iPast_uses_letter_length++;

        // for (int i = 0, len = strlen(cPast_used_letter); i < len; i++)
        // {
        //     printf("Your previoulsy entred characters : %c\n", cPast_used_letter[i]);
        // }
        // sleep(3);

        iTemp_count = 0;
        for (int i = 0; i < iChoosed_word_length; i++)
        {
            cIndivisual[0] = tolower(cIndivisual[0]);
            cUser_guessed_letter = tolower(cUser_guessed_letter);

            if (cUser_guessed_letter != cIndivisual[i])
            {
                iTemp_count++;
            }
            else
            {
                HANG_MAN_MANAGER(iIncorrect, iPrevious_incorrect_count);
                iLetter_matched_count++;
            }
        }

        if (iLetter_matched_count != iChoosed_word_length && iTemp_count == iChoosed_word_length)
        {
            iIncorrect++;
            HANG_MAN_MANAGER(iIncorrect, iPrevious_incorrect_count);
            iPrevious_incorrect_count = iIncorrect;
            iRemaining_guesses--;
        }
        else if (iLetter_matched_count == iChoosed_word_length)
        {
            printf("Congraulation you found the word \n");
            printf("The word was %s", cIndivisual);
            iRemaining_guesses = 0;
        }
        // printf("\nRemaining guesses : %d\n", REMAINING_GUESSES());
    }
    printf("You finished your remaining guesses\n");
    return 0;
}
