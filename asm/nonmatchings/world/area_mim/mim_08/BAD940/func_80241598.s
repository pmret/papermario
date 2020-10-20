.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241598
/* BAEED8 80241598 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BAEEDC 8024159C AFB10014 */  sw        $s1, 0x14($sp)
/* BAEEE0 802415A0 0080882D */  daddu     $s1, $a0, $zero
/* BAEEE4 802415A4 AFBF0018 */  sw        $ra, 0x18($sp)
/* BAEEE8 802415A8 AFB00010 */  sw        $s0, 0x10($sp)
/* BAEEEC 802415AC 8E300148 */  lw        $s0, 0x148($s1)
/* BAEEF0 802415B0 0C00EABB */  jal       get_npc_unsafe
/* BAEEF4 802415B4 86040008 */   lh       $a0, 8($s0)
/* BAEEF8 802415B8 24030001 */  addiu     $v1, $zero, 1
/* BAEEFC 802415BC 0040202D */  daddu     $a0, $v0, $zero
/* BAEF00 802415C0 AE03006C */  sw        $v1, 0x6c($s0)
/* BAEF04 802415C4 8482008C */  lh        $v0, 0x8c($a0)
/* BAEF08 802415C8 14400009 */  bnez      $v0, .L802415F0
/* BAEF0C 802415CC 24020002 */   addiu    $v0, $zero, 2
/* BAEF10 802415D0 96030072 */  lhu       $v1, 0x72($s0)
/* BAEF14 802415D4 AE02006C */  sw        $v0, 0x6c($s0)
/* BAEF18 802415D8 A483008E */  sh        $v1, 0x8e($a0)
/* BAEF1C 802415DC 8E0200CC */  lw        $v0, 0xcc($s0)
/* BAEF20 802415E0 8C420020 */  lw        $v0, 0x20($v0)
/* BAEF24 802415E4 AC820028 */  sw        $v0, 0x28($a0)
/* BAEF28 802415E8 2402001F */  addiu     $v0, $zero, 0x1f
/* BAEF2C 802415EC AE220070 */  sw        $v0, 0x70($s1)
.L802415F0:
/* BAEF30 802415F0 8FBF0018 */  lw        $ra, 0x18($sp)
/* BAEF34 802415F4 8FB10014 */  lw        $s1, 0x14($sp)
/* BAEF38 802415F8 8FB00010 */  lw        $s0, 0x10($sp)
/* BAEF3C 802415FC 03E00008 */  jr        $ra
/* BAEF40 80241600 27BD0020 */   addiu    $sp, $sp, 0x20
