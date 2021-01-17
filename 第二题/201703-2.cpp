#include<iostream>
using namespace std;
int student[1001] = {0};

void toward(int index, int dis){ // ���±�index�ĸ�����ǰdis������ 
	int num = student[index];
	for(int i = 0; i < dis; i++){
		student[index - i] = student[index - i - 1];
	}
	student[index - dis] = num;
}
void backward(int index, int dis){ // ���±�index�ĸ�������dis������ 
	int num = student[index];
	for(int i = 0; i < dis; i++){
		student[index + i] = student[index + i + 1];
	}
	student[index + dis] = num;
}

int findIndex(int num){ // �ҵ�ѧ��num���±�index 
	int index = 1;
	while(student[index] != num){
		index++;
	}
	return index;
}

int main(){
	int n, m, num, dis;
	cin >> n;
	for(int i = 1; i <= n; i++){
		student[i] = i;
	}
	cin >> m;
	for(int i = 0; i < m; i++){
		cin >> num >> dis;
		if(dis < 0){
			toward(findIndex(num), -dis);
		} else {
			backward(findIndex(num), dis);
		}
	}
	for(int i = 1; i <= n; i++){
		cout << student[i] << " ";
	}
	cout << endl;
	return 0;
} 
