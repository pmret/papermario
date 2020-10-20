.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241540_B2D9B0
/* B2D9B0 80241540 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B2D9B4 80241544 AFBF0010 */  sw        $ra, 0x10($sp)
/* B2D9B8 80241548 8C82000C */  lw        $v0, 0xc($a0)
/* B2D9BC 8024154C 0C0B1EAF */  jal       get_variable
/* B2D9C0 80241550 8C450000 */   lw       $a1, ($v0)
/* B2D9C4 80241554 3C018024 */  lui       $at, 0x8024
/* B2D9C8 80241558 AC22304C */  sw        $v0, 0x304c($at)
/* B2D9CC 8024155C 24020002 */  addiu     $v0, $zero, 2
/* B2D9D0 80241560 8FBF0010 */  lw        $ra, 0x10($sp)
/* B2D9D4 80241564 24030001 */  addiu     $v1, $zero, 1
/* B2D9D8 80241568 3C018024 */  lui       $at, 0x8024
/* B2D9DC 8024156C AC233048 */  sw        $v1, 0x3048($at)
/* B2D9E0 80241570 03E00008 */  jr        $ra
/* B2D9E4 80241574 27BD0018 */   addiu    $sp, $sp, 0x18
