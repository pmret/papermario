.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel snd_SEFCmd_00_SetVolume
/* 28270 8004CE70 8CA20000 */  lw        $v0, ($a1)
/* 28274 8004CE74 90430000 */  lbu       $v1, ($v0)
/* 28278 8004CE78 24420001 */  addiu     $v0, $v0, 1
/* 2827C 8004CE7C ACA20000 */  sw        $v0, ($a1)
/* 28280 8004CE80 A4A3005C */  sh        $v1, 0x5c($a1)
/* 28284 8004CE84 84A2005C */  lh        $v0, 0x5c($a1)
/* 28288 8004CE88 10400003 */  beqz      $v0, .L8004CE98
/* 2828C 8004CE8C 00031200 */   sll      $v0, $v1, 8
/* 28290 8004CE90 344200FF */  ori       $v0, $v0, 0xff
/* 28294 8004CE94 A4A2005C */  sh        $v0, 0x5c($a1)
.L8004CE98:
/* 28298 8004CE98 24020001 */  addiu     $v0, $zero, 1
/* 2829C 8004CE9C 03E00008 */  jr        $ra
/* 282A0 8004CEA0 A0A20055 */   sb       $v0, 0x55($a1)
