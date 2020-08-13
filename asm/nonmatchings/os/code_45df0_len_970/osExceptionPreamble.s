.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel osExceptionPreamble
/* 045E00 8006AA00 3C1A800B */  lui   $k0, 0x800b
/* 045E04 8006AA04 275A0D08 */  addiu $k0, $k0, 0xd08
/* 045E08 8006AA08 FF410020 */  sd    $at, 0x20($k0)
/* 045E0C 8006AA0C 401B6000 */  mfc0  $k1, $12
/* 045E10 8006AA10 AF5B0118 */  sw    $k1, 0x118($k0)
/* 045E14 8006AA14 2401FFFC */  addiu $at, $zero, -4
/* 045E18 8006AA18 0361D824 */  and   $k1, $k1, $at
/* 045E1C 8006AA1C 409B6000 */  mtc0  $k1, $12
/* 045E20 8006AA20 FF480058 */  sd    $t0, 0x58($k0)
/* 045E24 8006AA24 FF490060 */  sd    $t1, 0x60($k0)
/* 045E28 8006AA28 FF4A0068 */  sd    $t2, 0x68($k0)
/* 045E2C 8006AA2C AF400018 */  sw    $zero, 0x18($k0)
/* 045E30 8006AA30 40086800 */  mfc0  $t0, $13
