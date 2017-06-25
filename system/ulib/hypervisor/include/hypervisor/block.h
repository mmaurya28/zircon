// Copyright 2017 The Fuchsia Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#pragma once

#include <magenta/syscalls/hypervisor.h>

#define SECTOR_SIZE     0x200   // Sector size, 512 bytes

typedef struct virtio_queue virtio_queue_t;
typedef struct vcpu_context vcpu_context_t;

mx_status_t handle_virtio_block_read(uint16_t port, uint8_t* input_size,
                                     mx_guest_port_in_ret_t* port_in_ret);
mx_status_t handle_virtio_block_write(vcpu_context_t* context, uint16_t port,
                                      const mx_guest_port_out_t* port_out);

mx_status_t null_block_device(void* mem_addr, size_t mem_size, virtio_queue_t* queue);
