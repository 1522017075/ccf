#include<iostream>
using namespace std;

int arr[10001] = {0};
int main(){
	int n, temp, empty = 0, min = 10001;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> temp;
		arr[temp] += 1;
	}
	for(int i = 0; i < 10001; i++){
		if(arr[i] > 1){ // ���������ϵ���һ�� ��ֵΪ0 
			min = 0;
			break;
		} else if (arr[i]){ // �ҵ����뵱ǰλ�� ����ķ�0���ľ��� ����min 
			for(int j = i + 1; j < 10001; j++){
				if(arr[j]){
					min = (j - i) < min ? j - i : min;
					break;
				}
			}
		}
	}
	cout << min << endl;
	return 0;
} 
