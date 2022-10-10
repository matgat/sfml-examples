#include <array>
#include <SFML/Graphics.hpp>
#include "sfml-addons-color.hpp" // sfadd::Color


//----------------------------------------------------------------------
int main()
{
    // Some shapes changing color hue
    sfadd::Color col{200,118,118,200}; // Let's start with a pretty pastel red
    std::array<sf::CircleShape,10> shapes;
    shapes.fill( sf::CircleShape(50.0f) );
    for(float d=0.0f; auto& shape : shapes)
       {
        //shape.setFillColor( col.hue_incr(360.f/shapes.size()) );
        shape.setFillColor( col );
        shape.move({d, 0.0f});
        d += 1.5f * shape.getRadius();
       }

    //------------------------------------------------------------------------
    sf::RenderWindow window(sf::VideoMode(800, 800), "pan-zoom-resize");
    while( window.isOpen() )
       {
        sf::Event event;
        while( window.pollEvent(event) )
           {
            switch( event.type )
               {
                case sf::Event::Closed:
                    window.close();
                    break;

                default:
                    break;
               }
           }
        window.clear();
        for(const auto& shape : shapes)
            window.draw(shape);
        window.display();
       }
    return 0;
}

