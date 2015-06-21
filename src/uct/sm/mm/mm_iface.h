/**
 * Copyright (c) UT-Battelle, LLC. 2014-2015. ALL RIGHTS RESERVED.
 * Copyright (C) Mellanox Technologies Ltd. 2001-2015.  ALL RIGHTS RESERVED.
 * $COPYRIGHT$
 * $HEADER$
 */

#ifndef UCT_MM_IFACE_H
#define UCT_MM_IFACE_H

#include <uct/tl/tl_base.h>


typedef struct uct_mm_iface {
    uct_base_iface_t        super;
    struct {
        unsigned            max_put;
        unsigned            max_bcopy;
        unsigned            max_zcopy;
    } config;
} uct_mm_iface_t;

/* to make it visible to derived classes */
UCS_CLASS_DECLARE(uct_mm_iface_t, uct_iface_ops_t *, uct_pd_h, uct_worker_h,
                  const uct_iface_config_t *)


typedef struct uct_mm_iface_config {
    uct_iface_config_t      super;
} uct_mm_iface_config_t;


extern ucs_config_field_t uct_mm_iface_config_table[];


void uct_mm_iface_get_address(uct_mm_iface_t *iface,
                              uct_sockaddr_process_t *iface_addr);
int uct_mm_iface_is_reachable(uct_iface_t *tl_iface,
                              const struct sockaddr *addr);
ucs_status_t uct_mm_iface_query(uct_iface_h, uct_iface_attr_t *);
ucs_status_t uct_mm_iface_flush(uct_iface_h);

#endif
