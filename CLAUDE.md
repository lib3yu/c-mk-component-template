# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

This is a C project template using GNU Make for building a small C application. The template includes:
- A queue library with thread-safe queue implementation using pthreads
- The rxi/log.c logging library for simple logging functionality
- Template files for creating new modules
- A Makefile-based build system

## Build System

### Key Commands
- `make` - Builds the project (produces `build/demo`)
- `make clean` - Cleans the build directory
- `make show` - Shows build variables (C_SOURCES, OBJECTS, CFLAGS, LDFLAGS)

### Build Configuration
- `DEBUG=1` enables debug symbols (default)
- Build outputs go to `build/` directory
- Uses `gcc` with optimization level `-Og` for debugging
- Generates dependency files (`*.d`) for incremental builds
- Creates a memory map file (`build/demo.map`)

### Source Files
The Makefile compiles:
- `main.c` - Application entry point
- `libs/queue/queue.c` - Thread-safe queue implementation
- `libs/log.c/log.c` - Logging library

## Code Architecture

### Main Application
- Entry point: `main()` in `main.c`
- Uses queue library for message passing
- Uses log.c library for logging
- Template structure for adding new modules

### Queue Library (`libs/queue/`)
- Thread-safe circular buffer implementation
- Uses pthread mutexes and condition variables
- Supports timeout-based operations
- Functions: `newqueue()`, `delequeue()`, `enqueue()`, `dequeue()`
- Header: `queue.h`

### Log Library (`libs/log.c/`)
- Simple logging library by rxi
- Multiple log levels: TRACE, DEBUG, INFO, WARN, ERROR, FATAL
- Header: `log.h`
- Macros: `log_trace()`, `log_debug()`, `log_info()`, `log_warn()`, `log_error()`, `log_fatal()`

### Template Structure
- `template.c` / `template.h` - Example module structure
- Follows consistent header comment pattern with copyright notice
- Uses `extern "C"` guards for C++ compatibility

## Development Notes

### Adding New Source Files
1. Add C source file path to `C_SOURCES` in Makefile
2. Add include path to `C_INCLUDES` if needed
3. Follow the template structure for new modules

### Dependencies
- Requires pthreads library for queue functionality
- Standard C library dependencies

### VS Code Configuration
- `claudeCode.useTerminal` is enabled for terminal access

### Git Ignored Files
- `build/` directory (build outputs)
- `.vscode/` directory (editor settings)