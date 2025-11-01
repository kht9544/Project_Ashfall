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

UENUM()
enum class EAshfallSuccessType : uint8
{
    Successful,
    Failed
};