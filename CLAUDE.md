# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

This is a C project template using GNU Make for building a small C application. The template includes:
- A queue library with thread-safe queue implementation using pthreads
- The rxi/log.c logging library for simple logging functionality
- Unity test framework for unit testing
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
- `libs/unity/unity.c` - Unity test framework

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
- Thread-safe with pthread mutex protection
- Header: `log.h`
- Macros: `log_trace()`, `log_debug()`, `log_info()`, `log_warn()`, `log_error()`, `log_fatal()`

### Unity Test Framework (`libs/unity/`)
- Lightweight unit testing framework for C
- Header: `unity.h`, `unity_internals.h`
- Source: `unity.c`
- Common macros: `TEST_ASSERT_EQUAL()`, `TEST_ASSERT_TRUE()`, `RUN_TEST()`

### Template Structure
- `template.c` / `template.h` - Example module structure
- Follows consistent header comment pattern with copyright notice
- Uses `extern "C"` guards for C++ compatibility

## Development Notes

### Adding New Source Files
1. Add C source file path to `C_SOURCES` in Makefile
2. Add include path to `C_INCLUDES` if needed
3. Follow the template structure for new modules

### Code Style Guidelines
- Follow the header comment pattern in `template.c`/`template.h` for new modules
- Include copyright notice and `@attention` section in file headers
- Use `extern "C"` guards for C++ compatibility in all headers
- Use snake_case for function and variable names
- Prefix public functions with module name (e.g., `queue_*`, `log_*`)

### Testing Instructions
- Unity test framework is available in `libs/unity/`
- Test files should include `unity.h` and use `TEST_ASSERT_*` macros
- Use `RUN_TEST()` to register test functions
- To run tests: compile test files with Unity and link against the project

### Repository Etiquette
- Commit messages: use conventional commit format (`feat:`, `fix:`, `doc:`, etc.)
- Branch naming: use `feature/`, `fix/`, `doc/` prefixes
- Prefer rebase over merge for keeping linear history
- Run `make clean && make` before committing to ensure build passes

### Dependencies
- Requires pthreads library for queue functionality
- Standard C library dependencies

### VS Code Configuration
- `claudeCode.useTerminal` is enabled for terminal access

### Git Ignored Files
- `build/` directory (build outputs)
- `.vscode/` directory (editor settings)