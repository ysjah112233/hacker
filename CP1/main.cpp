#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <string>
#include <conio.h> //getch
#include "hacker.h"


using namespace std;
#define WIDTH 40
#define HEIGHT 15



/*
1.��վ404����
2.��վ�۸Ĺ���
3.��վ������¼
4.DNS����
5.��������������
*/
void inputpwd(char pwd[], int size){
	char c;
	int i = 0;
	while(1){
		c = getch();
		
		//��������س���������'\r'
		if(c == '\r'){
			pwd[i] = 0;
			break;
		}
		pwd[i++] = c;
		cout << '*';
	}
	cout << endl;
}
void login(void){
	string name;
	char pwd[32];
	while(1){
		system("cls");
		cout <<"�������˺�:";
		cin >> name;
	
		cout <<"����������:";
		//cin >> pwd;
		inputpwd(pwd,sizeof(pwd));
	
		if(name == "54hk" && !strcmp(pwd, "123456")){
			break;
		}
		else{
			cout <<"�˺Ż������������"<< endl;
			system("pause");
		}
	}

}

void printInMiddle(string msg){
	int leftSpace = (WIDTH - msg.length()) / 2;
	for(int j = 0; j < leftSpace; j++){
		cout << " ";
	}
	cout << msg << endl;
		
}

void menuShow(){
	/*
	system("cls");//�����Ļ
	cout <<"1.��վ404����"<< endl;
	cout <<"2.��վ�۸Ĺ���"<< endl;
	cout <<"3.�鿴������¼"<< endl;
	cout <<"4.�����޸�"<< endl;
	cout <<"5.�˳�"<< endl;
	*/
	string menu[] = {
		"1.��վ404����",
		"2.��վ�۸Ĺ���",
		"3.�鿴������¼",
		"4.�����޸�",
		"5.�˳�"
	};
	
	int max = 0;
	int menuCount = sizeof(menu) / sizeof(menu[0]);
	for(int i = 0; i < menuCount; i++){
		if(menu[i].length() > max){
			max = menu[i].length();
		}
	}

	system("cls");

	//��ӡ����
	printInMiddle("---�ڿ͹���ϵͳ---");

	int leftSpace = (WIDTH - max) / 2;
	for(int i = 0; i < menuCount; i++){
		for(int j = 0; j < leftSpace; j++){
			cout << " ";
		}
		cout << menu[i] << endl;
	}

}
int menuChoise(){

	int n = 0;
	while(1){
		//cout << "��ѡ��";
		cin >> n;
		if(cin.fail()){
			cin.clear();
			cin.sync();
			cout << "��Ч���룬����������" << endl;
		}
		else{
			break;
		}
	}

	return n;
}

void attack404(){
	system("cls");
	char id[64];
	char response[4096];

	printInMiddle("---��վ404����---");

	cout << "������׼����������վID:";
	scanf("%s",id);

	hk_404(id,response);
	cout << "����ִ��404����" << endl;

	string retStr = UTF8ToGBK(response);
	cout << retStr << endl;
	

	system("pause");
}

void siteEdit(){
	system("cls");
	char id[64];
	char response[4096];
	string attackText;

	printInMiddle("---��վ�۸Ĺ���---");

	cout << "������׼����������վID:";
	scanf("%s",id);

	cout << "������Ҫ�۸ĵ����ݣ�";
	cin >> attackText;

	GBKToUTF8(attackText);
	hk_tamper(id,(char*)attackText.c_str(),response);
	cout << "����ִ����վ�۸Ĺ���" << endl;

	string retStr = UTF8ToGBK(response);
	cout << retStr << endl;

	system("pause");
}

void attackRecord(){
	system("cls");
	char id[64];
	char response[4096];

	printInMiddle("---�鿴������¼---");

	cout << "������׼���鿴����վID:";
	scanf("%s",id);

	hk_record(id,response);
	cout << "���ڲ鿴������¼" << endl;

	string retStr = UTF8ToGBK(response);
	cout << retStr << endl;

	system("pause");
}

void attackRepair(){
	char id[64];
	char response[4096];
	system("pause");

	printInMiddle("---��վ�����޸�---");

	cout << "������׼���޸�����վID:";
	scanf("%s",id);

	hk_restore(id,response);
	cout << "����ִ����վ�����޸�" << endl;

	string retStr = UTF8ToGBK(response);
	cout << retStr << endl;
	system("pause");

}

void init(void){
	//�����ն˴��ڵĴ�С
	char cmd[128];
	sprintf(cmd,"mode con cols=%d lines=%d", WIDTH, HEIGHT);
	system(cmd);
	
}
int main(void){
	
	init();
	login();

	while(1){

		menuShow();
		int n = menuChoise();
		switch(n){
		case 1:
			attack404();
			break;
		case 2:
			siteEdit();
			break;
		case 3:
			attackRecord();
			break;
		case 4:
			attackRepair();
			break;
		case 5:
			return 0;
		default :
			cout << "��Ч���룬����������" << endl;
			system;
			break;

		}

	}
	system("pause");

	return 0;
}