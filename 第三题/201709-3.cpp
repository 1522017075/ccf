#include<iostream>
#include<map>
#include<cstring>
using namespace std;

map<string, string> result, stf;


string getStr(int *p, string temp){
	int i = *p;
	i++;
	string str = "";
	while(i < temp.length()){
		if(temp[i] == '\"'){
			break;
		}
		if(temp[i] == '\\'){
			i++;
		}
		str += temp[i];
		i++;
	}
	
	*p = i + 1;
	return str;
}

int main(){
	int n, m; // n������ m����� 
	string path = "", str = "", tempStr = ""; 
	cin >> n >> m;
	cin.get();
	for(int i = 0; i < n; i++){ // ȫ���һ�� 
		getline(cin, tempStr);
		str += tempStr;
	}
	for(int i = 1; i < str.length() - 1; i++){ // ������β������ 
		if(str[i] == ' ' || str[i] == ','){
			continue;
		}
		string key; 
		if(str[i] == '\"'){ // ��ʼ�ռ��ַ��� ������ iֵ 
			key = getStr(&i, str);
		}
		
		if(str[i] == ':') { // ����� 
			i++;
			while(str[i] == ' '){
				i++;
			}
			
			if(str[i] == '\"'){ // ¼���ֵ�� 
				string value = getStr(&i, str);
				result[path + "." + key] = value;
				
				if(str[i] == '}') { // ������� ˳���˼� 
					path = stf[path];
				} 
			}else if(str[i] == '{'){ // ���¸���  ����path
				stf[path + "." + key] = path;
				path = path + "." + key;
				result[path] = "likezhangyue";
			}
		
		} else if(str[i] == '}') { // �������Ҫ�ж�ѽ ��2������ 
			path = stf[path];
		}
	}
	string key = ".";
	for(int i = 0; i < m; i++){
		getline(cin, tempStr);
		
		if(result[key + tempStr] == ""){
			cout << "NOTEXIST" << endl; 
		} else if(result[key + tempStr] == "likezhangyue"){
			cout << "OBJECT" << endl;
		} else {
			cout << "STRING " << result[key + tempStr] << endl; 
		}
	}
	return 0;
} 
/*
	����˼·:
		1. ��������.xx.xx.xx��Ϊkey��ֱ�Ӵ�value
		2. �����ַ���ʱС��ת���ַ� 
		3. ����Ӳ���� �޵е� 
	Tips:
		ȫ���һ��  ����!!!���㼫�ˣ����� 
		
*/ 

/*
16 5
{
	"a": {
		"b": {
			"c":"d"
		}
	},
	"e":{
		"f": {
			"g": {
				"h":"xx"
				}
			}
		}
	},
	"x": "z" 
}
e
e.f
e.f.g
e.f.g.h
x
*/
