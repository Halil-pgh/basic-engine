#pragma once

#include <vector>

enum class ShaderType {
    float4, float3, float2, float1,
    double4, double3, double2, double1,
    int4, int3, int2, int1,
    bool1, bool2
};

class Layout {
public:
    Layout(ShaderType type, bool normalized) : type(type), normalized(normalized) {}

    ShaderType type;
    bool normalized;
};

class VBL {
public:
    VBL() = default;
    VBL(const std::vector<Layout>& layouts);

    void create(const std::vector<Layout>& layouts);
};