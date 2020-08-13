.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80124434
/* 0BAB34 80124434 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0BAB38 80124438 AFB00010 */  sw    $s0, 0x10($sp)
/* 0BAB3C 8012443C 0080802D */  daddu $s0, $a0, $zero
/* 0BAB40 80124440 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0BAB44 80124444 AFB20018 */  sw    $s2, 0x18($sp)
/* 0BAB48 80124448 AFB10014 */  sw    $s1, 0x14($sp)
/* 0BAB4C 8012444C F7B40020 */  sdc1  $f20, 0x20($sp)
/* 0BAB50 80124450 8E0204FC */  lw    $v0, 0x4fc($s0)
/* 0BAB54 80124454 3C030080 */  lui   $v1, 0x80
/* 0BAB58 80124458 00431024 */  and   $v0, $v0, $v1
/* 0BAB5C 8012445C 1040003D */  beqz  $v0, .L80124554
/* 0BAB60 80124460 00000000 */   nop   
/* 0BAB64 80124464 96020500 */  lhu   $v0, 0x500($s0)
/* 0BAB68 80124468 30420006 */  andi  $v0, $v0, 6
/* 0BAB6C 8012446C 14400039 */  bnez  $v0, .L80124554
/* 0BAB70 80124470 00000000 */   nop   
/* 0BAB74 80124474 92020519 */  lbu   $v0, 0x519($s0)
/* 0BAB78 80124478 10400036 */  beqz  $v0, .L80124554
/* 0BAB7C 8012447C 2404000F */   addiu $a0, $zero, 0xf
/* 0BAB80 80124480 4482A000 */  mtc1  $v0, $f20
/* 0BAB84 80124484 00000000 */  nop   
/* 0BAB88 80124488 4680A520 */  cvt.s.w $f20, $f20
/* 0BAB8C 8012448C 30B100FF */  andi  $s1, $a1, 0xff
/* 0BAB90 80124490 3C02CCCC */  lui   $v0, 0xcccc
/* 0BAB94 80124494 3442CCCD */  ori   $v0, $v0, 0xcccd
/* 0BAB98 80124498 02220019 */  multu $s1, $v0
/* 0BAB9C 8012449C 3C014059 */  lui   $at, 0x4059
/* 0BABA0 801244A0 44810800 */  mtc1  $at, $f1
/* 0BABA4 801244A4 44800000 */  mtc1  $zero, $f0
/* 0BABA8 801244A8 4600A521 */  cvt.d.s $f20, $f20
/* 0BABAC 801244AC 4620A503 */  div.d $f20, $f20, $f0
/* 0BABB0 801244B0 4620A520 */  cvt.s.d $f20, $f20
/* 0BABB4 801244B4 00004010 */  mfhi  $t0
/* 0BABB8 801244B8 00081902 */  srl   $v1, $t0, 4
/* 0BABBC 801244BC 00031080 */  sll   $v0, $v1, 2
/* 0BABC0 801244C0 00431021 */  addu  $v0, $v0, $v1
/* 0BABC4 801244C4 00021080 */  sll   $v0, $v0, 2
/* 0BABC8 801244C8 02221023 */  subu  $v0, $s1, $v0
/* 0BABCC 801244CC 304200FF */  andi  $v0, $v0, 0xff
/* 0BABD0 801244D0 00021880 */  sll   $v1, $v0, 2
/* 0BABD4 801244D4 00621821 */  addu  $v1, $v1, $v0
/* 0BABD8 801244D8 9602051C */  lhu   $v0, 0x51c($s0)
/* 0BABDC 801244DC 00031840 */  sll   $v1, $v1, 1
/* 0BABE0 801244E0 2442FF9C */  addiu $v0, $v0, -0x64
/* 0BABE4 801244E4 0C00A67F */  jal   rand_int
/* 0BABE8 801244E8 00629021 */   addu  $s2, $v1, $v0
/* 0BABEC 801244EC 2442004E */  addiu $v0, $v0, 0x4e
/* 0BABF0 801244F0 44820000 */  mtc1  $v0, $f0
/* 0BABF4 801244F4 00000000 */  nop   
/* 0BABF8 801244F8 46800020 */  cvt.s.w $f0, $f0
/* 0BABFC 801244FC 46140002 */  mul.s $f0, $f0, $f20
/* 0BAC00 80124500 00000000 */  nop   
/* 0BAC04 80124504 4600008D */  trunc.w.s $f2, $f0
/* 0BAC08 80124508 44021000 */  mfc1  $v0, $f2
/* 0BAC0C 8012450C 00000000 */  nop   
/* 0BAC10 80124510 0040282D */  daddu $a1, $v0, $zero
/* 0BAC14 80124514 00021400 */  sll   $v0, $v0, 0x10
/* 0BAC18 80124518 00021403 */  sra   $v0, $v0, 0x10
/* 0BAC1C 8012451C 28420100 */  slti  $v0, $v0, 0x100
/* 0BAC20 80124520 50400001 */  beql  $v0, $zero, .L80124528
/* 0BAC24 80124524 240500FF */   addiu $a1, $zero, 0xff
.L80124528:
/* 0BAC28 80124528 32220001 */  andi  $v0, $s1, 1
/* 0BAC2C 8012452C 10400004 */  beqz  $v0, .L80124540
/* 0BAC30 80124530 30A500FF */   andi  $a1, $a1, 0xff
/* 0BAC34 80124534 8E040520 */  lw    $a0, 0x520($s0)
/* 0BAC38 80124538 08049152 */  j     .L80124548
/* 0BAC3C 8012453C 00123C00 */   sll   $a3, $s2, 0x10

.L80124540:
/* 0BAC40 80124540 00123C00 */  sll   $a3, $s2, 0x10
/* 0BAC44 80124544 8E040524 */  lw    $a0, 0x524($s0)
.L80124548:
/* 0BAC48 80124548 9206051A */  lbu   $a2, 0x51a($s0)
/* 0BAC4C 8012454C 0C0526AE */  jal   _play_sound
/* 0BAC50 80124550 00073C03 */   sra   $a3, $a3, 0x10
.L80124554:
/* 0BAC54 80124554 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0BAC58 80124558 8FB20018 */  lw    $s2, 0x18($sp)
/* 0BAC5C 8012455C 8FB10014 */  lw    $s1, 0x14($sp)
/* 0BAC60 80124560 8FB00010 */  lw    $s0, 0x10($sp)
/* 0BAC64 80124564 D7B40020 */  ldc1  $f20, 0x20($sp)
/* 0BAC68 80124568 03E00008 */  jr    $ra
/* 0BAC6C 8012456C 27BD0028 */   addiu $sp, $sp, 0x28

