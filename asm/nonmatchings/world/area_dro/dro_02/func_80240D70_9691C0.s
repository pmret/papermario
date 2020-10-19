.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240D70_969F30
/* 969F30 80240D70 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 969F34 80240D74 AFBF0010 */  sw        $ra, 0x10($sp)
/* 969F38 80240D78 8C82000C */  lw        $v0, 0xc($a0)
/* 969F3C 80240D7C 0C0B1EAF */  jal       get_variable
/* 969F40 80240D80 8C450000 */   lw       $a1, ($v0)
/* 969F44 80240D84 0040202D */  daddu     $a0, $v0, $zero
/* 969F48 80240D88 3C028025 */  lui       $v0, 0x8025
/* 969F4C 80240D8C 8C42EFC0 */  lw        $v0, -0x1040($v0)
/* 969F50 80240D90 24030001 */  addiu     $v1, $zero, 1
/* 969F54 80240D94 8C45000C */  lw        $a1, 0xc($v0)
/* 969F58 80240D98 1083000D */  beq       $a0, $v1, .L80240DD0
/* 969F5C 80240D9C 28820002 */   slti     $v0, $a0, 2
/* 969F60 80240DA0 10400005 */  beqz      $v0, .L80240DB8
/* 969F64 80240DA4 24020002 */   addiu    $v0, $zero, 2
/* 969F68 80240DA8 10800007 */  beqz      $a0, .L80240DC8
/* 969F6C 80240DAC 240200C0 */   addiu    $v0, $zero, 0xc0
/* 969F70 80240DB0 08090378 */  j         .L80240DE0
/* 969F74 80240DB4 ACA00038 */   sw       $zero, 0x38($a1)
.L80240DB8:
/* 969F78 80240DB8 10820008 */  beq       $a0, $v0, .L80240DDC
/* 969F7C 80240DBC 24020040 */   addiu    $v0, $zero, 0x40
/* 969F80 80240DC0 08090378 */  j         .L80240DE0
/* 969F84 80240DC4 ACA00038 */   sw       $zero, 0x38($a1)
.L80240DC8:
/* 969F88 80240DC8 08090378 */  j         .L80240DE0
/* 969F8C 80240DCC ACA20038 */   sw       $v0, 0x38($a1)
.L80240DD0:
/* 969F90 80240DD0 24020080 */  addiu     $v0, $zero, 0x80
/* 969F94 80240DD4 08090378 */  j         .L80240DE0
/* 969F98 80240DD8 ACA20038 */   sw       $v0, 0x38($a1)
.L80240DDC:
/* 969F9C 80240DDC ACA20038 */  sw        $v0, 0x38($a1)
.L80240DE0:
/* 969FA0 80240DE0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 969FA4 80240DE4 24020002 */  addiu     $v0, $zero, 2
/* 969FA8 80240DE8 03E00008 */  jr        $ra
/* 969FAC 80240DEC 27BD0018 */   addiu    $sp, $sp, 0x18
