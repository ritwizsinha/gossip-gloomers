#ifndef COMMON_TYPES_H
#define COMMON_TYPES_H

#include <string>
#include <variant>

namespace Node 
{
    struct Context 
    {
        std::string src;
        std::string dest;
    };
    template<typename Body>
    struct Message
    {
        Context context;
        Body body;
    };

    template<typename Body>
    struct Reply
    {
        Context context;
        Body body;
    };  
}

#endif