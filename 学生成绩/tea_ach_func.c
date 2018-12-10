#include <stdio.h>
#include <stdlib.h>
#include <getch.h>
#include "tea_ach_func.h"
#include "teacher.h"
#include "stu_tea_adm_struct.h"
#include <string.h>
extern Student stu[500];
extern Teacher tea[50];
extern Administrator adm[10];
extern int  stu_num;
extern int add_ach;
int abcdefg = 0;
void add_stu_ach(){
	int have_stu = 0;
	int n = stu_num;
	int add_pat = 0;
	char want_add_ach_id[20];
	printf("请输入导入方式(1:单个输入，２:批量导入)：\n");
	while(1){
		scanf("%d",&add_pat);
		if(add_pat == 1 || add_pat == 2)
			break;
		printf("输入有误，请重新输入：");
	}
	if(add_pat == 1){
		printf("请输入想要录入成绩的学号：");
		scanf("%s",want_add_ach_id);
		for(int i = 0;i < n; i++){
			if((stu[i].is_study == 1 || stu[i].is_study == 2)&& strcmp(want_add_ach_id,stu[i].stu_id) == 0){
				if(stu[i].is_study == 1){
					if(stu[i].has_ach == 1){
						printf("该学号已有成绩\n");
						break;
					}else{
						printf("请输入语文成绩：");
						scanf("%d",&stu[i].ach_chi);
						printf("请输入数学成绩：");
						scanf("%d",&stu[i].ach_mat);
						printf("请输入英语成绩：");
						scanf("%d",&stu[i].ach_eng);
						stu[i].ach_sco = stu[i].ach_chi + stu[i].ach_mat + stu[i].ach_eng;
						stu[i].ach_avg = stu[i].ach_sco / 3.0;
						printf("录入成绩成功\n");
						stu[i].has_ach = 1;
						break;
					}
				}else if(stu[i].is_study == 2){
					printf("该学生已退学");
				}
				}else if(i == n - 1){
					printf("不存在该学号\n");
				}
				
		}
	}
	else if(add_pat == 2){
	//*****************************************//
		int flag = 0;
		int i = abcdefg;
		char fname[20];
		int want_add_ach_num = 0;
		printf("请输入想要导入的文件：\n");
		scanf("%s",fname);
		FILE *frp_ach = fopen(fname,"r");
		if(NULL == frp_ach)
		{
			perror("fopen");
			sleep(1);
			return;
		}
		while(i < add_ach + abcdefg ){
		 	fscanf(frp_ach,"%d %d %d %d\n",&stu[i].ach_chi,&stu[i].ach_mat,&stu[i].ach_eng,&stu[i].has_ach);
			stu[i].ach_sco = stu[i].ach_chi + stu[i].ach_mat + stu[i].ach_eng;
			stu[i].ach_avg = stu[i].ach_sco / 3.0;
			i++;
		}
		fclose(frp_ach);
		flag = i - abcdefg;
		abcdefg = i;
		printf("成功导入%d个学生信息\n",flag);
	//*****************************************//
	}
	sleep(1);
}

void mod_stu_ach(){
	int sub_flag = 0;
	char want_mod_ach_id[20];
	int n = stu_num;
	printf("请输入想要修改成绩的学号");
	scanf("%s",want_mod_ach_id);
	for(int i = 0;i < n;i++){
		if(stu[i].is_study == 1 && strcmp(want_mod_ach_id,stu[i].stu_id) == 0){
			printf("请输入想修改的成绩(1.语文2.数学3.英语)：");
			while(1){
				scanf("%d",&sub_flag);
				if(sub_flag == 1 || sub_flag == 2 || sub_flag == 3)
					break;
				printf("输入有误，请重新输入");
			}
			if(sub_flag == 1){
				printf("请输入修改后的语文成绩：");
				scanf("%d",&stu[i].ach_chi);
			}else if(sub_flag == 2){
				printf("请输入修改后的数学成绩：");
				scanf("%d",&stu[i].ach_mat);
			}else if(sub_flag == 3){
				printf("请输入修改后的英语成绩：");
				scanf("%d",&stu[i].ach_eng);	
			}
			printf("修改完成\n");
			stu[i].ach_sco = stu[i].ach_chi + stu[i].ach_mat + stu[i].ach_eng;
			stu[i].ach_avg = stu[i].ach_sco / 3.0;
			break;
		}
	}
	if(n == 0){
		printf("不存在该学号");
	}
	sleep(1);
}

