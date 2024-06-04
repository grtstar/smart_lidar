#include <mars_message/Event.hpp>  
#include "comm.h"

static int32_t S2M(std::string msg)
{
    if(msg.empty())
    {
        return 0;
    }
    int32_t m = 0;
    for(int i=0; i<msg.length();i++)
    {
        m <<= 8;
        m |= msg.at(i);
    }
    return m;
}

int main(int argc, char **argv)
{
    if(argc < 4)
    {
        printf("Usage: %s <topic> <evt> <param>\n", argv[0]);
        return -1;
    }

    mars_message::Event evt;
    evt.event = S2M(argv[2]);
    evt.param = atoi(argv[3]);
    Comm::Instance()->Publish(argv[1], &evt);
    return 0;
}