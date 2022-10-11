#include <array>
#include <SFML/Graphics.hpp>
#include "sfml-addons-color.hpp" // sfadd::Color

auto generate_shapes_array()
{
    const float half_dim = 50.0f;
    static float y = 0.0f;
    std::array<sf::CircleShape,10> shapes;
    shapes.fill( sf::CircleShape(half_dim) );
    for(float d=0.0f; auto& shape : shapes)
       {
        shape.move({d, y});
        d += 1.5f * shape.getRadius();
       }
    y += 2.1f * half_dim;
    return shapes;
}

//----------------------------------------------------------------------
int main()
{
    // Changing color hue
    auto hue_shapes = generate_shapes_array();
    sfadd::Color col{217,54,82,200}; // Let's start with a pretty red
    for(const float d=360.0f/(hue_shapes.size()+1.0f); auto& shape : hue_shapes)
       {
        shape.setFillColor(col);
        col.hue_incr(d);
       }

    // Changing color saturation
    auto desat_shapes = generate_shapes_array();
    col = {255,0,255,200}; // Start with an eyesore
    for(const float d=-1.0f/desat_shapes.size(); auto& shape : desat_shapes)
       {
        shape.setFillColor(col);
        col.sat_incr(d);
       }

    // Changing color luminance
    auto lum_shapes = generate_shapes_array();
    col = {0,0,50,200}; // Start with a very dark blue
    for(const float d=1.0f/lum_shapes.size(); auto& shape : lum_shapes)
       {
        shape.setFillColor(col);
        col.lum_incr(d);
       }

    // Changing color channel
    auto redder_shapes = generate_shapes_array();
    col = {61,188,55,200}; // Start with a green
    for(const std::uint8_t d=255/(redder_shapes.size()-2); auto& shape : redder_shapes)
       {
        shape.setFillColor(col);
        col.redder(d);
       }

    // Changing color channel
    auto cyaner_shapes = generate_shapes_array();
    for(const std::uint8_t d=255/(cyaner_shapes.size()-2); auto& shape : cyaner_shapes)
       {
        shape.setFillColor(col);
        col.cyaner(d);
       }

    std::array all_shapes = { hue_shapes, desat_shapes, lum_shapes, redder_shapes, cyaner_shapes };
    sf::RenderWindow window(sf::VideoMode(800, 800), "colors");
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
        for(const auto& shape_array : all_shapes)
           {
            for(const auto& shape : shape_array)
               {
                window.draw(shape);
               }
           }
        window.display();
       }
    return 0;
}

