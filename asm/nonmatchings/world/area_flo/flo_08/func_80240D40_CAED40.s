.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240D40_CAFA80
/* CAFA80 80240D40 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* CAFA84 80240D44 24040001 */  addiu     $a0, $zero, 1
/* CAFA88 80240D48 0000282D */  daddu     $a1, $zero, $zero
/* CAFA8C 80240D4C 00A0302D */  daddu     $a2, $a1, $zero
/* CAFA90 80240D50 00A0382D */  daddu     $a3, $a1, $zero
/* CAFA94 80240D54 AFBF0018 */  sw        $ra, 0x18($sp)
/* CAFA98 80240D58 AFA00010 */  sw        $zero, 0x10($sp)
/* CAFA9C 80240D5C 0C01CA54 */  jal       func_80072950
/* CAFAA0 80240D60 AFA00014 */   sw       $zero, 0x14($sp)
/* CAFAA4 80240D64 8FBF0018 */  lw        $ra, 0x18($sp)
/* CAFAA8 80240D68 24020002 */  addiu     $v0, $zero, 2
/* CAFAAC 80240D6C 03E00008 */  jr        $ra
/* CAFAB0 80240D70 27BD0020 */   addiu    $sp, $sp, 0x20
/* CAFAB4 80240D74 00000000 */  nop       
/* CAFAB8 80240D78 00000000 */  nop       
/* CAFABC 80240D7C 00000000 */  nop       
