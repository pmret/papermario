.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800579D8
/* 32DD8 800579D8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 32DDC 800579DC AFB20018 */  sw        $s2, 0x18($sp)
/* 32DE0 800579E0 00A0902D */  daddu     $s2, $a1, $zero
/* 32DE4 800579E4 308400FF */  andi      $a0, $a0, 0xff
/* 32DE8 800579E8 00041140 */  sll       $v0, $a0, 5
/* 32DEC 800579EC 3C038008 */  lui       $v1, %hi(D_80078E54)
/* 32DF0 800579F0 8C638E54 */  lw        $v1, %lo(D_80078E54)($v1)
/* 32DF4 800579F4 00441023 */  subu      $v0, $v0, $a0
/* 32DF8 800579F8 AFBF001C */  sw        $ra, 0x1c($sp)
/* 32DFC 800579FC AFB10014 */  sw        $s1, 0x14($sp)
/* 32E00 80057A00 AFB00010 */  sw        $s0, 0x10($sp)
/* 32E04 80057A04 8C63001C */  lw        $v1, 0x1c($v1)
/* 32E08 80057A08 00021080 */  sll       $v0, $v0, 2
/* 32E0C 80057A0C 00628021 */  addu      $s0, $v1, $v0
/* 32E10 80057A10 8E050064 */  lw        $a1, 0x64($s0)
/* 32E14 80057A14 8E030068 */  lw        $v1, 0x68($s0)
/* 32E18 80057A18 00A3102A */  slt       $v0, $a1, $v1
/* 32E1C 80057A1C 14400029 */  bnez      $v0, .L80057AC4
/* 32E20 80057A20 26110048 */   addiu    $s1, $s0, 0x48
/* 32E24 80057A24 3C028008 */  lui       $v0, %hi(D_80078181)
/* 32E28 80057A28 24428181 */  addiu     $v0, $v0, %lo(D_80078181)
/* 32E2C 80057A2C 90420000 */  lbu       $v0, ($v0)
/* 32E30 80057A30 1440000E */  bnez      $v0, .L80057A6C
/* 32E34 80057A34 AE030064 */   sw       $v1, 0x64($s0)
/* 32E38 80057A38 3C048008 */  lui       $a0, %hi(AlCosineBlend)
/* 32E3C 80057A3C 24848E60 */  addiu     $a0, $a0, %lo(AlCosineBlend)
/* 32E40 80057A40 8603004E */  lh        $v1, 0x4e($s0)
/* 32E44 80057A44 84820080 */  lh        $v0, 0x80($a0)
/* 32E48 80057A48 00620018 */  mult      $v1, $v0
/* 32E4C 80057A4C 00004012 */  mflo      $t0
/* 32E50 80057A50 000813C3 */  sra       $v0, $t0, 0xf
/* 32E54 80057A54 A6020050 */  sh        $v0, 0x50($s0)
/* 32E58 80057A58 84820080 */  lh        $v0, 0x80($a0)
/* 32E5C 80057A5C 00620018 */  mult      $v1, $v0
/* 32E60 80057A60 00004012 */  mflo      $t0
/* 32E64 80057A64 08015EBB */  j         .L80057AEC
/* 32E68 80057A68 000813C3 */   sra      $v0, $t0, 0xf
.L80057A6C:
/* 32E6C 80057A6C 8602004C */  lh        $v0, 0x4c($s0)
/* 32E70 80057A70 8603004E */  lh        $v1, 0x4e($s0)
/* 32E74 80057A74 00021040 */  sll       $v0, $v0, 1
/* 32E78 80057A78 3C018008 */  lui       $at, %hi(AlCosineBlend)
/* 32E7C 80057A7C 00220821 */  addu      $at, $at, $v0
/* 32E80 80057A80 84228E60 */  lh        $v0, %lo(AlCosineBlend)($at)
/* 32E84 80057A84 00620018 */  mult      $v1, $v0
/* 32E88 80057A88 8603004C */  lh        $v1, 0x4c($s0)
/* 32E8C 80057A8C 00004012 */  mflo      $t0
/* 32E90 80057A90 000813C3 */  sra       $v0, $t0, 0xf
/* 32E94 80057A94 A6020050 */  sh        $v0, 0x50($s0)
/* 32E98 80057A98 2402007F */  addiu     $v0, $zero, 0x7f
/* 32E9C 80057A9C 00431023 */  subu      $v0, $v0, $v1
/* 32EA0 80057AA0 00021040 */  sll       $v0, $v0, 1
/* 32EA4 80057AA4 8603004E */  lh        $v1, 0x4e($s0)
/* 32EA8 80057AA8 3C018008 */  lui       $at, %hi(AlCosineBlend)
/* 32EAC 80057AAC 00220821 */  addu      $at, $at, $v0
/* 32EB0 80057AB0 84228E60 */  lh        $v0, %lo(AlCosineBlend)($at)
/* 32EB4 80057AB4 00620018 */  mult      $v1, $v0
/* 32EB8 80057AB8 00004012 */  mflo      $t0
/* 32EBC 80057ABC 08015EBB */  j         .L80057AEC
/* 32EC0 80057AC0 000813C3 */   sra      $v0, $t0, 0xf
.L80057AC4:
/* 32EC4 80057AC4 86040050 */  lh        $a0, 0x50($s0)
/* 32EC8 80057AC8 8606005A */  lh        $a2, 0x5a($s0)
/* 32ECC 80057ACC 0C016001 */  jal       func_80058004
/* 32ED0 80057AD0 96070058 */   lhu      $a3, 0x58($s0)
/* 32ED4 80057AD4 86040052 */  lh        $a0, 0x52($s0)
/* 32ED8 80057AD8 8E050064 */  lw        $a1, 0x64($s0)
/* 32EDC 80057ADC 86060060 */  lh        $a2, 0x60($s0)
/* 32EE0 80057AE0 9607005E */  lhu       $a3, 0x5e($s0)
/* 32EE4 80057AE4 0C016001 */  jal       func_80058004
/* 32EE8 80057AE8 A6020050 */   sh       $v0, 0x50($s0)
.L80057AEC:
/* 32EEC 80057AEC A6020052 */  sh        $v0, 0x52($s0)
/* 32EF0 80057AF0 86220008 */  lh        $v0, 8($s1)
/* 32EF4 80057AF4 14400002 */  bnez      $v0, .L80057B00
/* 32EF8 80057AF8 24020001 */   addiu    $v0, $zero, 1
/* 32EFC 80057AFC A6220008 */  sh        $v0, 8($s1)
.L80057B00:
/* 32F00 80057B00 8622000A */  lh        $v0, 0xa($s1)
/* 32F04 80057B04 14400003 */  bnez      $v0, .L80057B14
/* 32F08 80057B08 324300FF */   andi     $v1, $s2, 0xff
/* 32F0C 80057B0C 24020001 */  addiu     $v0, $zero, 1
/* 32F10 80057B10 A622000A */  sh        $v0, 0xa($s1)
.L80057B14:
/* 32F14 80057B14 00031040 */  sll       $v0, $v1, 1
/* 32F18 80057B18 3C018008 */  lui       $at, %hi(AlCosineBlend)
/* 32F1C 80057B1C 00220821 */  addu      $at, $at, $v0
/* 32F20 80057B20 94228E60 */  lhu       $v0, %lo(AlCosineBlend)($at)
/* 32F24 80057B24 A622000C */  sh        $v0, 0xc($s1)
/* 32F28 80057B28 2402007F */  addiu     $v0, $zero, 0x7f
/* 32F2C 80057B2C 00431023 */  subu      $v0, $v0, $v1
/* 32F30 80057B30 00021040 */  sll       $v0, $v0, 1
/* 32F34 80057B34 3C038008 */  lui       $v1, %hi(AlCosineBlend)
/* 32F38 80057B38 00621821 */  addu      $v1, $v1, $v0
/* 32F3C 80057B3C 94638E60 */  lhu       $v1, %lo(AlCosineBlend)($v1)
/* 32F40 80057B40 24020001 */  addiu     $v0, $zero, 1
/* 32F44 80057B44 AE220024 */  sw        $v0, 0x24($s1)
/* 32F48 80057B48 A623000E */  sh        $v1, 0xe($s1)
/* 32F4C 80057B4C 8FBF001C */  lw        $ra, 0x1c($sp)
/* 32F50 80057B50 8FB20018 */  lw        $s2, 0x18($sp)
/* 32F54 80057B54 8FB10014 */  lw        $s1, 0x14($sp)
/* 32F58 80057B58 8FB00010 */  lw        $s0, 0x10($sp)
/* 32F5C 80057B5C 03E00008 */  jr        $ra
/* 32F60 80057B60 27BD0020 */   addiu    $sp, $sp, 0x20
