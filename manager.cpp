#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100 



//学号、姓名、年龄、性别、出生年月、家庭住址、电话、E-mail
struct Student
{
	int id;//学号
	char name[20];//姓名 
	char sex[20];//性别
	char birthday[20];//出生年月
	char address[20];//家庭地址
	char phone[20];//电话
	char email[20];//E-mail


};
int student_number = 0;
struct Student student[MAX];

struct User
{

	char username[20];//用户名 
	char password[20];//密码
	int role;//角色(1.管理员 2.学生)


};
int user_number = 0;
struct User user[MAX];


//菜单
void menu()
{
	printf("=======================================\n");
	printf("=          学生信息管理系统           =\n");
	printf("=            1.管理员                 =\n");
	printf("=            2.学生                   =\n");
	printf("=            3.注册                   =\n");
	printf("=            0.退出                   =\n");
	printf("=======================================\n");
}
void menu1()
{
	printf("=======================================\n");
	printf("=             管理员界面              =\n");
	printf("=           1.增加学生信息            =\n");
	printf("=           2.删除学生信息            =\n");
	printf("=           3.修改学生信息            =\n");
	printf("=           4.查询学生信息            =\n");
	printf("=           5.浏览学生信息            =\n");
	printf("=           6.学生信息排序            =\n");
	printf("=           7.保存学生信息            =\n");
	printf("=           0.退出系统                =\n");
	printf("=======================================\n");
}
void menu2()
{
	printf("=======================================\n");
	printf("=             学生界面                =\n");
	printf("=           1.查询学生信息            =\n");
	printf("=           2.浏览学生信息            =\n");
	printf("=           0.退出系统                =\n");
	printf("=======================================\n");
}
//保存文件
void save_student()
{
	FILE* file;
	if ((file = fopen("student.txt", "w")) == NULL)
	{
		printf("文件打开失败！");
		return;
	}

	for (int i = 0; i < student_number; i++)
	{
		fprintf(file, "%d ", student[i].id);
		fprintf(file, "%s ", student[i].name);
		fprintf(file, "%s ", student[i].sex);
		fprintf(file, "%s ", student[i].birthday);
		fprintf(file, "%s ", student[i].address);
		fprintf(file, "%s ", student[i].phone);
		fprintf(file, "%s\n", student[i].email);
	}

	fclose(file);
	printf("保存文件成功！\n");

}
void save_user()
{
	FILE* file;
	if ((file = fopen("user.txt", "w")) == NULL)
	{
		printf("文件打开失败！");
		return;
	}

	for (int i = 0; i < user_number; i++)
	{
		fprintf(file, "%s ", user[i].username);
		fprintf(file, "%s ", user[i].password);
		fprintf(file, "%d\n", user[i].role);
	}

	fclose(file);
	printf("保存文件成功！\n");

}
//加载文件信息
void load_student()
{
	char filename[20];
	printf("请输入读取的文件名称(如student.txt):\n");
	scanf("%s", filename);
	FILE* fp;
	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		printf("打开文件失败！\n");
		return;
	}

	int flag = 0;

	while (!feof(fp))
	{
		flag = 0;
		fscanf(fp, "%d %s %s %s %s %s %s\n",
			&student[student_number].id,
			student[student_number].name,
			student[student_number].sex,
			student[student_number].birthday,
			student[student_number].address,
			student[student_number].phone,
			student[student_number].email);

		for (int i = 0; i < student_number; i++)
		{
			if (student[student_number].id == student[i].id)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			student_number++;
		}

	}

	fclose(fp);
	printf("加载文件信息成功!\n");

}
// 初始化默认管理员信息
void initialize_default_admin() {
    strcpy(user[user_number].username, "Theresa");
    strcpy(user[user_number].password, "teriteri");
    user[user_number].role = 1;
    user_number++;
}

