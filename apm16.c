 #include<stdio.h>
   struct student{
     char name[20];
     int id;
     float salary;
     char department[20];
   }stud[10];
   int i=0;
   void input(){
    printf("Enter name:\n");
    scanf("%s",stud[i].name);
    printf("Enter id:\n");
    scanf("%d",&stud[i].id);
    printf("Enter salary:\n");
    scanf("%f",&stud[i].salary);
    printf("Enter department:\n");
    scanf("%s",stud[i].department);
    i++;
  }
  void display(){
    printf("Name\t\t\tId\t\t\tSalary\t\t\tDepartment\n");
    for(int j=0;j<i;j++){
  
      printf("%s\t\t\t%d\t\t\t%0.2f\t\t\t%s\n",stud[j].name,stud[j].id,stud[j].salary,stud[j].department);
    }
  }
  void update(){
    int id,j,found=0;
    printf("enter the id :\n");
    scanf("%d",&id);
    for(j=0;j<=i;j++){
      if(stud[j].id == id){
       printf("enter name:");
scanf("%s",stud[j].name);
        printf("Enter id:\n");
        scanf("%d",&stud[j].id);
        printf("Enter salary:\n");
        scanf("%f",&stud[j].salary);
        printf("Enter department:\n");
        scanf("%s",stud[j].department);
        int found=1;
       return;
        }
    }
    if(found==0){
            printf("Id not found\n");
            return ;
        }
  
  }
  int main(){
    int c;
    do{
      printf("1.input\n2.display\n3.update\n4.exit\n");
      scanf("%d",&c);
      switch(c){
        case 1:
          input();
          break;
          case 2:
          display();
          break;
        case 3:
          update();
          break;
        case 4:
         printf("exit\n");
          break;
        default:
          printf("invalid\n");
          break;
      }
    }while(c!=4);
    return 0;
  }

