#pragma once

#ifdef WIN32
#   ifdef LEETCODE_EXPORTS
#       define LEETCODE_API __declspec(dllexport)
#   else // LEETCODE_EXPORTS
#       define LEETCODE_API __declspec(dllimport)
#   endif // LEETCODE_EXPORTS
#else
#   define LEETCODE_API
#endif // WIN32
