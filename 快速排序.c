
//快速排序
//void Soar(int arr[],int left ,int right,int pr){
//	//判断递归结束条件
//	if(left>=right) return ; 
//	//创建临时变量
//	int temp;
//	temp=arr[left];
//	int tempp=pr;
//	while(left!=right){//外循环是控制左右指针进行一定规律移动的循环 
//		 //先移动右指针,碰见的大小的进行交换交换完再移动佐治帧
//		 while(arr[right]>temp){//内循环是控制单一移动的循环 
//		 	right--;
//		 	if(right==left) break; //少了循环判断 
//		 }
//		 arr[left]=temp;
//		 while(arr[left]<temp){
//		 	 left++; 
//		 	 if(right==left) break; 
//		 } 
//	} 
//	//少了填坑 
//	arr[left]=temp; 
//	pr=left;
//	Soar(arr,left-left,right-1,pr);//传递的左右指针是最近两次枢轴的夹角 
//	Soar(arr,left+1,tempp-1,pr);
//} 
#include <stdio.h>
int Exchange(int arr[], int left, int right) {
	int temp;
	temp = arr[left];
	while (left < right) {//外循环是控制左右指针进行一定规律移动的循环 
		while (left < right && (arr[right] > temp || arr[right] == temp)) {
			right--;
			if (right <= left) break;
		}
		arr[left] = arr[right];//少了加加 
		while (left < right &&(arr[left] < temp||arr[left]==temp)) {
			left++;
			if (right <= left) break;
		}
		arr[right] = arr[left];
	}
	arr[left] = temp;
	return left;
}
//真正的快速排序函数
void Soar(int arr[], int left, int right) {
	if (right > left) {
		int pos = Exchange(arr, left, right);
		Soar(arr, left, pos - 1);//处理左区间
		Soar(arr, pos + 1, right);//有区间的边界值和上一个左区间有所联系,保护了大边界值保护值两个小边界值 
	}
}
int main() {
	int arr[11] = { 56,23,82,45,76,69,20,45,93,16,27 };
	Soar(arr, 0, 10);
	int i = 0;
	while (i < 11) {
		printf("%d ", arr[i++]);
	}
}
