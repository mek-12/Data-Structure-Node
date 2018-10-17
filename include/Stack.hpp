#ifndef STACK_HPP
#define STACK_HPP
#include <iostream>
#include "Dugum.hpp"
#include "Hatalar.hpp"

using namespace std;

class Stack()
{

private:
	Dugum *stackbasi;
public:
	Stack();
	bool IsEmpty();
	void push(string eleman);
	void pop();
	string top();
	void makeEmpty();
	~Stack();
};
#endif