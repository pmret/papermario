.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241A18
/* 7EC728 80241A18 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 7EC72C 80241A1C AFBF0010 */  sw        $ra, 0x10($sp)
/* 7EC730 80241A20 8C82000C */  lw        $v0, 0xc($a0)
/* 7EC734 80241A24 0C0B1EAF */  jal       get_variable
/* 7EC738 80241A28 8C450000 */   lw       $a1, ($v0)
/* 7EC73C 80241A2C 0040182D */  daddu     $v1, $v0, $zero
/* 7EC740 80241A30 10600012 */  beqz      $v1, .L80241A7C
/* 7EC744 80241A34 0000202D */   daddu    $a0, $zero, $zero
/* 7EC748 80241A38 8C620000 */  lw        $v0, ($v1)
/* 7EC74C 80241A3C 5040000A */  beql      $v0, $zero, .L80241A68
/* 7EC750 80241A40 00041080 */   sll      $v0, $a0, 2
/* 7EC754 80241A44 3C058025 */  lui       $a1, 0x8025
/* 7EC758 80241A48 24A55D68 */  addiu     $a1, $a1, 0x5d68
.L80241A4C:
/* 7EC75C 80241A4C 24630004 */  addiu     $v1, $v1, 4
/* 7EC760 80241A50 24840001 */  addiu     $a0, $a0, 1
/* 7EC764 80241A54 ACA20000 */  sw        $v0, ($a1)
/* 7EC768 80241A58 8C620000 */  lw        $v0, ($v1)
/* 7EC76C 80241A5C 1440FFFB */  bnez      $v0, .L80241A4C
/* 7EC770 80241A60 24A50004 */   addiu    $a1, $a1, 4
/* 7EC774 80241A64 00041080 */  sll       $v0, $a0, 2
.L80241A68:
/* 7EC778 80241A68 3C018025 */  lui       $at, 0x8025
/* 7EC77C 80241A6C 00220821 */  addu      $at, $at, $v0
/* 7EC780 80241A70 AC205D68 */  sw        $zero, 0x5d68($at)
/* 7EC784 80241A74 080906A9 */  j         .L80241AA4
/* 7EC788 80241A78 00000000 */   nop      
.L80241A7C:
/* 7EC78C 80241A7C 3C038025 */  lui       $v1, 0x8025
/* 7EC790 80241A80 24635D68 */  addiu     $v1, $v1, 0x5d68
/* 7EC794 80241A84 0060282D */  daddu     $a1, $v1, $zero
.L80241A88:
/* 7EC798 80241A88 24820080 */  addiu     $v0, $a0, 0x80
/* 7EC79C 80241A8C AC620000 */  sw        $v0, ($v1)
/* 7EC7A0 80241A90 24630004 */  addiu     $v1, $v1, 4
/* 7EC7A4 80241A94 24840001 */  addiu     $a0, $a0, 1
/* 7EC7A8 80241A98 2882005B */  slti      $v0, $a0, 0x5b
/* 7EC7AC 80241A9C 1440FFFA */  bnez      $v0, .L80241A88
/* 7EC7B0 80241AA0 ACA0016C */   sw       $zero, 0x16c($a1)
.L80241AA4:
/* 7EC7B4 80241AA4 8FBF0010 */  lw        $ra, 0x10($sp)
/* 7EC7B8 80241AA8 24020002 */  addiu     $v0, $zero, 2
/* 7EC7BC 80241AAC 03E00008 */  jr        $ra
/* 7EC7C0 80241AB0 27BD0018 */   addiu    $sp, $sp, 0x18
