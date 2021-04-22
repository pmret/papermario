.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005DAA0
/* 38EA0 8005DAA0 3C02800B */  lui       $v0, %hi(D_800B0EF8)
/* 38EA4 8005DAA4 80420EF8 */  lb        $v0, %lo(D_800B0EF8)($v0)
/* 38EA8 8005DAA8 00021027 */  nor       $v0, $zero, $v0
/* 38EAC 8005DAAC 03E00008 */  jr        $ra
/* 38EB0 8005DAB0 0002102B */   sltu     $v0, $zero, $v0
/* 38EB4 8005DAB4 00000000 */  nop
/* 38EB8 8005DAB8 00000000 */  nop
/* 38EBC 8005DABC 00000000 */  nop
