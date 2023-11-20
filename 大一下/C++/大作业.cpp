#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
#include <cassert>
#include<algorithm>
using namespace std;
//记得写
class Book {
public:
	friend class Node;
	friend class userPerson;
	//完成一本书的初始化，包括名字，作者，语言，体裁
	Book(string name = "无", string writer = "无", string language = "无", string kind = "无", int bookNumber = 1) :Name(name), Writer(writer), Language(language), Kind(kind), bookNumber(bookNumber) {
		cout << "恭喜你完成了一本书的存档";
		bookNumber = 0;
	}
	//完成一本书的初始化
	Book(Book& b) {
		cout << "恭喜你完成了一本书的存档";
		bookNumber = 0;
	}
	void setInformation(string name, string writer, string launary, string kind,int bookNumber);//设置一本书的基础信息
	void getInformation();//获得一本书的基础信息
	string getName();//获得一本书的书名
	string getWriter();//获得一本书的种类
	string getLanguage();//获得一本书的语言
	string getKind();//获得一本书的种类
	int modifyInformation();//修改一本书的基础信息
	void modifyName(string name);//修改一本书的名字
	void modifyWriter(string writer);//修改一本书的作者
	void modifyLaunary(string launary);//修改一本书的语言种类
	void modifyKind(string kind);//修改一本书的体裁
	void modifybookNumber(int booknumber);//修改一本书的本数
private:
	int bookNumber;//确定一本书的本数
	string Name;//名字
	string Writer;//作者
	string Language;//语言
	string Kind;//体裁
};
string Book::getName() {
	return Name;
}
string Book::getWriter() {
	return Writer;
}
string Book::getLanguage() {
	return Language;
}
string Book::getKind() {
	return Kind;
}
void Book::setInformation(string name, string writer, string launary, string kind,int booknumber) {
	Name = name;
	Writer = writer;
	Language = launary;
	Kind = kind;
	bookNumber = booknumber;
}
void Book::getInformation() {
	cout << "这本书的名字是：" << Name << endl;
	cout << "这本书的作者是：" << Writer << endl;
	cout << "这本书所用的语言是：" << Language << endl;
	cout << "这本书的体裁是：" << Kind << endl;
	cout << "这本书现存数量为：" << bookNumber << endl;
}
void Book::modifyName(string name) {
	Name = name;
}
void Book::modifyWriter(string writer) {
	Writer = writer;
}
void Book::modifyLaunary(string launary) {
	Language = launary;
}
void Book::modifyKind(string kind) {
	Kind = kind;
}
void Book::modifybookNumber(int booknumber){
	bookNumber = booknumber;
}
int Book::modifyInformation() {
	string name, writer, launary, kind;
	int choose;
	cout << "1，修改书名；" << endl;
	cout << "2，修改作者；" << endl;
	cout << "3，修改语言；" << endl;
	cout << "4，修改种类；" << endl;
	cout << "5, 修改数量；" << endl;
	cout << "6，退出页面；" << endl;
	while (1) {
		cout << "请输入你的选择（1，2，3，4，5，6）" << endl;
		cin >> choose;
		switch (choose) {
		case 1:
			cout << "请输入正确的书名";
			cin >> name;
			modifyName(name);
			break;
		case 2:
			cout << "请输入正确的作者名：";
			cin >> writer;
			modifyWriter(writer);
			break;
		case 3:
			cout << "请输入正确的该书所用语：";
			cin >> launary;
			modifyLaunary(launary);
			break;
		case 4:
			cout << "请输入正确的书籍体裁：";
			cin >> kind;
			modifyKind(kind);
			break;
		case 5:
			cout << "请输入正确的书籍数量";
			break;
		case 6:
			return 0;
			break;
		default:
			cout << "输入错误";
			break;
		}
	}
}

