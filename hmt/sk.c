#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 2560

int i,j;

typedef struct Node {
    char character;
    int frequency;
    struct Node *left, *right;
} Node;

typedef struct MinHeap {
    int size;
    int capacity;
    Node** array;
} MinHeap;

Node* createNode(char character, int frequency) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->character = character;
    newNode->frequency = frequency;
    newNode->left = newNode->right = NULL;
    return newNode;
}

MinHeap* createMinHeap(int capacity) {
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (Node**)malloc(minHeap->capacity * sizeof(Node*));
    return minHeap;
}

void swapNodes(Node** a, Node** b) {
    Node* temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(MinHeap* minHeap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < minHeap->size && minHeap->array[left]->frequency < minHeap->array[smallest]->frequency) {
        smallest = left;
    }

    if (right < minHeap->size && minHeap->array[right]->frequency < minHeap->array[smallest]->frequency) {
        smallest = right;
    }

    if (smallest != index) {
        swapNodes(&minHeap->array[smallest], &minHeap->array[index]);
        minHeapify(minHeap, smallest);
    }
}

Node* extractMin(MinHeap* minHeap) {
    Node* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    minHeap->size--;
    minHeapify(minHeap, 0);
    return temp;
}

void insertMinHeap(MinHeap* minHeap, Node* node) {
    minHeap->size++;
    int i = minHeap->size - 1;

    while (i && node->frequency < minHeap->array[(i - 1) / 2]->frequency) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    minHeap->array[i] = node;
}

MinHeap* buildMinHeap(char characters[], int frequencies[], int size) {
    MinHeap* minHeap = createMinHeap(size);

    for ( i = 0; i < size; ++i) {
        minHeap->array[i] = createNode(characters[i], frequencies[i]);
    }

    minHeap->size = size;

    for ( i = (minHeap->size - 2) / 2; i >= 0; --i) {
        minHeapify(minHeap, i);
    }

    return minHeap;
}

Node* buildHuffmanTree(char characters[], int frequencies[], int size) {
    Node *left, *right, *top;
    MinHeap* minHeap = buildMinHeap(characters, frequencies, size);

    while (minHeap->size != 1) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);

        top = createNode('$', left->frequency + right->frequency);
        top->left = left;
        top->right = right;

        insertMinHeap(minHeap, top);
    }

    Node* root = extractMin(minHeap);
    free(minHeap->array);
    free(minHeap);
    return root;
}

void printCodes(Node* root, char* code, int top) {
    if (root->left) {
        code[top] = '0';
        printCodes(root->left, code, top + 1);
    }

    if (root->right) {
        code[top] = '1';
        printCodes(root->right, code, top + 1);
    }

    if (!root->left && !root->right) {
        code[top] = '\0';
        printf("%c: %s\n", root->character, code);
    }
}

int calculateFrequencies(const char* filename, char characters[], int frequencies[]) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return -1;
    }

    int freq[MAX_CHARS] = {0};
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        freq[(unsigned char)ch]++;
    }
    fclose(file);

    int count = 0;
    for ( i = 0; i < MAX_CHARS; ++i) {
        if (freq[i] > 0) {
            characters[count] = (char)i;
            frequencies[count] = freq[i];
            count++;
        }
    }
    return count;
}

void freeTree(Node* root) {
    if (root) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    char filename[] = "input.txt";
    char characters[MAX_CHARS];
    int frequencies[MAX_CHARS];

    int size = calculateFrequencies(filename, characters, frequencies);
    if (size == -1) {
        return 1;
    }

    Node* root = buildHuffmanTree(characters, frequencies, size);

    char code[MAX_CHARS];
    printf("Huffman Codes:\n");
    printCodes(root, code, 0);

    freeTree(root);
    return 0;
}

