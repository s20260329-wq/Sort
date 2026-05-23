#include<stdio.h>
//堆排序三个参数需要记好
void adjust(int* arr, int root, int len) {
	int temp = arr[root];
	int child = root * 2;//先乘以2因为完全二叉树的左子树一定存在
	while (child <= len) {
		//判断右子树和child的指向
		if (child < len && arr[child] < arr[child + 1]) {
			child++;
		}
		//与根节点比较大小
		if (temp >= arr[child]) {
			break;//以他为根节点的树已经成堆无需操作,因为是从前往后操作的
		}
		//索引里面不能写root,因为不止只比较一层
		arr[child / 2] = arr[child];
		child = child * 2;
	}
	arr[child / 2] = temp;
}
void swap(int arr[], int a, int b) {
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}
//堆排序真正函数,其实是控制外循环
//这个函数分为建堆过程和排序过程,起来需要初始化建一下堆,以后排完再建
//初始化建堆需要对全部元素进行操作,后续建好堆,排完序只需要对第一个元素进行操作就行了,所以for循环分开写
void heapSoar(int arr[], int len) {
	for (int i = len / 2; i > 0; i--) {
		adjust(arr, i, len);
	}
	for (int i = len; i > 1; i--) {
		swap(arr, 1, i);
		adjust(arr, 1, i - 1);
	}
}
int main() {
	int arr[] = { -1,47,35,60,95,77,15,18 };
	heapSoar(arr, sizeof(arr)/4 - 1);
	for (int i = 1; i < sizeof(arr)/4; i++) {
		printf("%d ", arr[i]);
	}
}

