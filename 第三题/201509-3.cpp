#include<iostream>
#include<cstring>
#include<map>
using namespace std;
map<string, string>parm;
string model[101] = {""};
string str;
int main(){
	int m, n; // m ģ�������� n ������ 
	cin >> m >> n;
	cin.get();
	for(int i = 0; i < m; i++){
		getline(cin, model[i]);
	}
	for(int i = 0; i < n; i++){ // ��ֵ������
		getline(cin, str);
		int space = str.find(' ');
		parm["{{ " + str.substr(0, space) + " }}"] 
			= str.substr(space + 2, str.length() - space - 3);
	}
	for(int i = 0; i < m; i++){
		int p1 = 0, p2 = 0;
		while((p1 = model[i].find("{{", p1)) != -1){
			p2 = model[i].find("}}", p1);
			p2 += 2;
			string key = model[i].substr(p1, p2 - p1);
			
			model[i] = model[i].replace(p1, key.length(), parm[key]); // ֱ�ӻ�
			p1 = p1 + parm[key].length(); // �����滻֮����Ӵ��ĳ��� 
		}
		cout << model[i] << endl;
	}
	return 0;
}
/*
	Tips:
		����h��Ҫѧϰ str.find("xxx", position);   ��string str;
		position���Ǵ�position֮��ʼѰ�ң��������ǳ����ϣ����ø���position����
		�Լ� 
		str.replace(���Ŀ�ʼ��, ���೤, Ҫ�����ĸ��ַ���);
	����˼·:
		Ҫע�⵽�������㣺
		1���������еı���û�ж��壬�����ɿմ����൱�ڰѱ�Ǵ�ģ����ɾ��
		2��ģ�岻�ݹ����ɡ�Ҳ����˵�����������ֵ�а�������������������һ�����滻��
		3��һ�仰�п����кü�����������ͬ����ͬ�����û�����
		�������������ǵ�˼·�ǣ���position��ʼΪ0��ÿ���ҵ��������ж������ֱ���
		Ȼ��position���� ���û��ַ����ĳ��ȣ����� find��ֱ���Ҳ��� 
*/ 
