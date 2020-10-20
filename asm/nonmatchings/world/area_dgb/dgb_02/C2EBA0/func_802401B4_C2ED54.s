.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802401B4_C2ED54
/* C2ED54 802401B4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C2ED58 802401B8 AFB10014 */  sw        $s1, 0x14($sp)
/* C2ED5C 802401BC 0080882D */  daddu     $s1, $a0, $zero
/* C2ED60 802401C0 AFBF0018 */  sw        $ra, 0x18($sp)
/* C2ED64 802401C4 AFB00010 */  sw        $s0, 0x10($sp)
/* C2ED68 802401C8 8E300148 */  lw        $s0, 0x148($s1)
/* C2ED6C 802401CC 0C00EABB */  jal       get_npc_unsafe
/* C2ED70 802401D0 86040008 */   lh       $a0, 8($s0)
/* C2ED74 802401D4 9443008E */  lhu       $v1, 0x8e($v0)
/* C2ED78 802401D8 2463FFFF */  addiu     $v1, $v1, -1
/* C2ED7C 802401DC A443008E */  sh        $v1, 0x8e($v0)
/* C2ED80 802401E0 00031C00 */  sll       $v1, $v1, 0x10
/* C2ED84 802401E4 1C600003 */  bgtz      $v1, .L802401F4
/* C2ED88 802401E8 2402000C */   addiu    $v0, $zero, 0xc
/* C2ED8C 802401EC AE00006C */  sw        $zero, 0x6c($s0)
/* C2ED90 802401F0 AE220070 */  sw        $v0, 0x70($s1)
.L802401F4:
/* C2ED94 802401F4 8FBF0018 */  lw        $ra, 0x18($sp)
/* C2ED98 802401F8 8FB10014 */  lw        $s1, 0x14($sp)
/* C2ED9C 802401FC 8FB00010 */  lw        $s0, 0x10($sp)
/* C2EDA0 80240200 03E00008 */  jr        $ra
/* C2EDA4 80240204 27BD0020 */   addiu    $sp, $sp, 0x20
