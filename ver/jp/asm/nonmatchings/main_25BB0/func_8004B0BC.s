.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004B0BC
/* 264BC 8004B0BC 8C830000 */  lw        $v1, ($a0)
/* 264C0 8004B0C0 10600003 */  beqz      $v1, .L8004B0D0
/* 264C4 8004B0C4 00000000 */   nop
/* 264C8 8004B0C8 8C820004 */  lw        $v0, 4($a0)
/* 264CC 8004B0CC AC620004 */  sw        $v0, 4($v1)
.L8004B0D0:
/* 264D0 8004B0D0 8C830004 */  lw        $v1, 4($a0)
/* 264D4 8004B0D4 10600003 */  beqz      $v1, .L8004B0E4
/* 264D8 8004B0D8 00000000 */   nop
/* 264DC 8004B0DC 8C820000 */  lw        $v0, ($a0)
/* 264E0 8004B0E0 AC620000 */  sw        $v0, ($v1)
.L8004B0E4:
/* 264E4 8004B0E4 03E00008 */  jr        $ra
/* 264E8 8004B0E8 00000000 */   nop
/* 264EC 8004B0EC 00000000 */  nop
