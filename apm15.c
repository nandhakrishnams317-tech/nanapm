#include<stdio.h>
struct complex{
int real;
int img;
}c[2],s,d;
int main(){
  int i;
  for(i=0;i<2;i++){
    printf("Enter the real and imaginary part:\n");
    scanf("%d %d",&c[i].real,&c[i].img);
  }
 s.real=c[0].real+c[1].real;
 s.img=c[0].img+c[1].img;
 d.real=c[0].real-c[1].real;
 d.img=c[0].img-c[1].img;
 printf("Sum of two complex numbers:%d+%di\n",s.real,s.img);
 printf("Difference of two complex numbers:%d+%di\n",d.real,d.img);

return 0;
}
/*output
Enter the real and imaginary part:
4 10
Enter the real and imaginary part:
2 4
Sum of two complex numbers:6+14i
Difference of two complex numbers:2+6i
*/

