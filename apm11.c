 #include<stdio.h>
 #include<string.h>
 #include<ctype.h>
   void convert(char str[]){
   int i;
   for(i=0;str[i]!='\0';i++)
         str[i]=tolower(str[i]);
   printf("After conversion: %s",str);
   
  }
  int main(){
    char str1[20],str2[20];
    int c;
    printf("Enter the 1st string:\n ");
    scanf("%s",str1);
    printf("Enter the 2nd string:\n ");
    scanf("%s",str2);
    printf("After comparison\n");
    c=strcmp(str1,str2);
    if(c==0)
          printf("Two strings are same\n");
    else
          printf("Strings are different\n");
    strcat(str1,str2);
    printf("After Concatenation:%s\n",str1);
     convert(str1);
    return 0;
  }
  /*output
    hi
    */

