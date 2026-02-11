#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <limits>
using namespace std;

class school {
public:
    string name;
    int rollno;

    virtual void getdata() {
        cout << "Enter the name of student: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, name);

        cout << "Enter the roll number: ";
        cin >> rollno;
    }

    virtual void display() {
        cout << left << setw(25) << name
             << setw(14) << rollno;
    }
};

class student : public school {
public:
    int n;
    vector<int> marks;

    void getdata() override {
        school::getdata();

        cout << "Enter number of subjects: ";
        cin >> n;

        marks.resize(n);
        for (int i = 0; i < n; i++) {
            cout << "Enter marks of subject " << i + 1 << ": ";
            cin >> marks[i];
        }
    }

    void display() override {
        school::display();
        for (int i = 0; i < n; i++) {
            cout << setw(13) << marks[i];
        }
    }
};

class result : public student {
public:
    char grade;
    double percentage;
    int total;
    bool ispass;

    void getdata() override {
        student::getdata();

        total = 0;
        for (int i = 0; i < n; i++) {
            total += marks[i];
        }

        percentage = (total / (n * 100.0)) * 100;
        ispass = (percentage >= 40);

        // ✅ use class grade (no 'char' here)
        if(percentage >= 90) grade = 'A';
        else if(percentage >= 75) grade = 'B';
        else if(percentage >= 60) grade = 'C';
        else if(percentage >= 40) grade = 'D';
        else grade = 'F';
    }

    void display() override {
        student::display();

        cout << setw(12) << total
             << setw(11) << fixed << setprecision(2) << percentage
             << setw(11) << (ispass ? "Pass" : "Fail")
             << setw(11) << grade
             << endl;
    }

   void writetofile(ofstream &file){ 
    file << name << "\n";   // newline
    file << rollno << " " << n << "\n";

    for(int i = 0; i < n; i++){
        file << marks[i] << " ";
    }
    file << "\n";
    }

    bool readfromfile(ifstream &file){

    if(!getline(file, name)) return false;

    file >> rollno >> n;
    file.ignore(numeric_limits<streamsize>::max(), '\n');

    marks.resize(n);
    for(int i = 0; i < n; i++){
        file >> marks[i];
    }
    file.ignore(numeric_limits<streamsize>::max(), '\n');

    // recalc
    total = 0;
    for (int i = 0; i < n; i++) total += marks[i];

    percentage = (total / (n * 100.0)) * 100;
    ispass = (percentage >= 40);

    if(percentage >= 90) grade = 'A';
    else if(percentage >= 75) grade = 'B';
    else if(percentage >= 60) grade = 'C';
    else if(percentage >= 40) grade = 'D';
    else grade = 'F';

    return true;
  }
  
  void printResultToFile() {
    string filename = "result_" + to_string(rollno) + ".txt";
    ofstream fout(filename);

    if(!fout){
        cout << "Error creating file!\n";
        return;
    }

    fout << "----- STUDENT RESULT -----\n";
    fout << "Name: " << name << "\n";
    fout << "Roll No: " << rollno << "\n\n";

    for(int i = 0; i < n; i++){
        fout << "Subject " << i+1
             << ": " << marks[i] << "\n";
    }

    fout << "\nTotal Marks: " << total << "\n";
    fout << "Percentage: " << fixed
         << setprecision(2)
         << percentage << "%\n";

    fout << "Result: "
         << (ispass ? "Pass" : "Fail") << "\n";
    fout << "Grade: " << grade << "\n";

    fout.close();
  }
};

  void deletestudent(vector<result> &students, int key) {

    for (int i = 0; i < students.size(); i++) {

        if (students[i].rollno == key) {

            students.erase(students.begin() + i);
            cout << "Student with roll number " << key << " deleted successfully.\n";

            // rewrite file after deletion
            ofstream file("students.txt");
            if (!file) {
                cout << "Error opening file!" << endl;
                return;
            }

            for (auto &r : students) {
                r.writetofile(file);
            }

            file.close();
            return;
        }
    }

    cout << "Student not found!\n";
}

