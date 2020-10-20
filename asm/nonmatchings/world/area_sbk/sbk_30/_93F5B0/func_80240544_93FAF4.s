.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240544_93FAF4
/* 93FAF4 80240544 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 93FAF8 80240548 AFB00010 */  sw        $s0, 0x10($sp)
/* 93FAFC 8024054C 0080802D */  daddu     $s0, $a0, $zero
/* 93FB00 80240550 AFBF0014 */  sw        $ra, 0x14($sp)
/* 93FB04 80240554 8E020148 */  lw        $v0, 0x148($s0)
/* 93FB08 80240558 0C00EABB */  jal       get_npc_unsafe
/* 93FB0C 8024055C 84440008 */   lh       $a0, 8($v0)
/* 93FB10 80240560 3C014120 */  lui       $at, 0x4120
/* 93FB14 80240564 44810000 */  mtc1      $at, $f0
/* 93FB18 80240568 3C014000 */  lui       $at, 0x4000
/* 93FB1C 8024056C 44811000 */  mtc1      $at, $f2
/* 93FB20 80240570 8C430000 */  lw        $v1, ($v0)
/* 93FB24 80240574 C444003C */  lwc1      $f4, 0x3c($v0)
/* 93FB28 80240578 34630800 */  ori       $v1, $v1, 0x800
/* 93FB2C 8024057C E440001C */  swc1      $f0, 0x1c($v0)
/* 93FB30 80240580 E4420014 */  swc1      $f2, 0x14($v0)
/* 93FB34 80240584 E4440064 */  swc1      $f4, 0x64($v0)
/* 93FB38 80240588 AC430000 */  sw        $v1, ($v0)
/* 93FB3C 8024058C 2402000B */  addiu     $v0, $zero, 0xb
/* 93FB40 80240590 AE020070 */  sw        $v0, 0x70($s0)
/* 93FB44 80240594 8FBF0014 */  lw        $ra, 0x14($sp)
/* 93FB48 80240598 8FB00010 */  lw        $s0, 0x10($sp)
/* 93FB4C 8024059C 03E00008 */  jr        $ra
/* 93FB50 802405A0 27BD0018 */   addiu    $sp, $sp, 0x18
