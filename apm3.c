#include<stdio.h>
int main()
{
  int i,j,n,flag;
  printf("enter the limit:");
  scanf("%d",&n);
  int arr[n];
  printf("enter the elements:");
  for(i=0;i<n;i++)
  {
    scanf("%d",&arr[i]);
  }
  printf("prime number:");
  for(i=0;i<n;i++)
  {
    if(arr[i]<2)
    {
      continue;
    }
    flag=1;
    for(j=2;j<arr[i];j++)
    {
      if(arr[i]%j==0)
      {
        flag=0;
        break;
      }
    }
    if(flag==1)
    {
      printf("%d\t",arr[i]);
    }
  }
}


