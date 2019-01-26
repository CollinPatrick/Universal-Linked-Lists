#pragma once
template<typename Type>
class UlinkedList
{
	//~UlinkedLists();
private:
	ListNode * head = NULL, *tail = NULL;
public:

	//Container for linked list nodes
	struct ListNode
	{
		Type *node = NULL;

		ListNode *next = NULL;
		ListNode *previous = NULL;
	};

	//-returns number of objects in list
	int Count()
	{
		ListNode *temp = head;
		int count = 0;
		while (temp != NULL)
		{
			count++;
			temp = temp->next;
		}
		return count;
	};

	//-Creates an object of specified Type at top of stack
	Type *CreateAtTop()
	{
		ListNode *listNode = new ListNode;
		Type *temp = new Type;
		listNode->node = temp;
		//Type *temp = new Type;
		if (head != NULL)
		{
			head->previous = listNode;
		}
		listNode->next = head;
		listNode->previous = NULL;
		head = listNode;

		if (tail == NULL)
		{
			tail = listNode;
		}
		return listNode->node;
	};

	//-Creates an object of specified Type at bottom of stack
	Type *CreateAtBottom()
	{
		ListNode *listNode = new ListNode;
		Type *temp = new Type;
		listNode->node = temp;
		if (tail != NULL)
		{
			tail->next = listNode;
		}
		listNode->previous = tail;
		listNode->next = NULL;
		tail = listNode;

		if (head == NULL)
		{
			head = listNode;
		}
		return listNode->node;
	};

	
	//-Inserts object of specified type at specified index in list
	//-throws error and returns null if specified index is out of bounds
	Type *CreateAtIndex(int index)
	{
		if (index >= Count() || index < 0)
		{
			cout << "Index out of bounds" << endl;
			return NULL;
		}
		
		int count = Count();

		//checks if index is top or bottom of list
		if (index == count)
		{
			return CreateAtBottom();
		}
		else if (index == 0)
		{
			return CreateAtTop();
		}

		ListNode *iterator;
		
		if (index > (count / 2))
		{
			iterator = tail;
			while (count >= index)
			{
				iterator = iterator->previous;
				count--;
			}
		}
		else
		{
			iterator = head;
			count = 0;
			while (count < index)
			{
				iterator = iterator->next;
				count++;
			}
		}
		Type *temp = new Type;
		ListNode *listNode = new ListNode;
		listNode->node = temp;
		listNode->previous = iterator->previous;
		listNode->next = iterator;
		iterator->previous->next = listNode;
		iterator->previous = listNode;
		return listNode->node;
	}


	//-adds existing object at top of list
	void AddAtTop(Type *node) 
	{
		ListNode *listNode = new ListNode;
		listNode->node = node;

		if (head != NULL)
		{
			head->previous = listNode;
		}
		listNode->next = head;
		listNode->previous = NULL;
		head = listNode;

		if (tail == NULL)
		{
			tail = listNode;
		}
	};

	//-adds existing object at bottom of list
	void AddAtBottom(Type *node) 
	{
		ListNode *listNode = new ListNode;
		listNode->node = node;
		if (tail != NULL)
		{
			tail->next = listNode;
		}
		listNode->previous = tail;
		listNode->next = NULL;
		tail = listNode;

		if (head == NULL)
		{
			head = listNode;
		}
	};

	//-adds existing object to list at specified index
	//-throws error and returns null if specified index is out of bounds
	void AddAtIndex(Type *node, int index) 
	{
		if (index >= Count() || index < 0)
		{
			cout << "Index out of bounds" << endl;
			return NULL;
		}

		int count = Count();

		//checks if index is top or bottom of list
		if (index == count)
		{
			return AddAtBottom( *node );
		}
		else if (index == 0)
		{
			return AddAtTop( *node );
		}

		ListNode *iterator;

		if (index > (count / 2))
		{
			iterator = tail;
			while (count >= index)
			{
				iterator = iterator->previous;
				count--;
			}
		}
		else
		{
			iterator = head;
			count = 0;
			while (count < index)
			{
				iterator = iterator->next;
				count++;
			}
		}
		ListNode *listNode = new ListNode;
		listNode->node = node;
		listNode->previous = iterator->previous;
		listNode->next = iterator;
		iterator->previous->next = listNode;
		iterator->previous = listNode;
	};

