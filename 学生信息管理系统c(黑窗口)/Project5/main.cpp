#pragma warning(disable:4996);
//vs2015�в�֧��scanf;��Ӵ������ʹ��scanf
//��vc6.0��dev c++��ֱ��ע�͵���������
/*
	ѧ��֤�������
	2019-11-11
	gao
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct StudentMessage//ѧ����Ϣ���
{
	char name[20];
	char gnder[20];
	int  id;					//ѧ��
	char college[20];			//ѧԺ
	char major[20];				//רҵ
	char classname[20];			//�༶
	char birthday[20];			//��������
	int AdmissionTime;		    //��ѧʱ��
	char DrivingRange[20];		//�˳�����
	struct StudentMessage *next;	//����
}Stu;

Stu head;//����ͷ���

/*ͳ�ư༶��������Ů����*/
/*������Ҫ�Ż��������Ӵ������룬��ôͳ��ÿ���ࣨ�м����࣬��������ʲô����֪����*/
void Statistical()
{
	Stu *p;
	p = head.next;
	int sum=0, man=0, women=0;
	char ClassName[20];
	if (p == NULL) {
		printf("�������Ϣ������\n");
		return;
	}
	printf("������Ҫͳ�Ƶİ���:\n");
	scanf("%s",ClassName);
	while (p != NULL) {
		if (strcmp(p->classname, ClassName) == 0) {
			sum++;//�ܺ�++
			if (strcmp(p->gnder, "��") == 0) {
				man++;
			}
			else {
				women++;
			}
		}
		p = p->next;
	}
	printf("%s�๲ %d �� \t��:Ů\t%d:%d\n",ClassName,sum,man,women);
	return;
}

/*��Ϣ����*/
void InFile()
{
	FILE *fp;
	Stu *p,*tail;
	tail = &head;
	char filename[20] = "StudentMessage.txt";
	char kong[20];
	fp = fopen(filename,"r");
	if (fp == NULL) {
		printf("�ļ���ʧ�ܣ�����\n");
		return;
	}
	while(!feof(fp)){
		p = (Stu *)malloc(sizeof(Stu));
		fscanf(fp,"%s",p->name);
		if (strcmp(p->name, "") == 0) {
			printf("û����Ϣ������ӣ�����\n");
			return;
		}
		fscanf(fp,"%s",p->gnder);
		fscanf(fp,"%d",&p->id);
		fscanf(fp,"%s",p->college);
		fscanf(fp,"%s",p->major);
		fscanf(fp,"%s",p->classname);
		fscanf(fp,"%s",p->birthday);
		fscanf(fp,"%d",&p->AdmissionTime);
		fscanf(fp,"%s",p->DrivingRange);

	tail->next = p;
	p->next = NULL;
	tail = p;
}

	fclose(fp);
	printf("��Ϣ����ɹ�������\n");
	return;
}

/*��Ϣд��*/
void OutFile()
{
	FILE *fp;
	Stu *p;
	p = head.next;
	if (p == NULL) {
		printf("�����ѧ����Ϣ������\n");
		return;
	}
	char filename[20] = "StudentMessage.txt";//�����ļ���
	fp = fopen(filename,"a");//��a���ļ������ļ�ĩβ׷������
	if (fp == NULL) {
		printf("�ļ���ʧ�ܣ�����\n");
		return;
	}
	while (p!=NULL) {
		fprintf(fp,"%s\t%s\t%d\t%s\t%s\t%s\t%s\t%d\t%s", p->name, p->gnder, p->id, p->college, p->major, p->classname, p->birthday, p->AdmissionTime, p->DrivingRange);
		p = p->next;
		fprintf(fp,"\n");
	}
	fclose(fp);
	printf("����ɹ�!!!\n");
	return;
}
/*�鿴ȫУѧ����Ϣ*/
void AllStudentMessage() {
	Stu *p;
	p = head.next;
	if (p == NULL) {
		printf("û��ѧ����Ϣ����ӣ�����\n");
	}
	else {
		printf("����\t  �Ա�\t    ѧ��\tѧԺ\t  רҵ\t    �༶\t  ��������\t��ѧʱ��\t�˳�����\n");
	}
	while (p != NULL) {		
		printf("%-10s%-10s%-10d  %-10s%-10s%-10s\t%-10s\t%-10d\t%-10s\n", p->name, p->gnder, p->id, p->college, p->major, p->classname, p->birthday, p->AdmissionTime, p->DrivingRange);
		p = p->next;
	}
	return;
}

