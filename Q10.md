#include<stdio.h>
#include<conio.h>
void func1(n,head_pos);
int main()
{
    int head_pos,n;
    printf("\nEnter the head position:: ");
    scanf("%d",&head_pos);          //head_pos points to current position
    printf("\nEnter the number of requests:: ");
    scanf("%d",&n);
    func1(n,head_pos);
    getch();
}
void func1(n,head_pos)
{
	int request[n],i;                //request[n] is the request list
    for(i=0;i<n;i++)
    {
        scanf("%d",&request[i]);
    }
    int difference=request[0]-head_pos;
    if(difference<0)
    {
            difference=difference*-1;
    }
    for(i=1;i<n;i++)
    {
        if((request[i]-request[i-1])>0)
        	difference=difference+(request[i]-request[i-1]);
        else
            difference=difference+(request[i-1]-request[i]);
    }
    printf("Seek time:: %d\n",difference);	
}
