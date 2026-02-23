#include <iostream>
#include<algorithm>
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

class Teacher {
public:
    string name;
    int id;
    double salary;
    string subject;
    Teacher* next;

    Teacher(string n, int i, double s, string sub) : name(n), id(i), salary(s), subject(sub), next(NULL){}
};

class staff {
  private:
    Teacher* head;
    Teacher* tail;

  public:
    staff() {
        head = tail = NULL;
     }

     void addteacher(string name, int id, double salary, string subject) {
        Teacher* newteacher = new Teacher(name, id, salary, subject);

        if (head == NULL) {
            head = tail = newteacher;
        } else {
            tail->next = newteacher;
            tail = newteacher;
        }
     }

     void displayteachers() {
      if (head == NULL) {
        cout << "No teachers available!\n";
        return;
     }

     cout << "\n";
     cout << "+" << string(78, '-') << "+\n";

     cout << "|"
         << left << setw(18) << " Name"
         << "|" << setw(10) << " ID"
         << "|" << setw(15) << " Salary"
         << "|" << setw(30) << " Subject"
         << "|\n";

      cout << "+" << string(78, '-') << "+\n";

     Teacher* temp = head;

     while (temp != NULL) {
        cout << "|"
             << left << setw(18) << temp->name
             << "|" << setw(10) << temp->id
             << "|" << setw(15) << fixed << setprecision(2) << temp->salary
             << "|" << setw(30) << temp->subject
             << "|\n";

        temp = temp->next;
     }

       cout << "+" << string(78, '-') << "+\n\n";
      }

     void inputteachers() {
        int count;
        cout << "Enter number of teachers to add: ";
        cin >> count;

        for (int i = 0; i < count; i++) {
            string name;
            int id;
            double salary;
            string subject;

            cout << "\nEnter details of teacher " << i + 1 << ":\n";
            cout << "Enter the Name of the teacher : ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, name);
            cout << " Enter the ID of teacher " << name << ": ";
            cin >> id;
            cout << " Enter the Salary of teacher " << name << ": ";
            cin >> salary;
            cout << " Enter the Subject of teacher " << name << ": ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, subject);

            addteacher(name, id, salary, subject);
           }
           cout<<endl;
           cout<<"TOTAL NUMBER OF TEACHER "<<count;
          }

         bool searchteacher(int key){
                Teacher* temp = head;

                while(temp!= NULL){
                    if(temp->id == key){
                         cout << "Teacher Found!\n";
                         cout << "Name: " << temp->name << endl;
                         cout << "ID: " << temp->id << endl;
                         cout << "Salary: " << temp->salary << endl;
                         cout << "Subject: " << temp->subject << endl;

                         return true;
                    }
                     temp = temp->next;
                }
                return false;
        }
 
       bool deleteteacher(int key){
         // case1
         if(head == NULL){
            cout<<"No Teacher Data is Available : ";
            return false;
         }
         // case2
          Teacher* temp = head;
          Teacher* prev = NULL;
         if(temp->id == key){
            head = temp->next;

            if(temp == tail){
              tail = NULL;
            }
            delete temp;
            cout<<"Delete Teacher Successfully : ";
             return true;
         }

         //case 3
         while(temp != NULL && temp->id != key){
             prev =  temp;
             temp = temp->next;
         }
         //if not found
          if(temp == NULL){
            cout<<"Teacher is not Found :";
          }
          
          //delete node
           prev->next = temp->next;

           // tail update
           if(temp == NULL){
             tail = prev;
              }
           
           delete temp;
           cout<<"Teacher Delete Successfully : ";
           return true;
         
      }

     void writetofile() {
        ofstream file("teachers.txt");
        Teacher* temp = head;

        while (temp != NULL) {
            file << temp->name << "\n"
                 << temp->id << " "
                 << temp->salary << " "
                 << temp->subject << "\n";
            temp = temp->next;
        }

        file.close();
     }

     void readfromfile() {
        ifstream file("teachers.txt");

        if (!file) {
            cout << "No teacher file found.\n";
            return;
        }

        // clear current list
        head = tail = NULL;
        string name;
        int id;
        double salary;
        string subject;

        while (getline(file, name)) {
            file >> id >> salary;
            file.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(file, subject);
            addteacher(name, id, salary, subject);
        }

        file.close();
         }

       ~staff(){
        Teacher* temp = head ;
         Teacher* next = NULL ;
         while(temp != NULL){
             next = temp->next;
             delete temp;
             temp = next;
         }
         
       }
};

class History{
     public:
       string action;
       History* next;
       History* prev;
       
       History(string a):action(a),next(NULL),prev(NULL){}
};

