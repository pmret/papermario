.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B48_B452B8
/* B452B8 80240B48 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B452BC 80240B4C AFB20018 */  sw        $s2, 0x18($sp)
/* B452C0 80240B50 0080902D */  daddu     $s2, $a0, $zero
/* B452C4 80240B54 AFBF001C */  sw        $ra, 0x1c($sp)
/* B452C8 80240B58 AFB10014 */  sw        $s1, 0x14($sp)
/* B452CC 80240B5C AFB00010 */  sw        $s0, 0x10($sp)
/* B452D0 80240B60 8E50000C */  lw        $s0, 0xc($s2)
/* B452D4 80240B64 8E050000 */  lw        $a1, ($s0)
/* B452D8 80240B68 0C0B1EAF */  jal       get_variable
/* B452DC 80240B6C 26100004 */   addiu    $s0, $s0, 4
/* B452E0 80240B70 0C04417A */  jal       get_entity_by_index
/* B452E4 80240B74 0040202D */   daddu    $a0, $v0, $zero
/* B452E8 80240B78 8E050000 */  lw        $a1, ($s0)
/* B452EC 80240B7C 26100004 */  addiu     $s0, $s0, 4
/* B452F0 80240B80 0040882D */  daddu     $s1, $v0, $zero
/* B452F4 80240B84 C6200048 */  lwc1      $f0, 0x48($s1)
/* B452F8 80240B88 4600008D */  trunc.w.s $f2, $f0
/* B452FC 80240B8C 44061000 */  mfc1      $a2, $f2
/* B45300 80240B90 0C0B2026 */  jal       set_variable
/* B45304 80240B94 0240202D */   daddu    $a0, $s2, $zero
/* B45308 80240B98 8E050000 */  lw        $a1, ($s0)
/* B4530C 80240B9C 26100004 */  addiu     $s0, $s0, 4
/* B45310 80240BA0 C620004C */  lwc1      $f0, 0x4c($s1)
/* B45314 80240BA4 4600008D */  trunc.w.s $f2, $f0
/* B45318 80240BA8 44061000 */  mfc1      $a2, $f2
/* B4531C 80240BAC 0C0B2026 */  jal       set_variable
/* B45320 80240BB0 0240202D */   daddu    $a0, $s2, $zero
/* B45324 80240BB4 C6200050 */  lwc1      $f0, 0x50($s1)
/* B45328 80240BB8 8E050000 */  lw        $a1, ($s0)
/* B4532C 80240BBC 4600008D */  trunc.w.s $f2, $f0
/* B45330 80240BC0 44061000 */  mfc1      $a2, $f2
/* B45334 80240BC4 0C0B2026 */  jal       set_variable
/* B45338 80240BC8 0240202D */   daddu    $a0, $s2, $zero
/* B4533C 80240BCC 8FBF001C */  lw        $ra, 0x1c($sp)
/* B45340 80240BD0 8FB20018 */  lw        $s2, 0x18($sp)
/* B45344 80240BD4 8FB10014 */  lw        $s1, 0x14($sp)
/* B45348 80240BD8 8FB00010 */  lw        $s0, 0x10($sp)
/* B4534C 80240BDC 24020002 */  addiu     $v0, $zero, 2
/* B45350 80240BE0 03E00008 */  jr        $ra
/* B45354 80240BE4 27BD0020 */   addiu    $sp, $sp, 0x20
