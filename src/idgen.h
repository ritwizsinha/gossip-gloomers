#ifndef ID_GEN_H 
#define ID_GEN_H

#include <types.h>
#include <nlohmann/json.hpp>

namespace IdGen {
    using namespace Node;
    struct IdGenRequest {
        std::string type;
        int msg_id;
    };

    struct IdGenResponse {
        std::string type;
        int msg_id;
        int in_reply_to;
        std::string id;
    };
    

    void to_json(nlohmann::json& j, const Reply<IdGenResponse> &resp);
    void from_json(const nlohmann::json& j, Message<IdGenRequest> &req);
    auto process(const Message<IdGenRequest>&, Reply<IdGenResponse>&) -> void;

    // std::ostream& operator<<(std::ostream& os, const Reply<EchoResponse>& reply);
}

#endif