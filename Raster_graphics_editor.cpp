#include "D:\TX\TxLib.h"

#include "main_header.h"

//=============================================================================

class ClAbstractTool
{
private:


public:
     ClAbstractTool () = default;
    ~ClAbstractTool () = default;

    virtual void Draw     (const Coord_t& coords)    { PR_LOG }
    virtual void SetColor (const Color_t& new_color) { PR_LOG }
    virtual Color_t GetColor ()                      { PR_LOG }
    virtual void SetSize  (const int& new_size)      { PR_LOG }
    virtual int GetSize ()                           { PR_LOG }
    virtual void SetClicked ()                       { PR_LOG }
    virtual void SetNoClicked ()                     { PR_LOG }
};


class ClBrush : public ClAbstractTool
{
private:
    Color_t color = ns_colors::C_black;
    int width = 5;
    bool is_clicked = false;
    Coord_t last_coords;

public:
    ClBrush () : ClAbstractTool () {}

    virtual void Draw (const Coord_t& coords)
    {
        SetColor (color);

        for (int i = 0; i < width; i++)
        {
            for (int k = 0; k < width; k++)
            {
                txSetPixel (coords.x + i - width / 2, coords.y + k - width / 2, RGB (color.red, color.green, color.blue));
            }
        }

        Coord_t p1, p2, p3, p4;


        int prev_width = width;

        if (is_clicked)
        {
            width /= 2;

            if (last_coords.y > coords.y)
            {
                if (last_coords.x > coords.x)
                {
                    p1 = {     coords.x - width,      coords.y + width};
                    p2 = {     coords.x + width,      coords.y - width};

                    p3 = {last_coords.x + width, last_coords.y - width};
                    p4 = {last_coords.x - width, last_coords.y + width};

                }
                else
                {
                    p1 = {     coords.x - width,      coords.y - width};
                    p2 = {     coords.x + width,      coords.y + width};

                    p3 = {last_coords.x + width, last_coords.y + width};
                    p4 = {last_coords.x - width, last_coords.y - width};

                }
            }
            else
            {
                if (last_coords.x > coords.x)
                {
                    p1 = {     coords.x - width,      coords.y - width};
                    p2 = {     coords.x + width,      coords.y + width};

                    p3 = {last_coords.x + width, last_coords.y + width};
                    p4 = {last_coords.x - width, last_coords.y - width};

                }
                else
                {
                    p1 = {     coords.x - width,      coords.y + width};
                    p2 = {     coords.x + width,      coords.y - width};

                    p3 = {last_coords.x + width, last_coords.y - width};
                    p4 = {last_coords.x - width, last_coords.y + width};

                }
            }

            POINT arr[4] = {p1, p2, p3, p4};

            width = prev_width;

            txPolygon (arr, 4);

//            txSleep (3000);
        }

        last_coords = coords;
        is_clicked = true;
    }

    virtual void SetColor (const Color_t& new_color)
    {
        color = new_color;

        txSetFillColor (RGB (color.red, color.green, color.blue));
        txSetColor     (RGB (color.red, color.green, color.blue));
    }

    virtual Color_t GetColor ()
    {
        return color;
    }

    virtual void SetSize (const int& new_size)
    {
        width = new_size;

        Clamp (width, ns_global_vars::C_min_width, ns_global_vars::C_max_width);
    }

    virtual int GetSize ()
    {
        return width;
    }

    virtual void SetClicked ()
    {
        is_clicked = true;
    }

    virtual void SetNoClicked ()
    {
        is_clicked = false;
    }
};

class ClEraser : public ClAbstractTool
{
private:
    Color_t color = ns_colors::C_white;
    int width = 5;
    bool is_clicked = false;
    Coord_t last_coords;

public:
    ClEraser () : ClAbstractTool () {}

