.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8025BAA0
/* 18A380 8025BAA0 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 18A384 8025BAA4 AFB40020 */  sw        $s4, 0x20($sp)
/* 18A388 8025BAA8 0080A02D */  daddu     $s4, $a0, $zero
/* 18A38C 8025BAAC AFB20018 */  sw        $s2, 0x18($sp)
/* 18A390 8025BAB0 00A0902D */  daddu     $s2, $a1, $zero
/* 18A394 8025BAB4 AFB50024 */  sw        $s5, 0x24($sp)
/* 18A398 8025BAB8 00C0A82D */  daddu     $s5, $a2, $zero
/* 18A39C 8025BABC AFB3001C */  sw        $s3, 0x1c($sp)
/* 18A3A0 8025BAC0 AFBF0030 */  sw        $ra, 0x30($sp)
/* 18A3A4 8025BAC4 AFB7002C */  sw        $s7, 0x2c($sp)
/* 18A3A8 8025BAC8 AFB60028 */  sw        $s6, 0x28($sp)
/* 18A3AC 8025BACC AFB10014 */  sw        $s1, 0x14($sp)
/* 18A3B0 8025BAD0 AFB00010 */  sw        $s0, 0x10($sp)
/* 18A3B4 8025BAD4 8E5000C0 */  lw        $s0, 0xc0($s2)
/* 18A3B8 8025BAD8 8FB60048 */  lw        $s6, 0x48($sp)
/* 18A3BC 8025BADC 820206C1 */  lb        $v0, 0x6c1($s0)
/* 18A3C0 8025BAE0 8FB1004C */  lw        $s1, 0x4c($sp)
/* 18A3C4 8025BAE4 1040005A */  beqz      $v0, .L8025BC50
/* 18A3C8 8025BAE8 00E0982D */   daddu    $s3, $a3, $zero
/* 18A3CC 8025BAEC 16800016 */  bnez      $s4, .L8025BB48
/* 18A3D0 8025BAF0 00000000 */   nop
/* 18A3D4 8025BAF4 0C0B7830 */  jal       spr_get_player_palettes
/* 18A3D8 8025BAF8 96440088 */   lhu      $a0, 0x88($s2)
/* 18A3DC 8025BAFC AE0206D0 */  sw        $v0, 0x6d0($s0)
/* 18A3E0 8025BB00 0040202D */  daddu     $a0, $v0, $zero
/* 18A3E4 8025BB04 A20006CD */  sb        $zero, 0x6cd($s0)
/* 18A3E8 8025BB08 8C830000 */  lw        $v1, ($a0)
/* 18A3EC 8025BB0C 2402FFFF */  addiu     $v0, $zero, -1
/* 18A3F0 8025BB10 10620020 */  beq       $v1, $v0, .L8025BB94
/* 18A3F4 8025BB14 0080182D */   daddu    $v1, $a0, $zero
/* 18A3F8 8025BB18 0040202D */  daddu     $a0, $v0, $zero
.L8025BB1C:
/* 18A3FC 8025BB1C 920206CD */  lbu       $v0, 0x6cd($s0)
/* 18A400 8025BB20 24420001 */  addiu     $v0, $v0, 1
/* 18A404 8025BB24 A20206CD */  sb        $v0, 0x6cd($s0)
/* 18A408 8025BB28 00021600 */  sll       $v0, $v0, 0x18
/* 18A40C 8025BB2C 00021583 */  sra       $v0, $v0, 0x16
/* 18A410 8025BB30 00431021 */  addu      $v0, $v0, $v1
/* 18A414 8025BB34 8C420000 */  lw        $v0, ($v0)
/* 18A418 8025BB38 10440016 */  beq       $v0, $a0, .L8025BB94
/* 18A41C 8025BB3C 00000000 */   nop
/* 18A420 8025BB40 08096EC7 */  j         .L8025BB1C
/* 18A424 8025BB44 00000000 */   nop
.L8025BB48:
/* 18A428 8025BB48 0C0B7A90 */  jal       spr_get_npc_palettes
/* 18A42C 8025BB4C 96440088 */   lhu      $a0, 0x88($s2)
/* 18A430 8025BB50 AE0206D0 */  sw        $v0, 0x6d0($s0)
/* 18A434 8025BB54 0040202D */  daddu     $a0, $v0, $zero
/* 18A438 8025BB58 A20006CD */  sb        $zero, 0x6cd($s0)
/* 18A43C 8025BB5C 8C830000 */  lw        $v1, ($a0)
/* 18A440 8025BB60 2402FFFF */  addiu     $v0, $zero, -1
/* 18A444 8025BB64 1062000B */  beq       $v1, $v0, .L8025BB94
/* 18A448 8025BB68 0080182D */   daddu    $v1, $a0, $zero
/* 18A44C 8025BB6C 0040202D */  daddu     $a0, $v0, $zero
.L8025BB70:
/* 18A450 8025BB70 920206CD */  lbu       $v0, 0x6cd($s0)
/* 18A454 8025BB74 24420001 */  addiu     $v0, $v0, 1
/* 18A458 8025BB78 A20206CD */  sb        $v0, 0x6cd($s0)
/* 18A45C 8025BB7C 00021600 */  sll       $v0, $v0, 0x18
/* 18A460 8025BB80 00021583 */  sra       $v0, $v0, 0x16
/* 18A464 8025BB84 00431021 */  addu      $v0, $v0, $v1
/* 18A468 8025BB88 8C420000 */  lw        $v0, ($v0)
/* 18A46C 8025BB8C 1444FFF8 */  bne       $v0, $a0, .L8025BB70
/* 18A470 8025BB90 00000000 */   nop
.L8025BB94:
/* 18A474 8025BB94 820306C1 */  lb        $v1, 0x6c1($s0)
/* 18A478 8025BB98 24020001 */  addiu     $v0, $zero, 1
/* 18A47C 8025BB9C 14620004 */  bne       $v1, $v0, .L8025BBB0
/* 18A480 8025BBA0 240200FF */   addiu    $v0, $zero, 0xff
/* 18A484 8025BBA4 A20006C2 */  sb        $zero, 0x6c2($s0)
/* 18A488 8025BBA8 08096EEE */  j         .L8025BBB8
/* 18A48C 8025BBAC A60006CA */   sh       $zero, 0x6ca($s0)
.L8025BBB0:
/* 18A490 8025BBB0 A20006C2 */  sb        $zero, 0x6c2($s0)
/* 18A494 8025BBB4 A60206CA */  sh        $v0, 0x6ca($s0)
.L8025BBB8:
/* 18A498 8025BBB8 820206CD */  lb        $v0, 0x6cd($s0)
/* 18A49C 8025BBBC 18400017 */  blez      $v0, .L8025BC1C
/* 18A4A0 8025BBC0 0000202D */   daddu    $a0, $zero, $zero
/* 18A4A4 8025BBC4 0200282D */  daddu     $a1, $s0, $zero
.L8025BBC8:
/* 18A4A8 8025BBC8 8E0206D0 */  lw        $v0, 0x6d0($s0)
/* 18A4AC 8025BBCC 00041880 */  sll       $v1, $a0, 2
/* 18A4B0 8025BBD0 00621821 */  addu      $v1, $v1, $v0
/* 18A4B4 8025BBD4 00041140 */  sll       $v0, $a0, 5
/* 18A4B8 8025BBD8 8C6A0000 */  lw        $t2, ($v1)
/* 18A4BC 8025BBDC 02024821 */  addu      $t1, $s0, $v0
/* 18A4C0 8025BBE0 11400009 */  beqz      $t2, .L8025BC08
/* 18A4C4 8025BBE4 ACA906D4 */   sw       $t1, 0x6d4($a1)
/* 18A4C8 8025BBE8 0000582D */  daddu     $t3, $zero, $zero
.L8025BBEC:
/* 18A4CC 8025BBEC 95420000 */  lhu       $v0, ($t2)
/* 18A4D0 8025BBF0 254A0002 */  addiu     $t2, $t2, 2
/* 18A4D4 8025BBF4 256B0001 */  addiu     $t3, $t3, 1
/* 18A4D8 8025BBF8 A5220000 */  sh        $v0, ($t1)
/* 18A4DC 8025BBFC 29620010 */  slti      $v0, $t3, 0x10
/* 18A4E0 8025BC00 1440FFFA */  bnez      $v0, .L8025BBEC
/* 18A4E4 8025BC04 25290002 */   addiu    $t1, $t1, 2
.L8025BC08:
/* 18A4E8 8025BC08 820206CD */  lb        $v0, 0x6cd($s0)
/* 18A4EC 8025BC0C 24840001 */  addiu     $a0, $a0, 1
/* 18A4F0 8025BC10 0082102A */  slt       $v0, $a0, $v0
/* 18A4F4 8025BC14 1440FFEC */  bnez      $v0, .L8025BBC8
/* 18A4F8 8025BC18 24A50004 */   addiu    $a1, $a1, 4
.L8025BC1C:
/* 18A4FC 8025BC1C 16600007 */  bnez      $s3, .L8025BC3C
/* 18A500 8025BC20 00000000 */   nop
/* 18A504 8025BC24 96020744 */  lhu       $v0, 0x744($s0)
/* 18A508 8025BC28 A6000744 */  sh        $zero, 0x744($s0)
/* 18A50C 8025BC2C A6020746 */  sh        $v0, 0x746($s0)
/* 18A510 8025BC30 0040182D */  daddu     $v1, $v0, $zero
/* 18A514 8025BC34 A6020748 */  sh        $v0, 0x748($s0)
/* 18A518 8025BC38 A603074A */  sh        $v1, 0x74a($s0)
.L8025BC3C:
/* 18A51C 8025BC3C 96020744 */  lhu       $v0, 0x744($s0)
/* 18A520 8025BC40 A60006CA */  sh        $zero, 0x6ca($s0)
/* 18A524 8025BC44 A20006C2 */  sb        $zero, 0x6c2($s0)
/* 18A528 8025BC48 A20006C1 */  sb        $zero, 0x6c1($s0)
/* 18A52C 8025BC4C A60206C8 */  sh        $v0, 0x6c8($s0)
.L8025BC50:
/* 18A530 8025BC50 820306C2 */  lb        $v1, 0x6c2($s0)
/* 18A534 8025BC54 10600005 */  beqz      $v1, .L8025BC6C
/* 18A538 8025BC58 24020001 */   addiu    $v0, $zero, 1
/* 18A53C 8025BC5C 1062000E */  beq       $v1, $v0, .L8025BC98
/* 18A540 8025BC60 24020002 */   addiu    $v0, $zero, 2
/* 18A544 8025BC64 08096FA3 */  j         .L8025BE8C
/* 18A548 8025BC68 00000000 */   nop
.L8025BC6C:
/* 18A54C 8025BC6C 16200085 */  bnez      $s1, .L8025BE84
/* 18A550 8025BC70 00000000 */   nop
/* 18A554 8025BC74 860206C8 */  lh        $v0, 0x6c8($s0)
/* 18A558 8025BC78 960306C8 */  lhu       $v1, 0x6c8($s0)
/* 18A55C 8025BC7C 10400003 */  beqz      $v0, .L8025BC8C
/* 18A560 8025BC80 2462FFFF */   addiu    $v0, $v1, -1
/* 18A564 8025BC84 08096FA1 */  j         .L8025BE84
/* 18A568 8025BC88 A60206C8 */   sh       $v0, 0x6c8($s0)
.L8025BC8C:
/* 18A56C 8025BC8C 24020001 */  addiu     $v0, $zero, 1
/* 18A570 8025BC90 A60006CA */  sh        $zero, 0x6ca($s0)
/* 18A574 8025BC94 A20206C2 */  sb        $v0, 0x6c2($s0)
.L8025BC98:
/* 18A578 8025BC98 16200018 */  bnez      $s1, .L8025BCFC
/* 18A57C 8025BC9C 3C0651EB */   lui      $a2, 0x51eb
/* 18A580 8025BCA0 86020746 */  lh        $v0, 0x746($s0)
/* 18A584 8025BCA4 24036400 */  addiu     $v1, $zero, 0x6400
/* 18A588 8025BCA8 14400002 */  bnez      $v0, .L8025BCB4
/* 18A58C 8025BCAC 0062001A */   div      $zero, $v1, $v0
/* 18A590 8025BCB0 0007000D */  break     7
.L8025BCB4:
/* 18A594 8025BCB4 2401FFFF */   addiu    $at, $zero, -1
/* 18A598 8025BCB8 14410004 */  bne       $v0, $at, .L8025BCCC
/* 18A59C 8025BCBC 3C018000 */   lui      $at, 0x8000
/* 18A5A0 8025BCC0 14610002 */  bne       $v1, $at, .L8025BCCC
/* 18A5A4 8025BCC4 00000000 */   nop
/* 18A5A8 8025BCC8 0006000D */  break     6
.L8025BCCC:
/* 18A5AC 8025BCCC 00001812 */   mflo     $v1
/* 18A5B0 8025BCD0 960206CA */  lhu       $v0, 0x6ca($s0)
/* 18A5B4 8025BCD4 00431021 */  addu      $v0, $v0, $v1
/* 18A5B8 8025BCD8 A60206CA */  sh        $v0, 0x6ca($s0)
/* 18A5BC 8025BCDC 00021400 */  sll       $v0, $v0, 0x10
/* 18A5C0 8025BCE0 00021403 */  sra       $v0, $v0, 0x10
/* 18A5C4 8025BCE4 2842639D */  slti      $v0, $v0, 0x639d
/* 18A5C8 8025BCE8 14400005 */  bnez      $v0, .L8025BD00
/* 18A5CC 8025BCEC 34C6851F */   ori      $a2, $a2, 0x851f
/* 18A5D0 8025BCF0 2402639C */  addiu     $v0, $zero, 0x639c
/* 18A5D4 8025BCF4 A60206CA */  sh        $v0, 0x6ca($s0)
/* 18A5D8 8025BCF8 3C0651EB */  lui       $a2, 0x51eb
.L8025BCFC:
/* 18A5DC 8025BCFC 34C6851F */  ori       $a2, $a2, 0x851f
.L8025BD00:
/* 18A5E0 8025BD00 0200682D */  daddu     $t5, $s0, $zero
/* 18A5E4 8025BD04 0000582D */  daddu     $t3, $zero, $zero
/* 18A5E8 8025BD08 3C0F8080 */  lui       $t7, 0x8080
/* 18A5EC 8025BD0C 35EF8081 */  ori       $t7, $t7, 0x8081
/* 18A5F0 8025BD10 86020740 */  lh        $v0, 0x740($s0)
/* 18A5F4 8025BD14 8E0506D0 */  lw        $a1, 0x6d0($s0)
/* 18A5F8 8025BD18 960306CA */  lhu       $v1, 0x6ca($s0)
/* 18A5FC 8025BD1C 00021080 */  sll       $v0, $v0, 2
/* 18A600 8025BD20 00451021 */  addu      $v0, $v0, $a1
/* 18A604 8025BD24 00031C00 */  sll       $v1, $v1, 0x10
/* 18A608 8025BD28 00032403 */  sra       $a0, $v1, 0x10
/* 18A60C 8025BD2C 8C4A0000 */  lw        $t2, ($v0)
/* 18A610 8025BD30 86020742 */  lh        $v0, 0x742($s0)
/* 18A614 8025BD34 00860018 */  mult      $a0, $a2
/* 18A618 8025BD38 00021080 */  sll       $v0, $v0, 2
/* 18A61C 8025BD3C 00451021 */  addu      $v0, $v0, $a1
/* 18A620 8025BD40 8C490000 */  lw        $t1, ($v0)
/* 18A624 8025BD44 00031FC3 */  sra       $v1, $v1, 0x1f
/* 18A628 8025BD48 AE1006D4 */  sw        $s0, 0x6d4($s0)
/* 18A62C 8025BD4C 0000C810 */  mfhi      $t9
/* 18A630 8025BD50 00191143 */  sra       $v0, $t9, 5
/* 18A634 8025BD54 0043C023 */  subu      $t8, $v0, $v1
/* 18A638 8025BD58 330C00FF */  andi      $t4, $t8, 0xff
/* 18A63C 8025BD5C 240200FF */  addiu     $v0, $zero, 0xff
/* 18A640 8025BD60 004C7023 */  subu      $t6, $v0, $t4
.L8025BD64:
/* 18A644 8025BD64 95430000 */  lhu       $v1, ($t2)
/* 18A648 8025BD68 000312C2 */  srl       $v0, $v1, 0xb
/* 18A64C 8025BD6C 004E0018 */  mult      $v0, $t6
/* 18A650 8025BD70 95240000 */  lhu       $a0, ($t1)
/* 18A654 8025BD74 00002812 */  mflo      $a1
/* 18A658 8025BD78 000412C2 */  srl       $v0, $a0, 0xb
/* 18A65C 8025BD7C 00000000 */  nop
/* 18A660 8025BD80 004C0018 */  mult      $v0, $t4
/* 18A664 8025BD84 00004012 */  mflo      $t0
/* 18A668 8025BD88 00A82821 */  addu      $a1, $a1, $t0
/* 18A66C 8025BD8C 00000000 */  nop
/* 18A670 8025BD90 00AF0018 */  mult      $a1, $t7
/* 18A674 8025BD94 00009810 */  mfhi      $s3
/* 18A678 8025BD98 00031182 */  srl       $v0, $v1, 6
/* 18A67C 8025BD9C 3042001F */  andi      $v0, $v0, 0x1f
/* 18A680 8025BDA0 004E0018 */  mult      $v0, $t6
/* 18A684 8025BDA4 00004012 */  mflo      $t0
/* 18A688 8025BDA8 00041182 */  srl       $v0, $a0, 6
/* 18A68C 8025BDAC 3042001F */  andi      $v0, $v0, 0x1f
/* 18A690 8025BDB0 004C0018 */  mult      $v0, $t4
/* 18A694 8025BDB4 00003812 */  mflo      $a3
/* 18A698 8025BDB8 00031842 */  srl       $v1, $v1, 1
/* 18A69C 8025BDBC 3063001F */  andi      $v1, $v1, 0x1f
/* 18A6A0 8025BDC0 006E0018 */  mult      $v1, $t6
/* 18A6A4 8025BDC4 00001812 */  mflo      $v1
/* 18A6A8 8025BDC8 00042042 */  srl       $a0, $a0, 1
/* 18A6AC 8025BDCC 3084001F */  andi      $a0, $a0, 0x1f
/* 18A6B0 8025BDD0 008C0018 */  mult      $a0, $t4
/* 18A6B4 8025BDD4 254A0002 */  addiu     $t2, $t2, 2
/* 18A6B8 8025BDD8 91260001 */  lbu       $a2, 1($t1)
/* 18A6BC 8025BDDC 25290002 */  addiu     $t1, $t1, 2
/* 18A6C0 8025BDE0 0000B812 */  mflo      $s7
/* 18A6C4 8025BDE4 256B0001 */  addiu     $t3, $t3, 1
/* 18A6C8 8025BDE8 01072021 */  addu      $a0, $t0, $a3
/* 18A6CC 8025BDEC 008F0018 */  mult      $a0, $t7
/* 18A6D0 8025BDF0 30C60001 */  andi      $a2, $a2, 1
/* 18A6D4 8025BDF4 02651021 */  addu      $v0, $s3, $a1
/* 18A6D8 8025BDF8 000211C3 */  sra       $v0, $v0, 7
/* 18A6DC 8025BDFC 00052FC3 */  sra       $a1, $a1, 0x1f
/* 18A6E0 8025BE00 00004010 */  mfhi      $t0
/* 18A6E4 8025BE04 00453823 */  subu      $a3, $v0, $a1
/* 18A6E8 8025BE08 00771821 */  addu      $v1, $v1, $s7
/* 18A6EC 8025BE0C 006F0018 */  mult      $v1, $t7
/* 18A6F0 8025BE10 01041021 */  addu      $v0, $t0, $a0
/* 18A6F4 8025BE14 000211C3 */  sra       $v0, $v0, 7
/* 18A6F8 8025BE18 000427C3 */  sra       $a0, $a0, 0x1f
/* 18A6FC 8025BE1C 00442823 */  subu      $a1, $v0, $a0
/* 18A700 8025BE20 00009810 */  mfhi      $s3
/* 18A704 8025BE24 02631021 */  addu      $v0, $s3, $v1
/* 18A708 8025BE28 000211C3 */  sra       $v0, $v0, 7
/* 18A70C 8025BE2C 00031FC3 */  sra       $v1, $v1, 0x1f
/* 18A710 8025BE30 00432023 */  subu      $a0, $v0, $v1
/* 18A714 8025BE34 30E300FF */  andi      $v1, $a3, 0xff
/* 18A718 8025BE38 00031AC0 */  sll       $v1, $v1, 0xb
/* 18A71C 8025BE3C 30A200FF */  andi      $v0, $a1, 0xff
/* 18A720 8025BE40 00021180 */  sll       $v0, $v0, 6
/* 18A724 8025BE44 00621825 */  or        $v1, $v1, $v0
/* 18A728 8025BE48 308200FF */  andi      $v0, $a0, 0xff
/* 18A72C 8025BE4C 00021040 */  sll       $v0, $v0, 1
/* 18A730 8025BE50 00621825 */  or        $v1, $v1, $v0
/* 18A734 8025BE54 00C33025 */  or        $a2, $a2, $v1
/* 18A738 8025BE58 A5A60000 */  sh        $a2, ($t5)
/* 18A73C 8025BE5C 29620010 */  slti      $v0, $t3, 0x10
/* 18A740 8025BE60 1440FFC0 */  bnez      $v0, .L8025BD64
/* 18A744 8025BE64 25AD0002 */   addiu    $t5, $t5, 2
/* 18A748 8025BE68 330300FF */  andi      $v1, $t8, 0xff
/* 18A74C 8025BE6C 240200FF */  addiu     $v0, $zero, 0xff
/* 18A750 8025BE70 14620004 */  bne       $v1, $v0, .L8025BE84
/* 18A754 8025BE74 24020002 */   addiu    $v0, $zero, 2
/* 18A758 8025BE78 96030748 */  lhu       $v1, 0x748($s0)
/* 18A75C 8025BE7C A20206C2 */  sb        $v0, 0x6c2($s0)
/* 18A760 8025BE80 A60306C8 */  sh        $v1, 0x6c8($s0)
.L8025BE84:
/* 18A764 8025BE84 820306C2 */  lb        $v1, 0x6c2($s0)
/* 18A768 8025BE88 24020002 */  addiu     $v0, $zero, 2
.L8025BE8C:
/* 18A76C 8025BE8C 10620005 */  beq       $v1, $v0, .L8025BEA4
/* 18A770 8025BE90 24020003 */   addiu    $v0, $zero, 3
/* 18A774 8025BE94 1062000C */  beq       $v1, $v0, .L8025BEC8
/* 18A778 8025BE98 00000000 */   nop
/* 18A77C 8025BE9C 0809702D */  j         .L8025C0B4
/* 18A780 8025BEA0 00000000 */   nop
.L8025BEA4:
/* 18A784 8025BEA4 16200083 */  bnez      $s1, .L8025C0B4
/* 18A788 8025BEA8 00000000 */   nop
/* 18A78C 8025BEAC 860206C8 */  lh        $v0, 0x6c8($s0)
/* 18A790 8025BEB0 960306C8 */  lhu       $v1, 0x6c8($s0)
/* 18A794 8025BEB4 1440007E */  bnez      $v0, .L8025C0B0
/* 18A798 8025BEB8 2462FFFF */   addiu    $v0, $v1, -1
/* 18A79C 8025BEBC 24020003 */  addiu     $v0, $zero, 3
/* 18A7A0 8025BEC0 A60006CA */  sh        $zero, 0x6ca($s0)
/* 18A7A4 8025BEC4 A20206C2 */  sb        $v0, 0x6c2($s0)
.L8025BEC8:
/* 18A7A8 8025BEC8 16200018 */  bnez      $s1, .L8025BF2C
/* 18A7AC 8025BECC 3C0651EB */   lui      $a2, 0x51eb
/* 18A7B0 8025BED0 8602074A */  lh        $v0, 0x74a($s0)
/* 18A7B4 8025BED4 24036400 */  addiu     $v1, $zero, 0x6400
/* 18A7B8 8025BED8 14400002 */  bnez      $v0, .L8025BEE4
/* 18A7BC 8025BEDC 0062001A */   div      $zero, $v1, $v0
/* 18A7C0 8025BEE0 0007000D */  break     7
.L8025BEE4:
/* 18A7C4 8025BEE4 2401FFFF */   addiu    $at, $zero, -1
/* 18A7C8 8025BEE8 14410004 */  bne       $v0, $at, .L8025BEFC
/* 18A7CC 8025BEEC 3C018000 */   lui      $at, 0x8000
/* 18A7D0 8025BEF0 14610002 */  bne       $v1, $at, .L8025BEFC
/* 18A7D4 8025BEF4 00000000 */   nop
/* 18A7D8 8025BEF8 0006000D */  break     6
.L8025BEFC:
/* 18A7DC 8025BEFC 00001812 */   mflo     $v1
/* 18A7E0 8025BF00 960206CA */  lhu       $v0, 0x6ca($s0)
/* 18A7E4 8025BF04 00431021 */  addu      $v0, $v0, $v1
/* 18A7E8 8025BF08 A60206CA */  sh        $v0, 0x6ca($s0)
/* 18A7EC 8025BF0C 00021400 */  sll       $v0, $v0, 0x10
/* 18A7F0 8025BF10 00021403 */  sra       $v0, $v0, 0x10
/* 18A7F4 8025BF14 2842639D */  slti      $v0, $v0, 0x639d
/* 18A7F8 8025BF18 14400005 */  bnez      $v0, .L8025BF30
/* 18A7FC 8025BF1C 34C6851F */   ori      $a2, $a2, 0x851f
/* 18A800 8025BF20 2402639C */  addiu     $v0, $zero, 0x639c
/* 18A804 8025BF24 A60206CA */  sh        $v0, 0x6ca($s0)
/* 18A808 8025BF28 3C0651EB */  lui       $a2, 0x51eb
.L8025BF2C:
/* 18A80C 8025BF2C 34C6851F */  ori       $a2, $a2, 0x851f
.L8025BF30:
/* 18A810 8025BF30 0200682D */  daddu     $t5, $s0, $zero
/* 18A814 8025BF34 0000582D */  daddu     $t3, $zero, $zero
/* 18A818 8025BF38 3C0F8080 */  lui       $t7, 0x8080
/* 18A81C 8025BF3C 35EF8081 */  ori       $t7, $t7, 0x8081
/* 18A820 8025BF40 86020742 */  lh        $v0, 0x742($s0)
/* 18A824 8025BF44 8E0506D0 */  lw        $a1, 0x6d0($s0)
/* 18A828 8025BF48 960306CA */  lhu       $v1, 0x6ca($s0)
/* 18A82C 8025BF4C 00021080 */  sll       $v0, $v0, 2
/* 18A830 8025BF50 00451021 */  addu      $v0, $v0, $a1
/* 18A834 8025BF54 00031C00 */  sll       $v1, $v1, 0x10
/* 18A838 8025BF58 00032403 */  sra       $a0, $v1, 0x10
/* 18A83C 8025BF5C 8C4A0000 */  lw        $t2, ($v0)
/* 18A840 8025BF60 86020740 */  lh        $v0, 0x740($s0)
/* 18A844 8025BF64 00860018 */  mult      $a0, $a2
/* 18A848 8025BF68 00021080 */  sll       $v0, $v0, 2
/* 18A84C 8025BF6C 00451021 */  addu      $v0, $v0, $a1
/* 18A850 8025BF70 8C490000 */  lw        $t1, ($v0)
/* 18A854 8025BF74 00031FC3 */  sra       $v1, $v1, 0x1f
/* 18A858 8025BF78 AE1006D4 */  sw        $s0, 0x6d4($s0)
/* 18A85C 8025BF7C 0000C810 */  mfhi      $t9
/* 18A860 8025BF80 00191143 */  sra       $v0, $t9, 5
/* 18A864 8025BF84 0043C023 */  subu      $t8, $v0, $v1
/* 18A868 8025BF88 330C00FF */  andi      $t4, $t8, 0xff
/* 18A86C 8025BF8C 240200FF */  addiu     $v0, $zero, 0xff
/* 18A870 8025BF90 004C7023 */  subu      $t6, $v0, $t4
.L8025BF94:
/* 18A874 8025BF94 95430000 */  lhu       $v1, ($t2)
/* 18A878 8025BF98 000312C2 */  srl       $v0, $v1, 0xb
/* 18A87C 8025BF9C 004E0018 */  mult      $v0, $t6
/* 18A880 8025BFA0 95240000 */  lhu       $a0, ($t1)
/* 18A884 8025BFA4 00002812 */  mflo      $a1
/* 18A888 8025BFA8 000412C2 */  srl       $v0, $a0, 0xb
/* 18A88C 8025BFAC 00000000 */  nop
/* 18A890 8025BFB0 004C0018 */  mult      $v0, $t4
/* 18A894 8025BFB4 00004012 */  mflo      $t0
/* 18A898 8025BFB8 00A82821 */  addu      $a1, $a1, $t0
/* 18A89C 8025BFBC 00000000 */  nop
/* 18A8A0 8025BFC0 00AF0018 */  mult      $a1, $t7
/* 18A8A4 8025BFC4 00008810 */  mfhi      $s1
/* 18A8A8 8025BFC8 00031182 */  srl       $v0, $v1, 6
/* 18A8AC 8025BFCC 3042001F */  andi      $v0, $v0, 0x1f
/* 18A8B0 8025BFD0 004E0018 */  mult      $v0, $t6
/* 18A8B4 8025BFD4 00004012 */  mflo      $t0
/* 18A8B8 8025BFD8 00041182 */  srl       $v0, $a0, 6
/* 18A8BC 8025BFDC 3042001F */  andi      $v0, $v0, 0x1f
/* 18A8C0 8025BFE0 004C0018 */  mult      $v0, $t4
/* 18A8C4 8025BFE4 00003812 */  mflo      $a3
/* 18A8C8 8025BFE8 00031842 */  srl       $v1, $v1, 1
/* 18A8CC 8025BFEC 3063001F */  andi      $v1, $v1, 0x1f
/* 18A8D0 8025BFF0 006E0018 */  mult      $v1, $t6
/* 18A8D4 8025BFF4 00001812 */  mflo      $v1
/* 18A8D8 8025BFF8 00042042 */  srl       $a0, $a0, 1
/* 18A8DC 8025BFFC 3084001F */  andi      $a0, $a0, 0x1f
/* 18A8E0 8025C000 008C0018 */  mult      $a0, $t4
/* 18A8E4 8025C004 254A0002 */  addiu     $t2, $t2, 2
/* 18A8E8 8025C008 91260001 */  lbu       $a2, 1($t1)
/* 18A8EC 8025C00C 25290002 */  addiu     $t1, $t1, 2
/* 18A8F0 8025C010 00009812 */  mflo      $s3
/* 18A8F4 8025C014 256B0001 */  addiu     $t3, $t3, 1
/* 18A8F8 8025C018 01072021 */  addu      $a0, $t0, $a3
/* 18A8FC 8025C01C 008F0018 */  mult      $a0, $t7
/* 18A900 8025C020 30C60001 */  andi      $a2, $a2, 1
/* 18A904 8025C024 02251021 */  addu      $v0, $s1, $a1
/* 18A908 8025C028 000211C3 */  sra       $v0, $v0, 7
/* 18A90C 8025C02C 00052FC3 */  sra       $a1, $a1, 0x1f
/* 18A910 8025C030 00004010 */  mfhi      $t0
/* 18A914 8025C034 00453823 */  subu      $a3, $v0, $a1
/* 18A918 8025C038 00731821 */  addu      $v1, $v1, $s3
/* 18A91C 8025C03C 006F0018 */  mult      $v1, $t7
/* 18A920 8025C040 01041021 */  addu      $v0, $t0, $a0
/* 18A924 8025C044 000211C3 */  sra       $v0, $v0, 7
/* 18A928 8025C048 000427C3 */  sra       $a0, $a0, 0x1f
/* 18A92C 8025C04C 00442823 */  subu      $a1, $v0, $a0
/* 18A930 8025C050 00008810 */  mfhi      $s1
/* 18A934 8025C054 02231021 */  addu      $v0, $s1, $v1
/* 18A938 8025C058 000211C3 */  sra       $v0, $v0, 7
/* 18A93C 8025C05C 00031FC3 */  sra       $v1, $v1, 0x1f
/* 18A940 8025C060 00432023 */  subu      $a0, $v0, $v1
/* 18A944 8025C064 30E300FF */  andi      $v1, $a3, 0xff
/* 18A948 8025C068 00031AC0 */  sll       $v1, $v1, 0xb
/* 18A94C 8025C06C 30A200FF */  andi      $v0, $a1, 0xff
/* 18A950 8025C070 00021180 */  sll       $v0, $v0, 6
/* 18A954 8025C074 00621825 */  or        $v1, $v1, $v0
/* 18A958 8025C078 308200FF */  andi      $v0, $a0, 0xff
/* 18A95C 8025C07C 00021040 */  sll       $v0, $v0, 1
/* 18A960 8025C080 00621825 */  or        $v1, $v1, $v0
/* 18A964 8025C084 00C33025 */  or        $a2, $a2, $v1
/* 18A968 8025C088 A5A60000 */  sh        $a2, ($t5)
/* 18A96C 8025C08C 29620010 */  slti      $v0, $t3, 0x10
/* 18A970 8025C090 1440FFC0 */  bnez      $v0, .L8025BF94
/* 18A974 8025C094 25AD0002 */   addiu    $t5, $t5, 2
/* 18A978 8025C098 330300FF */  andi      $v1, $t8, 0xff
/* 18A97C 8025C09C 240200FF */  addiu     $v0, $zero, 0xff
/* 18A980 8025C0A0 14620004 */  bne       $v1, $v0, .L8025C0B4
/* 18A984 8025C0A4 00000000 */   nop
/* 18A988 8025C0A8 96020744 */  lhu       $v0, 0x744($s0)
/* 18A98C 8025C0AC A20006C2 */  sb        $zero, 0x6c2($s0)
.L8025C0B0:
/* 18A990 8025C0B0 A60206C8 */  sh        $v0, 0x6c8($s0)
.L8025C0B4:
/* 18A994 8025C0B4 820306C2 */  lb        $v1, 0x6c2($s0)
/* 18A998 8025C0B8 28620004 */  slti      $v0, $v1, 4
/* 18A99C 8025C0BC 1040000D */  beqz      $v0, .L8025C0F4
/* 18A9A0 8025C0C0 00000000 */   nop
/* 18A9A4 8025C0C4 0460000B */  bltz      $v1, .L8025C0F4
/* 18A9A8 8025C0C8 00000000 */   nop
/* 18A9AC 8025C0CC 16800006 */  bnez      $s4, .L8025C0E8
/* 18A9B0 8025C0D0 0240202D */   daddu    $a0, $s2, $zero
/* 18A9B4 8025C0D4 02A0282D */  daddu     $a1, $s5, $zero
/* 18A9B8 8025C0D8 0C096657 */  jal       func_8025995C
/* 18A9BC 8025C0DC 02C0302D */   daddu    $a2, $s6, $zero
/* 18A9C0 8025C0E0 0809703D */  j         .L8025C0F4
/* 18A9C4 8025C0E4 00000000 */   nop
.L8025C0E8:
/* 18A9C8 8025C0E8 02A0282D */  daddu     $a1, $s5, $zero
/* 18A9CC 8025C0EC 0C0965B0 */  jal       func_802596C0
/* 18A9D0 8025C0F0 02C0302D */   daddu    $a2, $s6, $zero
.L8025C0F4:
/* 18A9D4 8025C0F4 8FBF0030 */  lw        $ra, 0x30($sp)
/* 18A9D8 8025C0F8 8FB7002C */  lw        $s7, 0x2c($sp)
/* 18A9DC 8025C0FC 8FB60028 */  lw        $s6, 0x28($sp)
/* 18A9E0 8025C100 8FB50024 */  lw        $s5, 0x24($sp)
/* 18A9E4 8025C104 8FB40020 */  lw        $s4, 0x20($sp)
/* 18A9E8 8025C108 8FB3001C */  lw        $s3, 0x1c($sp)
/* 18A9EC 8025C10C 8FB20018 */  lw        $s2, 0x18($sp)
/* 18A9F0 8025C110 8FB10014 */  lw        $s1, 0x14($sp)
/* 18A9F4 8025C114 8FB00010 */  lw        $s0, 0x10($sp)
/* 18A9F8 8025C118 03E00008 */  jr        $ra
/* 18A9FC 8025C11C 27BD0038 */   addiu    $sp, $sp, 0x38
