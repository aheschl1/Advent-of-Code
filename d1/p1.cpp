#include<iostream>
#include <string>

using namespace std;
typedef unsigned long long ull;
int main(){
    ull max = 0;

    string temp;
    ull current = 0;
    while(getline(cin, temp)){
        if(temp.size() == 1){
            if(max < current){
                max = current;
            }
            current = 0;
            continue;
        }
        current += stoi(temp);
    }
    cout << max << endl;
    return 0;
}