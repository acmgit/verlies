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
    void write(const sf::Color color, const std::string text);
    void draw_image(const sf::Sprite gfx_object);


private:
    sf::RenderWindow m_handle;
    bool m_is_open;

    int m_pen_x;
    int m_pen_y;

    unsigned int m_width;
    unsigned int m_height;

    int m_font_size;
    sf::Font m_font;
    std::string m_title;


};

#endif // window_h
