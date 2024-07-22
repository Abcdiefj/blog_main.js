#include<bits/stdc++.h>
using namespace std;
class phanso{
private:
int tu;
int mau;

public:
phanso(){
    tu=mau=0;
}
int  gettu(){
    return this->tu;
}
int getmau(){
    return this->mau;
}
void settu(int tu){
    this->tu=tu;
}
void setmau(int mau){
    this->mau=mau;
}
int  toigian(int ,int);
phanso(int tu,int mau){
    this->tu=tu;
    this->mau=mau;
};
~phanso(){
}
friend istream &operator>>(istream& in,phanso &a);
friend ostream &operator<<(ostream& out,phanso b);
friend phanso operator+(phanso a,phanso b){
    phanso c;
    c.tu=a.tu*b.mau+a.mau*b.tu;
    c.mau=a.mau*b.mau;
    return c;
}}
istream  &operator>>(istream& in,phanso &a){
    cout<<"nhap tu so :";
    in>>a.tu;
    cout<<"nhap mau so :";
    in>>a.mau;
    return in;
};
ostream &operator<<(ostream& out,phanso b){
    cout<<b.tu<<"/"<<b.mau<<endl;
    return out;
}
  
int main(){
    phanso a,b,c;
    cin>>a;
    cin>>b;
   c=a+b;
cout<<c;
return 0;
}