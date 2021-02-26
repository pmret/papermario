.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003A9E4
/* 15DE4 8003A9E4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 15DE8 8003A9E8 AFB00010 */  sw        $s0, 0x10($sp)
/* 15DEC 8003A9EC 0080802D */  daddu     $s0, $a0, $zero
/* 15DF0 8003A9F0 AFBF0014 */  sw        $ra, 0x14($sp)
/* 15DF4 8003A9F4 8E030000 */  lw        $v1, ($s0)
/* 15DF8 8003A9F8 3C040010 */  lui       $a0, 0x10
/* 15DFC 8003A9FC 00641024 */  and       $v0, $v1, $a0
/* 15E00 8003AA00 14400016 */  bnez      $v0, .L8003AA5C
/* 15E04 8003AA04 00641025 */   or       $v0, $v1, $a0
/* 15E08 8003AA08 240400F4 */  addiu     $a0, $zero, 0xf4
/* 15E0C 8003AA0C 0C00AB29 */  jal       func_8002ACA4
/* 15E10 8003AA10 AE020000 */   sw       $v0, ($s0)
/* 15E14 8003AA14 14400003 */  bnez      $v0, .L8003AA24
/* 15E18 8003AA18 AE020020 */   sw       $v0, 0x20($s0)
.L8003AA1C:
/* 15E1C 8003AA1C 0800EA87 */  j         .L8003AA1C
/* 15E20 8003AA20 00000000 */   nop
.L8003AA24:
/* 15E24 8003AA24 0000202D */  daddu     $a0, $zero, $zero
/* 15E28 8003AA28 0040182D */  daddu     $v1, $v0, $zero
/* 15E2C 8003AA2C A0600000 */  sb        $zero, ($v1)
/* 15E30 8003AA30 A0600001 */  sb        $zero, 1($v1)
.L8003AA34:
/* 15E34 8003AA34 C6000038 */  lwc1      $f0, 0x38($s0)
/* 15E38 8003AA38 E4600004 */  swc1      $f0, 4($v1)
/* 15E3C 8003AA3C C600003C */  lwc1      $f0, 0x3c($s0)
/* 15E40 8003AA40 24840001 */  addiu     $a0, $a0, 1
/* 15E44 8003AA44 E4600054 */  swc1      $f0, 0x54($v1)
/* 15E48 8003AA48 C6000040 */  lwc1      $f0, 0x40($s0)
/* 15E4C 8003AA4C 28820014 */  slti      $v0, $a0, 0x14
/* 15E50 8003AA50 E46000A4 */  swc1      $f0, 0xa4($v1)
/* 15E54 8003AA54 1440FFF7 */  bnez      $v0, .L8003AA34
/* 15E58 8003AA58 24630004 */   addiu    $v1, $v1, 4
.L8003AA5C:
/* 15E5C 8003AA5C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 15E60 8003AA60 8FB00010 */  lw        $s0, 0x10($sp)
/* 15E64 8003AA64 03E00008 */  jr        $ra
/* 15E68 8003AA68 27BD0018 */   addiu    $sp, $sp, 0x18
