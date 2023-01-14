#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<string.h>
char name1[25];
char name2[25];
int win0,win1,win2,total;
void print_grid();
char player(int number);
int search4win(int *moves, int length);
int tictactoe();
void reset_board();
int wins[8][3]={{1,2,3},{4,5,6},{7,8,9},{1,4,7},{2,5,8},{3,6,9},{1,5,9},{3,5,7}};
char board[9]={'1','2','3','4','5','6','7','8','9'};
void tictactoe10()
{
    printf("Welcome to the Tic Tac Toe game\n\n");
    printf("Enter the name of the first player:\n");
    scanf("%s",&name1);
    printf("Enter the name of the second player:\n");
    scanf("%s",&name2);
    printf("\n\n");
    printf("%s VS %s\n",name1,name2);
    printf("\n\n");
	int	play=1, winner;
	char again;
	while (play >= 1)
	{
		winner=tictactoe();
		switch (winner){
			case 1:
				win0++;
				break;
			case -1:
				win1++;
				break;
			case 0:
				win2++;
				break;
			default:
				printf("Unknown winner");
				break;
		}
		printf("So far \n %s has won: %d times\n %s has won: %d times\n and there have been %d draws.\n", name1,win0,name2,win1,win2);
		total=win0+win1+win2;
		printf("Would you like another go Y or N\n");
		scanf("%c", &again);
		getchar();
		if ((again=='y') || (again=='Y'))
		{
			play++;
			reset_board();
		}
		else if ((again=='n') || (again=='N'))
		{
            printf("The number of matches have been played by %s and %s is %d\n",name1,name2,total);
            printf("Thank you for playing goodbye\n");
			play=0;
		}
			 else
					printf("Invalid entry\n");
	}
return 0;
}
int tictactoe()
{
	int Xmoves[5], Omoves[4];
	int go, goes=0, turn=1, row=0, Xgoes=0, Ogoes=0;
	print_grid();
	while ((goes < 9) && (row != 3))
	{
		printf("Player %c please enter your move:\n", (player(turn)));
		scanf("%d", &go);
		getchar();
		if((go < 10) && (go > 0) && (board[go-1] != 'X') && (board[go-1] != 'O'))
		{
			board[go-1]=(player(turn));
			print_grid();
			if (turn > 0)
			{
				Xmoves[Xgoes]=go;
				Xgoes++;
				if (Xgoes >2)
				{
					row = search4win(Xmoves, Xgoes);
				}
			}
			else
			{
				Omoves[Ogoes]=go;
				Ogoes++;
				if (Ogoes >2)
				{
					row=search4win(Omoves, Ogoes);
				}
			}
			if(row==3)
			{
				printf("The winner is %c\n", (player(turn)));
				return turn;
			}
			goes++;
			turn=turn*(-1);
		}
		else
			printf("invalid entry\n");
	}
}
void reset_board()
{
    int i;
    for(i=0; i<=8; i++)
    {
        board[i]= i + '1';
    }
}
char player(int number)
{

	return (number > 0) ? 'X' : 'O';
}
void print_grid()
{
    system("cls");
    printf("      |      |      \n");
    printf("    %c |    %c |  %c \n", board[0], board[1], board[2]);
    printf("______|______|______\n");
    printf("      |      |     \n");
    printf("    %c |    %c |  %c \n", board[3], board[4], board[5]);
    printf("______|______|______\n");
    printf("      |      |     \n");
    printf("    %c |    %c |  %c \n",  board[6], board[7], board[8]);
    printf("      |      |     \n\n");
}
int search4win(int *moves, int length)
{
	int i=0, j=0, k=0, n, line=0, ret;
	while(line < 3 && j < 8)
	{
		for(i=0; i<3; i++)
		{
			n=wins[j][i];
			for(k=0; k<length; k++)
			{
				if (n == moves[k])
				line++;
			}
		}
		if (line == 3)
			return 3;
		else
			line=0;
		j++;
	}
return 0;
}
