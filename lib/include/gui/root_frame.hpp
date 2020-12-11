#ifndef ROOT_FRAME_HPP_
#define ROOT_FRAME_HPP_

#include <SFML/Graphics.hpp>
#include <string_view>


namespace raspify::gui 
{
    class RootFrame
    {
    public:
        RootFrame() {
            _window.create({ 640, 480 }, "Raspify");
            _window.setFramerateLimit(60);
        }

        inline void loop() 
        {
            using namespace sf;
            while (_window.isOpen())
            {
                Event event;
                while (_window.pollEvent(event))
                {
                    if (event.type == Event::Closed)
                        return;
                }
                
                _window.setActive();
                // TODO
                _window.display();
            }
        }


        ~RootFrame() {
            _window.close();
        }

    private: 
        sf::RenderWindow _window;
    };
}

#endif // !ROOT_FRAME_HPP_