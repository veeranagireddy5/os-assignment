#include<stdio.h> 
 
int main() 
{ 
 
  int count,j,n,time,remain,flag=0,time_quantum; 
  int wait_time=0,turnaround_time=0,arrival_time[10],burst_time[10],response_time[10]; 
  printf("Enter Total Process:\t "); 
  scanf("%d",&n); 
  remain=n; 
    for(count=0;count<n;count++) 
  { 
    printf("Enter Arrival Time  %d :",count+1); 
    scanf("%d",&arrival_time[count]); 
    
  } 
  for(count=0;count<n;count++) 
  { 
    printf("Enter Burst Time for Process Process Number %d :",count+1);  
    scanf("%d",&burst_time[count]); 
    response_time[count]=burst_time[count]; 
  } 
  printf("Enter Time Quantum:\t"); 
  scanf("%d",&time_quantum); 
  printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n"); 
  for(time=0,count=0;remain!=0;) 
  { 
    if(response_time[count]<=time_quantum && response_time[count]>0) 
    { 
      time+=response_time[count]; 
      response_time[count]=0; 
      flag=1; 
    } 
    else if(response_time[count]>0) 
    { 
      response_time[count]-=time_quantum; 
      time+=time_quantum; 
    } 
    if(response_time[count]==0 && flag==1) 
    { 
      remain--; 
      printf("P[%d]\t|\t%d\t|\t%d\n",count+1,time-arrival_time[count],time-arrival_time[count]-burst_time[count]); 
      wait_time+=time-arrival_time[count]-burst_time[count]; 
      turnaround_time+=time-arrival_time[count]; 
      flag=0; 
    } 
    if(count==n-1) 
      count=0; 
    else if(arrival_time[count+1]<=time) 
      count++; 
    else 
      count=0; 
  } 
  printf("\nAverage Waiting Time= %f\n",wait_time*1.0/n); 
  printf("Avg Turnaround Time = %f",turnaround_time*1.0/n); 
  
  return 0; 
}
