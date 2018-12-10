#include <stdio.h>
#include "stu_tea_adm_struct.h"
#include <stdlib.h>
#include <getch.h>
#include <string.h>
#include "teacher.h"
#include "teacher_dis.h"
#include "get_cmd.h"
#include "tea_ach_func.h"
/*
Student stu[500];
Teacher tea[50];
Administrator adm[10];
int stu_num = 0;
*/
extern Student stu[500];
extern Teacher tea[50];
extern Administrator adm[10];
int stu_num = 0;
int add_ach = 0;
//信息管理
int add_stu(int stu_num){
	int is_samename = 0;
	int a = stu_num;
	int add_pat = 0;
	printf("请输入导入方式(1:单个输入，２:批量导入)：\n");
	while(1){
		scanf("%d",&add_pat);
		if(add_pat == 1 || add_pat == 2){
			break;
		}else{
			printf("输入有误，请输入1或者2");
		}
	}
	if(add_pat == 1){
		if(!(a < 500)){
			printf("-----------学生已满----------\n");
			sleep(1);
			return a;
		}else{
			printf("请输入学号：");
			do{
				scanf("%s",stu[a].stu_id);
				for(int i = 0;i < a;i++){
					if((stu[i].is_study == 1 || stu[i].is_study == 2) && strcmp(stu[i].stu_id,stu[a].stu_id) == 0){	
						if(stu[i].is_study == 1){
							printf("学号以存在，请重新输入：\n");
						}else if(stu[i].is_study == 2){
							printf("该学生虽以退学，但学号依然存在，请输入新的学号：\n");
						}
						is_samename = 1;
						break;
					}else{
						is_samename = 0;	
					}
				}
			}while(is_samename);
			printf("请输入姓名：");
			scanf("%s",stu[a].name);
			printf("请输入性别(1：男，２：女)：");
			scanf("%d",&stu[a].sex);
			printf("请输入年龄:");
			scanf("%d",&stu[a].age);
			printf("录入成功\n");
			stu[a].is_study = 1;
			strcpy(stu[a].stu_pass_word,"88888888"); 
			sleep(1);
			return ++a;
		}
	}
	else if(add_pat == 2){
		int count = 500 - stu_num;
		int i = stu_num;
		char fname[20];
		int n = 0;
		int want_add_num = 0;
		printf("请输入想要导入的文件：\n");
		scanf("%s",fname);
		printf("请输入想导入的人数:\n");
		scanf("%d",&want_add_num);
		FILE *frp = fopen(fname,"r");
		if(NULL == frp)
		{
			perror("fopen");
			sleep(1);
			return 0;
		}
		while(i < want_add_num + stu_num ){
			fscanf(frp,"%s %s %d %d %d\n",stu[i].stu_id,stu[i].name,&stu[i].sex,&stu[i].age,&stu[i].is_study);
			strcpy(stu[i].stu_pass_word,"88888888");
			i++;
		}
		fclose(frp);
		printf("成功导入%d个学生信息\n",i - stu_num);
		add_ach = i - stu_num;
		sleep(1);
		return i;
	}
}

void delet_stu(){
	int n = stu_num;
	char want_delet_id[20];
	printf("请输入要删除的学生的学号：");
	scanf("%s",want_delet_id);
	for(int i = 0;i < n;i++){
		if(strcmp(stu[i].stu_id,want_delet_id) == 0){
			if(stu[i].is_study == 1){
				stu[i].is_study = 2;
				printf("删除成功\n");
			}else{
				printf("该学号已经是退学的的学生了\n");
			}
			break;
		}else if(i == n - 1){
			printf("查找不到该学号\n");
		}
	}
	if(n == 0){
		printf("不存在该学号\n");
	}
	sleep(1);
}

void mod_stu(){
	int flag = 0;
	int is_sameid = 0;
	int n = stu_num;
	char want_mod_stu_id[20];
	printf("请输入要修改信息的学生学号：");
	scanf("%s",want_mod_stu_id);
	for(int i = 0;i < n;i++){
		if(strcmp(want_mod_stu_id,stu[i].stu_id) == 0){
			flag = i;
			printf("请输入更改后的学号：");
			do{
				scanf("%s",stu[i].stu_id);
				for(int a = 0;a < n;a++){
					if((stu[a].is_study == 1 || stu[a].is_study == 2) && strcmp(stu[a].stu_id,stu[i].stu_id) == 0 && flag != a ){	
						printf("学号以存在，请重新输入：\n");
						is_sameid = 1;
						break;
					}else{
						is_sameid = 0;	
					}
				}
			}while(is_sameid);
			printf("请输入更改后的姓名：");
			scanf("%s",stu[flag].name);
			printf("请输入更改后的性别（１：男，２：女）：");
			scanf("%d",&stu[flag].sex);
			printf("请输入更改后的年龄：");
			scanf("%d",&stu[flag].age);
			printf("更改信息成功\n");
			break;
		}else if(i == n - 1){
		printf("不存在该学号\n");
		}
	}
	sleep(1);
}

