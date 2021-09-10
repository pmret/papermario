.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024113C_CF8CAC
/* CF8CAC 8024113C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* CF8CB0 80241140 AFBF0010 */  sw        $ra, 0x10($sp)
/* CF8CB4 80241144 8C82000C */  lw        $v0, 0xc($a0)
/* CF8CB8 80241148 0C0B1EAF */  jal       evt_get_variable
/* CF8CBC 8024114C 8C450000 */   lw       $a1, ($v0)
/* CF8CC0 80241150 3C038025 */  lui       $v1, %hi(D_8024DF18)
/* CF8CC4 80241154 8C63DF18 */  lw        $v1, %lo(D_8024DF18)($v1)
/* CF8CC8 80241158 8C63000C */  lw        $v1, 0xc($v1)
/* CF8CCC 8024115C AC620034 */  sw        $v0, 0x34($v1)
/* CF8CD0 80241160 8FBF0010 */  lw        $ra, 0x10($sp)
/* CF8CD4 80241164 24020002 */  addiu     $v0, $zero, 2
/* CF8CD8 80241168 03E00008 */  jr        $ra
/* CF8CDC 8024116C 27BD0018 */   addiu    $sp, $sp, 0x18
