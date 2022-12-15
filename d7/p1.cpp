#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<string>
#include<algorithm>
#include<queue>
#include"dir.h"

typedef long long int ll;
typedef unsigned long long ull;

using namespace std;

void insertion_sort(vector<ull> &arr){
    for(int sorting = 1; sorting < arr.size(); sorting ++){
        int current = arr[sorting];
        int checking = sorting - 1;
        while(checking >= 0 && arr[checking] > current){
            arr[checking + 1] = arr[checking];
            checking--;
        }
        arr[checking + 1] = current;
    }
}

void new_command(string command, Directory *currentDir){
    if(command.substr(0,4) == "$ cd"){
        string newDirLabel = command.substr(5);
        if(newDirLabel[0] == '.'){
            currentDir = currentDir->getParent();
        }else{
            //move forward
            Directory *child = currentDir->containsChild(newDirLabel);
            if( child == nullptr){
                Directory *newDir = new Directory(newDirLabel, currentDir);
                currentDir->addChildDir(newDir);
                currentDir = newDir;
            }else{
                currentDir = child;
            }
        }
        //next command
        string newest_command;
        if(std::getline(cin, newest_command)){
            new_command(newest_command, currentDir);
        }
    }else if(command.substr(0,4) == "$ ls"){
        //ls
        string output = "";
        while(std::getline(cin, output) && output[0]!='$'){
            if(output[0] == 'd'){
                //dir
                Directory *child = currentDir->containsChild(output.substr(4));
                if(child == nullptr){
                    Directory *newDir = new Directory(output.substr(4), currentDir);
                    currentDir->addChildDir(newDir);
                }
            }else{
                //file
                currentDir->addFile(stoi(output));
            }
        }
        if(output[0] == '$'){
            new_command(output, currentDir);
        }
    }

}
void solve(){
    string label = "/";
    Directory *rootDir = new Directory(label);
    string line;
    std::getline(cin, line);
    std::getline(cin, line);
    new_command(line, rootDir);
    rootDir->getChildDirs()[0]->getSize();

    ull total = 0;
    vector<ull> sizes;
    rootDir->get_map(sizes);
    insertion_sort(sizes);

    const unsigned int required_space = 30000000;
    unsigned int total_space = 70000000;
    unsigned int used_space = sizes[sizes.size()-1];
    unsigned int required_delete = used_space-(total_space-required_space);
    
    for(ull entry : sizes){
        if(entry >= required_delete){
            cout << entry << endl;
            break;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}