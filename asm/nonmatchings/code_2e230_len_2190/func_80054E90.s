.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80054E90
/* 30290 80054E90 10A0000A */  beqz      $a1, .L80054EBC
/* 30294 80054E94 28A20400 */   slti     $v0, $a1, 0x400
/* 30298 80054E98 1040000A */  beqz      $v0, .L80054EC4
/* 3029C 80054E9C 00A0102D */   daddu    $v0, $a1, $zero
/* 302A0 80054EA0 10400006 */  beqz      $v0, .L80054EBC
/* 302A4 80054EA4 24A5FFFF */   addiu    $a1, $a1, -1
.L80054EA8:
/* 302A8 80054EA8 A0860000 */  sb        $a2, ($a0)
/* 302AC 80054EAC 24840001 */  addiu     $a0, $a0, 1
/* 302B0 80054EB0 00A0102D */  daddu     $v0, $a1, $zero
/* 302B4 80054EB4 1440FFFC */  bnez      $v0, .L80054EA8
/* 302B8 80054EB8 24A5FFFF */   addiu    $a1, $a1, -1
.L80054EBC:
/* 302BC 80054EBC 03E00008 */  jr        $ra
/* 302C0 80054EC0 00000000 */   nop      
.L80054EC4:
/* 302C4 80054EC4 30870003 */  andi      $a3, $a0, 3
/* 302C8 80054EC8 10E00009 */  beqz      $a3, .L80054EF0
/* 302CC 80054ECC 24020004 */   addiu    $v0, $zero, 4
/* 302D0 80054ED0 00473823 */  subu      $a3, $v0, $a3
/* 302D4 80054ED4 080153B9 */  j         .L80054EE4
/* 302D8 80054ED8 00A72823 */   subu     $a1, $a1, $a3
.L80054EDC:
/* 302DC 80054EDC A0860000 */  sb        $a2, ($a0)
/* 302E0 80054EE0 24840001 */  addiu     $a0, $a0, 1
.L80054EE4:
/* 302E4 80054EE4 00E0102D */  daddu     $v0, $a3, $zero
/* 302E8 80054EE8 1440FFFC */  bnez      $v0, .L80054EDC
/* 302EC 80054EEC 24E7FFFF */   addiu    $a3, $a3, -1
.L80054EF0:
/* 302F0 80054EF0 00053883 */  sra       $a3, $a1, 2
/* 302F4 80054EF4 30C300FF */  andi      $v1, $a2, 0xff
/* 302F8 80054EF8 00031200 */  sll       $v0, $v1, 8
/* 302FC 80054EFC 00431821 */  addu      $v1, $v0, $v1
/* 30300 80054F00 00031400 */  sll       $v0, $v1, 0x10
/* 30304 80054F04 080153C5 */  j         .L80054F14
/* 30308 80054F08 00621821 */   addu     $v1, $v1, $v0
.L80054F0C:
/* 3030C 80054F0C AC830000 */  sw        $v1, ($a0)
/* 30310 80054F10 24840004 */  addiu     $a0, $a0, 4
.L80054F14:
/* 30314 80054F14 00E0102D */  daddu     $v0, $a3, $zero
/* 30318 80054F18 1440FFFC */  bnez      $v0, .L80054F0C
/* 3031C 80054F1C 24E7FFFF */   addiu    $a3, $a3, -1
/* 30320 80054F20 30A70003 */  andi      $a3, $a1, 3
/* 30324 80054F24 10E0FFE5 */  beqz      $a3, .L80054EBC
/* 30328 80054F28 24E7FFFF */   addiu    $a3, $a3, -1
.L80054F2C:
/* 3032C 80054F2C A0860000 */  sb        $a2, ($a0)
/* 30330 80054F30 24840001 */  addiu     $a0, $a0, 1
/* 30334 80054F34 00E0102D */  daddu     $v0, $a3, $zero
/* 30338 80054F38 1440FFFC */  bnez      $v0, .L80054F2C
/* 3033C 80054F3C 24E7FFFF */   addiu    $a3, $a3, -1
/* 30340 80054F40 03E00008 */  jr        $ra
/* 30344 80054F44 00000000 */   nop      
