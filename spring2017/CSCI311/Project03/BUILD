cc_library(
    name = "hashLib",
    srcs = [
        "hash.cpp",
        "hash_function.cpp"
    ],
    hdrs = [
        "hash.h"
    ],
)
cc_binary(
    name = "main",
    srcs = [
        "main.cpp",
        "hash.cpp",
    ],
    deps = [
        ":hashLib"
    ],
)
