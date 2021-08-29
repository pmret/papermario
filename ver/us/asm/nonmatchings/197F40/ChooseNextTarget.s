.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel ChooseNextTarget
/* 19CCF4 8026E414 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 19CCF8 8026E418 AFB20018 */  sw        $s2, 0x18($sp)
/* 19CCFC 8026E41C 0080902D */  daddu     $s2, $a0, $zero
/* 19CD00 8026E420 AFBF001C */  sw        $ra, 0x1c($sp)
/* 19CD04 8026E424 AFB10014 */  sw        $s1, 0x14($sp)
/* 19CD08 8026E428 AFB00010 */  sw        $s0, 0x10($sp)
/* 19CD0C 8026E42C 8E440148 */  lw        $a0, 0x148($s2)
/* 19CD10 8026E430 0C09A75B */  jal       get_actor
/* 19CD14 8026E434 8E50000C */   lw       $s0, 0xc($s2)
/* 19CD18 8026E438 8E050000 */  lw        $a1, ($s0)
/* 19CD1C 8026E43C 26100004 */  addiu     $s0, $s0, 4
/* 19CD20 8026E440 0240202D */  daddu     $a0, $s2, $zero
/* 19CD24 8026E444 0C0B1EAF */  jal       get_variable
/* 19CD28 8026E448 0040882D */   daddu    $s1, $v0, $zero
/* 19CD2C 8026E44C 0040202D */  daddu     $a0, $v0, $zero
/* 19CD30 8026E450 2402FFFF */  addiu     $v0, $zero, -1
/* 19CD34 8026E454 8E050000 */  lw        $a1, ($s0)
/* 19CD38 8026E458 14820004 */  bne       $a0, $v0, .L8026E46C
/* 19CD3C 8026E45C 2402000A */   addiu    $v0, $zero, 0xa
/* 19CD40 8026E460 8223040D */  lb        $v1, 0x40d($s1)
/* 19CD44 8026E464 0809B924 */  j         .L8026E490
/* 19CD48 8026E468 A2200425 */   sb       $zero, 0x425($s1)
.L8026E46C:
/* 19CD4C 8026E46C 14820013 */  bne       $a0, $v0, .L8026E4BC
/* 19CD50 8026E470 00000000 */   nop
/* 19CD54 8026E474 9222040C */  lbu       $v0, 0x40c($s1)
/* 19CD58 8026E478 2442FFFF */  addiu     $v0, $v0, -1
/* 19CD5C 8026E47C A2220425 */  sb        $v0, 0x425($s1)
/* 19CD60 8026E480 00021600 */  sll       $v0, $v0, 0x18
/* 19CD64 8026E484 00021603 */  sra       $v0, $v0, 0x18
/* 19CD68 8026E488 02221021 */  addu      $v0, $s1, $v0
/* 19CD6C 8026E48C 8043040D */  lb        $v1, 0x40d($v0)
.L8026E490:
/* 19CD70 8026E490 00031080 */  sll       $v0, $v1, 2
/* 19CD74 8026E494 00431021 */  addu      $v0, $v0, $v1
/* 19CD78 8026E498 00021080 */  sll       $v0, $v0, 2
/* 19CD7C 8026E49C 2442022C */  addiu     $v0, $v0, 0x22c
/* 19CD80 8026E4A0 02221821 */  addu      $v1, $s1, $v0
/* 19CD84 8026E4A4 94620000 */  lhu       $v0, ($v1)
/* 19CD88 8026E4A8 A6220428 */  sh        $v0, 0x428($s1)
/* 19CD8C 8026E4AC 90630003 */  lbu       $v1, 3($v1)
/* 19CD90 8026E4B0 24020002 */  addiu     $v0, $zero, 2
/* 19CD94 8026E4B4 0809B950 */  j         .L8026E540
/* 19CD98 8026E4B8 A2230426 */   sb       $v1, 0x426($s1)
.L8026E4BC:
/* 19CD9C 8026E4BC 82230425 */  lb        $v1, 0x425($s1)
/* 19CDA0 8026E4C0 8222040C */  lb        $v0, 0x40c($s1)
/* 19CDA4 8026E4C4 14800003 */  bnez      $a0, .L8026E4D4
/* 19CDA8 8026E4C8 0000302D */   daddu    $a2, $zero, $zero
/* 19CDAC 8026E4CC 0809B936 */  j         .L8026E4D8
/* 19CDB0 8026E4D0 24630001 */   addiu    $v1, $v1, 1
.L8026E4D4:
/* 19CDB4 8026E4D4 2463FFFF */  addiu     $v1, $v1, -1
.L8026E4D8:
/* 19CDB8 8026E4D8 04630004 */  bgezl     $v1, .L8026E4EC
/* 19CDBC 8026E4DC 0062102A */   slt      $v0, $v1, $v0
/* 19CDC0 8026E4E0 2443FFFF */  addiu     $v1, $v0, -1
/* 19CDC4 8026E4E4 2406FFFF */  addiu     $a2, $zero, -1
/* 19CDC8 8026E4E8 0062102A */  slt       $v0, $v1, $v0
.L8026E4EC:
/* 19CDCC 8026E4EC 14400004 */  bnez      $v0, .L8026E500
/* 19CDD0 8026E4F0 00031600 */   sll      $v0, $v1, 0x18
/* 19CDD4 8026E4F4 0000182D */  daddu     $v1, $zero, $zero
/* 19CDD8 8026E4F8 2406FFFF */  addiu     $a2, $zero, -1
/* 19CDDC 8026E4FC 00031600 */  sll       $v0, $v1, 0x18
.L8026E500:
/* 19CDE0 8026E500 00021603 */  sra       $v0, $v0, 0x18
/* 19CDE4 8026E504 02221021 */  addu      $v0, $s1, $v0
/* 19CDE8 8026E508 A2230425 */  sb        $v1, 0x425($s1)
/* 19CDEC 8026E50C 8043040D */  lb        $v1, 0x40d($v0)
/* 19CDF0 8026E510 00031080 */  sll       $v0, $v1, 2
/* 19CDF4 8026E514 00431021 */  addu      $v0, $v0, $v1
/* 19CDF8 8026E518 00021080 */  sll       $v0, $v0, 2
/* 19CDFC 8026E51C 2442022C */  addiu     $v0, $v0, 0x22c
/* 19CE00 8026E520 02221821 */  addu      $v1, $s1, $v0
/* 19CE04 8026E524 94620000 */  lhu       $v0, ($v1)
/* 19CE08 8026E528 A6220428 */  sh        $v0, 0x428($s1)
/* 19CE0C 8026E52C 90620003 */  lbu       $v0, 3($v1)
/* 19CE10 8026E530 0240202D */  daddu     $a0, $s2, $zero
/* 19CE14 8026E534 0C0B2026 */  jal       evt_set_variable
/* 19CE18 8026E538 A2220426 */   sb       $v0, 0x426($s1)
/* 19CE1C 8026E53C 24020002 */  addiu     $v0, $zero, 2
.L8026E540:
/* 19CE20 8026E540 8FBF001C */  lw        $ra, 0x1c($sp)
/* 19CE24 8026E544 8FB20018 */  lw        $s2, 0x18($sp)
/* 19CE28 8026E548 8FB10014 */  lw        $s1, 0x14($sp)
/* 19CE2C 8026E54C 8FB00010 */  lw        $s0, 0x10($sp)
/* 19CE30 8026E550 03E00008 */  jr        $ra
/* 19CE34 8026E554 27BD0020 */   addiu    $sp, $sp, 0x20
