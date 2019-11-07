/*
Bullet Continuous Collision Detection and Physics Library
Copyright (c) 2003-2006 Erwin Coumans  http://continuousphysics.com/Bullet/

This software is provided 'as-is', without any express or implied warranty.
In no event will the authors be held liable for any damages arising from the use of this software.
Permission is granted to anyone to use this software for any purpose, 
including commercial applications, and to alter it and redistribute it freely, 
subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.
2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.
*/

#ifndef _WINDOWS

	#include "ntrt/tgOpenGLSupport/tgOpenGLFreeGlut/tgDemoApplication.h"
	#include <iostream> // Debugging only

	//glut is C code, this global gtgDemoApplication links glut to the C++ demo
	static tgDemoApplication* gtgDemoApplication = 0;


	#include "ntrt/tgOpenGLSupport/tgOpenGLFreeGlut/tgGlutStuff.h"

	static	void glutKeyboardCallback(unsigned char key, int x, int y)
	{
		gtgDemoApplication->keyboardCallback(key,x,y);
	}

	static	void glutKeyboardUpCallback(unsigned char key, int x, int y)
	{
	gtgDemoApplication->keyboardUpCallback(key,x,y);
	}

	static void glutSpecialKeyboardCallback(int key, int x, int y)
	{
		gtgDemoApplication->specialKeyboard(key,x,y);
	}

	static void glutSpecialKeyboardUpCallback(int key, int x, int y)
	{
		gtgDemoApplication->specialKeyboardUp(key,x,y);
	}


	static void glutReshapeCallback(int w, int h)
	{
		gtgDemoApplication->reshape(w,h);
	}

	static void glutMoveAndDisplayCallback()
	{
		gtgDemoApplication->moveAndDisplay();
	}

	static void glutMouseFuncCallback(int button, int state, int x, int y)
	{
		gtgDemoApplication->mouseFunc(button,state,x,y);
	}


	static void	glutMotionFuncCallback(int x,int y)
	{
		gtgDemoApplication->mouseMotionFunc(x,y);
	}


	static void glutDisplayCallback(void)
	{
		gtgDemoApplication->displayCallback();
	}


	void tgglutmain(int width,int height,const char* title,tgDemoApplication* demoApp) {
		
		gtgDemoApplication = demoApp;
		
		//Faking argc and argv since GLUT doesn't need to receive them
		static char** argv = NULL;
		static int argc = 0;
		
		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_STENCIL);
		glutInitWindowPosition(0, 0);
		glutInitWindowSize(width, height);
		glutCreateWindow(title);
		#ifdef BT_USE_FREEGLUT
			glutSetOption (GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
		#endif

		gtgDemoApplication->myinit();

		glutKeyboardFunc(glutKeyboardCallback);
		glutKeyboardUpFunc(glutKeyboardUpCallback);
		glutSpecialFunc(glutSpecialKeyboardCallback);
		glutSpecialUpFunc(glutSpecialKeyboardUpCallback);

		glutReshapeFunc(glutReshapeCallback);
		//createMenu();
		glutIdleFunc(glutMoveAndDisplayCallback);
		glutMouseFunc(glutMouseFuncCallback);
		glutPassiveMotionFunc(glutMotionFuncCallback);
		glutMotionFunc(glutMotionFuncCallback);
		glutDisplayFunc( glutDisplayCallback );

		glutMoveAndDisplayCallback();

		//enable vsync to avoid tearing on Apple (todo: for Windows)

		#if defined(__APPLE__) && !defined (VMDMESA)
			int swap_interval = 1;
			CGLContextObj cgl_context = CGLGetCurrentContext();
			CGLSetParameter(cgl_context, kCGLCPSwapInterval, &swap_interval);
		#endif

	}

	#if (0)
		void tgGlutMainEventLoop()
		{
			glutMainLoopEvent();
		}
	#endif
#endif //_WINDOWS
