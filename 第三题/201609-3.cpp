#include<iostream>
#include<stdlib.h>
using namespace std;

int player = 0, n, pos, att, heal, from, to;
int num[2] = {0, 0};
char *op = (char *)malloc(8);

typedef struct{
	int heal;
	int att;
}Servlant;

Servlant servlant[2][8] = {{0}};

void callServlant(){
	if(pos <= num[player]){ // ���� ���� 
		for(int i = num[player]; i >= pos; i--){
			servlant[player][i + 1] = servlant[player][i];
		}
		servlant[player][pos].att = att;
		servlant[player][pos].heal = heal;
		num[player]++;
	} else { // û�� ��������� 
		num[player]++;
		int tempPos = num[player];
		servlant[player][tempPos].att = att;
		servlant[player][tempPos].heal = heal;
	}
}

void attackFunction(){
	servlant[player][from].heal -= servlant[!player][to].att;
	servlant[!player][to].heal -= servlant[player][from].att;
}

void clearDead(){ // �������ˣ����ṥ��0��Ӣ�ۣ����� 
	if(servlant[player][from].heal <= 0){
		int tempNum = num[player];
		for(int i = from; i < 7; i++){
			servlant[player][i].att = servlant[player][i+1].att;
			servlant[player][i].heal = servlant[player][i+1].heal;
		}
		servlant[player][tempNum].att = 0;
		servlant[player][tempNum].heal = 0;
		--num[player];
	}
	if(servlant[!player][to].heal <= 0 && to != 0){
		int tempNum = num[!player];
		for(int i = to; i < 7; i++){
			servlant[!player][i].att = servlant[!player][i+1].att;
			servlant[!player][i].heal = servlant[!player][i+1].heal;
		}
		servlant[!player][tempNum].att = 0;
		servlant[!player][tempNum].heal = 0;
		--num[!player];
	}
	
//	cout << "_________________" <<n<<endl;
//	cout << num[0];
//	for(int i = 1; i <= num[0]; i++){
//		cout << " " << servlant[0][i].heal;
//	}
//	cout << endl;
//	cout << num[1];
//	for(int i = 1; i <= num[1]; i++){
//		cout << " " << servlant[1][i].heal;
//	}
//	cout << endl;
//	cout << "_________________" <<n<<endl;
}

void printResult(){
	if(servlant[0][0].heal > 0 && servlant[1][0].heal > 0){ // ƽ�� 
		cout << "0" << endl; 
	} else if(servlant[0][0].heal <= 0){ // �������ʤ�� 
		cout << "-1" << endl;
	} else {
		cout << "1" << endl;
	}
	// ������ҵ�Ѫ�� 
	cout << servlant[0][0].heal << endl;
	// �������ʣ����Ӽ���Ѫ��
	cout << num[0];
	for(int i = 1; i <= num[0]; i++){
		cout << " " << servlant[0][i].heal;
	}
	cout << endl;
	
	// ������ҵ�Ѫ�� 
	cout << servlant[1][0].heal << endl;
	// �������ʣ����Ӽ���Ѫ��
	cout << num[1];
	for(int i = 1; i <= num[1]; i++){
		cout << " " << servlant[1][i].heal;
	}
	cout << endl;
}

int main(){
	servlant[0][0].heal = 30;
	servlant[1][0].heal = 30;
	cin >> n;
	while(n--){
		scanf("%s", op);
		if(op[0] == 's'){ // �ٻ���� 
			cin >> pos >> att >> heal; // λ�� ������ Ѫ��
			callServlant();
		} else if(op[0] == 'a'){ // ���� 
			cin >> from >> to;
			attackFunction();
			clearDead();
		} else { // ���� 
			player = !player;
		}
	}
	printResult();
	return 0;
}
/*
	����˼·��
		��ģ��д�������ܶ�
		1.�ٻ���Ӽ�ʹ�ٻ���7λ�ã�����˿�û����ӣ�����Ӧ����1λ�� 
*/
