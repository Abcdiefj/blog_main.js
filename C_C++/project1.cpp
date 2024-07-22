#include<bits/stdc++.h>
using namespace std;
class lesson{
public:
int toan;
int ly;
int hoa;
int sinh;
int van;
int su;
int dia;
};
class thongtin{
    public:
    string sbd;
string ho_ten;
string adress;
string khoithi;
friend istream &operator >>(istream& in,thongtin &a){
cout<<"nhap ho va ten :";
getline(in,a.ho_ten);
cin.ignore();
cout<<"nhap sbd:";
in>>a.adress;
cout<<"nhap adress:";
in>>a.adress;
cout<<"nhap khoi thi :";
in>>a.khoithi;
return in;
};
friend ostream &operator <<(ostream& out,thongtin b){
    out<<"ho va ten :"<<b.ho_ten<<" "<<"sbd:"<<b.sbd<<endl;
    out<<"dia chi :"<<b.adress<<" "<<"khoi thi:"<<b.khoithi<<endl;
    return out;
};
string getkhoithi(){
    return khoithi;
}
// virtual float  getdtb()=0;
};
class thisinhkhoiA:public lesson,public thongtin {

public:

int  getdiemtoan(){
    return this->toan;
};
int  getdiemly(){
    return this->ly;
};
int  getdiemhoa(){
    return this->hoa;
}

void nhapdiem(){
    cout<<"nhap diem toan:";
    cin>>this->toan;
    cout<<"nhap diem ly:";
    cin>>this->ly;
    cout<<"nhap diem hoa:";
    cin>>this->hoa;
}
float getdtb(thisinhkhoiA a){
return (a.getdiemhoa()+a.getdiemly()+a.getdiemtoan())/3;
};
};
class thisinhkhoiB:public lesson,public thongtin{
public:

int  getdiemtoan(){
    return this->toan;
};
int  getdiemsinh(){
    return this->sinh;
};
int  getdiemly(){
    return this->ly;
};
void nhapdiem(){
    cout<<"nhap diem toan:";
    cin>>this->toan;
    cout<<"nhap diem ly:";
    cin>>this->ly;
    cout<<"nhap diem sinh:";
    cin>>this->sinh;
}
float getdtb(thisinhkhoiB b){
return (b.getdiemsinh()+b.getdiemly()+b.getdiemtoan())/3;
};
};

class thisinhkhoiC:public lesson,public thongtin{
public:

int  getdiemvan(){
    return this->van;
};
int  getdiemsu(){
    return this->su;
};
int  getdiemdia(){
    return this->dia;
};
void nhapdiem(){
    cout<<"nhap diem van:";
    cin>>this->van;
    cout<<"nhap diem su:";
    cin>>this->su;
    cout<<"nhap diem dia:";
    cin>>this->dia;
}
float getdtb(thisinhkhoiC c){
return (c.getdiemvan()+c.getdiemsu()+c.getdiemdia())/3;
};
};


class sapxep: public thisinhkhoiA,public thisinhkhoiB ,public thisinhkhoiC{
private:
vector<thongtin> thisinh1;
vector<thongtin> thisinh2;
public:
vector<thongtin> &sapxepkhoi(){
return thisinh1;
}
vector<thongtin> &sapxepdtb(){
return thisinh2;
}
void themthisinh1(thongtin a){
for(auto &x:thisinh1){
   if( x.ho_ten==a.ho_ten)
{
    cout<<"thi sinh da co!"<<endl;
    return;
}
};
thisinh1.push_back(a);
};
void themthisinh2(thongtin a){
for(auto &x:thisinh2){
   if( x.ho_ten==a.ho_ten)
{
    return;
};
thisinh2.push_back(a);
};
};
bool sapxepkhoicon(thongtin a,thongtin b){
   return a.getkhoithi()<b.getkhoithi();
};
void sapxepkhoi(vector<thongtin> sapxep){
    sort(sapxep.begin(),sapxep.end(),sapxepkhoicon);
    for(int i=0;i<sapxep.size();i++){
        cout<<sapxep[i]<<endl;
    };
}
// bool sapxepkhoicon2(thongtin a,thongtin b){
//    return a.getdtb()<b.getdtb();
// };
// void sapxepdtb(vector<thongtin> sapxep){
//     sort(sapxep.begin(),sapxep.end(),sapxepkhoicon2);
//     for(int i=0;i<sapxep.size();i++){
//         cout<<sapxep[i]<<endl;
//     };
// }
};
int main(){
    int x;
  
thongtin hocsinh;thisinhkhoiA hocsinhA;thisinhkhoiB hocsinhB;thisinhkhoiC hocsinhC;
cin>>hocsinh;
cout<<hocsinh;
cout<<"1.sinh vien khoi A"<<endl;
cout<<"2.sinh vien khoi B"<<endl;
cout<<"3.sinh vien khoi C"<<endl;
cin>>x;
switch(x)
{
case 1:

hocsinhA.nhapdiem();
cout<<"diem trung binh la :";
hocsinhA.getdtb(hocsinhA);
    break;
case 2:
hocsinhB.nhapdiem();
cout<<"diem trung binh la :";
hocsinhB.getdtb(hocsinhB);
case 3:
hocsinhC.nhapdiem();
cout<<"diem trung binh la :";
hocsinhC.getdtb(hocsinhC);

default:
    break;

};
}