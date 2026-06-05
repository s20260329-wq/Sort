#include <stdio.h>
void haxiInser(int arr[], int n, int number) //数组,长度,存的数据
{
	//确定p
	int p = n; //Hey=Hey%p
	//映射
	int i = number % p;
	if (arr[i] != 0) {
		//冲突处理
		while (arr[i]!=0) {
			i = (i + 1) % (n+1);//超出数组下标从零开始
		}
		arr[i] = number;
	}
	else if (arr[i] == 0||arr[i]==-1) {//-1为删除标记
		arr[i] = number;
	}
}
void Inser(int n, int arr[], int p) //n为哈希表的容量,p为元素的多少
{
	int i = p, number;//循环变量,接受键盘数据变量
	printf("请输入元素");
	while (i--) {
		scanf_s("%d", &number);
		haxiInser(arr, n, number);
	}

}
//查找函数
int find(int arr[], int n, int number)//除留余数法得到的数组,数的多少,要删除的数,返回值为数组下标
{

	//映射
	int i = number % n;
	//查找
	while (arr[i] != 0 && arr[i] != number) {
		i = (i + 1) % n ;
	}
	if (arr[i] == 0) return -1;
	else return i;
	
}
//删除函数
void delet(int arr[], int n, int number) //除留余数法得到的数组,数的多少,要删除的数
{
	//确定p
	int p = n;
	//映射
	int i = number % p;
	//查找
	int j = find(arr, n, number);
	if (j == -1) return;//没找到
	else {
		arr[j] = -1;
	}
}
int main() {
	int arr[11] = { 0};
	//装入
	Inser(11, arr, 8);
	//输出检测
	for (int i = 0; i <=10; i++) {
		printf("%d ", arr[i]);
	}
	printf("%d", find(arr,11,78));
	printf("%d", find(arr, 11, 99));
	delet(arr, 11, 12);
	printf("%d", find(arr, 11, 36));
}