    virtual void Draw (const Coord_t& coords)
    {
        SetColor (color);

        for (int i = 0; i < width; i++)
        {
            for (int k = 0; k < width; k++)
            {
                txSetPixel (coords.x + i - width / 2, coords.y + k - width / 2, RGB (color.red, color.green, color.blue));
            }
        }

        Coord_t p1, p2, p3, p4;


        int prev_width = width;

        if (is_clicked)
        {
            width /= 2;

            if (last_coords.y > coords.y)
            {
                if (last_coords.x > coords.x)
                {
                    p1 = {     coords.x - width,      coords.y + width};
                    p2 = {     coords.x + width,      coords.y - width};

                    p3 = {last_coords.x + width, last_coords.y - width};
                    p4 = {last_coords.x - width, last_coords.y + width};

                }
                else
                {
                    p1 = {     coords.x - width,      coords.y - width};
                    p2 = {     coords.x + width,      coords.y + width};

                    p3 = {last_coords.x + width, last_coords.y + width};
                    p4 = {last_coords.x - width, last_coords.y - width};

                }
            }
            else
            {
                if (last_coords.x > coords.x)
                {
                    p1 = {     coords.x - width,      coords.y - width};
                    p2 = {     coords.x + width,      coords.y + width};

                    p3 = {last_coords.x + width, last_coords.y + width};
                    p4 = {last_coords.x - width, last_coords.y - width};

                }
                else
                {
                    p1 = {     coords.x - width,      coords.y + width};
                    p2 = {     coords.x + width,      coords.y - width};

                    p3 = {last_coords.x + width, last_coords.y - width};
                    p4 = {last_coords.x - width, last_coords.y + width};

                }
            }

            POINT arr[4] = {p1, p2, p3, p4};

            width = prev_width;

            txPolygon (arr, 4);
        }

        last_coords = coords;
        is_clicked = true;
    }

    virtual void SetColor (const Color_t& new_color)
    {
        color = new_color;

        txSetFillColor (RGB (color.red, color.green, color.blue));
        txSetColor     (RGB (color.red, color.green, color.blue));
    }

    virtual Color_t GetColor ()
    {
        return color;
    }

    virtual void SetSize (const int& new_size)
    {
        width = new_size;

        Clamp (width, ns_global_vars::C_min_width, ns_global_vars::C_max_width);
    }

    virtual int GetSize ()
    {
        return width;
    }

    virtual void SetClicked ()
    {
        is_clicked = true;
    }

    virtual void SetNoClicked ()
    {
        is_clicked = false;
    }
};



class ClDrawingFrame
{
private:
    bool is_clicked = false;
    ClAbstractTool *tool;
    ClViewport view;
    Coord_t left_up;
    Coord_t right_down;
    Coord_t last_coords;


public:
    ClDrawingFrame (ClAbstractTool *tool = nullptr) : left_up    {0,                             ns_global_vars::C_max_y_coord / 8},
                                                      right_down {ns_global_vars::C_max_x_coord, ns_global_vars::C_max_y_coord},
                                                      view (left_up, right_down), tool (tool)
    {
        COLORREF prev_color = txGetFillColor ();
        txSetFillColor (TX_WHITE);

        txRectangle (left_up.x, left_up.y, right_down.x, right_down.y);

        txSetFillColor (prev_color);
    }

    void MouseClick (const Coord_t& coords)
    {
        Draw (coords);
    }

    void SetTool (ClAbstractTool *new_tool)
    {
        tool = new_tool;
    }

    ClAbstractTool *GetTool ()
    {
        return tool;
    }

    void Draw (const Coord_t& coords)
    {
        tool->Draw (coords);
    }

    void SetClicked ()
    {
        is_clicked = true;

        tool->SetClicked ();
    }

    void SetNoClicked ()
    {
        is_clicked = false;

        tool->SetNoClicked ();
    }

};

class ClAbstractWindow
{
public:
    ClAbstractWindow (const Coord_t lu = {}, const Coord_t rd = {}) {}

    virtual ~ClAbstractWindow ()                         = default;

