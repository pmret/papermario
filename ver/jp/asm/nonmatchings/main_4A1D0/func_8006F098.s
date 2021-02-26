.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006F098
/* 4A498 8006F098 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 4A49C 8006F09C AFBF0014 */  sw        $ra, 0x14($sp)
/* 4A4A0 8006F0A0 AFA40020 */  sw        $a0, 0x20($sp)
/* 4A4A4 8006F0A4 3C04800B */  lui       $a0, %hi(D_800B0C50)
/* 4A4A8 8006F0A8 24840C50 */  addiu     $a0, $a0, %lo(D_800B0C50)
/* 4A4AC 8006F0AC 3C05800B */  lui       $a1, %hi(D_800B0C5C)
/* 4A4B0 8006F0B0 8CA50C5C */  lw        $a1, %lo(D_800B0C5C)($a1)
/* 4A4B4 8006F0B4 3C010001 */  lui       $at, 1
/* 4A4B8 8006F0B8 00A17025 */  or        $t6, $a1, $at
/* 4A4BC 8006F0BC 01C02825 */  or        $a1, $t6, $zero
/* 4A4C0 8006F0C0 3C06D200 */  lui       $a2, 0xd200
/* 4A4C4 8006F0C4 0C01834C */  jal       func_80060D30
/* 4A4C8 8006F0C8 00000000 */   nop
/* 4A4CC 8006F0CC 3C04800B */  lui       $a0, %hi(D_800B0C50)
/* 4A4D0 8006F0D0 24840C50 */  addiu     $a0, $a0, %lo(D_800B0C50)
/* 4A4D4 8006F0D4 3C05800B */  lui       $a1, %hi(D_800B0C5C)
/* 4A4D8 8006F0D8 8CA50C5C */  lw        $a1, %lo(D_800B0C5C)($a1)
/* 4A4DC 8006F0DC 27A6001C */  addiu     $a2, $sp, 0x1c
/* 4A4E0 8006F0E0 0C018364 */  jal       func_80060D90
/* 4A4E4 8006F0E4 00000000 */   nop
/* 4A4E8 8006F0E8 3C04800B */  lui       $a0, %hi(D_800B0C50)
/* 4A4EC 8006F0EC 24840C50 */  addiu     $a0, $a0, %lo(D_800B0C50)
/* 4A4F0 8006F0F0 3C05800B */  lui       $a1, %hi(D_800B0C5C)
/* 4A4F4 8006F0F4 8CA50C5C */  lw        $a1, %lo(D_800B0C5C)($a1)
/* 4A4F8 8006F0F8 3C010001 */  lui       $at, 1
/* 4A4FC 8006F0FC 00A17825 */  or        $t7, $a1, $at
/* 4A500 8006F100 01E02825 */  or        $a1, $t7, $zero
/* 4A504 8006F104 3C06D200 */  lui       $a2, 0xd200
/* 4A508 8006F108 0C01834C */  jal       func_80060D30
/* 4A50C 8006F10C 00000000 */   nop
/* 4A510 8006F110 3C04800B */  lui       $a0, %hi(D_800B0C50)
/* 4A514 8006F114 24840C50 */  addiu     $a0, $a0, %lo(D_800B0C50)
/* 4A518 8006F118 3C05800B */  lui       $a1, %hi(D_800B0C5C)
/* 4A51C 8006F11C 8CA50C5C */  lw        $a1, %lo(D_800B0C5C)($a1)
/* 4A520 8006F120 27A6001C */  addiu     $a2, $sp, 0x1c
/* 4A524 8006F124 0C018364 */  jal       func_80060D90
/* 4A528 8006F128 00000000 */   nop
/* 4A52C 8006F12C 8FB8001C */  lw        $t8, 0x1c($sp)
/* 4A530 8006F130 00000000 */  nop
/* 4A534 8006F134 331900FF */  andi      $t9, $t8, 0xff
/* 4A538 8006F138 8FA80020 */  lw        $t0, 0x20($sp)
/* 4A53C 8006F13C 00000000 */  nop
/* 4A540 8006F140 A1190000 */  sb        $t9, ($t0)
/* 4A544 8006F144 10000003 */  b         .L8006F154
/* 4A548 8006F148 00000000 */   nop
/* 4A54C 8006F14C 10000001 */  b         .L8006F154
/* 4A550 8006F150 00000000 */   nop
.L8006F154:
/* 4A554 8006F154 8FBF0014 */  lw        $ra, 0x14($sp)
/* 4A558 8006F158 27BD0020 */  addiu     $sp, $sp, 0x20
/* 4A55C 8006F15C 03E00008 */  jr        $ra
/* 4A560 8006F160 00000000 */   nop
