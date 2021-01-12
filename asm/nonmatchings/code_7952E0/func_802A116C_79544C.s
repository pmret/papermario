.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A116C_79544C
/* 79544C 802A116C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 795450 802A1170 AFB1001C */  sw        $s1, 0x1c($sp)
/* 795454 802A1174 0080882D */  daddu     $s1, $a0, $zero
/* 795458 802A1178 AFBF0024 */  sw        $ra, 0x24($sp)
/* 79545C 802A117C AFB20020 */  sw        $s2, 0x20($sp)
/* 795460 802A1180 AFB00018 */  sw        $s0, 0x18($sp)
/* 795464 802A1184 8E30000C */  lw        $s0, 0xc($s1)
/* 795468 802A1188 8E050000 */  lw        $a1, ($s0)
/* 79546C 802A118C 0C0B1EAF */  jal       get_variable
/* 795470 802A1190 26100004 */   addiu    $s0, $s0, 4
/* 795474 802A1194 8E050000 */  lw        $a1, ($s0)
/* 795478 802A1198 26100004 */  addiu     $s0, $s0, 4
/* 79547C 802A119C 0220202D */  daddu     $a0, $s1, $zero
/* 795480 802A11A0 0C0B1EAF */  jal       get_variable
/* 795484 802A11A4 0040902D */   daddu    $s2, $v0, $zero
/* 795488 802A11A8 0220202D */  daddu     $a0, $s1, $zero
/* 79548C 802A11AC 8E050000 */  lw        $a1, ($s0)
/* 795490 802A11B0 0C0B1EAF */  jal       get_variable
/* 795494 802A11B4 0040802D */   daddu    $s0, $v0, $zero
/* 795498 802A11B8 44921000 */  mtc1      $s2, $f2
/* 79549C 802A11BC 00000000 */  nop       
/* 7954A0 802A11C0 468010A0 */  cvt.s.w   $f2, $f2
/* 7954A4 802A11C4 44051000 */  mfc1      $a1, $f2
/* 7954A8 802A11C8 44901000 */  mtc1      $s0, $f2
/* 7954AC 802A11CC 00000000 */  nop       
/* 7954B0 802A11D0 468010A0 */  cvt.s.w   $f2, $f2
/* 7954B4 802A11D4 44061000 */  mfc1      $a2, $f2
/* 7954B8 802A11D8 44821000 */  mtc1      $v0, $f2
/* 7954BC 802A11DC 00000000 */  nop       
/* 7954C0 802A11E0 468010A0 */  cvt.s.w   $f2, $f2
/* 7954C4 802A11E4 3C0141F0 */  lui       $at, 0x41f0
/* 7954C8 802A11E8 44810000 */  mtc1      $at, $f0
/* 7954CC 802A11EC 44071000 */  mfc1      $a3, $f2
/* 7954D0 802A11F0 0000202D */  daddu     $a0, $zero, $zero
/* 7954D4 802A11F4 0C01BFBC */  jal       func_8006FEF0
/* 7954D8 802A11F8 E7A00010 */   swc1     $f0, 0x10($sp)
/* 7954DC 802A11FC 8FBF0024 */  lw        $ra, 0x24($sp)
/* 7954E0 802A1200 8FB20020 */  lw        $s2, 0x20($sp)
/* 7954E4 802A1204 8FB1001C */  lw        $s1, 0x1c($sp)
/* 7954E8 802A1208 8FB00018 */  lw        $s0, 0x18($sp)
/* 7954EC 802A120C 24020002 */  addiu     $v0, $zero, 2
/* 7954F0 802A1210 03E00008 */  jr        $ra
/* 7954F4 802A1214 27BD0028 */   addiu    $sp, $sp, 0x28
