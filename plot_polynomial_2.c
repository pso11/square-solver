/**
 * @file plot_polynomial_2.c
 * @brief graphics file.
 * @author Pshanichnaya Sofia
 * @date 2026-08-28
 */
#include <TXLib.h>
#include <stdio.h>

#include "solving.h"
#include "plot_polynomial_2.h"
#include "input_and_output.h"
#include "choose_color.h"

void plot_polynomial_2(double a, double b, double c, bool CREATING_WINDOW)
{
    /* Задаём постоянные параметры окна */
    const int width = 800;
    const int height = 800;
    const double increment_x = 0.01;
    const int max_number_digits = 10;
    const int marking_density = 80;
    double width_cell_pixels_x = 10;
    double width_cell_pixels_y = 10;
    double scaling_step = 1.5;

    delayed_output("Let's plot a second-order polynomial\n\n", TIME_DELAY);

    if (!CREATING_WINDOW)
        txCreateWindow (width, height);
    
    txBegin();
    txClearConsole();
    txSelectFont ("Comic Sans MS", 20);
    txTextOut(0, 0, "To exit from the scale mode press F");
    txSleep(PAUSE_BEFOR_PLOT);
    txRedrawWindow();

    int number_presses_y = 0, number_presses_x = 0, shift_pixels = 10;
    while (!txGetAsyncKeyState('F'))
    {
        if (txGetAsyncKeyState(down))
            number_presses_y--;
        if (txGetAsyncKeyState(up))
            number_presses_y++;
        if (txGetAsyncKeyState(right))
            number_presses_x--;
        if (txGetAsyncKeyState(left))
            number_presses_x++;
        if (txGetAsyncKeyState(increase_scale_x))
                width_cell_pixels_x *= scaling_step;
        if (txGetAsyncKeyState(decrease_scale_x))
                width_cell_pixels_x /= scaling_step;
         if (txGetAsyncKeyState(increase_scale_y))
                width_cell_pixels_y *= scaling_step;
        if (txGetAsyncKeyState(decrease_scale_y))
                width_cell_pixels_y /= scaling_step;
        
        txSetFillColor(TX_BLACK);
        txClear();

        txLine (0, height / 2 + number_presses_y * shift_pixels, width, height / 2 + number_presses_y * shift_pixels);	
        txLine (width / 2 + number_presses_x * shift_pixels, 0, width /2 + number_presses_x * shift_pixels, height);

        double x_center     = width  /  2  +  number_presses_x * shift_pixels;
        double y_center     = height / 2 + number_presses_y * shift_pixels;
        double y_up_risk    = y_center;
        double y_down_risk  = y_center;
        double x_right_risk = x_center;
        double x_left_risk  = x_center;

        int i = 0;
        while ((y_up_risk > 0 || y_down_risk < height) || (x_right_risk < width || x_left_risk > 0)) 
        {       
            y_up_risk    = y_center - i * marking_density;
            y_down_risk  = y_center + i * marking_density;
            x_right_risk = x_center + i * marking_density;
            x_left_risk  = x_center - i * marking_density;

            txLine(x_center - 5, y_up_risk,   x_center + 5, y_up_risk);                                                
            txLine(x_center - 5, y_down_risk, x_center + 5, y_down_risk); 
            
            txLine(x_right_risk, y_center - 5, x_right_risk, y_center + 5);                                              
            txLine(x_left_risk,  y_center - 5, x_left_risk,  y_center + 5); 
            
            char x_right_point[max_number_digits] = {};
            char x_left_point [max_number_digits] = {};
            char y_up_point   [max_number_digits] = {};
            char y_down_point [max_number_digits] = {};
            snprintf(x_right_point, sizeof(x_right_point), "%.2f",  ((x_right_risk - x_center) / width_cell_pixels_x));
            snprintf(x_left_point,  sizeof(x_left_point),  "%.2f",  ((x_left_risk -  x_center) / width_cell_pixels_x));
            snprintf(y_up_point,    sizeof(y_up_point),    "%.2f", -((y_up_risk -    y_center) / width_cell_pixels_y));
            snprintf(y_down_point,  sizeof(y_down_point),  "%.2f", -((y_down_risk -  y_center) / width_cell_pixels_y));

            if (!compare_doubles(x_right_risk, x_center) && !compare_doubles(x_left_risk, x_center)
                && !compare_doubles(y_up_risk, y_center) && !compare_doubles(y_down_risk, y_center))
            {
                txTextOut(x_right_risk - 7, y_center + 5, x_right_point);
                txTextOut(x_left_risk - 7, y_center + 5, x_left_point);
                txTextOut(x_center + 5, y_up_risk - 7, y_up_point);
                txTextOut(x_center + 5, y_down_risk - 7, y_down_point);
            }
            i++;
        }
        
        double x = 0.0, y = 0.0;
        int val1 = rand() % 256, val2 = rand() % 256, val3 = rand() % 256;
        while (x < width)
        {
            txSetPixel(x, y, RGB (val1, val2, val3));
            x += increment_x;
            y =  height / 2 + number_presses_y * shift_pixels - width_cell_pixels_y * (a * (x - width / 2 - shift_pixels * number_presses_x) * 
                 (x - width / 2 - shift_pixels * number_presses_x) / (width_cell_pixels_x * width_cell_pixels_x) + b * 
                 (x - width / 2 - shift_pixels * number_presses_x) / width_cell_pixels_x + c); 
        }
        txRedrawWindow();
    }
    txClear();
    buffer_cleaning();
}