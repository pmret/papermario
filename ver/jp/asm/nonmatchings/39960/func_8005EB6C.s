.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005EB6C
/* 39F6C 8005EB6C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 39F70 8005EB70 AFB00010 */  sw        $s0, 0x10($sp)
/* 39F74 8005EB74 0080802D */  daddu     $s0, $a0, $zero
/* 39F78 8005EB78 AFBF0014 */  sw        $ra, 0x14($sp)
/* 39F7C 8005EB7C 0C018244 */  jal       func_80060910
/* 39F80 8005EB80 24040001 */   addiu    $a0, $zero, 1
/* 39F84 8005EB84 3C06800E */  lui       $a2, %hi(D_800DAA88)
/* 39F88 8005EB88 24C6AA88 */  addiu     $a2, $a2, %lo(D_800DAA88)
/* 39F8C 8005EB8C 0000282D */  daddu     $a1, $zero, $zero
/* 39F90 8005EB90 8CC30000 */  lw        $v1, ($a2)
/* 39F94 8005EB94 1060000E */  beqz      $v1, .L8005EBD0
/* 39F98 8005EB98 0040202D */   daddu    $a0, $v0, $zero
.L8005EB9C:
/* 39F9C 8005EB9C 54700009 */  bnel      $v1, $s0, .L8005EBC4
/* 39FA0 8005EBA0 0060282D */   daddu    $a1, $v1, $zero
/* 39FA4 8005EBA4 10A00004 */  beqz      $a1, .L8005EBB8
/* 39FA8 8005EBA8 00000000 */   nop
/* 39FAC 8005EBAC 8C620000 */  lw        $v0, ($v1)
/* 39FB0 8005EBB0 08017AF4 */  j         .L8005EBD0
/* 39FB4 8005EBB4 ACA20000 */   sw       $v0, ($a1)
.L8005EBB8:
/* 39FB8 8005EBB8 8C620000 */  lw        $v0, ($v1)
/* 39FBC 8005EBBC 08017AF4 */  j         .L8005EBD0
/* 39FC0 8005EBC0 ACC20000 */   sw       $v0, ($a2)
.L8005EBC4:
/* 39FC4 8005EBC4 8C630000 */  lw        $v1, ($v1)
/* 39FC8 8005EBC8 1460FFF4 */  bnez      $v1, .L8005EB9C
/* 39FCC 8005EBCC 00000000 */   nop
.L8005EBD0:
/* 39FD0 8005EBD0 0C018244 */  jal       func_80060910
/* 39FD4 8005EBD4 00000000 */   nop
/* 39FD8 8005EBD8 8FBF0014 */  lw        $ra, 0x14($sp)
/* 39FDC 8005EBDC 8FB00010 */  lw        $s0, 0x10($sp)
/* 39FE0 8005EBE0 03E00008 */  jr        $ra
/* 39FE4 8005EBE4 27BD0018 */   addiu    $sp, $sp, 0x18
