#include <iostream>
using namespace std;


int main() {
    // int a = 10;
    // int* ptr = &a;
    // int** ptr2 = &ptr;
    // cout<<*ptr<<endl;
    // cout<<**ptr2<<endl;
    // cout<<*(&a)<<endl;
    int arr[] = {1,2,3,4,5};
    cout<<*arr<<endl;
    cout<<*(arr+1)<<endl;
    cout<<*(arr+2)<<endl;
    cout<<*(arr+3)<<endl;
    return 0;
}
