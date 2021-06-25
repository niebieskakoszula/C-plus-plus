//https://pl.spoj.com/problems/JGGHACK/
#include <bits/stdc++.h>

using namespace std;

int char_value(char x){
    return x - 'A';
}

int main()
{
    string input, result;
    int first_letter, second_letter;
    while(cin>>input){
        result="";
        for(int i = 0; i < 20; i += 2){
            first_letter = char_value(input[i]);
            second_letter = char_value(input[i+1]) * 16;
            result.push_back((char)first_letter + second_letter);
        }
        cout<<result<<endl;
    }
    return 0;
}

