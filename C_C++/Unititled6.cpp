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
};
istream &operator>>(istream& in,phanso &a){
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
int phanso::toigian(int tu,int mau){
    if(mau==0)return tu;
    return toigian(mau,tu%mau);
}
int main(){
    phanso a;
    int x;
    cin>>a;
    x=a.toigian(a.gettu(),a.getmau());
a.setmau(a.getmau()/x);
a.settu(a.gettu()/x);
cout<<a;
return 0;
}