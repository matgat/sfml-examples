#include <vector>
#include <SFML/Graphics.hpp>
#include "sfml-addons-color.hpp" // sfadd::Color


//////////////////////////////////////////////////////////////////////////////
// A facility to generate some shapes
class ShapeArrays
{
 private:
    std::vector<std::vector<sf::CircleShape>> m_shapes;

    static auto generate_shape_array(const std::size_t n)
       {
        std::vector<sf::CircleShape> shapes;
        shapes.reserve(n);
        const float half_dim = 50.0f;
        const float dx = 1.5f * half_dim;
        static float y = 0.0f;
        for( std::size_t i=0; i<n; ++i )
           {
            auto& shape = shapes.emplace_back(half_dim);
            shape.move({static_cast<float>(i)*dx, y});
           }
        y += 2.1f * half_dim;
        return shapes;
       }

 public:
    auto& add_shape_array(const std::size_t n)
       {
        m_shapes.push_back(generate_shape_array(n));
        return m_shapes.back();
       }

    [[nodiscard]] auto begin() const noexcept { return m_shapes.cbegin(); }
    [[nodiscard]] auto end() const noexcept { return m_shapes.cend(); }
};


//----------------------------------------------------------------------
int main()
{
    const std::size_t n = 10; // How many shapes per row
    ShapeArrays all_shapes;


    // Let's have some fun with colors

    // Changing color hue
    sfadd::Color col{217,54,82,200}; // Let's start with a pretty red
    for(const float delta=360.0f/(static_cast<float>(n)+1.0f);
        auto& shape : all_shapes.add_shape_array(n))
       {
        shape.setFillColor(col);
        col.hue_incr(delta); // <== Here the magic
       }

    // Changing color saturation
    col = {255,0,255,200}; // Start with an eyesore
    for(const float delta=-1.0f/static_cast<float>(n);
        auto& shape : all_shapes.add_shape_array(n))
       {
        shape.setFillColor(col);
        col.sat_incr(delta); // <== Here the magic
       }

    // Changing color luminance
    col = {0,0,50,200}; // Start with a very dark blue
    for(const float delta=1.0f/static_cast<float>(n);
        auto& shape : all_shapes.add_shape_array(n))
       {
        shape.setFillColor(col);
        col.lum_incr(delta); // <== Here the magic
       }

    // Changing color channels
    const std::uint8_t delta_rgb = 255/(n-4);
    col = {61,188,55,200}; // Start with a green
    for(auto& shape : all_shapes.add_shape_array(n))
       {
        shape.setFillColor(col);
        col.redder(delta_rgb); // <== Here the magic
       }
    for(auto& shape : all_shapes.add_shape_array(n))
       {
        shape.setFillColor(col);
        col.bluer(delta_rgb); // <== Here the magic
       }
    for(auto& shape : all_shapes.add_shape_array(n))
       {
        shape.setFillColor(col);
        col.greener(delta_rgb); // <== Here the magic
       }



    // Draw shapes
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

