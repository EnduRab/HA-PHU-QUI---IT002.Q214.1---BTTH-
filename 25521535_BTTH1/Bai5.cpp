#include <iostream>
#include <string>
#include <limits>

using namespace std;

struct HocSinh {
    string HoVaTen;
    float diemToan;
    float diemVan; 
    float GPA;
};

// Hàm tính điểm trung bình (GPA) dựa trên điểm Toán và Văn của học sinh
float CalcGPA(HocSinh HS) {
    return (HS.diemToan + HS.diemVan) / 2.0;
}

// Hàm nhập điểm cho một môn học cụ thể, có kiểm tra tính hợp lệ (0-10) và lỗi nhập chữ
float NhapDiem(string monHoc) {
    float diem;
    while (true) {
        cout << "Nhap diem " << monHoc << ": ";
        // Kiểm tra nếu nhập đúng số thực và nằm trong khoảng [0, 10]
        if (cin >> diem && diem >= 0 && diem <= 10) {
            return diem;
        } else {
            cout << "Diem khong hop le (phai la so tu 0 den 10)." << "\n";

            // Xóa sạch các ký tự lỗi hoặc thừa trong bộ đệm cho đến khi gặp phím Enter 
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        }
    }
}

// Hàm nhập đầy đủ thông tin cho học sinh, bao gồm xử lý trôi lệnh khi dùng getline
void NhapHocSinh(HocSinh &HS) {
    cout << "Nhap ho va ten: ";
    // Xóa bộ đệm nếu trước đó có lệnh cin >> (tránh trôi lệnh getline)
    getline(cin >> ws, HS.HoVaTen); // "ws" giúp bỏ qua các khoảng trắng/dòng trống ở đầu bộ đệm

    HS.diemToan = NhapDiem("Toan"); // Gọi hàm để nhập điểm toán cho học sinh
    HS.diemVan = NhapDiem("Van"); // Gọi hàm để nhập điểm văn cho học sinh
    HS.GPA = CalcGPA(HS); // Gọi hàm tính GPA dựa trên điểm toán và văn của học sinh
}

// In thông tin học sinh ra màn hình
void printHocSinh(HocSinh HS) {
    cout << "\n--- Thong Tin Hoc Sinh ---" << "\n";
    cout << "Ho va Ten: " << HS.HoVaTen << "\n";
    cout << "Diem Toan: " << HS.diemToan << "\n";
    cout << "Diem Van: " << HS.diemVan << "\n";
    cout << "Diem Trung Binh: " << HS.GPA << "\n";
}

int main() {
    HocSinh HS;
    NhapHocSinh(HS);
    printHocSinh(HS);
    return 0;
}