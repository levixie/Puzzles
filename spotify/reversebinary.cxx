#include<iostream>
#include<limits.h>
using namespace std;


unsigned int reverse(unsigned int v){
        unsigned int s = sizeof(v) * CHAR_BIT; // bit size; must be power of 2 
        unsigned int mask = ~0;         
        while ((s >>= 1) > 0) 
        {
                mask ^= (mask << s);
                v = ((v >> s) & mask) | ((v << s) & ~mask);
        } 
        while( (v&0x1) == 0 ){
                v=v>>1;
        }
        return v;
}

int main(){
        int n;
        cin>>n;
        cout<<reverse(n)<<endl;

        return 0;
}

