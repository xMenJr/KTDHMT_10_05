#include "glut.h"
#include <math.h>
#include <thread>
#include <chrono>

# include <iostream>
using namespace std;

static float  megh_t = 0.0;
static float  drop_t = 0.0;

//void triangle()
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor3f(0.88, 0.88, 0.88);
//	glPointSize(4.0);
//	glBegin(GL_TRIANGLES);
//	glVertex2f(0.0, 768.0);
//	glVertex2f(0.0, 748.0);
//	glVertex2f(70.0, 748.0);
//	glEnd();
//	glFlush();
//
//	glBegin(GL_LINE_LOOP);
//	glColor3f(0.0, 0.0, 0.0);
//	glVertex2f(0.0, 768.0);
//	glVertex2f(0.0, 748.0);
//	glVertex2f(70.0, 748.0);
//
//	glEnd();
//	glFlush();
//
//}

void triangle()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Thêm GL_DEPTH_BUFFER_BIT để xóa bộ đệm độ sâu
	glColor3f(0.88, 0.88, 0.88);
	glPointSize(4.0);

	glBegin(GL_TRIANGLES);
	glVertex3f(0.0, 0.0, 0.0); // Điểm đầu tiên của tam giác
	glVertex3f(0.0, 20.0, 0.0); // Điểm thứ hai của tam giác
	glVertex3f(10.0, 20.0, 0.0); // Điểm thứ ba của tam giác
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, 0.0); // Điểm đầu tiên của đường viền
	glVertex3f(0.0, 20.0, 0.0); // Điểm thứ hai của đường viền
	glVertex3f(10.0, 20.0, 0.0); // Điểm thứ ba của đường viền
	glEnd();

	glFlush();
}

//void roof()
//{
//	//roof
//	glBegin(GL_POLYGON);
//	glColor3f(0.96, 0.96, 0.93);
//	glVertex2f(0.0, 768.0);
//	glVertex2f(70.0, 748.0);
//	glVertex2f(130.0, 748.0);
//	glVertex2f(300.0, 718.0);
//	glVertex2f(800.0, 718.0);
//	glVertex2f(1024.0, 768.0);
//
//	glEnd();
//	glFlush();
//
//	glBegin(GL_LINE_LOOP);
//	glColor3f(0.0, 0.0, 0.0);
//	glVertex2f(0.0, 768.0);
//	glVertex2f(70.0, 748.0);
//	glVertex2f(130.0, 748.0);
//	glVertex2f(300.0, 718.0);
//	glVertex2f(800.0, 718.0);
//	glVertex2f(1024.0, 768.0);
//
//	glEnd();
//	glFlush();
//}


void roof()
{
	//roof
	glBegin(GL_POLYGON);
	glColor3f(0.96, 0.96, 0.93);
	glVertex3f(0.0, 768.0, 0.0);
	glVertex3f(70.0, 748.0, 0.0);
	glVertex3f(130.0, 748.0, 0.0);
	glVertex3f(300.0, 718.0, 0.0);
	glVertex3f(800.0, 718.0, 0.0);
	glVertex3f(1024.0, 768.0, 0.0);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 768.0, 0.0);
	glVertex3f(70.0, 748.0, 0.0);
	glVertex3f(130.0, 748.0, 0.0);
	glVertex3f(300.0, 718.0, 0.0);
	glVertex3f(800.0, 718.0, 0.0);
	glVertex3f(1024.0, 768.0, 0.0);
	glEnd();

	// Connect the bottom points to the top point to form a pyramid shape
	glBegin(GL_LINES);
	glVertex3f(0.0, 768.0, 0.0);
	glVertex3f(70.0, 748.0, 0.0);

	glVertex3f(70.0, 748.0, 0.0);
	glVertex3f(130.0, 748.0, 0.0);

	glVertex3f(130.0, 748.0, 0.0);
	glVertex3f(300.0, 718.0, 0.0);

	glVertex3f(300.0, 718.0, 0.0);
	glVertex3f(800.0, 718.0, 0.0);

	glVertex3f(800.0, 718.0, 0.0);
	glVertex3f(1024.0, 768.0, 0.0);
	glEnd();

	glFlush();
}


//void floor()
//{
//	//floor
//	glBegin(GL_QUADS);
//	glColor3f(1.1, 1.0, 0.6);
//	glVertex2f(130.0, 0.0);
//	glVertex2f(1024.0, 0.0);
//	glVertex2f(800.0, 238.0);
//	glVertex2f(300.0, 238.0);
//
//	glEnd();
//	glFlush();
//
//	glBegin(GL_LINE_LOOP);
//	glColor3f(0.0, 0.0, 0.0);
//	glVertex2f(130.0, 0.0);
//	glVertex2f(1024.0, 0.0);
//	glVertex2f(800.0, 238.0);
//	glVertex2f(300.0, 238.0);
//
//	glEnd();
//	glFlush();
//
//}
//void background_wall()
//{
//	//background wall
//	glBegin(GL_POLYGON);
//	glColor3f(0.2, 0.1, 0.0);
//
//	glVertex2f(800.0, 718.0);
//	glVertex2f(300.0, 718.0);
//	glVertex2f(300.0, 538.0);
//	glVertex2f(220.0, 491.0);
//	glVertex2f(220.0, 360.0);
//	glVertex2f(300.0, 360.0);
//	glVertex2f(300.0, 238.0);
//	glVertex2f(800.0, 238.0);
//
//	glEnd();
//	glFlush();
//
//
//	glBegin(GL_QUADS);
//	glColor3f(0.25, 0.25, 0.25);
//
//	glVertex2f(700.0, 718.0);
//	glVertex2f(500.0, 718.0);
//	glVertex2f(500.0, 360.0);
//	glVertex2f(700.0, 360.0);
//
//	glEnd();
//	glFlush();
//
//	glBegin(GL_LINE_LOOP);
//	glColor3f(0.0, 0.0, 0.0);
//
//	glVertex2f(700.0, 718.0);
//	glVertex2f(500.0, 718.0);
//	glVertex2f(500.0, 360.0);
//	glVertex2f(700.0, 360.0);
//
//	glEnd();
//	glFlush();
//
//}
//void right_side_wall()
//{
//	//right side wall
//	glBegin(GL_QUADS);
//	glColor3f(0.88, 0.88, 0.88);
//	glVertex2f(1024.0, 768.0);
//	glVertex2f(800.0, 718.0);
//	glVertex2f(800.0, 238.0);
//	glVertex2f(1024.0, 0.0);
//
//	glEnd();
//	glFlush();
//
//	glBegin(GL_LINE_LOOP);
//	glColor3f(0.0, 0.0, 0.0);
//	glVertex2f(1024.0, 768.0);
//	glVertex2f(800.0, 718.0);
//	glVertex2f(800.0, 238.0);
//	glVertex2f(1024.0, 0.0);
//
//	glEnd();
//	glFlush();
//
//}

