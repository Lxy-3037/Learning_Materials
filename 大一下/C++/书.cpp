#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
using namespace std;



class Book {
public:
	friend class node;
	Book(string n="��", string w="��", string l="��", string k="��") {
		name = n;
		writer = w;
		launary = l;
		kind = k;
	}
	void setInformation();
	void getInformation();
	int modifyInformation();
private:
	string name;
	string writer;
	string launary;
	string kind;
};
void Book::setInformation() {
	string n;
	string w;
	string l;
	string k;
	cout << "���������Ļ�����Ϣ��1��������2�����ߣ�3�����ԣ�4������" << endl;
	cin >> n >> w >> l >> k;
	name = n;
	writer = w;
	launary = l;
	kind = k;
}
void Book::getInformation() {
	cout << "�Ȿ��������ǣ�" << name << "  " << "�Ȿ��������ǣ�" << writer << "  " << "�Ȿ�����õ������ǣ�" << launary << "  " << "�Ȿ�������ǣ�" << kind << endl;
}
int Book:: modifyInformation() {
	string n, w, l, k;
	n = name;
	w = writer;
	l = launary;
	k = kind;
	int choose;
	cout << "1���޸�������" << endl;
	cout << "2���޸����ߣ�" << endl;
	cout << "3���޸����ԣ�" << endl;
	cout << "4���޸����ࣻ" << endl;
	cout << "5���˳�ҳ�棻" << endl;
	while (1) {
		cout << "���������ѡ��1��2��3��4��5��" << endl;
		cin >> choose;
		switch (choose) {
		case 1:
			cout << "��������������";
			cin >> n;
			name = n;
			break;
		case 2:
			cout << "�����������ߣ�";
			cin >> w;
			writer = w;
			break;
		case 3:
			cout << "�����������ԣ�";
			cin >> l;
			launary = l;
			break;
		case 4:
			cout << "�����������ࣺ";
			cin >> k;
			kind = k;
			break;
		case 5:
			return 0;
			break;
		default:
			cout << "�������";
			break;
		}
	}
}
class node
{
public:
	node() {
		next = NULL;
	}
	Book b;
	node* next;
};
class list
{
public:
	list();
	~list();
	int length;//������
	void trave();//����
	void add();//��β����ӽڵ�
	int add(int n);//��ӽ�㵽��n��λ��
	int delet(int n);//ɾ����nλ�Ľ��
	int change(int n);//�޸�ѧ����Ϣ
	void set();
	node* head;
private:
	node* tail;
};
list::list()//���캯��
{
	head = new node;//����ͷ
	tail = new node;//�ڶ����ڵ�
	head->next = tail;//����
	tail->next = NULL;//β���ÿ�
	length = 2;//Ŀǰ������
}
void list::trave()//����
{
	node* mid = head;
	while (length) {
		mid->b.getInformation();
		mid = mid->next;
		length--;
	}
	
}
void list::add()//��β�����
{
	node* pre = head;//�洢ͷָ��
	while (pre->next != NULL)//��ָ������β��
	{
		pre = pre->next;
	}
	char c = '\0';
	cout << "�����Ϣ��y/n��" << endl;
	cin >> c;
	while (c == 'y')
	{
		pre->next = new node;    //�½�һ���ڵ�
		pre = pre->next;
		pre->next = NULL;     //β���ÿ�
		length++;                 //���һ�Σ����ȼ�һ
		cout << "�����Ϣ��y/n��" << endl;//ѭ���ж�
		cin >> c;
	}
	trave();
}
int list::add(int n)//����½ڵ㵽��nλ
{
	if (n <= 0 || n > length + 1)
	{
		cout << "������Ч����" << endl;
	}
	else
	{
		node* pre = head;   //�洢head
		node* pp = NULL;
		node* rp = NULL;
		if (n > 1 && n < length + 1)
		{
			while (--n)     //ѭ���ƶ�ָ��
			{
				pp = pre;
				pre = pre->next;
			}
			rp = pre;          //�洢ԭλ�õĽڵ��ַ
			pre = new node;    //�½��ڵ㣬���ı���Ӧλ�ýڵ��ָ��
			pp->next = pre;    //nextָ���½ڵ�
			pre->next = rp;    //�½ڵ��nextָ��ԭλ�ýڵ���׵�ַ
			length++;
			trave();
		}
		if (n == 1)           //�������λ
		{
			head = new node;  //head��Ϊ�½ڵ���׵�ַ
			head->next = pre;
			length++;
			trave();
		}
		if (n == length + 1)     //�����ĩβ
			add();     //����add����
	}
	return 0;
}
int list::delet(int n)  //ɾ����nλ�ڵ�
{
	node* pre = head;
	node* pp = NULL;
	if (n <= 0 || n > length)
	{
		cout << "������Ч����" << endl;
		return 1;
	}
	if (n == 1)     //ɾ����λ
	{
		pre = pre->next;
		delete head;
		head = pre;
		length--;   //���ȼ�һ
		trave();
	}
	if (n == length)   //ɾ��ĩβ���
	{
		while (pre->next != nullptr)//ѭ���ƶ�ָ����ĩβ
		{
			pp = pre;
			pre = pre->next;
		}
		delete pre;
		length--;
		trave();
	}
	if (n > 1 && n < length)
	{
		while (--n)          //ѭ���ƶ�ָ��
		{
		    pre = head;
			pp = pre;
			pre = pre->next;
		}
		pp->next = pre->next;//�ı�ָ��
		delete pre;
		length--;
		trave();
	}
	return 0;
}
int list::change(int n)//�ı���Ϣ
{
	if (n > length)
	{
		cout << "������Ч����" << endl;
		return 1;
	}
	node* pre = head;
	while (--n)       //ѭ���ƶ�ָ��
		pre = pre->next;
	pre->b.modifyInformation();
	trave();
	return 0;
}
void list::set() {
	node* mid = head;
	for (length; length > 0; length--) {
		mid->b.setInformation();
		mid = mid->next;
	}
}

