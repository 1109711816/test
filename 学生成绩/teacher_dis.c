#include <stdio.h>
#include "teacher_dis.h"
#include "stu_tea_adm_struct.h"
#include <stdlib.h>
extern Teacher tea[50];
void display(int i){
	system("clear");
	printf("———————————————————————————————————————————\n");
	printf("|         欢迎登录学生管理系统,%s        |\n",tea[i].name);
	printf("|         输入１进入学生信息系统       	  |\n");
	printf("|         输入２进入学生成绩系统          |\n");
	printf("|         输入３修改密码                  |\n");
	printf("|         输入４退出学生管理系统          |\n");
	printf("|_________________________________________|\n");
}

void inf_display(int i){
	system("clear");
	printf("———————————————————————————————————————————————————————————\n");
	printf("|         欢迎使用学信息管理理系统,%s                     | \n",tea[i].name);
	printf("|         输入１添加学生 （学号，姓名，性别，年龄）        |\n");
	printf("|         输入２删除学生（记作退学）                       |\n");
	printf("|         输入３修改学生基本信息                           |\n");
	printf("|         输入４重置学生密码                               |\n");
	printf("|         输入５解锁学生账户                               |\n");
	printf("|         输入６根据学生姓名查找学生                       |\n");
	printf("|         输入７显示所有在读学生                           |\n");
	printf("|         输入８显示所有退学学生                           |\n");
	printf("|         输入９退出学生信息管理系统                       |\n");
	printf("|__________________________________________________________|\n");
}

void ach_display(int i){
	system("clear");
	printf("———————————————————————————————————————————————————————————\n");
	printf("|         欢迎使用学生成绩管理系统,%s                     |\n",tea[i].name);
	printf("|         输入１录入成绩（语文，数学，英语）               |\n");
	printf("|         输入２修改成绩                                   |\n");
	printf("|         输入３根据学号或姓名查询学生成绩                 |\n");
	printf("|         输入４按各科成绩排名                             |\n");
	printf("|         输入５退出学生成绩管理系统                       |\n");
	printf("|__________________________________________________________|\n");
}
