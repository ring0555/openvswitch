#ifndef __LINUX_RCULIST_WRAPPER_H
#define __LINUX_RCULIST_WRAPPER_H

#include <linux/version.h>
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,26)
#include_next <linux/rculist.h>
#else
/* Prior to 2.6.26, the contents of rculist.h were part of list.h. */
#include <linux/list.h>
#endif

#if LINUX_VERSION_CODE < KERNEL_VERSION(2,6,27)
#define hlist_del_init_rcu rpl_hlist_del_init_rcu
static inline void hlist_del_init_rcu(struct hlist_node *n)
{
	if (!hlist_unhashed(n)) {
		__hlist_del(n);
		n->pprev = NULL;
	}
}
#endif

#endif
