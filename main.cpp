#include <iostream>
#include <string>

using namespace std;

class Employee {
private:
    string cccd;
    string phone;
    string address;

public:
    Employee() {
        cccd = "";
        phone = "";
        address = "";
    }

    Employee(string c, string p, string a) {
        cccd = c;
        phone = p;
        address = a;
    }

    virtual ~Employee() = default;

    string getCCCD() const { return cccd; }
    void setCCCD(string c) { cccd = c; }

    string getPhone() const { return phone; }
    void setPhone(string p) { phone = p; }

    string getAddress() const { return address; }
    void setAddress(string a) { address = a; }

    virtual double calculateSalary(int month, int year) = 0;

    virtual double calculateYearlySalary(int year) {
        double total = 0;
        for (int m = 1; m <= 12; m++) {
            total += calculateSalary(m, year);
        }
        return total;
    }

    virtual void displayInfo() {
        cout << "CCCD: " << cccd << endl;
        cout << "Phone: " << phone << endl;
        cout << "Address: " << address << endl;
    }
};

class HourlyEmployee : public Employee {
private:
    int hours;
    double salaryPerHour;
    int month, year;

public:
    HourlyEmployee() : Employee() {
        hours = 0;
        salaryPerHour = 0;
        month = 1;
        year = 2026;
    }

    HourlyEmployee(string c, string p, string a,
                   int h, double s, int m, int y)
        : Employee(c, p, a) {
        hours = h;
        salaryPerHour = s;
        month = m;
        year = y;
    }

    int getHours() const { return hours; }
    void setHours(int h) { hours = h; }

    double getSalaryPerHour() const { return salaryPerHour; }
    void setSalaryPerHour(double s) { salaryPerHour = s; }

    int getMonth() const { return month; }
    void setMonth(int m) { month = m; }

    int getYear() const { return year; }
    void setYear(int y) { year = y; }

    double calculateSalary(int m, int y) override {
        if (m == month && y == year)
            return hours * salaryPerHour;
        return 0;
    }
};

class MonthlyEmployee : public Employee {
private:
    double monthlySalary;
    int month, year;

public:
    MonthlyEmployee() : Employee() {
        monthlySalary = 0;
        month = 1;
        year = 2026;
    }

    MonthlyEmployee(string c, string p, string a,
                    double s, int m, int y)
        : Employee(c, p, a) {
        monthlySalary = s;
        month = m;
        year = y;
    }

    double getMonthlySalary() const { return monthlySalary; }
    void setMonthlySalary(double s) { monthlySalary = s; }

    int getMonth() const { return month; }
    void setMonth(int m) { month = m; }

    int getYear() const { return year; }
    void setYear(int y) { year = y; }

    double calculateSalary(int m, int y) override {
        if (m == month && y == year)
            return monthlySalary;
        return 0;
    }
};

class DailyEmployee : public Employee {
private:
    int numberOfDays;
    double salaryPerDay;
    int month, year;

public:
    DailyEmployee() : Employee() {
        numberOfDays = 0;
        salaryPerDay = 0;
        month = 1;
        year = 2026;
    }

    DailyEmployee(string c, string p, string a,
                  int d, double s, int m, int y)
        : Employee(c, p, a) {
        numberOfDays = d;
        salaryPerDay = s;
        month = m;
        year = y;
    }

    int getNumberOfDays() const { return numberOfDays; }
    void setNumberOfDays(int d) { numberOfDays = d; }

    double getSalaryPerDay() const { return salaryPerDay; }
    void setSalaryPerDay(double s) { salaryPerDay = s; }

    int getMonth() const { return month; }
    void setMonth(int m) { month = m; }

    int getYear() const { return year; }
    void setYear(int y) { year = y; }

    double calculateSalary(int m, int y) override {
        if (m == month && y == year)
            return numberOfDays * salaryPerDay;
        return 0;
    }
};

int main() {
    HourlyEmployee h("001", "0901", "HCM", 160, 50000, 10, 2026);
    MonthlyEmployee m("002", "0902", "Dong Nai", 15000000, 10, 2026);
    DailyEmployee d("003", "0903", "Ha Noi", 22, 400000, 10, 2026);

    Employee* employees[] = {&h, &m, &d};

    cout << "=== TIEN LUONG THANG 10/2026 ===" << endl;
    for (Employee* e : employees) {
        e->displayInfo();
        cout << "Luong thang 10/2026: " << e->calculateSalary(10, 2026) << " VND" << endl;
        cout << "Tong luong ca nam 2026: " << e->calculateYearlySalary(2026) << " VND" << endl;
        cout << "---------------------------------" << endl;
    }

    return 0;
}