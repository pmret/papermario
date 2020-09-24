.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8025CD28
/* 18B608 8025CD28 8CA300C0 */  lw        $v1, 0xc0($a1)
/* 18B60C 8025CD2C 80620765 */  lb        $v0, 0x765($v1)
/* 18B610 8025CD30 54400001 */  bnel      $v0, $zero, .L8025CD38
/* 18B614 8025CD34 A0600765 */   sb       $zero, 0x765($v1)
.L8025CD38:
/* 18B618 8025CD38 03E00008 */  jr        $ra
/* 18B61C 8025CD3C A0600768 */   sb       $zero, 0x768($v1)
