.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802414C8_ECB1C8
/* ECB1C8 802414C8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* ECB1CC 802414CC AFB00010 */  sw        $s0, 0x10($sp)
/* ECB1D0 802414D0 0080802D */  daddu     $s0, $a0, $zero
/* ECB1D4 802414D4 AFBF0014 */  sw        $ra, 0x14($sp)
/* ECB1D8 802414D8 8E020148 */  lw        $v0, 0x148($s0)
/* ECB1DC 802414DC 0C00F92F */  jal       dead_get_npc_unsafe
/* ECB1E0 802414E0 84440008 */   lh       $a0, 8($v0)
/* ECB1E4 802414E4 9443008E */  lhu       $v1, 0x8e($v0)
/* ECB1E8 802414E8 2463FFFF */  addiu     $v1, $v1, -1
/* ECB1EC 802414EC A443008E */  sh        $v1, 0x8e($v0)
/* ECB1F0 802414F0 00031C00 */  sll       $v1, $v1, 0x10
/* ECB1F4 802414F4 50600001 */  beql      $v1, $zero, .L802414FC
/* ECB1F8 802414F8 AE000070 */   sw       $zero, 0x70($s0)
.L802414FC:
/* ECB1FC 802414FC 8FBF0014 */  lw        $ra, 0x14($sp)
/* ECB200 80241500 8FB00010 */  lw        $s0, 0x10($sp)
/* ECB204 80241504 03E00008 */  jr        $ra
/* ECB208 80241508 27BD0018 */   addiu    $sp, $sp, 0x18
