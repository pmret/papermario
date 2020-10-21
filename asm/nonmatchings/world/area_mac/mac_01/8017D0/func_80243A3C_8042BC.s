.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243A3C_8042BC
/* 8042BC 80243A3C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8042C0 80243A40 AFBF0010 */  sw        $ra, 0x10($sp)
/* 8042C4 80243A44 8C82000C */  lw        $v0, 0xc($a0)
/* 8042C8 80243A48 3C068011 */  lui       $a2, 0x8011
/* 8042CC 80243A4C 80C6F2A2 */  lb        $a2, -0xd5e($a2)
/* 8042D0 80243A50 0C0B2026 */  jal       set_variable
/* 8042D4 80243A54 8C450000 */   lw       $a1, ($v0)
/* 8042D8 80243A58 0C03AC5A */  jal       func_800EB168
/* 8042DC 80243A5C 0000202D */   daddu    $a0, $zero, $zero
/* 8042E0 80243A60 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8042E4 80243A64 24020002 */  addiu     $v0, $zero, 2
/* 8042E8 80243A68 03E00008 */  jr        $ra
/* 8042EC 80243A6C 27BD0018 */   addiu    $sp, $sp, 0x18
