workspace(name = "time")

load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

# =====================================================================
# Boost
# =====================================================================
load("@time//:boost.bzl", "boost")
boost()

load("@com_github_nelhage_rules_boost//:boost/boost.bzl", "boost_deps")
boost_deps()

# =====================================================================
# Googletest
# =====================================================================
git_repository(
    name = "googletest",
    tag = "release-1.8.1",
    remote = "https://github.com/google/googletest",
)