/*���ѧ����Ϣ*/
void AddStudentMessage()
{
	Stu *tail,*p,*q;
	tail = &head;
	while (tail->next != NULL) {//�ٴ����ʱ�����֮ǰ��ӹ���tail->next��Ϊ�գ���tail�Ƶ�β�������������
		tail = tail->next;
	}
	p = (Stu *)malloc(sizeof(Stu));
	if (p == NULL) {
		printf("ѧ����Ϣ��㴴��ʧ�ܣ�������");
		return;
	}
	q = head.next;
	fflush(stdin);//���������
	printf("������ѧ������:\n");
	scanf("%s",p->name);
	fflush(stdin);
	printf("�Ա�:\n");
	scanf("%s",p->gnder);
	fflush(stdin);
	printf("ѧ��:\n");
	scanf("%d",&(p->id));

	/*��֤ѧ�ŵ�Ψһ��*/
	while (q != NULL) {
		if (p->id == q->id) {
			printf("ѧ���Ѵ��ڣ����ʧ�ܣ�����\n");
			return;
		}
		q = q->next;
	}
	fflush(stdin);
	printf("ѧԺ:\n");
	scanf("%s",p->college);
	fflush(stdin);
	printf("רҵ:\n");
	scanf("%s",p->major);
	fflush(stdin);
	printf("�༶:\n");
	scanf("%s",p->classname);
	fflush(stdin);
	printf("��������:(xxxx-xx-xx��2019��1��1��:2019-01-01)\n");
	scanf("%s",p->birthday);
	/*�������µĺϷ��Լ��� ʱ���ʽ:xxxx-xx-xx*/
	while (p->birthday[4] != '-'||p->birthday[7]!='-') {
		printf("����������:\n");
		scanf("%s", p->birthday);
	}
	fflush(stdin);
	printf("��ѧʱ��:(2000-3000)\n");
	scanf("%d",&p->AdmissionTime);
	/*��ѧʱ��ĺϷ��Լ��� 2000<=��ѧʱ��<=3000*/
	while (2000>p->AdmissionTime||p->AdmissionTime>3000)
	{
		printf("����������:\n");
		scanf("%d", &p->AdmissionTime);
	}
	fflush(stdin);
	printf("�˳�����:\n");
	scanf("%s",p->DrivingRange);
	fflush(stdin);

	tail->next = p;
	p->next = NULL;
	tail = p;
	return;
}

/*����ѧ����Ϣ*/
void FindStudentMessage()
{
	Stu *p;
	p = head.next;
	int No=0;	
	printf("������Ҫ��ѯ��ѧ��ѧ��:\n");
	scanf("%d",&No);
	printf("����\t�Ա�\tѧ��\tѧԺ\tרҵ\t�༶\t��������\t��ѧʱ��\t�˳�����\n");
	while (p != NULL) {		
		if (p->id == No) {
			printf("%s\t%s\t%d\t%s\t%s\t%s\t%s\t%d\t%s\n",p->name,p->gnder,p->id,p->college,p->major,p->classname,p->birthday,p->AdmissionTime,p->DrivingRange);
		}
		p = p->next;
	}
	return;
}

/*��ѯ�༶��Ϣ*/
void FindClassMessage()
{
	Stu *p;
	p = head.next;
	char ClassNo[20]="0";
	printf("������Ҫ��ѯ�İ༶���:\n");
	scanf("%s", ClassNo);
	printf("%s ���ѧ����Ϣ����:\n", ClassNo);	
	printf("�༶\t����\t�Ա�\tѧ��\tѧԺ\tרҵ\t��������\t��ѧʱ��\t�˳�����\n");
	while (p != NULL) {
		//����if�ж���strcmp
		if (strcmp(p->classname,ClassNo)==0) {
			printf("%s\t%s\t%s\t%d\t%s\t%s\t%s\t%d\t%s\n", p->classname ,p->name, p->major, p->id, p->college, p->major, p->birthday, p->AdmissionTime, p->DrivingRange);
		}
		p = p->next;
	}
	return;
}

