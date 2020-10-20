.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802401B4_C526F4
/* C526F4 802401B4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C526F8 802401B8 AFB10014 */  sw        $s1, 0x14($sp)
/* C526FC 802401BC 0080882D */  daddu     $s1, $a0, $zero
/* C52700 802401C0 AFBF0018 */  sw        $ra, 0x18($sp)
/* C52704 802401C4 AFB00010 */  sw        $s0, 0x10($sp)
/* C52708 802401C8 8E300148 */  lw        $s0, 0x148($s1)
/* C5270C 802401CC 0C00EABB */  jal       get_npc_unsafe
/* C52710 802401D0 86040008 */   lh       $a0, 8($s0)
/* C52714 802401D4 9443008E */  lhu       $v1, 0x8e($v0)
/* C52718 802401D8 2463FFFF */  addiu     $v1, $v1, -1
/* C5271C 802401DC A443008E */  sh        $v1, 0x8e($v0)
/* C52720 802401E0 00031C00 */  sll       $v1, $v1, 0x10
/* C52724 802401E4 1C600003 */  bgtz      $v1, .L802401F4
/* C52728 802401E8 2402000C */   addiu    $v0, $zero, 0xc
/* C5272C 802401EC AE00006C */  sw        $zero, 0x6c($s0)
/* C52730 802401F0 AE220070 */  sw        $v0, 0x70($s1)
.L802401F4:
/* C52734 802401F4 8FBF0018 */  lw        $ra, 0x18($sp)
/* C52738 802401F8 8FB10014 */  lw        $s1, 0x14($sp)
/* C5273C 802401FC 8FB00010 */  lw        $s0, 0x10($sp)
/* C52740 80240200 03E00008 */  jr        $ra
/* C52744 80240204 27BD0020 */   addiu    $sp, $sp, 0x20
