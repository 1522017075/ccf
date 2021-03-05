#include<iostream>
#include<string>
#include<set>
using namespace std;

int isNum(string str) {
	int result = 1;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] < '0' || str[i] > '9') {
			result = 0;
			break;
		}
	}
	return result;
}

string getNum(string str) {
	int flag = 0;
	while (str[flag] == '0') {
		flag++;
	}
	return str.substr(flag);
}

const string C = "0123456789qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM-_./";
int main() {
	int n, m;
	string R[100], N[100], Q[100], P;
	set<char> S;
	cin >> n >> m;
	cin.get();
	for (int i = 0; i < n; i++) {
		cin >> R[i] >> N[i]; // R �ǲ���·�� N������
	}
	for (int i = 0, f, p1, p2; i < m; i++) { // f -1��ƥ�� 1ƥ�� 0δ֪
		cin >> Q[i]; // Q�Ǵ�ƥ��·��
		f = 0;
		S.clear();
		S.insert(C.begin(), C.end());
		S.insert(Q[i].begin(), Q[i].end());
		if (S.size() == C.size()) { // û�зǷ��ַ�
			for (int j = 0; j < n && f < 1; j++) { // �Աȵ�j��R��Q�Ƿ�ƥ��
				int k = 0, nk = Q[i].size(), l = 0, nl = R[j].size();
				P = "";
				f = 0;
				string K = Q[i], L = R[j], s1, s2;
				while (k < nk && l < nl && f == 0) {
					p1 = k + 1;
					k = K.find('/', p1);
					s1 = K.substr(p1, (k == string::npos ? k = nk : k) - p1);
					p2 = l + 1;
					l = L.find('/', p2);
					s2 = L.substr(p2, (l == string::npos ? l = nl : l) - p2);
					if (s1 != "" && s2 == "<int>" && isNum(s1)) {
						P += " " + getNum(s1);
					}
					else if (s1 != "" && s2 == "<str>") {
						P += " " + s1;
					}
					else if (s1 != "" && s2 == "<path>") {
						P += " " + K.substr(p1, nk - p1);
						f = 1; // һ��ƥ��
					}
					else if (s2 != s1){
						f = -1;
					}
				}
				if (f != -1 && k == nk && l == nl || f == 1) {
					f = 1;
					cout << N[j] << (P.size() > 0 ? P : "") << endl;
				}
			}
		}
		if (f < 1) cout << "404" << endl;
	}
	return 0;
}

/*
	Tips:
		����h������ѧC++11��׼�µ�#include<unordered_set> 
		�������������жϺϷ��ַ�
		unordered_set<char> S;
		S.insert(string.begin(), string.end());
		S.clear();
	����˼·��
		����forѭ�� ����֮����Ҫ�����ַ����Ĵ���
		�� ����<path>��˵�������ǽ�β�����ÿ���б��
		string::npos  �ַ������� �Ҳ����ķ���ֵΪ��� �����з���-1
*/
