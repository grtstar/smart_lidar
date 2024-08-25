// THIS IS AN AUTOMATICALLY GENERATED FILE.  DO NOT MODIFY
// BY HAND!!
//
// Generated by lcm-gen

#ifndef _baofei_message_Rect2d_h
#define _baofei_message_Rect2d_h

#include <stdint.h>
#include <stdlib.h>
#include <lcm/lcm_coretypes.h>
#include <lcm/lcm.h>

#ifdef __cplusplus
extern "C" {
#endif

#include "baofei_message_Grid2d.h"
#include "baofei_message_Grid2d.h"
typedef struct _baofei_message_Rect2d baofei_message_Rect2d;
struct _baofei_message_Rect2d
{
    baofei_message_Grid2d lt;
    baofei_message_Grid2d rb;
};

/**
 * Create a deep copy of a baofei_message_Rect2d.
 * When no longer needed, destroy it with baofei_message_Rect2d_destroy()
 */
baofei_message_Rect2d* baofei_message_Rect2d_copy(const baofei_message_Rect2d* to_copy);

/**
 * Destroy an instance of baofei_message_Rect2d created by baofei_message_Rect2d_copy()
 */
void baofei_message_Rect2d_destroy(baofei_message_Rect2d* to_destroy);

/**
 * Identifies a single subscription.  This is an opaque data type.
 */
typedef struct _baofei_message_Rect2d_subscription_t baofei_message_Rect2d_subscription_t;

/**
 * Prototype for a callback function invoked when a message of type
 * baofei_message_Rect2d is received.
 */
typedef void(*baofei_message_Rect2d_handler_t)(
    const lcm_recv_buf_t *rbuf, const char *channel,
    const baofei_message_Rect2d *msg, void *userdata);

/**
 * Publish a message of type baofei_message_Rect2d using LCM.
 *
 * @param lcm The LCM instance to publish with.
 * @param channel The channel to publish on.
 * @param msg The message to publish.
 * @return 0 on success, <0 on error.  Success means LCM has transferred
 * responsibility of the message data to the OS.
 */
int baofei_message_Rect2d_publish(lcm_t *lcm, const char *channel, const baofei_message_Rect2d *msg);

/**
 * Subscribe to messages of type baofei_message_Rect2d using LCM.
 *
 * @param lcm The LCM instance to subscribe with.
 * @param channel The channel to subscribe to.
 * @param handler The callback function invoked by LCM when a message is
 *     received. This function is invoked by LCM during calls to lcm_handle()
 *     and lcm_handle_timeout().
 * @param userdata An opaque pointer passed to @p handler when it is invoked.
 * @return 0 on success, <0 if an error occured
 */
baofei_message_Rect2d_subscription_t* baofei_message_Rect2d_subscribe(
    lcm_t *lcm, const char *channel, baofei_message_Rect2d_handler_t handler, void *userdata);

/**
 * Removes and destroys a subscription created by baofei_message_Rect2d_subscribe()
 */
int baofei_message_Rect2d_unsubscribe(lcm_t *lcm, baofei_message_Rect2d_subscription_t* hid);

/**
 * Sets the queue capacity for a subscription.
 * Some LCM providers (e.g., the default multicast provider) are implemented
 * using a background receive thread that constantly revceives messages from
 * the network.  As these messages are received, they are buffered on
 * per-subscription queues until dispatched by lcm_handle().  This function
 * how many messages are queued before dropping messages.
 *
 * @param subs the subscription to modify.
 * @param num_messages The maximum number of messages to queue
 *  on the subscription.
 * @return 0 on success, <0 if an error occured
 */
int baofei_message_Rect2d_subscription_set_queue_capacity(
    baofei_message_Rect2d_subscription_t* subs, int num_messages);

/**
 * Encode a message of type baofei_message_Rect2d into binary form.
 *
 * @param buf The output buffer.
 * @param offset Encoding starts at this byte offset into @p buf.
 * @param maxlen Maximum number of bytes to write.  This should generally
 *               be equal to baofei_message_Rect2d_encoded_size().
 * @param msg The message to encode.
 * @return The number of bytes encoded, or <0 if an error occured.
 */
int baofei_message_Rect2d_encode(void *buf, int offset, int maxlen, const baofei_message_Rect2d *p);

/**
 * Decode a message of type baofei_message_Rect2d from binary form.
 * When decoding messages containing strings or variable-length arrays, this
 * function may allocate memory.  When finished with the decoded message,
 * release allocated resources with baofei_message_Rect2d_decode_cleanup().
 *
 * @param buf The buffer containing the encoded message
 * @param offset The byte offset into @p buf where the encoded message starts.
 * @param maxlen The maximum number of bytes to read while decoding.
 * @param msg Output parameter where the decoded message is stored
 * @return The number of bytes decoded, or <0 if an error occured.
 */
int baofei_message_Rect2d_decode(const void *buf, int offset, int maxlen, baofei_message_Rect2d *msg);

/**
 * Release resources allocated by baofei_message_Rect2d_decode()
 * @return 0
 */
int baofei_message_Rect2d_decode_cleanup(baofei_message_Rect2d *p);

/**
 * Check how many bytes are required to encode a message of type baofei_message_Rect2d
 */
int baofei_message_Rect2d_encoded_size(const baofei_message_Rect2d *p);

// LCM support functions. Users should not call these
int64_t __baofei_message_Rect2d_get_hash(void);
uint64_t __baofei_message_Rect2d_hash_recursive(const __lcm_hash_ptr *p);
int __baofei_message_Rect2d_encode_array(
    void *buf, int offset, int maxlen, const baofei_message_Rect2d *p, int elements);
int __baofei_message_Rect2d_decode_array(
    const void *buf, int offset, int maxlen, baofei_message_Rect2d *p, int elements);
int __baofei_message_Rect2d_decode_array_cleanup(baofei_message_Rect2d *p, int elements);
int __baofei_message_Rect2d_encoded_array_size(const baofei_message_Rect2d *p, int elements);
int __baofei_message_Rect2d_clone_array(const baofei_message_Rect2d *p, baofei_message_Rect2d *q, int elements);

#ifdef __cplusplus
}
#endif

#endif