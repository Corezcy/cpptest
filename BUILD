load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

# cc_binary(
#     name = "test_write",
#     srcs = [":test_write.cc"],
#     deps = ["//dir:foo_cc_proto"],
# )

cc_binary(
    name = "test_read",
    srcs = [":test_read.cc"],
    deps = [
        "//dir:foo_cc_proto",
        "@fawai_common_proto//:common_cc_proto",
    ],
)
