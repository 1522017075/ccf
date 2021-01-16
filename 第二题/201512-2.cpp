#include<iostream>
using namespace std;

int main(){  
	int n, m;
	cin >> n >> m;
	int map[n][m] = {{0}};
	int destory[n][m] = {{0}}; // record that destoried checker
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> map[i][j];
			destory[i][j] = 1;
		}
	}
	for(int i = 0; i < n; i++){ // row
		for(int j = 1; j < m - 1; j++){
			if((map[i][j-1] == map[i][j]) && (map[i][j] == map[i][j+1])){
				destory[i][j-1] = 0;
				destory[i][j] = 0;
				destory[i][j+1] = 0;
			}
		}
	}
	for(int i = 1; i < n - 1; i++){ // column
		for(int j = 0; j < m; j++){
			if((map[i-1][j] == map[i][j]) && (map[i][j] == map[i+1][j])){
				destory[i-1][j] = 0;
				destory[i][j] = 0;
				destory[i+1][j] = 0;
			}
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(destory[i][j]){
				cout << map[i][j] << " ";
			} else {
				cout << 0 << " ";
			}
		}
		cout << endl;
	}
	return 0;
}
/*
	����˼�룺
	��������ά���飬
	һ�������һ������Щ��Ӧ�ñ�������
	���к��зֱ��ж�ÿ�����Ƿ�������
	�������������ľ�������������ԭ���� 
*/ 
