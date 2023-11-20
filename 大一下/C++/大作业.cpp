#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
#include <cassert>
#include<algorithm>
using namespace std;
//�ǵ�д
class Book {
public:
	friend class Node;
	friend class userPerson;
	//���һ����ĳ�ʼ�����������֣����ߣ����ԣ����
	Book(string name = "��", string writer = "��", string language = "��", string kind = "��", int bookNumber = 1) :Name(name), Writer(writer), Language(language), Kind(kind), bookNumber(bookNumber) {
		cout << "��ϲ�������һ����Ĵ浵";
		bookNumber = 0;
	}
	//���һ����ĳ�ʼ��
	Book(Book& b) {
		cout << "��ϲ�������һ����Ĵ浵";
		bookNumber = 0;
	}
	void setInformation(string name, string writer, string launary, string kind,int bookNumber);//����һ����Ļ�����Ϣ
	void getInformation();//���һ����Ļ�����Ϣ
	string getName();//���һ���������
	string getWriter();//���һ���������
	string getLanguage();//���һ���������
	string getKind();//���һ���������
	int modifyInformation();//�޸�һ����Ļ�����Ϣ
	void modifyName(string name);//�޸�һ���������
	void modifyWriter(string writer);//�޸�һ���������
	void modifyLaunary(string launary);//�޸�һ�������������
	void modifyKind(string kind);//�޸�һ��������
	void modifybookNumber(int booknumber);//�޸�һ����ı���
private:
	int bookNumber;//ȷ��һ����ı���
	string Name;//����
	string Writer;//����
	string Language;//����
	string Kind;//���
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
	cout << "�Ȿ��������ǣ�" << Name << endl;
	cout << "�Ȿ��������ǣ�" << Writer << endl;
	cout << "�Ȿ�����õ������ǣ�" << Language << endl;
	cout << "�Ȿ�������ǣ�" << Kind << endl;
	cout << "�Ȿ���ִ�����Ϊ��" << bookNumber << endl;
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
	cout << "1���޸�������" << endl;
	cout << "2���޸����ߣ�" << endl;
	cout << "3���޸����ԣ�" << endl;
	cout << "4���޸����ࣻ" << endl;
	cout << "5, �޸�������" << endl;
	cout << "6���˳�ҳ�棻" << endl;
	while (1) {
		cout << "���������ѡ��1��2��3��4��5��6��" << endl;
		cin >> choose;
		switch (choose) {
		case 1:
			cout << "��������ȷ������";
			cin >> name;
			modifyName(name);
			break;
		case 2:
			cout << "��������ȷ����������";
			cin >> writer;
			modifyWriter(writer);
			break;
		case 3:
			cout << "��������ȷ�ĸ��������";
			cin >> launary;
			modifyLaunary(launary);
			break;
		case 4:
			cout << "��������ȷ���鼮��ã�";
			cin >> kind;
			modifyKind(kind);
			break;
		case 5:
			cout << "��������ȷ���鼮����";
			break;
		case 6:
			return 0;
			break;
		default:
			cout << "�������";
			break;
		}
	}
}

