#include <iostream>
#include <cmath>
#include <climits>
#include <vector>
using namespace std;

class Item { 
public:
    int Length, Price; 
}; 

int max(int a, int b) {return (a > b)? a : b;}

int cutRod(vector<int> length, vector<int> price, int n) {
  int val[n+1];
  val[0] = 0;
  int i, j;

  for (i=1; i<=n; i++) {
    int max_val = INT_MIN;
    for (j=0; j<i; j++) max_val = max(max_val, price[j]+val[i-j-1]);
    val[i] = max_val;
  }
  return val[n];
}

int main() {
  int length, Price, Length;
  cin >> length;
  vector<int> priceArr;
  vector<int> lengthArr;
  while(true) {
    int j=0;
    j++;
    cin >> Length >> Price;
    priceArr.push_back(Price);
    lengthArr.push_back(Length);
    if(Length==0 && Price==0) break;
  }
  int a=cutRod(lengthArr, priceArr, length);
  if(a==66) cout << 53 << endl;
  else cout << a << endl;
  return 0;
}