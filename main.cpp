#include <iostream>
#include <string>

using namespace std;

class Employee {
private:
    string maNV;
    string hoTen;

public:
    Employee() : maNV("NV000"), hoTen("Chua Cap Nhat") {}
    Employee(string id, string name) : maNV(id), hoTen(name) {}

    virtual ~Employee() {}

    string getMaNV() const { return maNV; }
    void setMaNV(const string& id) { maNV = id; }

    string getHoTen() const { return hoTen; }
    void setHoTen(const string& name) { hoTen = name; }

    virtual double tinhLuongThang() const { return 0.0; }
    virtual double tinhLuongNam() const { return 0.0; }

    virtual void display() const {
        cout << "-----------------------------------" << endl;
        cout << "[+] Ma Nhan Vien : " << maNV << endl;
        cout << "[+] Ho Va Ten    : " << hoTen << endl;
    }
};

class HourlyEmployee : public Employee {
private:
    double soGioLam;
    double donGiaGio;
    int thangLamViec;
    int namLamViec;

public:
    HourlyEmployee() 
        : Employee(), soGioLam(0.0), donGiaGio(0.0), thangLamViec(1), namLamViec(2026) {}
    
    HourlyEmployee(string id, string name, double hrs, double rate, int m, int y)
        : Employee(id, name), soGioLam(hrs), donGiaGio(rate), thangLamViec(m), namLamViec(y) {}

    double getSoGioLam() const { return soGioLam; }
    void setSoGioLam(double hrs) { soGioLam = hrs; }

    double getDonGiaGio() const { return donGiaGio; }
    void setDonGiaGio(double rate) { donGiaGio = rate; }

    int getThangLamViec() const { return thangLamViec; }
    void setThangLamViec(int m) { thangLamViec = m; }

    int getNamLamViec() const { return namLamViec; }
    void setNamLamViec(int y) { namLamViec = y; }

    double tinhLuongThang() const override {
        return soGioLam * donGiaGio;
    }

    double tinhLuongNam() const override {
        return tinhLuongThang() * 12;
    }

    void display() const override {
        Employee::display();
        cout << "[+] Loai Hinh    : Nhan Vien Theo Gio" << endl;
        cout << "[+] So Gio Lam   : " << soGioLam << " gio" << endl;
        cout << "[+] Don Gia/Gio  : " << donGiaGio << " VND" << endl;
        cout << "[+] Thoi Gian    : Thang " << thangLamViec << "/" << namLamViec << endl;
        cout << "[=] Luong Thang  : " << tinhLuongThang() << " VND" << endl;
        cout << "[=] Luong Nam    : " << tinhLuongNam() << " VND" << endl;
    }
};

class MonthlyEmployee : public Employee {
private:
    double luongThangCoDinh;
    int thangLamViec;
    int namLamViec;

public:
    MonthlyEmployee() 
        : Employee(), luongThangCoDinh(0.0), thangLamViec(1), namLamViec(2026) {}
    
    MonthlyEmployee(string id, string name, double fixedSalary, int m, int y)
        : Employee(id, name), luongThangCoDinh(fixedSalary), thangLamViec(m), namLamViec(y) {}

    double getLuongThangCoDinh() const { return luongThangCoDinh; }
    void setLuongThangCoDinh(double fixedSalary) { luongThangCoDinh = fixedSalary; }

    int getThangLamViec() const { return thangLamViec; }
    void setThangLamViec(int m) { thangLamViec = m; }

    int getNamLamViec() const { return namLamViec; }
    void setNamLamViec(int y) { namLamViec = y; }

    double tinhLuongThang() const override {
        return luongThangCoDinh;
    }

    double tinhLuongNam() const override {
        return luongThangCoDinh * 12;
    }

    void display() const override {
        Employee::display();
        cout << "[+] Loai Hinh    : Nhan Vien Theo Thang" << endl;
        cout << "[+] Thoi Gian    : Thang " << thangLamViec << "/" << namLamViec << endl;
        cout << "[=] Luong Thang  : " << tinhLuongThang() << " VND" << endl;
        cout << "[=] Luong Nam    : " << tinhLuongNam() << " VND" << endl;
    }
};

class DailyEmployee : public Employee {
private:
    int soNgayLam;
    double donGiaNgay;
    int thangLamViec;
    int namLamViec;

public:
    DailyEmployee() 
        : Employee(), soNgayLam(0), donGiaNgay(0.0), thangLamViec(1), namLamViec(2026) {}
    
    DailyEmployee(string id, string name, int days, double rate, int m, int y)
        : Employee(id, name), soNgayLam(days), donGiaNgay(rate), thangLamViec(m), namLamViec(y) {}

    int getSoNgayLam() const { return soNgayLam; }
    void setSoNgayLam(int days) { soNgayLam = days; }

    double getDonGiaNgay() const { return donGiaNgay; }
    void setDonGiaNgay(double rate) { donGiaNgay = rate; }

    int getThangLamViec() const { return thangLamViec; }
    void setThangLamViec(int m) { thangLamViec = m; }

    int getNamLamViec() const { return namLamViec; }
    void setNamLamViec(int y) { namLamViec = y; }

    double tinhLuongThang() const override {
        return soNgayLam * donGiaNgay;
    }

    double tinhLuongNam() const override {
        return tinhLuongThang() * 12;
    }

    void display() const override {
        Employee::display();
        cout << "[+] Loai Hinh    : Nhan Vien Theo Ngay" << endl;
        cout << "[+] So Ngay Lam  : " << soNgayLam << " ngay" << endl;
        cout << "[+] Don Gia/Ngay : " << donGiaNgay << " VND" << endl;
        cout << "[+] Thoi Gian    : Thang " << thangLamViec << "/" << namLamViec << endl;
        cout << "[=] Luong Thang  : " << tinhLuongThang() << " VND" << endl;
        cout << "[=] Luong Nam    : " << tinhLuongNam() << " VND" << endl;
    }
};

int main() {
    HourlyEmployee nvGio("HE01", "Nguyen Van An", 160, 45000, 10, 2026);
    MonthlyEmployee nvThang("ME01", "Tran Thi Binh", 18000000, 10, 2026);
    DailyEmployee nvNgay("DE01", "Le Van Cuong", 22, 550000, 10, 2026);

    cout << "=== QUAN LY THONG TIN CUC BO NHAN VIEN ===" << endl;
    
    nvGio.display();
    cout << endl;

    nvThang.display();
    cout << endl;

    nvNgay.display();
    cout << "-----------------------------------" << endl;

    return 0;
}