cc_library(
    name = "rbLib",
    srcs = [
        "rbtree.cpp"
    ],
    hdrs = [
        "rbapp.h",
        "rbtree.h"
    ],
)
cc_binary(
    name = "run",
    srcs = [
        "rbapp.cpp"
    ],
    deps = [
        ":rbLib"
    ],
)