    ClAbstractWindow (const ClAbstractWindow&)           = default;
    ClAbstractWindow (ClAbstractWindow&&)                = default;

    ClAbstractWindow& operator=(const ClAbstractWindow&) = default;
    ClAbstractWindow& operator=(ClAbstractWindow&&)      = default;

    virtual bool Draw ()                           { PR_LOG }
    virtual bool MouseOver  (const Coord_t coords) { PR_LOG }
    virtual bool MouseOut   () { PR_LOG }
    virtual bool MouseClick (const Coord_t coords, const ClAbstractWindow *last_window) { PR_LOG }
    virtual bool Coord_In   (const Coord_t coords) { PR_LOG }

//    void Print () { printf ("%p\n", this); }
};

class ClRectButton
{
private:

    Coord_t left_up;
    Coord_t right_down;


public:
    ClRectButton (const Coord_t lu = {}, const Coord_t rd = {}) :
                    left_up (lu), right_down (rd) {}

    virtual bool Coord_In (const Coord_t& coords) { PR_LOG }
};


class ClToolRectButton : public ClRectButton
{
private:
    ClAbstractTool *tool;

    Coord_t left_up;
    Coord_t right_down;

public:
    ClToolRectButton (const Coord_t lu = {}, const Coord_t rd = {}) :
                    ClRectButton (lu, rd), left_up (lu), right_down (rd) {}

    virtual bool Coord_In (const Coord_t& coords) { PR_LOG }
};

class ClApplication
{
private:
    ClDrawingFrame frame;
    std::vector<ClAbstractWindow *> arr_of_windows;

public:

    ClApplication (const ClDrawingFrame&& old_frame) : frame (old_frame) {}

    void Start_Program ()
    {
        ClEraser er;
        ClAbstractTool& a_tool = er;
        ClDrawingFrame frame2(&a_tool);
        frame2.GetTool()->SetColor (ns_colors::C_white);

        int is_clicked = 0;
        while (!txGetAsyncKeyState (VK_ESCAPE))
        {
            Coord_t coords = txMousePos();

            is_clicked = txMouseButtons ();

            if (is_clicked != 3)
            {
                if (is_clicked & 1)
                {
                    frame.MouseClick (coords);
                }
                else if (is_clicked & 2)
                {
                    frame2.MouseClick (coords);
                }
                else
                {
                    frame. GetTool()->SetNoClicked ();
                    frame2.GetTool()->SetNoClicked ();
                }
            }
            else
            {
                frame. GetTool()->SetNoClicked ();
                frame2.GetTool()->SetNoClicked ();
            }

            if (txGetAsyncKeyState (VK_UP))
            {
                int size = frame.GetTool()->GetSize ();
                frame.GetTool()->SetSize (size * 2);
                txSleep (100);
            }
            else if (txGetAsyncKeyState (VK_DOWN))
            {
                int size = frame.GetTool()->GetSize ();
                frame.GetTool()->SetSize (size / 2);
                txSleep (100);
            }
        }
    }
};

//=============================================================================

void Create_Background ();

//=============================================================================

int main ()
{
    // inheritance buttons
    // application
    // make buttons
    // make textures

    Create_Background ();

    ClBrush brush;
    ClAbstractTool& a_tool = brush;
    ClDrawingFrame frame(&a_tool);

    frame.GetTool()->SetColor (ns_colors::C_black);

    ClApplication appl(std::move (frame));
    appl.Start_Program ();


    return 0;
}

//=============================================================================

void Create_Background ()
{
    txCreateWindow (ns_global_vars::C_max_x_coord, ns_global_vars::C_max_y_coord);
    txSetFillColor (TX_WHITE);
    txRectangle (0, 0, ns_global_vars::C_max_x_coord, ns_global_vars::C_max_y_coord);

    txSetFillColor (TX_GRAY);
    txRectangle (0, 0, ns_global_vars::C_max_x_coord, ns_global_vars::C_max_y_coord / 8);
}
