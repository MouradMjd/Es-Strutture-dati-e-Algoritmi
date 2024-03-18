int upper_bound(int A[], int first, int last, int target) {
	int mid, middle;
	while (first < last) {
		mid = (last + first) / 2;
		middle = A[mid];
		if (middle < target) 
			first = mid + 1;
		else
		
			last = mid;
	}
	if (first == last && A[first] < target) {
		first++;
	}
	
	if (first == last) return first;
	else 
		return -1;
}

int lower_bound(int A[], int first, int last, int target) {
	int mid, middle;
	while (first < last) {
		mid = (last + first) / 2;
		middle = A[mid];
		if (middle <= target) // cerca a destra
			first = mid + 1;
		else
			// cerca a sinistra
			last = mid;
	}
	if (first == last && A[first] < target) {
		first++;
	}
	
	if (first == last) return first;
	else 
		return -1;
}

	void main(void)
	{
		int b[] = { 1,5,8,9,10 };
		upper_bound(b, 0, 4, 7);
	}
