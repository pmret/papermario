.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241800_C8F3B0
/* C8F3B0 80241800 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C8F3B4 80241804 AFBF0010 */  sw        $ra, 0x10($sp)
/* C8F3B8 80241808 8C82000C */  lw        $v0, 0xc($a0)
/* C8F3BC 8024180C 0C0B1EAF */  jal       evt_get_variable
/* C8F3C0 80241810 8C450000 */   lw       $a1, ($v0)
/* C8F3C4 80241814 3C018024 */  lui       $at, %hi(D_80243DDC_C9198C)
/* C8F3C8 80241818 AC223DDC */  sw        $v0, %lo(D_80243DDC_C9198C)($at)
/* C8F3CC 8024181C 24020002 */  addiu     $v0, $zero, 2
/* C8F3D0 80241820 8FBF0010 */  lw        $ra, 0x10($sp)
/* C8F3D4 80241824 24030001 */  addiu     $v1, $zero, 1
/* C8F3D8 80241828 3C018024 */  lui       $at, %hi(D_80243DD8_C91988)
/* C8F3DC 8024182C AC233DD8 */  sw        $v1, %lo(D_80243DD8_C91988)($at)
/* C8F3E0 80241830 03E00008 */  jr        $ra
/* C8F3E4 80241834 27BD0018 */   addiu    $sp, $sp, 0x18
