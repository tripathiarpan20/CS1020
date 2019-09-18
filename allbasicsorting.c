#include <stdio.h>

/*int binary_search(int* arr, int key, int start, int end) {
    if(start==end && arr[start] == key) return start;
    else if(start==end && arr[start] != key || start>end) return -1;
    if(start<end) {
        int mid = (start+end)/2;
        if(key==arr[mid]) return mid;
        else if(key<arr[mid]) return binary_search(arr,key,start,mid-1);
        else if(key>arr[mid]) return binary_search(arr,key,mid+1,end);
    }
}*/

/*int partition(int* arr, int start, int end) {
    int key = arr[end];
    int pivot_index = start;
    int i;
    for(i= start; i< end; i++) {
        if(arr[i] < key) {
            int temp = arr[pivot_index];
            arr[pivot_index] = arr[i];
            arr[i] = temp;
            pivot_index++;
        }
    }
    int temp = arr[pivot_index];
    arr[pivot_index] = arr[end];
    arr[end] = temp;
    return pivot_index;
}



void quick_sort(int* arr,int start, int end) {
    if(start==end) return;
    if(start< end) {
        int pivot = partition(arr,start,end);
        quick_sort(arr,start,pivot-1);
        quick_sort(arr,pivot+1,end);
        return;
    }
}*/

void merge(int* arr, int start, int mid, int end) {
    if(start<end) {
        int left[mid-start+1];
        int right[end-mid];
        for(int i=start; i<=mid;i++) {
            left[i-start] = arr[i];
        }
        for(int j=mid+1; j<=end;j++) {
            right[j-mid-1] = arr[j];
        }
        int k=start;
        while(k<=end) {
            int i= 0;
            int j= 0;
            while(i< mid-start+1 && j<end-mid) {
                if(left[i] <= right[j]) {
                    arr[k] = left[i++];
                    k++;
                }
                else if(left[i] > right[j]){
                    arr[k] = right[j++];
                    k++;
                }
            }
            while(i< mid-start+1) {
                arr[k] = left[i++];
                k++;
            }
            while(j<end-mid) {
                arr[k] = right[j++];
                k++;
            }
        }
        
    }
}


void merge_sort(int* arr, int start, int end) {
    if(start<end) {
        int mid = (start+end)/2;
        merge_sort(arr,start,mid);
        merge_sort(arr,mid+1,end);
        merge(arr,start,mid,end);
    }
}


int main() {
	int n;
	scanf("%d",&n);
	if(n==0 || n==1) return 0;
	int arr[n];
	for(int i =0; i<n; i++) {
	    scanf("%d",&arr[i]);
	}
    merge_sort(arr,0,n-1);
	for(int i =0; i<n; i++) {
	    printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}
