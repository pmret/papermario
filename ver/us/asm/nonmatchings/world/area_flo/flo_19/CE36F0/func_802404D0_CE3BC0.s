.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802404D0_CE3BC0
/* CE3BC0 802404D0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* CE3BC4 802404D4 AFB00010 */  sw        $s0, 0x10($sp)
/* CE3BC8 802404D8 0080802D */  daddu     $s0, $a0, $zero
/* CE3BCC 802404DC AFB20018 */  sw        $s2, 0x18($sp)
/* CE3BD0 802404E0 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* CE3BD4 802404E4 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* CE3BD8 802404E8 AFBF001C */  sw        $ra, 0x1c($sp)
/* CE3BDC 802404EC AFB10014 */  sw        $s1, 0x14($sp)
/* CE3BE0 802404F0 C64000A8 */  lwc1      $f0, 0xa8($s2)
/* CE3BE4 802404F4 8E02000C */  lw        $v0, 0xc($s0)
/* CE3BE8 802404F8 4600008D */  trunc.w.s $f2, $f0
/* CE3BEC 802404FC 44061000 */  mfc1      $a2, $f2
/* CE3BF0 80240500 8C450000 */  lw        $a1, ($v0)
/* CE3BF4 80240504 0C0B2026 */  jal       set_variable
/* CE3BF8 80240508 8C510004 */   lw       $s1, 4($v0)
/* CE3BFC 8024050C 0200202D */  daddu     $a0, $s0, $zero
/* CE3C00 80240510 C6400080 */  lwc1      $f0, 0x80($s2)
/* CE3C04 80240514 4600008D */  trunc.w.s $f2, $f0
/* CE3C08 80240518 44061000 */  mfc1      $a2, $f2
/* CE3C0C 8024051C 0C0B2026 */  jal       set_variable
/* CE3C10 80240520 0220282D */   daddu    $a1, $s1, $zero
/* CE3C14 80240524 8FBF001C */  lw        $ra, 0x1c($sp)
/* CE3C18 80240528 8FB20018 */  lw        $s2, 0x18($sp)
/* CE3C1C 8024052C 8FB10014 */  lw        $s1, 0x14($sp)
/* CE3C20 80240530 8FB00010 */  lw        $s0, 0x10($sp)
/* CE3C24 80240534 24020002 */  addiu     $v0, $zero, 2
/* CE3C28 80240538 03E00008 */  jr        $ra
/* CE3C2C 8024053C 27BD0020 */   addiu    $sp, $sp, 0x20
