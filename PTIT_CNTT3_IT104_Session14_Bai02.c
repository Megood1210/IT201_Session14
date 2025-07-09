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
        printf("Ngan xep dang rong!\n");
        return;
    }

    printf("Cac phan tu trong Stack (LIFO):\n");
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

// Hàm thêm 1 phần tử do người dùng nhập
Node* addStack(Node* top) {
    // Nhập phần tử trong stack
    int value;
    do {
        printf("Nhap mot so nguyen duong: ");
        scanf("%d", &value);
        // Kiểm tra phần tử không nguyên dương
        if (value <= 0)
            printf("Vui long nhap so nguyen duong!\n");
    } while (value <= 0);
    // Thêm phần tử
    top = push(value, top);
    return top; // Trả về đầu stack
}

// Hàm main
int main(){
    Node* stack = initialStack(); // Khởi tạo Stack

    // Thêm một số phần tử ban đầu
    stack = push(5, stack);
    stack = push(4, stack);
    stack = push(3, stack);
    stack = push(2, stack);
    stack = push(1, stack);

    int n;
    printf("Nhap so luong phan tu muon them: ");
    scanf("%d", &n);

    if (n < 1) {
        printf("Khong co phan tu nao duoc them\n");
    } else {
        for (int i = 0; i < n; i++) {
            printf("Phan tu thu %d:\n", i + 1);
            stack = addStack(stack);
        }
    }

    printStack(stack);     // In Stack
    freeStack(stack);      // Giải phóng bộ nhớ

    return 0;
}