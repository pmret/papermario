.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241614_C6F944
/* C6F944 80241614 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C6F948 80241618 AFB00010 */  sw        $s0, 0x10($sp)
/* C6F94C 8024161C 0080802D */  daddu     $s0, $a0, $zero
/* C6F950 80241620 AFBF0014 */  sw        $ra, 0x14($sp)
/* C6F954 80241624 8E020148 */  lw        $v0, 0x148($s0)
/* C6F958 80241628 0C00EABB */  jal       get_npc_unsafe
/* C6F95C 8024162C 84440008 */   lh       $a0, 8($v0)
/* C6F960 80241630 0040202D */  daddu     $a0, $v0, $zero
/* C6F964 80241634 8482008E */  lh        $v0, 0x8e($a0)
/* C6F968 80241638 9483008E */  lhu       $v1, 0x8e($a0)
/* C6F96C 8024163C 18400005 */  blez      $v0, .L80241654
/* C6F970 80241640 2462FFFF */   addiu    $v0, $v1, -1
/* C6F974 80241644 A482008E */  sh        $v0, 0x8e($a0)
/* C6F978 80241648 00021400 */  sll       $v0, $v0, 0x10
/* C6F97C 8024164C 1C400006 */  bgtz      $v0, .L80241668
/* C6F980 80241650 00000000 */   nop      
.L80241654:
/* C6F984 80241654 8482008C */  lh        $v0, 0x8c($a0)
/* C6F988 80241658 14400003 */  bnez      $v0, .L80241668
/* C6F98C 8024165C 2402000E */   addiu    $v0, $zero, 0xe
/* C6F990 80241660 A480008E */  sh        $zero, 0x8e($a0)
/* C6F994 80241664 AE020070 */  sw        $v0, 0x70($s0)
.L80241668:
/* C6F998 80241668 8FBF0014 */  lw        $ra, 0x14($sp)
/* C6F99C 8024166C 8FB00010 */  lw        $s0, 0x10($sp)
/* C6F9A0 80241670 03E00008 */  jr        $ra
/* C6F9A4 80241674 27BD0018 */   addiu    $sp, $sp, 0x18
