#include<stdio.h>
 
struct times
{
       int p,art,but,wtt,tat,rnt;
};
 
void sortart(struct times a[],int pro)
{
       int i,j;
       struct times temp;
       for(i=0;i<pro;i++)
       {
              for(j=i+1;j<pro;j++)
              {
                     if(a[i].art > a[j].art)
                     {
                           temp = a[i];
                           a[i] = a[j];
                           a[j] = temp;
                     }
              }
       }
       return;
}
 
int main()
{
       int i,j,pro,time,remain,count=0,ts;
       struct times a[100];
       float avgwt=0,avgtt=0,avgct=0;
       int rt[5][2];
       printf("Enter Number Of Processes : ");
       scanf("%d",&pro);
       remain=pro;
       for(i=0;i<pro;i++)
       {
              printf("Enter arrival time and Burst time for Process P%d : ",i+1);
              scanf("%d%d",&a[i].art,&a[i].but);
              a[i].p = i;
              a[i].rnt = a[i].but;
       }
       sortart(a,pro);
       printf("Enter Time Slice OR Quantum Number : ");
       scanf("%d",&ts);
       printf("Gantt Chart\n");
       printf("0");
       for(time=0,i=0;remain!=0;)
       {
              if(a[i].rnt<=ts && a[i].rnt>0)
              {
                     time = time + a[i].rnt;
                     printf(" -> [P%d] <- %d",a[i].p+1,time);
                     a[i].rnt=0;
                     count=1;
              }
              else if(a[i].rnt > 0)
              {
                     a[i].rnt = a[i].rnt - ts;
                     time = time + ts;
                     printf(" -> [P%d] <- %d",a[i].p+1,time);
              }
              if(a[i].rnt==0 && count==1)
              {
                     remain--;
                     a[i].tat = time-a[i].art;
                     a[i].wtt = time-a[i].art-a[i].but;
                     avgwt = avgwt + time-a[i].art-a[i].but;
                     avgtt = avgtt + time-a[i].art;
                     count=0;
              }
              if(i==pro-1)
              {
                     i=0;
              }
              else if(a[i+1].art <= time)
              {
                     i++;
              }
              else
              {
                     i=0;
              }
       }
       printf("\n\n");
       printf("Pro\tArTi\tBuTi\tCTi\tTaTi\tWtTi\n");
       for(i=0;i<pro;i++)
       {
              printf("P%d\t%d\t%d\t%d\t%d\t%d\n",a[i].p+1,a[i].art,a[i].but,a[i].tat+a[i].art,a[i].tat,a[i].wtt);
       }
       avgtt = avgtt/pro;
       for(i=0;i<pro;i++)
       {
           avgct=avgct+a[i].art;
       }
       avgct=(avgwt+avgct)/pro;
       avgwt = avgwt/pro;
       printf("Average Waiting Time : %.2f\n",avgwt);
       printf("Average Turnaround Time : %.2f\n",avgtt);
       printf("Average complete Time : %.2f\n",avgct);
       return 0;
       printf("\n\n");
       
}
