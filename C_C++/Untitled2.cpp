#include<bits/stdc++.h>
using namespace std;
void swap(int &a,int &b){
	int c;
	c=a;
	a=b;
	b=c;
}
int partition(int arr[],int l,int r){
	int i=l-1;
	int pivot=arr[r];
	for(int j=l;j<r;j++){
		if(arr[j]<=pivot){
			i++;
		swap(arr[i],arr[j]);
		};
		if(j==r-1){
			i++;
			swap(arr[i],arr[r]);
		};
	}return i;};
void quicksoft(int arr[],int l,int r){
if(l>=r) return;
int p=partition( arr,l,r);
	  quicksoft(arr,l,p-1);
	 quicksoft(arr,p+1,r);
}

	


void print(int arr[],int n){
	for(int i=0;i<n;i++){
		printf(" %d",arr[i]);
	};
};
int main(){
	int arr[9]={9,6,4,7,1,4,0,4,5};
	quicksoft(arr,0,8);
	print(arr,9);
	return 0;
}