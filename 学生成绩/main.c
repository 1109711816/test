#include <stdio.h>
#include <getch.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "stu_tea_adm_struct.h"
#include "student.h"
#include "teacher.h"
#include "adm.h"
#include "super_adm.h"
#include "get_cmd.h"
Student stu[500];
Teacher tea[50];
Administrator adm[10];
void show_menu(void)
{
	system("clear");
	puts("♪♪♪♪欢迎使用学生成绩管理系统♪♪♪♪");
	puts("|                              |");
	puts("|           1、学生            |");
	puts("|                              |");
	puts("|           2、教师            |");
	puts("|                              |");
	puts("|          3、管理员           |");
	puts("|                              |");
	puts("|        4、超级管理员         |");
	puts("|                              |");
	puts("|           5、退出            |");
	puts("|______________________________|");
	puts("请输入您的身份（输入相应数字）：");
}
void tea_username_and_password(void)
{
	char id[20];
	int a = 0;
	char str[10];
	int n = 3;
	puts("请输入工号:");
		int flag = 1;
		while(flag){
			scanf("%s",id);
			for(int i = 0;i < 50;i++ ){
				if(0==strcmp(tea[i].tea_id,id && tea[i].is_work == 1)){
					if(tea[i].is_lock == 1){
						printf("该工号被锁定！请向上一级（管理员）申诉\n");
						sleep(1);
						return;
					}else{
						flag = 0;
						a = i; 
						break;
					}
				}
				else if(0 == strcmp(tea[i].tea_id,id)&&tea[i].is_work == 2)
				{
					puts("该老师已离职，无法登陆!");
					return;
				}
				else if(i == 49){
					printf("该工号不存在\n");
					sleep(1);
					return;
				}
			}
		}
	puts("请输入密码：");
	do{
		n--;
		scanf("%s",str);
		if(0 != strcmp(tea[a].tea_pass_word,str)){
			if(n > 0){
				printf("密码错误，请重新输入（还有%d次）\n",n);	
			}else{
				printf("工号被锁定！请向上一级（管理员）申诉\n");
				tea[a].is_lock=1;
				sleep(1);
				return;
			}
		}
		else{
			teacher_func(a);//传参内容：第a个教师
			n = 0;
		}
	}while(n);
}

void stu_username_and_password(void)
{
	char id[20];
	int a = 0;
	char str[10];
	int n = 3;
	puts("请输入学号:");
	int flag = 1;
	while(flag){
		scanf("%s",id);
		for(int i = 0;i < 500;i++ ){
			if(0==strcmp(stu[i].stu_id,id)&&stu[i].is_study == 1){
				if(stu[i].is_lock == 1){
					printf("该学号被锁定！请向上一级（教师）申诉\n");
					sleep(1);
					return;
				}else{
					flag = 0;
					a = i; 
					break;
				}
			}
			else if(0==strcmp(stu[i].stu_id,id)&&sti[i].is_study ==2)
			{
				puts("该学生已退学，无法登陆！");
				return;
			}
			else if(i == 499){
				printf("该学号不存在\n");
				sleep(1);
				return;
			}
		}
	}	
	puts("请输入密码：");
	do{
		n--;
		scanf("%s",str);
		if(0 != strcmp(stu[a].stu_pass_word,str)){
			if(n > 0){
				printf("密码错误，请重新输入（还有%d次）\n",n);	
			}else{
				printf("学号被锁定！请向上一级（教师）申诉\n");
				stu[a].is_lock=1;
				sleep(1);
				return;
			}
		}
		else{
			student_use(a);
			n = 0;
		}
	}while(n);
}
void adm_username_and_password(void)
{
	char id[20];
	char id_flag[20];
	int a = 0;
	char str[10];
	int n = 3;
	puts("请输入管理号ID:");
	int flag = 1;
	while(flag){
		scanf("%s",id);
		for(int i = 0;i < 10;i++ ){
			if(0==strcmp(id,adm[i].adm_id)&&adm[i].is_alive==1){
				if(adm[i].is_lock == 1){
					printf("该管理员ＩＤ被锁定！请向上一级（超级管理员）申诉\n");
					sleep(1);
					return;
				}else{
					flag = 0;
					a = i; 
					break;
				}
			}
			else if(0 == strcmp(id,adm[i]_id)&&adm[i].is_alive==2)
			{
				puts("该管理员已不存在，登录失败");
				return;
			}
			else if(i == 9){
				printf("该管理员不存在\n");
				sleep(1);
				return;
			}
		}
	}
	puts("请输入密码：");
	do{
		n--;
		scanf("%s",str);
		if(0 != strcmp(adm[a].adm_pass_word,str)){
			if(n > 0){
				printf("密码错误，请重新输入（还有%d次）\n",n);	
			}else{
				printf("管理员ＩＤ被锁定！请向上一级（超级管理员）申诉\n");
				adm[a].is_lock=1;
				sleep(1);
				return;
			}
		}
		else{
			nor_adm(a);
			n = 0;
		}
	}while(n);
}
void password(void)
{
	char str[20]="888888";
	char *super_pass;
	puts("请输入密码：");
	while(1)
	{
		super_pass = getpass("");
		if(0 == strcmp(super_pass,str))
		{
			super_adm();
			break;
		}
	}
}

void main()
{
	while(1){
		show_menu();
		switch(get_cmd('1','5'))
		{
			case '1':stu_username_and_password();break;
			case '2':tea_username_and_password();break;
			case '3':adm_username_and_password();break;
			case '4':password();break;
			case '5':puts("退出成功!");return;
		}
	}
}
