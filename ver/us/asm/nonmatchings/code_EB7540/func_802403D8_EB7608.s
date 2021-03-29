.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802403D8_EB7608
/* EB7608 802403D8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EB760C 802403DC AFB20018 */  sw        $s2, 0x18($sp)
/* EB7610 802403E0 0080902D */  daddu     $s2, $a0, $zero
/* EB7614 802403E4 AFBF001C */  sw        $ra, 0x1c($sp)
/* EB7618 802403E8 AFB10014 */  sw        $s1, 0x14($sp)
/* EB761C 802403EC AFB00010 */  sw        $s0, 0x10($sp)
/* EB7620 802403F0 8E50000C */  lw        $s0, 0xc($s2)
/* EB7624 802403F4 8E050000 */  lw        $a1, ($s0)
/* EB7628 802403F8 0C0B53A3 */  jal       dead_get_variable
/* EB762C 802403FC 26100004 */   addiu    $s0, $s0, 4
/* EB7630 80240400 0C0462EC */  jal       func_80118BB0
/* EB7634 80240404 0040202D */   daddu    $a0, $v0, $zero
/* EB7638 80240408 8E050000 */  lw        $a1, ($s0)
/* EB763C 8024040C 26100004 */  addiu     $s0, $s0, 4
/* EB7640 80240410 0040882D */  daddu     $s1, $v0, $zero
/* EB7644 80240414 C6200048 */  lwc1      $f0, 0x48($s1)
/* EB7648 80240418 4600008D */  trunc.w.s $f2, $f0
/* EB764C 8024041C 44061000 */  mfc1      $a2, $f2
/* EB7650 80240420 0C0B551A */  jal       dead_set_variable
/* EB7654 80240424 0240202D */   daddu    $a0, $s2, $zero
/* EB7658 80240428 8E050000 */  lw        $a1, ($s0)
/* EB765C 8024042C 26100004 */  addiu     $s0, $s0, 4
/* EB7660 80240430 C620004C */  lwc1      $f0, 0x4c($s1)
/* EB7664 80240434 4600008D */  trunc.w.s $f2, $f0
/* EB7668 80240438 44061000 */  mfc1      $a2, $f2
/* EB766C 8024043C 0C0B551A */  jal       dead_set_variable
/* EB7670 80240440 0240202D */   daddu    $a0, $s2, $zero
/* EB7674 80240444 C6200050 */  lwc1      $f0, 0x50($s1)
/* EB7678 80240448 8E050000 */  lw        $a1, ($s0)
/* EB767C 8024044C 4600008D */  trunc.w.s $f2, $f0
/* EB7680 80240450 44061000 */  mfc1      $a2, $f2
/* EB7684 80240454 0C0B551A */  jal       dead_set_variable
/* EB7688 80240458 0240202D */   daddu    $a0, $s2, $zero
/* EB768C 8024045C 8FBF001C */  lw        $ra, 0x1c($sp)
/* EB7690 80240460 8FB20018 */  lw        $s2, 0x18($sp)
/* EB7694 80240464 8FB10014 */  lw        $s1, 0x14($sp)
/* EB7698 80240468 8FB00010 */  lw        $s0, 0x10($sp)
/* EB769C 8024046C 24020002 */  addiu     $v0, $zero, 2
/* EB76A0 80240470 03E00008 */  jr        $ra
/* EB76A4 80240474 27BD0020 */   addiu    $sp, $sp, 0x20
