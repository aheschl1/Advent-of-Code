#include<iostream>
#include<string>
using namespace std;

int main(){
    string line;
    int count = 0;
    while(cin >> line){
        string firststring1, secondstring1;
        string firststring2, secondstring2;
        bool firstsection = true;
        bool firstelf = true;
        for(const char &c : line){
            if(firstelf){
                if(firstsection && !(c=='-')){
                    firststring1 += c;
                    continue;
                }else if(c=='-'){
                    firstsection = false;
                    continue;
                }
                if(!(c == ',')){
                    secondstring1 += c;
                    continue;
                }
                firstsection = true;
                firstelf = false;
            }else{
                if(firstsection && !(c=='-')){
                    firststring2 += c;
                    continue;
                }else if(c=='-'){
                    firstsection = false;
                    continue;
                }
                secondstring2 += c;
            }
        }
        int first1, second1, first2, second2;
        first1 = stoi(firststring1);
        second1 = stoi(secondstring1);
        first2 = stoi(firststring2);
        second2 = stoi(secondstring2);
        if((first1 >= first2 && second1 <= second2) || (first2 >= first1 && second2 <= second1)){
            count ++;
        }
    }
    cout << count << endl;
    return 0;
}