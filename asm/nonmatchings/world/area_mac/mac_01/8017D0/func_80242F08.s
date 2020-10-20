.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242F08
/* 803788 80242F08 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 80378C 80242F0C 3C058026 */  lui       $a1, 0x8026
/* 803790 80242F10 8CA52A58 */  lw        $a1, 0x2a58($a1)
/* 803794 80242F14 AFBF0010 */  sw        $ra, 0x10($sp)
/* 803798 80242F18 0C0B1EAF */  jal       get_variable
/* 80379C 80242F1C 0000202D */   daddu    $a0, $zero, $zero
/* 8037A0 80242F20 0040182D */  daddu     $v1, $v0, $zero
/* 8037A4 80242F24 24020001 */  addiu     $v0, $zero, 1
/* 8037A8 80242F28 14620006 */  bne       $v1, $v0, .L80242F44
/* 8037AC 80242F2C 24020002 */   addiu    $v0, $zero, 2
/* 8037B0 80242F30 44800000 */  mtc1      $zero, $f0
/* 8037B4 80242F34 00000000 */  nop       
/* 8037B8 80242F38 44050000 */  mfc1      $a1, $f0
/* 8037BC 80242F3C 08090BD7 */  j         .L80242F5C
/* 8037C0 80242F40 0000202D */   daddu    $a0, $zero, $zero
.L80242F44:
/* 8037C4 80242F44 14620008 */  bne       $v1, $v0, .L80242F68
/* 8037C8 80242F48 24040001 */   addiu    $a0, $zero, 1
/* 8037CC 80242F4C 44800000 */  mtc1      $zero, $f0
/* 8037D0 80242F50 00000000 */  nop       
/* 8037D4 80242F54 44050000 */  mfc1      $a1, $f0
/* 8037D8 80242F58 00000000 */  nop       
.L80242F5C:
/* 8037DC 80242F5C 00A0302D */  daddu     $a2, $a1, $zero
/* 8037E0 80242F60 0C01C5A4 */  jal       func_80071690
/* 8037E4 80242F64 00A0382D */   daddu    $a3, $a1, $zero
.L80242F68:
/* 8037E8 80242F68 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8037EC 80242F6C 03E00008 */  jr        $ra
/* 8037F0 80242F70 27BD0018 */   addiu    $sp, $sp, 0x18
