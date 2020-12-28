.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80219F5C_6A115C
/* 6A115C 80219F5C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 6A1160 80219F60 AFB20018 */  sw        $s2, 0x18($sp)
/* 6A1164 80219F64 0080902D */  daddu     $s2, $a0, $zero
/* 6A1168 80219F68 AFBF001C */  sw        $ra, 0x1c($sp)
/* 6A116C 80219F6C AFB10014 */  sw        $s1, 0x14($sp)
/* 6A1170 80219F70 AFB00010 */  sw        $s0, 0x10($sp)
/* 6A1174 80219F74 8E50000C */  lw        $s0, 0xc($s2)
/* 6A1178 80219F78 8E050000 */  lw        $a1, ($s0)
/* 6A117C 80219F7C 0C0B1EAF */  jal       get_variable
/* 6A1180 80219F80 26100004 */   addiu    $s0, $s0, 4
/* 6A1184 80219F84 0C04C3D6 */  jal       get_item_entity
/* 6A1188 80219F88 0040202D */   daddu    $a0, $v0, $zero
/* 6A118C 80219F8C 8E050000 */  lw        $a1, ($s0)
/* 6A1190 80219F90 26100004 */  addiu     $s0, $s0, 4
/* 6A1194 80219F94 0040882D */  daddu     $s1, $v0, $zero
/* 6A1198 80219F98 C6200008 */  lwc1      $f0, 8($s1)
/* 6A119C 80219F9C 4600008D */  trunc.w.s $f2, $f0
/* 6A11A0 80219FA0 44061000 */  mfc1      $a2, $f2
/* 6A11A4 80219FA4 0C0B2026 */  jal       set_variable
/* 6A11A8 80219FA8 0240202D */   daddu    $a0, $s2, $zero
/* 6A11AC 80219FAC 8E050000 */  lw        $a1, ($s0)
/* 6A11B0 80219FB0 26100004 */  addiu     $s0, $s0, 4
/* 6A11B4 80219FB4 C620000C */  lwc1      $f0, 0xc($s1)
/* 6A11B8 80219FB8 4600008D */  trunc.w.s $f2, $f0
/* 6A11BC 80219FBC 44061000 */  mfc1      $a2, $f2
/* 6A11C0 80219FC0 0C0B2026 */  jal       set_variable
/* 6A11C4 80219FC4 0240202D */   daddu    $a0, $s2, $zero
/* 6A11C8 80219FC8 C6200010 */  lwc1      $f0, 0x10($s1)
/* 6A11CC 80219FCC 8E050000 */  lw        $a1, ($s0)
/* 6A11D0 80219FD0 4600008D */  trunc.w.s $f2, $f0
/* 6A11D4 80219FD4 44061000 */  mfc1      $a2, $f2
/* 6A11D8 80219FD8 0C0B2026 */  jal       set_variable
/* 6A11DC 80219FDC 0240202D */   daddu    $a0, $s2, $zero
/* 6A11E0 80219FE0 8FBF001C */  lw        $ra, 0x1c($sp)
/* 6A11E4 80219FE4 8FB20018 */  lw        $s2, 0x18($sp)
/* 6A11E8 80219FE8 8FB10014 */  lw        $s1, 0x14($sp)
/* 6A11EC 80219FEC 8FB00010 */  lw        $s0, 0x10($sp)
/* 6A11F0 80219FF0 24020002 */  addiu     $v0, $zero, 2
/* 6A11F4 80219FF4 03E00008 */  jr        $ra
/* 6A11F8 80219FF8 27BD0020 */   addiu    $sp, $sp, 0x20
