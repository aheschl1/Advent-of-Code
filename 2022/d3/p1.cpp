#include<iostream>
#include<map>

using namespace std;

int priority(string search, char target, int min, int max){
    unsigned int mid = min+((max-min)/2);
    if(search[mid] == target){
        if(mid > 25){
            return mid - 25;
        }
        return mid + 27;
    }
    if(search[mid] > target){
        return priority(search, target, min, mid-1);
    }else{
        return priority(search, target, mid+1, max);
    }
}

int main(){
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    unsigned int score = 0;
    string input;
    while(cin >> input){
        map<char, unsigned int> reocurrence;
        int length = input.size()/2;
        for(int i = 0; i < length; i++){
            reocurrence[input[i]] = 1;
        }
        for(int i = length; i < 2*length; i++){
            if(reocurrence[input[i]]){
                score += priority(alphabet, input[i], 0, alphabet.size()-1);
                break;
            }
        }
    }
    cout << score << endl;
    return 0;
}