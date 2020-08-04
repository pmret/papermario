.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel nuGfxDisplayOn
/* 03A830 8005F430 24020080 */  addiu $v0, $zero, 0x80
/* 03A834 8005F434 3C01800A */  lui   $at, 0x800a
/* 03A838 8005F438 AC22A5F8 */  sw    $v0, -0x5a08($at)
/* 03A83C 8005F43C 03E00008 */  jr    $ra
/* 03A840 8005F440 00000000 */   nop   

/* 03A844 8005F444 00000000 */  nop   
/* 03A848 8005F448 00000000 */  nop   
/* 03A84C 8005F44C 00000000 */  nop   

.set reorder
