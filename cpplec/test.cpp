/*
#include <stdio.h>
#include "djh.h"
#include <string>
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>


using namespace std;

int main(){
    ifstream fin("movie.txt");
    if (!fin.is_open()){
        cerr << "파일 오픈 실패";
        exit(0);
    }
        
    string buffer;
    string name[100];
    fin>>name[0];
    getline(fin, name[1]);
    
    return 0;
}

*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
   ifstream fin("movie.txt");
   int n; fin >> n;
    
    string n_arr[n];
    string row[n];
    string col[n];


   for (int i = 0; i < n*2; i++) {
      string name; getline(fin, name);
      cout << name;
       n_arr[i]=name;
      string a, b; fin >> a >> b;
       row[i]=a; col[i]=b;
      cout << a << " " << b << endl;
   }
   fin.close();
   return 0;
}
