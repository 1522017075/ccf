#include<iostream>
#include<cstring>
#include<ctype.h>
using namespace std;
string str, temp, tempSelf;
int flag; // ��Сд����  0 ������   1 ���� 

int main(){
	getline(cin, str);
	cin >> flag;
	int n;
	cin >> n;
	cin.get(); // �Ե��س� ������������һ������ 
	for(int i = 0; i < n; i++){
		getline(cin, temp);
		tempSelf = temp; 
		int result = temp.find(str);
		if(!flag){ // �����еĻ� ȫת�ɴ�д 
			int len = temp.length();
			for(int i = 0; i < len; i++){
				temp[i] = toupper(temp[i]);
			}
			len = str.length();
			for(int i = 0; i < len; i++){
				str[i] = toupper(str[i]);
			}
		}
		if(temp.find(str) != -1){
			cout << tempSelf << endl;
		}
	}
	return 0;
}

/*
	Tips��
		����������һ��ctype.h ��toupper('a') => A
		Ȼ������Ӵ���string�ķ��� 
		string str,str1;
		str.find(str1); ����ֵ����λ�� û�ҵ�����-1
	Hello
	0
	5
	HelloWorld
	HiHiHelloHiHi
	GrepIsAGreatTool
	HELLO
	HELLOisNOTHello
*/
