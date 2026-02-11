// #include<iostream>
// #include<vector>
// using namespace std;

// int main(){
//     vector<vector<int>> vect1 = {{1,2,3},{2,3,4},{3,4,5},{4,5,6}};
//     for(int i = 0;i<vect1.size();i++){
//         for(int j = 0;j<vect1[i].size();j++){
//             cout<<vect1[i][j]<<" ";
//         }
//         cout<<endl;
//     }
    
// }
// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {
//     int rows , cols;

//     cout<<"Enter number of rows: ";
//     cin >> rows;
//     cout<<"Enter number of columns: ";          
//     cin >> cols;

//     vector<vector<int>> arr(rows , vector<int>(cols));                  
//     cout<<"Enter elements of the matrix: "<<endl;
//     for(int i = 0; i < rows; i++) {
//         for(int j = 0; j < cols; j++) {
//             cin >> arr[i][j];
//         }
//     }           

//     cout<<"The matrix is: "<<endl;
//     for(int i = 0; i < rows; i++) {
//         for(int j = 0; j < cols; j++) {
//             cout << arr[i][j] << " ";
//         }
//         cout << endl;
//     }



//}

// iomanip example
// #include <iostream>
// #include<iomanip>
// using namespace std;
// int main(){
//    cout<<left<<setfill('**')<<setw(10)<<"print";
// }

//how to opeb files and write in file using ifsteam and ofstream;
// #include<iostream>
// #include<fstream>
// using namespace std;

// int main(){
//     ofstream fout;
//       fout.open("sample.txt");
//       fout<<"hello world"<<endl;

//      fout.close();

//      ifstream fin;
//        fin.open("sample.txt");
//          string str;
//          fin>>str;

//          str = fin.get();

//          while(!fin.eof()){
//             cout<<str<<endl;
//              str = fin.get();
            
//          }
// }

#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
 int main(){
     vector<int> arr(5) ;
     cout<<"Enter 5 elements"<<endl;
     for(int i = 0;i<5;i++){
         cin>>arr[i];
     }

  ofstream fout;
   fout.open("sample.txt");
   fout<<"original data"<<endl;
    for(int i = 0; i<5;i++){
      fout<<arr[i]<<endl;
    }

    fout<<"sorted data"<<endl;
    sort(arr.begin(),arr.end());
    for(int i = 0; i<5;i++){
       fout<<arr[i]<<endl;
    }

    fout.close();
  } 