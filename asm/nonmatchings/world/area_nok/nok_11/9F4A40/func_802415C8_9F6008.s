.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802415C8_9F6008
/* 9F6008 802415C8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9F600C 802415CC AFB00010 */  sw        $s0, 0x10($sp)
/* 9F6010 802415D0 0080802D */  daddu     $s0, $a0, $zero
/* 9F6014 802415D4 AFBF0014 */  sw        $ra, 0x14($sp)
/* 9F6018 802415D8 8E020148 */  lw        $v0, 0x148($s0)
/* 9F601C 802415DC 0C00EABB */  jal       get_npc_unsafe
/* 9F6020 802415E0 84440008 */   lh       $a0, 8($v0)
/* 9F6024 802415E4 0040202D */  daddu     $a0, $v0, $zero
/* 9F6028 802415E8 8482008E */  lh        $v0, 0x8e($a0)
/* 9F602C 802415EC 9483008E */  lhu       $v1, 0x8e($a0)
/* 9F6030 802415F0 18400005 */  blez      $v0, .L80241608
/* 9F6034 802415F4 2462FFFF */   addiu    $v0, $v1, -1
/* 9F6038 802415F8 A482008E */  sh        $v0, 0x8e($a0)
/* 9F603C 802415FC 00021400 */  sll       $v0, $v0, 0x10
/* 9F6040 80241600 1C400006 */  bgtz      $v0, .L8024161C
/* 9F6044 80241604 00000000 */   nop      
.L80241608:
/* 9F6048 80241608 8482008C */  lh        $v0, 0x8c($a0)
/* 9F604C 8024160C 14400003 */  bnez      $v0, .L8024161C
/* 9F6050 80241610 2402000E */   addiu    $v0, $zero, 0xe
/* 9F6054 80241614 A480008E */  sh        $zero, 0x8e($a0)
/* 9F6058 80241618 AE020070 */  sw        $v0, 0x70($s0)
.L8024161C:
/* 9F605C 8024161C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 9F6060 80241620 8FB00010 */  lw        $s0, 0x10($sp)
/* 9F6064 80241624 03E00008 */  jr        $ra
/* 9F6068 80241628 27BD0018 */   addiu    $sp, $sp, 0x18
