.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B68_9168D8
/* 9168D8 80240B68 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 9168DC 80240B6C AFB10014 */  sw        $s1, 0x14($sp)
/* 9168E0 80240B70 0080882D */  daddu     $s1, $a0, $zero
/* 9168E4 80240B74 AFBF0018 */  sw        $ra, 0x18($sp)
/* 9168E8 80240B78 AFB00010 */  sw        $s0, 0x10($sp)
/* 9168EC 80240B7C 8E300148 */  lw        $s0, 0x148($s1)
/* 9168F0 80240B80 0C00EABB */  jal       get_npc_unsafe
/* 9168F4 80240B84 86040008 */   lh       $a0, 8($s0)
/* 9168F8 80240B88 0040202D */  daddu     $a0, $v0, $zero
/* 9168FC 80240B8C 8482008E */  lh        $v0, 0x8e($a0)
/* 916900 80240B90 9483008E */  lhu       $v1, 0x8e($a0)
/* 916904 80240B94 18400002 */  blez      $v0, .L80240BA0
/* 916908 80240B98 2462FFFF */   addiu    $v0, $v1, -1
/* 91690C 80240B9C A482008E */  sh        $v0, 0x8e($a0)
.L80240BA0:
/* 916910 80240BA0 8482008C */  lh        $v0, 0x8c($a0)
/* 916914 80240BA4 1440000A */  bnez      $v0, .L80240BD0
/* 916918 80240BA8 00000000 */   nop
/* 91691C 80240BAC 8482008E */  lh        $v0, 0x8e($a0)
/* 916920 80240BB0 1C400007 */  bgtz      $v0, .L80240BD0
/* 916924 80240BB4 24020008 */   addiu    $v0, $zero, 8
/* 916928 80240BB8 A482008E */  sh        $v0, 0x8e($a0)
/* 91692C 80240BBC 8E0200CC */  lw        $v0, 0xcc($s0)
/* 916930 80240BC0 8C42002C */  lw        $v0, 0x2c($v0)
/* 916934 80240BC4 AC820028 */  sw        $v0, 0x28($a0)
/* 916938 80240BC8 24020033 */  addiu     $v0, $zero, 0x33
/* 91693C 80240BCC AE220070 */  sw        $v0, 0x70($s1)
.L80240BD0:
/* 916940 80240BD0 8FBF0018 */  lw        $ra, 0x18($sp)
/* 916944 80240BD4 8FB10014 */  lw        $s1, 0x14($sp)
/* 916948 80240BD8 8FB00010 */  lw        $s0, 0x10($sp)
/* 91694C 80240BDC 03E00008 */  jr        $ra
/* 916950 80240BE0 27BD0020 */   addiu    $sp, $sp, 0x20
