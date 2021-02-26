.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004486C
/* 1FC6C 8004486C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 1FC70 80044870 AFB10014 */  sw        $s1, 0x14($sp)
/* 1FC74 80044874 0080882D */  daddu     $s1, $a0, $zero
/* 1FC78 80044878 AFBF0020 */  sw        $ra, 0x20($sp)
/* 1FC7C 8004487C AFB3001C */  sw        $s3, 0x1c($sp)
/* 1FC80 80044880 AFB20018 */  sw        $s2, 0x18($sp)
/* 1FC84 80044884 AFB00010 */  sw        $s0, 0x10($sp)
/* 1FC88 80044888 8E30000C */  lw        $s0, 0xc($s1)
/* 1FC8C 8004488C 8E330148 */  lw        $s3, 0x148($s1)
/* 1FC90 80044890 8E050000 */  lw        $a1, ($s0)
/* 1FC94 80044894 0C0B1EAF */  jal       func_802C7ABC
/* 1FC98 80044898 26100004 */   addiu    $s0, $s0, 4
/* 1FC9C 8004489C 0040902D */  daddu     $s2, $v0, $zero
/* 1FCA0 800448A0 8E050000 */  lw        $a1, ($s0)
/* 1FCA4 800448A4 0C0B1EAF */  jal       func_802C7ABC
/* 1FCA8 800448A8 0220202D */   daddu    $a0, $s1, $zero
/* 1FCAC 800448AC 0040802D */  daddu     $s0, $v0, $zero
/* 1FCB0 800448B0 2402FFFF */  addiu     $v0, $zero, -1
/* 1FCB4 800448B4 16420002 */  bne       $s2, $v0, .L800448C0
/* 1FCB8 800448B8 00000000 */   nop
/* 1FCBC 800448BC 86720008 */  lh        $s2, 8($s3)
.L800448C0:
/* 1FCC0 800448C0 0C00FA6A */  jal       func_8003E9A8
/* 1FCC4 800448C4 0240202D */   daddu    $a0, $s2, $zero
/* 1FCC8 800448C8 AC500024 */  sw        $s0, 0x24($v0)
/* 1FCCC 800448CC 8FBF0020 */  lw        $ra, 0x20($sp)
/* 1FCD0 800448D0 8FB3001C */  lw        $s3, 0x1c($sp)
/* 1FCD4 800448D4 8FB20018 */  lw        $s2, 0x18($sp)
/* 1FCD8 800448D8 8FB10014 */  lw        $s1, 0x14($sp)
/* 1FCDC 800448DC 8FB00010 */  lw        $s0, 0x10($sp)
/* 1FCE0 800448E0 24020002 */  addiu     $v0, $zero, 2
/* 1FCE4 800448E4 03E00008 */  jr        $ra
/* 1FCE8 800448E8 27BD0028 */   addiu    $sp, $sp, 0x28