//定义链表的点
class Node
{
public:
	Node() {
		next = NULL;
	}
	Book b;
	Node* next;
};
//定义链表
class List
{
public:
	friend class userPerson;
	List();
	~List();
	int length;//链表长度
	void traveList();//遍历
	void addNode();//从尾部添加节点
	int deletNode(int n);//删除第n位的结点
	int changeNode(int n);//改变节点信息
	void setNode();//设置节点信息
	void findBook1(string bookname);//通过书名查找书
	void findBook2(string bookwriter);//通过书的作者查找书
	void findBook3(string language);//通过书的语言查找书
	void findBook4(string bookkind);//通过书的种类查找书
	Node* head;//头指针
private:
	Node* tail;
};
void List::findBook1(string bookname) {
	Node* mid = head;
	int length2 = length;
	while (length) {
		if (bookname == mid->b.getName())
			mid->b.getInformation();
		mid = mid->next;
		length--;
	}
	length = length2;
}
void List::findBook2(string bookwriter) {
	Node* mid = head;
	int length2 = length;
	while (length) {
		if (bookwriter == mid->b.getWriter())
			mid->b.getInformation();
		mid = mid->next;
		length--;
	}
	length = length2;
}
void List::findBook3(string language) {
	Node* mid = head;
	int length2 = length;
	while (length) {
		if (language == mid->b.getLanguage())
			mid->b.getInformation();
		mid = mid->next;
		length--;
	}
	length = length2;
}
void List::findBook4(string bookkind) {
	Node* mid = head;
	int length2 = length;
	while (length) {
		if (bookkind == mid->b.getKind())
			mid->b.getInformation();
		mid = mid->next;
		length--;
	}
	length = length2;
}
List::List()//构造函数
{
	head = new Node;//链表头
	tail = new Node;//第二个节点
	head->next = tail;//连接
	tail->next = NULL;//尾巴置空
	length = 2;//目前链表长度
}
void List::traveList()//遍历
{
	Node* mid = head;
	int length2 = length;
	while (length) {
		mid->b.getInformation();
		mid = mid->next;
		length--;
	}
	length = length2;
}
void List::addNode()//从尾部添加
{
	Node* pre = head;//存储头指针
	while (pre->next != NULL)//将指针移向尾部
	{
		pre = pre->next;
	}
	char c = '\0';
	cout << "添加信息吗（y/n）" << endl;
	cin >> c;
	while (c == 'y')
	{
		pre->next = new Node;    //新建一个节点
		pre = pre->next;
		pre->next = NULL;     //尾部置空
		length++;                 //添加一次，长度加一
		cout << "添加信息吗（y/n）" << endl;//循环判断
		cin >> c;
	}
	traveList();
}
int List::deletNode(int n)  //删除第n位节点
{
	Node* pre = head;
	Node* pp = NULL;
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
		traveList();
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
		traveList();
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
		traveList();
	}
	return 0;
}
int List::changeNode(int n)//改变信息
{
	if (n > length)
	{
		cout << "不是有效长度" << endl;
		return 1;
	}
	Node* pre = head;
	while (--n)       //循环移动指针
		pre = pre->next;
	pre->b.modifyInformation();
	return 0;
}
void List::setNode() {
	Node* mid = head;
	string name, launary, kind, writer;
	int booknumber;
	for (length; length > 0; length--) {
		cin >> name >> writer >> launary >> kind >> booknumber;
		mid->b.setInformation(name,writer,launary,kind,booknumber);
		mid = mid->next;
	}
}




