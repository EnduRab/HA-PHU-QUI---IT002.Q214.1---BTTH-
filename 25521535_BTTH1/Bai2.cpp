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
   
    // Nhập vào 2 số nguyên a và b và trả về ước chung lớn nhất của 2 số (sử dụng thuật toán Euclid)
    int gcd(int a,int b) {
        if(b == 0) return a;
        return gcd(b, a % b);
    }
    
    // Nhập vào 2 số nguyên a và b và trả về bội chung nhỏ nhất của 2 số (sử dụng thuật toán Euclid)
    int BCNN(int a,int b) {
        return (abs(a) / gcd(abs(a), abs(b))) * abs(b);
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
    
    // Quy đồng phân số hiện tại với một phân số khác và cập nhật giá trị sau khi quy đồng cho cả hai phân số (other: tham chiếu đến phân số thứ 2 cần quy đồng)
    void QuyDong(PhanSo &other) {
        int boi = BCNN(mau,other.mau); // Tìm mẫu số chung nhỏ nhất
        int hs1 = boi/mau; // Hệ số nhân của phân số thứ nhất
        int hs2 = boi/other.mau; // Hệ số nhân của phân số thứ hai
        tu *= hs1; // Nhân tử phân số thứ nhất cho hệ số nhân của nó
        other.tu *= hs2; // Nhân tử phân số thứ hai cho hệ số nhân của nó

        // Cập nhật cả hai mẫu số của hai phân số bằng với bội chung nhỏ nhất
        mau = boi;
        other.mau = boi;
    }

    // Gọi hàm quy đồng phân số hiện tại với phân số khác và so sánh hai phân số
    int SoSanh(PhanSo other) {
        PhanSo self = *this; // Tạo bản sao của phân số hiện tại 
        self.QuyDong(other); // Quy đồng bản sao của phân số hiện tại với phân số khác
        // Trả về 1 nếu phân số hiện tại lớn hơn phân số đang so sánh
        if(self.tu > other.tu) return 1;
        // Trả về -1 nếu ngược lại
        else if(self.tu < other.tu) return -1;
        // Trả về 0 nếu hai phân số bằng nhau
        else return 0;
    }

};

int main() {
    PhanSo ps1,ps2;
    ps1.Nhap();
    ps2.Nhap();
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