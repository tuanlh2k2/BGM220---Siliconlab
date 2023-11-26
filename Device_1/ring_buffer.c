#include "ring_buffer.h"
#include "app_log.h"
// this is function use check ring buffer full.
uint8_t ring_buffer_is_full(ring_buffer_types *queue)
{
	if (queue->front == (queue->rear + 1) || (queue->front == 0 && queue->rear == MAX_SIZE_BUFFER)) {
		return 1;
	}
	return 0;
}

// this is function use check ring buffer empty.
uint8_t ring_buffer_is_empty(ring_buffer_types *queue)
{
	if (queue->front == queue->rear) {
		return 1;
	}
	return 0;
}

// this is function use push data in ring buffer.
status_ring_buffer ring_buffer_push_data(ring_buffer_types *queue, uint8_t *data)
{
	if (!ring_buffer_is_full(queue)) {
		for (int i = 0; i < 6; i++) {
			queue->data[queue->rear][i] = data[i];
		}
		queue->rear = (queue->rear + 1) % (MAX_SIZE_BUFFER + 1);
		return RING_BUFFER_OK;
	}
	return RING_BUFFER_ERROR;
}

// this is function use pop data out ring buffer.
uint8_t *ring_buffer_pop_data(ring_buffer_types *queue)
{
	if (!ring_buffer_is_empty(queue)) {
		uint8_t *data_out = queue->data[queue->front];
		queue->front = (queue->front + 1) % (MAX_SIZE_BUFFER + 1);
		return data_out;
	} else {
		return NULL;
	}
}
