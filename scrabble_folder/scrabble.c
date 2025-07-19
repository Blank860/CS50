#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int score(string word);
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int main(void)
{
    string word1 = get_string("Player 1 : ");
    string word2 = get_string("Player 2 : ");

    int score1 = score(word1);
    int score2 = score(word2);

    if (score1 > score2)
    {
        printf("Player 1 wins\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins\n");
    }
    else
    {
        printf("Its a tie\n");
    }


}

int score(string word)
{
    int game_score = 0;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        if (isalpha(word[i]))
        {
            int index = toupper(word[i]) - 'A';
            game_score += POINTS[index];
        }
    }
    return game_score;
}
