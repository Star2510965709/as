/**
 * SSAS - Simple Smart Automotive Software
 * Copyright (C) 2021 Parai Wang <parai@foxmail.com>
 */
#ifndef SREC_H
#define SREC_H
/* ================================ [ INCLUDES  ] ============================================== */
#include <stdint.h>
/* ================================ [ MACROS    ] ============================================== */
#define SREC_MAX_BLK 32
/* ================================ [ TYPES     ] ============================================== */
typedef struct {
  uint8_t *data;
  uint32_t address;
  size_t offset;
  size_t length;
} sblk_t;

typedef struct {
  uint8_t *data;
  sblk_t blks[SREC_MAX_BLK];
  size_t numOfBlks;
  size_t totalSize;
} srec_t;
/* ================================ [ DECLARES  ] ============================================== */
/* ================================ [ DATAS     ] ============================================== */
/* ================================ [ LOCALS    ] ============================================== */
/* ================================ [ FUNCTIONS ] ============================================== */
srec_t *srec_open(char *path);
int srec_sign(char *path, size_t total);
void srec_print(srec_t *srec);
uint32_t srec_range(srec_t *srec, uint32_t *length);
void srec_close(srec_t *srec);
#endif /* SREC_H */