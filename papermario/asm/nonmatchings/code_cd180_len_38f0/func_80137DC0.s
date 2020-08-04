.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80137DC0
/* 0CE4C0 80137DC0 10800005 */  beqz  $a0, .L80137DD8
/* 0CE4C4 80137DC4 24020001 */   addiu $v0, $zero, 1
/* 0CE4C8 80137DC8 1082000A */  beq   $a0, $v0, .L80137DF4
/* 0CE4CC 80137DCC 00000000 */   nop   
/* 0CE4D0 80137DD0 03E00008 */  jr    $ra
/* 0CE4D4 80137DD4 00000000 */   nop   

.L80137DD8:
/* 0CE4D8 80137DD8 3C028015 */  lui   $v0, 0x8015
/* 0CE4DC 80137DDC 90426903 */  lbu   $v0, 0x6903($v0)
/* 0CE4E0 80137DE0 A0A20000 */  sb    $v0, ($a1)
/* 0CE4E4 80137DE4 3C018015 */  lui   $at, 0x8015
/* 0CE4E8 80137DE8 C4206904 */  lwc1  $f0, 0x6904($at)
/* 0CE4EC 80137DEC 03E00008 */  jr    $ra
/* 0CE4F0 80137DF0 E4C00000 */   swc1  $f0, ($a2)

.L80137DF4:
/* 0CE4F4 80137DF4 3C028015 */  lui   $v0, 0x8015
/* 0CE4F8 80137DF8 9042690B */  lbu   $v0, 0x690b($v0)
/* 0CE4FC 80137DFC A0A20000 */  sb    $v0, ($a1)
/* 0CE500 80137E00 3C018015 */  lui   $at, 0x8015
/* 0CE504 80137E04 C420690C */  lwc1  $f0, 0x690c($at)
/* 0CE508 80137E08 03E00008 */  jr    $ra
/* 0CE50C 80137E0C E4C00000 */   swc1  $f0, ($a2)

