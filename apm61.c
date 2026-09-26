#include<stdio.h>
int main(){
  int i,s,c,j,r;
  printf("Enter no of rows:");
  scanf("%d",&r);
  for(i=0;i<r;i++){
    for(s=1;s<=r-i;s++)
      printf(" ");
    for(j=0;j<=i;j++){
      if(j==0 || j==i)
        c=1;
      else
        c=c*(i-j+1)/j;
    printf("%d ",c);}
    
      printf("\n");
  }    return 0;
  }
/*output
  Enter no of rows:4
    1
   1 1
  1 2 1
 1 3 3 1
 */

