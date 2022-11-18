#include <iostream>
#include <math.h>
#include <cstdlib>
#include <locale.h>

using namespace std;

int ulamek(int x, int y){
    if(x%y==0)return 1;
    else return 0;
}

float wsk(int tab_tem[3][3]){
    float wynik=0, q;
    int x,y;
    cout<<"det= ";
    for(int i=0; i<3; i++){
            x=i+1; y=i+2;
            if(x>=3) x-=3;
            if(y>=3) y-=3;
            q=tab_tem[0][i]*tab_tem[1][x]*tab_tem[2][y];
            cout<<"+"<<q<<" ";
            wynik+=q;
    }
    for(int i=2; i>=0; i--){
            x=i-1; y=i-2;
            if(x<=-1) x+=3;
            if(y<=-1) y+=3;
            q=tab_tem[0][i]*tab_tem[1][x]*tab_tem[2][y];
            cout<<"-"<<q<<" ";
            wynik-=q;
    }cout<<"= "<<wynik;
    return wynik;
}

void wypisz_tab(int tab[3][3]){
    for(int i=0; i<3; i++){
        cout<<"|";
        for(int j=0; j<3; j++){
            cout<<tab[i][j]<<" ";
        }cout<<"|"<<endl;
    }
}

void wypelnij_tab(float tb[3][3], int tab_tem[3][3], int i){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            tab_tem[i][j]=tb[i][j];
        }
    }
    int x=0;
    switch(i){
        case 0: break;
        case 1:while(x<3){tab_tem[x][0]=(pow(tb[x][0],2)+pow(tb[x][1],2))*(-1); x++;} break;
        case 2:while(x<3){tab_tem[x][1]=(pow(tb[x][0],2)+pow(tb[x][1],2))*(-1); x++;} break;
        case 3:while(x<3){tab_tem[x][2]=(pow(tb[x][0],2)+pow(tb[x][1],2))*(-1); x++;} break;
    }
    wypisz_tab(tab_tem);
}

void kolo(){
	//nie jestem humanista choc jak widzisz tez kiepsko programuje
    float a, b, c, p, q, r;
    float tab[3][3];
    int tab_temp[3][3];
    float wskaznik[4];
    cout << "podawaj wspolrzedne po spacji i potwierdz enterem" << endl;
    cout << "P1(x,y): ";
    cin>>tab[0][0]>>tab[0][1]; tab[0][2]=1;
    cout <<endl<< "P2(x,y): ";
    cin>>tab[1][0]>>tab[1][1]; tab[1][2]=1;
    cout <<endl<< "P3(x,y): ";
    cin>>tab[2][0]>>tab[2][1]; tab[2][2]=1;

    for(int i=0; i<=3; i++){
    wypelnij_tab(tab, tab_temp, i);
    wskaznik[i]=wsk(tab_temp);
    cout<<endl;
    }
    a=wskaznik[1]/wskaznik[0];
    b=wskaznik[2]/wskaznik[0];
    c=wskaznik[3]/wskaznik[0];
    p=a/-2;
    q=b/-2;
    r=pow(p,2)+pow(q,2)-c;
    cout<<"a="<<wskaznik[1]<<"/"<<wskaznik[0]<<endl;
    cout<<"b="<<wskaznik[2]<<"/"<<wskaznik[0]<<endl;
    cout<<"c="<<wskaznik[3]<<"/"<<wskaznik[0]<<endl;
    cout<<"r^2=a^2 + b^2 -c"<<endl;
    cout<<"r^2="<<pow(p,2)<<"+"<<pow(q,2)<<"-"<<c<<endl;
    cout<<"p=a/-2"<<endl;
    cout<<"q=b/-2"<<endl;
    cout<<" Odp1: (x-p)^2 + (y-q)^2 =r^2 \n(x+"<<p*-1<<")^2 + (y+"<<q*-1<<")^2 = "<<r<<endl;
    cout<<" Odp2: S=(p,q)\nS=("<<p<<","<<q<<"), r="<<sqrt(r)<<endl;
}

