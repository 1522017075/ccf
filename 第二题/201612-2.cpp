#include<iostream>
using namespace std;
int point[10]    = {1500, 3000, 4500, 26000, 20000, 25000};
//int tax[10]      = {45,   300,  900,  6500,  6000,  8750};
int afterTax[10] = {1455, 2700, 3600, 19500, 14000, 16250};
int rate[10]     = {3,    10,   20,   25,    30,    35, 45};
int main(){
	int salary, result = 0, flag = 0;
	cin >> salary;
	if(salary > 3500){
		result = 3500;
		salary -= 3500;
	} else {
		result = salary;
		salary = 0;
	}
	while((salary - afterTax[flag]) > 0 && flag < 6){
		salary -= afterTax[flag];
		result += point[flag];
		flag++;
	}
	cout << result + (salary * 100)/(100 - rate[flag]) << endl;
	return 0;
} 
/*
	����˼�룺
		��ǰ��������ж� 
		���ж�˰��нˮ���ĸ����� 
		һ�߼�˰��һ�߼�˰ǰ 
		���� ���� �����Ӧ˰�� ȥ ��ԭ˰ǰ 
	С֪ʶ��
		�漰 ��Ǯ���ף���Ҫ�ø��������ᷢ�����ȴ��� 
		�h�������˷� 
*/
