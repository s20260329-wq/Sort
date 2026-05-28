#include<stdio.h>
#define MAXSIZEOF 100
void merge(int data[], int left, int right,int mind)
{
	int temp [MAXSIZEOF] = {};
	int i = left;
	int j = mind + 1;
	int k = 0;
	while (i <= mind && j <= right) {
		if (data[i] <= data[j])
			temp[k++] = data[i++];
		else
			temp[k++] = data[j++];
	}
	//拼接剩余的值
	if (i > mind) {
		while (j <= right)
			temp[k++] = data[j++];
	}
	else if (j > right) {
		while (i <= mind)
			temp[k++] = data[i++];
	}
	//覆盖原素组
	/*for (int m = left; m <= right; m++) {
		data[m] = temp[m];
	}*/
	for (int m = 0; m <k; m++) {
		data[left+m] = temp[m];
	}

}
void mergeSort(int data[], int left, int right) {
	//先判断能否进行操作,即判断左右指针的大小
	if (left < right) {
		//找到中间点
		int mind = (left + right) / 2;
		//对最左边进行递归调用
		mergeSort(data, left, mind);
		//对右边进行递归调用
		mergeSort(data, mind + 1,right);
		//进行排序操作
		merge(data, left, right, mind);
	}
}
int main() {
	int arr[10] = { 12,3,24,3,4,5,4,6,5,89 };
	mergeSort(arr, 0, 9);
	for (int i = 0; i <10; i++) {
		printf("%d ", arr[i]);
	}
}