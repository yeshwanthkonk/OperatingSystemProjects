#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main()
{
    int Proce;
    printf("Enter Number of Processors to Be Submitted to the Processors : \n");
    scanf("%d",&Proce);
    int i,j,var;
    int TS;
    char P[Proce][2],var2;
    int AT[Proce];
    int BT[Proce],RT[Proce];
    int WT[Proce];
    int TRT[Proce];
    int AvgWT=0,AvgTRT=0;
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
    for(i=0;i<Proce;i++)
    {
        printf("%c%d : %d    %d",P[i][0],P[i][1],AT[i],BT[i]);
        printf("\n");
        RT[i] = BT[i];
    }
    printf("----------------------------------------------------GANTTCHART---------------------------------------------------------\n");
    int time = AT[0];
    int z;
    for(z=0;z<2;)
    {
        ++z;
        if(z==1)
            TS = 3;
        else
            TS = 6;
        for(i=0;i<Proce;i++)
        {
            if(RT[i]==0)
                continue;
            if(RT[i]>TS)
            {
                printf("%c%d : %d  -  %d \n",P[i][0],P[i][1],time,time+TS);
                time = time+TS;
                RT[i] = RT[i] - TS;
            }
            else
            {
                printf("%c%d : %d  -  %d \n",P[i][0],P[i][1],time,time+RT[i]);
                time = time + RT[i];
                RT[i] = 0;
                TRT[i] = time - AT[i];
                WT[i] = TRT[i] - BT[i];
            }
        }
    }
    for(i=0;i<Proce;i++)
    {
        for(j=i+1;j<Proce;j++)
        {
            if(RT[i]>RT[j])
            {
                var = AT[i];
                AT[i] = AT[j];
                AT[j] = var;

                var = BT[i];
                BT[i] = BT[j];
                BT[j] = var;

                var = RT[i];
                RT[i] = RT[j];
                RT[j] = var;

                var = TRT[i];
                TRT[i] = TRT[j];
                TRT[j] = var;

                var = WT[i];
                WT[i] = WT[j];
                WT[j] = var;

                var2 = P[i][1];
                P[i][1] = P[j][1];
                P[j][1] = var2;
            }
        }
    }
    for(i=0;i<Proce;i++)
    {
        if(RT[i]==0)
            continue;
        printf("%c%d : %d  -  %d \n",P[i][0],P[i][1],time,time+RT[i]);
        time = time + RT[i];
        RT[i] = 0;
        TRT[i] = time - AT[i];
        WT[i] = TRT[i] - BT[i];
    }
    printf("Processes  Waiting Time of Processes:      ||      Turn Around Time of Processes: \n");
    int a;
    for(i=0;i<Proce;i++)
    {
        for(j=0;j<Proce;j++)
        {
            if(i==(P[j][1]-1))
            {
                a=i;
                i=j;
                break;
            }
        }
        printf("%c%d : \t\t%d\t\t\t\t\t %d\n",P[i][0],P[i][1],WT[i],TRT[i]);
        AvgWT = AvgWT + WT[i];
        AvgTRT = AvgTRT + TRT[i];
        i=a;
    }
    printf("Average Waiting Time : %d\n",AvgWT/Proce);
    printf("Average Trun Around Time : %d\n",AvgTRT/Proce);
}
