// The best C programe ever made by me

/*

@author : Indranil Sen
@purpose : Hand Cricket(Mobile Version) development
@lauch date : 25-10-2022
@first update : 05-11-2022
@version : 2.0

/*

Upcoming updates :

1. Difficult : Over System
2. Easy : Commentry for bounderies and 50, 100, 150, 200 runs by the team
3. Wrong input handling (Done on 05/11/2022)
4. Teams and player system
5. Required run rate, Strike rate functionality
6. Batsman celebration for 50, 100 runs
7. Batsman, bowler list wise performance system after each over and final result display after full match

*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int random_num(int n, int m)
{
    srand(time(NULL));
    return rand() % (m - n + 1) + n;
}

void TOSS(int n)
{
    if (n == 1)
    {
        printf("Head");
    }
    else
    {
        printf("Tail");
    }
}

int wicket, player_toss_choice, computer_toss_choice, toss_decision, player_bat_bowl, computer_bat_bowl, player_run, computer_run, player_wicket, computer_wicket, player_wicket_fall, computer_wicket_fall, sum_player_run = 0, sum_computer_run = 0;

void player_batting_and_computer_bowling()
{
    printf("\n\n\n....Your batting....\n");
    while (player_wicket != 0)
    {
        // Me batting && Computer bowling
        printf("\n\nEnter run : ");
        scanf("%d", &player_run);
        if (player_run > 6 || player_run < 1)
        {
            printf("\nOops! Invalid input! Please input correctly\n\n.........GAME OVER..........\n");
            break;
        }
        computer_run = random_num(1, 6);
        printf("\n\nYou : %d run", player_run);
        printf("\nComputer : %d run\n", computer_run);
        if (player_run == computer_run)
        {
            printf("\nOut!");
            player_wicket--;
            player_wicket_fall++;
            printf("\n\nYour Remaining wickets : %d\n", player_wicket);
            printf("\n\nYour Scoreboard : %d/%d", sum_player_run, player_wicket_fall);
        }
        else
        {
            printf("\n\n%d run for you", player_run);
            sum_player_run += player_run;
            printf("\n\nTotal : %d runs", sum_player_run);
        }
    }
    if (player_run > 0 && player_run < 7)
    {
        printf("\n\nYour Final score : %d/%d", sum_player_run, player_wicket_fall);
    }
}

void player_bowling_and_computer_batting()
{
    printf("\n\n\n....Computer's batting....\n");
    while (computer_wicket != 0)
    {
        // Me bowling && computer batting
        printf("\n\nEnter run : ");
        scanf("%d", &player_run);
        if (player_run > 6 || player_run < 1)
        {
            printf("\nOops! Invalid input! Please input correctly\n\n.........GAME OVER..........\n");
            break;
        }
        computer_run = random_num(1, 6);
        printf("\n\nYou : %d run", player_run);
        printf("\nComputer : %d run", computer_run);
        if (player_run == computer_run)
        {
            printf("\n\nOut!");
            computer_wicket--;
            computer_wicket_fall++;
            printf("\n\nComputer's Remaining wickets : %d\n", computer_wicket);
            printf("\n\nComputer's Scoreboard : %d/%d", sum_computer_run, computer_wicket_fall);
        }
        else
        {
            printf("\n\n%d run for computer", computer_run);
            sum_computer_run += computer_run;
            printf("\n\nTotal : %d runs", sum_computer_run);
        }
    }
    if (player_run > 0 && player_run < 7)
    {
        printf("\n\nComputer's Final score : %d/%d", sum_computer_run, computer_wicket_fall);
    }
}

int main()
{
    printf("\n..........Welcome to Hand Cricket..............\n");
    printf("..............(Mobile Version)..................");
    printf("\n\n\n........Developed by @Indranil Sen..........");
    printf("\n\n\nEnter the no of wickets you want to play : ");
    scanf("%d", &wicket);
    printf("\n\nOkkkk, let's move to the toss round");
    printf("\n\nEnter your choice\nEnter 1 for Head\nEnter 2 for tail\n--> ");
    scanf("%d", &player_toss_choice);
    if (player_toss_choice == 1)
    {
        computer_toss_choice == 2;
    }
    else if (player_toss_choice == 2)
    {
        computer_toss_choice == 1;
    }
    else
    {
        printf("\nOops! Invalid input! Please input correctly\n\n.........GAME OVER..........\n");
        goto label;
    }
    printf("\n\nYou choose : ");
    TOSS(player_toss_choice);
    toss_decision = random_num(1, 2);
    if (player_toss_choice == toss_decision)
    {
        printf("\n\nIt's ");
        TOSS(toss_decision);
        printf("\n\nYou win the toss!");
        printf("\n\n\nWhat do you want to select\nEnter 1 for Bat\nEnter 2 for Bowl\n--> ");
        scanf("%d", &player_bat_bowl);
        if (player_bat_bowl == 1)
        {
            printf("\n\nYou have selected bat first!");
        }
        else if (player_bat_bowl == 2)
        {
            printf("\n\nYou have selected bowl first!");
        }
        else
        {
            printf("\nOops! Invalid input! Please input correctly\n\n.........GAME OVER..........\n");
            goto label;
        }
    }
    else
    {
        printf("\n\nIt's ");
        TOSS(toss_decision);
        printf("\n\nComputer wins the toss!");
        computer_bat_bowl = random_num(1, 2);
        if (computer_bat_bowl == 1)
        {
            printf("\n\nComputer selected bat first");
        }
        else
        {
            printf("\n\nComputer selected bowl first");
        }
    }
    printf("\n\n\nAllright! The match is going to be start");

    player_wicket = wicket;
    computer_wicket = wicket;
    if (player_bat_bowl == 1 || computer_bat_bowl == 2)
    {
        player_batting_and_computer_bowling();
        if (player_run > 6 || player_run < 1)
        {
            goto label;
        }
        printf("\n\n\n....Computer's batting....\n");

        while (computer_wicket != 0)
        {
            // Me bowling && computer batting
            printf("\n\nEnter run : ");
            scanf("%d", &player_run);
            if (player_run > 6 || player_run < 1)
            {
                printf("\nOops! Invalid input! Please input correctly\n\n.........GAME OVER..........\n");
                break;
                goto label;
            }
            computer_run = random_num(1, 6);
            printf("\n\nYou : %d run", player_run);
            printf("\nComputer : %d run", computer_run);
            if (player_run == computer_run)
            {
                printf("\n\nOut!");
                computer_wicket--;
                computer_wicket_fall++;
                printf("\n\nComputer's Remaining wickets : %d\n", computer_wicket);
                printf("\n\nComputer's Scoreboard : %d/%d", sum_computer_run, computer_wicket_fall);
                if (computer_wicket == 0)
                {
                    printf("\n\n\nYour score : %d", sum_player_run);
                    printf("\nComputer score : %d", sum_computer_run);
                    printf("\n\n\nYou win by %d runs", sum_player_run - sum_computer_run);
                }
            }
            else
            {
                printf("\n\n%d run for computer", computer_run);
                sum_computer_run += computer_run;
                printf("\n\nTotal : %d runs", sum_computer_run);
                if (sum_computer_run > sum_player_run)
                {
                    printf("\n\n\nYour score : %d", sum_player_run);
                    printf("\nComputer score : %d/%d", sum_computer_run, computer_wicket_fall);
                    printf("\n\n\nComputer won by %d wickets", computer_wicket);
                    break;
                }
            }
        }
    }
    else
    {
        player_bowling_and_computer_batting();
        if (player_run > 6 || player_run < 1)
        {
            goto label;
        }
        printf("\n\n\n....Your batting....\n");
        while (player_wicket != 0)
        {
            // Me batting && Computer bowling
            printf("\n\nEnter run : ");
            scanf("%d", &player_run);
            if (player_run > 6 && player_run < 1)
            {
                printf("\nOops! Invalid input! Please input correctly\n\n.........GAME OVER..........\n");
                break;
                goto label;
            }
            computer_run = random_num(1, 6);
            printf("\n\nYou : %d run", player_run);
            printf("\nComputer : %d run", computer_run);
            if (player_run == computer_run)
            {
                printf("\n\nOut!");
                player_wicket--;
                player_wicket_fall++;
                printf("\n\nYour Remaining wickets : %d\n", player_wicket);
                printf("\n\nYour Scoreboard : %d/%d", sum_player_run, player_wicket_fall);
                if (player_wicket == 0)
                {
                    printf("\n\n\nYour score : %d", sum_player_run);
                    printf("\nComputer score : %d", sum_computer_run);
                    printf("\n\n\nComputer win by %d runs", sum_computer_run - sum_player_run);
                }
            }
            else
            {
                printf("\n\n%d run for you", player_run);
                sum_player_run += player_run;
                printf("\n\nTotal : %d runs", sum_player_run);
                if (sum_computer_run < sum_player_run)
                {
                    printf("\n\n\nYour score : %d/%d", sum_player_run, player_wicket_fall);
                    printf("\nComputer score : %d", sum_computer_run);
                    printf("\n\n\nYou won by %d wickets", player_wicket);
                    break;
                }
            }
        }
    }

label:

    return 0;
}