void floor()
{
	//floor
	glBegin(GL_QUADS);
	glColor3f(1.1, 1.0, 0.6);
	glVertex3f(130.0, 0.0, 0.0);
	glVertex3f(1024.0, 0.0, 0.0);
	glVertex3f(800.0, 238.0, 0.0);
	glVertex3f(300.0, 238.0, 0.0);
	glEnd();
	glFlush();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(130.0, 0.0, 0.0);
	glVertex3f(1024.0, 0.0, 0.0);
	glVertex3f(800.0, 238.0, 0.0);
	glVertex3f(300.0, 238.0, 0.0);
	glEnd();
	glFlush();
}

void drawRefrigerator() {
	// Cửa trên
	glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(430.0, 520.0, 0.0); // Top right
    glVertex3f(315.0, 520.0, 0.0); // Top left
    glVertex3f(315.0, 220.0, 0.0); // Bottom left
    glVertex3f(430.0, 220.0, 0.0); // Bottom right
    glEnd();
    glFlush();

	// Tay nắm cửa trên
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0.0); // Black color
	glVertex3f(340.0, 410.0, 0.0); // Top right (increase the y coordinate to create a gap)
	glVertex3f(315.0, 410.0, 0.0); // Top left (increase the y coordinate to create a gap)
	glVertex3f(315.0, 420.0, 0.0); // Bottom left
	glVertex3f(340.0, 420.0, 0.0); // Bottom right
	glEnd();
	glFlush();

	// Cửa dưới
	glBegin(GL_QUADS);
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(430.0, 410.0, 0.0); // Top right
	glVertex3f(315.0, 410.0, 0.0); // Top left
	glVertex3f(315.0, 220.0, 0.0); // Bottom left
	glVertex3f(430.0, 220.0, 0.0); // Bottom right
	glEnd();
	glFlush();

	// Tay nắm cửa dưới
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0.0); // Black color
	glVertex3f(340.0, 410.0, 0.0); // Top right (increase the y coordinate to create a gap)
	glVertex3f(315.0, 410.0, 0.0); // Top left (increase the y coordinate to create a gap)
	glVertex3f(315.0, 395.0, 0.0); // Bottom left
	glVertex3f(340.0, 395.0, 0.0); // Bottom right
	glEnd();
	glFlush();

	// Khoảng trắng
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0); // White color for the space
	glVertex3f(430.0, 410.0, 0.0); // Top right
	glVertex3f(315.0, 410.0, 0.0); // Top left
	glVertex3f(315.0, 410.0 - 5.0, 0.0); // Bottom left (reduce the y coordinate to create a gap)
	glVertex3f(430.0, 410.0 - 5.0, 0.0); // Bottom right
	glEnd();
	glFlush();

    // Door frame
    /*glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(430.0, 520.0, 0.0);
    glVertex3f(315.0, 520.0, 0.0);
    glVertex3f(315.0, 360.0, 0.0);
    glVertex3f(430.0, 360.0, 0.0);
    glEnd();
    glFlush();*/

	//glBegin(GL_QUADS);
	//glColor3f(0.1, 0.1, 0.1); // Black color
	//glVertex3f(480.0, 360.0, 0.0); // Top right
	//glVertex3f(290.0, 360.0, 0.0); // Top left
	//glVertex3f(290.0, 340.0, 0.0); // Bottom left
	//glVertex3f(480.0, 340.0, 0.0); // Bottom right
	//glEnd();
	//glFlush();

}

void microwave() {

	// Vẽ đáy của hộp
	glBegin(GL_QUADS);
	glColor3f(0.25f, 0.25f, 0.25f);
	glVertex3f(81.0f, 247.0f, 0.0f);   // Điểm 
	glVertex3f(30.0f, 210.0f, 0.0f);   // Điểm 
	glVertex3f(90.0f, 210.0f, 0.0f);  // Điểm
	glVertex3f(132.0f, 247.0f, 0.0f);  // Điểm D
	glEnd();


	//glBegin(GL_LINE_LOOP);
	//glColor3f(0.0f, 0.0f, 0.0f);
	//glVertex3f(81.0f, 247.0f, 0.0f);   // Điểm 
	//glVertex3f(30.0f, 210.0f, 0.0f);   // Điểm 
	//glVertex3f(90.0f, 210.0f, 0.0f);  // Điểm
	//glVertex3f(132.0f, 247.0f, 0.0f);  // Điểm 
	//glEnd();


	// Vẽ nắp của hộp
	glBegin(GL_QUADS);
	glColor3f(0.25f, 0.25f, 0.25f);
	glVertex3f(81.0f, 287.0f, 0.0f);   //
	glVertex3f(30.0f, 250.0f, 0.0f);   // Điểm 
	glVertex3f(88.0f, 250.0f, 0.0f);  // --
	glVertex3f(132.0f, 287.0f, 0.0f);  // Điểm 
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(81.0f, 287.0f, 0.0f);   // 
	glVertex3f(30.0f, 250.0f, 0.0f);   // 
	glVertex3f(88.0f, 250.0f, 0.0f);  // 
	glVertex3f(132.0f, 287.0f, 0.0f);  // B
	glEnd();

	// Vẽ cạnh trái
	glBegin(GL_QUADS);
	glColor3f(0.25f, 0.25f, 0.25f);
	glVertex3f(88.0f, 250.0f, 0.0f);  // Điểm 
	glVertex3f(30.0f, 250.0f, 0.0f);   // Điểm 
	glVertex3f(30.0f, 210.0f, 0.0f);   // Điểm 
	glVertex3f(88.0f, 210.0f, 0.0f);  // Điểm 

	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(88.0f, 250.0f, 0.0f);  // Điểm A
	glVertex3f(30.0f, 250.0f, 0.0f);   // Điểm 
	glVertex3f(30.0f, 210.0f, 0.0f);   // Điểm 
	glVertex3f(88.0f, 210.0f, 0.0f);  // Điểm C

	glEnd();

	// Vẽ mặt trực diện

	glBegin(GL_QUADS);
	glColor3f(0.25f, 0.25f, 0.25f);
	glVertex3f(88.0f, 250.0f, 0.0f);  // Điểm G
	glVertex3f(132.0f, 287.0f, 0.0f);  // Điểm H
	glVertex3f(132.0f, 250.0f, 0.0f);  // Điểm D
	glVertex3f(88.0f, 210.0f, 0.0f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(88.0f, 250.0f, 0.0f);  // Điểm G
	glVertex3f(132.0f, 287.0f, 0.0f);  // Điểm H
	glVertex3f(132.0f, 250.0f, 0.0f);  // Điểm D
	glVertex3f(88.0f, 210.0f, 0.0f);
	glEnd();



}

void microware_decord() {
	glBegin(GL_QUADS);
	glColor3f(0.88, 0.93, 0.93);
	glVertex3f(98.0f, 250.0f, 0.0f);  // --
	glVertex3f(125.0f, 273.0f, 0.0f);  // --
	glVertex3f(125.0f, 247.0f, 0.0f);  // --
	glVertex3f(98.0f, 222.0f, 0.0f);  // --
	glEnd();

	//glEnd();
	//glFlush();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(98.0f, 250.0f, 0.0f);  // --
	glVertex3f(125.0f, 273.0f, 0.0f);  // --
	glVertex3f(125.0f, 247.0f, 0.0f);  // --
	glVertex3f(98.0f, 222.0f, 0.0f);  // --
	glEnd();
	glFlush();
}


void background_wall()
{
	//background wall
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.1, 0.0);
	glVertex3f(800.0, 718.0, 0.0);
	glVertex3f(300.0, 718.0, 0.0);
	glVertex3f(300.0, 538.0, 0.0);
	glVertex3f(220.0, 491.0, 0.0);
	glVertex3f(220.0, 360.0, 0.0);
	glVertex3f(300.0, 360.0, 0.0);
	glVertex3f(300.0, 238.0, 0.0);
	glVertex3f(800.0, 238.0, 0.0);
	glEnd();
	glFlush();

	glBegin(GL_QUADS);
	glColor3f(0.25, 0.25, 0.25);
	glVertex3f(700.0, 718.0, 0.0);
	glVertex3f(500.0, 718.0, 0.0);
	glVertex3f(500.0, 360.0, 0.0);
	glVertex3f(700.0, 360.0, 0.0);
	glEnd();
	glFlush();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(700.0, 718.0, 0.0);
	glVertex3f(500.0, 718.0, 0.0);
	glVertex3f(500.0, 360.0, 0.0);
	glVertex3f(700.0, 360.0, 0.0);
	glEnd();
	glFlush();

}

