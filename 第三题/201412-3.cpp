#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

typedef struct {
	string c; // command ָ��
	float p; // price ����
	long long n; // num ���� 
}data;
vector<data>notes;
data temp;
long long maxNum = 0;
long long money[1000001] = {0}; // ��������� 1000000 / 100
int resultIndex = 0;

long long successDealNum(int money){
	long long allSell = 0, allBuy = 0;
	for(vector<data>::iterator it = notes.begin(); it != notes.end(); it++){
		string command = (*it).c;
		int price = round((*it).p * 100);
		long long n = (*it).n;
		if(command == "buy" && price >= money){ // �߼��� 
			allBuy += n;
		} else if(command == "sell" && price <= money){ // �ͼ��� 
			allSell += n;
		} 
	}
	return allBuy < allSell ? allBuy : allSell;
}

int main(){
	while(cin >> temp.c){
		if(temp.c == "buy" || temp.c == "sell"){
			cin >> temp.p >> temp.n;
		} else if(temp.c == "cancel"){
			cin >> temp.n;
			notes[temp.n - 1].n = 0; // ������i����¼�Ĺ���
			temp.p = 0;
			temp.n = 0;
		} else {
			break;
		}
		notes.push_back(temp);
	}
	for(vector<data>::iterator it = notes.begin(); it != notes.end(); it++){
		if((*it).c == "buy" && (*it).n != 0){ // �������Ǯ �ļ۸� �ҳ��� 
			int index = round((*it).p * 100); // �����Ҫ��round��λ 
			money[index] = 1;
		}
	}
	for(int i = 1; i < 1000001; i++){
		if(money[i]){
			money[i] = successDealNum(i);
			if(maxNum <= money[i]){
				maxNum = money[i];
				resultIndex = i;
			}
		}
	}
	printf("%.2f %lld\n", resultIndex/100.0, maxNum);
	return 0;
} 

/*
	Tips��
		����h��Ҫѧ #include<vector>
		����һ�����Դ��Զ������͵� ����������ȡ�Ķ��а� ����ٶ� 
	����˼·��
		���ɽ���һ����buy�е�ĳһ���۸� 
		����֮ ���5000*5000��ʱ�临�Ӷȣ����Ǹ�O(n^2) ������ү���ܽ���
		�۸�Ĵ���һ��Ҫ�ȳ�100��roundȡ�� �ٳ�100.0 
		
		round()����ԭ��Ϊ
		x=(int)(x+0.5)    
		
		�����������ݣ�ֹͣ�ķ������������ݺ� Ctrl + Z �ٻس� 
*/
