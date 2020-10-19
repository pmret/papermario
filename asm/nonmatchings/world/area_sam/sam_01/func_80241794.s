.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241794
/* CF9304 80241794 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* CF9308 80241798 AFB10014 */  sw        $s1, 0x14($sp)
/* CF930C 8024179C 0080882D */  daddu     $s1, $a0, $zero
/* CF9310 802417A0 AFBF0018 */  sw        $ra, 0x18($sp)
/* CF9314 802417A4 AFB00010 */  sw        $s0, 0x10($sp)
/* CF9318 802417A8 8E30000C */  lw        $s0, 0xc($s1)
/* CF931C 802417AC 8E050000 */  lw        $a1, ($s0)
/* CF9320 802417B0 0C0B1EAF */  jal       get_variable
/* CF9324 802417B4 26100004 */   addiu    $s0, $s0, 4
/* CF9328 802417B8 AE22008C */  sw        $v0, 0x8c($s1)
/* CF932C 802417BC 8E050000 */  lw        $a1, ($s0)
/* CF9330 802417C0 26100004 */  addiu     $s0, $s0, 4
/* CF9334 802417C4 0C0B1EAF */  jal       get_variable
/* CF9338 802417C8 0220202D */   daddu    $a0, $s1, $zero
/* CF933C 802417CC AE220090 */  sw        $v0, 0x90($s1)
/* CF9340 802417D0 8E050000 */  lw        $a1, ($s0)
/* CF9344 802417D4 26100004 */  addiu     $s0, $s0, 4
/* CF9348 802417D8 0C0B1EAF */  jal       get_variable
/* CF934C 802417DC 0220202D */   daddu    $a0, $s1, $zero
/* CF9350 802417E0 AE220094 */  sw        $v0, 0x94($s1)
/* CF9354 802417E4 8E050000 */  lw        $a1, ($s0)
/* CF9358 802417E8 26100004 */  addiu     $s0, $s0, 4
/* CF935C 802417EC 0C0B1EAF */  jal       get_variable
/* CF9360 802417F0 0220202D */   daddu    $a0, $s1, $zero
/* CF9364 802417F4 AE220098 */  sw        $v0, 0x98($s1)
/* CF9368 802417F8 8E050000 */  lw        $a1, ($s0)
/* CF936C 802417FC 26100004 */  addiu     $s0, $s0, 4
/* CF9370 80241800 0C0B1EAF */  jal       get_variable
/* CF9374 80241804 0220202D */   daddu    $a0, $s1, $zero
/* CF9378 80241808 AE22009C */  sw        $v0, 0x9c($s1)
/* CF937C 8024180C 8E050000 */  lw        $a1, ($s0)
/* CF9380 80241810 26100004 */  addiu     $s0, $s0, 4
/* CF9384 80241814 0C0B1EAF */  jal       get_variable
/* CF9388 80241818 0220202D */   daddu    $a0, $s1, $zero
/* CF938C 8024181C AE2200A0 */  sw        $v0, 0xa0($s1)
/* CF9390 80241820 8E050000 */  lw        $a1, ($s0)
/* CF9394 80241824 26100004 */  addiu     $s0, $s0, 4
/* CF9398 80241828 0C0B1EAF */  jal       get_variable
/* CF939C 8024182C 0220202D */   daddu    $a0, $s1, $zero
/* CF93A0 80241830 AE2200A4 */  sw        $v0, 0xa4($s1)
/* CF93A4 80241834 8E050000 */  lw        $a1, ($s0)
/* CF93A8 80241838 26100004 */  addiu     $s0, $s0, 4
/* CF93AC 8024183C 0C0B1EAF */  jal       get_variable
/* CF93B0 80241840 0220202D */   daddu    $a0, $s1, $zero
/* CF93B4 80241844 AE2200A8 */  sw        $v0, 0xa8($s1)
/* CF93B8 80241848 8E050000 */  lw        $a1, ($s0)
/* CF93BC 8024184C 26100004 */  addiu     $s0, $s0, 4
/* CF93C0 80241850 0C0B1EAF */  jal       get_variable
/* CF93C4 80241854 0220202D */   daddu    $a0, $s1, $zero
/* CF93C8 80241858 AE2200AC */  sw        $v0, 0xac($s1)
/* CF93CC 8024185C 8E050000 */  lw        $a1, ($s0)
/* CF93D0 80241860 0C0B1EAF */  jal       get_variable
/* CF93D4 80241864 0220202D */   daddu    $a0, $s1, $zero
/* CF93D8 80241868 AE2200B0 */  sw        $v0, 0xb0($s1)
/* CF93DC 8024186C 8FBF0018 */  lw        $ra, 0x18($sp)
/* CF93E0 80241870 8FB10014 */  lw        $s1, 0x14($sp)
/* CF93E4 80241874 8FB00010 */  lw        $s0, 0x10($sp)
/* CF93E8 80241878 24020002 */  addiu     $v0, $zero, 2
/* CF93EC 8024187C 03E00008 */  jr        $ra
/* CF93F0 80241880 27BD0020 */   addiu    $sp, $sp, 0x20
