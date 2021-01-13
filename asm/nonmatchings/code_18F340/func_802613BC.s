.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802613BC
/* 18FC9C 802613BC 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 18FCA0 802613C0 AFB1001C */  sw        $s1, 0x1c($sp)
/* 18FCA4 802613C4 0080882D */  daddu     $s1, $a0, $zero
/* 18FCA8 802613C8 AFBF0024 */  sw        $ra, 0x24($sp)
/* 18FCAC 802613CC AFB20020 */  sw        $s2, 0x20($sp)
/* 18FCB0 802613D0 AFB00018 */  sw        $s0, 0x18($sp)
/* 18FCB4 802613D4 8E30000C */  lw        $s0, 0xc($s1)
/* 18FCB8 802613D8 8E050000 */  lw        $a1, ($s0)
/* 18FCBC 802613DC 0C0B1EAF */  jal       get_variable
/* 18FCC0 802613E0 26100004 */   addiu    $s0, $s0, 4
/* 18FCC4 802613E4 8E050000 */  lw        $a1, ($s0)
/* 18FCC8 802613E8 26100004 */  addiu     $s0, $s0, 4
/* 18FCCC 802613EC 0220202D */  daddu     $a0, $s1, $zero
/* 18FCD0 802613F0 0C0B1EAF */  jal       get_variable
/* 18FCD4 802613F4 0040902D */   daddu    $s2, $v0, $zero
/* 18FCD8 802613F8 0220202D */  daddu     $a0, $s1, $zero
/* 18FCDC 802613FC 8E050000 */  lw        $a1, ($s0)
/* 18FCE0 80261400 0C0B1EAF */  jal       get_variable
/* 18FCE4 80261404 0040802D */   daddu    $s0, $v0, $zero
/* 18FCE8 80261408 24040006 */  addiu     $a0, $zero, 6
/* 18FCEC 8026140C 44921000 */  mtc1      $s2, $f2
/* 18FCF0 80261410 00000000 */  nop
/* 18FCF4 80261414 468010A0 */  cvt.s.w   $f2, $f2
/* 18FCF8 80261418 2610000F */  addiu     $s0, $s0, 0xf
/* 18FCFC 8026141C 44051000 */  mfc1      $a1, $f2
/* 18FD00 80261420 44901000 */  mtc1      $s0, $f2
/* 18FD04 80261424 00000000 */  nop
/* 18FD08 80261428 468010A0 */  cvt.s.w   $f2, $f2
/* 18FD0C 8026142C 44061000 */  mfc1      $a2, $f2
/* 18FD10 80261430 44821000 */  mtc1      $v0, $f2
/* 18FD14 80261434 00000000 */  nop
/* 18FD18 80261438 468010A0 */  cvt.s.w   $f2, $f2
/* 18FD1C 8026143C 3C013F99 */  lui       $at, 0x3f99
/* 18FD20 80261440 3421999A */  ori       $at, $at, 0x999a
/* 18FD24 80261444 44810000 */  mtc1      $at, $f0
/* 18FD28 80261448 44071000 */  mfc1      $a3, $f2
/* 18FD2C 8026144C 2403001E */  addiu     $v1, $zero, 0x1e
/* 18FD30 80261450 AFA30014 */  sw        $v1, 0x14($sp)
/* 18FD34 80261454 0C01C82C */  jal       func_800720B0
/* 18FD38 80261458 E7A00010 */   swc1     $f0, 0x10($sp)
/* 18FD3C 8026145C 8FBF0024 */  lw        $ra, 0x24($sp)
/* 18FD40 80261460 8FB20020 */  lw        $s2, 0x20($sp)
/* 18FD44 80261464 8FB1001C */  lw        $s1, 0x1c($sp)
/* 18FD48 80261468 8FB00018 */  lw        $s0, 0x18($sp)
/* 18FD4C 8026146C 24020002 */  addiu     $v0, $zero, 2
/* 18FD50 80261470 03E00008 */  jr        $ra
/* 18FD54 80261474 27BD0028 */   addiu    $sp, $sp, 0x28
