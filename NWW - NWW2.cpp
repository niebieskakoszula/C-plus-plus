//https://pl.spoj.com/problems/NWW/

    #include <iostream>
     
    using namespace std;
     
    unsigned long long nwd(unsigned long long a, unsigned long long b){
        unsigned long long c;
        while(b!=0){
            c=a%b;
            a=b;
            b=c;
        }
        return a;
    }
     
    unsigned long long nww(unsigned long long a, unsigned long long b){
        return (a/nwd(a,b))*b;
    }
     
    int main()
    {
        int t,n;
        cin>>t;
        while(t){
            cin>>n;
            unsigned long long tab[n];
            for(int i=0; i<n; i++) cin>>tab[i];
            for(int j=1; j<n; j++){
                tab[j]=nww(tab[j-1],tab[j]);
            }
            cout<<tab[n-1]<<endl;
            t--;
        }
     
        return 0;
    }
     
