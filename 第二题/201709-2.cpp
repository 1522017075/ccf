#include<iostream>
#include<algorithm>
#include<stdlib.h>
using namespace std;
typedef struct{
	int time; // ����������ʱ�� 
	int op;   // �����ĸ����� ��or�� 1or0
	int num;  // Կ�ױ�� 
}Operate;
int n, k;
int box[1001] = {0};
bool cmp(Operate a, Operate b){
	if(a.time != b.time){ // ����ʱ��ʱ�䣬ʱ����ǰ���Ȳ��� 
		return a.time < b.time;
	} else if(a.op != b.op){ // �Ȼ����ã���Ϊ1����Ϊ0 
		return a.op > b.op;
	} else { // ���С���ȴ��� 
		return a.num < b.num;
	}
}

int findKey(int num){ // �ҵ�Կ�����ĸ����Ϲ��� 
	for(int i = 1; i <= n; i++){
		if(box[i] == num){
			return i;
		}
	}
}

int main(){
	int w, s, c;
	cin >> n >> k;
	for(int i = 0; i <= n; i++){ // initial key box
		box[i] = i;
	}
	Operate *operate = (Operate*)malloc(sizeof(Operate) * k * 2);
	for(int i = 0; i < k; i++){
		cin >> w >> s >> c; // which start class
		// �ò���
		operate[i].num = w;
		operate[i].op = 0;
		operate[i].time = s;
		// ������ 
		operate[i + k].num = w;
		operate[i + k].op = 1;
		operate[i + k].time = s + c;
	}
	sort(operate, operate + 2 * k, cmp); // ����nb 
	for(int i = 0; i < k * 2; i++){ // ģ������õ�ÿһ������ 
		if(operate[i].op){ // ��Կ�� 
			for(int j = 1; j <= n; j++){
				if(box[j] == -1){
//					printf("ʱ��%d, %d��������", operate[i].time, operate[i].num);
					box[j] = operate[i].num;
					break;
				}
			}
		} else { // ��Կ�� 
//			printf("ʱ��%d, %d������   ", operate[i].time, operate[i].num);
			box[findKey(operate[i].num)] = -1;
		}
//		for(int j = 1; j <= n; j++){
//			cout << " " << box[j];
//		}
//		cout << endl;
	}
	cout << box[1];
	for(int j = 2; j <= n; j++){
		cout << " " << box[j];
	}
	cout << endl;
	return 0;
}

/*
	����˼�룺
		�����в������� ����ʱ�� ��ȡ/�桢Կ�ױ�ţ����ȼ�Ϊ1 1.5 2.5 3�� 
		�����Ϳ��԰���ʵ�ʲ�����˳��ģ���ȡԿ��
		����h����Ҫѧ���ļ����ǣ��ṹ��ֱ𰴸���Ԫ������ 
	Tips��
		ע�͵��Ĵ����ǿ��������й��̣������ȡ��ע����һ����������һ�� 
*/
