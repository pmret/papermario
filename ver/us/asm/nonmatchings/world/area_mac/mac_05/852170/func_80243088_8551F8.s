.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel mac_05_UnkFunc30
/* 8551F8 80243088 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8551FC 8024308C AFBF0010 */  sw        $ra, 0x10($sp)
/* 855200 80243090 8C82000C */  lw        $v0, 0xc($a0)
/* 855204 80243094 3C068016 */  lui       $a2, %hi(gCollisionStatus+0x2)
/* 855208 80243098 84C6A552 */  lh        $a2, %lo(gCollisionStatus+0x2)($a2)
/* 85520C 8024309C 0C0B2026 */  jal       set_variable
/* 855210 802430A0 8C450000 */   lw       $a1, ($v0)
/* 855214 802430A4 8FBF0010 */  lw        $ra, 0x10($sp)
/* 855218 802430A8 24020002 */  addiu     $v0, $zero, 2
/* 85521C 802430AC 03E00008 */  jr        $ra
/* 855220 802430B0 27BD0018 */   addiu    $sp, $sp, 0x18
