// THIS IS AN AUTOMATICALLY GENERATED FILE.  DO NOT MODIFY
// BY HAND!!
//
// Generated by lcm-gen

#ifndef _baofei_message_Order_h
#define _baofei_message_Order_h

#include <stdint.h>
#include <stdlib.h>
#include <lcm/lcm_coretypes.h>
#include <lcm/lcm.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _baofei_message_Order baofei_message_Order;
struct _baofei_message_Order
{
    int8_t     orderId;
    int32_t    sign;
    int8_t     valid;
    int8_t     hour;
    int8_t     minute;
    int8_t     mode;
    int8_t     fan;
    int8_t     waterTank;
    int8_t     regionCount;
    int8_t     *regions;
    int8_t     mopMode;
    int8_t     washWorkType;
    int8_t     wipeMode;
    int8_t     conflictType;
};

/**
 * Create a deep copy of a baofei_message_Order.
 * When no longer needed, destroy it with baofei_message_Order_destroy()
 */
baofei_message_Order* baofei_message_Order_copy(const baofei_message_Order* to_copy);

/**
 * Destroy an instance of baofei_message_Order created by baofei_message_Order_copy()
 */
void baofei_message_Order_destroy(baofei_message_Order* to_destroy);

/**
 * Identifies a single subscription.  This is an opaque data type.
 */
typedef struct _baofei_message_Order_subscription_t baofei_message_Order_subscription_t;

/**
 * Prototype for a callback function invoked when a message of type
 * baofei_message_Order is received.
 */
typedef void(*baofei_message_Order_handler_t)(
    const lcm_recv_buf_t *rbuf, const char *channel,
    const baofei_message_Order *msg, void *userdata);

/**
 * Publish a message of type baofei_message_Order using LCM.
 *
 * @param lcm The LCM instance to publish with.
 * @param channel The channel to publish on.
 * @param msg The message to publish.
 * @return 0 on success, <0 on error.  Success means LCM has transferred
 * responsibility of the message data to the OS.
 */
int baofei_message_Order_publish(lcm_t *lcm, const char *channel, const baofei_message_Order *msg);

/**
 * Subscribe to messages of type baofei_message_Order using LCM.
 *
 * @param lcm The LCM instance to subscribe with.
 * @param channel The channel to subscribe to.
 * @param handler The callback function invoked by LCM when a message is
 *     received. This function is invoked by LCM during calls to lcm_handle()
 *     and lcm_handle_timeout().
 * @param userdata An opaque pointer passed to @p handler when it is invoked.
 * @return 0 on success, <0 if an error occured
 */
baofei_message_Order_subscription_t* baofei_message_Order_subscribe(
    lcm_t *lcm, const char *channel, baofei_message_Order_handler_t handler, void *userdata);

/**
 * Removes and destroys a subscription created by baofei_message_Order_subscribe()
 */
int baofei_message_Order_unsubscribe(lcm_t *lcm, baofei_message_Order_subscription_t* hid);

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
int baofei_message_Order_subscription_set_queue_capacity(
    baofei_message_Order_subscription_t* subs, int num_messages);

/**
 * Encode a message of type baofei_message_Order into binary form.
 *
 * @param buf The output buffer.
 * @param offset Encoding starts at this byte offset into @p buf.
 * @param maxlen Maximum number of bytes to write.  This should generally
 *               be equal to baofei_message_Order_encoded_size().
 * @param msg The message to encode.
 * @return The number of bytes encoded, or <0 if an error occured.
 */
int baofei_message_Order_encode(void *buf, int offset, int maxlen, const baofei_message_Order *p);

/**
 * Decode a message of type baofei_message_Order from binary form.
 * When decoding messages containing strings or variable-length arrays, this
 * function may allocate memory.  When finished with the decoded message,
 * release allocated resources with baofei_message_Order_decode_cleanup().
 *
 * @param buf The buffer containing the encoded message
 * @param offset The byte offset into @p buf where the encoded message starts.
 * @param maxlen The maximum number of bytes to read while decoding.
 * @param msg Output parameter where the decoded message is stored
 * @return The number of bytes decoded, or <0 if an error occured.
 */
int baofei_message_Order_decode(const void *buf, int offset, int maxlen, baofei_message_Order *msg);

/**
 * Release resources allocated by baofei_message_Order_decode()
 * @return 0
 */
int baofei_message_Order_decode_cleanup(baofei_message_Order *p);

/**
 * Check how many bytes are required to encode a message of type baofei_message_Order
 */
int baofei_message_Order_encoded_size(const baofei_message_Order *p);

// LCM support functions. Users should not call these
int64_t __baofei_message_Order_get_hash(void);
uint64_t __baofei_message_Order_hash_recursive(const __lcm_hash_ptr *p);
int __baofei_message_Order_encode_array(
    void *buf, int offset, int maxlen, const baofei_message_Order *p, int elements);
int __baofei_message_Order_decode_array(
    const void *buf, int offset, int maxlen, baofei_message_Order *p, int elements);
int __baofei_message_Order_decode_array_cleanup(baofei_message_Order *p, int elements);
int __baofei_message_Order_encoded_array_size(const baofei_message_Order *p, int elements);
int __baofei_message_Order_clone_array(const baofei_message_Order *p, baofei_message_Order *q, int elements);

#ifdef __cplusplus
}
#endif

#endif