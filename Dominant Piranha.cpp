//https://codeforces.com/contest/1433/problem/C

#include <iostream>
#include <vector>

using namespace std;

vector <int> pirahnas_sizes;
int amount_of_piranhas;
int biggest_size;

void Read_Piranhas_Sizes() {
    for (int i = 0; i < amount_of_piranhas; i++)
        cin >> pirahnas_sizes[i];
}

void Find_Biggest_Piranha() {
    biggest_size = 0;
    for (int i = 0; i < amount_of_piranhas; i++)
        if (pirahnas_sizes[i] > biggest_size)
            biggest_size = pirahnas_sizes[i];
}

int Find_Dominant_Pirahna_Position() {
    int position = -1;
    for (int i = 0; i < amount_of_piranhas; i++) {
        if (pirahnas_sizes[i] != biggest_size) {
            continue;
        }
        if (i - 1 >= 0 && pirahnas_sizes[i - 1] < biggest_size) {
            position = i + 1;
            break;
        }
        if (i + 1 < amount_of_piranhas && pirahnas_sizes[i + 1] < biggest_size) {
            position = i + 1;
            break;
        }
    }
    return position;
}

int main()
{
    int tests;
    cin >> tests;
    while (tests--) {
        cin >> amount_of_piranhas;
        pirahnas_sizes.resize(amount_of_piranhas);
        Read_Piranhas_Sizes();
        Find_Biggest_Piranha();

        cout << Find_Dominant_Pirahna_Position() << endl;
    }
    return 0;
}
