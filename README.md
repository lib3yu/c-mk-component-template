# TMC4671 Lua Simulator

使用 Lua 脚本模拟测试 TMC4671 电机控制器 API，并规划高层接口设计。

## Overview

本项目通过 Lua 脚本引擎模拟 TMC4671 FOC 电机控制器的行为，在无需真实硬件的情况下：
- 测试和验证控制逻辑
- 设计和迭代高层接口
- 进行单元测试和回归测试

### 核心组件
- `libs/tmc-api/` - TMC4671 官方 API (Analog Devices/Trinamic)
- `libs/lua-src/` - Lua 5.5 解释器
- `libs/unity/` - Unity 单元测试框架
- `libs/log.c/` - 线程安全日志库
- `libs/queue/` - 线程安全队列

## Build

```bash
make        # 构建，输出 build/demo
make clean  # 清理 build/ 目录
make show   # 显示构建变量
```

## Run

```bash
./build/demo
```

## TMC4671 API

TMC4671 是 FOC 电机控制器 IC，支持：
- **Torque Mode** - 力矩/电流控制
- **Velocity Mode** - 速度控制
- **Position Mode** - 位置控制

API 头文件: `libs/tmc-api/tmc/TMC4671/TMC4671.h`

## Project Layout

```
├── Makefile              # 构建配置
├── main.c                # 程序入口
├── libs/
│   ├── tmc-api/          # TMC4671 API
│   ├── lua-src/          # Lua 5.5
│   ├── unity/            # 测试框架
│   ├── log.c/            # 日志库
│   └── queue/            # 队列库
└── template.c/h          # 模块模板
```

## Dependencies

- GCC (C11)
- pthread
- Lua 5.5
