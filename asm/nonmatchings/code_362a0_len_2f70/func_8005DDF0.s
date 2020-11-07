.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005DDF0
/* 391F0 8005DDF0 3C02800B */  lui       $v0, %hi(gCurrentEncounter+0x8)
/* 391F4 8005DDF4 80420F18 */  lb        $v0, %lo(gCurrentEncounter+0x8)($v0)
/* 391F8 8005DDF8 00021027 */  nor       $v0, $zero, $v0
/* 391FC 8005DDFC 03E00008 */  jr        $ra
/* 39200 8005DE00 0002102B */   sltu     $v0, $zero, $v0
/* 39204 8005DE04 00000000 */  nop       
/* 39208 8005DE08 00000000 */  nop       
/* 3920C 8005DE0C 00000000 */  nop       