void right_side_wall()
{
	//right side wall
	glBegin(GL_QUADS);
	glColor3f(0.88, 0.88, 0.88);
	glVertex3f(1024.0, 768.0, 0.0);
	glVertex3f(800.0, 718.0, 0.0);
	glVertex3f(800.0, 238.0, 0.0);
	glVertex3f(1024.0, 0.0, 0.0);
	glEnd();
	glFlush();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(1024.0, 768.0, 0.0);
	glVertex3f(800.0, 718.0, 0.0);
	glVertex3f(800.0, 238.0, 0.0);
	glVertex3f(1024.0, 0.0, 0.0);
	glEnd();
	glFlush();
}


//void window()
//{
//	//window
//	glBegin(GL_QUADS);
//	glColor3f(0.90, 0.97, 0.98);
//	glVertex2f(900.0, 600.0);
//	glVertex2f(900.0, 300.0);
//	glVertex2f(970.0, 280.0);
//	glVertex2f(970.0, 600.0);
//
//	glEnd();
//	glFlush();
//
//	glBegin(GL_LINE_LOOP);
//	glColor3f(0.0, 0.0, 0.0);
//	glVertex2f(900.0, 600.0);
//	glVertex2f(900.0, 300.0);
//	glVertex2f(970.0, 280.0);
//	glVertex2f(970.0, 600.0);
//
//	glEnd();
//	glFlush();
//
//}
//void cabinet_top()
//{
//	//cabinet side top
//	glBegin(GL_QUADS);
//	glColor3f(0.25, 0.25, 0.25);
//	glVertex2f(0.0, 748.0);
//	glVertex2f(0.0, 438.0);
//	glVertex2f(130.0, 438.0);
//	glVertex2f(130.0, 748.0);
//
//	glEnd();
//	glFlush();
//
//	glBegin(GL_LINE_LOOP);
//	glColor3f(0.0, 0.0, 0.0);
//	glVertex2f(0.0, 748.0);
//	glVertex2f(0.0, 438.0);
//	glVertex2f(130.0, 438.0);
//	glVertex2f(130.0, 748.0);
//
//	glEnd();
//	glFlush();
//
//	//cabinet front top
//	glBegin(GL_QUADS);
//	glColor3f(0.25, 0.25, 0.25);
//	glVertex2f(130.0, 748.0);
//	glVertex2f(130.0, 438.0);
//	glVertex2f(300.0, 538.0);
//	glVertex2f(300.0, 718.0);
//
//	glEnd();
//	glFlush();
//
//	glBegin(GL_LINE_LOOP);
//	glColor3f(0.0, 0.0, 0.0);
//	glVertex2f(130.0, 748.0);
//	glVertex2f(130.0, 438.0);
//	glVertex2f(300.0, 538.0);
//	glVertex2f(300.0, 718.0);
//
//	glEnd();
//	glFlush();
//}
//
//void cabinet_top_design()
//{
//	//cabinet front door design 
//	glBegin(GL_QUADS);
//	glColor3f(0.88, 0.93, 0.93);
//	glVertex2f(130.0, 480.0);
//	glVertex2f(130.0, 455.0);
//	glVertex2f(135.0, 455.0);
//	glVertex2f(135.0, 480.0);
//
//	glEnd();
//	glFlush();
//
//	glBegin(GL_LINE_LOOP);
//	glColor3f(0.0, 0.0, 0.0);
//	glVertex2f(130.0, 480.0);
//	glVertex2f(130.0, 455.0);
//	glVertex2f(135.0, 455.0);
//	glVertex2f(135.0, 480.0);
//
//	glEnd();
//	glFlush();
//
//	glBegin(GL_QUADS);
//	glColor3f(0.88, 0.93, 0.93);
//	glVertex2f(135.0, 480.0);
//	glVertex2f(135.0, 455.0);
//	glVertex2f(300.0, 550.0);
//	glVertex2f(300.0, 565.0);
//
//	glEnd();
//	glFlush();
//
//	glBegin(GL_LINE_LOOP);
//	glColor3f(0.0, 0.0, 0.0);
//	glVertex2f(135.0, 480.0);
//	glVertex2f(135.0, 455.0);
//	glVertex2f(300.0, 550.0);
//	glVertex2f(300.0, 565.0);
//
//	glEnd();
//	glFlush();
//
//	glBegin(GL_LINE_LOOP);
//	glColor3f(0.0, 0.0, 0.0);
//	glVertex2f(135.0, 477.0);
//	glVertex2f(300.0, 562.0);
//
//	glEnd();
//	glFlush();
//
//	//cabinet front door 
//	glBegin(GL_LINE_LOOP);
//	glColor3f(0.0, 0.0, 0.0);
//	glVertex2f(200.0, 737.0);
//	glVertex2f(200.0, 480.0);
//
//	glEnd();
//	glFlush();
//
//	glBegin(GL_LINE_LOOP);
//	glColor3f(0.0, 0.0, 0.0);
//	glVertex2f(250.0, 728.0);
//	glVertex2f(250.0, 508.0);
//
//	glEnd();
//	glFlush();
//
//}

