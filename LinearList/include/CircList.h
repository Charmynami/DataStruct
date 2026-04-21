//
// Created by wangy on 2026/4/21.
//

#ifndef SEQUENTIALLIST_CIRCLIST_H
#define SEQUENTIALLIST_CIRCLIST_H

#endif //SEQUENTIALLIST_CIRCLIST_H

#define OK 1
#define ERROR 0
#define OVERFLOW -1

#ifndef CIRCLIST_H
#define CIRCLIST_H

typedef int ElemType;

// 节点结构（同单链表）
typedef struct CNode {
    ElemType data;
    struct CNode* next;
} CNode, *CircList;

// 基本操作（带头结点，尾结点指向头结点）

// 1. 初始化（创建头结点，自己指向自己）
void InitList(CircList& L);

// 2. 销毁（释放所有节点）
void DestroyList(CircList& L);

// 3. 清空（保留头结点）
void ClearList(CircList& L);

// 4. 判空
bool ListEmpty(const CircList& L);

// 5. 获取长度
int ListLength(const CircList& L);

// 6. 获取第i个元素的值
bool GetElem(const CircList& L, int i, ElemType& e);

// 7. 按值查找（返回节点指针）
CNode* LocateElem(const CircList& L, ElemType e);

// 8. 按序号查找（返回节点指针）
CNode* GetElemPtr(const CircList& L, int i);

// 9. 前驱
bool PriorElem(const CircList& L, ElemType cur_e, ElemType& pre_e);

// 10. 后继
bool NextElem(const CircList& L, ElemType cur_e, ElemType& next_e);

// 11. 在第i个位置前插入元素
bool ListInsert(CircList& L, int i, ElemType e);

// 12. 头插法（插入到头结点之后）
bool ListInsertHead(CircList& L, ElemType e);

// 13. 尾插法（插入到表尾，即头结点之前）
bool ListInsertTail(CircList& L, ElemType e);

// 14. 删除第i个元素
bool ListDelete(CircList& L, int i, ElemType& e);

// 15. 遍历（从第一个节点开始）
void ListTraverse(const CircList& L, void(*visit)(ElemType&));

// 16. 创建表（后插法，数组输入）
void CreateListTail(CircList& L, int n, ElemType arr[]);

// 合并两个有序循环链表 La 和 Lb（均非递减），结果存入 Lc（带头结点，循环）
void MergeCircList(const CircList& La, const CircList& Lb, CircList& Lc);
#endif