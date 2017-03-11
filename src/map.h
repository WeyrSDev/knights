#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>

#include <boost/config.hpp>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/property_map/property_map.hpp>

#include "resource_mgr.h"
#include "animation.h"
#include "tile.h"
#include "unit.h"
#include "data_loader.h"
#include "game_window.h"

namespace ks
{
    /* Side of each tile */
    const int TILE = 32;

    struct Vertex{
    Vertex(int x, int y, int spritesheet_id, int tile_id)
    : x(x), y(y), spritesheet_id(spritesheet_id), tile_id(tile_id)
            {
            }

        int x, y;
        int spritesheet_id, tile_id;
    };
    struct Edge{};

    typedef boost::adjacency_list<
        boost::vecS,
        boost::vecS,
        boost::undirectedS,
        std::shared_ptr<Vertex>,
        boost::property<boost::edge_weight_t, int> > Graph;

    typedef boost::graph_traits<Graph>::vertex_descriptor vertex_t;
    typedef boost::graph_traits<Graph>::edge_descriptor edge_t;

    class Map
    {
    public:
        Map(std::shared_ptr<ks::ResourceMgr> resource_mgr,
            std::shared_ptr<ks::DataLoader> data_loader,
            std::shared_ptr<ks::GameWindow> window,
            std::string map_name);
        ~Map();

        void update(sf::Time delta);
        void render(sf::RenderWindow& window,
                    std::vector<std::shared_ptr<ks::Unit> >& units);

    private:
        std::unique_ptr<ks::Graph> _graph;

        void load();

        std::shared_ptr<ks::ResourceMgr> _resource_mgr;
        std::shared_ptr<ks::GameWindow> _window;
        std::shared_ptr<ks::DataLoader> _data_loader;

        std::vector<
            std::unique_ptr<ks::Tile>
            > _tiles;

        /* Number of rows */
        int _tiles_rows;

        /* Number of columns */
        int _tiles_cols;

        std::string _map_name;

        int _get_nw(const int v) const;
        int _get_n(const int v) const;
        int _get_ne(const int v) const;
        int _get_e(const int v) const;
        int _get_se(const int v) const;
        int _get_s(const int v) const;
        int _get_sw(const int v) const;
        int _get_w(const int v) const;

        void _add_edge(const int v1, const int v2) const;
        void _build_initial_graph() const;
    };
}

#endif
