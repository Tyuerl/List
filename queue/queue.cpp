#include <iostream>
using namespace std;

class List
{
private :
	struct list
	{
		char info;
		list* next;
	};
	list* head;
	int size;
public:
	List()
	{
		head = NULL;
		size = 0;
	}

	List(const char* arr, int n)
	{
		head = NULL;
		for (int i = 0; i < n; i++)
			push(arr[i]);
	}

	List(char a, int n)
	{
		head = NULL;
		for (int i = 0; i < n; i++)
			push(a);
	}

	//~List()
	//{
	//	if (head == NULL)
	//		return ;
	//	list* cur = ;
	//	list* prev = cur;
	//	while (cur != NULL)
	//	{
	//		cur = cur->next;
	//		delete prev;
	//		prev = cur;
	//	}
	//}

	//~List()
	//{
	//	while (head)
	//		pop();
	//}

	bool is_in(char info)
	{
		list* cur = head;
		for (int i = 0; i < size; i++, cur = cur->next)
			if (info == cur->info)
				return (1);
		return (0);
	}
	void push(char info)
	{
		size++;
		if (head == NULL)
		{
			list* temp = new list;
			temp->next = NULL;
			temp->info = info;
			head = temp;
			return;
		}
		list* cur = head;
		list* temp = new list;
		for (; cur->next != NULL; cur = cur->next);
		cur->next = temp;
		temp->next = NULL;
		temp->info = info;
		return;
	}
	
	void push(char info, int index)
	{
		if (index > size)
			return;
		size++;
		if (index == 0)
		{
			list* temp = new list;
			temp->info = info;
			temp->next = head;
			head = temp;
		}
		else
		{
			list* cur = head;
			list* temp = new list;
			for (int i = 0; i < index - 1; i++, cur = cur->next)
				;
			temp->info = info;
			temp->next = cur->next;
			cur->next = temp;
			return;
		}
	}

	bool isEmpty()
	{
		return head == NULL;
	}
	char front()
	{
		return head->info;
	}
	char pop()
	{
		char data;
		list* cur = head;
		if (head == NULL || !head)
			return 0;
		if (head->next == NULL)
		{
			data = head->info;
			delete head;
			head = NULL;
			return (data);
		}
		for (; cur->next != NULL; cur = cur->next)
			;
		data = cur->info;
		delete cur;
		cur = head;
		size--;
		for (int i = 0; i < size - 1; i++, cur = cur->next)
			;
		cur->next = NULL;
		return data;
	}
	
	char pop(int index)
	{
		if (head == NULL)
			return 0;
		if (index > size)
			return (-1);
		list* cur = head;
		list* temp = cur;
		for (int i = 0; i < index; i++, cur = cur->next)
			if (i == index - 1)
				temp = cur;
		char data = cur->info;
		temp->next = cur->next;
		delete cur;
		size--;
		return data;
	}

	char get(int index)
	{ 
		list* cur = head;
		if (index < 0 || index > size)
			return (-1);
		for (int i = 0; i < index; cur = cur->next, i++)
			;
		return (cur->info);
	}

	int get_index(char data)
	{
		list* cur = head;
		if (head == NULL)
			return (-1);
		for (int i = 0; i < size; cur = cur->next, i++)
			if (cur->info == data)
				return (i);
		return (-1);
	}

	void Print()
	{
		if (head == NULL)
			return;
		list* cur = head;
		for (; cur != NULL; cur = cur->next)
			cout << cur->info << " ";
		cout << endl;
		return;
	}

	void operator--()
	{
		list* cur = head;
		head = head->next;
		delete cur;
	}

	List  operator+(List b)
	{
		List newlist(' ', size + b.size);
		list* cur = newlist.head;
		list* cur1 = head;
		list* cur2 = b.head;
		for (int i = 0; i < newlist.size; i++, cur = cur->next)
		{
			if (i < size)
			{
				cur->info = cur1->info;
				cur1 = cur1->next;
			}
			else
			{
				cur->info = cur2->info;
				cur2 = cur2->next;
			}
		}
		return (newlist);
	}

	void input() {
		char a;
		int N = size;
		cout << "Enter count of list : \n";
		cin >> N;
		cout << "Enter " " chars:" << endl;
		for (int i = 0; i < N; i++)
		{
			cin >> a;
			push(a);
		}
	}

	bool operator==(List b)
	{
		if (size != b.size)
			return (0);
		list* cur = b.head;
		list* curr = head;
		for (int i = 0; i < size; i++)
		{
			if (cur->info != curr->info)
				return (0);
			cur = cur->next;
			curr = curr->next;
		}
		return (1);
	}
};


int main()
{
	setlocale(LC_ALL, "ru");
	List b("ABCD", 4);
	List c;
	c.input();
	List a = b + c;
	cout << "B = ";
	b.Print();
	cout << "C = ";
	c.Print();
	cout << "B + C = ";
	a.Print();

	a.pop();
	a.push('G');
	cout << "6 = G \n";
	a.Print();
	cout << "0 1 2 3 4 5 6 7\n";
	cout << "Index of symbol 'G' = "<< a.get_index('G') << '\n';

	a.Print();
	cout << "Operator --a = ";
	--a;
	a.Print();

	a.Print();
	cout << "info in index 4 == " << a.get(4) << endl;

	a.Print();
	cout << "remove element 3 index : " << endl;
	a.pop(3);
	a.Print();
}