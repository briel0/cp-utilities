#include <bits/stdc++.h>
using namespace std;

int main(){

    //check if the j-th (0-based) bit is on
    //testing for j = 3
    int s = 34, j = 1;
    int t = s & (1 << j);

    //if t != 0 (to be precise, t = (1 << j))
    bool c = (t != 0);
    cout << t << ' ' << c;
    
    //to turn of the j-th bit
    //~ not operation
    //100010 AND 111101
    s &= ~(1 << j);
    
    //flip the j-th bit
    //once that XOR returns TRUE only if both bits are different
    s ^= (1 << j);
    
    //to get the least significant bit
    t = (s & (-s));
    
    //all n bits on
    s = (1 << n) - 1;
  
}