void window()
{
	//window
	glBegin(GL_QUADS);
	glColor3f(0.90, 0.97, 0.98);
	glVertex3f(900.0, 600.0, 0.0);
	glVertex3f(900.0, 300.0, 0.0);
	glVertex3f(970.0, 280.0, 0.0);
	glVertex3f(970.0, 600.0, 0.0);
	glEnd();
	glFlush();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(900.0, 600.0, 0.0);
	glVertex3f(900.0, 300.0, 0.0);
	glVertex3f(970.0, 280.0, 0.0);
	glVertex3f(970.0, 600.0, 0.0);
	glEnd();
	glFlush();
}

void cabinet_top()
{
	//cabinet side top
	glBegin(GL_QUADS);
	glColor3f(0.25, 0.25, 0.25);
	glVertex3f(0.0, 748.0, 0.0);
	glVertex3f(0.0, 438.0, 0.0);
	glVertex3f(130.0, 438.0, 0.0);
	glVertex3f(130.0, 748.0, 0.0);
	glEnd();
	glFlush();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 748.0, 0.0);
	glVertex3f(0.0, 438.0, 0.0);
	glVertex3f(130.0, 438.0, 0.0);
	glVertex3f(130.0, 748.0, 0.0);
	glEnd();
	glFlush();

	//cabinet front top
	glBegin(GL_QUADS);
	glColor3f(0.25, 0.25, 0.25);
	glVertex3f(130.0, 748.0, 0.0);
	glVertex3f(130.0, 438.0, 0.0);
	glVertex3f(300.0, 538.0, 0.0);
	glVertex3f(300.0, 718.0, 0.0);
	glEnd();
	glFlush();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(130.0, 748.0, 0.0);
	glVertex3f(130.0, 438.0, 0.0);
	glVertex3f(300.0, 538.0, 0.0);
	glVertex3f(300.0, 718.0, 0.0);
	glEnd();
	glFlush();
}

void cabinet_top_design()
{
	//cabinet front door design 
	glBegin(GL_QUADS);
	glColor3f(0.88, 0.93, 0.93);
	glVertex3f(130.0, 480.0, 0.0);
	glVertex3f(130.0, 455.0, 0.0);
	glVertex3f(135.0, 455.0, 0.0);
	glVertex3f(135.0, 480.0, 0.0);
	glEnd();
	glFlush();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(130.0, 480.0, 0.0);
	glVertex3f(130.0, 455.0, 0.0);
	glVertex3f(135.0, 455.0, 0.0);
	glVertex3f(135.0, 480.0, 0.0);
	glEnd();
	glFlush();

	glBegin(GL_QUADS);
	glColor3f(0.88, 0.93, 0.93);
	glVertex3f(135.0, 480.0, 0.0);
	glVertex3f(135.0, 455.0, 0.0);
	glVertex3f(300.0, 550.0, 0.0);
	glVertex3f(300.0, 565.0, 0.0);
	glEnd();
	glFlush();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(135.0, 480.0, 0.0);
	glVertex3f(135.0, 455.0, 0.0);
	glVertex3f(300.0, 550.0, 0.0);
	glVertex3f(300.0, 565.0, 0.0);
	glEnd();
	glFlush();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(135.0, 477.0, 0.0);
	glVertex3f(300.0, 562.0, 0.0);
	glEnd();
	glFlush();

	//cabinet front door 
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(200.0, 737.0, 0.0);
	glVertex3f(200.0, 480.0, 0.0);
	glEnd();
	glFlush();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(250.0, 728.0, 0.0);
	glVertex3f(250.0, 508.0, 0.0);
	glEnd();
	glFlush();
}


void cabinet_bottom()
{
	//cabinet side Bottom
	glBegin(GL_QUADS);
	glColor3f(0.25, 0.25, 0.25);
	glVertex2f(0.0, 200.0);
	glVertex2f(0.0, 0.0);
	glVertex2f(130.0, 0.0);
	glVertex2f(130.0, 200.0);

	glEnd();
	glFlush();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(0.0, 200.0);
	glVertex2f(0.0, 0.0);
	glVertex2f(130.0, 0.0);
	glVertex2f(130.0, 200.0);


	glEnd();
	glFlush();

	//cabinet front Bottom
	glBegin(GL_QUADS);
	glColor3f(0.25, 0.25, 0.25);
	glVertex2f(130.0, 200.0);
	glVertex2f(130.0, 0.0);
	glVertex2f(300.0, 238.0);
	glVertex2f(300.0, 360.0);

	glEnd();
	glFlush();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(130.0, 200.0);
	glVertex2f(130.0, 0.0);
	glVertex2f(300.0, 238.0);
	glVertex2f(300.0, 360.0);

	glEnd();
	glFlush();

}

void cabinet_bottom_design()
{
	//cabinet front Bottom Design

	glBegin(GL_QUADS);
	glColor3f(0.88, 0.93, 0.93);
	glVertex2f(130.0, 180.0);
	glVertex2f(130.0, 155.0);
	glVertex2f(135.0, 155.0);
	glVertex2f(135.0, 180.0);

	glEnd();
	glFlush();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(130.0, 180.0);
	glVertex2f(130.0, 155.0);
	glVertex2f(135.0, 155.0);
	glVertex2f(135.0, 180.0);

	glEnd();
	glFlush();

	glBegin(GL_QUADS);
	glColor3f(0.88, 0.93, 0.93);
	glVertex2f(130.0, 180.0);
	glVertex2f(135.0, 180.0);
	glVertex2f(305.0, 345.0);
	glVertex2f(300.0, 345.0);

	glEnd();
	glFlush();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(130.0, 180.0);
	glVertex2f(135.0, 180.0);
	glVertex2f(305.0, 345.0);
	glVertex2f(300.0, 345.0);

	glEnd();
	glFlush();



	glBegin(GL_QUADS);
	glColor3f(0.88, 0.93, 0.93);
	glVertex2f(135.0, 180.0);
	glVertex2f(135.0, 155.0);
	glVertex2f(305.0, 325.0);
	glVertex2f(305.0, 345.0);

	glEnd();
	glFlush();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(135.0, 180.0);
	glVertex2f(135.0, 155.0);
	glVertex2f(305.0, 325.0);
	glVertex2f(305.0, 345.0);

	glEnd();
	glFlush();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(200.0, 300.0);
	glVertex2f(200.0, 97.0);
	glEnd();
	glFlush();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(260.0, 350.0);
	glVertex2f(260.0, 183.0);
	glEnd();
	glFlush();
}

