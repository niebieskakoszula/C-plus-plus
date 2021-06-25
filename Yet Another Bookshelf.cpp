//https://codeforces.com/contest/1433/problem/B

#include <bits/stdc++.h>

using namespace std;

int shelf_size;
int books[50];


void Read_Input(){
    for (int i = 0; i < shelf_size; i++)
        cin >> books[i];
}

int Find_First_Book() {
    for (int i = 0; i < shelf_size; i++)
        if (books[i] == 1)
            return i;
}
int Find_Last_Book() {
    for (int i = shelf_size - 1; i >= 0; i--)
        if (books[i] == 1)
            return i;
}
int Count_Minimum_Moves(int start, int end_index){
    int min_moves = 0;
    for (int i = start; i < end_index; i++) {
        if (books[i] == 0) min_moves++;
    }
    return min_moves;
}

int main()
{
    int tests, first_book_index, last_book_index;
    cin >> tests;
    for(int j = 0; j < tests; j++) {
        cin >> shelf_size;
        Read_Input();
        first_book_index = Find_First_Book();
        last_book_index = Find_Last_Book();

        cout << Count_Minimum_Moves(first_book_index, last_book_index) << endl;
    }

    return 0;
}

