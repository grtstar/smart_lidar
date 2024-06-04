// THIS IS AN AUTOMATICALLY GENERATED FILE.  DO NOT MODIFY
// BY HAND!!
//
// Generated by lcm-gen

#ifndef _mars_message_Marker_h
#define _mars_message_Marker_h

#include <stdint.h>
#include <stdlib.h>
#include <lcm/lcm_coretypes.h>
#include <lcm/lcm.h>

#ifdef __cplusplus
extern "C" {
#endif

#include "mars_message_Pose.h"
#include "mars_message_Vector3.h"
#include "mars_message_ColorRGBA.h"
#include "mars_message_Point.h"
#include "mars_message_ColorRGBA.h"
typedef struct _mars_message_Marker mars_message_Marker;
struct _mars_message_Marker
{
    int64_t    timestampMs;
    char*      ns;
    int32_t    id;
    int32_t    type;
    int32_t    action;
    mars_message_Pose pose;
    mars_message_Vector3 scale;
    mars_message_ColorRGBA color;
    int32_t    lifetime;
    int32_t    frame_locked;
    int32_t    pointCount;
    mars_message_Point *points;
    mars_message_ColorRGBA *colors;
    char*      text;
    char*      mesh_resource;
    int32_t    mesh_use_embeded_materials;
};

/**
 * Create a deep copy of a mars_message_Marker.
 * When no longer needed, destroy it with mars_message_Marker_destroy()
 */
mars_message_Marker* mars_message_Marker_copy(const mars_message_Marker* to_copy);

/**
 * Destroy an instance of mars_message_Marker created by mars_message_Marker_copy()
 */
void mars_message_Marker_destroy(mars_message_Marker* to_destroy);

/**
 * Identifies a single subscription.  This is an opaque data type.
 */
typedef struct _mars_message_Marker_subscription_t mars_message_Marker_subscription_t;

/**
 * Prototype for a callback function invoked when a message of type
 * mars_message_Marker is received.
 */
typedef void(*mars_message_Marker_handler_t)(
    const lcm_recv_buf_t *rbuf, const char *channel,
    const mars_message_Marker *msg, void *userdata);

/**
 * Publish a message of type mars_message_Marker using LCM.
 *
 * @param lcm The LCM instance to publish with.
 * @param channel The channel to publish on.
 * @param msg The message to publish.
 * @return 0 on success, <0 on error.  Success means LCM has transferred
 * responsibility of the message data to the OS.
 */
int mars_message_Marker_publish(lcm_t *lcm, const char *channel, const mars_message_Marker *msg);

/**
 * Subscribe to messages of type mars_message_Marker using LCM.
 *
 * @param lcm The LCM instance to subscribe with.
 * @param channel The channel to subscribe to.
 * @param handler The callback function invoked by LCM when a message is
 *     received. This function is invoked by LCM during calls to lcm_handle()
 *     and lcm_handle_timeout().
 * @param userdata An opaque pointer passed to @p handler when it is invoked.
 * @return 0 on success, <0 if an error occured
 */
mars_message_Marker_subscription_t* mars_message_Marker_subscribe(
    lcm_t *lcm, const char *channel, mars_message_Marker_handler_t handler, void *userdata);

/**
 * Removes and destroys a subscription created by mars_message_Marker_subscribe()
 */
int mars_message_Marker_unsubscribe(lcm_t *lcm, mars_message_Marker_subscription_t* hid);

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
int mars_message_Marker_subscription_set_queue_capacity(
    mars_message_Marker_subscription_t* subs, int num_messages);

/**
 * Encode a message of type mars_message_Marker into binary form.
 *
 * @param buf The output buffer.
 * @param offset Encoding starts at this byte offset into @p buf.
 * @param maxlen Maximum number of bytes to write.  This should generally
 *               be equal to mars_message_Marker_encoded_size().
 * @param msg The message to encode.
 * @return The number of bytes encoded, or <0 if an error occured.
 */
int mars_message_Marker_encode(void *buf, int offset, int maxlen, const mars_message_Marker *p);

/**
 * Decode a message of type mars_message_Marker from binary form.
 * When decoding messages containing strings or variable-length arrays, this
 * function may allocate memory.  When finished with the decoded message,
 * release allocated resources with mars_message_Marker_decode_cleanup().
 *
 * @param buf The buffer containing the encoded message
 * @param offset The byte offset into @p buf where the encoded message starts.
 * @param maxlen The maximum number of bytes to read while decoding.
 * @param msg Output parameter where the decoded message is stored
 * @return The number of bytes decoded, or <0 if an error occured.
 */
int mars_message_Marker_decode(const void *buf, int offset, int maxlen, mars_message_Marker *msg);

/**
 * Release resources allocated by mars_message_Marker_decode()
 * @return 0
 */
int mars_message_Marker_decode_cleanup(mars_message_Marker *p);

/**
 * Check how many bytes are required to encode a message of type mars_message_Marker
 */
int mars_message_Marker_encoded_size(const mars_message_Marker *p);

// LCM support functions. Users should not call these
int64_t __mars_message_Marker_get_hash(void);
uint64_t __mars_message_Marker_hash_recursive(const __lcm_hash_ptr *p);
int __mars_message_Marker_encode_array(
    void *buf, int offset, int maxlen, const mars_message_Marker *p, int elements);
int __mars_message_Marker_decode_array(
    const void *buf, int offset, int maxlen, mars_message_Marker *p, int elements);
int __mars_message_Marker_decode_array_cleanup(mars_message_Marker *p, int elements);
int __mars_message_Marker_encoded_array_size(const mars_message_Marker *p, int elements);
int __mars_message_Marker_clone_array(const mars_message_Marker *p, mars_message_Marker *q, int elements);

#ifdef __cplusplus
}
#endif

#endif
