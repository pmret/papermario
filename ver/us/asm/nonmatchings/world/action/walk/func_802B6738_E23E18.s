.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802B6738_E23E18
/* E23E18 802B6738 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* E23E1C 802B673C AFB00018 */  sw        $s0, 0x18($sp)
/* E23E20 802B6740 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* E23E24 802B6744 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* E23E28 802B6748 AFBF001C */  sw        $ra, 0x1c($sp)
/* E23E2C 802B674C 8E030000 */  lw        $v1, ($s0)
/* E23E30 802B6750 0461002E */  bgez      $v1, .L802B680C
/* E23E34 802B6754 3C027FFF */   lui      $v0, 0x7fff
/* E23E38 802B6758 3442FFFF */  ori       $v0, $v0, 0xffff
/* E23E3C 802B675C 00621024 */  and       $v0, $v1, $v0
/* E23E40 802B6760 AE020000 */  sw        $v0, ($s0)
/* E23E44 802B6764 30624000 */  andi      $v0, $v1, 0x4000
/* E23E48 802B6768 14400003 */  bnez      $v0, .L802B6778
/* E23E4C 802B676C AE000060 */   sw       $zero, 0x60($s0)
/* E23E50 802B6770 C600005C */  lwc1      $f0, 0x5c($s0)
/* E23E54 802B6774 E6000054 */  swc1      $f0, 0x54($s0)
.L802B6778:
/* E23E58 802B6778 8E020004 */  lw        $v0, 4($s0)
/* E23E5C 802B677C 30422000 */  andi      $v0, $v0, 0x2000
/* E23E60 802B6780 14400019 */  bnez      $v0, .L802B67E8
/* E23E64 802B6784 00000000 */   nop
/* E23E68 802B6788 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* E23E6C 802B678C 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* E23E70 802B6790 9062007E */  lbu       $v0, 0x7e($v1)
/* E23E74 802B6794 30420010 */  andi      $v0, $v0, 0x10
/* E23E78 802B6798 1440000F */  bnez      $v0, .L802B67D8
/* E23E7C 802B679C 3C04000D */   lui      $a0, 0xd
/* E23E80 802B67A0 90620080 */  lbu       $v0, 0x80($v1)
/* E23E84 802B67A4 14400006 */  bnez      $v0, .L802B67C0
/* E23E88 802B67A8 00021080 */   sll      $v0, $v0, 2
/* E23E8C 802B67AC 3C04000A */  lui       $a0, 0xa
/* E23E90 802B67B0 0C037FBF */  jal       suggest_player_anim_clearUnkFlag
/* E23E94 802B67B4 34840003 */   ori      $a0, $a0, 3
/* E23E98 802B67B8 080ADA03 */  j         .L802B680C
/* E23E9C 802B67BC 00000000 */   nop
.L802B67C0:
/* E23EA0 802B67C0 3C04802B */  lui       $a0, %hi(D_802B6910_E23FF0)
/* E23EA4 802B67C4 00822021 */  addu      $a0, $a0, $v0
/* E23EA8 802B67C8 0C037FBF */  jal       suggest_player_anim_clearUnkFlag
/* E23EAC 802B67CC 8C846910 */   lw       $a0, %lo(D_802B6910_E23FF0)($a0)
/* E23EB0 802B67D0 080ADA03 */  j         .L802B680C
/* E23EB4 802B67D4 00000000 */   nop
.L802B67D8:
/* E23EB8 802B67D8 0C037FBF */  jal       suggest_player_anim_clearUnkFlag
/* E23EBC 802B67DC 3484000D */   ori      $a0, $a0, 0xd
/* E23EC0 802B67E0 080ADA03 */  j         .L802B680C
/* E23EC4 802B67E4 00000000 */   nop
.L802B67E8:
/* E23EC8 802B67E8 8203000C */  lb        $v1, 0xc($s0)
/* E23ECC 802B67EC 00031040 */  sll       $v0, $v1, 1
/* E23ED0 802B67F0 00431021 */  addu      $v0, $v0, $v1
/* E23ED4 802B67F4 000210C0 */  sll       $v0, $v0, 3
/* E23ED8 802B67F8 3C04800F */  lui       $a0, %hi(world_actions_peachDisguises+0x8)
/* E23EDC 802B67FC 00822021 */  addu      $a0, $a0, $v0
/* E23EE0 802B6800 8C847C24 */  lw        $a0, %lo(world_actions_peachDisguises+0x8)($a0)
/* E23EE4 802B6804 0C0398DB */  jal       peach_set_disguise_anim
/* E23EE8 802B6808 00000000 */   nop
.L802B680C:
/* E23EEC 802B680C 8E020000 */  lw        $v0, ($s0)
/* E23EF0 802B6810 30424000 */  andi      $v0, $v0, 0x4000
/* E23EF4 802B6814 10400004 */  beqz      $v0, .L802B6828
/* E23EF8 802B6818 24040004 */   addiu    $a0, $zero, 4
/* E23EFC 802B681C C60000A0 */  lwc1      $f0, 0xa0($s0)
/* E23F00 802B6820 080ADA3B */  j         .L802B68EC
/* E23F04 802B6824 E6000080 */   swc1     $f0, 0x80($s0)
.L802B6828:
/* E23F08 802B6828 27A40010 */  addiu     $a0, $sp, 0x10
/* E23F0C 802B682C C600005C */  lwc1      $f0, 0x5c($s0)
/* E23F10 802B6830 27A50014 */  addiu     $a1, $sp, 0x14
/* E23F14 802B6834 0C0388C1 */  jal       player_input_to_move_vector
/* E23F18 802B6838 E6000054 */   swc1     $f0, 0x54($s0)
/* E23F1C 802B683C 0C039454 */  jal       phys_update_interact_collider
/* E23F20 802B6840 00000000 */   nop
/* E23F24 802B6844 C7A20014 */  lwc1      $f2, 0x14($sp)
/* E23F28 802B6848 44800000 */  mtc1      $zero, $f0
/* E23F2C 802B684C 00000000 */  nop
/* E23F30 802B6850 46001032 */  c.eq.s    $f2, $f0
/* E23F34 802B6854 00000000 */  nop
/* E23F38 802B6858 45000005 */  bc1f      .L802B6870
/* E23F3C 802B685C 00000000 */   nop
/* E23F40 802B6860 0C039769 */  jal       set_action_state
/* E23F44 802B6864 0000202D */   daddu    $a0, $zero, $zero
/* E23F48 802B6868 080ADA3D */  j         .L802B68F4
/* E23F4C 802B686C 00000000 */   nop
.L802B6870:
/* E23F50 802B6870 8E0200E8 */  lw        $v0, 0xe8($s0)
/* E23F54 802B6874 00420018 */  mult      $v0, $v0
/* E23F58 802B6878 00001812 */  mflo      $v1
/* E23F5C 802B687C 8E0200EC */  lw        $v0, 0xec($s0)
/* E23F60 802B6880 00000000 */  nop
/* E23F64 802B6884 00420018 */  mult      $v0, $v0
/* E23F68 802B6888 C7A00010 */  lwc1      $f0, 0x10($sp)
/* E23F6C 802B688C 00001012 */  mflo      $v0
/* E23F70 802B6890 00621021 */  addu      $v0, $v1, $v0
/* E23F74 802B6894 44826000 */  mtc1      $v0, $f12
/* E23F78 802B6898 00000000 */  nop
/* E23F7C 802B689C 46806320 */  cvt.s.w   $f12, $f12
/* E23F80 802B68A0 46006084 */  sqrt.s    $f2, $f12
/* E23F84 802B68A4 46021032 */  c.eq.s    $f2, $f2
/* E23F88 802B68A8 00000000 */  nop
/* E23F8C 802B68AC 45010004 */  bc1t      .L802B68C0
/* E23F90 802B68B0 E6000080 */   swc1     $f0, 0x80($s0)
/* E23F94 802B68B4 0C0187BC */  jal       sqrtf
/* E23F98 802B68B8 00000000 */   nop
/* E23F9C 802B68BC 46000086 */  mov.s     $f2, $f0
.L802B68C0:
/* E23FA0 802B68C0 3C01425C */  lui       $at, 0x425c
/* E23FA4 802B68C4 44810000 */  mtc1      $at, $f0
/* E23FA8 802B68C8 00000000 */  nop
/* E23FAC 802B68CC 4600103C */  c.lt.s    $f2, $f0
/* E23FB0 802B68D0 00000000 */  nop
/* E23FB4 802B68D4 45000005 */  bc1f      .L802B68EC
/* E23FB8 802B68D8 24040004 */   addiu    $a0, $zero, 4
/* E23FBC 802B68DC 0C039769 */  jal       set_action_state
/* E23FC0 802B68E0 24040001 */   addiu    $a0, $zero, 1
/* E23FC4 802B68E4 080ADA3D */  j         .L802B68F4
/* E23FC8 802B68E8 00000000 */   nop
.L802B68EC:
/* E23FCC 802B68EC 0C039426 */  jal       try_player_footstep_sounds
/* E23FD0 802B68F0 00000000 */   nop
.L802B68F4:
/* E23FD4 802B68F4 8FBF001C */  lw        $ra, 0x1c($sp)
/* E23FD8 802B68F8 8FB00018 */  lw        $s0, 0x18($sp)
/* E23FDC 802B68FC 03E00008 */  jr        $ra
/* E23FE0 802B6900 27BD0020 */   addiu    $sp, $sp, 0x20
/* E23FE4 802B6904 00000000 */  nop
/* E23FE8 802B6908 00000000 */  nop
/* E23FEC 802B690C 00000000 */  nop
