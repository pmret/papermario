.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024146C_DBE71C
/* DBE71C 8024146C 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* DBE720 80241470 AFB20028 */  sw        $s2, 0x28($sp)
/* DBE724 80241474 0080902D */  daddu     $s2, $a0, $zero
/* DBE728 80241478 AFBF002C */  sw        $ra, 0x2c($sp)
/* DBE72C 8024147C AFB10024 */  sw        $s1, 0x24($sp)
/* DBE730 80241480 AFB00020 */  sw        $s0, 0x20($sp)
/* DBE734 80241484 8E510148 */  lw        $s1, 0x148($s2)
/* DBE738 80241488 0C00EABB */  jal       get_npc_unsafe
/* DBE73C 8024148C 86240008 */   lh       $a0, 8($s1)
/* DBE740 80241490 0040802D */  daddu     $s0, $v0, $zero
/* DBE744 80241494 0200202D */  daddu     $a0, $s0, $zero
/* DBE748 80241498 C600000C */  lwc1      $f0, 0xc($s0)
/* DBE74C 8024149C 27A60018 */  addiu     $a2, $sp, 0x18
/* DBE750 802414A0 E7A00018 */  swc1      $f0, 0x18($sp)
/* DBE754 802414A4 AFA00010 */  sw        $zero, 0x10($sp)
/* DBE758 802414A8 AFA00014 */  sw        $zero, 0x14($sp)
/* DBE75C 802414AC 8E050018 */  lw        $a1, 0x18($s0)
/* DBE760 802414B0 0C0129E1 */  jal       func_8004A784
/* DBE764 802414B4 0000382D */   daddu    $a3, $zero, $zero
/* DBE768 802414B8 14400005 */  bnez      $v0, .L802414D0
/* DBE76C 802414BC 00000000 */   nop
/* DBE770 802414C0 8E050018 */  lw        $a1, 0x18($s0)
/* DBE774 802414C4 8E06000C */  lw        $a2, 0xc($s0)
/* DBE778 802414C8 0C00EA95 */  jal       npc_move_heading
/* DBE77C 802414CC 0200202D */   daddu    $a0, $s0, $zero
.L802414D0:
/* DBE780 802414D0 9602008E */  lhu       $v0, 0x8e($s0)
/* DBE784 802414D4 2442FFFF */  addiu     $v0, $v0, -1
/* DBE788 802414D8 A602008E */  sh        $v0, 0x8e($s0)
/* DBE78C 802414DC 00021400 */  sll       $v0, $v0, 0x10
/* DBE790 802414E0 14400010 */  bnez      $v0, .L80241524
/* DBE794 802414E4 00000000 */   nop
/* DBE798 802414E8 C6000018 */  lwc1      $f0, 0x18($s0)
/* DBE79C 802414EC 3C018024 */  lui       $at, %hi(D_80246F18)
/* DBE7A0 802414F0 D4226F18 */  ldc1      $f2, %lo(D_80246F18)($at)
/* DBE7A4 802414F4 46000021 */  cvt.d.s   $f0, $f0
/* DBE7A8 802414F8 46220002 */  mul.d     $f0, $f0, $f2
/* DBE7AC 802414FC 00000000 */  nop
/* DBE7B0 80241500 46200020 */  cvt.s.d   $f0, $f0
/* DBE7B4 80241504 E6000018 */  swc1      $f0, 0x18($s0)
/* DBE7B8 80241508 8E2200CC */  lw        $v0, 0xcc($s1)
/* DBE7BC 8024150C 8C43002C */  lw        $v1, 0x2c($v0)
/* DBE7C0 80241510 2402000A */  addiu     $v0, $zero, 0xa
/* DBE7C4 80241514 A602008E */  sh        $v0, 0x8e($s0)
/* DBE7C8 80241518 24020010 */  addiu     $v0, $zero, 0x10
/* DBE7CC 8024151C AE030028 */  sw        $v1, 0x28($s0)
/* DBE7D0 80241520 AE420070 */  sw        $v0, 0x70($s2)
.L80241524:
/* DBE7D4 80241524 8FBF002C */  lw        $ra, 0x2c($sp)
/* DBE7D8 80241528 8FB20028 */  lw        $s2, 0x28($sp)
/* DBE7DC 8024152C 8FB10024 */  lw        $s1, 0x24($sp)
/* DBE7E0 80241530 8FB00020 */  lw        $s0, 0x20($sp)
/* DBE7E4 80241534 03E00008 */  jr        $ra
/* DBE7E8 80241538 27BD0030 */   addiu    $sp, $sp, 0x30
