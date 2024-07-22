#include<bits/stdc++.h>
using namespace std;
void nhapmang(int h,int arr[]){
	for (int i=0;i<h;++i){
		scanf("%d",&arr[i]);
	}
}
void swap(int &a,int &b){
	int temp;
	temp=a;
	a=b;
	b=temp;
}
int sogach(int n,int arr[]){
	
	
	int max=arr[n-1];
	int cout=1;
	for(int i=n-2;i>=0;i--){
		cout++;
		if(max==1){
			return cout;
		}
		if(arr[i]<max){
			max=arr[i];
			continue;
		}
		max-=1;
		
	}
	
}
bool cmp(int a,int b){
return a>b;
}
int  main(){
	int h;
	scanf("%d",&h);
	printf("\n");
	int arr[h];
	nhapmang(h,arr);
	sort(arr,arr+h);
	printf("%d",sogach(h,arr));
	return 0;
	
}
