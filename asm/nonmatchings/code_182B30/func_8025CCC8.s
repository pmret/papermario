.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8025CCC8
/* 18B5A8 8025CCC8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 18B5AC 8025CCCC AFBF0010 */  sw        $ra, 0x10($sp)
/* 18B5B0 8025CCD0 8CA20000 */  lw        $v0, ($a1)
/* 18B5B4 8025CCD4 30420002 */  andi      $v0, $v0, 2
/* 18B5B8 8025CCD8 14400010 */  bnez      $v0, .L8025CD1C
/* 18B5BC 8025CCDC 0000102D */   daddu    $v0, $zero, $zero
/* 18B5C0 8025CCE0 8CA200C0 */  lw        $v0, 0xc0($a1)
/* 18B5C4 8025CCE4 80430764 */  lb        $v1, 0x764($v0)
/* 18B5C8 8025CCE8 10600005 */  beqz      $v1, .L8025CD00
/* 18B5CC 8025CCEC 24020001 */   addiu    $v0, $zero, 1
/* 18B5D0 8025CCF0 10620007 */  beq       $v1, $v0, .L8025CD10
/* 18B5D4 8025CCF4 0000102D */   daddu    $v0, $zero, $zero
/* 18B5D8 8025CCF8 08097347 */  j         .L8025CD1C
/* 18B5DC 8025CCFC 00000000 */   nop
.L8025CD00:
/* 18B5E0 8025CD00 0C09734A */  jal       func_8025CD28
/* 18B5E4 8025CD04 00000000 */   nop
/* 18B5E8 8025CD08 08097347 */  j         .L8025CD1C
/* 18B5EC 8025CD0C 0000102D */   daddu    $v0, $zero, $zero
.L8025CD10:
/* 18B5F0 8025CD10 0C097350 */  jal       func_8025CD40
/* 18B5F4 8025CD14 00000000 */   nop
/* 18B5F8 8025CD18 0000102D */  daddu     $v0, $zero, $zero
.L8025CD1C:
/* 18B5FC 8025CD1C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 18B600 8025CD20 03E00008 */  jr        $ra
/* 18B604 8025CD24 27BD0018 */   addiu    $sp, $sp, 0x18
