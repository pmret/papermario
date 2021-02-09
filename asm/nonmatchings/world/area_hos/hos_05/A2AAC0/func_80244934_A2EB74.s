.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80244934_A2EB74
/* A2EB74 80244934 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A2EB78 80244938 AFBF0010 */  sw        $ra, 0x10($sp)
/* A2EB7C 8024493C 10A00005 */  beqz      $a1, .L80244954
/* A2EB80 80244940 0080182D */   daddu    $v1, $a0, $zero
/* A2EB84 80244944 3C05437F */  lui       $a1, 0x437f
/* A2EB88 80244948 24040001 */  addiu     $a0, $zero, 1
/* A2EB8C 8024494C 08091264 */  j         .L80244990
/* A2EB90 80244950 AC600070 */   sw       $zero, 0x70($v1)
.L80244954:
/* A2EB94 80244954 8C620070 */  lw        $v0, 0x70($v1)
/* A2EB98 80244958 24420001 */  addiu     $v0, $v0, 1
/* A2EB9C 8024495C AC620070 */  sw        $v0, 0x70($v1)
/* A2EBA0 80244960 2403000A */  addiu     $v1, $zero, 0xa
/* A2EBA4 80244964 10430013 */  beq       $v0, $v1, .L802449B4
/* A2EBA8 80244968 24040001 */   addiu    $a0, $zero, 1
/* A2EBAC 8024496C 00621823 */  subu      $v1, $v1, $v0
/* A2EBB0 80244970 00831004 */  sllv      $v0, $v1, $a0
/* A2EBB4 80244974 00431021 */  addu      $v0, $v0, $v1
/* A2EBB8 80244978 000210C0 */  sll       $v0, $v0, 3
/* A2EBBC 8024497C 00431021 */  addu      $v0, $v0, $v1
/* A2EBC0 80244980 44820000 */  mtc1      $v0, $f0
/* A2EBC4 80244984 00000000 */  nop
/* A2EBC8 80244988 46800020 */  cvt.s.w   $f0, $f0
/* A2EBCC 8024498C 44050000 */  mfc1      $a1, $f0
.L80244990:
/* A2EBD0 80244990 0C04DF69 */  jal       set_transition_stencil_zoom_1
/* A2EBD4 80244994 00000000 */   nop
/* A2EBD8 80244998 24040001 */  addiu     $a0, $zero, 1
/* A2EBDC 8024499C 240500FA */  addiu     $a1, $zero, 0xfa
/* A2EBE0 802449A0 00A0302D */  daddu     $a2, $a1, $zero
/* A2EBE4 802449A4 0C04DF84 */  jal       set_transition_stencil_color
/* A2EBE8 802449A8 00A0382D */   daddu    $a3, $a1, $zero
/* A2EBEC 802449AC 08091276 */  j         .L802449D8
/* A2EBF0 802449B0 0000102D */   daddu    $v0, $zero, $zero
.L802449B4:
/* A2EBF4 802449B4 0000202D */  daddu     $a0, $zero, $zero
/* A2EBF8 802449B8 0C04DF69 */  jal       set_transition_stencil_zoom_1
/* A2EBFC 802449BC 0000282D */   daddu    $a1, $zero, $zero
/* A2EC00 802449C0 24040001 */  addiu     $a0, $zero, 1
/* A2EC04 802449C4 240500FA */  addiu     $a1, $zero, 0xfa
/* A2EC08 802449C8 00A0302D */  daddu     $a2, $a1, $zero
/* A2EC0C 802449CC 0C04DF84 */  jal       set_transition_stencil_color
/* A2EC10 802449D0 00A0382D */   daddu    $a3, $a1, $zero
/* A2EC14 802449D4 24020002 */  addiu     $v0, $zero, 2
.L802449D8:
/* A2EC18 802449D8 8FBF0010 */  lw        $ra, 0x10($sp)
/* A2EC1C 802449DC 03E00008 */  jr        $ra
/* A2EC20 802449E0 27BD0018 */   addiu    $sp, $sp, 0x18
/* A2EC24 802449E4 00000000 */  nop
/* A2EC28 802449E8 00000000 */  nop
/* A2EC2C 802449EC 00000000 */  nop
