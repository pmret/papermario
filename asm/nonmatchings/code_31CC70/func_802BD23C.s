.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BD23C
/* 31CDAC 802BD23C 24020018 */  addiu     $v0, $zero, 0x18
/* 31CDB0 802BD240 A48200A8 */  sh        $v0, 0xa8($a0)
/* 31CDB4 802BD244 A48200A6 */  sh        $v0, 0xa6($a0)
/* 31CDB8 802BD248 24020014 */  addiu     $v0, $zero, 0x14
/* 31CDBC 802BD24C 3C01802C */  lui       $at, 0x802c
/* 31CDC0 802BD250 AC20E308 */  sw        $zero, -0x1cf8($at)
/* 31CDC4 802BD254 3C01802C */  lui       $at, 0x802c
/* 31CDC8 802BD258 AC20E300 */  sw        $zero, -0x1d00($at)
/* 31CDCC 802BD25C 3C01802C */  lui       $at, 0x802c
/* 31CDD0 802BD260 AC20E30C */  sw        $zero, -0x1cf4($at)
/* 31CDD4 802BD264 3C01802C */  lui       $at, 0x802c
/* 31CDD8 802BD268 AC22E304 */  sw        $v0, -0x1cfc($at)
/* 31CDDC 802BD26C 3C01802C */  lui       $at, 0x802c
/* 31CDE0 802BD270 AC20E310 */  sw        $zero, -0x1cf0($at)
/* 31CDE4 802BD274 03E00008 */  jr        $ra
/* 31CDE8 802BD278 00000000 */   nop      
