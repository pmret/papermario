.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243438_9AB828
/* 9AB828 80243438 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 9AB82C 8024343C AFB20018 */  sw        $s2, 0x18($sp)
/* 9AB830 80243440 0080902D */  daddu     $s2, $a0, $zero
/* 9AB834 80243444 AFBF001C */  sw        $ra, 0x1c($sp)
/* 9AB838 80243448 AFB10014 */  sw        $s1, 0x14($sp)
/* 9AB83C 8024344C AFB00010 */  sw        $s0, 0x10($sp)
/* 9AB840 80243450 8E510148 */  lw        $s1, 0x148($s2)
/* 9AB844 80243454 0C00EABB */  jal       get_npc_unsafe
/* 9AB848 80243458 86240008 */   lh       $a0, 8($s1)
/* 9AB84C 8024345C 0040802D */  daddu     $s0, $v0, $zero
/* 9AB850 80243460 C602001C */  lwc1      $f2, 0x1c($s0)
/* 9AB854 80243464 C6000014 */  lwc1      $f0, 0x14($s0)
/* 9AB858 80243468 8E050018 */  lw        $a1, 0x18($s0)
/* 9AB85C 8024346C 46001080 */  add.s     $f2, $f2, $f0
/* 9AB860 80243470 C600003C */  lwc1      $f0, 0x3c($s0)
/* 9AB864 80243474 8E06000C */  lw        $a2, 0xc($s0)
/* 9AB868 80243478 46020000 */  add.s     $f0, $f0, $f2
/* 9AB86C 8024347C 0200202D */  daddu     $a0, $s0, $zero
/* 9AB870 80243480 E602001C */  swc1      $f2, 0x1c($s0)
/* 9AB874 80243484 0C00EA95 */  jal       npc_move_heading
/* 9AB878 80243488 E600003C */   swc1     $f0, 0x3c($s0)
/* 9AB87C 8024348C 9602008E */  lhu       $v0, 0x8e($s0)
/* 9AB880 80243490 2442FFFF */  addiu     $v0, $v0, -1
/* 9AB884 80243494 A602008E */  sh        $v0, 0x8e($s0)
/* 9AB888 80243498 00021400 */  sll       $v0, $v0, 0x10
/* 9AB88C 8024349C 1C40000F */  bgtz      $v0, .L802434DC
/* 9AB890 802434A0 00000000 */   nop
/* 9AB894 802434A4 3C013E99 */  lui       $at, 0x3e99
/* 9AB898 802434A8 3421999A */  ori       $at, $at, 0x999a
/* 9AB89C 802434AC 44810000 */  mtc1      $at, $f0
/* 9AB8A0 802434B0 3C014040 */  lui       $at, 0x4040
/* 9AB8A4 802434B4 44811000 */  mtc1      $at, $f2
/* 9AB8A8 802434B8 A2200007 */  sb        $zero, 7($s1)
/* 9AB8AC 802434BC AE00001C */  sw        $zero, 0x1c($s0)
/* 9AB8B0 802434C0 E6000014 */  swc1      $f0, 0x14($s0)
/* 9AB8B4 802434C4 E6020018 */  swc1      $f2, 0x18($s0)
/* 9AB8B8 802434C8 8E2200CC */  lw        $v0, 0xcc($s1)
/* 9AB8BC 802434CC 8C420028 */  lw        $v0, 0x28($v0)
/* 9AB8C0 802434D0 AE020028 */  sw        $v0, 0x28($s0)
/* 9AB8C4 802434D4 2402000E */  addiu     $v0, $zero, 0xe
/* 9AB8C8 802434D8 AE420070 */  sw        $v0, 0x70($s2)
.L802434DC:
/* 9AB8CC 802434DC 8FBF001C */  lw        $ra, 0x1c($sp)
/* 9AB8D0 802434E0 8FB20018 */  lw        $s2, 0x18($sp)
/* 9AB8D4 802434E4 8FB10014 */  lw        $s1, 0x14($sp)
/* 9AB8D8 802434E8 8FB00010 */  lw        $s0, 0x10($sp)
/* 9AB8DC 802434EC 03E00008 */  jr        $ra
/* 9AB8E0 802434F0 27BD0020 */   addiu    $sp, $sp, 0x20
