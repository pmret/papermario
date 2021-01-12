.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BB6E0_E2E010
/* E2E010 802BB6E0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* E2E014 802BB6E4 AFB00018 */  sw        $s0, 0x18($sp)
/* E2E018 802BB6E8 0080802D */  daddu     $s0, $a0, $zero
/* E2E01C 802BB6EC AFBF0020 */  sw        $ra, 0x20($sp)
/* E2E020 802BB6F0 AFB1001C */  sw        $s1, 0x1c($sp)
/* E2E024 802BB6F4 86040014 */  lh        $a0, 0x14($s0)
/* E2E028 802BB6F8 0C047FF8 */  jal       get_anim_mesh
/* E2E02C 802BB6FC 8E110040 */   lw       $s1, 0x40($s0)
/* E2E030 802BB700 24030011 */  addiu     $v1, $zero, 0x11
/* E2E034 802BB704 3C04802C */  lui       $a0, %hi(D_802BC7D0)
/* E2E038 802BB708 2484C7D0 */  addiu     $a0, $a0, %lo(D_802BC7D0)
/* E2E03C 802BB70C A0430004 */  sb        $v1, 4($v0)
/* E2E040 802BB710 C6000048 */  lwc1      $f0, 0x48($s0)
/* E2E044 802BB714 C602004C */  lwc1      $f2, 0x4c($s0)
/* E2E048 802BB718 C6040050 */  lwc1      $f4, 0x50($s0)
/* E2E04C 802BB71C 3C028000 */  lui       $v0, 0x8000
/* E2E050 802BB720 AFA00010 */  sw        $zero, 0x10($sp)
/* E2E054 802BB724 4600018D */  trunc.w.s $f6, $f0
/* E2E058 802BB728 44053000 */  mfc1      $a1, $f6
/* E2E05C 802BB72C 4600118D */  trunc.w.s $f6, $f2
/* E2E060 802BB730 44063000 */  mfc1      $a2, $f6
/* E2E064 802BB734 4600218D */  trunc.w.s $f6, $f4
/* E2E068 802BB738 44073000 */  mfc1      $a3, $f6
/* E2E06C 802BB73C 0C044631 */  jal       create_entity
/* E2E070 802BB740 AFA20014 */   sw       $v0, 0x14($sp)
/* E2E074 802BB744 0040202D */  daddu     $a0, $v0, $zero
/* E2E078 802BB748 0C04417A */  jal       get_entity_by_index
/* E2E07C 802BB74C A6240004 */   sh       $a0, 4($s1)
/* E2E080 802BB750 8C510040 */  lw        $s1, 0x40($v0)
/* E2E084 802BB754 92030004 */  lbu       $v1, 4($s0)
/* E2E088 802BB758 A6230004 */  sh        $v1, 4($s1)
/* E2E08C 802BB75C C4400064 */  lwc1      $f0, 0x64($v0)
/* E2E090 802BB760 E6200008 */  swc1      $f0, 8($s1)
/* E2E094 802BB764 8FBF0020 */  lw        $ra, 0x20($sp)
/* E2E098 802BB768 8FB1001C */  lw        $s1, 0x1c($sp)
/* E2E09C 802BB76C 8FB00018 */  lw        $s0, 0x18($sp)
/* E2E0A0 802BB770 03E00008 */  jr        $ra
/* E2E0A4 802BB774 27BD0028 */   addiu    $sp, $sp, 0x28
