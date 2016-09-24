#ifndef DATA_LOADER_H
#define DATA_LOADER_H

#include <memory>
#include <unordered_map>
#include <sstream>
#include <fstream>

#include <SFML/Graphics.hpp>

#include "../thirdparty/json/src/json.hpp"

using json = nlohmann::json;

namespace ks
{
    class DataLoader
    {
    public:
        DataLoader();
        ~DataLoader();

        void load_jsons();

        const json& get_json(const std::string name);
        const json& load_map(const std::string filename);

    private:
        void load_json(std::string path, std::string identifier);
        std::unordered_map<std::string, json> _jsons;
        json _map;
    };
}

#endif
