#include <idgen.h>

extern int msg_id;
namespace IdGen
{
        void to_json(nlohmann::json& j, const Reply<IdGenResponse> &resp){
            j = nlohmann::json{
                {"src", resp.context.src},
                {"dest", resp.context.dest},
                {"body", {
                    {"type", resp.body.type},
                    {"msg_id", resp.body.msg_id},
                    {"in_reply_to", resp.body.in_reply_to},
                    {"id", resp.body.id}
                }
            }};
        }
        void from_json(const nlohmann::json& j, Message<IdGenRequest> &req)
        {
            req.context.src = j.at("src").get<std::string>();
            req.context.dest = j.at("dest").get<std::string>();
            req.body.type = j.at("body").at("type").get<std::string>();
            req.body.msg_id = j.at("body").at("msg_id").get<int>();
        }

        auto process(const Message<IdGenRequest>& req, Reply<IdGenResponse> &resp) -> void
        {
            resp.context.src = req.context.dest;
            resp.context.dest = req.context.src;
            resp.body.type = "generate_ok";
            resp.body.msg_id = msg_id++;
            resp.body.in_reply_to = req.body.msg_id;
            resp.body.id = std::to_string(msg_id) + req.context.src;
        }

}