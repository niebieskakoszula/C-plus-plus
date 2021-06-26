//https://pl.spoj.com/problems/NWW/

#include <iostream>

using namespace std;

unsigned long long Greatest_Common_Factor(unsigned long long first, unsigned long long second){
    unsigned long long temp;
    while(second != 0){
        temp = first % second;
        first = second;
        second = temp;
    }
    return first;
}

unsigned long long Smallest_Common_Multiple(unsigned long long first, unsigned long long second){
    return (first / Greatest_Common_Factor(first, second)) * second;
}

int main()
{
    int tests, amount;
    cin >> tests;
    while(tests--){
        cin >> amount;
        unsigned long long numbers[amount];
        for(int i = 0; i < amount; i++)
            cin >> numbers[i];

        for(int j = 1; j < amount; j++){
            numbers[j] = Smallest_Common_Multiple(numbers[j - 1], numbers[j]);
        }
        cout << numbers[amount - 1] << endl;
    }

    return 0;
}

