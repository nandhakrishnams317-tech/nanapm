#include<stdio.h>
 #include<string.h>
   int main(){
   int p,i,l,subl;
     char str[50],sub[20];
     printf("Enter string:\n");
     scanf("%s",str);
     printf("Enter substring:\n");
     scanf("%s",sub);
    printf("Enter position\n");
     scanf("%d",&p);
    l=strlen(str);
    subl=strlen(sub);
    for(i=l;i>=p;i--)
      str[i+subl]=str[i];
    for(i=0;i<subl;i++)
      str[p+i]=sub[i];
    printf("After insertion %s\n",str);
    return 0;
  }
  /*output
  */                      
