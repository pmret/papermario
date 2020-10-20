.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241904_CCCC14
/* CCCC14 80241904 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* CCCC18 80241908 AFB00010 */  sw        $s0, 0x10($sp)
/* CCCC1C 8024190C 0080802D */  daddu     $s0, $a0, $zero
/* CCCC20 80241910 AFBF0014 */  sw        $ra, 0x14($sp)
/* CCCC24 80241914 8E020148 */  lw        $v0, 0x148($s0)
/* CCCC28 80241918 0C00EABB */  jal       get_npc_unsafe
/* CCCC2C 8024191C 84440008 */   lh       $a0, 8($v0)
/* CCCC30 80241920 0040202D */  daddu     $a0, $v0, $zero
/* CCCC34 80241924 8482008E */  lh        $v0, 0x8e($a0)
/* CCCC38 80241928 9483008E */  lhu       $v1, 0x8e($a0)
/* CCCC3C 8024192C 18400005 */  blez      $v0, .L80241944
/* CCCC40 80241930 2462FFFF */   addiu    $v0, $v1, -1
/* CCCC44 80241934 A482008E */  sh        $v0, 0x8e($a0)
/* CCCC48 80241938 00021400 */  sll       $v0, $v0, 0x10
/* CCCC4C 8024193C 1C400006 */  bgtz      $v0, .L80241958
/* CCCC50 80241940 00000000 */   nop      
.L80241944:
/* CCCC54 80241944 8482008C */  lh        $v0, 0x8c($a0)
/* CCCC58 80241948 14400003 */  bnez      $v0, .L80241958
/* CCCC5C 8024194C 2402000E */   addiu    $v0, $zero, 0xe
/* CCCC60 80241950 A480008E */  sh        $zero, 0x8e($a0)
/* CCCC64 80241954 AE020070 */  sw        $v0, 0x70($s0)
.L80241958:
/* CCCC68 80241958 8FBF0014 */  lw        $ra, 0x14($sp)
/* CCCC6C 8024195C 8FB00010 */  lw        $s0, 0x10($sp)
/* CCCC70 80241960 03E00008 */  jr        $ra
/* CCCC74 80241964 27BD0018 */   addiu    $sp, $sp, 0x18
