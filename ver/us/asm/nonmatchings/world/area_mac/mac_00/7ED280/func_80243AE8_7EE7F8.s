.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243AE8_7EE7F8
/* 7EE7F8 80243AE8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 7EE7FC 80243AEC AFB00010 */  sw        $s0, 0x10($sp)
/* 7EE800 80243AF0 0080802D */  daddu     $s0, $a0, $zero
/* 7EE804 80243AF4 AFBF0014 */  sw        $ra, 0x14($sp)
/* 7EE808 80243AF8 0C00EABB */  jal       get_npc_unsafe
/* 7EE80C 80243AFC 8E04008C */   lw       $a0, 0x8c($s0)
/* 7EE810 80243B00 0040282D */  daddu     $a1, $v0, $zero
/* 7EE814 80243B04 8E040094 */  lw        $a0, 0x94($s0)
/* 7EE818 80243B08 8CA30028 */  lw        $v1, 0x28($a1)
/* 7EE81C 80243B0C ACA40028 */  sw        $a0, 0x28($a1)
/* 7EE820 80243B10 8FBF0014 */  lw        $ra, 0x14($sp)
/* 7EE824 80243B14 8FB00010 */  lw        $s0, 0x10($sp)
/* 7EE828 80243B18 24020002 */  addiu     $v0, $zero, 2
/* 7EE82C 80243B1C 3C018025 */  lui       $at, %hi(D_802560A4)
/* 7EE830 80243B20 AC2360A4 */  sw        $v1, %lo(D_802560A4)($at)
/* 7EE834 80243B24 03E00008 */  jr        $ra
/* 7EE838 80243B28 27BD0018 */   addiu    $sp, $sp, 0x18
