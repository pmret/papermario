.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243D14_9DAD34
/* 9DAD34 80243D14 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9DAD38 80243D18 AFBF0010 */  sw        $ra, 0x10($sp)
/* 9DAD3C 80243D1C 8C82000C */  lw        $v0, 0xc($a0)
/* 9DAD40 80243D20 0C0B1EAF */  jal       get_variable
/* 9DAD44 80243D24 8C450000 */   lw       $a1, ($v0)
/* 9DAD48 80243D28 0040182D */  daddu     $v1, $v0, $zero
/* 9DAD4C 80243D2C 10600012 */  beqz      $v1, .L80243D78
/* 9DAD50 80243D30 0000202D */   daddu    $a0, $zero, $zero
/* 9DAD54 80243D34 8C620000 */  lw        $v0, ($v1)
/* 9DAD58 80243D38 5040000A */  beql      $v0, $zero, .L80243D64
/* 9DAD5C 80243D3C 00041080 */   sll      $v0, $a0, 2
/* 9DAD60 80243D40 3C058025 */  lui       $a1, 0x8025
/* 9DAD64 80243D44 24A54D68 */  addiu     $a1, $a1, 0x4d68
.L80243D48:
/* 9DAD68 80243D48 24630004 */  addiu     $v1, $v1, 4
/* 9DAD6C 80243D4C 24840001 */  addiu     $a0, $a0, 1
/* 9DAD70 80243D50 ACA20000 */  sw        $v0, ($a1)
/* 9DAD74 80243D54 8C620000 */  lw        $v0, ($v1)
/* 9DAD78 80243D58 1440FFFB */  bnez      $v0, .L80243D48
/* 9DAD7C 80243D5C 24A50004 */   addiu    $a1, $a1, 4
/* 9DAD80 80243D60 00041080 */  sll       $v0, $a0, 2
.L80243D64:
/* 9DAD84 80243D64 3C018025 */  lui       $at, 0x8025
/* 9DAD88 80243D68 00220821 */  addu      $at, $at, $v0
/* 9DAD8C 80243D6C AC204D68 */  sw        $zero, 0x4d68($at)
/* 9DAD90 80243D70 08090F68 */  j         .L80243DA0
/* 9DAD94 80243D74 00000000 */   nop      
.L80243D78:
/* 9DAD98 80243D78 3C038025 */  lui       $v1, 0x8025
/* 9DAD9C 80243D7C 24634D68 */  addiu     $v1, $v1, 0x4d68
/* 9DADA0 80243D80 0060282D */  daddu     $a1, $v1, $zero
.L80243D84:
/* 9DADA4 80243D84 24820080 */  addiu     $v0, $a0, 0x80
/* 9DADA8 80243D88 AC620000 */  sw        $v0, ($v1)
/* 9DADAC 80243D8C 24630004 */  addiu     $v1, $v1, 4
/* 9DADB0 80243D90 24840001 */  addiu     $a0, $a0, 1
/* 9DADB4 80243D94 2882005B */  slti      $v0, $a0, 0x5b
/* 9DADB8 80243D98 1440FFFA */  bnez      $v0, .L80243D84
/* 9DADBC 80243D9C ACA0016C */   sw       $zero, 0x16c($a1)
.L80243DA0:
/* 9DADC0 80243DA0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 9DADC4 80243DA4 24020002 */  addiu     $v0, $zero, 2
/* 9DADC8 80243DA8 03E00008 */  jr        $ra
/* 9DADCC 80243DAC 27BD0018 */   addiu    $sp, $sp, 0x18