//定义用户类
class userPerson {
protected:
	string userName;//定义用户名
	string trueName;//定义真实姓名
	long Cipher;//定义密码
	long cpNumber;//定义手机号
	int borrowedBooks;//已借书籍数量
	vector<Book> personalBook;//定义每个人所借的书籍
public:
	friend class Administrators;
    //对个人进行初始化
	userPerson(string Admini = "无", string trueName = "无", long Cipher = 0, long cpNumber = 0) :userName(Admini), trueName(trueName), Cipher(Cipher), cpNumber(cpNumber) {
		borrowedBooks = 0;
		cout << "已经成功建立一位新用户";
	}
	userPerson(userPerson& p) {
		cout << "已经成功建立一位新用户";
	}
	void modifyCipher(long cipher);//修改密码
	void modifycpNumber(long cpnumber);//修改手机号码
	void modifyuserName(string username);//修改用户名
	void modifytrueName(string truename);//修改用户真实姓名
	void getuesrName();//获得用户名
	void gettrueName();//得到用户真实姓名
	void getCipher();//得到用户的密码
	void getcpNumber();//得到用户的手机号码
	void borrowBooks(Book& b2);//借书
	void borrowBooks(Book& b2,int n);//同一本书借多本
	void returnBooks(Book& b2);//还书
	void returnBooks(Book& b2,int n);//同一本书还多本
	int getNumber(string name);//得到某本书在个人数组中的位置
};
int userPerson::getNumber(string name) {
	for (int i = personalBook.size(); i > 0; i--) {
		if (name == personalBook[i - 1].Name)
			return i;
	}
}
void userPerson::borrowBooks(Book& b2) {
	if (borrowedBooks >= 5 || borrowedBooks + 1 > 5)
		cout << "抱歉，您已超过限额";
	else if (b2.bookNumber > 0) {
		b2.bookNumber--;
		cout << "恭喜你，你已成功借出本书！";
		borrowedBooks++;
		personalBook.push_back(b2);
	}
	else cout << "抱歉，书籍数量不足，请重新借书";
}
void userPerson::borrowBooks(Book& b2,int n) {
	if (borrowedBooks >= 5 || borrowedBooks + n > 5)
		cout << "抱歉，您已超过限额";
	else if ((b2.bookNumber - n) > 0) {
		b2.bookNumber -= n;
		borrowedBooks += n;
		for (int i = 1; i <= n; i++) {
			personalBook.push_back(b2);
		}
		cout << "恭喜你，你已成功借出这" << n << "本书";
	}
	else cout << "抱歉，书籍数量不足，请重新借书";
}
void userPerson::returnBooks(Book& b2) {
	b2.bookNumber++;
	borrowedBooks--;
	int i = getNumber(b2.Name);
	personalBook.erase(personalBook.begin() + (i-1));
}
void userPerson::returnBooks(Book& b2,int n) {
	b2.bookNumber += n;
	borrowedBooks -= n;
	for (n; n > 0; n--) {
		int i = getNumber(b2.Name);
		personalBook.erase(personalBook.begin() + (i - 1));
	}
}
void userPerson::modifyCipher(long cipher) {
	Cipher = cipher;
}
void userPerson::modifycpNumber(long cpnumber) {
	cpNumber = cpnumber;
}
void userPerson::modifyuserName(string username) {
	userName = username;
}
void userPerson::modifytrueName(string truename) {
	trueName = truename;
}
void userPerson::getCipher() {
	cout << "密码是：" << Cipher;
}
void userPerson::getcpNumber() {
	cout << "手机号码是：" << cpNumber;
}
void userPerson::getuesrName() {
	cout << "用户名是：" << userName;
}
void userPerson::gettrueName() {
	cout << "真实姓名是：" << trueName;
}


class Administrators:public userPerson{
public:
	void addUser(userPerson& b3);//增加用户
	int getuserNumber(string personname);//得到某用户在数组中的位置
	void deleteUser(userPerson& b4);//删除某一个用户
	void LookupOne(userPerson& per);//观看一个用户的借书情况
	void LookupAll();//观看整个用户及借书情况
private:
	vector<userPerson>users;//用户数组
};
void Administrators::LookupOne(userPerson& per) {
	for (int i = 0; i < per.borrowedBooks; i++) {
		cout << "第" << i+1 << "本书：";
		per.personalBook[i].getInformation();
	}
}
void Administrators::addUser(userPerson& b3) {
	users.push_back(b3);
}
int Administrators::getuserNumber(string personname) {
	for (int i = users.size(); i > 0; i--) {
		if (personname == users[i - 1].trueName) {
			return i;
		}
	}
}
void Administrators::deleteUser(userPerson& b4) {
	int i = getuserNumber(b4.trueName);
	users.erase(users.begin() + (i - 1));
}
void Administrators::LookupAll() {
	for (int i = users.size(); i > 0; i--) {
		cout << "姓名：" << users[i - 1].trueName;
		for (int j = 0; j < users[i - 1].borrowedBooks; j++)
			users[i - 1].personalBook[j].getInformation();
	}
}


