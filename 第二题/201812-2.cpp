#include<iostream>
using namespace std;
long long lightColor[4] = {0}; // 1 �� 2 �� 3 �� 
long long r, y, g, n;
long long result = 0;

void switchLight(long long *light, long long time, long long *lightTime){ // ��������ʱ��ͳ���ʱ�ĵƣ����� ��ǰ����ɫ 
	time = -time; // ��������Դ����������ʱ�� 
	time %= lightColor[0];
	time = -time;
	while(time < 0){
		*light = --(*light) ? *light : 3;
		time += lightColor[*light];
	}
	*lightTime = time;
}


int main(){
	cin >> r >> y >> g >> n;
	lightColor[1] = r;
	lightColor[2] = y;
	lightColor[3] = g;
	lightColor[0] = r + y + g;
	long long initWay[n][2] = {{0}}; // �����ȥ�ĵƵ���Ϣ 
	for(long long i = 0; i < n; i++){
		cin >> initWay[i][0] >> initWay[i][1];
	}
	for(long long i = 0; i < n; i++){ // ģ���ߵ�ÿһ��·ʱ �ƺ�ʱ�� �ı仯 
		if(initWay[i][0]){ // 1 2 3�� Ϊ�к��̵� 
			switchLight(&initWay[i][0], initWay[i][1] - result, &initWay[i][1]);
			if(initWay[i][0] == 1){ // �˿�Ϊ��ƣ��ȴ�ʣ������ 
				result += initWay[i][1];
			} else if (initWay[i][0] == 2){ // Ϊ�Ƶƣ��ȴ�ʣ������+������� 
				result += initWay[i][1];
				result += lightColor[1];
			}
		} else { // ����·�� ֱ����
			result += initWay[i][1];
		}
	}
	cout << result << endl;
	return 0;
} 

/*
	����˼�룺
		����h�����������������ĳ�ʼ�����ǳ���ǰ����·�ڵ����
		������Ҫ��ģ������ߵ�ĳһ·��ʱ���Ƶ���ɫ��ʣ��ʱ��
		��ʵģ���꣬��Ҳ�ͳ����ˡ� 
	Tips:
		����С�����ϣ���int��ֻ��60�֣���40����Ҫ��long long�� 
	��߶߶��
		��Ȼ�������Լ��Գ����Ŀӣ�����ҲҪ��סѽ��̫�������� 
*/
