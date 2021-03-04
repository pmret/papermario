.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800654C0
/* 408C0 800654C0 AFA50004 */  sw        $a1, 4($sp)
/* 408C4 800654C4 AFA60008 */  sw        $a2, 8($sp)
/* 408C8 800654C8 AFA7000C */  sw        $a3, 0xc($sp)
/* 408CC 800654CC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 408D0 800654D0 AFB00010 */  sw        $s0, 0x10($sp)
/* 408D4 800654D4 00808021 */  addu      $s0, $a0, $zero
/* 408D8 800654D8 00A03021 */  addu      $a2, $a1, $zero
/* 408DC 800654DC 3C048006 */  lui       $a0, %hi(func_80065518)
/* 408E0 800654E0 24845518 */  addiu     $a0, $a0, %lo(func_80065518)
/* 408E4 800654E4 02002821 */  addu      $a1, $s0, $zero
/* 408E8 800654E8 AFBF0014 */  sw        $ra, 0x14($sp)
/* 408EC 800654EC 0C01929C */  jal       _Printf
/* 408F0 800654F0 27A70020 */   addiu    $a3, $sp, 0x20
/* 408F4 800654F4 00401821 */  addu      $v1, $v0, $zero
/* 408F8 800654F8 04600002 */  bltz      $v1, .L80065504
/* 408FC 800654FC 02031021 */   addu     $v0, $s0, $v1
/* 40900 80065500 A0400000 */  sb        $zero, ($v0)
.L80065504:
/* 40904 80065504 00601021 */  addu      $v0, $v1, $zero
/* 40908 80065508 8FBF0014 */  lw        $ra, 0x14($sp)
/* 4090C 8006550C 8FB00010 */  lw        $s0, 0x10($sp)
/* 40910 80065510 03E00008 */  jr        $ra
/* 40914 80065514 27BD0018 */   addiu    $sp, $sp, 0x18
