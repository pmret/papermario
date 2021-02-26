.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004CF94
/* 28394 8004CF94 8CA30000 */  lw        $v1, ($a1)
/* 28398 8004CF98 24620002 */  addiu     $v0, $v1, 2
/* 2839C 8004CF9C ACA20050 */  sw        $v0, 0x50($a1)
/* 283A0 8004CFA0 90620000 */  lbu       $v0, ($v1)
/* 283A4 8004CFA4 90630001 */  lbu       $v1, 1($v1)
/* 283A8 8004CFA8 8C840008 */  lw        $a0, 8($a0)
/* 283AC 8004CFAC 00021200 */  sll       $v0, $v0, 8
/* 283B0 8004CFB0 00431021 */  addu      $v0, $v0, $v1
/* 283B4 8004CFB4 00441021 */  addu      $v0, $v0, $a0
/* 283B8 8004CFB8 03E00008 */  jr        $ra
/* 283BC 8004CFBC ACA20000 */   sw       $v0, ($a1)
