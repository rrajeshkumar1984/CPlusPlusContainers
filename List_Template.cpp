#include <iostream>

using namespace std;

template<typename T, int size>
int SIZE(T(&)[size]) { return size; }

template<typename T>
class node
{
public:
	T val;
	node* next;
};

template<typename T>
class List
{
public:
	List()
	{
		head = nullptr;
	}

	~List()
	{
		if (head != nullptr)
		{
			delete head;
			head = nullptr;
		}
	}

	bool insert(T a[], unsigned int u32Size)
	{
		if (u32Size == 0)
			return false;

		for (unsigned int i = 0; i < u32Size; i++)
		{
			insert(a[i]);
		}
	
		return true;
	}

	unsigned int GetSize()
	{
		return m_u32Size;
	}

	void printlist()
	{
		std::cout << "-- List Size: " << m_u32Size << endl;
		node<T>* curr = head;
		while (curr != nullptr)
		{
			std::cout << "-- " << curr->val << " --" << endl;
			curr = curr->next;
		}

		std::cout << endl;
	}

	void sort()
	{
		node<T>* curr;
		for (bool bswapped = true; bswapped;)
		{
			bswapped = false;

			for (curr = head; curr->next != nullptr; curr = curr->next)
			{
				if (curr->val > curr->next->val)
				{
					T val = curr->val;
					curr->val = curr->next->val;
					curr->next->val = val;
					bswapped = true;
				}
			}
		}
	}

	void insert(T val)
	{
		if (head == nullptr)
		{
			head = new node<T>();
			head->val = val;
			head->next = nullptr;
			m_u32Size++;
		}
		else
		{			
			node<T>* curr = head;
			while (curr->next != nullptr)
			{
				if (curr->val == val)
				{
					return;
				}
				curr = curr->next;
			}

			curr->next = new node<T>();
			curr->next->val = val;
			curr->next->next = nullptr;
			m_u32Size++;
		}
	}

	
private:
	node<T>*	  head;
	unsigned int  m_u32Size;

};
int main()
{
	int a[] = { 1,4,2,6,5,3 };
	int b[] = { 7, 12, 11, 6, 7, 10, 8, 9};

	List<int>* list = new List<int>();
	list->insert(a, SIZE(a));
	list->insert(b, SIZE(b));
	list->printlist();
	list->sort();
	list->printlist();

	std::cin.get();

    return 0;
}

