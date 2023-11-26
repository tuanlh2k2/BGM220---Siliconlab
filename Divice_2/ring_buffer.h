/*
 * ring_buffer.h
 *
 *  Created on: Aug 14, 2023
 *      Author: Wind
 */

#ifndef RING_BUFFER_H_
#define RING_BUFFER_H_

#include <stdint.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define SIZE_OF_DATA 6
enum { MAX_SIZE_RING_BUFFER = 5}; // N elements of the circular buffer
// this is status of ring buffer.
typedef enum {
    RING_BUFFER_ERROR,
    RING_BUFFER_OK
}status_ring_buffer;

// this is type data ring buffer.
typedef struct  __attribute__((__packed__)) {
    uint8_t front;
    uint8_t rear;
    uint8_t data[MAX_SIZE_RING_BUFFER][SIZE_OF_DATA];	// Note that N-1 is the actual capacity, see put function.

}ring_buffer_types;

// this is function use check ring buffer empty.
uint8_t ring_buffer_is_full(ring_buffer_types *queue);

// this is function use check ring buffer full.
uint8_t ring_buffer_is_full(ring_buffer_types *queue);

// this is function use push data in ring buffer.
status_ring_buffer ring_buffer_push_data(ring_buffer_types *queue, uint8_t *data);

// this is function use pop data out ring buffer.
status_ring_buffer ring_buffer_pop_data(ring_buffer_types *queue, uint8_t *data_out);

// this is function use show data.
void ring_buffer_show_data(ring_buffer_types *queue);


#endif /* RING_BUFFER_H_ */
