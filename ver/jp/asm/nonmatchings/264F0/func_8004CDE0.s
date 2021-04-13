.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004CDE0
/* 281E0 8004CDE0 90A2008C */  lbu       $v0, 0x8c($a1)
/* 281E4 8004CDE4 10400005 */  beqz      $v0, .L8004CDFC
/* 281E8 8004CDE8 2442FFFF */   addiu    $v0, $v0, -1
/* 281EC 8004CDEC A0A2008C */  sb        $v0, 0x8c($a1)
/* 281F0 8004CDF0 304200FF */  andi      $v0, $v0, 0xff
/* 281F4 8004CDF4 10400003 */  beqz      $v0, .L8004CE04
/* 281F8 8004CDF8 00000000 */   nop
.L8004CDFC:
/* 281FC 8004CDFC 8CA20088 */  lw        $v0, 0x88($a1)
/* 28200 8004CE00 ACA20000 */  sw        $v0, ($a1)
.L8004CE04:
/* 28204 8004CE04 03E00008 */  jr        $ra
/* 28208 8004CE08 00000000 */   nop
