#include<stdio.h>
#include<ctype.h>
int main(){
  char str[20];
  int i=0;
  printf("Text Analysis Tool");
  printf("Enter the string:\n");
  fgets(str,sizeof(str),stdin);
  while(str[i]!='\0' &&  str[i]!='\n'){
   if(isalpha((unsigned char)str[i])){
    str[i]=tolower(str[i]);
    switch(str[i]){
    case 'a':
        printf("%c-vowel\n",str[i]);
        break;
    case 'e':
        printf("%c-vowel\n",str[i]);
        break;
    case  'i':
        printf("%c-vowel\n",str[i]);
        break;
    case 'o':
        printf("%c-vowel\n",str[i]);
        break;
    case 'u':
        printf("%c-vowel\n",str[i]);
        break;
    default:
        printf("%c-consonant\n",str[i]);
    }}
    else if(isdigit((unsigned char)str[i]))
        printf("%c-number\n",str[i]);
    else
        printf("%c-special\n",str[i]);
    ++i;}
  return 0;
}
/*output
  Text Analysis ToolEnter the string:
anna@12
a-vowel
n-consonant
n-consonant
a-vowel
@-special
1-number
2-number
*/

