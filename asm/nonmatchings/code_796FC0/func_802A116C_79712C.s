.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A116C_79712C
/* 79712C 802A116C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 797130 802A1170 AFB1001C */  sw        $s1, 0x1c($sp)
/* 797134 802A1174 0080882D */  daddu     $s1, $a0, $zero
/* 797138 802A1178 AFBF0024 */  sw        $ra, 0x24($sp)
/* 79713C 802A117C AFB20020 */  sw        $s2, 0x20($sp)
/* 797140 802A1180 AFB00018 */  sw        $s0, 0x18($sp)
/* 797144 802A1184 8E30000C */  lw        $s0, 0xc($s1)
/* 797148 802A1188 8E050000 */  lw        $a1, ($s0)
/* 79714C 802A118C 0C0B1EAF */  jal       get_variable
/* 797150 802A1190 26100004 */   addiu    $s0, $s0, 4
/* 797154 802A1194 8E050000 */  lw        $a1, ($s0)
/* 797158 802A1198 26100004 */  addiu     $s0, $s0, 4
/* 79715C 802A119C 0220202D */  daddu     $a0, $s1, $zero
/* 797160 802A11A0 0C0B1EAF */  jal       get_variable
/* 797164 802A11A4 0040902D */   daddu    $s2, $v0, $zero
/* 797168 802A11A8 0220202D */  daddu     $a0, $s1, $zero
/* 79716C 802A11AC 8E050000 */  lw        $a1, ($s0)
/* 797170 802A11B0 0C0B1EAF */  jal       get_variable
/* 797174 802A11B4 0040802D */   daddu    $s0, $v0, $zero
/* 797178 802A11B8 44921000 */  mtc1      $s2, $f2
/* 79717C 802A11BC 00000000 */  nop       
/* 797180 802A11C0 468010A0 */  cvt.s.w   $f2, $f2
/* 797184 802A11C4 44051000 */  mfc1      $a1, $f2
/* 797188 802A11C8 44901000 */  mtc1      $s0, $f2
/* 79718C 802A11CC 00000000 */  nop       
/* 797190 802A11D0 468010A0 */  cvt.s.w   $f2, $f2
/* 797194 802A11D4 44061000 */  mfc1      $a2, $f2
/* 797198 802A11D8 44821000 */  mtc1      $v0, $f2
/* 79719C 802A11DC 00000000 */  nop       
/* 7971A0 802A11E0 468010A0 */  cvt.s.w   $f2, $f2
/* 7971A4 802A11E4 3C0141F0 */  lui       $at, 0x41f0
/* 7971A8 802A11E8 44810000 */  mtc1      $at, $f0
/* 7971AC 802A11EC 44071000 */  mfc1      $a3, $f2
/* 7971B0 802A11F0 0000202D */  daddu     $a0, $zero, $zero
/* 7971B4 802A11F4 0C01BFBC */  jal       func_8006FEF0
/* 7971B8 802A11F8 E7A00010 */   swc1     $f0, 0x10($sp)
/* 7971BC 802A11FC 8FBF0024 */  lw        $ra, 0x24($sp)
/* 7971C0 802A1200 8FB20020 */  lw        $s2, 0x20($sp)
/* 7971C4 802A1204 8FB1001C */  lw        $s1, 0x1c($sp)
/* 7971C8 802A1208 8FB00018 */  lw        $s0, 0x18($sp)
/* 7971CC 802A120C 24020002 */  addiu     $v0, $zero, 2
/* 7971D0 802A1210 03E00008 */  jr        $ra
/* 7971D4 802A1214 27BD0028 */   addiu    $sp, $sp, 0x28
