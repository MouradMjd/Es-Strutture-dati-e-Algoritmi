#if !defined SEC
#define SEC

typedef struct {
	int* coeff;
	size_t size;
}Polinomio;
extern double secanti(const Polinomio* p, double x0, double x1, double t, int max_iter);
#endif // !defined SEC
