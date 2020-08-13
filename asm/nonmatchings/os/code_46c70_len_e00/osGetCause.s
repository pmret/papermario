.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel osGetCause
/* 047A60 8006C660 40026800 */  mfc0  $v0, $13
/* 047A64 8006C664 03E00008 */  jr    $ra
/* 047A68 8006C668 00000000 */   nop   

/* 047A6C 8006C66C 00000000 */  nop   