void skalar(float wk1[], float wk2[]){
    float wynik=0;
    for(int i=0; i<3; i++){
        cout<<wk1[i]*wk2[i]<<"+";
        wynik+=wk1[i]*wk2[i];
    }cout<<"="<<wynik<<endl;
}
float wk_temp[3];
void wektor(float wk3[], float wk4[], bool m){


    float wektorowe[3], q, e;
    for(int i=0; i<3; i++){
        int x=i-1,y=i+1;
        if(x==-1) x+=3;
        if(y==3) y-=3;
        q=wk3[y]*wk4[x];
        e=wk3[x]*wk4[y];
        if(m==0)cout<<" "<<q<<"-"<<e<<" ";
        wektorowe[i]=q-e;
    }
    if(m==1){
        for(int j=0; j<3; j++){wk_temp[j]=wektorowe[j];}
    }
    cout<<"[";
    for(int j=0; j<3; j++){
        cout<<wektorowe[j]<<" ";
    }cout<<"]"<<endl;

}

void mieszane(float wk1[], float wk2[],float wk3[]){
    int odp;
    cout<<"wybierz format rownania: "<<endl;
    cout<<"1 ax(bxc)"<<endl;
    cout<<"2 (axb)xc"<<endl;
    cin>>odp;
    switch(odp){
        case 1:
            cout<<"[";
            for(int j=0; j<3; j++){
                cout<<wk1[j]<<" ";
            }cout<<"]x";
            wektor(wk2, wk3, 1);
            cout<<"=";
            wektor(wk1, wk_temp, 0);
            break;
        case 2:
            wektor(wk1, wk2, 1);
            cout<<"x[";
            for(int j=0; j<3; j++){
                cout<<wk3[j]<<" ";
            }cout<<"]=";
            wektor(wk_temp, wk3,  0);
            break;
    }cout<<endl;
}

void trzy_wek(float wk1[], float wk2[], float wk3[]){
    int tab_wek[3][3];
    for(int i=0; i<3; i++){
        tab_wek[0][i]=wk1[i];
        tab_wek[1][i]=wk2[i];
        tab_wek[2][i]=wk3[i];
    }
    wsk(tab_wek);
}

void wektory_menu(){
    system("cls");
    int odp;
    float wek1[3];
    float wek2[3];
    float wek3[3];
    cout << "podaj wektory a, b i c (w postaci (x,y,z)): " << endl;
    cout << "a: " << endl;
    cin>>wek1[0]>>wek1[1]>>wek1[2];
    cout << "b: " << endl;
    cin>>wek2[0]>>wek2[1]>>wek2[2];
    cout << "c: " << endl;
    cin>>wek3[0]>>wek3[1]>>wek3[2];

    do{
    cout << "wybierz rownanie: " << endl;
    cout << "1 iloczyn skalarny *" << endl;
    cout << "2 iloczyn wektorowy x" << endl;
    cout << "3 iloczyn mieszany" << endl;
    cout << "4 iloczyn wektorowy 3 wektorow " << endl;
    cout << "5 powrot do menu " << endl;
    cin>>odp;
    switch(odp){
        case 1: skalar(wek1, wek2); break;
        case 2: wektor(wek1, wek2, 0); break;
        case 3: mieszane(wek1, wek2, wek3); break;
        case 4: trzy_wek(wek1, wek2, wek3); break;
    }
    }while(odp!=5);
}

void prosta_pros(){
    float xo, yo, A, B;
    cout<<"podaj punkt Po[xo,yo] przez ktory przechodzi prosta l:"<<endl;
    cin>>xo>>yo;
    cout<<"podaj wektor N[A,B] do ktorego prosta l  jest prostopadla:"<<endl;
    cin>>A>>B;
    cout<<"wzor A(x-xo)+B(y-yo)"<<endl;
    if(B>0) cout<<"y= "<<-A<<"/"<<B<<"x+ "<<((A*xo)+(B*yo))<<"/"<<B;
    else cout<<"y= "<<A<<"/"<<-B<<"x+ "<<((A*xo)+(B*yo))*-1<<"/"<<-B;
}

void prosta_rown(){
    float xo, yo, A, B;
    cout<<"podaj punkt Po[xo,yo] przez ktory przechodzi prosta l:"<<endl;
    cin>>xo>>yo;
    cout<<"podaj wektor N[A,B] do którego prosta l  jest rownolegla:"<<endl;
    cin>>A>>B;
    cout<<"wzor: B(x-xo)-A(y-yo)"<<endl;
    if(A>0) cout<<"y= "<<B<<"/"<<A<<"x+ "<<((B*xo*-1)+(A*yo))<<"/"<<A;
    else cout<<"y= "<<-B<<"/"<<A<<"x+ "<<((B*xo)-(A*yo))<<"/"<<A;
}

