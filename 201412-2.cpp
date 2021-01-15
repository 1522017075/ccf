#include<iostream>
using namespace std;
int n;

int direction(int x, int y){ // (��1)(�L2)(��3)(�J4) 
	int result = 0;
	if(x == 0 && y != (n - 1)){ // ��һ�� 
		if((x + y) & 1){ // ż������ 
			 result = 2;
		} else { // ������ 
			result = 1;
		}
	} else if(y == 0 && x != (n - 1)){ // ��һ�� 
		if((x + y) & 1){ // ż���J 
			 result = 3;
		} else { // ������ 
			result = 4;
		}
	} else if(x == (n - 1)){ // ���һ�� 
		if((x + y) & 1){ // ż���� 
			 result = 1;
		} else { // �������� 
			result = 4;
		}
	} else if(y == (n - 1)){ // ���һ�� 
		if((x + y) & 1){ // ż���L 
			 result = 2;
		} else { // ������ 
			result = 3;
		}
	} else { // ���ڱ߽� 
		if((x + y) & 1){ // ż���L
			 result = 2;
		} else { // �����J 
			result = 4;
		}
	}
	return result; 
}
int main(){
	cin >> n;
	int matrix[n][n] = {{0}};
	for(int i = 0; i < n; i++){ // initial matrix
		for(int j = 0; j < n; j++){
			cin >> matrix[i][j];
		}
	}
	cout << matrix[0][0];
	int x = 0, y = 1, index = 0;
	for(int i = 0; i < n * n - 1; i++){
		cout << " " << matrix[x][y];
		index = direction(x, y); // (��1)(�L2)(��3)(�J4) 
		if(index == 1){
			y++;
		} else if(index == 2){
			y--;
			x++;
		} else if(index == 3){
			x++;
		} else {
			y++;
			x--;
		}
	}
	cout << endl;
	return 0;
} 
