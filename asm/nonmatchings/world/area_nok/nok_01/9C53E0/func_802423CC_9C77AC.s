.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802423CC_9C77AC
/* 9C77AC 802423CC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9C77B0 802423D0 AFB00010 */  sw        $s0, 0x10($sp)
/* 9C77B4 802423D4 0080802D */  daddu     $s0, $a0, $zero
/* 9C77B8 802423D8 AFBF0014 */  sw        $ra, 0x14($sp)
/* 9C77BC 802423DC 0C00EABB */  jal       get_npc_unsafe
/* 9C77C0 802423E0 8E04008C */   lw       $a0, 0x8c($s0)
/* 9C77C4 802423E4 0040282D */  daddu     $a1, $v0, $zero
/* 9C77C8 802423E8 8E040094 */  lw        $a0, 0x94($s0)
/* 9C77CC 802423EC 8CA30028 */  lw        $v1, 0x28($a1)
/* 9C77D0 802423F0 ACA40028 */  sw        $a0, 0x28($a1)
/* 9C77D4 802423F4 8FBF0014 */  lw        $ra, 0x14($sp)
/* 9C77D8 802423F8 8FB00010 */  lw        $s0, 0x10($sp)
/* 9C77DC 802423FC 24020002 */  addiu     $v0, $zero, 2
/* 9C77E0 80242400 3C018025 */  lui       $at, %hi(D_80251E34)
/* 9C77E4 80242404 AC231E34 */  sw        $v1, %lo(D_80251E34)($at)
/* 9C77E8 80242408 03E00008 */  jr        $ra
/* 9C77EC 8024240C 27BD0018 */   addiu    $sp, $sp, 0x18