void load_user()
{
	FILE* fp;
	fp = fopen("user.txt", "r");
	if (fp == NULL)
	{
		printf("打开文件失败！\n");
		return;
	}

	int flag = 0;

	while (!feof(fp))
	{
		flag = 0;
		fscanf(fp, "%s %s %d\n",
			user[user_number].username,
			user[user_number].password,
			&user[user_number].role);

		for (int i = 0; i < user_number; i++)
		{
			if (!strcmp(user[user_number].username , user[i].username))
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			user_number++;
		}

	}

	fclose(fp);
	printf("加载文件信息成功!\n");

}
//录入学生信息
void add_student()
{

	printf("请输入学生学号：\n");
	scanf("%d", &student[student_number].id);
	for (int i = 0; i < student_number; i++)
	{
		if (student[student_number].id == student[i].id)
		{
			printf("存在该学号，添加失败！\n");
			return;
		}
	}

	printf("请输入学生姓名：\n");
	scanf("%s", student[student_number].name);

	printf("请输入学生性别：\n");
	scanf("%s", student[student_number].sex);
	printf("请输入学生出生年月：\n");
	scanf("%s", student[student_number].birthday);
	printf("请输入学生地址：\n");
	scanf("%s", student[student_number].address);
	printf("请输入学生电话：\n");
	scanf("%s", student[student_number].phone);
	printf("请输入学生E-mail：\n");
	scanf("%s", student[student_number].email);
	student_number++;
	printf("添加学生信息成功！\n");

}
//删除学生信息
void delete_student()
{
	printf("请输入你要删除的学号：\n");
	int id;
	int a = 1;
	scanf("%d", &id);
	for (int i = 0; i < student_number; i++)
	{
		if (id == student[i].id)
		{
			a++;
			for (int j = i; j < student_number - 1; j++)
			{
				student[j] = student[j + 1];
			}
			student_number--;
			printf("删除成功!\n");


			break;
		}
	}

	if (a == 1)
	{
		printf("没有该学生信息！\n");
		return;
	}

}
//修改学生信息
void update_student()
{
	printf("请输入你要修改的学号：\n");
	int id;
	int a = 1;
	scanf("%d", &id);
	for (int i = 0; i < student_number; i++)
	{
		if (id == student[i].id)
		{
			a++;
			printf("请输入学生姓名：\n");
			scanf("%s", student[i].name);

			printf("请输入学生性别：\n");
			scanf("%s", student[i].sex);
			printf("请输入学出生年月：\n");
			scanf("%s", student[i].birthday);
			printf("请输入学生地址：\n");
			scanf("%s", student[i].address);
			printf("请输入学生电话：\n");
			scanf("%s", student[i].phone);
			printf("请输入学生E-mail：\n");
			scanf("%s", student[i].email);


			printf("修改成功!\n");


			break;
		}
	}

	if (a == 1)
	{
		printf("没有该学生信息！\n");
		return;
	}

}
//浏览学生信息
void show_student()
{

	if (student_number == 0)
	{
		printf("没有信息！\n");
		return;
	}

	for (int i = 0; i < student_number; i++)
	{


		printf("学号：%d\t", student[i].id);
		printf("姓名：%s\t", student[i].name);
		printf("性别：%s\t", student[i].sex);
		printf("出生年月：%s\t", student[i].birthday);
		printf("地址：%s\t", student[i].address);
		printf("电话：%s\t", student[i].phone);
		printf("E-mail：%s\n", student[i].email);

	}


}
//查询学生信息
void query_student()
{
	printf("1.按姓名查找 \n");
	printf("2.按学号查找\n");
	printf("请输入你的选择：");
	int chioce;
	scanf("%d", &chioce);
	switch (chioce)
	{
	case 1:
	{
		char name[20];
		int temp = 0;
		printf("请输入查找的姓名：");
		scanf("%s", name);
		for (int i = 0; i < student_number; i++)
		{
			if (!strcmp(name, student[i].name))
			{
				temp++;
				printf("学号：%d\t", student[i].id);
				printf("姓名：%s\t", student[i].name);
				printf("性别：%s\t", student[i].sex);
				printf("出生年月：%s\t", student[i].birthday);
				printf("地址：%s\t", student[i].address);
				printf("电话：%s\t", student[i].phone);
				printf("E-mail：%s\n", student[i].email);

			}
		}
		if (temp == 0)
		{
			printf("没有该学生信息，查找失败！\n");
		}
	}
	break;
	case 2:
	{
		int id;
		int temp = 0;
		printf("请输入查找的学号：");
		scanf("%d", &id);
		for (int i = 0; i < student_number; i++)
		{
			if (id == student[i].id)
			{
				temp++;
				printf("学号：%d\t", student[i].id);
				printf("姓名：%s\t", student[i].name);
				printf("性别：%s\t", student[i].sex);
				printf("出生年月：%s\t", student[i].birthday);
				printf("地址：%s\t", student[i].address);
				printf("电话：%s\t", student[i].phone);
				printf("E-mail：%s\n", student[i].email);

			}
		}
		if (temp == 0)
		{
			printf("没有该学生信息，查找失败！\n");
		}
	}
	break;

	default:
		printf("输入有误,将返回主菜单！\n");
	}

}
//学生信息排序
void sort_student()
{
	if (student_number == 0)
	{
		printf("没有信息！\n");
		return;

	}
	printf("1.按姓名排序 \n");
	printf("2.按学号排序\n");
	printf("请输入你的选择：");
	int chioce;
	scanf("%d", &chioce);
	switch (chioce)
	{
	case 1:
	{
		for (int i = 0; i < student_number; i++)
		{
			for (int j = 0; j < student_number - 1 - i; j++)
			{
				if (strcmp(student[j].name, student[j + 1].name) > 0)
				{
					struct Student temp = student[j];
					student[j] = student[j + 1];
					student[j + 1] = temp;
				}
			}
		}

		printf("排序信息如下：\n");
		for (int i = 0; i < student_number; i++)
		{

			printf("学号：%d\t", student[i].id);
			printf("姓名：%s\t", student[i].name);
			printf("性别：%s\t", student[i].sex);
			printf("出生年月：%s\t", student[i].birthday);
			printf("地址：%s\t", student[i].address);
			printf("电话：%s\t", student[i].phone);
			printf("E-mail：%s\n", student[i].email);


		}
	}
	break;
	case 2:
	{
		for (int i = 0; i < student_number; i++)
		{
			for (int j = 0; j < student_number - 1 - i; j++)
			{
				if (student[j].id> student[j + 1].id)
				{
					struct Student temp = student[j];
					student[j] = student[j + 1];
					student[j + 1] = temp;
				}
			}
		}

		printf("排序信息如下：\n");
		for (int i = 0; i < student_number; i++)
		{

			printf("学号：%d\t", student[i].id);
			printf("姓名：%s\t", student[i].name);
			printf("性别：%s\t", student[i].sex);
			printf("出生年月：%s\t", student[i].birthday);
			printf("地址：%s\t", student[i].address);
			printf("电话：%s\t", student[i].phone);
			printf("E-mail：%s\n", student[i].email);

		}
	}
	break;

	default:
		printf("输入有误,将返回主菜单！\n");
	}

}


