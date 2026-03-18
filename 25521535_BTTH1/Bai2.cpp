#include <iostream>
#include <climits>
using namespace std;

struct PhanSo {
    int tu;
    int mau;

    PhanSo(int t = 0, int m = 1){
        tu = t;
        mau = m;
        RutGon();
    }

    int gcd(int a,int b) {
        if(b == 0) return a;
        return gcd(b, a % b);
    }

    int BCNN(int a,int b) {
        return a * b / (gcd(a,b));
    }

    void Nhap() {
        cout << "Nhap tu va mau cua phan so (cach nhau bang dau cach): ";
        if(!(cin >> tu >> mau)) {
            CheckInt();
        }
        if(mau == 0) {
            MauKhacKhong();
        }
        RutGon();
    }

    void RutGon() {
        int ucln = gcd(abs(tu),abs(mau));
        tu /= ucln;
        mau /= ucln;
        if(mau < 0) {
            tu = -tu;
            mau = -mau;
        }
    }

    void Xuat() {
        if(mau == 1) {
            cout << tu << "\n";
        }
        else {
            cout << tu << "/" << mau << "\n";
        }
    }

    void MauKhacKhong() {
        while(mau == 0)
            {
                cout << "Vui long nhap mau khac 0" << "\n";
                Nhap();
            }
    }

    void CheckInt() {
        cout << "Vui long nhap mot so nguyen: " << "\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        Nhap();
    }
    
    void QuyDong(PhanSo &other) {
        int boi = BCNN(mau,other.mau);
        int hs1 = boi/mau;
        int hs2 = boi/other.mau;
        tu *= hs1;
        other.tu *= hs2;
        mau = boi;
        other.mau = boi;
    }

    int SoSanh(PhanSo &other) {
        if(tu > other.tu) return 1;
        if(tu < other.tu) return -1;
        else return 0;
    }

};

int main() {
    PhanSo ps1,ps2;
    ps1.Nhap();
    ps2.Nhap();
    ps1.QuyDong(ps2);
    if(ps1.SoSanh(ps2) == 1) {
        ps1.Xuat();
    }
    else if(ps1.SoSanh(ps2) == -1) {
        ps2.Xuat();
    }
    else {
        cout << "Hai phan so bang nhau" << "\n";
        ps1.Xuat();
    }
}