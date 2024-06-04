#pragma once

#include <lcm/lcm-cpp.hpp>

#undef TAG
#define TAG "COMM"

class Comm
{
    int handlerId;
    Comm(){ handlerId = 0;}
public:
    static Comm* Instance()
    {
        static Comm* _instance = NULL;
        if (_instance == NULL)
        {
            _instance = new Comm();
        }
        return _instance;
    }

    bool IsGood()
    {
        return lcm.good();
    }

    void HandleForever()
    {
        handlerId = pthread_self();
        while (0 == lcm.handle());
    }

    void HandleTimeout(int ms)
    {
        if(handlerId == 0)
        {
            handlerId = pthread_self();
        }
        lcm.handleTimeout(ms);
    }

    template <class MessageType>
    inline int Publish(const std::string &channel, const MessageType *msg)
    {
        return lcm.publish(channel, msg);
    }

    template <class MessageType, class MessageHandlerClass>
    void* Subscribe(const std::string &channel,
                             void (MessageHandlerClass::*handlerMethod)(const lcm::ReceiveBuffer *rbuf,
                                                                        const std::string &channel,
                                                                        const MessageType *msg),
                             MessageHandlerClass *handler)
    {
        return lcm.subscribe(channel, handlerMethod, handler);
    }

    template <class MessageType, class MessageTypeRet>
    inline int Send(const std::string &channel, MessageType *msg, MessageTypeRet *ret, int timeoutMs = 100, int retryTimes = 1)
    {
        return lcm.send(channel, msg, ret, timeoutMs, retryTimes) == 0;
    }

    template <class MessageType>
    inline bool Send(const std::string &channel, MessageType *msg, int timeoutMs = 100, int retryTimes = 1)
    {
        MessageType ret;
        int r = lcm.send(channel, msg, &ret, timeoutMs, retryTimes);
        *msg = ret;
        return r == 0;
    }

    template <class MessageType, class MessageTypeRet, class MessageHandlerClass>
    void* Defines(const std::string & channel, 
                            MessageTypeRet (MessageHandlerClass::*handlerMethod)(const MessageType *msg),
                            MessageHandlerClass *handler)
    {
        return lcm.defines(channel, handlerMethod, handler);   
    }
    lcm::LCM  lcm;
};
