#include<stdio.h>
int main(){
int i,j,r;
printf("Enter the noof rows:");
scanf("%d",&r);
for(i=0;i<r;i++){
  for(j=0;j<r;j++){
    if(i==0 || i==r-1 || j==r-i-1)
        printf("*");
    else
        printf(" ");}
 printf("\n");
}

  return 0;
}
/*output
  Enter the noof rows:4
****
  *
 *
****
*/

