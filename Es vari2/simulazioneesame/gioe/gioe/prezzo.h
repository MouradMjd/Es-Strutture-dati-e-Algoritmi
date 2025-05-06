#if !defined G_H
#define G_H
struct Articolo {
    char nome[11];
    int prezzo;
};

extern void TrovaArticoli(const struct Articolo* a, size_t a_size, int sum);

#endif // !defined G_H
