/*
	fstack.cpp
	November 30, 2016
	Ralph McCracken, III
	mccracke

	Test client for Stack<T,N>
	MODELED AFTER FILE, fbitvect.cpp, BY R. C. Lacher
	ALSO MODELED AFTER FILES, fstack_*_i.x
 */

#include <iostream>
#include <stack.t>

// ==========================================================
// = TYPE DEFINITIONS FOR TEST CLIENT
// ==========================================================
// Uncomment for desired test attributes.


// char =====================
typedef char dataType;
const char fill = '*';
const size_t capacity = 10;
const char ofc = '\0';
const char* typeName = "char";
// ==========================


/*
// int ======================
typedef int dataType;
const int fill = 0;
const size_t capacity = 100;
const char ofc = ' ';
const char* typeName = "int";
// ==========================
*/

/*
// fsu::String ==============
#include <xstring.h>
#include <xstring.cpp>
typedef fsu::String dataType;
const fsu::String fill = "*";
const size_t capacity = 100;
const char ofc = ' ';
const char* typeName = "String";
// ==========================
*/

// ==========================================================
// = TEST CLIENT
// ==========================================================

void DisplayMenu();

template <typename Stack>
void CopyTest(Stack stck);

template <typename Stack>
void AssignTest(const Stack& stck);

template <typename Stack>
void ConstTest(Stack& stck);

template <typename Stack>
void ConstTest(const Stack& stck);

int main(int argc, char* argv[])
{
	typedef fsu::Stack<dataType, capacity> StackT;

	char selection;
	StackT stck(fill);
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
				stck.Push(input);
				break;
			case '-':
			case '2':
				stck.Pop();
				break;
			case 'C':
			case 'c':
				stck.Clear();
				break;
			case 'T':
			case 't':
				if(stck.Size() == 0)
				{
					std::cout << stck.Top() << "\n";
					break;
				}
				std::cout << "Top of Stack: " << stck.Top() << "\n";
				break;
			case 'E':
			case 'e':
				if (stck.Empty())
				{
					std::cout << "Stack is empty" << std::endl;
				}else
				{
					std::cout << "Stack is not empty" << std::endl;
				}
				break;
			case 'S':
			case 's':
				std::cout << "Stack size = " << stck.Size() << "\n";
				break;
			case '=':
				CopyTest(stck);
				AssignTest(stck);
				ConstTest(stck);
				break;
			case 'D':
			case 'd':
				std::cout << "Stack contents: ";
				stck.Display(std::cout, ofc);
				std::cout << '\n';
				break;
			case 'U':
			case 'u':
				stck.Dump(std::cout);
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
	std::cout << "Top()  ..................  T"				<< "\n";
	std::cout << "Empty()  ................  E"				<< "\n";
	std::cout << "Size()  .................  S"				<< "\n";
	std::cout << "Copies  .................  ="				<< "\n";
	std::cout << "Display stack ...........  D"				<< "\n";
	std::cout << "Dump() ..................  U"				<< "\n";
	std::cout << "Display this menu  ......  M"				<< "\n";
}

template <typename Stack>
void CopyTest(Stack stck)
{
	std::cout << "CopyTest:"																														<< "\n";
	std::cout << "Copied object       size: " << stck.Size()														<< "\n";
	std::cout << "                contents: "; stck.Display(std::cout, ofc); std::cout	<< "\n";
}

template <typename Stack>
void AssignTest(const Stack& stck)
{
	Stack stckB;
	stckB = stck;

	std::cout << "AssignTest:"																														<< "\n";
	std::cout << "Original stack      size: " << stck.Size()															<< "\n";
	std::cout << "                contents: ";		stck.Display(std::cout, ofc); std::cout	<< "\n";
	std::cout << "Assignee stack      size: " << stckB.Size()															<< "\n";
	std::cout << "                contents: ";		stckB.Display(std::cout, ofc); std::cout<< "\n";
}

template <typename Stack>
void ConstTest(Stack& stck)
{
	if(stck.Size() == 0)
	{
		std::cout << "ConstTest: inactive on empty stack" << "\n";
		return;
	}
	std::cout << "ConstTest: OK" << "\n";
}

template <typename Stack>
void ConstTest(const Stack& stck)
{
	if(stck.Size() == 0)
	{
		std::cout << "ConstTest: inactive on empty stack" << "\n";
		return;
	}
	std::cout << "ConstTest: NOT OK" << "\n";
}
