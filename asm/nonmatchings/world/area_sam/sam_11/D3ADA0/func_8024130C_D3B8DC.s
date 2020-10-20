.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024130C_D3B8DC
/* D3B8DC 8024130C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D3B8E0 80241310 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* D3B8E4 80241314 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* D3B8E8 80241318 3C05FE36 */  lui       $a1, 0xfe36
/* D3B8EC 8024131C AFBF0010 */  sw        $ra, 0x10($sp)
/* D3B8F0 80241320 80460075 */  lb        $a2, 0x75($v0)
/* D3B8F4 80241324 0C0B2026 */  jal       set_variable
/* D3B8F8 80241328 34A53C80 */   ori      $a1, $a1, 0x3c80
/* D3B8FC 8024132C 8FBF0010 */  lw        $ra, 0x10($sp)
/* D3B900 80241330 24020002 */  addiu     $v0, $zero, 2
/* D3B904 80241334 03E00008 */  jr        $ra
/* D3B908 80241338 27BD0018 */   addiu    $sp, $sp, 0x18
