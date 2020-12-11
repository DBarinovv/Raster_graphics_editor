
// auxiliary.h

//=============================================================================

struct Color_t
{
    Color_t (const int r = 255, const int gr = 255, const int bl = 255) : red (r), green (gr), blue (bl) {}

    int red   = 255;
    int green = 255;
    int blue  = 255;

    bool operator== (const Color_t& other)
    {
        return (this->red == other.red && this->green == other.green && this->blue == other.blue);
    }

    bool operator!= (const Color_t& other)
    {
        return !(*this == other);
    }

    void Print ()
    {
        printf ("Red = [%d], Green = [%d], Blue = [%d]\n", red, green, blue);
    }

    ~Color_t() = default;
};

//-----------------------------------------------------------------------------

struct Coord_t
{
    Coord_t (const int x = 0, const int y = 0) : x (x), y (y) {}
    Coord_t (POINT point) : x (point.x), y (point.y) {}
    operator POINT () { return {x, y}; }

    Coord_t            (const Coord_t& other) = default;
    Coord_t& operator= (const Coord_t& other) = default;

    int x = 0;
    int y = 0;

    void Print (std::string str = "") const
    {
        printf ("%s: x coord = [%d], y coord = [%d]\n", str.c_str(), x, y);
    }

    ~Coord_t() = default;
};

//-----------------------------------------------------------------------------

namespace ns_colors
{
    Color_t C_black   ( 0,   0,   0   );
    Color_t C_blue    ( 0,   0,   128 );
    Color_t C_green   ( 0,   128, 0   );
    Color_t C_cyan    ( 0,   128, 128 );
    Color_t C_red     ( 128, 0,   0   );
    Color_t C_magenta ( 128, 0,   128 );
    Color_t C_brown   ( 128, 128, 0   );
    Color_t C_orange  ( 255, 128, 0   );
    Color_t C_gray    ( 160, 160, 160 );
    Color_t C_yellow  ( 255, 255, 128 );
    Color_t C_white   ( 255, 255, 255 );
}
