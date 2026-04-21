#ifndef SEQLIST_H
#define SEQLIST_H

#define LIST_INIT_SIZE 100    // 初始分配量
#define LIST_INCREMENT 10     // 分配增量
#define OK 1
#define ERROR 0
#define OVERFLOW -1

typedef int Status;            // 函数返回值类型
typedef int ElemType;          // 元素类型

typedef struct {
    ElemType* elem;           // 存储空间基址
    int length;               // 当前长度
    int listsize;             // 当前分配的存储容量
} SeqList;

// 基本操作函数声明

// 1. 初始化
void InitList(SeqList& L);

// 2. 销毁线性表
void DestroyList(SeqList& L);

// 3. 清空线性表
void ClearList(SeqList& L);

// 4. 判断是否为空
bool ListEmpty(const SeqList& L);

// 5. 获取表长
int ListLength(const SeqList& L);

// 6. 获取元素
bool GetElem(const SeqList& L, int i, ElemType& e);

// 7. 查找元素
int LocateElem(const SeqList& L, ElemType e);

// 8. 前驱
bool PriorElem(const SeqList& L, ElemType cur_e, ElemType& pre_e);

// 9. 后继
bool NextElem(const SeqList& L, ElemType cur_e, ElemType& next_e);

// 10. 插入
bool ListInsert(SeqList& L, int i, ElemType e);

// 11. 删除
bool ListDelete(SeqList& L, int i);

// 12. 遍历
void ListTraverse(const SeqList& L, void(*visit)(ElemType&));

// 13. 扩容
void IncrementList(SeqList& L);

// 合并两个有序顺序表 La 和 Lb（均非递减），结果存入 Lc（也保持有序）
void MergeSeqList(const SeqList& La, const SeqList& Lb, SeqList& Lc);
#endif