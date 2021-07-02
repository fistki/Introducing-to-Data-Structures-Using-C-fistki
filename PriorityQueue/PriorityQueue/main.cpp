#include <cstdio>
#include <string>
#include <iostream>
#include "PriorityQueue.h"

int DataPrioirtyComp(char ch1, char ch2)
{
	return ch2 - ch1;
}

int StringPriorityComp(const std::string& s1, const std::string& s2)
{
	return s2.length() - s1.length();
}

void Problem9_1(void)
{
	PriorityQueue<std::string> PQString(StringPriorityComp);

	PQString.enqueue("asdfdfsf");
	PQString.enqueue("bbbbbbbbbbbb");
	PQString.enqueue("asdf");
	PQString.enqueue("dfsf");
	PQString.enqueue("bvv");
	PQString.enqueue("qq");
	PQString.enqueue("ihaveapen");

	while (!PQString.empty())
	{
		std::cout << PQString.dequeue() << std::endl;
	}

}

int main(void)
{
	PriorityQueue<char> pq(DataPrioirtyComp);

	pq.enqueue('A');
	pq.enqueue('B');
	pq.enqueue('C');
	printf("%c\n", pq.dequeue());

	pq.enqueue('A');
	pq.enqueue('B');
	pq.enqueue('C');
	printf("%c\n", pq.dequeue());

	while (!pq.empty())
	{
		printf("%c\n", pq.dequeue());
	}

	Problem9_1();

	return 0;
}
