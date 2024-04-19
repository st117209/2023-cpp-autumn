#include<iostream >

struct Node 
{
	int data;
	Node* next;
	Node() : data(0), next(nullptr) {};
	Node(int data) : data(data), next(nullptr) {};
	~Node() {};	
	friend std::ostream& operator << (std::ostream& stream, Node& node);
};

class LinkedList
{
public:
	LinkedList() : head(nullptr) {};
	~LinkedList();
	int Length();
	bool IsEmpty();
	void PushHead(int data);

	//вставляет элемент data на позицию index
	void Insert(int index, int data);
	void PushTail(int data);

	//извлекает головной элемент
	int PopHead();

	//извлекает данные из позиции index
	//и удаляет элемент из списка
	int Extract(int index);
	int PopTail();

	//получает данные из позиции index
	//без удаления из списка
	int Data(int index);
	void swap(int ia, int ib);
	void sort();
	//оператор вывода в поток
	friend std::ostream& operator<<(std::ostream& stream, LinkedList& list);
private:
	void dispose();

	//извлекает данные из ноды и удаляет саму ноду
	int PopData(Node* node); //!
	void InsertNode(int index, Node* node); //!
	Node* ExtractNode(int index); //!
	bool IndexValid(int index);
	Node* head;
};


int main(int argc, char* argv[])
{
	LinkedList list;
	std::cout << list << std::endl;
	list.PushHead(1);
	std::cout << list << std::endl;
	list.PushTail(3);
	std::cout << list << std::endl;
	list.Insert(1, 2);
	std::cout << list << std::endl;
	list.Insert(3, 4);
	std::cout << list << std::endl << std::endl;
	std::cout << list << std::endl;
	std::cout << list.PopHead() << " ";
	std::cout << list.Extract(1) << " ";
	std::cout << list.PopTail() << " ";
	std::cout << list.Extract(0) << std::endl;
	std::cout << list << std::endl << std::endl;

	list.PushHead(3); list.PushHead(4); list.PushHead(1); list.PushHead(2);
	list.PushHead(7); list.PushHead(5); list.PushHead(8); list.PushHead(6);
	std::cout << list << std::endl;
	list.sort();
	std::cout << list << std::endl;
	return EXIT_SUCCESS;
}

// node
std::ostream& operator << (std::ostream& stream, Node& node) 
{
	std::cout << node.data;
	return stream;
}

// public 
LinkedList::~LinkedList()
{
	dispose();
}

int LinkedList::Length()
{
	int cnt = 0;
	Node* node = head;
	while (node != nullptr)
	{
		cnt++;
		node = node->next;
	}
	return cnt;
}

bool LinkedList::IsEmpty()
{
	return head == nullptr;
}

void LinkedList::Insert(int index, int data)
{
	Node* node = new Node(data);
	InsertNode(index, node);
}

void LinkedList::PushHead(int data)
{
	Node* node = new Node(data);
	InsertNode(0, node);
}

void LinkedList::PushTail(int data)
{
	Node* node = new Node(data);
	InsertNode(Length(), node);
}
int LinkedList::Extract(int index)
{
	return PopData(ExtractNode(index));
}
int LinkedList::PopHead()
{
	return PopData(ExtractNode(0));
}
int LinkedList::PopTail()
{
	return PopData(ExtractNode(Length() - 1));
}
int LinkedList::Data(int index)
{
	if (!IndexValid(index) || (Length() - 1 < index))
	{
		return 0;
	}

	Node* current = head;
	while (index > 0)
	{
		current = current->next;
		index = index - 1;
	}
	return current->data;
}
void LinkedList::swap(int ind1, int ind2)
{
	if (!IndexValid(ind1) || !IndexValid(ind2) || ind1 == ind2)
	{
		return;
	}
	if (ind1 > ind2)
	{
		std::swap(ind1, ind2);
	}
	Node* ibnode = ExtractNode(ind2);
	Node* ianode = ExtractNode(ind1);
	InsertNode(ind1, ibnode);
	InsertNode(ind2, ianode);
}
void LinkedList::sort()
{
	for (int i = Length() - 1; i >= 0; --i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (Data(j) > Data(j + 1))
			{
				swap(j, j + 1);
			}
		}
	}
}


std::ostream& operator<<(std::ostream& stream, LinkedList& list)
{
	Node* tmp = list.head;
	while (tmp != nullptr)
	{
		stream << *tmp << " ";
		tmp = tmp->next; 
	}
	return stream;
};

// Private
bool LinkedList::IndexValid(int index)
{
	if (index < 0)
	{
		return false;
	}
	return true;
}

void LinkedList::InsertNode(int index, Node* node)
{
	if (!IndexValid(index))
	{
		return;
	}
	if (index == 0)
	{
		node->next = head;
		head = node;
	}
	else if (index == Length())
	{
		Node* crnt = head;
		while (crnt->next != nullptr)
		{
			crnt = crnt->next;
		}
		crnt->next = node;
	}
	else if (index < Length())
	{
		Node* crnt = head;
		for (int i = 0; i < index - 1; i++)
		{
			crnt = crnt->next;
		}
		node->next = crnt->next;
		crnt->next = node;
	}
}

int LinkedList::PopData(Node* node)
{
	if (node == nullptr)
	{
		return 0;
	}
	int res = node->data;
	delete node;
	return res;
}

Node* LinkedList::ExtractNode(int index)
{
	if (!IndexValid(index))
	{
		return nullptr;
	}
	if (index == 0)
	{
		Node* temp = head;
		head = head->next;
		return temp;
	}
	if (index == Length() - 1)
	{
		Node* crnt = head;
		while (crnt->next->next != nullptr)
		{
			crnt = crnt->next;
		}
		Node* temp = crnt->next;
		crnt->next = nullptr;
		return temp;
	}
	if (index < Length())
	{
		Node* crnt = head;
		for (int i = 0; i < index - 1; i++)
		{
			crnt = crnt->next;
		}
		Node* temp = crnt->next;
		crnt->next = crnt->next->next;
		return temp;
	}
	return nullptr;
}

void LinkedList::dispose()
{
	while (head != nullptr)
	{
		Node* temp = head;
		head = head->next;
		delete temp;
	}
}

