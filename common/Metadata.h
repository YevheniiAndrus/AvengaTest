#pragma once

struct Box{
    int center_x;
    int center_y;
    int width;
    int height;

    Box(int c_x, int c_y, int w, int h) : 
        center_x(c_x), center_y(c_y),
        width(w), height(h) {}
};

struct Metadata{
    int id{0};
    Box box{0, 0, 0, 0};
};