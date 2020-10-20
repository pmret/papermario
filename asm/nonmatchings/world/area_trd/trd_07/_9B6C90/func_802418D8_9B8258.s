.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802418D8_9B8258
/* 9B8258 802418D8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9B825C 802418DC AFB00010 */  sw        $s0, 0x10($sp)
/* 9B8260 802418E0 0080802D */  daddu     $s0, $a0, $zero
/* 9B8264 802418E4 AFBF0014 */  sw        $ra, 0x14($sp)
/* 9B8268 802418E8 8E020148 */  lw        $v0, 0x148($s0)
/* 9B826C 802418EC 0C00EABB */  jal       get_npc_unsafe
/* 9B8270 802418F0 84440008 */   lh       $a0, 8($v0)
/* 9B8274 802418F4 0040202D */  daddu     $a0, $v0, $zero
/* 9B8278 802418F8 8482008E */  lh        $v0, 0x8e($a0)
/* 9B827C 802418FC 9483008E */  lhu       $v1, 0x8e($a0)
/* 9B8280 80241900 18400005 */  blez      $v0, .L80241918
/* 9B8284 80241904 2462FFFF */   addiu    $v0, $v1, -1
/* 9B8288 80241908 A482008E */  sh        $v0, 0x8e($a0)
/* 9B828C 8024190C 00021400 */  sll       $v0, $v0, 0x10
/* 9B8290 80241910 1C400006 */  bgtz      $v0, .L8024192C
/* 9B8294 80241914 00000000 */   nop      
.L80241918:
/* 9B8298 80241918 8482008C */  lh        $v0, 0x8c($a0)
/* 9B829C 8024191C 14400003 */  bnez      $v0, .L8024192C
/* 9B82A0 80241920 2402000E */   addiu    $v0, $zero, 0xe
/* 9B82A4 80241924 A480008E */  sh        $zero, 0x8e($a0)
/* 9B82A8 80241928 AE020070 */  sw        $v0, 0x70($s0)
.L8024192C:
/* 9B82AC 8024192C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 9B82B0 80241930 8FB00010 */  lw        $s0, 0x10($sp)
/* 9B82B4 80241934 03E00008 */  jr        $ra
/* 9B82B8 80241938 27BD0018 */   addiu    $sp, $sp, 0x18
