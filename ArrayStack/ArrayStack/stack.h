#pragma once

template<typename Data>
class Stack {
public:
	virtual ~Stack() {}
	virtual bool empty(void) const = 0;
	virtual void push(const Data& data) = 0;
	virtual Data pop(void) = 0;
	virtual Data peek(void) const = 0;

};

