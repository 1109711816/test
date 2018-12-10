#ifndef __INF_H__
#define __INF_H__

typedef struct Student {
	char stu_id[20];
	char stu_pass_word[20];
	char name[20];
	int sex;
	int age;
	int ach_chi;
	int ach_mat;
	int ach_eng;
	int ach_sco;
	double ach_avg;
	int ach_rank;
	//１为在读，２为离校
	int is_study;
	//１为锁，２为没锁
	int is_lock;
	//是否为第一次登录,０为第一次登录
	int is_first;
	//1为已有成绩，0为没有
	int has_ach;
	int chi_rank;
	int mat_rank;
	int eng_rank;
	int sco_rank;
	int is_display;
}Student;

typedef struct Teacher{
	char tea_id[20];
	char tea_pass_word[20];
	char name[20];
	int sex;
	int age;
	int work_age;
	//１为在职，２为离职
	int is_work;
	//１为锁，２为没锁
	int is_lock;
	//是否为第一次登录,０为第一次登录
	int is_first;
}Teacher;

typedef struct Administrator{
	char adm_id[20];
	char adm_pass_word[20];
	//１为存在，０为不存在
	int is_alive;
	//１为锁，２为没锁
	int is_lock;
	//是否为第一次登录,０为第一次登录
	int is_first;
}Administrator;

#endif//
