#include<iostream>
#include<stdlib.h>
#include<stack>
using namespace std;
stack<int> stkNum;
stack<char> stkChar;

void operate(int a, int b, char op){
	if(op == '+'){
		stkNum.push(a+b);
	}else if(op == '-'){
		stkNum.push(a-b);
	}else if(op == 'x'){
		stkNum.push(a*b);
	} else {
		stkNum.push(a/b);
	}
}

bool isTwentyFour(char *express){
	stkNum.push(express[0] - 48);
	for(int i = 1; i <= 5; i+=2){
		stkNum.push((express[i+1] - 48));
		if(express[i] == '+' || express[i] == '-'){ // �Ӽ��ȷ�һ��
			if(express[i] == '-'){ // ���ŵĻ�����������λ���� ������Ӻ� 
				int temp = stkNum.top();
				stkNum.pop();
				temp = -temp;
				stkNum.push(temp);
			}
			stkChar.push('+');
		} else { // �˳�ֱ���� 
			int b = stkNum.top();
			stkNum.pop();
			int a = stkNum.top();
			stkNum.pop();
			operate(a, b, express[i]);
		}
	}
	while(stkChar.size()){
		int b = stkNum.top();
		stkNum.pop();
		int a = stkNum.top();
		stkNum.pop();
		char op = stkChar.top();
		stkChar.pop();
		operate(a, b, op);
	}
	
	int result = stkNum.top();
	stkNum.pop();
	return result == 24;
}

int main(){
	int n;
	cin >> n;
	char *express = (char *)malloc(sizeof(char) * 8);
	for(int i = 0; i < n; i++){
		cin >> express;
		if(isTwentyFour(express)){
			cout << "Yes" <<endl;
		} else {
			cout << "No" <<endl;
		}
	}
	return 0;
} 

/*
10
9+3+4x3
5+4x5x5
7-9-9+8
5x6/5x4
3+5+7+9
1x1+9-9
1x9-5/9
8/5+6x9
6x7-3x6
6x4+4/5

	����˼�룺
		������ջ��һ��������һ������ţ������˳�ֱ���㣬�Ӽ��ͻ�һ��
	�h��Ҫѧ����
		C++ջ���ʹ��
		#include<stack>
		����ջ���£�
		stack<int> stk;
		
		s.empty()               ���ջΪ�շ���true�����򷵻�false  
		s.size()                ����ջ��Ԫ�صĸ���  
		s.pop()                 ɾ��ջ��Ԫ�ص���������ֵ  
		s.top()                 ����ջ����Ԫ�أ�����ɾ����Ԫ��  
		s.push()                ��ջ��ѹ����Ԫ��  
*/
