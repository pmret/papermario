.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240FE4_9A1FC4
/* 9A1FC4 80240FE4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 9A1FC8 80240FE8 AFB10014 */  sw        $s1, 0x14($sp)
/* 9A1FCC 80240FEC 0080882D */  daddu     $s1, $a0, $zero
/* 9A1FD0 80240FF0 AFBF0018 */  sw        $ra, 0x18($sp)
/* 9A1FD4 80240FF4 AFB00010 */  sw        $s0, 0x10($sp)
/* 9A1FD8 80240FF8 8E300148 */  lw        $s0, 0x148($s1)
/* 9A1FDC 80240FFC 0C00EABB */  jal       get_npc_unsafe
/* 9A1FE0 80241000 86040008 */   lh       $a0, 8($s0)
/* 9A1FE4 80241004 8E0300CC */  lw        $v1, 0xcc($s0)
/* 9A1FE8 80241008 3C014120 */  lui       $at, 0x4120
/* 9A1FEC 8024100C 44812000 */  mtc1      $at, $f4
/* 9A1FF0 80241010 3C014000 */  lui       $at, 0x4000
/* 9A1FF4 80241014 44810000 */  mtc1      $at, $f0
/* 9A1FF8 80241018 C442003C */  lwc1      $f2, 0x3c($v0)
/* 9A1FFC 8024101C 8C640010 */  lw        $a0, 0x10($v1)
/* 9A2000 80241020 8C430000 */  lw        $v1, ($v0)
/* 9A2004 80241024 E444001C */  swc1      $f4, 0x1c($v0)
/* 9A2008 80241028 E4400014 */  swc1      $f0, 0x14($v0)
/* 9A200C 8024102C E4420064 */  swc1      $f2, 0x64($v0)
/* 9A2010 80241030 34630800 */  ori       $v1, $v1, 0x800
/* 9A2014 80241034 AC430000 */  sw        $v1, ($v0)
/* 9A2018 80241038 AC440028 */  sw        $a0, 0x28($v0)
/* 9A201C 8024103C 2402000B */  addiu     $v0, $zero, 0xb
/* 9A2020 80241040 AE220070 */  sw        $v0, 0x70($s1)
/* 9A2024 80241044 8FBF0018 */  lw        $ra, 0x18($sp)
/* 9A2028 80241048 8FB10014 */  lw        $s1, 0x14($sp)
/* 9A202C 8024104C 8FB00010 */  lw        $s0, 0x10($sp)
/* 9A2030 80241050 03E00008 */  jr        $ra
/* 9A2034 80241054 27BD0020 */   addiu    $sp, $sp, 0x20
