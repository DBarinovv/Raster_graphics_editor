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
    ClAbstractTool *tool = nullptr;
    Coord_t left_up;
    Coord_t right_down;
    Coord_t last_coords;

    ClViewport view;


public:
    ClDrawingFrame (ClAbstractTool *tool = nullptr) : left_up    (0,                             ns_global_vars::C_max_y_coord / 8),
                                                      right_down (ns_global_vars::C_max_x_coord, ns_global_vars::C_max_y_coord),
                                                      view (left_up, right_down), tool (tool)
    {
        COLORREF prev_color = txGetFillColor ();
        txSetFillColor (TX_WHITE);

        txRectangle (left_up.x, left_up.y, right_down.x, right_down.y);

        txSetFillColor (prev_color);
    }

    ~ClDrawingFrame () = default;

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
        if (!tool) return;

        view.Make_Region ();
        tool->Draw (coords);
        view.Remove_Region ();
    }

    void SetClicked ()
    {
        if (!tool) return;

        is_clicked = true;

        tool->SetClicked ();
    }

    void SetNoClicked ()
    {
        if (!tool) return;

        is_clicked = false;

        tool->SetNoClicked ();
    }

    bool Coord_In (const Coord_t coords)
    {
        return coords.x <= right_down.x && coords.x >= left_up.x &&
               coords.y <= right_down.y && coords.y >= left_up.y;
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

    virtual bool Draw ()                             { PR_LOG }
    virtual bool MouseOver  ()                       { PR_LOG }
    virtual bool MouseOut   ()                       { PR_LOG }
    virtual bool MouseClick ()                       { PR_LOG }
    virtual bool Coord_In (const Coord_t coords)     { PR_LOG return false; }
    virtual void SetNoFocused ()                     { PR_LOG }
    virtual ClAbstractTool *GetTool ()               { PR_LOG }
};

class ClRectButton : public ClAbstractWindow
{
private:

    Coord_t left_up;
    Coord_t right_down;


public:
    ClRectButton (const Coord_t lu = {}, const Coord_t rd = {}) :
                  ClAbstractWindow (lu, rd), left_up (lu), right_down (rd) {}

    virtual ~ClRectButton () = default;

    virtual bool Draw ()                             { PR_LOG }
    virtual bool MouseOver  ()                       { PR_LOG }
    virtual bool MouseOut   ()                       { PR_LOG }
    virtual bool MouseClick ()                       { PR_LOG }
    virtual bool Coord_In (const Coord_t coords)     { PR_LOG }
    virtual void SetNoFocused ()                     { PR_LOG }
    virtual ClAbstractTool *GetTool ()               { PR_LOG }
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

    virtual ~ClToolRectButton () = default;

    virtual bool Draw ()                             { PR_LOG }
    virtual bool MouseOver  ()                       { PR_LOG }
    virtual bool MouseOut   ()                       { PR_LOG }
    virtual bool MouseClick ()                       { PR_LOG }
    virtual bool Coord_In (const Coord_t coords)     { PR_LOG }
    virtual void SetNoFocused ()                     { PR_LOG }
    virtual ClAbstractTool *GetTool ()               { PR_LOG }
};

class ClTextureToolRectButton : public ClToolRectButton
{
private:
    ClAbstractTool *tool = nullptr;

    Coord_t left_up;
    Coord_t right_down;
    HDC texture;
    HDC texture_over;
    HDC texture_now;
    std::string path;

    bool is_focused = false;

public:
    ClTextureToolRectButton (const Coord_t lu = {}, const Coord_t rd = {}, const std::string& image = "", ClAbstractTool *tool = nullptr) :
                        ClToolRectButton (lu, rd), left_up (lu), right_down (rd), path ("Resources\\Images\\"), tool (tool)
    {
        path += image;
        path += ".bmp";
        texture = NOtxLoadImage (path.c_str(), IMAGE_BITMAP, LR_LOADFROMFILE,
                                                                            right_down.x - left_up.x,
                                                                            right_down.y - left_up.y);

        texture_now = texture;

        path = "Resources\\Images\\";
        path += image;
        path += "Over.bmp";

        texture_over = NOtxLoadImage (path.c_str(), IMAGE_BITMAP, LR_LOADFROMFILE,
                                                                            right_down.x - left_up.x,
                                                                            right_down.y - left_up.y);


        if (!texture_over)
        {
            texture_over = texture;

            printf ("WAS, path = [%s]\n", path.c_str());
        }

        if (!texture)
        {
            std::string out = "�� ���� ��������� ��������(\nPath = ";
            out += path;

            txMessageBox (out.c_str(), "��, � ���������� ��� �� �������");
        }
    }

