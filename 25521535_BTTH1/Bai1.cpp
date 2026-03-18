#include <iostream>
#include <limits>
#include <cmath>
using namespace std;

struct PhanSo {

    int tu;
    int mau;

// Khởi tạo phân số, mặc định là 0/1 nếu không truyền tham số
    PhanSo(int t = 0, int m = 1){
        tu = t;
        mau = m;
        RutGon();
    }
// Nhập vào 2 số nguyên a và b và trả ước chung lớn nhất của 2 số
    int gcd(int a,int b) {
        if(b == 0) return a;
        return gcd(b, a % b);
    }
// Nhập dữ liệu tử số và mẫu số, gán giá trị cho biến 'tu' va 'mau', tự động kiểm tra tính hợp lệ (nếu không hợp lệ sẽ bắt nhập lại) và gọi hàm rút gọn phân số
    void Nhap() {
        while (true) {
            cout << "Nhap tu va mau cua phan so (cach nhau bang dau cach): ";
            if (cin >> tu >> mau) {
                if (mau != 0) {
                    break; 
                } else {
                    cout << "Loi: Mau so phai khac 0!" << endl;
                }
            } else {
                cout << "Loi: Vui long chi nhap so nguyen!" << endl;
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            }
        }
        RutGon(); 
    }
//
    void RutGon() {
        int ucln = gcd(abs(tu),abs(mau));
        tu /= ucln;
        mau /= ucln;
        if(mau < 0) {
            tu = -tu;
            mau = -mau;
        }
    }
//
    void Xuat() {
        if(mau == 1) {
            cout << tu << "\n";
        }
        else {
            cout << tu << "/" << mau << "\n";
        }
    }
};

int main() {
    PhanSo ps1;
    ps1.Nhap();
    cout << "Phan so da rut gon la: ";
    ps1.Xuat();
}