.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004CCBC
/* 280BC 8004CCBC 8CA20000 */  lw        $v0, ($a1)
/* 280C0 8004CCC0 80430000 */  lb        $v1, ($v0)
/* 280C4 8004CCC4 24420001 */  addiu     $v0, $v0, 1
/* 280C8 8004CCC8 ACA20000 */  sw        $v0, ($a1)
/* 280CC 8004CCCC 00031040 */  sll       $v0, $v1, 1
/* 280D0 8004CCD0 00431021 */  addu      $v0, $v0, $v1
/* 280D4 8004CCD4 000210C0 */  sll       $v0, $v0, 3
/* 280D8 8004CCD8 00431021 */  addu      $v0, $v0, $v1
/* 280DC 8004CCDC 00021080 */  sll       $v0, $v0, 2
/* 280E0 8004CCE0 03E00008 */  jr        $ra
/* 280E4 8004CCE4 A4A20092 */   sh       $v0, 0x92($a1)
