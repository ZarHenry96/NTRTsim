
#ifndef _WINDOWS

#include "ntrt/tgOpenGLSupport/tgOpenGLFreeGlut/tgGlutDemoApplication.h"
#include "ntrt/tgOpenGLSupport/tgOpenGLFreeGlut/tgGlutStuff.h"

#include "BulletDynamics/Dynamics/btDiscreteDynamicsWorld.h"
#include "BulletDynamics/Dynamics/btRigidBody.h"

void	tgGlutDemoApplication::updateModifierKeys()
{
	m_modifierKeys = 0;
	if (glutGetModifiers() & GLUT_ACTIVE_ALT)
		m_modifierKeys |= BT_ACTIVE_ALT;

	if (glutGetModifiers() & GLUT_ACTIVE_CTRL)
		m_modifierKeys |= BT_ACTIVE_CTRL;
	
	if (glutGetModifiers() & GLUT_ACTIVE_SHIFT)
		m_modifierKeys |= BT_ACTIVE_SHIFT;
}

void tgGlutDemoApplication::specialKeyboard(int key, int x, int y)	
{
	(void)x;
	(void)y;

	switch (key) 
	{
	case GLUT_KEY_F1:
		{

			break;
		}

	case GLUT_KEY_F2:
		{

			break;
		}


	case GLUT_KEY_END:
		{
			
			exitPhysics();
			break;
		}
	case GLUT_KEY_LEFT : stepLeft(); break;
	case GLUT_KEY_RIGHT : stepRight(); break;
	case GLUT_KEY_UP : stepFront(); break;
	case GLUT_KEY_DOWN : stepBack(); break;
	case GLUT_KEY_PAGE_UP : zoomIn(); break;
	case GLUT_KEY_PAGE_DOWN : zoomOut(); break;
	case GLUT_KEY_HOME : toggleIdle(); break;
	default:
		//        std::cout << "unused (special) key : " << key << std::endl;
		break;
	}

	glutPostRedisplay();

}

void tgGlutDemoApplication::swapBuffers()
{
	glutSwapBuffers();

}

#endif //_WINDOWS


