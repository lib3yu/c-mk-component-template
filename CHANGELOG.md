# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.1.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [Unreleased]

### Added

- TMC4671 API integration from Analog Devices TMC-API library
- Lua 5.5 scripting engine (onelua.c single-file build)
- Lua integration tests and Unity test cases

### Changed

- Project purpose: TMC4671 API simulation and high-level interface design with Lua

## [0.1.0] - 2025-12-24

### Added

- Initial project structure with GNU Make build system
- Simple logging library from [rxi/log.c](https://github.com/rxi/log.c)
- Thread-safe logging with pthread mutex protection
- Unity test framework for unit testing (`libs/unity/`)
- Module template files (`template.c`, `template.h`)

[Unreleased]: https://github.com/akaka/tmc4671/compare/v0.1.0...HEAD
[0.1.0]: https://github.com/akaka/tmc4671/releases/tag/v0.1.0