void odleglosc(){
    float p1, p2, a, b, c, licznik, mianownik;
    cout<<"podaj punkt: "<<endl;
    cin>>p1>>p2;
    cout<<"podaj rownanie prostej _x+_y+_=0 "<<endl;
    cin>>a>>b>>c;
    cout<<"|A*x + B*y +C|"<<endl;
    cout<<"______________"<<endl;
    cout<<"-vTA^2 + B^2' <-to jest pierwiastek"<<endl<<endl;

    cout<<"="<<endl;

    cout<<"|"<<p1*a<<"+"<<p2*b<<"+"<<c<<"|"<<endl;
    cout<<"______________"<<endl;
    cout<<"-vT"<<pow(a,2)<<"+"<<pow(b,2)<<"'"<<endl<<endl;

    cout<<"="<<endl;

    cout<<"|"<<(p1*a)+(p2*b)+c<<"|"<<endl;
    cout<<"______________"<<endl;
    cout<<"-vT"<<pow(a,2)+pow(b,2)<<"'"<<endl<<endl;

    cout<<"="<<endl;

    licznik=(p1*a)+(p2*b)+c;
    if(licznik<0) licznik*=-1;
    mianownik=sqrt(pow(a,2)+pow(b,2));
    if (mianownik == (int)mianownik){
        if(ulamek(licznik, mianownik)) cout<<licznik/mianownik<<endl;
        else cout<<licznik<<"/"<<mianownik<<endl;
    }else{
        mianownik=pow(a,2)+pow(b,2);
        cout<<licznik<<endl;
        cout<<"______________"<<endl;
        cout<<"-vT"<<mianownik<<"'"<<endl<<endl;

        cout<<"="<<endl;

        cout<<licznik<<"*-vT"<<mianownik<<"'"<<endl;
        cout<<"______________"<<endl;
        cout<<mianownik<<endl<<endl;

        if(ulamek(licznik, mianownik)){
                cout<<"="<<endl;
                cout<<licznik/mianownik<<"*-vT"<<mianownik<<"'"<<endl;
        }
    }

}

void wypelnij_tabc(float tb[3][3], int tab_tem[3][3], float tb2[3], int i){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            tab_tem[i][j]=tb[i][j];
        }
    }
    int x=0;
    switch(i){
        case 0: break;
        case 1:while(x<3){tab_tem[x][0]=tb2[x]; x++;} break;
        case 2:while(x<3){tab_tem[x][1]=tb2[x]; x++;} break;
        case 3:while(x<3){tab_tem[x][2]=tb2[x]; x++;} break;
    }
    for(int i=0; i<3; i++){
        cout<<"|";
        for(int j=0; j<3; j++){
            cout<<tab_tem[i][j]<<" ";
        }cout<<"|"<<endl;
    }
}

void cramer(){
    int x,y,z,q;
    float tab[3][3];
    float tab2[3];
    int tab_temp[3][3];
    float wskaznik[4];
    cout << "podawaj zawartosc macierzy po spacji i potwierdz enterem" << endl;
    cout << "rzad 1: ";
    cin>>tab[0][0]>>tab[0][1]>>tab[0][2];
    cout <<endl<< "rzad 2: ";
    cin>>tab[1][0]>>tab[1][1]>>tab[1][2];
    cout <<endl<< "rzad 3: ";
    cin>>tab[2][0]>>tab[2][1]>>tab[2][2];

    cout << "druga macierz ";
    cin>>tab2[0]>>tab2[1]>>tab2[2];

    for(int i=0; i<=3; i++){
    wypelnij_tabc(tab, tab_temp, tab2, i);
    wskaznik[i]=wsk(tab_temp);
    }

    q=wskaznik[0];
    x=wskaznik[1];
    y=wskaznik[2];
    z=wskaznik[3];
    cout<<"wyznacznik macierzy ="<<q<<endl;
    if(x%q==0) cout<<"x="<<x/q<<endl;
    else cout<<"x="<<x<<"/"<<q<<endl;
    if(y%q==0) cout<<"y="<<y/q<<endl;
    else cout<<"y="<<y<<"/"<<q<<endl;
    if(z%q==0) cout<<"z="<<z/q<<endl;
    else cout<<"z="<<z<<"/"<<q<<endl;
}

