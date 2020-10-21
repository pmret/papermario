.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240ED0_843AA0
/* 843AA0 80240ED0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 843AA4 80240ED4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 843AA8 80240ED8 8C82000C */  lw        $v0, 0xc($a0)
/* 843AAC 80240EDC 0C0B1EAF */  jal       get_variable
/* 843AB0 80240EE0 8C450000 */   lw       $a1, ($v0)
/* 843AB4 80240EE4 0040202D */  daddu     $a0, $v0, $zero
/* 843AB8 80240EE8 3C028025 */  lui       $v0, 0x8025
/* 843ABC 80240EEC 8C42F5C0 */  lw        $v0, -0xa40($v0)
/* 843AC0 80240EF0 24030001 */  addiu     $v1, $zero, 1
/* 843AC4 80240EF4 8C45000C */  lw        $a1, 0xc($v0)
/* 843AC8 80240EF8 1083000D */  beq       $a0, $v1, .L80240F30
/* 843ACC 80240EFC 28820002 */   slti     $v0, $a0, 2
/* 843AD0 80240F00 10400005 */  beqz      $v0, .L80240F18
/* 843AD4 80240F04 24020002 */   addiu    $v0, $zero, 2
/* 843AD8 80240F08 10800007 */  beqz      $a0, .L80240F28
/* 843ADC 80240F0C 240200C0 */   addiu    $v0, $zero, 0xc0
/* 843AE0 80240F10 080903D0 */  j         .L80240F40
/* 843AE4 80240F14 ACA00038 */   sw       $zero, 0x38($a1)
.L80240F18:
/* 843AE8 80240F18 10820008 */  beq       $a0, $v0, .L80240F3C
/* 843AEC 80240F1C 24020040 */   addiu    $v0, $zero, 0x40
/* 843AF0 80240F20 080903D0 */  j         .L80240F40
/* 843AF4 80240F24 ACA00038 */   sw       $zero, 0x38($a1)
.L80240F28:
/* 843AF8 80240F28 080903D0 */  j         .L80240F40
/* 843AFC 80240F2C ACA20038 */   sw       $v0, 0x38($a1)
.L80240F30:
/* 843B00 80240F30 24020080 */  addiu     $v0, $zero, 0x80
/* 843B04 80240F34 080903D0 */  j         .L80240F40
/* 843B08 80240F38 ACA20038 */   sw       $v0, 0x38($a1)
.L80240F3C:
/* 843B0C 80240F3C ACA20038 */  sw        $v0, 0x38($a1)
.L80240F40:
/* 843B10 80240F40 8FBF0010 */  lw        $ra, 0x10($sp)
/* 843B14 80240F44 24020002 */  addiu     $v0, $zero, 2
/* 843B18 80240F48 03E00008 */  jr        $ra
/* 843B1C 80240F4C 27BD0018 */   addiu    $sp, $sp, 0x18
