#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100 



//ѧ�š����������䡢�Ա𡢳������¡���ͥסַ���绰��E-mail
struct Student
{
	int id;//ѧ��
	char name[20];//���� 
	char sex[20];//�Ա�
	char birthday[20];//��������
	char address[20];//��ͥ��ַ
	char phone[20];//�绰
	char email[20];//E-mail


};
int student_number = 0;
struct Student student[MAX];

struct User
{

	char username[20];//�û��� 
	char password[20];//����
	int role;//��ɫ(1.����Ա 2.ѧ��)


};
int user_number = 0;
struct User user[MAX];


//�˵�
void menu()
{
	printf("=======================================\n");
	printf("=          ѧ����Ϣ����ϵͳ           =\n");
	printf("=            1.����Ա                 =\n");
	printf("=            2.ѧ��                   =\n");
	printf("=            3.ע��                   =\n");
	printf("=            0.�˳�                   =\n");
	printf("=======================================\n");
}
void menu1()
{
	printf("=======================================\n");
	printf("=             ����Ա����              =\n");
	printf("=           1.����ѧ����Ϣ            =\n");
	printf("=           2.ɾ��ѧ����Ϣ            =\n");
	printf("=           3.�޸�ѧ����Ϣ            =\n");
	printf("=           4.��ѯѧ����Ϣ            =\n");
	printf("=           5.���ѧ����Ϣ            =\n");
	printf("=           6.ѧ����Ϣ����            =\n");
	printf("=           7.����ѧ����Ϣ            =\n");
	printf("=           0.�˳�ϵͳ                =\n");
	printf("=======================================\n");
}
void menu2()
{
	printf("=======================================\n");
	printf("=             ѧ������                =\n");
	printf("=           1.��ѯѧ����Ϣ            =\n");
	printf("=           2.���ѧ����Ϣ            =\n");
	printf("=           0.�˳�ϵͳ                =\n");
	printf("=======================================\n");
}
//�����ļ�
void save_student()
{
	FILE* file;
	if ((file = fopen("student.txt", "w")) == NULL)
	{
		printf("�ļ���ʧ�ܣ�");
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
	printf("�����ļ��ɹ���\n");

}
void save_user()
{
	FILE* file;
	if ((file = fopen("user.txt", "w")) == NULL)
	{
		printf("�ļ���ʧ�ܣ�");
		return;
	}

	for (int i = 0; i < user_number; i++)
	{
		fprintf(file, "%s ", user[i].username);
		fprintf(file, "%s ", user[i].password);
		fprintf(file, "%d\n", user[i].role);
	}

	fclose(file);
	printf("�����ļ��ɹ���\n");

}
//�����ļ���Ϣ
void load_student()
{
	char filename[20];
	printf("�������ȡ���ļ�����(��student.txt):\n");
	scanf("%s", filename);
	FILE* fp;
	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		printf("���ļ�ʧ�ܣ�\n");
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
	printf("�����ļ���Ϣ�ɹ�!\n");

}
// ��ʼ��Ĭ�Ϲ���Ա��Ϣ
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
		printf("���ļ�ʧ�ܣ�\n");
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
	printf("�����ļ���Ϣ�ɹ�!\n");

}
//¼��ѧ����Ϣ
void add_student()
{

	printf("������ѧ��ѧ�ţ�\n");
	scanf("%d", &student[student_number].id);
	for (int i = 0; i < student_number; i++)
	{
		if (student[student_number].id == student[i].id)
		{
			printf("���ڸ�ѧ�ţ����ʧ�ܣ�\n");
			return;
		}
	}

	printf("������ѧ��������\n");
	scanf("%s", student[student_number].name);

	printf("������ѧ���Ա�\n");
	scanf("%s", student[student_number].sex);
	printf("������ѧ���������£�\n");
	scanf("%s", student[student_number].birthday);
	printf("������ѧ����ַ��\n");
	scanf("%s", student[student_number].address);
	printf("������ѧ���绰��\n");
	scanf("%s", student[student_number].phone);
	printf("������ѧ��E-mail��\n");
	scanf("%s", student[student_number].email);
	student_number++;
	printf("���ѧ����Ϣ�ɹ���\n");

}
//ɾ��ѧ����Ϣ
void delete_student()
{
	printf("��������Ҫɾ����ѧ�ţ�\n");
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
			printf("ɾ���ɹ�!\n");


			break;
		}
	}

	if (a == 1)
	{
		printf("û�и�ѧ����Ϣ��\n");
		return;
	}

}
//�޸�ѧ����Ϣ
void update_student()
{
	printf("��������Ҫ�޸ĵ�ѧ�ţ�\n");
	int id;
	int a = 1;
	scanf("%d", &id);
	for (int i = 0; i < student_number; i++)
	{
		if (id == student[i].id)
		{
			a++;
			printf("������ѧ��������\n");
			scanf("%s", student[i].name);

			printf("������ѧ���Ա�\n");
			scanf("%s", student[i].sex);
			printf("������ѧ�������£�\n");
			scanf("%s", student[i].birthday);
			printf("������ѧ����ַ��\n");
			scanf("%s", student[i].address);
			printf("������ѧ���绰��\n");
			scanf("%s", student[i].phone);
			printf("������ѧ��E-mail��\n");
			scanf("%s", student[i].email);


			printf("�޸ĳɹ�!\n");


			break;
		}
	}

	if (a == 1)
	{
		printf("û�и�ѧ����Ϣ��\n");
		return;
	}

}
//���ѧ����Ϣ
void show_student()
{

	if (student_number == 0)
	{
		printf("û����Ϣ��\n");
		return;
	}

	for (int i = 0; i < student_number; i++)
	{


		printf("ѧ�ţ�%d\t", student[i].id);
		printf("������%s\t", student[i].name);
		printf("�Ա�%s\t", student[i].sex);
		printf("�������£�%s\t", student[i].birthday);
		printf("��ַ��%s\t", student[i].address);
		printf("�绰��%s\t", student[i].phone);
		printf("E-mail��%s\n", student[i].email);

	}


}
//��ѯѧ����Ϣ
void query_student()
{
	printf("1.���������� \n");
	printf("2.��ѧ�Ų���\n");
	printf("���������ѡ��");
	int chioce;
	scanf("%d", &chioce);
	switch (chioce)
	{
	case 1:
	{
		char name[20];
		int temp = 0;
		printf("��������ҵ�������");
		scanf("%s", name);
		for (int i = 0; i < student_number; i++)
		{
			if (!strcmp(name, student[i].name))
			{
				temp++;
				printf("ѧ�ţ�%d\t", student[i].id);
				printf("������%s\t", student[i].name);
				printf("�Ա�%s\t", student[i].sex);
				printf("�������£�%s\t", student[i].birthday);
				printf("��ַ��%s\t", student[i].address);
				printf("�绰��%s\t", student[i].phone);
				printf("E-mail��%s\n", student[i].email);

			}
		}
		if (temp == 0)
		{
			printf("û�и�ѧ����Ϣ������ʧ�ܣ�\n");
		}
	}
	break;
	case 2:
	{
		int id;
		int temp = 0;
		printf("��������ҵ�ѧ�ţ�");
		scanf("%d", &id);
		for (int i = 0; i < student_number; i++)
		{
			if (id == student[i].id)
			{
				temp++;
				printf("ѧ�ţ�%d\t", student[i].id);
				printf("������%s\t", student[i].name);
				printf("�Ա�%s\t", student[i].sex);
				printf("�������£�%s\t", student[i].birthday);
				printf("��ַ��%s\t", student[i].address);
				printf("�绰��%s\t", student[i].phone);
				printf("E-mail��%s\n", student[i].email);

			}
		}
		if (temp == 0)
		{
			printf("û�и�ѧ����Ϣ������ʧ�ܣ�\n");
		}
	}
	break;

	default:
		printf("��������,���������˵���\n");
	}

}
//ѧ����Ϣ����
void sort_student()
{
	if (student_number == 0)
	{
		printf("û����Ϣ��\n");
		return;

	}
	printf("1.���������� \n");
	printf("2.��ѧ������\n");
	printf("���������ѡ��");
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

		printf("������Ϣ���£�\n");
		for (int i = 0; i < student_number; i++)
		{

			printf("ѧ�ţ�%d\t", student[i].id);
			printf("������%s\t", student[i].name);
			printf("�Ա�%s\t", student[i].sex);
			printf("�������£�%s\t", student[i].birthday);
			printf("��ַ��%s\t", student[i].address);
			printf("�绰��%s\t", student[i].phone);
			printf("E-mail��%s\n", student[i].email);


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

		printf("������Ϣ���£�\n");
		for (int i = 0; i < student_number; i++)
		{

			printf("ѧ�ţ�%d\t", student[i].id);
			printf("������%s\t", student[i].name);
			printf("�Ա�%s\t", student[i].sex);
			printf("�������£�%s\t", student[i].birthday);
			printf("��ַ��%s\t", student[i].address);
			printf("�绰��%s\t", student[i].phone);
			printf("E-mail��%s\n", student[i].email);

		}
	}
	break;

	default:
		printf("��������,���������˵���\n");
	}

}


