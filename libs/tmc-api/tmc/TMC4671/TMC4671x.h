#ifndef TMC4671X_H_
#define TMC4671X_H_

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "TMC4671.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef TMC4671x_MAX_IC
    #define TMC4671x_MAX_IC  8
#endif

typedef struct {
    bool pwmSaturated;
    bool adcClipped;
    bool watchdogError;
    bool limitActive;
} TMC4671x_Fault_t;

typedef struct {
    int32_t  position;
    int32_t  velocity;
    int32_t  torque;
    uint32_t status;
} TMC4671x_ActualAll_t;

typedef struct {
    uint8_t motionMode;
    void *priv;
} TMC4671x_Obj_t;

extern void tmc4671_readWriteSPI(uint16_t icID, uint8_t *data, size_t dataLength);
extern void tmc4671x_writeEnable(uint16_t icID, uint8_t en);

void tmc4671x_init(uint16_t icID);
void tmc4671x_deinit(uint16_t icID);
bool tmc4671x_isEnabled(uint16_t icID);
void tmc4671x_enable(uint16_t icID);
void tmc4671x_disable(uint16_t icID);
void tmc4671x_checkFault(uint16_t icID, TMC4671x_Fault_t *out);

void tmc4671x_switchToMotionMode(uint16_t icID, uint8_t mode);
void tmc4671x_setTargetTorque_raw(uint16_t icID, int32_t torque);
void tmc4671x_setTargetTorque_mA(uint16_t icID, uint16_t factor, int32_t torque);
void tmc4671x_setTargetVelocity(uint16_t icID, int32_t velocity);
void tmc4671x_setAbsoluteTargetPosition(uint16_t icID, int32_t position);
void tmc4671x_setRelativeTargetPosition(uint16_t icID, int32_t offset);

uint8_t  tmc4671x_getMotionMode(uint16_t icID);
int32_t  tmc4671x_getActualPosition(uint16_t icID);
int32_t  tmc4671x_getActualVelocity(uint16_t icID);
int32_t  tmc4671x_getActualTorque_raw(uint16_t icID);
int32_t  tmc4671x_getActualTorque_mA(uint16_t icID, uint16_t factor);
uint32_t tmc4671x_getStatusFlags(uint16_t icID);
void     tmc4671x_getActualAll(uint16_t icID, TMC4671x_ActualAll_t *data);

#ifdef __cplusplus
}
#endif

#endif
