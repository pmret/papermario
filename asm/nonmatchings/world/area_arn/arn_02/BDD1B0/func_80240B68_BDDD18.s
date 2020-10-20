.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B68_BDDD18
/* BDDD18 80240B68 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BDDD1C 80240B6C AFB10014 */  sw        $s1, 0x14($sp)
/* BDDD20 80240B70 0080882D */  daddu     $s1, $a0, $zero
/* BDDD24 80240B74 AFBF0018 */  sw        $ra, 0x18($sp)
/* BDDD28 80240B78 AFB00010 */  sw        $s0, 0x10($sp)
/* BDDD2C 80240B7C 8E300148 */  lw        $s0, 0x148($s1)
/* BDDD30 80240B80 0C00EABB */  jal       get_npc_unsafe
/* BDDD34 80240B84 86040008 */   lh       $a0, 8($s0)
/* BDDD38 80240B88 0040202D */  daddu     $a0, $v0, $zero
/* BDDD3C 80240B8C 8482008E */  lh        $v0, 0x8e($a0)
/* BDDD40 80240B90 9483008E */  lhu       $v1, 0x8e($a0)
/* BDDD44 80240B94 18400002 */  blez      $v0, .L80240BA0
/* BDDD48 80240B98 2462FFFF */   addiu    $v0, $v1, -1
/* BDDD4C 80240B9C A482008E */  sh        $v0, 0x8e($a0)
.L80240BA0:
/* BDDD50 80240BA0 8482008C */  lh        $v0, 0x8c($a0)
/* BDDD54 80240BA4 1440000A */  bnez      $v0, .L80240BD0
/* BDDD58 80240BA8 00000000 */   nop      
/* BDDD5C 80240BAC 8482008E */  lh        $v0, 0x8e($a0)
/* BDDD60 80240BB0 1C400007 */  bgtz      $v0, .L80240BD0
/* BDDD64 80240BB4 24020008 */   addiu    $v0, $zero, 8
/* BDDD68 80240BB8 A482008E */  sh        $v0, 0x8e($a0)
/* BDDD6C 80240BBC 8E0200CC */  lw        $v0, 0xcc($s0)
/* BDDD70 80240BC0 8C42002C */  lw        $v0, 0x2c($v0)
/* BDDD74 80240BC4 AC820028 */  sw        $v0, 0x28($a0)
/* BDDD78 80240BC8 24020033 */  addiu     $v0, $zero, 0x33
/* BDDD7C 80240BCC AE220070 */  sw        $v0, 0x70($s1)
.L80240BD0:
/* BDDD80 80240BD0 8FBF0018 */  lw        $ra, 0x18($sp)
/* BDDD84 80240BD4 8FB10014 */  lw        $s1, 0x14($sp)
/* BDDD88 80240BD8 8FB00010 */  lw        $s0, 0x10($sp)
/* BDDD8C 80240BDC 03E00008 */  jr        $ra
/* BDDD90 80240BE0 27BD0020 */   addiu    $sp, $sp, 0x20
