.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241800_EAA2E0
/* EAA2E0 80241800 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* EAA2E4 80241804 AFBF0010 */  sw        $ra, 0x10($sp)
/* EAA2E8 80241808 8C82000C */  lw        $v0, 0xc($a0)
/* EAA2EC 8024180C 0C0B53A3 */  jal       dead_get_variable
/* EAA2F0 80241810 8C450000 */   lw       $a1, ($v0)
/* EAA2F4 80241814 3C018024 */  lui       $at, %hi(D_80243DDC_EAC8BC)
/* EAA2F8 80241818 AC223DDC */  sw        $v0, %lo(D_80243DDC_EAC8BC)($at)
/* EAA2FC 8024181C 24020002 */  addiu     $v0, $zero, 2
/* EAA300 80241820 8FBF0010 */  lw        $ra, 0x10($sp)
/* EAA304 80241824 24030001 */  addiu     $v1, $zero, 1
/* EAA308 80241828 3C018024 */  lui       $at, %hi(D_80243DD8_EAC8B8)
/* EAA30C 8024182C AC233DD8 */  sw        $v1, %lo(D_80243DD8_EAC8B8)($at)
/* EAA310 80241830 03E00008 */  jr        $ra
/* EAA314 80241834 27BD0018 */   addiu    $sp, $sp, 0x18
