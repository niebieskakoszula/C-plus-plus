//https://pl.spoj.com/problems/JGGHACK/

#include <iostream>
#include <string>
#include<stdio.h>
 
using namespace std;
 
int wartosc_P(char x){
    switch(x){
        case 'A': return 0; break;
        case 'B': return 1; break;
        case 'C': return 2; break;
        case 'D': return 3; break;
        case 'E': return 4; break;
        case 'F': return 5; break;
        case 'G': return 6; break;
        case 'H': return 7; break;
        case 'I': return 8; break;
        case 'J': return 9; break;
        case 'K': return 10; break;
        case 'L': return 11; break;
        case 'M': return 12; break;
        case 'N': return 13; break;
        case 'O': return 14; break;
        case 'P': return 15; break;
    }
}
 
int wartosc_D(char x){
    switch(x){
        case 'A': return 0; break;
        case 'B': return 16; break;
        case 'C': return 32; break;
        case 'D': return 48; break;
        case 'E': return 64; break;
        case 'F': return 80; break;
        case 'G': return 96; break;
        case 'H': return 112; break;
        case 'I': return 128; break;
        case 'J': return 144; break;
        case 'K': return 160; break;
        case 'L': return 176; break;
        case 'M': return 192; break;
        case 'N': return 208; break;
        case 'O': return 224; break;
        case 'P': return 240; break;
    }
}
 
int main()
{
    string haslo;
    while(cin>>haslo){
            string deszyf="";
        for(int i=0; i<20; i+=2){
            int x,y,z;
            x=wartosc_P(haslo[i]);
            y=wartosc_D(haslo[i+1]);
            z=x+y;
            char q=(char)z;
            deszyf.push_back(q);
        }cout<<deszyf<<endl;
    }
    return 0;
}
