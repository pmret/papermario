.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024137C_C9F29C
/* C9F29C 8024137C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C9F2A0 80241380 AFBF0010 */  sw        $ra, 0x10($sp)
/* C9F2A4 80241384 0C03A6DB */  jal       sync_status_menu
/* C9F2A8 80241388 00000000 */   nop      
/* C9F2AC 8024138C 8FBF0010 */  lw        $ra, 0x10($sp)
/* C9F2B0 80241390 24020002 */  addiu     $v0, $zero, 2
/* C9F2B4 80241394 03E00008 */  jr        $ra
/* C9F2B8 80241398 27BD0018 */   addiu    $sp, $sp, 0x18
