.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024309C_95E29C
/* 95E29C 8024309C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 95E2A0 802430A0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 95E2A4 802430A4 8C82000C */  lw        $v0, 0xc($a0)
/* 95E2A8 802430A8 3C068016 */  lui       $a2, 0x8016
/* 95E2AC 802430AC 84C6A552 */  lh        $a2, -0x5aae($a2)
/* 95E2B0 802430B0 0C0B2026 */  jal       set_variable
/* 95E2B4 802430B4 8C450000 */   lw       $a1, ($v0)
/* 95E2B8 802430B8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 95E2BC 802430BC 24020002 */  addiu     $v0, $zero, 2
/* 95E2C0 802430C0 03E00008 */  jr        $ra
/* 95E2C4 802430C4 27BD0018 */   addiu    $sp, $sp, 0x18
