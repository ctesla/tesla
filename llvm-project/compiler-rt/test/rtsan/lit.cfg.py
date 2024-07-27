import os

# Setup config name.
config.name = "RTSAN" + config.name_suffix

# Setup source root.
config.test_source_root = os.path.dirname(__file__)

# Setup default compiler flags use with -frtsan-instrument option.
clang_rtsan_cflags = ["-frtsan-instrument", config.target_cflags]

clang_rtsan_cxxflags = config.cxx_mode_flags + clang_rtsan_cflags


def build_invocation(compile_flags):
    return " " + " ".join([config.clang] + compile_flags) + " "


# Assume that llvm-rtsan is in the config.llvm_tools_dir.
llvm_rtsan = os.path.join(config.llvm_tools_dir, "llvm-rtsan")

# Setup substitutions.
if config.host_os == "Linux":
    libdl_flag = "-ldl"
else:
    libdl_flag = ""

config.substitutions.append(("%clang ", build_invocation([config.target_cflags])))
config.substitutions.append(
    ("%clangxx ", build_invocation(config.cxx_mode_flags + [config.target_cflags]))
)
config.substitutions.append(("%clang_rtsan ", build_invocation(clang_rtsan_cflags)))
config.substitutions.append(("%clangxx_rtsan", build_invocation(clang_rtsan_cxxflags)))
config.substitutions.append(("%llvm_rtsan", llvm_rtsan))

# Default test suffixes.
config.suffixes = [".c", ".cpp"]

if config.host_os not in ["Darwin", "FreeBSD", "Linux", "NetBSD", "OpenBSD"]:
    config.unsupported = True
elif "64" not in config.host_arch:
    if "arm" in config.host_arch:
        if "-mthumb" in config.target_cflags:
            config.unsupported = True
    else:
        config.unsupported = True

if config.host_os == "NetBSD":
    config.substitutions.insert(0, ("%run", config.netbsd_nomprotect_prefix))
