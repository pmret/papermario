.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802401D4_9C55B4
/* 9C55B4 802401D4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9C55B8 802401D8 AFB00010 */  sw        $s0, 0x10($sp)
/* 9C55BC 802401DC 0080802D */  daddu     $s0, $a0, $zero
/* 9C55C0 802401E0 AFBF0014 */  sw        $ra, 0x14($sp)
/* 9C55C4 802401E4 8E020148 */  lw        $v0, 0x148($s0)
/* 9C55C8 802401E8 0C00EABB */  jal       get_npc_unsafe
/* 9C55CC 802401EC 84440008 */   lh       $a0, 8($v0)
/* 9C55D0 802401F0 3C014120 */  lui       $at, 0x4120
/* 9C55D4 802401F4 44810000 */  mtc1      $at, $f0
/* 9C55D8 802401F8 3C014000 */  lui       $at, 0x4000
/* 9C55DC 802401FC 44811000 */  mtc1      $at, $f2
/* 9C55E0 80240200 8C430000 */  lw        $v1, ($v0)
/* 9C55E4 80240204 C444003C */  lwc1      $f4, 0x3c($v0)
/* 9C55E8 80240208 34630800 */  ori       $v1, $v1, 0x800
/* 9C55EC 8024020C E440001C */  swc1      $f0, 0x1c($v0)
/* 9C55F0 80240210 E4420014 */  swc1      $f2, 0x14($v0)
/* 9C55F4 80240214 E4440064 */  swc1      $f4, 0x64($v0)
/* 9C55F8 80240218 AC430000 */  sw        $v1, ($v0)
/* 9C55FC 8024021C 2402000B */  addiu     $v0, $zero, 0xb
/* 9C5600 80240220 AE020070 */  sw        $v0, 0x70($s0)
/* 9C5604 80240224 8FBF0014 */  lw        $ra, 0x14($sp)
/* 9C5608 80240228 8FB00010 */  lw        $s0, 0x10($sp)
/* 9C560C 8024022C 03E00008 */  jr        $ra
/* 9C5610 80240230 27BD0018 */   addiu    $sp, $sp, 0x18
