.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802404D0_EFEFD0
/* EFEFD0 802404D0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EFEFD4 802404D4 AFB00010 */  sw        $s0, 0x10($sp)
/* EFEFD8 802404D8 0080802D */  daddu     $s0, $a0, $zero
/* EFEFDC 802404DC AFB20018 */  sw        $s2, 0x18($sp)
/* EFEFE0 802404E0 3C128011 */  lui       $s2, %hi(D_80117578)
/* EFEFE4 802404E4 26527578 */  addiu     $s2, $s2, %lo(D_80117578)
/* EFEFE8 802404E8 AFBF001C */  sw        $ra, 0x1c($sp)
/* EFEFEC 802404EC AFB10014 */  sw        $s1, 0x14($sp)
/* EFEFF0 802404F0 C64000A8 */  lwc1      $f0, 0xa8($s2)
/* EFEFF4 802404F4 8E02000C */  lw        $v0, 0xc($s0)
/* EFEFF8 802404F8 4600008D */  trunc.w.s $f2, $f0
/* EFEFFC 802404FC 44061000 */  mfc1      $a2, $f2
/* EFF000 80240500 8C450000 */  lw        $a1, ($v0)
/* EFF004 80240504 0C0B551A */  jal       dead_evt_set_variable
/* EFF008 80240508 8C510004 */   lw       $s1, 4($v0)
/* EFF00C 8024050C 0200202D */  daddu     $a0, $s0, $zero
/* EFF010 80240510 C6400080 */  lwc1      $f0, 0x80($s2)
/* EFF014 80240514 4600008D */  trunc.w.s $f2, $f0
/* EFF018 80240518 44061000 */  mfc1      $a2, $f2
/* EFF01C 8024051C 0C0B551A */  jal       dead_evt_set_variable
/* EFF020 80240520 0220282D */   daddu    $a1, $s1, $zero
/* EFF024 80240524 8FBF001C */  lw        $ra, 0x1c($sp)
/* EFF028 80240528 8FB20018 */  lw        $s2, 0x18($sp)
/* EFF02C 8024052C 8FB10014 */  lw        $s1, 0x14($sp)
/* EFF030 80240530 8FB00010 */  lw        $s0, 0x10($sp)
/* EFF034 80240534 24020002 */  addiu     $v0, $zero, 2
/* EFF038 80240538 03E00008 */  jr        $ra
/* EFF03C 8024053C 27BD0020 */   addiu    $sp, $sp, 0x20