void sink() {
	//sink
	glBegin(GL_QUADS);
	glColor3f(0.63f, 0.63f, 0.63f);
	glVertex3f(0.0f, 200.0f, 0.0f);
	glVertex3f(130.0f, 200.0f, 0.0f);
	glVertex3f(300.0f, 360.0f, 0.0f);
	glVertex3f(220.0f, 360.0f, 0.0f);
	glEnd();
	glFlush();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 200.0f, 0.0f);
	glVertex3f(130.0f, 200.0f, 0.0f);
	glVertex3f(300.0f, 360.0f, 0.0f);
	glVertex3f(220.0f, 360.0f, 0.0f);
	glEnd();
	glFlush();

	//sink side wall
	glBegin(GL_POLYGON);
	glColor3f(0.63f, 0.63f, 0.63f);
	glVertex3f(0.0f, 200.0f, 0.0f);
	glVertex3f(220.0f, 360.0f, 0.0f);
	glVertex3f(220.0f, 491.0f, 0.0f);
	glVertex3f(130.0f, 438.0f, 0.0f);
	glVertex3f(0.0f, 438.0f, 0.0f);
	glEnd();
	glFlush();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 200.0f, 0.0f);
	glVertex3f(220.0f, 360.0f, 0.0f);
	glVertex3f(220.0f, 491.0f, 0.0f);
	glVertex3f(130.0f, 438.0f, 0.0f);
	glVertex3f(0.0f, 438.0f, 0.0f);
	glEnd();
	glFlush();
}

void stove() {
	glBegin(GL_QUADS);
	glColor3f(0.25f, 0.25f, 0.25f);
	glVertex3f(221.0f, 357.0f, 0.0f);
	glVertex3f(170.0f, 320.0f, 0.0f);
	glVertex3f(250.0f, 320.0f, 0.0f);
	glVertex3f(292.0f, 357.0f, 0.0f);
	glEnd();
	glFlush();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(221.0f, 357.0f, 0.0f);
	glVertex3f(170.0f, 320.0f, 0.0f);
	glVertex3f(250.0f, 320.0f, 0.0f);
	glVertex3f(292.0f, 357.0f, 0.0f);
	glEnd();
	glFlush();
}


void water_tap() {
	// Sink
	glBegin(GL_QUADS);
	glColor3f(0.50, 0.50, 0.50);
	glVertex3f(162.0, 310.0, 0.0);
	glVertex3f(85.0, 250.0, 0.0);
	glVertex3f(178.0, 250.0, 0.0);
	glVertex3f(243.0, 310.0, 0.0);
	glEnd();
	glFlush();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(162.0, 310.0, 0.0);
	glVertex3f(85.0, 250.0, 0.0);
	glVertex3f(178.0, 250.0, 0.0);
	glVertex3f(243.0, 310.0, 0.0);
	glEnd();
	glFlush();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(233.0, 300.0, 0.0);
	glVertex3f(165.0, 300.0, 0.0);
	glEnd();
	glFlush();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(165.0, 300.0, 0.0);
	glVertex3f(105.0, 250.0, 0.0);
	glEnd();
	glFlush();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(165.0, 300.0, 0.0);
	glVertex3f(162.0, 310.0, 0.0);
	glEnd();
	glFlush();

	// Tap
	glBegin(GL_QUADS);
	glColor3f(0.50, 0.50, 0.50);
	glVertex3f(140.0, 320.0, 0.0);
	glVertex3f(160.0, 315.0, 0.0);
	glVertex3f(160.0, 323.0, 0.0);
	glVertex3f(130.0, 330.0, 0.0);
	glEnd();
	glFlush();

	glBegin(GL_QUADS);
	glColor3f(0.50, 0.50, 0.50);
	glVertex3f(130.0, 330.0, 0.0);
	glVertex3f(130.0, 295.0, 0.0);
	glVertex3f(140.0, 293.0, 0.0);
	glVertex3f(140.0, 320.0, 0.0);
	glEnd();
	glFlush();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(140.0, 320.0, 0.0);
	glVertex3f(160.0, 315.0, 0.0);
	glVertex3f(160.0, 323.0, 0.0);
	glVertex3f(130.0, 330.0, 0.0);
	glVertex3f(130.0, 295.0, 0.0);
	glVertex3f(140.0, 293.0, 0.0);
	glVertex3f(140.0, 320.0, 0.0);
	glEnd();
	glFlush();
}

void tv_cabinet() {
	glBegin(GL_QUADS);
	glColor3f(0.25, 0.25, 0.25);
	glVertex3f(450.0, 360.0, 0.0);
	glVertex3f(452.0, 358.0, 0.0);
	glVertex3f(752.0, 358.0, 0.0);
	glVertex3f(750.0, 360.0, 0.0);
	glEnd();
	glFlush();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(450.0, 360.0, 0.0);
	glVertex3f(452.0, 357.0, 0.0);
	glVertex3f(752.0, 357.0, 0.0);
	glVertex3f(750.0, 360.0, 0.0);
	glEnd();
	glFlush();

	glBegin(GL_QUADS);
	glColor3f(0.25, 0.25, 0.25);
	glVertex3f(452.0, 357.0, 0.0);
	glVertex3f(452.0, 220.0, 0.0);
	glVertex3f(752.0, 220.0, 0.0);
	glVertex3f(752.0, 357.0, 0.0);
	glEnd();
	glFlush();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(452.0, 357.0, 0.0);
	glVertex3f(452.0, 220.0, 0.0);
	glVertex3f(752.0, 220.0, 0.0);
	glVertex3f(752.0, 357.0, 0.0);
	glEnd();
	glFlush();
}


void tv_cabinet_design() {
	glBegin(GL_QUADS);
	glColor3f(0.88, 0.93, 0.93);
	glVertex3f(452.0, 345.0, 0.0);
	glVertex3f(452.0, 335.0, 0.0);
	glVertex3f(752.0, 335.0, 0.0);
	glVertex3f(752.0, 345.0, 0.0);
	glEnd();
	glFlush();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(452.0, 345.0, 0.0);
	glVertex3f(452.0, 335.0, 0.0);
	glVertex3f(752.0, 335.0, 0.0);
	glVertex3f(752.0, 345.0, 0.0);
	glEnd();
	glFlush();
}

void tv() {
	// Stand
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(550.0, 367.0, 0.0);
	glVertex3f(550.0, 360.0, 0.0);
	glVertex3f(650.0, 360.0, 0.0);
	glVertex3f(650.0, 367.0, 0.0);
	glEnd();
	glFlush();

	// Frame
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(475.0, 500.0, 0.0);
	glVertex3f(475.0, 367.0, 0.0);
	glVertex3f(725.0, 367.0, 0.0);
	glVertex3f(725.0, 500.0, 0.0);
	glEnd();
	glFlush();

	// Screen
	glBegin(GL_QUADS);
	glColor3f(0.70, 0.96, 0.96);
	glVertex3f(485.0, 490.0, 0.0);
	glVertex3f(485.0, 377.0, 0.0);
	glVertex3f(715.0, 377.0, 0.0);
	glVertex3f(715.0, 490.0, 0.0);
	glEnd();
	glFlush();
}

