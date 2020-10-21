.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240BE8_91C4C8
/* 91C4C8 80240BE8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 91C4CC 80240BEC AFB10014 */  sw        $s1, 0x14($sp)
/* 91C4D0 80240BF0 0080882D */  daddu     $s1, $a0, $zero
/* 91C4D4 80240BF4 AFBF0018 */  sw        $ra, 0x18($sp)
/* 91C4D8 80240BF8 AFB00010 */  sw        $s0, 0x10($sp)
/* 91C4DC 80240BFC 8E300148 */  lw        $s0, 0x148($s1)
/* 91C4E0 80240C00 0C00EABB */  jal       get_npc_unsafe
/* 91C4E4 80240C04 86040008 */   lh       $a0, 8($s0)
/* 91C4E8 80240C08 0040202D */  daddu     $a0, $v0, $zero
/* 91C4EC 80240C0C 8482008E */  lh        $v0, 0x8e($a0)
/* 91C4F0 80240C10 9483008E */  lhu       $v1, 0x8e($a0)
/* 91C4F4 80240C14 18400002 */  blez      $v0, .L80240C20
/* 91C4F8 80240C18 2462FFFF */   addiu    $v0, $v1, -1
/* 91C4FC 80240C1C A482008E */  sh        $v0, 0x8e($a0)
.L80240C20:
/* 91C500 80240C20 8482008C */  lh        $v0, 0x8c($a0)
/* 91C504 80240C24 1440000A */  bnez      $v0, .L80240C50
/* 91C508 80240C28 00000000 */   nop      
/* 91C50C 80240C2C 8482008E */  lh        $v0, 0x8e($a0)
/* 91C510 80240C30 1C400007 */  bgtz      $v0, .L80240C50
/* 91C514 80240C34 24020008 */   addiu    $v0, $zero, 8
/* 91C518 80240C38 A482008E */  sh        $v0, 0x8e($a0)
/* 91C51C 80240C3C 8E0200CC */  lw        $v0, 0xcc($s0)
/* 91C520 80240C40 8C42002C */  lw        $v0, 0x2c($v0)
/* 91C524 80240C44 AC820028 */  sw        $v0, 0x28($a0)
/* 91C528 80240C48 24020033 */  addiu     $v0, $zero, 0x33
/* 91C52C 80240C4C AE220070 */  sw        $v0, 0x70($s1)
.L80240C50:
/* 91C530 80240C50 8FBF0018 */  lw        $ra, 0x18($sp)
/* 91C534 80240C54 8FB10014 */  lw        $s1, 0x14($sp)
/* 91C538 80240C58 8FB00010 */  lw        $s0, 0x10($sp)
/* 91C53C 80240C5C 03E00008 */  jr        $ra
/* 91C540 80240C60 27BD0020 */   addiu    $sp, $sp, 0x20
