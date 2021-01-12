.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel osGetCause
/* 47A60 8006C660 40026800 */  mfc0      $v0, $13
/* 47A64 8006C664 03E00008 */  jr        $ra
/* 47A68 8006C668 00000000 */   nop
/* 47A6C 8006C66C 00000000 */  nop
