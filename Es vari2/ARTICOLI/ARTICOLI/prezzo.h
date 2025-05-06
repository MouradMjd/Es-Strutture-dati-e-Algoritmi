#if !defined prezzo_h
#define prezzo_h

struct Articolo {
	char nome[11];
	int prezzo;
};


extern void Trovaarticoli(const struct Articolo* a, size_t size_a, int sum);

#endif 

  