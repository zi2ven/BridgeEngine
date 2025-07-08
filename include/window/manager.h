#pragma once
#include <algorithm>
#include <memory>
#include <vector>

#include "window.hpp"

namespace BE
{
    class WindowManager
    {
    public:
        template <typename... A>
        IWindow* create(A&&... a)
        {
            wins.emplace_back(std::make_unique<SdlWindow>(std::forward<A>(a)...));
            return wins.back().get();
        }

        bool tick()
        {
            for (const auto& w : wins) { w->pollEvents(); }
            wins.erase(std::remove_if(wins.begin(), wins.end(),
                                      [](auto& p) { return p->shouldClose(); }), wins.end());
            return !wins.empty();
        }

    private:
        std::vector<std::unique_ptr<IWindow>> wins;
    };
}