	/////////////////////////////////////////////// UNTESTED BEYOND THIS POINT \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

	//-removes and returns object at top of list
	Type *PopTop() 
	{
		ListNode *listNode = head;
		Type *temp = listNode->node;
		head = head->next;
		head->previous = NULL;

		listNode->next = NULL;
		listNode->previous = NULL;
		delete(listNode);
		return temp;

	};

	//-removes and returns object at bottom of list
	Type *PopBottom() 
	{
		ListNode *listNode = tail;
		Type *temp = listNode->node;
		tail = tail->previous;
		tail->next = NULL;

		temp->next = NULL;
		temp->previous = NULL;
		delete(listNode);
		return temp;
	};

	//-removes and returns object at specified index
	//-throws error and returns null if specified index is out of bounds
	Type *PopAtIndex(int index) 
	{
		if (index >= Count() || index < 0)
		{
			cout << "Index out of bounds" << endl;
			return NULL;
		}

		count = Count();

		if (index == count)
		{
			return PopBottom(*node);
		}
		else if (index == 0)
		{
			return PopTop(*node);
		}

		ListNode *iterator;

		if (index > (count / 2))
		{
			iterator = tail;
			while (count >= index)
			{
				iterator = iterator->previous;
				count--;
			}
		}
		else
		{
			iterator = head;
			count = 0;
			while (count < index)
			{
				iterator = iterator->next;
				count++;
			}
		}

		Type *temp = iterator->node;
		iterator->previous->next = iterator->next;
		iterator->next->previous = iterator->next;
		iterator->next = NULL;
		iterator->previous = NULL;
		delete(iterator);

		return temp;
	};

	//-returns object at head of list
	Type GetHead() 
	{
		return *head->node;
	};

	//-returns object at tail of list
	Type GetTail() 
	{
		return *tail->node;
	};

	//-returns object at specified index
	Type GetAtIndex(int index) {};

	//-returns index of specified object within list
	//-throws error and returns -1 if specified index is out of bounds
	int GetIndex(Type *node) 
	{
		ListNode *listNode = head;

		int count = 0;
		while (listNode->next != NULL)
		{
			if (listNode->node == node)
			{
				return count;
			}
			listNode = listNode->next;
			count++;
		}

		return -1;
	};

	//removes specified object from list
	//throws error if object is not in list
	void Remove(Type *node) 
	{
		if (!Contains(node))
		{
			std::cout << "List does not contain " << *node << endl;
			//Throw Error
			return;
		}

		ListNode *iterator = head;

		while (iterator->node != node)
		{
			iterator = iterator->next;
		}

		iterator->previous->next = iterator->next;
		iterator->next->previous = iterator->next;

		delete iterator->node;
		delete iterator;

	};

	//removes specified object from list at specified index
	//throws out of bounds error if index is not within list
	void RemoveAtIndex(int index) 
	{
		if (index >= Count() || index < 0)
		{
			cout << "Index out of bounds" << endl;
			return;
		}

		ListNode *itterator = head;
		int count = Count();

		if (index >(count / 2))
		{
			iterator = tail;
			while (count >= index)
			{
				iterator = iterator->previous;
				count--;
			}
		}
		else
		{
			iterator = head;
			count = 0;
			while (count < index)
			{
				iterator = iterator->next;
				count++;
			}
		}

		iterator->previous->next = iterator->next;
		iterator->next->previous = iterator->next;

		delete iterator->node;
		delete iterator;
	};


	//returns true or false if an object is in the stack
	bool Peek()
	{
		return bool(head == NULL) ? false : true;
	};

	bool Contains(Type *node)
	{
		ListNode *listNode = head;

		while (listNode->next != NULL)
		{
			if (listNode->node == node)
			{
				return true;
			}
			listNode = listNode->next;
		}

		return false;
	};

	void PrintList()
	{
		ListNode *temp = head;
		int count = 0;
		while (temp != NULL)
		{
			std::cout << "[" << count << "]" << temp->node->name << ", ";
			count++;
			temp = temp->next;
		}
		std::cout << endl;
	};
};