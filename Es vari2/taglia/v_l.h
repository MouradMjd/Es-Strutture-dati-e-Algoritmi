

#if !defined VETT_H
#define VETT_H
#include"list.h"
enum ConversioneType
{
	kinOrder,
	kReverse
};
extern Item* Vector2list(const ElemType* v, size_t v_size, enum ConversioneType c);
extern ElemType *List2Vector(const Item *i, size_t v_size, enum ConversioneType c);



#endif // !defined VETT_H
