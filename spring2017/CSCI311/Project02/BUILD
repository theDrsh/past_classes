cc_library(
    name = "libFile",
    srcs = [
        "CensusData.cpp",
        "CensusDataSorts.cpp"
    ],
    hdrs = [
        "CensusData.h"
    ],
)
cc_binary(
    name = "sort",
    srcs = ["CensusSort.cpp"],
    deps = [
        ":libFile"
    ]
)
