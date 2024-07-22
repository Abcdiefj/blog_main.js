#include<bits/stdc++.h>
#include<math.h>
using namespace std;

bool cmp(string a,string  b){
	return a.length()>b.length();
}
int main(){
vector<string> vt={"PHP","c++","Javascript","rush"};

   sort(vt.begin(),vt.end(),cmp);
for(int i=0;i<4;i++){
	cout<<vt[i]<<" ";
}
printf("%4d",12);
string a="mot con vit";
stringstream ss(a);
string tmp;
while(ss>>tmp){
	cout<<tmp<<endl;
}

}
