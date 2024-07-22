#include<bits/stdc++.h>
using namespace std;
class khachhang;
class donhang;
class suabot{
    private:
string mahang="001";
string tenhang_suabot="sữa bột";
string trongluong="100g";
string NSX="1/1/2024";
string NHH="1/1/2025";
string adressSX="1@ luong dinh cua,p21,tanbinh,tphcm";
int gianhap=100;
int giaban_suabot=150;
int thung=giaban_suabot*6-giaban_suabot*6*(3/100);
friend class danhsachhang;

public:
int soluongsuabot;
int getgiaban_suabot(){
return this->giaban_suabot;
};
int getthung(){
return this->thung;
};
int sothung_suabot(int);
int solon_suabot(int );
};
class suaphasan{
private:
string  dungtich="100ml";
string mahang="002";
string tenhang_suaphasan="sữa pha sẵn";
string NSX="1/1/2024";
string NHH="1/1/2025";
string adressSX="1@ luong dinh cua,p21,tanbinh,tphcm";
int gianhap=200;
int giaban_suaphasan=250;
int thung=giaban_suaphasan*6*8-giaban_suaphasan*48*(5/100);
friend class danhsachhang;

public:
int soluongsuaphasan;
int getgiaban_suaphasan(){
    return this->giaban_suaphasan;
};
int getthung(){
return this->thung;
};
int sothung_suaphasan(int);
int solon_suaphasan(int );
};
class suadac{
     private:
string mahang="003";
string tenhang_suadac="sữa đặc";
string trongluong="100g";
string NSX="1/1/2024";
string NHH="1/1/2025";
string adressSX="1@ luong dinh cua,p21,tanbinh,tphcm";
int gianhap=300;
int giaban_suadac=350;
int thung=giaban_suadac*4-giaban_suadac*4*(5/100);
friend class danhsachhang;

public:
int soluongsuadac;
int getgiaban_suadac(){
return this->giaban_suadac;
};
int getthung(){
return this->thung;
};
int sothung_suadac(int);
int solon_suadac(int );
};

class khachhang:public suabot,public suadac,public suaphasan{
    private:
  long long sdt;
  string tenkhachhang;
  string adress;
 string lever;
friend  class donhang;
public:
string gettenkhachhang(){
return this->tenkhachhang;
};
string getlever(){
    return this->lever;
}
long long  getsdt(){
    return this->sdt;
}
 friend istream &operator >>(istream& in,khachhang &a);
friend ostream &operator <<(ostream& out,khachhang a);
};

class danhsachhang{
public:
void update1(suadac&,int);
void update2(suaphasan&,int);
void update3(suabot&,int); 
void sapxep(suadac,suabot,suaphasan);
};

