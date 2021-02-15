.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241EE0_9FC6D0
/* 9FC6D0 80241EE0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 9FC6D4 80241EE4 3C048024 */  lui       $a0, %hi(D_802459CC_A001BC)
/* 9FC6D8 80241EE8 248459CC */  addiu     $a0, $a0, %lo(D_802459CC_A001BC)
/* 9FC6DC 80241EEC AFBF0018 */  sw        $ra, 0x18($sp)
/* 9FC6E0 80241EF0 AFB10014 */  sw        $s1, 0x14($sp)
/* 9FC6E4 80241EF4 AFB00010 */  sw        $s0, 0x10($sp)
/* 9FC6E8 80241EF8 F7B40020 */  sdc1      $f20, 0x20($sp)
/* 9FC6EC 80241EFC 8C830000 */  lw        $v1, ($a0)
/* 9FC6F0 80241F00 3C118011 */  lui       $s1, %hi(gPlayerStatus)
/* 9FC6F4 80241F04 2631EFC8 */  addiu     $s1, $s1, %lo(gPlayerStatus)
/* 9FC6F8 80241F08 28620003 */  slti      $v0, $v1, 3
/* 9FC6FC 80241F0C 50400007 */  beql      $v0, $zero, .L80241F2C
/* 9FC700 80241F10 24020003 */   addiu    $v0, $zero, 3
/* 9FC704 80241F14 1C60000C */  bgtz      $v1, .L80241F48
/* 9FC708 80241F18 24620001 */   addiu    $v0, $v1, 1
/* 9FC70C 80241F1C 10600007 */  beqz      $v1, .L80241F3C
/* 9FC710 80241F20 0000102D */   daddu    $v0, $zero, $zero
/* 9FC714 80241F24 080907EE */  j         .L80241FB8
/* 9FC718 80241F28 00000000 */   nop
.L80241F2C:
/* 9FC71C 80241F2C 10620008 */  beq       $v1, $v0, .L80241F50
/* 9FC720 80241F30 0000102D */   daddu    $v0, $zero, $zero
/* 9FC724 80241F34 080907EE */  j         .L80241FB8
/* 9FC728 80241F38 00000000 */   nop
.L80241F3C:
/* 9FC72C 80241F3C 24020001 */  addiu     $v0, $zero, 1
/* 9FC730 80241F40 080907ED */  j         .L80241FB4
/* 9FC734 80241F44 AC820000 */   sw       $v0, ($a0)
.L80241F48:
/* 9FC738 80241F48 080907ED */  j         .L80241FB4
/* 9FC73C 80241F4C AC820000 */   sw       $v0, ($a0)
.L80241F50:
/* 9FC740 80241F50 3C108011 */  lui       $s0, %hi(D_8010C930)
/* 9FC744 80241F54 2610C930 */  addiu     $s0, $s0, %lo(D_8010C930)
/* 9FC748 80241F58 0C03BD17 */  jal       clear_partner_move_history
/* 9FC74C 80241F5C 8E040000 */   lw       $a0, ($s0)
/* 9FC750 80241F60 C6200028 */  lwc1      $f0, 0x28($s1)
/* 9FC754 80241F64 C6220030 */  lwc1      $f2, 0x30($s1)
/* 9FC758 80241F68 4600010D */  trunc.w.s $f4, $f0
/* 9FC75C 80241F6C 44042000 */  mfc1      $a0, $f4
/* 9FC760 80241F70 4600110D */  trunc.w.s $f4, $f2
/* 9FC764 80241F74 44052000 */  mfc1      $a1, $f4
/* 9FC768 80241F78 0C03BCF0 */  jal       func_800EF3C0
/* 9FC76C 80241F7C 00000000 */   nop
/* 9FC770 80241F80 0C03BCF5 */  jal       func_800EF3D4
/* 9FC774 80241F84 0000202D */   daddu    $a0, $zero, $zero
/* 9FC778 80241F88 3C0142B4 */  lui       $at, 0x42b4
/* 9FC77C 80241F8C 4481A000 */  mtc1      $at, $f20
/* 9FC780 80241F90 8E040000 */  lw        $a0, ($s0)
/* 9FC784 80241F94 4405A000 */  mfc1      $a1, $f20
/* 9FC788 80241F98 0C00ECD0 */  jal       set_npc_yaw
/* 9FC78C 80241F9C 00000000 */   nop
/* 9FC790 80241FA0 24020002 */  addiu     $v0, $zero, 2
/* 9FC794 80241FA4 E6340080 */  swc1      $f20, 0x80($s1)
/* 9FC798 80241FA8 E6340084 */  swc1      $f20, 0x84($s1)
/* 9FC79C 80241FAC 080907EE */  j         .L80241FB8
/* 9FC7A0 80241FB0 AE2000A8 */   sw       $zero, 0xa8($s1)
.L80241FB4:
/* 9FC7A4 80241FB4 0000102D */  daddu     $v0, $zero, $zero
.L80241FB8:
/* 9FC7A8 80241FB8 8FBF0018 */  lw        $ra, 0x18($sp)
/* 9FC7AC 80241FBC 8FB10014 */  lw        $s1, 0x14($sp)
/* 9FC7B0 80241FC0 8FB00010 */  lw        $s0, 0x10($sp)
/* 9FC7B4 80241FC4 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 9FC7B8 80241FC8 03E00008 */  jr        $ra
/* 9FC7BC 80241FCC 27BD0028 */   addiu    $sp, $sp, 0x28
