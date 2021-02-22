.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80031EA0
/* D2A0 80031EA0 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* D2A4 80031EA4 AFB00058 */  sw        $s0, 0x58($sp)
/* D2A8 80031EA8 00E0802D */  daddu     $s0, $a3, $zero
/* D2AC 80031EAC 3C0146FF */  lui       $at, 0x46ff
/* D2B0 80031EB0 3421FE00 */  ori       $at, $at, 0xfe00
/* D2B4 80031EB4 44811000 */  mtc1      $at, $f2
/* D2B8 80031EB8 44802000 */  mtc1      $zero, $f4
/* D2BC 80031EBC 3C01BF80 */  lui       $at, 0xbf80
/* D2C0 80031EC0 44810000 */  mtc1      $at, $f0
/* D2C4 80031EC4 44072000 */  mfc1      $a3, $f4
/* D2C8 80031EC8 27A20038 */  addiu     $v0, $sp, 0x38
/* D2CC 80031ECC AFBF005C */  sw        $ra, 0x5c($sp)
/* D2D0 80031ED0 E7A20044 */  swc1      $f2, 0x44($sp)
/* D2D4 80031ED4 AFA20018 */  sw        $v0, 0x18($sp)
/* D2D8 80031ED8 27A2003C */  addiu     $v0, $sp, 0x3c
/* D2DC 80031EDC AFA2001C */  sw        $v0, 0x1c($sp)
/* D2E0 80031EE0 27A20040 */  addiu     $v0, $sp, 0x40
/* D2E4 80031EE4 AFA20020 */  sw        $v0, 0x20($sp)
/* D2E8 80031EE8 27A20044 */  addiu     $v0, $sp, 0x44
/* D2EC 80031EEC AFA20024 */  sw        $v0, 0x24($sp)
/* D2F0 80031EF0 27A20048 */  addiu     $v0, $sp, 0x48
/* D2F4 80031EF4 AFA20028 */  sw        $v0, 0x28($sp)
/* D2F8 80031EF8 27A2004C */  addiu     $v0, $sp, 0x4c
/* D2FC 80031EFC AFA2002C */  sw        $v0, 0x2c($sp)
/* D300 80031F00 27A20050 */  addiu     $v0, $sp, 0x50
/* D304 80031F04 E7A00010 */  swc1      $f0, 0x10($sp)
/* D308 80031F08 E7A40014 */  swc1      $f4, 0x14($sp)
/* D30C 80031F0C 0C017375 */  jal       func_8005CDD4
/* D310 80031F10 AFA20030 */   sw       $v0, 0x30($sp)
/* D314 80031F14 0040202D */  daddu     $a0, $v0, $zero
/* D318 80031F18 04800010 */  bltz      $a0, .L80031F5C
/* D31C 80031F1C 0000102D */   daddu    $v0, $zero, $zero
/* D320 80031F20 12000007 */  beqz      $s0, .L80031F40
/* D324 80031F24 000410C0 */   sll      $v0, $a0, 3
/* D328 80031F28 00441023 */  subu      $v0, $v0, $a0
/* D32C 80031F2C 3C03800E */  lui       $v1, %hi(D_800D91B4)
/* D330 80031F30 8C6391B4 */  lw        $v1, %lo(D_800D91B4)($v1)
/* D334 80031F34 00021080 */  sll       $v0, $v0, 2
/* D338 80031F38 00621821 */  addu      $v1, $v1, $v0
/* D33C 80031F3C AE030000 */  sw        $v1, ($s0)
.L80031F40:
/* D340 80031F40 000410C0 */  sll       $v0, $a0, 3
/* D344 80031F44 00441023 */  subu      $v0, $v0, $a0
/* D348 80031F48 3C03800E */  lui       $v1, %hi(D_800D91B4)
/* D34C 80031F4C 8C6391B4 */  lw        $v1, %lo(D_800D91B4)($v1)
/* D350 80031F50 00021080 */  sll       $v0, $v0, 2
/* D354 80031F54 00431021 */  addu      $v0, $v0, $v1
/* D358 80031F58 8C420010 */  lw        $v0, 0x10($v0)
.L80031F5C:
/* D35C 80031F5C 8FBF005C */  lw        $ra, 0x5c($sp)
/* D360 80031F60 8FB00058 */  lw        $s0, 0x58($sp)
/* D364 80031F64 03E00008 */  jr        $ra
/* D368 80031F68 27BD0060 */   addiu    $sp, $sp, 0x60
