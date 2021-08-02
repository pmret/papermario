.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241904_EE7EB4
/* EE7EB4 80241904 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* EE7EB8 80241908 AFB00010 */  sw        $s0, 0x10($sp)
/* EE7EBC 8024190C 0080802D */  daddu     $s0, $a0, $zero
/* EE7EC0 80241910 AFBF0014 */  sw        $ra, 0x14($sp)
/* EE7EC4 80241914 8E020148 */  lw        $v0, 0x148($s0)
/* EE7EC8 80241918 0C00F92F */  jal       dead_get_npc_unsafe
/* EE7ECC 8024191C 84440008 */   lh       $a0, 8($v0)
/* EE7ED0 80241920 0040202D */  daddu     $a0, $v0, $zero
/* EE7ED4 80241924 8482008E */  lh        $v0, 0x8e($a0)
/* EE7ED8 80241928 9483008E */  lhu       $v1, 0x8e($a0)
/* EE7EDC 8024192C 18400005 */  blez      $v0, .L80241944
/* EE7EE0 80241930 2462FFFF */   addiu    $v0, $v1, -1
/* EE7EE4 80241934 A482008E */  sh        $v0, 0x8e($a0)
/* EE7EE8 80241938 00021400 */  sll       $v0, $v0, 0x10
/* EE7EEC 8024193C 1C400006 */  bgtz      $v0, .L80241958
/* EE7EF0 80241940 00000000 */   nop
.L80241944:
/* EE7EF4 80241944 8482008C */  lh        $v0, 0x8c($a0)
/* EE7EF8 80241948 14400003 */  bnez      $v0, .L80241958
/* EE7EFC 8024194C 2402000E */   addiu    $v0, $zero, 0xe
/* EE7F00 80241950 A480008E */  sh        $zero, 0x8e($a0)
/* EE7F04 80241954 AE020070 */  sw        $v0, 0x70($s0)
.L80241958:
/* EE7F08 80241958 8FBF0014 */  lw        $ra, 0x14($sp)
/* EE7F0C 8024195C 8FB00010 */  lw        $s0, 0x10($sp)
/* EE7F10 80241960 03E00008 */  jr        $ra
/* EE7F14 80241964 27BD0018 */   addiu    $sp, $sp, 0x18
