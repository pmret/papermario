.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802402D0_A78790
/* A78790 802402D0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A78794 802402D4 AFBF0010 */  sw        $ra, 0x10($sp)
/* A78798 802402D8 8C82000C */  lw        $v0, 0xc($a0)
/* A7879C 802402DC 0C0B1EAF */  jal       get_variable
/* A787A0 802402E0 8C450000 */   lw       $a1, ($v0)
/* A787A4 802402E4 3C018024 */  lui       $at, %hi(D_80240D9C)
/* A787A8 802402E8 AC220D9C */  sw        $v0, %lo(D_80240D9C)($at)
/* A787AC 802402EC 24020002 */  addiu     $v0, $zero, 2
/* A787B0 802402F0 8FBF0010 */  lw        $ra, 0x10($sp)
/* A787B4 802402F4 24030001 */  addiu     $v1, $zero, 1
/* A787B8 802402F8 3C018024 */  lui       $at, %hi(func_80240D98_99D728)
/* A787BC 802402FC AC230D98 */  sw        $v1, %lo(func_80240D98_99D728)($at)
/* A787C0 80240300 03E00008 */  jr        $ra
/* A787C4 80240304 27BD0018 */   addiu    $sp, $sp, 0x18
