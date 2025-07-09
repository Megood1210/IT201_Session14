#include <stdio.h>
#include <stdlib.h>

// Định nghĩa Node của danh sách liên kết (đơn)
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Khởi tạo Stack rỗng
Node* initialStack(){
    return NULL;
}

// Thêm phần tử vào đầu Stack
Node* push(int value, Node* top){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL){
        printf("Khong du bo nho de cap phat!\n");
        exit(1);
    }

    newNode->data = value;
    newNode->next = top;
    return newNode; // newNode trở thành top mới
}

// Kiểm tra Stack có rỗng không
int isEmpty(Node* top){
    return top == NULL;
}

// Duyệt và in toàn bộ Stack
void printStack(Node* top){
    if (isEmpty(top)){
        printf("Ngan xep trong\n");
        return;
    }

    Node* temp = top;
    while (temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Giải phóng bộ nhớ
void freeStack(Node* top){
    Node* temp;
    while (top != NULL){
        temp = top;
        top = top->next;
        free(temp);
    }
}
//  Hàm lấy phần tử trên cũng
Node* pop(Node* top, int* value){
    if (isEmpty(top)) {
        printf("Ngan xep trong\n");
        *value = -1; // báo giá trị lỗi
        return top;
    }

    Node* temp = top;
    *value = top->data; // lấy giá trị tại top
    top = top->next;
    free(temp); // giải phóng node cũ

    return top; // trả về top mới
}
int main() {
    Node* stack = initialStack(); // Khởi tạo Stack
    // Thêm một số phần tử ban đầu
    stack = push(5, stack);
    stack = push(4, stack);
    stack = push(3, stack);
    stack = push(2, stack);
    stack = push(1, stack);
    printStack(stack); // In stack trước khi lấy
    int value;
    stack = pop(stack, &value); // Lấy và xóa phần tử đầu
    printStack(stack); // In stack sau khi lấy
    freeStack(stack);  // Giải phóng bộ nhớ

    return 0;
}
