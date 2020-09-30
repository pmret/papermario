.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802616B4
/* 18FF94 802616B4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 18FF98 802616B8 AFBF0010 */  sw        $ra, 0x10($sp)
/* 18FF9C 802616BC 0C00EABB */  jal       get_npc_unsafe
/* 18FFA0 802616C0 2404FFF6 */   addiu    $a0, $zero, -0xa
/* 18FFA4 802616C4 0040182D */  daddu     $v1, $v0, $zero
/* 18FFA8 802616C8 906200AC */  lbu       $v0, 0xac($v1)
/* 18FFAC 802616CC 2442FFEF */  addiu     $v0, $v0, -0x11
/* 18FFB0 802616D0 A06200AC */  sb        $v0, 0xac($v1)
/* 18FFB4 802616D4 304200FF */  andi      $v0, $v0, 0xff
/* 18FFB8 802616D8 14400003 */  bnez      $v0, .L802616E8
/* 18FFBC 802616DC 0000102D */   daddu    $v0, $zero, $zero
/* 18FFC0 802616E0 A06000AC */  sb        $zero, 0xac($v1)
/* 18FFC4 802616E4 24020001 */  addiu     $v0, $zero, 1
.L802616E8:
/* 18FFC8 802616E8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 18FFCC 802616EC 03E00008 */  jr        $ra
/* 18FFD0 802616F0 27BD0018 */   addiu    $sp, $sp, 0x18
