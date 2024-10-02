//https://pythontutor.com/visualize.html#code=%23include%20%3Cstdio.h%3E%0A%0A%23define%20MAX%208%0A%0Atypedef%20enum%20%7B%20TRUE,%20FALSE%20%7D%20Boolean%3B%0A%0Astruct%20cell%20%7B%0A%20%20%20%20char%20elems%5BMAX%5D%3B%0A%20%20%20%20int%20front,%20rear%3B%0A%7D%3B%0A%0Avoid%20initCQueue%28struct%20cell%20*Q%29%3B%0ABoolean%20isEmpty%28struct%20cell%20Q%29%3B%0ABoolean%20isFull%28struct%20cell%20Q%29%3B%0Achar%20front%28struct%20cell%20Q%29%3B%0ABoolean%20enQueue%28struct%20cell%20*Q,%20char%20x%29%3B%0ABoolean%20deQueue%28struct%20cell%20*Q%29%3B%0A%0Aint%20main%28%29%20%7B%0A%20%20%20%20struct%20cell%20Q%3B%0A%20%20%20%20%0A%20%20%20%20//%20Initialize%20the%20queue%0A%20%20%20%20initCQueue%28%26Q%29%3B%0A%20%20%20%20%0A%20%20%20%20printf%28%22Initial%20state%3A%5Cn%22%29%3B%0A%20%20%20%20printf%28%22Front%3A%20%25d,%20Rear%3A%20%25d%5Cn%22,%20Q.front,%20Q.rear%29%3B%0A%20%20%20%20%0A%20%20%20%20//%20Enqueue%20elements%0A%20%20%20%20deQueue%28%26Q%29%3B%0A%20%20%20%20enQueue%28%26Q,%20'A'%29%3B%0A%20%20%20%20enQueue%28%26Q,%20'B'%29%3B%0A%20%20%20%20enQueue%28%26Q,%20'C'%29%3B%0A%20%20%20%20enQueue%28%26Q,%20'D'%29%3B%0A%20%20%20%20enQueue%28%26Q,%20'E'%29%3B%0A%20%20%20%20enQueue%28%26Q,%20'F'%29%3B%0A%20%20%20%20enQueue%28%26Q,%20'G'%29%3B%0A%20%20%20%20enQueue%28%26Q,%20'U'%29%3B%0A%20%20%20%20deQueue%28%26Q%29%3B%0A%20%20%20%20deQueue%28%26Q%29%3B%0A%20%20%20%20enQueue%28%26Q,%20'U'%29%3B%0A%20%20%20%20enQueue%28%26Q,%20'S'%29%3B%0A%20%20%20%20enQueue%28%26Q,%20'U'%29%3B%0A%20%20%20%20%0A%20%20%20%20printf%28%22%5CnAfter%20enqueueing%3A%5Cn%22%29%3B%0A%20%20%20%20printf%28%22Front%3A%20%25d,%20Rear%3A%20%25d%5Cn%22,%20Q.front,%20Q.rear%29%3B%0A%20%20%20%20printf%28%22Elements%3A%20%22%29%3B%0A%20%20%20%20for%20%28int%20i%20%3D%20Q.front%3B%20i%20!%3D%20Q.rear%3B%20i%20%3D%20%28i%20%2B%201%29%20%25%20MAX%29%20%7B%0A%20%20%20%20%20%20%20%20printf%28%22%25c%20%22,%20Q.elems%5Bi%5D%29%3B%0A%20%20%20%20%7D%0A%20%20%20%20printf%28%22%5Cn%22%29%3B%0A%20%20%20%20%0A%20%20%20%20//%20Dequeue%20elements%0A%20%20%20%20while%20%28!isEmpty%28Q%29%29%20%7B%0A%20%20%20%20%20%20%20%20char%20element%20%3D%20front%28Q%29%3B%0A%20%20%20%20%20%20%20%20printf%28%22Dequeued%3A%20%25c%5Cn%22,%20element%29%3B%0A%20%20%20%20%20%20%20%20deQueue%28%26Q%29%3B%0A%20%20%20%20%20%20%20%20%0A%20%20%20%20%20%20%20%20printf%28%22Front%3A%20%25d,%20Rear%3A%20%25d%5Cn%22,%20Q.front,%20Q.rear%29%3B%0A%20%20%20%20%20%20%20%20printf%28%22Remaining%20elements%3A%20%22%29%3B%0A%20%20%20%20%20%20%20%20for%20%28int%20i%20%3D%20Q.front%3B%20i%20!%3D%20Q.rear%3B%20i%20%3D%20%28i%20%2B%201%29%20%25%20MAX%29%20%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20printf%28%22%25c%20%22,%20Q.elems%5Bi%5D%29%3B%0A%20%20%20%20%20%20%20%20%7D%0A%20%20%20%20%20%20%20%20printf%28%22%5Cn%22%29%3B%0A%20%20%20%20%7D%0A%20%20%20%20%0A%20%20%20%20return%200%3B%0A%7D%0A%0Avoid%20initCQueue%28struct%20cell%20*Q%29%20%7B%0A%20%20%20%20Q-%3Efront%20%3D%200%3B%0A%20%20%20%20Q-%3Erear%20%3D%20MAX%20-%201%3B%0A%7D%0A%0ABoolean%20isEmpty%28struct%20cell%20Q%29%20%7B%0A%20%20%20%20return%20%28%28Q.rear%20%2B%201%29%20%25%20MAX%20%3D%3D%20Q.front%29%20%3F%20TRUE%20%3A%20FALSE%3B%0A%7D%0A%0ABoolean%20isFull%28struct%20cell%20Q%29%20%7B%0A%20%20%20%20return%20%28%28Q.rear%20%2B%202%29%20%25%20MAX%20%3D%3D%20Q.front%29%20%3F%20TRUE%20%3A%20FALSE%3B%0A%7D%0A%0Achar%20front%28struct%20cell%20Q%29%20%7B%0A%20%20%20%20return%20%28%28Q.rear%20%2B%201%29%20%25%20MAX%20!%3D%20Q.front%29%20%3F%20Q.elems%5BQ.front%5D%20%3A%20'%5C0'%3B%0A%7D%0A%0ABoolean%20enQueue%28struct%20cell%20*Q,%20char%20x%29%20%7B%0A%20%20%20%20if%20%28%28Q-%3Erear%20%2B%202%29%20%25%20MAX%20!%3D%20Q-%3Efront%29%20%7B%0A%20%20%20%20%20%20%20%20Q-%3Erear%20%3D%20%28Q-%3Erear%20%2B%201%29%20%25%20MAX%3B%0A%20%20%20%20%20%20%20%20Q-%3Eelems%5BQ-%3Erear%5D%20%3D%20x%3B%0A%20%20%20%20%20%20%20%20return%20TRUE%3B%0A%20%20%20%20%7D%0A%20%20%20%20return%20FALSE%3B%0A%7D%0A%0ABoolean%20deQueue%28struct%20cell%20*Q%29%20%7B%0A%20%20%20%20if%20%28%28Q-%3Erear%20%2B%201%29%20%25%20MAX%20!%3D%20Q-%3Efront%29%20%7B%0A%20%20%20%20%20%20%20%20Q-%3Eelems%5BQ-%3Efront%5D%20%3D%20NULL%3B%0A%20%20%20%20%20%20%20%20Q-%3Efront%20%3D%20%28Q-%3Efront%20%2B%201%29%20%25%20MAX%3B%0A%20%20%20%20%20%20%20%20return%20TRUE%3B%0A%20%20%20%20%7D%0A%20%20%20%20return%20FALSE%3B%0A%7D&cumulative=false&heapPrimitives=nevernest&mode=edit&origin=opt-frontend.js&py=c_gcc9.3.0&rawInputLstJSON=%5B%5D&textReferences=false
#include <stdio.h>