void zesp_przelicz(){
    int odp, odp2;
    punkt:
    cout << "wybierz poczatkowa postac" << endl;
    cout << "1. trygonometryczna (|z|(cosa+isina))" << endl;
    cout << "2. wykladnicza (|z|e^ia)" << endl;
    cout << "3. algebraiczna (a+bi)" << endl;
    cin>>odp;
    cout << "wybierz koncowa postac" << endl;
    cout << "1. trygonometryczna (|z|(cosa+isina))" << endl;
    cout << "2. wykladnicza (|z|e^ia)" << endl;
    cout << "3. algebraiczna (a+bi)" << endl;
    cin>>odp2;
    if(odp==odp2){cout<<"nie wiesz jak to dziala prawda?"<<endl; goto punkt;}
    switch(odp){
        case 1:
            switch(odp2){
                case 2: cout<<"|z|(cosa+isina) = |z|e^ia";break;
                case 3: cout<<"|z|(cosa+isina)\n a=|z|*cosa, b=|z|*sina*i";break;
            }
            break;
        case 2:
            switch(odp2){
                case 1: cout<<"|z|e^ia = |z|(cosa+isina)";break;
                case 3: cout<<"|z|e^ia = |z|(cosa+isina)\n a=|z|*cosa, b=|z|*sina*i";break;
            }
            break;
        case 3:
            switch(odp2){
                case 1: cout<<"a+bi\n cosa=a/|z|, sina=b/|z|\n |z|(cosa+isina)";break;
                case 2: cout<<"a+bi\n oblicz kat a i modul |z|e^ia";break;
            }
            break;
    }
}

void zesp_pierw(){
    float mod, kat;
    int stopien;
    cout<<"podaj modul liczby zespolonej (podniesiony do potegi 2):"<<endl;
    cin>>mod;
    cout<<"podaj kat:"<<endl;
    cin>>kat;
    cout<<"podaj stopien:"<<endl;
    cin>>stopien;
    cout<<"wzór ogolny:"<<endl;
    cout<<"n -> stopien pierwiastka"<<endl;
    cout<<"k -> 'aktualny stopien' (dla kazdego stopnia jest rozwiazanie -> pierwiastek 4 stopnia bêdzie mial 4 rozwiazania"<<endl;
    cout<<"|z| -> modul"<<endl;
    cout<<"wk = n-vT|z|(cos(fi+2*k*pi)/n + i*sin(fi+2*k*pi)/n)"<<endl;
    for(int i=0; i<stopien; i++){
        cout<<stopien*2<<"-vT"<<mod<<"(cos"<<(kat+2*i*180)/stopien<<"+i*sin"<<(kat+2*i*180)/stopien<<")"<<endl;
    }
}

void zespolone_menu(){
    system("cls");
    cout << "to rozwijana czesc programu -> wiecej znajdziecie w notatkach i internecie" << endl;
    int odp;
    cout<<"dopiero w planach\n podeslij jakies dobre notatki to moze pojdzie latwiej"<<endl;
    cout << "1. przeliczanie postaci - wzory" << endl;
    cout << "2. pierwiastek n-tego stopnia" << endl;
    cin>>odp;
    switch(odp){
        case 1: zesp_przelicz(); break;
        case 2: zesp_pierw(); break;
    }
}

void mnozenie_macierzy(int tab1[3][3], int tab2[3][3]){
    int wynik[3][3];
    for(int x=0; x<3; x++){
        for(int y=0; y<3; y++){
            wynik[x][y]=(tab1[x][0]*tab2[0][y])+(tab1[x][1]*tab2[1][y])+(tab1[x][2]*tab2[2][y]);
        }
    }
    wypisz_tab(wynik);
}

