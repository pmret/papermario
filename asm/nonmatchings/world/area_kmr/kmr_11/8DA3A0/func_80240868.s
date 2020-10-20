.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240868
/* 8DA968 80240868 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8DA96C 8024086C AFB00010 */  sw        $s0, 0x10($sp)
/* 8DA970 80240870 0080802D */  daddu     $s0, $a0, $zero
/* 8DA974 80240874 AFBF0014 */  sw        $ra, 0x14($sp)
/* 8DA978 80240878 8E020148 */  lw        $v0, 0x148($s0)
/* 8DA97C 8024087C 0C00EABB */  jal       get_npc_unsafe
/* 8DA980 80240880 84440008 */   lh       $a0, 8($v0)
/* 8DA984 80240884 9443008E */  lhu       $v1, 0x8e($v0)
/* 8DA988 80240888 2463FFFF */  addiu     $v1, $v1, -1
/* 8DA98C 8024088C A443008E */  sh        $v1, 0x8e($v0)
/* 8DA990 80240890 00031C00 */  sll       $v1, $v1, 0x10
/* 8DA994 80240894 14600002 */  bnez      $v1, .L802408A0
/* 8DA998 80240898 2402000F */   addiu    $v0, $zero, 0xf
/* 8DA99C 8024089C AE020070 */  sw        $v0, 0x70($s0)
.L802408A0:
/* 8DA9A0 802408A0 8FBF0014 */  lw        $ra, 0x14($sp)
/* 8DA9A4 802408A4 8FB00010 */  lw        $s0, 0x10($sp)
/* 8DA9A8 802408A8 03E00008 */  jr        $ra
/* 8DA9AC 802408AC 27BD0018 */   addiu    $sp, $sp, 0x18
