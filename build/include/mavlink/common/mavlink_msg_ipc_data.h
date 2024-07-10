#pragma once
// MESSAGE IPC_DATA PACKING

#define MAVLINK_MSG_ID_IPC_DATA 11046


typedef struct __mavlink_ipc_data_t {
 uint32_t preamble; /*<  The preamble of payload.*/
 float refrences[20]; /*<  Steering tire rotation rate ref.*/
 float steer_fb; /*<  Steering angle from OAU.*/
 float acc_fb; /*<  Acceleration angle from OAU.*/
 float ebrake_fb; /*<  Electronic Brake angle from OAU.*/
 uint8_t mode; /*<  Indicates modes for Autopilot.*/
 uint8_t mode_fb; /*<  Indicates modes come from OAU.*/
 uint8_t switch_fb; /*<  Indicates switch status from OAU.*/
 uint8_t hbrake_fb; /*<  Hydraulic status from OAU.*/
} mavlink_ipc_data_t;

#define MAVLINK_MSG_ID_IPC_DATA_LEN 100
#define MAVLINK_MSG_ID_IPC_DATA_MIN_LEN 100
#define MAVLINK_MSG_ID_11046_LEN 100
#define MAVLINK_MSG_ID_11046_MIN_LEN 100

#define MAVLINK_MSG_ID_IPC_DATA_CRC 72
#define MAVLINK_MSG_ID_11046_CRC 72

#define MAVLINK_MSG_IPC_DATA_FIELD_REFRENCES_LEN 20

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_IPC_DATA { \
    11046, \
    "IPC_DATA", \
    9, \
    {  { "preamble", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_ipc_data_t, preamble) }, \
         { "mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 96, offsetof(mavlink_ipc_data_t, mode) }, \
         { "refrences", NULL, MAVLINK_TYPE_FLOAT, 20, 4, offsetof(mavlink_ipc_data_t, refrences) }, \
         { "mode_fb", NULL, MAVLINK_TYPE_UINT8_T, 0, 97, offsetof(mavlink_ipc_data_t, mode_fb) }, \
         { "switch_fb", NULL, MAVLINK_TYPE_UINT8_T, 0, 98, offsetof(mavlink_ipc_data_t, switch_fb) }, \
         { "steer_fb", NULL, MAVLINK_TYPE_FLOAT, 0, 84, offsetof(mavlink_ipc_data_t, steer_fb) }, \
         { "acc_fb", NULL, MAVLINK_TYPE_FLOAT, 0, 88, offsetof(mavlink_ipc_data_t, acc_fb) }, \
         { "ebrake_fb", NULL, MAVLINK_TYPE_FLOAT, 0, 92, offsetof(mavlink_ipc_data_t, ebrake_fb) }, \
         { "hbrake_fb", NULL, MAVLINK_TYPE_UINT8_T, 0, 99, offsetof(mavlink_ipc_data_t, hbrake_fb) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_IPC_DATA { \
    "IPC_DATA", \
    9, \
    {  { "preamble", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_ipc_data_t, preamble) }, \
         { "mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 96, offsetof(mavlink_ipc_data_t, mode) }, \
         { "refrences", NULL, MAVLINK_TYPE_FLOAT, 20, 4, offsetof(mavlink_ipc_data_t, refrences) }, \
         { "mode_fb", NULL, MAVLINK_TYPE_UINT8_T, 0, 97, offsetof(mavlink_ipc_data_t, mode_fb) }, \
         { "switch_fb", NULL, MAVLINK_TYPE_UINT8_T, 0, 98, offsetof(mavlink_ipc_data_t, switch_fb) }, \
         { "steer_fb", NULL, MAVLINK_TYPE_FLOAT, 0, 84, offsetof(mavlink_ipc_data_t, steer_fb) }, \
         { "acc_fb", NULL, MAVLINK_TYPE_FLOAT, 0, 88, offsetof(mavlink_ipc_data_t, acc_fb) }, \
         { "ebrake_fb", NULL, MAVLINK_TYPE_FLOAT, 0, 92, offsetof(mavlink_ipc_data_t, ebrake_fb) }, \
         { "hbrake_fb", NULL, MAVLINK_TYPE_UINT8_T, 0, 99, offsetof(mavlink_ipc_data_t, hbrake_fb) }, \
         } \
}
#endif

