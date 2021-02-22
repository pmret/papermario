.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243088_826348
/* 826348 80243088 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 82634C 8024308C AFB00010 */  sw        $s0, 0x10($sp)
/* 826350 80243090 0080802D */  daddu     $s0, $a0, $zero
/* 826354 80243094 AFBF0018 */  sw        $ra, 0x18($sp)
/* 826358 80243098 AFB10014 */  sw        $s1, 0x14($sp)
/* 82635C 8024309C 8E02000C */  lw        $v0, 0xc($s0)
/* 826360 802430A0 0C039D88 */  jal       get_item_empty_count
/* 826364 802430A4 8C510000 */   lw       $s1, ($v0)
/* 826368 802430A8 0200202D */  daddu     $a0, $s0, $zero
/* 82636C 802430AC 0040302D */  daddu     $a2, $v0, $zero
/* 826370 802430B0 0C0B2026 */  jal       set_variable
/* 826374 802430B4 0220282D */   daddu    $a1, $s1, $zero
/* 826378 802430B8 8FBF0018 */  lw        $ra, 0x18($sp)
/* 82637C 802430BC 8FB10014 */  lw        $s1, 0x14($sp)
/* 826380 802430C0 8FB00010 */  lw        $s0, 0x10($sp)
/* 826384 802430C4 24020002 */  addiu     $v0, $zero, 2
/* 826388 802430C8 03E00008 */  jr        $ra
/* 82638C 802430CC 27BD0020 */   addiu    $sp, $sp, 0x20
