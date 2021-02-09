#include<iostream>
#include<cstring>
using namespace std;
char picture[100][100] = {{0}};
bool flag[100][100] = {{0}}; // ÿ�����ʱ��Ǹø������ 
int m, n, q, op, x1, y1, x2, y2; // m�� n�� q�λ�ͼ���� op���� 


void drawLine(int x1, int y1, int x2, int y2){
	char ch = '|'; // Ĭ�ϻ����� 
	if(x1 > x2){
		x1 = x1 ^ x2;
		x2 = x1 ^ x2;
		x1 = x1 ^ x2; 
	}
	if(y1 > y2){
		y1 = y1 ^ y2;
		y2 = y1 ^ y2;
		y1 = y1 ^ y2;
	}
	if(x1 == x2){ // ���β���������
		ch = '-';
	}
	for(int i = x1; i <= x2; i++){
		for(int j = y1; j<= y2; j++){
			if((picture[i][j] == '-' && ch == '|') 
			|| (picture[i][j] == '|' && ch == '-')){ //'-' + '|' == 169
				picture[i][j] = '+';
			} else if(picture[i][j] != '+'){ // �ǳ��ӵ� ����� 
				picture[i][j] = ch;
			}
		}
	}
}

void dfs(int x, int y, char ch){
	if(x >= m || y >= n 
	|| x < 0 || y < 0
	|| picture[y][x] == '-' 
	|| picture[y][x] == '|' 
	|| picture[y][x] == '+'
	|| flag[y][x]){ // ֹͣ����
		return;
	}
	picture[y][x] = ch;
	flag[y][x] = true;
	dfs(x+1, y, ch); // �ݹ���� 
	dfs(x, y+1, ch);
	dfs(x-1, y, ch);
	dfs(x, y-1, ch);
}

int main(){
	char ch;
	cin >> m >> n >> q;
	memset(picture, '.', sizeof(picture)); // ��ʼ������Ϊ��� 
	while(q--){ // 0�߶� 1����������� 
		cin >> op;
		if(op){ // ���
			memset(flag, 0, sizeof(flag)); // ��ʼ����� 
			cin >> x1 >> y1 >> ch;
			dfs(x1, y1, ch);
		} else { // ���� 
			cin >> y1 >> x1 >> y2 >> x2;
			drawLine(x1, y1, x2, y2);
		} 
	}
	for(int i = n - 1; i >= 0; i--){
		for(int j = 0; j < m; j++){
			cout << picture[i][j];
		}
		cout << endl;
	}
	return 0;
} 

/*
	Tips:
		��ڿΫh����ϰһ������ memset(arr, �������, sizeof(arr))
		�ɶ�nά���� �����Զ����ʼ�� ��� �� #include<cstring>�� 
	����˼·��
		�߶κû����и������ʱ����������Ӻ� ������
		���Ļ�����dfs�������ұ���������Ѿ��������ĵ㣬��Ȼ����ѭ�� 
*/
