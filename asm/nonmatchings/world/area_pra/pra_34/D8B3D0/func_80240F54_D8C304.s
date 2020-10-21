.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F54_D8C304
/* D8C304 80240F54 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D8C308 80240F58 AFB20018 */  sw        $s2, 0x18($sp)
/* D8C30C 80240F5C 0080902D */  daddu     $s2, $a0, $zero
/* D8C310 80240F60 AFBF001C */  sw        $ra, 0x1c($sp)
/* D8C314 80240F64 AFB10014 */  sw        $s1, 0x14($sp)
/* D8C318 80240F68 AFB00010 */  sw        $s0, 0x10($sp)
/* D8C31C 80240F6C 8E50000C */  lw        $s0, 0xc($s2)
/* D8C320 80240F70 8E050000 */  lw        $a1, ($s0)
/* D8C324 80240F74 0C0B1EAF */  jal       get_variable
/* D8C328 80240F78 26100004 */   addiu    $s0, $s0, 4
/* D8C32C 80240F7C 0C04417A */  jal       get_entity_by_index
/* D8C330 80240F80 0040202D */   daddu    $a0, $v0, $zero
/* D8C334 80240F84 8E050000 */  lw        $a1, ($s0)
/* D8C338 80240F88 26100004 */  addiu     $s0, $s0, 4
/* D8C33C 80240F8C 0040882D */  daddu     $s1, $v0, $zero
/* D8C340 80240F90 C6200048 */  lwc1      $f0, 0x48($s1)
/* D8C344 80240F94 4600008D */  trunc.w.s $f2, $f0
/* D8C348 80240F98 44061000 */  mfc1      $a2, $f2
/* D8C34C 80240F9C 0C0B2026 */  jal       set_variable
/* D8C350 80240FA0 0240202D */   daddu    $a0, $s2, $zero
/* D8C354 80240FA4 8E050000 */  lw        $a1, ($s0)
/* D8C358 80240FA8 26100004 */  addiu     $s0, $s0, 4
/* D8C35C 80240FAC C620004C */  lwc1      $f0, 0x4c($s1)
/* D8C360 80240FB0 4600008D */  trunc.w.s $f2, $f0
/* D8C364 80240FB4 44061000 */  mfc1      $a2, $f2
/* D8C368 80240FB8 0C0B2026 */  jal       set_variable
/* D8C36C 80240FBC 0240202D */   daddu    $a0, $s2, $zero
/* D8C370 80240FC0 C6200050 */  lwc1      $f0, 0x50($s1)
/* D8C374 80240FC4 8E050000 */  lw        $a1, ($s0)
/* D8C378 80240FC8 4600008D */  trunc.w.s $f2, $f0
/* D8C37C 80240FCC 44061000 */  mfc1      $a2, $f2
/* D8C380 80240FD0 0C0B2026 */  jal       set_variable
/* D8C384 80240FD4 0240202D */   daddu    $a0, $s2, $zero
/* D8C388 80240FD8 8FBF001C */  lw        $ra, 0x1c($sp)
/* D8C38C 80240FDC 8FB20018 */  lw        $s2, 0x18($sp)
/* D8C390 80240FE0 8FB10014 */  lw        $s1, 0x14($sp)
/* D8C394 80240FE4 8FB00010 */  lw        $s0, 0x10($sp)
/* D8C398 80240FE8 24020002 */  addiu     $v0, $zero, 2
/* D8C39C 80240FEC 03E00008 */  jr        $ra
/* D8C3A0 80240FF0 27BD0020 */   addiu    $sp, $sp, 0x20
/* D8C3A4 80240FF4 00000000 */  nop       
/* D8C3A8 80240FF8 00000000 */  nop       
/* D8C3AC 80240FFC 00000000 */  nop       
