.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024060C_99A27C
/* 99A27C 8024060C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 99A280 80240610 AFBF0010 */  sw        $ra, 0x10($sp)
/* 99A284 80240614 0C03A6DB */  jal       sync_status_menu
/* 99A288 80240618 00000000 */   nop      
/* 99A28C 8024061C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 99A290 80240620 24020002 */  addiu     $v0, $zero, 2
/* 99A294 80240624 03E00008 */  jr        $ra
/* 99A298 80240628 27BD0018 */   addiu    $sp, $sp, 0x18
/* 99A29C 8024062C 00000000 */  nop       
