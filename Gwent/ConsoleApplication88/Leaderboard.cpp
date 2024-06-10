#include "LeaderBoard.h"
char LeaderBoardPath[] = "LeaderBoard.txt";
void leaderboardSort(int* leaderboard) {
    int swap = 0;
    // Сортировка пузырьком
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (leaderboard[j] < leaderboard[j + 1]) // Сортируем по возрастанию, а не по убыванию, как в обычном bubble-sort
            {
                swap = leaderboard[j];
                leaderboard[j] = leaderboard[j + 1];
                leaderboard[j + 1] = swap;
            }
        }
    }
}

void leaderboardWrite(int* leaderboard) {
    FILE* leaderboardFile;
    errno_t err;

    err = fopen_s(&leaderboardFile, LeaderBoardPath, "wt");

    if (!err)
    {
        for (int i = 0; i < 5; i++)
        {
            fprintf_s(leaderboardFile, "%d\n", leaderboard[i]);
        }
    }

    fclose(leaderboardFile);
}

void leaderboardRead(int* leaderboard) {
    FILE* leaderboardFile;
    errno_t err;

    err = fopen_s(&leaderboardFile, LeaderBoardPath, "rt");

    if (!err)
    {
        for (int i = 0; i < 5; i++)
        {
            fscanf_s(leaderboardFile, "%d", &leaderboard[i]);
        }
        fclose(leaderboardFile);
    }
    fclose(leaderboardFile);
}

void leaderboardUpdate(int* leaderboard, int score) {
    int updated = 0;

   /* for (int i = 0; i < 5; i++)
    {
        if (leaderboard[i] == 0)
        {
            leaderboard[i] = score;
            updated = 1;
            break;
        }
        else
        {
            if (score >= leaderboard[i])
            {
                leaderboard[4] = score;
                updated = 1;
                break;
            }
        }
    }*/

    leaderboard[4] = leaderboard[3];
    leaderboard[3] = leaderboard[2];
    leaderboard[2] = leaderboard[1];
    leaderboard[1] = leaderboard[0];
    leaderboard[0] = score;
    updated = 1;
   
    
    if (updated)
    {
        //leaderboardSort(leaderboard);
        leaderboardWrite(leaderboard);
    }
}

void leaderboardInit(int* leaderboard) {
    leaderboardRead(leaderboard);
  //  leaderboardSort(leaderboard);
    leaderboardWrite(leaderboard);
}