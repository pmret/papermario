.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802410BC
/* 99DA4C 802410BC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 99DA50 802410C0 AFB00010 */  sw        $s0, 0x10($sp)
/* 99DA54 802410C4 0080802D */  daddu     $s0, $a0, $zero
/* 99DA58 802410C8 AFBF0014 */  sw        $ra, 0x14($sp)
/* 99DA5C 802410CC 8E020148 */  lw        $v0, 0x148($s0)
/* 99DA60 802410D0 0C00EABB */  jal       get_npc_unsafe
/* 99DA64 802410D4 84440008 */   lh       $a0, 8($v0)
/* 99DA68 802410D8 9443008E */  lhu       $v1, 0x8e($v0)
/* 99DA6C 802410DC 2463FFFF */  addiu     $v1, $v1, -1
/* 99DA70 802410E0 A443008E */  sh        $v1, 0x8e($v0)
/* 99DA74 802410E4 00031C00 */  sll       $v1, $v1, 0x10
/* 99DA78 802410E8 14600002 */  bnez      $v1, .L802410F4
/* 99DA7C 802410EC 2402000F */   addiu    $v0, $zero, 0xf
/* 99DA80 802410F0 AE020070 */  sw        $v0, 0x70($s0)
.L802410F4:
/* 99DA84 802410F4 8FBF0014 */  lw        $ra, 0x14($sp)
/* 99DA88 802410F8 8FB00010 */  lw        $s0, 0x10($sp)
/* 99DA8C 802410FC 03E00008 */  jr        $ra
/* 99DA90 80241100 27BD0018 */   addiu    $sp, $sp, 0x18
