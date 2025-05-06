#if !defined MERGE_H
#define MERGE_H
#include"list.h"
enum MergeType {
	Kcopy,
	KNoCopy
};

extern Item* ordermerge(Item* i1, Item* i2, enum MergeType m);




#endif // !defined