void res_stu_pass(){
	int n = stu_num;
	char want_res_stu_id[20];
	printf("请输入要重置密码的学号：");
	scanf("%s",want_res_stu_id);
	for(int i = 0;i < n;i++){
		if(strcmp(want_res_stu_id,stu[i].stu_id) == 0){
			strcpy(stu[i].stu_pass_word,"88888888"); 
			printf("重置密码成功\n");
			break;
		}else if(i == n - 1){
			printf("不存在该学号\n");
		}
	}
	if(n == 0){
		printf("不存在该学号\n");
	}
	sleep(1);
}

void unlock_stu_acc(){
	int n = stu_num;
	char want_unlock_stu_id[20];
	printf("请输入想要解锁的学号：");
	scanf("%s",want_unlock_stu_id);
	for(int i = 0;i < n;i++){
		if(strcmp(want_unlock_stu_id,stu[i].stu_id) == 0){
			stu[i].is_lock = 0;
			printf("解锁成功\n");
			break;
		}else if(i == n - 1){
			printf("不存在该学号\n");
		}
	}
	if(n == 0){
		printf("不存在该学号\n");
	}
	sleep(1);
}

void sea_stu(){
	int is_one = 0;
	int n = stu_num;
	char want_know_stu[20];
	printf("请输入姓名：");
	scanf("%s",want_know_stu);
	system("clear");
	for(int i = 0;i < n;i++){
		if(strcmp(want_know_stu,stu[i].name) == 0){
			printf("学号    姓名    性别    年龄    状态\n");
			printf("%-5s   %-5s    %-2s    %-3d    %-2s\n",stu[i].stu_id,stu[i].name,stu[i].sex == 1 ? "男":"女",stu[i].age,stu[i].is_study == 1 ? "在读":"退学");
			is_one = 1;
		}else if((i == n - 1) && is_one == 0){
			printf("不存在该姓名\n");
		}
	}
	if(n == 0){
		printf("不存在该学生\n");
	}
	printf("* * * * * 按1键返回 * * * * *\n");
	while(1){
		if(getch() == '1')
			break;
	}
}

void dis_stu(){
	system("clear");
	int n = stu_num; 
	printf("学号    姓名    性别    年龄\n");
	for(int i = 0;i < n;i++){
		if(stu[i].is_study == 1){
			printf("%-5s    %-5s    %-5s    %-5d\n",stu[i].stu_id,stu[i].name,stu[i].sex == 1 ? "男":"女",stu[i].age);
		}
	}
	printf("* * * * * 按任意键返回 * * * * *");
	getch();
}

void dis_drop_stu(){
	system("clear");
	int n = stu_num; 
	printf("学号    姓名    性别    年龄\n");
	for(int i = 0;i < n;i++){
		if(stu[i].is_study == 2){
			printf("%-5s    %-5s    %-5s    %-5d\n",stu[i].stu_id,stu[i].name,stu[i].sex == 1 ? "男":"女",stu[i].age);
		}
	}
	printf("* * * * * 按任意键返回 * * * * *");
	getch();
}

void tea_cha_pass(int i){
	printf("请输入修改后的密码：");
	scanf("%s",tea[i].tea_pass_word);
	printf("修改成功\n");
	sleep(1);
}

void inf_key(int i){
	while(1){
		inf_display(i);
		switch(get_cmd('1','9')){
			case '1':stu_num = add_stu(stu_num);
				break;
			case '2':delet_stu();
				break;
			case '3':mod_stu();
				break;
			case '4':res_stu_pass();
				break;
			case '5':unlock_stu_acc();
				break;
			case '6':sea_stu();
				break;
			case '7':dis_stu();
				break;
			case '8':dis_drop_stu();
				break;
			case '9':return;
		}
	}
}
void ach_key(int i){
	while(1){
		ach_display(i);
		switch(get_cmd('1','5')){
			case '1':add_stu_ach();
				break;
			case '2':mod_stu_ach();
				break;
			case '3':sea_ach();
				break;
			case '4':ach_sort();
				break;
			case '5':return;
		}
	}
}
void teacher_func(int i){
	display(i);	
	if(tea[i].is_first == 0){
		printf("请更改登录密码:");
		scanf("%s",tea[i].tea_pass_word);
		printf("更改成功\n");
		tea[i].is_first = 1;
		sleep(1);
	}
	while(1){	
		display(i);
		switch(get_cmd('1','4')){
			case '1':inf_key(i);
				break;
			case '2':ach_key(i);
				break;
			case '3':tea_cha_pass(i);
				break;
			case '4':return;
		}
	}
}
