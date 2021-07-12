.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241E8C_A046CC
/* A046CC 80241E8C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* A046D0 80241E90 AFB3001C */  sw        $s3, 0x1c($sp)
/* A046D4 80241E94 0080982D */  daddu     $s3, $a0, $zero
/* A046D8 80241E98 AFBF0020 */  sw        $ra, 0x20($sp)
/* A046DC 80241E9C AFB20018 */  sw        $s2, 0x18($sp)
/* A046E0 80241EA0 AFB10014 */  sw        $s1, 0x14($sp)
/* A046E4 80241EA4 AFB00010 */  sw        $s0, 0x10($sp)
/* A046E8 80241EA8 8E710148 */  lw        $s1, 0x148($s3)
/* A046EC 80241EAC 0C00EABB */  jal       get_npc_unsafe
/* A046F0 80241EB0 86240008 */   lh       $a0, 8($s1)
/* A046F4 80241EB4 0040802D */  daddu     $s0, $v0, $zero
/* A046F8 80241EB8 C60C0038 */  lwc1      $f12, 0x38($s0)
/* A046FC 80241EBC 8E2200CC */  lw        $v0, 0xcc($s1)
/* A04700 80241EC0 3C01C0A0 */  lui       $at, 0xc0a0
/* A04704 80241EC4 44811000 */  mtc1      $at, $f2
/* A04708 80241EC8 3C013E19 */  lui       $at, 0x3e19
/* A0470C 80241ECC 3421999A */  ori       $at, $at, 0x999a
/* A04710 80241ED0 44810000 */  mtc1      $at, $f0
/* A04714 80241ED4 8C420024 */  lw        $v0, 0x24($v0)
/* A04718 80241ED8 3C12800F */  lui       $s2, %hi(gPlayerStatusPtr)
/* A0471C 80241EDC 26527B30 */  addiu     $s2, $s2, %lo(gPlayerStatusPtr)
/* A04720 80241EE0 E602001C */  swc1      $f2, 0x1c($s0)
/* A04724 80241EE4 E6000014 */  swc1      $f0, 0x14($s0)
/* A04728 80241EE8 AE020028 */  sw        $v0, 0x28($s0)
/* A0472C 80241EEC 8E22008C */  lw        $v0, 0x8c($s1)
/* A04730 80241EF0 C60E0040 */  lwc1      $f14, 0x40($s0)
/* A04734 80241EF4 00021FC2 */  srl       $v1, $v0, 0x1f
/* A04738 80241EF8 00431021 */  addu      $v0, $v0, $v1
/* A0473C 80241EFC 8E430000 */  lw        $v1, ($s2)
/* A04740 80241F00 00021043 */  sra       $v0, $v0, 1
/* A04744 80241F04 A60200A8 */  sh        $v0, 0xa8($s0)
/* A04748 80241F08 8C660028 */  lw        $a2, 0x28($v1)
/* A0474C 80241F0C 0C00A7B5 */  jal       dist2D
/* A04750 80241F10 8C670030 */   lw       $a3, 0x30($v1)
/* A04754 80241F14 0200202D */  daddu     $a0, $s0, $zero
/* A04758 80241F18 0000302D */  daddu     $a2, $zero, $zero
/* A0475C 80241F1C C6020038 */  lwc1      $f2, 0x38($s0)
/* A04760 80241F20 3C0140E0 */  lui       $at, 0x40e0
/* A04764 80241F24 44810000 */  mtc1      $at, $f0
/* A04768 80241F28 4600110D */  trunc.w.s $f4, $f2
/* A0476C 80241F2C 44022000 */  mfc1      $v0, $f4
/* A04770 80241F30 E6000018 */  swc1      $f0, 0x18($s0)
/* A04774 80241F34 A6220010 */  sh        $v0, 0x10($s1)
/* A04778 80241F38 C600003C */  lwc1      $f0, 0x3c($s0)
/* A0477C 80241F3C 240502C1 */  addiu     $a1, $zero, 0x2c1
/* A04780 80241F40 4600010D */  trunc.w.s $f4, $f0
/* A04784 80241F44 44022000 */  mfc1      $v0, $f4
/* A04788 80241F48 00000000 */  nop
/* A0478C 80241F4C A6220012 */  sh        $v0, 0x12($s1)
/* A04790 80241F50 C6000040 */  lwc1      $f0, 0x40($s0)
/* A04794 80241F54 24020001 */  addiu     $v0, $zero, 1
/* A04798 80241F58 A2220007 */  sb        $v0, 7($s1)
/* A0479C 80241F5C 4600010D */  trunc.w.s $f4, $f0
/* A047A0 80241F60 44022000 */  mfc1      $v0, $f4
/* A047A4 80241F64 0C012530 */  jal       ai_enemy_play_sound
/* A047A8 80241F68 A6220014 */   sh       $v0, 0x14($s1)
/* A047AC 80241F6C C60C0038 */  lwc1      $f12, 0x38($s0)
/* A047B0 80241F70 8E420000 */  lw        $v0, ($s2)
/* A047B4 80241F74 C60E0040 */  lwc1      $f14, 0x40($s0)
/* A047B8 80241F78 8C460028 */  lw        $a2, 0x28($v0)
/* A047BC 80241F7C 0C00A720 */  jal       atan2
/* A047C0 80241F80 8C470030 */   lw       $a3, 0x30($v0)
/* A047C4 80241F84 2402000C */  addiu     $v0, $zero, 0xc
/* A047C8 80241F88 A602008E */  sh        $v0, 0x8e($s0)
/* A047CC 80241F8C 2402000D */  addiu     $v0, $zero, 0xd
/* A047D0 80241F90 E600000C */  swc1      $f0, 0xc($s0)
/* A047D4 80241F94 AE620070 */  sw        $v0, 0x70($s3)
/* A047D8 80241F98 8FBF0020 */  lw        $ra, 0x20($sp)
/* A047DC 80241F9C 8FB3001C */  lw        $s3, 0x1c($sp)
/* A047E0 80241FA0 8FB20018 */  lw        $s2, 0x18($sp)
/* A047E4 80241FA4 8FB10014 */  lw        $s1, 0x14($sp)
/* A047E8 80241FA8 8FB00010 */  lw        $s0, 0x10($sp)
/* A047EC 80241FAC 03E00008 */  jr        $ra
/* A047F0 80241FB0 27BD0028 */   addiu    $sp, $sp, 0x28
