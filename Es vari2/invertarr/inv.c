



void invrec(int* arr, int size,int i)
{
	if (i == size-1)
	{
		return;
	}

	int n = arr[i];
	arr[i] = arr[size-1];
	arr[size-1] = n;

	invrec(arr, size - 1, i + 1);
}

void inv(int* arr, int size)
{
	invrec(arr, size, 0);
}

void main(void)
{

	int v[] = { 1,2,3,4,5,6,7 };
	inv(v, 7);
}