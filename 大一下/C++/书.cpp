#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
using namespace std;



class Book {
public:
	friend class node;
	Book(string n="无", string w="无", string l="无", string k="无") {
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
	cout << "请输入该书的基本信息：1，书名；2，作者；3，语言；4，种类" << endl;
	cin >> n >> w >> l >> k;
	name = n;
	writer = w;
	launary = l;
	kind = k;
}
void Book::getInformation() {
	cout << "这本书的名字是：" << name << "  " << "这本书的作者是：" << writer << "  " << "这本书所用的语言是：" << launary << "  " << "这本书的体裁是：" << kind << endl;
}
int Book:: modifyInformation() {
	string n, w, l, k;
	n = name;
	w = writer;
	l = launary;
	k = kind;
	int choose;
	cout << "1，修改书名；" << endl;
	cout << "2，修改作者；" << endl;
	cout << "3，修改语言；" << endl;
	cout << "4，修改种类；" << endl;
	cout << "5，退出页面；" << endl;
	while (1) {
		cout << "请输入你的选择（1，2，3，4，5）" << endl;
		cin >> choose;
		switch (choose) {
		case 1:
			cout << "请输入新书名：";
			cin >> n;
			name = n;
			break;
		case 2:
			cout << "请输入新作者：";
			cin >> w;
			writer = w;
			break;
		case 3:
			cout << "请输入新语言：";
			cin >> l;
			launary = l;
			break;
		case 4:
			cout << "请输入新种类：";
			cin >> k;
			kind = k;
			break;
		case 5:
			return 0;
			break;
		default:
			cout << "输入错误";
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
	int length;//链表长度
	void trave();//遍历
	void add();//从尾部添加节点
	int add(int n);//添加结点到第n个位置
	int delet(int n);//删除第n位的结点
	int change(int n);//修改学生信息
	void set();
	node* head;
private:
	node* tail;
};
list::list()//构造函数
{
	head = new node;//链表头
	tail = new node;//第二个节点
	head->next = tail;//连接
	tail->next = NULL;//尾巴置空
	length = 2;//目前链表长度
}
void list::trave()//遍历
{
	node* mid = head;
	while (length) {
		mid->b.getInformation();
		mid = mid->next;
		length--;
	}
	
}
void list::add()//从尾部添加
{
	node* pre = head;//存储头指针
	while (pre->next != NULL)//将指针移向尾部
	{
		pre = pre->next;
	}
	char c = '\0';
	cout << "添加信息吗（y/n）" << endl;
	cin >> c;
	while (c == 'y')
	{
		pre->next = new node;    //新建一个节点
		pre = pre->next;
		pre->next = NULL;     //尾部置空
		length++;                 //添加一次，长度加一
		cout << "添加信息吗（y/n）" << endl;//循环判断
		cin >> c;
	}
	trave();
}
int list::add(int n)//添加新节点到第n位
{
	if (n <= 0 || n > length + 1)
	{
		cout << "不是有效长度" << endl;
	}
	else
	{
		node* pre = head;   //存储head
		node* pp = NULL;
		node* rp = NULL;
		if (n > 1 && n < length + 1)
		{
			while (--n)     //循环移动指针
			{
				pp = pre;
				pre = pre->next;
			}
			rp = pre;          //存储原位置的节点地址
			pre = new node;    //新建节点，并改变相应位置节点的指针
			pp->next = pre;    //next指向新节点
			pre->next = rp;    //新节点的next指向原位置节点的首地址
			length++;
			trave();
		}
		if (n == 1)           //添加在首位
		{
			head = new node;  //head变为新节点的首地址
			head->next = pre;
			length++;
			trave();
		}
		if (n == length + 1)     //添加在末尾
			add();     //调用add函数
	}
	return 0;
}
int list::delet(int n)  //删除第n位节点
{
	node* pre = head;
	node* pp = NULL;
	if (n <= 0 || n > length)
	{
		cout << "不是有效长度" << endl;
		return 1;
	}
	if (n == 1)     //删除首位
	{
		pre = pre->next;
		delete head;
		head = pre;
		length--;   //长度减一
		trave();
	}
	if (n == length)   //删除末尾结点
	{
		while (pre->next != nullptr)//循环移动指针至末尾
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
		while (--n)          //循环移动指针
		{
		    pre = head;
			pp = pre;
			pre = pre->next;
		}
		pp->next = pre->next;//改变指向
		delete pre;
		length--;
		trave();
	}
	return 0;
}
int list::change(int n)//改变信息
{
	if (n > length)
	{
		cout << "不是有效长度" << endl;
		return 1;
	}
	node* pre = head;
	while (--n)       //循环移动指针
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

