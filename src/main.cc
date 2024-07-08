#include <nlohmann/json.hpp>
#include <iostream>
#include <echo.h>
#include <initialization.h>
#include <types.h>
#include <idgen.h>

using json = nlohmann::json;
int msg_id = 0;
int main() {
  for (std::string line; std::getline(std::cin, line);) {
	if (json::accept(line)) {
		    json j = json::parse(line);
        auto type = j.at("body").at("type").get<std::string>();
        if (type == "init") {
            Node::Message<Initialization::InitRequest> msg;
            Initialization::from_json(j, msg);
            Node::Reply<Initialization::InitResponse> resp;
            Initialization::process(msg, resp);
            Initialization::to_json(j, resp);

            std::cout << j.dump() << std::endl;
        }
        else if (type == "echo")
        {
          Node::Message<Echo::EchoRequest> msg; 
          Echo::from_json(j, msg);
          Node::Reply<Echo::EchoResponse> reply;
          Echo::process(msg, reply);
          Echo::to_json(j, reply);
          std::cout << j.dump() << std::endl;
        }
        else {
          Node::Message<IdGen::IdGenRequest> msg;
          IdGen::from_json(j, msg);
          Node::Reply<IdGen::IdGenResponse> resp;
          IdGen::process(msg, resp);
          IdGen::to_json(j, resp);

          std::cout << j.dump() << std::endl;
        }
	} else {
		std::cerr << "unable to parse invalid json" << std::endl;
	}
  }
  return 0;
}