void sea_ach(){
	int have_stu = 0;
	int n = stu_num;
	char want_sea_ach[20];
	printf("请输入学号或姓名查询成绩");
	scanf("%s",want_sea_ach);
	for(int i = 0;i < n;i++){
		if(strcmp(want_sea_ach,stu[i].stu_id) == 0 || strcmp(want_sea_ach,stu[i].name) == 0){
			printf("学号     姓名   语文   数学   英语   总分   平均分\n");
			printf("%-5s   %5s   %-2d     %-2d     %-2d     %-2d   %-2.2lf\n",stu[i].stu_id,stu[i].name,stu[i].ach_chi,stu[i].ach_mat,stu[i].ach_eng,stu[i].ach_sco,stu[i].ach_avg);
			have_stu = 1;
		}else if(i == n - 1 && have_stu == 0){
			printf("查无此人\n");
		}
	}
	if(n == 0){
		printf("查无此人\n");
	}
	printf("* * * * * 按1键返回 * * * * *\n");
	while(1){
		if(getch() == '1')
			break;
	}
}
void ach_sort(){
	int flag = 0;
	int n = stu_num;
	int ach_num[500] = {};
	int want_sort_sub = 0;
	printf("请输入要排序的科目（１.语文 ２.数学 3.英语 4.总分）：");
	scanf("%d",&want_sort_sub);
	for(int i = 0;i < n;i++){
		stu[i].is_display = 0;
	}

	//语文排序
	if(want_sort_sub == 1){
		for(int i = 0;i < n; i++){
			ach_num[i] = stu[i].ach_chi;
		}
		for(int j = 0;j < n - 1;j++){
			for(int i = 0;i < n - 1;i++){
				if(ach_num[i] < ach_num[i + 1]){
					flag = ach_num[i + 1];
					ach_num[i + 1] = ach_num[i];
					ach_num[i] = flag;
				}
			}
		}
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				if(stu[i].ach_chi == ach_num[j]){
					stu[i].chi_rank = j + 1;
					break;
				}
			}
		}
		printf("学号     姓名   语文成绩   排名\n");
		for(int i = 0 ;i < n;i++){
			for(int j = 0; j < n;j++){
				if(ach_num[i] == stu[j].ach_chi && stu[j].is_display == 0){
					printf("%-5s   %-5s    %-2d     %-2d\n",stu[j].stu_id,stu[j].name,stu[j].ach_chi,stu[j].chi_rank);
					stu[j].is_display = 1;
					break;
				}
			}
		}
		printf("排序成功！\n");
	//数学排序
	}else if(want_sort_sub == 2){
		for(int i = 0;i < n; i++){
			ach_num[i] = stu[i].ach_mat;
		}
		for(int j = 0;j < n -1;j++){
			for(int i = 0;i < n - 1;i++){
				if(ach_num[i] < ach_num[i + 1]){
					flag = ach_num[i + 1];
					ach_num[i + 1] = ach_num[i];
					ach_num[i] = flag;
				}
			}
		}
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				if(stu[i].ach_mat == ach_num[j]){
					stu[i].mat_rank = j + 1;
					break;
				}
			}
		}
		printf("学号     姓名   数学成绩   排名\n");
		for(int i = 0 ;i < n;i++){
			for(int j = 0; j < n;j++){
				if(ach_num[i] == stu[j].ach_mat && stu[j].is_display == 0){
					printf("%-5s   %-5s    %-2d     %-2d\n",stu[j].stu_id,stu[j].name,stu[j].ach_mat,stu[j].mat_rank);
					stu[j].is_display = 1;
					break;
				}
			}
		}
		printf("排序成功！\n");
	//英语排序
	}else if(want_sort_sub == 3){
		for(int i = 0;i < n; i++){
			ach_num[i] = stu[i].ach_eng;
		}
		for(int j = 0;j < n - 1;j++){
		for(int i = 0;i < n - 1;i++){
				if(ach_num[i] < ach_num[i + 1]){
					flag = ach_num[i + 1];
					ach_num[i + 1] = ach_num[i];
					ach_num[i] = flag;
				}
			}
		}
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				if(stu[i].ach_eng == ach_num[j]){
					stu[i].eng_rank = j + 1;
					break;
				}
			}
		}
		printf("学号     姓名   英语成绩   排名\n");
		for(int i = 0 ;i < n;i++){
			for(int j = 0; j < n;j++){
				if(ach_num[i] == stu[j].ach_eng && stu[j].is_display == 0){
					printf("%-5s   %-5s    %d     %-2d\n",stu[j].stu_id,stu[j].name,stu[j].ach_eng,stu[j].eng_rank);
					stu[j].is_display = 1;
					break;
				}
			}
		}
		printf("排序成功！\n");
	//总分排序
	}else if(want_sort_sub == 4){
		for(int i = 0;i < n; i++){
			ach_num[i] = stu[i].ach_sco;
		}
		for(int j = 0;j < n - 1;j++){
			for(int i = 0;i < n -1;i++){
				if(ach_num[i] < ach_num[i + 1]){
					flag = ach_num[i + 1];
					ach_num[i +1 ] = ach_num[i];
					ach_num[i] = flag;
				}
			}
		}
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				if(stu[i].ach_sco == ach_num[j]){
					stu[i].sco_rank = j + 1;
					break;
				}
			}
		}
		printf("学号     姓名   总成绩   平均   平均分   排名\n");
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				if(ach_num[i] == stu[j].ach_sco &&stu[j].is_display == 0){
					printf("%-5s   %-5s    %d    %-2.2lf     %-2d\n",stu[j].stu_id,stu[j].name,stu[j].ach_sco,stu[j].ach_avg,stu[j].sco_rank);
					stu[j].is_display = 1;
					break;
				}
			}
		}
		printf("排序成功!\n");
	}
	printf("* * * * * 输１键返回 * * * * *");
	while(1){
		if(getch() == '1')
			break;
	}
}
