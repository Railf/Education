/*
	fstack.cpp
	November 30, 2016
	Ralph McCracken, III
	mccracke

	Test client for Queue<T>
	MODIFIED FROM PERSONAL PROJECT 7 FILE, fstack.cpp
	MODELED AFTER FILE, fbitvect.cpp, BY R. C. Lacher
	ALSO MODELED AFTER FILES, fqueue_*_i.x
 
 */

#include <iostream>
#include <queue.t>

// ==========================================================
// = TYPE DEFINITIONS FOR TEST CLIENT
// ==========================================================
// Uncomment for desired test attributes.


// char =====================
typedef char dataType;
const char ofc = '\0';
const char* typeName = "char";
// ==========================


/*
// int ======================
typedef int dataType;
const char ofc = ' ';
const char* typeName = "int";
// ==========================
*/

/*
// fsu::String ==============
#include <xstring.h>
#include <xstring.cpp>
typedef fsu::String dataType;
const char ofc = ' ';
const char* typeName = "String";
// ==========================
*/

// ==========================================================
// = TEST CLIENT
// ==========================================================

void DisplayMenu();

template < typename Queue >
void CopyTest(Queue que);

template < typename Queue >
void AssignTest(const Queue& que);

template < typename Queue >
void ConstTest(Queue& que);

template < typename Queue >
void ConstTest(const Queue& que);

int main(int argc, char* argv[])
{
	typedef fsu::Queue<dataType> QueueT;

	char selection;
	QueueT que;
	dataType input;
	std::cout << "This is a Stack < " << typeName << " > test program" << "\n";
	DisplayMenu();
	do
	{
		std::cout << "Enter [command][argument] ('M' for menu, 'Q' to quit): ";
		std::cin >> selection;
		switch (selection)
		{
			case '+':
			case '1':
				std::cin >> input;
				que.Push(input);
				break;
			case '-':
			case '2':
				que.Pop();
				break;
			case 'C':
			case 'c':
				que.Clear();
				break;
			case 'R':
			case 'r':
				que.Release();
				break;
			case 'F':
			case 'f':
				if(que.Size() == 0)
				{
					std::cout << que.Front() << "\n";
					break;
				}
				std::cout << "Front of Queue: " << que.Front() << "\n";
				break;
			case 'E':
			case 'e':
				if (que.Empty())
				{
					std::cout << "Queue is empty" << std::endl;
				}else
				{
					std::cout << "Queue is not empty" << std::endl;
				}
				break;
			case 'S':
			case 's':
				std::cout << "Queue size     = " << que.Size() << "\n";
				std::cout << "Queue capacity = " << que.Capacity() << "\n";
				break;
			case '=':
				CopyTest(que);
				AssignTest(que);
				ConstTest(que);
				break;
			case 'D':
			case 'd':
				std::cout << "Queue contents: "; que.Display(std::cout, ofc); std::cout << '\n';
				std::cout << "          dump: "; que.Dump(std::cout, ofc);
				std::cout << '\n';
				break;
			case 'M':
			case 'm':
				DisplayMenu();
				break;
			case 'Q':
			case 'q':
				break;
			default:
				std::cout << "  command not found\n";
		}
	} while ((selection != 'q') && (selection != 'Q'));
	std::cout << "\nHave a nice day." << "\n";
	return 0;
}

void DisplayMenu()
{
	std::cout << "Push(Tval)  .............  + or 1"	<< "\n";
	std::cout << "Pop()  ..................  - or 2"	<< "\n";
	std::cout << "Clear()  ................  C"				<< "\n";
	std::cout << "Release()  ..............  R"				<< "\n";
	std::cout << "Front()  ................  F"				<< "\n";
	std::cout << "Empty()  ................  E"				<< "\n";
	std::cout << "Size()  .................  S"				<< "\n";
	std::cout << "Copies  .................  ="				<< "\n";
	std::cout << "Display entire queue  ...  D"				<< "\n";
	std::cout << "Display this menu  ......  M"				<< "\n";
}

template < typename Queue >
void CopyTest(Queue que)
{
	std::cout << "CopyTest:"																													<< "\n";
	std::cout << "Copied object       size: " << que.Size()														<< "\n";
	std::cout << "                contents: "; que.Display(std::cout, ofc); std::cout	<< "\n";
}

template < typename Queue >
void AssignTest(const Queue& que)
{
	Queue queB;
	queB = que;

	std::cout << "AssignTest:"																														<< "\n";
	std::cout << "Original stack      size: " << que.Size()																<< "\n";
	std::cout << "                contents: ";		que.Display(std::cout, ofc); std::cout	<< "\n";
	std::cout << "Assignee stack      size: " << queB.Size()															<< "\n";
	std::cout << "                contents: ";		queB.Display(std::cout, ofc); std::cout	<< "\n";
}

template < typename Queue >
void ConstTest(Queue& que)
{
	if(que.Size() == 0)
	{
		std::cout << "ConstTest: inactive on empty stack" << "\n";
		return;
	}
	std::cout << "ConstTest: OK" << "\n";
}

template < typename Queue >
void ConstTest(const Queue& que)
{
	if(que.Size() == 0)
	{
		std::cout << "ConstTest: inactive on empty stack" << "\n";
		return;
	}
	std::cout << "ConstTest: NOT OK" << "\n";
}
