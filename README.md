# c-mk-component-template
Simple GNU Make–based C project template with thread-safe components.

## Overview
- `main.c` implements thread-safe logging initialization and queue demonstration
- Thread-safe queue library (`libs/queue/`) for message passing using pthreads
- Simple logging library (`libs/log.c/`) with multiple log levels and thread-safe mutex protection
- `template.c` / `template.h` provide scaffolding for new modules
- `Makefile` drives the build, keeping outputs under `build/`

## Build
- Run `make` to compile everything; produces `build/demo` using `gcc` with debug info
- `make clean` removes the `build/` directory
- `make show` shows build variables (C_SOURCES, OBJECTS, CFLAGS, LDFLAGS)

## Run
After building, execute `./build/demo` to see:
```
[INFO] Log system initialized with thread-safe mutex
[INFO] Hello log.c
Hello World!, 0
```

## Project layout
- `Makefile`: configurable compiler flags, include paths, and build directory
- `main.c`: application entry point with thread-safe logging
- `libs/queue/`: thread-safe circular buffer implementation
- `libs/log.c/`: simple logging library by rxi
- `template.c` / `template.h`: example module structure

## 中文说明
- 本项目使用 GNU Make 构建，包含线程安全组件的 C 语言项目模板。
- `main.c` 实现线程安全日志初始化和队列演示
- 线程安全队列库 (`libs/queue/`) 使用 pthreads 进行消息传递
- 简单日志库 (`libs/log.c/`) 支持多级日志输出和线程安全互斥锁保护
- `template.c` / `template.h` 提供新模块的模板结构
- 所有编译输出都放在 `build/` 目录下，由 `Makefile` 统一管理

### 构建
- 执行 `make` 生成 `build/demo`，默认使用带调试信息的 `gcc`
- `make clean` 会清理 `build/` 目录
- `make show` 显示构建变量

### 运行
构建完成后运行 `./build/demo` 查看输出。

### 项目结构
- `Makefile`：可配置的编译器标志、包含路径和输出目录
- `main.c`：程序入口与线程安全日志
- `libs/queue/`：线程安全队列实现
- `libs/log.c/`：日志库
- `template.c` / `template.h`：预留的模块结构
