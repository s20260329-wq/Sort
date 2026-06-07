//快速排序
#include<stdio.h> 
int  main(){
	int n=0, i, temp, min=0, max=0; //数据个数,循环变量,接受从键盘录入的数据,最小最大值,减少循环次数 
	int arr[100]={0};
	printf("请选择你要输入几个数据");
    scanf("%d",&n);
    //输入 
    for(i=0;i<n;i++){
    	scanf("%d",&temp);
    	arr[temp]++;
    	if(temp>max) max=temp;
    	else if(temp<min) min=temp;
	} 
	//输出
	for(i=min;i<=max;i++){
		while(arr[i]){//控制输出几次 
			printf("%d ",i);
			arr[i]--;
		}
	} 
} 
