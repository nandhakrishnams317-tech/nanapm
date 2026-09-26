#include<stdio.h>
#include<string.h>
int main(){
  int i,n,k;
  char str[10][20];
  printf("Enter the no.of elements to be entered:");
  scanf("%d",&n);
  printf("Enter the product code:");
  for(i=0;i<n;i++)
    scanf("%19s",str[i]);
  printf("Product code report\n");
  for(i=0;i<n;i++){
    int len=strlen(str[i]);
    int f=1;
    for(int j=0;j<len/2;j++){
        if(str[i][j]==str[i][len-1]){
        f=0;
        break;
      }
    }
    if(f==0)
      printf("it is palindrome %s\n",str[i]);
    else
        printf("it is not palindrom %s\n",str[i]);
    }
   
return 0;
}
/*output
Enter the no.of elements to be entered:3
Enter the product code:102
210
111
Product code report
it is not palindrom 102
it is not palindrom 210
it is palindrome 111
*/