bool protection(){
    string password;
    int attempts = 3;

    while(attempts--){
        cout << "Enter password to access the system: ";
        cin >> password;

        if(password == "admin123"){
            cout << "Access granted!\n";
            return true;
        }
        else{
            cout << "Incorrect password! Attempts left: "
                 << attempts << endl;
        }
    }

    cout << "Access denied!\n";
    return false;
}

void printHeader(int subjects){
    cout << left << setw(25) << "Name"
         << setw(12) << "Roll No";

    for (int i = 0; i < subjects; i++) {
        cout << setw(13) << ("Sub" + to_string(i+1));
    }

    cout << setw(12) << "Total"
         << setw(12) << "Percent"
         << setw(12) << "Result" 
         << setw(12) << "Grade"
         << endl;

    cout << string(110, '-') << endl;
   } 

    template<typename T>
    void sort(vector<T> &students) {
      int n = students.size();
      for(int i = 0;i<n-1;i++){
        bool swapped = false;
          for(int j = 0;j<n-i-1;j++){
              if(students[j].rollno > students[j+1].rollno){
                  swap(students[j], students[j+1]);
                  swapped = true;
              }
          }
          if(!swapped) 
          break;
      }
    }   

     template<typename T>
    int binarysearch(vector<T>& students, int key){
       int st = 0; int end = students.size() - 1;
         while(st <= end){

              int mid = st + (end - st) / 2;
              if(students[mid].rollno == key){
                cout << "Student found:\n";
                printHeader(students[mid].n);
                students[mid].display();
                return mid;
              }
              else if(students[mid].rollno < key){
                st = mid + 1;
              }
              else{
                end = mid - 1;
              }
         }
            return -1;
    }

int main(){
    vector<result> students;
    int choice;

    // LOAD DATA ONCE AT STARt

    ifstream fin("students.txt");

    if(!fin){
        cout<< "No saved data found. Starting new database..." << endl;
    }
    else{
      result r;
      while(r.readfromfile(fin)){
        students.push_back(r);
        }    
      fin.close();
    }
    if(!protection()){
        return 0;
    }

    do {
        cout << "\n--- Student Management System ---\n";
        cout << "1. Add Students\n";
        cout << "2. Display Students\n";
        cout << "3. search student by roll number\n";
        cout << "4. Delete Student by roll number\n";
        cout << "5. Print Result by rollno\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;


    switch (choice) {

    case 1: {
        int size;
        cout << "Enter number of students: ";
        cin >> size;

        ofstream file("students.txt", ios::app );
        if (!file) {
            cout << "Error opening file!" << endl;
            break;
        }

        for (int i = 0; i < size; i++) {
            result r;
            cout << "\nEnter details of student " << i + 1 << ":\n";
            r.getdata();
            r.writetofile(file);
            students.push_back(r);
        }

        file.close();
        cout << "\nData saved successfully in students.txt !\n";
        break;
      }

    case 2: {
      
    if (students.empty()) {
        cout << "No student data available!\n";
    } else {
       printHeader(students[0].n);
       sort(students);

        for (auto &s : students) {
            s.display();
        }

        cout << "\nTotal number of students: " << students.size() << endl;
    }
    break;
    }

    case 3:
       {
        int key;
        cout << "Enter roll number to search: ";
        cin >> key;

        if(students.empty()){
            cout << "No student data available!\n";
        }
        else{
            sort(students);
            int index = binarysearch(students, key);
            if(index == -1){
                cout << "Student with roll number " << key << " not found.\n";
            }
        }
        break;
      }
     
      case 4: {
        int key;
        cout<<"Enter roll number to delete: ";
        cin>>key;

        if(students.empty()){
            cout << "No student data available!\n";
        }
        else{
            deletestudent(students, key);
        }
        break;
      }

      case 5: {
        int key;
        cout << "Enter roll number to print result: ";
        cin >> key;

        if(students.empty()){
            cout << "No student data available!\n";
        }
        else{
            sort(students);
            int index = binarysearch(students, key);
            if(index != -1){
                students[index].printResultToFile();
                cout << "Result printed to file successfully!\n";
            }
            else{
                cout << "Student with roll number " << key << " not found.\n";
            }
        }
        break;
      }
    case 6:
        cout << "Exiting program...\n";
        break;

    default:
        cout << "Invalid choice. Try again.\n";
    }

   } while (choice != 6);

    return 0;
 }

