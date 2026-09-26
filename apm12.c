   #include<stdio.h>
   int main(){
     int i,f=1,len=0;
     char str[100],rev[20];
    printf("Enter the string:");
    scanf("%s",str);
     for(int i=0;str[i]!='\0';i++)
       len++;
     for(i=0;i<len;i++)
      rev[i]=str[len-1-i];
    rev[i]='\0';
     printf("Reverse of string %s\n",rev);
     for(i=0;i<len;i++){
       if(str[i]!=rev[i]){
         f=0;
         break;
        }
      }
      if(f==1){
        printf("it is palindrome\n");
      }
      else
          printf("it is not palindrom\n");
  return 0;
  }
  /*output
  Enter the string:malayalam
  Reverse of string malayalam
  it is palindrome
  
    */
           
