.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B54_B66604
/* B66604 80240B54 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B66608 80240B58 AFB10014 */  sw        $s1, 0x14($sp)
/* B6660C 80240B5C 0080882D */  daddu     $s1, $a0, $zero
/* B66610 80240B60 AFBF0018 */  sw        $ra, 0x18($sp)
/* B66614 80240B64 AFB00010 */  sw        $s0, 0x10($sp)
/* B66618 80240B68 8E300148 */  lw        $s0, 0x148($s1)
/* B6661C 80240B6C 0C00EABB */  jal       get_npc_unsafe
/* B66620 80240B70 86040008 */   lh       $a0, 8($s0)
/* B66624 80240B74 24030001 */  addiu     $v1, $zero, 1
/* B66628 80240B78 0040202D */  daddu     $a0, $v0, $zero
/* B6662C 80240B7C AE03006C */  sw        $v1, 0x6c($s0)
/* B66630 80240B80 8482008C */  lh        $v0, 0x8c($a0)
/* B66634 80240B84 14400009 */  bnez      $v0, .L80240BAC
/* B66638 80240B88 24020002 */   addiu    $v0, $zero, 2
/* B6663C 80240B8C 96030072 */  lhu       $v1, 0x72($s0)
/* B66640 80240B90 AE02006C */  sw        $v0, 0x6c($s0)
/* B66644 80240B94 A483008E */  sh        $v1, 0x8e($a0)
/* B66648 80240B98 8E0200CC */  lw        $v0, 0xcc($s0)
/* B6664C 80240B9C 8C420020 */  lw        $v0, 0x20($v0)
/* B66650 80240BA0 AC820028 */  sw        $v0, 0x28($a0)
/* B66654 80240BA4 2402001F */  addiu     $v0, $zero, 0x1f
/* B66658 80240BA8 AE220070 */  sw        $v0, 0x70($s1)
.L80240BAC:
/* B6665C 80240BAC 8FBF0018 */  lw        $ra, 0x18($sp)
/* B66660 80240BB0 8FB10014 */  lw        $s1, 0x14($sp)
/* B66664 80240BB4 8FB00010 */  lw        $s0, 0x10($sp)
/* B66668 80240BB8 03E00008 */  jr        $ra
/* B6666C 80240BBC 27BD0020 */   addiu    $sp, $sp, 0x20
