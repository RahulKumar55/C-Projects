
/*
*****************************************************************************
                          Workshop - #7 (P2)
Full Name  :
Student ID#:
Email      :
Section    :
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define maxlength 70
#define minlength 10
#define divisor 5
int main(void)
{
    int maxlives = 10, maxmoves = 0, i = 0, move = 0;
    int lastvisit[maxlength] = { 0 }, symbolprinted = 0;
    struct playerinfo
    {
        int lives;
        char symbol;
        int foundtreasures;
        int history[maxlength];
    };
    struct playerinfo player = { 0,'a',0,{0} };

    struct gameinfo
    {
        int nummoves;
        int pathlength;
        int bombs[maxlength];
        int treasure[maxlength];
    };
    struct gameinfo game = { 0,0,{0},{0} };
    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n\n");
    printf("PLAYER Configuration\n");
    printf("--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &player.symbol);

    do
    {
        printf("Set the number of lives: ");
        scanf("%d", &player.lives);
        if (player.lives < 1 || player.lives > maxlives)
        {
            printf("     Must be between 1 and %d!\n", maxlives);
        }
    } while (player.lives < 1 || player.lives > maxlives);
    printf("Player configuration set-up is complete\n\n");

    printf("GAME Configuration\n");
    printf("------------------\n");
    do
    {
        printf("Set the path length (a multiple of %d between %d-%d): ", divisor, minlength, maxlength);
        scanf("%d", &game.pathlength);
        if ((game.pathlength < minlength || game.pathlength > maxlength) || (game.pathlength % divisor != 0))
        {
            printf("     Must be a multiple of %d and between %d-%d!!!\n", divisor, minlength, maxlength);
        }
    } while ((game.pathlength < minlength || game.pathlength > maxlength) || (game.pathlength % divisor != 0));

    maxmoves = game.pathlength * 0.75;

    do
    {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &game.nummoves);
        if (game.nummoves < player.lives || game.nummoves > maxmoves)
        {
            printf("    Value must be between %d and %d\n", player.lives, maxmoves);
        }
    } while (game.nummoves < player.lives || game.nummoves > maxmoves);



    printf("\nBOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of %d where a value\nof 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", divisor, game.pathlength);
    for (i = 0; i < game.pathlength; i += 5)
    {
        printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
        scanf("%d%d%d%d%d", &game.bombs[i], &game.bombs[i + 1], &game.bombs[i + 2], &game.bombs[i + 3], &game.bombs[i + 4]);
    }
    printf("BOMB placement set\n");



    printf("\nTREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of %d where a value\nof 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", divisor, game.pathlength);
    for (i = 0; i < game.pathlength; i += 5)
    {
        printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
        scanf("%d%d%d%d%d", &game.treasure[i], &game.treasure[i + 1], &game.treasure[i + 2], &game.treasure[i + 3], &game.treasure[i + 4]);
    }
    printf("TREASURE placement set\n\n");
    printf("GAME configuration set-up is complete...\n\n");

    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");
    printf("Player:\n");
    printf("   Symbol     : %c\n", player.symbol);
    printf("   Lives      : %d\n", player.lives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n");
    printf("\nGame:\n");
    printf("   Path Length: %d\n", game.pathlength);
    printf("   Bombs      : ");
    for (i = 0; i < game.pathlength; i++)
    {
        printf("%d", game.bombs[i]);
    }
    printf("\n   Treasure   : ");
    for (i = 0; i < game.pathlength; i++)
    {
        printf("%d", game.treasure[i]);
    }
    printf("\n\n====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n\n");

    do
    {
        if (move != 0)
        {
            printf(" ");
            for (i = 0; i < game.pathlength; i++)
            {
                if (lastvisit[i] == 1)
                {
                    printf(" %c", player.symbol);
                    symbolprinted = 1;
                }
                else
                {
                    if (symbolprinted == 0)
                    {
                        printf(" ");
                    }
                }
            }
            printf("\n");
        }

        printf("  ");
        for (i = 0; i < game.pathlength; i++)
        {
            if (player.history[i] == 0)
            {
                printf("-");
            }
            else if ((game.bombs[i] == 1) && (game.treasure[i] == 1))
            {
                printf("&");
            }
            else if (game.bombs[i] == 1)
            {
                printf("!");
            }
            else if (game.treasure[i] == 1)
            {
                printf("$");
            }
            else
            {
                printf(".");
            }
        }
        printf("\n  ");


        for (i = 1; i <= game.pathlength; i++)
        {
            if (i % 10 == 0)
            {
                printf("%d", i / 10);
            }
            else
            {
                printf("|");
            }
        }
        printf("\n  ");


        for (i = 1; i <= game.pathlength; i++)
        {
            printf("%d", i % 10);
        }
        printf("\n");

        printf("+---------------------------------------------------+\n");
        printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", player.lives, player.foundtreasures, game.nummoves);
        printf("+---------------------------------------------------+\n");

        do
        {
            printf("Next Move [1-%d]: ", game.pathlength);
            scanf("%d", &move);
            if (move < 1 || move > game.pathlength)
            {
                printf("  Out of Range!!!\n");
            }
        } while (move < 1 || move > game.pathlength);
        printf("\n");
       
        if (player.history[move - 1] == 1)
        {
            printf("===============> Dope! You've been here before!\n");
        }
        else if ((game.bombs[move - 1] == 1) && (game.treasure[move - 1] == 1))
        {
            printf("===============> [&] !!! BOOOOOM !!! [&]\n");
            printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n");
            player.lives--;
            player.foundtreasures++;
            game.nummoves--;
        }
        else if (game.bombs[move - 1] == 1)
        {
            printf("===============> [!] !!! BOOOOOM !!! [!]\n");
            player.lives--;
            game.nummoves--;
        }
        else if (game.treasure[move - 1] == 1)
        {
            printf("===============> [$] $$$ Found Treasure! $$$ [$]\n");
            player.foundtreasures++;
            game.nummoves--;
        }
        else if ((game.bombs[move - 1] == 0) && (game.treasure[move - 1] == 0))
        {
            printf("===============> [.] ...Nothing found here... [.]\n");
            game.nummoves--;
        }
        printf("\n");

        player.history[move - 1] = 1;

        for (i = 0; i < game.pathlength;i++)
        {
            lastvisit[i] = 0;
        } 

        lastvisit[move - 1] = 1;
        symbolprinted = 0;

        if (player.lives == 0) printf("No more LIVES remaining!\n\n");
        else if (game.nummoves == 0) printf("No more moves\n");
    } while (player.lives > 0 && game.nummoves > 0);


    printf(" ");
    for (i = 0; i < game.pathlength; i++)
    {
        if (lastvisit[i] == 1)
        {
            printf(" %c", player.symbol);
            symbolprinted = 1;
        }
        else
        {
            if (symbolprinted == 0)
            {
                printf(" ");
            }
        }
    }
    printf("\n");
    printf("  ");

    for (i = 0; i < game.pathlength; i++)
    {
        if (player.history[i] == 0)
        {
            printf("-");
        }
        else if ((game.bombs[i] == 1) && (game.treasure[i] == 1))
        {
            printf("&");
        }
        else if (game.bombs[i] == 1)
        {
            printf("!");
        }
        else if (game.treasure[i] == 1)
        {
            printf("$");
        }
        else
        {
            printf(".");
        }
    }
    printf("\n  ");


    for (i = 1; i <= game.pathlength; i++)
    {
        if (i % 10 == 0)
        {
            printf("%d", i / 10);
        }
        else
        {
            printf("|");
        }
    }
    printf("\n  ");


    for (i = 1; i <= game.pathlength; i++)
    {
        printf("%d", i % 10);
    }
    printf("\n");

    printf("+---------------------------------------------------+\n");
    printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", player.lives, player.foundtreasures, game.nummoves);
    printf("+---------------------------------------------------+\n");
   
    printf("\n##################\n");
    printf("#   Game over!   #\n");
    printf("##################\n");
    printf("\nYou should play again and try to beat your score!\n");

    return 0;
}