void odwaracanie_macierzy(){
    int tab[3][3], tab_przej[4], tab_D[3][3], tab_1[3][3];
    cout << "podaj tablice do odwrocenia" << endl;
    cout << "pierwszy rzad: ";
    cin>>tab[0][0]>>tab[0][1]>>tab[0][2];
    cout <<endl<< "drugi rzad: ";
    cin>>tab[1][0]>>tab[1][1]>>tab[1][2];
    cout <<endl<< "trzeci rzad: ";
    cin>>tab[2][0]>>tab[2][1]>>tab[2][2];

    wypisz_tab(tab);
    int w=wsk(tab);
    for(int x=0; x<3; x++){
        for(int y=0; y<3; y++){
            int i=0, u=pow(-1,x+y+2);
            for(int q=0; q<3; q++){
                for(int e=0; e<3; e++){
                    if((q!=x)&&(e!=y)){
                        tab_przej[i]=tab[q][e];
                        i++;
                    }
                }
            }
            tab_D[x][y]=((tab_przej[0]*tab_przej[3])-(tab_przej[1]*tab_przej[2]))*u;
        }
    }

    cout <<endl<< "macierz dopelnien"<<endl;
    wypisz_tab(tab_D);
    swap(tab_D[1][0], tab_D[0][1]);
    swap(tab_D[2][0], tab_D[0][2]);
    swap(tab_D[2][1], tab_D[1][2]);
    cout <<endl<< "macierz transponowana"<<endl;
    wypisz_tab(tab_D);
    cout<<"*1/"<<w;
    cout <<endl<< "mnozeneie przez macierz jedynek"<<endl;
    for(int x=0; x<3; x++){
        for(int y=0; y<3; y++){
            tab_1[x][y]=1;
        }
    }
    mnozenie_macierzy(tab_D,tab_1);
    cout<<"*1/"<<w;

}

void macierz_4(){
    int tab[4][4], tab_przej[3][3], wskaznik;
    cout << "podaj tablice 4 stopnia" << endl;
    cout << "pierwszy rzad: ";
    cin>>tab[0][0]>>tab[0][1]>>tab[0][2]>>tab[0][3];
    cout <<endl<< "drugi rzad: ";
    cin>>tab[1][0]>>tab[1][1]>>tab[1][2]>>tab[1][3];
    cout <<endl<< "trzeci rzad: ";
    cin>>tab[2][0]>>tab[2][1]>>tab[2][2]>>tab[2][3];
    cout <<endl<< "czwarty rzad: ";
    cin>>tab[3][0]>>tab[3][1]>>tab[3][2]>>tab[3][3];

    int x=0,y=0;
    for(int i=0; i<4; i++) if(tab[i][0]==0) x++;
    for(int i=0; i<4; i++) if(tab[0][i]==0) y++;

    int wynik=0;
    int q=0,e=0;
    for(int i=0; i<4; i++){
        int o=0,p=0;
        if(tab[q][e]!=0){
            for(int a=0; a<4; a++){
                for(int b=0; b<4; b++){
                    if((a!=q)&&(b!=e)){
                        tab_przej[o][p]=tab[a][b];
                        p++;
                        if(p==3){p=0; o++;}
                    }
                }
            }
        int u;
        if(i%2==0)u=1;
        else u=-1;
        wypisz_tab(tab_przej);
        float wskaznik=wsk(tab_przej);
        cout<<"    ("<<tab[q][e]<<"*"<<wskaznik<<")*(-1)^"<<q+e+2<<endl;
        wynik+=tab[q][e]*wskaznik*u;
        }else{
        wskaznik=0;
        cout<<"(tablica pomnozona przez zero -> nie ma sensu liczyc)"<<endl;
        }
        if((x>y)||(x==y)){q++;}else e++;
    }cout<<"="<<wynik;

}

void menu(){
    system("cls");
    int odp;
    cout << "wybierz zadanie: " << endl;
    cout << "1 okrag" << endl;
    cout << "2 wektory" << endl;
    cout << "3 prosta przechodzaca przez punkt i prostopadla do wektora" << endl;
    cout << "4 prosta przechodzaca przez punkt i rownolegla do wektora" << endl;
    cout << "5 odleglosc punktu od prostej" << endl;
    cout << "6 metoda cramera" << endl;
    cout << "7 liczby zespolone" << endl;
    cout << "8 odwracanie macierzy" << endl;
    cout << "9 wyznacznik macierzy 4 stopnia" << endl;
    cout << "10 zakoncz" << endl;
    cin>>odp;
    switch(odp){
        case 1: kolo(); break;
        case 2: wektory_menu(); break;
        case 3: prosta_pros(); break;
        case 4: prosta_rown(); break;
        case 5: odleglosc(); break;
        case 6: cramer(); break;
        case 7: zespolone_menu(); break;
        case 8: odwaracanie_macierzy(); break;
        case 9: macierz_4(); break;
        case 10: break;
    }
}

int main()
{
    char odp;
    do{
    menu();
    cout<<endl<<"czy zakonczyc? (t/n)"<<endl;
    cin>>odp;
    }while(odp!='t');
    return 0;
}
