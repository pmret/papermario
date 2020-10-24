.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240D98_99D728
/* 99D728 80240D98 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 99D72C 80240D9C AFB00010 */  sw        $s0, 0x10($sp)
/* 99D730 80240DA0 0080802D */  daddu     $s0, $a0, $zero
/* 99D734 80240DA4 AFBF0014 */  sw        $ra, 0x14($sp)
/* 99D738 80240DA8 8E020148 */  lw        $v0, 0x148($s0)
/* 99D73C 80240DAC 0C00EABB */  jal       get_npc_unsafe
/* 99D740 80240DB0 84440008 */   lh       $a0, 8($v0)
/* 99D744 80240DB4 3C014120 */  lui       $at, 0x4120
/* 99D748 80240DB8 44810000 */  mtc1      $at, $f0
/* 99D74C 80240DBC 3C014000 */  lui       $at, 0x4000
/* 99D750 80240DC0 44811000 */  mtc1      $at, $f2
/* 99D754 80240DC4 8C430000 */  lw        $v1, ($v0)
/* 99D758 80240DC8 C444003C */  lwc1      $f4, 0x3c($v0)
/* 99D75C 80240DCC 34630800 */  ori       $v1, $v1, 0x800
/* 99D760 80240DD0 E440001C */  swc1      $f0, 0x1c($v0)
/* 99D764 80240DD4 E4420014 */  swc1      $f2, 0x14($v0)
/* 99D768 80240DD8 E4440064 */  swc1      $f4, 0x64($v0)
/* 99D76C 80240DDC AC430000 */  sw        $v1, ($v0)
/* 99D770 80240DE0 2402000B */  addiu     $v0, $zero, 0xb
/* 99D774 80240DE4 AE020070 */  sw        $v0, 0x70($s0)
/* 99D778 80240DE8 8FBF0014 */  lw        $ra, 0x14($sp)
/* 99D77C 80240DEC 8FB00010 */  lw        $s0, 0x10($sp)
/* 99D780 80240DF0 03E00008 */  jr        $ra
/* 99D784 80240DF4 27BD0018 */   addiu    $sp, $sp, 0x18