class danhsachkhachhang{
    private:
    vector<khachhang> kh;
    public:
    vector<khachhang> &getdanhsach(){
        return kh;
    };
    void themkhachhang(khachhang a){
    for(khachhang &x:kh){
        if(a.getsdt()==x.getsdt()){
        cout<<"so dt da co";
        };
    }
    kh.push_back(a);
    };
    void xoakhachhang(long long b){
   for (auto it = kh.begin(); it != kh.end(); it++) {
            if (it->getsdt() == b) {
                kh.erase(it);
                cout << "Xoa khach hang thanh cong!" << endl;
                return;
            }
        }
    cout<<"xoa khong thanh cong";
    };
     void suakhachhang(khachhang c){
for(auto &x:kh){
if(c.getsdt()==x.getsdt())
{
    x=c;
}}
};
//    khachhang timKhachHangThuongXuyen(vector<donhang >& danhSachDonHang ) {
//         unordered_map<long long, int> soLanMua;
//         for (donhang& xr : danhSachDonHang) {
//             soLanMua[xr.getsdt()]++;
//         }

//         long long  maxSoDT = 0;
//         int maxSoLanMua = 0;
//         for (auto& pair : soLanMua) {
//             if (pair.second > maxSoLanMua) {
//                 maxSoDT = pair.first;
//                 maxSoLanMua = pair.second;
//             }
//         }

//         for (khachhang& kh1 : kh) {
//             if (kh1.getsdt() == maxSoDT) {
//                 return kh1;
//             }
//         }
//         return khachhang(); // Trường hợp không tìm thấy khách hàng
//     }

//     void xuatDanhSach() {
//         cout << "Danh sach khach hang:" << endl;
//         for (khachhang& kh1 : kh) {
//             cout<<kh1.gettenkhachhang()<<endl;
//             cout<<kh1.getlever()<<" "<<kh1.getsdt();
//             cout << "---------------------------------------" << endl;
//         }
//     }
  };
  class donhang:public suadac,public suaphasan,public suabot,public khachhang{
    public:
long long sdt;
    long long tongtien;
    long long chietkhau;
    long long thanhtien;
    time_t orderDate;

    // Getters and setters (consider adding for encapsulation)

    void calculateDiscount( khachhang customer,  suabot mp, int mpQuantity,int tonglonsuabot,
                            suaphasan pmm, int pmmQuantity,int tonglonsuaphasan, suadac cm, int cmQuantity,int tonglonsuadac) {
        tongtien = mpQuantity * mp.getgiaban_suabot() + pmmQuantity * pmm.getgiaban_suaphasan() +
                     cmQuantity * cm.getgiaban_suadac();
        chietkhau = 0;

        if (customer.getlever()== "VIP") {
             chietkhau += tongtien * 5 / 100; // 5% discount for VIP
        }

        chietkhau += mpQuantity * mp.sothung_suabot(tonglonsuabot) * 3 / 100 + // Bulk discount for Milk Powder
                    cmQuantity * cm.sothung_suadac(tonglonsuadac) * 5 / 100 +  // Bulk discount for Condensed Milk
                    pmmQuantity * pmm.sothung_suaphasan(tonglonsuaphasan) * 5 / 100;   // Bulk discount for Pre-Made Milk
    }

    void calculateFinalPrice() {
        thanhtien = tongtien - chietkhau;
    }

    void printReceipt() const {
        cout << "Order details:" << endl;
        cout << *this; // Use overloaded operator<< for Customer
        cout << "Order date: " << ctime(&orderDate) << endl;
        cout << "Total price: " << tongtien<< endl;
        cout << "Discount: " << chietkhau << endl;
        cout << "Final price: " << thanhtien << endl;
    }
};
  class danhsachdonhang:public khachhang,public donhang{
private:
vector<donhang> dh;
public:
vector<donhang> &getdanhsachdonhang(){
    return dh;
};
void themdonhang(donhang a){
    
for(donhang &x:dh){
if(x.getsdt()==a.getsdt()){
    cout<<"don hang da co";
     return;
};
};
dh.push_back(a);
};
   void xoadonhang(long long b){
   for (auto it = dh.begin(); it != dh.end(); it++) {
            if (it->getsdt() == b) {
                dh.erase(it);
                cout << "Xoa don hang thanh cong!" << endl;
                return;
            }
        }
    cout<<"xoa khong thanh cong";
    };
    void suadonhang(donhang c){

for(auto &x:dh){
if(c.getsdt()==x.getsdt())
{
    x=c;
}}
};
void sapxepsdt(vector<donhang> dh1){
    long long arr[dh1.size()];
for(int i=0;i<dh1.size();i++){
arr[i]=dh1[i].thanhtien;
}
sort(arr,arr+dh1.size());
cout<<endl;
cout<<"sdt da duoc sap xep :";
for(int i=0;i<dh1.size();i++){
    cout<<arr[i]<<endl;
}
};
void sapxepthanhtien(vector<donhang> dh2){
    long long arr[dh2.size()];
for(int i=0;i<dh2.size();i++){
arr[i]=dh2[i].thanhtien;
}
sort(arr,arr+dh2.size());
cout<<endl;
cout<<"thanh tien da duoc sap xep :";
for(int i=0;i<dh2.size();i++){
    cout<<arr[i]<<endl;
}
};
  };

int suabot::sothung_suabot(int a){
return a/6;
};
int suaphasan::sothung_suaphasan(int a){
return a/48;
};
int suadac::sothung_suadac(int a){
return a/4;
};
int suabot::solon_suabot(int b){
return b%6;
};
int suaphasan::solon_suaphasan(int b){
return b%48;
};
int suadac::solon_suadac(int b){
return b%4;
};
void danhsachhang::update1(suadac& x,int y){
    x.giaban_suadac=y;
};
void danhsachhang::update2(suaphasan& x,int y){
x.giaban_suaphasan=y;
};
void danhsachhang::update3(suabot& x,int y){
x.giaban_suabot=y;
};
void danhsachhang::sapxep(suadac x,suabot y,suaphasan z){
int arr[4];
arr[0]=x.giaban_suadac;
arr[1]=y.giaban_suabot;
arr[2]=z.giaban_suaphasan;
sort(arr,arr+3);
cout<<endl;
cout<<"gia ban da duoc sap xep :";
for(int i=0;i<3;i++){
    cout<<arr[i]<<endl;
}
};

istream &operator >>(istream& in,khachhang &a){
cout<<"nhap so dien thoai :";
in>>a.sdt;
cout<<"nhap ten :";

in>>a.tenkhachhang;cin.ignore();
cout<<"nhap dia chi :";
in>>a.adress;cin.ignore();
cout<<"ban la khach vip hay nomal ?(VIP)";
in>>a.lever;cin.ignore();
cout<<"so luong sua bot:";
in>>a.soluongsuabot;
cout<<"so luong sua pha san:";
in>>a.soluongsuaphasan;
cout<<"so luong sua dac:";
in>>a.soluongsuadac;
return in;}
 ostream &operator <<(ostream& out,khachhang a)
 {
    out<<a.sdt<<" "<<a.tenkhachhang<<" "<<a.adress<<endl;
    out<<"khach :"<<"\""<<a.lever<<"\""<<endl;
    return out;
 };


