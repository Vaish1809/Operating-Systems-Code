#include<stdio.h> 
int findLRU(int 
time[], int n)  
{  
int i, minimum = time[0], position = 0;  
for(i = 1; i < n; i++)  
{  
if(time[i] < minimum)  
{  
minimum = time[i];  
position = i;  
}  
}  
return position;  
}  
   
int main()  
{  
int f, s, i, j, position, counth = 0, countf = 0, temp = 
0, flag1, flag2; float hit, miss;  
printf("Enter the number of frames in the 
memory : "); scanf("%d", &f); printf("Enter 
the size of page stream : "); scanf("%d", 
&s); int stream[s], frame[f], time[f]; 
printf("Enter the page stream - \n");  
for(i = 0; i < s; i++)  
{  
scanf("%d", &stream[i]);  
} for(i = 0; i < 
f; i++) {  
frame[i] = -1;  
}  
printf("\nPage Stream\tFrames\n");  
for(i = 0; i < s; i++)  
{  
printf("%d\t\t", 
stream[i]); flag1 = flag2 
= 0;  
for(j = 0; j < f; j++)  
{  
if(frame[j] == stream[i])  
{  
temp++;  
time[j] = temp; 
flag1 = flag2 = 
1;  
counth++; 
break;  
}  
}  
if(flag1 == 0)  
{ for(j = 0; j < 
f; j++)  
{  
if(frame[j] == -1)  
{  
temp++; 
countf++; 
frame[j] = 
stream[i]; 
time[j] = temp; 
flag2 = 1; 
break;  
} 
}      
}  
if(flag2 == 0)  
{  
position = 
findLRU(time, f); 
temp++; countf++; 
frame[position] = 
stream[i]; 
time[position] = 
temp;  
} for(j = 0; j < 
f; j++)  
{  
printf("%d\t", frame[j]);  
}  
if(flag1 == 1 && flag2 == 1) printf("\t\t 
HIT\n"); else printf("\t\t FAULT\n");  
}  
printf("\nNumber of page hits = 
%d", counth); printf("\nNumber of 
page faults = %d", countf); hit = 
(float)counth / (float)s; miss = 
(float)countf / (float)s; printf("\nHit 
ratio = %f", hit); printf("\nMiss ratio 
= %f", miss); return 0;  
}  
 
