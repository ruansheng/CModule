
/**
* 冒泡排序
*/
#include<stdio.h>
#define MAX 7

void sort(int *array,int len);
void display(int *array,int len);

int main(void){
        int array[MAX]={5,3,6,4,1,7,2};
        display(array,MAX);
        sort(array,MAX);
        display(array,MAX);     
        return 0;
}

/**
* 排序
*/
void sort(int *array,int len){
        int i,j,t;
        for(i=0;i<len;i++){
                for(j=0;j<len-i-1;j++){
                        if(array[j]>array[j+1]){
                                t=array[j];
                                array[j]=array[j+1];
                                array[j+1]=t;           
                        }
                }
        }
}

/**
* 打印输出
*/
void display(int *array,int len){
        int i;
        for(i=0;i<len;i++){
                printf("%d ",array[i]);
        }
        printf("\n");
}
