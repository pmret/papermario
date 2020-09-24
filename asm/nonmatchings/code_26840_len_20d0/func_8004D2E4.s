.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004D2E4
/* 286E4 8004D2E4 8CA30000 */  lw        $v1, ($a1)
/* 286E8 8004D2E8 24620002 */  addiu     $v0, $v1, 2
/* 286EC 8004D2EC ACA20050 */  sw        $v0, 0x50($a1)
/* 286F0 8004D2F0 90620000 */  lbu       $v0, ($v1)
/* 286F4 8004D2F4 90630001 */  lbu       $v1, 1($v1)
/* 286F8 8004D2F8 8C840008 */  lw        $a0, 8($a0)
/* 286FC 8004D2FC 00021200 */  sll       $v0, $v0, 8
/* 28700 8004D300 00431021 */  addu      $v0, $v0, $v1
/* 28704 8004D304 00441021 */  addu      $v0, $v0, $a0
/* 28708 8004D308 03E00008 */  jr        $ra
/* 2870C 8004D30C ACA20000 */   sw       $v0, ($a1)