void floor_mat() {
	glBegin(GL_QUADS);
	glColor3f(0.11, 0.13, 0.51);
	glVertex3f(472.0, 200.0, 0.0);
	glVertex3f(482.0, 130.0, 0.0);
	glVertex3f(800.0, 130.0, 0.0);
	glVertex3f(772.0, 200.0, 0.0);
	glEnd();
	glFlush();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.11, 0.13, 0.51);
	glVertex3f(472.0, 200.0, 0.0);
	glVertex3f(482.0, 130.0, 0.0);
	glVertex3f(800.0, 130.0, 0.0);
	glVertex3f(772.0, 200.0, 0.0);
	glEnd();
	glFlush();

	glBegin(GL_QUADS);
	glColor3f(0.57, 0.57, 0.59);
	glVertex3f(482.0, 190.0, 0.0);
	glVertex3f(492.0, 140.0, 0.0);
	glVertex3f(785.0, 140.0, 0.0);
	glVertex3f(762.0, 190.0, 0.0);
	glEnd();
	glFlush();
}


void sofa() {
	// Top
	glBegin(GL_QUADS);
	glColor3f(0.50, 0.50, 0.50);
	glVertex3f(950.0, 145.0, 0.0);
	glVertex3f(940.0, 160.0, 0.0);
	glVertex3f(700.0, 160.0, 0.0);
	glVertex3f(720.0, 145.0, 0.0);
	glEnd();
	glFlush();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(950.0, 145.0, 0.0);
	glVertex3f(940.0, 160.0, 0.0);
	glVertex3f(700.0, 160.0, 0.0);
	glVertex3f(720.0, 145.0, 0.0);
	glEnd();
	glFlush();

	// Back
	glBegin(GL_QUADS);
	glColor3f(0.50, 0.50, 0.50);
	glVertex3f(950.0, 145.0, 0.0);
	glVertex3f(720.0, 145.0, 0.0);
	glVertex3f(720.0, 65.0, 0.0);
	glVertex3f(950.0, 65.0, 0.0);
	glEnd();
	glFlush();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(950.0, 145.0, 0.0);
	glVertex3f(720.0, 145.0, 0.0);
	glVertex3f(720.0, 65.0, 0.0);
	glVertex3f(950.0, 65.0, 0.0);
	glEnd();
	glFlush();

	// Side
	glBegin(GL_QUADS);
	glColor3f(0.50, 0.50, 0.50);
	glVertex3f(700.0, 160.0, 0.0);
	glVertex3f(700.0, 120.0, 0.0);
	glVertex3f(720.0, 120.0, 0.0);
	glVertex3f(720.0, 145.0, 0.0);
	glEnd();
	glFlush();

	glBegin(GL_QUADS);
	glColor3f(0.50, 0.50, 0.50);
	glVertex3f(720.0, 120.0, 0.0);
	glVertex3f(660.0, 140.0, 0.0);
	glVertex3f(660.0, 90.0, 0.0);
	glVertex3f(720.0, 65.0, 0.0);
	glEnd();
	glFlush();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(700.0, 160.0, 0.0);
	glVertex3f(700.0, 120.0, 0.0);
	glVertex3f(660.0, 140.0, 0.0);
	glVertex3f(660.0, 90.0, 0.0);
	glVertex3f(720.0, 65.0, 0.0);
	glVertex3f(720.0, 145.0, 0.0);
	glEnd();
	glFlush();

	// Stand
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(720.0, 65.0, 0.0);
	glVertex3f(720.0, 50.0, 0.0);
	glVertex3f(730.0, 50.0, 0.0);
	glVertex3f(730.0, 65.0, 0.0);
	glEnd();
	glFlush();

	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(940.0, 65.0, 0.0);
	glVertex3f(940.0, 50.0, 0.0);
	glVertex3f(950.0, 50.0, 0.0);
	glVertex3f(950.0, 65.0, 0.0);
	glEnd();
	glFlush();

	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(660.0, 90.0, 0.0);
	glVertex3f(660.0, 75.0, 0.0);
	glVertex3f(670.0, 77.0, 0.0);
	glVertex3f(670.0, 87.0, 0.0);
	glEnd();
	glFlush();
}

void chair_right() {
	// Back
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.5, 0.0);
	glVertex3f(545.0, 270.0, 0.0);
	glVertex3f(545.0, 170.0, 0.0);
	glVertex3f(550.0, 165.0, 0.0);
	glVertex3f(550.0, 270.0, 0.0);
	glEnd();
	glFlush();

	// Seat
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.5, 0.0);
	glVertex3f(545.0, 170.0, 0.0);
	glVertex3f(470.0, 170.0, 0.0);
	glVertex3f(470.0, 165.0, 0.0);
	glVertex3f(550.0, 165.0, 0.0);
	glEnd();
	glFlush();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(545.0, 270.0, 0.0);
	glVertex3f(545.0, 170.0, 0.0);
	glVertex3f(470.0, 170.0, 0.0);
	glVertex3f(470.0, 165.0, 0.0);
	glVertex3f(550.0, 165.0, 0.0);
	glVertex3f(550.0, 270.0, 0.0);
	glEnd();
	glFlush();

	glBegin(GL_QUADS);
	glColor3f(1.0, 0.5, 0.0);
	glVertex3f(544.0, 200.0, 0.0);
	glVertex3f(472.0, 200.0, 0.0);
	glVertex3f(470.0, 170.0, 0.0);
	glVertex3f(545.0, 170.0, 0.0);
	glEnd();
	glFlush();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(544.0, 200.0, 0.0);
	glVertex3f(472.0, 200.0, 0.0);
	glVertex3f(470.0, 170.0, 0.0);
	glVertex3f(545.0, 170.0, 0.0);
	glEnd();
	glFlush();
}

void chair_right_stand() {
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(470.0, 165.0, 0.0);
	glVertex3f(470.0, 115.0, 0.0);
	glVertex3f(475.0, 120.0, 0.0);
	glVertex3f(475.0, 165.0, 0.0);
	glEnd();
	glFlush();

	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(475.0, 120.0, 0.0);
	glVertex3f(550.0, 120.0, 0.0);
	glVertex3f(550.0, 115.0, 0.0);
	glVertex3f(470.0, 115.0, 0.0);
	glEnd();
	glFlush();
}

