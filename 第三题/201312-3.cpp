#include<iostream>
using namespace std;
int arr[1001] = {0};
long long result = 0;

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	for(int i = 0; i < n; i++){
		long long temp = 0;
		int minHeight = 26161; // ��Ȼ��Ŀ˵���10000��������������ֵд����26160 ��Ϊ90�֣��ɼ���ccfƭ�� 
								// ��Ȼ����ȷд��Ӧ���� int minHeight = arr[i]; ��������һʧ 
		for(int j = i; j < n; j++){
			if(arr[j] < minHeight){ // ����С�ͺ� 
				minHeight = arr[j];
			}
			temp = (j - i + 1) * minHeight;
			result = temp > result ? temp : result;
		}
	}
	cout << result <<endl;
	return 0;
}
