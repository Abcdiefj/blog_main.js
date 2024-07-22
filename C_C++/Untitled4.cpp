
#include<bits/stdc++.h>

using  namespace std;
class connguoi{
private :
string ho_ten;
double age;
string adress;

public:static string kamenraider;
friend void nhau();
friend  void dieuchinh(string&);
connguoi();
void an();
void uong();
void ngu(int hours);
double Getage(double);
void them(string ho_ten,int age,string adress){
	this->adress=adress;
	this->age=age;
	this->ho_ten=ho_ten;
}
void xuat();
void nhap();
~connguoi();
};
void nhau(){
	cout<<"nhau coi";
};
string connguoi::kamenraider="hensin";
double connguoi::Getage(double a){
	return this->age=a;
}
connguoi::~connguoi(){
	cout<<"ham het thuc";
}
connguoi::connguoi(){
	cout<<"ham khoi tao"<<endl;
}
void connguoi::an(){
cout<<"dffsdfsd";
	};
   void connguoi::nhap(){
	cin>>this->age;
	cin>>this->ho_ten;
	cin>>this->adress;
   };
	void connguoi::xuat(){
		cout<<this->adress;
		cout<<this->age;
		cout<<this->ho_ten;
	}
	void dieuchinh(string &a){

stringstream ss(a);
string tmp="";
string tokent;
while(ss>>tokent){
   tmp+=toupper(tokent[0]);
   for(int i=1;i<tokent.length();i++){
	tmp+=tolower(tokent[i]);
   }
   tmp+=" ";
};
tmp.erase(tmp.length()-1);
cout<<tmp;
	}
int main(){
	

string a;
getline(cin,a);
dieuchinh(a);

	return 0;
}
