.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024195C_C7863C
/* C7863C 8024195C 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* C78640 80241960 AFB3003C */  sw        $s3, 0x3c($sp)
/* C78644 80241964 0080982D */  daddu     $s3, $a0, $zero
/* C78648 80241968 AFBF0040 */  sw        $ra, 0x40($sp)
/* C7864C 8024196C AFB20038 */  sw        $s2, 0x38($sp)
/* C78650 80241970 AFB10034 */  sw        $s1, 0x34($sp)
/* C78654 80241974 AFB00030 */  sw        $s0, 0x30($sp)
/* C78658 80241978 8E720148 */  lw        $s2, 0x148($s3)
/* C7865C 8024197C 00A0882D */  daddu     $s1, $a1, $zero
/* C78660 80241980 86440008 */  lh        $a0, 8($s2)
/* C78664 80241984 0C00EABB */  jal       get_npc_unsafe
/* C78668 80241988 00C0802D */   daddu    $s0, $a2, $zero
/* C7866C 8024198C 0200202D */  daddu     $a0, $s0, $zero
/* C78670 80241990 0240282D */  daddu     $a1, $s2, $zero
/* C78674 80241994 AFA00010 */  sw        $zero, 0x10($sp)
/* C78678 80241998 8E26000C */  lw        $a2, 0xc($s1)
/* C7867C 8024199C 8E270010 */  lw        $a3, 0x10($s1)
/* C78680 802419A0 0C01242D */  jal       func_800490B4
/* C78684 802419A4 0040882D */   daddu    $s1, $v0, $zero
/* C78688 802419A8 10400024 */  beqz      $v0, .L80241A3C
/* C7868C 802419AC 0220202D */   daddu    $a0, $s1, $zero
/* C78690 802419B0 24050322 */  addiu     $a1, $zero, 0x322
/* C78694 802419B4 0C012530 */  jal       ai_enemy_play_sound
/* C78698 802419B8 0000302D */   daddu    $a2, $zero, $zero
/* C7869C 802419BC 0000202D */  daddu     $a0, $zero, $zero
/* C786A0 802419C0 0220282D */  daddu     $a1, $s1, $zero
/* C786A4 802419C4 0000302D */  daddu     $a2, $zero, $zero
/* C786A8 802419C8 2410000A */  addiu     $s0, $zero, 0xa
/* C786AC 802419CC 862300A8 */  lh        $v1, 0xa8($s1)
/* C786B0 802419D0 3C013F80 */  lui       $at, 0x3f80
/* C786B4 802419D4 44810000 */  mtc1      $at, $f0
/* C786B8 802419D8 3C014000 */  lui       $at, 0x4000
/* C786BC 802419DC 44811000 */  mtc1      $at, $f2
/* C786C0 802419E0 3C01C1A0 */  lui       $at, 0xc1a0
/* C786C4 802419E4 44812000 */  mtc1      $at, $f4
/* C786C8 802419E8 44833000 */  mtc1      $v1, $f6
/* C786CC 802419EC 00000000 */  nop
/* C786D0 802419F0 468031A0 */  cvt.s.w   $f6, $f6
/* C786D4 802419F4 44073000 */  mfc1      $a3, $f6
/* C786D8 802419F8 27A20028 */  addiu     $v0, $sp, 0x28
/* C786DC 802419FC AFB0001C */  sw        $s0, 0x1c($sp)
/* C786E0 80241A00 AFA20020 */  sw        $v0, 0x20($sp)
/* C786E4 80241A04 E7A00010 */  swc1      $f0, 0x10($sp)
/* C786E8 80241A08 E7A20014 */  swc1      $f2, 0x14($sp)
/* C786EC 80241A0C 0C01BFA4 */  jal       fx_emote
/* C786F0 80241A10 E7A40018 */   swc1     $f4, 0x18($sp)
/* C786F4 80241A14 0220202D */  daddu     $a0, $s1, $zero
/* C786F8 80241A18 240502F4 */  addiu     $a1, $zero, 0x2f4
/* C786FC 80241A1C 0C012530 */  jal       ai_enemy_play_sound
/* C78700 80241A20 3C060020 */   lui      $a2, 0x20
/* C78704 80241A24 8E4200CC */  lw        $v0, 0xcc($s2)
/* C78708 80241A28 8C420020 */  lw        $v0, 0x20($v0)
/* C7870C 80241A2C AE220028 */  sw        $v0, 0x28($s1)
/* C78710 80241A30 9642008E */  lhu       $v0, 0x8e($s2)
/* C78714 80241A34 A622008E */  sh        $v0, 0x8e($s1)
/* C78718 80241A38 AE700070 */  sw        $s0, 0x70($s3)
.L80241A3C:
/* C7871C 80241A3C 8FBF0040 */  lw        $ra, 0x40($sp)
/* C78720 80241A40 8FB3003C */  lw        $s3, 0x3c($sp)
/* C78724 80241A44 8FB20038 */  lw        $s2, 0x38($sp)
/* C78728 80241A48 8FB10034 */  lw        $s1, 0x34($sp)
/* C7872C 80241A4C 8FB00030 */  lw        $s0, 0x30($sp)
/* C78730 80241A50 03E00008 */  jr        $ra
/* C78734 80241A54 27BD0048 */   addiu    $sp, $sp, 0x48
