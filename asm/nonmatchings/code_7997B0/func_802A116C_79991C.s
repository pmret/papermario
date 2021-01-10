.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A116C_79991C
/* 79991C 802A116C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 799920 802A1170 AFB1001C */  sw        $s1, 0x1c($sp)
/* 799924 802A1174 0080882D */  daddu     $s1, $a0, $zero
/* 799928 802A1178 AFBF0024 */  sw        $ra, 0x24($sp)
/* 79992C 802A117C AFB20020 */  sw        $s2, 0x20($sp)
/* 799930 802A1180 AFB00018 */  sw        $s0, 0x18($sp)
/* 799934 802A1184 8E30000C */  lw        $s0, 0xc($s1)
/* 799938 802A1188 8E050000 */  lw        $a1, ($s0)
/* 79993C 802A118C 0C0B1EAF */  jal       get_variable
/* 799940 802A1190 26100004 */   addiu    $s0, $s0, 4
/* 799944 802A1194 8E050000 */  lw        $a1, ($s0)
/* 799948 802A1198 26100004 */  addiu     $s0, $s0, 4
/* 79994C 802A119C 0220202D */  daddu     $a0, $s1, $zero
/* 799950 802A11A0 0C0B1EAF */  jal       get_variable
/* 799954 802A11A4 0040902D */   daddu    $s2, $v0, $zero
/* 799958 802A11A8 0220202D */  daddu     $a0, $s1, $zero
/* 79995C 802A11AC 8E050000 */  lw        $a1, ($s0)
/* 799960 802A11B0 0C0B1EAF */  jal       get_variable
/* 799964 802A11B4 0040802D */   daddu    $s0, $v0, $zero
/* 799968 802A11B8 44921000 */  mtc1      $s2, $f2
/* 79996C 802A11BC 00000000 */  nop       
/* 799970 802A11C0 468010A0 */  cvt.s.w   $f2, $f2
/* 799974 802A11C4 44051000 */  mfc1      $a1, $f2
/* 799978 802A11C8 44901000 */  mtc1      $s0, $f2
/* 79997C 802A11CC 00000000 */  nop       
/* 799980 802A11D0 468010A0 */  cvt.s.w   $f2, $f2
/* 799984 802A11D4 44061000 */  mfc1      $a2, $f2
/* 799988 802A11D8 44821000 */  mtc1      $v0, $f2
/* 79998C 802A11DC 00000000 */  nop       
/* 799990 802A11E0 468010A0 */  cvt.s.w   $f2, $f2
/* 799994 802A11E4 3C0141F0 */  lui       $at, 0x41f0
/* 799998 802A11E8 44810000 */  mtc1      $at, $f0
/* 79999C 802A11EC 44071000 */  mfc1      $a3, $f2
/* 7999A0 802A11F0 0000202D */  daddu     $a0, $zero, $zero
/* 7999A4 802A11F4 0C01BFBC */  jal       func_8006FEF0
/* 7999A8 802A11F8 E7A00010 */   swc1     $f0, 0x10($sp)
/* 7999AC 802A11FC 8FBF0024 */  lw        $ra, 0x24($sp)
/* 7999B0 802A1200 8FB20020 */  lw        $s2, 0x20($sp)
/* 7999B4 802A1204 8FB1001C */  lw        $s1, 0x1c($sp)
/* 7999B8 802A1208 8FB00018 */  lw        $s0, 0x18($sp)
/* 7999BC 802A120C 24020002 */  addiu     $v0, $zero, 2
/* 7999C0 802A1210 03E00008 */  jr        $ra
/* 7999C4 802A1214 27BD0028 */   addiu    $sp, $sp, 0x28
