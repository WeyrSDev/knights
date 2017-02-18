#include <iostream>

#include "unit_template.h"

namespace ks
{
    UnitTemplate::UnitTemplate(std::string name, ks::NationType nation)
        : _name(name),
        _nation(nation)
    {
        
    }

    UnitTemplate::~UnitTemplate()
    {
    }

    void UnitTemplate::add_animation(
        std::shared_ptr<ks::ResourceMgr>& resource_mgr,
        const std::string name,
        const std::string image,
        const double speed,
        const std::vector<int>& frames)
    {
        auto anim = std::make_shared<ks::Animation>(
            resource_mgr->get_spritesheet(image),
            frames);

        anim->set_speed(speed);

        _animations[name] = anim;
    }

    UnitLibrary::UnitLibrary(std::shared_ptr<ks::ResourceMgr>& resource_mgr)
        : _resource_mgr(resource_mgr)
    {
        ks::UnitLibrary::KnightsArcher
            = std::make_shared<ks::UnitTemplate>(
                "knights_archer", ks::NationType::Knights);

        ks::UnitLibrary::KnightsArcher->add_animation(
            resource_mgr,
            "stand_up",
            "knights_archer_walk",
            1.0,
            {0});
        ks::UnitLibrary::KnightsArcher->add_animation(
            resource_mgr,
            "stand_left",
            "knights_archer_walk",
            1.0,
            {9});
        ks::UnitLibrary::KnightsArcher->add_animation(
            resource_mgr,
            "stand_down",
            "knights_archer_walk",
            1.0,
            {18});
        ks::UnitLibrary::KnightsArcher->add_animation(
            resource_mgr,
            "stand_right",
            "knights_archer_walk",
            1.0,
            {27});

        ks::UnitLibrary::KnightsArcher->add_animation(
            resource_mgr,
            "walk_up",
            "knights_archer_walk",
            0.5,
            {1, 2, 3, 4, 5, 6, 7, 8});
        ks::UnitLibrary::KnightsArcher->add_animation(
            resource_mgr,
            "walk_left",
            "knights_archer_walk",
            0.5,
            {10, 11, 12, 13, 14, 15, 16, 17});
        ks::UnitLibrary::KnightsArcher->add_animation(
            resource_mgr,
            "walk_down",
            "knights_archer_walk",
            0.5,
            {19, 20, 21, 22, 23, 24, 25, 26});
        ks::UnitLibrary::KnightsArcher->add_animation(
            resource_mgr,
            "walk_right",
            "knights_archer_walk",
            0.5,
            {28, 29, 30, 31, 32, 33, 34, 35});
    }

    UnitLibrary::~UnitLibrary()
    {
    }
}