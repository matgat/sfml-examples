#include <array>
#include <SFML/Graphics.hpp>
#include "sfml-addons-view.hpp" // sfadd::View


//----------------------------------------------------------------------
int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "pan-zoom-resize");
    sfadd::View view{ window }; // The magic happens here

    // Define some shapes, just to show something
    std::array shapes = { sf::CircleShape(50.0f),
                          sf::CircleShape(100.0f),
                          sf::CircleShape(200.0f) };
    for(float d=200.0f; auto& shape : shapes)
       {
        shape.setFillColor( {100,150,200,200} );
        shape.setPosition(d, d);
        d += shape.getRadius()/1.1f;
       }

    while( window.isOpen() )
       {
        sf::Event event;
        while( window.pollEvent(event) )
           {
            switch( event.type )
               {
                case sf::Event::Resized:
                    view.resize(event.size.width, event.size.height);
                    break;

                case sf::Event::MouseButtonPressed:
                    if( event.mouseButton.button==sf::Mouse::Left )
                       {
                        view.pan_init({event.mouseButton.x, event.mouseButton.y});
                       }
                    break;

                case sf::Event::MouseButtonReleased:
                    view.pan_end();
                    break;

                case sf::Event::MouseMoved:
                    if( view.panning() )
                       {
                        view.pan({event.mouseMove.x, event.mouseMove.y});
                       }
                    break;

                case sf::Event::MouseWheelScrolled:
                    view.zoom({event.mouseWheelScroll.x, event.mouseWheelScroll.y}, event.mouseWheelScroll.delta>0);
                    break;

                case sf::Event::Closed:
                    window.close();
                    break;

                default:
                    break;
               }
           }

        window.clear();
        view.draw_grid(100, 100, sf::Color{50,50,50});

        for(const auto& shape : shapes)
            window.draw(shape);

        window.display();
       }

    return 0;
}

