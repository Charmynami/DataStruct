#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#define OK 1
#define ERROR 0
#define OVERFLOW -1

typedef int ElemType;

// 单链表节点结构
typedef struct LNode {
    ElemType data;
    struct LNode* next;
} LNode, *LinkList;

// 基本操作函数声明

// 1. 初始化（带头节点）
void InitList(LinkList& L);

// 2. 销毁
void DestroyList(LinkList& L);

// 3. 清空（保留头节点）
void ClearList(LinkList& L);

// 4. 判空
bool ListEmpty(const LinkList& L);

// 5. 获取长度
int ListLength(const LinkList& L);

// 6. 获取元素
bool GetElem(const LinkList& L, int i, ElemType& e);

// 7. 查找（按值）
LNode* LocateElem(const LinkList& L, ElemType e);

// 8. 按序号查找
LNode* GetElemPtr(const LinkList& L, int i);

// 9. 前驱
bool PriorElem(const LinkList& L, ElemType cur_e, ElemType& pre_e);

// 10. 后继
bool NextElem(const LinkList& L, ElemType cur_e, ElemType& next_e);

// 11. 插入（在第i个位置前插入）
bool ListInsert(LinkList& L, int i, ElemType e);

// 12. 头插法
bool ListInsertHead(LinkList& L, ElemType e);

// 13. 尾插法
bool ListInsertTail(LinkList& L, ElemType e);

// 14. 删除
bool ListDelete(LinkList& L, int i, ElemType& e);

// 15. 遍历
void ListTraverse(const LinkList& L, void(*visit)(ElemType&));

// 16. 创建（前插法）
void CreateListHead(LinkList& L, int n, ElemType arr[]);

// 17. 创建（后插法）
void CreateListTail(LinkList& L, int n, ElemType arr[]);

// 18. 合并有序链表
void MergeList(const LinkList& La, const LinkList& Lb, LinkList& Lc);

// 合并两个有序单链表 La 和 Lb（均非递减），结果存入 Lc（带头结点，新链表）
void MergeLinkList(const LinkList& La, const LinkList& Lb, LinkList& Lc);
#endif