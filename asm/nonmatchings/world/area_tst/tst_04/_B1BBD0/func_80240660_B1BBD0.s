.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240660_B1BBD0
/* B1BBD0 80240660 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B1BBD4 80240664 AFBF0010 */  sw        $ra, 0x10($sp)
/* B1BBD8 80240668 8C820148 */  lw        $v0, 0x148($a0)
/* B1BBDC 8024066C 0C00EABB */  jal       get_npc_unsafe
/* B1BBE0 80240670 84440008 */   lh       $a0, 8($v0)
/* B1BBE4 80240674 0C00EAFF */  jal       disable_npc_shadow
/* B1BBE8 80240678 0040202D */   daddu    $a0, $v0, $zero
/* B1BBEC 8024067C 8FBF0010 */  lw        $ra, 0x10($sp)
/* B1BBF0 80240680 24020002 */  addiu     $v0, $zero, 2
/* B1BBF4 80240684 03E00008 */  jr        $ra
/* B1BBF8 80240688 27BD0018 */   addiu    $sp, $sp, 0x18
/* B1BBFC 8024068C 00000000 */  nop       
