#ifndef VECTOR_H_
#define VECTOR_H_

typedef struct vector {
	int* data;
	int size;
} vector_t, *p_vector_t;

// NOTE: p_vector_t is same with vector_t*

void vector_initialize(p_vector_t vec, int size);
void vector_destroy(p_vector_t vec);

int vector_lookup(const p_vector_t vec, int idx);
void vector_modify(p_vector_t vec, int idx, int data);

void vector_append(p_vector_t vec, int data);
void vector_append_after(p_vector_t vec, int before, int data);

void vector_remove(p_vector_t vec, int idx);

int vector_size(const p_vector_t vec);

#endif // VECTOR_H_
