.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel savecontext
/* 045E34 8006AA34 03404021 */  addu  $t0, $k0, $zero
/* 045E38 8006AA38 3C1A8009 */  lui   $k0, 0x8009
/* 045E3C 8006AA3C 8F5A4660 */  lw    $k0, 0x4660($k0)
/* 045E40 8006AA40 DD090020 */  ld    $t1, 0x20($t0)
/* 045E44 8006AA44 FF490020 */  sd    $t1, 0x20($k0)
/* 045E48 8006AA48 DD090118 */  ld    $t1, 0x118($t0)
/* 045E4C 8006AA4C FF490118 */  sd    $t1, 0x118($k0)
/* 045E50 8006AA50 DD090058 */  ld    $t1, 0x58($t0)
/* 045E54 8006AA54 FF490058 */  sd    $t1, 0x58($k0)
/* 045E58 8006AA58 DD090060 */  ld    $t1, 0x60($t0)
/* 045E5C 8006AA5C FF490060 */  sd    $t1, 0x60($k0)
/* 045E60 8006AA60 DD090068 */  ld    $t1, 0x68($t0)
/* 045E64 8006AA64 FF490068 */  sd    $t1, 0x68($k0)
/* 045E68 8006AA68 FF420028 */  sd    $v0, 0x28($k0)
/* 045E6C 8006AA6C FF430030 */  sd    $v1, 0x30($k0)
/* 045E70 8006AA70 FF440038 */  sd    $a0, 0x38($k0)
/* 045E74 8006AA74 FF450040 */  sd    $a1, 0x40($k0)
/* 045E78 8006AA78 FF460048 */  sd    $a2, 0x48($k0)
/* 045E7C 8006AA7C FF470050 */  sd    $a3, 0x50($k0)
/* 045E80 8006AA80 FF4B0070 */  sd    $t3, 0x70($k0)
/* 045E84 8006AA84 FF4C0078 */  sd    $t4, 0x78($k0)
/* 045E88 8006AA88 FF4D0080 */  sd    $t5, 0x80($k0)
/* 045E8C 8006AA8C FF4E0088 */  sd    $t6, 0x88($k0)
/* 045E90 8006AA90 FF4F0090 */  sd    $t7, 0x90($k0)
/* 045E94 8006AA94 FF500098 */  sd    $s0, 0x98($k0)
/* 045E98 8006AA98 FF5100A0 */  sd    $s1, 0xa0($k0)
/* 045E9C 8006AA9C FF5200A8 */  sd    $s2, 0xa8($k0)
/* 045EA0 8006AAA0 FF5300B0 */  sd    $s3, 0xb0($k0)
/* 045EA4 8006AAA4 FF5400B8 */  sd    $s4, 0xb8($k0)
/* 045EA8 8006AAA8 FF5500C0 */  sd    $s5, 0xc0($k0)
/* 045EAC 8006AAAC FF5600C8 */  sd    $s6, 0xc8($k0)
/* 045EB0 8006AAB0 FF5700D0 */  sd    $s7, 0xd0($k0)
/* 045EB4 8006AAB4 FF5800D8 */  sd    $t8, 0xd8($k0)
/* 045EB8 8006AAB8 FF5900E0 */  sd    $t9, 0xe0($k0)
/* 045EBC 8006AABC FF5C00E8 */  sd    $gp, 0xe8($k0)
/* 045EC0 8006AAC0 FF5D00F0 */  sd    $sp, 0xf0($k0)
/* 045EC4 8006AAC4 FF5E00F8 */  sd    $fp, 0xf8($k0)
/* 045EC8 8006AAC8 FF5F0100 */  sd    $ra, 0x100($k0)
/* 045ECC 8006AACC 00004012 */  mflo  $t0
/* 045ED0 8006AAD0 FF480108 */  sd    $t0, 0x108($k0)
/* 045ED4 8006AAD4 00004010 */  mfhi  $t0
/* 045ED8 8006AAD8 FF480110 */  sd    $t0, 0x110($k0)
/* 045EDC 8006AADC 8F5B0118 */  lw    $k1, 0x118($k0)
/* 045EE0 8006AAE0 3369FF00 */  andi  $t1, $k1, 0xff00
/* 045EE4 8006AAE4 11200013 */  beqz  $t1, .L8006AB34
/* 045EE8 8006AAE8 00000000 */   nop   
/* 045EEC 8006AAEC 3C088009 */  lui   $t0, 0x8009
/* 045EF0 8006AAF0 25085900 */  addiu $t0, $t0, 0x5900
/* 045EF4 8006AAF4 8D080000 */  lw    $t0, ($t0)
/* 045EF8 8006AAF8 2401FFFF */  addiu $at, $zero, -1
/* 045EFC 8006AAFC 01015026 */  xor   $t2, $t0, $at
/* 045F00 8006AB00 314AFF00 */  andi  $t2, $t2, 0xff00
/* 045F04 8006AB04 012A6025 */  or    $t4, $t1, $t2
/* 045F08 8006AB08 3C01FFFF */  lui   $at, 0xffff
/* 045F0C 8006AB0C 342100FF */  ori   $at, $at, 0xff
/* 045F10 8006AB10 03615824 */  and   $t3, $k1, $at
/* 045F14 8006AB14 016C5825 */  or    $t3, $t3, $t4
/* 045F18 8006AB18 AF4B0118 */  sw    $t3, 0x118($k0)
/* 045F1C 8006AB1C 3108FF00 */  andi  $t0, $t0, 0xff00
/* 045F20 8006AB20 01284824 */  and   $t1, $t1, $t0
/* 045F24 8006AB24 3C01FFFF */  lui   $at, 0xffff
/* 045F28 8006AB28 342100FF */  ori   $at, $at, 0xff
/* 045F2C 8006AB2C 0361D824 */  and   $k1, $k1, $at
/* 045F30 8006AB30 0369D825 */  or    $k1, $k1, $t1
