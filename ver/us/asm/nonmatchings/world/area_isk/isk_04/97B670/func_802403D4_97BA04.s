.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel jtbl_80242438_97DA68
.word .L802407E0_97BE10, .L802407EC_97BE1C, .L802407EC_97BE1C, .L802407EC_97BE1C, .L802407EC_97BE1C, .L802407EC_97BE1C, .L802407EC_97BE1C, .L802407EC_97BE1C, .L802407E0_97BE10, .L802407EC_97BE1C, .L802407E0_97BE10, .L802407EC_97BE1C, .L802407E0_97BE10, .L802407EC_97BE1C, .L802407E0_97BE10, .L802407EC_97BE1C, .L802407EC_97BE1C, .L802407EC_97BE1C, .L802407E0_97BE10, .L802407EC_97BE1C, .L802407E0_97BE10, 0

.section .text

glabel func_802403D4_97BA04
/* 97BA04 802403D4 27BDFF90 */  addiu     $sp, $sp, -0x70
/* 97BA08 802403D8 AFB3005C */  sw        $s3, 0x5c($sp)
/* 97BA0C 802403DC 0080982D */  daddu     $s3, $a0, $zero
/* 97BA10 802403E0 AFBF0068 */  sw        $ra, 0x68($sp)
/* 97BA14 802403E4 AFB50064 */  sw        $s5, 0x64($sp)
/* 97BA18 802403E8 AFB40060 */  sw        $s4, 0x60($sp)
/* 97BA1C 802403EC AFB20058 */  sw        $s2, 0x58($sp)
/* 97BA20 802403F0 AFB10054 */  sw        $s1, 0x54($sp)
/* 97BA24 802403F4 AFB00050 */  sw        $s0, 0x50($sp)
/* 97BA28 802403F8 8E710148 */  lw        $s1, 0x148($s3)
/* 97BA2C 802403FC 86240008 */  lh        $a0, 8($s1)
/* 97BA30 80240400 0C00EABB */  jal       get_npc_unsafe
/* 97BA34 80240404 00A0802D */   daddu    $s0, $a1, $zero
/* 97BA38 80240408 8E63000C */  lw        $v1, 0xc($s3)
/* 97BA3C 8024040C 0260202D */  daddu     $a0, $s3, $zero
/* 97BA40 80240410 8C650000 */  lw        $a1, ($v1)
/* 97BA44 80240414 0C0B1EAF */  jal       evt_get_variable
/* 97BA48 80240418 0040902D */   daddu    $s2, $v0, $zero
/* 97BA4C 8024041C AFA00028 */  sw        $zero, 0x28($sp)
/* 97BA50 80240420 8E2300D0 */  lw        $v1, 0xd0($s1)
/* 97BA54 80240424 8C630030 */  lw        $v1, 0x30($v1)
/* 97BA58 80240428 AFA3002C */  sw        $v1, 0x2c($sp)
/* 97BA5C 8024042C 8E2300D0 */  lw        $v1, 0xd0($s1)
/* 97BA60 80240430 8C63001C */  lw        $v1, 0x1c($v1)
/* 97BA64 80240434 AFA30030 */  sw        $v1, 0x30($sp)
/* 97BA68 80240438 8E2300D0 */  lw        $v1, 0xd0($s1)
/* 97BA6C 8024043C 8C630024 */  lw        $v1, 0x24($v1)
/* 97BA70 80240440 AFA30034 */  sw        $v1, 0x34($sp)
/* 97BA74 80240444 8E2300D0 */  lw        $v1, 0xd0($s1)
/* 97BA78 80240448 8C630028 */  lw        $v1, 0x28($v1)
/* 97BA7C 8024044C 27B50028 */  addiu     $s5, $sp, 0x28
/* 97BA80 80240450 AFA30038 */  sw        $v1, 0x38($sp)
/* 97BA84 80240454 8E2300D0 */  lw        $v1, 0xd0($s1)
/* 97BA88 80240458 3C0142C8 */  lui       $at, 0x42c8
/* 97BA8C 8024045C 44810000 */  mtc1      $at, $f0
/* 97BA90 80240460 8C63002C */  lw        $v1, 0x2c($v1)
/* 97BA94 80240464 0040A02D */  daddu     $s4, $v0, $zero
/* 97BA98 80240468 E7A00040 */  swc1      $f0, 0x40($sp)
/* 97BA9C 8024046C A7A00044 */  sh        $zero, 0x44($sp)
/* 97BAA0 80240470 12000009 */  beqz      $s0, .L80240498
/* 97BAA4 80240474 AFA3003C */   sw       $v1, 0x3c($sp)
/* 97BAA8 80240478 864300A8 */  lh        $v1, 0xa8($s2)
/* 97BAAC 8024047C 8E2200B0 */  lw        $v0, 0xb0($s1)
/* 97BAB0 80240480 AE20008C */  sw        $zero, 0x8c($s1)
/* 97BAB4 80240484 A22000B5 */  sb        $zero, 0xb5($s1)
/* 97BAB8 80240488 34420008 */  ori       $v0, $v0, 8
/* 97BABC 8024048C AE230084 */  sw        $v1, 0x84($s1)
/* 97BAC0 80240490 0809012A */  j         .L802404A8
/* 97BAC4 80240494 AE2200B0 */   sw       $v0, 0xb0($s1)
.L80240498:
/* 97BAC8 80240498 8E2200B0 */  lw        $v0, 0xb0($s1)
/* 97BACC 8024049C 30420004 */  andi      $v0, $v0, 4
/* 97BAD0 802404A0 10400047 */  beqz      $v0, .L802405C0
/* 97BAD4 802404A4 00000000 */   nop
.L802404A8:
/* 97BAD8 802404A8 AE600070 */  sw        $zero, 0x70($s3)
/* 97BADC 802404AC A640008E */  sh        $zero, 0x8e($s2)
/* 97BAE0 802404B0 8E2300CC */  lw        $v1, 0xcc($s1)
/* 97BAE4 802404B4 2404F7FF */  addiu     $a0, $zero, -0x801
/* 97BAE8 802404B8 A2200007 */  sb        $zero, 7($s1)
/* 97BAEC 802404BC 8E420000 */  lw        $v0, ($s2)
/* 97BAF0 802404C0 8C630000 */  lw        $v1, ($v1)
/* 97BAF4 802404C4 00441024 */  and       $v0, $v0, $a0
/* 97BAF8 802404C8 AE420000 */  sw        $v0, ($s2)
/* 97BAFC 802404CC AE430028 */  sw        $v1, 0x28($s2)
/* 97BB00 802404D0 96220086 */  lhu       $v0, 0x86($s1)
/* 97BB04 802404D4 A64200A8 */  sh        $v0, 0xa8($s2)
/* 97BB08 802404D8 8E2200D0 */  lw        $v0, 0xd0($s1)
/* 97BB0C 802404DC AE200090 */  sw        $zero, 0x90($s1)
/* 97BB10 802404E0 8C420034 */  lw        $v0, 0x34($v0)
/* 97BB14 802404E4 14400006 */  bnez      $v0, .L80240500
/* 97BB18 802404E8 2403FDFF */   addiu    $v1, $zero, -0x201
/* 97BB1C 802404EC 8E420000 */  lw        $v0, ($s2)
/* 97BB20 802404F0 2403FFF7 */  addiu     $v1, $zero, -9
/* 97BB24 802404F4 34420200 */  ori       $v0, $v0, 0x200
/* 97BB28 802404F8 08090143 */  j         .L8024050C
/* 97BB2C 802404FC 00431024 */   and      $v0, $v0, $v1
.L80240500:
/* 97BB30 80240500 8E420000 */  lw        $v0, ($s2)
/* 97BB34 80240504 00431024 */  and       $v0, $v0, $v1
/* 97BB38 80240508 34420008 */  ori       $v0, $v0, 8
.L8024050C:
/* 97BB3C 8024050C AE420000 */  sw        $v0, ($s2)
/* 97BB40 80240510 8E2200B0 */  lw        $v0, 0xb0($s1)
/* 97BB44 80240514 30420004 */  andi      $v0, $v0, 4
/* 97BB48 80240518 1040001E */  beqz      $v0, .L80240594
/* 97BB4C 8024051C 24040002 */   addiu    $a0, $zero, 2
/* 97BB50 80240520 0240282D */  daddu     $a1, $s2, $zero
/* 97BB54 80240524 0000302D */  daddu     $a2, $zero, $zero
/* 97BB58 80240528 24020063 */  addiu     $v0, $zero, 0x63
/* 97BB5C 8024052C AE620070 */  sw        $v0, 0x70($s3)
/* 97BB60 80240530 AE600074 */  sw        $zero, 0x74($s3)
/* 97BB64 80240534 864300A8 */  lh        $v1, 0xa8($s2)
/* 97BB68 80240538 3C013F80 */  lui       $at, 0x3f80
/* 97BB6C 8024053C 44810000 */  mtc1      $at, $f0
/* 97BB70 80240540 3C014000 */  lui       $at, 0x4000
/* 97BB74 80240544 44811000 */  mtc1      $at, $f2
/* 97BB78 80240548 3C01C1A0 */  lui       $at, 0xc1a0
/* 97BB7C 8024054C 44812000 */  mtc1      $at, $f4
/* 97BB80 80240550 24020028 */  addiu     $v0, $zero, 0x28
/* 97BB84 80240554 AFA2001C */  sw        $v0, 0x1c($sp)
/* 97BB88 80240558 44833000 */  mtc1      $v1, $f6
/* 97BB8C 8024055C 00000000 */  nop
/* 97BB90 80240560 468031A0 */  cvt.s.w   $f6, $f6
/* 97BB94 80240564 44073000 */  mfc1      $a3, $f6
/* 97BB98 80240568 27A20048 */  addiu     $v0, $sp, 0x48
/* 97BB9C 8024056C AFA20020 */  sw        $v0, 0x20($sp)
/* 97BBA0 80240570 E7A00010 */  swc1      $f0, 0x10($sp)
/* 97BBA4 80240574 E7A20014 */  swc1      $f2, 0x14($sp)
/* 97BBA8 80240578 0C01BFA4 */  jal       fx_emote
/* 97BBAC 8024057C E7A40018 */   swc1     $f4, 0x18($sp)
/* 97BBB0 80240580 8E2200B0 */  lw        $v0, 0xb0($s1)
/* 97BBB4 80240584 2403FFFB */  addiu     $v1, $zero, -5
/* 97BBB8 80240588 00431024 */  and       $v0, $v0, $v1
/* 97BBBC 8024058C 08090170 */  j         .L802405C0
/* 97BBC0 80240590 AE2200B0 */   sw       $v0, 0xb0($s1)
.L80240594:
/* 97BBC4 80240594 8E220000 */  lw        $v0, ($s1)
/* 97BBC8 80240598 3C034000 */  lui       $v1, 0x4000
/* 97BBCC 8024059C 00431024 */  and       $v0, $v0, $v1
/* 97BBD0 802405A0 10400007 */  beqz      $v0, .L802405C0
/* 97BBD4 802405A4 3C03BFFF */   lui      $v1, 0xbfff
/* 97BBD8 802405A8 2402000C */  addiu     $v0, $zero, 0xc
/* 97BBDC 802405AC AE620070 */  sw        $v0, 0x70($s3)
/* 97BBE0 802405B0 8E220000 */  lw        $v0, ($s1)
/* 97BBE4 802405B4 3463FFFF */  ori       $v1, $v1, 0xffff
/* 97BBE8 802405B8 00431024 */  and       $v0, $v0, $v1
/* 97BBEC 802405BC AE220000 */  sw        $v0, ($s1)
.L802405C0:
/* 97BBF0 802405C0 8E220090 */  lw        $v0, 0x90($s1)
/* 97BBF4 802405C4 1840000C */  blez      $v0, .L802405F8
/* 97BBF8 802405C8 2442FFFF */   addiu    $v0, $v0, -1
/* 97BBFC 802405CC 14400087 */  bnez      $v0, .L802407EC_97BE1C
/* 97BC00 802405D0 AE220090 */   sw       $v0, 0x90($s1)
/* 97BC04 802405D4 3C03FFAA */  lui       $v1, 0xffaa
/* 97BC08 802405D8 8E420028 */  lw        $v0, 0x28($s2)
/* 97BC0C 802405DC 3463FFD2 */  ori       $v1, $v1, 0xffd2
/* 97BC10 802405E0 00431021 */  addu      $v0, $v0, $v1
/* 97BC14 802405E4 2C420002 */  sltiu     $v0, $v0, 2
/* 97BC18 802405E8 10400003 */  beqz      $v0, .L802405F8
/* 97BC1C 802405EC 3C020055 */   lui      $v0, 0x55
/* 97BC20 802405F0 3442000C */  ori       $v0, $v0, 0xc
/* 97BC24 802405F4 AE420028 */  sw        $v0, 0x28($s2)
.L802405F8:
/* 97BC28 802405F8 8E630070 */  lw        $v1, 0x70($s3)
/* 97BC2C 802405FC 2402000C */  addiu     $v0, $zero, 0xc
/* 97BC30 80240600 10620048 */  beq       $v1, $v0, .L80240724
/* 97BC34 80240604 2862000D */   slti     $v0, $v1, 0xd
/* 97BC38 80240608 1040000F */  beqz      $v0, .L80240648
/* 97BC3C 8024060C 24100001 */   addiu    $s0, $zero, 1
/* 97BC40 80240610 1070001E */  beq       $v1, $s0, .L8024068C
/* 97BC44 80240614 28620002 */   slti     $v0, $v1, 2
/* 97BC48 80240618 10400005 */  beqz      $v0, .L80240630
/* 97BC4C 8024061C 24020002 */   addiu    $v0, $zero, 2
/* 97BC50 80240620 10600015 */  beqz      $v1, .L80240678
/* 97BC54 80240624 0260202D */   daddu    $a0, $s3, $zero
/* 97BC58 80240628 080901E0 */  j         .L80240780
/* 97BC5C 8024062C 00000000 */   nop
.L80240630:
/* 97BC60 80240630 1062001C */  beq       $v1, $v0, .L802406A4
/* 97BC64 80240634 24020003 */   addiu    $v0, $zero, 3
/* 97BC68 80240638 10620035 */  beq       $v1, $v0, .L80240710
/* 97BC6C 8024063C 0260202D */   daddu    $a0, $s3, $zero
/* 97BC70 80240640 080901E0 */  j         .L80240780
/* 97BC74 80240644 00000000 */   nop
.L80240648:
/* 97BC78 80240648 2402000E */  addiu     $v0, $zero, 0xe
/* 97BC7C 8024064C 1062003F */  beq       $v1, $v0, .L8024074C
/* 97BC80 80240650 0062102A */   slt      $v0, $v1, $v0
/* 97BC84 80240654 14400038 */  bnez      $v0, .L80240738
/* 97BC88 80240658 0260202D */   daddu    $a0, $s3, $zero
/* 97BC8C 8024065C 2402000F */  addiu     $v0, $zero, 0xf
/* 97BC90 80240660 10620040 */  beq       $v1, $v0, .L80240764
/* 97BC94 80240664 24020063 */   addiu    $v0, $zero, 0x63
/* 97BC98 80240668 10620043 */  beq       $v1, $v0, .L80240778
/* 97BC9C 8024066C 00000000 */   nop
/* 97BCA0 80240670 080901E0 */  j         .L80240780
/* 97BCA4 80240674 00000000 */   nop
.L80240678:
/* 97BCA8 80240678 0280282D */  daddu     $a1, $s4, $zero
/* 97BCAC 8024067C 0C012568 */  jal       func_800495A0
/* 97BCB0 80240680 02A0302D */   daddu    $a2, $s5, $zero
/* 97BCB4 80240684 96220086 */  lhu       $v0, 0x86($s1)
/* 97BCB8 80240688 A64200A8 */  sh        $v0, 0xa8($s2)
.L8024068C:
/* 97BCBC 8024068C 0260202D */  daddu     $a0, $s3, $zero
/* 97BCC0 80240690 0280282D */  daddu     $a1, $s4, $zero
/* 97BCC4 80240694 0C0125AE */  jal       func_800496B8
/* 97BCC8 80240698 02A0302D */   daddu    $a2, $s5, $zero
/* 97BCCC 8024069C 080901E0 */  j         .L80240780
/* 97BCD0 802406A0 00000000 */   nop
.L802406A4:
/* 97BCD4 802406A4 0260202D */  daddu     $a0, $s3, $zero
/* 97BCD8 802406A8 0280282D */  daddu     $a1, $s4, $zero
/* 97BCDC 802406AC 0C0126D1 */  jal       base_UnkNpcAIFunc1
/* 97BCE0 802406B0 02A0302D */   daddu    $a2, $s5, $zero
/* 97BCE4 802406B4 8E230088 */  lw        $v1, 0x88($s1)
/* 97BCE8 802406B8 24020006 */  addiu     $v0, $zero, 6
/* 97BCEC 802406BC 14620014 */  bne       $v1, $v0, .L80240710
/* 97BCF0 802406C0 0260202D */   daddu    $a0, $s3, $zero
/* 97BCF4 802406C4 0C00A67F */  jal       rand_int
/* 97BCF8 802406C8 24040064 */   addiu    $a0, $zero, 0x64
/* 97BCFC 802406CC 28420021 */  slti      $v0, $v0, 0x21
/* 97BD00 802406D0 5040000F */  beql      $v0, $zero, .L80240710
/* 97BD04 802406D4 0260202D */   daddu    $a0, $s3, $zero
/* 97BD08 802406D8 8E22008C */  lw        $v0, 0x8c($s1)
/* 97BD0C 802406DC 10400005 */  beqz      $v0, .L802406F4
/* 97BD10 802406E0 3C020055 */   lui      $v0, 0x55
/* 97BD14 802406E4 3442002F */  ori       $v0, $v0, 0x2f
/* 97BD18 802406E8 AE20008C */  sw        $zero, 0x8c($s1)
/* 97BD1C 802406EC 080901C0 */  j         .L80240700
/* 97BD20 802406F0 A22000B5 */   sb       $zero, 0xb5($s1)
.L802406F4:
/* 97BD24 802406F4 3442002E */  ori       $v0, $v0, 0x2e
/* 97BD28 802406F8 AE30008C */  sw        $s0, 0x8c($s1)
/* 97BD2C 802406FC A23000B5 */  sb        $s0, 0xb5($s1)
.L80240700:
/* 97BD30 80240700 AE420028 */  sw        $v0, 0x28($s2)
/* 97BD34 80240704 24020007 */  addiu     $v0, $zero, 7
/* 97BD38 80240708 080901FB */  j         .L802407EC_97BE1C
/* 97BD3C 8024070C AE220090 */   sw       $v0, 0x90($s1)
.L80240710:
/* 97BD40 80240710 0280282D */  daddu     $a1, $s4, $zero
/* 97BD44 80240714 0C012701 */  jal       func_80049C04
/* 97BD48 80240718 02A0302D */   daddu    $a2, $s5, $zero
/* 97BD4C 8024071C 080901E0 */  j         .L80240780
/* 97BD50 80240720 00000000 */   nop
.L80240724:
/* 97BD54 80240724 0260202D */  daddu     $a0, $s3, $zero
/* 97BD58 80240728 0280282D */  daddu     $a1, $s4, $zero
/* 97BD5C 8024072C 0C090010 */  jal       isk_04_set_script_owner_npc_anim
/* 97BD60 80240730 02A0302D */   daddu    $a2, $s5, $zero
/* 97BD64 80240734 0260202D */  daddu     $a0, $s3, $zero
.L80240738:
/* 97BD68 80240738 0280282D */  daddu     $a1, $s4, $zero
/* 97BD6C 8024073C 0C09002F */  jal       isk_04_UnkDistFunc
/* 97BD70 80240740 02A0302D */   daddu    $a2, $s5, $zero
/* 97BD74 80240744 080901E0 */  j         .L80240780
/* 97BD78 80240748 00000000 */   nop
.L8024074C:
/* 97BD7C 8024074C 0260202D */  daddu     $a0, $s3, $zero
/* 97BD80 80240750 0280282D */  daddu     $a1, $s4, $zero
/* 97BD84 80240754 0C09007C */  jal       isk_04_UnkNpcAIFunc12
/* 97BD88 80240758 02A0302D */   daddu    $a2, $s5, $zero
/* 97BD8C 8024075C 080901E0 */  j         .L80240780
/* 97BD90 80240760 00000000 */   nop
.L80240764:
/* 97BD94 80240764 0280282D */  daddu     $a1, $s4, $zero
/* 97BD98 80240768 0C0900D5 */  jal       isk_04_set_script_owner_npc_col_height
/* 97BD9C 8024076C 02A0302D */   daddu    $a2, $s5, $zero
/* 97BDA0 80240770 080901E0 */  j         .L80240780
/* 97BDA4 80240774 00000000 */   nop
.L80240778:
/* 97BDA8 80240778 0C0129CF */  jal       func_8004A73C
/* 97BDAC 8024077C 0260202D */   daddu    $a0, $s3, $zero
.L80240780:
/* 97BDB0 80240780 8E230088 */  lw        $v1, 0x88($s1)
/* 97BDB4 80240784 24020006 */  addiu     $v0, $zero, 6
/* 97BDB8 80240788 14620019 */  bne       $v1, $v0, .L802407F0
/* 97BDBC 8024078C 0000102D */   daddu    $v0, $zero, $zero
/* 97BDC0 80240790 8E22008C */  lw        $v0, 0x8c($s1)
/* 97BDC4 80240794 10400003 */  beqz      $v0, .L802407A4
/* 97BDC8 80240798 24020001 */   addiu    $v0, $zero, 1
/* 97BDCC 8024079C 080901EA */  j         .L802407A8
/* 97BDD0 802407A0 A22200B5 */   sb       $v0, 0xb5($s1)
.L802407A4:
/* 97BDD4 802407A4 A22000B5 */  sb        $zero, 0xb5($s1)
.L802407A8:
/* 97BDD8 802407A8 8E22008C */  lw        $v0, 0x8c($s1)
/* 97BDDC 802407AC 1040000F */  beqz      $v0, .L802407EC_97BE1C
/* 97BDE0 802407B0 3C03FFAA */   lui      $v1, 0xffaa
/* 97BDE4 802407B4 8E420028 */  lw        $v0, 0x28($s2)
/* 97BDE8 802407B8 3463FFFC */  ori       $v1, $v1, 0xfffc
/* 97BDEC 802407BC 00431821 */  addu      $v1, $v0, $v1
/* 97BDF0 802407C0 2C620015 */  sltiu     $v0, $v1, 0x15
/* 97BDF4 802407C4 10400009 */  beqz      $v0, .L802407EC_97BE1C
/* 97BDF8 802407C8 00031080 */   sll      $v0, $v1, 2
/* 97BDFC 802407CC 3C018024 */  lui       $at, %hi(jtbl_80242438_97DA68)
/* 97BE00 802407D0 00220821 */  addu      $at, $at, $v0
/* 97BE04 802407D4 8C222438 */  lw        $v0, %lo(jtbl_80242438_97DA68)($at)
/* 97BE08 802407D8 00400008 */  jr        $v0
/* 97BE0C 802407DC 00000000 */   nop
.L802407E0_97BE10:
/* 97BE10 802407E0 8E420028 */  lw        $v0, 0x28($s2)
/* 97BE14 802407E4 24420001 */  addiu     $v0, $v0, 1
/* 97BE18 802407E8 AE420028 */  sw        $v0, 0x28($s2)
.L802407EC_97BE1C:
/* 97BE1C 802407EC 0000102D */  daddu     $v0, $zero, $zero
.L802407F0:
/* 97BE20 802407F0 8FBF0068 */  lw        $ra, 0x68($sp)
/* 97BE24 802407F4 8FB50064 */  lw        $s5, 0x64($sp)
/* 97BE28 802407F8 8FB40060 */  lw        $s4, 0x60($sp)
/* 97BE2C 802407FC 8FB3005C */  lw        $s3, 0x5c($sp)
/* 97BE30 80240800 8FB20058 */  lw        $s2, 0x58($sp)
/* 97BE34 80240804 8FB10054 */  lw        $s1, 0x54($sp)
/* 97BE38 80240808 8FB00050 */  lw        $s0, 0x50($sp)
/* 97BE3C 8024080C 03E00008 */  jr        $ra
/* 97BE40 80240810 27BD0070 */   addiu    $sp, $sp, 0x70
