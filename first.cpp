#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
// void opentofile(ofstream &fout){
//      fout<<"hello world"<<endl;
//      fout<<3445<<endl;
     
// }

// void readfromfile(ifstream &fin){
//    string text;
//    int number;

//    fin>>text >>number;
//    cout << "Text: " << text << endl;
//     cout << "Number: " << number << endl;
// }

// int main(){
//   ofstream fout("sample.txt");
//   opentofile(fout);
//   fout.close();

//   ifstream fin("sample.txt");
//   readfromfile(fin);
//   fin.close();

//    return 0;  
// }

// 

class school{
   public:
      string name;
        int rollno;

    virtual void getdata(){
        cout << "Enter the name of student: ";  
        cin.ignore();
        getline(cin, name);
        cout << "Enter the roll number: ";
        cin >> rollno;  
    }

    virtual void display(){
        cout << name;
        cout << rollno;
    }

};
class calculate: public school{
   public:

void writetofile(ofstream &fout){
      fout<<name<<endl;
      fout<<rollno<<endl;
      fout<<endl;

}

bool readfromfile(ifstream &fin){
      if(!(fin>>name>>rollno))
            return false;
        return true;
      cout<<"data successfully read from file"<<endl;
}
};
int main(){
     calculate c;
    // load data 
    ifstream fin("sample.txt");
    if(!fin){
        cout<<"No saved data found. Starting new database..."<<endl;
    }
    else{
         
        while(c.readfromfile(fin)){
              c.display();
        }
        fin.close();
    }

    ofstream fout("sample.txt", ios::app | ios::in | ios::out);
    if(!fout){
        cout<<"Error opening file!"<<endl;
    }
        
    c.getdata();
    c.writetofile(fout);
    fout.close();
}




