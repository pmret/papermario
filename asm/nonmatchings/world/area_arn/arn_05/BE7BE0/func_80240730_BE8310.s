.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240730_BE8310
/* BE8310 80240730 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BE8314 80240734 AFB10014 */  sw        $s1, 0x14($sp)
/* BE8318 80240738 0080882D */  daddu     $s1, $a0, $zero
/* BE831C 8024073C AFBF0018 */  sw        $ra, 0x18($sp)
/* BE8320 80240740 AFB00010 */  sw        $s0, 0x10($sp)
/* BE8324 80240744 8E300148 */  lw        $s0, 0x148($s1)
/* BE8328 80240748 0C00EABB */  jal       get_npc_unsafe
/* BE832C 8024074C 86040008 */   lh       $a0, 8($s0)
/* BE8330 80240750 8E0300CC */  lw        $v1, 0xcc($s0)
/* BE8334 80240754 3C014120 */  lui       $at, 0x4120
/* BE8338 80240758 44812000 */  mtc1      $at, $f4
/* BE833C 8024075C 3C014000 */  lui       $at, 0x4000
/* BE8340 80240760 44810000 */  mtc1      $at, $f0
/* BE8344 80240764 C442003C */  lwc1      $f2, 0x3c($v0)
/* BE8348 80240768 8C640010 */  lw        $a0, 0x10($v1)
/* BE834C 8024076C 8C430000 */  lw        $v1, ($v0)
/* BE8350 80240770 E444001C */  swc1      $f4, 0x1c($v0)
/* BE8354 80240774 E4400014 */  swc1      $f0, 0x14($v0)
/* BE8358 80240778 E4420064 */  swc1      $f2, 0x64($v0)
/* BE835C 8024077C 34630800 */  ori       $v1, $v1, 0x800
/* BE8360 80240780 AC430000 */  sw        $v1, ($v0)
/* BE8364 80240784 AC440028 */  sw        $a0, 0x28($v0)
/* BE8368 80240788 2402000B */  addiu     $v0, $zero, 0xb
/* BE836C 8024078C AE220070 */  sw        $v0, 0x70($s1)
/* BE8370 80240790 8FBF0018 */  lw        $ra, 0x18($sp)
/* BE8374 80240794 8FB10014 */  lw        $s1, 0x14($sp)
/* BE8378 80240798 8FB00010 */  lw        $s0, 0x10($sp)
/* BE837C 8024079C 03E00008 */  jr        $ra
/* BE8380 802407A0 27BD0020 */   addiu    $sp, $sp, 0x20
