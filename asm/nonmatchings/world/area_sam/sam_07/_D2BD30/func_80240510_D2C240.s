.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240510_D2C240
/* D2C240 80240510 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D2C244 80240514 AFB20018 */  sw        $s2, 0x18($sp)
/* D2C248 80240518 0080902D */  daddu     $s2, $a0, $zero
/* D2C24C 8024051C AFBF001C */  sw        $ra, 0x1c($sp)
/* D2C250 80240520 AFB10014 */  sw        $s1, 0x14($sp)
/* D2C254 80240524 AFB00010 */  sw        $s0, 0x10($sp)
/* D2C258 80240528 8E50000C */  lw        $s0, 0xc($s2)
/* D2C25C 8024052C 8E050000 */  lw        $a1, ($s0)
/* D2C260 80240530 0C0B1EAF */  jal       get_variable
/* D2C264 80240534 26100004 */   addiu    $s0, $s0, 4
/* D2C268 80240538 0C04417A */  jal       get_entity_by_index
/* D2C26C 8024053C 0040202D */   daddu    $a0, $v0, $zero
/* D2C270 80240540 8E050000 */  lw        $a1, ($s0)
/* D2C274 80240544 26100004 */  addiu     $s0, $s0, 4
/* D2C278 80240548 0040882D */  daddu     $s1, $v0, $zero
/* D2C27C 8024054C C6200048 */  lwc1      $f0, 0x48($s1)
/* D2C280 80240550 4600008D */  trunc.w.s $f2, $f0
/* D2C284 80240554 44061000 */  mfc1      $a2, $f2
/* D2C288 80240558 0C0B2026 */  jal       set_variable
/* D2C28C 8024055C 0240202D */   daddu    $a0, $s2, $zero
/* D2C290 80240560 8E050000 */  lw        $a1, ($s0)
/* D2C294 80240564 26100004 */  addiu     $s0, $s0, 4
/* D2C298 80240568 C620004C */  lwc1      $f0, 0x4c($s1)
/* D2C29C 8024056C 4600008D */  trunc.w.s $f2, $f0
/* D2C2A0 80240570 44061000 */  mfc1      $a2, $f2
/* D2C2A4 80240574 0C0B2026 */  jal       set_variable
/* D2C2A8 80240578 0240202D */   daddu    $a0, $s2, $zero
/* D2C2AC 8024057C C6200050 */  lwc1      $f0, 0x50($s1)
/* D2C2B0 80240580 8E050000 */  lw        $a1, ($s0)
/* D2C2B4 80240584 4600008D */  trunc.w.s $f2, $f0
/* D2C2B8 80240588 44061000 */  mfc1      $a2, $f2
/* D2C2BC 8024058C 0C0B2026 */  jal       set_variable
/* D2C2C0 80240590 0240202D */   daddu    $a0, $s2, $zero
/* D2C2C4 80240594 8FBF001C */  lw        $ra, 0x1c($sp)
/* D2C2C8 80240598 8FB20018 */  lw        $s2, 0x18($sp)
/* D2C2CC 8024059C 8FB10014 */  lw        $s1, 0x14($sp)
/* D2C2D0 802405A0 8FB00010 */  lw        $s0, 0x10($sp)
/* D2C2D4 802405A4 24020002 */  addiu     $v0, $zero, 2
/* D2C2D8 802405A8 03E00008 */  jr        $ra
/* D2C2DC 802405AC 27BD0020 */   addiu    $sp, $sp, 0x20
