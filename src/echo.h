#ifndef ECHO_H
#define ECHO_H

#include <types.h>
#include <nlohmann/json.hpp>
#include <iostream>

namespace Echo {
    using namespace Node;
    struct EchoRequest {
        std::string type;
        int msg_id;
        std::string echo;
    };

    struct EchoResponse {
        std::string type;
        int msg_id;
        int in_reply_to;
        std::string echo;
    };
    

    void to_json(nlohmann::json& j, const Reply<EchoResponse> &resp);
    void from_json(const nlohmann::json& j, Message<EchoRequest> &req);
    auto process(const Message<EchoRequest>&, Reply<EchoResponse>&) -> void;

    // std::ostream& operator<<(std::ostream& os, const Reply<EchoResponse>& reply);
}

#endif