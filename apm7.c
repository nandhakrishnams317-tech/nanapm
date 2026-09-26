#include<stdio.h>
int i,j,a[10][10];
  int transpose(int r,int c){
    printf("transpose:\n");
     for(i=0;i<c;i++){
       for(j=0;j<r;j++){
                printf("%d\t",a[j][i]);
        }
    printf("\n");
     }}
int main(){
  int rsum,csum,t=0,r,c;
  printf("enter no.of rows and columns\n");
  scanf("%d %d",&r,&c);
  printf("enetr data\n");
  for(i=0;i<r;i++){
    for(j=0;j<c;j++)
      scanf("%d",&a[i][j]);}
for(i=0;i<r;i++){
        rsum=0;
       for(j=0;j<c;j++){
                rsum+=a[i][j];}
       printf("sum of row %d is %d\n",i+1,rsum);}
for(j=0;j<c;j++){
  csum=0;
  for(i=0;i<r;i++){
      csum+=a[i][j];}
  printf("sum of col %d is %d\n",j+1,csum);
}
for(i=0;i<r;i++){
         for(j=0;j<c;j++){
           if(i==j)
                t+=a[i][j];
         }}
printf("trace= %d\n",t);
transpose(r,c);
return 0;}
/*output
enter no.of rows and columns
3 3
enetr data
1 2 4
2 5 6
3 7 1
sum of row 1 is 7
sum of row 2 is 13
sum of row 3 is 11
sum of col 1 is 6
sum of col 2 is 14
sum of col 3 is 11
trace= 7
transpose:
1	2	3	
2	5	7	
4	6	1	
  */

