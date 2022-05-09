PROGRAM - 7



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
    int n,check_ar=0,i,j,sum,k,l,minp,m,n1=0,n2=0;//with no two process with same priority
    int Cmp_time=0;
    float Avg_WT=0,Avg_TAT=0,Avg_RT=0;
    struct process p[10];
    struct process pro[100];
    struct process temp[10];
    printf("Enter the number of process \n");
    scanf("%d",&n);
    printf("Enter the Arrival time , Burst time and priority of the process\n");
    printf("AT\tBT\tPR\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d",&a[i].AT,&a[i].BT,&a[i].PR);
        a[i].id=i+1;
        n2=n2+a[i].BT;
        temp[i]=a[i];
    }
    sortart(a,n);
    sum=0;
    for(i=0;i<n2+a[i].AT;i++)
    {
        k=0;
        for(j=0;j<n;j++)
        {
            if(sum>=a[j].AT && a[j].BT>0)
            {
                p[k]=a[j];
                k++;
            }
        }
        minp=p[0].PR;
        for(l=0;l<k;l++)
        {
            if(minp>p[l].PR)
            {
                minp=p[l].PR;
            }
        }
        for(m=0;m<n;m++)
        {
            if(a[m].PR==minp)
            {
                a[m].BT=a[m].BT-1;
                pro[n1].id=a[m].id;
                if(n1==0)
                {
                    pro[n1].CT=i+1;
                    n1++;
                }
                else
                {
                    if(pro[n1].id==pro[n1-1].id)
                    {
                        pro[n1-1].CT=i+1;
                    }
                    else
                    {
                        pro[n1].CT=i+1;
                        n1++;
                    }
                }
            }
        }
        sum++;
    }
    printf("gantt chart :\n\n%d ",a[0].AT);
    for(i=0;i<n1;i++)
    {
        printf(" p%d %d | ",pro[i].id,pro[i].CT);
    }
    for(i=0;i<n1;i++)
    {
        for(j=0;j<n;j++)
        {
            if(temp[j].id==pro[i].id)
            {
                temp[j].CT=pro[i].CT;
            }
        }
    }
    printf("\n\nProcess\tArrival\tComplete\tTAT\tWaiting\n");
    for(i=0;i<n;i++)
    {
        printf("p%d\t%d\t%d\t%d\t%d\n",temp[i].id,temp[i].AT,temp[i].CT,temp[i].CT-temp[i].AT,temp[i].CT-temp[i].BT-temp[i].AT);
    }
    for(i=0;i<n;i++)
    {
        Avg_WT=Avg_WT+temp[i].CT-temp[i].BT-temp[i].AT;
        Avg_TAT=Avg_TAT+temp[i].CT-temp[i].AT;
    }
    printf("AVERAGE TURN AROUND TIME : %.2f\n",Avg_TAT/n);
    printf("AVERAGE WAITING TIME IS : %.2f\n",Avg_WT/n);
}
