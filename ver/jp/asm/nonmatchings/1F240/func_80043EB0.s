.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80043EB0
/* 1F2B0 80043EB0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 1F2B4 80043EB4 AFB00010 */  sw        $s0, 0x10($sp)
/* 1F2B8 80043EB8 0080802D */  daddu     $s0, $a0, $zero
/* 1F2BC 80043EBC AFBF0018 */  sw        $ra, 0x18($sp)
/* 1F2C0 80043EC0 AFB10014 */  sw        $s1, 0x14($sp)
/* 1F2C4 80043EC4 8E02000C */  lw        $v0, 0xc($s0)
/* 1F2C8 80043EC8 0C010F82 */  jal       func_80043E08
/* 1F2CC 80043ECC 8C510000 */   lw       $s1, ($v0)
/* 1F2D0 80043ED0 0200202D */  daddu     $a0, $s0, $zero
/* 1F2D4 80043ED4 0040302D */  daddu     $a2, $v0, $zero
/* 1F2D8 80043ED8 0C0B2026 */  jal       func_802C8098
/* 1F2DC 80043EDC 0220282D */   daddu    $a1, $s1, $zero
/* 1F2E0 80043EE0 8FBF0018 */  lw        $ra, 0x18($sp)
/* 1F2E4 80043EE4 8FB10014 */  lw        $s1, 0x14($sp)
/* 1F2E8 80043EE8 8FB00010 */  lw        $s0, 0x10($sp)
/* 1F2EC 80043EEC 24020002 */  addiu     $v0, $zero, 2
/* 1F2F0 80043EF0 03E00008 */  jr        $ra
/* 1F2F4 80043EF4 27BD0020 */   addiu    $sp, $sp, 0x20
