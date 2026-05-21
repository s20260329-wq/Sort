//希尔排序
void XiEr(int arr[],int len){
	//先确定步长 
	int step=len/2;
	while(step>=1){
		for(int i=step;i<len;i++){
			if(arr[i]<arrr[i-step]){
				int temp=arr[i];
				int j=i-step;
				while(j>=0&&arr[i]<arr[j]){
					//让j+step代指上一个为止 
					arr[j+step]=arr[j];
					j-=step;
				}
				arr[j+step]=temp;  
			}
		}
		//step控制条件
		step=step/2; 
	} 
} 
