.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241514_832D14
/* 832D14 80241514 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 832D18 80241518 3C058024 */  lui       $a1, %hi(D_802414A8)
/* 832D1C 8024151C 24A514A8 */  addiu     $a1, $a1, %lo(D_802414A8)
/* 832D20 80241520 AFBF0010 */  sw        $ra, 0x10($sp)
/* 832D24 80241524 0C048C8F */  jal       bind_dynamic_entity_7
/* 832D28 80241528 0000202D */   daddu    $a0, $zero, $zero
/* 832D2C 8024152C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 832D30 80241530 3C018025 */  lui       $at, %hi(D_802513D0)
/* 832D34 80241534 AC2213D0 */  sw        $v0, %lo(D_802513D0)($at)
/* 832D38 80241538 24020002 */  addiu     $v0, $zero, 2
/* 832D3C 8024153C 03E00008 */  jr        $ra
/* 832D40 80241540 27BD0018 */   addiu    $sp, $sp, 0x18
