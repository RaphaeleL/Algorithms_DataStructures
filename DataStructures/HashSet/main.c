#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_HASH_SET_CAPACITY 1 << 10

typedef struct {
  unsigned capacity;
  unsigned length;
  void **values;
  void **keys;
} hash_set_t;

extern hash_set_t *init_hash_set() {
  hash_set_t *set = (hash_set_t *)malloc(sizeof(hash_set_t));
  set->keys = calloc(DEFAULT_HASH_SET_CAPACITY, sizeof(void **));
  set->values = calloc(DEFAULT_HASH_SET_CAPACITY, sizeof(void **));
  set->length = 0;
  set->capacity = DEFAULT_HASH_SET_CAPACITY;

  return set;
}

unsigned add(hash_set_t *set, void *value) {
  return put(set, hash(value), value);
}

unsigned put(hash_set_t *set, long long hash, void *value) {
  if (contains_hash(set, hash)) {
    if (set->keys[retrieve_index_from_hash(hash, set->capacity)] == value) {
      return 0;
    }

    resize(set);

    return put(set, hash, value);
  }

  set->keys[retrieve_index_from_hash(hash, set->capacity)] = value;
  set->values[set->length++] = value;

  return 1;
}

int contains(hash_set_t *set, void *value) {
  return set->keys[retrieve_index_from_hash(hash(value), set->capacity)] ==
                 value
             ? 1
             : 0;
}

int contains_hash(hash_set_t *set, long long hash) {
  return set->keys[retrieve_index_from_hash(hash, set->capacity)] ? 1 : 0;
}

void delete (hash_set_t *set, void *value) {
  set->keys[retrieve_index_from_hash(hash(value), set->capacity)] = NULL;
}

// adler_32 hash
long long hash(void *value) {
  char *str = value;

  int a = 1;
  int b = 0;
  const int MODADLER = 65521;

  for (int i = 0; str[i] != '\0'; i++) {
    a = (a + str[i]) % MODADLER;
    b = (b + a) % MODADLER;
  }

  return (b << 16) | a;
}

unsigned retrieve_index_from_hash(const long long hash,
                                  const unsigned capacity) {
  return (capacity - 1) & (hash ^ (hash >> 12));
}

void resize(hash_set_t *set) {
  void **keys_resized = calloc((set->capacity <<= 1), sizeof(void **));

  for (int i = 0; i < set->length; i++) {
    keys_resized[retrieve_index_from_hash(hash(set->values[i]),
                                          set->capacity)] = set->values[i];
  }

  free(set->keys);

  set->keys = keys_resized;

  void **new_values =
      (void **)realloc(set->values, set->capacity * sizeof(void **));
  set->values = new_values;
}

int main() {
  hash_set_t *set = init_hash_set();

  int v1 = 10, v2 = 20, v3 = 30, v4 = 40, v5 = 50, v6 = 60, v7 = 70;

  printf("Value %d was add? %d\n", v1, add(set, &v1));
  printf("Value %d was add? %d\n", v1, add(set, &v1));
  printf("contains %d? %d\n", v1, contains(set, &v1));

  printf("Value %d was add? %d\n", v2, add(set, &v2));
  printf("Value %d was add? %d\n", v2, add(set, &v2));
  printf("contains %d? %d\n", v2, contains(set, &v2));

  printf("Value %d was add? %d\n", v3, add(set, &v3));
  printf("Value %d is add? %d\n", v3, add(set, &v3));
  printf("contains %d? %d\n", v3, contains(set, &v3));

  printf("Value %d was add? %d\n", v4, add(set, &v4));
  printf("Value %d was add? %d\n", v4, add(set, &v4));
  printf("contains %d? %d\n", v4, contains(set, &v4));

  printf("Value %d was add? %d\n", v5, add(set, &v5));
  printf("Value %d was add? %d\n", v5, add(set, &v5));
  printf("contains %d? %d\n", v5, contains(set, &v5));

  printf("Value %d is add? %d\n", v6, add(set, &v6));
  printf("Value %d is add? %d\n", v6, add(set, &v6));
  printf("contains %d? %d\n", v6, contains(set, &v6));

  printf("contains %d? %d\n", v7, contains(set, &v7));

  delete (set, &v6);

  printf("contains %d? %d\n", v6, contains(set, &v6));

  return 0;
}
