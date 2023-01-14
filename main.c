#include "wordbuild.c"
#include "tictactoe.c"
int main()
{


    int exit=0;
    do {
    system("cls");
    printf("Enter the game u want to choose\n1.Word building\n2.Tictactoe\n3.Exit");
    int choice;
    printf("\nEnter a choice:");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: wordbuilding();
                system("pause");
        break;
        case 2:tictactoe10();
                system("pause");
        break;
        case 3: exit=1;
                printf("Thank you for playing.Have a good day");
    }
    }while(exit==0);
}
