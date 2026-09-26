#include<stdio.h>
int main(){
  int i,j,c,r,mat[10][10];
  printf("Enter the noof rows and cols\n");
  scanf("%d %d",&r,&c);
  if(r!=c){
    printf("Matrix is not symmetry\n");
    return 0;
}
  printf("Enter the elemnts of matrix\n");
  for(i=0;i<r;i++){
    for(j=0;j<c;j++)
      scanf("%d",&mat[i][j]);
  }
  for(i=0;i<r;i++){
    for(j=0;j<c;j++){
      if(mat[i][j]!=mat[j][i]){
        printf(" Not symmetry\n");
        return 0;
      }  
    }
  }
 printf("Symmetry\n");
  return 0;
}
/*output
  Enter the noof rows and cols
3 3
Enter the elemnts of matrix
1 2 3
2 4 5
3 5 6
Symmetry
*/

