#include <stdio.h>
#include <string.h>
#include <getch.h>
#include <stdlib.h>
#include"adm.h" 
#include"super_adm.h"
#include "stu_tea_adm_struct.h"
#include<time.h>
#include "get_cmd.h"
extern Student stu[500];
extern Teacher tea[50];
extern Administrator adm[10];
extern int stu_num;

int super_count=0;
char a[10];
int find_adm_id(char* str)//查找管理员id模块
{
	for(int i=0;i<10;i++)
	{
		if(0==strcmp(str,adm[i].adm_id)&&a[i])
		{
			return i;
		}	
	}
	return -1;
}

void add_adm(void)//添加管理员模块
{
	if(super_count>=10) 
	{
		printf("管理员个数已满，无法添加\n");
		return;
	}
	for(int i=0;i<10;i++)
	{
		if(0==a[i])
		{
			printf("请输入管理员账号:");
			scanf("%s",adm[i].adm_id);
				if(-1!=find_adm_id(adm[i].adm_id))
				{
					puts("账号重复，输入失败！");
					return;
				}
			strcpy(adm[i].adm_pass_word,"88888888");
			puts("管理员添加成功");
			adm[i].is_alive=1;
			a[i]=1;
			super_count++;
			return;
		}
	}
}

void del_adm(void)//删除管理员模块
{
	puts("请输入管理员帐号：");
	char key[20];
	gets(key);
	int i=find_adm_id(key);
	if(-1!=i)
	{
		adm[i].is_alive=0;
		puts("删除成功!");
		a[i]=0;
		super_count--;
		return;
	}
	else puts("账号不存在");
}

void res_adm_pass(void)//重置管理员密码模块
{
	puts("请输入管理员帐号：");
	char key[20];
	gets(key);
	int i=find_adm_id(key);
	if(-1!=i)
	{
		strcpy(adm[i].adm_pass_word,"88888888");
		puts("重置密码成功");
		puts("按任意键返回！");
		getch();
	}
	else
	{
		puts("账号不存在，重置失败!");
		puts("按任意键返回！");
		getch();
	}
}
void unlock_adm_acc(void)//解锁账号模块
{
	puts("请输入管理员帐号：");
	char key[20];
	gets(key);
	int i=find_adm_id(key);
	if(-1!=i)
	{
		adm[i].is_lock=0;
		puts("解锁成功！");
		puts("按任意键返回！");
		getch();
	}
	else
	{
		puts("账号不存在，解锁失败！");
		puts("按任意键返回！");
		getch();
	}
}

void dis_all_adm(void)//显示所有管理员模块
{
	puts("管理员ｉｄ");
	for(int i=0;i<10;i++)
	{
		if(1==adm[i].is_alive)
		{
			printf("　　%s\n",adm[i].adm_id);
		}
	}
	puts("按任意键返回！");		
	getch();
}

void display_super_adm(void)//显示模块
{
	system("clear");
	puts("____________O(∩_∩)O____________");
	puts("|❤ ❤ ❤ 欢迎您，超级管理员❤ ❤ ❤ |");
	puts("|☺ ☺ ☺ ☺ ☺ ☺ ☺ ☺ ☺ ☺ ☺ ☺ ☺ ☺ ☺ |");
	puts("|       1、添加管理员          |");
	puts("|       2、删除管理员          |");
	puts("|      3、重置管理员密码       |");
	puts("|      4、解锁管理员帐号       |");
	puts("|      5、显示所有管理员       |");
	puts("|          6、退出             |");
	puts("|______________________________|");
	puts("请输入指令：");
}
void super_adm(void)
{
	while(1)
	{//选择功能
		display_super_adm();
		switch(get_cmd('1','6'))
		{
			case '1':add_adm();sleep(1);break;
			case '2':del_adm();sleep(1);break;
			case '3':res_adm_pass();break;
			case '4':unlock_adm_acc();break;
			case '5':dis_all_adm();break;
			case '6':return;break;
		}
	}
}
