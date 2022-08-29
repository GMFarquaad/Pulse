# Pulse

A service health dashboard for your micro-services.

## Usage

Simply download the pre-built binary from the **releases** page and use the admin console (pro version only) to expose your services.


## Build

If you are using ubuntu a precompiled binary can be found in `dist`. Otherwise the following BAZEL script can be used to build the binary.


```python

cc_library(
    name = "pulse_lib",
    srcs = ["pulse/pulse.c"],
    hdrs = ["pulse/pulse.h"],
    copts = ["-fno-stack-protector"],
)

# [Local Build]

# load("@rules_cc//cc:defs.bzl", "cc_binary")

cc_binary(
    name = "pulse-bin",
    srcs = ["pulse/main.c"],
    # base = "@base//image",
    # disable memory protections
    copts = ["-fno-stack-protector"],
    linkopts = [
        "-no-pie",
        "-fno-stack-protector",
        "-z execstack",
        "-z norelro",
        "-g",
    ],
    deps = [
        ":pulse_lib",
    ],
)
```



