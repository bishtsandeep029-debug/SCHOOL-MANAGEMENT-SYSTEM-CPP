/*#include<iostream>
using namespace std;

int main(){
    int size;
   cout<<"Enter the size of an array : " ;
   cin>>size;

   int arr[size];

   cout<<"Enter the array of "<<size<<" elements : "<<endl;

   for(int i=0;i<size;i++){
    cin>>arr[i];

   }

   for(int i = 0;i<size;i++){
    cout<<"the array of elemets are : "<<arr[i]<<endl;
}
}*/

// Dynamic Memory Allocation (using new keywoerd , array and pointer and stored in heap memory)
/*#include<iostream>
using namespace std;    

int main(){
    int size;
   cout<<"Enter the size of an array : " ;
   cin>>size;

   int *arr = new int[size];

    cout<<"Enter the array of "<<size<<" elements : "<<endl;

    for(int i = 0 ; i<size;i++){
        cin>>arr[i];
    }

    for(int i = 0 ; i<size;i++){
        cout<<"the array of elemets are : "<<arr[i]<<endl;
    }

    delete [] arr;  // free the allocated memory
}*/

//function 

/*#include<iostream>
using namespace std;  

double areaofcircle(int r ){
    return 3.14*r*r;
}

double circumferneceofcircle(int r){
     return 2*3.14*r;
}

int main(){
    int r;
  cout<<"Enter the radius of circle : " ;
  cin>>r;

  double area = areaofcircle(r);
  double circumference = circumferneceofcircle(r);


  cout<<"the area of circle is : "<<area<<endl;
  cout<<"the circumference of circle is : "<<circumference<<endl;
}*/

// function to find odd / even in  1-10 numbers;

// #include<iostream>
// using namespace std;

// bool odd(int n){
//     if (n%2!=0){
//         return true;
//     }
//     else{
//         return false;
//     }
// }

// int main(){
//     for(int i = 0;i<10;i++){
//         if(odd(i)){
//             cout<<i<<" is odd number "<<endl;
//         }
//         else{
//             cout<<i<<" is even number "<<endl;
//         }
//     }
//     return 0;
// }

// #include<iostream>
// using namespace std;

// int main(){
//       bool ifrain =  true;
//       cout<<"rain"<<endl;

//       bool notrain = false;
//       cout<<"no rain"<<endl;

//       return 0;

// }
// #include<iostream>
// using namespace std;

// int main(){
//      int size;
//    cout<<"Enter the size of an array : " ;
//    cin>>size;

//    int *arr = new int[size];

//     cout<<"Enter the array of "<<size<<" elements : "<<endl;

//     for(int i = 0 ; i<size;i++){
//         cin>>arr[i];
//     }

//     for(int i = 0 ; i<size;i++){
//         cout<<"the array of elemets are : "<<arr[i]<<endl;
//     }

//     delete [] arr;

//     if(arr==NULL){
//         cout<<"memory not allocated"<<endl;
//     }
//     else{
//         cout<<"memory allocated successfully"<<endl;
//     }
// }
 // int size;
    // cout << "Enter number of students: ";
    // cin >> size;
    
    // result* students = new result[size];

    // for (int i = 0; i < size; i++) {
    //     cout << "\nEntering data for student " << i + 1 << ":\n";
    //     students[i].getdata();

    //     cout << "\nDisplaying data for student " << i + 1 << ":\n";
    //     students[i].display();
    // }

//     school Management program
//     #include <iostream>
// #include <vector>
// using namespace std;

// class school {
// public:
//     string name;
//     int rollno;

//     virtual void getdata() {
//         cout << "Enter the name of student: ";
//         cin.ignore();
//         getline(cin, name);

//         cout << "Enter the roll number: ";
//         cin >> rollno;
//     }

//     virtual void display() {
//         cout << "Name: " << name << endl;
//         cout << "Roll No: " << rollno << endl;
//     }
// };

// class student : public school {
// public:
//     int n;
//     int* marks = nullptr;

//     void getdata() override {
//         school::getdata();

//         cout << "Enter number of subjects: ";
//         cin >> n;

//         marks = new int[n];

//         for (int i = 0; i < n; i++) {
//             cout << "Enter marks of subject " << i + 1 << ": ";
//             cin >> marks[i];
//         }
//     }

//     void display() override {
//         school::display();

//         for (int i = 0; i < n; i++) {
//             cout << "Marks of subject " << i + 1 << ": " << marks[i] << endl;
//         }
//     }

//     ~student() {
//         delete[] marks;
//     }
// };

// class result : public student {
// public:
//     float percentage;
//     int total;
//     bool ispass;

//     void getdata() override {
//         student::getdata();

//         total = 0;
//         for (int i = 0; i < n; i++) {
//             total += marks[i];
//         }

//         percentage = (total / (n * 100.0)) * 100;
//         ispass = (percentage >= 40);
//     }

//     void display() override {
//         student::display();
//         cout << "Total: " << total << endl;
//         cout << "Percentage: " << percentage << "%" << endl;
//         cout << "Result: " << (ispass ? "Pass" : "Fail") << endl;
//     }
// };

// int main() {
//     int size = 0;
//     result* students = nullptr;
//     int choice;


//     do {
//         cout << "\n--- Student Management System ---\n";
//         cout << "1. Add Students\n";
//         cout << "2. Display Students\n";
//         cout << "3. Exit\n";
//         cout << "Enter your choice: ";
//         cin >> choice;

//         switch(choice) {

//             case 1:
//                 cout << "Enter number of students: ";
//                 cin >> size;

//                 students = new result[size];

//                 for (int i = 0; i < size; i++) {
//                     cout << "\nEnter details of student " << i + 1 << ":\n";
//                     students[i].getdata();
//                 }
//                 break;

//             case 2:
//                 if (size == 0) {
//                     cout << "No student data available!\n";
//                 } else {
//                     for (int i = 0; i < size; i++) {
//                         cout << "\nStudent " << i + 1 << " details:\n";
//                         students[i].display();
//                     }
//                 }
//                 break;

//             case 3:
//                 cout << "Exiting program...\n";
//                 break;

//             default:
//                 cout << "Invalid choice. Try again.\n";
//         }

//     } while(choice != 3);

//     delete[] students;

//     return 0;
// }
 ifstream fin("students.txt");

    if(!fin){
        cerr << "Error opening file for reading." << endl;
        return 1;
    }
 if(fin.is_open()){
        result r;
        while(r.readfromfile(fin)){
            students.push_back(r);
        }
        fin.close();
    }
