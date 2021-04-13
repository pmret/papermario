.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004D0A8
/* 284A8 8004D0A8 8CA20000 */  lw        $v0, ($a1)
/* 284AC 8004D0AC 90430000 */  lbu       $v1, ($v0)
/* 284B0 8004D0B0 24420001 */  addiu     $v0, $v0, 1
/* 284B4 8004D0B4 ACA20000 */  sw        $v0, ($a1)
/* 284B8 8004D0B8 A4A3005E */  sh        $v1, 0x5e($a1)
/* 284BC 8004D0BC 84A2005E */  lh        $v0, 0x5e($a1)
/* 284C0 8004D0C0 10400003 */  beqz      $v0, .L8004D0D0
/* 284C4 8004D0C4 00031200 */   sll      $v0, $v1, 8
/* 284C8 8004D0C8 344200FF */  ori       $v0, $v0, 0xff
/* 284CC 8004D0CC A4A2005E */  sh        $v0, 0x5e($a1)
.L8004D0D0:
/* 284D0 8004D0D0 03E00008 */  jr        $ra
/* 284D4 8004D0D4 00000000 */   nop
