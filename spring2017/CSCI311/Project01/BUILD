cc_library(
  name = "restLib",
  srcs = [
          "party.cc",
          "table.cc"
  ],
  hdrs = [
          "doublylinkedlist.h",
          "restaurant.h",
          "table.h",
          "party.h"
  ],
  )
cc_binary(
  name = "restaurant",
  srcs = ["restaurant.cc"],
  deps = [
          ":restLib",
  ],
  )
