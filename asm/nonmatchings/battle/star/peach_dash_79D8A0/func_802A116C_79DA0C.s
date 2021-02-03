.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A116C_79DA0C
/* 79DA0C 802A116C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 79DA10 802A1170 AFB1001C */  sw        $s1, 0x1c($sp)
/* 79DA14 802A1174 0080882D */  daddu     $s1, $a0, $zero
/* 79DA18 802A1178 AFBF0024 */  sw        $ra, 0x24($sp)
/* 79DA1C 802A117C AFB20020 */  sw        $s2, 0x20($sp)
/* 79DA20 802A1180 AFB00018 */  sw        $s0, 0x18($sp)
/* 79DA24 802A1184 8E30000C */  lw        $s0, 0xc($s1)
/* 79DA28 802A1188 8E050000 */  lw        $a1, ($s0)
/* 79DA2C 802A118C 0C0B1EAF */  jal       func_802C7ABC_7C435C
/* 79DA30 802A1190 26100004 */   addiu    $s0, $s0, 4
/* 79DA34 802A1194 8E050000 */  lw        $a1, ($s0)
/* 79DA38 802A1198 26100004 */  addiu     $s0, $s0, 4
/* 79DA3C 802A119C 0220202D */  daddu     $a0, $s1, $zero
/* 79DA40 802A11A0 0C0B1EAF */  jal       func_802C7ABC_7C435C
/* 79DA44 802A11A4 0040902D */   daddu    $s2, $v0, $zero
/* 79DA48 802A11A8 0220202D */  daddu     $a0, $s1, $zero
/* 79DA4C 802A11AC 8E050000 */  lw        $a1, ($s0)
/* 79DA50 802A11B0 0C0B1EAF */  jal       func_802C7ABC_7C435C
/* 79DA54 802A11B4 0040802D */   daddu    $s0, $v0, $zero
/* 79DA58 802A11B8 44921000 */  mtc1      $s2, $f2
/* 79DA5C 802A11BC 00000000 */  nop
/* 79DA60 802A11C0 468010A0 */  cvt.s.w   $f2, $f2
/* 79DA64 802A11C4 44051000 */  mfc1      $a1, $f2
/* 79DA68 802A11C8 44901000 */  mtc1      $s0, $f2
/* 79DA6C 802A11CC 00000000 */  nop
/* 79DA70 802A11D0 468010A0 */  cvt.s.w   $f2, $f2
/* 79DA74 802A11D4 44061000 */  mfc1      $a2, $f2
/* 79DA78 802A11D8 44821000 */  mtc1      $v0, $f2
/* 79DA7C 802A11DC 00000000 */  nop
/* 79DA80 802A11E0 468010A0 */  cvt.s.w   $f2, $f2
/* 79DA84 802A11E4 3C0141F0 */  lui       $at, 0x41f0
/* 79DA88 802A11E8 44810000 */  mtc1      $at, $f0
/* 79DA8C 802A11EC 44071000 */  mfc1      $a3, $f2
/* 79DA90 802A11F0 0000202D */  daddu     $a0, $zero, $zero
/* 79DA94 802A11F4 0C01BFBC */  jal       func_8006FEF0
/* 79DA98 802A11F8 E7A00010 */   swc1     $f0, 0x10($sp)
/* 79DA9C 802A11FC 8FBF0024 */  lw        $ra, 0x24($sp)
/* 79DAA0 802A1200 8FB20020 */  lw        $s2, 0x20($sp)
/* 79DAA4 802A1204 8FB1001C */  lw        $s1, 0x1c($sp)
/* 79DAA8 802A1208 8FB00018 */  lw        $s0, 0x18($sp)
/* 79DAAC 802A120C 24020002 */  addiu     $v0, $zero, 2
/* 79DAB0 802A1210 03E00008 */  jr        $ra
/* 79DAB4 802A1214 27BD0028 */   addiu    $sp, $sp, 0x28
