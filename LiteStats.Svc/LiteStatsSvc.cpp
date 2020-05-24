#include "LiteStats.h"

class LiteStatsSvc : public LiteStats::Application
{
public:
    LiteStatsSvc()
    {

    }

    ~LiteStatsSvc()
    {

    }
};

LiteStats::Application* LiteStats::CreateApplication()
{
    return new LiteStatsSvc();
}