//����Ա��¼
int login_admin()
{
	char username[20];//�û��� 
	char password[20];//����

	printf("�������¼�Ĺ���Ա�û�����\n");
	scanf("%s", username);
	printf("�������¼�Ĺ���Ա���룺\n");
	scanf("%s", password);
	for (int i = 0; i < user_number; i++)
	{
		if (!strcmp(username, user[i].username)
			&& !strcmp(password, user[i].password)
			&& user[i].role == 1)
		{
			printf("��¼�ɹ���\n");
			return i;
		}
	}

	printf("�û�������������󣬵�¼ʧ�ܣ�\n");
	return -1;
}
//ѧ����¼
int login_student()
{
	char username[20];//�û��� 
	char password[20];//����

	printf("�������¼��ѧ���û�����\n");
	scanf("%s", username);
	printf("�������¼��ѧ�����룺\n");
	scanf("%s", password);
	for (int i = 0; i < user_number; i++)
	{
		if (!strcmp(username, user[i].username)
			&& !strcmp(password, user[i].password)
			&& user[i].role == 2)
		{
			printf("��¼�ɹ���\n");
			return i;
		}
	}

	printf("�û�������������󣬵�¼ʧ�ܣ�\n");
	return -1;
}
//ע��
void regist_user()
{
	printf("������ע����û�����\n");
	scanf("%s", user[user_number].username);
	for (int i = 0; i < user_number; i++)
	{
		if (!strcmp(user[user_number].username, user[i].username))
		{
			printf("���ڸ���Ϣ��ע��ʧ�ܣ�\n");
			return;
		}

	}
	printf("������ע������룺\n");
	scanf("%s", user[user_number].password);
	printf("������ע��Ľ�ɫ(1.����Ա 2.ѧ��)��\n");
	scanf("%d", &user[user_number].role);
	if (user[user_number].role < 1 || user[user_number].role>2)
	{
		printf("��������ע��ʧ�ܣ�\n");
		return;
	}
	user_number++;
	printf("ע��ɹ���\n");

}



//������
int main()
{
	initialize_default_admin();

	load_user();
	int chioce;
	while (1)
	{
		one:
		menu();
		printf("���������ѡ��0-3��:\n");
		scanf("%d", &chioce);
		if (chioce < 0 || chioce>3)
		{
			printf("�����������������룡\n");
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
						printf("���������ѡ��0-7��:\n");
						scanf("%d", &chioce);
						if (chioce < 0 || chioce>7)
						{
							printf("�����������������룡\n");
						}
						else
						{
							switch (chioce)
							{
							case 1:
								printf("1.�ֶ�¼�� \n");
								printf("2.�ļ�����\n");
								printf("���������ѡ��");
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
									printf("��������¼��ʧ�ܣ�\n");
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
						printf("���������ѡ��0-2��:\n");
						scanf("%d", &chioce);
						if (chioce < 0 || chioce>2)
						{
							printf("�����������������룡\n");
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
				printf("��ӭ�´�ʹ�ã�\n");
				return 0;
			}
		}

	}

	return 0;
}
