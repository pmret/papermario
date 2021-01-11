.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240020_ED8E40
/* ED8E40 80240020 3C028017 */  lui       $v0, %hi(D_80169B12)
/* ED8E44 80240024 84429B12 */  lh        $v0, %lo(D_80169B12)($v0)
/* ED8E48 80240028 AC820084 */  sw        $v0, 0x84($a0)
/* ED8E4C 8024002C 03E00008 */  jr        $ra
/* ED8E50 80240030 24020002 */   addiu    $v0, $zero, 2
