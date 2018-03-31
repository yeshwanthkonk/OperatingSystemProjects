#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main()
{
    int Proce;
    printf("Enter Number of Processors to Be Submitted to the Processors : \n");
    scanf("%d",&Proce);
    int i,j,var;
    int time=0;
    char P[Proce][2];
    int AT[Proce];
    int BT[Proce],RT[Proce];
    int WT[Proce];
    int TRT[Proce];
    int AvgWT,AvgTRT;
    for(i=0;i<Proce;i++)
    {
        printf("Enter Arrival Time and Brust Time for Processor \"P%d\" : \n",i+1);
        P[i][0] = 'P';
        P[i][1] = i+1;
        scanf("%d %d",&AT[i],&BT[i]);
        //RT[i] = BT[i];
    }
    for(i=0;i<Proce;i++)
    {
        for(j=i+1;j<Proce;j++)
        {
            if(AT[i]>AT[j])
            {
                var = AT[i];
                AT[i] = AT[j];
                AT[j] = var;

                var = BT[i];
                BT[i] = BT[j];
                BT[j] = var;

                var = P[i][1];
                P[i][1] = P[j][1];
                P[j][1] = var;
            }
        }
    }
    int q = AT[0];

    for(i=0;i<Proce;i++)
    {
        printf("%c%d : %d \t %d",P[i][0],P[i][1],AT[i],BT[i]);
        printf("\n");
    }
}
