#include<iostream>
#include<algorithm>
using namespace std;
int m, errors = 0, rights = 0, allError = 0, allRight = 0;
typedef struct {
	long long y;
	int result;
}Data;

bool cmp(Data a, Data b){
	return a.y < b.y;
}

int main(){
	cin >> m;
	Data *data = (Data *)malloc(sizeof(Data) * m);
	Data *dataSum = (Data *)malloc(sizeof(Data) * m);
	for(int i = 0; i < m; i++){
		cin >> data[i].y >> data[i].result;
		dataSum[i].y = data[i].y;
	}
	sort(data, data + m, cmp);
	sort(dataSum, dataSum + m, cmp);
	
	dataSum[0].result = 0;
	allError = data[0].result ? 0 : 1;
	
	for(int i = 1; i < m; i++){ // ͳ��iԪ��֮ǰ �ж��ٸ��ҿ�
		if(dataSum[i].y != dataSum[i-1].y){
			errors = allError;
		}
		dataSum[i].result = errors;
		if(!data[i].result){ // �ҿ�
			allError++;
		}
	}
	allRight = data[m - 1].result ? 1 : 0;
	dataSum[m - 1].result += allRight;
	
	for(int i = m - 2; i >= 0; i--){ // ͳ��iԪ��֮�� �ж��ٸ����ҿ�
		if(data[i].result){ // ���ҿ�
			allRight++;
		}
		if(dataSum[i].y != dataSum[i+1].y){
			rights = allRight;
		}
		dataSum[i].result += rights;
	}
	int index = 0;
	long long value = 0;
	for(int i = 0; i < m; i++){ // �ҵ��÷���ߵ��� ������ 
		if(dataSum[i].result >= index){
			index = dataSum[i].result;
			value = dataSum[i].y;
		}
	}
	cout << value << endl;
	return 0;
}


/*
	����߶߶��
		�����̫ţ���ˣ�����ֻ�ܵ�70��
		�h��Ӧ�����õ�70��֮�������������100�� 
	����˼�룺
		��30��ֻ���á�ǰ׺�͡�˼����������˴��Ȱٶȡ�ǰ׺�͡�
		¼�����ݺ��¿�һ�� dataSum���飬������ÿ����ֵ �Լ�����ֵ��Ӧ����ȷ����
		�� �ж��ٸ���ֵС�����ҹҿƣ����ڵ������Ҳ��ҿƣ�����������forѭ���ֱ�ͳ������������֮��
		Ȼ�����һ���ҵ���ȷ��������ֵ�����֮���ܵ���˵�����ѣ����Ǳ�����������������Ѿ� 
*/