/*�޸�ѧ����Ϣ*/
void ModifyStudentMessage()//�޸�ѧ����Ϣ
{
	Stu *p;
	p = head.next;
	int no = 0,flag=0,NO=0;//flag�ж�ѧ���Ƿ����
	printf("������Ҫ�޸�ѧ����ѧ��:\n");
	scanf("%d",&no);
	while (p != NULL) {
		if (p->id == no) {
			flag = 1;
			break;
		}
		p = p->next;
	}
	if (flag == 0) {
		printf("%d��ѧ�������ڣ������޸ģ�����\n",no);
		return;
	}

	system("cls");
	printf("**********�޸� %d ѧ����Ϣ**********\n",no);
	printf("�޸ı��:\n");
	printf("\t0.�޸�����\n");
	printf("\t1.�޸��Ա�\n");
	printf("\t2.�޸�ѧ��\n");
	printf("\t3.�޸�ѧԺ\n");
	printf("\t4.�޸�רҵ\n");
	printf("\t5.�޸İ༶\n");
	printf("\t6.�޸ĳ�������\n");
	printf("\t7.�޸���ѧʱ��\n");
	printf("\t8.�޸ĳ˳�����\n");

	printf("��������Ҫ�޸ĵ���Ϣ���:\n");
	scanf("%d",&NO);
	switch (NO) {
	case 0:printf("�޸�ǰ %s\n�޸�Ϊ: ",p->name);
		   scanf("%s",p->name);
		break;
	case 1:printf("�޸�ǰ %s\n�޸�Ϊ: ",p->gnder);
		   scanf("%s",p->gnder);
		break;
	case 2:printf("�޸�ǰ %d\n�޸�Ϊ: ",p->id);
		scanf("%d",&p->id);
		break;
	case 3:printf("�޸�ǰ %s\n�޸�Ϊ: ", p->college);
		scanf("%s",p->college);
		break;
	case 4:printf("�޸�ǰ %s\n�޸�Ϊ: ", p->major);
		scanf("%s",p->major);
		break;
	case 5:printf("�޸�ǰ %s\n�޸�Ϊ: ", p->classname);
		scanf("%s",p->classname);
	    break;
	case 6:printf("�޸�ǰ %s\n�޸�Ϊ: ", p->birthday);
		scanf("%s",p->birthday);
		break;
	case 7:printf("�޸�ǰ %d\n�޸�Ϊ: ", p->AdmissionTime);
		scanf("%d",&p->AdmissionTime);
		break;
	case 8:printf("�޸�ǰ %s\n�޸�Ϊ: ", p->DrivingRange);
		scanf("%s",p->DrivingRange);
		break;
	}
	printf("�޸���ɣ�����\n");
	return;
}

/*ɾ��ѧ����Ϣ*/
void DeleteStudentMessage()
{
	Stu *p,*pre;
	p = head.next;
	pre = head.next;
	if (p == NULL) {
		printf("û��ѧ����Ϣ������ӣ�����\n");
		return;
	}
	int no = 0,flag=0;//flag��������¼Ҫɾ���Ľ��֮ǰ�Ľ��
	printf("������Ҫɾ��ѧ����ѧ�ţ�\n");
	scanf("%d",&no);
	while (p != NULL) {
		if (p->id == no) {
			break;
		}
		p = p->next;
		flag++;
	}
	if (flag == 0) {//ɾ��head����Ľ��Ĵ������
		head.next = p->next;
		free(p);
		return;
	}
	for (int i = 0; i < flag-1; i++) {
		pre = pre->next;
	}
	pre->next = p->next;
	free(p);
	if (p == NULL) {
		printf("%dͬѧɾ���ɹ�",no);
	}
	else {
		printf("%dͬѧû��ɾ��",no);
	}
	return;
}

/*�ͷ����������д��ѧ����Ϣ�Ľ��*/
void freeList()
{
	Stu *p;
	p = head.next;
	while (p != NULL) {
		head.next = p->next;
		free(p);	/*�ͷ�pָ��Ľ��ռ�*/
		p = head.next;/*ָ�����pָ����һ�����ͷŵĽ��*/
	}
}

/*��ҳ��˵�*/
void MainMenu()//���˵�"\t�Ʊ��"
{
	printf("***************ѧ��֤�������*****************\n");
	printf("\t0.�鿴ȫУѧ��\n");
	printf("\t1.���ѧ����Ϣ\n");
	printf("\t2.��ѯѧ����Ϣ\n");
	printf("\t3.��ѯ�༶��Ϣ\n");
	printf("\t4.�޸�ѧ����Ϣ\n");
	printf("\t5.ɾ��ѧ����Ϣ\n");
	printf("��չ:\n");
	printf("\t6.ͳ�ư༶��������Ů����\n");
	printf("\t7.��Ϣ���루�ļ����룩\n");
	printf("\t8.��Ϣ���棨�ļ�д�룩\n");
	printf("\t9.�˳�����\n");
	printf("**********************************************\n");
}

/*���������������*/
void main()
{
	int no = 0;//����ѡ��
	while (1) {
		system("cls");//����
		MainMenu();
		printf("�����빦��ѡ��:\n");
		scanf("%d",&no);
		switch (no) {
		case 0:AllStudentMessage();
			break;
		case 1:AddStudentMessage();
			break;
		case 2:FindStudentMessage();
			break;
		case 3:FindClassMessage();
			break;
		case 4:ModifyStudentMessage();
			break;
		case 5:DeleteStudentMessage();
			break;
		case 6:Statistical();
			break;
		case 7:InFile();
			break;
		case 8:OutFile();
			break;
		case 9:freeList(); return;
		default:printf("ѡ�����\n");
		}
		system("pause");
	}	
	return;
}