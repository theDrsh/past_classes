cc_library(
    name = "primLib",
    srcs = [
        "graph.cpp",
        "minpriority.cpp"
    ],
    hdrs = [
        "graph.h",
        "minpriority.h",
        "mstapp.h"
    ],
)
cc_binary(
    name = "graph",
    srcs = [
        "mstapp.cpp",
    ],
    deps = [
        ":primLib"
    ],
)
