//
// Created by wangy on 2026/4/9.
//

#include "SeqList.h"
#include <iostream>
using namespace std;

// #define LIST_INIT_SIZE 100    // 初始分配量
// #define LIST_INCREMENT 10     // 分配增量
// #define OK 1
// #define ERROR 0
// #define OVERFLOW -1
//
// typedef int Status;            // 函数返回值类型
// typedef int ElemType;          // 元素类型
//
// typedef struct {
//     ElemType* elem;           // 存储空间基址
//     int length;               // 当前长度
//     int listsize;             // 当前分配的存储容量
// } SeqList;

// 1. 初始化
void InitList(SeqList& L) {
    L.elem = new (std::nothrow) ElemType[LIST_INIT_SIZE];
    if (!L.elem) {
        cout << "Memory allocation failed" << endl;
        exit(ERROR);
    }else {
        cout << "Initialization successful" << endl;
        L.length = 0;
        L.listsize = LIST_INIT_SIZE;
    }
}

// 2. 销毁线性表
void DestroyList(SeqList& L) {
    delete []L.elem;
    L.elem = nullptr;
    L.length = 0;
    L.listsize = 0;
    cout << "Destruction successful" << endl;
}

// 3. 清空线性表
void ClearList(SeqList& L) {
    L.length = 0;
    cout << "Clear successful" << endl;
}

// 4. 判断是否为空
bool ListEmpty(const SeqList& L) {
    return L.length == 0;
}

// 5. 获取表长
int ListLength(const SeqList& L) {
    return L.length;
}

// 6. 获取元素
bool GetElem(const SeqList& L, int i, ElemType& e) {
    if (i < 1 || i > L.length)return ERROR;// 越界检查
    e = L.elem[i-1];// 数组索引从0开始
    return OK; // 元素获取成功
}

// 7. 查找元素
int LocateElem(const SeqList& L, ElemType e) {
    for (int i = 0; i < L.length; i++) {
        if (L.elem[i] == e) {
            return i+1;
        }
    }
    return ERROR; // 元素未找到
}

// 8. 前驱
bool PriorElem(const SeqList& L, ElemType cur_e, ElemType& pre_e) {
    if (L.length == 0) return ERROR;  // 空表无前驱

    // 从第二个元素开始查找(第一个元素没有前驱)
    for (int i = 1; i < L.length; i++) {
        if (L.elem[i] == cur_e) {
            pre_e = L.elem[i - 1];  // 找到后返回前一个元素
            return OK;
        }
    }

    return ERROR;  // 未找到该元素或该元素是第一个元素

}

// 9. 后继
bool NextElem(const SeqList& L, ElemType cur_e, ElemType& next_e) {
    // (最后一个元素没有后继)末尾检查
    if (L.length == 0) return ERROR;  // 空表无后继

    for (int i = 0; i < L.length; i++) {
        if (i == L.length - 1)
            return ERROR;// 末尾检查：最后一个元素没有后继
        if (L.elem[i] == cur_e) {
            next_e = L.elem[i + 1];  // 找到后返回后一个元素
            return OK;
        }
    }
    return ERROR;  // 未找到该元素或该元素是最后一个元素
}

// 10. 插入
bool ListInsert(SeqList& L, int i, ElemType e) {
    // 越界检查
    if (i < 1 || i > L.length + 1) return ERROR;
    // 容量检查
    if (L.length == L.listsize) {
        cout << "Expansion failed: insufficient memory" << endl;
        return ERROR;
    }
    // 插入
    for (int j = L.length; j >= i; j--) {
        L.elem[j]=L.elem[j-1];
    }
    L.elem[i-1]=e;
    L.length++;
    return OK;
}

// 11. 删除
bool ListDelete(SeqList& L, int i) {
    // 越界检查
    if (i<1 || i>L.length) return ERROR;
    // 删除
    for (int j=i-1;j<L.length;j++) {
        L.elem[j]=L.elem[j+1];
    }
    L.length--;
    cout << "Delete successful" << endl;
    return OK;
}

// 12. 遍历
void ListTraverse(const SeqList& L, void(*visit)(ElemType&)) {
    for (int i=0;i<L.length;i++) {
        visit(L.elem[i]);
    }
}

// 13. 扩容
void IncrementList(SeqList& L) {
    auto* new_elem = new (std::nothrow) ElemType[L.listsize+LIST_INCREMENT];
    if (!new_elem) {
        cout << "Expansion failed: insufficient memory" << endl;
        exit(ERROR);
    }
    for (int i=0;i<L.length;i++) {
        new_elem[i]=L.elem[i];
    }
    delete []L.elem;
    L.elem=new_elem;
    L.listsize+=LIST_INCREMENT;
    cout << "Expansion successful" << endl;
}