.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80054478
/* 2F878 80054478 27BDFF80 */  addiu     $sp, $sp, -0x80
/* 2F87C 8005447C AFB5006C */  sw        $s5, 0x6c($sp)
/* 2F880 80054480 0080A82D */  daddu     $s5, $a0, $zero
/* 2F884 80054484 AFB40068 */  sw        $s4, 0x68($sp)
/* 2F888 80054488 00A0A02D */  daddu     $s4, $a1, $zero
/* 2F88C 8005448C AFB70074 */  sw        $s7, 0x74($sp)
/* 2F890 80054490 00C0B82D */  daddu     $s7, $a2, $zero
/* 2F894 80054494 AFBE0078 */  sw        $fp, 0x78($sp)
/* 2F898 80054498 00E0F02D */  daddu     $fp, $a3, $zero
/* 2F89C 8005449C AFB1005C */  sw        $s1, 0x5c($sp)
/* 2F8A0 800544A0 27B10018 */  addiu     $s1, $sp, 0x18
/* 2F8A4 800544A4 0220282D */  daddu     $a1, $s1, $zero
/* 2F8A8 800544A8 3C028008 */  lui       $v0, %hi(D_80078E24)
/* 2F8AC 800544AC 8C428E24 */  lw        $v0, %lo(D_80078E24)($v0)
/* 2F8B0 800544B0 24060040 */  addiu     $a2, $zero, 0x40
/* 2F8B4 800544B4 AFB30064 */  sw        $s3, 0x64($sp)
/* 2F8B8 800544B8 2413000B */  addiu     $s3, $zero, 0xb
/* 2F8BC 800544BC AFB20060 */  sw        $s2, 0x60($sp)
/* 2F8C0 800544C0 AFBF007C */  sw        $ra, 0x7c($sp)
/* 2F8C4 800544C4 AFB60070 */  sw        $s6, 0x70($sp)
/* 2F8C8 800544C8 AFB00058 */  sw        $s0, 0x58($sp)
/* 2F8CC 800544CC 8C560018 */  lw        $s6, 0x18($v0)
/* 2F8D0 800544D0 0C0152AC */  jal       func_80054AB0
/* 2F8D4 800544D4 24120001 */   addiu    $s2, $zero, 1
/* 2F8D8 800544D8 3263FFFF */  andi      $v1, $s3, 0xffff
.L800544DC:
/* 2F8DC 800544DC 2402006F */  addiu     $v0, $zero, 0x6f
/* 2F8E0 800544E0 10620057 */  beq       $v1, $v0, .L80054640
/* 2F8E4 800544E4 28620070 */   slti     $v0, $v1, 0x70
/* 2F8E8 800544E8 1040005E */  beqz      $v0, .L80054664
/* 2F8EC 800544EC 2402000B */   addiu    $v0, $zero, 0xb
/* 2F8F0 800544F0 1062000A */  beq       $v1, $v0, .L8005451C
/* 2F8F4 800544F4 2862000C */   slti     $v0, $v1, 0xc
/* 2F8F8 800544F8 5440005B */  bnel      $v0, $zero, .L80054668
/* 2F8FC 800544FC 0000902D */   daddu    $s2, $zero, $zero
/* 2F900 80054500 24020015 */  addiu     $v0, $zero, 0x15
/* 2F904 80054504 1062000E */  beq       $v1, $v0, .L80054540
/* 2F908 80054508 24020065 */   addiu    $v0, $zero, 0x65
/* 2F90C 8005450C 1062001A */  beq       $v1, $v0, .L80054578
/* 2F910 80054510 00000000 */   nop
/* 2F914 80054514 0801519A */  j         .L80054668
/* 2F918 80054518 0000902D */   daddu    $s2, $zero, $zero
.L8005451C:
/* 2F91C 8005451C 96230000 */  lhu       $v1, ($s1)
/* 2F920 80054520 2402424B */  addiu     $v0, $zero, 0x424b
/* 2F924 80054524 54620050 */  bnel      $v1, $v0, .L80054668
/* 2F928 80054528 0000902D */   daddu    $s2, $zero, $zero
/* 2F92C 8005452C 8E220004 */  lw        $v0, 4($s1)
/* 2F930 80054530 5040004D */  beql      $v0, $zero, .L80054668
/* 2F934 80054534 0000902D */   daddu    $s2, $zero, $zero
/* 2F938 80054538 0801519A */  j         .L80054668
/* 2F93C 8005453C 24130015 */   addiu    $s3, $zero, 0x15
.L80054540:
/* 2F940 80054540 9623000C */  lhu       $v1, 0xc($s1)
/* 2F944 80054544 24024352 */  addiu     $v0, $zero, 0x4352
/* 2F948 80054548 14620003 */  bne       $v1, $v0, .L80054558
/* 2F94C 8005454C 24024452 */   addiu    $v0, $zero, 0x4452
/* 2F950 80054550 0801519A */  j         .L80054668
/* 2F954 80054554 24130065 */   addiu    $s3, $zero, 0x65
.L80054558:
/* 2F958 80054558 14620003 */  bne       $v1, $v0, .L80054568
/* 2F95C 8005455C 24025352 */   addiu    $v0, $zero, 0x5352
/* 2F960 80054560 0801519A */  j         .L80054668
/* 2F964 80054564 241300C9 */   addiu    $s3, $zero, 0xc9
.L80054568:
/* 2F968 80054568 5462003F */  bnel      $v1, $v0, .L80054668
/* 2F96C 8005456C 0000902D */   daddu    $s2, $zero, $zero
/* 2F970 80054570 0801519A */  j         .L80054668
/* 2F974 80054574 2413012D */   addiu    $s3, $zero, 0x12d
.L80054578:
/* 2F978 80054578 96240032 */  lhu       $a0, 0x32($s1)
/* 2F97C 8005457C 96220036 */  lhu       $v0, 0x36($s1)
/* 2F980 80054580 9623003A */  lhu       $v1, 0x3a($s1)
/* 2F984 80054584 2484000F */  addiu     $a0, $a0, 0xf
/* 2F988 80054588 3084FFF0 */  andi      $a0, $a0, 0xfff0
/* 2F98C 8005458C 2442000F */  addiu     $v0, $v0, 0xf
/* 2F990 80054590 3042FFF0 */  andi      $v0, $v0, 0xfff0
/* 2F994 80054594 00822021 */  addu      $a0, $a0, $v0
/* 2F998 80054598 2463000F */  addiu     $v1, $v1, 0xf
/* 2F99C 8005459C 3063FFF0 */  andi      $v1, $v1, 0xfff0
/* 2F9A0 800545A0 9622003E */  lhu       $v0, 0x3e($s1)
/* 2F9A4 800545A4 00832021 */  addu      $a0, $a0, $v1
/* 2F9A8 800545A8 2442000F */  addiu     $v0, $v0, 0xf
/* 2F9AC 800545AC 3042FFF0 */  andi      $v0, $v0, 0xfff0
/* 2F9B0 800545B0 00822021 */  addu      $a0, $a0, $v0
/* 2F9B4 800545B4 16800006 */  bnez      $s4, .L800545D0
/* 2F9B8 800545B8 24900040 */   addiu    $s0, $a0, 0x40
/* 2F9BC 800545BC 02C0202D */  daddu     $a0, $s6, $zero
/* 2F9C0 800545C0 24050001 */  addiu     $a1, $zero, 1
/* 2F9C4 800545C4 0C015F10 */  jal       func_80057C40
/* 2F9C8 800545C8 0200302D */   daddu    $a2, $s0, $zero
/* 2F9CC 800545CC 0040A02D */  daddu     $s4, $v0, $zero
.L800545D0:
/* 2F9D0 800545D0 02A0202D */  daddu     $a0, $s5, $zero
/* 2F9D4 800545D4 0280282D */  daddu     $a1, $s4, $zero
/* 2F9D8 800545D8 0C0152AC */  jal       func_80054AB0
/* 2F9DC 800545DC 0200302D */   daddu    $a2, $s0, $zero
/* 2F9E0 800545E0 03C0202D */  daddu     $a0, $fp, $zero
/* 2F9E4 800545E4 0C0150FD */  jal       func_800543F4
/* 2F9E8 800545E8 02E0282D */   daddu    $a1, $s7, $zero
/* 2F9EC 800545EC 0040802D */  daddu     $s0, $v0, $zero
/* 2F9F0 800545F0 0200182D */  daddu     $v1, $s0, $zero
/* 2F9F4 800545F4 0000302D */  daddu     $a2, $zero, $zero
/* 2F9F8 800545F8 00C0282D */  daddu     $a1, $a2, $zero
/* 2F9FC 800545FC 0220202D */  daddu     $a0, $s1, $zero
.L80054600:
/* 2FA00 80054600 94820012 */  lhu       $v0, 0x12($a0)
/* 2FA04 80054604 10400004 */  beqz      $v0, .L80054618
/* 2FA08 80054608 00541021 */   addu     $v0, $v0, $s4
/* 2FA0C 8005460C 24C60001 */  addiu     $a2, $a2, 1
/* 2FA10 80054610 08015187 */  j         .L8005461C
/* 2FA14 80054614 AC620000 */   sw       $v0, ($v1)
.L80054618:
/* 2FA18 80054618 AC600000 */  sw        $zero, ($v1)
.L8005461C:
/* 2FA1C 8005461C 24630004 */  addiu     $v1, $v1, 4
/* 2FA20 80054620 24A50001 */  addiu     $a1, $a1, 1
/* 2FA24 80054624 2CA20010 */  sltiu     $v0, $a1, 0x10
/* 2FA28 80054628 1440FFF5 */  bnez      $v0, .L80054600
/* 2FA2C 8005462C 24840002 */   addiu    $a0, $a0, 2
/* 2FA30 80054630 50C0000D */  beql      $a2, $zero, .L80054668
/* 2FA34 80054634 0000902D */   daddu    $s2, $zero, $zero
/* 2FA38 80054638 0801519A */  j         .L80054668
/* 2FA3C 8005463C 2413006F */   addiu    $s3, $zero, 0x6f
.L80054640:
/* 2FA40 80054640 24020001 */  addiu     $v0, $zero, 1
/* 2FA44 80054644 AFA20010 */  sw        $v0, 0x10($sp)
/* 2FA48 80054648 02A0202D */  daddu     $a0, $s5, $zero
/* 2FA4C 8005464C 0280282D */  daddu     $a1, $s4, $zero
/* 2FA50 80054650 0200302D */  daddu     $a2, $s0, $zero
/* 2FA54 80054654 0C0151AA */  jal       func_800546A8
/* 2FA58 80054658 24070010 */   addiu    $a3, $zero, 0x10
/* 2FA5C 8005465C 0801519A */  j         .L80054668
/* 2FA60 80054660 0000982D */   daddu    $s3, $zero, $zero
.L80054664:
/* 2FA64 80054664 0000902D */  daddu     $s2, $zero, $zero
.L80054668:
/* 2FA68 80054668 3242FFFF */  andi      $v0, $s2, 0xffff
/* 2FA6C 8005466C 1440FF9B */  bnez      $v0, .L800544DC
/* 2FA70 80054670 3263FFFF */   andi     $v1, $s3, 0xffff
/* 2FA74 80054674 0280102D */  daddu     $v0, $s4, $zero
/* 2FA78 80054678 8FBF007C */  lw        $ra, 0x7c($sp)
/* 2FA7C 8005467C 8FBE0078 */  lw        $fp, 0x78($sp)
/* 2FA80 80054680 8FB70074 */  lw        $s7, 0x74($sp)
/* 2FA84 80054684 8FB60070 */  lw        $s6, 0x70($sp)
/* 2FA88 80054688 8FB5006C */  lw        $s5, 0x6c($sp)
/* 2FA8C 8005468C 8FB40068 */  lw        $s4, 0x68($sp)
/* 2FA90 80054690 8FB30064 */  lw        $s3, 0x64($sp)
/* 2FA94 80054694 8FB20060 */  lw        $s2, 0x60($sp)
/* 2FA98 80054698 8FB1005C */  lw        $s1, 0x5c($sp)
/* 2FA9C 8005469C 8FB00058 */  lw        $s0, 0x58($sp)
/* 2FAA0 800546A0 03E00008 */  jr        $ra
/* 2FAA4 800546A4 27BD0080 */   addiu    $sp, $sp, 0x80