int main(){
  
    khachhang levi;
    suabot levi_suabot;
    suaphasan levi_suaphasan;
    suadac levi_suadac;
    donhang levi_donhang;
    danhsachhang levi_danhsachhang;
    danhsachkhachhang levi_danhsachkhachhang;
    danhsachdonhang levi_danhsachdonhang;
    cin>>levi;
    
      string doigia;
    cout<<"ban muon doi gia khong ?(yes/no)";
    cin>>doigia;bool cases=true;
    if(doigia=="yes"){
        while(cases==true){
    cout<<"1.gia suabot"<<endl;
    cout<<"2.gia suaphasan"<<endl;
    cout<<"3.gia suadac"<<endl;
    cout<<"4.thoat"<<endl;
    int gia;
    cin>>gia;
    
    switch (gia)
    {

    case 1:
    int x;
        cout<<"gia muon doi :";
        cin>>x;
        levi_danhsachhang.update3(levi_suabot,x);
        break;
    case 2:
    int y;
    cout<<"gia muon doi :";
        cin>>y;
        levi_danhsachhang.update2(levi_suaphasan,y);
        break;
    case 3:
    int z;
    cout<<"gia muon doi :";
        cin>>z;
        levi_danhsachhang.update1(levi_suadac,z);
        break;
    default:
    cases=false;
        break;
    };
    };};
    levi_danhsachhang.sapxep(levi_suadac,levi_suabot,levi_suaphasan);
 levi_donhang.calculateDiscount(levi,levi_suabot,levi_suabot.solon_suabot(levi_suabot.soluongsuabot),levi_suabot.soluongsuabot,
 levi_suaphasan,levi_suaphasan.solon_suaphasan(levi_suaphasan.soluongsuaphasan),levi_suaphasan.soluongsuaphasan,
 levi_suadac,levi_suadac.solon_suadac(levi_suadac.soluongsuadac),levi_suadac.soluongsuadac);
 levi_donhang.calculateFinalPrice();
 levi_donhang.printReceipt();
int sdtkhachhang;
vector<khachhang> kh=levi_danhsachkhachhang.getdanhsach();
vector<donhang> dh=levi_danhsachdonhang.getdanhsachdonhang();
 khachhang levi_1;
 khachhang levi_2;
 int xoakhachhang;int suakhachhang;
 while (cases==false){

 
cout<<"1.them khach hang"<<endl;;
cout<<"2.xoa khach hang"<<endl;
cout<<"3.sua khach hang"<<endl;
cout<<"4.khach hang thuong xuyen"<<endl;
cout<<"5.thoat"<<endl;
cin>>sdtkhachhang;
switch(sdtkhachhang)
{
case 1:

cin>>levi_1;
levi_danhsachkhachhang.themkhachhang(levi_1);
    break;
case 2:
cout<<"nhap so DT:";
cin>>xoakhachhang;
if(xoakhachhang==levi.getsdt()){
levi_danhsachkhachhang.xoakhachhang(xoakhachhang);
}
break;
case 3:
cout<<"nhap so DT:";
cin>>suakhachhang;
cout<<endl;
cin>>levi_2;
levi_danhsachkhachhang.suakhachhang(levi_2);
break;
case 4:
//  levi_danhsachkhachhang.timKhachHangThuongXuyen(dh);
   
break;
default:
cases=true;
    break;
};};

int sdtkhachhang2;
 khachhang levi_3;
 donhang levi_2_donhang;
   suabot levi_2_suabot;
    suaphasan levi_2_suaphasan;
    suadac levi_2_suadac;
 khachhang levi_4;
 donhang levi_3_donhang;
 int xoadonhang;int suadonhang;
 while (cases==true){

 
cout<<"1.them don hang"<<endl;;
cout<<"2.xoa don hang"<<endl;
cout<<"3.sua don hang"<<endl;
cout<<"4.thoat"<<endl;
cin>>sdtkhachhang2;
switch(sdtkhachhang2)
{
case 1:
cin>>levi_3;
 
 levi_2_donhang.calculateDiscount(levi,levi_2_suabot,levi_2_suabot.solon_suabot(levi_2_suabot.soluongsuabot),levi_2_suabot.soluongsuabot,
 levi_2_suaphasan,levi_2_suaphasan.solon_suaphasan(levi_2_suaphasan.soluongsuaphasan),levi_2_suaphasan.soluongsuaphasan,
 levi_2_suadac,levi_2_suadac.solon_suadac(levi_2_suadac.soluongsuadac),levi_2_suadac.soluongsuadac);
levi_danhsachdonhang.themdonhang(levi_2_donhang);
    break;
case 2:
cout<<"nhap so DT:";
cin>>xoadonhang;
if(xoakhachhang==levi.getsdt()){
levi_danhsachdonhang.xoadonhang(xoadonhang);
}
break;
case 3:
cout<<"nhap so DT:";
cin>>suadonhang;
cout<<endl;
cin>>levi_4;
levi_danhsachdonhang.suadonhang(levi_3_donhang);
break;

default:
cases=false;
    break;
};};
cout<<"sap xep khach hang theo sdt:";
levi_danhsachdonhang.sapxepsdt(dh);
cout<<"sap xep khach hang theo thanh tien:";
levi_danhsachdonhang.sapxepthanhtien(dh);
return 0;
}
