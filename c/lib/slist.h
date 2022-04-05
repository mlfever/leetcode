/*
 * single list struct
 */

#ifndef NULL
#define NULL (void *)0
#endif

typedef struct slist
{
    struct slist *next;
} slist_t;

typedef struct slist_head
{
    slist_t *pre;
    slist_t *next;
} slist_head_t;

static inline void slist_head_init(slist_head_t *head)
{
    head->pre = (slist_t *)NULL;
    head->next = (slist_t *)NULL;
}

static inline void slist_add_head(slist_head_t *head, slist_t *node)
{
    node->next = head->next;
    head->next = node;
}

static inline void slist_add_tail(slist_head_t *head, slist_t *node)
{
    node->next = (slist_t *)NULL;
    head->pre->next = node;
    head->pre = node;
}

static inline void slist_head_init(slist_head_t *head);
static inline void slist_add_head(slist_head_t *head, slist_t *node);
static inline void slist_add_tail(slist_head_t *head, slist_t *node);