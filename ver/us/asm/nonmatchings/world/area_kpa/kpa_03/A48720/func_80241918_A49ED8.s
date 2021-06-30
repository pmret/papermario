.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241918_A49ED8
/* A49ED8 80241918 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* A49EDC 8024191C AFB3003C */  sw        $s3, 0x3c($sp)
/* A49EE0 80241920 0080982D */  daddu     $s3, $a0, $zero
/* A49EE4 80241924 AFBF0044 */  sw        $ra, 0x44($sp)
/* A49EE8 80241928 AFB40040 */  sw        $s4, 0x40($sp)
/* A49EEC 8024192C AFB20038 */  sw        $s2, 0x38($sp)
/* A49EF0 80241930 AFB10034 */  sw        $s1, 0x34($sp)
/* A49EF4 80241934 AFB00030 */  sw        $s0, 0x30($sp)
/* A49EF8 80241938 8E720148 */  lw        $s2, 0x148($s3)
/* A49EFC 8024193C 00A0882D */  daddu     $s1, $a1, $zero
/* A49F00 80241940 86440008 */  lh        $a0, 8($s2)
/* A49F04 80241944 0C00EABB */  jal       get_npc_unsafe
/* A49F08 80241948 00C0A02D */   daddu    $s4, $a2, $zero
/* A49F0C 8024194C 0040802D */  daddu     $s0, $v0, $zero
/* A49F10 80241950 9602008E */  lhu       $v0, 0x8e($s0)
/* A49F14 80241954 2442FFFF */  addiu     $v0, $v0, -1
/* A49F18 80241958 A602008E */  sh        $v0, 0x8e($s0)
/* A49F1C 8024195C 00021400 */  sll       $v0, $v0, 0x10
/* A49F20 80241960 1C400032 */  bgtz      $v0, .L80241A2C
/* A49F24 80241964 00000000 */   nop
/* A49F28 80241968 0260202D */  daddu     $a0, $s3, $zero
/* A49F2C 8024196C 8E250024 */  lw        $a1, 0x24($s1)
/* A49F30 80241970 8E260028 */  lw        $a2, 0x28($s1)
/* A49F34 80241974 0C090292 */  jal       func_80240A48_A49008
/* A49F38 80241978 0280382D */   daddu    $a3, $s4, $zero
/* A49F3C 8024197C 0040882D */  daddu     $s1, $v0, $zero
/* A49F40 80241980 24020001 */  addiu     $v0, $zero, 1
/* A49F44 80241984 1222001D */  beq       $s1, $v0, .L802419FC
/* A49F48 80241988 0200282D */   daddu    $a1, $s0, $zero
/* A49F4C 8024198C 24040002 */  addiu     $a0, $zero, 2
/* A49F50 80241990 0000302D */  daddu     $a2, $zero, $zero
/* A49F54 80241994 860300A8 */  lh        $v1, 0xa8($s0)
/* A49F58 80241998 3C013F80 */  lui       $at, 0x3f80
/* A49F5C 8024199C 44810000 */  mtc1      $at, $f0
/* A49F60 802419A0 3C014000 */  lui       $at, 0x4000
/* A49F64 802419A4 44811000 */  mtc1      $at, $f2
/* A49F68 802419A8 3C01C1A0 */  lui       $at, 0xc1a0
/* A49F6C 802419AC 44812000 */  mtc1      $at, $f4
/* A49F70 802419B0 2402000C */  addiu     $v0, $zero, 0xc
/* A49F74 802419B4 AFA2001C */  sw        $v0, 0x1c($sp)
/* A49F78 802419B8 44833000 */  mtc1      $v1, $f6
/* A49F7C 802419BC 00000000 */  nop
/* A49F80 802419C0 468031A0 */  cvt.s.w   $f6, $f6
/* A49F84 802419C4 44073000 */  mfc1      $a3, $f6
/* A49F88 802419C8 27A20028 */  addiu     $v0, $sp, 0x28
/* A49F8C 802419CC AFA20020 */  sw        $v0, 0x20($sp)
/* A49F90 802419D0 E7A00010 */  swc1      $f0, 0x10($sp)
/* A49F94 802419D4 E7A20014 */  swc1      $f2, 0x14($sp)
/* A49F98 802419D8 0C01BFA4 */  jal       fx_emote
/* A49F9C 802419DC E7A40018 */   swc1     $f4, 0x18($sp)
/* A49FA0 802419E0 8E4200CC */  lw        $v0, 0xcc($s2)
/* A49FA4 802419E4 8C430000 */  lw        $v1, ($v0)
/* A49FA8 802419E8 2402000F */  addiu     $v0, $zero, 0xf
/* A49FAC 802419EC A602008E */  sh        $v0, 0x8e($s0)
/* A49FB0 802419F0 AE030028 */  sw        $v1, 0x28($s0)
/* A49FB4 802419F4 0809068B */  j         .L80241A2C
/* A49FB8 802419F8 AE600070 */   sw       $zero, 0x70($s3)
.L802419FC:
/* A49FBC 802419FC 0200202D */  daddu     $a0, $s0, $zero
/* A49FC0 80241A00 240520D5 */  addiu     $a1, $zero, 0x20d5
/* A49FC4 80241A04 0C012530 */  jal       ai_enemy_play_sound
/* A49FC8 80241A08 0000302D */   daddu    $a2, $zero, $zero
/* A49FCC 80241A0C 86440008 */  lh        $a0, 8($s2)
/* A49FD0 80241A10 0C00FB3A */  jal       get_enemy
/* A49FD4 80241A14 24840001 */   addiu    $a0, $a0, 1
/* A49FD8 80241A18 AC51006C */  sw        $s1, 0x6c($v0)
/* A49FDC 80241A1C 24020014 */  addiu     $v0, $zero, 0x14
/* A49FE0 80241A20 A602008E */  sh        $v0, 0x8e($s0)
/* A49FE4 80241A24 24020018 */  addiu     $v0, $zero, 0x18
/* A49FE8 80241A28 AE620070 */  sw        $v0, 0x70($s3)
.L80241A2C:
/* A49FEC 80241A2C 8FBF0044 */  lw        $ra, 0x44($sp)
/* A49FF0 80241A30 8FB40040 */  lw        $s4, 0x40($sp)
/* A49FF4 80241A34 8FB3003C */  lw        $s3, 0x3c($sp)
/* A49FF8 80241A38 8FB20038 */  lw        $s2, 0x38($sp)
/* A49FFC 80241A3C 8FB10034 */  lw        $s1, 0x34($sp)
/* A4A000 80241A40 8FB00030 */  lw        $s0, 0x30($sp)
/* A4A004 80241A44 03E00008 */  jr        $ra
/* A4A008 80241A48 27BD0048 */   addiu    $sp, $sp, 0x48
