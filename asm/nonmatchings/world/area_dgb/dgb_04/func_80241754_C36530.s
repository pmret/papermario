.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241754_C37C84
/* C37C84 80241754 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* C37C88 80241758 AFB20020 */  sw        $s2, 0x20($sp)
/* C37C8C 8024175C 0080902D */  daddu     $s2, $a0, $zero
/* C37C90 80241760 AFBF0024 */  sw        $ra, 0x24($sp)
/* C37C94 80241764 AFB1001C */  sw        $s1, 0x1c($sp)
/* C37C98 80241768 AFB00018 */  sw        $s0, 0x18($sp)
/* C37C9C 8024176C 8E500148 */  lw        $s0, 0x148($s2)
/* C37CA0 80241770 0C00EABB */  jal       get_npc_unsafe
/* C37CA4 80241774 86040008 */   lh       $a0, 8($s0)
/* C37CA8 80241778 0040882D */  daddu     $s1, $v0, $zero
/* C37CAC 8024177C 8E02006C */  lw        $v0, 0x6c($s0)
/* C37CB0 80241780 3C03800F */  lui       $v1, %hi(gPlayerStatusPtr)
/* C37CB4 80241784 8C637B30 */  lw        $v1, %lo(gPlayerStatusPtr)($v1)
/* C37CB8 80241788 34420100 */  ori       $v0, $v0, 0x100
/* C37CBC 8024178C AE02006C */  sw        $v0, 0x6c($s0)
/* C37CC0 80241790 C4600028 */  lwc1      $f0, 0x28($v1)
/* C37CC4 80241794 E6200038 */  swc1      $f0, 0x38($s1)
/* C37CC8 80241798 C4600030 */  lwc1      $f0, 0x30($v1)
/* C37CCC 8024179C E6200040 */  swc1      $f0, 0x40($s1)
/* C37CD0 802417A0 8E03006C */  lw        $v1, 0x6c($s0)
/* C37CD4 802417A4 30621000 */  andi      $v0, $v1, 0x1000
/* C37CD8 802417A8 14400003 */  bnez      $v0, .L802417B8
/* C37CDC 802417AC 3C048000 */   lui      $a0, 0x8000
/* C37CE0 802417B0 34621000 */  ori       $v0, $v1, 0x1000
/* C37CE4 802417B4 AE02006C */  sw        $v0, 0x6c($s0)
.L802417B8:
/* C37CE8 802417B8 C6200040 */  lwc1      $f0, 0x40($s1)
/* C37CEC 802417BC 34840011 */  ori       $a0, $a0, 0x11
/* C37CF0 802417C0 E7A00010 */  swc1      $f0, 0x10($sp)
/* C37CF4 802417C4 8E260038 */  lw        $a2, 0x38($s1)
/* C37CF8 802417C8 8E27003C */  lw        $a3, 0x3c($s1)
/* C37CFC 802417CC 0C052757 */  jal       play_sound_at_position
/* C37D00 802417D0 24050002 */   addiu    $a1, $zero, 2
/* C37D04 802417D4 2402000F */  addiu     $v0, $zero, 0xf
/* C37D08 802417D8 A620008E */  sh        $zero, 0x8e($s1)
/* C37D0C 802417DC AE420070 */  sw        $v0, 0x70($s2)
/* C37D10 802417E0 8FBF0024 */  lw        $ra, 0x24($sp)
/* C37D14 802417E4 8FB20020 */  lw        $s2, 0x20($sp)
/* C37D18 802417E8 8FB1001C */  lw        $s1, 0x1c($sp)
/* C37D1C 802417EC 8FB00018 */  lw        $s0, 0x18($sp)
/* C37D20 802417F0 03E00008 */  jr        $ra
/* C37D24 802417F4 27BD0028 */   addiu    $sp, $sp, 0x28
