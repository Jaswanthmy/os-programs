#include<stdio.h>
struct process
{
    int id,WT,AT,BT,TAT,PR,CT,RT;
};
struct process a[10];

void sortart(struct process a[],int n)
{
       int i,j;
       struct process temp;
       for(i=0;i<n;i++)
       {
              for(j=i+1;j<n;j++)
              {
                     if(a[i].AT > a[j].AT)
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
    int n,check_ar=0,i,j,sum,r=0,min,ch,j1;
    int Cmp_time=0;
    float Avg_WT=0,Avg_TAT=0,Avg_RT=0;
    struct process temp;
    struct process pro[10];
    printf("Enter the number of process \n");
    scanf("%d",&n);
    printf("Enter the Arrival time , Burst time and priority of the process\n");
    printf("AT\tBT\tPR\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d",&a[i].AT,&a[i].BT,&a[i].PR);
        a[i].id=i+1;
    }
    sortart(a,n);
    sum=a[0].AT;
    for(i=0;i<n;i++)//ghannt chart
    {
        r=0;
        for(j=i;j<n;j++)
        {
            if(sum>=a[j].AT)
            {
                r=r+1;
            }
        }
        min=a[i].PR;                                                
        for(j=i+1;j<r+i;j++)
        {
           if(min>a[j].PR)
           {
               min=a[j].PR;
           }
        }
        ch=0;
        for(j=i;j<r+i;j++)
        {
            if(min==a[j].PR)
            {
                j1=j;
                pro[ch]=a[j];
                ch=ch+1;
            }
        }
        if(ch>1)
        {
            min=pro[0].AT;
            for(j=1;j<ch;j++)
            {
                if(min>pro[j].AT)
                {
                    min=pro[j].AT;
                }
            }
            for(j=i;j<r+i;j++)
            {
                if(min==a[j].AT)
                {
                    temp=a[i];
                    a[i]=a[j];
                    a[j]=temp;
                    a[i].RT=sum;
                    if(a[i].RT<0)
                    {
                        a[i].RT=0;
                    }
                    a[i].CT=sum+a[i].BT;
                    a[i].TAT=a[i].CT-a[i].AT;
                    a[i].WT=a[i].TAT-a[i].BT;
                    if(a[i].WT<0)
                    {
                        a[i].WT=0;
                    }
                    sum=sum+a[i].BT;
                }
            }
        }
        else
        {
            temp=a[i];
            a[i]=a[j1];
            a[j1]=temp;
            a[i].RT=sum;
            if(a[i].RT<0)
            {
                a[i].RT=0;
            }
            a[i].CT=sum+a[i].BT;
            a[i].TAT=a[i].CT-a[i].AT;
            a[i].WT=a[i].TAT-a[i].BT;
            if(a[i].WT<0)
            {
                a[i].WT=0;
            }
            sum=sum+a[i].BT;
        }
    }
    printf("\n Table :\n\n");
    printf("Process\tAT\tBT\tPriorty\tCT\tTAT\tWT\tRT\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i+1==a[j].id)
            {
                printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",a[j].id,a[j].AT,a[j].BT,a[j].PR,a[j].CT,a[j].TAT,a[j].WT,a[j].RT);
            }
        }
    }
    printf("\n Gantt chart :\n\n");
    for(i=0;i<n;i++)
    {
        printf("  P%d\t",a[i].id);
    }
    printf("\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i].RT);
    }
    printf("%d\n",a[i-1].CT);
    for(i=0;i<n;i++)
    {
        Avg_WT=Avg_WT+a[i].WT;
        Avg_TAT=Avg_TAT+a[i].TAT;
        Avg_RT=Avg_RT+a[i].RT;
    }
    printf("Average Turn around time : %.2f\n",Avg_TAT/n);
    printf("Average Waiting time : %.2f\n",Avg_WT/n);
    printf("Average Response around time : %.2f\n",Avg_RT/n);
}