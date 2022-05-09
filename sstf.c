PROGRAM - 15(SSTF DISK SCHEDULING)



#include<stdio.h>
int main()
{
    int totalTrack,trackNo,i,j,trackSum=0,count=0,temp,a=0,next,min;
    float avghead;
    printf("Enter the Total number of tracks  : ");
    scanf("%d",&totalTrack);
    printf("\nEnter the number of tracks in the queue : ");
    scanf("%d",&trackNo);
    int que[trackNo];
    printf("\nEnter the track values : ");
    for(i=0;i<trackNo;i++)
    {
        scanf("%d",&que[i]);
    }
    printf("\nEnter the header pointer track : ");
    scanf("%d",&temp);
    printf("\n");
    for(i=0;i<trackNo;i++)
    {
        if(temp>que[i])
        {
            min=temp-que[i];
            next=i;
        }
        else
        {
            min=que[i]-temp;
            next=i;
        }
        for(j=i+1;j<trackNo;j++)
        {
            if(temp-que[j]>0)
            {
                if(min>temp-que[j])
                {
                    min=temp-que[j];
                    next=j;
                }
            }
            else
            {
                if(min>que[j]-temp)
                {
                    min=que[j]-temp;
                    next=j;
                }
            }
        }
        if(que[next]-temp>0)
        {
            trackSum=trackSum+que[next]-temp;
            printf("%d  -->  %d(%d) | ",temp,que[next],que[next]-temp);
            temp=que[next];
            count++;
        }
        else if(que[next]-temp<0)
        {
            trackSum=trackSum-que[next]+temp;
            printf("%d  -->  %d(%d) | ",temp,que[next],-que[next]+temp);
            temp=que[next];
            count++;
        }
        else if(que[i]-temp==0)
        {
            printf("%d  ->  %d(0) | ",temp,temp);
            count++;
        }
        que[next]=que[a];
        a++;

    }
    printf("\nTotal sum of tracks : %d\n",trackSum);
    avghead=(float)trackSum/count;
    printf("\n>Average Head Movement =  %.2f",avghead);
    return 0;
}