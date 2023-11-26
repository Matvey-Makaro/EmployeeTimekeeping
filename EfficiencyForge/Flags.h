#pragma once

#include <cstdint>

enum class AuthorizationResCode
{
    Success,
    LoginDoesNotMeetRequirements,
    PasswordDoesNotMeetRequirements,
    NoSuchUser,
};

using ResultCode = uint64_t;


