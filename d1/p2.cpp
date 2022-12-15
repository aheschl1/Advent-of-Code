#include<iostream>
#include <string>

using namespace std;
typedef unsigned long long ull;

void insertionsort(ull list[], int n){
    for(int sorting = 1; sorting < n; sorting ++){
        int current = list[sorting];
        int checking = sorting - 1;
        while(checking >= 0 && list[checking] > current){
            list[checking + 1] = list[checking];
            checking--;
        }
        list[checking + 1] = current;
    }
}

int main(){
    
    ull maxlist[3];

    string temp;
    ull current = 0;
    while(getline(cin, temp)){
        if(temp.size() == 1){
            if(current > maxlist[0]){
                maxlist[0] = current;
                insertionsort(maxlist, sizeof(maxlist)/sizeof(maxlist[0]));
            }
            current = 0;
            continue;
        }
        current += stoi(temp);
    }
    cout << maxlist[0] + maxlist[1] + maxlist[2] << endl;

    return 0;
}