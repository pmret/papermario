.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240544_8DA644
/* 8DA644 80240544 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8DA648 80240548 AFB00010 */  sw        $s0, 0x10($sp)
/* 8DA64C 8024054C 0080802D */  daddu     $s0, $a0, $zero
/* 8DA650 80240550 AFBF0014 */  sw        $ra, 0x14($sp)
/* 8DA654 80240554 8E020148 */  lw        $v0, 0x148($s0)
/* 8DA658 80240558 0C00EABB */  jal       get_npc_unsafe
/* 8DA65C 8024055C 84440008 */   lh       $a0, 8($v0)
/* 8DA660 80240560 3C014120 */  lui       $at, 0x4120
/* 8DA664 80240564 44810000 */  mtc1      $at, $f0
/* 8DA668 80240568 3C014000 */  lui       $at, 0x4000
/* 8DA66C 8024056C 44811000 */  mtc1      $at, $f2
/* 8DA670 80240570 8C430000 */  lw        $v1, ($v0)
/* 8DA674 80240574 C444003C */  lwc1      $f4, 0x3c($v0)
/* 8DA678 80240578 34630800 */  ori       $v1, $v1, 0x800
/* 8DA67C 8024057C E440001C */  swc1      $f0, 0x1c($v0)
/* 8DA680 80240580 E4420014 */  swc1      $f2, 0x14($v0)
/* 8DA684 80240584 E4440064 */  swc1      $f4, 0x64($v0)
/* 8DA688 80240588 AC430000 */  sw        $v1, ($v0)
/* 8DA68C 8024058C 2402000B */  addiu     $v0, $zero, 0xb
/* 8DA690 80240590 AE020070 */  sw        $v0, 0x70($s0)
/* 8DA694 80240594 8FBF0014 */  lw        $ra, 0x14($sp)
/* 8DA698 80240598 8FB00010 */  lw        $s0, 0x10($sp)
/* 8DA69C 8024059C 03E00008 */  jr        $ra
/* 8DA6A0 802405A0 27BD0018 */   addiu    $sp, $sp, 0x18
