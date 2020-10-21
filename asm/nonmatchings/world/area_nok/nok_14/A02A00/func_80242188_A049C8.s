.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242188_A049C8
/* A049C8 80242188 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A049CC 8024218C AFB00010 */  sw        $s0, 0x10($sp)
/* A049D0 80242190 0080802D */  daddu     $s0, $a0, $zero
/* A049D4 80242194 AFBF0014 */  sw        $ra, 0x14($sp)
/* A049D8 80242198 8E020148 */  lw        $v0, 0x148($s0)
/* A049DC 8024219C 0C00EABB */  jal       get_npc_unsafe
/* A049E0 802421A0 84440008 */   lh       $a0, 8($v0)
/* A049E4 802421A4 9443008E */  lhu       $v1, 0x8e($v0)
/* A049E8 802421A8 2463FFFF */  addiu     $v1, $v1, -1
/* A049EC 802421AC A443008E */  sh        $v1, 0x8e($v0)
/* A049F0 802421B0 00031C00 */  sll       $v1, $v1, 0x10
/* A049F4 802421B4 58600001 */  blezl     $v1, .L802421BC
/* A049F8 802421B8 AE000070 */   sw       $zero, 0x70($s0)
.L802421BC:
/* A049FC 802421BC 8FBF0014 */  lw        $ra, 0x14($sp)
/* A04A00 802421C0 8FB00010 */  lw        $s0, 0x10($sp)
/* A04A04 802421C4 03E00008 */  jr        $ra
/* A04A08 802421C8 27BD0018 */   addiu    $sp, $sp, 0x18
