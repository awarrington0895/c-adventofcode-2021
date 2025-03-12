const std = @import("std");

pub fn build(b: *std.Build) void {
    const target = b.standardTargetOptions(.{}); // Allows specifying target via CLI
    const optimize = b.standardOptimizeOption(.{}); // Allows specifying optimization level

    const exe = b.addExecutable(.{
        .name = "hello",
        .target = target,
        .optimize = optimize,
    });

    // exe.addCSourceFile(.{
    //     .file = b.path("d1p2.c"), // Corrected: Use b.path() instead of .path
    //     .flags = &.{"-std=c99"},
    // });

    const files = &.{ "d1p2.c", "window.c" };

    exe.addCSourceFiles(.{ .files = files });
    // exe.addCSourceFile(.{
    //     .file = b.path("window.c"),
    //     .flags = &.{"-std=c99"},
    // });

    exe.linkLibC(); // Ensure linking with libc
    b.installArtifact(exe);
}
