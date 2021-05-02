typedef struct {
    int* arr;
    int size;
    int front;
    int tail;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* tmp = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    tmp->arr = (int*)malloc(sizeof(int) * (k + 1));
    tmp->front = tmp->tail = 0;
    tmp->size = k;
    return tmp;
}
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    if (obj->tail == obj->front)
        return true;
    return false;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    if ((obj->tail + 1) % (obj->size + 1) == obj->front)
        return true;
    return false;
}
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (myCircularQueueIsFull(obj))
        return false;
    obj->arr[obj->tail] = value;
    // if(obj->tail==obj->size+1)
    //     obj->tail=0;
    obj->tail = (obj->tail + 1) % (obj->size + 1);
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return false;
    //obj->front = (obj->front + 1) % (obj->size + 1);
    obj->front++;
    if (obj->front == obj->size + 1)
        obj->front = 0;
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return -1;
    return obj->arr[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return -1;
    int tailprev = obj->tail;
    if (tailprev == 0)
        tailprev = obj->size + 1;
    return obj->arr[tailprev - 1];
}


void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->arr);
    obj->tail = NULL;
    free(obj);
    obj = NULL;
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);

 * bool param_2 = myCircularQueueDeQueue(obj);

 * int param_3 = myCircularQueueFront(obj);

 * int param_4 = myCircularQueueRear(obj);

 * bool param_5 = myCircularQueueIsEmpty(obj);

 * bool param_6 = myCircularQueueIsFull(obj);

 * myCircularQueueFree(obj);
*/