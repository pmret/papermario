.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241FB4_A047F4
/* A047F4 80241FB4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A047F8 80241FB8 AFB20018 */  sw        $s2, 0x18($sp)
/* A047FC 80241FBC 0080902D */  daddu     $s2, $a0, $zero
/* A04800 80241FC0 AFBF001C */  sw        $ra, 0x1c($sp)
/* A04804 80241FC4 AFB10014 */  sw        $s1, 0x14($sp)
/* A04808 80241FC8 AFB00010 */  sw        $s0, 0x10($sp)
/* A0480C 80241FCC 8E510148 */  lw        $s1, 0x148($s2)
/* A04810 80241FD0 0C00EABB */  jal       get_npc_unsafe
/* A04814 80241FD4 86240008 */   lh       $a0, 8($s1)
/* A04818 80241FD8 0040802D */  daddu     $s0, $v0, $zero
/* A0481C 80241FDC C602001C */  lwc1      $f2, 0x1c($s0)
/* A04820 80241FE0 C6000014 */  lwc1      $f0, 0x14($s0)
/* A04824 80241FE4 8E050018 */  lw        $a1, 0x18($s0)
/* A04828 80241FE8 46001080 */  add.s     $f2, $f2, $f0
/* A0482C 80241FEC C600003C */  lwc1      $f0, 0x3c($s0)
/* A04830 80241FF0 8E06000C */  lw        $a2, 0xc($s0)
/* A04834 80241FF4 46020000 */  add.s     $f0, $f0, $f2
/* A04838 80241FF8 0200202D */  daddu     $a0, $s0, $zero
/* A0483C 80241FFC E602001C */  swc1      $f2, 0x1c($s0)
/* A04840 80242000 0C00EA95 */  jal       npc_move_heading
/* A04844 80242004 E600003C */   swc1     $f0, 0x3c($s0)
/* A04848 80242008 9602008E */  lhu       $v0, 0x8e($s0)
/* A0484C 8024200C 2442FFFF */  addiu     $v0, $v0, -1
/* A04850 80242010 A602008E */  sh        $v0, 0x8e($s0)
/* A04854 80242014 00021400 */  sll       $v0, $v0, 0x10
/* A04858 80242018 1C40000F */  bgtz      $v0, .L80242058
/* A0485C 8024201C 00000000 */   nop
/* A04860 80242020 3C013E99 */  lui       $at, 0x3e99
/* A04864 80242024 3421999A */  ori       $at, $at, 0x999a
/* A04868 80242028 44810000 */  mtc1      $at, $f0
/* A0486C 8024202C 3C014040 */  lui       $at, 0x4040
/* A04870 80242030 44811000 */  mtc1      $at, $f2
/* A04874 80242034 A2200007 */  sb        $zero, 7($s1)
/* A04878 80242038 AE00001C */  sw        $zero, 0x1c($s0)
/* A0487C 8024203C E6000014 */  swc1      $f0, 0x14($s0)
/* A04880 80242040 E6020018 */  swc1      $f2, 0x18($s0)
/* A04884 80242044 8E2200CC */  lw        $v0, 0xcc($s1)
/* A04888 80242048 8C420028 */  lw        $v0, 0x28($v0)
/* A0488C 8024204C AE020028 */  sw        $v0, 0x28($s0)
/* A04890 80242050 2402000E */  addiu     $v0, $zero, 0xe
/* A04894 80242054 AE420070 */  sw        $v0, 0x70($s2)
.L80242058:
/* A04898 80242058 8FBF001C */  lw        $ra, 0x1c($sp)
/* A0489C 8024205C 8FB20018 */  lw        $s2, 0x18($sp)
/* A048A0 80242060 8FB10014 */  lw        $s1, 0x14($sp)
/* A048A4 80242064 8FB00010 */  lw        $s0, 0x10($sp)
/* A048A8 80242068 03E00008 */  jr        $ra
/* A048AC 8024206C 27BD0020 */   addiu    $sp, $sp, 0x20