/**
 * @brief Pack a ipc_data message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param preamble  The preamble of payload.
 * @param mode  Indicates modes for Autopilot.
 * @param refrences  Steering tire rotation rate ref.
 * @param mode_fb  Indicates modes come from OAU.
 * @param switch_fb  Indicates switch status from OAU.
 * @param steer_fb  Steering angle from OAU.
 * @param acc_fb  Acceleration angle from OAU.
 * @param ebrake_fb  Electronic Brake angle from OAU.
 * @param hbrake_fb  Hydraulic status from OAU.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ipc_data_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t preamble, uint8_t mode, const float *refrences, uint8_t mode_fb, uint8_t switch_fb, float steer_fb, float acc_fb, float ebrake_fb, uint8_t hbrake_fb)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_IPC_DATA_LEN];
    _mav_put_uint32_t(buf, 0, preamble);
    _mav_put_float(buf, 84, steer_fb);
    _mav_put_float(buf, 88, acc_fb);
    _mav_put_float(buf, 92, ebrake_fb);
    _mav_put_uint8_t(buf, 96, mode);
    _mav_put_uint8_t(buf, 97, mode_fb);
    _mav_put_uint8_t(buf, 98, switch_fb);
    _mav_put_uint8_t(buf, 99, hbrake_fb);
    _mav_put_float_array(buf, 4, refrences, 20);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_IPC_DATA_LEN);
#else
    mavlink_ipc_data_t packet;
    packet.preamble = preamble;
    packet.steer_fb = steer_fb;
    packet.acc_fb = acc_fb;
    packet.ebrake_fb = ebrake_fb;
    packet.mode = mode;
    packet.mode_fb = mode_fb;
    packet.switch_fb = switch_fb;
    packet.hbrake_fb = hbrake_fb;
    mav_array_memcpy(packet.refrences, refrences, sizeof(float)*20);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_IPC_DATA_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_IPC_DATA;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_IPC_DATA_MIN_LEN, MAVLINK_MSG_ID_IPC_DATA_LEN, MAVLINK_MSG_ID_IPC_DATA_CRC);
}

/**
 * @brief Pack a ipc_data message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param preamble  The preamble of payload.
 * @param mode  Indicates modes for Autopilot.
 * @param refrences  Steering tire rotation rate ref.
 * @param mode_fb  Indicates modes come from OAU.
 * @param switch_fb  Indicates switch status from OAU.
 * @param steer_fb  Steering angle from OAU.
 * @param acc_fb  Acceleration angle from OAU.
 * @param ebrake_fb  Electronic Brake angle from OAU.
 * @param hbrake_fb  Hydraulic status from OAU.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ipc_data_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint32_t preamble, uint8_t mode, const float *refrences, uint8_t mode_fb, uint8_t switch_fb, float steer_fb, float acc_fb, float ebrake_fb, uint8_t hbrake_fb)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_IPC_DATA_LEN];
    _mav_put_uint32_t(buf, 0, preamble);
    _mav_put_float(buf, 84, steer_fb);
    _mav_put_float(buf, 88, acc_fb);
    _mav_put_float(buf, 92, ebrake_fb);
    _mav_put_uint8_t(buf, 96, mode);
    _mav_put_uint8_t(buf, 97, mode_fb);
    _mav_put_uint8_t(buf, 98, switch_fb);
    _mav_put_uint8_t(buf, 99, hbrake_fb);
    _mav_put_float_array(buf, 4, refrences, 20);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_IPC_DATA_LEN);
#else
    mavlink_ipc_data_t packet;
    packet.preamble = preamble;
    packet.steer_fb = steer_fb;
    packet.acc_fb = acc_fb;
    packet.ebrake_fb = ebrake_fb;
    packet.mode = mode;
    packet.mode_fb = mode_fb;
    packet.switch_fb = switch_fb;
    packet.hbrake_fb = hbrake_fb;
    mav_array_memcpy(packet.refrences, refrences, sizeof(float)*20);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_IPC_DATA_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_IPC_DATA;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_IPC_DATA_MIN_LEN, MAVLINK_MSG_ID_IPC_DATA_LEN, MAVLINK_MSG_ID_IPC_DATA_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_IPC_DATA_MIN_LEN, MAVLINK_MSG_ID_IPC_DATA_LEN);
#endif
}

/**
 * @brief Pack a ipc_data message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param preamble  The preamble of payload.
 * @param mode  Indicates modes for Autopilot.
 * @param refrences  Steering tire rotation rate ref.
 * @param mode_fb  Indicates modes come from OAU.
 * @param switch_fb  Indicates switch status from OAU.
 * @param steer_fb  Steering angle from OAU.
 * @param acc_fb  Acceleration angle from OAU.
 * @param ebrake_fb  Electronic Brake angle from OAU.
 * @param hbrake_fb  Hydraulic status from OAU.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ipc_data_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t preamble,uint8_t mode,const float *refrences,uint8_t mode_fb,uint8_t switch_fb,float steer_fb,float acc_fb,float ebrake_fb,uint8_t hbrake_fb)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_IPC_DATA_LEN];
    _mav_put_uint32_t(buf, 0, preamble);
    _mav_put_float(buf, 84, steer_fb);
    _mav_put_float(buf, 88, acc_fb);
    _mav_put_float(buf, 92, ebrake_fb);
    _mav_put_uint8_t(buf, 96, mode);
    _mav_put_uint8_t(buf, 97, mode_fb);
    _mav_put_uint8_t(buf, 98, switch_fb);
    _mav_put_uint8_t(buf, 99, hbrake_fb);
    _mav_put_float_array(buf, 4, refrences, 20);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_IPC_DATA_LEN);
#else
    mavlink_ipc_data_t packet;
    packet.preamble = preamble;
    packet.steer_fb = steer_fb;
    packet.acc_fb = acc_fb;
    packet.ebrake_fb = ebrake_fb;
    packet.mode = mode;
    packet.mode_fb = mode_fb;
    packet.switch_fb = switch_fb;
    packet.hbrake_fb = hbrake_fb;
    mav_array_memcpy(packet.refrences, refrences, sizeof(float)*20);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_IPC_DATA_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_IPC_DATA;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_IPC_DATA_MIN_LEN, MAVLINK_MSG_ID_IPC_DATA_LEN, MAVLINK_MSG_ID_IPC_DATA_CRC);
}

/**
 * @brief Encode a ipc_data struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param ipc_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ipc_data_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_ipc_data_t* ipc_data)
{
    return mavlink_msg_ipc_data_pack(system_id, component_id, msg, ipc_data->preamble, ipc_data->mode, ipc_data->refrences, ipc_data->mode_fb, ipc_data->switch_fb, ipc_data->steer_fb, ipc_data->acc_fb, ipc_data->ebrake_fb, ipc_data->hbrake_fb);
}

/**
 * @brief Encode a ipc_data struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param ipc_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ipc_data_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_ipc_data_t* ipc_data)
{
    return mavlink_msg_ipc_data_pack_chan(system_id, component_id, chan, msg, ipc_data->preamble, ipc_data->mode, ipc_data->refrences, ipc_data->mode_fb, ipc_data->switch_fb, ipc_data->steer_fb, ipc_data->acc_fb, ipc_data->ebrake_fb, ipc_data->hbrake_fb);
}

/**
 * @brief Encode a ipc_data struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param ipc_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ipc_data_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_ipc_data_t* ipc_data)
{
    return mavlink_msg_ipc_data_pack_status(system_id, component_id, _status, msg,  ipc_data->preamble, ipc_data->mode, ipc_data->refrences, ipc_data->mode_fb, ipc_data->switch_fb, ipc_data->steer_fb, ipc_data->acc_fb, ipc_data->ebrake_fb, ipc_data->hbrake_fb);
}

/**
 * @brief Send a ipc_data message
 * @param chan MAVLink channel to send the message
 *
 * @param preamble  The preamble of payload.
 * @param mode  Indicates modes for Autopilot.
 * @param refrences  Steering tire rotation rate ref.
 * @param mode_fb  Indicates modes come from OAU.
 * @param switch_fb  Indicates switch status from OAU.
 * @param steer_fb  Steering angle from OAU.
 * @param acc_fb  Acceleration angle from OAU.
 * @param ebrake_fb  Electronic Brake angle from OAU.
 * @param hbrake_fb  Hydraulic status from OAU.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_ipc_data_send(mavlink_channel_t chan, uint32_t preamble, uint8_t mode, const float *refrences, uint8_t mode_fb, uint8_t switch_fb, float steer_fb, float acc_fb, float ebrake_fb, uint8_t hbrake_fb)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_IPC_DATA_LEN];
    _mav_put_uint32_t(buf, 0, preamble);
    _mav_put_float(buf, 84, steer_fb);
    _mav_put_float(buf, 88, acc_fb);
    _mav_put_float(buf, 92, ebrake_fb);
    _mav_put_uint8_t(buf, 96, mode);
    _mav_put_uint8_t(buf, 97, mode_fb);
    _mav_put_uint8_t(buf, 98, switch_fb);
    _mav_put_uint8_t(buf, 99, hbrake_fb);
    _mav_put_float_array(buf, 4, refrences, 20);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_IPC_DATA, buf, MAVLINK_MSG_ID_IPC_DATA_MIN_LEN, MAVLINK_MSG_ID_IPC_DATA_LEN, MAVLINK_MSG_ID_IPC_DATA_CRC);
#else
    mavlink_ipc_data_t packet;
    packet.preamble = preamble;
    packet.steer_fb = steer_fb;
    packet.acc_fb = acc_fb;
    packet.ebrake_fb = ebrake_fb;
    packet.mode = mode;
    packet.mode_fb = mode_fb;
    packet.switch_fb = switch_fb;
    packet.hbrake_fb = hbrake_fb;
    mav_array_memcpy(packet.refrences, refrences, sizeof(float)*20);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_IPC_DATA, (const char *)&packet, MAVLINK_MSG_ID_IPC_DATA_MIN_LEN, MAVLINK_MSG_ID_IPC_DATA_LEN, MAVLINK_MSG_ID_IPC_DATA_CRC);
#endif
}

/**
 * @brief Send a ipc_data message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_ipc_data_send_struct(mavlink_channel_t chan, const mavlink_ipc_data_t* ipc_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_ipc_data_send(chan, ipc_data->preamble, ipc_data->mode, ipc_data->refrences, ipc_data->mode_fb, ipc_data->switch_fb, ipc_data->steer_fb, ipc_data->acc_fb, ipc_data->ebrake_fb, ipc_data->hbrake_fb);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_IPC_DATA, (const char *)ipc_data, MAVLINK_MSG_ID_IPC_DATA_MIN_LEN, MAVLINK_MSG_ID_IPC_DATA_LEN, MAVLINK_MSG_ID_IPC_DATA_CRC);
#endif
}

#if MAVLINK_MSG_ID_IPC_DATA_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_ipc_data_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t preamble, uint8_t mode, const float *refrences, uint8_t mode_fb, uint8_t switch_fb, float steer_fb, float acc_fb, float ebrake_fb, uint8_t hbrake_fb)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, preamble);
    _mav_put_float(buf, 84, steer_fb);
    _mav_put_float(buf, 88, acc_fb);
    _mav_put_float(buf, 92, ebrake_fb);
    _mav_put_uint8_t(buf, 96, mode);
    _mav_put_uint8_t(buf, 97, mode_fb);
    _mav_put_uint8_t(buf, 98, switch_fb);
    _mav_put_uint8_t(buf, 99, hbrake_fb);
    _mav_put_float_array(buf, 4, refrences, 20);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_IPC_DATA, buf, MAVLINK_MSG_ID_IPC_DATA_MIN_LEN, MAVLINK_MSG_ID_IPC_DATA_LEN, MAVLINK_MSG_ID_IPC_DATA_CRC);
#else
    mavlink_ipc_data_t *packet = (mavlink_ipc_data_t *)msgbuf;
    packet->preamble = preamble;
    packet->steer_fb = steer_fb;
    packet->acc_fb = acc_fb;
    packet->ebrake_fb = ebrake_fb;
    packet->mode = mode;
    packet->mode_fb = mode_fb;
    packet->switch_fb = switch_fb;
    packet->hbrake_fb = hbrake_fb;
    mav_array_memcpy(packet->refrences, refrences, sizeof(float)*20);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_IPC_DATA, (const char *)packet, MAVLINK_MSG_ID_IPC_DATA_MIN_LEN, MAVLINK_MSG_ID_IPC_DATA_LEN, MAVLINK_MSG_ID_IPC_DATA_CRC);
#endif
}
#endif

#endif

// MESSAGE IPC_DATA UNPACKING


/**
 * @brief Get field preamble from ipc_data message
 *
 * @return  The preamble of payload.
 */
