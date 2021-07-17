#pragma once

#include "Person.h"

typedef size_t Key;
typedef Person* Value;
enum class ESlotStatus{ EMPTY, DELETED, INUSE };

struct Slot {
	Slot() : key(), val() {}
	Slot(Key k, Value v) : key(k), val(v) {}
	~Slot() { key = 0; delete val; }
	Key key;
	Value val;
};