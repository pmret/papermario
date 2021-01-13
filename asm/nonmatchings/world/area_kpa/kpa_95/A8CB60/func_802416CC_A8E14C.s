.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802416CC_A8E14C
/* A8E14C 802416CC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A8E150 802416D0 AFB10014 */  sw        $s1, 0x14($sp)
/* A8E154 802416D4 0080882D */  daddu     $s1, $a0, $zero
/* A8E158 802416D8 AFBF0018 */  sw        $ra, 0x18($sp)
/* A8E15C 802416DC AFB00010 */  sw        $s0, 0x10($sp)
/* A8E160 802416E0 8E30000C */  lw        $s0, 0xc($s1)
/* A8E164 802416E4 8E050000 */  lw        $a1, ($s0)
/* A8E168 802416E8 0C0B1EAF */  jal       get_variable
/* A8E16C 802416EC 26100004 */   addiu    $s0, $s0, 4
/* A8E170 802416F0 0220202D */  daddu     $a0, $s1, $zero
/* A8E174 802416F4 8E050000 */  lw        $a1, ($s0)
/* A8E178 802416F8 0C0B1EAF */  jal       get_variable
/* A8E17C 802416FC 0040802D */   daddu    $s0, $v0, $zero
/* A8E180 80241700 44820000 */  mtc1      $v0, $f0
/* A8E184 80241704 00000000 */  nop
/* A8E188 80241708 46800020 */  cvt.s.w   $f0, $f0
/* A8E18C 8024170C 24020002 */  addiu     $v0, $zero, 2
/* A8E190 80241710 00501804 */  sllv      $v1, $s0, $v0
/* A8E194 80241714 00701821 */  addu      $v1, $v1, $s0
/* A8E198 80241718 00431804 */  sllv      $v1, $v1, $v0
/* A8E19C 8024171C 00701823 */  subu      $v1, $v1, $s0
/* A8E1A0 80241720 000320C0 */  sll       $a0, $v1, 3
/* A8E1A4 80241724 00641821 */  addu      $v1, $v1, $a0
/* A8E1A8 80241728 000318C0 */  sll       $v1, $v1, 3
/* A8E1AC 8024172C 3C01800B */  lui       $at, %hi(D_800B1D98)
/* A8E1B0 80241730 00230821 */  addu      $at, $at, $v1
/* A8E1B4 80241734 E4201D98 */  swc1      $f0, %lo(D_800B1D98)($at)
/* A8E1B8 80241738 8FBF0018 */  lw        $ra, 0x18($sp)
/* A8E1BC 8024173C 8FB10014 */  lw        $s1, 0x14($sp)
/* A8E1C0 80241740 8FB00010 */  lw        $s0, 0x10($sp)
/* A8E1C4 80241744 03E00008 */  jr        $ra
/* A8E1C8 80241748 27BD0020 */   addiu    $sp, $sp, 0x20
