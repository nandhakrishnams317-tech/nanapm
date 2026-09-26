#include<stdio.h>
#include<string.h>
int main(){
  int i,j,n,k;
  char e[20][20];
   printf("Enter the number:\n");
   scanf("%d",&n);
   printf("Enter the emails:\n");
   for(i=0;i<n;i++)
        scanf("%s",e[i]);
   for(i=0;i<n;i++){
     for(j=i+1;j<n;j++){
       if(strcmp(e[i],e[j])==0){
         for(k=j;k<n-1;k++)
           strcpy(e[k],e[k+1]);
         n--;
         j--;
       }
     }
   }
   if(n!=k)
     printf("No duplicates Found");
   else{
   printf("After removing duplicates\n");
   for(i=0;i<n;i++)
        printf("%s\n",e[i]);
   }
  return 0;
}
/*output
  Enter the number:
3
Enter the emails:
anu@gmail.com
anna@gmail.com
anu@gmail.com
After removing duplicates
anu@gmail.com
anna@gmail.com
*/

