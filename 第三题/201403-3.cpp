#include<iostream>
#include<stdlib.h>
#include<cstring>
#include<string>
#include<map>
using namespace std;
map<char, int>type; // ��¼�������ͣ�1Ϊ���Σ�2Ϊ����  "map���intĬ��Ϊ0"
map<char, string>para; // �������ÿ�εĽ����ÿ�ζ���ʼ�� para.clear(); 
string str;

void initial(){
	getline(cin, str);
	int len = str.length();
	for(int i = 0; i < len - 1; i++){
		if(str[i] != ':' && str[i+1] == ':'){ // ���ε� 
			type[str[i]] = 1;
		} else if(str[i] != ':'){
			type[str[i]] = 2;
		}
	}
	if(str[len - 1] != ':'){ // �����һ������ 
		type[str[len - 1]] = 2;
	}
}

void operateExpress(string str){
	int len = str.length();
	int p1 = 0, p2 = 0, p3 = 0, flag = 0; // flag ���ֲ��� 0Ϊ���� 1Ϊ���� 
	string temp, parm;
	while((p1 = str.find(' ')) != -1){ // �Կո�Ϊ���
		str[p1] = 0;
		p2 = str.find(' ');
		if(p2 == -1){ // ĩβ ���ǿո�����ַ������ȸ���p2 
			p2 = len;
		}
		temp = str.substr(p1 + 1, p2 - p1 - 1); // �������� 
		if(!flag){ // ������ 
			if(temp[0] != '-' || !type[temp[1]]){ // ����-��ͷ���߲��ǲ��� �h��Ӧ�ÿ�����Ŀ������仰��ָ�������ֹͣ���� 
				break;
			} else if(type[temp[1]] == 2) { // ��������
				para[temp[1]] = "*";
			} else { // ������ 
				parm = temp;
				flag = !flag;
			}
		} else { // �ǲ��� 
			 para[parm[1]] = temp;
			 flag = !flag;
		}
	}
}

void printExpress(int i){
	cout << "Case " << i << ":";
	for(map<char, string>::iterator it = para.begin(); it != para.end(); it++){
		cout << " -" << (*it).first;
		if((*it).second != "*"){
			cout << " " << (*it).second;
		}
	}
	cout << endl;
}

int main(){
	initial();
	int n;
	cin >> n;
	cin.get();//������뻻�з�
	for(int i = 1; i <= n; i++){
		para.clear();
		string str;
		getline(cin, str);
		operateExpress(str);
		printExpress(i);
	} 
	
	return 0;
} 

/*
	Tips��
		�ַ������������￪ʼ����Ҫѧ��ʹ�õĿ⺯����map��string��iterator�������map 
	����˼�룺
		ʹ������map��
		һ���� ����Щ��ĸ��ָ�ָ���Ƿ������ 
		һ���� ÿһ�仰 ���������� ָ����������ע��ÿ�ζ�Ҫ��ʼ��
		�������۲���ӣ������Կո�Ϊ��϶���պÿ��Լ����
	
	��¼��
	c++�⺯��
	#include<map>
	map<char, int>type;
	clear()����ɾ������Ԫ��
	find()��������һ��Ԫ��
	insert()��������Ԫ�� //��ʵ��������ֱ��map['x']  = 1 �ʹ����˼�ֵ�� <x, 1> 
	size()��������map��Ԫ�صĸ���
	
	#include<cstring> // ��<string.h>��c++�� ��cstring�ͺ�
	string str = "abc";
	str.length();
	getline(cin, str); // ����һ�� 
*/		 
