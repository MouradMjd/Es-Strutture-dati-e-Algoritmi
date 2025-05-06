#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void BabboNataleRec(const int *pacchi, size_t pacchi_size, int p, bool* selected_gifts, size_t i, size_t cnt, size_t *max, bool* max_gifts, size_t *number_of_calls) {
	int total_weight = 0;
	for(size_t j = 0; j < i; j++) {
		if (selected_gifts[j]) {
			total_weight += pacchi[j];
		}
	}
	
	if (total_weight > p || cnt + (pacchi_size - i - 1) < *max) {
		return;
	}

	
	if (total_weight == p ) {
		memcpy(max_gifts, selected_gifts, sizeof(bool) * pacchi_size);
		*max = cnt;
		return;
	}
	
	if (cnt>*max) {
		memcpy(max_gifts, selected_gifts, sizeof(bool) * pacchi_size);
		*max = cnt;
		return;
	}



	if (i == pacchi_size) {
		return;
	}
	
	selected_gifts[i] = 0;
	(*number_of_calls) += 1;
	BabboNataleRec(pacchi, pacchi_size, p, selected_gifts, i+1, cnt, max, max_gifts, number_of_calls);

	selected_gifts[i] = 1;
	(*number_of_calls) += 1;
	BabboNataleRec(pacchi, pacchi_size, p, selected_gifts, i+1, cnt+1, max, max_gifts, number_of_calls);

	selected_gifts[i] = 0;
}

void BabboNatale(const int* pacchi, size_t pacchi_size, int p) {
	if (pacchi == NULL || p < 0) {
		return;
	}
	bool* selected_gifts = calloc(pacchi_size, sizeof(bool));
	bool* max_gifts = calloc(pacchi_size, sizeof(bool));
	size_t number_of_calls = 1;
	
	BabboNataleRec(pacchi, pacchi_size, p, selected_gifts, 0, 0, &max, max_gifts, &number_of_calls);
	if (max_gifts != 0) {
		for (size_t i = 0; i < pacchi_size; i++) {
			printf("%i ", max_gifts[i]);
		}
	}
	printf("\nCalls: %zi", number_of_calls);
	free(selected_gifts);
	free(max_gifts);
	return;
}