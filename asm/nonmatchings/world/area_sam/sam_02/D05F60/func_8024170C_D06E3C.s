.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024170C_D06E3C
/* D06E3C 8024170C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D06E40 80241710 AFB10014 */  sw        $s1, 0x14($sp)
/* D06E44 80241714 0080882D */  daddu     $s1, $a0, $zero
/* D06E48 80241718 AFBF0018 */  sw        $ra, 0x18($sp)
/* D06E4C 8024171C AFB00010 */  sw        $s0, 0x10($sp)
/* D06E50 80241720 8E30000C */  lw        $s0, 0xc($s1)
/* D06E54 80241724 8E050000 */  lw        $a1, ($s0)
/* D06E58 80241728 0C0B1EAF */  jal       get_variable
/* D06E5C 8024172C 26100004 */   addiu    $s0, $s0, 4
/* D06E60 80241730 00021880 */  sll       $v1, $v0, 2
/* D06E64 80241734 00621821 */  addu      $v1, $v1, $v0
/* D06E68 80241738 00031880 */  sll       $v1, $v1, 2
/* D06E6C 8024173C 00621823 */  subu      $v1, $v1, $v0
/* D06E70 80241740 000310C0 */  sll       $v0, $v1, 3
/* D06E74 80241744 00621821 */  addu      $v1, $v1, $v0
/* D06E78 80241748 000318C0 */  sll       $v1, $v1, 3
/* D06E7C 8024174C 3C01800B */  lui       $at, 0x800b
/* D06E80 80241750 00230821 */  addu      $at, $at, $v1
/* D06E84 80241754 C4221D98 */  lwc1      $f2, 0x1d98($at)
/* D06E88 80241758 3C014480 */  lui       $at, 0x4480
/* D06E8C 8024175C 44810000 */  mtc1      $at, $f0
/* D06E90 80241760 00000000 */  nop       
/* D06E94 80241764 46001082 */  mul.s     $f2, $f2, $f0
/* D06E98 80241768 00000000 */  nop       
/* D06E9C 8024176C 3C01CD5B */  lui       $at, 0xcd5b
/* D06EA0 80241770 34215858 */  ori       $at, $at, 0x5858
/* D06EA4 80241774 44810000 */  mtc1      $at, $f0
/* D06EA8 80241778 00000000 */  nop       
/* D06EAC 8024177C 46001080 */  add.s     $f2, $f2, $f0
/* D06EB0 80241780 8E050000 */  lw        $a1, ($s0)
/* D06EB4 80241784 4600110D */  trunc.w.s $f4, $f2
/* D06EB8 80241788 44062000 */  mfc1      $a2, $f4
/* D06EBC 8024178C 0C0B2026 */  jal       set_variable
/* D06EC0 80241790 0220202D */   daddu    $a0, $s1, $zero
/* D06EC4 80241794 8FBF0018 */  lw        $ra, 0x18($sp)
/* D06EC8 80241798 8FB10014 */  lw        $s1, 0x14($sp)
/* D06ECC 8024179C 8FB00010 */  lw        $s0, 0x10($sp)
/* D06ED0 802417A0 24020002 */  addiu     $v0, $zero, 2
/* D06ED4 802417A4 03E00008 */  jr        $ra
/* D06ED8 802417A8 27BD0020 */   addiu    $sp, $sp, 0x20
