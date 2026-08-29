/**
 * @file plot_polynomial_2.h
 * @brief graphics header file.
 * @author Pshanichnaya Sofia
 * @date 2026-08-28
 */

/**
 * @brief  Creates a graphics window and draws a second-order polynomial in it.
 * @param[in] a The coefficient before x^2
 * @param[in] b The coefficient before x
 * @param[in] c The constant term.
 * @see delayed_output(), buffer_cleaning()
 */
void plot_polynomial_2(double a, double b, double c, bool CREATING_WINDOW);

/**
 * @brief  Enum with the name of the key actions and their virtual codes.
 */
enum virtual_codes
{
    up = 38,                ///<moves plot up
    down = 40,              ///<moves plot down
    left = 37,              ///<moves plot to left
    right = 39,             ///<moves plot to right
    increase_scale_x = 106, ///<increases the scale along x-asis
    decrease_scale_x = 111, ///<decreases the scale along x-asis
    increase_scale_y = 56,  ///<increases the scale along y-asis
    decrease_scale_y = 191  ///<decreases the scale along y-asis
};

/**
 * @brief  .
 * @details function RGB(..., ..., ...) returns hexadecimal color code
 */ 
#define  TX_BLACK RGB ( 0, 0, 0)
#define  TX_BLUE RGB ( 0, 0, 128)
#define  TX_GREEN RGB ( 0, 128, 0)
#define  TX_CYAN RGB ( 0, 128, 128)
#define  TX_RED RGB (128, 0, 0)
#define  TX_MAGENTA RGB (128, 0, 128)
#define  TX_BROWN RGB (128, 128, 0)
#define  TX_ORANGE RGB (255, 128, 0)
#define  TX_GRAY RGB (103, 112, 106)
#define  TX_DARKGRAY RGB (128, 128, 128)
#define  TX_LIGHTGRAY RGB (192, 192, 192)
#define  TX_LIGHTBLUE RGB ( 0, 0, 255)
#define  TX_LIGHTGREEN RGB ( 0, 255, 128)
#define  TX_LIGHTCYAN RGB ( 0, 255, 255)
#define  TX_LIGHTRED RGB (255, 0, 128)
#define  TX_LIGHTMAGENTA RGB (255, 0, 25)
#define  TX_PINK RGB (255, 128, 255)
#define  TX_YELLOW RGB (255, 255, 128)
#define  TX_WHITE RGB (255, 255, 255)
#define  TX_NULL 0xFFFFFFF
#define  TX_HUE 0x04000000
#define  TX_SATURATION 0x05000000
#define  TX_LIGHTNESS 0x06000000
#define  TX_LAB_L 0x07000000
#define  TX_LAB_A 0x08000000
#define  TX_LAB_B 0x09000000

/**
 * @brief  Pause befor plotting second-order polynomial
 */ 
#define PAUSE_BEFOR_PLOT 5000
