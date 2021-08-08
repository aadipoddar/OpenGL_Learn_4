#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

void framebuffer_size_callback ( GLFWwindow * window , int width , int height );
void processInput ( GLFWwindow * window );

int main ( )
{
	std::cout << "Hello World" << std::endl;

    //glm test
    glm::vec4 vec ( 1.0f , 0.0f , 0.0f , 1.0f );
    glm::mat4 trans = glm::mat4 ( 1.0f );// identity matrix
    trans = glm::translate ( trans , glm::vec3 ( 1.0f , 1.0f , 0.0f ) );
    trans = glm::rotate ( trans , glm::radians ( 90.0f ) , glm::vec3 ( 0.0 , 0.0 , 1.0 ) );
    trans = glm::scale ( trans , glm::vec3 ( 0.5 , 0.5 , 0.5 ) );
    vec = trans * vec;
    std::cout << vec.x << vec.y << vec.z << std::endl;

    glfwInit ( );

    //OpenGl version 3.3
    glfwWindowHint ( GLFW_CONTEXT_VERSION_MAJOR , 3 );
    glfwWindowHint ( GLFW_CONTEXT_VERSION_MINOR , 3 );

    glfwWindowHint ( GLFW_OPENGL_PROFILE , GLFW_OPENGL_CORE_PROFILE );
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow * window = glfwCreateWindow ( 800 , 600 , "LearnOpenGL" , NULL , NULL );
    if ( window == NULL )
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate ( );
        return -1;
    }
    glfwMakeContextCurrent ( window );

    if ( !gladLoadGLLoader ( ( GLADloadproc ) glfwGetProcAddress ) )
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glViewport ( 0 , 0 , 800 , 600 );

    glfwSetFramebufferSizeCallback ( window , framebuffer_size_callback );

    // render loop
    while ( !glfwWindowShouldClose ( window ) )
    {
        // input
        processInput ( window );

        // rendering commands here
        glClearColor ( 0.2f , 0.3f , 0.3f , 1.0f );
        glClear ( GL_COLOR_BUFFER_BIT );

        // check and call events and swap the buffers
        glfwSwapBuffers ( window );
        glfwPollEvents ( );
    }

    glfwTerminate ( );
    return 0;
}

void framebuffer_size_callback ( GLFWwindow * window , int width , int height )
{
    glViewport ( 0 , 0 , width , height );
}

void processInput ( GLFWwindow * window )
{
    if ( glfwGetKey ( window , GLFW_KEY_ESCAPE ) == GLFW_PRESS )
        glfwSetWindowShouldClose ( window , true );
}