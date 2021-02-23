#include<iostream>
#include<map>
#include<vector>
#include<cstring>
using namespace std;
int p, n, q, u;

typedef struct{
	int level;
	string cmd;
}Command;

map<string, int> command;
map<string, vector<Command> >role; // ��������ö���ո�> > 
map<string, vector<Command> >user;

string getStr(string str){
	return str.substr(0, str.length() - 2);
}

void initialCommand(int p){ // ��ʼ������Ҫ 
	while(p--){
		string temp;
		int tempLevel = -1;
		cin >> temp;
		if(temp.find(':') != -1){ // �еȼ� 
			tempLevel = temp[temp.length() - 1] - 48;
			temp = getStr(temp);
		}
		command[temp] = tempLevel;
	}
}

void initialRole(int n){ // ¼���ɫ 
	while(n--){
		string name, tempStr;
		cin >> name;
		int num, tempLevel;
		cin >> num;
		vector<Command> vec;
		while(num--){
			tempLevel = -1;
			cin >> tempStr;
			if(tempStr.find(':') != -1){ // �еȼ� 
				tempLevel = tempStr[tempStr.length() - 1] - 48;
				tempStr = getStr(tempStr);
			}
			Command command = {tempLevel, tempStr};
			vec.push_back(command);
		}
		role[name] = vec;
	}
}

void initialUser(int u){ // �ǵñȽ�ָ��Ĵ�С ��git:3 git:1 ���Ӧ�ô�git:3 
	while(u--){
		string userName, roleName;
		cin >> userName;
		vector<Command> vec;
		
		int num;
		cin >> num;
		
		while(num--){
			cin >> roleName;
			vector<Command> vecc = role[roleName];
			for(vector<Command>::iterator it = vecc.begin(); it != vecc.end(); it++){
				string cmd = it -> cmd;
				int tempLevel = it -> level;
				int flag = 1;
				for(vector<Command>::iterator itt = vec.begin(); itt != vec.end(); itt++){
					if(itt -> cmd == cmd && itt -> level < tempLevel){
						itt -> level = tempLevel;
						flag = 0;
					}
				}
				if(flag){ // �����ڱ�Ԫ�� 
					Command c = {tempLevel, cmd};
					vec.push_back(c);
				}
			}
		}
		
		user[userName] = vec;
	}
}

int isContainEle(vector<Command> vec, string str){ // -1����Ȩ�� 
	int result = -999;
	for(vector<Command>::iterator it = vec.begin(); it != vec.end(); it++){
		if(it -> cmd == str){
			result = it -> level;
			break;
		}
	}
	return result;
}

void selectQuery(int q){
	while(q--){
		string userName, tempStr;
		int tempLevel = -1;
		cin >> userName >> tempStr;
		if(tempStr.find(':') != -1){ // �еȼ� 
			tempLevel = tempStr[tempStr.length() - 1] - 48;
			tempStr = getStr(tempStr);
		}
		
		if(command.count(tempStr) == 1){ // ϵͳ�ڴ��ڸ�ָ�� 
			vector<Command> vec = user[userName]; // ���û�������Ȩ�� 
			int result = isContainEle(vec, tempStr); // �Ƿ�ӵ�и�Ȩ��
			if(command[tempStr] == -1){ // �޵ȼ�ָ��
				if(result == -999){ // ��Ȩ�� 
					cout << "false" << endl;
				} else {
					cout << "true" << endl;
				}
			} else { // �еȼ�ָ�� 
				if(tempLevel == -1){ // ��ѯʱ�����ȼ� ������� 
					if(result == -999){ // ����û��Ȩ�� 
						cout << "false" << endl;
					} else {
						cout << result << endl;
					}
				} else { // ��ѯʱ���ȼ�
					if(result == -999){ // ����û��Ȩ�� 
						cout << "false" << endl;
					} else {
						cout << ((result >= tempLevel) ? "true" : "false") << endl;
					}
				}
			}
		} else { // ϵͳ���޸�ָ�� 
			cout << "false" << endl;
		}
	} 
}

int main(){
	cin >> p; // p��Ȩ��
	initialCommand(p);
	cin >> n; // n�ֽ�ɫ
	initialRole(n);
	
	cin >> u;
	initialUser(u);
	cin >> q; // q����ѯ
	selectQuery(q);
	return 0;
} 

/*
	Tips:
		����h����ϰvector��map��ʹ��
		1.�ж�map����ĳkey: map.count(str) == 1
		2.map�ı���: for(map<str, int>::iterator it = myMap.begin(); it != myMap.end(); it++){
						it -> first; // ������Ԫ�صķ��� 
						it -> second;
					}  vectorд����ͬ�����õ�����
		3.vector���Ԫ��: vec.push_back(element); 
	����˼·��
		3��map��������ָ���ɫ���û� 
*/ 
