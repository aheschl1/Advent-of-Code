#include<iostream>
#include<vector>
#include<map>
#include<string>

using namespace std;

int main(){
    map<unsigned short, vector<char>> stack;
    for(int i = 0; i < 8; i++){
        string temp;
        getline(cin, temp);
        unsigned short stacknum = 1;
        //input stacks
        for(int i = 0; i < sizeof(temp)/sizeof(temp[0]) + 1; i+=4){
            char item = temp[i+1];
            if(item != ' '){
                stack[stacknum].insert(stack[stacknum].begin(), item);
            }
            stacknum++;
        }
    }
    //getemptylines
    string garbage;
    getline(cin, garbage);
    getline(cin, garbage);
    //
    unsigned int quantity, from, to;
    while(cin >> garbage >> quantity >> garbage >> from >> garbage >> to){
        vector<char> tempvect;
        for(int i = 0; i < quantity; i++){
            char element = stack[from][stack[from].size()-1];
            tempvect.push_back(element);
            stack[from].pop_back();
        }
        for(int x = tempvect.size() - 1; x >= 0; x--){
            stack[to].push_back(tempvect[x]);
        }
    }

    //show result
    for(int w = 1; w < 10; w++){
        cout << stack[w][stack[w].size()-1];
    }
    cout << endl;
    return 0;
}