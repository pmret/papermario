.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241EB4_D21D44
/* D21D44 80241EB4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D21D48 80241EB8 AFBF0010 */  sw        $ra, 0x10($sp)
/* D21D4C 80241EBC 8C82000C */  lw        $v0, 0xc($a0)
/* D21D50 80241EC0 0C0B1EAF */  jal       get_variable
/* D21D54 80241EC4 8C450000 */   lw       $a1, ($v0)
/* D21D58 80241EC8 0040182D */  daddu     $v1, $v0, $zero
/* D21D5C 80241ECC 10600012 */  beqz      $v1, .L80241F18
/* D21D60 80241ED0 0000202D */   daddu    $a0, $zero, $zero
/* D21D64 80241ED4 8C620000 */  lw        $v0, ($v1)
/* D21D68 80241ED8 5040000A */  beql      $v0, $zero, .L80241F04
/* D21D6C 80241EDC 00041080 */   sll      $v0, $a0, 2
/* D21D70 80241EE0 3C058025 */  lui       $a1, %hi(D_8024C068)
/* D21D74 80241EE4 24A5C068 */  addiu     $a1, $a1, %lo(D_8024C068)
.L80241EE8:
/* D21D78 80241EE8 24630004 */  addiu     $v1, $v1, 4
/* D21D7C 80241EEC 24840001 */  addiu     $a0, $a0, 1
/* D21D80 80241EF0 ACA20000 */  sw        $v0, ($a1)
/* D21D84 80241EF4 8C620000 */  lw        $v0, ($v1)
/* D21D88 80241EF8 1440FFFB */  bnez      $v0, .L80241EE8
/* D21D8C 80241EFC 24A50004 */   addiu    $a1, $a1, 4
/* D21D90 80241F00 00041080 */  sll       $v0, $a0, 2
.L80241F04:
/* D21D94 80241F04 3C018025 */  lui       $at, %hi(D_8024C068)
/* D21D98 80241F08 00220821 */  addu      $at, $at, $v0
/* D21D9C 80241F0C AC20C068 */  sw        $zero, %lo(D_8024C068)($at)
/* D21DA0 80241F10 080907D0 */  j         .L80241F40
/* D21DA4 80241F14 00000000 */   nop      
.L80241F18:
/* D21DA8 80241F18 3C038025 */  lui       $v1, %hi(D_8024C068)
/* D21DAC 80241F1C 2463C068 */  addiu     $v1, $v1, %lo(D_8024C068)
/* D21DB0 80241F20 0060282D */  daddu     $a1, $v1, $zero
.L80241F24:
/* D21DB4 80241F24 24820080 */  addiu     $v0, $a0, 0x80
/* D21DB8 80241F28 AC620000 */  sw        $v0, ($v1)
/* D21DBC 80241F2C 24630004 */  addiu     $v1, $v1, 4
/* D21DC0 80241F30 24840001 */  addiu     $a0, $a0, 1
/* D21DC4 80241F34 2882005B */  slti      $v0, $a0, 0x5b
/* D21DC8 80241F38 1440FFFA */  bnez      $v0, .L80241F24
/* D21DCC 80241F3C ACA0016C */   sw       $zero, 0x16c($a1)
.L80241F40:
/* D21DD0 80241F40 8FBF0010 */  lw        $ra, 0x10($sp)
/* D21DD4 80241F44 24020002 */  addiu     $v0, $zero, 2
/* D21DD8 80241F48 03E00008 */  jr        $ra
/* D21DDC 80241F4C 27BD0018 */   addiu    $sp, $sp, 0x18
