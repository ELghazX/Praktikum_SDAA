#include <iostream>
using namespace std;
void hanoi(int n,char a,char b, char c);

int main (){
int n = 3;
cout<<" ========================================"<<endl;
cout<<endl;
hanoi(n, 'A', 'B', 'C');
cout<<" ========================================"<<endl;

return 0;
}

void hanoi (int n, char a, char b, char c){
    if(n==1){
        cout<<"Pindah Bagian atas Piring dari "<<a<<" ke "<<c<<endl;
    }
    else{
        hanoi (n-1, a, c, b);
        hanoi (1 , a, b, c);    
        hanoi (n-1, b, a, c);
    }
}
