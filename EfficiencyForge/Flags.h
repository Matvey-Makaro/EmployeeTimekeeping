#pragma once

#include <cstdint>

using FromFlag = int64_t;
using CodeFlag = int64_t;

namespace FromFlags
{
constexpr FromFlag UserGateway = 1;
constexpr FromFlag ReportItemTypeGateway = 2;
constexpr FromFlag ProjectGateway = 3;
constexpr FromFlag TaskGateway = 4;
constexpr FromFlag ReportGateway = 5;
}

namespace CodeFlags
{
constexpr CodeFlag Success = 1;
constexpr CodeFlag ExecError = 1;
constexpr CodeFlag NotFound = 1;
}


