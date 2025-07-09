#include <stdio.h>
#include <stdlib.h>

// Định nghĩa Node của danh sách liên kết (đơn)
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Hàm khởi tạo Stack (ban dầu sẽ là NULL)
Node* initialStack(){
    return NULL;
}

// Thêm phần tử vào đầu Stack
Node* push (int value, Node* top){
    // Cần sử dụng cấp phát bộ nhớ
    Node* newNode = (Node*) malloc(sizeof (Node));

    // Kiểm tra xem bộ nhớ còn đủ để cấp phát không?
    if (newNode == NULL){
        printf("Khong du bo nho de cap phat!");
        exit(1);
    }

    newNode->data = value;
    newNode->next = top;

    // newNode trở thành top mới
    return newNode;
}

// Kiểm tra xe Stack có bị rỗng không
int isEmpty(Node* top){
    return top == NULL;
}

// In ra toàn bộ Stack
void printStack(Node* top){

    if (isEmpty(top)){
        printf("Ngan sep bi rong \n");
        return;
    }

    // Duyệt danh sách
    Node* temp = top;

    while (temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp-> next;
    }

    printf("NULL\n");
    printf("\n");
}

// Hàm giải phóng bộ nhớ
void freeStack(Node* top){
    Node* temp;

    while (top != NULL){
        temp = top;
        top = top->next;
        free(temp); // Giải phóng từng Node
    }
}
// Hàm in ra toàn bộ phần tử có trong ngăn xếp theo đúng thứ tự last in first out
void traverseStack(Node* top){
    // Kiểm tra stack rỗng
    if (isEmpty(top)){
        printf("Ngan xep trong\n");
        return;
    }

    Node* temp = top; // Con trỏ lưu phần tử đầu
    // In phần tử
    while (temp != NULL){
        printf("%d \n", temp->data);
        temp = temp->next;
    }
}
int main(){
    Node* stack = initialStack(); // Khởi tạo ngăn xếp

    printStack(stack); // In stack trước khi thêm
    traverseStack(stack); //// In stack trước khi thêm
    freeStack(stack);  // Giải phóng bộ nhớ

    return 0;
}