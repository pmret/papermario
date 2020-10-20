.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024106C_B7B0BC
/* B7B0BC 8024106C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B7B0C0 80241070 AFB00010 */  sw        $s0, 0x10($sp)
/* B7B0C4 80241074 0080802D */  daddu     $s0, $a0, $zero
/* B7B0C8 80241078 AFBF0014 */  sw        $ra, 0x14($sp)
/* B7B0CC 8024107C 8E020148 */  lw        $v0, 0x148($s0)
/* B7B0D0 80241080 0C00EABB */  jal       get_npc_unsafe
/* B7B0D4 80241084 84440008 */   lh       $a0, 8($v0)
/* B7B0D8 80241088 9443008E */  lhu       $v1, 0x8e($v0)
/* B7B0DC 8024108C 2463FFFF */  addiu     $v1, $v1, -1
/* B7B0E0 80241090 A443008E */  sh        $v1, 0x8e($v0)
/* B7B0E4 80241094 00031C00 */  sll       $v1, $v1, 0x10
/* B7B0E8 80241098 58600001 */  blezl     $v1, .L802410A0
/* B7B0EC 8024109C AE000070 */   sw       $zero, 0x70($s0)
.L802410A0:
/* B7B0F0 802410A0 8FBF0014 */  lw        $ra, 0x14($sp)
/* B7B0F4 802410A4 8FB00010 */  lw        $s0, 0x10($sp)
/* B7B0F8 802410A8 03E00008 */  jr        $ra
/* B7B0FC 802410AC 27BD0018 */   addiu    $sp, $sp, 0x18
