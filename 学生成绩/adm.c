#include<stdio.h>
#include<getch.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include"adm.h"
#include"super_adm.h"
#include"get_cmd.h"
#include "stu_tea_adm_struct.h"
extern Student stu[500];
extern Teacher tea[50];
extern Administrator adm[10];
extern int stu_num;
int count=0;
char a[50];

//添加老师模块
int add_tea(void)
{
	int x=0,what_key=0;
	if(count >= 50) {printf("老师个数已满，无法添加\n");return 0;}
	while(1)
	{
		scanf("%d",&what_key);
		if(1==what_key||2==what_key)
		{
			break;
		}
		printf("输入错误，输入1或2!");
		continue;
	}
	if(1==what_key)//单个输入老师
	{	
		for(int i=0 ; i<50 ; i++)
		{
			if(0 == b[i])
			{
				printf("请输入工号:");
				scanf("%s",tea[i].tea_id);
				if(-1!=find_tea_id(tea[i].tea_id))
				{
					x=find_tea_id(tea[i].tea_id);
					if(1==tea[x].is_work)
					{
						puts("工号重复，添加失败！");
						return 0;
					}
					else if(2==tea[x].is_work)
					{
						puts("虽已离职，工号依旧存在，添加失败！");	
						return 0;
					}
				}
				strcpy(tea[i].tea_pass_word,"88888888");
				printf("请输入姓名:");
				scanf("%s",tea[i].name);
				printf("请输入性别（1、男 2、女）:");
				scanf("%d",&tea[i].sex);
				printf("请输入年龄:");
				scanf("%d",&tea[i].age);
				printf("请输入工龄:");
				scanf("%d",&tea[i].work_age);
				tea[i].is_work=1;
				b[i]=1;
				puts("添加成功");
				count++;
				return 0;
			}
		}
	}
	else if(2==what_key)//文件导入老师信息
	{
		int add = 50 - count;
		int i = 0;
		char fname[20];
		printf("请输入你想导入的文件：\n");
		scanf("%s",fname);
		FILE *frp = fopen(fname,"r");
		if(NULL==frp)
		{
			perror("fopen");
			sleep(1);
			return -1;
		}
		while(i < add )
		{
			fscanf(frp,"%s %s %d %d %d %d\n",tea[i].tea_id,tea[i].name,&tea[i].sex,&tea[i].age,&tea[i].work_age,&tea[i].is_work);
			strcpy(tea[i].tea_pass_word,"88888888");
			b[i]=1;
			i++;
		}
		fclose(frp);
		sleep(1);
		return i;
	}
}

int find_tea_id(char* str)//查找老师工号是否存在模块
{
	for(int i=0;i<50;i++)
	{
		if(0==strcmp(str,tea[i].tea_id)&&b[i])
		{
			return i;
		}
	}
	return -1;
}

void sear_tea(void)//查询老师的信息
{
	puts("请输入工号：");
	char key[20];
	gets(key);
	int i=find_tea_id(key);
	if(-1!=i)
	{
		puts("工号   姓名   性别   年龄   工龄");
		printf("%-s     %-s     %-s     %-d     %-d\n",tea[i].tea_id,tea[i].name,tea[i].sex == 1 ?"男":"女",tea[i].age,tea[i].work_age);
		puts("按任意键返回！");
		getch();
	}
	else
	{	
		puts("工号不存在，查询失败！");
		puts("按任意键返回！");
		getch();
	}
}

void mod_tea(void)//修改老师信息模块
{
	puts("请输入工号：");
	char key[20];
	gets(key);
	int i=find_tea_id(key);
	if(-1!=i)
	{
			printf("请输入姓名:");
			gets(tea[i].name);
			printf("请输入性别:");
			scanf("%d",&tea[i].sex);
			printf("请输入年龄:");
			scanf("%d",&tea[i].age);
			printf("请输入工龄:");
			scanf("%d",&tea[i].work_age);
			puts("修改完成！");
			puts("按任意键返回！");
			getch();
	}
	else
	{
		puts("工号不存在，修改失败！");
		puts("按任意键返回！");
		getch();
	}
}

