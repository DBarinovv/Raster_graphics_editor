
// viewport.h

namespace { namespace TX { namespace Win32 {
    _TX_DLLIMPORT ("GDI32", HRGN,  CreateRectRgn, (int x0, int y0, int x1, int y1));
}}}

class ClViewport
{
public:
    ClViewport (const Coord_t lu = {0, 0},
                const Coord_t rd = {ns_global_vars::C_max_x_coord, ns_global_vars::C_max_y_coord}) :
                new_region (Win32::CreateRectRgn (lu.x, lu.y, rd.x, rd.y)),
                left_up (lu), right_down (rd) {};

    virtual ~ClViewport ()
    {
        Win32::DeleteObject (new_region);
    }

    // change
    ClViewport (const ClViewport&) = default;
    ClViewport (ClViewport&& dead_viewport) : new_region (std::move (dead_viewport.new_region)) {}

    ClViewport& operator=(const ClViewport&) = default;
    ClViewport& operator=(ClViewport&& dead_viewport)
    {
        new_region = std::move (dead_viewport.new_region);

        return *this;
    }


    HRGN Ret_Region () { return new_region; }

    void Make_Region ()
    {
        Win32::SelectObject (txDC(), new_region);
    }

    void Remove_Region ()
    {
        Win32::SelectObject (txDC(), ns_global_vars::main_region);
    }

    int Get_And_Change_LU_Y (int offset = 0) { left_up.y    += offset; return left_up.y; }
    int Get_And_Change_RD_Y (int offset = 0) { right_down.y += offset; return right_down.y; }
    int Get_And_Change_LU_X (int offset = 0) { left_up.x    += offset; return left_up.x; }
    int Get_And_Change_RD_X (int offset = 0) { right_down.x += offset; return right_down.x; }

private:
    HRGN new_region;
    Coord_t left_up;
    Coord_t right_down;
};
