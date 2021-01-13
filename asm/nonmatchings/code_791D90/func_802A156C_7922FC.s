.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A156C_7922FC
/* 7922FC 802A156C 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 792300 802A1570 AFB1001C */  sw        $s1, 0x1c($sp)
/* 792304 802A1574 0080882D */  daddu     $s1, $a0, $zero
/* 792308 802A1578 AFBF0028 */  sw        $ra, 0x28($sp)
/* 79230C 802A157C AFB30024 */  sw        $s3, 0x24($sp)
/* 792310 802A1580 AFB20020 */  sw        $s2, 0x20($sp)
/* 792314 802A1584 AFB00018 */  sw        $s0, 0x18($sp)
/* 792318 802A1588 8E30000C */  lw        $s0, 0xc($s1)
/* 79231C 802A158C 8E050000 */  lw        $a1, ($s0)
/* 792320 802A1590 0C0B1EAF */  jal       get_variable
/* 792324 802A1594 26100004 */   addiu    $s0, $s0, 4
/* 792328 802A1598 8E050000 */  lw        $a1, ($s0)
/* 79232C 802A159C 26100004 */  addiu     $s0, $s0, 4
/* 792330 802A15A0 0220202D */  daddu     $a0, $s1, $zero
/* 792334 802A15A4 0C0B1EAF */  jal       get_variable
/* 792338 802A15A8 0040982D */   daddu    $s3, $v0, $zero
/* 79233C 802A15AC 8E050000 */  lw        $a1, ($s0)
/* 792340 802A15B0 26100004 */  addiu     $s0, $s0, 4
/* 792344 802A15B4 0220202D */  daddu     $a0, $s1, $zero
/* 792348 802A15B8 0C0B1EAF */  jal       get_variable
/* 79234C 802A15BC 0040902D */   daddu    $s2, $v0, $zero
/* 792350 802A15C0 0220202D */  daddu     $a0, $s1, $zero
/* 792354 802A15C4 8E050000 */  lw        $a1, ($s0)
/* 792358 802A15C8 0C0B1EAF */  jal       get_variable
/* 79235C 802A15CC 0040802D */   daddu    $s0, $v0, $zero
/* 792360 802A15D0 44930000 */  mtc1      $s3, $f0
/* 792364 802A15D4 00000000 */  nop
/* 792368 802A15D8 46800020 */  cvt.s.w   $f0, $f0
/* 79236C 802A15DC 44050000 */  mfc1      $a1, $f0
/* 792370 802A15E0 44920000 */  mtc1      $s2, $f0
/* 792374 802A15E4 00000000 */  nop
/* 792378 802A15E8 46800020 */  cvt.s.w   $f0, $f0
/* 79237C 802A15EC 44060000 */  mfc1      $a2, $f0
/* 792380 802A15F0 44900000 */  mtc1      $s0, $f0
/* 792384 802A15F4 00000000 */  nop
/* 792388 802A15F8 46800020 */  cvt.s.w   $f0, $f0
/* 79238C 802A15FC 44070000 */  mfc1      $a3, $f0
/* 792390 802A1600 0000202D */  daddu     $a0, $zero, $zero
/* 792394 802A1604 0C01C424 */  jal       func_80071090
/* 792398 802A1608 AFA20010 */   sw       $v0, 0x10($sp)
/* 79239C 802A160C 8FBF0028 */  lw        $ra, 0x28($sp)
/* 7923A0 802A1610 8FB30024 */  lw        $s3, 0x24($sp)
/* 7923A4 802A1614 8FB20020 */  lw        $s2, 0x20($sp)
/* 7923A8 802A1618 8FB1001C */  lw        $s1, 0x1c($sp)
/* 7923AC 802A161C 8FB00018 */  lw        $s0, 0x18($sp)
/* 7923B0 802A1620 24020002 */  addiu     $v0, $zero, 2
/* 7923B4 802A1624 03E00008 */  jr        $ra
/* 7923B8 802A1628 27BD0030 */   addiu    $sp, $sp, 0x30
/* 7923BC 802A162C 00000000 */  nop
