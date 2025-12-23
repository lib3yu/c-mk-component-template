# c-mk-template
Simple GNU Make–based starter project that builds a tiny C application.

## Overview
- `main.c` (and `template.c`) currently implement a basic `main()` that prints `Hello World!`.
- `template.h` provides the scaffolding for future shared declarations.
- `Makefile` drives the build, keeping outputs under `build/`.

## Build
- Run `make` to compile everything; the default target produces `build/demo` using `gcc` with debug info.
- `make clean` removes the `build/` directory.

## Run
- After building, execute `./build/demo` to see the `Hello World!` output.

## Project layout
- `Makefile`: configurable compiler flags, include paths, and build directory.
- `main.c`: application entry point and public includes.
- `template.c` / `template.h`: example module structure to expand upon.

## 中文说明
- 本项目使用 GNU Make 构建，目标是生成一个简单的 C 应用程序。
- `main.c` 与 `template.c` 目前都实现了一个打印 `Hello World!` 的 `main()`。
- `template.h` 提供头文件模板，用于后续共享声明。
- 所有编译输出都放在 `build/` 目录下，由 `Makefile` 统一管理。

### 构建
- 执行 `make` 生成 `build/demo`，默认使用带调试信息的 `gcc`。
- `make clean` 会清理 `build/` 目录。

### 运行
- 构建完成后运行 `./build/demo` 查看输出。

### 项目结构
- `Makefile`：可配置的编译器标志、包含路径和输出目录。
- `main.c`：程序入口与公共包含部分。
- `template.c` / `template.h`：预留的模块结构，可据此扩展功能。
