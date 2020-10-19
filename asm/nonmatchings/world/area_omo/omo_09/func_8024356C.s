.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024356C
/* DD023C 8024356C 8C830148 */  lw        $v1, 0x148($a0)
/* DD0240 80243570 24020003 */  addiu     $v0, $zero, 3
/* DD0244 80243574 A06200B5 */  sb        $v0, 0xb5($v1)
/* DD0248 80243578 03E00008 */  jr        $ra
/* DD024C 8024357C 24020002 */   addiu    $v0, $zero, 2