//��������ĵ�
class Node
{
public:
	Node() {
		next = NULL;
	}
	Book b;
	Node* next;
};
//��������
class List
{
public:
	friend class userPerson;
	List();
	~List();
	int length;//������
	void traveList();//����
	void addNode();//��β����ӽڵ�
	int deletNode(int n);//ɾ����nλ�Ľ��
	int changeNode(int n);//�ı�ڵ���Ϣ
	void setNode();//���ýڵ���Ϣ
	void findBook1(string bookname);//ͨ������������
	void findBook2(string bookwriter);//ͨ��������߲�����
	void findBook3(string language);//ͨ��������Բ�����
	void findBook4(string bookkind);//ͨ��������������
	Node* head;//ͷָ��
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
List::List()//���캯��
{
	head = new Node;//����ͷ
	tail = new Node;//�ڶ����ڵ�
	head->next = tail;//����
	tail->next = NULL;//β���ÿ�
	length = 2;//Ŀǰ������
}
void List::traveList()//����
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
void List::addNode()//��β�����
{
	Node* pre = head;//�洢ͷָ��
	while (pre->next != NULL)//��ָ������β��
	{
		pre = pre->next;
	}
	char c = '\0';
	cout << "�����Ϣ��y/n��" << endl;
	cin >> c;
	while (c == 'y')
	{
		pre->next = new Node;    //�½�һ���ڵ�
		pre = pre->next;
		pre->next = NULL;     //β���ÿ�
		length++;                 //���һ�Σ����ȼ�һ
		cout << "�����Ϣ��y/n��" << endl;//ѭ���ж�
		cin >> c;
	}
	traveList();
}
int List::deletNode(int n)  //ɾ����nλ�ڵ�
{
	Node* pre = head;
	Node* pp = NULL;
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
		traveList();
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
		traveList();
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
		traveList();
	}
	return 0;
}
int List::changeNode(int n)//�ı���Ϣ
{
	if (n > length)
	{
		cout << "������Ч����" << endl;
		return 1;
	}
	Node* pre = head;
	while (--n)       //ѭ���ƶ�ָ��
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




//�����û���
class userPerson {
protected:
	string userName;//�����û���
	string trueName;//������ʵ����
	long Cipher;//��������
	long cpNumber;//�����ֻ���
	int borrowedBooks;//�ѽ��鼮����
	vector<Book> personalBook;//����ÿ����������鼮
public:
	friend class Administrators;
    //�Ը��˽��г�ʼ��
	userPerson(string Admini = "��", string trueName = "��", long Cipher = 0, long cpNumber = 0) :userName(Admini), trueName(trueName), Cipher(Cipher), cpNumber(cpNumber) {
		borrowedBooks = 0;
		cout << "�Ѿ��ɹ�����һλ���û�";
	}
	userPerson(userPerson& p) {
		cout << "�Ѿ��ɹ�����һλ���û�";
	}
	void modifyCipher(long cipher);//�޸�����
	void modifycpNumber(long cpnumber);//�޸��ֻ�����
	void modifyuserName(string username);//�޸��û���
	void modifytrueName(string truename);//�޸��û���ʵ����
	void getuesrName();//����û���
	void gettrueName();//�õ��û���ʵ����
	void getCipher();//�õ��û�������
	void getcpNumber();//�õ��û����ֻ�����
	void borrowBooks(Book& b2);//����
	void borrowBooks(Book& b2,int n);//ͬһ�����౾
	void returnBooks(Book& b2);//����
	void returnBooks(Book& b2,int n);//ͬһ���黹�౾
	int getNumber(string name);//�õ�ĳ�����ڸ��������е�λ��
};
int userPerson::getNumber(string name) {
	for (int i = personalBook.size(); i > 0; i--) {
		if (name == personalBook[i - 1].Name)
			return i;
	}
}
void userPerson::borrowBooks(Book& b2) {
	if (borrowedBooks >= 5 || borrowedBooks + 1 > 5)
		cout << "��Ǹ�����ѳ����޶�";
	else if (b2.bookNumber > 0) {
		b2.bookNumber--;
		cout << "��ϲ�㣬���ѳɹ�������飡";
		borrowedBooks++;
		personalBook.push_back(b2);
	}
	else cout << "��Ǹ���鼮�������㣬�����½���";
}
void userPerson::borrowBooks(Book& b2,int n) {
	if (borrowedBooks >= 5 || borrowedBooks + n > 5)
		cout << "��Ǹ�����ѳ����޶�";
	else if ((b2.bookNumber - n) > 0) {
		b2.bookNumber -= n;
		borrowedBooks += n;
		for (int i = 1; i <= n; i++) {
			personalBook.push_back(b2);
		}
		cout << "��ϲ�㣬���ѳɹ������" << n << "����";
	}
	else cout << "��Ǹ���鼮�������㣬�����½���";
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
	cout << "�����ǣ�" << Cipher;
}
void userPerson::getcpNumber() {
	cout << "�ֻ������ǣ�" << cpNumber;
}
void userPerson::getuesrName() {
	cout << "�û����ǣ�" << userName;
}
void userPerson::gettrueName() {
	cout << "��ʵ�����ǣ�" << trueName;
}


class Administrators:public userPerson{
public:
	void addUser(userPerson& b3);//�����û�
	int getuserNumber(string personname);//�õ�ĳ�û��������е�λ��
	void deleteUser(userPerson& b4);//ɾ��ĳһ���û�
	void LookupOne(userPerson& per);//�ۿ�һ���û��Ľ������
	void LookupAll();//�ۿ������û����������
private:
	vector<userPerson>users;//�û�����
};
void Administrators::LookupOne(userPerson& per) {
	for (int i = 0; i < per.borrowedBooks; i++) {
		cout << "��" << i+1 << "���飺";
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
		cout << "������" << users[i - 1].trueName;
		for (int j = 0; j < users[i - 1].borrowedBooks; j++)
			users[i - 1].personalBook[j].getInformation();
	}
}


