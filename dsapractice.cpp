// reverse an array
// #include<iostream>
// using namespace std;

// void reversearray(int arr[], int n){
//     int st= 0 , end = n-1;
//     while(st<end){
//         swap(arr[st], arr[end]);
//         st++;
//         end--;
//     }
// }
// int main(){
//     int arr[5] = {10, 20, 30, 40, 50};
//     reversearray(arr, 5);
//     cout << "Reversed array: ";
//     for(int i = 0; i < 5; i++){
//         cout << arr[i] << " ";              
//     }   
//      cout << endl; 
// }

// second max
// #include<iostream>
// #include<climits>
// using namespace std;

// int main(){
//     int arr[5] = {10, 20, 30, 40, 50};
//     int max1 = INT_MIN, max2 = INT_MIN;

//     for(int i = 0;i<5;i++){
//          if(arr[i] > max1){
//               max1 = arr[i];
//          }
//     }

//     for(int i = 0;i<5;i++){
//          if(arr[i] != max1){
//             max2 = max(max2, arr[i]);
//          }
//     }

//      for(int i = 0;i<5;i++){
        
//             cout << "Second maximum element is: " << max2 << endl;
//             return 0;
//          }
//      }

// took last digit from a number

// #include <iostream>     
// using namespace std;
// int main(){
// //     int num = 1234;
// //         int last = num % 10;
// //         cout << last << " ";
// //         num = num / 10;
// //         cout << endl;   
// //     return 0;
//      int n = 1234;
//      int answ = 0;
//      while(n>0){
//        int rem = n % 10;
//          answ = answ * 10 + rem;
//             n = n / 10;

        
//      }
//      cout << "Reversed number: " << answ << endl;
//   }

//first and last occurenece of an element in an array
// #include<iostream>
// #include<vector>
// using namespace std;

// void occurrence(vector<int> &element, int target){
    
//     int start = 0, end = element.size() - 1;
//     int first = -1;

//     // First occurrence
//     while(start <= end){
//         int mid = start + (end - start) / 2;

//         if(element[mid] == target){
//             first = mid;
//             end = mid - 1;
//         }
//         else if(element[mid] > target){
//             end = mid - 1;
//         }
//         else{
//             start = mid + 1;
//         }
//     }

//     // Reset search range
//     start = 0;
//     end = element.size() - 1;

//     int last = -1;

//     // Last occurrence
//     while(start <= end){
//         int mid = start + (end - start) / 2;

//         if(element[mid] == target){
//             last = mid;
//             start = mid + 1;
//         }
//         else if(element[mid] > target){
//             end = mid - 1;
//         }
//         else{
//             start = mid + 1;
//         }
//     }

//     cout << "First occurrence index: " << first << endl;
//     cout << "Last occurrence index: " << last << endl;
// }

// int main(){
//     int size;
//     cout << "Enter array size: ";
//     cin >> size;

//     vector<int> element(size);

//     cout << "Enter sorted elements: ";
//     for(int i = 0; i < size; i++)
//         cin >> element[i];

//     int target;
//     cout << "Enter target: ";
//     cin >> target;

//     occurrence(element, target);

//     return 0;
// }

//bubble sort
#include<iostream>
#include<vector>
using namespace std;
  //bubble sort
int bubblesort(vector<int>&numpy ){
    for(int i = 0;i<numpy.size();i++){
      bool swapped = false;
        for(int j = 0;j<numpy.size()-i-1;j++){
            if(numpy[j]>numpy[j+1]){
                swap(numpy[j], numpy[j+1]);
            }
            swapped = true;
        }
    }
}

//selction sort

void selectionsort(vector<int> &numpy){
    for(int i = 0;i<numpy.size();i++){
        int smallest = i;
      for(int j = i+1;j<numpy.size();j++){
          if(numpy[j]<numpy[smallest]){
              smallest = j;
          }
      }
      swap(numpy[i], numpy[smallest]);
    }

}

//selection sort
void insertionsort(vector<int> &numpy){
    for(int i = 1;i<numpy.size();i++){
        int prev = i-1;
        int current = numpy[i];
        while(prev>=0 && numpy[prev]>current){
            numpy[prev+1] = numpy[prev];
            prev--;
        }
        numpy[prev+1] = current;
    }
}
void printarray(vector<int>&numpy){
    for(int i = 0;i<numpy.size();i++){
        cout << numpy[i] << " ";
    }
    cout << endl;
}

int main(){
    vector<int> numpy ;
    int size;
    cout << "Enter size of array: ";
    cin >> size;
    cout << "Enter elements: ";
    for(int i = 0;i<size;i++){
        int element;
        cin >> element;
        numpy.push_back(element);
    }
   // bubblesort(numpy);
    //selectionsort(numpy);
    insertionsort(numpy);
    cout << "Sorted array: ";
    printarray(numpy);
}