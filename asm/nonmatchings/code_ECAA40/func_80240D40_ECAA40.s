.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240D40_ECAA40
/* ECAA40 80240D40 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* ECAA44 80240D44 24040001 */  addiu     $a0, $zero, 1
/* ECAA48 80240D48 0000282D */  daddu     $a1, $zero, $zero
/* ECAA4C 80240D4C 00A0302D */  daddu     $a2, $a1, $zero
/* ECAA50 80240D50 00A0382D */  daddu     $a3, $a1, $zero
/* ECAA54 80240D54 AFBF0018 */  sw        $ra, 0x18($sp)
/* ECAA58 80240D58 AFA00010 */  sw        $zero, 0x10($sp)
/* ECAA5C 80240D5C 0C01DEF4 */  jal       func_80077BD0
/* ECAA60 80240D60 AFA00014 */   sw       $zero, 0x14($sp)
/* ECAA64 80240D64 8FBF0018 */  lw        $ra, 0x18($sp)
/* ECAA68 80240D68 24020002 */  addiu     $v0, $zero, 2
/* ECAA6C 80240D6C 03E00008 */  jr        $ra
/* ECAA70 80240D70 27BD0020 */   addiu    $sp, $sp, 0x20
/* ECAA74 80240D74 00000000 */  nop       
/* ECAA78 80240D78 00000000 */  nop       
/* ECAA7C 80240D7C 00000000 */  nop       