static inline uint32_t mavlink_msg_ipc_data_get_preamble(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field mode from ipc_data message
 *
 * @return  Indicates modes for Autopilot.
 */
static inline uint8_t mavlink_msg_ipc_data_get_mode(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  96);
}

/**
 * @brief Get field refrences from ipc_data message
 *
 * @return  Steering tire rotation rate ref.
 */
static inline uint16_t mavlink_msg_ipc_data_get_refrences(const mavlink_message_t* msg, float *refrences)
{
    return _MAV_RETURN_float_array(msg, refrences, 20,  4);
}

/**
 * @brief Get field mode_fb from ipc_data message
 *
 * @return  Indicates modes come from OAU.
 */
static inline uint8_t mavlink_msg_ipc_data_get_mode_fb(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  97);
}

/**
 * @brief Get field switch_fb from ipc_data message
 *
 * @return  Indicates switch status from OAU.
 */
static inline uint8_t mavlink_msg_ipc_data_get_switch_fb(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  98);
}

/**
 * @brief Get field steer_fb from ipc_data message
 *
 * @return  Steering angle from OAU.
 */
static inline float mavlink_msg_ipc_data_get_steer_fb(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  84);
}

/**
 * @brief Get field acc_fb from ipc_data message
 *
 * @return  Acceleration angle from OAU.
 */