void res_tea_pass(void)//重置老师密码模块
{
	puts("请输入工号：");
	char key[20];
	gets(key);
	int i=find_tea_id(key);
	if(-1!=i)
	{
		strcpy(tea[i].tea_pass_word,"88888888");
		puts("重置密码成功！");
		tea[i].is_first=0;
		puts("按任意键返回！");
		getch();
	}
	else
	{
		puts("工号不存在，重置失败！");
		puts("按任意键返回！");
		getch();
	}
}


void unlock_tea_acc(void)//解锁老师账号模块
{
	puts("请输入工号：");
	char key[20];
	gets(key);
	int i=find_tea_id(key);
	if(-1!=i)
	{
		tea[i].is_lock=0;
		puts("解锁成功！");
		puts("按任意键返回！");
		getch();
	}
	else
	{
		puts("工号不存在，解锁失败！");
		puts("按任意键返回！");
		getch();
	}

}

void del_tea(void)//删除老师并记离职模块
{
	puts("请输入工号：");
	char key[20];
	gets(key);
	int i=find_tea_id(key);
	if(-1!=i)
	{
		b[i]=1;
		tea[i].is_work=2;
		puts("删除成功!");
		return;
	}
	else
	{
		puts("工号不存在，删除失败");
	}
}

void dis_tea(void)//显示在职老师模块
{
	puts("工号   姓名   性别   年龄   工龄");
	for(int i=0;i<50;i++)
	{
		if(1==tea[i].is_work)
		{
			printf("%-s     %-s     %-s     %-d     %-d\n",tea[i].tea_id,tea[i].name,tea[i].sex == 1 ?"男":"女",tea[i].age,tea[i].work_age);
		}	
	}
	puts("按任意键返回！");
	getch();
}

void dis_quit_tea(void)//显示离职老师模块
{
	puts("工号   姓名   性别   年龄   工龄");
	for(int i=0;i<50;i++)
	{
		if(2==tea[i].is_work)
		{
			printf("%-s     %-s     %-s     %-d     %-d\n",tea[i].tea_id,tea[i].name,tea[i].sex == 1 ?"男":"女",tea[i].age,tea[i].work_age);
		}
	}
	puts("按任意键返回！");
	getch();
}

void adm_cha_pass(int i)//修改密码模块
{
	char pass[20];
	puts("请输入你的旧密码：");
	gets(pass);
	if(0==strcmp(pass,adm[i].adm_pass_word))
	{
		puts("请输入你的新密码：");
		gets(pass);
		strcpy(adm[i].adm_pass_word,pass);
		adm[i].is_first=1;
		puts("新密码设定成功！");
		puts("按任意键返回！");
		getch();
	}
}

void display_nor_adm(void)//显示模块
{
	system("clear");
	puts(" ❀ ❀ ❀ 欢迎您，管理员！❀ ❀ ❀ ");
	puts("|       1、添加教师         |");
	puts("|       2、删除教师         |");
	puts("|      3、修改教师信息      |");
	puts("|      4、重置教师密码      |");
	puts("|      5、解锁教师账号      |");
	puts("|      6、查询教师信息      |");
	puts("|      7、显示在职教师      |");
	puts("|      8、显示离职教师      |");
	puts("|      9、修改登录密码      |");
	puts("|         0、退出           |");
	puts("|~~~~~~~~~~~~~~~~~~~~~~~~~~~|");
}

void nor_adm(int i)
{//第一次进入修改密码
	display_nor_adm();
	if(0==adm[i].is_first)
	{
		puts("修改登录密码");
		puts("输入你的新密码：");
		scanf("%s",adm[i].adm_pass_word);
		adm[i].is_first=1;
		puts("修改成功!");
		sleep(1);
		display_nor_adm();
	}
	while(1)
	{//选择功能
		display_nor_adm();
		switch(get_cmd('0','9'))
		{
		case '1':puts("按1为单个添加教师，按2多个添加");add_tea();
		sleep(1);display_nor_adm();break;
		case '2':del_tea();sleep(1);break;
		case '3':mod_tea();sleep(1);break;
		case '4':res_tea_pass();break;
		case '5':unlock_tea_acc();break;
		case '6':sear_tea();break;
		case '7':dis_tea();break;
		case '8':dis_quit_tea();break;
		case '9':adm_cha_pass(i);break;
		case '0':return;
		}
	}
}
