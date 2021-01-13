.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004A6F0
/* 25AF0 8004A6F0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 25AF4 8004A6F4 AFB00010 */  sw        $s0, 0x10($sp)
/* 25AF8 8004A6F8 0080802D */  daddu     $s0, $a0, $zero
/* 25AFC 8004A6FC AFBF0014 */  sw        $ra, 0x14($sp)
/* 25B00 8004A700 8E020148 */  lw        $v0, 0x148($s0)
/* 25B04 8004A704 0C00EABB */  jal       get_npc_unsafe
/* 25B08 8004A708 84440008 */   lh       $a0, 8($v0)
/* 25B0C 8004A70C 9443008E */  lhu       $v1, 0x8e($v0)
/* 25B10 8004A710 2463FFFF */  addiu     $v1, $v1, -1
/* 25B14 8004A714 A443008E */  sh        $v1, 0x8e($v0)
/* 25B18 8004A718 00031C00 */  sll       $v1, $v1, 0x10
/* 25B1C 8004A71C 1C600003 */  bgtz      $v1, .L8004A72C
/* 25B20 8004A720 00000000 */   nop
/* 25B24 8004A724 8E020074 */  lw        $v0, 0x74($s0)
/* 25B28 8004A728 AE020070 */  sw        $v0, 0x70($s0)
.L8004A72C:
/* 25B2C 8004A72C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 25B30 8004A730 8FB00010 */  lw        $s0, 0x10($sp)
/* 25B34 8004A734 03E00008 */  jr        $ra
/* 25B38 8004A738 27BD0018 */   addiu    $sp, $sp, 0x18
