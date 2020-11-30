
// config.h

namespace ns_global_vars
{
    FILE *log_file = fopen ("log_raster_graphic_editor.txt", "w");

    const int C_max_x_coord = 1500;
    const int C_max_y_coord = 900;

    const int C_min_width = 3;
    const int C_max_width = 150;

    HRGN main_region;
}
