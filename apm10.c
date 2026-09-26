#include<stdio.h>
#include<string.h>
void swap(char str[],int i,int j){
char temp;
temp=str[i];
str[i]=str[j];
str[j]=temp;
}
void permute(char str[],int l,int r){
int i;
if(l==r)
  printf("%s\n",str);
else{
  for(i=l;i<=r;i++){
    swap(str,l,i);
    permute(str,l+1,r);
    swap(str,l,i);
  }
}
}
int main(){
  char str[20];
  printf("Enter the string:\n");
  scanf("%s",str);
  printf("All permutatons:\n");
  permute(str,0,strlen(str)-1);
return 0;
}
/*
output
Enter the string:
ABC
All permutatons:
ABC
ACB
BAC
BCA
CBA
CAB
*/

