.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802CD418
/* F1DC8 802CD418 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* F1DCC 802CD41C AFB10014 */  sw        $s1, 0x14($sp)
/* F1DD0 802CD420 0080882D */  daddu     $s1, $a0, $zero
/* F1DD4 802CD424 AFBF001C */  sw        $ra, 0x1c($sp)
/* F1DD8 802CD428 AFB20018 */  sw        $s2, 0x18($sp)
/* F1DDC 802CD42C AFB00010 */  sw        $s0, 0x10($sp)
/* F1DE0 802CD430 8E30000C */  lw        $s0, 0xc($s1)
/* F1DE4 802CD434 8E050000 */  lw        $a1, ($s0)
/* F1DE8 802CD438 0C0B1EAF */  jal       get_variable
/* F1DEC 802CD43C 26100004 */   addiu    $s0, $s0, 4
/* F1DF0 802CD440 0220202D */  daddu     $a0, $s1, $zero
/* F1DF4 802CD444 8E050004 */  lw        $a1, 4($s0)
/* F1DF8 802CD448 8E120000 */  lw        $s2, ($s0)
/* F1DFC 802CD44C 0C0B1EAF */  jal       get_variable
/* F1E00 802CD450 0040882D */   daddu    $s1, $v0, $zero
/* F1E04 802CD454 3C03802E */  lui       $v1, %hi(gCurrentMeshAnimationListPtr)
/* F1E08 802CD458 8C63AE30 */  lw        $v1, %lo(gCurrentMeshAnimationListPtr)($v1)
/* F1E0C 802CD45C 00118880 */  sll       $s1, $s1, 2
/* F1E10 802CD460 02238821 */  addu      $s1, $s1, $v1
/* F1E14 802CD464 8E230000 */  lw        $v1, ($s1)
/* F1E18 802CD468 8C640000 */  lw        $a0, ($v1)
/* F1E1C 802CD46C 0C047FF8 */  jal       func_8011FFE0
/* F1E20 802CD470 0040802D */   daddu    $s0, $v0, $zero
/* F1E24 802CD474 12000004 */  beqz      $s0, .L802CD488
/* F1E28 802CD478 0040202D */   daddu    $a0, $v0, $zero
/* F1E2C 802CD47C 8C820000 */  lw        $v0, ($a0)
/* F1E30 802CD480 080B3525 */  j         .L802CD494
/* F1E34 802CD484 00521025 */   or       $v0, $v0, $s2
.L802CD488:
/* F1E38 802CD488 8C820000 */  lw        $v0, ($a0)
/* F1E3C 802CD48C 00121827 */  nor       $v1, $zero, $s2
/* F1E40 802CD490 00431024 */  and       $v0, $v0, $v1
.L802CD494:
/* F1E44 802CD494 AC820000 */  sw        $v0, ($a0)
/* F1E48 802CD498 8FBF001C */  lw        $ra, 0x1c($sp)
/* F1E4C 802CD49C 8FB20018 */  lw        $s2, 0x18($sp)
/* F1E50 802CD4A0 8FB10014 */  lw        $s1, 0x14($sp)
/* F1E54 802CD4A4 8FB00010 */  lw        $s0, 0x10($sp)
/* F1E58 802CD4A8 24020002 */  addiu     $v0, $zero, 2
/* F1E5C 802CD4AC 03E00008 */  jr        $ra
/* F1E60 802CD4B0 27BD0020 */   addiu    $sp, $sp, 0x20