static inline float mavlink_msg_ipc_data_get_acc_fb(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  88);
}

/**
 * @brief Get field ebrake_fb from ipc_data message
 *
 * @return  Electronic Brake angle from OAU.
 */
static inline float mavlink_msg_ipc_data_get_ebrake_fb(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  92);
}

/**
 * @brief Get field hbrake_fb from ipc_data message
 *
 * @return  Hydraulic status from OAU.
 */
static inline uint8_t mavlink_msg_ipc_data_get_hbrake_fb(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  99);
}

/**
 * @brief Decode a ipc_data message into a struct
 *
 * @param msg The message to decode
 * @param ipc_data C-struct to decode the message contents into
 */
static inline void mavlink_msg_ipc_data_decode(const mavlink_message_t* msg, mavlink_ipc_data_t* ipc_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    ipc_data->preamble = mavlink_msg_ipc_data_get_preamble(msg);
    mavlink_msg_ipc_data_get_refrences(msg, ipc_data->refrences);
    ipc_data->steer_fb = mavlink_msg_ipc_data_get_steer_fb(msg);
    ipc_data->acc_fb = mavlink_msg_ipc_data_get_acc_fb(msg);
    ipc_data->ebrake_fb = mavlink_msg_ipc_data_get_ebrake_fb(msg);
    ipc_data->mode = mavlink_msg_ipc_data_get_mode(msg);
    ipc_data->mode_fb = mavlink_msg_ipc_data_get_mode_fb(msg);
    ipc_data->switch_fb = mavlink_msg_ipc_data_get_switch_fb(msg);
    ipc_data->hbrake_fb = mavlink_msg_ipc_data_get_hbrake_fb(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_IPC_DATA_LEN? msg->len : MAVLINK_MSG_ID_IPC_DATA_LEN;
        memset(ipc_data, 0, MAVLINK_MSG_ID_IPC_DATA_LEN);
    memcpy(ipc_data, _MAV_PAYLOAD(msg), len);
#endif
}
