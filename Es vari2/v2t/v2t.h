#if !defined V2T_H
#define V2T_H
#include"tree.h"

enum TreeType {

	KZeroBase,
	Konebase

};

extern Node* v2t(const ElemType* v, size_t v_size, enum TreeType Type);



#endif // !defined V2T_H
