.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel osPfsGetInitData
/* 48960 8006D560 27BDFFF0 */  addiu     $sp, $sp, -0x10
/* 48964 8006D564 00805821 */  addu      $t3, $a0, $zero
/* 48968 8006D568 00A04821 */  addu      $t1, $a1, $zero
/* 4896C 8006D56C 00005021 */  addu      $t2, $zero, $zero
/* 48970 8006D570 3C02800A */  lui       $v0, %hi(D_8009A606)
/* 48974 8006D574 9042A606 */  lbu       $v0, %lo(D_8009A606)($v0)
/* 48978 8006D578 3C08800E */  lui       $t0, %hi(__osPfsPifRam)
/* 4897C 8006D57C 2508A000 */  addiu     $t0, $t0, %lo(__osPfsPifRam)
/* 48980 8006D580 18400021 */  blez      $v0, .L8006D608
/* 48984 8006D584 00003821 */   addu     $a3, $zero, $zero
/* 48988 8006D588 240C0001 */  addiu     $t4, $zero, 1
/* 4898C 8006D58C 24A60002 */  addiu     $a2, $a1, 2
.L8006D590:
/* 48990 8006D590 89020000 */  lwl       $v0, ($t0)
/* 48994 8006D594 99020003 */  lwr       $v0, 3($t0)
/* 48998 8006D598 89030004 */  lwl       $v1, 4($t0)
/* 4899C 8006D59C 99030007 */  lwr       $v1, 7($t0)
/* 489A0 8006D5A0 ABA20000 */  swl       $v0, ($sp)
/* 489A4 8006D5A4 BBA20003 */  swr       $v0, 3($sp)
/* 489A8 8006D5A8 ABA30004 */  swl       $v1, 4($sp)
/* 489AC 8006D5AC BBA30007 */  swr       $v1, 7($sp)
/* 489B0 8006D5B0 93A20002 */  lbu       $v0, 2($sp)
/* 489B4 8006D5B4 304200C0 */  andi      $v0, $v0, 0xc0
/* 489B8 8006D5B8 00021102 */  srl       $v0, $v0, 4
/* 489BC 8006D5BC 1440000A */  bnez      $v0, .L8006D5E8
/* 489C0 8006D5C0 A0C20001 */   sb       $v0, 1($a2)
/* 489C4 8006D5C4 93A20005 */  lbu       $v0, 5($sp)
/* 489C8 8006D5C8 93A30004 */  lbu       $v1, 4($sp)
/* 489CC 8006D5CC 00021200 */  sll       $v0, $v0, 8
/* 489D0 8006D5D0 00621825 */  or        $v1, $v1, $v0
/* 489D4 8006D5D4 A5230000 */  sh        $v1, ($t1)
/* 489D8 8006D5D8 93A30006 */  lbu       $v1, 6($sp)
/* 489DC 8006D5DC 00EC1004 */  sllv      $v0, $t4, $a3
/* 489E0 8006D5E0 01425025 */  or        $t2, $t2, $v0
/* 489E4 8006D5E4 A0C30000 */  sb        $v1, ($a2)
.L8006D5E8:
/* 489E8 8006D5E8 24E70001 */  addiu     $a3, $a3, 1
/* 489EC 8006D5EC 25080008 */  addiu     $t0, $t0, 8
/* 489F0 8006D5F0 3C02800A */  lui       $v0, %hi(D_8009A606)
/* 489F4 8006D5F4 9042A606 */  lbu       $v0, %lo(D_8009A606)($v0)
/* 489F8 8006D5F8 24C60004 */  addiu     $a2, $a2, 4
/* 489FC 8006D5FC 00E2102A */  slt       $v0, $a3, $v0
/* 48A00 8006D600 1440FFE3 */  bnez      $v0, .L8006D590
/* 48A04 8006D604 25290004 */   addiu    $t1, $t1, 4
.L8006D608:
/* 48A08 8006D608 A16A0000 */  sb        $t2, ($t3)
/* 48A0C 8006D60C 03E00008 */  jr        $ra
/* 48A10 8006D610 27BD0010 */   addiu    $sp, $sp, 0x10
/* 48A14 8006D614 00000000 */  nop
/* 48A18 8006D618 00000000 */  nop
/* 48A1C 8006D61C 00000000 */  nop