    virtual ~ClTextureToolRectButton ()
    {
        txDeleteDC (texture);
        txDeleteDC (texture_over);
        txDeleteDC (texture_now);
    };


    virtual bool Draw ()
    {
        txBitBlt (txDC(), left_up.x, left_up.y, right_down.x, right_down.y, texture_now, 0, 0);
    }

    virtual bool MouseOver ()
    {
        texture_now = texture_over;
//        Draw ();
    }

    virtual bool MouseOut ()
    {
        if (!is_focused)
        {
            texture_now = texture;

            is_focused = false;
        }
    }

    virtual bool MouseClick ()
    {
        texture_now = texture_over;

        is_focused = true;
    }

    virtual bool Coord_In (const Coord_t coords)
    {
        return coords.x <= right_down.x && coords.x >= left_up.x &&
               coords.y <= right_down.y && coords.y >= left_up.y;
    }

    virtual void SetNoFocused ()
    {
        is_focused = false;

        texture_now = texture;
    }

    virtual ClAbstractTool *GetTool ()
    {
        return tool;
    }
};

class ClApplication
{
private:
    ClDrawingFrame frame;
    std::vector<ClAbstractWindow *> arr_of_windows;

public:

    ClApplication (const ClDrawingFrame& old_frame) : frame (old_frame) {}

    void Add_Window (ClAbstractWindow *new_window)
    {
        arr_of_windows.push_back (new_window);
    }

    void Draw ()
    {
        for (auto& window : arr_of_windows)
        {
            window->Draw ();
        }
    }

    void Mouse_Over_Out (const Coord_t coords, ClAbstractWindow **last_window_over)
    {
        for (int i = arr_of_windows.size() - 1; i >= 0; i--)
        {
            if (arr_of_windows[i]->Coord_In (coords))
            {
                arr_of_windows[i]->MouseOver ();

                if (arr_of_windows[i] != (*last_window_over))
                {
                    (*last_window_over)->MouseOut ();
                    (*last_window_over) = arr_of_windows[i];
                }

                break;
            }

            if (i == 0)
            {
                (*last_window_over)->MouseOut ();
                (*last_window_over) = arr_of_windows[i];
            }
        }
    }

    void Mouse_Click (const Coord_t coords, int *is_clicked, ClAbstractWindow **last_window_clicked)
    {
        if (*is_clicked != 0)
        {
            if (frame.Coord_In (coords))
            {
                if (*is_clicked & 1)
                {
                    frame.MouseClick (coords);
                }
            }
            else
            {
                for (int i = arr_of_windows.size() - 1; i >= 0; i--)
                {
                    if (arr_of_windows[i]->Coord_In (coords))
                    {
                        (*last_window_clicked)->SetNoFocused ();
                        arr_of_windows[i]->MouseClick ();

                        if (arr_of_windows[i]->GetTool ())
                        {
                            frame.SetTool (arr_of_windows[i]->GetTool ());
                        }

                        (*last_window_clicked) = arr_of_windows[i];

                        break;
                    }
                }
            }
        }
        else
        {
            frame.GetTool()->SetNoClicked ();
        }
    }

    void Start_Program ()
    {
        ns_global_vars::main_region = Win32::CreateRectRgn (0, 0, ns_global_vars::C_max_x_coord, ns_global_vars::C_max_y_coord);

        ClAbstractWindow *last_window_over    = arr_of_windows[0];
        ClAbstractWindow *last_window_clicked = arr_of_windows[1];
        last_window_clicked->MouseClick ();

        int is_clicked = 0;
        while (!txGetAsyncKeyState (VK_ESCAPE))
        {
            Draw ();

            Coord_t coords = txMousePos ();

            is_clicked = txMouseButtons ();

            Mouse_Over_Out (coords, &last_window_over);

            Mouse_Click (coords, &is_clicked, &last_window_clicked);

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
    // manager (is_clicked, width, ...)

    Create_Background ();

    ClBrush brush;
    ClAbstractTool& brush_tool = brush;
    ClDrawingFrame frame(&brush_tool);

    ClEraser eraser;
    ClAbstractTool& eraser_tool = eraser;

    frame.GetTool()->SetColor (ns_colors::C_black);

    ClTextureToolRectButton but ({15,  15}, {100, 100}, "Brush",  &brush_tool);
    ClAbstractWindow& but_in = but;
    ClTextureToolRectButton but2({115, 15}, {200, 100}, "Eraser", &eraser_tool);
    ClAbstractWindow& but_in2 = but2;


    ClApplication appl(frame);

    appl.Add_Window (new ClAbstractWindow({0, 0}, {ns_global_vars::C_max_x_coord, ns_global_vars::C_max_y_coord}));
    appl.Add_Window (&but_in);
    appl.Add_Window (&but_in2);

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
