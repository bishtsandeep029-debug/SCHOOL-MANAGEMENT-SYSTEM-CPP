#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;

class Vehicle {
public:
    int id;
    string name;
    string type;
    double rentPerDay;
    bool available;

    Vehicle() {}

    Vehicle(int i, string n, string t, double r, bool a) {
        id = i;
        name = n;
        type = t;
        rentPerDay = r;
        available = a;
    }

    void display() {
        cout << left << setw(6) << id
             << setw(15) << name
             << setw(10) << type
             << setw(12) << rentPerDay
             << (available ? "Available" : "Rented") << endl;
    }
};

class Customer {
public:
    string cname;
    int vehicleId;
    int days;

    Customer() {}

    Customer(string n, int v, int d) {
        cname = n;
        vehicleId = v;
        days = d;
    }
};

vector<Vehicle> vehicles;

// ---------------- File Handling ----------------

void loadVehicles() {
    ifstream fin("vehicles.txt");
    if (!fin) return;

    Vehicle v;
    while (fin >> v.id >> v.name >> v.type >> v.rentPerDay >> v.available) {
        vehicles.push_back(v);
    }
    fin.close();
}

void saveVehicles() {
    ofstream fout("vehicles.txt");
    for (auto &v : vehicles) {
        fout << v.id << " "
             << v.name << " "
             << v.type << " "
             << v.rentPerDay << " "
             << v.available << endl;
    }
    fout.close();
}

// ---------------- Admin Functions ----------------

void addVehicle() {
    int id;
    string name, type;
    double rent;

    cout << "Enter Vehicle ID: ";
    cin >> id;
    cout << "Enter Vehicle Name: ";
    cin >> name;
    cout << "Enter Type (Car/Bike): ";
    cin >> type;
    cout << "Enter Rent per day: ";
    cin >> rent;

    vehicles.push_back(Vehicle(id, name, type, rent, true));
    saveVehicles();

    cout << "Vehicle Added Successfully!\n";
}

void viewVehicles() {
    cout << left << setw(6) << "ID"
         << setw(15) << "Name"
         << setw(10) << "Type"
         << setw(12) << "Rent/Day"
         << "Status\n";

    for (auto &v : vehicles) {
        v.display();
    }
}

// ---------------- User Functions ----------------

void rentVehicle() {
    string cname;
    int id, days;

    viewVehicles();

    cout << "Enter Vehicle ID to Rent: ";
    cin >> id;

    for (auto &v : vehicles) {
        if (v.id == id && v.available) {
            cout << "Enter Your Name: ";
            cin >> cname;
            cout << "Enter Number of Days: ";
            cin >> days;

            double bill = days * v.rentPerDay;
            v.available = false;
            saveVehicles();

            ofstream fout("customers.txt", ios::app);
            fout << cname << " " << id << " " << days << endl;
            fout.close();

            cout << "Vehicle Rented Successfully!\n";
            cout << "Total Bill: " << bill << endl;
            return;
        }
    }

    cout << "Vehicle not available!\n";
}

void returnVehicle() {
    int id;
    cout << "Enter Vehicle ID to Return: ";
    cin >> id;

    for (auto &v : vehicles) {
        if (v.id == id && !v.available) {
            v.available = true;
            saveVehicles();
            cout << "Vehicle Returned Successfully!\n";
            return;
        }
    }

    cout << "Invalid Vehicle ID!\n";
}

// ---------------- Menus ----------------

void adminMenu() {
    int choice;
    do {
        cout << "\n--- Admin Menu ---\n";
        cout << "1. Add Vehicle\n";
        cout << "2. View Vehicles\n";
        cout << "3. Back\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addVehicle(); break;
            case 2: viewVehicles(); break;
        }
    } while (choice != 3);
}

void userMenu() {
    int choice;
    do {
        cout << "\n--- User Menu ---\n";
        cout << "1. View Vehicles\n";
        cout << "2. Rent Vehicle\n";
        cout << "3. Return Vehicle\n";
        cout << "4. Back\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: viewVehicles(); break;
            case 2: rentVehicle(); break;
            case 3: returnVehicle(); break;
        }
    } while (choice != 4);
}

// ---------------- Main ----------------

int main() {
    loadVehicles();

    int choice;
    do {
        cout << "\n===== Vehicle Rental System =====\n";
        cout << "1. Admin\n";
        cout << "2. User\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: adminMenu(); break;
            case 2: userMenu(); break;
        }
    } while (choice != 3);

    return 0;
}
