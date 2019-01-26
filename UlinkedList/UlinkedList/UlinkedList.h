#pragma once
template<typename Type>
class UlinkedList
{
	//~UlinkedLists();
public:
	Type *head = NULL, *tail = NULL;

	//-returns number of objects in list
	int Count()
	{
		Type *temp = head;
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
		Type *temp = new Type;
		if (head != NULL)
		{
			head->previous = temp;
		}
		temp->next = head;
		temp->previous = NULL;
		head = temp;

		if (tail == NULL)
		{
			tail = temp;
		}
		return temp;
	};

	//-Creates an object of specified Type at bottom of stack
	Type *CreateAtBottom()
	{
		Type *temp = new Type;
		if (tail != NULL)
		{
			tail->next = temp;
		}
		temp->previous = tail;
		temp->next = NULL;
		tail = temp;

		if (head == NULL)
		{
			head = temp;
		}
		return temp;
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

		Type *iterator;
		
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
		temp->previous = iterator->previous;
		temp->next = iterator;
		iterator->previous->next = temp;
		iterator->previous = temp;
		return temp;
	}

	//-adds existing object at top of list
	void AddAtTop(Type *node) 
	{
		if (head != NULL)
		{
			head->previous = node;
		}
		node->next = head;
		node->previous = NULL;
		head = node;

		if (tail == NULL)
		{
			tail = node;
		}
	};

	//-adds existing object at bottom of list
	void AddAtBottom(Type *node) 
	{
		if (tail != NULL)
		{
			tail->next = node;
		}
		node->previous = tail;
		node->next = NULL;
		tail = node;

		if (head == NULL)
		{
			head = node;
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

		Type *iterator;

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
		node->previous = iterator->previous;
		node->next = iterator;
		iterator->previous->next = node;
		iterator->previous = node;
	};

	/////////////////////////////////////////////// UNTESTED BEYOND THIS POINT \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

	//-removes and returns object at top of list
	Type *PopTop() 
	{
		Type *temp = head;
		head = head->next;
		head->previous = NULL;

		temp->next = NULL;
		temp->previous = NULL;
		return temp;

	};

	//-removes and returns object at bottom of list
	Type *PopBottom() 
	{
		Type *temp = tail;
		tail = tail->previous;
		tail->next = NULL;

		temp->next = NULL;
		temp->previous = NULL;
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

		Type *iterator;

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

		iterator->previous->next = iterator->next;
		iterator->next->previous = iterator->next;
		iterator->next = NULL;
		iterator->previous = NULL;

		return iterator;
	};

	//-returns object at head of list
	Type GetHead() 
	{
		return *head;
	};

	//-returns object at tail of list
	Type GetTail() 
	{
		return *tail;
	};

	//-returns object at specified index
	Type GetAtIndex(int index) {};

	//-returns index of specified object within list
	//-throws error and returns -1 if specified index is out of bounds
	int GetIndex(Type *node) 
	{
		Type *temp = head;

		int count = 0;
		while (temp->next != NULL)
		{
			if (temp == node)
			{
				return count;
			}
			temp = temp->next;
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

		Type *iterator = head;

		while (iterator != node)
		{
			iterator = iterator->next;
		}

		iterator->previous->next = iterator->next;
		iterator->next->previous = iterator->next;

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

		Type *itterator = head;
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

		delete iterator;
	};


	//returns true or false if an object is in the stack
	bool Peek()
	{
		return bool(head == NULL) ? false : true;
	};

	bool Contains(Type *node)
	{
		Type *temp = head;

		while (temp->next != NULL)
		{
			if (temp == node)
			{
				return true;
			}
			temp = temp->next;
		}

		return false;
	};

	void PrintList()
	{
		Type *temp = head;
		int count = 0;
		while (temp != NULL)
		{
			std::cout << "[" << count << "]" << temp->name << ", ";
			count++;
			temp = temp->next;
		}
		std::cout << endl;
	};
};