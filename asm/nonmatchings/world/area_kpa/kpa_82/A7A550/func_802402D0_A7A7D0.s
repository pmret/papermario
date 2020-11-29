.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802402D0_A7A7D0
/* A7A7D0 802402D0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A7A7D4 802402D4 AFBF0010 */  sw        $ra, 0x10($sp)
/* A7A7D8 802402D8 8C82000C */  lw        $v0, 0xc($a0)
/* A7A7DC 802402DC 0C0B1EAF */  jal       get_variable
/* A7A7E0 802402E0 8C450000 */   lw       $a1, ($v0)
/* A7A7E4 802402E4 3C018024 */  lui       $at, %hi(D_80240C24)
/* A7A7E8 802402E8 AC220C24 */  sw        $v0, %lo(D_80240C24)($at)
/* A7A7EC 802402EC 24020002 */  addiu     $v0, $zero, 2
/* A7A7F0 802402F0 8FBF0010 */  lw        $ra, 0x10($sp)
/* A7A7F4 802402F4 24030001 */  addiu     $v1, $zero, 1
/* A7A7F8 802402F8 3C018024 */  lui       $at, %hi(D_80240C20)
/* A7A7FC 802402FC AC230C20 */  sw        $v1, %lo(D_80240C20)($at)
/* A7A800 80240300 03E00008 */  jr        $ra
/* A7A804 80240304 27BD0018 */   addiu    $sp, $sp, 0x18
