#include <iostream>
#include <graphics.h>
using namespace std;

// Clipping window coordinates
const int xmin = 100, ymin = 100, xmax = 400, ymax = 300;

// Region codes
const int INSIDE = 0; // 0000
const int LEFT = 1;   // 0001
const int RIGHT = 2;  // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8;    // 1000

// Function to compute the region code of a point
int computeCode(int x, int y) {
    int code = INSIDE;

    if (x < xmin) code |= LEFT;
    else if (x > xmax) code |= RIGHT;

    if (y < ymin) code |= BOTTOM;
    else if (y > ymax) code |= TOP;

    return code;
}

// Cohen-Sutherland Line Clipping Algorithm
void cohenSutherlandClip(int x1, int y1, int x2, int y2) {
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);
    bool accept = false;

    while (true) {
        if ((code1 | code2) == 0) {
            // Both endpoints are inside the clipping window
            accept = true;
            break;
        } else if (code1 & code2) {
            // Both endpoints share an outside region (trivially reject)
            break;
        } else {
            // One endpoint is outside the clipping window
            int codeOut;
            int x, y;

            // Choose the outside point
            if (code1 != 0) codeOut = code1;
            else codeOut = code2;

            // Find intersection point
            if (codeOut & TOP) {
                x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
                y = ymax;
            } else if (codeOut & BOTTOM) {
                x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
                y = ymin;
            } else if (codeOut & RIGHT) {
                y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
                x = xmax;
            } else if (codeOut & LEFT) {
                y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
                x = xmin;
            }

            // Replace the outside point with the intersection point
            if (codeOut == code1) {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            } else {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }

    if (accept) {
        setcolor(GREEN);
        line(x1, y1, x2, y2); // Draw the clipped line
    }
}

// Main Function
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    // Draw the clipping rectangle
    setcolor(WHITE);
    rectangle(xmin, ymin, xmax, ymax);

    // Define a line segment
    int x1 = 0, y1 = 100, x2 = 440, y2 = 390;

    // Draw the original line
    setcolor(RED);
    line(x1, y1, x2, y2);

    // Perform line clipping
    cohenSutherlandClip(x1, y1, x2, y2);

    // Wait for user to view the result
    getch();
    closegraph();

    return 0;
}
