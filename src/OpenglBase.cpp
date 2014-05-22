#include "OpenglBase.h"

bool OpenglBase::inicializaContexto(){
    if (!glfwInit())
        return false;
    glfwSwapInterval(0);
    return true;
}

bool OpenglBase::inicializaJanela(int largura, int altura){
    if( !glfwOpenWindow( largura, altura, 0,0,0,0, 32,0, GLFW_WINDOW ) )
        return false;

    return true;
}

void OpenglBase::mudaNomeJanela(std::string titulo){
    glfwSetWindowTitle(titulo.c_str());
}

void OpenglBase::encerraContexto(){
    glfwCloseWindow();
    glfwTerminate();
}
