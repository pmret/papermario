.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241690_A08590
/* A08590 80241690 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A08594 80241694 AFB20018 */  sw        $s2, 0x18($sp)
/* A08598 80241698 0080902D */  daddu     $s2, $a0, $zero
/* A0859C 8024169C AFBF001C */  sw        $ra, 0x1c($sp)
/* A085A0 802416A0 AFB10014 */  sw        $s1, 0x14($sp)
/* A085A4 802416A4 AFB00010 */  sw        $s0, 0x10($sp)
/* A085A8 802416A8 8E510148 */  lw        $s1, 0x148($s2)
/* A085AC 802416AC 0C00EABB */  jal       get_npc_unsafe
/* A085B0 802416B0 86240008 */   lh       $a0, 8($s1)
/* A085B4 802416B4 0040802D */  daddu     $s0, $v0, $zero
/* A085B8 802416B8 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* A085BC 802416BC 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* A085C0 802416C0 C60C0038 */  lwc1      $f12, 0x38($s0)
/* A085C4 802416C4 C60E0040 */  lwc1      $f14, 0x40($s0)
/* A085C8 802416C8 A600008E */  sh        $zero, 0x8e($s0)
/* A085CC 802416CC 8C460028 */  lw        $a2, 0x28($v0)
/* A085D0 802416D0 0C00A720 */  jal       atan2
/* A085D4 802416D4 8C470030 */   lw       $a3, 0x30($v0)
/* A085D8 802416D8 E600000C */  swc1      $f0, 0xc($s0)
/* A085DC 802416DC 8E2200CC */  lw        $v0, 0xcc($s1)
/* A085E0 802416E0 8C420020 */  lw        $v0, 0x20($v0)
/* A085E4 802416E4 AE020028 */  sw        $v0, 0x28($s0)
/* A085E8 802416E8 2402000B */  addiu     $v0, $zero, 0xb
/* A085EC 802416EC AE420070 */  sw        $v0, 0x70($s2)
/* A085F0 802416F0 8FBF001C */  lw        $ra, 0x1c($sp)
/* A085F4 802416F4 8FB20018 */  lw        $s2, 0x18($sp)
/* A085F8 802416F8 8FB10014 */  lw        $s1, 0x14($sp)
/* A085FC 802416FC 8FB00010 */  lw        $s0, 0x10($sp)
/* A08600 80241700 03E00008 */  jr        $ra
/* A08604 80241704 27BD0020 */   addiu    $sp, $sp, 0x20
