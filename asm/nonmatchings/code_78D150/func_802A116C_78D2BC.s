.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A116C_78D2BC
/* 78D2BC 802A116C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 78D2C0 802A1170 AFB1001C */  sw        $s1, 0x1c($sp)
/* 78D2C4 802A1174 0080882D */  daddu     $s1, $a0, $zero
/* 78D2C8 802A1178 AFBF0024 */  sw        $ra, 0x24($sp)
/* 78D2CC 802A117C AFB20020 */  sw        $s2, 0x20($sp)
/* 78D2D0 802A1180 AFB00018 */  sw        $s0, 0x18($sp)
/* 78D2D4 802A1184 8E30000C */  lw        $s0, 0xc($s1)
/* 78D2D8 802A1188 8E050000 */  lw        $a1, ($s0)
/* 78D2DC 802A118C 0C0B1EAF */  jal       get_variable
/* 78D2E0 802A1190 26100004 */   addiu    $s0, $s0, 4
/* 78D2E4 802A1194 8E050000 */  lw        $a1, ($s0)
/* 78D2E8 802A1198 26100004 */  addiu     $s0, $s0, 4
/* 78D2EC 802A119C 0220202D */  daddu     $a0, $s1, $zero
/* 78D2F0 802A11A0 0C0B1EAF */  jal       get_variable
/* 78D2F4 802A11A4 0040902D */   daddu    $s2, $v0, $zero
/* 78D2F8 802A11A8 0220202D */  daddu     $a0, $s1, $zero
/* 78D2FC 802A11AC 8E050000 */  lw        $a1, ($s0)
/* 78D300 802A11B0 0C0B1EAF */  jal       get_variable
/* 78D304 802A11B4 0040802D */   daddu    $s0, $v0, $zero
/* 78D308 802A11B8 44921000 */  mtc1      $s2, $f2
/* 78D30C 802A11BC 00000000 */  nop       
/* 78D310 802A11C0 468010A0 */  cvt.s.w   $f2, $f2
/* 78D314 802A11C4 44051000 */  mfc1      $a1, $f2
/* 78D318 802A11C8 44901000 */  mtc1      $s0, $f2
/* 78D31C 802A11CC 00000000 */  nop       
/* 78D320 802A11D0 468010A0 */  cvt.s.w   $f2, $f2
/* 78D324 802A11D4 44061000 */  mfc1      $a2, $f2
/* 78D328 802A11D8 44821000 */  mtc1      $v0, $f2
/* 78D32C 802A11DC 00000000 */  nop       
/* 78D330 802A11E0 468010A0 */  cvt.s.w   $f2, $f2
/* 78D334 802A11E4 3C0141F0 */  lui       $at, 0x41f0
/* 78D338 802A11E8 44810000 */  mtc1      $at, $f0
/* 78D33C 802A11EC 44071000 */  mfc1      $a3, $f2
/* 78D340 802A11F0 0000202D */  daddu     $a0, $zero, $zero
/* 78D344 802A11F4 0C01BFBC */  jal       func_8006FEF0
/* 78D348 802A11F8 E7A00010 */   swc1     $f0, 0x10($sp)
/* 78D34C 802A11FC 8FBF0024 */  lw        $ra, 0x24($sp)
/* 78D350 802A1200 8FB20020 */  lw        $s2, 0x20($sp)
/* 78D354 802A1204 8FB1001C */  lw        $s1, 0x1c($sp)
/* 78D358 802A1208 8FB00018 */  lw        $s0, 0x18($sp)
/* 78D35C 802A120C 24020002 */  addiu     $v0, $zero, 2
/* 78D360 802A1210 03E00008 */  jr        $ra
/* 78D364 802A1214 27BD0028 */   addiu    $sp, $sp, 0x28
