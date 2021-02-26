.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80045984
/* 20D84 80045984 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 20D88 80045988 AFB00010 */  sw        $s0, 0x10($sp)
/* 20D8C 8004598C 0080802D */  daddu     $s0, $a0, $zero
/* 20D90 80045990 AFBF0014 */  sw        $ra, 0x14($sp)
/* 20D94 80045994 8E040018 */  lw        $a0, 0x18($s0)
/* 20D98 80045998 50800005 */  beql      $a0, $zero, .L800459B0
/* 20D9C 8004599C A6000010 */   sh       $zero, 0x10($s0)
/* 20DA0 800459A0 0C00AB3B */  jal       func_8002ACEC
/* 20DA4 800459A4 00000000 */   nop
/* 20DA8 800459A8 AE000018 */  sw        $zero, 0x18($s0)
/* 20DAC 800459AC A6000010 */  sh        $zero, 0x10($s0)
.L800459B0:
/* 20DB0 800459B0 8FBF0014 */  lw        $ra, 0x14($sp)
/* 20DB4 800459B4 8FB00010 */  lw        $s0, 0x10($sp)
/* 20DB8 800459B8 03E00008 */  jr        $ra
/* 20DBC 800459BC 27BD0018 */   addiu    $sp, $sp, 0x18
