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
1.网站404攻击
2.网站篡改攻击
3.网站攻击记录
4.DNS攻击
5.服务器重启攻击
*/
void inputpwd(char pwd[], int size){
	char c;
	int i = 0;
	while(1){
		c = getch();
		
		//如果读到回车符，返回'\r'
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
		cout <<"请输入账号:";
		cin >> name;
	
		cout <<"请输入密码:";
		//cin >> pwd;
		inputpwd(pwd,sizeof(pwd));
	
		if(name == "54hk" && !strcmp(pwd, "123456")){
			break;
		}
		else{
			cout <<"账号或密码输入错误！"<< endl;
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
	system("cls");//清除屏幕
	cout <<"1.网站404攻击"<< endl;
	cout <<"2.网站篡改攻击"<< endl;
	cout <<"3.查看攻击记录"<< endl;
	cout <<"4.攻击修复"<< endl;
	cout <<"5.退出"<< endl;
	*/
	string menu[] = {
		"1.网站404攻击",
		"2.网站篡改攻击",
		"3.查看攻击记录",
		"4.攻击修复",
		"5.退出"
	};
	
	int max = 0;
	int menuCount = sizeof(menu) / sizeof(menu[0]);
	for(int i = 0; i < menuCount; i++){
		if(menu[i].length() > max){
			max = menu[i].length();
		}
	}

	system("cls");

	//打印标题
	printInMiddle("---黑客攻击系统---");

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
		//cout << "请选择：";
		cin >> n;
		if(cin.fail()){
			cin.clear();
			cin.sync();
			cout << "无效输入，请重新输入" << endl;
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

	printInMiddle("---网站404攻击---");

	cout << "请输入准备攻击的网站ID:";
	scanf("%s",id);

	hk_404(id,response);
	cout << "正在执行404攻击" << endl;

	string retStr = UTF8ToGBK(response);
	cout << retStr << endl;
	

	system("pause");
}

void siteEdit(){
	system("cls");
	char id[64];
	char response[4096];
	string attackText;

	printInMiddle("---网站篡改攻击---");

	cout << "请输入准备攻击的网站ID:";
	scanf("%s",id);

	cout << "请输入要篡改的内容：";
	cin >> attackText;

	GBKToUTF8(attackText);
	hk_tamper(id,(char*)attackText.c_str(),response);
	cout << "正在执行网站篡改攻击" << endl;

	string retStr = UTF8ToGBK(response);
	cout << retStr << endl;

	system("pause");
}

void attackRecord(){
	system("cls");
	char id[64];
	char response[4096];

	printInMiddle("---查看攻击记录---");

	cout << "请输入准备查看的网站ID:";
	scanf("%s",id);

	hk_record(id,response);
	cout << "正在查看攻击记录" << endl;

	string retStr = UTF8ToGBK(response);
	cout << retStr << endl;

	system("pause");
}

void attackRepair(){
	char id[64];
	char response[4096];
	system("pause");

	printInMiddle("---网站攻击修复---");

	cout << "请输入准备修复的网站ID:";
	scanf("%s",id);

	hk_restore(id,response);
	cout << "正在执行网站攻击修复" << endl;

	string retStr = UTF8ToGBK(response);
	cout << retStr << endl;
	system("pause");

}

void init(void){
	//设置终端窗口的大小
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
			cout << "无效输入，请重新输入" << endl;
			system;
			break;

		}

	}
	system("pause");

	return 0;
}