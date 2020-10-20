.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802403D8_C9C6D8
/* C9C6D8 802403D8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C9C6DC 802403DC AFB20018 */  sw        $s2, 0x18($sp)
/* C9C6E0 802403E0 0080902D */  daddu     $s2, $a0, $zero
/* C9C6E4 802403E4 AFBF001C */  sw        $ra, 0x1c($sp)
/* C9C6E8 802403E8 AFB10014 */  sw        $s1, 0x14($sp)
/* C9C6EC 802403EC AFB00010 */  sw        $s0, 0x10($sp)
/* C9C6F0 802403F0 8E50000C */  lw        $s0, 0xc($s2)
/* C9C6F4 802403F4 8E050000 */  lw        $a1, ($s0)
/* C9C6F8 802403F8 0C0B1EAF */  jal       get_variable
/* C9C6FC 802403FC 26100004 */   addiu    $s0, $s0, 4
/* C9C700 80240400 0C04417A */  jal       get_entity_by_index
/* C9C704 80240404 0040202D */   daddu    $a0, $v0, $zero
/* C9C708 80240408 8E050000 */  lw        $a1, ($s0)
/* C9C70C 8024040C 26100004 */  addiu     $s0, $s0, 4
/* C9C710 80240410 0040882D */  daddu     $s1, $v0, $zero
/* C9C714 80240414 C6200048 */  lwc1      $f0, 0x48($s1)
/* C9C718 80240418 4600008D */  trunc.w.s $f2, $f0
/* C9C71C 8024041C 44061000 */  mfc1      $a2, $f2
/* C9C720 80240420 0C0B2026 */  jal       set_variable
/* C9C724 80240424 0240202D */   daddu    $a0, $s2, $zero
/* C9C728 80240428 8E050000 */  lw        $a1, ($s0)
/* C9C72C 8024042C 26100004 */  addiu     $s0, $s0, 4
/* C9C730 80240430 C620004C */  lwc1      $f0, 0x4c($s1)
/* C9C734 80240434 4600008D */  trunc.w.s $f2, $f0
/* C9C738 80240438 44061000 */  mfc1      $a2, $f2
/* C9C73C 8024043C 0C0B2026 */  jal       set_variable
/* C9C740 80240440 0240202D */   daddu    $a0, $s2, $zero
/* C9C744 80240444 C6200050 */  lwc1      $f0, 0x50($s1)
/* C9C748 80240448 8E050000 */  lw        $a1, ($s0)
/* C9C74C 8024044C 4600008D */  trunc.w.s $f2, $f0
/* C9C750 80240450 44061000 */  mfc1      $a2, $f2
/* C9C754 80240454 0C0B2026 */  jal       set_variable
/* C9C758 80240458 0240202D */   daddu    $a0, $s2, $zero
/* C9C75C 8024045C 8FBF001C */  lw        $ra, 0x1c($sp)
/* C9C760 80240460 8FB20018 */  lw        $s2, 0x18($sp)
/* C9C764 80240464 8FB10014 */  lw        $s1, 0x14($sp)
/* C9C768 80240468 8FB00010 */  lw        $s0, 0x10($sp)
/* C9C76C 8024046C 24020002 */  addiu     $v0, $zero, 2
/* C9C770 80240470 03E00008 */  jr        $ra
/* C9C774 80240474 27BD0020 */   addiu    $sp, $sp, 0x20
