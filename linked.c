#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//name字符串长度
#define SIZE 45

//定义数据结构
struct student {
   char name[SIZE];
   int age;
   struct student * next;
};

//定义复类型
typedef struct student * STU;


int main(){
   //初始化数据结构
   STU head=NULL,current,prev;
   int i;
   for(i=0;i<10;i++){
        current=(STU)malloc(sizeof(struct student));
      if(head==NULL){
        head=current;
      }else{
        prev->next=current;     
      }
      strcpy(current->name,"ruansheng");
      current->age=i;
      prev=current;
   }   
 
   //打印输出
   if(head==NULL){
      printf("No data\n");
   }else{
      printf("Here is the movie list:\n");
   }
   
   current=head;
   while(current!=NULL){
      printf("name:%s,age:%d\n",current->name,current->age);
      current=current->next;
   }

   //释放内存
   current=head;
   while(current!=NULL){
      free(current);
      current=current->next;
   }
   
   printf("Bye!\n");
   return 0;
}
