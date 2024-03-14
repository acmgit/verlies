#ifndef window_h
#define window_h

#include <string>
#include <SFML/Graphics.hpp>


class Window
{
public:
    Window(const std::string title, sf::Vector2u dimension);
    ~Window();

    bool is_open();
    void clear(sf::Color color);
    void poll();
    void close();

    void set_font(sf::Font);
    void set_pen(int x = 0, int y = 0);
    void set_font_size(int character_size = 8);
    void set_color(sf::Color color);

    int get_font_size();

    void write(const std::string text);
    void write(const sf::Text& text);

    void draw_image(const sf::Sprite gfx_object);
    void update();


private:
    void wait();
    float m_miliseconds;

    sf::RenderWindow m_handle;
    bool m_is_open;

    int m_pen_x;
    int m_pen_y;

    unsigned int m_width;
    unsigned int m_height;

    int m_font_size;
    sf::Color m_color;
    sf::Font m_font;
    std::string m_title;


};

#endif // window_h
