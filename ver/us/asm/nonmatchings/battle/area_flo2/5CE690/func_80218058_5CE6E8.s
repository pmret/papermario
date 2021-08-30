.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218058_5CE6E8
/* 5CE6E8 80218058 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 5CE6EC 8021805C AFB20018 */  sw        $s2, 0x18($sp)
/* 5CE6F0 80218060 0080902D */  daddu     $s2, $a0, $zero
/* 5CE6F4 80218064 AFBF001C */  sw        $ra, 0x1c($sp)
/* 5CE6F8 80218068 AFB10014 */  sw        $s1, 0x14($sp)
/* 5CE6FC 8021806C AFB00010 */  sw        $s0, 0x10($sp)
/* 5CE700 80218070 8E50000C */  lw        $s0, 0xc($s2)
/* 5CE704 80218074 0C09A75B */  jal       get_actor
/* 5CE708 80218078 24040200 */   addiu    $a0, $zero, 0x200
/* 5CE70C 8021807C 0240202D */  daddu     $a0, $s2, $zero
/* 5CE710 80218080 8E050000 */  lw        $a1, ($s0)
/* 5CE714 80218084 0C0B1EAF */  jal       evt_get_variable
/* 5CE718 80218088 0040882D */   daddu    $s1, $v0, $zero
/* 5CE71C 8021808C C6200138 */  lwc1      $f0, 0x138($s1)
/* 5CE720 80218090 44821000 */  mtc1      $v0, $f2
/* 5CE724 80218094 00000000 */  nop
/* 5CE728 80218098 468010A0 */  cvt.s.w   $f2, $f2
/* 5CE72C 8021809C 46020000 */  add.s     $f0, $f0, $f2
/* 5CE730 802180A0 26100004 */  addiu     $s0, $s0, 4
/* 5CE734 802180A4 4600018D */  trunc.w.s $f6, $f0
/* 5CE738 802180A8 44023000 */  mfc1      $v0, $f6
/* 5CE73C 802180AC 00000000 */  nop
/* 5CE740 802180B0 A6220156 */  sh        $v0, 0x156($s1)
/* 5CE744 802180B4 8E050000 */  lw        $a1, ($s0)
/* 5CE748 802180B8 0C0B1EAF */  jal       evt_get_variable
/* 5CE74C 802180BC 0240202D */   daddu    $a0, $s2, $zero
/* 5CE750 802180C0 44822000 */  mtc1      $v0, $f4
/* 5CE754 802180C4 00000000 */  nop
/* 5CE758 802180C8 46802120 */  cvt.s.w   $f4, $f4
/* 5CE75C 802180CC C620013C */  lwc1      $f0, 0x13c($s1)
/* 5CE760 802180D0 C6220140 */  lwc1      $f2, 0x140($s1)
/* 5CE764 802180D4 46040000 */  add.s     $f0, $f0, $f4
/* 5CE768 802180D8 4600118D */  trunc.w.s $f6, $f2
/* 5CE76C 802180DC 44033000 */  mfc1      $v1, $f6
/* 5CE770 802180E0 00000000 */  nop
/* 5CE774 802180E4 A623015A */  sh        $v1, 0x15a($s1)
/* 5CE778 802180E8 4600018D */  trunc.w.s $f6, $f0
/* 5CE77C 802180EC 44033000 */  mfc1      $v1, $f6
/* 5CE780 802180F0 00000000 */  nop
/* 5CE784 802180F4 A6230158 */  sh        $v1, 0x158($s1)
/* 5CE788 802180F8 8FBF001C */  lw        $ra, 0x1c($sp)
/* 5CE78C 802180FC 8FB20018 */  lw        $s2, 0x18($sp)
/* 5CE790 80218100 8FB10014 */  lw        $s1, 0x14($sp)
/* 5CE794 80218104 8FB00010 */  lw        $s0, 0x10($sp)
/* 5CE798 80218108 24020002 */  addiu     $v0, $zero, 2
/* 5CE79C 8021810C 03E00008 */  jr        $ra
/* 5CE7A0 80218110 27BD0020 */   addiu    $sp, $sp, 0x20
