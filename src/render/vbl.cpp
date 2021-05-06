#include "vbl.hpp"

#include <glad/glad.h>

#include <stdio.h>

static uint32_t getSizeFromShaderType(ShaderType type) {
    switch (type)
    {
        case ShaderType::float1: return sizeof(float) * 1;
        case ShaderType::float2: return sizeof(float) * 2;
        case ShaderType::float3: return sizeof(float) * 3;
        case ShaderType::float4: return sizeof(float) * 4;
        case ShaderType::double1: return sizeof(double) * 1;
        case ShaderType::double2: return sizeof(double) * 2;
        case ShaderType::double3: return sizeof(double) * 3;
        case ShaderType::double4: return sizeof(double) * 4;
        case ShaderType::int1: return sizeof(int) * 1;
        case ShaderType::int2: return sizeof(int) * 2;
        case ShaderType::int3: return sizeof(int) * 3;
        case ShaderType::int4: return sizeof(int) * 4;
        case ShaderType::bool1: return sizeof(bool) * 1;
        case ShaderType::bool2: return sizeof(bool) * 2;
    }
    printf("Error: Undefined shader type!\n");
    return 0;
}

static uint32_t getOpenglTypeFromShaderType(ShaderType type) {
    switch (type)
    {
        case ShaderType::float1:
        case ShaderType::float2:
        case ShaderType::float3:
        case ShaderType::float4:
            return GL_FLOAT;
        case ShaderType::double1:
        case ShaderType::double2:
        case ShaderType::double3:
        case ShaderType::double4:
            return GL_DOUBLE;
        case ShaderType::int1:
        case ShaderType::int2:
        case ShaderType::int3:
        case ShaderType::int4:
            return GL_INT;
        case ShaderType::bool1:
        case ShaderType::bool2:
            return GL_BOOL;
    }
    printf("Error: Undefined shader type!\n");
    return 0;
}

static uint32_t getCountFromShaderType(ShaderType type) {
    switch (type)
    {
        case ShaderType::float1:
        case ShaderType::double1:
        case ShaderType::int1:
        case ShaderType::bool1:
            return 1;
        case ShaderType::float2:
        case ShaderType::double2:
        case ShaderType::int2:
        case ShaderType::bool2:
            return 2;
        case ShaderType::float3:
        case ShaderType::double3:
        case ShaderType::int3:
            return 3;
        case ShaderType::float4:
        case ShaderType::double4:
        case ShaderType::int4:
            return 4;
    }
    printf("Error: Undefined shader type!\n");
    return 0;
}

VBL::VBL(const std::vector<Layout>& layouts) {
    create(layouts);
}

void VBL::create(const std::vector<Layout>& layouts) {
    uint32_t totalLayoutSize = 0;
    for (const Layout& layout : layouts) {
        totalLayoutSize += getSizeFromShaderType(layout.type);
    }

    uint32_t index = 0;
    uint32_t offset = 0;
    for (const Layout& layout : layouts) {
        glVertexAttribPointer(index, getCountFromShaderType(layout.type),
            getOpenglTypeFromShaderType(layout.type), layout.normalized ? GL_TRUE : GL_FALSE,
            totalLayoutSize, (const void*)offset);
        glEnableVertexAttribArray(index);
        offset += getSizeFromShaderType(layout.type);
        index++;
    }
}