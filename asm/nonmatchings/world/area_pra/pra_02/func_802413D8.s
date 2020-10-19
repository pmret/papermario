.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802413D8
/* D513C8 802413D8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D513CC 802413DC AFB20018 */  sw        $s2, 0x18($sp)
/* D513D0 802413E0 0080902D */  daddu     $s2, $a0, $zero
/* D513D4 802413E4 AFBF001C */  sw        $ra, 0x1c($sp)
/* D513D8 802413E8 AFB10014 */  sw        $s1, 0x14($sp)
/* D513DC 802413EC AFB00010 */  sw        $s0, 0x10($sp)
/* D513E0 802413F0 8E50000C */  lw        $s0, 0xc($s2)
/* D513E4 802413F4 8E050000 */  lw        $a1, ($s0)
/* D513E8 802413F8 0C0B1EAF */  jal       get_variable
/* D513EC 802413FC 26100004 */   addiu    $s0, $s0, 4
/* D513F0 80241400 0C04417A */  jal       get_entity_by_index
/* D513F4 80241404 0040202D */   daddu    $a0, $v0, $zero
/* D513F8 80241408 8E050000 */  lw        $a1, ($s0)
/* D513FC 8024140C 26100004 */  addiu     $s0, $s0, 4
/* D51400 80241410 0040882D */  daddu     $s1, $v0, $zero
/* D51404 80241414 C6200048 */  lwc1      $f0, 0x48($s1)
/* D51408 80241418 4600008D */  trunc.w.s $f2, $f0
/* D5140C 8024141C 44061000 */  mfc1      $a2, $f2
/* D51410 80241420 0C0B2026 */  jal       set_variable
/* D51414 80241424 0240202D */   daddu    $a0, $s2, $zero
/* D51418 80241428 8E050000 */  lw        $a1, ($s0)
/* D5141C 8024142C 26100004 */  addiu     $s0, $s0, 4
/* D51420 80241430 C620004C */  lwc1      $f0, 0x4c($s1)
/* D51424 80241434 4600008D */  trunc.w.s $f2, $f0
/* D51428 80241438 44061000 */  mfc1      $a2, $f2
/* D5142C 8024143C 0C0B2026 */  jal       set_variable
/* D51430 80241440 0240202D */   daddu    $a0, $s2, $zero
/* D51434 80241444 C6200050 */  lwc1      $f0, 0x50($s1)
/* D51438 80241448 8E050000 */  lw        $a1, ($s0)
/* D5143C 8024144C 4600008D */  trunc.w.s $f2, $f0
/* D51440 80241450 44061000 */  mfc1      $a2, $f2
/* D51444 80241454 0C0B2026 */  jal       set_variable
/* D51448 80241458 0240202D */   daddu    $a0, $s2, $zero
/* D5144C 8024145C 8FBF001C */  lw        $ra, 0x1c($sp)
/* D51450 80241460 8FB20018 */  lw        $s2, 0x18($sp)
/* D51454 80241464 8FB10014 */  lw        $s1, 0x14($sp)
/* D51458 80241468 8FB00010 */  lw        $s0, 0x10($sp)
/* D5145C 8024146C 24020002 */  addiu     $v0, $zero, 2
/* D51460 80241470 03E00008 */  jr        $ra
/* D51464 80241474 27BD0020 */   addiu    $sp, $sp, 0x20
