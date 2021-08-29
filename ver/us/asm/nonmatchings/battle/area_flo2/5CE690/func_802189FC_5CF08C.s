.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802189FC_5CF08C
/* 5CF08C 802189FC 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 5CF090 80218A00 AFB10014 */  sw        $s1, 0x14($sp)
/* 5CF094 80218A04 0080882D */  daddu     $s1, $a0, $zero
/* 5CF098 80218A08 AFBF001C */  sw        $ra, 0x1c($sp)
/* 5CF09C 80218A0C AFB20018 */  sw        $s2, 0x18($sp)
/* 5CF0A0 80218A10 AFB00010 */  sw        $s0, 0x10($sp)
/* 5CF0A4 80218A14 F7B60028 */  sdc1      $f22, 0x28($sp)
/* 5CF0A8 80218A18 F7B40020 */  sdc1      $f20, 0x20($sp)
/* 5CF0AC 80218A1C 8E30000C */  lw        $s0, 0xc($s1)
/* 5CF0B0 80218A20 8E050000 */  lw        $a1, ($s0)
/* 5CF0B4 80218A24 0C0B1EAF */  jal       get_variable
/* 5CF0B8 80218A28 26100004 */   addiu    $s0, $s0, 4
/* 5CF0BC 80218A2C 8E050000 */  lw        $a1, ($s0)
/* 5CF0C0 80218A30 26100004 */  addiu     $s0, $s0, 4
/* 5CF0C4 80218A34 0220202D */  daddu     $a0, $s1, $zero
/* 5CF0C8 80218A38 0C0B210B */  jal       evt_get_float_variable
/* 5CF0CC 80218A3C 0040902D */   daddu    $s2, $v0, $zero
/* 5CF0D0 80218A40 8E050000 */  lw        $a1, ($s0)
/* 5CF0D4 80218A44 26100004 */  addiu     $s0, $s0, 4
/* 5CF0D8 80218A48 0220202D */  daddu     $a0, $s1, $zero
/* 5CF0DC 80218A4C 0C0B210B */  jal       evt_get_float_variable
/* 5CF0E0 80218A50 46000586 */   mov.s    $f22, $f0
/* 5CF0E4 80218A54 0220202D */  daddu     $a0, $s1, $zero
/* 5CF0E8 80218A58 8E050000 */  lw        $a1, ($s0)
/* 5CF0EC 80218A5C 0C0B210B */  jal       evt_get_float_variable
/* 5CF0F0 80218A60 46000506 */   mov.s    $f20, $f0
/* 5CF0F4 80218A64 8E42000C */  lw        $v0, 0xc($s2)
/* 5CF0F8 80218A68 E4560004 */  swc1      $f22, 4($v0)
/* 5CF0FC 80218A6C 8E42000C */  lw        $v0, 0xc($s2)
/* 5CF100 80218A70 E4540008 */  swc1      $f20, 8($v0)
/* 5CF104 80218A74 8E43000C */  lw        $v1, 0xc($s2)
/* 5CF108 80218A78 E460000C */  swc1      $f0, 0xc($v1)
/* 5CF10C 80218A7C 8FBF001C */  lw        $ra, 0x1c($sp)
/* 5CF110 80218A80 8FB20018 */  lw        $s2, 0x18($sp)
/* 5CF114 80218A84 8FB10014 */  lw        $s1, 0x14($sp)
/* 5CF118 80218A88 8FB00010 */  lw        $s0, 0x10($sp)
/* 5CF11C 80218A8C D7B60028 */  ldc1      $f22, 0x28($sp)
/* 5CF120 80218A90 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 5CF124 80218A94 24020002 */  addiu     $v0, $zero, 2
/* 5CF128 80218A98 03E00008 */  jr        $ra
/* 5CF12C 80218A9C 27BD0030 */   addiu    $sp, $sp, 0x30
