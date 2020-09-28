.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel nuContPakMgrRemove
/* 3AAD4 8005F6D4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3AAD8 8005F6D8 3C048009 */  lui       $a0, 0x8009
/* 3AADC 8005F6DC 24843CD0 */  addiu     $a0, $a0, 0x3cd0
/* 3AAE0 8005F6E0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 3AAE4 8005F6E4 0C018124 */  jal       nuSiCallBackRemove
/* 3AAE8 8005F6E8 00000000 */   nop      
/* 3AAEC 8005F6EC 8FBF0010 */  lw        $ra, 0x10($sp)
/* 3AAF0 8005F6F0 03E00008 */  jr        $ra
/* 3AAF4 8005F6F4 27BD0018 */   addiu    $sp, $sp, 0x18
