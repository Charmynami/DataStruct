//
// Created by wangy on 2026/4/21.
//

#ifndef SEQUENTIALLIST_DULLIST_H
#define SEQUENTIALLIST_DULLIST_H

#endif //SEQUENTIALLIST_DULLIST_H

#define OK 1
#define ERROR 0
#define OVERFLOW -1

#ifndef DULLIST_H
#define DULLIST_H

typedef int ElemType;

// 双向节点结构
typedef struct DuLNode {
    ElemType data;
    struct DuLNode* prior;
    struct DuLNode* next;
} DuLNode, *DuLinkList;

// 基本操作（带头结点，头结点的prior指向尾结点，尾结点的next指向头结点）

// 1. 初始化
void InitList(DuLinkList& L);

// 2. 销毁
void DestroyList(DuLinkList& L);

// 3. 清空（保留头结点）
void ClearList(DuLinkList& L);

// 4. 判空
bool ListEmpty(const DuLinkList& L);

// 5. 获取长度
int ListLength(const DuLinkList& L);

// 6. 获取第i个元素
bool GetElem(const DuLinkList& L, int i, ElemType& e);

// 7. 按值查找（返回节点指针）
DuLNode* LocateElem(const DuLinkList& L, ElemType e);

// 8. 按序号查找
DuLNode* GetElemPtr(const DuLinkList& L, int i);

// 9. 前驱
bool PriorElem(const DuLinkList& L, ElemType cur_e, ElemType& pre_e);

// 10. 后继
bool NextElem(const DuLinkList& L, ElemType cur_e, ElemType& next_e);

// 11. 在第i个位置前插入元素
bool ListInsert(DuLinkList& L, int i, ElemType e);

// 12. 头插法
bool ListInsertHead(DuLinkList& L, ElemType e);

// 13. 尾插法
bool ListInsertTail(DuLinkList& L, ElemType e);

// 14. 删除第i个元素
bool ListDelete(DuLinkList& L, int i, ElemType& e);

// 15. 遍历（正向）
void ListTraverse(const DuLinkList& L, void(*visit)(ElemType&));

// 16. 反向遍历
void ListTraverseReverse(const DuLinkList& L, void(*visit)(ElemType&));

// 17. 创建表（后插法）
void CreateListTail(DuLinkList& L, int n, ElemType arr[]);

// 合并两个有序双向循环链表 La 和 Lb（均非递减），结果存入 Lc（带头结点，循环双向）
void MergeDuLinkList(const DuLinkList& La, const DuLinkList& Lb, DuLinkList& Lc);
#endif