#include<iostream>

class listayList
{ 
private:
	int len;
	int* data;

	int element;

	void init(int len = 10)
	{
		this->len = len;
		this->data = (int*)malloc(sizeof(int) * len);
	}
	bool indexValid(int index)
	{
		return 0 <= index < this->len;
	}
	void expand(int** a, int* len)
	{
		int* newlistay = initIntlistay(*len + 1);
		if (newlistay != nullptr)
		{
			for (int i = 0; i < *len; ++i)
			{
				newlistay[i] = (*a)[i];
			}
			free(*a);
			*a = newlistay;
			(*len)++;
		}
	}
	void expandIntlistay_back(int** a, int* len)
	{
		int* newlistay = initIntlistay(*len + 1);
		if (newlistay != nullptr)
		{
			for (int i = 0; i < *len; ++i)
			{
				newlistay[i] = (*a)[i];
			}
			free(*a);
			*a = newlistay;
			(*len)++;
		}
	}
	void contract(int reduced = 1)
	{
		if (reduced > len)
		{
			return;
		}
		int newlen = this->len - reduced;
		int* newdata = (int*)malloc(sizeof(int) * newlen);
		if (newdata != nullptr)
		{
			for (int i = 0; i < newlen; ++i)
			{
				newdata[i] = this->data[i];
			}
		}
		if (this->data != nullptr)
		{
			free(this->data);
			this->data = newdata;
			this->len = newlen;
		}
	}
	void swap(int i1, int i2)
	{
		int c = get(i1);
		set(i1, get(i2));
		set(i2, c);
	}

public:
	listayList(int len = 10)
	{
		this->init(len);
		for (int i = 0; i < this->len; ++i)
		{
			this->data[i] = 0;
		}
	}
	listayList(listayList& list)
	{
	
		this->init(list.len);
		for (int i = 0; i < list.len; ++i)
		{
			this->set(i, list.get(i));
		}
	}
	~listayList()
	{

		free(this->data);
	
	}
	void randomize(int min = 10, int max = 99)
	{
		for (int i = 0; i < len; ++i)
		{
			this->data[i] = rand() % (max - min + 1) + min;
		}
	}
	void print()
	{
		for (int i = 0; i < this->len; ++i)
		{
			printf("%d ", this->data[i]);
		}
		printf("\n");
	}
	int get(int index)
	{
		if (indexValid(index))
		{
			return this->data[index];
		}
		return -1;
	}
	void set(int index, int value)
	{
		if (indexValid(index))
		{
			this->data[index] = value;
		}
	}
	int count()
	{
		return len;
	}

	int* initIntlistay(int len)
	{
		int* res = nullptr;
		res = (int*)malloc(sizeof(int) * len);
		for (int i = 0; res != nullptr && i < len; ++i)
		{
			res[i] = 0;
		}
		return res;
	}

	
	
	void pushBack(int element)
	{
		expandIntlistay_back(a, len);
		(*a)[*len - 1] = element;
	}
	void pushFront(int element)
	{
		pushBack(element);
		shift(1);
	}
	void insert(int index, int element)
	{
		expand();
		for (int i = len - 1; i > index; --i)
		{
			set(i, get(i - 1));
		}
		set(index, element);
	}	int popBack()
	{
		int res = get(this->len - 1);
		contract();
		return res;
	}	int popFront()
	{
		shift(-1);
		return popBack();
	}
	int extract(int index)
	{
		if (index >= 0 && index < this->len)
		{
			return data[index];
		}

	}
	int sum();
	{
		int total = 0;
		for (len i = 0; i < this->len; ++i) 
		{
			int value = data[i];
			total += value;
		}
		return total;
	}
}

void reverse(int start, int end)
{
	if (!indexValid(start) || !indexValid(end))
	{
		return;
	}
	int rnglen = end - start + 1;
	for (int i = 0; i < rnglen / 2; ++i)
	{
		swap(start + i, end - i);
	}
}
	
	int secondMax();
	{
		for (int i = index; i < this->len; ++i)
		{
			for (int j = 0; j < this->len - 1; ++j)
			{
				if (this->data[i] > this->data[i + 1])
				{
					int z = this->data[i];
					this->data[i] = this->data[i + 1];
					this->data[i + 1] = z;
				}
			}
		}

		int SecMax = this->data[this->len - 2];
		return SecMax;
	}
	
	int lastMinIndex()
	{
		int mnInd = 0;
		for (int i = 0; i < len; ++i)
		{
			if (get(i) <= get(mnInd))
			{
				mnInd = i;
			}
		}
		return mnInd;
	}
	
	int shift(int k)				
	{									
		reverse(0, len - k - 1);		
		reverse(len - k, len - 1);		
		reverse(0, len - 1);			
	}
	
	
	int countOdd()
	{
		int count = 0;
		for (int i = 0; i < len; ++i)
		{
			if (get(i) % 2 == 1)
			{
				++count;
			}
		}
		return count;
	}

	
	int sumEven();
	{
		for (i = index; i < this->len; ++i)
		{
			if (this->data[i] % 2 == 0)
			{
				int SumEven += this->data[i];
			}
			else
			{
				continue;
			}
		}
		return SumEven;
	}
};

int max(listayList list)
{
	int mx = list.get(0);
	for (int i = 0; i < list.count(); ++i)
	{
		mx = (mx > list.get(i) ? mx : list.get(i));
	}
	return mx;
}

int main(int argc, char* argv[])
{
	listayList list(10);
	list.randomize();
	list.print();
	printf("%d\n", max(list));
	return 0;
}