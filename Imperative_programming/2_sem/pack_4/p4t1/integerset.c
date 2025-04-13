#include "integerset.h"
#include <stdlib.h>


typedef struct Node {
    int value;
    struct Node* next;
} Node;


struct IntegerSet {
    Node** table; 
    int size;     
};


static unsigned int gethash(int n, int table_size) {
    unsigned int val = (unsigned int)n;
    return val % table_size;
}


static Node* crnode(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (node) {
        node->value = value;
        node->next = NULL;
    }
    return node;
}


static int dupl(const int* arr, int size) {
    if (size <= 1) return 0;
    
    
    const int temp_size = size * 2; 
    Node** temp_table = (Node**)calloc(temp_size, sizeof(Node*));
    if (!temp_table) return 1; 
    
    for (int i = 0; i < size; i++) {
        unsigned int h = gethash(arr[i], temp_size);
        Node* curr = temp_table[h];
        
        
        while (curr) {
            if (curr->value == arr[i]) {
                for (int j = 0; j < temp_size; j++) {
                    Node* n = temp_table[j];
                    while (n) {
                        Node* next = n->next;
                        free(n);
                        n = next;
                    }
                }
                free(temp_table);
                return 1; 
            }
            curr = curr->next;
        }
        
        
        Node* new_node = crnode(arr[i]);
        if (!new_node) {
            for (int j = 0; j < temp_size; j++) {
                Node* n = temp_table[j];
                while (n) {
                    Node* next = n->next;
                    free(n);
                    n = next;
                }
            }
            free(temp_table);
            return 1; 
        }
        new_node->next = temp_table[h];
        temp_table[h] = new_node;
    }
    
    
    for (int i = 0; i < temp_size; i++) {
        Node* n = temp_table[i];
        while (n) {
            Node* next = n->next;
            free(n);
            n = next;
        }
    }
    free(temp_table);
    return 0; 
}

IntegerSet* CreateSet(const int* arr, int size) {
    if (size < 0) return NULL;
    if (size == 0) {
        IntegerSet* set = (IntegerSet*)malloc(sizeof(IntegerSet));
        if (!set) return NULL;
        set->table = NULL;
        set->size = 0;
        return set;
    }
    if (!arr) return NULL;

    
    if (dupl(arr, size)) return NULL;

    
    int table_size = size * 2; 
    IntegerSet* set = (IntegerSet*)malloc(sizeof(IntegerSet));
    if (!set) return NULL;

    set->table = (Node**)calloc(table_size, sizeof(Node*));
    if (!set->table) {
        free(set);
        return NULL;
    }
    set->size = table_size;

    
    for (int i = 0; i < size; i++) {
        unsigned int h = gethash(arr[i], table_size);
        Node* new_node = crnode(arr[i]);
        if (!new_node) {
            for (int j = 0; j < table_size; j++) {
                Node* n = set->table[j];
                while (n) {
                    Node* next = n->next;
                    free(n);
                    n = next;
                }
            }
            free(set->table);
            free(set);
            return NULL;
        }
        new_node->next = set->table[h];
        set->table[h] = new_node;
    }

    return set;
}

int IsInSet(const IntegerSet* set, int n) {
    if (!set || !set->table) return 0; 

    unsigned int h = gethash(n, set->size);
    Node* curr = set->table[h];
    
    while (curr) {
        if (curr->value == n) return 1;
        curr = curr->next;
    }
    return 0;
}