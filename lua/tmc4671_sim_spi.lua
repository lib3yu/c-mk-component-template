-- TMC4671 SPI Simulator
-- Register storage and SPI callback implementation

local M = {}

-- Register storage for each IC
local registers = {}

-- Initialize registers for an IC
local function init_ic(ic_id)
    if not registers[ic_id] then
        registers[ic_id] = {}
        for addr = 0, 127 do
            registers[ic_id][addr] = 0
        end
    end
end

-- SPI callback function - called by C code
-- @param ic_id     IC index (0-3)
-- @param is_write  true for write, false for read
-- @param address   register address (0-127)
-- @param value     value to write (nil for read)
-- @return value read (for read operations)
function tmc4671_sim_spi(ic_id, is_write, address, value)
    init_ic(ic_id)

    if is_write then
        registers[ic_id][address] = value
        return nil
    else
        return registers[ic_id][address] or 0
    end
end

-- API functions
function M.reset(ic_id)
    init_ic(ic_id)
    for addr = 0, 127 do
        registers[ic_id][addr] = 0
    end
end

function M.get_register(ic_id, address)
    init_ic(ic_id)
    return registers[ic_id][address] or 0
end

function M.set_register(ic_id, address, value)
    init_ic(ic_id)
    registers[ic_id][address] = value
end

-- Register addresses (from TMC4671_HW_Abstraction.h)
M.REG = {
    MODE_MOTION             = 0x63,
    PID_TORQUE_FLUX_TARGET  = 0x64,
    PID_VELOCITY_TARGET     = 0x66,
    PID_POSITION_TARGET     = 0x68,
    PID_TORQUE_FLUX_ACTUAL  = 0x69,
    PID_VELOCITY_ACTUAL     = 0x6A,
    PID_POSITION_ACTUAL     = 0x6B,
    INTERIM_DATA            = 0x6E,
    INTERIM_ADDR            = 0x6F,
}

-- Motion modes
M.MODE = {
    STOPPED  = 0,
    TORQUE   = 1,
    VELOCITY = 2,
    POSITION = 3,
    UQ_UD_EXT = 8,
}

return M
