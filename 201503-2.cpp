#include<iostream>
using namespace std;

int arr[1001] = {0};
int main(){
	int n, temp, max, index, num = 0;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> temp;
		if(!arr[temp]){
			num++;
		}
		arr[temp]++;
	}
	for(int i = 0; i < num; i++){
		max = 0;
		for(int i = 1; i <= 1000; i++){
			if(arr[i] && arr[i] > max){
				max = arr[i];
				index = i;
			}
		}
		cout << index << " " << max << endl;
		arr[index] = 0;
	}
	return 0;
}
/*
	����˼�룺 
	���������飬���������Ϊ�±꣬�ø��һ������ļ�Ϊ����
	����num�飨numΪһ�����ֶ��ٸ����� ��ÿ���ҵ����ֵ��������� 
*/
