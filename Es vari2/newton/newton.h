
#if !defined New
#define New
typedef struct {
	int* coeff;
	size_t size;
}Polinomio;
extern double newton(const Polinomio* p, const Polinomio* d, double xn, double t, int max_iter);
#endif // !defined New
