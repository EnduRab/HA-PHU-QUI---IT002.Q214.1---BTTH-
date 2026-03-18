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
        // Tự động gọi hàm rút gọn phân số
        RutGon();
    }
    // Nhập vào 2 số nguyên a và b và trả về ước chung lớn nhất của 2 số (sử dụng thuật toán Euclid)
    int gcd(int a,int b) {
        if(b == 0) return a;
        return gcd(b, a % b);
    }
    // Nhập dữ liệu tử số và mẫu số, gán giá trị cho biến 'tu' va 'mau', tự động kiểm tra tính hợp lệ (nếu không hợp lệ sẽ bắt nhập lại) và rút gọn phân số sau khi người dùng đã nhập một phân số hợp lệ
    void Nhap() {
        while (true) {
            cout << "Nhap tu va mau cua phan so (cach nhau bang dau cach): ";

            // Nếu nhập vào số nguyên và mẫu khác 0 thì break vòng lặp, còn lại thì bắt người dùng nhập lại
            if (cin >> tu >> mau) {
                if (mau != 0) {
                    break; 
                } else {
                    cout << "Loi: Mau so phai khac 0" << endl;
                }
            } else {
                cout << "Loi: Vui long chi nhap so nguyen" << endl;

                // Xóa sạch các ký tự lỗi hoặc thừa trong bộ đệm cho đến khi gặp phím Enter 
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  
            }
        }
        RutGon(); 
    }

    // Tối giản phân số và đảm bảo mẫu số luôn dương
    void RutGon() {
        int ucln = gcd(abs(tu),abs(mau)); // Tìm ước chung lớn nhất của tử và mẫu số
        tu /= ucln; // Chia tử cho ước chung lớn nhất
        mau /= ucln; // Chia mẫu cho ước chung lớn nhất

        // Đưa dấu trừ lên tử số nếu mẫu âm
        if(mau < 0) {
            tu = -tu;
            mau = -mau;
        }
    }
    
    // Xuất phân số ra màn hình (ẩn mẫu số nếu mẫu bằng 1)
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