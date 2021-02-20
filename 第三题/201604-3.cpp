#include<iostream>
#include<cstring>
#include<stack> 
using namespace std;
int p;
string current, str, perfect;
stack<string> stk;

void initial(){ // ȥ��N��б�� ��  ./ ��ǰĿ¼ 
	int p1 = 0;
	while((p1 = str.find("//")) != -1) {
		str.replace(p1, 2, "/"); // p1��ʼ �滻2���ȵ��ַ�Ϊ ��/�� 
	}
	p1 = 0;
	while((p1 = str.find("./", p1)) != -1) {
		if(p1 != 0 && str[p1 -1] != '.'){ // �ж��Ƿ�Ϊ"../" 
			str.replace(p1, 2, ""); // "./"Ϊ��ǰĿ¼ ֱ��ɾ�� 
		} else {
			++p1;
		}
	}
}

void GetPath(){ // ����Ǿ���·���Ͳ��ܣ����·���ͼ��ϵ�ǰ·�� 
	int curLen = current.length();
	if(str[0] != '/'){ // ���·�� 
		if(current[curLen - 1] != '/'){ // ��һ��б�� 
			perfect = current + "/" + str;
		} else {
			perfect = current + str;
		}
	} else { // ����·�� 
		perfect = str;
	}
	if(perfect[perfect.length() - 1] != '/'){
		perfect = perfect + "/";
	}
}

void operatePath(){ // ���� "��һ��" -- ".."Ŀ¼  ����������ջ������..�ͳ�ջ 
	int p1 = 0,p2 = 0;
	string temp;
	while((p1 = perfect.find('/', p1)) != -1){
		if((p2 = perfect.find('/', p1+1)) != -1){
			temp = perfect.substr(p1 + 1, p2 - p1 - 1);
			if(temp == ".."){
				if(stk.size()){
					stk.pop();
				}
			} else {
				stk.push(temp);
			}
			p1 = p2;
		} else {
			p1++;
		}
	}
}

void printPath(){ // ��ӡջ���ʣ�µ�Ԫ�أ��Ը�Ŀ¼������ 
	string path = "/";
	while(stk.size()){
		path = "/" + stk.top() + path;
		stk.pop();
	}
	if(path.length() > 1){
		path[path.length() - 1] = '\n';
		cout << path;
	} else {
		cout << "/" << endl;
	}
}

int main(){
	cin >> p;
	cin.get();
	getline(cin, current);
	while(p--){
		while(stk.size()){
			stk.pop();
		} 
		getline(cin, str);
		initial();
		GetPath();
		operatePath();
		printPath();
	}
	return 0;
} 

/*
	Tips:
		����h������ѧ�� str.append(len, str1);
		��str���׷�� len �����ַ��� str1 
		
		str = str + str1; ����������� 
		
	����˼·��
		�ֳ����ĸ�������ÿ����������ע�ͣ�ȥ������ 
*/
