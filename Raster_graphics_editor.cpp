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
};


class ClBrush : public ClAbstractTool
{
private:
    Color_t color = TX_BLACK;
    int width = 5;

public:
    ClBrush () : ClAbstractTool () {}

    virtual void Draw (const Coord_t& coords)
    {
        for (int i = 0; i < width; i++)
        {
            for (int k = 0; k < width; k++)
            {
                txSetPixel (coords.x + i - width / 2, coords.y + k - width / 2, RGB (color.red, color.green, color.blue));
            }
        }
    }

    virtual void SetColor (const Color_t& new_color)
    {
        color = new_color;
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


};


class ClDrawingFrame
{
private:
    bool is_clicked = false;
    ClAbstractTool *tool;
    ClViewport view;
    Coord_t left_up;
    Coord_t right_down;


public:
    ClDrawingFrame (ClAbstractTool *tool = nullptr) : left_up    {0,                             ns_global_vars::C_max_y_coord / 8},
                                                      right_down {ns_global_vars::C_max_x_coord, ns_global_vars::C_max_y_coord},
                                                      view (left_up, right_down), tool (tool)
    {
        txSetFillColor (TX_WHITE);
//        txSetFillColor (TX_RED);
        txRectangle (left_up.x, left_up.y, right_down.x, right_down.y);
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

//=============================================================================

void Create_Background ();

//=============================================================================

int main ()
{
    Create_Background ();

    txSleep(1000);

    ClBrush brush;
    ClAbstractTool& a_tool = brush;
    ClDrawingFrame frame(&a_tool);

//    txBegin();
    while (!txGetAsyncKeyState (VK_ESCAPE))
    {
        Coord_t coords = txMousePos();

        frame.MouseClick (coords);

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
//        txSleep ();
    }

//    txEnd();


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
