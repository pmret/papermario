.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240808_BD4078
/* BD4078 80240808 3C048011 */  lui       $a0, %hi(gPlayerData)
/* BD407C 8024080C 2484F290 */  addiu     $a0, $a0, %lo(gPlayerData)
/* BD4080 80240810 80820002 */  lb        $v0, 2($a0)
/* BD4084 80240814 90830002 */  lbu       $v1, 2($a0)
/* BD4088 80240818 28420002 */  slti      $v0, $v0, 2
/* BD408C 8024081C 14400004 */  bnez      $v0, .L80240830
/* BD4090 80240820 2462FFFF */   addiu    $v0, $v1, -1
/* BD4094 80240824 A0820002 */  sb        $v0, 2($a0)
/* BD4098 80240828 03E00008 */  jr        $ra
/* BD409C 8024082C 24020002 */   addiu    $v0, $zero, 2
.L80240830:
/* BD40A0 80240830 03E00008 */  jr        $ra
/* BD40A4 80240834 24020002 */   addiu    $v0, $zero, 2
/* BD40A8 80240838 00000000 */  nop
/* BD40AC 8024083C 00000000 */  nop
