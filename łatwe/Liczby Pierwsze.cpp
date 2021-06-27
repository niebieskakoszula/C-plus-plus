//https://pl.spoj.com/problems/PRIME_T/

#include <iostream>

using namespace std;

bool Check_If_Prime(int number){
    if(number == 1) return false;

    int q = 0;
    for(int i = 2; i < number; i++){
        if(number % i == 0){
            return false;
        }
    }
    return true;
}

int main()
{
    int tests, input;
    cin >> tests;
    for(int i = 0; i < tests; i++){
        cin >> input;
        if(Check_If_Prime(input)) cout << "TAK" << endl;
        else cout << "NIE" << endl;
    }
    return 0;
}
