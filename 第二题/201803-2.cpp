#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int n, l, t, temp, direction = 0, ball = 1, index = 0;
	cin >> n >> l >> t;
	int result[n] = {0};
	int position[n] = {0};
	int tmp[n] = {0}; // ��ȷ�����λ�� 
	for(int i = 0; i < n; i++){
		cin >> position[i];
	}
	for(int i = 0; i < n; i++){ // ����ÿ����������ĸ�λ�ã����� 
		temp = position[i];
		direction = (temp + t) / l;
		temp = (temp + t) % l;
		if(direction & 1){ // ������ ��������  
			temp = l - temp;
		} else { // ż���� �������� ��Ĭ�ϼ������ д��䷽����� 
			
		} 
		result[i] = temp;
	}
	int min = 1001, minIndex = 0;
	for(int i = 0; i < n; i++){ // �������������λ�������� ���ʼ����� 3 2 1 �������ʱ��Ҫ��1 2 3��Ӧ��λ�� 
		for(int j = 0; j < n; j++){
			if(position[j] < min){
				min = position[j];
				minIndex = j;
			}
		}
		tmp[i] = minIndex;
		min = 1001;
		position[minIndex] = 1001;
	}
	sort(result, result + n); // ������ 
	
	for(int i = 0; i < n; i++){ // ��Ӧ�����Ϊ���� 
		for(int j = 0; j < n; j++){
			if(tmp[j] == i){
				cout<< result[j] << " ";
				break;
			}
		}
	}
	return 0;
} 

/*
	����˼�룺
		����ÿ��������λ�ã�����Ϊ������Ϊ����������������ײ ���ǲ������
		��¼��ʼλ��
		���ݳ�ʼ���λ�� ���±߰� ��˵������ ��ư�� _(:�١���)_ 
		 https://blog.csdn.net/SongBai1997/article/details/81175312
*/

