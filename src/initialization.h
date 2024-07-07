#ifndef INITIALIZATION_H
#define INITIALIZATION_H

#include <nlohmann/json.hpp>
#include <types.h>
#include <vector>

namespace Initialization {
    using namespace Node;
    struct InitRequest {
        std::string type;
        int msg_id;
        std::string node_id;
        std::vector<std::string> node_ids;
    };

    struct InitResponse {
        std::string type;
        int in_reply_to;
    };
    

    void to_json(nlohmann::json& j, const Reply<InitResponse> &resp);
    void from_json(const nlohmann::json& j, Message<InitRequest> &req);
    auto process(const Message<InitRequest>&, Reply<InitResponse>&) -> void;

}

#endif