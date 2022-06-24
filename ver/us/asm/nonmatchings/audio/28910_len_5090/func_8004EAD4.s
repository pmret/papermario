.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004EAD4
/* 29ED4 8004EAD4 0000402D */  daddu     $t0, $zero, $zero
/* 29ED8 8004EAD8 0100582D */  daddu     $t3, $t0, $zero
/* 29EDC 8004EADC 0100482D */  daddu     $t1, $t0, $zero
/* 29EE0 8004EAE0 240C0001 */  addiu     $t4, $zero, 1
/* 29EE4 8004EAE4 240A025C */  addiu     $t2, $zero, 0x25c
/* 29EE8 8004EAE8 30A5FFFF */  andi      $a1, $a1, 0xffff
/* 29EEC 8004EAEC 8C82006C */  lw        $v0, 0x6c($a0)
/* 29EF0 8004EAF0 00052880 */  sll       $a1, $a1, 2
/* 29EF4 8004EAF4 00A22821 */  addu      $a1, $a1, $v0
/* 29EF8 8004EAF8 AC850070 */  sw        $a1, 0x70($a0)
.L8004EAFC:
/* 29EFC 8004EAFC 8CA30000 */  lw        $v1, ($a1)
/* 29F00 8004EB00 24A50004 */  addiu     $a1, $a1, 4
/* 29F04 8004EB04 008A3021 */  addu      $a2, $a0, $t2
/* 29F08 8004EB08 00031402 */  srl       $v0, $v1, 0x10
/* 29F0C 8004EB0C 10400034 */  beqz      $v0, .L8004EBE0
/* 29F10 8004EB10 ACC20000 */   sw       $v0, ($a2)
/* 29F14 8004EB14 30620100 */  andi      $v0, $v1, 0x100
/* 29F18 8004EB18 54400031 */  bnel      $v0, $zero, .L8004EBE0
/* 29F1C 8004EB1C ACC00000 */   sw       $zero, ($a2)
/* 29F20 8004EB20 3062E000 */  andi      $v0, $v1, 0xe000
/* 29F24 8004EB24 00021342 */  srl       $v0, $v0, 0xd
/* 29F28 8004EB28 A0C20054 */  sb        $v0, 0x54($a2)
/* 29F2C 8004EB2C 000311C2 */  srl       $v0, $v1, 7
/* 29F30 8004EB30 30420001 */  andi      $v0, $v0, 1
/* 29F34 8004EB34 A0C20058 */  sb        $v0, 0x58($a2)
/* 29F38 8004EB38 30621E00 */  andi      $v0, $v1, 0x1e00
/* 29F3C 8004EB3C 00023A42 */  srl       $a3, $v0, 9
/* 29F40 8004EB40 10E0001B */  beqz      $a3, .L8004EBB0
/* 29F44 8004EB44 A0C00059 */   sb       $zero, 0x59($a2)
/* 29F48 8004EB48 00071040 */  sll       $v0, $a3, 1
/* 29F4C 8004EB4C 00471021 */  addu      $v0, $v0, $a3
/* 29F50 8004EB50 00021140 */  sll       $v0, $v0, 5
/* 29F54 8004EB54 244201FC */  addiu     $v0, $v0, 0x1fc
/* 29F58 8004EB58 00821821 */  addu      $v1, $a0, $v0
/* 29F5C 8004EB5C 24E2FFFF */  addiu     $v0, $a3, -1
/* 29F60 8004EB60 0049102B */  sltu      $v0, $v0, $t1
/* 29F64 8004EB64 5040001E */  beql      $v0, $zero, .L8004EBE0
/* 29F68 8004EB68 ACC00000 */   sw       $zero, ($a2)
/* 29F6C 8004EB6C 90620051 */  lbu       $v0, 0x51($v1)
/* 29F70 8004EB70 A0C20051 */  sb        $v0, 0x51($a2)
/* 29F74 8004EB74 90620052 */  lbu       $v0, 0x52($v1)
/* 29F78 8004EB78 A0C20052 */  sb        $v0, 0x52($a2)
/* 29F7C 8004EB7C 90620053 */  lbu       $v0, 0x53($v1)
/* 29F80 8004EB80 A0C20053 */  sb        $v0, 0x53($a2)
/* 29F84 8004EB84 8CC20000 */  lw        $v0, ($a2)
/* 29F88 8004EB88 8C830070 */  lw        $v1, 0x70($a0)
/* 29F8C 8004EB8C ACCC0028 */  sw        $t4, 0x28($a2)
/* 29F90 8004EB90 A0C70059 */  sb        $a3, 0x59($a2)
/* 29F94 8004EB94 00431021 */  addu      $v0, $v0, $v1
/* 29F98 8004EB98 ACC20000 */  sw        $v0, ($a2)
/* 29F9C 8004EB9C 90820233 */  lbu       $v0, 0x233($a0)
/* 29FA0 8004EBA0 54400001 */  bnel      $v0, $zero, .L8004EBA8
/* 29FA4 8004EBA4 A0CC005A */   sb       $t4, 0x5a($a2)
.L8004EBA8:
/* 29FA8 8004EBA8 08013AF8 */  j         .L8004EBE0
/* 29FAC 8004EBAC 240B0001 */   addiu    $t3, $zero, 1
.L8004EBB0:
/* 29FB0 8004EBB0 90C20054 */  lbu       $v0, 0x54($a2)
/* 29FB4 8004EBB4 00821021 */  addu      $v0, $a0, $v0
/* 29FB8 8004EBB8 9042022A */  lbu       $v0, 0x22a($v0)
/* 29FBC 8004EBBC A0C80052 */  sb        $t0, 0x52($a2)
/* 29FC0 8004EBC0 01024021 */  addu      $t0, $t0, $v0
/* 29FC4 8004EBC4 A0C20051 */  sb        $v0, 0x51($a2)
/* 29FC8 8004EBC8 8CC20000 */  lw        $v0, ($a2)
/* 29FCC 8004EBCC A0C80053 */  sb        $t0, 0x53($a2)
/* 29FD0 8004EBD0 8C830070 */  lw        $v1, 0x70($a0)
/* 29FD4 8004EBD4 ACCC0028 */  sw        $t4, 0x28($a2)
/* 29FD8 8004EBD8 00431021 */  addu      $v0, $v0, $v1
/* 29FDC 8004EBDC ACC20000 */  sw        $v0, ($a2)
.L8004EBE0:
/* 29FE0 8004EBE0 25290001 */  addiu     $t1, $t1, 1
/* 29FE4 8004EBE4 29220010 */  slti      $v0, $t1, 0x10
/* 29FE8 8004EBE8 1440FFC4 */  bnez      $v0, .L8004EAFC
/* 29FEC 8004EBEC 254A0060 */   addiu    $t2, $t2, 0x60
/* 29FF0 8004EBF0 11600002 */  beqz      $t3, .L8004EBFC
/* 29FF4 8004EBF4 A088021B */   sb       $t0, 0x21b($a0)
/* 29FF8 8004EBF8 A0800233 */  sb        $zero, 0x233($a0)
.L8004EBFC:
/* 29FFC 8004EBFC 03E00008 */  jr        $ra
/* 2A000 8004EC00 00000000 */   nop
