#include<iostream>
using namespace std;

int main(){
	int n, k, sum = 0, result = 0, weight = 0;
	cin >> n >> k;
	while(n--){
		cin >> weight;
		sum = sum >= k ? (++result, weight) : sum + weight;
	}
	cout << result + (sum > 0) << endl;
	return 0;
}
