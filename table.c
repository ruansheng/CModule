#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/**
* 设置表头
* col 表格列数
*/
void setTableHeader(int col,char titles[][20]){
	if(col<=0){
		printf("param col must > 0\n");
		exit(1);
	}
	//输出上横线
	int i;
	for(i=1;i<=col;i++){
		int titleLen=strlen(titles[i-1]);
		int j;
		for(j=1;j<titleLen+6;j++){
			printf("-");
		}
		if(i==col){
			printf("\n");
		}
	}

	//输出中间内容
	printf("|");
	int k;
	for(k=0;k<col;k++){
		int titleLen=strlen(titles[k]);
		int j;
		printf("  %s  ",titles[k]);
		printf("|");
	}
	printf("\n");
	
	//输出下横线
        int n;
        for(n=1;n<=col;n++){
               int titleLen=strlen(titles[n-1]);
               int j;
               for(j=1;j<titleLen+6;j++){
                        printf("-");
               }
               if(n==col){
                        printf("\n");
               }
        }

	
}

/**
* 在表格中添加一行
*/
void addTableRow(){
	
}


int main(){
	int col=5;
	char titles[][20]={"id","name","age","addr","phonenumber"};
	setTableHeader(col,titles);
	return 0;
}
