#include <echo.h>

extern int msg_id;
namespace Echo
{
        void to_json(nlohmann::json& j, const Reply<EchoResponse> &resp){
            j = nlohmann::json{
                {"src", resp.context.src},
                {"dest", resp.context.dest},
                {"body", {
                    {"type", resp.body.type},
                    {"msg_id", resp.body.msg_id},
                    {"in_reply_to", resp.body.in_reply_to},
                    {"echo", resp.body.echo}
                }
            }};
        }
        void from_json(const nlohmann::json& j, Message<EchoRequest> &req)
        {
            req.context.src = j.at("src").get<std::string>();
            req.context.dest = j.at("dest").get<std::string>();
            req.body.type = j.at("body").at("type").get<std::string>();
            req.body.msg_id = j.at("body").at("msg_id").get<int>();
            req.body.echo = j.at("body").at("echo").get<std::string>();
        }

        auto process(const Message<EchoRequest>& req, Reply<EchoResponse> &resp) -> void
        {
            resp.context.src = req.context.dest;
            resp.context.dest = req.context.src;
            resp.body.type = "echo_ok";
            resp.body.msg_id = msg_id++;
            resp.body.in_reply_to = req.body.msg_id;
            resp.body.echo = req.body.echo;
        }

}