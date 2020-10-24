.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802415F8_8B1668
/* 8B1668 802415F8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8B166C 802415FC AFB00010 */  sw        $s0, 0x10($sp)
/* 8B1670 80241600 0080802D */  daddu     $s0, $a0, $zero
/* 8B1674 80241604 AFBF0014 */  sw        $ra, 0x14($sp)
/* 8B1678 80241608 8E020148 */  lw        $v0, 0x148($s0)
/* 8B167C 8024160C 0C00EABB */  jal       get_npc_unsafe
/* 8B1680 80241610 84440008 */   lh       $a0, 8($v0)
/* 8B1684 80241614 3C014120 */  lui       $at, 0x4120
/* 8B1688 80241618 44810000 */  mtc1      $at, $f0
/* 8B168C 8024161C 3C014000 */  lui       $at, 0x4000
/* 8B1690 80241620 44811000 */  mtc1      $at, $f2
/* 8B1694 80241624 8C430000 */  lw        $v1, ($v0)
/* 8B1698 80241628 C444003C */  lwc1      $f4, 0x3c($v0)
/* 8B169C 8024162C 34630800 */  ori       $v1, $v1, 0x800
/* 8B16A0 80241630 E440001C */  swc1      $f0, 0x1c($v0)
/* 8B16A4 80241634 E4420014 */  swc1      $f2, 0x14($v0)
/* 8B16A8 80241638 E4440064 */  swc1      $f4, 0x64($v0)
/* 8B16AC 8024163C AC430000 */  sw        $v1, ($v0)
/* 8B16B0 80241640 2402000B */  addiu     $v0, $zero, 0xb
/* 8B16B4 80241644 AE020070 */  sw        $v0, 0x70($s0)
/* 8B16B8 80241648 8FBF0014 */  lw        $ra, 0x14($sp)
/* 8B16BC 8024164C 8FB00010 */  lw        $s0, 0x10($sp)
/* 8B16C0 80241650 03E00008 */  jr        $ra
/* 8B16C4 80241654 27BD0018 */   addiu    $sp, $sp, 0x18
