#include <initialization.h>


namespace Initialization 
{
        void to_json(nlohmann::json& j, const Reply<InitResponse> &resp){
            j = nlohmann::json{
                {"src", resp.context.src},
                {"dest", resp.context.dest},
                {
                    "body", {
                        {"type", resp.body.type},
                        {"in_reply_to", resp.body.in_reply_to}
                    }
                }
            };
        }
        void from_json(const nlohmann::json& j, Message<InitRequest> &req)
        {
            req.context.src = j.at("src").get<std::string>();
            req.context.dest = j.at("dest").get<std::string>();
            req.body.type = j.at("body").at("type").get<std::string>();
            req.body.msg_id = j.at("body").at("msg_id").get<int>();
            req.body.node_id = j.at("body").at("node_id").get<std::string>();
            req.body.node_ids = j.at("body").at("node_ids").get<std::vector<std::string>>();
        }

        auto process(const Message<InitRequest>& req, Reply<InitResponse> &resp) -> void
        {
            extern int msg_id;
            resp.context.src = req.context.dest;
            resp.context.dest = req.context.src;

            resp.body.type = "init_ok";
            resp.body.in_reply_to = req.body.msg_id;
        }

}