void chair_left() {
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.5, 0.0);
	glVertex3f(290.0, 270.0, 0.0);
	glVertex3f(290.0, 170.0, 0.0);
	glVertex3f(295.0, 175.0, 0.0);
	glVertex3f(295.0, 270.0, 0.0);
	glEnd();
	glFlush();

	// Seat
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.5, 0.0);
	glVertex3f(295.0, 175.0, 0.0);
	glVertex3f(290.0, 170.0, 0.0);
	glVertex3f(370.0, 170.0, 0.0);
	glVertex3f(370.0, 175.0, 0.0);
	glEnd();
	glFlush();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(290.0, 270.0, 0.0);
	glVertex3f(290.0, 170.0, 0.0);
	glVertex3f(370.0, 170.0, 0.0);
	glVertex3f(370.0, 175.0, 0.0);
	glVertex3f(295.0, 175.0, 0.0);
	glVertex3f(295.0, 270.0, 0.0);
	glEnd();
	glFlush();

	glBegin(GL_QUADS);
	glColor3f(1.0, 0.5, 0.0);
	glVertex3f(297.0, 200.0, 0.0);
	glVertex3f(295.0, 175.0, 0.0);
	glVertex3f(370.0, 175.0, 0.0);
	glVertex3f(368.0, 200.0, 0.0);
	glEnd();
	glFlush();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(297.0, 200.0, 0.0);
	glVertex3f(295.0, 175.0, 0.0);
	glVertex3f(370.0, 175.0, 0.0);
	glVertex3f(368.0, 200.0, 0.0);
	glEnd();
	glFlush();
}

void chair_left_stand() {
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(370.0, 170.0, 0.0);
	glVertex3f(370.0, 120.0, 0.0);
	glVertex3f(365.0, 125.0, 0.0);
	glVertex3f(365.0, 170.0, 0.0);
	glEnd();
	glFlush();

	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(365.0, 125.0, 0.0);
	glVertex3f(290.0, 125.0, 0.0);
	glVertex3f(290.0, 120.0, 0.0);
	glVertex3f(370.0, 120.0, 0.0);
	glEnd();
	glFlush();
}


void table()
{
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);

	glVertex3f(315.0, 220.0, 0.0);
	glVertex3f(315.0, 210.0, 0.0);
	glVertex3f(500.0, 210.0, 0.0);
	glVertex3f(500.0, 220.0, 0.0);

	glEnd();
	glFlush();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);

	glVertex3f(315.0, 220.0, 0.0);
	glVertex3f(315.0, 210.0, 0.0);
	glVertex3f(500.0, 210.0, 0.0);
	glVertex3f(500.0, 220.0, 0.0);

	glEnd();
	glFlush();


	glBegin(GL_QUADS);
	glColor3f(0.8, 0.0, 0.0);

	glVertex3f(315.0, 220.0, 0.0);
	glVertex3f(500.0, 220.0, 0.0);
	glVertex3f(515.0, 300.0, 0.0);
	glVertex3f(370.0, 300.0, 0.0);

	glEnd();
	glFlush();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);

	glVertex3f(315.0, 220.0, 0.0);
	glVertex3f(500.0, 220.0, 0.0);
	glVertex3f(515.0, 300.0, 0.0);
	glVertex3f(370.0, 300.0, 0.0);

	glEnd();
	glFlush();


	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);

	glVertex3f(502.0, 217.0, 0.0);
	glVertex3f(517.0, 298.0, 0.0);
	glVertex3f(515.0, 300.0, 0.0);
	glVertex3f(500.0, 220.0, 0.0);

	glEnd();
	glFlush();


	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);

	glVertex3f(502.0, 217.0, 0.0);
	glVertex3f(517.0, 298.0, 0.0);
	glVertex3f(515.0, 300.0, 0.0);
	glVertex3f(500.0, 220.0, 0.0);
	glEnd();
	glFlush();
}

void table_stand_left()
{
	//front
	glBegin(GL_QUADS);
	glColor3f(0.5, 0.5, 0.5);

	glVertex3f(317.0, 210.0, 0.0);
	glVertex3f(317.0, 110.0, 0.0);
	glVertex3f(327.0, 110.0, 0.0);
	glVertex3f(327.0, 210.0, 0.0);

	glEnd();
	glFlush();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);

	glVertex3f(317.0, 210.0, 0.0);
	glVertex3f(317.0, 110.0, 0.0);
	glVertex3f(327.0, 110.0, 0.0);
	glVertex3f(327.0, 210.0, 0.0);

	glEnd();
	glFlush();

	glBegin(GL_QUADS);
	glColor3f(0.5, 0.5, 0.5);

	glVertex3f(327.0, 210.0, 0.0);
	glVertex3f(327.0, 110.0, 0.0);
	glVertex3f(330.0, 113.0, 0.0);
	glVertex3f(330.0, 210.0, 0.0);

	glEnd();
	glFlush();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);

	glVertex3f(327.0, 210.0, 0.0);
	glVertex3f(327.0, 110.0, 0.0);
	glVertex3f(330.0, 113.0, 0.0);
	glVertex3f(330.0, 210.0, 0.0);

	glEnd();
	glFlush();


	//back
	glBegin(GL_QUADS);
	glColor3f(0.5, 0.5, 0.5);

	glVertex3f(375.0, 210.0, 0.0);
	glVertex3f(375.0, 160.0, 0.0);
	glVertex3f(385.0, 160.0, 0.0);
	glVertex3f(385.0, 210.0, 0.0);

	glEnd();
	glFlush();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);

	glVertex3f(375.0, 210.0, 0.0);
	glVertex3f(375.0, 160.0, 0.0);
	glVertex3f(385.0, 160.0, 0.0);
	glVertex3f(385.0, 210.0, 0.0);

	glEnd();
	glFlush();

	glBegin(GL_QUADS);
	glColor3f(0.5, 0.5, 0.5);

	glVertex3f(385.0, 210.0, 0.0);
	glVertex3f(385.0, 160.0, 0.0);
	glVertex3f(388.0, 163.0, 0.0);
	glVertex3f(388.0, 210.0, 0.0);

	glEnd();
	glFlush();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);

	glVertex3f(385.0, 210.0, 0.0);
	glVertex3f(385.0, 160.0, 0.0);
	glVertex3f(388.0, 163.0, 0.0);
	glVertex3f(388.0, 210.0, 0.0);

	glEnd();
	glFlush();
}

