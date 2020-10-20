.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802434CC
/* 96C68C 802434CC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 96C690 802434D0 AFB10014 */  sw        $s1, 0x14($sp)
/* 96C694 802434D4 0080882D */  daddu     $s1, $a0, $zero
/* 96C698 802434D8 AFBF0018 */  sw        $ra, 0x18($sp)
/* 96C69C 802434DC AFB00010 */  sw        $s0, 0x10($sp)
/* 96C6A0 802434E0 8E30000C */  lw        $s0, 0xc($s1)
/* 96C6A4 802434E4 8E050000 */  lw        $a1, ($s0)
/* 96C6A8 802434E8 0C0B1EAF */  jal       get_variable
/* 96C6AC 802434EC 26100004 */   addiu    $s0, $s0, 4
/* 96C6B0 802434F0 0220202D */  daddu     $a0, $s1, $zero
/* 96C6B4 802434F4 8E050000 */  lw        $a1, ($s0)
/* 96C6B8 802434F8 0C0B1EAF */  jal       get_variable
/* 96C6BC 802434FC 0040882D */   daddu    $s1, $v0, $zero
/* 96C6C0 80243500 0000202D */  daddu     $a0, $zero, $zero
/* 96C6C4 80243504 0080282D */  daddu     $a1, $a0, $zero
/* 96C6C8 80243508 0040802D */  daddu     $s0, $v0, $zero
/* 96C6CC 8024350C 240600BE */  addiu     $a2, $zero, 0xbe
/* 96C6D0 80243510 0C04DF93 */  jal       func_80137E4C
/* 96C6D4 80243514 24070091 */   addiu    $a3, $zero, 0x91
/* 96C6D8 80243518 44900000 */  mtc1      $s0, $f0
/* 96C6DC 8024351C 00000000 */  nop       
/* 96C6E0 80243520 46800020 */  cvt.s.w   $f0, $f0
/* 96C6E4 80243524 44050000 */  mfc1      $a1, $f0
/* 96C6E8 80243528 0C04DF62 */  jal       func_80137D88
/* 96C6EC 8024352C 322400FF */   andi     $a0, $s1, 0xff
/* 96C6F0 80243530 8FBF0018 */  lw        $ra, 0x18($sp)
/* 96C6F4 80243534 8FB10014 */  lw        $s1, 0x14($sp)
/* 96C6F8 80243538 8FB00010 */  lw        $s0, 0x10($sp)
/* 96C6FC 8024353C 24020002 */  addiu     $v0, $zero, 2
/* 96C700 80243540 03E00008 */  jr        $ra
/* 96C704 80243544 27BD0020 */   addiu    $sp, $sp, 0x20
