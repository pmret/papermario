.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8002AF30
/* 6330 8002AF30 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 6334 8002AF34 3C02800E */  lui       $v0, %hi(D_800D95C8)
/* 6338 8002AF38 244295C8 */  addiu     $v0, $v0, %lo(D_800D95C8)
/* 633C 8002AF3C AFB00010 */  sw        $s0, 0x10($sp)
/* 6340 8002AF40 0040802D */  daddu     $s0, $v0, $zero
/* 6344 8002AF44 3C058007 */  lui       $a1, %hi(D_800745B0)
/* 6348 8002AF48 24A545B0 */  addiu     $a1, $a1, %lo(D_800745B0)
/* 634C 8002AF4C AFBF0014 */  sw        $ra, 0x14($sp)
/* 6350 8002AF50 0C01BB54 */  jal       func_8006ED50
/* 6354 8002AF54 0200202D */   daddu    $a0, $s0, $zero
/* 6358 8002AF58 1440000B */  bnez      $v0, .L8002AF88
/* 635C 8002AF5C 0000102D */   daddu    $v0, $zero, $zero
/* 6360 8002AF60 8E020034 */  lw        $v0, 0x34($s0)
/* 6364 8002AF64 8E030030 */  lw        $v1, 0x30($s0)
/* 6368 8002AF68 00021027 */  nor       $v0, $zero, $v0
/* 636C 8002AF6C 54620006 */  bnel      $v1, $v0, .L8002AF88
/* 6370 8002AF70 0000102D */   daddu    $v0, $zero, $zero
/* 6374 8002AF74 0C00ABC0 */  jal       func_8002AF00
/* 6378 8002AF78 00000000 */   nop
/* 637C 8002AF7C 8E030030 */  lw        $v1, 0x30($s0)
/* 6380 8002AF80 00431026 */  xor       $v0, $v0, $v1
/* 6384 8002AF84 2C420001 */  sltiu     $v0, $v0, 1
.L8002AF88:
/* 6388 8002AF88 8FBF0014 */  lw        $ra, 0x14($sp)
/* 638C 8002AF8C 8FB00010 */  lw        $s0, 0x10($sp)
/* 6390 8002AF90 03E00008 */  jr        $ra
/* 6394 8002AF94 27BD0018 */   addiu    $sp, $sp, 0x18
