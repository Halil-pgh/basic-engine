#pragma once

#include <string>

class Shader {
public:
    Shader() = default;
    Shader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);
    ~Shader();

    void create(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);

    void bind() const;
    void unbind() const;
private:
    std::string readFromFile(const std::string& filePath);
    uint32_t createShader(std::string source, uint32_t type);

private:
    uint32_t id;
};