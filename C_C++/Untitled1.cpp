#include<bits/stdc++.h>
using namespace std;
class SinhVien {
private:
string name;
int age;
string adress;
string ngaysinh;
public:
SinhVien(){
    this->age=0;
};
~SinhVien(){
    this->age=0;
};
friend istream& operator >>(istream& in,SinhVien &a );
friend ostream& operator <<(ostream& out,SinhVien a);
SinhVien operator ++(){
    int cout=0;
    cout+=1;
    age+=cout;
    return *this;
};
SinhVien operator+(const SinhVien& a){
SinhVien c;
c.age=this->age+a.age;
return c;
}
};
 istream& operator >>(istream& in,SinhVien &a){
cout<<"nhap ten:";in.ignore();
getline(in,a.name);
cout<<"nhap tuoi:";
in>>a.age;
return in;
};
ostream& operator <<(ostream& out,SinhVien a){
cout<<a.name<<" "<<a.age<<endl;
return out;
};
int main(){
    SinhVien x,y,z;
    map<float,class> mp;
   cin>>x;
   cin>>y;
   z= x + y;
   cout<<z;

    
}
