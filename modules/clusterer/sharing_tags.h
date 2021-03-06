/*
 * Copyright (C) 2018 OpenSIPS Solutions
 *
 * This file is part of opensips, a free SIP server.
 *
 * opensips is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version
 *
 * opensips is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */


#ifndef _CLUSTERER_SHARING_TAGS_H
#define _CLUSTERER_SHARING_TAGS_H

#include "../../sr_module.h"
#include "../../mi/mi.h"

#include "api.h"

int shtag_modparam_func(modparam_t type, void *val);

int shtag_init_list(void);

void shtag_validate_list(void);

int handle_shtag_active(bin_packet_t *packet, int cluster_id);

int send_shtag_active_info(int c_id, str *tag_name, int node_id);

void shtag_flush_state(int c_id, int node_id);

void shtag_event_handler(int cluster_id, enum clusterer_event ev, int node_id);

struct mi_root *shtag_mi_list(struct mi_root *cmd, void *param);

struct mi_root *shtag_mi_set_active(struct mi_root *cmd, void *param);


/* API functions */
int shtag_get(str *tag_name, int cluster_id);

int shtag_set(str *tag_name, int cluster_id, int new_state);

str** shtag_get_all_active(int c_id);



#endif

