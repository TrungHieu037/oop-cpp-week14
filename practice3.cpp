#include <iostream>
#include <string>

using namespace std;

class Date {
private:
    int day, month, year;

public:
    Date() : day(1), month(1), year(2026) {}
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    bool equals(int d, int m, int y) const {
        return (day == d && month == m && year == y);
    }

    void display() const {
        cout << (day < 10 ? "0" : "") << day << "/"
             << (month < 10 ? "0" : "") << month << "/" << year;
    }
};

class Item {
protected:
    string name;
    double price;
    int quantity;
    Date saleDate;

public:
    Item() : name(""), price(0.0), quantity(0), saleDate(Date()) {}
    Item(string n, double p, int q, Date d) 
        : name(n), price(p), quantity(q), saleDate(d) {}

    virtual ~Item() = default;

    virtual int getGroupType() const = 0;

    double getRevenue(int d, int m, int y) const {
        if (saleDate.equals(d, m, y)) {
            return price * quantity;
        }
        return 0.0;
    }
};

class Drinks : public Item {
public:
    Drinks(string n, double p, int q, Date d) : Item(n, p, q, d) {}
    int getGroupType() const override { return 1; }
};

class Coffee : public Drinks {
public:
    Coffee(string n, double p, int q, Date d) : Drinks(n, p, q, d) {}
};

class Tea : public Drinks {
public:
    Tea(string n, double p, int q, Date d) : Drinks(n, p, q, d) {}
};

class Smoothies : public Drinks {
public:
    Smoothies(string n, double p, int q, Date d) : Drinks(n, p, q, d) {}
};

class Juices : public Drinks {
public:
    Juices(string n, double p, int q, Date d) : Drinks(n, p, q, d) {}
};

class Foods : public Item {
public:
    Foods(string n, double p, int q, Date d) : Item(n, p, q, d) {}
    int getGroupType() const override { return 2; }
};

class Cake : public Foods {
public:
    Cake(string n, double p, int q, Date d) : Foods(n, p, q, d) {}
};

class Breads : public Foods {
public:
    Breads(string n, double p, int q, Date d) : Foods(n, p, q, d) {}
};

void calculateDailyRevenue(Item* items[], int size, int day, int month, int year) {
    double totalDrinks = 0.0;
    double totalFoods = 0.0;

    for (int i = 0; i < size; ++i) {
        if (items[i]->getGroupType() == 1) {
            totalDrinks += items[i]->getRevenue(day, month, year);
        } else if (items[i]->getGroupType() == 2) {
            totalFoods += items[i]->getRevenue(day, month, year);
        }
    }

    cout << "=== TONG DOANH THU NGAY ";
    Date(day, month, year).display();
    cout << " ===" << endl;
    cout << "- Drinks: " << totalDrinks << " VND" << endl;
    cout << "- Foods : " << totalFoods << " VND" << endl;
}

int main() {
    Date today(16, 10, 2026);

    Coffee c1("Espresso", 35000, 10, today);
    Tea t1("Tra Dao", 30000, 5, today);
    Smoothies s1("Sinh To Bo", 45000, 4, today);