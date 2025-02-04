#include <stdio.h> 
int 
main()  
{  
int f, s, i, j = 0, k, counth = 0, countf = 0, 
temp; float hit, miss; printf("Enter the number of frames in the memory : "); scanf("%d", &f); printf("Enter the size of page stream : "); scanf("%d", &s);  
int stream[s], frame[f]; 
printf("Enter the page stream - \n"); for(i = 0; i < s; 
i++)  
{  
scanf("%d", &stream[i]);  
} for(i = 0; i < 
f; i++)  
{  
frame[i] = -1;  
}  
printf("\nPage Stream\tFrames\n");  
for(i = 0; i < s; i++)  
{  
printf("%d\t\t", 
stream[i]); temp = 0;  
for(k = 0; k < f; k++)  
{  
if(frame[k] == stream[i])  
{  
temp = 1; 
counth++;  
for(k = 0; k < f; k++)  
{  
printf("%d\t", frame[k]);  
}  
printf("\t\tHIT\n");  
}  
}  
if(temp == 0)  
{  
frame[j] = stream[i];  
j = (j + 1) % f;  
countf++; for(k 
= 0; k < f; k++)  
{  
printf("%d\t", frame[k]);  
}  
printf("\t\tFAULT\n");  
}  
}  
printf("\nNumber of page hits =  %d", counth); printf("\nNumber of  page faults = %d", countf);       hit = 
(float)counth / (float)s;       miss 
= (float)countf / (float)s;      
 printf("\nHit ratio = %f", hit);      
 printf("\nMiss ratio = %f", miss);      
 return 0;  
} 