class historyrecord {
private:
    History* head;
    History* tail;

public:
    historyrecord() {
        head = NULL;
        tail = NULL;
    }

    void addaction(string act) {
        History* newnode = new History(act);

        if (head == NULL) {
            head = tail = newnode;
        }
        else {
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        }
    }

    void displayhistory() {
        if (head == NULL) {
            cout << "No history available!\n";
            return;
        }

        cout << "\n========== HISTORY ==========\n";
        History* temp = head;
        while (temp != NULL) {
            cout << "- " << temp->action << endl;
            temp = temp->next;
        }
        cout << "=============================\n";
    }

    void writetofile() {
        ofstream file("history.txt");

        History* temp = head;
        while (temp != NULL) {
            file << temp->action << "\n";
            temp = temp->next;
        }

        file.close();
    }

    void readfromfile() {
        ifstream file("history.txt");
        if (!file) return;

        string line;
        while (getline(file, line)) {
            addaction(line);
        }

        file.close();
     }
         
       ~historyrecord(){
        History* temp = head ;
        History* next = NULL ;
         while(temp != NULL){
             next = temp->next;
             delete temp;
             temp = next;
         }
       }
     
};

class result : public student {
public:
    char grade;
    double percentage;
    int total;
    bool ispass;

    void calculateResult() {

       if(n==0){
           cout << "No subjects entered! Cannot calculate result.\n";
        }

       total = 0;
       for(int m : marks)
        total += m;

       percentage = (total / (n * 100.0)) * 100;
      ispass = percentage >= 40;

     if(percentage >= 90) grade = 'A';
     else if(percentage >= 75) grade = 'B';
     else if(percentage >= 60) grade = 'C';
     else if(percentage >= 40) grade = 'D';
      else grade = 'F';
     }

    void getdata() override {
        student::getdata();
        calculateResult();
    }

    void display() override {
      cout << "|" << left << setw(24) << name
         << "|" << setw(11) << rollno;

       for (int i = 0; i < n; i++)
        cout << "|" << setw(12) << marks[i];

      cout << "|" << setw(11) << total
         << "|" << setw(11) << fixed << setprecision(2) << percentage
         << "|" << setw(11) << (ispass ? "Pass" : "Fail")
         << "|" << setw(11) << grade
         << "|\n";
    }
   void writetofile(ofstream &file){ // write data in file
    file << name << "\n";   // newline
    file << rollno << " " << n << "\n";

    for(int i = 0; i < n; i++){
        file << marks[i] << " ";
      }
    file << "\n";
      }

    bool readfromfile(ifstream &file){     // read data from file

    if(!getline(file, name)) return false;

    file >> rollno >> n;
    file.ignore(numeric_limits<streamsize>::max(), '\n');

    marks.resize(n);
    for(int i = 0; i < n; i++){
        file >> marks[i];
    }
    file.ignore(numeric_limits<streamsize>::max(), '\n');

    // recalc
      if(n > 0){
        calculateResult();
      }
       return true;
  }
  
