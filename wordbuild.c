#include<stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<string.h>
#define ZERO 0
struct struct1
{
  char storage[20];
};
void wordbuilding()
{
    const char* mode = "w+";
    const char* filename = "WordBuilding.txt";
    FILE *pt;
    pt=fopen(filename,mode);
    printf("Welcome to the WORD BUILDING GAME\n\n");
    int name[25];
    printf("Enter the name of the player:\n");
    scanf("%s",&name);
    printf("Player name:%s\n\n",&name);
    int n;
    struct struct1 *p;
    printf("Enter the number of rounds:\n");
    scanf("%d",&n);
    fflush(stdin);
    struct struct1 store[n];
    p=store;
    printf("Enter the words:\n");
    for(int i=0;i<n;i++)
    {
        printf("Word : %d\n",i+1);
        if(i==0)
        {
            scanf("%s",store[i].storage);
        }
        else
        {
            int size=strlen(store[i-1].storage);
            scanf("%s",store[i].storage);
            if((store+i-1)->storage[size-1]!=(store+i)->storage[0])
            {
                printf("Invalid entry,Please enter a valid choice \n");
                scanf("%s",(store+i)->storage);
            }
        }
    }
        if(pt==NULL)
        {
            printf("Error - Cannot open the designated file\n");
        }
        else
        {
            fprintf("Name of the player:%s",name,pt);
            for(int i=0;i<n;i++)
                {
                    fputs((p+i)->storage,pt);
                    fprintf(pt,"\n");
                }
        }
        printf("\nTHe contents you have written \n");
        char something[20];
        rewind(pt);
        for(int i=0;i<n;i++)
                {
                    fscanf(pt," %s",something);
                    printf("%s\n",something);
                }
                printf("Thank you for playing,Have a good day %s\n\n",&name);
}
