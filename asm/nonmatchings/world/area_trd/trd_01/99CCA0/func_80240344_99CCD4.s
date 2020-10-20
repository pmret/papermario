.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240344_99CCD4
/* 99CCD4 80240344 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 99CCD8 80240348 AFB20018 */  sw        $s2, 0x18($sp)
/* 99CCDC 8024034C 0080902D */  daddu     $s2, $a0, $zero
/* 99CCE0 80240350 AFBF001C */  sw        $ra, 0x1c($sp)
/* 99CCE4 80240354 AFB10014 */  sw        $s1, 0x14($sp)
/* 99CCE8 80240358 AFB00010 */  sw        $s0, 0x10($sp)
/* 99CCEC 8024035C 8E50000C */  lw        $s0, 0xc($s2)
/* 99CCF0 80240360 8E050000 */  lw        $a1, ($s0)
/* 99CCF4 80240364 0C0B1EAF */  jal       get_variable
/* 99CCF8 80240368 26100004 */   addiu    $s0, $s0, 4
/* 99CCFC 8024036C 0C04417A */  jal       get_entity_by_index
/* 99CD00 80240370 0040202D */   daddu    $a0, $v0, $zero
/* 99CD04 80240374 8E050000 */  lw        $a1, ($s0)
/* 99CD08 80240378 26100004 */  addiu     $s0, $s0, 4
/* 99CD0C 8024037C 0040882D */  daddu     $s1, $v0, $zero
/* 99CD10 80240380 C6200048 */  lwc1      $f0, 0x48($s1)
/* 99CD14 80240384 4600008D */  trunc.w.s $f2, $f0
/* 99CD18 80240388 44061000 */  mfc1      $a2, $f2
/* 99CD1C 8024038C 0C0B2026 */  jal       set_variable
/* 99CD20 80240390 0240202D */   daddu    $a0, $s2, $zero
/* 99CD24 80240394 8E050000 */  lw        $a1, ($s0)
/* 99CD28 80240398 26100004 */  addiu     $s0, $s0, 4
/* 99CD2C 8024039C C620004C */  lwc1      $f0, 0x4c($s1)
/* 99CD30 802403A0 4600008D */  trunc.w.s $f2, $f0
/* 99CD34 802403A4 44061000 */  mfc1      $a2, $f2
/* 99CD38 802403A8 0C0B2026 */  jal       set_variable
/* 99CD3C 802403AC 0240202D */   daddu    $a0, $s2, $zero
/* 99CD40 802403B0 C6200050 */  lwc1      $f0, 0x50($s1)
/* 99CD44 802403B4 8E050000 */  lw        $a1, ($s0)
/* 99CD48 802403B8 4600008D */  trunc.w.s $f2, $f0
/* 99CD4C 802403BC 44061000 */  mfc1      $a2, $f2
/* 99CD50 802403C0 0C0B2026 */  jal       set_variable
/* 99CD54 802403C4 0240202D */   daddu    $a0, $s2, $zero
/* 99CD58 802403C8 8FBF001C */  lw        $ra, 0x1c($sp)
/* 99CD5C 802403CC 8FB20018 */  lw        $s2, 0x18($sp)
/* 99CD60 802403D0 8FB10014 */  lw        $s1, 0x14($sp)
/* 99CD64 802403D4 8FB00010 */  lw        $s0, 0x10($sp)
/* 99CD68 802403D8 24020002 */  addiu     $v0, $zero, 2
/* 99CD6C 802403DC 03E00008 */  jr        $ra
/* 99CD70 802403E0 27BD0020 */   addiu    $sp, $sp, 0x20
/* 99CD74 802403E4 00000000 */  nop       
/* 99CD78 802403E8 00000000 */  nop       
/* 99CD7C 802403EC 00000000 */  nop       
