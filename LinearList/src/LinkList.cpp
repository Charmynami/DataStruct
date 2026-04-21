//
// Created by wangy on 2026/4/9.
//
#include "LinkList.h"
#include <iostream>
using namespace std;
// typedef int ElemType;
// // 单链表节点结构
// typedef struct LNode {
//     ElemType data;
//     struct LNode* next;
// } LNode, *LinkList;

// 基本操作函数声明

// 1. 初始化（带头节点）
void InitList(LinkList& L) {
    //检查头节点是否已存在
    if (L != nullptr) {
        DestroyList(L);  // 先销毁旧的
    }
    L=new (std::nothrow) LNode;
    if (!L) {
        cout << "Memory allocation failed" << endl;
        exit(ERROR);
    }
    L->next=nullptr;
    L->data = ElemType{};//初始化数据域为空，头节点数据域无实际意义，仅作为占位符，表示链表的起始位置。
}

// 2. 销毁
void DestroyList(LinkList& L) {
    // 释放所有节点
    if (!L) return;
    LinkList p=L;//指向头节点
    LinkList q=nullptr;//临时节点
    while ( p) {
        q=p->next;
        delete p;
        p=q;
    }
    L=nullptr;
    cout << "DestroyList Successful" << endl;
}

// 3. 清空（保留头节点）
void ClearList(LinkList& L) {
    //初始条件：表不为空
    if (!L) return;
    LinkList p=L->next;//指向首元节点
    LinkList q=nullptr;
    while (p) {
        q=p->next;
        delete p;
        p=q;
    }
    L->next=nullptr;
    cout << "ClearList Successful" << endl;
}

// 4. 判空
bool ListEmpty(const LinkList& L) {
    if (!L)return ERROR;
    return L->next==nullptr;//头节点的next为空，则链表为空
}

// 5. 获取长度
int ListLength(const LinkList& L) {
    if (!L) return ERROR;
    int len=0;
    LinkList p=L->next;
    while (p) {
        ++len;
        p=p->next;
    }
    return len;
}

// 6. 获取元素
bool GetElem(const LinkList& L, int i, ElemType& e) {
    // 越界检查
    if (!L)return ERROR;
    if (i<1 || i>ListLength(L))
        return ERROR;

    LinkList p=L->next;
    while (--i) {
        p=p->next;
    }
    e=p->data;
    cout << "GetElem Successful" << endl;
    return true;
}

// 7. 查找（按值）
LNode* LocateElem(const LinkList& L, ElemType e) {
    LinkList p=L->next;
    while ( p) {
        if (p->data==e) {
            cout << "LocateElem Successful" << endl;
            return p;
        }
        p=p->next;//我忘记移动指针了，这是非常容易出错的地方，一定要注意。
    }
    cout << "LocateElem Failed" << endl;
    return nullptr;

}

// 8. 按序号查找
LNode* GetElemPtr(const LinkList& L, int i) {
    //忘记检查合法性
    if (!L) return ERROR;
    if (i<1 || i>ListLength(L))return ERROR ;
    LinkList p=L->next;
    while (--i) {
        p=p->next;
    }
    cout << "GetElemPtr Successful" << endl;
    return p;
}

// 9. 前驱：有头节点
bool PriorElem(const LinkList& L, ElemType cur_e, ElemType& pre_e) {
    if (!L) return false;
    LinkList p=L->next;
    LinkList q=L;
    while (p) {
        if (p->data==cur_e) {
            pre_e=q->data;
            return true;
        }
        q=p;
        p=p->next;
    }
    cout << "PriorElem Failed" << endl;
    return false;
}

// 10. 后继
bool NextElem(const LinkList& L, ElemType cur_e, ElemType& next_e) {
    if (!L) return false;
    LinkList p=L->next;
    while ( p->next) {
        if (p->data==cur_e) {
            next_e=p->next->data;
            return true;
        }
        p=p->next;
    }
    cout << "NextElem Failed" << endl;
    return false;
}

// 11. 插入（在第i个位置前插入）
bool ListInsert(LinkList& L, int i, ElemType e) {
    //判断插入位置是否合法
    if (i<1 || i>ListLength(L)+1)return ERROR;
    //双指针法
    // LinkList p=L;
    // LinkList q=p->next;
    // while (--i) {
    //     p=p->next;
    //     q=q->next;
    // }
    // LinkList s=new (std::nothrow) LNode;
    // s->data=e;
    // s->next=q;
    // p->next=s;
    // cout << "ListInsert Successful" << endl;
    // 单指针法
    LinkList p=L;
    while (--i) {
        p=p->next;
    }
    LinkList s=new (std::nothrow) LNode;
    s->data=e;
    s->next=p->next;
    p->next=s;
    return true;
}

// 12. 头插法
bool ListInsertHead(LinkList& L, ElemType e) {
    LinkList s=new (std::nothrow) LNode;
    s->data=e;
    s->next=L->next;
    L->next=s;
    return true;
}

// 13. 尾插法
bool ListInsertTail(LinkList& L, ElemType e) {
    //处理链表为空的情况
    LinkList R=L;
    while (R->next) {
        R=R->next;
    }
    LinkList s=new (std::nothrow) LNode;
    s->data=e;
    s->next=nullptr;
    R->next=s;
    return true;
}

// 14. 删除
bool ListDelete(LinkList& L, int i, ElemType& e) {
    // 判断删除位置是否合法
    if (i<1 || i>ListLength(L))
        return ERROR;
    LinkList p=L;//指向头节点，用来寻找待删除的节点的前一个节点
    while (--i) {
        p=p->next;
    }
    LinkList q=p->next;//待删除的节点
    e=q->data;
    p->next=q->next;
    delete q;
    cout << "ListDelete Successful" << endl;
    return true;
}

// 15. 遍历
void ListTraverse(const LinkList& L, void(*visit)(ElemType&)) {
    if (!L) return;
    LinkList p=L->next;
    while (p) {
        visit(p->data);
        p=p->next;
    }
}

// 16. 创建（前插法）
void CreateListHead(LinkList& L, int n, ElemType arr[]) {
    InitList( L);
    while (n--) {
        LinkList s=new (std::nothrow) LNode;
        s->data=arr[n];
        s->next=L->next;
        L->next=s;
    }
    cout << "CreateListHead Successful" << endl;
}

// 17. 创建（后插法）
void CreateListTail(LinkList& L, int n, ElemType arr[]) {
    InitList( L);
    LinkList p=L;
    for (int i=0; i<n; i++){
        LinkList s=new (std::nothrow) LNode;
        s->data=arr[i];
        s->next=nullptr;
        p->next=s;
        p=s;//更新尾指针
    }
    p->next=nullptr;
    cout << "CreateListTail Successful" << endl;
}

// 18. 合并有序链表：链表都有头节点
void MergeList(const LinkList& La, const LinkList& Lb, LinkList& Lc) {
    LinkList p=La->next;
    LinkList q=Lb->next;

    InitList( Lc);
    LinkList r=Lc;
    while (p && q) {
        if (p->data<=q->data) {
            r->next=p;
            r=r->next;
            p=p->next;
        }else {
            r->next=q;
            r=r->next;
            q=q->next;
        }
    }

    if (p) {
        r->next=p;
    }
    if (q) {
        r->next=q;
    }
    cout << "MergeList Successful" << endl;
}