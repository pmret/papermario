.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802414E8_BA1C18
/* BA1C18 802414E8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BA1C1C 802414EC AFB10014 */  sw        $s1, 0x14($sp)
/* BA1C20 802414F0 0080882D */  daddu     $s1, $a0, $zero
/* BA1C24 802414F4 AFBF0018 */  sw        $ra, 0x18($sp)
/* BA1C28 802414F8 AFB00010 */  sw        $s0, 0x10($sp)
/* BA1C2C 802414FC 8E300148 */  lw        $s0, 0x148($s1)
/* BA1C30 80241500 0C00EABB */  jal       get_npc_unsafe
/* BA1C34 80241504 86040008 */   lh       $a0, 8($s0)
/* BA1C38 80241508 0040202D */  daddu     $a0, $v0, $zero
/* BA1C3C 8024150C 9482008E */  lhu       $v0, 0x8e($a0)
/* BA1C40 80241510 2442FFFF */  addiu     $v0, $v0, -1
/* BA1C44 80241514 A482008E */  sh        $v0, 0x8e($a0)
/* BA1C48 80241518 00021400 */  sll       $v0, $v0, 0x10
/* BA1C4C 8024151C 8E030098 */  lw        $v1, 0x98($s0)
/* BA1C50 80241520 00021403 */  sra       $v0, $v0, 0x10
/* BA1C54 80241524 0062182A */  slt       $v1, $v1, $v0
/* BA1C58 80241528 14600005 */  bnez      $v1, .L80241540
/* BA1C5C 8024152C 3C03E0EF */   lui      $v1, 0xe0ef
/* BA1C60 80241530 8E020000 */  lw        $v0, ($s0)
/* BA1C64 80241534 3463FFFF */  ori       $v1, $v1, 0xffff
/* BA1C68 80241538 00431024 */  and       $v0, $v0, $v1
/* BA1C6C 8024153C AE020000 */  sw        $v0, ($s0)
.L80241540:
/* BA1C70 80241540 8482008E */  lh        $v0, 0x8e($a0)
/* BA1C74 80241544 14400007 */  bnez      $v0, .L80241564
/* BA1C78 80241548 00000000 */   nop      
/* BA1C7C 8024154C 8E0200CC */  lw        $v0, 0xcc($s0)
/* BA1C80 80241550 8C420028 */  lw        $v0, 0x28($v0)
/* BA1C84 80241554 A480008E */  sh        $zero, 0x8e($a0)
/* BA1C88 80241558 AC820028 */  sw        $v0, 0x28($a0)
/* BA1C8C 8024155C 2402000C */  addiu     $v0, $zero, 0xc
/* BA1C90 80241560 AE220070 */  sw        $v0, 0x70($s1)
.L80241564:
/* BA1C94 80241564 8FBF0018 */  lw        $ra, 0x18($sp)
/* BA1C98 80241568 8FB10014 */  lw        $s1, 0x14($sp)
/* BA1C9C 8024156C 8FB00010 */  lw        $s0, 0x10($sp)
/* BA1CA0 80241570 03E00008 */  jr        $ra
/* BA1CA4 80241574 27BD0020 */   addiu    $sp, $sp, 0x20
