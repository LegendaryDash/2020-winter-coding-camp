#include <stdio.h>
#include <assert.h>

#include "vector.h"

int main()
{
	vector_t v1;

	vector_initialize(&v1, 10);
	assert(vector_size(&v1) == 0);

	for (int i = 0; i < 10; ++i) {
		vector_append(&v1, i);
	}
	for (int i = 0; i < 10; ++i) {
		assert(i == vector_lookup(&v1, i));
	}
	assert(vector_size(&v1) == 10);

	int before = 2;
	int new_data = 3;
	vector_append_after(&v1, before, new_data);

	int where = 0;
	int modifying_data = 88;
	vector_modify(&v1, where, modifying_data);

	int len = vector_size(&v1);
	assert(len == 11);

	assert(88 == vector_lookup(&v1, 0));
	assert(1 == vector_lookup(&v1, 1));
	assert(2 == vector_lookup(&v1, 3));

	for (int i = 3; i < len; ++i) {
		assert(i-1 == vector_lookup(&v1, i));
	}

	int target = 9;
	vector_remove(&v1, target);

	len = vector_size(&v1);
	assert(len == 10);

	assert(88 == vector_lookup(&v1, 0));
	assert(1 == vector_lookup(&v1, 1));
	assert(2 == vector_lookup(&v1, 3));

	for (int i = 3; i < 9; ++i) {
		assert(i-1 == vector_lookup(&v1, i));
	}
	for (int i = 9; i < len; ++i) {
		assert(i == vector_lookup(&v1, i));
	}

	vector_destroy(&v1);

	return 0;
}
