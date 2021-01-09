.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802406D4_B1D124
/* B1D124 802406D4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B1D128 802406D8 AFB00010 */  sw        $s0, 0x10($sp)
/* B1D12C 802406DC 0080802D */  daddu     $s0, $a0, $zero
/* B1D130 802406E0 3C048024 */  lui       $a0, %hi(func_80240730_B1CAAC)
/* B1D134 802406E4 24840730 */  addiu     $a0, $a0, %lo(func_80240730_B1CAAC)
/* B1D138 802406E8 AFBF0014 */  sw        $ra, 0x14($sp)
/* B1D13C 802406EC 0C048C56 */  jal       bind_dynamic_entity_3
/* B1D140 802406F0 0000282D */   daddu    $a1, $zero, $zero
/* B1D144 802406F4 8E03013C */  lw        $v1, 0x13c($s0)
/* B1D148 802406F8 2404FFFC */  addiu     $a0, $zero, -4
/* B1D14C 802406FC 0C00EAD2 */  jal       get_npc_safe
/* B1D150 80240700 AC620004 */   sw       $v0, 4($v1)
/* B1D154 80240704 0040282D */  daddu     $a1, $v0, $zero
/* B1D158 80240708 10A00005 */  beqz      $a1, .L80240720
/* B1D15C 8024070C 24020002 */   addiu    $v0, $zero, 2
/* B1D160 80240710 8CA30000 */  lw        $v1, ($a1)
/* B1D164 80240714 3C04000A */  lui       $a0, 0xa
/* B1D168 80240718 00641825 */  or        $v1, $v1, $a0
/* B1D16C 8024071C ACA30000 */  sw        $v1, ($a1)
.L80240720:
/* B1D170 80240720 8FBF0014 */  lw        $ra, 0x14($sp)
/* B1D174 80240724 8FB00010 */  lw        $s0, 0x10($sp)
/* B1D178 80240728 03E00008 */  jr        $ra
/* B1D17C 8024072C 27BD0018 */   addiu    $sp, $sp, 0x18
