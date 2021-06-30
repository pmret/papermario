.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240C4C_C866FC
/* C866FC 80240C4C 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* C86700 80240C50 AFB3003C */  sw        $s3, 0x3c($sp)
/* C86704 80240C54 0080982D */  daddu     $s3, $a0, $zero
/* C86708 80240C58 AFBF0040 */  sw        $ra, 0x40($sp)
/* C8670C 80240C5C AFB20038 */  sw        $s2, 0x38($sp)
/* C86710 80240C60 AFB10034 */  sw        $s1, 0x34($sp)
/* C86714 80240C64 AFB00030 */  sw        $s0, 0x30($sp)
/* C86718 80240C68 8E720148 */  lw        $s2, 0x148($s3)
/* C8671C 80240C6C 00A0882D */  daddu     $s1, $a1, $zero
/* C86720 80240C70 86440008 */  lh        $a0, 8($s2)
/* C86724 80240C74 0C00EABB */  jal       get_npc_unsafe
/* C86728 80240C78 00C0802D */   daddu    $s0, $a2, $zero
/* C8672C 80240C7C 0200202D */  daddu     $a0, $s0, $zero
/* C86730 80240C80 0240282D */  daddu     $a1, $s2, $zero
/* C86734 80240C84 AFA00010 */  sw        $zero, 0x10($sp)
/* C86738 80240C88 8E26000C */  lw        $a2, 0xc($s1)
/* C8673C 80240C8C 8E270010 */  lw        $a3, 0x10($s1)
/* C86740 80240C90 0C01242D */  jal       func_800490B4
/* C86744 80240C94 0040882D */   daddu    $s1, $v0, $zero
/* C86748 80240C98 10400024 */  beqz      $v0, .L80240D2C
/* C8674C 80240C9C 0220202D */   daddu    $a0, $s1, $zero
/* C86750 80240CA0 24050322 */  addiu     $a1, $zero, 0x322
/* C86754 80240CA4 0C012530 */  jal       ai_enemy_play_sound
/* C86758 80240CA8 0000302D */   daddu    $a2, $zero, $zero
/* C8675C 80240CAC 0000202D */  daddu     $a0, $zero, $zero
/* C86760 80240CB0 0220282D */  daddu     $a1, $s1, $zero
/* C86764 80240CB4 0000302D */  daddu     $a2, $zero, $zero
/* C86768 80240CB8 2410000A */  addiu     $s0, $zero, 0xa
/* C8676C 80240CBC 862300A8 */  lh        $v1, 0xa8($s1)
/* C86770 80240CC0 3C013F80 */  lui       $at, 0x3f80
/* C86774 80240CC4 44810000 */  mtc1      $at, $f0
/* C86778 80240CC8 3C014000 */  lui       $at, 0x4000
/* C8677C 80240CCC 44811000 */  mtc1      $at, $f2
/* C86780 80240CD0 3C01C1A0 */  lui       $at, 0xc1a0
/* C86784 80240CD4 44812000 */  mtc1      $at, $f4
/* C86788 80240CD8 44833000 */  mtc1      $v1, $f6
/* C8678C 80240CDC 00000000 */  nop
/* C86790 80240CE0 468031A0 */  cvt.s.w   $f6, $f6
/* C86794 80240CE4 44073000 */  mfc1      $a3, $f6
/* C86798 80240CE8 27A20028 */  addiu     $v0, $sp, 0x28
/* C8679C 80240CEC AFB0001C */  sw        $s0, 0x1c($sp)
/* C867A0 80240CF0 AFA20020 */  sw        $v0, 0x20($sp)
/* C867A4 80240CF4 E7A00010 */  swc1      $f0, 0x10($sp)
/* C867A8 80240CF8 E7A20014 */  swc1      $f2, 0x14($sp)
/* C867AC 80240CFC 0C01BFA4 */  jal       fx_emote
/* C867B0 80240D00 E7A40018 */   swc1     $f4, 0x18($sp)
/* C867B4 80240D04 0220202D */  daddu     $a0, $s1, $zero
/* C867B8 80240D08 240502F4 */  addiu     $a1, $zero, 0x2f4
/* C867BC 80240D0C 0C012530 */  jal       ai_enemy_play_sound
/* C867C0 80240D10 3C060020 */   lui      $a2, 0x20
/* C867C4 80240D14 8E4200CC */  lw        $v0, 0xcc($s2)
/* C867C8 80240D18 8C420020 */  lw        $v0, 0x20($v0)
/* C867CC 80240D1C AE220028 */  sw        $v0, 0x28($s1)
/* C867D0 80240D20 9642008E */  lhu       $v0, 0x8e($s2)
/* C867D4 80240D24 A622008E */  sh        $v0, 0x8e($s1)
/* C867D8 80240D28 AE700070 */  sw        $s0, 0x70($s3)
.L80240D2C:
/* C867DC 80240D2C 8FBF0040 */  lw        $ra, 0x40($sp)
/* C867E0 80240D30 8FB3003C */  lw        $s3, 0x3c($sp)
/* C867E4 80240D34 8FB20038 */  lw        $s2, 0x38($sp)
/* C867E8 80240D38 8FB10034 */  lw        $s1, 0x34($sp)
/* C867EC 80240D3C 8FB00030 */  lw        $s0, 0x30($sp)
/* C867F0 80240D40 03E00008 */  jr        $ra
/* C867F4 80240D44 27BD0048 */   addiu    $sp, $sp, 0x48
