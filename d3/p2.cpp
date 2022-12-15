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
    string temp1, temp2, temp3;
    unsigned int total = 0;
    while(cin >> temp1 >> temp2 >> temp3){
        map<char, unsigned int> frequency;
        map<char, unsigned int> occurence;
        char key;
        for(const char &c: temp1){
            if(occurence[c] != 1){occurence[c] = 1;}
            frequency[c]++;
        }
        for(const char &c: temp2){
            if(occurence[c] == 1){occurence[c] = 2;}
            frequency[c]++;
        }
        for(const char &c: temp3){
            if(occurence[c] == 2){occurence[c] = 3; key = c;}
            frequency[c]++;
        }
        total += priority(alphabet, key, 0, alphabet.size()-1);
    }
    cout << total << endl;

    return 0;
}