  void printResultToFile() {
    string filename = "result_" + to_string(rollno) + ".txt";
    ofstream fout(filename);

    if(!fout){
        cout << "Error creating file!\n";
        return;
    }
    if(n==0){
        cout << "No subjects entered! Cannot print result.\n";
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

 bool staffProtection(){
    string password;
     int attempts = 3;

     while(attempts--){
        cout << "Enter password to access staff menu: ";
        cin >> password;

        if(password == "staff123"){
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
    int width = 25 + 12 + (subjects * 13) + 12 + 12 + 12 + 12;

    cout << "+" << string(width - 2, '-') << "+\n";

    cout << "|" << left << setw(24) << " Name"
         << "|" << setw(11) << " Roll No";

    for (int i = 0; i < subjects; i++)
        cout << "|" << setw(12) << (" Sub" + to_string(i+1));

    cout << "|" << setw(11) << " Total"
         << "|" << setw(11) << " Percent"
         << "|" << setw(11) << " Result"
         << "|" << setw(11) << " Grade"
         << "|\n";

    cout << "+" << string(width - 2, '-') << "+\n";
  }

   template<typename T>
   bool comparison(const T &a, const T &b){
    return a.rollno < b.rollno;
      }
  template<typename T>
  void sortstudent(vector<T> &students) {
      int n = students.size();
       sort(students.begin(), students.end(), comparison<T>);       
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

 void showStudents(vector<result>& students){
    if(students.empty()){
        cout << "No student data available!\n";
        return;
    }

    printHeader(students[0].n);
    sortstudent(students);

    for(auto &s : students)
        s.display();

    cout << "\nTotal students: "
         << students.size() << endl;
  }

 void userMenu(vector<result>& students) {
    int choice;

    do {
        cout << "\n--- Student Menu ---\n";
        cout << "1. show result \n";
        cout << "2.  Back\n";
        cout << "Enter choice: ";
        cin >> choice;

    switch(choice) {
      case 1:{
                 // show result
                 int key;
        cout << "Enter roll number to print result: ";
        cin >> key;

        if(students.empty()){
            cout << "No student data available!\n";
        }
        else{
            sortstudent(students);
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
          
      case 2:{
          break;

        default:
            cout << "Invalid choice\n";
    }
  }

 }while(choice != 2);
  
 }   

 void adminMenu(vector<result>& students,historyrecord& h,staff& s) {
    int choice;

    do {
        cout << "\n--- Admin Menu ---\n";
        cout << "1. Add Student\n";
        cout << "2. Add Teacher\n";
        cout << "3. Delete Student\n";
        cout << "4. Delete Teacher\n";
        cout << "5. View Students\n";
        cout << "6. view Teachers\n";
        cout << "7. search teacher \n";
        cout << "8. view History\n";
        cout << "9. Back\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {

        case 1: {
            int size;
            cout << "Enter number of students: ";
            cin >> size;

            if(size <= 0){
                cout << "Invalid number of students!\n";
                break;
            }

            ofstream file("students.txt", ios::app);
            if (!file) {
                cout << "Error opening file!\n";
                break;
            }

            for (int i = 0; i < size; i++) {
                result r;
                cout << "\nEnter details of student " << i + 1 << ":\n";
                r.getdata();
                r.writetofile(file);
                students.push_back(r);
               }
            
            h.addaction("Admin added student(s)");
            h.writetofile();
            file.close();
            cout << "\nData saved successfully!\n";
            break;
        }

        case 2: {
    
            s.inputteachers();
            s.writetofile();
            h.addaction("NEW TEACHER ADDED");
            h.writetofile();

            break;
        }

        case 3: {
            int key;
            cout << "Enter roll number to delete: ";
            cin >> key;

            if(students.empty()){
                cout << "No student data available!\n";
            } else {
                deletestudent(students, key);
                h.addaction("Admin deleted student Roll No: " + to_string(key));
                h.writetofile();
            }
            break;
        }

        case 4:{
              int id;
              cout<<"Enter the ID of the teacher to delete";
              cin>>id;

              s.deleteteacher(id);
              s.writetofile();
              h.addaction("Delete Teacher with id ");
              h.writetofile();
              break;
        }

        case 5:{
            showStudents(students);
            break;
        }
           
        case 6:{
              s.readfromfile();
              s.displayteachers();
               break;
        }

        case 7 :{
            int key;
            cout<<"Enter the ID of the Teacher for search : ";
            cin>>key;
             if(!s.searchteacher(key)){
               cout<<"Teacher not found ";
           }
            break;
            }

        case 8:{
            h.displayhistory();
            break;
        }

        case 9:
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while(choice != 9);
}

 void staffMenu(vector<result>& students,staff &s,historyrecord& h) {
    int choice;
  
     do{
        cout << "1. View Students\n";
        cout << "2. Search Student\n";
        cout << "3. show result \n";
        cout << "4. Back\n";
        cout << "Enter choice: ";
        cin >> choice;

    switch(choice) {
      case 1:{
                // display students
            showStudents(students);
                break;
          }
      case 2:{
                // search student
          int key;
          cout << "Enter roll number to search: ";
          cin >> key;

          if(students.empty()){
            cout << "No student data available!\n";
              }
          else{
            sortstudent(students);
            int index = binarysearch(students, key);
            if(index == -1){
                cout << "Student with roll number " << key << " not found.\n";
            }
          }
                break;
        }
       case 3:{
                // show result
                 int key;
        cout << "Enter roll number to print result: ";
        cin >> key;

        if(students.empty()){
            cout << "No student data available!\n";
        }
        else{
            sortstudent(students);
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
    }
  } while(choice != 4);
}

int main(){
    vector<result> students;
    historyrecord h;
     staff s;

// Load history once
     h.readfromfile();

// Load students once
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

int role;

    do {
       cout << "\n=====================================\n";
      cout << "        SCHOOL MANAGEMENT SYSTEM\n";
      cout << "=====================================\n";

      cout << "1. Admin\n";
      cout << "2. User\n";
      cout << "3. Staff\n";
      cout << "4. Exit\n";
      cout<<"Enter your role: ";
      cin >> role;

    if(role == 1){
        if(protection())
            adminMenu(students, h,s);
    }
    else if(role == 2){
        userMenu(students);
    }
    else if(role == 3){
        if(staffProtection())
         staffMenu(students,s,h);
    }

   } while(role != 4);

  return 0;
}