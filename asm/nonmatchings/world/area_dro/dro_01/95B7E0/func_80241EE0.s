.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241EE0
/* 95D0E0 80241EE0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 95D0E4 80241EE4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 95D0E8 80241EE8 8C82000C */  lw        $v0, 0xc($a0)
/* 95D0EC 80241EEC 0C0B1EAF */  jal       get_variable
/* 95D0F0 80241EF0 8C450000 */   lw       $a1, ($v0)
/* 95D0F4 80241EF4 0040202D */  daddu     $a0, $v0, $zero
/* 95D0F8 80241EF8 3C028025 */  lui       $v0, 0x8025
/* 95D0FC 80241EFC 8C42DFE0 */  lw        $v0, -0x2020($v0)
/* 95D100 80241F00 24030001 */  addiu     $v1, $zero, 1
/* 95D104 80241F04 8C45000C */  lw        $a1, 0xc($v0)
/* 95D108 80241F08 1083000D */  beq       $a0, $v1, .L80241F40
/* 95D10C 80241F0C 28820002 */   slti     $v0, $a0, 2
/* 95D110 80241F10 10400005 */  beqz      $v0, .L80241F28
/* 95D114 80241F14 24020002 */   addiu    $v0, $zero, 2
/* 95D118 80241F18 10800007 */  beqz      $a0, .L80241F38
/* 95D11C 80241F1C 240200C0 */   addiu    $v0, $zero, 0xc0
/* 95D120 80241F20 080907D4 */  j         .L80241F50
/* 95D124 80241F24 ACA00038 */   sw       $zero, 0x38($a1)
.L80241F28:
/* 95D128 80241F28 10820008 */  beq       $a0, $v0, .L80241F4C
/* 95D12C 80241F2C 24020040 */   addiu    $v0, $zero, 0x40
/* 95D130 80241F30 080907D4 */  j         .L80241F50
/* 95D134 80241F34 ACA00038 */   sw       $zero, 0x38($a1)
.L80241F38:
/* 95D138 80241F38 080907D4 */  j         .L80241F50
/* 95D13C 80241F3C ACA20038 */   sw       $v0, 0x38($a1)
.L80241F40:
/* 95D140 80241F40 24020080 */  addiu     $v0, $zero, 0x80
/* 95D144 80241F44 080907D4 */  j         .L80241F50
/* 95D148 80241F48 ACA20038 */   sw       $v0, 0x38($a1)
.L80241F4C:
/* 95D14C 80241F4C ACA20038 */  sw        $v0, 0x38($a1)
.L80241F50:
/* 95D150 80241F50 8FBF0010 */  lw        $ra, 0x10($sp)
/* 95D154 80241F54 24020002 */  addiu     $v0, $zero, 2
/* 95D158 80241F58 03E00008 */  jr        $ra
/* 95D15C 80241F5C 27BD0018 */   addiu    $sp, $sp, 0x18
