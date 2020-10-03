.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel nuContRmbMgrRemove
/* 3B0EC 8005FCEC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3B0F0 8005FCF0 3C048009 */  lui       $a0, 0x8009
/* 3B0F4 8005FCF4 24843D00 */  addiu     $a0, $a0, 0x3d00
/* 3B0F8 8005FCF8 AFBF0010 */  sw        $ra, 0x10($sp)
/* 3B0FC 8005FCFC 0C018124 */  jal       nuSiCallBackRemove
/* 3B100 8005FD00 00000000 */   nop      
/* 3B104 8005FD04 8FBF0010 */  lw        $ra, 0x10($sp)
/* 3B108 8005FD08 03E00008 */  jr        $ra
/* 3B10C 8005FD0C 27BD0018 */   addiu    $sp, $sp, 0x18
