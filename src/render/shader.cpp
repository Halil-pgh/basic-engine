#include "shader.hpp"

#include <glad/glad.h>

#include <stdio.h>
#include <fstream>

Shader::Shader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath) {
    create(vertexShaderPath, fragmentShaderPath);
}

Shader::~Shader() {
    glDeleteProgram(id);
}

void Shader::create(const std::string& vertexShaderPath, const std::string& fragmentShaderPath) {
    std::string vertexShaderSource = readFromFile(vertexShaderPath);
    uint32_t vertexShaderId = createShader(vertexShaderSource, GL_VERTEX_SHADER);

    std::string fragmentShaderSource = readFromFile(fragmentShaderPath);
    uint32_t fragmentShaderId = createShader(fragmentShaderSource, GL_FRAGMENT_SHADER);

    id = glCreateProgram();
    glAttachShader(id, vertexShaderId);
    glAttachShader(id, fragmentShaderId);
    glLinkProgram(id);

    int success;
    glGetProgramiv(id, GL_LINK_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetProgramInfoLog(id, 512, NULL, infoLog);
        printf("Error: Shader linking error: %s\n", infoLog);
    }
    glUseProgram(id);
    
    glDeleteShader(vertexShaderId);
    glDeleteShader(fragmentShaderId);
}

void Shader::bind() const {
    glUseProgram(id);
}

void Shader::unbind() const {
    glUseProgram(0);
}

std::string Shader::readFromFile(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open())
        printf("Error: File can't opened: file: %s\n", filePath.c_str());

    std::string fileSource = "";
    std::string line;
    while (std::getline(file, line)) {
        fileSource += line + "\n";
    }

    return fileSource;
}

uint32_t Shader::createShader(std::string source, uint32_t type) {
    uint32_t shader = glCreateShader(type);
    const char* src = source.c_str();
    glShaderSource(shader, 1, &src, NULL);
    glCompileShader(shader);

    int success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        printf("Error: %s shader compilation failed: %s\n", type == GL_VERTEX_SHADER ? "Vertex" : "Fragment", infoLog);
    }

    return shader;
}
