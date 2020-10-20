.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240720_9AEE20
/* 9AEE20 80240720 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 9AEE24 80240724 AFBF0018 */  sw        $ra, 0x18($sp)
/* 9AEE28 80240728 C4800084 */  lwc1      $f0, 0x84($a0)
/* 9AEE2C 8024072C 46800020 */  cvt.s.w   $f0, $f0
/* 9AEE30 80240730 C4820088 */  lwc1      $f2, 0x88($a0)
/* 9AEE34 80240734 468010A0 */  cvt.s.w   $f2, $f2
/* 9AEE38 80240738 C484008C */  lwc1      $f4, 0x8c($a0)
/* 9AEE3C 8024073C 46802120 */  cvt.s.w   $f4, $f4
/* 9AEE40 80240740 44050000 */  mfc1      $a1, $f0
/* 9AEE44 80240744 44061000 */  mfc1      $a2, $f2
/* 9AEE48 80240748 44072000 */  mfc1      $a3, $f4
/* 9AEE4C 8024074C 24040002 */  addiu     $a0, $zero, 2
/* 9AEE50 80240750 AFA00010 */  sw        $zero, 0x10($sp)
/* 9AEE54 80240754 0C01BECC */  jal       fx_walk_normal
/* 9AEE58 80240758 AFA00014 */   sw       $zero, 0x14($sp)
/* 9AEE5C 8024075C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 9AEE60 80240760 24020002 */  addiu     $v0, $zero, 2
/* 9AEE64 80240764 03E00008 */  jr        $ra
/* 9AEE68 80240768 27BD0020 */   addiu    $sp, $sp, 0x20
/* 9AEE6C 8024076C 00000000 */  nop       
