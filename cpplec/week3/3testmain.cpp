//
//  3testmain.cpp
//  cpplec
//
//  Created by 하동준 on 2021/03/15.
//

#include <iostream>
#include <string>
using namespace std;

int* makeArray(const int SIZE){
    int* temp = new int[SIZE];
    for(int i =0;i<SIZE;i++)
        temp[i] = rand() % 10;
    return temp;
}

void printArray(int* (&arr), const int SIZE){
    for(int i = 0; i<SIZE;i++)
        cout << arr[i] << "`t";
    cout << endl;
}

#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new (_NORMAL_BLOCK , _FILE_,_LINE_)
#define new DBG_NEW
#endif // !DBG_NEW
#endif

int main(){
    //&는 변수의 메모리 주소값
    
    //_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    int* arr = makeArray(10);
    printArray(arr,10);
    delete[] arr;
    arr = nullptr;
    
    /*int arr[3][4];
    cout << typeid(arr).name() << endl;   //typeinfo
    cout << typeid(arr[0]).name() << endl;   //typeinfo
    cout << typeid(arr[0][0]).name() << endl;   //typeinfo
     타입정보보는법*/
    
/*A3_A4_i
 A4_i
 i*/
    /*int* parr=arr;
     int(*parr)[3][4]=&arr;
     int(*parr)[4]=arr;
     */
    
   /*int col;
    cin>>col;
    int* parr = new int[col];
    delete[] parr;
    parr = nullptr;
   1차원 */
    
    /*int row, col;
    cin >> row >> col;
    int* (* parr)=new int* [row];
    for(int i=0;i<row;i++){
        parr[i] = new int[col];
    }
    
    for(int i=0;i<row;i++)
        delete[] parr[i];
    delete[] parr;
    parr=nullptr;
    2차원생성 삭제
     */
    
    
}
