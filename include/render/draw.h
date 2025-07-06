#pragma once

void engine_render_drawpixel(float x, float y, int color);

/**
 * @brief Fills a rectangle on the screen with a specified color.
 *
 * This function creates a filled rectangle at the given position and size, using
 * the provided color. The color is an integer value that is converted to RGBA,
 * which is then used to set the rendering color before drawing the rectangle.
 *
 * @param ax X coordinate of the top-left corner of the rectangle.
 * @param ay Y coordinate of the top-left corner of the rectangle.
 * @param width Width of the rectangle.
 * @param height Height of the rectangle.
 * @param color Color of the rectangle in hexadecimal format (e.g., 0xRRGGBBAA).
 */
void engine_render_fillrect(float ax, float ay, float width, float height, int color);
