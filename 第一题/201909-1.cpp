#include<iostream>
using namespace std;

int main(){
	int n, m, sum = 0, tree, temp, tempSum, tempMax = 0, treeIndex = 0;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		tempSum = 0;
		cin >> tree;
		for(int j = 0; j < m; j++){
			cin >> temp;
			tempSum -=temp;
		}
		if(tempSum > tempMax){ // �����߹������� 
			tempMax = tempSum;
			treeIndex = i;
		}
		sum += (tree - tempSum); // ���й��� 
	}
	printf("%d %d %d\n", sum, treeIndex, tempMax);
	return 0;
}
