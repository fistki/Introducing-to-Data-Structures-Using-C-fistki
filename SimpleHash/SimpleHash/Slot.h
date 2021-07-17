#pragma once

#include "Person.h"

typedef size_t Key;
typedef Person* Value;
enum class ESlotStatus{ EMPTY, DELETED, INUSE };

struct Slot {
	Slot() : status(ESlotStatus::EMPTY), key(), val() {}
	ESlotStatus status;
	Key key;
	Value val;
};