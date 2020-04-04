#include<stdio.h>
#include<conio.h>

void Sorting_of_Arrival_Time(no_process);

struct processes
{
    int arr_t, bur_t, curr_t, wt_t, turn_t, priority,status;
};

struct processes p_queue[10];

int main()
{
	printf("\nEnter the Choice 1 or 2\n");
	printf("\n1.Fixed Priority Preemptive Scheduling");
    printf("\n2.Round Robin Scheduling\n");
    printf("\nEnter your choice :: ");
    int ch;
    scanf("%d",&ch);
    switch(ch)
    {
    	int no_process;
    	case 1:
       {
            int i, tot_t = 0, bur_t = 0, lar;
            float wt_t = 0, turn_t = 0, avg_wt_t, average_turnaround_time;
            printf("\nEnter Total Number of Processes :: ");
            scanf("%d", &no_process);
            for(i = 0; i < no_process; i++)
            {
                printf("\nProcess%d\n", i+1);
                printf("Enter Arrival time :: "); 
                scanf("%d", &p_queue[i].arr_t );
                printf("Enter Burst time :: ");
                scanf("%d", &p_queue[i].bur_t);
                printf("Enter Priority ::");
                scanf("%d", &p_queue[i].priority);
                p_queue[i].status = 0;
                bur_t = bur_t + p_queue[i].bur_t;
            }
            Sorting_of_Arrival_Time(no_process);
            p_queue[9].priority = -10000;
            printf("\nProcess Name\tArrival Time\tBurst Time\tPriority\tWaiting Time");
            for(tot_t = p_queue[0].arr_t; tot_t < bur_t;)
            {
                lar = 9;
                for(i = 0; i < no_process; i++)
                {
                    if(p_queue[i].arr_t <= tot_t && p_queue[i].status != 1 && p_queue[i].priority > p_queue[lar].priority)
                    {
                        lar = i;
                    }
                }
                tot_t = tot_t + p_queue[lar].bur_t;
                p_queue[lar].curr_t = tot_t;
                p_queue[lar].wt_t = p_queue[lar].curr_t - p_queue[lar].arr_t - p_queue[lar].bur_t;
                p_queue[lar].turn_t = p_queue[lar].curr_t - p_queue[lar].arr_t;
                p_queue[lar].status = 1;
                wt_t = wt_t + p_queue[lar].wt_t;
                turn_t = turn_t + p_queue[lar].turn_t;
                printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", lar+1, p_queue[lar].arr_t, p_queue[lar].bur_t, p_queue[lar].priority, p_queue[lar].wt_t);
            }
                avg_wt_t = wt_t / no_process;
                average_turnaround_time = turn_t / no_process;
                printf("\n\nAverage waiting total time::\t%f\n", avg_wt_t);
                printf("Average Turnaround Time::\t%f\n", average_turnaround_time);
                break;
       }            
		
		case 2:
       {
            int counter,j,n,tot_t,left_process,flag=0,t_quan; 
            int wt_t=0,turn_t=0,arr_t[10],bur_t[10],remaining_time[10]; 
            printf("\nEnter no of process :: "); 
            scanf("%d",&n); 
            left_process=n; 
            for(counter=0;counter<n;counter++) 
            {
				 
         	    printf("\nProcess%d\n",counter+1); 
                printf("Enter Arrival time :: "); 
                scanf("%d",&arr_t[counter]); 
                printf("Enter Burst time :: ");
                scanf("%d",&bur_t[counter]); 
                remaining_time[counter]=bur_t[counter]; 
            } 
            printf("\nEnter Time Quantum ::"); 
            scanf("%d",&t_quan); 
            printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n"); 
            for(tot_t=0,counter=0;left_process!=0;) 
            { 
                if(remaining_time[counter]<=t_quan && remaining_time[counter]>0) 
                { 
                    tot_t+=remaining_time[counter]; 
                    remaining_time[counter]=0; 
                    flag=1; 
                } 
                else if(remaining_time[counter]>0) 
                { 
                    remaining_time[counter]-=t_quan; 
                    tot_t+=t_quan; 
                } 
                if(remaining_time[counter]==0 && flag==1) 
                { 
            	    left_process--; 
                    printf("P%d\t|\t%d\t|\t%d\n",counter+1,tot_t-arr_t[counter],tot_t-arr_t[counter]-bur_t[counter]); 
                    wt_t+=tot_t-arr_t[counter]-bur_t[counter]; 
                    turn_t+=tot_t-arr_t[counter]; 
                    flag=0; 
                } 
                if(counter==n-1) 
                    counter=0; 
                else if(arr_t[counter+1]<=tot_t) 
                    counter++; 
                else 
                    counter=0; 
            } 
                printf("\nAverage Waiting Time= %f\n",wt_t*1.0/n); 
                printf("Avg Turnaround Time = %f",turn_t*1.0/n); 
                break;
       }
    	default:
    		printf("\nWrong Choice Entered\n");
    }
    getch();
}

void Sorting_of_Arrival_Time(no_process)
{
    struct processes temp1;
    int i1,j1;
    for(i1 = 0; i1 < no_process - 1; i1++)
    {
        for(j1 = i1 + 1; j1 < no_process; j1++)
        {
            if(p_queue[i1].arr_t > p_queue[j1].arr_t)
            {
                temp1 = p_queue[i1];
                p_queue[i1] = p_queue[j1];
                p_queue[j1] = temp1;
            }
        }
    }
}