#define MAX 8

typedef enum { TRUE, FALSE } Boolean;

struct cell {
    char elems[MAX];
    int front, rear;
};

void initCQueue(struct cell *Q);
Boolean isEmpty(struct cell Q);
Boolean isFull(struct cell Q);
char front(struct cell Q);
Boolean enQueue(struct cell *Q, char x);
Boolean deQueue(struct cell *Q);

int main() {
    struct cell Q;
    
    // Initialize the queue
    initCQueue(&Q);
    
    printf("Initial state:\n");
    printf("Front: %d, Rear: %d\n", Q.front, Q.rear);
    
    // Enqueue elements
    deQueue(&Q);
    enQueue(&Q, 'A');
    enQueue(&Q, 'B');
    enQueue(&Q, 'C');
    enQueue(&Q, 'D');
    enQueue(&Q, 'E');
    enQueue(&Q, 'F');
    enQueue(&Q, 'G');
    enQueue(&Q, 'U');
    deQueue(&Q);
    deQueue(&Q);
    enQueue(&Q, 'U');
    enQueue(&Q, 'S');
    enQueue(&Q, 'U');
    
    printf("\nAfter enqueueing:\n");
    printf("Front: %d, Rear: %d\n", Q.front, Q.rear);
    printf("Elements: ");
    for (int i = Q.front; i != Q.rear; i = (i + 1) % MAX) {
        printf("%c ", Q.elems[i]);
    }
    printf("\n");
    
    // Dequeue elements
    while (!isEmpty(Q)) {
        char element = front(Q);
        printf("Dequeued: %c\n", element);
        deQueue(&Q);
        
        printf("Front: %d, Rear: %d\n", Q.front, Q.rear);
        printf("Remaining elements: ");
        for (int i = Q.front; i != Q.rear; i = (i + 1) % MAX) {
            printf("%c ", Q.elems[i]);
        }
        printf("\n");
    }
    
    return 0;
}

void initCQueue(struct cell *Q) {
    Q->front = 0;
    Q->rear = MAX - 1;
}

Boolean isEmpty(struct cell Q) {
    return ((Q.rear + 1) % MAX == Q.front) ? TRUE : FALSE;
}

Boolean isFull(struct cell Q) {
    return ((Q.rear + 2) % MAX == Q.front) ? TRUE : FALSE;
}

char front(struct cell Q) {
    return ((Q.rear + 1) % MAX != Q.front) ? Q.elems[Q.front] : '\0';
}

Boolean enQueue(struct cell *Q, char x) {
    if ((Q->rear + 2) % MAX != Q->front) {
        Q->rear = (Q->rear + 1) % MAX;
        Q->elems[Q->rear] = x;
        return TRUE;
    }
    return FALSE;
}

Boolean deQueue(struct cell *Q) {
    if ((Q->rear + 1) % MAX != Q->front) {
        Q->elems[Q->front] = NULL;
        Q->front = (Q->front + 1) % MAX;
        return TRUE;
    }
    return FALSE;
}
