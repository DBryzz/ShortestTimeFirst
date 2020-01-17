#include<stdio.h>
#include<curses.h> // #include<conio.h> for windows system

void main()
{
  // Variable declaration
 int pid[10], arriv_Time[10], burst_Time[10], x[10];
 int waiting[10], turnaround[10], completion[10];
 int i, j, smallest, count = 0, time, n;
 double avg = 0,tt = 0, end;
 

 // Enter number of processes
 printf("\nEnter the number of Processes: ");
 scanf("%d",&n);

 // number processes
 for(i = 0; i < n; i++){
   pid[i] = i+1;
 } 

// Enter Processes' arrival Time
 for(i = 0; i < n; i++)
 {
   printf("\nEnter arrival time of process %d : ", i+1);
   scanf("%d", &arriv_Time[i]);
 }

// Enter burst time of processes (Execution time)
 for(i = 0; i < n; i++)
 {
   printf("\nEnter burst time of process %d : ",i+1);
   scanf("%d", &burst_Time[i]);
 }

 for(i = 0; i < n; i++)
 x[i]=burst_Time[i];

  burst_Time[9]=9999;

 //printf("time => process number");

 for(time = 0; count != n; time++)
 {

   smallest = 9;

  for(i = 0; i < n; i++)
  {

   if(arriv_Time[i] <= time && burst_Time[i] < burst_Time[smallest] && burst_Time[i]>0 )
   smallest=i;

  }

  burst_Time[smallest]--;


  if(burst_Time[smallest] == 0)
  {

   count++;
   end = time+1;
   completion[smallest] = end;
   waiting[smallest] = end - arriv_Time[smallest] - x[smallest];
   turnaround[smallest] = end - arriv_Time[smallest];

  }

}

printf("\n\nBefore Sorting base on Turnaround Time\n================================================\n\n");
printf("pid \t burst \t arrival \twaiting \tturnaround \tcompletion");
 for(i = 0; i < n; i++)
 {
   printf("\n %d \t   %d \t %d\t\t%d   \t\t%d\t\t%d", pid[i], x[i], arriv_Time[i], waiting[i], turnaround[i], completion[i]);
   avg = avg + waiting[i];
   tt = tt + turnaround[i];
 }

 printf("\n  %If   %If", avg,tt);
 printf("\n\nAverage waiting time = %lf\n",avg/n);
 printf("Average Turnaround time = %lf\n\n",tt/n);
 getch();

printf("\n\nAfter Sorting base on Turnaround Time\n================================================\n\n");
printf("pid \t burst \t arrival \twaiting \tturnaround \tcompletion");

 for(i = 0; i < n; i++)
 {
	 
	 int j, s;
 
 
            for (j = i + 1; j < n; ++j)
            {
 
                if (turnaround[i] > turnaround[j]) 
                {
 
                    s =  turnaround[i];
                    turnaround[i] = turnaround[j];
                    turnaround[j] = s;


                    s =  pid[i];
                    pid[i] = pid[j];
                    pid[j] = s;


                    s =  waiting[i];
                    waiting[i] = waiting[j];
                    waiting[j] = s;

                    s =  completion[i];
                    completion[i] = completion[j];
                    completion[j] = s;

                    s =  arriv_Time[i];
                    arriv_Time[i] = arriv_Time[j];
                    arriv_Time[j] = s;

                    s =  x[i];
                    x[i] = x[j];
                    x[j] = s;
 
                }


	  }

	 

 

   printf("\n %d \t   %d \t %d\t\t%d   \t\t%d\t\t%d", pid[i], x[i], arriv_Time[i], waiting[i], turnaround[i], completion[i]);
   avg = avg + waiting[i];
   tt = tt + turnaround[i];
 }
 
 printf("\n\nAverage waiting time = %lf\n",avg/n);
 printf("Average Turnaround time = %lf\n\n",tt/n);
 getch();
}
