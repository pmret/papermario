.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240420_DDF730
/* DDF730 80240420 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* DDF734 80240424 3C048024 */  lui       $a0, %hi(D_80243168_DE2478)
/* DDF738 80240428 24843168 */  addiu     $a0, $a0, %lo(D_80243168_DE2478)
/* DDF73C 8024042C 27A50010 */  addiu     $a1, $sp, 0x10
/* DDF740 80240430 AFBF0020 */  sw        $ra, 0x20($sp)
/* DDF744 80240434 AFB1001C */  sw        $s1, 0x1c($sp)
/* DDF748 80240438 0C016B3A */  jal       load_asset_by_name
/* DDF74C 8024043C AFB00018 */   sw       $s0, 0x18($sp)
/* DDF750 80240440 0040802D */  daddu     $s0, $v0, $zero
/* DDF754 80240444 0200202D */  daddu     $a0, $s0, $zero
/* DDF758 80240448 3C118024 */  lui       $s1, %hi(D_80243190)
/* DDF75C 8024044C 26313190 */  addiu     $s1, $s1, %lo(D_80243190)
/* DDF760 80240450 0C01BB7C */  jal       decode_yay0
/* DDF764 80240454 0220282D */   daddu    $a1, $s1, $zero
/* DDF768 80240458 0C00AB1E */  jal       general_heap_free
/* DDF76C 8024045C 0200202D */   daddu    $a0, $s0, $zero
/* DDF770 80240460 3C048024 */  lui       $a0, %hi(D_80247120)
/* DDF774 80240464 24847120 */  addiu     $a0, $a0, %lo(D_80247120)
/* DDF778 80240468 3C028024 */  lui       $v0, %hi(jtbl_80243390_C558D0)
/* DDF77C 8024046C 24423390 */  addiu     $v0, $v0, %lo(jtbl_80243390_C558D0)
/* DDF780 80240470 AC820000 */  sw        $v0, ($a0)
/* DDF784 80240474 24020096 */  addiu     $v0, $zero, 0x96
/* DDF788 80240478 A4820008 */  sh        $v0, 8($a0)
/* DDF78C 8024047C 24020069 */  addiu     $v0, $zero, 0x69
/* DDF790 80240480 A482000A */  sh        $v0, 0xa($a0)
/* DDF794 80240484 24020002 */  addiu     $v0, $zero, 2
/* DDF798 80240488 AC82000C */  sw        $v0, 0xc($a0)
/* DDF79C 8024048C 24020001 */  addiu     $v0, $zero, 1
/* DDF7A0 80240490 AC910004 */  sw        $s1, 4($a0)
/* DDF7A4 80240494 0C0496CB */  jal       set_message_images
/* DDF7A8 80240498 AC820010 */   sw       $v0, 0x10($a0)
/* DDF7AC 8024049C 8FBF0020 */  lw        $ra, 0x20($sp)
/* DDF7B0 802404A0 8FB1001C */  lw        $s1, 0x1c($sp)
/* DDF7B4 802404A4 8FB00018 */  lw        $s0, 0x18($sp)
/* DDF7B8 802404A8 24020002 */  addiu     $v0, $zero, 2
/* DDF7BC 802404AC 03E00008 */  jr        $ra
/* DDF7C0 802404B0 27BD0028 */   addiu    $sp, $sp, 0x28
/* DDF7C4 802404B4 00000000 */  nop
/* DDF7C8 802404B8 00000000 */  nop
/* DDF7CC 802404BC 00000000 */  nop
