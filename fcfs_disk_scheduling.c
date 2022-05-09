PROGRAM - 15(FCFS DISK SCHEDULING)





#include<stdio.h>
int main()
{
    int totalTrack,trackNo,i,trackSum=0,count=0,temp;
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
        if(que[i]-temp>0)
        {
            trackSum=trackSum+que[i]-temp;
            printf("%d  -->  %d(%d) | ",temp,que[i],que[i]-temp);
            temp=que[i];
            count++;
        }
        else if(que[i]-temp<0)
        {
            trackSum=trackSum-que[i]+temp;
            printf("%d  -->  %d(%d) | ",temp,que[i],-que[i]+temp);
            temp=que[i];
            count++;
        }
        else if(que[i]-temp==0)
        {
            printf("%d  ->  %d(0) | ",temp,temp);
            count++;
        }
    }
    printf("\nTotal sum of tracks : %d\n",trackSum);
    avghead=(float)trackSum/count;
    printf("\n>Average Head Movement =  %.2f",avghead);
    return 0;
}