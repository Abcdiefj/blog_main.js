#include <iostream>
#include<iostream>
#include<string>
#include<vector>
#include <ctime>
using namespace std;

enum MonHoc
{
    TOAN,
    LY,
    HOA,
    SINH,
    VAN,
    SU,
    DIA
};

class KhoiNganh;

class HocSinh
{
    private:
        string ma;
        string hoTen;
        char dsDiem[8];

    public:
        HocSinh();
        HocSinh(string, string);
        HocSinh(const HocSinh&);
        ~HocSinh();
    public:
    	string getMa();
    	void setMa(string);
    	string getHoTen();
    	void setHoTen(string);
        char getDiem(MonHoc);
        void setDiem(MonHoc, char);
       bool dangKy(KhoiNganh*);
};
class ThiSinh : public HocSinh
{
    private:
        time_t ngayNopHS;

    public:
    	ThiSinh();
        ThiSinh(HocSinh*);
        ~ThiSinh();
};
class KhoiNganh
{
    private:
    protected:
        vector<ThiSinh*> dsThiSinh;

    public:
        KhoiNganh();
        virtual ~KhoiNganh();
    public:
        bool dangKy(HocSinh*);
        virtual bool kiemTraDiem(HocSinh*) = 0;
};
class KhoiNganhA : public KhoiNganh
{
	private:
		static const char DIEM_PASS = 25;
		static const char DIEM_MIN = 7;
		
	public:
		KhoiNganhA();
		~KhoiNganhA();
		
	public:
		 bool kiemTraDiem(HocSinh*);
};


int main(int argc, char** argv)
{
    KhoiNganh *khoiNganhA = new KhoiNganhA();

    HocSinh *hs = new HocSinh("hs001", "Nguyen Van 1");
    hs->setDiem(TOAN, 8);
    hs->setDiem(LY, 8);
    hs->setDiem(HOA, 9);
    hs->dangKy(khoiNganhA);

	hs = new HocSinh("hs002", "Nguyen Van 2");
    hs->setDiem(TOAN, 6);
    hs->setDiem(LY, 10);
    hs->setDiem(HOA, 9);
    hs->dangKy(khoiNganhA);

	hs = new HocSinh("hs003", "Nguyen Van 3");
    hs->setDiem(TOAN, 7);
    hs->setDiem(LY, 8);
    hs->setDiem(HOA, 5);
    hs->dangKy(khoiNganhA);

    khoiNganhA->dangKy(hs);

    delete khoiNganhA;
    return 0;
}
HocSinh::HocSinh() : ma(0), hoTen(""), dsDiem{0}
{
}

HocSinh::HocSinh(string ma, string hoTen) : ma(ma), hoTen(hoTen), dsDiem{0}
{
}

HocSinh::HocSinh(const HocSinh &hs)
{
	this->ma = hs.ma;
	this->hoTen = hs.hoTen;
	copy(begin(hs.dsDiem), std::end(hs.dsDiem), std::begin(this->dsDiem));
}

HocSinh::~HocSinh()
{
}

string HocSinh::getMa()
{
    return this->ma;
}
void HocSinh::setMa(string ma)
{
    if (ma.length() > 0)
    {
        this->ma = ma;
    }
}
string HocSinh::getHoTen()
{
    return this->hoTen;
}
void HocSinh::setHoTen(string hoTen)
{
    if (hoTen.length() > 0)
    {
        this->hoTen = hoTen;
    }
}

char HocSinh::getDiem(MonHoc monHoc)
{
    return this->dsDiem[monHoc];
}

void HocSinh::setDiem(MonHoc monHoc, char diem)
{
    if (0 <= diem && diem <= 10)
    {
        this->dsDiem[monHoc] = diem;
    }
}

bool HocSinh::dangKy(KhoiNganh* khoiNganh)
{
    if (khoiNganh != NULL)
    {
        return khoiNganh->dangKy(this);
    }
    return false;
}
KhoiNganh::KhoiNganh()
{
}

KhoiNganh::~KhoiNganh()
{
	  for (auto ts = this->dsThiSinh.cbegin(); ts != this->dsThiSinh.cend(); ts++)
    {
        delete *ts;
    }
}
bool KhoiNganh::dangKy(HocSinh *hs)
{
    if (kiemTraDiem(hs))
    {
        this->dsThiSinh.push_back(new ThiSinh(hs));
        return true;           
    }
    return false;
}
KhoiNganhA::KhoiNganhA()
{
}

KhoiNganhA::~KhoiNganhA()
{
}

bool KhoiNganhA::kiemTraDiem(HocSinh *hs)
{
    if (hs != NULL)
    {
        char dt = hs->getDiem(TOAN);
        char dl = hs->getDiem(LY);
        char dh = hs->getDiem(HOA);
        return dt >= DIEM_MIN
               && dl >= DIEM_MIN
               && dh >= DIEM_MIN
               && (dt + dl + dh) >= DIEM_PASS;

    }
    return false;
}
ThiSinh::ThiSinh()
{
}

ThiSinh::ThiSinh(HocSinh *hs): HocSinh(*hs)
{
	ngayNopHS = time(0);
}

ThiSinh::~ThiSinh()
{
}