void table_stand_right()
{
	//front
	glBegin(GL_QUADS);
	glColor3f(0.5, 0.5, 0.5);

	glVertex3f(500.0, 210.0, 0.0);
	glVertex3f(490.0, 210.0, 0.0);
	glVertex3f(490.0, 110.0, 0.0);
	glVertex3f(500.0, 110.0, 0.0);

	glEnd();
	glFlush();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);

	glVertex3f(500.0, 210.0, 0.0);
	glVertex3f(490.0, 210.0, 0.0);
	glVertex3f(490.0, 110.0, 0.0);
	glVertex3f(500.0, 110.0, 0.0);

	glEnd();
	glFlush();

	glBegin(GL_QUADS);
	glColor3f(0.5, 0.5, 0.5);

	glVertex3f(500.0, 210.0, 0.0);
	glVertex3f(500.0, 110.0, 0.0);
	glVertex3f(503.0, 113.0, 0.0);
	glVertex3f(503.0, 217.0, 0.0);

	glEnd();
	glFlush();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);

	glVertex3f(500.0, 210.0, 0.0);
	glVertex3f(500.0, 110.0, 0.0);
	glVertex3f(503.0, 113.0, 0.0);
	glVertex3f(503.0, 217.0, 0.0);

	glEnd();
	glFlush();

	//back

	glBegin(GL_QUADS);
	glColor3f(0.5, 0.5, 0.5);

	glVertex3f(517.0, 298.0, 0.0);
	glVertex3f(514.0, 295.0, 0.0);
	glVertex3f(514.0, 210.0, 0.0);
	glVertex3f(517.0, 213.0, 0.0);

	glEnd();
	glFlush();


	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);

	glVertex3f(517.0, 298.0, 0.0);
	glVertex3f(514.0, 295.0, 0.0);
	glVertex3f(514.0, 210.0, 0.0);
	glVertex3f(517.0, 213.0, 0.0);

	glEnd();
	glFlush();

	glBegin(GL_QUADS);
	glColor3f(0.5, 0.5, 0.5);

	glVertex3f(514.0, 295.0, 0.0);
	glVertex3f(504.0, 220.0, 0.0);
	glVertex3f(504.0, 210.0, 0.0);
	glVertex3f(514.0, 210.0, 0.0);

	glEnd();
	glFlush();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);

	glVertex3f(514.0, 295.0, 0.0);
	glVertex3f(504.0, 215.0, 0.0);
	glVertex3f(504.0, 210.0, 0.0);
	glVertex3f(514.0, 210.0, 0.0);

	glEnd();
	glFlush();
}

void drawCircle(float x1, float y1, double radius)
{
	float x2, y2;
	float angle;
	glBegin(GL_POLYGON);
	for (angle = .1f; angle < 361.0f; angle += 1.0f)
	{
		x2 = x1 + sin(angle) * radius;
		y2 = y1 + cos(angle) * radius;
		glVertex3f(x2, y2, 0.0);
	}
	glEnd();
}

void waterdrop() {

	glPushMatrix();
	glTranslatef(0, -drop_t, 0);
	glColor3f(0.70, 0.96, 0.96);
	drawCircle(160.0, 315.0, 3);

	glPopMatrix();
	if (drop_t < 50)
		drop_t += 1.0;
	else
		drop_t = 1.0;
}

void megh()
{
	glPushMatrix();
	glTranslatef(megh_t, 0, 0);
	glColor3f(0.9411, 1, 0.9411);
	drawCircle(500.0, 470.0, 10);
	drawCircle(510.0, 465.0, 10);
	drawCircle(520.0, 465.0, 10);
	drawCircle(530.0, 470.0, 10);
	drawCircle(520.0, 475.0, 10);
	drawCircle(510.0, 475.0, 10);

	drawCircle(560.0, 460.0, 10);
	drawCircle(570.0, 455.0, 10);
	drawCircle(580.0, 455.0, 10);
	drawCircle(590.0, 460.0, 10);
	drawCircle(580.0, 465.0, 10);
	drawCircle(570.0, 465.0, 10);

	drawCircle(610.0, 470.0, 10);
	drawCircle(620.0, 465.0, 10);
	drawCircle(630.0, 465.0, 10);
	drawCircle(640.0, 470.0, 10);
	drawCircle(630.0, 475.0, 10);
	drawCircle(620.0, 475.0, 10);

	glPopMatrix();
	if (megh_t > 60)
		megh_t = -1.0;
	else
		megh_t += 1.0;
}


void draw()
{
	triangle();
	roof();
	floor();
	background_wall();
	drawRefrigerator();
	right_side_wall();
	window();
	cabinet_top();
	cabinet_top_design();
	cabinet_bottom();
	cabinet_bottom_design();
	sink();
	stove();
	water_tap();
	tv_cabinet();
	tv_cabinet_design();
	tv();
	floor_mat();
	sofa();
	chair_right();
	chair_right_stand();
	chair_left();
	chair_left_stand();
	table();
	table_stand_left();
	table_stand_right();
	megh();
	waterdrop();
	glutSwapBuffers();
	microwave();
	microware_decord();
}

void myDisplay(void)
{
	glViewport(-400, -300, 1600, 1200);
	glPushMatrix();
	draw();
	glPopMatrix();

}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Xóa bộ đệm màu và bộ đệm độ sâu
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(0.0, 0.0, 0.0); // Dịch chuyển toàn bộ vẽ về phía trước và lên trên

	triangle();
	roof();
	floor();
	background_wall();
	drawRefrigerator();
	right_side_wall();
	window();
	cabinet_top();
	cabinet_top_design();
	cabinet_bottom();
	cabinet_bottom_design();
	sink();
	stove();
	water_tap();
	tv_cabinet();
	tv_cabinet_design();
	tv();
	floor_mat();
	sofa();
	microwave();
	microware_decord();

	glFlush();
}


void keyboard(unsigned char key, int x, int y) {

	if (key == 'w') {
		glTranslatef(0, -50, 0);
		glutPostRedisplay();
	}
	else if (key == 's') {
		glTranslatef(0, 50, 0);
		glutPostRedisplay();
	}
	else if (key == 'd') {
		glTranslatef(-50, 0, 0);
		glutPostRedisplay();
	}
	else if (key == 'a') {
		glTranslatef(50, 0, 0);
		glutPostRedisplay();
	}

}

void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION_MATRIX);
	glLoadIdentity();
	gluOrtho2D(0.0, 1024.0, 0.0, 768.0);
}

void update(int value) {
	megh_t += 1.0;
	drop_t += 1.0;
	glutPostRedisplay();
	glutTimerFunc(50, update, 0);


}

void main(int argc, char** argv)
{
	/*glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("Living Room");
	glutKeyboardFunc(keyboard);
	glutDisplayFunc(myDisplay);
	glutTimerFunc(1000, update, 0);
	myInit();
	glutMainLoop();*/

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1024, 768);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Kitchen Design");

	//glEnable(GL_DEPTH_TEST); // Kích hoạt kiểm tra độ sâu

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1024.0, 0.0, 768.0, -200.0, 200.0);

	glutDisplayFunc(display);
	//glutTimerFunc(5000, update, 0);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
}
