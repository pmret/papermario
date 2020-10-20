.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802401D4
/* 8D3F94 802401D4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8D3F98 802401D8 AFB00010 */  sw        $s0, 0x10($sp)
/* 8D3F9C 802401DC 0080802D */  daddu     $s0, $a0, $zero
/* 8D3FA0 802401E0 AFBF0014 */  sw        $ra, 0x14($sp)
/* 8D3FA4 802401E4 8E020148 */  lw        $v0, 0x148($s0)
/* 8D3FA8 802401E8 0C00EABB */  jal       get_npc_unsafe
/* 8D3FAC 802401EC 84440008 */   lh       $a0, 8($v0)
/* 8D3FB0 802401F0 3C014120 */  lui       $at, 0x4120
/* 8D3FB4 802401F4 44810000 */  mtc1      $at, $f0
/* 8D3FB8 802401F8 3C014000 */  lui       $at, 0x4000
/* 8D3FBC 802401FC 44811000 */  mtc1      $at, $f2
/* 8D3FC0 80240200 8C430000 */  lw        $v1, ($v0)
/* 8D3FC4 80240204 C444003C */  lwc1      $f4, 0x3c($v0)
/* 8D3FC8 80240208 34630800 */  ori       $v1, $v1, 0x800
/* 8D3FCC 8024020C E440001C */  swc1      $f0, 0x1c($v0)
/* 8D3FD0 80240210 E4420014 */  swc1      $f2, 0x14($v0)
/* 8D3FD4 80240214 E4440064 */  swc1      $f4, 0x64($v0)
/* 8D3FD8 80240218 AC430000 */  sw        $v1, ($v0)
/* 8D3FDC 8024021C 2402000B */  addiu     $v0, $zero, 0xb
/* 8D3FE0 80240220 AE020070 */  sw        $v0, 0x70($s0)
/* 8D3FE4 80240224 8FBF0014 */  lw        $ra, 0x14($sp)
/* 8D3FE8 80240228 8FB00010 */  lw        $s0, 0x10($sp)
/* 8D3FEC 8024022C 03E00008 */  jr        $ra
/* 8D3FF0 80240230 27BD0018 */   addiu    $sp, $sp, 0x18