//管理员登录
int login_admin()
{
	char username[20];//用户名 
	char password[20];//密码

	printf("请输入登录的管理员用户名：\n");
	scanf("%s", username);
	printf("请输入登录的管理员密码：\n");
	scanf("%s", password);
	for (int i = 0; i < user_number; i++)
	{
		if (!strcmp(username, user[i].username)
			&& !strcmp(password, user[i].password)
			&& user[i].role == 1)
		{
			printf("登录成功！\n");
			return i;
		}
	}

	printf("用户名或者密码错误，登录失败！\n");
	return -1;
}
//学生登录
int login_student()
{
	char username[20];//用户名 
	char password[20];//密码

	printf("请输入登录的学生用户名：\n");
	scanf("%s", username);
	printf("请输入登录的学生密码：\n");
	scanf("%s", password);
	for (int i = 0; i < user_number; i++)
	{
		if (!strcmp(username, user[i].username)
			&& !strcmp(password, user[i].password)
			&& user[i].role == 2)
		{
			printf("登录成功！\n");
			return i;
		}
	}

	printf("用户名或者密码错误，登录失败！\n");
	return -1;
}
//注册
void regist_user()
{
	printf("请输入注册的用户名：\n");
	scanf("%s", user[user_number].username);
	for (int i = 0; i < user_number; i++)
	{
		if (!strcmp(user[user_number].username, user[i].username))
		{
			printf("存在该信息，注册失败！\n");
			return;
		}

	}
	printf("请输入注册的密码：\n");
	scanf("%s", user[user_number].password);
	printf("请输入注册的角色(1.管理员 2.学生)：\n");
	scanf("%d", &user[user_number].role);
	if (user[user_number].role < 1 || user[user_number].role>2)
	{
		printf("输入有误，注册失败！\n");
		return;
	}
	user_number++;
	printf("注册成功！\n");

}



//主函数
int main()
{
	initialize_default_admin();

	load_user();
	int chioce;
	while (1)
	{
		one:
		menu();
		printf("请输入你的选择（0-3）:\n");
		scanf("%d", &chioce);
		if (chioce < 0 || chioce>3)
		{
			printf("输入有误，请重新输入！\n");
		}
		else
		{
			switch (chioce)
			{
			case 1:
			{
				int index = login_admin();
				if (index != -1)
				{
					while (1)
					{
						menu1();
						printf("请输入你的选择（0-7）:\n");
						scanf("%d", &chioce);
						if (chioce < 0 || chioce>7)
						{
							printf("输入有误，请重新输入！\n");
						}
						else
						{
							switch (chioce)
							{
							case 1:
								printf("1.手动录入 \n");
								printf("2.文件导入\n");
								printf("请输入你的选择：");
								scanf("%d", &chioce);
								if (chioce == 1)
								{
									add_student();
								}
								else if (chioce == 2)
								{
									load_student();
								}
								else
								{
									printf("输入有误，录入失败！\n");
								}

								break;
							case 2:
								delete_student();
								break;
							case 3:
								update_student();
								break;
							case 4:
								query_student();
								break;
							case 5:
								show_student();
								break;
							case 6:
								sort_student();
								break;
							case 7:
								save_student();
								break;

							case 0:
								goto one;
							}
						}

					}
				}
			}
				break;
			case 2:
			{
				int index = login_student();
				if (index != -1)
				{
					while (1)
					{

						menu2();
						printf("请输入你的选择（0-2）:\n");
						scanf("%d", &chioce);
						if (chioce < 0 || chioce>2)
						{
							printf("输入有误，请重新输入！\n");
						}
						else
						{
							switch (chioce)
							{
							case 1:
								query_student();
					
								break;
							case 2:
								show_student();
								break;
							case 0:
								goto one;
							}
						}
					}

				}
			}
				break;
			case 3:
				regist_user();
				break;
			
			case 0:
				save_student();
				save_user();
				printf("欢迎下次使用！\n");
				return 0;
			}
		}

	}

	return 0;
}
