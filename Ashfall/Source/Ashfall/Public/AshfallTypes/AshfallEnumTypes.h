#pragma once

#include <cstdint>
UENUM()
enum class EAshfallConfirmType : uint8
{
	Yes,
	No
};

UENUM()
enum class EAshfallValidType : uint8
{
    Valid,
    Invalid
};