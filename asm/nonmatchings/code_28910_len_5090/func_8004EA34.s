.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004EA34
/* 29E34 8004EA34 30A8001F */  andi      $t0, $a1, 0x1f
/* 29E38 8004EA38 90830210 */  lbu       $v1, 0x210($a0)
/* 29E3C 8004EA3C 00052942 */  srl       $a1, $a1, 5
/* 29E40 8004EA40 00031080 */  sll       $v0, $v1, 2
/* 29E44 8004EA44 00823021 */  addu      $a2, $a0, $v0
/* 29E48 8004EA48 8CC20158 */  lw        $v0, 0x158($a2)
/* 29E4C 8004EA4C 10400017 */  beqz      $v0, .L8004EAAC
/* 29E50 8004EA50 30A5007F */   andi     $a1, $a1, 0x7f
/* 29E54 8004EA54 8C870068 */  lw        $a3, 0x68($a0)
/* 29E58 8004EA58 1447000D */  bne       $v0, $a3, .L8004EA90
/* 29E5C 8004EA5C 2C620004 */   sltiu    $v0, $v1, 4
/* 29E60 8004EA60 00832821 */  addu      $a1, $a0, $v1
/* 29E64 8004EA64 90A20168 */  lbu       $v0, 0x168($a1)
/* 29E68 8004EA68 10400014 */  beqz      $v0, .L8004EABC
/* 29E6C 8004EA6C 2442FFFF */   addiu    $v0, $v0, -1
/* 29E70 8004EA70 A0A20168 */  sb        $v0, 0x168($a1)
/* 29E74 8004EA74 304200FF */  andi      $v0, $v0, 0xff
/* 29E78 8004EA78 54400011 */  bnel      $v0, $zero, .L8004EAC0
/* 29E7C 8004EA7C 00081080 */   sll      $v0, $t0, 2
/* 29E80 8004EA80 10600012 */  beqz      $v1, .L8004EACC
/* 29E84 8004EA84 ACC00158 */   sw       $zero, 0x158($a2)
/* 29E88 8004EA88 08013AB3 */  j         .L8004EACC
/* 29E8C 8004EA8C 2463FFFF */   addiu    $v1, $v1, -1
.L8004EA90:
/* 29E90 8004EA90 1040000E */  beqz      $v0, .L8004EACC
/* 29E94 8004EA94 00000000 */   nop      
/* 29E98 8004EA98 24630001 */  addiu     $v1, $v1, 1
/* 29E9C 8004EA9C 00031080 */  sll       $v0, $v1, 2
/* 29EA0 8004EAA0 00821021 */  addu      $v0, $a0, $v0
/* 29EA4 8004EAA4 08013AAD */  j         .L8004EAB4
/* 29EA8 8004EAA8 AC470158 */   sw       $a3, 0x158($v0)
.L8004EAAC:
/* 29EAC 8004EAAC 8C820068 */  lw        $v0, 0x68($a0)
/* 29EB0 8004EAB0 ACC20158 */  sw        $v0, 0x158($a2)
.L8004EAB4:
/* 29EB4 8004EAB4 00831021 */  addu      $v0, $a0, $v1
/* 29EB8 8004EAB8 A0450168 */  sb        $a1, 0x168($v0)
.L8004EABC:
/* 29EBC 8004EABC 00081080 */  sll       $v0, $t0, 2
.L8004EAC0:
/* 29EC0 8004EAC0 00821021 */  addu      $v0, $a0, $v0
/* 29EC4 8004EAC4 8C4200D8 */  lw        $v0, 0xd8($v0)
/* 29EC8 8004EAC8 AC820068 */  sw        $v0, 0x68($a0)
.L8004EACC:
/* 29ECC 8004EACC 03E00008 */  jr        $ra
/* 29ED0 8004EAD0 A0830210 */   sb       $v1, 0x210($a0)
