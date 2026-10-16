#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Vehicle {
private:
    string maSo;
    string thuongHieu;
    double donGiaNgay;

public:
    Vehicle() : maSo(""), thuongHieu(""), donGiaNgay(0.0) {}
    Vehicle(string id, string brand, double price) 
        : maSo(id), thuongHieu(brand), donGiaNgay(price) {}

    virtual ~Vehicle() = default;

    string getMaSo() const { return maSo; }
    void setMaSo(const string& id) { maSo = id; }

    string getThuongHieu() const { return thuongHieu; }
    void setThuongHieu(const string& brand) { thuongHieu = brand; }

    double getDonGiaNgay() const { return donGiaNgay; }
    void setDonGiaNgay(double price) { donGiaNgay = price; }

    virtual double calculateRentalFee(int days) const = 0;

    virtual void displayInfo() const {
        cout << "[+] Ma So      : " << maSo << endl;
        cout << "[+] Thuong Hieu: " << thuongHieu << endl;
        cout << "[+] Gia/Ngay   : " << donGiaNgay << " VND" << endl;
    }
};

class Car : public Vehicle {
private:
    int soChoNgoi;

public:
    Car() : Vehicle(), soChoNgoi(4) {}
    Car(string id, string brand, double price, int seats)
        : Vehicle(id, brand, price), soChoNgoi(seats) {}

    int getSoChoNgoi() const { return soChoNgoi; }
    void setSoChoNgoi(int seats) { soChoNgoi = seats; }

    double calculateRentalFee(int days) const override {
        double tongTien = days * getDonGiaNgay();
        if (days >= 7) {
            tongTien *= 0.90;
        }
        return tongTien;
    }

    void displayInfo() const override {
        Vehicle::displayInfo();
        cout << "[+] Loai Xe    : O to (" << soChoNgoi << " cho)" << endl;
    }
};

class Motorbike : public Vehicle {
private:
    int dungTichXylanh;

public:
    Motorbike() : Vehicle(), dungTichXylanh(110) {}
    Motorbike(string id, string brand, double price, int cc)
        : Vehicle(id, brand, price), dungTichXylanh(cc) {}

    int getDungTichXylanh() const { return dungTichXylanh; }
    void setDungTichXylanh(int cc) { dungTichXylanh = cc; }

    double calculateRentalFee(int days) const override {
        double tongTien = days * getDonGiaNgay();
        if (days >= 5) {
            tongTien *= 0.95;
        }
        return tongTien;
    }

    void displayInfo() const override {
        Vehicle::displayInfo();
        cout << "[+] Loai Xe    : Xe may (" << dungTichXylanh << " cc)" << endl;
    }
};

class Truck : public Vehicle {
private:
    double phiVanChuyenCoDinh;

public:
    Truck() : Vehicle(), phiVanChuyenCoDinh(0.0) {}
    Truck(string id, string brand, double price, double extraFee)
        : Vehicle(id, brand, price), phiVanChuyenCoDinh(extraFee) {}

    double getPhiVanChuyenCoDinh() const { return phiVanChuyenCoDinh; }
    void setPhiVanChuyenCoDinh(double extraFee) { phiVanChuyenCoDinh = extraFee; }

    double calculateRentalFee(int days) const override {
        return (days * getDonGiaNgay()) + phiVanChuyenCoDinh;
    }

    void displayInfo() const override {
        Vehicle::displayInfo();
        cout << "[+] Phi Phu Tro : " << phiVanChuyenCoDinh << " VND" << endl;
    }
};

struct DichVuThueXe {
    static double tinhDoanhThu(const vector<Vehicle*>& ds, int soNgay) {
        double tongDoanhThu = 0.0;
        for (const auto* xe : ds) {
            tongDoanhThu += xe->calculateRentalFee(soNgay);
        }
        return tongDoanhThu;
    }

    static const Vehicle* timXeGiaCaoNhat(const vector<Vehicle*>& ds, int soNgay) {
        if (ds.empty()) return nullptr;
        
        const Vehicle* xeMax = ds[0];
        double maxFee = xeMax->calculateRentalFee(soNgay);

        for (size_t i = 1; i < ds.size(); ++i) {
            double currentFee = ds[i]->calculateRentalFee(soNgay);
            if (currentFee > maxFee) {
                maxFee = currentFee;
                xeMax = ds[i];
            }
        }
        return xeMax;
    }
};

int main() {
    int soNgayThue = 7;

    Car oto("CAR-01", "Toyota", 800000, 5);
    Motorbike xemay("MB-01", "Honda", 150000, 125);
    Truck xetai("TRK-01", "Isuzu", 1200000, 500000);

    vector<Vehicle*> danhSachXe = { &oto, &xemay, &xetai };

    cout << "=== DANH SACH PHUONG TIEN THUE (" << soNgayThue << " NGAY) ===" << endl;
    for (const auto* xe : danhSachXe) {
        xe->displayInfo();
        cout << "[=] Phi Thue    : " << xe->calculateRentalFee(soNgayThue) << " VND" << endl;
        cout << "------------------------------------------" << endl;
    }

    double tongThu = DichVuThueXe::tinhDoanhThu(danhSachXe, soNgayThue);
    cout << ">> TONG DOANH THU THUE XE: " << tongThu << " VND" << endl;

    const Vehicle* xeDatNhat = DichVuThueXe::timXeGiaCaoNhat(danhSachXe, soNgayThue);
    if (xeDatNhat != nullptr) {
        cout << "\n=== PHUONG TIEN CO PHI THUE CAO NHAT ===" << endl;
        xeDatNhat->displayInfo();
        cout << "[=] Thanh Tien  : " << xeDatNhat->calculateRentalFee(soNgayThue) << " VND" << endl;
    }

    return 0;
}