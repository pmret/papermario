.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel draw_box
/* 8E790 800F52E0 27BDFE10 */  addiu     $sp, $sp, -0x1f0
/* 8E794 800F52E4 0000482D */  daddu     $t1, $zero, $zero
/* 8E798 800F52E8 93AE020F */  lbu       $t6, 0x20f($sp)
/* 8E79C 800F52EC 0120502D */  daddu     $t2, $t1, $zero
/* 8E7A0 800F52F0 AFA701FC */  sw        $a3, 0x1fc($sp)
/* 8E7A4 800F52F4 3C078080 */  lui       $a3, 0x8080
/* 8E7A8 800F52F8 F7B601E0 */  sdc1      $f22, 0x1e0($sp)
/* 8E7AC 800F52FC C7B60214 */  lwc1      $f22, 0x214($sp)
/* 8E7B0 800F5300 34E78081 */  ori       $a3, $a3, 0x8081
/* 8E7B4 800F5304 F7B801E8 */  sdc1      $f24, 0x1e8($sp)
/* 8E7B8 800F5308 C7B80218 */  lwc1      $f24, 0x218($sp)
/* 8E7BC 800F530C 93AF0213 */  lbu       $t7, 0x213($sp)
/* 8E7C0 800F5310 2CA20017 */  sltiu     $v0, $a1, 0x17
/* 8E7C4 800F5314 AFBF01D4 */  sw        $ra, 0x1d4($sp)
/* 8E7C8 800F5318 AFBE01D0 */  sw        $fp, 0x1d0($sp)
/* 8E7CC 800F531C AFB701CC */  sw        $s7, 0x1cc($sp)
/* 8E7D0 800F5320 AFB601C8 */  sw        $s6, 0x1c8($sp)
/* 8E7D4 800F5324 AFB501C4 */  sw        $s5, 0x1c4($sp)
/* 8E7D8 800F5328 AFB401C0 */  sw        $s4, 0x1c0($sp)
/* 8E7DC 800F532C AFB301BC */  sw        $s3, 0x1bc($sp)
/* 8E7E0 800F5330 AFB201B8 */  sw        $s2, 0x1b8($sp)
/* 8E7E4 800F5334 AFB101B4 */  sw        $s1, 0x1b4($sp)
/* 8E7E8 800F5338 AFB001B0 */  sw        $s0, 0x1b0($sp)
/* 8E7EC 800F533C F7B401D8 */  sdc1      $f20, 0x1d8($sp)
/* 8E7F0 800F5340 AFA401F0 */  sw        $a0, 0x1f0($sp)
/* 8E7F4 800F5344 AFA601F8 */  sw        $a2, 0x1f8($sp)
/* 8E7F8 800F5348 31C600FF */  andi      $a2, $t6, 0xff
/* 8E7FC 800F534C A3AE00E7 */  sb        $t6, 0xe7($sp)
/* 8E800 800F5350 1040002B */  beqz      $v0, .L800F5400
/* 8E804 800F5354 A3AF00E8 */   sb       $t7, 0xe8($sp)
/* 8E808 800F5358 3C038011 */  lui       $v1, %hi(D_801098E0)
/* 8E80C 800F535C 246398E0 */  addiu     $v1, $v1, %lo(D_801098E0)
/* 8E810 800F5360 00051040 */  sll       $v0, $a1, 1
/* 8E814 800F5364 00451021 */  addu      $v0, $v0, $a1
/* 8E818 800F5368 00021080 */  sll       $v0, $v0, 2
/* 8E81C 800F536C 00451023 */  subu      $v0, $v0, $a1
/* 8E820 800F5370 00434821 */  addu      $t1, $v0, $v1
/* 8E824 800F5374 91320003 */  lbu       $s2, 3($t1)
/* 8E828 800F5378 A3B200F7 */  sb        $s2, 0xf7($sp)
/* 8E82C 800F537C 91390004 */  lbu       $t9, 4($t1)
/* 8E830 800F5380 A3B900FF */  sb        $t9, 0xff($sp)
/* 8E834 800F5384 912E0005 */  lbu       $t6, 5($t1)
/* 8E838 800F5388 A3AE0107 */  sb        $t6, 0x107($sp)
/* 8E83C 800F538C 912F0007 */  lbu       $t7, 7($t1)
/* 8E840 800F5390 A3AF0117 */  sb        $t7, 0x117($sp)
/* 8E844 800F5394 91320008 */  lbu       $s2, 8($t1)
/* 8E848 800F5398 A3B2011F */  sb        $s2, 0x11f($sp)
/* 8E84C 800F539C 91390009 */  lbu       $t9, 9($t1)
/* 8E850 800F53A0 A3B90127 */  sb        $t9, 0x127($sp)
/* 8E854 800F53A4 912E000A */  lbu       $t6, 0xa($t1)
/* 8E858 800F53A8 A3AE012F */  sb        $t6, 0x12f($sp)
/* 8E85C 800F53AC 91230006 */  lbu       $v1, 6($t1)
/* 8E860 800F53B0 00660018 */  mult      $v1, $a2
/* 8E864 800F53B4 91240000 */  lbu       $a0, ($t1)
/* 8E868 800F53B8 3C058011 */  lui       $a1, %hi(D_8010BAE8)
/* 8E86C 800F53BC 24A5BAE8 */  addiu     $a1, $a1, %lo(D_8010BAE8)
/* 8E870 800F53C0 00041040 */  sll       $v0, $a0, 1
/* 8E874 800F53C4 00441021 */  addu      $v0, $v0, $a0
/* 8E878 800F53C8 00001812 */  mflo      $v1
/* 8E87C 800F53CC 00021080 */  sll       $v0, $v0, 2
/* 8E880 800F53D0 0045A021 */  addu      $s4, $v0, $a1
/* 8E884 800F53D4 00670018 */  mult      $v1, $a3
/* 8E888 800F53D8 91220001 */  lbu       $v0, 1($t1)
/* 8E88C 800F53DC 3C048011 */  lui       $a0, %hi(D_8010BB00)
/* 8E890 800F53E0 2484BB00 */  addiu     $a0, $a0, %lo(D_8010BB00)
/* 8E894 800F53E4 00021100 */  sll       $v0, $v0, 4
/* 8E898 800F53E8 00442021 */  addu      $a0, $v0, $a0
/* 8E89C 800F53EC 00004010 */  mfhi      $t0
/* 8E8A0 800F53F0 01031821 */  addu      $v1, $t0, $v1
/* 8E8A4 800F53F4 000319C2 */  srl       $v1, $v1, 7
/* 8E8A8 800F53F8 0803D519 */  j         .L800F5464
/* 8E8AC 800F53FC A3A3010F */   sb       $v1, 0x10f($sp)
.L800F5400:
/* 8E8B0 800F5400 00A0A02D */  daddu     $s4, $a1, $zero
/* 8E8B4 800F5404 928E0030 */  lbu       $t6, 0x30($s4)
/* 8E8B8 800F5408 92820033 */  lbu       $v0, 0x33($s4)
/* 8E8BC 800F540C A3AE00F7 */  sb        $t6, 0xf7($sp)
/* 8E8C0 800F5410 928F0031 */  lbu       $t7, 0x31($s4)
/* 8E8C4 800F5414 A3AF00FF */  sb        $t7, 0xff($sp)
/* 8E8C8 800F5418 92920032 */  lbu       $s2, 0x32($s4)
/* 8E8CC 800F541C 00460018 */  mult      $v0, $a2
/* 8E8D0 800F5420 A3B20107 */  sb        $s2, 0x107($sp)
/* 8E8D4 800F5424 928E0034 */  lbu       $t6, 0x34($s4)
/* 8E8D8 800F5428 0280502D */  daddu     $t2, $s4, $zero
/* 8E8DC 800F542C A3AE0117 */  sb        $t6, 0x117($sp)
/* 8E8E0 800F5430 928F0035 */  lbu       $t7, 0x35($s4)
/* 8E8E4 800F5434 00001012 */  mflo      $v0
/* 8E8E8 800F5438 A3AF011F */  sb        $t7, 0x11f($sp)
/* 8E8EC 800F543C 92920036 */  lbu       $s2, 0x36($s4)
/* 8E8F0 800F5440 00470018 */  mult      $v0, $a3
/* 8E8F4 800F5444 A3B20127 */  sb        $s2, 0x127($sp)
/* 8E8F8 800F5448 92990037 */  lbu       $t9, 0x37($s4)
/* 8E8FC 800F544C 2684000C */  addiu     $a0, $s4, 0xc
/* 8E900 800F5450 A3B9012F */  sb        $t9, 0x12f($sp)
/* 8E904 800F5454 00001810 */  mfhi      $v1
/* 8E908 800F5458 00621021 */  addu      $v0, $v1, $v0
/* 8E90C 800F545C 000211C2 */  srl       $v0, $v0, 7
/* 8E910 800F5460 A3A2010F */  sb        $v0, 0x10f($sp)
.L800F5464:
/* 8E914 800F5464 8E820004 */  lw        $v0, 4($s4)
/* 8E918 800F5468 8C8E0000 */  lw        $t6, ($a0)
/* 8E91C 800F546C 00021702 */  srl       $v0, $v0, 0x1c
/* 8E920 800F5470 AFAE013C */  sw        $t6, 0x13c($sp)
/* 8E924 800F5474 AFA20140 */  sw        $v0, 0x140($sp)
/* 8E928 800F5478 92950005 */  lbu       $s5, 5($s4)
/* 8E92C 800F547C 8E8F0000 */  lw        $t7, ($s4)
/* 8E930 800F5480 2EA20002 */  sltiu     $v0, $s5, 2
/* 8E934 800F5484 AFAF0138 */  sw        $t7, 0x138($sp)
/* 8E938 800F5488 92970006 */  lbu       $s7, 6($s4)
/* 8E93C 800F548C 5440002F */  bnel      $v0, $zero, .L800F554C
/* 8E940 800F5490 AFA00144 */   sw       $zero, 0x144($sp)
/* 8E944 800F5494 2EA20003 */  sltiu     $v0, $s5, 3
/* 8E948 800F5498 5440002B */  bnel      $v0, $zero, .L800F5548
/* 8E94C 800F549C 24190001 */   addiu    $t9, $zero, 1
/* 8E950 800F54A0 2EA20005 */  sltiu     $v0, $s5, 5
/* 8E954 800F54A4 54400026 */  bnel      $v0, $zero, .L800F5540
/* 8E958 800F54A8 24120002 */   addiu    $s2, $zero, 2
/* 8E95C 800F54AC 2EA20009 */  sltiu     $v0, $s5, 9
/* 8E960 800F54B0 54400021 */  bnel      $v0, $zero, .L800F5538
/* 8E964 800F54B4 240F0003 */   addiu    $t7, $zero, 3
/* 8E968 800F54B8 2EA20011 */  sltiu     $v0, $s5, 0x11
/* 8E96C 800F54BC 5440001C */  bnel      $v0, $zero, .L800F5530
/* 8E970 800F54C0 240E0004 */   addiu    $t6, $zero, 4
/* 8E974 800F54C4 2EA20021 */  sltiu     $v0, $s5, 0x21
/* 8E978 800F54C8 54400017 */  bnel      $v0, $zero, .L800F5528
/* 8E97C 800F54CC 24190005 */   addiu    $t9, $zero, 5
/* 8E980 800F54D0 2EA20041 */  sltiu     $v0, $s5, 0x41
/* 8E984 800F54D4 54400012 */  bnel      $v0, $zero, .L800F5520
/* 8E988 800F54D8 24120006 */   addiu    $s2, $zero, 6
/* 8E98C 800F54DC 2EA20081 */  sltiu     $v0, $s5, 0x81
/* 8E990 800F54E0 5440000D */  bnel      $v0, $zero, .L800F5518
/* 8E994 800F54E4 240F0007 */   addiu    $t7, $zero, 7
/* 8E998 800F54E8 2EA20101 */  sltiu     $v0, $s5, 0x101
/* 8E99C 800F54EC 14400008 */  bnez      $v0, .L800F5510
/* 8E9A0 800F54F0 240E0008 */   addiu    $t6, $zero, 8
/* 8E9A4 800F54F4 2412000A */  addiu     $s2, $zero, 0xa
/* 8E9A8 800F54F8 2EA20201 */  sltiu     $v0, $s5, 0x201
/* 8E9AC 800F54FC 10400013 */  beqz      $v0, .L800F554C
/* 8E9B0 800F5500 AFB20144 */   sw       $s2, 0x144($sp)
/* 8E9B4 800F5504 24190009 */  addiu     $t9, $zero, 9
/* 8E9B8 800F5508 0803D553 */  j         .L800F554C
/* 8E9BC 800F550C AFB90144 */   sw       $t9, 0x144($sp)
.L800F5510:
/* 8E9C0 800F5510 0803D553 */  j         .L800F554C
/* 8E9C4 800F5514 AFAE0144 */   sw       $t6, 0x144($sp)
.L800F5518:
/* 8E9C8 800F5518 0803D553 */  j         .L800F554C
/* 8E9CC 800F551C AFAF0144 */   sw       $t7, 0x144($sp)
.L800F5520:
/* 8E9D0 800F5520 0803D553 */  j         .L800F554C
/* 8E9D4 800F5524 AFB20144 */   sw       $s2, 0x144($sp)
.L800F5528:
/* 8E9D8 800F5528 0803D553 */  j         .L800F554C
/* 8E9DC 800F552C AFB90144 */   sw       $t9, 0x144($sp)
.L800F5530:
/* 8E9E0 800F5530 0803D553 */  j         .L800F554C
/* 8E9E4 800F5534 AFAE0144 */   sw       $t6, 0x144($sp)
.L800F5538:
/* 8E9E8 800F5538 0803D553 */  j         .L800F554C
/* 8E9EC 800F553C AFAF0144 */   sw       $t7, 0x144($sp)
.L800F5540:
/* 8E9F0 800F5540 0803D553 */  j         .L800F554C
/* 8E9F4 800F5544 AFB20144 */   sw       $s2, 0x144($sp)
.L800F5548:
/* 8E9F8 800F5548 AFB90144 */  sw        $t9, 0x144($sp)
.L800F554C:
/* 8E9FC 800F554C 2EE20002 */  sltiu     $v0, $s7, 2
/* 8EA00 800F5550 1440001D */  bnez      $v0, .L800F55C8
/* 8EA04 800F5554 0000B02D */   daddu    $s6, $zero, $zero
/* 8EA08 800F5558 2EE20003 */  sltiu     $v0, $s7, 3
/* 8EA0C 800F555C 1440001A */  bnez      $v0, .L800F55C8
/* 8EA10 800F5560 24160001 */   addiu    $s6, $zero, 1
/* 8EA14 800F5564 2EE20005 */  sltiu     $v0, $s7, 5
/* 8EA18 800F5568 14400017 */  bnez      $v0, .L800F55C8
/* 8EA1C 800F556C 24160002 */   addiu    $s6, $zero, 2
/* 8EA20 800F5570 2EE20009 */  sltiu     $v0, $s7, 9
/* 8EA24 800F5574 14400014 */  bnez      $v0, .L800F55C8
/* 8EA28 800F5578 24160003 */   addiu    $s6, $zero, 3
/* 8EA2C 800F557C 2EE20011 */  sltiu     $v0, $s7, 0x11
/* 8EA30 800F5580 14400011 */  bnez      $v0, .L800F55C8
/* 8EA34 800F5584 24160004 */   addiu    $s6, $zero, 4
/* 8EA38 800F5588 2EE20021 */  sltiu     $v0, $s7, 0x21
/* 8EA3C 800F558C 1440000E */  bnez      $v0, .L800F55C8
/* 8EA40 800F5590 24160005 */   addiu    $s6, $zero, 5
/* 8EA44 800F5594 2EE20041 */  sltiu     $v0, $s7, 0x41
/* 8EA48 800F5598 1440000B */  bnez      $v0, .L800F55C8
/* 8EA4C 800F559C 24160006 */   addiu    $s6, $zero, 6
/* 8EA50 800F55A0 2EE20081 */  sltiu     $v0, $s7, 0x81
/* 8EA54 800F55A4 14400008 */  bnez      $v0, .L800F55C8
/* 8EA58 800F55A8 24160007 */   addiu    $s6, $zero, 7
/* 8EA5C 800F55AC 2EE20101 */  sltiu     $v0, $s7, 0x101
/* 8EA60 800F55B0 14400005 */  bnez      $v0, .L800F55C8
/* 8EA64 800F55B4 24160008 */   addiu    $s6, $zero, 8
/* 8EA68 800F55B8 2EE20201 */  sltiu     $v0, $s7, 0x201
/* 8EA6C 800F55BC 10400002 */  beqz      $v0, .L800F55C8
/* 8EA70 800F55C0 2416000A */   addiu    $s6, $zero, 0xa
/* 8EA74 800F55C4 24160009 */  addiu     $s6, $zero, 9
.L800F55C8:
/* 8EA78 800F55C8 0000F02D */  daddu     $fp, $zero, $zero
/* 8EA7C 800F55CC AFA00154 */  sw        $zero, 0x154($sp)
/* 8EA80 800F55D0 8C820004 */  lw        $v0, 4($a0)
/* 8EA84 800F55D4 8FAF0204 */  lw        $t7, 0x204($sp)
/* 8EA88 800F55D8 24840005 */  addiu     $a0, $a0, 5
/* 8EA8C 800F55DC AFA40148 */  sw        $a0, 0x148($sp)
/* 8EA90 800F55E0 00027702 */  srl       $t6, $v0, 0x1c
/* 8EA94 800F55E4 00021602 */  srl       $v0, $v0, 0x18
/* 8EA98 800F55E8 3042000F */  andi      $v0, $v0, 0xf
/* 8EA9C 800F55EC AFAE014C */  sw        $t6, 0x14c($sp)
/* 8EAA0 800F55F0 19E00026 */  blez      $t7, .L800F568C
/* 8EAA4 800F55F4 AFA20150 */   sw       $v0, 0x150($sp)
/* 8EAA8 800F55F8 8FB20208 */  lw        $s2, 0x208($sp)
/* 8EAAC 800F55FC 1A40093B */  blez      $s2, .L800F7AEC
/* 8EAB0 800F5600 24020001 */   addiu    $v0, $zero, 1
/* 8EAB4 800F5604 93B900E7 */  lbu       $t9, 0xe7($sp)
/* 8EAB8 800F5608 13200938 */  beqz      $t9, .L800F7AEC
/* 8EABC 800F560C 00000000 */   nop      
/* 8EAC0 800F5610 8FAE01F8 */  lw        $t6, 0x1f8($sp)
/* 8EAC4 800F5614 29C2FD01 */  slti      $v0, $t6, -0x2ff
/* 8EAC8 800F5618 14400934 */  bnez      $v0, .L800F7AEC
/* 8EACC 800F561C 24020001 */   addiu    $v0, $zero, 1
/* 8EAD0 800F5620 8FAF01FC */  lw        $t7, 0x1fc($sp)
/* 8EAD4 800F5624 29E2FD01 */  slti      $v0, $t7, -0x2ff
/* 8EAD8 800F5628 14400930 */  bnez      $v0, .L800F7AEC
/* 8EADC 800F562C 24020001 */   addiu    $v0, $zero, 1
/* 8EAE0 800F5630 8FB201F8 */  lw        $s2, 0x1f8($sp)
/* 8EAE4 800F5634 2A420140 */  slti      $v0, $s2, 0x140
/* 8EAE8 800F5638 1040092C */  beqz      $v0, .L800F7AEC
/* 8EAEC 800F563C 24020001 */   addiu    $v0, $zero, 1
/* 8EAF0 800F5640 8FB901FC */  lw        $t9, 0x1fc($sp)
/* 8EAF4 800F5644 2B2200F0 */  slti      $v0, $t9, 0xf0
/* 8EAF8 800F5648 10400928 */  beqz      $v0, .L800F7AEC
/* 8EAFC 800F564C 24020001 */   addiu    $v0, $zero, 1
/* 8EB00 800F5650 8FAF0204 */  lw        $t7, 0x204($sp)
/* 8EB04 800F5654 01CF2021 */  addu      $a0, $t6, $t7
/* 8EB08 800F5658 28820300 */  slti      $v0, $a0, 0x300
/* 8EB0C 800F565C 10400923 */  beqz      $v0, .L800F7AEC
/* 8EB10 800F5660 24020001 */   addiu    $v0, $zero, 1
/* 8EB14 800F5664 8FB201FC */  lw        $s2, 0x1fc($sp)
/* 8EB18 800F5668 8FB90208 */  lw        $t9, 0x208($sp)
/* 8EB1C 800F566C 02591821 */  addu      $v1, $s2, $t9
/* 8EB20 800F5670 28620300 */  slti      $v0, $v1, 0x300
/* 8EB24 800F5674 1040091D */  beqz      $v0, .L800F7AEC
/* 8EB28 800F5678 24020001 */   addiu    $v0, $zero, 1
/* 8EB2C 800F567C 1880091B */  blez      $a0, .L800F7AEC
/* 8EB30 800F5680 00000000 */   nop      
/* 8EB34 800F5684 1C600003 */  bgtz      $v1, .L800F5694
/* 8EB38 800F5688 00000000 */   nop      
.L800F568C:
/* 8EB3C 800F568C 0803DEBB */  j         .L800F7AEC
/* 8EB40 800F5690 24020001 */   addiu    $v0, $zero, 1
.L800F5694:
/* 8EB44 800F5694 8FAE01F0 */  lw        $t6, 0x1f0($sp)
/* 8EB48 800F5698 31C20001 */  andi      $v0, $t6, 1
/* 8EB4C 800F569C 1040000E */  beqz      $v0, .L800F56D8
/* 8EB50 800F56A0 3C04E300 */   lui      $a0, %hi(D_E2FFD6B0)
/* 8EB54 800F56A4 3C058011 */  lui       $a1, %hi(D_8010BBB0)
/* 8EB58 800F56A8 24A5BBB0 */  addiu     $a1, $a1, %lo(D_8010BBB0)
/* 8EB5C 800F56AC 8CA20000 */  lw        $v0, ($a1)
/* 8EB60 800F56B0 3C048011 */  lui       $a0, %hi(D_8010D6B0)
/* 8EB64 800F56B4 2484D6B0 */  addiu     $a0, $a0, %lo(D_E2FFD6B0)
/* 8EB68 800F56B8 00021A00 */  sll       $v1, $v0, 8
/* 8EB6C 800F56BC 24420001 */  addiu     $v0, $v0, 1
/* 8EB70 800F56C0 ACA20000 */  sw        $v0, ($a1)
/* 8EB74 800F56C4 28420015 */  slti      $v0, $v0, 0x15
/* 8EB78 800F56C8 14400002 */  bnez      $v0, .L800F56D4
/* 8EB7C 800F56CC 0064F021 */   addu     $fp, $v1, $a0
/* 8EB80 800F56D0 ACA00000 */  sw        $zero, ($a1)
.L800F56D4:
/* 8EB84 800F56D4 3C04E300 */  lui       $a0, 0xe300
.L800F56D8:
/* 8EB88 800F56D8 34840A01 */  ori       $a0, $a0, 0xa01
/* 8EB8C 800F56DC 3C06E200 */  lui       $a2, 0xe200
/* 8EB90 800F56E0 34C6001C */  ori       $a2, $a2, 0x1c
/* 8EB94 800F56E4 3C058410 */  lui       $a1, 0x8410
/* 8EB98 800F56E8 3C08800A */  lui       $t0, %hi(D_8009A66C)
/* 8EB9C 800F56EC 2508A66C */  addiu     $t0, $t0, %lo(D_8009A66C)
/* 8EBA0 800F56F0 8D070000 */  lw        $a3, ($t0)
/* 8EBA4 800F56F4 3C02E700 */  lui       $v0, 0xe700
/* 8EBA8 800F56F8 00E0182D */  daddu     $v1, $a3, $zero
/* 8EBAC 800F56FC 24E70008 */  addiu     $a3, $a3, 8
/* 8EBB0 800F5700 AD070000 */  sw        $a3, ($t0)
/* 8EBB4 800F5704 AC620000 */  sw        $v0, ($v1)
/* 8EBB8 800F5708 24E20008 */  addiu     $v0, $a3, 8
/* 8EBBC 800F570C AC600004 */  sw        $zero, 4($v1)
/* 8EBC0 800F5710 AD020000 */  sw        $v0, ($t0)
/* 8EBC4 800F5714 3C020010 */  lui       $v0, 0x10
/* 8EBC8 800F5718 ACE20004 */  sw        $v0, 4($a3)
/* 8EBCC 800F571C 24E20010 */  addiu     $v0, $a3, 0x10
/* 8EBD0 800F5720 ACE40000 */  sw        $a0, ($a3)
/* 8EBD4 800F5724 AD020000 */  sw        $v0, ($t0)
/* 8EBD8 800F5728 3C02F900 */  lui       $v0, 0xf900
/* 8EBDC 800F572C ACE20008 */  sw        $v0, 8($a3)
/* 8EBE0 800F5730 24E20018 */  addiu     $v0, $a3, 0x18
/* 8EBE4 800F5734 ACE0000C */  sw        $zero, 0xc($a3)
/* 8EBE8 800F5738 AD020000 */  sw        $v0, ($t0)
/* 8EBEC 800F573C 3C02F800 */  lui       $v0, 0xf800
/* 8EBF0 800F5740 ACE20010 */  sw        $v0, 0x10($a3)
/* 8EBF4 800F5744 93A200E8 */  lbu       $v0, 0xe8($sp)
/* 8EBF8 800F5748 34A54240 */  ori       $a1, $a1, 0x4240
/* 8EBFC 800F574C ACE20014 */  sw        $v0, 0x14($a3)
/* 8EC00 800F5750 24E20020 */  addiu     $v0, $a3, 0x20
/* 8EC04 800F5754 AD020000 */  sw        $v0, ($t0)
/* 8EC08 800F5758 ACE60018 */  sw        $a2, 0x18($a3)
/* 8EC0C 800F575C ACE5001C */  sw        $a1, 0x1c($a3)
/* 8EC10 800F5760 8FAF01F0 */  lw        $t7, 0x1f0($sp)
/* 8EC14 800F5764 31E20004 */  andi      $v0, $t7, 4
/* 8EC18 800F5768 14400007 */  bnez      $v0, .L800F5788
/* 8EC1C 800F576C 3C020050 */   lui      $v0, 0x50
/* 8EC20 800F5770 344203C0 */  ori       $v0, $v0, 0x3c0
/* 8EC24 800F5774 24E30028 */  addiu     $v1, $a3, 0x28
/* 8EC28 800F5778 AD030000 */  sw        $v1, ($t0)
/* 8EC2C 800F577C 3C03ED00 */  lui       $v1, 0xed00
/* 8EC30 800F5780 ACE30020 */  sw        $v1, 0x20($a3)
/* 8EC34 800F5784 ACE20024 */  sw        $v0, 0x24($a3)
.L800F5788:
/* 8EC38 800F5788 11200011 */  beqz      $t1, .L800F57D0
/* 8EC3C 800F578C 240200FF */   addiu    $v0, $zero, 0xff
/* 8EC40 800F5790 93A3010F */  lbu       $v1, 0x10f($sp)
/* 8EC44 800F5794 8D050000 */  lw        $a1, ($t0)
/* 8EC48 800F5798 91240002 */  lbu       $a0, 2($t1)
/* 8EC4C 800F579C 10620003 */  beq       $v1, $v0, .L800F57AC
/* 8EC50 800F57A0 24820002 */   addiu    $v0, $a0, 2
/* 8EC54 800F57A4 0803D5EC */  j         .L800F57B0
/* 8EC58 800F57A8 000218C0 */   sll      $v1, $v0, 3
.L800F57AC:
/* 8EC5C 800F57AC 000418C0 */  sll       $v1, $a0, 3
.L800F57B0:
/* 8EC60 800F57B0 3C028011 */  lui       $v0, %hi(D_8010BB90)
/* 8EC64 800F57B4 2442BB90 */  addiu     $v0, $v0, %lo(D_8010BB90)
/* 8EC68 800F57B8 00431021 */  addu      $v0, $v0, $v1
/* 8EC6C 800F57BC 8C520000 */  lw        $s2, ($v0)
/* 8EC70 800F57C0 8C590004 */  lw        $t9, 4($v0)
/* 8EC74 800F57C4 ACB20000 */  sw        $s2, ($a1)
/* 8EC78 800F57C8 0803D601 */  j         .L800F5804
/* 8EC7C 800F57CC ACB90004 */   sw       $t9, 4($a1)
.L800F57D0:
/* 8EC80 800F57D0 93A3010F */  lbu       $v1, 0x10f($sp)
/* 8EC84 800F57D4 8D040000 */  lw        $a0, ($t0)
/* 8EC88 800F57D8 10620006 */  beq       $v1, $v0, .L800F57F4
/* 8EC8C 800F57DC 3C03E300 */   lui      $v1, 0xe300
/* 8EC90 800F57E0 8D520028 */  lw        $s2, 0x28($t2)
/* 8EC94 800F57E4 8D59002C */  lw        $t9, 0x2c($t2)
/* 8EC98 800F57E8 AC920000 */  sw        $s2, ($a0)
/* 8EC9C 800F57EC 0803D602 */  j         .L800F5808
/* 8ECA0 800F57F0 AC990004 */   sw       $t9, 4($a0)
.L800F57F4:
/* 8ECA4 800F57F4 8D520020 */  lw        $s2, 0x20($t2)
/* 8ECA8 800F57F8 8D590024 */  lw        $t9, 0x24($t2)
/* 8ECAC 800F57FC AC920000 */  sw        $s2, ($a0)
/* 8ECB0 800F5800 AC990004 */  sw        $t9, 4($a0)
.L800F5804:
/* 8ECB4 800F5804 3C03E300 */  lui       $v1, 0xe300
.L800F5808:
/* 8ECB8 800F5808 3C13800A */  lui       $s3, %hi(D_8009A66C)
/* 8ECBC 800F580C 2673A66C */  addiu     $s3, $s3, %lo(D_8009A66C)
/* 8ECC0 800F5810 8E680000 */  lw        $t0, ($s3)
/* 8ECC4 800F5814 34631201 */  ori       $v1, $v1, 0x1201
/* 8ECC8 800F5818 25020010 */  addiu     $v0, $t0, 0x10
/* 8ECCC 800F581C AE620000 */  sw        $v0, ($s3)
/* 8ECD0 800F5820 AD030008 */  sw        $v1, 8($t0)
/* 8ECD4 800F5824 13C000E7 */  beqz      $fp, .L800F5BC4
/* 8ECD8 800F5828 AD00000C */   sw       $zero, 0xc($t0)
/* 8ECDC 800F582C 3C03DC08 */  lui       $v1, 0xdc08
/* 8ECE0 800F5830 34630008 */  ori       $v1, $v1, 8
/* 8ECE4 800F5834 27A40020 */  addiu     $a0, $sp, 0x20
/* 8ECE8 800F5838 3C120001 */  lui       $s2, 1
/* 8ECEC 800F583C 36521630 */  ori       $s2, $s2, 0x1630
/* 8ECF0 800F5840 3C05C2A0 */  lui       $a1, 0xc2a0
/* 8ECF4 800F5844 3C0642A0 */  lui       $a2, 0x42a0
/* 8ECF8 800F5848 3C074270 */  lui       $a3, 0x4270
/* 8ECFC 800F584C 3C01C270 */  lui       $at, 0xc270
/* 8ED00 800F5850 44810000 */  mtc1      $at, $f0
/* 8ED04 800F5854 3C014320 */  lui       $at, 0x4320
/* 8ED08 800F5858 44811000 */  mtc1      $at, $f2
/* 8ED0C 800F585C 3C0143F0 */  lui       $at, 0x43f0
/* 8ED10 800F5860 44812000 */  mtc1      $at, $f4
/* 8ED14 800F5864 3C013F80 */  lui       $at, 0x3f80
/* 8ED18 800F5868 4481A000 */  mtc1      $at, $f20
/* 8ED1C 800F586C 25020018 */  addiu     $v0, $t0, 0x18
/* 8ED20 800F5870 AE620000 */  sw        $v0, ($s3)
/* 8ED24 800F5874 3C028011 */  lui       $v0, %hi(D_8010BBB8)
/* 8ED28 800F5878 2442BBB8 */  addiu     $v0, $v0, %lo(D_8010BBB8)
/* 8ED2C 800F587C AD030010 */  sw        $v1, 0x10($t0)
/* 8ED30 800F5880 AD020014 */  sw        $v0, 0x14($t0)
/* 8ED34 800F5884 E7A00010 */  swc1      $f0, 0x10($sp)
/* 8ED38 800F5888 E7A20014 */  swc1      $f2, 0x14($sp)
/* 8ED3C 800F588C E7A40018 */  swc1      $f4, 0x18($sp)
/* 8ED40 800F5890 0C0187CC */  jal       guFrustumF
/* 8ED44 800F5894 E7B4001C */   swc1     $f20, 0x1c($sp)
/* 8ED48 800F5898 27A40020 */  addiu     $a0, $sp, 0x20
/* 8ED4C 800F589C 3C108007 */  lui       $s0, %hi(D_800741F0)
/* 8ED50 800F58A0 261041F0 */  addiu     $s0, $s0, %lo(D_800741F0)
/* 8ED54 800F58A4 3C11800A */  lui       $s1, %hi(D_8009A674)
/* 8ED58 800F58A8 2631A674 */  addiu     $s1, $s1, %lo(D_8009A674)
/* 8ED5C 800F58AC 96050000 */  lhu       $a1, ($s0)
/* 8ED60 800F58B0 8E220000 */  lw        $v0, ($s1)
/* 8ED64 800F58B4 00052980 */  sll       $a1, $a1, 6
/* 8ED68 800F58B8 00B22821 */  addu      $a1, $a1, $s2
/* 8ED6C 800F58BC 0C019D40 */  jal       guMtxF2L
/* 8ED70 800F58C0 00452821 */   addu     $a1, $v0, $a1
/* 8ED74 800F58C4 3C0ADA38 */  lui       $t2, 0xda38
/* 8ED78 800F58C8 354A0007 */  ori       $t2, $t2, 7
/* 8ED7C 800F58CC 8E630000 */  lw        $v1, ($s3)
/* 8ED80 800F58D0 8FA5021C */  lw        $a1, 0x21c($sp)
/* 8ED84 800F58D4 8FA60220 */  lw        $a2, 0x220($sp)
/* 8ED88 800F58D8 96020000 */  lhu       $v0, ($s0)
/* 8ED8C 800F58DC 8FA70224 */  lw        $a3, 0x224($sp)
/* 8ED90 800F58E0 8E280000 */  lw        $t0, ($s1)
/* 8ED94 800F58E4 00021180 */  sll       $v0, $v0, 6
/* 8ED98 800F58E8 00521021 */  addu      $v0, $v0, $s2
/* 8ED9C 800F58EC 01021021 */  addu      $v0, $t0, $v0
/* 8EDA0 800F58F0 0060482D */  daddu     $t1, $v1, $zero
/* 8EDA4 800F58F4 AFA20154 */  sw        $v0, 0x154($sp)
/* 8EDA8 800F58F8 96020000 */  lhu       $v0, ($s0)
/* 8EDAC 800F58FC 24630008 */  addiu     $v1, $v1, 8
/* 8EDB0 800F5900 AE630000 */  sw        $v1, ($s3)
/* 8EDB4 800F5904 AD2A0000 */  sw        $t2, ($t1)
/* 8EDB8 800F5908 24430001 */  addiu     $v1, $v0, 1
/* 8EDBC 800F590C 3042FFFF */  andi      $v0, $v0, 0xffff
/* 8EDC0 800F5910 00021180 */  sll       $v0, $v0, 6
/* 8EDC4 800F5914 00521021 */  addu      $v0, $v0, $s2
/* 8EDC8 800F5918 01024021 */  addu      $t0, $t0, $v0
/* 8EDCC 800F591C A6030000 */  sh        $v1, ($s0)
/* 8EDD0 800F5920 AD280004 */  sw        $t0, 4($t1)
/* 8EDD4 800F5924 8FB90204 */  lw        $t9, 0x204($sp)
/* 8EDD8 800F5928 8FAE01F8 */  lw        $t6, 0x1f8($sp)
/* 8EDDC 800F592C 8FAF0208 */  lw        $t7, 0x208($sp)
/* 8EDE0 800F5930 8FB201FC */  lw        $s2, 0x1fc($sp)
/* 8EDE4 800F5934 27A40020 */  addiu     $a0, $sp, 0x20
/* 8EDE8 800F5938 E7B40010 */  swc1      $f20, 0x10($sp)
/* 8EDEC 800F593C 001917C2 */  srl       $v0, $t9, 0x1f
/* 8EDF0 800F5940 03221021 */  addu      $v0, $t9, $v0
/* 8EDF4 800F5944 00021043 */  sra       $v0, $v0, 1
/* 8EDF8 800F5948 01C21021 */  addu      $v0, $t6, $v0
/* 8EDFC 800F594C 44820000 */  mtc1      $v0, $f0
/* 8EE00 800F5950 00000000 */  nop       
/* 8EE04 800F5954 46800020 */  cvt.s.w   $f0, $f0
/* 8EE08 800F5958 000F17C2 */  srl       $v0, $t7, 0x1f
/* 8EE0C 800F595C 01E21021 */  addu      $v0, $t7, $v0
/* 8EE10 800F5960 00021043 */  sra       $v0, $v0, 1
/* 8EE14 800F5964 02421021 */  addu      $v0, $s2, $v0
/* 8EE18 800F5968 E7A00014 */  swc1      $f0, 0x14($sp)
/* 8EE1C 800F596C 44820000 */  mtc1      $v0, $f0
/* 8EE20 800F5970 00000000 */  nop       
/* 8EE24 800F5974 46800020 */  cvt.s.w   $f0, $f0
/* 8EE28 800F5978 E7A00018 */  swc1      $f0, 0x18($sp)
/* 8EE2C 800F597C C7A00200 */  lwc1      $f0, 0x200($sp)
/* 8EE30 800F5980 46800020 */  cvt.s.w   $f0, $f0
/* 8EE34 800F5984 0C018FC4 */  jal       guPositionF
/* 8EE38 800F5988 E7A0001C */   swc1     $f0, 0x1c($sp)
/* 8EE3C 800F598C 4614B032 */  c.eq.s    $f22, $f20
/* 8EE40 800F5990 00000000 */  nop       
/* 8EE44 800F5994 45000005 */  bc1f      .L800F59AC
/* 8EE48 800F5998 27B00060 */   addiu    $s0, $sp, 0x60
/* 8EE4C 800F599C 4614C032 */  c.eq.s    $f24, $f20
/* 8EE50 800F59A0 00000000 */  nop       
/* 8EE54 800F59A4 4501000A */  bc1t      .L800F59D0
/* 8EE58 800F59A8 00000000 */   nop      
.L800F59AC:
/* 8EE5C 800F59AC 4405B000 */  mfc1      $a1, $f22
/* 8EE60 800F59B0 4406C000 */  mfc1      $a2, $f24
/* 8EE64 800F59B4 4407A000 */  mfc1      $a3, $f20
/* 8EE68 800F59B8 0C019DF0 */  jal       guScaleF
/* 8EE6C 800F59BC 0200202D */   daddu    $a0, $s0, $zero
/* 8EE70 800F59C0 0200202D */  daddu     $a0, $s0, $zero
/* 8EE74 800F59C4 27A50020 */  addiu     $a1, $sp, 0x20
/* 8EE78 800F59C8 0C019D80 */  jal       guMtxCatF
/* 8EE7C 800F59CC 00A0302D */   daddu    $a2, $a1, $zero
.L800F59D0:
/* 8EE80 800F59D0 8FB90230 */  lw        $t9, 0x230($sp)
/* 8EE84 800F59D4 1320001E */  beqz      $t9, .L800F5A50
/* 8EE88 800F59D8 27B00060 */   addiu    $s0, $sp, 0x60
/* 8EE8C 800F59DC 8FA20234 */  lw        $v0, 0x234($sp)
/* 8EE90 800F59E0 0200202D */  daddu     $a0, $s0, $zero
/* 8EE94 800F59E4 00021023 */  negu      $v0, $v0
/* 8EE98 800F59E8 00021FC2 */  srl       $v1, $v0, 0x1f
/* 8EE9C 800F59EC 00431021 */  addu      $v0, $v0, $v1
/* 8EEA0 800F59F0 00021043 */  sra       $v0, $v0, 1
/* 8EEA4 800F59F4 44823000 */  mtc1      $v0, $f6
/* 8EEA8 800F59F8 00000000 */  nop       
/* 8EEAC 800F59FC 468031A0 */  cvt.s.w   $f6, $f6
/* 8EEB0 800F5A00 8FA20238 */  lw        $v0, 0x238($sp)
/* 8EEB4 800F5A04 44053000 */  mfc1      $a1, $f6
/* 8EEB8 800F5A08 00021023 */  negu      $v0, $v0
/* 8EEBC 800F5A0C 00021FC2 */  srl       $v1, $v0, 0x1f
/* 8EEC0 800F5A10 00431021 */  addu      $v0, $v0, $v1
/* 8EEC4 800F5A14 00021043 */  sra       $v0, $v0, 1
/* 8EEC8 800F5A18 44823000 */  mtc1      $v0, $f6
/* 8EECC 800F5A1C 00000000 */  nop       
/* 8EED0 800F5A20 468031A0 */  cvt.s.w   $f6, $f6
/* 8EED4 800F5A24 44063000 */  mfc1      $a2, $f6
/* 8EED8 800F5A28 0C019E40 */  jal       guTranslateF
/* 8EEDC 800F5A2C 0000382D */   daddu    $a3, $zero, $zero
/* 8EEE0 800F5A30 27A40020 */  addiu     $a0, $sp, 0x20
/* 8EEE4 800F5A34 0200282D */  daddu     $a1, $s0, $zero
/* 8EEE8 800F5A38 0C019D80 */  jal       guMtxCatF
/* 8EEEC 800F5A3C 0200302D */   daddu    $a2, $s0, $zero
/* 8EEF0 800F5A40 0200202D */  daddu     $a0, $s0, $zero
/* 8EEF4 800F5A44 8FA50230 */  lw        $a1, 0x230($sp)
/* 8EEF8 800F5A48 0C019D80 */  jal       guMtxCatF
/* 8EEFC 800F5A4C 27A60020 */   addiu    $a2, $sp, 0x20
.L800F5A50:
/* 8EF00 800F5A50 8FAE023C */  lw        $t6, 0x23c($sp)
/* 8EF04 800F5A54 11C00012 */  beqz      $t6, .L800F5AA0
/* 8EF08 800F5A58 27A80020 */   addiu    $t0, $sp, 0x20
/* 8EF0C 800F5A5C 0000302D */  daddu     $a2, $zero, $zero
/* 8EF10 800F5A60 01C0382D */  daddu     $a3, $t6, $zero
.L800F5A64:
/* 8EF14 800F5A64 0000282D */  daddu     $a1, $zero, $zero
/* 8EF18 800F5A68 00E0202D */  daddu     $a0, $a3, $zero
/* 8EF1C 800F5A6C 00061900 */  sll       $v1, $a2, 4
.L800F5A70:
/* 8EF20 800F5A70 01031021 */  addu      $v0, $t0, $v1
/* 8EF24 800F5A74 24630004 */  addiu     $v1, $v1, 4
/* 8EF28 800F5A78 24A50001 */  addiu     $a1, $a1, 1
/* 8EF2C 800F5A7C C4400000 */  lwc1      $f0, ($v0)
/* 8EF30 800F5A80 28A20004 */  slti      $v0, $a1, 4
/* 8EF34 800F5A84 E4800000 */  swc1      $f0, ($a0)
/* 8EF38 800F5A88 1440FFF9 */  bnez      $v0, .L800F5A70
/* 8EF3C 800F5A8C 24840004 */   addiu    $a0, $a0, 4
/* 8EF40 800F5A90 24C60001 */  addiu     $a2, $a2, 1
/* 8EF44 800F5A94 28C20004 */  slti      $v0, $a2, 4
/* 8EF48 800F5A98 1440FFF2 */  bnez      $v0, .L800F5A64
/* 8EF4C 800F5A9C 24E70010 */   addiu    $a3, $a3, 0x10
.L800F5AA0:
/* 8EF50 800F5AA0 27B00060 */  addiu     $s0, $sp, 0x60
/* 8EF54 800F5AA4 3C05C320 */  lui       $a1, 0xc320
/* 8EF58 800F5AA8 3C06C2F0 */  lui       $a2, 0xc2f0
/* 8EF5C 800F5AAC 3C07C3A0 */  lui       $a3, 0xc3a0
/* 8EF60 800F5AB0 0C019E40 */  jal       guTranslateF
/* 8EF64 800F5AB4 0200202D */   daddu    $a0, $s0, $zero
/* 8EF68 800F5AB8 27A40020 */  addiu     $a0, $sp, 0x20
/* 8EF6C 800F5ABC 0200282D */  daddu     $a1, $s0, $zero
/* 8EF70 800F5AC0 0C019D80 */  jal       guMtxCatF
/* 8EF74 800F5AC4 0080302D */   daddu    $a2, $a0, $zero
/* 8EF78 800F5AC8 3C03D9FD */  lui       $v1, 0xd9fd
/* 8EF7C 800F5ACC 3C13800A */  lui       $s3, %hi(D_8009A66C)
/* 8EF80 800F5AD0 2673A66C */  addiu     $s3, $s3, %lo(D_8009A66C)
/* 8EF84 800F5AD4 8E640000 */  lw        $a0, ($s3)
/* 8EF88 800F5AD8 3463F9FF */  ori       $v1, $v1, 0xf9ff
/* 8EF8C 800F5ADC 0080102D */  daddu     $v0, $a0, $zero
/* 8EF90 800F5AE0 24840008 */  addiu     $a0, $a0, 8
/* 8EF94 800F5AE4 AE640000 */  sw        $a0, ($s3)
/* 8EF98 800F5AE8 AC430000 */  sw        $v1, ($v0)
/* 8EF9C 800F5AEC AC400004 */  sw        $zero, 4($v0)
/* 8EFA0 800F5AF0 8FAF01F0 */  lw        $t7, 0x1f0($sp)
/* 8EFA4 800F5AF4 31E20008 */  andi      $v0, $t7, 8
/* 8EFA8 800F5AF8 10400007 */  beqz      $v0, .L800F5B18
/* 8EFAC 800F5AFC 3C02D9FF */   lui      $v0, 0xd9ff
/* 8EFB0 800F5B00 3442FFFF */  ori       $v0, $v0, 0xffff
/* 8EFB4 800F5B04 24830008 */  addiu     $v1, $a0, 8
/* 8EFB8 800F5B08 AE630000 */  sw        $v1, ($s3)
/* 8EFBC 800F5B0C AC820000 */  sw        $v0, ($a0)
/* 8EFC0 800F5B10 24020400 */  addiu     $v0, $zero, 0x400
/* 8EFC4 800F5B14 AC820004 */  sw        $v0, 4($a0)
.L800F5B18:
/* 8EFC8 800F5B18 3C120001 */  lui       $s2, 1
/* 8EFCC 800F5B1C 36521630 */  ori       $s2, $s2, 0x1630
/* 8EFD0 800F5B20 27A40020 */  addiu     $a0, $sp, 0x20
/* 8EFD4 800F5B24 3C108007 */  lui       $s0, %hi(D_800741F0)
/* 8EFD8 800F5B28 261041F0 */  addiu     $s0, $s0, %lo(D_800741F0)
/* 8EFDC 800F5B2C 3C11800A */  lui       $s1, %hi(D_8009A674)
/* 8EFE0 800F5B30 2631A674 */  addiu     $s1, $s1, %lo(D_8009A674)
/* 8EFE4 800F5B34 96050000 */  lhu       $a1, ($s0)
/* 8EFE8 800F5B38 8E220000 */  lw        $v0, ($s1)
/* 8EFEC 800F5B3C 00052980 */  sll       $a1, $a1, 6
/* 8EFF0 800F5B40 00B22821 */  addu      $a1, $a1, $s2
/* 8EFF4 800F5B44 0C019D40 */  jal       guMtxF2L
/* 8EFF8 800F5B48 00452821 */   addu     $a1, $v0, $a1
/* 8EFFC 800F5B4C 3C03DA38 */  lui       $v1, 0xda38
/* 8F000 800F5B50 34630002 */  ori       $v1, $v1, 2
/* 8F004 800F5B54 3C06E300 */  lui       $a2, 0xe300
/* 8F008 800F5B58 34C60C00 */  ori       $a2, $a2, 0xc00
/* 8F00C 800F5B5C 8E640000 */  lw        $a0, ($s3)
/* 8F010 800F5B60 96020000 */  lhu       $v0, ($s0)
/* 8F014 800F5B64 0080282D */  daddu     $a1, $a0, $zero
/* 8F018 800F5B68 24840008 */  addiu     $a0, $a0, 8
/* 8F01C 800F5B6C AE640000 */  sw        $a0, ($s3)
/* 8F020 800F5B70 ACA30000 */  sw        $v1, ($a1)
/* 8F024 800F5B74 24430001 */  addiu     $v1, $v0, 1
/* 8F028 800F5B78 3042FFFF */  andi      $v0, $v0, 0xffff
/* 8F02C 800F5B7C 00021180 */  sll       $v0, $v0, 6
/* 8F030 800F5B80 A6030000 */  sh        $v1, ($s0)
/* 8F034 800F5B84 8E230000 */  lw        $v1, ($s1)
/* 8F038 800F5B88 00521021 */  addu      $v0, $v0, $s2
/* 8F03C 800F5B8C 00621821 */  addu      $v1, $v1, $v0
/* 8F040 800F5B90 24820008 */  addiu     $v0, $a0, 8
/* 8F044 800F5B94 ACA30004 */  sw        $v1, 4($a1)
/* 8F048 800F5B98 AE620000 */  sw        $v0, ($s3)
/* 8F04C 800F5B9C 3C020008 */  lui       $v0, 8
/* 8F050 800F5BA0 AC820004 */  sw        $v0, 4($a0)
/* 8F054 800F5BA4 24820010 */  addiu     $v0, $a0, 0x10
/* 8F058 800F5BA8 AC860000 */  sw        $a2, ($a0)
/* 8F05C 800F5BAC AE620000 */  sw        $v0, ($s3)
/* 8F060 800F5BB0 3C02DB0E */  lui       $v0, 0xdb0e
/* 8F064 800F5BB4 AC820008 */  sw        $v0, 8($a0)
/* 8F068 800F5BB8 24020014 */  addiu     $v0, $zero, 0x14
/* 8F06C 800F5BBC 0803D6F7 */  j         .L800F5BDC
/* 8F070 800F5BC0 AC82000C */   sw       $v0, 0xc($a0)
.L800F5BC4:
/* 8F074 800F5BC4 3C03E300 */  lui       $v1, 0xe300
/* 8F078 800F5BC8 34630C00 */  ori       $v1, $v1, 0xc00
/* 8F07C 800F5BCC 25020018 */  addiu     $v0, $t0, 0x18
/* 8F080 800F5BD0 AE620000 */  sw        $v0, ($s3)
/* 8F084 800F5BD4 AD030010 */  sw        $v1, 0x10($t0)
/* 8F088 800F5BD8 AD000014 */  sw        $zero, 0x14($t0)
.L800F5BDC:
/* 8F08C 800F5BDC 3C02D700 */  lui       $v0, 0xd700
/* 8F090 800F5BE0 34420002 */  ori       $v0, $v0, 2
/* 8F094 800F5BE4 3C04E300 */  lui       $a0, 0xe300
/* 8F098 800F5BE8 34841001 */  ori       $a0, $a0, 0x1001
/* 8F09C 800F5BEC 3C05E300 */  lui       $a1, 0xe300
/* 8F0A0 800F5BF0 34A50D01 */  ori       $a1, $a1, 0xd01
/* 8F0A4 800F5BF4 3C06E300 */  lui       $a2, 0xe300
/* 8F0A8 800F5BF8 3C0B800A */  lui       $t3, %hi(D_8009A66C)
/* 8F0AC 800F5BFC 256BA66C */  addiu     $t3, $t3, %lo(D_8009A66C)
/* 8F0B0 800F5C00 8D6A0000 */  lw        $t2, ($t3)
/* 8F0B4 800F5C04 34C60F00 */  ori       $a2, $a2, 0xf00
/* 8F0B8 800F5C08 0140182D */  daddu     $v1, $t2, $zero
/* 8F0BC 800F5C0C 254A0008 */  addiu     $t2, $t2, 8
/* 8F0C0 800F5C10 AD6A0000 */  sw        $t2, ($t3)
/* 8F0C4 800F5C14 AC620000 */  sw        $v0, ($v1)
/* 8F0C8 800F5C18 2402FFFF */  addiu     $v0, $zero, -1
/* 8F0CC 800F5C1C AC620004 */  sw        $v0, 4($v1)
/* 8F0D0 800F5C20 25420008 */  addiu     $v0, $t2, 8
/* 8F0D4 800F5C24 AD620000 */  sw        $v0, ($t3)
/* 8F0D8 800F5C28 25420010 */  addiu     $v0, $t2, 0x10
/* 8F0DC 800F5C2C AD440000 */  sw        $a0, ($t2)
/* 8F0E0 800F5C30 AD400004 */  sw        $zero, 4($t2)
/* 8F0E4 800F5C34 AD620000 */  sw        $v0, ($t3)
/* 8F0E8 800F5C38 25420018 */  addiu     $v0, $t2, 0x18
/* 8F0EC 800F5C3C AD450008 */  sw        $a1, 8($t2)
/* 8F0F0 800F5C40 AD40000C */  sw        $zero, 0xc($t2)
/* 8F0F4 800F5C44 AD620000 */  sw        $v0, ($t3)
/* 8F0F8 800F5C48 25420020 */  addiu     $v0, $t2, 0x20
/* 8F0FC 800F5C4C AD460010 */  sw        $a2, 0x10($t2)
/* 8F100 800F5C50 AD400014 */  sw        $zero, 0x14($t2)
/* 8F104 800F5C54 AD620000 */  sw        $v0, ($t3)
/* 8F108 800F5C58 3C02FA00 */  lui       $v0, 0xfa00
/* 8F10C 800F5C5C AD420018 */  sw        $v0, 0x18($t2)
/* 8F110 800F5C60 93B200F7 */  lbu       $s2, 0xf7($sp)
/* 8F114 800F5C64 93B900FF */  lbu       $t9, 0xff($sp)
/* 8F118 800F5C68 93AE0107 */  lbu       $t6, 0x107($sp)
/* 8F11C 800F5C6C 00121600 */  sll       $v0, $s2, 0x18
/* 8F120 800F5C70 00191C00 */  sll       $v1, $t9, 0x10
/* 8F124 800F5C74 00431025 */  or        $v0, $v0, $v1
/* 8F128 800F5C78 000E1A00 */  sll       $v1, $t6, 8
/* 8F12C 800F5C7C 00431025 */  or        $v0, $v0, $v1
/* 8F130 800F5C80 93A3010F */  lbu       $v1, 0x10f($sp)
/* 8F134 800F5C84 00431025 */  or        $v0, $v0, $v1
/* 8F138 800F5C88 AD42001C */  sw        $v0, 0x1c($t2)
/* 8F13C 800F5C8C 25420028 */  addiu     $v0, $t2, 0x28
/* 8F140 800F5C90 AD620000 */  sw        $v0, ($t3)
/* 8F144 800F5C94 3C02FB00 */  lui       $v0, 0xfb00
/* 8F148 800F5C98 AD420020 */  sw        $v0, 0x20($t2)
/* 8F14C 800F5C9C 93AF0117 */  lbu       $t7, 0x117($sp)
/* 8F150 800F5CA0 93B2011F */  lbu       $s2, 0x11f($sp)
/* 8F154 800F5CA4 93B90127 */  lbu       $t9, 0x127($sp)
/* 8F158 800F5CA8 93AE012F */  lbu       $t6, 0x12f($sp)
/* 8F15C 800F5CAC 000F1600 */  sll       $v0, $t7, 0x18
/* 8F160 800F5CB0 00121C00 */  sll       $v1, $s2, 0x10
/* 8F164 800F5CB4 00431025 */  or        $v0, $v0, $v1
/* 8F168 800F5CB8 00191A00 */  sll       $v1, $t9, 8
/* 8F16C 800F5CBC 00431025 */  or        $v0, $v0, $v1
/* 8F170 800F5CC0 01C21025 */  or        $v0, $t6, $v0
/* 8F174 800F5CC4 AD420024 */  sw        $v0, 0x24($t2)
/* 8F178 800F5CC8 8FAF0138 */  lw        $t7, 0x138($sp)
/* 8F17C 800F5CCC 11E0012E */  beqz      $t7, .L800F6188
/* 8F180 800F5CD0 00000000 */   nop      
/* 8F184 800F5CD4 92820004 */  lbu       $v0, 4($s4)
/* 8F188 800F5CD8 3043000F */  andi      $v1, $v0, 0xf
/* 8F18C 800F5CDC 24020001 */  addiu     $v0, $zero, 1
/* 8F190 800F5CE0 10620054 */  beq       $v1, $v0, .L800F5E34
/* 8F194 800F5CE4 28620002 */   slti     $v0, $v1, 2
/* 8F198 800F5CE8 10400005 */  beqz      $v0, .L800F5D00
/* 8F19C 800F5CEC 24020002 */   addiu    $v0, $zero, 2
/* 8F1A0 800F5CF0 10600009 */  beqz      $v1, .L800F5D18
/* 8F1A4 800F5CF4 25420030 */   addiu    $v0, $t2, 0x30
/* 8F1A8 800F5CF8 0803D80F */  j         .L800F603C
/* 8F1AC 800F5CFC 00000000 */   nop      
.L800F5D00:
/* 8F1B0 800F5D00 1062006D */  beq       $v1, $v0, .L800F5EB8
/* 8F1B4 800F5D04 24020003 */   addiu    $v0, $zero, 3
/* 8F1B8 800F5D08 1062008D */  beq       $v1, $v0, .L800F5F40
/* 8F1BC 800F5D0C 25420030 */   addiu    $v0, $t2, 0x30
/* 8F1C0 800F5D10 0803D80F */  j         .L800F603C
/* 8F1C4 800F5D14 00000000 */   nop      
.L800F5D18:
/* 8F1C8 800F5D18 00152042 */  srl       $a0, $s5, 1
/* 8F1CC 800F5D1C AD620000 */  sw        $v0, ($t3)
/* 8F1D0 800F5D20 2482FFFF */  addiu     $v0, $a0, -1
/* 8F1D4 800F5D24 30420FFF */  andi      $v0, $v0, 0xfff
/* 8F1D8 800F5D28 3C03FD08 */  lui       $v1, 0xfd08
/* 8F1DC 800F5D2C 00431025 */  or        $v0, $v0, $v1
/* 8F1E0 800F5D30 24840007 */  addiu     $a0, $a0, 7
/* 8F1E4 800F5D34 000420C2 */  srl       $a0, $a0, 3
/* 8F1E8 800F5D38 00042240 */  sll       $a0, $a0, 9
/* 8F1EC 800F5D3C 00164380 */  sll       $t0, $s6, 0xe
/* 8F1F0 800F5D40 3C060700 */  lui       $a2, 0x700
/* 8F1F4 800F5D44 26A3FFFF */  addiu     $v1, $s5, -1
/* 8F1F8 800F5D48 26E5FFFF */  addiu     $a1, $s7, -1
/* 8F1FC 800F5D4C 8FB20140 */  lw        $s2, 0x140($sp)
/* 8F200 800F5D50 00052880 */  sll       $a1, $a1, 2
/* 8F204 800F5D54 32470007 */  andi      $a3, $s2, 7
/* 8F208 800F5D58 00073D40 */  sll       $a3, $a3, 0x15
/* 8F20C 800F5D5C 00E21025 */  or        $v0, $a3, $v0
/* 8F210 800F5D60 AD420028 */  sw        $v0, 0x28($t2)
/* 8F214 800F5D64 8FB90138 */  lw        $t9, 0x138($sp)
/* 8F218 800F5D68 25420038 */  addiu     $v0, $t2, 0x38
/* 8F21C 800F5D6C AD59002C */  sw        $t9, 0x2c($t2)
/* 8F220 800F5D70 AD620000 */  sw        $v0, ($t3)
/* 8F224 800F5D74 3C02F508 */  lui       $v0, 0xf508
/* 8F228 800F5D78 00821025 */  or        $v0, $a0, $v0
/* 8F22C 800F5D7C 00E21025 */  or        $v0, $a3, $v0
/* 8F230 800F5D80 AD420030 */  sw        $v0, 0x30($t2)
/* 8F234 800F5D84 8FAE0144 */  lw        $t6, 0x144($sp)
/* 8F238 800F5D88 30A50FFF */  andi      $a1, $a1, 0xfff
/* 8F23C 800F5D8C 000E4900 */  sll       $t1, $t6, 4
/* 8F240 800F5D90 01261025 */  or        $v0, $t1, $a2
/* 8F244 800F5D94 01021025 */  or        $v0, $t0, $v0
/* 8F248 800F5D98 AD420034 */  sw        $v0, 0x34($t2)
/* 8F24C 800F5D9C 25420040 */  addiu     $v0, $t2, 0x40
/* 8F250 800F5DA0 AD620000 */  sw        $v0, ($t3)
/* 8F254 800F5DA4 3C02E600 */  lui       $v0, 0xe600
/* 8F258 800F5DA8 AD420038 */  sw        $v0, 0x38($t2)
/* 8F25C 800F5DAC 25420048 */  addiu     $v0, $t2, 0x48
/* 8F260 800F5DB0 AD40003C */  sw        $zero, 0x3c($t2)
/* 8F264 800F5DB4 AD620000 */  sw        $v0, ($t3)
/* 8F268 800F5DB8 3C02F400 */  lui       $v0, 0xf400
/* 8F26C 800F5DBC AD420040 */  sw        $v0, 0x40($t2)
/* 8F270 800F5DC0 00031040 */  sll       $v0, $v1, 1
/* 8F274 800F5DC4 30420FFF */  andi      $v0, $v0, 0xfff
/* 8F278 800F5DC8 00021300 */  sll       $v0, $v0, 0xc
/* 8F27C 800F5DCC 00A63025 */  or        $a2, $a1, $a2
/* 8F280 800F5DD0 00461025 */  or        $v0, $v0, $a2
/* 8F284 800F5DD4 AD420044 */  sw        $v0, 0x44($t2)
/* 8F288 800F5DD8 25420050 */  addiu     $v0, $t2, 0x50
/* 8F28C 800F5DDC AD620000 */  sw        $v0, ($t3)
/* 8F290 800F5DE0 3C02E700 */  lui       $v0, 0xe700
/* 8F294 800F5DE4 AD420048 */  sw        $v0, 0x48($t2)
/* 8F298 800F5DE8 25420058 */  addiu     $v0, $t2, 0x58
/* 8F29C 800F5DEC AD40004C */  sw        $zero, 0x4c($t2)
/* 8F2A0 800F5DF0 AD620000 */  sw        $v0, ($t3)
/* 8F2A4 800F5DF4 3C02F500 */  lui       $v0, 0xf500
/* 8F2A8 800F5DF8 00822025 */  or        $a0, $a0, $v0
/* 8F2AC 800F5DFC 00E43825 */  or        $a3, $a3, $a0
/* 8F2B0 800F5E00 01094025 */  or        $t0, $t0, $t1
/* 8F2B4 800F5E04 25420060 */  addiu     $v0, $t2, 0x60
/* 8F2B8 800F5E08 AD470050 */  sw        $a3, 0x50($t2)
/* 8F2BC 800F5E0C AD480054 */  sw        $t0, 0x54($t2)
/* 8F2C0 800F5E10 AD620000 */  sw        $v0, ($t3)
/* 8F2C4 800F5E14 3C02F200 */  lui       $v0, 0xf200
/* 8F2C8 800F5E18 00031880 */  sll       $v1, $v1, 2
/* 8F2CC 800F5E1C 30630FFF */  andi      $v1, $v1, 0xfff
/* 8F2D0 800F5E20 00031B00 */  sll       $v1, $v1, 0xc
/* 8F2D4 800F5E24 00651825 */  or        $v1, $v1, $a1
/* 8F2D8 800F5E28 AD420058 */  sw        $v0, 0x58($t2)
/* 8F2DC 800F5E2C 0803D80F */  j         .L800F603C
/* 8F2E0 800F5E30 AD43005C */   sw       $v1, 0x5c($t2)
.L800F5E34:
/* 8F2E4 800F5E34 25420030 */  addiu     $v0, $t2, 0x30
/* 8F2E8 800F5E38 26A5FFFF */  addiu     $a1, $s5, -1
/* 8F2EC 800F5E3C AD620000 */  sw        $v0, ($t3)
/* 8F2F0 800F5E40 30A20FFF */  andi      $v0, $a1, 0xfff
/* 8F2F4 800F5E44 3C03FD08 */  lui       $v1, 0xfd08
/* 8F2F8 800F5E48 00431025 */  or        $v0, $v0, $v1
/* 8F2FC 800F5E4C 3C03F508 */  lui       $v1, 0xf508
/* 8F300 800F5E50 00163B80 */  sll       $a3, $s6, 0xe
/* 8F304 800F5E54 3C040700 */  lui       $a0, 0x700
/* 8F308 800F5E58 00052880 */  sll       $a1, $a1, 2
/* 8F30C 800F5E5C 30A50FFF */  andi      $a1, $a1, 0xfff
/* 8F310 800F5E60 8FAF0140 */  lw        $t7, 0x140($sp)
/* 8F314 800F5E64 00052B00 */  sll       $a1, $a1, 0xc
/* 8F318 800F5E68 31E60007 */  andi      $a2, $t7, 7
/* 8F31C 800F5E6C 00063540 */  sll       $a2, $a2, 0x15
/* 8F320 800F5E70 00C21025 */  or        $v0, $a2, $v0
/* 8F324 800F5E74 AD420028 */  sw        $v0, 0x28($t2)
/* 8F328 800F5E78 8FB20138 */  lw        $s2, 0x138($sp)
/* 8F32C 800F5E7C 25420038 */  addiu     $v0, $t2, 0x38
/* 8F330 800F5E80 AD52002C */  sw        $s2, 0x2c($t2)
/* 8F334 800F5E84 AD620000 */  sw        $v0, ($t3)
/* 8F338 800F5E88 26A20007 */  addiu     $v0, $s5, 7
/* 8F33C 800F5E8C 000210C2 */  srl       $v0, $v0, 3
/* 8F340 800F5E90 00021240 */  sll       $v0, $v0, 9
/* 8F344 800F5E94 00431025 */  or        $v0, $v0, $v1
/* 8F348 800F5E98 00C23025 */  or        $a2, $a2, $v0
/* 8F34C 800F5E9C 26E3FFFF */  addiu     $v1, $s7, -1
/* 8F350 800F5EA0 00031880 */  sll       $v1, $v1, 2
/* 8F354 800F5EA4 AD460030 */  sw        $a2, 0x30($t2)
/* 8F358 800F5EA8 8FB90144 */  lw        $t9, 0x144($sp)
/* 8F35C 800F5EAC 30630FFF */  andi      $v1, $v1, 0xfff
/* 8F360 800F5EB0 0803D7F0 */  j         .L800F5FC0
/* 8F364 800F5EB4 00194100 */   sll      $t0, $t9, 4
.L800F5EB8:
/* 8F368 800F5EB8 25420030 */  addiu     $v0, $t2, 0x30
/* 8F36C 800F5EBC 26A5FFFF */  addiu     $a1, $s5, -1
/* 8F370 800F5EC0 AD620000 */  sw        $v0, ($t3)
/* 8F374 800F5EC4 30A20FFF */  andi      $v0, $a1, 0xfff
/* 8F378 800F5EC8 3C03FD10 */  lui       $v1, 0xfd10
/* 8F37C 800F5ECC 00431025 */  or        $v0, $v0, $v1
/* 8F380 800F5ED0 3C03F510 */  lui       $v1, 0xf510
/* 8F384 800F5ED4 00163B80 */  sll       $a3, $s6, 0xe
/* 8F388 800F5ED8 3C040700 */  lui       $a0, 0x700
/* 8F38C 800F5EDC 00052880 */  sll       $a1, $a1, 2
/* 8F390 800F5EE0 30A50FFF */  andi      $a1, $a1, 0xfff
/* 8F394 800F5EE4 8FAE0140 */  lw        $t6, 0x140($sp)
/* 8F398 800F5EE8 00052B00 */  sll       $a1, $a1, 0xc
/* 8F39C 800F5EEC 31C60007 */  andi      $a2, $t6, 7
/* 8F3A0 800F5EF0 00063540 */  sll       $a2, $a2, 0x15
/* 8F3A4 800F5EF4 00C21025 */  or        $v0, $a2, $v0
/* 8F3A8 800F5EF8 AD420028 */  sw        $v0, 0x28($t2)
/* 8F3AC 800F5EFC 8FAF0138 */  lw        $t7, 0x138($sp)
/* 8F3B0 800F5F00 25420038 */  addiu     $v0, $t2, 0x38
/* 8F3B4 800F5F04 AD4F002C */  sw        $t7, 0x2c($t2)
/* 8F3B8 800F5F08 AD620000 */  sw        $v0, ($t3)
/* 8F3BC 800F5F0C 00151040 */  sll       $v0, $s5, 1
/* 8F3C0 800F5F10 24420007 */  addiu     $v0, $v0, 7
/* 8F3C4 800F5F14 000210C2 */  srl       $v0, $v0, 3
/* 8F3C8 800F5F18 00021240 */  sll       $v0, $v0, 9
/* 8F3CC 800F5F1C 00431025 */  or        $v0, $v0, $v1
/* 8F3D0 800F5F20 00C23025 */  or        $a2, $a2, $v0
/* 8F3D4 800F5F24 26E3FFFF */  addiu     $v1, $s7, -1
/* 8F3D8 800F5F28 00031880 */  sll       $v1, $v1, 2
/* 8F3DC 800F5F2C AD460030 */  sw        $a2, 0x30($t2)
/* 8F3E0 800F5F30 8FB20144 */  lw        $s2, 0x144($sp)
/* 8F3E4 800F5F34 30630FFF */  andi      $v1, $v1, 0xfff
/* 8F3E8 800F5F38 0803D7F0 */  j         .L800F5FC0
/* 8F3EC 800F5F3C 00124100 */   sll      $t0, $s2, 4
.L800F5F40:
/* 8F3F0 800F5F40 26A5FFFF */  addiu     $a1, $s5, -1
/* 8F3F4 800F5F44 AD620000 */  sw        $v0, ($t3)
/* 8F3F8 800F5F48 30A20FFF */  andi      $v0, $a1, 0xfff
/* 8F3FC 800F5F4C 3C03FD18 */  lui       $v1, 0xfd18
/* 8F400 800F5F50 00431025 */  or        $v0, $v0, $v1
/* 8F404 800F5F54 3C03F518 */  lui       $v1, 0xf518
/* 8F408 800F5F58 00163B80 */  sll       $a3, $s6, 0xe
/* 8F40C 800F5F5C 3C040700 */  lui       $a0, 0x700
/* 8F410 800F5F60 00052880 */  sll       $a1, $a1, 2
/* 8F414 800F5F64 30A50FFF */  andi      $a1, $a1, 0xfff
/* 8F418 800F5F68 8FB90140 */  lw        $t9, 0x140($sp)
/* 8F41C 800F5F6C 00052B00 */  sll       $a1, $a1, 0xc
/* 8F420 800F5F70 33260007 */  andi      $a2, $t9, 7
/* 8F424 800F5F74 00063540 */  sll       $a2, $a2, 0x15
/* 8F428 800F5F78 00C21025 */  or        $v0, $a2, $v0
/* 8F42C 800F5F7C AD420028 */  sw        $v0, 0x28($t2)
/* 8F430 800F5F80 8FAE0138 */  lw        $t6, 0x138($sp)
/* 8F434 800F5F84 25420038 */  addiu     $v0, $t2, 0x38
/* 8F438 800F5F88 AD4E002C */  sw        $t6, 0x2c($t2)
/* 8F43C 800F5F8C AD620000 */  sw        $v0, ($t3)
/* 8F440 800F5F90 00151040 */  sll       $v0, $s5, 1
/* 8F444 800F5F94 24420007 */  addiu     $v0, $v0, 7
/* 8F448 800F5F98 000210C2 */  srl       $v0, $v0, 3
/* 8F44C 800F5F9C 00021240 */  sll       $v0, $v0, 9
/* 8F450 800F5FA0 00431025 */  or        $v0, $v0, $v1
/* 8F454 800F5FA4 00C23025 */  or        $a2, $a2, $v0
/* 8F458 800F5FA8 26E3FFFF */  addiu     $v1, $s7, -1
/* 8F45C 800F5FAC 00031880 */  sll       $v1, $v1, 2
/* 8F460 800F5FB0 AD460030 */  sw        $a2, 0x30($t2)
/* 8F464 800F5FB4 8FAF0144 */  lw        $t7, 0x144($sp)
/* 8F468 800F5FB8 30630FFF */  andi      $v1, $v1, 0xfff
/* 8F46C 800F5FBC 000F4100 */  sll       $t0, $t7, 4
.L800F5FC0:
/* 8F470 800F5FC0 01041025 */  or        $v0, $t0, $a0
/* 8F474 800F5FC4 00E21025 */  or        $v0, $a3, $v0
/* 8F478 800F5FC8 AD420034 */  sw        $v0, 0x34($t2)
/* 8F47C 800F5FCC 25420040 */  addiu     $v0, $t2, 0x40
/* 8F480 800F5FD0 AD620000 */  sw        $v0, ($t3)
/* 8F484 800F5FD4 3C02E600 */  lui       $v0, 0xe600
/* 8F488 800F5FD8 AD420038 */  sw        $v0, 0x38($t2)
/* 8F48C 800F5FDC 25420048 */  addiu     $v0, $t2, 0x48
/* 8F490 800F5FE0 AD40003C */  sw        $zero, 0x3c($t2)
/* 8F494 800F5FE4 AD620000 */  sw        $v0, ($t3)
/* 8F498 800F5FE8 3C02F400 */  lui       $v0, 0xf400
/* 8F49C 800F5FEC 00642025 */  or        $a0, $v1, $a0
/* 8F4A0 800F5FF0 00A42025 */  or        $a0, $a1, $a0
/* 8F4A4 800F5FF4 AD420040 */  sw        $v0, 0x40($t2)
/* 8F4A8 800F5FF8 25420050 */  addiu     $v0, $t2, 0x50
/* 8F4AC 800F5FFC AD440044 */  sw        $a0, 0x44($t2)
/* 8F4B0 800F6000 AD620000 */  sw        $v0, ($t3)
/* 8F4B4 800F6004 3C02E700 */  lui       $v0, 0xe700
/* 8F4B8 800F6008 AD420048 */  sw        $v0, 0x48($t2)
/* 8F4BC 800F600C 25420058 */  addiu     $v0, $t2, 0x58
/* 8F4C0 800F6010 00E83825 */  or        $a3, $a3, $t0
/* 8F4C4 800F6014 AD40004C */  sw        $zero, 0x4c($t2)
/* 8F4C8 800F6018 AD620000 */  sw        $v0, ($t3)
/* 8F4CC 800F601C 25420060 */  addiu     $v0, $t2, 0x60
/* 8F4D0 800F6020 AD460050 */  sw        $a2, 0x50($t2)
/* 8F4D4 800F6024 AD470054 */  sw        $a3, 0x54($t2)
/* 8F4D8 800F6028 AD620000 */  sw        $v0, ($t3)
/* 8F4DC 800F602C 3C02F200 */  lui       $v0, 0xf200
/* 8F4E0 800F6030 00A32825 */  or        $a1, $a1, $v1
/* 8F4E4 800F6034 AD420058 */  sw        $v0, 0x58($t2)
/* 8F4E8 800F6038 AD45005C */  sw        $a1, 0x5c($t2)
.L800F603C:
/* 8F4EC 800F603C 8FB201F0 */  lw        $s2, 0x1f0($sp)
/* 8F4F0 800F6040 32420002 */  andi      $v0, $s2, 2
/* 8F4F4 800F6044 1040002E */  beqz      $v0, .L800F6100
/* 8F4F8 800F6048 240801FF */   addiu    $t0, $zero, 0x1ff
/* 8F4FC 800F604C 3C04800A */  lui       $a0, %hi(D_8009A66C)
/* 8F500 800F6050 2484A66C */  addiu     $a0, $a0, %lo(D_8009A66C)
/* 8F504 800F6054 3C06F200 */  lui       $a2, 0xf200
/* 8F508 800F6058 8C820000 */  lw        $v0, ($a0)
/* 8F50C 800F605C 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* 8F510 800F6060 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* 8F514 800F6064 0040482D */  daddu     $t1, $v0, $zero
/* 8F518 800F6068 94670134 */  lhu       $a3, 0x134($v1)
/* 8F51C 800F606C 24420008 */  addiu     $v0, $v0, 8
/* 8F520 800F6070 AC820000 */  sw        $v0, ($a0)
/* 8F524 800F6074 8FB90204 */  lw        $t9, 0x204($sp)
/* 8F528 800F6078 8FAE0208 */  lw        $t6, 0x208($sp)
/* 8F52C 800F607C 00073880 */  sll       $a3, $a3, 2
/* 8F530 800F6080 30E701FF */  andi      $a3, $a3, 0x1ff
/* 8F534 800F6084 01074023 */  subu      $t0, $t0, $a3
/* 8F538 800F6088 001927C2 */  srl       $a0, $t9, 0x1f
/* 8F53C 800F608C 03242021 */  addu      $a0, $t9, $a0
/* 8F540 800F6090 00042043 */  sra       $a0, $a0, 1
/* 8F544 800F6094 00042880 */  sll       $a1, $a0, 2
/* 8F548 800F6098 00A82821 */  addu      $a1, $a1, $t0
/* 8F54C 800F609C 30A50FFF */  andi      $a1, $a1, 0xfff
/* 8F550 800F60A0 00052B00 */  sll       $a1, $a1, 0xc
/* 8F554 800F60A4 000E1FC2 */  srl       $v1, $t6, 0x1f
/* 8F558 800F60A8 01C31821 */  addu      $v1, $t6, $v1
/* 8F55C 800F60AC 00031843 */  sra       $v1, $v1, 1
/* 8F560 800F60B0 00031080 */  sll       $v0, $v1, 2
/* 8F564 800F60B4 00471021 */  addu      $v0, $v0, $a3
/* 8F568 800F60B8 30420FFF */  andi      $v0, $v0, 0xfff
/* 8F56C 800F60BC 00461025 */  or        $v0, $v0, $a2
/* 8F570 800F60C0 00A22825 */  or        $a1, $a1, $v0
/* 8F574 800F60C4 00952021 */  addu      $a0, $a0, $s5
/* 8F578 800F60C8 2484FFFF */  addiu     $a0, $a0, -1
/* 8F57C 800F60CC 00042080 */  sll       $a0, $a0, 2
/* 8F580 800F60D0 00882021 */  addu      $a0, $a0, $t0
/* 8F584 800F60D4 30840FFF */  andi      $a0, $a0, 0xfff
/* 8F588 800F60D8 00042300 */  sll       $a0, $a0, 0xc
/* 8F58C 800F60DC 00771821 */  addu      $v1, $v1, $s7
/* 8F590 800F60E0 2463FFFF */  addiu     $v1, $v1, -1
/* 8F594 800F60E4 00031880 */  sll       $v1, $v1, 2
/* 8F598 800F60E8 00671821 */  addu      $v1, $v1, $a3
/* 8F59C 800F60EC 30630FFF */  andi      $v1, $v1, 0xfff
/* 8F5A0 800F60F0 00832025 */  or        $a0, $a0, $v1
/* 8F5A4 800F60F4 AD250000 */  sw        $a1, ($t1)
/* 8F5A8 800F60F8 0803D862 */  j         .L800F6188
/* 8F5AC 800F60FC AD240004 */   sw       $a0, 4($t1)
.L800F6100:
/* 8F5B0 800F6100 3C03800A */  lui       $v1, %hi(D_8009A66C)
/* 8F5B4 800F6104 2463A66C */  addiu     $v1, $v1, %lo(D_8009A66C)
/* 8F5B8 800F6108 8C620000 */  lw        $v0, ($v1)
/* 8F5BC 800F610C 3C06F200 */  lui       $a2, 0xf200
/* 8F5C0 800F6110 0040382D */  daddu     $a3, $v0, $zero
/* 8F5C4 800F6114 24420008 */  addiu     $v0, $v0, 8
/* 8F5C8 800F6118 AC620000 */  sw        $v0, ($v1)
/* 8F5CC 800F611C 8FAF0204 */  lw        $t7, 0x204($sp)
/* 8F5D0 800F6120 8FB20208 */  lw        $s2, 0x208($sp)
/* 8F5D4 800F6124 000F17C2 */  srl       $v0, $t7, 0x1f
/* 8F5D8 800F6128 01E21021 */  addu      $v0, $t7, $v0
/* 8F5DC 800F612C 00021043 */  sra       $v0, $v0, 1
/* 8F5E0 800F6130 00022880 */  sll       $a1, $v0, 2
/* 8F5E4 800F6134 30A50FFF */  andi      $a1, $a1, 0xfff
/* 8F5E8 800F6138 00052B00 */  sll       $a1, $a1, 0xc
/* 8F5EC 800F613C 001227C2 */  srl       $a0, $s2, 0x1f
/* 8F5F0 800F6140 02442021 */  addu      $a0, $s2, $a0
/* 8F5F4 800F6144 00042043 */  sra       $a0, $a0, 1
/* 8F5F8 800F6148 00041880 */  sll       $v1, $a0, 2
/* 8F5FC 800F614C 30630FFF */  andi      $v1, $v1, 0xfff
/* 8F600 800F6150 00661825 */  or        $v1, $v1, $a2
/* 8F604 800F6154 00A32825 */  or        $a1, $a1, $v1
/* 8F608 800F6158 00551021 */  addu      $v0, $v0, $s5
/* 8F60C 800F615C 2442FFFF */  addiu     $v0, $v0, -1
/* 8F610 800F6160 00021080 */  sll       $v0, $v0, 2
/* 8F614 800F6164 30420FFF */  andi      $v0, $v0, 0xfff
/* 8F618 800F6168 00021300 */  sll       $v0, $v0, 0xc
/* 8F61C 800F616C 00972021 */  addu      $a0, $a0, $s7
/* 8F620 800F6170 2484FFFF */  addiu     $a0, $a0, -1
/* 8F624 800F6174 00042080 */  sll       $a0, $a0, 2
/* 8F628 800F6178 30840FFF */  andi      $a0, $a0, 0xfff
/* 8F62C 800F617C 00441025 */  or        $v0, $v0, $a0
/* 8F630 800F6180 ACE50000 */  sw        $a1, ($a3)
/* 8F634 800F6184 ACE20004 */  sw        $v0, 4($a3)
.L800F6188:
/* 8F638 800F6188 8FB9013C */  lw        $t9, 0x13c($sp)
/* 8F63C 800F618C 132003C4 */  beqz      $t9, .L800F70A0
/* 8F640 800F6190 0000682D */   daddu    $t5, $zero, $zero
/* 8F644 800F6194 3C0C800A */  lui       $t4, %hi(D_8009A66C)
/* 8F648 800F6198 258CA66C */  addiu     $t4, $t4, %lo(D_8009A66C)
/* 8F64C 800F619C 240F01FF */  addiu     $t7, $zero, 0x1ff
/* 8F650 800F61A0 31F40100 */  andi      $s4, $t7, 0x100
/* 8F654 800F61A4 3C120708 */  lui       $s2, 0x708
/* 8F658 800F61A8 36520200 */  ori       $s2, $s2, 0x200
/* 8F65C 800F61AC 8FAE014C */  lw        $t6, 0x14c($sp)
/* 8F660 800F61B0 8FAF0208 */  lw        $t7, 0x208($sp)
/* 8F664 800F61B4 3C190108 */  lui       $t9, 0x108
/* 8F668 800F61B8 AFB20158 */  sw        $s2, 0x158($sp)
/* 8F66C 800F61BC 8FB201F8 */  lw        $s2, 0x1f8($sp)
/* 8F670 800F61C0 37390200 */  ori       $t9, $t9, 0x200
/* 8F674 800F61C4 AFB9019C */  sw        $t9, 0x19c($sp)
/* 8F678 800F61C8 31C20007 */  andi      $v0, $t6, 7
/* 8F67C 800F61CC 00028540 */  sll       $s0, $v0, 0x15
/* 8F680 800F61D0 8FAE0204 */  lw        $t6, 0x204($sp)
/* 8F684 800F61D4 000FC023 */  negu      $t8, $t7
/* 8F688 800F61D8 25C2FFFF */  addiu     $v0, $t6, -1
/* 8F68C 800F61DC 00021080 */  sll       $v0, $v0, 2
/* 8F690 800F61E0 30420FFF */  andi      $v0, $v0, 0xfff
/* 8F694 800F61E4 00021300 */  sll       $v0, $v0, 0xc
/* 8F698 800F61E8 AFA2015C */  sw        $v0, 0x15c($sp)
/* 8F69C 800F61EC 000E1023 */  negu      $v0, $t6
/* 8F6A0 800F61F0 00021FC2 */  srl       $v1, $v0, 0x1f
/* 8F6A4 800F61F4 00431021 */  addu      $v0, $v0, $v1
/* 8F6A8 800F61F8 0002A843 */  sra       $s5, $v0, 1
/* 8F6AC 800F61FC 02AEB821 */  addu      $s7, $s5, $t6
/* 8F6B0 800F6200 000E1FC2 */  srl       $v1, $t6, 0x1f
/* 8F6B4 800F6204 01C31821 */  addu      $v1, $t6, $v1
/* 8F6B8 800F6208 00031843 */  sra       $v1, $v1, 1
/* 8F6BC 800F620C 02431021 */  addu      $v0, $s2, $v1
/* 8F6C0 800F6210 00021480 */  sll       $v0, $v0, 0x12
/* 8F6C4 800F6214 00028C03 */  sra       $s1, $v0, 0x10
/* 8F6C8 800F6218 32390FFF */  andi      $t9, $s1, 0xfff
/* 8F6CC 800F621C 00197300 */  sll       $t6, $t9, 0xc
/* 8F6D0 800F6220 000F17C2 */  srl       $v0, $t7, 0x1f
/* 8F6D4 800F6224 01E21021 */  addu      $v0, $t7, $v0
/* 8F6D8 800F6228 00029843 */  sra       $s3, $v0, 1
/* 8F6DC 800F622C 00119280 */  sll       $s2, $s1, 0xa
/* 8F6E0 800F6230 8FAF01FC */  lw        $t7, 0x1fc($sp)
/* 8F6E4 800F6234 00031940 */  sll       $v1, $v1, 5
/* 8F6E8 800F6238 AFB90160 */  sw        $t9, 0x160($sp)
/* 8F6EC 800F623C 3079FFFF */  andi      $t9, $v1, 0xffff
/* 8F6F0 800F6240 AFAE0164 */  sw        $t6, 0x164($sp)
/* 8F6F4 800F6244 AFB2016C */  sw        $s2, 0x16c($sp)
/* 8F6F8 800F6248 AFA301A4 */  sw        $v1, 0x1a4($sp)
/* 8F6FC 800F624C AFB90170 */  sw        $t9, 0x170($sp)
/* 8F700 800F6250 01F37821 */  addu      $t7, $t7, $s3
/* 8F704 800F6254 000F1480 */  sll       $v0, $t7, 0x12
/* 8F708 800F6258 00021403 */  sra       $v0, $v0, 0x10
/* 8F70C 800F625C 30560FFF */  andi      $s6, $v0, 0xfff
/* 8F710 800F6260 00027280 */  sll       $t6, $v0, 0xa
/* 8F714 800F6264 AFAF0168 */  sw        $t7, 0x168($sp)
/* 8F718 800F6268 00137940 */  sll       $t7, $s3, 5
/* 8F71C 800F626C 31F2FFFF */  andi      $s2, $t7, 0xffff
/* 8F720 800F6270 AFA201A0 */  sw        $v0, 0x1a0($sp)
/* 8F724 800F6274 AFAE0174 */  sw        $t6, 0x174($sp)
/* 8F728 800F6278 AFAF01A8 */  sw        $t7, 0x1a8($sp)
/* 8F72C 800F627C AFB20178 */  sw        $s2, 0x178($sp)
.L800F6280:
/* 8F730 800F6280 8FB90148 */  lw        $t9, 0x148($sp)
/* 8F734 800F6284 000D1040 */  sll       $v0, $t5, 1
/* 8F738 800F6288 00591021 */  addu      $v0, $v0, $t9
/* 8F73C 800F628C 904A0000 */  lbu       $t2, ($v0)
/* 8F740 800F6290 904B0001 */  lbu       $t3, 1($v0)
/* 8F744 800F6294 2D430002 */  sltiu     $v1, $t2, 2
/* 8F748 800F6298 1460001D */  bnez      $v1, .L800F6310
/* 8F74C 800F629C 0000382D */   daddu    $a3, $zero, $zero
/* 8F750 800F62A0 2D420003 */  sltiu     $v0, $t2, 3
/* 8F754 800F62A4 1440001A */  bnez      $v0, .L800F6310
/* 8F758 800F62A8 24070001 */   addiu    $a3, $zero, 1
/* 8F75C 800F62AC 2D420005 */  sltiu     $v0, $t2, 5
/* 8F760 800F62B0 14400017 */  bnez      $v0, .L800F6310
/* 8F764 800F62B4 24070002 */   addiu    $a3, $zero, 2
/* 8F768 800F62B8 2D420009 */  sltiu     $v0, $t2, 9
/* 8F76C 800F62BC 14400014 */  bnez      $v0, .L800F6310
/* 8F770 800F62C0 24070003 */   addiu    $a3, $zero, 3
/* 8F774 800F62C4 2D420011 */  sltiu     $v0, $t2, 0x11
/* 8F778 800F62C8 14400011 */  bnez      $v0, .L800F6310
/* 8F77C 800F62CC 24070004 */   addiu    $a3, $zero, 4
/* 8F780 800F62D0 2D420021 */  sltiu     $v0, $t2, 0x21
/* 8F784 800F62D4 1440000E */  bnez      $v0, .L800F6310
/* 8F788 800F62D8 24070005 */   addiu    $a3, $zero, 5
/* 8F78C 800F62DC 2D420041 */  sltiu     $v0, $t2, 0x41
/* 8F790 800F62E0 1440000B */  bnez      $v0, .L800F6310
/* 8F794 800F62E4 24070006 */   addiu    $a3, $zero, 6
/* 8F798 800F62E8 2D420081 */  sltiu     $v0, $t2, 0x81
/* 8F79C 800F62EC 14400008 */  bnez      $v0, .L800F6310
/* 8F7A0 800F62F0 24070007 */   addiu    $a3, $zero, 7
/* 8F7A4 800F62F4 2D420101 */  sltiu     $v0, $t2, 0x101
/* 8F7A8 800F62F8 14400005 */  bnez      $v0, .L800F6310
/* 8F7AC 800F62FC 24070008 */   addiu    $a3, $zero, 8
/* 8F7B0 800F6300 2D420201 */  sltiu     $v0, $t2, 0x201
/* 8F7B4 800F6304 10400002 */  beqz      $v0, .L800F6310
/* 8F7B8 800F6308 2407000A */   addiu    $a3, $zero, 0xa
/* 8F7BC 800F630C 24070009 */  addiu     $a3, $zero, 9
.L800F6310:
/* 8F7C0 800F6310 2D620002 */  sltiu     $v0, $t3, 2
/* 8F7C4 800F6314 1440001D */  bnez      $v0, .L800F638C
/* 8F7C8 800F6318 0000402D */   daddu    $t0, $zero, $zero
/* 8F7CC 800F631C 2D620003 */  sltiu     $v0, $t3, 3
/* 8F7D0 800F6320 1440001A */  bnez      $v0, .L800F638C
/* 8F7D4 800F6324 24080001 */   addiu    $t0, $zero, 1
/* 8F7D8 800F6328 2D620005 */  sltiu     $v0, $t3, 5
/* 8F7DC 800F632C 14400017 */  bnez      $v0, .L800F638C
/* 8F7E0 800F6330 24080002 */   addiu    $t0, $zero, 2
/* 8F7E4 800F6334 2D620009 */  sltiu     $v0, $t3, 9
/* 8F7E8 800F6338 14400014 */  bnez      $v0, .L800F638C
/* 8F7EC 800F633C 24080003 */   addiu    $t0, $zero, 3
/* 8F7F0 800F6340 2D620011 */  sltiu     $v0, $t3, 0x11
/* 8F7F4 800F6344 14400011 */  bnez      $v0, .L800F638C
/* 8F7F8 800F6348 24080004 */   addiu    $t0, $zero, 4
/* 8F7FC 800F634C 2D620021 */  sltiu     $v0, $t3, 0x21
/* 8F800 800F6350 1440000E */  bnez      $v0, .L800F638C
/* 8F804 800F6354 24080005 */   addiu    $t0, $zero, 5
/* 8F808 800F6358 2D620041 */  sltiu     $v0, $t3, 0x41
/* 8F80C 800F635C 1440000B */  bnez      $v0, .L800F638C
/* 8F810 800F6360 24080006 */   addiu    $t0, $zero, 6
/* 8F814 800F6364 2D620081 */  sltiu     $v0, $t3, 0x81
/* 8F818 800F6368 14400008 */  bnez      $v0, .L800F638C
/* 8F81C 800F636C 24080007 */   addiu    $t0, $zero, 7
/* 8F820 800F6370 2D620101 */  sltiu     $v0, $t3, 0x101
/* 8F824 800F6374 14400005 */  bnez      $v0, .L800F638C
/* 8F828 800F6378 24080008 */   addiu    $t0, $zero, 8
/* 8F82C 800F637C 2D620201 */  sltiu     $v0, $t3, 0x201
/* 8F830 800F6380 10400002 */  beqz      $v0, .L800F638C
/* 8F834 800F6384 2408000A */   addiu    $t0, $zero, 0xa
/* 8F838 800F6388 24080009 */  addiu     $t0, $zero, 9
.L800F638C:
/* 8F83C 800F638C 8FAE0150 */  lw        $t6, 0x150($sp)
/* 8F840 800F6390 240F0001 */  addiu     $t7, $zero, 1
/* 8F844 800F6394 11CF005C */  beq       $t6, $t7, .L800F6508
/* 8F848 800F6398 2546FFFF */   addiu    $a2, $t2, -1
/* 8F84C 800F639C 11C00007 */  beqz      $t6, .L800F63BC
/* 8F850 800F63A0 24120002 */   addiu    $s2, $zero, 2
/* 8F854 800F63A4 11D200A0 */  beq       $t6, $s2, .L800F6628
/* 8F858 800F63A8 24190003 */   addiu    $t9, $zero, 3
/* 8F85C 800F63AC 11D900E6 */  beq       $t6, $t9, .L800F6748
/* 8F860 800F63B0 240E0002 */   addiu    $t6, $zero, 2
/* 8F864 800F63B4 0803DA1C */  j         .L800F6870
/* 8F868 800F63B8 00000000 */   nop      
.L800F63BC:
/* 8F86C 800F63BC 000A2842 */  srl       $a1, $t2, 1
/* 8F870 800F63C0 24A2FFFF */  addiu     $v0, $a1, -1
/* 8F874 800F63C4 30420FFF */  andi      $v0, $v0, 0xfff
/* 8F878 800F63C8 3C03FD08 */  lui       $v1, 0xfd08
/* 8F87C 800F63CC 00431025 */  or        $v0, $v0, $v1
/* 8F880 800F63D0 02021025 */  or        $v0, $s0, $v0
/* 8F884 800F63D4 24A50007 */  addiu     $a1, $a1, 7
/* 8F888 800F63D8 000528C2 */  srl       $a1, $a1, 3
/* 8F88C 800F63DC 00052A40 */  sll       $a1, $a1, 9
/* 8F890 800F63E0 00084B80 */  sll       $t1, $t0, 0xe
/* 8F894 800F63E4 00074100 */  sll       $t0, $a3, 4
/* 8F898 800F63E8 2567FFFF */  addiu     $a3, $t3, -1
/* 8F89C 800F63EC 00073880 */  sll       $a3, $a3, 2
/* 8F8A0 800F63F0 30E70FFF */  andi      $a3, $a3, 0xfff
/* 8F8A4 800F63F4 8D840000 */  lw        $a0, ($t4)
/* 8F8A8 800F63F8 014B0018 */  mult      $t2, $t3
/* 8F8AC 800F63FC 0080302D */  daddu     $a2, $a0, $zero
/* 8F8B0 800F6400 24840008 */  addiu     $a0, $a0, 8
/* 8F8B4 800F6404 AD840000 */  sw        $a0, ($t4)
/* 8F8B8 800F6408 ACC20000 */  sw        $v0, ($a2)
/* 8F8BC 800F640C 8FAE013C */  lw        $t6, 0x13c($sp)
/* 8F8C0 800F6410 24820008 */  addiu     $v0, $a0, 8
/* 8F8C4 800F6414 ACCE0004 */  sw        $t6, 4($a2)
/* 8F8C8 800F6418 AD820000 */  sw        $v0, ($t4)
/* 8F8CC 800F641C 3C02F508 */  lui       $v0, 0xf508
/* 8F8D0 800F6420 00A21025 */  or        $v0, $a1, $v0
/* 8F8D4 800F6424 02021025 */  or        $v0, $s0, $v0
/* 8F8D8 800F6428 00541025 */  or        $v0, $v0, $s4
/* 8F8DC 800F642C 3C12E600 */  lui       $s2, 0xe600
/* 8F8E0 800F6430 3C19F400 */  lui       $t9, 0xf400
/* 8F8E4 800F6434 2546FFFF */  addiu     $a2, $t2, -1
/* 8F8E8 800F6438 3C0E0700 */  lui       $t6, 0x700
/* 8F8EC 800F643C 00EE1825 */  or        $v1, $a3, $t6
/* 8F8F0 800F6440 3C0E0100 */  lui       $t6, 0x100
/* 8F8F4 800F6444 AC820000 */  sw        $v0, ($a0)
/* 8F8F8 800F6448 8FAF0158 */  lw        $t7, 0x158($sp)
/* 8F8FC 800F644C 00EE3825 */  or        $a3, $a3, $t6
/* 8F900 800F6450 010F1025 */  or        $v0, $t0, $t7
/* 8F904 800F6454 01221025 */  or        $v0, $t1, $v0
/* 8F908 800F6458 AC820004 */  sw        $v0, 4($a0)
/* 8F90C 800F645C 24820010 */  addiu     $v0, $a0, 0x10
/* 8F910 800F6460 AD820000 */  sw        $v0, ($t4)
/* 8F914 800F6464 24820018 */  addiu     $v0, $a0, 0x18
/* 8F918 800F6468 AC920008 */  sw        $s2, 8($a0)
/* 8F91C 800F646C AC80000C */  sw        $zero, 0xc($a0)
/* 8F920 800F6470 AD820000 */  sw        $v0, ($t4)
/* 8F924 800F6474 00061040 */  sll       $v0, $a2, 1
/* 8F928 800F6478 30420FFF */  andi      $v0, $v0, 0xfff
/* 8F92C 800F647C 00021300 */  sll       $v0, $v0, 0xc
/* 8F930 800F6480 00431025 */  or        $v0, $v0, $v1
/* 8F934 800F6484 AC820014 */  sw        $v0, 0x14($a0)
/* 8F938 800F6488 24820020 */  addiu     $v0, $a0, 0x20
/* 8F93C 800F648C 3C0FE700 */  lui       $t7, 0xe700
/* 8F940 800F6490 AC990010 */  sw        $t9, 0x10($a0)
/* 8F944 800F6494 AD820000 */  sw        $v0, ($t4)
/* 8F948 800F6498 24820028 */  addiu     $v0, $a0, 0x28
/* 8F94C 800F649C AC8F0018 */  sw        $t7, 0x18($a0)
/* 8F950 800F64A0 AC80001C */  sw        $zero, 0x1c($a0)
/* 8F954 800F64A4 AD820000 */  sw        $v0, ($t4)
/* 8F958 800F64A8 3C02F500 */  lui       $v0, 0xf500
/* 8F95C 800F64AC 00A22825 */  or        $a1, $a1, $v0
/* 8F960 800F64B0 02052825 */  or        $a1, $s0, $a1
/* 8F964 800F64B4 00B42825 */  or        $a1, $a1, $s4
/* 8F968 800F64B8 24820030 */  addiu     $v0, $a0, 0x30
/* 8F96C 800F64BC 3C19F200 */  lui       $t9, 0xf200
/* 8F970 800F64C0 00063080 */  sll       $a2, $a2, 2
/* 8F974 800F64C4 30C60FFF */  andi      $a2, $a2, 0xfff
/* 8F978 800F64C8 00063300 */  sll       $a2, $a2, 0xc
/* 8F97C 800F64CC AC850020 */  sw        $a1, 0x20($a0)
/* 8F980 800F64D0 8FB2019C */  lw        $s2, 0x19c($sp)
/* 8F984 800F64D4 00C73025 */  or        $a2, $a2, $a3
/* 8F988 800F64D8 01124025 */  or        $t0, $t0, $s2
/* 8F98C 800F64DC 01284825 */  or        $t1, $t1, $t0
/* 8F990 800F64E0 00007812 */  mflo      $t7
/* 8F994 800F64E4 AC890024 */  sw        $t1, 0x24($a0)
/* 8F998 800F64E8 AD820000 */  sw        $v0, ($t4)
/* 8F99C 800F64EC AC990028 */  sw        $t9, 0x28($a0)
/* 8F9A0 800F64F0 AC86002C */  sw        $a2, 0x2c($a0)
/* 8F9A4 800F64F4 8FB2013C */  lw        $s2, 0x13c($sp)
/* 8F9A8 800F64F8 000F1042 */  srl       $v0, $t7, 1
/* 8F9AC 800F64FC 02429021 */  addu      $s2, $s2, $v0
/* 8F9B0 800F6500 0803DA1B */  j         .L800F686C
/* 8F9B4 800F6504 AFB2013C */   sw       $s2, 0x13c($sp)
.L800F6508:
/* 8F9B8 800F6508 30C20FFF */  andi      $v0, $a2, 0xfff
/* 8F9BC 800F650C 3C03FD08 */  lui       $v1, 0xfd08
/* 8F9C0 800F6510 00431025 */  or        $v0, $v0, $v1
/* 8F9C4 800F6514 02021025 */  or        $v0, $s0, $v0
/* 8F9C8 800F6518 00084380 */  sll       $t0, $t0, 0xe
/* 8F9CC 800F651C 00073900 */  sll       $a3, $a3, 4
/* 8F9D0 800F6520 00063080 */  sll       $a2, $a2, 2
/* 8F9D4 800F6524 30C60FFF */  andi      $a2, $a2, 0xfff
/* 8F9D8 800F6528 00063300 */  sll       $a2, $a2, 0xc
/* 8F9DC 800F652C 2563FFFF */  addiu     $v1, $t3, -1
/* 8F9E0 800F6530 00031880 */  sll       $v1, $v1, 2
/* 8F9E4 800F6534 30630FFF */  andi      $v1, $v1, 0xfff
/* 8F9E8 800F6538 8D840000 */  lw        $a0, ($t4)
/* 8F9EC 800F653C 014B0018 */  mult      $t2, $t3
/* 8F9F0 800F6540 0080282D */  daddu     $a1, $a0, $zero
/* 8F9F4 800F6544 24840008 */  addiu     $a0, $a0, 8
/* 8F9F8 800F6548 AD840000 */  sw        $a0, ($t4)
/* 8F9FC 800F654C ACA20000 */  sw        $v0, ($a1)
/* 8FA00 800F6550 8FB9013C */  lw        $t9, 0x13c($sp)
/* 8FA04 800F6554 24820008 */  addiu     $v0, $a0, 8
/* 8FA08 800F6558 ACB90004 */  sw        $t9, 4($a1)
/* 8FA0C 800F655C 25450007 */  addiu     $a1, $t2, 7
/* 8FA10 800F6560 000528C2 */  srl       $a1, $a1, 3
/* 8FA14 800F6564 00052A40 */  sll       $a1, $a1, 9
/* 8FA18 800F6568 AD820000 */  sw        $v0, ($t4)
/* 8FA1C 800F656C 3C02F508 */  lui       $v0, 0xf508
/* 8FA20 800F6570 00A22825 */  or        $a1, $a1, $v0
/* 8FA24 800F6574 02052825 */  or        $a1, $s0, $a1
/* 8FA28 800F6578 00B42825 */  or        $a1, $a1, $s4
/* 8FA2C 800F657C 3C0FE600 */  lui       $t7, 0xe600
/* 8FA30 800F6580 3C12F400 */  lui       $s2, 0xf400
/* 8FA34 800F6584 AC850000 */  sw        $a1, ($a0)
/* 8FA38 800F6588 8FAE0158 */  lw        $t6, 0x158($sp)
/* 8FA3C 800F658C 3C190700 */  lui       $t9, 0x700
/* 8FA40 800F6590 00EE1025 */  or        $v0, $a3, $t6
/* 8FA44 800F6594 01021025 */  or        $v0, $t0, $v0
/* 8FA48 800F6598 AC820004 */  sw        $v0, 4($a0)
/* 8FA4C 800F659C 24820010 */  addiu     $v0, $a0, 0x10
/* 8FA50 800F65A0 AD820000 */  sw        $v0, ($t4)
/* 8FA54 800F65A4 24820018 */  addiu     $v0, $a0, 0x18
/* 8FA58 800F65A8 AC8F0008 */  sw        $t7, 8($a0)
/* 8FA5C 800F65AC AC80000C */  sw        $zero, 0xc($a0)
/* 8FA60 800F65B0 AD820000 */  sw        $v0, ($t4)
/* 8FA64 800F65B4 00791025 */  or        $v0, $v1, $t9
/* 8FA68 800F65B8 00C21025 */  or        $v0, $a2, $v0
/* 8FA6C 800F65BC AC820014 */  sw        $v0, 0x14($a0)
/* 8FA70 800F65C0 24820020 */  addiu     $v0, $a0, 0x20
/* 8FA74 800F65C4 3C0EE700 */  lui       $t6, 0xe700
/* 8FA78 800F65C8 AC920010 */  sw        $s2, 0x10($a0)
/* 8FA7C 800F65CC AD820000 */  sw        $v0, ($t4)
/* 8FA80 800F65D0 24820028 */  addiu     $v0, $a0, 0x28
/* 8FA84 800F65D4 AC8E0018 */  sw        $t6, 0x18($a0)
/* 8FA88 800F65D8 AC80001C */  sw        $zero, 0x1c($a0)
/* 8FA8C 800F65DC AD820000 */  sw        $v0, ($t4)
/* 8FA90 800F65E0 24820030 */  addiu     $v0, $a0, 0x30
/* 8FA94 800F65E4 AC850020 */  sw        $a1, 0x20($a0)
/* 8FA98 800F65E8 8FAF019C */  lw        $t7, 0x19c($sp)
/* 8FA9C 800F65EC 3C0EF200 */  lui       $t6, 0xf200
/* 8FAA0 800F65F0 00EF3825 */  or        $a3, $a3, $t7
/* 8FAA4 800F65F4 01074025 */  or        $t0, $t0, $a3
/* 8FAA8 800F65F8 3C0F0100 */  lui       $t7, 0x100
/* 8FAAC 800F65FC 006F1825 */  or        $v1, $v1, $t7
/* 8FAB0 800F6600 00C33025 */  or        $a2, $a2, $v1
/* 8FAB4 800F6604 AC880024 */  sw        $t0, 0x24($a0)
/* 8FAB8 800F6608 AD820000 */  sw        $v0, ($t4)
/* 8FABC 800F660C AC8E0028 */  sw        $t6, 0x28($a0)
/* 8FAC0 800F6610 AC86002C */  sw        $a2, 0x2c($a0)
/* 8FAC4 800F6614 8FB2013C */  lw        $s2, 0x13c($sp)
/* 8FAC8 800F6618 0000C812 */  mflo      $t9
/* 8FACC 800F661C 02599021 */  addu      $s2, $s2, $t9
/* 8FAD0 800F6620 0803DA1B */  j         .L800F686C
/* 8FAD4 800F6624 AFB2013C */   sw       $s2, 0x13c($sp)
.L800F6628:
/* 8FAD8 800F6628 30C20FFF */  andi      $v0, $a2, 0xfff
/* 8FADC 800F662C 3C03FD10 */  lui       $v1, 0xfd10
/* 8FAE0 800F6630 00431025 */  or        $v0, $v0, $v1
/* 8FAE4 800F6634 02021025 */  or        $v0, $s0, $v0
/* 8FAE8 800F6638 00084380 */  sll       $t0, $t0, 0xe
/* 8FAEC 800F663C 00073900 */  sll       $a3, $a3, 4
/* 8FAF0 800F6640 00063080 */  sll       $a2, $a2, 2
/* 8FAF4 800F6644 30C60FFF */  andi      $a2, $a2, 0xfff
/* 8FAF8 800F6648 00063300 */  sll       $a2, $a2, 0xc
/* 8FAFC 800F664C 2563FFFF */  addiu     $v1, $t3, -1
/* 8FB00 800F6650 00031880 */  sll       $v1, $v1, 2
/* 8FB04 800F6654 30630FFF */  andi      $v1, $v1, 0xfff
/* 8FB08 800F6658 8D840000 */  lw        $a0, ($t4)
/* 8FB0C 800F665C 014B0018 */  mult      $t2, $t3
/* 8FB10 800F6660 0080282D */  daddu     $a1, $a0, $zero
/* 8FB14 800F6664 24840008 */  addiu     $a0, $a0, 8
/* 8FB18 800F6668 AD840000 */  sw        $a0, ($t4)
/* 8FB1C 800F666C ACA20000 */  sw        $v0, ($a1)
/* 8FB20 800F6670 8FAE013C */  lw        $t6, 0x13c($sp)
/* 8FB24 800F6674 24820008 */  addiu     $v0, $a0, 8
/* 8FB28 800F6678 ACAE0004 */  sw        $t6, 4($a1)
/* 8FB2C 800F667C 000A2840 */  sll       $a1, $t2, 1
/* 8FB30 800F6680 24A50007 */  addiu     $a1, $a1, 7
/* 8FB34 800F6684 000528C2 */  srl       $a1, $a1, 3
/* 8FB38 800F6688 00052A40 */  sll       $a1, $a1, 9
/* 8FB3C 800F668C AD820000 */  sw        $v0, ($t4)
/* 8FB40 800F6690 3C02F510 */  lui       $v0, 0xf510
/* 8FB44 800F6694 00A22825 */  or        $a1, $a1, $v0
/* 8FB48 800F6698 02052825 */  or        $a1, $s0, $a1
/* 8FB4C 800F669C 00B42825 */  or        $a1, $a1, $s4
/* 8FB50 800F66A0 3C12E600 */  lui       $s2, 0xe600
/* 8FB54 800F66A4 3C19F400 */  lui       $t9, 0xf400
/* 8FB58 800F66A8 AC850000 */  sw        $a1, ($a0)
/* 8FB5C 800F66AC 8FAF0158 */  lw        $t7, 0x158($sp)
/* 8FB60 800F66B0 3C0E0700 */  lui       $t6, 0x700
/* 8FB64 800F66B4 00EF1025 */  or        $v0, $a3, $t7
/* 8FB68 800F66B8 01021025 */  or        $v0, $t0, $v0
/* 8FB6C 800F66BC AC820004 */  sw        $v0, 4($a0)
/* 8FB70 800F66C0 24820010 */  addiu     $v0, $a0, 0x10
/* 8FB74 800F66C4 AD820000 */  sw        $v0, ($t4)
/* 8FB78 800F66C8 24820018 */  addiu     $v0, $a0, 0x18
/* 8FB7C 800F66CC AC920008 */  sw        $s2, 8($a0)
/* 8FB80 800F66D0 AC80000C */  sw        $zero, 0xc($a0)
/* 8FB84 800F66D4 AD820000 */  sw        $v0, ($t4)
/* 8FB88 800F66D8 006E1025 */  or        $v0, $v1, $t6
/* 8FB8C 800F66DC 00C21025 */  or        $v0, $a2, $v0
/* 8FB90 800F66E0 AC820014 */  sw        $v0, 0x14($a0)
/* 8FB94 800F66E4 24820020 */  addiu     $v0, $a0, 0x20
/* 8FB98 800F66E8 3C0FE700 */  lui       $t7, 0xe700
/* 8FB9C 800F66EC AC990010 */  sw        $t9, 0x10($a0)
/* 8FBA0 800F66F0 AD820000 */  sw        $v0, ($t4)
/* 8FBA4 800F66F4 24820028 */  addiu     $v0, $a0, 0x28
/* 8FBA8 800F66F8 AC8F0018 */  sw        $t7, 0x18($a0)
/* 8FBAC 800F66FC AC80001C */  sw        $zero, 0x1c($a0)
/* 8FBB0 800F6700 AD820000 */  sw        $v0, ($t4)
/* 8FBB4 800F6704 24820030 */  addiu     $v0, $a0, 0x30
/* 8FBB8 800F6708 3C0EF200 */  lui       $t6, 0xf200
/* 8FBBC 800F670C 3C0F0100 */  lui       $t7, 0x100
/* 8FBC0 800F6710 006F1825 */  or        $v1, $v1, $t7
/* 8FBC4 800F6714 AC850020 */  sw        $a1, 0x20($a0)
/* 8FBC8 800F6718 8FB2019C */  lw        $s2, 0x19c($sp)
/* 8FBCC 800F671C 00C33025 */  or        $a2, $a2, $v1
/* 8FBD0 800F6720 00F23825 */  or        $a3, $a3, $s2
/* 8FBD4 800F6724 01074025 */  or        $t0, $t0, $a3
/* 8FBD8 800F6728 00009012 */  mflo      $s2
/* 8FBDC 800F672C AC880024 */  sw        $t0, 0x24($a0)
/* 8FBE0 800F6730 AD820000 */  sw        $v0, ($t4)
/* 8FBE4 800F6734 AC8E0028 */  sw        $t6, 0x28($a0)
/* 8FBE8 800F6738 AC86002C */  sw        $a2, 0x2c($a0)
/* 8FBEC 800F673C 8FB9013C */  lw        $t9, 0x13c($sp)
/* 8FBF0 800F6740 0803DA19 */  j         .L800F6864
/* 8FBF4 800F6744 00121040 */   sll      $v0, $s2, 1
.L800F6748:
/* 8FBF8 800F6748 30C20FFF */  andi      $v0, $a2, 0xfff
/* 8FBFC 800F674C 3C03FD18 */  lui       $v1, 0xfd18
/* 8FC00 800F6750 00431025 */  or        $v0, $v0, $v1
/* 8FC04 800F6754 02021025 */  or        $v0, $s0, $v0
/* 8FC08 800F6758 00084380 */  sll       $t0, $t0, 0xe
/* 8FC0C 800F675C 00073900 */  sll       $a3, $a3, 4
/* 8FC10 800F6760 00063080 */  sll       $a2, $a2, 2
/* 8FC14 800F6764 30C60FFF */  andi      $a2, $a2, 0xfff
/* 8FC18 800F6768 00063300 */  sll       $a2, $a2, 0xc
/* 8FC1C 800F676C 2563FFFF */  addiu     $v1, $t3, -1
/* 8FC20 800F6770 00031880 */  sll       $v1, $v1, 2
/* 8FC24 800F6774 30630FFF */  andi      $v1, $v1, 0xfff
/* 8FC28 800F6778 8D840000 */  lw        $a0, ($t4)
/* 8FC2C 800F677C 014B0018 */  mult      $t2, $t3
/* 8FC30 800F6780 0080282D */  daddu     $a1, $a0, $zero
/* 8FC34 800F6784 24840008 */  addiu     $a0, $a0, 8
/* 8FC38 800F6788 AD840000 */  sw        $a0, ($t4)
/* 8FC3C 800F678C ACA20000 */  sw        $v0, ($a1)
/* 8FC40 800F6790 8FAE013C */  lw        $t6, 0x13c($sp)
/* 8FC44 800F6794 24820008 */  addiu     $v0, $a0, 8
/* 8FC48 800F6798 ACAE0004 */  sw        $t6, 4($a1)
/* 8FC4C 800F679C 000A2840 */  sll       $a1, $t2, 1
/* 8FC50 800F67A0 24A50007 */  addiu     $a1, $a1, 7
/* 8FC54 800F67A4 000528C2 */  srl       $a1, $a1, 3
/* 8FC58 800F67A8 00052A40 */  sll       $a1, $a1, 9
/* 8FC5C 800F67AC AD820000 */  sw        $v0, ($t4)
/* 8FC60 800F67B0 3C02F518 */  lui       $v0, 0xf518
/* 8FC64 800F67B4 00A22825 */  or        $a1, $a1, $v0
/* 8FC68 800F67B8 02052825 */  or        $a1, $s0, $a1
/* 8FC6C 800F67BC 00B42825 */  or        $a1, $a1, $s4
/* 8FC70 800F67C0 3C12E600 */  lui       $s2, 0xe600
/* 8FC74 800F67C4 3C19F400 */  lui       $t9, 0xf400
/* 8FC78 800F67C8 AC850000 */  sw        $a1, ($a0)
/* 8FC7C 800F67CC 8FAF0158 */  lw        $t7, 0x158($sp)
/* 8FC80 800F67D0 3C0E0700 */  lui       $t6, 0x700
/* 8FC84 800F67D4 00EF1025 */  or        $v0, $a3, $t7
/* 8FC88 800F67D8 01021025 */  or        $v0, $t0, $v0
/* 8FC8C 800F67DC AC820004 */  sw        $v0, 4($a0)
/* 8FC90 800F67E0 24820010 */  addiu     $v0, $a0, 0x10
/* 8FC94 800F67E4 AD820000 */  sw        $v0, ($t4)
/* 8FC98 800F67E8 24820018 */  addiu     $v0, $a0, 0x18
/* 8FC9C 800F67EC AC920008 */  sw        $s2, 8($a0)
/* 8FCA0 800F67F0 AC80000C */  sw        $zero, 0xc($a0)
/* 8FCA4 800F67F4 AD820000 */  sw        $v0, ($t4)
/* 8FCA8 800F67F8 006E1025 */  or        $v0, $v1, $t6
/* 8FCAC 800F67FC 00C21025 */  or        $v0, $a2, $v0
/* 8FCB0 800F6800 AC820014 */  sw        $v0, 0x14($a0)
/* 8FCB4 800F6804 24820020 */  addiu     $v0, $a0, 0x20
/* 8FCB8 800F6808 3C0FE700 */  lui       $t7, 0xe700
/* 8FCBC 800F680C AC990010 */  sw        $t9, 0x10($a0)
/* 8FCC0 800F6810 AD820000 */  sw        $v0, ($t4)
/* 8FCC4 800F6814 24820028 */  addiu     $v0, $a0, 0x28
/* 8FCC8 800F6818 AC8F0018 */  sw        $t7, 0x18($a0)
/* 8FCCC 800F681C AC80001C */  sw        $zero, 0x1c($a0)
/* 8FCD0 800F6820 AD820000 */  sw        $v0, ($t4)
/* 8FCD4 800F6824 24820030 */  addiu     $v0, $a0, 0x30
/* 8FCD8 800F6828 3C0EF200 */  lui       $t6, 0xf200
/* 8FCDC 800F682C 3C0F0100 */  lui       $t7, 0x100
/* 8FCE0 800F6830 006F1825 */  or        $v1, $v1, $t7
/* 8FCE4 800F6834 AC850020 */  sw        $a1, 0x20($a0)
/* 8FCE8 800F6838 8FB2019C */  lw        $s2, 0x19c($sp)
/* 8FCEC 800F683C 00C33025 */  or        $a2, $a2, $v1
/* 8FCF0 800F6840 00F23825 */  or        $a3, $a3, $s2
/* 8FCF4 800F6844 01074025 */  or        $t0, $t0, $a3
/* 8FCF8 800F6848 00009012 */  mflo      $s2
/* 8FCFC 800F684C AC880024 */  sw        $t0, 0x24($a0)
/* 8FD00 800F6850 AD820000 */  sw        $v0, ($t4)
/* 8FD04 800F6854 AC8E0028 */  sw        $t6, 0x28($a0)
/* 8FD08 800F6858 AC86002C */  sw        $a2, 0x2c($a0)
/* 8FD0C 800F685C 8FB9013C */  lw        $t9, 0x13c($sp)
/* 8FD10 800F6860 00121080 */  sll       $v0, $s2, 2
.L800F6864:
/* 8FD14 800F6864 0322C821 */  addu      $t9, $t9, $v0
/* 8FD18 800F6868 AFB9013C */  sw        $t9, 0x13c($sp)
.L800F686C:
/* 8FD1C 800F686C 240E0002 */  addiu     $t6, $zero, 2
.L800F6870:
/* 8FD20 800F6870 11AE0020 */  beq       $t5, $t6, .L800F68F4
/* 8FD24 800F6874 29A20003 */   slti     $v0, $t5, 3
/* 8FD28 800F6878 10400005 */  beqz      $v0, .L800F6890
/* 8FD2C 800F687C 240F0001 */   addiu    $t7, $zero, 1
/* 8FD30 800F6880 11AF0008 */  beq       $t5, $t7, .L800F68A4
/* 8FD34 800F6884 3C0EF200 */   lui      $t6, 0xf200
/* 8FD38 800F6888 0803DA6C */  j         .L800F69B0
/* 8FD3C 800F688C 00000000 */   nop      
.L800F6890:
/* 8FD40 800F6890 24120003 */  addiu     $s2, $zero, 3
/* 8FD44 800F6894 11B2002E */  beq       $t5, $s2, .L800F6950
/* 8FD48 800F6898 3C0EF200 */   lui      $t6, 0xf200
/* 8FD4C 800F689C 0803DA6C */  j         .L800F69B0
/* 8FD50 800F68A0 00000000 */   nop      
.L800F68A4:
/* 8FD54 800F68A4 8D820000 */  lw        $v0, ($t4)
/* 8FD58 800F68A8 0040182D */  daddu     $v1, $v0, $zero
/* 8FD5C 800F68AC 24420008 */  addiu     $v0, $v0, 8
/* 8FD60 800F68B0 AD820000 */  sw        $v0, ($t4)
/* 8FD64 800F68B4 8FB90204 */  lw        $t9, 0x204($sp)
/* 8FD68 800F68B8 3C0F0100 */  lui       $t7, 0x100
/* 8FD6C 800F68BC 032A1023 */  subu      $v0, $t9, $t2
/* 8FD70 800F68C0 00021080 */  sll       $v0, $v0, 2
/* 8FD74 800F68C4 30420FFF */  andi      $v0, $v0, 0xfff
/* 8FD78 800F68C8 00021300 */  sll       $v0, $v0, 0xc
/* 8FD7C 800F68CC 004E1025 */  or        $v0, $v0, $t6
/* 8FD80 800F68D0 AC620000 */  sw        $v0, ($v1)
/* 8FD84 800F68D4 2562FFFF */  addiu     $v0, $t3, -1
/* 8FD88 800F68D8 00021080 */  sll       $v0, $v0, 2
/* 8FD8C 800F68DC 30420FFF */  andi      $v0, $v0, 0xfff
/* 8FD90 800F68E0 8FB2015C */  lw        $s2, 0x15c($sp)
/* 8FD94 800F68E4 004F1025 */  or        $v0, $v0, $t7
/* 8FD98 800F68E8 02421025 */  or        $v0, $s2, $v0
/* 8FD9C 800F68EC 0803DA6C */  j         .L800F69B0
/* 8FDA0 800F68F0 AC620004 */   sw       $v0, 4($v1)
.L800F68F4:
/* 8FDA4 800F68F4 3C0EF200 */  lui       $t6, 0xf200
/* 8FDA8 800F68F8 2543FFFF */  addiu     $v1, $t2, -1
/* 8FDAC 800F68FC 00031880 */  sll       $v1, $v1, 2
/* 8FDB0 800F6900 30630FFF */  andi      $v1, $v1, 0xfff
/* 8FDB4 800F6904 8D820000 */  lw        $v0, ($t4)
/* 8FDB8 800F6908 00031B00 */  sll       $v1, $v1, 0xc
/* 8FDBC 800F690C 0040202D */  daddu     $a0, $v0, $zero
/* 8FDC0 800F6910 24420008 */  addiu     $v0, $v0, 8
/* 8FDC4 800F6914 AD820000 */  sw        $v0, ($t4)
/* 8FDC8 800F6918 8FB90208 */  lw        $t9, 0x208($sp)
/* 8FDCC 800F691C 3C0F0100 */  lui       $t7, 0x100
/* 8FDD0 800F6920 032B1023 */  subu      $v0, $t9, $t3
/* 8FDD4 800F6924 00021080 */  sll       $v0, $v0, 2
/* 8FDD8 800F6928 30420FFF */  andi      $v0, $v0, 0xfff
/* 8FDDC 800F692C 004E1025 */  or        $v0, $v0, $t6
/* 8FDE0 800F6930 AC820000 */  sw        $v0, ($a0)
/* 8FDE4 800F6934 2722FFFF */  addiu     $v0, $t9, -1
/* 8FDE8 800F6938 00021080 */  sll       $v0, $v0, 2
/* 8FDEC 800F693C 30420FFF */  andi      $v0, $v0, 0xfff
/* 8FDF0 800F6940 004F1025 */  or        $v0, $v0, $t7
/* 8FDF4 800F6944 00621825 */  or        $v1, $v1, $v0
/* 8FDF8 800F6948 0803DA6C */  j         .L800F69B0
/* 8FDFC 800F694C AC830004 */   sw       $v1, 4($a0)
.L800F6950:
/* 8FE00 800F6950 8D820000 */  lw        $v0, ($t4)
/* 8FE04 800F6954 3C0F0100 */  lui       $t7, 0x100
/* 8FE08 800F6958 0040202D */  daddu     $a0, $v0, $zero
/* 8FE0C 800F695C 24420008 */  addiu     $v0, $v0, 8
/* 8FE10 800F6960 AD820000 */  sw        $v0, ($t4)
/* 8FE14 800F6964 8FB20204 */  lw        $s2, 0x204($sp)
/* 8FE18 800F6968 8FB90208 */  lw        $t9, 0x208($sp)
/* 8FE1C 800F696C 024A1823 */  subu      $v1, $s2, $t2
/* 8FE20 800F6970 00031880 */  sll       $v1, $v1, 2
/* 8FE24 800F6974 30630FFF */  andi      $v1, $v1, 0xfff
/* 8FE28 800F6978 00031B00 */  sll       $v1, $v1, 0xc
/* 8FE2C 800F697C 032B1023 */  subu      $v0, $t9, $t3
/* 8FE30 800F6980 00021080 */  sll       $v0, $v0, 2
/* 8FE34 800F6984 30420FFF */  andi      $v0, $v0, 0xfff
/* 8FE38 800F6988 004E1025 */  or        $v0, $v0, $t6
/* 8FE3C 800F698C 00621825 */  or        $v1, $v1, $v0
/* 8FE40 800F6990 2722FFFF */  addiu     $v0, $t9, -1
/* 8FE44 800F6994 00021080 */  sll       $v0, $v0, 2
/* 8FE48 800F6998 30420FFF */  andi      $v0, $v0, 0xfff
/* 8FE4C 800F699C AC830000 */  sw        $v1, ($a0)
/* 8FE50 800F69A0 8FB2015C */  lw        $s2, 0x15c($sp)
/* 8FE54 800F69A4 004F1025 */  or        $v0, $v0, $t7
/* 8FE58 800F69A8 02421025 */  or        $v0, $s2, $v0
/* 8FE5C 800F69AC AC820004 */  sw        $v0, 4($a0)
.L800F69B0:
/* 8FE60 800F69B0 13C00093 */  beqz      $fp, .L800F6C00
/* 8FE64 800F69B4 24190001 */   addiu    $t9, $zero, 1
/* 8FE68 800F69B8 11B90029 */  beq       $t5, $t9, .L800F6A60
/* 8FE6C 800F69BC 29A20002 */   slti     $v0, $t5, 2
/* 8FE70 800F69C0 10400005 */  beqz      $v0, .L800F69D8
/* 8FE74 800F69C4 240E0002 */   addiu    $t6, $zero, 2
/* 8FE78 800F69C8 11A00009 */  beqz      $t5, .L800F69F0
/* 8FE7C 800F69CC 3C040100 */   lui      $a0, 0x100
/* 8FE80 800F69D0 0803DAF2 */  j         .L800F6BC8
/* 8FE84 800F69D4 34844008 */   ori      $a0, $a0, 0x4008
.L800F69D8:
/* 8FE88 800F69D8 11AE0040 */  beq       $t5, $t6, .L800F6ADC
/* 8FE8C 800F69DC 240F0003 */   addiu    $t7, $zero, 3
/* 8FE90 800F69E0 11AF005A */  beq       $t5, $t7, .L800F6B4C
/* 8FE94 800F69E4 3C040100 */   lui      $a0, 0x100
/* 8FE98 800F69E8 0803DAF2 */  j         .L800F6BC8
/* 8FE9C 800F69EC 34844008 */   ori      $a0, $a0, 0x4008
.L800F69F0:
/* 8FEA0 800F69F0 001817C2 */  srl       $v0, $t8, 0x1f
/* 8FEA4 800F69F4 03021021 */  addu      $v0, $t8, $v0
/* 8FEA8 800F69F8 00021043 */  sra       $v0, $v0, 1
/* 8FEAC 800F69FC A7D50000 */  sh        $s5, ($fp)
/* 8FEB0 800F6A00 A7C20002 */  sh        $v0, 2($fp)
/* 8FEB4 800F6A04 A7C00004 */  sh        $zero, 4($fp)
/* 8FEB8 800F6A08 A7C00010 */  sh        $zero, 0x10($fp)
/* 8FEBC 800F6A0C A7C20012 */  sh        $v0, 0x12($fp)
/* 8FEC0 800F6A10 A7C00014 */  sh        $zero, 0x14($fp)
/* 8FEC4 800F6A14 A7D50020 */  sh        $s5, 0x20($fp)
/* 8FEC8 800F6A18 A7C00022 */  sh        $zero, 0x22($fp)
/* 8FECC 800F6A1C A7C00024 */  sh        $zero, 0x24($fp)
/* 8FED0 800F6A20 A7C00030 */  sh        $zero, 0x30($fp)
/* 8FED4 800F6A24 A7C00032 */  sh        $zero, 0x32($fp)
/* 8FED8 800F6A28 A7C00034 */  sh        $zero, 0x34($fp)
/* 8FEDC 800F6A2C A7C00008 */  sh        $zero, 8($fp)
/* 8FEE0 800F6A30 A7C0000A */  sh        $zero, 0xa($fp)
/* 8FEE4 800F6A34 97B201A6 */  lhu       $s2, 0x1a6($sp)
/* 8FEE8 800F6A38 A7C0001A */  sh        $zero, 0x1a($fp)
/* 8FEEC 800F6A3C A7C00028 */  sh        $zero, 0x28($fp)
/* 8FEF0 800F6A40 A7D20018 */  sh        $s2, 0x18($fp)
/* 8FEF4 800F6A44 97B901AA */  lhu       $t9, 0x1aa($sp)
/* 8FEF8 800F6A48 A7D9002A */  sh        $t9, 0x2a($fp)
/* 8FEFC 800F6A4C 97AE01A6 */  lhu       $t6, 0x1a6($sp)
/* 8FF00 800F6A50 A7CE0038 */  sh        $t6, 0x38($fp)
/* 8FF04 800F6A54 97AF01AA */  lhu       $t7, 0x1aa($sp)
/* 8FF08 800F6A58 0803DAF0 */  j         .L800F6BC0
/* 8FF0C 800F6A5C A7CF003A */   sh       $t7, 0x3a($fp)
.L800F6A60:
/* 8FF10 800F6A60 001817C2 */  srl       $v0, $t8, 0x1f
/* 8FF14 800F6A64 03021021 */  addu      $v0, $t8, $v0
/* 8FF18 800F6A68 00021043 */  sra       $v0, $v0, 1
/* 8FF1C 800F6A6C A7C00040 */  sh        $zero, 0x40($fp)
/* 8FF20 800F6A70 A7C20042 */  sh        $v0, 0x42($fp)
/* 8FF24 800F6A74 A7C00044 */  sh        $zero, 0x44($fp)
/* 8FF28 800F6A78 A7D70050 */  sh        $s7, 0x50($fp)
/* 8FF2C 800F6A7C A7C20052 */  sh        $v0, 0x52($fp)
/* 8FF30 800F6A80 A7C00054 */  sh        $zero, 0x54($fp)
/* 8FF34 800F6A84 A7C00060 */  sh        $zero, 0x60($fp)
/* 8FF38 800F6A88 A7C00062 */  sh        $zero, 0x62($fp)
/* 8FF3C 800F6A8C A7C00064 */  sh        $zero, 0x64($fp)
/* 8FF40 800F6A90 A7D70070 */  sh        $s7, 0x70($fp)
/* 8FF44 800F6A94 A7C00072 */  sh        $zero, 0x72($fp)
/* 8FF48 800F6A98 A7C00074 */  sh        $zero, 0x74($fp)
/* 8FF4C 800F6A9C 97B201A6 */  lhu       $s2, 0x1a6($sp)
/* 8FF50 800F6AA0 A7C0004A */  sh        $zero, 0x4a($fp)
/* 8FF54 800F6AA4 A7D20048 */  sh        $s2, 0x48($fp)
/* 8FF58 800F6AA8 8FB90204 */  lw        $t9, 0x204($sp)
/* 8FF5C 800F6AAC A7C0005A */  sh        $zero, 0x5a($fp)
/* 8FF60 800F6AB0 00191140 */  sll       $v0, $t9, 5
/* 8FF64 800F6AB4 A7C20058 */  sh        $v0, 0x58($fp)
/* 8FF68 800F6AB8 97AE01A6 */  lhu       $t6, 0x1a6($sp)
/* 8FF6C 800F6ABC A7CE0068 */  sh        $t6, 0x68($fp)
/* 8FF70 800F6AC0 97AF01AA */  lhu       $t7, 0x1aa($sp)
/* 8FF74 800F6AC4 A7C20078 */  sh        $v0, 0x78($fp)
/* 8FF78 800F6AC8 A7CF006A */  sh        $t7, 0x6a($fp)
/* 8FF7C 800F6ACC 97B201AA */  lhu       $s2, 0x1aa($sp)
/* 8FF80 800F6AD0 A7D2007A */  sh        $s2, 0x7a($fp)
/* 8FF84 800F6AD4 0803DAF0 */  j         .L800F6BC0
/* 8FF88 800F6AD8 27DE0040 */   addiu    $fp, $fp, 0x40
.L800F6ADC:
/* 8FF8C 800F6ADC A7D50080 */  sh        $s5, 0x80($fp)
/* 8FF90 800F6AE0 A7C00082 */  sh        $zero, 0x82($fp)
/* 8FF94 800F6AE4 A7C00084 */  sh        $zero, 0x84($fp)
/* 8FF98 800F6AE8 A7C00090 */  sh        $zero, 0x90($fp)
/* 8FF9C 800F6AEC A7C00092 */  sh        $zero, 0x92($fp)
/* 8FFA0 800F6AF0 A7C00094 */  sh        $zero, 0x94($fp)
/* 8FFA4 800F6AF4 A7D500A0 */  sh        $s5, 0xa0($fp)
/* 8FFA8 800F6AF8 A7D300A2 */  sh        $s3, 0xa2($fp)
/* 8FFAC 800F6AFC A7C000A4 */  sh        $zero, 0xa4($fp)
/* 8FFB0 800F6B00 A7C000B0 */  sh        $zero, 0xb0($fp)
/* 8FFB4 800F6B04 A7D300B2 */  sh        $s3, 0xb2($fp)
/* 8FFB8 800F6B08 A7C000B4 */  sh        $zero, 0xb4($fp)
/* 8FFBC 800F6B0C A7C00088 */  sh        $zero, 0x88($fp)
/* 8FFC0 800F6B10 97B901AA */  lhu       $t9, 0x1aa($sp)
/* 8FFC4 800F6B14 A7D9008A */  sh        $t9, 0x8a($fp)
/* 8FFC8 800F6B18 97AE01A6 */  lhu       $t6, 0x1a6($sp)
/* 8FFCC 800F6B1C A7CE0098 */  sh        $t6, 0x98($fp)
/* 8FFD0 800F6B20 97AF01AA */  lhu       $t7, 0x1aa($sp)
/* 8FFD4 800F6B24 A7C000A8 */  sh        $zero, 0xa8($fp)
/* 8FFD8 800F6B28 A7CF009A */  sh        $t7, 0x9a($fp)
/* 8FFDC 800F6B2C 8FB20208 */  lw        $s2, 0x208($sp)
/* 8FFE0 800F6B30 00121140 */  sll       $v0, $s2, 5
/* 8FFE4 800F6B34 A7C200AA */  sh        $v0, 0xaa($fp)
/* 8FFE8 800F6B38 97B901A6 */  lhu       $t9, 0x1a6($sp)
/* 8FFEC 800F6B3C A7C200BA */  sh        $v0, 0xba($fp)
/* 8FFF0 800F6B40 A7D900B8 */  sh        $t9, 0xb8($fp)
/* 8FFF4 800F6B44 0803DAF0 */  j         .L800F6BC0
/* 8FFF8 800F6B48 27DE0080 */   addiu    $fp, $fp, 0x80
.L800F6B4C:
/* 8FFFC 800F6B4C A7C000C0 */  sh        $zero, 0xc0($fp)
/* 90000 800F6B50 A7C000C2 */  sh        $zero, 0xc2($fp)
/* 90004 800F6B54 A7C000C4 */  sh        $zero, 0xc4($fp)
/* 90008 800F6B58 A7D700D0 */  sh        $s7, 0xd0($fp)
/* 9000C 800F6B5C A7C000D2 */  sh        $zero, 0xd2($fp)
/* 90010 800F6B60 A7C000D4 */  sh        $zero, 0xd4($fp)
/* 90014 800F6B64 A7C000E0 */  sh        $zero, 0xe0($fp)
/* 90018 800F6B68 A7D300E2 */  sh        $s3, 0xe2($fp)
/* 9001C 800F6B6C A7C000E4 */  sh        $zero, 0xe4($fp)
/* 90020 800F6B70 A7D700F0 */  sh        $s7, 0xf0($fp)
/* 90024 800F6B74 A7D300F2 */  sh        $s3, 0xf2($fp)
/* 90028 800F6B78 A7C000F4 */  sh        $zero, 0xf4($fp)
/* 9002C 800F6B7C 97AE01A6 */  lhu       $t6, 0x1a6($sp)
/* 90030 800F6B80 A7CE00C8 */  sh        $t6, 0xc8($fp)
/* 90034 800F6B84 97AF01AA */  lhu       $t7, 0x1aa($sp)
/* 90038 800F6B88 A7CF00CA */  sh        $t7, 0xca($fp)
/* 9003C 800F6B8C 8FB20204 */  lw        $s2, 0x204($sp)
/* 90040 800F6B90 00121940 */  sll       $v1, $s2, 5
/* 90044 800F6B94 A7C300D8 */  sh        $v1, 0xd8($fp)
/* 90048 800F6B98 97B901AA */  lhu       $t9, 0x1aa($sp)
/* 9004C 800F6B9C A7D900DA */  sh        $t9, 0xda($fp)
/* 90050 800F6BA0 97AE01A6 */  lhu       $t6, 0x1a6($sp)
/* 90054 800F6BA4 A7CE00E8 */  sh        $t6, 0xe8($fp)
/* 90058 800F6BA8 8FAF0208 */  lw        $t7, 0x208($sp)
/* 9005C 800F6BAC A7C300F8 */  sh        $v1, 0xf8($fp)
/* 90060 800F6BB0 000F1140 */  sll       $v0, $t7, 5
/* 90064 800F6BB4 A7C200EA */  sh        $v0, 0xea($fp)
/* 90068 800F6BB8 A7C200FA */  sh        $v0, 0xfa($fp)
/* 9006C 800F6BBC 27DE00C0 */  addiu     $fp, $fp, 0xc0
.L800F6BC0:
/* 90070 800F6BC0 3C040100 */  lui       $a0, 0x100
/* 90074 800F6BC4 34844008 */  ori       $a0, $a0, 0x4008
.L800F6BC8:
/* 90078 800F6BC8 3C050600 */  lui       $a1, 0x600
/* 9007C 800F6BCC 8D830000 */  lw        $v1, ($t4)
/* 90080 800F6BD0 34A50602 */  ori       $a1, $a1, 0x602
/* 90084 800F6BD4 0060102D */  daddu     $v0, $v1, $zero
/* 90088 800F6BD8 24630008 */  addiu     $v1, $v1, 8
/* 9008C 800F6BDC AD830000 */  sw        $v1, ($t4)
/* 90090 800F6BE0 AC440000 */  sw        $a0, ($v0)
/* 90094 800F6BE4 AC5E0004 */  sw        $fp, 4($v0)
/* 90098 800F6BE8 24620008 */  addiu     $v0, $v1, 8
/* 9009C 800F6BEC AD820000 */  sw        $v0, ($t4)
/* 900A0 800F6BF0 24020406 */  addiu     $v0, $zero, 0x406
/* 900A4 800F6BF4 AC650000 */  sw        $a1, ($v1)
/* 900A8 800F6BF8 0803DC1C */  j         .L800F7070
/* 900AC 800F6BFC AC620004 */   sw       $v0, 4($v1)
.L800F6C00:
/* 900B0 800F6C00 24120001 */  addiu     $s2, $zero, 1
/* 900B4 800F6C04 11B2004B */  beq       $t5, $s2, .L800F6D34
/* 900B8 800F6C08 29A20002 */   slti     $v0, $t5, 2
/* 900BC 800F6C0C 10400005 */  beqz      $v0, .L800F6C24
/* 900C0 800F6C10 24190002 */   addiu    $t9, $zero, 2
/* 900C4 800F6C14 11A00009 */  beqz      $t5, .L800F6C3C
/* 900C8 800F6C18 00000000 */   nop      
/* 900CC 800F6C1C 0803DC1C */  j         .L800F7070
/* 900D0 800F6C20 00000000 */   nop      
.L800F6C24:
/* 900D4 800F6C24 11B90082 */  beq       $t5, $t9, .L800F6E30
/* 900D8 800F6C28 240E0003 */   addiu    $t6, $zero, 3
/* 900DC 800F6C2C 11AE00C3 */  beq       $t5, $t6, .L800F6F3C
/* 900E0 800F6C30 00000000 */   nop      
/* 900E4 800F6C34 0803DC1C */  j         .L800F7070
/* 900E8 800F6C38 00000000 */   nop      
.L800F6C3C:
/* 900EC 800F6C3C 8D830000 */  lw        $v1, ($t4)
/* 900F0 800F6C40 24620008 */  addiu     $v0, $v1, 8
/* 900F4 800F6C44 1A200005 */  blez      $s1, .L800F6C5C
/* 900F8 800F6C48 AD820000 */   sw       $v0, ($t4)
/* 900FC 800F6C4C 8FAF0164 */  lw        $t7, 0x164($sp)
/* 90100 800F6C50 3C02E400 */  lui       $v0, 0xe400
/* 90104 800F6C54 0803DB18 */  j         .L800F6C60
/* 90108 800F6C58 01E21025 */   or       $v0, $t7, $v0
.L800F6C5C:
/* 9010C 800F6C5C 3C02E400 */  lui       $v0, 0xe400
.L800F6C60:
/* 90110 800F6C60 AC620000 */  sw        $v0, ($v1)
/* 90114 800F6C64 8FB201A0 */  lw        $s2, 0x1a0($sp)
/* 90118 800F6C68 1A400002 */  blez      $s2, .L800F6C74
/* 9011C 800F6C6C 00561025 */   or       $v0, $v0, $s6
/* 90120 800F6C70 AC620000 */  sw        $v0, ($v1)
.L800F6C74:
/* 90124 800F6C74 8FB901F8 */  lw        $t9, 0x1f8($sp)
/* 90128 800F6C78 00191480 */  sll       $v0, $t9, 0x12
/* 9012C 800F6C7C 00021403 */  sra       $v0, $v0, 0x10
/* 90130 800F6C80 18400004 */  blez      $v0, .L800F6C94
/* 90134 800F6C84 24640004 */   addiu    $a0, $v1, 4
/* 90138 800F6C88 30420FFF */  andi      $v0, $v0, 0xfff
/* 9013C 800F6C8C 0803DB26 */  j         .L800F6C98
/* 90140 800F6C90 00021B00 */   sll      $v1, $v0, 0xc
.L800F6C94:
/* 90144 800F6C94 0000182D */  daddu     $v1, $zero, $zero
.L800F6C98:
/* 90148 800F6C98 AC830000 */  sw        $v1, ($a0)
/* 9014C 800F6C9C 8FAE01FC */  lw        $t6, 0x1fc($sp)
/* 90150 800F6CA0 000E1480 */  sll       $v0, $t6, 0x12
/* 90154 800F6CA4 00021403 */  sra       $v0, $v0, 0x10
/* 90158 800F6CA8 18400003 */  blez      $v0, .L800F6CB8
/* 9015C 800F6CAC 30420FFF */   andi     $v0, $v0, 0xfff
/* 90160 800F6CB0 00621025 */  or        $v0, $v1, $v0
/* 90164 800F6CB4 AC820000 */  sw        $v0, ($a0)
.L800F6CB8:
/* 90168 800F6CB8 8D820000 */  lw        $v0, ($t4)
/* 9016C 800F6CBC 0040182D */  daddu     $v1, $v0, $zero
/* 90170 800F6CC0 24420008 */  addiu     $v0, $v0, 8
/* 90174 800F6CC4 AD820000 */  sw        $v0, ($t4)
/* 90178 800F6CC8 3C02E100 */  lui       $v0, 0xe100
/* 9017C 800F6CCC AC620000 */  sw        $v0, ($v1)
/* 90180 800F6CD0 8FAF01F8 */  lw        $t7, 0x1f8($sp)
/* 90184 800F6CD4 000F1480 */  sll       $v0, $t7, 0x12
/* 90188 800F6CD8 00021403 */  sra       $v0, $v0, 0x10
/* 9018C 800F6CDC 04410007 */  bgez      $v0, .L800F6CFC
/* 90190 800F6CE0 24630004 */   addiu    $v1, $v1, 4
/* 90194 800F6CE4 000210C0 */  sll       $v0, $v0, 3
/* 90198 800F6CE8 5C400001 */  bgtzl     $v0, .L800F6CF0
/* 9019C 800F6CEC 0000102D */   daddu    $v0, $zero, $zero
.L800F6CF0:
/* 901A0 800F6CF0 00021023 */  negu      $v0, $v0
/* 901A4 800F6CF4 0803DB40 */  j         .L800F6D00
/* 901A8 800F6CF8 00022400 */   sll      $a0, $v0, 0x10
.L800F6CFC:
/* 901AC 800F6CFC 0000202D */  daddu     $a0, $zero, $zero
.L800F6D00:
/* 901B0 800F6D00 AC640000 */  sw        $a0, ($v1)
/* 901B4 800F6D04 8FB201FC */  lw        $s2, 0x1fc($sp)
/* 901B8 800F6D08 00121080 */  sll       $v0, $s2, 2
/* 901BC 800F6D0C 044300D0 */  bgezl     $v0, .L800F7050
/* 901C0 800F6D10 3C040400 */   lui      $a0, 0x400
/* 901C4 800F6D14 00121480 */  sll       $v0, $s2, 0x12
/* 901C8 800F6D18 00021343 */  sra       $v0, $v0, 0xd
/* 901CC 800F6D1C 5C400001 */  bgtzl     $v0, .L800F6D24
/* 901D0 800F6D20 0000102D */   daddu    $v0, $zero, $zero
.L800F6D24:
/* 901D4 800F6D24 00021023 */  negu      $v0, $v0
/* 901D8 800F6D28 3042FFFF */  andi      $v0, $v0, 0xffff
/* 901DC 800F6D2C 0803DC12 */  j         .L800F7048
/* 901E0 800F6D30 00821025 */   or       $v0, $a0, $v0
.L800F6D34:
/* 901E4 800F6D34 8D840000 */  lw        $a0, ($t4)
/* 901E8 800F6D38 24820008 */  addiu     $v0, $a0, 8
/* 901EC 800F6D3C AD820000 */  sw        $v0, ($t4)
/* 901F0 800F6D40 8FB901F8 */  lw        $t9, 0x1f8($sp)
/* 901F4 800F6D44 8FAE0204 */  lw        $t6, 0x204($sp)
/* 901F8 800F6D48 032E1021 */  addu      $v0, $t9, $t6
/* 901FC 800F6D4C 00021480 */  sll       $v0, $v0, 0x12
/* 90200 800F6D50 00021403 */  sra       $v0, $v0, 0x10
/* 90204 800F6D54 18400005 */  blez      $v0, .L800F6D6C
/* 90208 800F6D58 30420FFF */   andi     $v0, $v0, 0xfff
/* 9020C 800F6D5C 00021300 */  sll       $v0, $v0, 0xc
/* 90210 800F6D60 3C03E400 */  lui       $v1, 0xe400
/* 90214 800F6D64 0803DB5C */  j         .L800F6D70
/* 90218 800F6D68 00431025 */   or       $v0, $v0, $v1
.L800F6D6C:
/* 9021C 800F6D6C 3C02E400 */  lui       $v0, 0xe400
.L800F6D70:
/* 90220 800F6D70 AC820000 */  sw        $v0, ($a0)
/* 90224 800F6D74 8FAF01A0 */  lw        $t7, 0x1a0($sp)
/* 90228 800F6D78 19E00002 */  blez      $t7, .L800F6D84
/* 9022C 800F6D7C 00561025 */   or       $v0, $v0, $s6
/* 90230 800F6D80 AC820000 */  sw        $v0, ($a0)
.L800F6D84:
/* 90234 800F6D84 1A200003 */  blez      $s1, .L800F6D94
/* 90238 800F6D88 0000182D */   daddu    $v1, $zero, $zero
/* 9023C 800F6D8C 8FB20160 */  lw        $s2, 0x160($sp)
/* 90240 800F6D90 00121B00 */  sll       $v1, $s2, 0xc
.L800F6D94:
/* 90244 800F6D94 AC830004 */  sw        $v1, 4($a0)
/* 90248 800F6D98 8FB901FC */  lw        $t9, 0x1fc($sp)
/* 9024C 800F6D9C 00191480 */  sll       $v0, $t9, 0x12
/* 90250 800F6DA0 00021403 */  sra       $v0, $v0, 0x10
/* 90254 800F6DA4 18400003 */  blez      $v0, .L800F6DB4
/* 90258 800F6DA8 30420FFF */   andi     $v0, $v0, 0xfff
/* 9025C 800F6DAC 00621025 */  or        $v0, $v1, $v0
/* 90260 800F6DB0 AC820004 */  sw        $v0, 4($a0)
.L800F6DB4:
/* 90264 800F6DB4 8D820000 */  lw        $v0, ($t4)
/* 90268 800F6DB8 0040182D */  daddu     $v1, $v0, $zero
/* 9026C 800F6DBC 24420008 */  addiu     $v0, $v0, 8
/* 90270 800F6DC0 AD820000 */  sw        $v0, ($t4)
/* 90274 800F6DC4 3C02E100 */  lui       $v0, 0xe100
/* 90278 800F6DC8 AC620000 */  sw        $v0, ($v1)
/* 9027C 800F6DCC 06210009 */  bgez      $s1, .L800F6DF4
/* 90280 800F6DD0 24630004 */   addiu    $v1, $v1, 4
/* 90284 800F6DD4 8FAE016C */  lw        $t6, 0x16c($sp)
/* 90288 800F6DD8 000E11C3 */  sra       $v0, $t6, 7
/* 9028C 800F6DDC 5C400001 */  bgtzl     $v0, .L800F6DE4
/* 90290 800F6DE0 0000102D */   daddu    $v0, $zero, $zero
.L800F6DE4:
/* 90294 800F6DE4 8FAF01A4 */  lw        $t7, 0x1a4($sp)
/* 90298 800F6DE8 01E21023 */  subu      $v0, $t7, $v0
/* 9029C 800F6DEC 0803DB7F */  j         .L800F6DFC
/* 902A0 800F6DF0 00022400 */   sll      $a0, $v0, 0x10
.L800F6DF4:
/* 902A4 800F6DF4 8FB20170 */  lw        $s2, 0x170($sp)
/* 902A8 800F6DF8 00122400 */  sll       $a0, $s2, 0x10
.L800F6DFC:
/* 902AC 800F6DFC AC640000 */  sw        $a0, ($v1)
/* 902B0 800F6E00 8FB901FC */  lw        $t9, 0x1fc($sp)
/* 902B4 800F6E04 00191080 */  sll       $v0, $t9, 2
/* 902B8 800F6E08 04430091 */  bgezl     $v0, .L800F7050
/* 902BC 800F6E0C 3C040400 */   lui      $a0, 0x400
/* 902C0 800F6E10 00191480 */  sll       $v0, $t9, 0x12
/* 902C4 800F6E14 00021343 */  sra       $v0, $v0, 0xd
/* 902C8 800F6E18 5C400001 */  bgtzl     $v0, .L800F6E20
/* 902CC 800F6E1C 0000102D */   daddu    $v0, $zero, $zero
.L800F6E20:
/* 902D0 800F6E20 00021023 */  negu      $v0, $v0
/* 902D4 800F6E24 3042FFFF */  andi      $v0, $v0, 0xffff
/* 902D8 800F6E28 0803DC12 */  j         .L800F7048
/* 902DC 800F6E2C 00821025 */   or       $v0, $a0, $v0
.L800F6E30:
/* 902E0 800F6E30 8D840000 */  lw        $a0, ($t4)
/* 902E4 800F6E34 24820008 */  addiu     $v0, $a0, 8
/* 902E8 800F6E38 1A200005 */  blez      $s1, .L800F6E50
/* 902EC 800F6E3C AD820000 */   sw       $v0, ($t4)
/* 902F0 800F6E40 8FAE0164 */  lw        $t6, 0x164($sp)
/* 902F4 800F6E44 3C02E400 */  lui       $v0, 0xe400
/* 902F8 800F6E48 0803DB95 */  j         .L800F6E54
/* 902FC 800F6E4C 01C21825 */   or       $v1, $t6, $v0
.L800F6E50:
/* 90300 800F6E50 3C03E400 */  lui       $v1, 0xe400
.L800F6E54:
/* 90304 800F6E54 AC830000 */  sw        $v1, ($a0)
/* 90308 800F6E58 8FAF01FC */  lw        $t7, 0x1fc($sp)
/* 9030C 800F6E5C 8FB20208 */  lw        $s2, 0x208($sp)
/* 90310 800F6E60 01F21021 */  addu      $v0, $t7, $s2
/* 90314 800F6E64 00021480 */  sll       $v0, $v0, 0x12
/* 90318 800F6E68 00021403 */  sra       $v0, $v0, 0x10
/* 9031C 800F6E6C 18400003 */  blez      $v0, .L800F6E7C
/* 90320 800F6E70 30420FFF */   andi     $v0, $v0, 0xfff
/* 90324 800F6E74 00621025 */  or        $v0, $v1, $v0
/* 90328 800F6E78 AC820000 */  sw        $v0, ($a0)
.L800F6E7C:
/* 9032C 800F6E7C 8FB901F8 */  lw        $t9, 0x1f8($sp)
/* 90330 800F6E80 00191480 */  sll       $v0, $t9, 0x12
/* 90334 800F6E84 00021403 */  sra       $v0, $v0, 0x10
/* 90338 800F6E88 18400004 */  blez      $v0, .L800F6E9C
/* 9033C 800F6E8C 24830004 */   addiu    $v1, $a0, 4
/* 90340 800F6E90 30420FFF */  andi      $v0, $v0, 0xfff
/* 90344 800F6E94 0803DBA8 */  j         .L800F6EA0
/* 90348 800F6E98 00021300 */   sll      $v0, $v0, 0xc
.L800F6E9C:
/* 9034C 800F6E9C 0000102D */  daddu     $v0, $zero, $zero
.L800F6EA0:
/* 90350 800F6EA0 AC620000 */  sw        $v0, ($v1)
/* 90354 800F6EA4 8FAE01A0 */  lw        $t6, 0x1a0($sp)
/* 90358 800F6EA8 19C00002 */  blez      $t6, .L800F6EB4
/* 9035C 800F6EAC 00561025 */   or       $v0, $v0, $s6
/* 90360 800F6EB0 AC620000 */  sw        $v0, ($v1)
.L800F6EB4:
/* 90364 800F6EB4 8D820000 */  lw        $v0, ($t4)
/* 90368 800F6EB8 0040182D */  daddu     $v1, $v0, $zero
/* 9036C 800F6EBC 24420008 */  addiu     $v0, $v0, 8
/* 90370 800F6EC0 AD820000 */  sw        $v0, ($t4)
/* 90374 800F6EC4 3C02E100 */  lui       $v0, 0xe100
/* 90378 800F6EC8 AC620000 */  sw        $v0, ($v1)
/* 9037C 800F6ECC 8FAF01F8 */  lw        $t7, 0x1f8($sp)
/* 90380 800F6ED0 000F1480 */  sll       $v0, $t7, 0x12
/* 90384 800F6ED4 00021403 */  sra       $v0, $v0, 0x10
/* 90388 800F6ED8 04410007 */  bgez      $v0, .L800F6EF8
/* 9038C 800F6EDC 24630004 */   addiu    $v1, $v1, 4
/* 90390 800F6EE0 000210C0 */  sll       $v0, $v0, 3
/* 90394 800F6EE4 5C400001 */  bgtzl     $v0, .L800F6EEC
/* 90398 800F6EE8 0000102D */   daddu    $v0, $zero, $zero
.L800F6EEC:
/* 9039C 800F6EEC 00021023 */  negu      $v0, $v0
/* 903A0 800F6EF0 0803DBBF */  j         .L800F6EFC
/* 903A4 800F6EF4 00022400 */   sll      $a0, $v0, 0x10
.L800F6EF8:
/* 903A8 800F6EF8 0000202D */  daddu     $a0, $zero, $zero
.L800F6EFC:
/* 903AC 800F6EFC 8FB20168 */  lw        $s2, 0x168($sp)
/* 903B0 800F6F00 00121080 */  sll       $v0, $s2, 2
/* 903B4 800F6F04 0441000A */  bgez      $v0, .L800F6F30
/* 903B8 800F6F08 00000000 */   nop      
/* 903BC 800F6F0C 8FB90174 */  lw        $t9, 0x174($sp)
/* 903C0 800F6F10 001911C3 */  sra       $v0, $t9, 7
/* 903C4 800F6F14 5C400001 */  bgtzl     $v0, .L800F6F1C
/* 903C8 800F6F18 0000102D */   daddu    $v0, $zero, $zero
.L800F6F1C:
/* 903CC 800F6F1C 8FAE01A8 */  lw        $t6, 0x1a8($sp)
/* 903D0 800F6F20 01C21023 */  subu      $v0, $t6, $v0
/* 903D4 800F6F24 3042FFFF */  andi      $v0, $v0, 0xffff
/* 903D8 800F6F28 0803DC12 */  j         .L800F7048
/* 903DC 800F6F2C 00821025 */   or       $v0, $a0, $v0
.L800F6F30:
/* 903E0 800F6F30 8FAF0178 */  lw        $t7, 0x178($sp)
/* 903E4 800F6F34 0803DC12 */  j         .L800F7048
/* 903E8 800F6F38 008F1025 */   or       $v0, $a0, $t7
.L800F6F3C:
/* 903EC 800F6F3C 8D840000 */  lw        $a0, ($t4)
/* 903F0 800F6F40 24820008 */  addiu     $v0, $a0, 8
/* 903F4 800F6F44 AD820000 */  sw        $v0, ($t4)
/* 903F8 800F6F48 8FB201F8 */  lw        $s2, 0x1f8($sp)
/* 903FC 800F6F4C 8FB90204 */  lw        $t9, 0x204($sp)
/* 90400 800F6F50 02591021 */  addu      $v0, $s2, $t9
/* 90404 800F6F54 00021480 */  sll       $v0, $v0, 0x12
/* 90408 800F6F58 00021403 */  sra       $v0, $v0, 0x10
/* 9040C 800F6F5C 18400005 */  blez      $v0, .L800F6F74
/* 90410 800F6F60 30420FFF */   andi     $v0, $v0, 0xfff
/* 90414 800F6F64 00021300 */  sll       $v0, $v0, 0xc
/* 90418 800F6F68 3C03E400 */  lui       $v1, 0xe400
/* 9041C 800F6F6C 0803DBDE */  j         .L800F6F78
/* 90420 800F6F70 00431825 */   or       $v1, $v0, $v1
.L800F6F74:
/* 90424 800F6F74 3C03E400 */  lui       $v1, 0xe400
.L800F6F78:
/* 90428 800F6F78 AC830000 */  sw        $v1, ($a0)
/* 9042C 800F6F7C 8FAE01FC */  lw        $t6, 0x1fc($sp)
/* 90430 800F6F80 8FAF0208 */  lw        $t7, 0x208($sp)
/* 90434 800F6F84 01CF1021 */  addu      $v0, $t6, $t7
/* 90438 800F6F88 00021480 */  sll       $v0, $v0, 0x12
/* 9043C 800F6F8C 00021403 */  sra       $v0, $v0, 0x10
/* 90440 800F6F90 18400003 */  blez      $v0, .L800F6FA0
/* 90444 800F6F94 30420FFF */   andi     $v0, $v0, 0xfff
/* 90448 800F6F98 00621025 */  or        $v0, $v1, $v0
/* 9044C 800F6F9C AC820000 */  sw        $v0, ($a0)
.L800F6FA0:
/* 90450 800F6FA0 1A200003 */  blez      $s1, .L800F6FB0
/* 90454 800F6FA4 0000102D */   daddu    $v0, $zero, $zero
/* 90458 800F6FA8 8FB20160 */  lw        $s2, 0x160($sp)
/* 9045C 800F6FAC 00121300 */  sll       $v0, $s2, 0xc
.L800F6FB0:
/* 90460 800F6FB0 AC820004 */  sw        $v0, 4($a0)
/* 90464 800F6FB4 8FB901A0 */  lw        $t9, 0x1a0($sp)
/* 90468 800F6FB8 1B200002 */  blez      $t9, .L800F6FC4
/* 9046C 800F6FBC 00561025 */   or       $v0, $v0, $s6
/* 90470 800F6FC0 AC820004 */  sw        $v0, 4($a0)
.L800F6FC4:
/* 90474 800F6FC4 8D820000 */  lw        $v0, ($t4)
/* 90478 800F6FC8 0040182D */  daddu     $v1, $v0, $zero
/* 9047C 800F6FCC 24420008 */  addiu     $v0, $v0, 8
/* 90480 800F6FD0 AD820000 */  sw        $v0, ($t4)
/* 90484 800F6FD4 3C02E100 */  lui       $v0, 0xe100
/* 90488 800F6FD8 AC620000 */  sw        $v0, ($v1)
/* 9048C 800F6FDC 06210009 */  bgez      $s1, .L800F7004
/* 90490 800F6FE0 24630004 */   addiu    $v1, $v1, 4
/* 90494 800F6FE4 8FAE016C */  lw        $t6, 0x16c($sp)
/* 90498 800F6FE8 000E11C3 */  sra       $v0, $t6, 7
/* 9049C 800F6FEC 5C400001 */  bgtzl     $v0, .L800F6FF4
/* 904A0 800F6FF0 0000102D */   daddu    $v0, $zero, $zero
.L800F6FF4:
/* 904A4 800F6FF4 8FAF01A4 */  lw        $t7, 0x1a4($sp)
/* 904A8 800F6FF8 01E21023 */  subu      $v0, $t7, $v0
/* 904AC 800F6FFC 0803DC03 */  j         .L800F700C
/* 904B0 800F7000 00022400 */   sll      $a0, $v0, 0x10
.L800F7004:
/* 904B4 800F7004 8FB20170 */  lw        $s2, 0x170($sp)
/* 904B8 800F7008 00122400 */  sll       $a0, $s2, 0x10
.L800F700C:
/* 904BC 800F700C 8FB90168 */  lw        $t9, 0x168($sp)
/* 904C0 800F7010 00191080 */  sll       $v0, $t9, 2
/* 904C4 800F7014 0441000A */  bgez      $v0, .L800F7040
/* 904C8 800F7018 00000000 */   nop      
/* 904CC 800F701C 8FAE0174 */  lw        $t6, 0x174($sp)
/* 904D0 800F7020 000E11C3 */  sra       $v0, $t6, 7
/* 904D4 800F7024 5C400001 */  bgtzl     $v0, .L800F702C
/* 904D8 800F7028 0000102D */   daddu    $v0, $zero, $zero
.L800F702C:
/* 904DC 800F702C 8FAF01A8 */  lw        $t7, 0x1a8($sp)
/* 904E0 800F7030 01E21023 */  subu      $v0, $t7, $v0
/* 904E4 800F7034 3042FFFF */  andi      $v0, $v0, 0xffff
/* 904E8 800F7038 0803DC12 */  j         .L800F7048
/* 904EC 800F703C 00821025 */   or       $v0, $a0, $v0
.L800F7040:
/* 904F0 800F7040 8FB20178 */  lw        $s2, 0x178($sp)
/* 904F4 800F7044 00921025 */  or        $v0, $a0, $s2
.L800F7048:
/* 904F8 800F7048 AC620000 */  sw        $v0, ($v1)
/* 904FC 800F704C 3C040400 */  lui       $a0, 0x400
.L800F7050:
/* 90500 800F7050 8D820000 */  lw        $v0, ($t4)
/* 90504 800F7054 34840400 */  ori       $a0, $a0, 0x400
/* 90508 800F7058 0040182D */  daddu     $v1, $v0, $zero
/* 9050C 800F705C 24420008 */  addiu     $v0, $v0, 8
/* 90510 800F7060 AD820000 */  sw        $v0, ($t4)
/* 90514 800F7064 3C02F100 */  lui       $v0, %hi(D_F1000008)
/* 90518 800F7068 AC620000 */  sw        $v0, ($v1)
/* 9051C 800F706C AC640004 */  sw        $a0, 4($v1)
.L800F7070:
/* 90520 800F7070 8D820000 */  lw        $v0, ($t4)
/* 90524 800F7074 25AD0001 */  addiu     $t5, $t5, 1
/* 90528 800F7078 0040182D */  daddu     $v1, $v0, $zero
/* 9052C 800F707C 24420008 */  addiu     $v0, $v0, %lo(D_F1000008)
/* 90530 800F7080 3C19E700 */  lui       $t9, 0xe700
/* 90534 800F7084 AD820000 */  sw        $v0, ($t4)
/* 90538 800F7088 29A20004 */  slti      $v0, $t5, 4
/* 9053C 800F708C AC790000 */  sw        $t9, ($v1)
/* 90540 800F7090 1440FC7B */  bnez      $v0, .L800F6280
/* 90544 800F7094 AC600004 */   sw       $zero, 4($v1)
/* 90548 800F7098 0803DCC4 */  j         .L800F7310
/* 9054C 800F709C 3C19E300 */   lui      $t9, 0xe300
.L800F70A0:
/* 90550 800F70A0 8FAE0138 */  lw        $t6, 0x138($sp)
/* 90554 800F70A4 11C0009A */  beqz      $t6, .L800F7310
/* 90558 800F70A8 3C19E300 */   lui      $t9, 0xe300
/* 9055C 800F70AC 13C00036 */  beqz      $fp, .L800F7188
/* 90560 800F70B0 3C070100 */   lui      $a3, 0x100
/* 90564 800F70B4 34E74008 */  ori       $a3, $a3, 0x4008
/* 90568 800F70B8 3C080600 */  lui       $t0, 0x600
/* 9056C 800F70BC 3C06800A */  lui       $a2, %hi(D_8009A66C)
/* 90570 800F70C0 24C6A66C */  addiu     $a2, $a2, %lo(D_8009A66C)
/* 90574 800F70C4 8FAF0204 */  lw        $t7, 0x204($sp)
/* 90578 800F70C8 8CC50000 */  lw        $a1, ($a2)
/* 9057C 800F70CC 000F2023 */  negu      $a0, $t7
/* 90580 800F70D0 000417C2 */  srl       $v0, $a0, 0x1f
/* 90584 800F70D4 00822021 */  addu      $a0, $a0, $v0
/* 90588 800F70D8 00042043 */  sra       $a0, $a0, 1
/* 9058C 800F70DC A7C40000 */  sh        $a0, ($fp)
/* 90590 800F70E0 8FB20208 */  lw        $s2, 0x208($sp)
/* 90594 800F70E4 35080602 */  ori       $t0, $t0, 0x602
/* 90598 800F70E8 A7C00004 */  sh        $zero, 4($fp)
/* 9059C 800F70EC A7C00014 */  sh        $zero, 0x14($fp)
/* 905A0 800F70F0 A7C40020 */  sh        $a0, 0x20($fp)
/* 905A4 800F70F4 A7C00024 */  sh        $zero, 0x24($fp)
/* 905A8 800F70F8 A7C00034 */  sh        $zero, 0x34($fp)
/* 905AC 800F70FC A7C00008 */  sh        $zero, 8($fp)
/* 905B0 800F7100 A7C0000A */  sh        $zero, 0xa($fp)
/* 905B4 800F7104 A7C0001A */  sh        $zero, 0x1a($fp)
/* 905B8 800F7108 A7C00028 */  sh        $zero, 0x28($fp)
/* 905BC 800F710C 00121023 */  negu      $v0, $s2
/* 905C0 800F7110 00021FC2 */  srl       $v1, $v0, 0x1f
/* 905C4 800F7114 00431021 */  addu      $v0, $v0, $v1
/* 905C8 800F7118 00021043 */  sra       $v0, $v0, 1
/* 905CC 800F711C 008F1821 */  addu      $v1, $a0, $t7
/* 905D0 800F7120 A7C20002 */  sh        $v0, 2($fp)
/* 905D4 800F7124 A7C20012 */  sh        $v0, 0x12($fp)
/* 905D8 800F7128 001217C2 */  srl       $v0, $s2, 0x1f
/* 905DC 800F712C 02421021 */  addu      $v0, $s2, $v0
/* 905E0 800F7130 00021043 */  sra       $v0, $v0, 1
/* 905E4 800F7134 A7C30010 */  sh        $v1, 0x10($fp)
/* 905E8 800F7138 A7C30030 */  sh        $v1, 0x30($fp)
/* 905EC 800F713C 000F1940 */  sll       $v1, $t7, 5
/* 905F0 800F7140 A7C20022 */  sh        $v0, 0x22($fp)
/* 905F4 800F7144 A7C20032 */  sh        $v0, 0x32($fp)
/* 905F8 800F7148 00121140 */  sll       $v0, $s2, 5
/* 905FC 800F714C A7C2002A */  sh        $v0, 0x2a($fp)
/* 90600 800F7150 A7C2003A */  sh        $v0, 0x3a($fp)
/* 90604 800F7154 00A0102D */  daddu     $v0, $a1, $zero
/* 90608 800F7158 24A50008 */  addiu     $a1, $a1, 8
/* 9060C 800F715C A7C30018 */  sh        $v1, 0x18($fp)
/* 90610 800F7160 A7C30038 */  sh        $v1, 0x38($fp)
/* 90614 800F7164 ACC50000 */  sw        $a1, ($a2)
/* 90618 800F7168 AC470000 */  sw        $a3, ($v0)
/* 9061C 800F716C AC5E0004 */  sw        $fp, 4($v0)
/* 90620 800F7170 24A20008 */  addiu     $v0, $a1, 8
/* 90624 800F7174 ACC20000 */  sw        $v0, ($a2)
/* 90628 800F7178 24020406 */  addiu     $v0, $zero, 0x406
/* 9062C 800F717C ACA80000 */  sw        $t0, ($a1)
/* 90630 800F7180 0803DCBA */  j         .L800F72E8
/* 90634 800F7184 ACA20004 */   sw       $v0, 4($a1)
.L800F7188:
/* 90638 800F7188 3C03800A */  lui       $v1, %hi(D_8009A66C)
/* 9063C 800F718C 2463A66C */  addiu     $v1, $v1, %lo(D_8009A66C)
/* 90640 800F7190 8C640000 */  lw        $a0, ($v1)
/* 90644 800F7194 24820008 */  addiu     $v0, $a0, 8
/* 90648 800F7198 AC620000 */  sw        $v0, ($v1)
/* 9064C 800F719C 8FB901F8 */  lw        $t9, 0x1f8($sp)
/* 90650 800F71A0 8FAE0204 */  lw        $t6, 0x204($sp)
/* 90654 800F71A4 032E1021 */  addu      $v0, $t9, $t6
/* 90658 800F71A8 00021480 */  sll       $v0, $v0, 0x12
/* 9065C 800F71AC 00021403 */  sra       $v0, $v0, 0x10
/* 90660 800F71B0 18400005 */  blez      $v0, .L800F71C8
/* 90664 800F71B4 30420FFF */   andi     $v0, $v0, 0xfff
/* 90668 800F71B8 00021300 */  sll       $v0, $v0, 0xc
/* 9066C 800F71BC 3C03E400 */  lui       $v1, 0xe400
/* 90670 800F71C0 0803DC73 */  j         .L800F71CC
/* 90674 800F71C4 00431825 */   or       $v1, $v0, $v1
.L800F71C8:
/* 90678 800F71C8 3C03E400 */  lui       $v1, 0xe400
.L800F71CC:
/* 9067C 800F71CC AC830000 */  sw        $v1, ($a0)
/* 90680 800F71D0 8FAF01FC */  lw        $t7, 0x1fc($sp)
/* 90684 800F71D4 8FB20208 */  lw        $s2, 0x208($sp)
/* 90688 800F71D8 01F21021 */  addu      $v0, $t7, $s2
/* 9068C 800F71DC 00021480 */  sll       $v0, $v0, 0x12
/* 90690 800F71E0 00021403 */  sra       $v0, $v0, 0x10
/* 90694 800F71E4 18400003 */  blez      $v0, .L800F71F4
/* 90698 800F71E8 30420FFF */   andi     $v0, $v0, 0xfff
/* 9069C 800F71EC 00621025 */  or        $v0, $v1, $v0
/* 906A0 800F71F0 AC820000 */  sw        $v0, ($a0)
.L800F71F4:
/* 906A4 800F71F4 8FB901F8 */  lw        $t9, 0x1f8($sp)
/* 906A8 800F71F8 00191480 */  sll       $v0, $t9, 0x12
/* 906AC 800F71FC 00021403 */  sra       $v0, $v0, 0x10
/* 906B0 800F7200 18400004 */  blez      $v0, .L800F7214
/* 906B4 800F7204 24830004 */   addiu    $v1, $a0, 4
/* 906B8 800F7208 30420FFF */  andi      $v0, $v0, 0xfff
/* 906BC 800F720C 0803DC86 */  j         .L800F7218
/* 906C0 800F7210 00022300 */   sll      $a0, $v0, 0xc
.L800F7214:
/* 906C4 800F7214 0000202D */  daddu     $a0, $zero, $zero
.L800F7218:
/* 906C8 800F7218 AC640000 */  sw        $a0, ($v1)
/* 906CC 800F721C 8FAE01FC */  lw        $t6, 0x1fc($sp)
/* 906D0 800F7220 000E1480 */  sll       $v0, $t6, 0x12
/* 906D4 800F7224 00021403 */  sra       $v0, $v0, 0x10
/* 906D8 800F7228 18400003 */  blez      $v0, .L800F7238
/* 906DC 800F722C 30420FFF */   andi     $v0, $v0, 0xfff
/* 906E0 800F7230 00821025 */  or        $v0, $a0, $v0
/* 906E4 800F7234 AC620000 */  sw        $v0, ($v1)
.L800F7238:
/* 906E8 800F7238 3C03800A */  lui       $v1, %hi(D_8009A66C)
/* 906EC 800F723C 2463A66C */  addiu     $v1, $v1, %lo(D_8009A66C)
/* 906F0 800F7240 8C620000 */  lw        $v0, ($v1)
/* 906F4 800F7244 0040202D */  daddu     $a0, $v0, $zero
/* 906F8 800F7248 24420008 */  addiu     $v0, $v0, 8
/* 906FC 800F724C AC620000 */  sw        $v0, ($v1)
/* 90700 800F7250 3C02E100 */  lui       $v0, 0xe100
/* 90704 800F7254 AC820000 */  sw        $v0, ($a0)
/* 90708 800F7258 8FAF01F8 */  lw        $t7, 0x1f8($sp)
/* 9070C 800F725C 000F1480 */  sll       $v0, $t7, 0x12
/* 90710 800F7260 00021403 */  sra       $v0, $v0, 0x10
/* 90714 800F7264 04410007 */  bgez      $v0, .L800F7284
/* 90718 800F7268 24840004 */   addiu    $a0, $a0, 4
/* 9071C 800F726C 000210C0 */  sll       $v0, $v0, 3
/* 90720 800F7270 5C400001 */  bgtzl     $v0, .L800F7278
/* 90724 800F7274 0000102D */   daddu    $v0, $zero, $zero
.L800F7278:
/* 90728 800F7278 00021023 */  negu      $v0, $v0
/* 9072C 800F727C 0803DCA2 */  j         .L800F7288
/* 90730 800F7280 00021C00 */   sll      $v1, $v0, 0x10
.L800F7284:
/* 90734 800F7284 0000182D */  daddu     $v1, $zero, $zero
.L800F7288:
/* 90738 800F7288 AC830000 */  sw        $v1, ($a0)
/* 9073C 800F728C 8FB201FC */  lw        $s2, 0x1fc($sp)
/* 90740 800F7290 00121080 */  sll       $v0, $s2, 2
/* 90744 800F7294 0441000A */  bgez      $v0, .L800F72C0
/* 90748 800F7298 3C050400 */   lui      $a1, 0x400
/* 9074C 800F729C 00121480 */  sll       $v0, $s2, 0x12
/* 90750 800F72A0 00021343 */  sra       $v0, $v0, 0xd
/* 90754 800F72A4 5C400001 */  bgtzl     $v0, .L800F72AC
/* 90758 800F72A8 0000102D */   daddu    $v0, $zero, $zero
.L800F72AC:
/* 9075C 800F72AC 00021023 */  negu      $v0, $v0
/* 90760 800F72B0 3042FFFF */  andi      $v0, $v0, 0xffff
/* 90764 800F72B4 00621025 */  or        $v0, $v1, $v0
/* 90768 800F72B8 AC820000 */  sw        $v0, ($a0)
/* 9076C 800F72BC 3C050400 */  lui       $a1, 0x400
.L800F72C0:
/* 90770 800F72C0 3C03800A */  lui       $v1, %hi(D_8009A66C)
/* 90774 800F72C4 2463A66C */  addiu     $v1, $v1, %lo(D_8009A66C)
/* 90778 800F72C8 8C620000 */  lw        $v0, ($v1)
/* 9077C 800F72CC 34A50400 */  ori       $a1, $a1, 0x400
/* 90780 800F72D0 0040202D */  daddu     $a0, $v0, $zero
/* 90784 800F72D4 24420008 */  addiu     $v0, $v0, 8
/* 90788 800F72D8 AC620000 */  sw        $v0, ($v1)
/* 9078C 800F72DC 3C02F100 */  lui       $v0, %hi(D_F1000008)
/* 90790 800F72E0 AC820000 */  sw        $v0, ($a0)
/* 90794 800F72E4 AC850004 */  sw        $a1, 4($a0)
.L800F72E8:
/* 90798 800F72E8 3C03800A */  lui       $v1, %hi(D_8009A66C)
/* 9079C 800F72EC 2463A66C */  addiu     $v1, $v1, %lo(D_8009A66C)
/* 907A0 800F72F0 8C620000 */  lw        $v0, ($v1)
/* 907A4 800F72F4 0040202D */  daddu     $a0, $v0, $zero
/* 907A8 800F72F8 24420008 */  addiu     $v0, $v0, %lo(D_F1000008)
/* 907AC 800F72FC AC620000 */  sw        $v0, ($v1)
/* 907B0 800F7300 3C02E700 */  lui       $v0, 0xe700
/* 907B4 800F7304 AC820000 */  sw        $v0, ($a0)
/* 907B8 800F7308 AC800004 */  sw        $zero, 4($a0)
/* 907BC 800F730C 3C19E300 */  lui       $t9, 0xe300
.L800F7310:
/* 907C0 800F7310 37390C00 */  ori       $t9, $t9, 0xc00
/* 907C4 800F7314 3C0EE300 */  lui       $t6, 0xe300
/* 907C8 800F7318 3C18800A */  lui       $t8, %hi(D_8009A66C)
/* 907CC 800F731C 2718A66C */  addiu     $t8, $t8, %lo(D_8009A66C)
/* 907D0 800F7320 AFB9017C */  sw        $t9, 0x17c($sp)
/* 907D4 800F7324 8F020000 */  lw        $v0, ($t8)
/* 907D8 800F7328 35CE0A01 */  ori       $t6, $t6, 0xa01
/* 907DC 800F732C AFAE0180 */  sw        $t6, 0x180($sp)
/* 907E0 800F7330 0040182D */  daddu     $v1, $v0, $zero
/* 907E4 800F7334 24420008 */  addiu     $v0, $v0, 8
/* 907E8 800F7338 AF020000 */  sw        $v0, ($t8)
/* 907EC 800F733C AC790000 */  sw        $t9, ($v1)
/* 907F0 800F7340 AC600004 */  sw        $zero, 4($v1)
/* 907F4 800F7344 24430008 */  addiu     $v1, $v0, 8
/* 907F8 800F7348 AF030000 */  sw        $v1, ($t8)
/* 907FC 800F734C AC4E0000 */  sw        $t6, ($v0)
/* 90800 800F7350 AC400004 */  sw        $zero, 4($v0)
/* 90804 800F7354 8FAF0228 */  lw        $t7, 0x228($sp)
/* 90808 800F7358 11E001CC */  beqz      $t7, .L800F7A8C
/* 9080C 800F735C 00000000 */   nop      
/* 90810 800F7360 13C001BE */  beqz      $fp, .L800F7A5C
/* 90814 800F7364 00000000 */   nop      
/* 90818 800F7368 8FAE0204 */  lw        $t6, 0x204($sp)
/* 9081C 800F736C 8FAF0208 */  lw        $t7, 0x208($sp)
/* 90820 800F7370 01CF0018 */  mult      $t6, $t7
/* 90824 800F7374 AFB80198 */  sw        $t8, 0x198($sp)
/* 90828 800F7378 00009012 */  mflo      $s2
/* 9082C 800F737C 0C0475F9 */  jal       func_8011D7E4
/* 90830 800F7380 00122040 */   sll      $a0, $s2, 1
/* 90834 800F7384 0040402D */  daddu     $t0, $v0, $zero
/* 90838 800F7388 8FB80198 */  lw        $t8, 0x198($sp)
/* 9083C 800F738C 110001BF */  beqz      $t0, .L800F7A8C
/* 90840 800F7390 3C17E200 */   lui      $s7, 0xe200
/* 90844 800F7394 36F7001C */  ori       $s7, $s7, 0x1c
/* 90848 800F7398 3C0BED00 */  lui       $t3, 0xed00
/* 9084C 800F739C 356B4004 */  ori       $t3, $t3, 0x4004
/* 90850 800F73A0 3C190001 */  lui       $t9, 1
/* 90854 800F73A4 37391630 */  ori       $t9, $t9, 0x1630
/* 90858 800F73A8 3C02FF10 */  lui       $v0, 0xff10
/* 9085C 800F73AC 3C168000 */  lui       $s6, 0x8000
/* 90860 800F73B0 01164021 */  addu      $t0, $t0, $s6
/* 90864 800F73B4 3C15ED00 */  lui       $s5, 0xed00
/* 90868 800F73B8 8FA4022C */  lw        $a0, 0x22c($sp)
/* 9086C 800F73BC 8FA70204 */  lw        $a3, 0x204($sp)
/* 90870 800F73C0 8F090000 */  lw        $t1, ($t8)
/* 90874 800F73C4 3C11E700 */  lui       $s1, 0xe700
/* 90878 800F73C8 AFB90190 */  sw        $t9, 0x190($sp)
/* 9087C 800F73CC 0120182D */  daddu     $v1, $t1, $zero
/* 90880 800F73D0 25290008 */  addiu     $t1, $t1, 8
/* 90884 800F73D4 AF090000 */  sw        $t1, ($t8)
/* 90888 800F73D8 8FAE0204 */  lw        $t6, 0x204($sp)
/* 9088C 800F73DC 3C014080 */  lui       $at, 0x4080
/* 90890 800F73E0 44812000 */  mtc1      $at, $f4
/* 90894 800F73E4 25CEFFFF */  addiu     $t6, $t6, -1
/* 90898 800F73E8 31CF0FFF */  andi      $t7, $t6, 0xfff
/* 9089C 800F73EC 01E21025 */  or        $v0, $t7, $v0
/* 908A0 800F73F0 AFAE0184 */  sw        $t6, 0x184($sp)
/* 908A4 800F73F4 AFAF0188 */  sw        $t7, 0x188($sp)
/* 908A8 800F73F8 AC620000 */  sw        $v0, ($v1)
/* 908AC 800F73FC 25220008 */  addiu     $v0, $t1, 8
/* 908B0 800F7400 AFA8018C */  sw        $t0, 0x18c($sp)
/* 908B4 800F7404 AC680004 */  sw        $t0, 4($v1)
/* 908B8 800F7408 AF020000 */  sw        $v0, ($t8)
/* 908BC 800F740C 25220010 */  addiu     $v0, $t1, 0x10
/* 908C0 800F7410 AD350000 */  sw        $s5, ($t1)
/* 908C4 800F7414 AF020000 */  sw        $v0, ($t8)
/* 908C8 800F7418 8FB20180 */  lw        $s2, 0x180($sp)
/* 908CC 800F741C 3C020030 */  lui       $v0, 0x30
/* 908D0 800F7420 AD22000C */  sw        $v0, 0xc($t1)
/* 908D4 800F7424 25220018 */  addiu     $v0, $t1, 0x18
/* 908D8 800F7428 AD320008 */  sw        $s2, 8($t1)
/* 908DC 800F742C AF020000 */  sw        $v0, ($t8)
/* 908E0 800F7430 3C02F700 */  lui       $v0, 0xf700
/* 908E4 800F7434 AD220010 */  sw        $v0, 0x10($t1)
/* 908E8 800F7438 93B900F7 */  lbu       $t9, 0xf7($sp)
/* 908EC 800F743C 93AE00FF */  lbu       $t6, 0xff($sp)
/* 908F0 800F7440 93AF0107 */  lbu       $t7, 0x107($sp)
/* 908F4 800F7444 00191A00 */  sll       $v1, $t9, 8
/* 908F8 800F7448 3063F800 */  andi      $v1, $v1, 0xf800
/* 908FC 800F744C 000E10C0 */  sll       $v0, $t6, 3
/* 90900 800F7450 304207C0 */  andi      $v0, $v0, 0x7c0
/* 90904 800F7454 00621825 */  or        $v1, $v1, $v0
/* 90908 800F7458 000F1082 */  srl       $v0, $t7, 2
/* 9090C 800F745C 3042003E */  andi      $v0, $v0, 0x3e
/* 90910 800F7460 00621825 */  or        $v1, $v1, $v0
/* 90914 800F7464 00031400 */  sll       $v0, $v1, 0x10
/* 90918 800F7468 00431025 */  or        $v0, $v0, $v1
/* 9091C 800F746C AD220014 */  sw        $v0, 0x14($t1)
/* 90920 800F7470 25220020 */  addiu     $v0, $t1, 0x20
/* 90924 800F7474 AF020000 */  sw        $v0, ($t8)
/* 90928 800F7478 25220028 */  addiu     $v0, $t1, 0x28
/* 9092C 800F747C 3C03F600 */  lui       $v1, 0xf600
/* 90930 800F7480 AD370018 */  sw        $s7, 0x18($t1)
/* 90934 800F7484 AD20001C */  sw        $zero, 0x1c($t1)
/* 90938 800F7488 AF020000 */  sw        $v0, ($t8)
/* 9093C 800F748C 8FB20184 */  lw        $s2, 0x184($sp)
/* 90940 800F7490 8FB90208 */  lw        $t9, 0x208($sp)
/* 90944 800F7494 324803FF */  andi      $t0, $s2, 0x3ff
/* 90948 800F7498 00084380 */  sll       $t0, $t0, 0xe
/* 9094C 800F749C 272AFFFF */  addiu     $t2, $t9, -1
/* 90950 800F74A0 314203FF */  andi      $v0, $t2, 0x3ff
/* 90954 800F74A4 00021080 */  sll       $v0, $v0, 2
/* 90958 800F74A8 00431025 */  or        $v0, $v0, $v1
/* 9095C 800F74AC 01024025 */  or        $t0, $t0, $v0
/* 90960 800F74B0 25220030 */  addiu     $v0, $t1, 0x30
/* 90964 800F74B4 AD280020 */  sw        $t0, 0x20($t1)
/* 90968 800F74B8 AD200024 */  sw        $zero, 0x24($t1)
/* 9096C 800F74BC AF020000 */  sw        $v0, ($t8)
/* 90970 800F74C0 25220038 */  addiu     $v0, $t1, 0x38
/* 90974 800F74C4 AD310028 */  sw        $s1, 0x28($t1)
/* 90978 800F74C8 AD20002C */  sw        $zero, 0x2c($t1)
/* 9097C 800F74CC AF020000 */  sw        $v0, ($t8)
/* 90980 800F74D0 AD2B0030 */  sw        $t3, 0x30($t1)
/* 90984 800F74D4 C7A20204 */  lwc1      $f2, 0x204($sp)
/* 90988 800F74D8 468010A0 */  cvt.s.w   $f2, $f2
/* 9098C 800F74DC 25220040 */  addiu     $v0, $t1, 0x40
/* 90990 800F74E0 46041082 */  mul.s     $f2, $f2, $f4
/* 90994 800F74E4 00000000 */  nop       
/* 90998 800F74E8 AF020000 */  sw        $v0, ($t8)
/* 9099C 800F74EC 8FAE0180 */  lw        $t6, 0x180($sp)
/* 909A0 800F74F0 AD20003C */  sw        $zero, 0x3c($t1)
/* 909A4 800F74F4 AD2E0038 */  sw        $t6, 0x38($t1)
/* 909A8 800F74F8 C7A00208 */  lwc1      $f0, 0x208($sp)
/* 909AC 800F74FC 46800020 */  cvt.s.w   $f0, $f0
/* 909B0 800F7500 46040002 */  mul.s     $f0, $f0, $f4
/* 909B4 800F7504 00000000 */  nop       
/* 909B8 800F7508 4600118D */  trunc.w.s $f6, $f2
/* 909BC 800F750C 44033000 */  mfc1      $v1, $f6
/* 909C0 800F7510 00000000 */  nop       
/* 909C4 800F7514 30630FFF */  andi      $v1, $v1, 0xfff
/* 909C8 800F7518 00031B00 */  sll       $v1, $v1, 0xc
/* 909CC 800F751C C7A20184 */  lwc1      $f2, 0x184($sp)
/* 909D0 800F7520 468010A0 */  cvt.s.w   $f2, $f2
/* 909D4 800F7524 46041082 */  mul.s     $f2, $f2, $f4
/* 909D8 800F7528 00000000 */  nop       
/* 909DC 800F752C 4600018D */  trunc.w.s $f6, $f0
/* 909E0 800F7530 44023000 */  mfc1      $v0, $f6
/* 909E4 800F7534 00000000 */  nop       
/* 909E8 800F7538 30420FFF */  andi      $v0, $v0, 0xfff
/* 909EC 800F753C 00621825 */  or        $v1, $v1, $v0
/* 909F0 800F7540 448A0000 */  mtc1      $t2, $f0
/* 909F4 800F7544 00000000 */  nop       
/* 909F8 800F7548 46800020 */  cvt.s.w   $f0, $f0
/* 909FC 800F754C 46040002 */  mul.s     $f0, $f0, $f4
/* 90A00 800F7550 00000000 */  nop       
/* 90A04 800F7554 AD230004 */  sw        $v1, 4($t1)
/* 90A08 800F7558 4600118D */  trunc.w.s $f6, $f2
/* 90A0C 800F755C 44023000 */  mfc1      $v0, $f6
/* 90A10 800F7560 00000000 */  nop       
/* 90A14 800F7564 30420FFF */  andi      $v0, $v0, 0xfff
/* 90A18 800F7568 00021300 */  sll       $v0, $v0, 0xc
/* 90A1C 800F756C 4600018D */  trunc.w.s $f6, $f0
/* 90A20 800F7570 44033000 */  mfc1      $v1, $f6
/* 90A24 800F7574 00000000 */  nop       
/* 90A28 800F7578 30630FFF */  andi      $v1, $v1, 0xfff
/* 90A2C 800F757C 00431025 */  or        $v0, $v0, $v1
/* 90A30 800F7580 AD220034 */  sw        $v0, 0x34($t1)
/* 90A34 800F7584 93A200E7 */  lbu       $v0, 0xe7($sp)
/* 90A38 800F7588 8FAF0228 */  lw        $t7, 0x228($sp)
/* 90A3C 800F758C 0000282D */  daddu     $a1, $zero, $zero
/* 90A40 800F7590 AFA20014 */  sw        $v0, 0x14($sp)
/* 90A44 800F7594 93A200E8 */  lbu       $v0, 0xe8($sp)
/* 90A48 800F7598 00A0302D */  daddu     $a2, $a1, $zero
/* 90A4C 800F759C AFB90010 */  sw        $t9, 0x10($sp)
/* 90A50 800F75A0 AFB80198 */  sw        $t8, 0x198($sp)
/* 90A54 800F75A4 01E0F809 */  jalr      $t7
/* 90A58 800F75A8 AFA20018 */   sw       $v0, 0x18($sp)
/* 90A5C 800F75AC 3C09FF10 */  lui       $t1, 0xff10
/* 90A60 800F75B0 3529013F */  ori       $t1, $t1, 0x13f
/* 90A64 800F75B4 3C0A0050 */  lui       $t2, 0x50
/* 90A68 800F75B8 354A03C0 */  ori       $t2, $t2, 0x3c0
/* 90A6C 800F75BC 3C0BDC08 */  lui       $t3, 0xdc08
/* 90A70 800F75C0 356B0008 */  ori       $t3, $t3, 8
/* 90A74 800F75C4 3C0CDA38 */  lui       $t4, 0xda38
/* 90A78 800F75C8 358C0007 */  ori       $t4, $t4, 7
/* 90A7C 800F75CC 3C0DD700 */  lui       $t5, 0xd700
/* 90A80 800F75D0 35AD0002 */  ori       $t5, $t5, 2
/* 90A84 800F75D4 3C12E300 */  lui       $s2, 0xe300
/* 90A88 800F75D8 36521001 */  ori       $s2, $s2, 0x1001
/* 90A8C 800F75DC 3C19FCFF */  lui       $t9, 0xfcff
/* 90A90 800F75E0 3739FFFF */  ori       $t9, $t9, 0xffff
/* 90A94 800F75E4 3C0EFFFC */  lui       $t6, 0xfffc
/* 90A98 800F75E8 35CEF279 */  ori       $t6, $t6, 0xf279
/* 90A9C 800F75EC 3C130040 */  lui       $s3, 0x40
/* 90AA0 800F75F0 36734340 */  ori       $s3, $s3, 0x4340
/* 90AA4 800F75F4 3C14E300 */  lui       $s4, 0xe300
/* 90AA8 800F75F8 4480A000 */  mtc1      $zero, $f20
/* 90AAC 800F75FC 8FB80198 */  lw        $t8, 0x198($sp)
/* 90AB0 800F7600 3C0640C0 */  lui       $a2, 0x40c0
/* 90AB4 800F7604 36941201 */  ori       $s4, $s4, 0x1201
/* 90AB8 800F7608 AFB201A8 */  sw        $s2, 0x1a8($sp)
/* 90ABC 800F760C AFB901A0 */  sw        $t9, 0x1a0($sp)
/* 90AC0 800F7610 AFAE01A4 */  sw        $t6, 0x1a4($sp)
/* 90AC4 800F7614 8F020000 */  lw        $v0, ($t8)
/* 90AC8 800F7618 4405A000 */  mfc1      $a1, $f20
/* 90ACC 800F761C 4407A000 */  mfc1      $a3, $f20
/* 90AD0 800F7620 0040182D */  daddu     $v1, $v0, $zero
/* 90AD4 800F7624 24420008 */  addiu     $v0, $v0, 8
/* 90AD8 800F7628 AF020000 */  sw        $v0, ($t8)
/* 90ADC 800F762C 3C08800A */  lui       $t0, %hi(D_8009A64C)
/* 90AE0 800F7630 8D08A64C */  lw        $t0, %lo(D_8009A64C)($t0)
/* 90AE4 800F7634 27B000A0 */  addiu     $s0, $sp, 0xa0
/* 90AE8 800F7638 AC710000 */  sw        $s1, ($v1)
/* 90AEC 800F763C AC600004 */  sw        $zero, 4($v1)
/* 90AF0 800F7640 24430008 */  addiu     $v1, $v0, 8
/* 90AF4 800F7644 AF030000 */  sw        $v1, ($t8)
/* 90AF8 800F7648 24430010 */  addiu     $v1, $v0, 0x10
/* 90AFC 800F764C AC490000 */  sw        $t1, ($v0)
/* 90B00 800F7650 01164021 */  addu      $t0, $t0, $s6
/* 90B04 800F7654 AC480004 */  sw        $t0, 4($v0)
/* 90B08 800F7658 AF030000 */  sw        $v1, ($t8)
/* 90B0C 800F765C 24430018 */  addiu     $v1, $v0, 0x18
/* 90B10 800F7660 AC550008 */  sw        $s5, 8($v0)
/* 90B14 800F7664 AC4A000C */  sw        $t2, 0xc($v0)
/* 90B18 800F7668 AF030000 */  sw        $v1, ($t8)
/* 90B1C 800F766C 3C038011 */  lui       $v1, %hi(D_8010BBB8)
/* 90B20 800F7670 2463BBB8 */  addiu     $v1, $v1, %lo(D_8010BBB8)
/* 90B24 800F7674 AC430014 */  sw        $v1, 0x14($v0)
/* 90B28 800F7678 24430020 */  addiu     $v1, $v0, 0x20
/* 90B2C 800F767C AC4B0010 */  sw        $t3, 0x10($v0)
/* 90B30 800F7680 AF030000 */  sw        $v1, ($t8)
/* 90B34 800F7684 AC4C0018 */  sw        $t4, 0x18($v0)
/* 90B38 800F7688 8FAF0154 */  lw        $t7, 0x154($sp)
/* 90B3C 800F768C 24430028 */  addiu     $v1, $v0, 0x28
/* 90B40 800F7690 AC4F001C */  sw        $t7, 0x1c($v0)
/* 90B44 800F7694 AF030000 */  sw        $v1, ($t8)
/* 90B48 800F7698 2403FFFF */  addiu     $v1, $zero, -1
/* 90B4C 800F769C AC430024 */  sw        $v1, 0x24($v0)
/* 90B50 800F76A0 24430030 */  addiu     $v1, $v0, 0x30
/* 90B54 800F76A4 AC4D0020 */  sw        $t5, 0x20($v0)
/* 90B58 800F76A8 AF030000 */  sw        $v1, ($t8)
/* 90B5C 800F76AC 8FB20180 */  lw        $s2, 0x180($sp)
/* 90B60 800F76B0 24430038 */  addiu     $v1, $v0, 0x38
/* 90B64 800F76B4 AC520028 */  sw        $s2, 0x28($v0)
/* 90B68 800F76B8 AC40002C */  sw        $zero, 0x2c($v0)
/* 90B6C 800F76BC AF030000 */  sw        $v1, ($t8)
/* 90B70 800F76C0 8FB901A8 */  lw        $t9, 0x1a8($sp)
/* 90B74 800F76C4 24430040 */  addiu     $v1, $v0, 0x40
/* 90B78 800F76C8 AC590030 */  sw        $t9, 0x30($v0)
/* 90B7C 800F76CC AC400034 */  sw        $zero, 0x34($v0)
/* 90B80 800F76D0 AF030000 */  sw        $v1, ($t8)
/* 90B84 800F76D4 8FAE01A0 */  lw        $t6, 0x1a0($sp)
/* 90B88 800F76D8 0200202D */  daddu     $a0, $s0, $zero
/* 90B8C 800F76DC AC4E0038 */  sw        $t6, 0x38($v0)
/* 90B90 800F76E0 8FAF01A4 */  lw        $t7, 0x1a4($sp)
/* 90B94 800F76E4 24430048 */  addiu     $v1, $v0, 0x48
/* 90B98 800F76E8 AC4F003C */  sw        $t7, 0x3c($v0)
/* 90B9C 800F76EC AF030000 */  sw        $v1, ($t8)
/* 90BA0 800F76F0 24430050 */  addiu     $v1, $v0, 0x50
/* 90BA4 800F76F4 AC570040 */  sw        $s7, 0x40($v0)
/* 90BA8 800F76F8 AC530044 */  sw        $s3, 0x44($v0)
/* 90BAC 800F76FC AF030000 */  sw        $v1, ($t8)
/* 90BB0 800F7700 8FB2017C */  lw        $s2, 0x17c($sp)
/* 90BB4 800F7704 3C030008 */  lui       $v1, 8
/* 90BB8 800F7708 AC520048 */  sw        $s2, 0x48($v0)
/* 90BBC 800F770C AC43004C */  sw        $v1, 0x4c($v0)
/* 90BC0 800F7710 24430058 */  addiu     $v1, $v0, 0x58
/* 90BC4 800F7714 AF030000 */  sw        $v1, ($t8)
/* 90BC8 800F7718 24032000 */  addiu     $v1, $zero, 0x2000
/* 90BCC 800F771C AC540050 */  sw        $s4, 0x50($v0)
/* 90BD0 800F7720 0C019E40 */  jal       guTranslateF
/* 90BD4 800F7724 AC430054 */   sw       $v1, 0x54($v0)
/* 90BD8 800F7728 3C058011 */  lui       $a1, %hi(D_8010BC08)
/* 90BDC 800F772C 24A5BC08 */  addiu     $a1, $a1, %lo(D_8010BC08)
/* 90BE0 800F7730 0C019D40 */  jal       guMtxF2L
/* 90BE4 800F7734 0200202D */   daddu    $a0, $s0, $zero
/* 90BE8 800F7738 0200202D */  daddu     $a0, $s0, $zero
/* 90BEC 800F773C 8FB90208 */  lw        $t9, 0x208($sp)
/* 90BF0 800F7740 4405A000 */  mfc1      $a1, $f20
/* 90BF4 800F7744 00191023 */  negu      $v0, $t9
/* 90BF8 800F7748 00021FC2 */  srl       $v1, $v0, 0x1f
/* 90BFC 800F774C 00431021 */  addu      $v0, $v0, $v1
/* 90C00 800F7750 00021043 */  sra       $v0, $v0, 1
/* 90C04 800F7754 44823000 */  mtc1      $v0, $f6
/* 90C08 800F7758 00000000 */  nop       
/* 90C0C 800F775C 468031A0 */  cvt.s.w   $f6, $f6
/* 90C10 800F7760 44063000 */  mfc1      $a2, $f6
/* 90C14 800F7764 0C019E40 */  jal       guTranslateF
/* 90C18 800F7768 00A0382D */   daddu    $a3, $a1, $zero
/* 90C1C 800F776C 0200202D */  daddu     $a0, $s0, $zero
/* 90C20 800F7770 3C108007 */  lui       $s0, %hi(D_800741F0)
/* 90C24 800F7774 261041F0 */  addiu     $s0, $s0, %lo(D_800741F0)
/* 90C28 800F7778 3C11800A */  lui       $s1, %hi(D_8009A674)
/* 90C2C 800F777C 2631A674 */  addiu     $s1, $s1, %lo(D_8009A674)
/* 90C30 800F7780 96050000 */  lhu       $a1, ($s0)
/* 90C34 800F7784 8E220000 */  lw        $v0, ($s1)
/* 90C38 800F7788 8FAE0190 */  lw        $t6, 0x190($sp)
/* 90C3C 800F778C 00052980 */  sll       $a1, $a1, 6
/* 90C40 800F7790 00AE2821 */  addu      $a1, $a1, $t6
/* 90C44 800F7794 0C019D40 */  jal       guMtxF2L
/* 90C48 800F7798 00452821 */   addu     $a1, $v0, $a1
/* 90C4C 800F779C 3C05DA38 */  lui       $a1, 0xda38
/* 90C50 800F77A0 34A50001 */  ori       $a1, $a1, 1
/* 90C54 800F77A4 3C062AAA */  lui       $a2, 0x2aaa
/* 90C58 800F77A8 34C6AAAB */  ori       $a2, $a2, 0xaaab
/* 90C5C 800F77AC 8FAF0208 */  lw        $t7, 0x208($sp)
/* 90C60 800F77B0 8FB80198 */  lw        $t8, 0x198($sp)
/* 90C64 800F77B4 000F7FC3 */  sra       $t7, $t7, 0x1f
/* 90C68 800F77B8 AFAF01A8 */  sw        $t7, 0x1a8($sp)
/* 90C6C 800F77BC 8F020000 */  lw        $v0, ($t8)
/* 90C70 800F77C0 96030000 */  lhu       $v1, ($s0)
/* 90C74 800F77C4 0040202D */  daddu     $a0, $v0, $zero
/* 90C78 800F77C8 24420008 */  addiu     $v0, $v0, 8
/* 90C7C 800F77CC AF020000 */  sw        $v0, ($t8)
/* 90C80 800F77D0 24620001 */  addiu     $v0, $v1, 1
/* 90C84 800F77D4 3063FFFF */  andi      $v1, $v1, 0xffff
/* 90C88 800F77D8 00031980 */  sll       $v1, $v1, 6
/* 90C8C 800F77DC AC850000 */  sw        $a1, ($a0)
/* 90C90 800F77E0 A6020000 */  sh        $v0, ($s0)
/* 90C94 800F77E4 8FAE0208 */  lw        $t6, 0x208($sp)
/* 90C98 800F77E8 8E220000 */  lw        $v0, ($s1)
/* 90C9C 800F77EC 8FAF0190 */  lw        $t7, 0x190($sp)
/* 90CA0 800F77F0 01C60018 */  mult      $t6, $a2
/* 90CA4 800F77F4 006F1821 */  addu      $v1, $v1, $t7
/* 90CA8 800F77F8 00431021 */  addu      $v0, $v0, $v1
/* 90CAC 800F77FC AC820004 */  sw        $v0, 4($a0)
/* 90CB0 800F7800 8FB201A8 */  lw        $s2, 0x1a8($sp)
/* 90CB4 800F7804 00002810 */  mfhi      $a1
/* 90CB8 800F7808 00B21023 */  subu      $v0, $a1, $s2
/* 90CBC 800F780C 1840009F */  blez      $v0, .L800F7A8C
/* 90CC0 800F7810 0000682D */   daddu    $t5, $zero, $zero
/* 90CC4 800F7814 00A0982D */  daddu     $s3, $a1, $zero
/* 90CC8 800F7818 0300602D */  daddu     $t4, $t8, $zero
/* 90CCC 800F781C 3C02FD10 */  lui       $v0, 0xfd10
/* 90CD0 800F7820 3C03F510 */  lui       $v1, 0xf510
/* 90CD4 800F7824 3C15E700 */  lui       $s5, 0xe700
/* 90CD8 800F7828 3C16F200 */  lui       $s6, 0xf200
/* 90CDC 800F782C 8FB90188 */  lw        $t9, 0x188($sp)
/* 90CE0 800F7830 8FB8018C */  lw        $t8, 0x18c($sp)
/* 90CE4 800F7834 8FAE0204 */  lw        $t6, 0x204($sp)
/* 90CE8 800F7838 8FAF0184 */  lw        $t7, 0x184($sp)
/* 90CEC 800F783C 01A0802D */  daddu     $s0, $t5, $zero
/* 90CF0 800F7840 AFA001A4 */  sw        $zero, 0x1a4($sp)
/* 90CF4 800F7844 03221025 */  or        $v0, $t9, $v0
/* 90CF8 800F7848 AFA2019C */  sw        $v0, 0x19c($sp)
/* 90CFC 800F784C 000E1040 */  sll       $v0, $t6, 1
/* 90D00 800F7850 24420007 */  addiu     $v0, $v0, 7
/* 90D04 800F7854 000210C3 */  sra       $v0, $v0, 3
/* 90D08 800F7858 304201FF */  andi      $v0, $v0, 0x1ff
/* 90D0C 800F785C 00021240 */  sll       $v0, $v0, 9
/* 90D10 800F7860 00431025 */  or        $v0, $v0, $v1
/* 90D14 800F7864 AFA201A0 */  sw        $v0, 0x1a0($sp)
/* 90D18 800F7868 000F1080 */  sll       $v0, $t7, 2
/* 90D1C 800F786C 30420FFF */  andi      $v0, $v0, 0xfff
/* 90D20 800F7870 00028B00 */  sll       $s1, $v0, 0xc
/* 90D24 800F7874 000E17C2 */  srl       $v0, $t6, 0x1f
/* 90D28 800F7878 01C21021 */  addu      $v0, $t6, $v0
/* 90D2C 800F787C 0002A043 */  sra       $s4, $v0, 1
/* 90D30 800F7880 240200A0 */  addiu     $v0, $zero, 0xa0
/* 90D34 800F7884 00541023 */  subu      $v0, $v0, $s4
/* 90D38 800F7888 00021080 */  sll       $v0, $v0, 2
/* 90D3C 800F788C 30420FFF */  andi      $v0, $v0, 0xfff
/* 90D40 800F7890 00021300 */  sll       $v0, $v0, 0xc
/* 90D44 800F7894 0056B825 */  or        $s7, $v0, $s6
.L800F7898:
/* 90D48 800F7898 8FB201A8 */  lw        $s2, 0x1a8($sp)
/* 90D4C 800F789C 02721823 */  subu      $v1, $s3, $s2
/* 90D50 800F78A0 2462FFFF */  addiu     $v0, $v1, -1
/* 90D54 800F78A4 55A20007 */  bnel      $t5, $v0, .L800F78C4
/* 90D58 800F78A8 24020001 */   addiu    $v0, $zero, 1
/* 90D5C 800F78AC 00031040 */  sll       $v0, $v1, 1
/* 90D60 800F78B0 00431021 */  addu      $v0, $v0, $v1
/* 90D64 800F78B4 8FB90208 */  lw        $t9, 0x208($sp)
/* 90D68 800F78B8 00021040 */  sll       $v0, $v0, 1
/* 90D6C 800F78BC 03221023 */  subu      $v0, $t9, $v0
/* 90D70 800F78C0 0002102B */  sltu      $v0, $zero, $v0
.L800F78C4:
/* 90D74 800F78C4 3C070708 */  lui       $a3, 0x708
/* 90D78 800F78C8 34E7C290 */  ori       $a3, $a3, 0xc290
/* 90D7C 800F78CC 3C080008 */  lui       $t0, 8
/* 90D80 800F78D0 3508C290 */  ori       $t0, $t0, 0xc290
/* 90D84 800F78D4 3C090100 */  lui       $t1, 0x100
/* 90D88 800F78D8 35294008 */  ori       $t1, $t1, 0x4008
/* 90D8C 800F78DC 3C0A0600 */  lui       $t2, 0x600
/* 90D90 800F78E0 354A0602 */  ori       $t2, $t2, 0x602
/* 90D94 800F78E4 3C0BDA38 */  lui       $t3, 0xda38
/* 90D98 800F78E8 356B0001 */  ori       $t3, $t3, 1
/* 90D9C 800F78EC 32050FFF */  andi      $a1, $s0, 0xfff
/* 90DA0 800F78F0 26100018 */  addiu     $s0, $s0, 0x18
/* 90DA4 800F78F4 24460005 */  addiu     $a2, $v0, 5
/* 90DA8 800F78F8 25AD0001 */  addiu     $t5, $t5, 1
/* 90DAC 800F78FC 8FAE01A4 */  lw        $t6, 0x1a4($sp)
/* 90DB0 800F7900 8FAF0208 */  lw        $t7, 0x208($sp)
/* 90DB4 800F7904 01C62021 */  addu      $a0, $t6, $a2
/* 90DB8 800F7908 25CE0006 */  addiu     $t6, $t6, 6
/* 90DBC 800F790C 000F7FC3 */  sra       $t7, $t7, 0x1f
/* 90DC0 800F7910 AFAE01A4 */  sw        $t6, 0x1a4($sp)
/* 90DC4 800F7914 8D830000 */  lw        $v1, ($t4)
/* 90DC8 800F7918 00042080 */  sll       $a0, $a0, 2
/* 90DCC 800F791C AFAF01A8 */  sw        $t7, 0x1a8($sp)
/* 90DD0 800F7920 0060102D */  daddu     $v0, $v1, $zero
/* 90DD4 800F7924 24630008 */  addiu     $v1, $v1, 8
/* 90DD8 800F7928 AD830000 */  sw        $v1, ($t4)
/* 90DDC 800F792C 8FB2019C */  lw        $s2, 0x19c($sp)
/* 90DE0 800F7930 30840FFF */  andi      $a0, $a0, 0xfff
/* 90DE4 800F7934 AC580004 */  sw        $t8, 4($v0)
/* 90DE8 800F7938 AC520000 */  sw        $s2, ($v0)
/* 90DEC 800F793C 24620008 */  addiu     $v0, $v1, 8
/* 90DF0 800F7940 AD820000 */  sw        $v0, ($t4)
/* 90DF4 800F7944 8FB901A0 */  lw        $t9, 0x1a0($sp)
/* 90DF8 800F7948 24620010 */  addiu     $v0, $v1, 0x10
/* 90DFC 800F794C AC670004 */  sw        $a3, 4($v1)
/* 90E00 800F7950 AC790000 */  sw        $t9, ($v1)
/* 90E04 800F7954 AD820000 */  sw        $v0, ($t4)
/* 90E08 800F7958 3C02E600 */  lui       $v0, 0xe600
/* 90E0C 800F795C AC620008 */  sw        $v0, 8($v1)
/* 90E10 800F7960 24620018 */  addiu     $v0, $v1, 0x18
/* 90E14 800F7964 AC60000C */  sw        $zero, 0xc($v1)
/* 90E18 800F7968 AD820000 */  sw        $v0, ($t4)
/* 90E1C 800F796C 3C02F400 */  lui       $v0, 0xf400
/* 90E20 800F7970 00A21025 */  or        $v0, $a1, $v0
/* 90E24 800F7974 AC620010 */  sw        $v0, 0x10($v1)
/* 90E28 800F7978 3C020700 */  lui       $v0, 0x700
/* 90E2C 800F797C 00821025 */  or        $v0, $a0, $v0
/* 90E30 800F7980 02221025 */  or        $v0, $s1, $v0
/* 90E34 800F7984 AC620014 */  sw        $v0, 0x14($v1)
/* 90E38 800F7988 24620020 */  addiu     $v0, $v1, 0x20
/* 90E3C 800F798C AD820000 */  sw        $v0, ($t4)
/* 90E40 800F7990 24620028 */  addiu     $v0, $v1, 0x28
/* 90E44 800F7994 AC750018 */  sw        $s5, 0x18($v1)
/* 90E48 800F7998 AC60001C */  sw        $zero, 0x1c($v1)
/* 90E4C 800F799C AD820000 */  sw        $v0, ($t4)
/* 90E50 800F79A0 24620030 */  addiu     $v0, $v1, 0x30
/* 90E54 800F79A4 00B62825 */  or        $a1, $a1, $s6
/* 90E58 800F79A8 02242025 */  or        $a0, $s1, $a0
/* 90E5C 800F79AC AC790020 */  sw        $t9, 0x20($v1)
/* 90E60 800F79B0 AC680024 */  sw        $t0, 0x24($v1)
/* 90E64 800F79B4 AD820000 */  sw        $v0, ($t4)
/* 90E68 800F79B8 24620038 */  addiu     $v0, $v1, 0x38
/* 90E6C 800F79BC AC650028 */  sw        $a1, 0x28($v1)
/* 90E70 800F79C0 AC64002C */  sw        $a0, 0x2c($v1)
/* 90E74 800F79C4 AD820000 */  sw        $v0, ($t4)
/* 90E78 800F79C8 AC770030 */  sw        $s7, 0x30($v1)
/* 90E7C 800F79CC 8FAE0204 */  lw        $t6, 0x204($sp)
/* 90E80 800F79D0 00063080 */  sll       $a2, $a2, 2
/* 90E84 800F79D4 25C200A0 */  addiu     $v0, $t6, 0xa0
/* 90E88 800F79D8 00541023 */  subu      $v0, $v0, $s4
/* 90E8C 800F79DC 2442FFFF */  addiu     $v0, $v0, -1
/* 90E90 800F79E0 00021080 */  sll       $v0, $v0, 2
/* 90E94 800F79E4 30420FFF */  andi      $v0, $v0, 0xfff
/* 90E98 800F79E8 00021300 */  sll       $v0, $v0, 0xc
/* 90E9C 800F79EC 00461025 */  or        $v0, $v0, $a2
/* 90EA0 800F79F0 AC620034 */  sw        $v0, 0x34($v1)
/* 90EA4 800F79F4 24620040 */  addiu     $v0, $v1, 0x40
/* 90EA8 800F79F8 AD820000 */  sw        $v0, ($t4)
/* 90EAC 800F79FC 3C028011 */  lui       $v0, %hi(D_8010BBC8)
/* 90EB0 800F7A00 2442BBC8 */  addiu     $v0, $v0, %lo(D_8010BBC8)
/* 90EB4 800F7A04 AC690038 */  sw        $t1, 0x38($v1)
/* 90EB8 800F7A08 AC62003C */  sw        $v0, 0x3c($v1)
/* 90EBC 800F7A0C 24620048 */  addiu     $v0, $v1, 0x48
/* 90EC0 800F7A10 AD820000 */  sw        $v0, ($t4)
/* 90EC4 800F7A14 24020406 */  addiu     $v0, $zero, 0x406
/* 90EC8 800F7A18 AC620044 */  sw        $v0, 0x44($v1)
/* 90ECC 800F7A1C 24620050 */  addiu     $v0, $v1, 0x50
/* 90ED0 800F7A20 AC6A0040 */  sw        $t2, 0x40($v1)
/* 90ED4 800F7A24 AD820000 */  sw        $v0, ($t4)
/* 90ED8 800F7A28 24620058 */  addiu     $v0, $v1, 0x58
/* 90EDC 800F7A2C AC750048 */  sw        $s5, 0x48($v1)
/* 90EE0 800F7A30 AC60004C */  sw        $zero, 0x4c($v1)
/* 90EE4 800F7A34 AD820000 */  sw        $v0, ($t4)
/* 90EE8 800F7A38 3C028011 */  lui       $v0, %hi(D_8010BC08)
/* 90EEC 800F7A3C 2442BC08 */  addiu     $v0, $v0, %lo(D_8010BC08)
/* 90EF0 800F7A40 AC620054 */  sw        $v0, 0x54($v1)
/* 90EF4 800F7A44 026F1023 */  subu      $v0, $s3, $t7
/* 90EF8 800F7A48 01A2102A */  slt       $v0, $t5, $v0
/* 90EFC 800F7A4C 1440FF92 */  bnez      $v0, .L800F7898
/* 90F00 800F7A50 AC6B0050 */   sw       $t3, 0x50($v1)
/* 90F04 800F7A54 0803DEA3 */  j         .L800F7A8C
/* 90F08 800F7A58 00000000 */   nop      
.L800F7A5C:
/* 90F0C 800F7A5C 93A200E7 */  lbu       $v0, 0xe7($sp)
/* 90F10 800F7A60 8FA4022C */  lw        $a0, 0x22c($sp)
/* 90F14 800F7A64 8FA501F8 */  lw        $a1, 0x1f8($sp)
/* 90F18 800F7A68 8FA601FC */  lw        $a2, 0x1fc($sp)
/* 90F1C 800F7A6C 8FA70204 */  lw        $a3, 0x204($sp)
/* 90F20 800F7A70 8FAF0208 */  lw        $t7, 0x208($sp)
/* 90F24 800F7A74 8FB20228 */  lw        $s2, 0x228($sp)
/* 90F28 800F7A78 AFA20014 */  sw        $v0, 0x14($sp)
/* 90F2C 800F7A7C 93A200E8 */  lbu       $v0, 0xe8($sp)
/* 90F30 800F7A80 AFAF0010 */  sw        $t7, 0x10($sp)
/* 90F34 800F7A84 0240F809 */  jalr      $s2
/* 90F38 800F7A88 AFA20018 */   sw       $v0, 0x18($sp)
.L800F7A8C:
/* 90F3C 800F7A8C 13C00016 */  beqz      $fp, .L800F7AE8
/* 90F40 800F7A90 3C03D838 */   lui      $v1, 0xd838
/* 90F44 800F7A94 34630002 */  ori       $v1, $v1, 2
/* 90F48 800F7A98 3C06E300 */  lui       $a2, 0xe300
/* 90F4C 800F7A9C 3C04800A */  lui       $a0, %hi(D_8009A66C)
/* 90F50 800F7AA0 2484A66C */  addiu     $a0, $a0, %lo(D_8009A66C)
/* 90F54 800F7AA4 8C820000 */  lw        $v0, ($a0)
/* 90F58 800F7AA8 34C60C00 */  ori       $a2, $a2, 0xc00
/* 90F5C 800F7AAC 0040282D */  daddu     $a1, $v0, $zero
/* 90F60 800F7AB0 24420008 */  addiu     $v0, $v0, 8
/* 90F64 800F7AB4 AC820000 */  sw        $v0, ($a0)
/* 90F68 800F7AB8 ACA30000 */  sw        $v1, ($a1)
/* 90F6C 800F7ABC 24030040 */  addiu     $v1, $zero, 0x40
/* 90F70 800F7AC0 ACA30004 */  sw        $v1, 4($a1)
/* 90F74 800F7AC4 24430008 */  addiu     $v1, $v0, 8
/* 90F78 800F7AC8 AC830000 */  sw        $v1, ($a0)
/* 90F7C 800F7ACC 24430010 */  addiu     $v1, $v0, 0x10
/* 90F80 800F7AD0 AC460000 */  sw        $a2, ($v0)
/* 90F84 800F7AD4 AC400004 */  sw        $zero, 4($v0)
/* 90F88 800F7AD8 AC830000 */  sw        $v1, ($a0)
/* 90F8C 800F7ADC 3C03E700 */  lui       $v1, 0xe700
/* 90F90 800F7AE0 AC430008 */  sw        $v1, 8($v0)
/* 90F94 800F7AE4 AC40000C */  sw        $zero, 0xc($v0)
.L800F7AE8:
/* 90F98 800F7AE8 0000102D */  daddu     $v0, $zero, $zero
.L800F7AEC:
/* 90F9C 800F7AEC 8FBF01D4 */  lw        $ra, 0x1d4($sp)
/* 90FA0 800F7AF0 8FBE01D0 */  lw        $fp, 0x1d0($sp)
/* 90FA4 800F7AF4 8FB701CC */  lw        $s7, 0x1cc($sp)
/* 90FA8 800F7AF8 8FB601C8 */  lw        $s6, 0x1c8($sp)
/* 90FAC 800F7AFC 8FB501C4 */  lw        $s5, 0x1c4($sp)
/* 90FB0 800F7B00 8FB401C0 */  lw        $s4, 0x1c0($sp)
/* 90FB4 800F7B04 8FB301BC */  lw        $s3, 0x1bc($sp)
/* 90FB8 800F7B08 8FB201B8 */  lw        $s2, 0x1b8($sp)
/* 90FBC 800F7B0C 8FB101B4 */  lw        $s1, 0x1b4($sp)
/* 90FC0 800F7B10 8FB001B0 */  lw        $s0, 0x1b0($sp)
/* 90FC4 800F7B14 D7B801E8 */  ldc1      $f24, 0x1e8($sp)
/* 90FC8 800F7B18 D7B601E0 */  ldc1      $f22, 0x1e0($sp)
/* 90FCC 800F7B1C D7B401D8 */  ldc1      $f20, 0x1d8($sp)
/* 90FD0 800F7B20 03E00008 */  jr        $ra
/* 90FD4 800F7B24 27BD01F0 */   addiu    $sp, $sp, 0x1f0
/* 90FD8 800F7B28 00000000 */  nop       
/* 90FDC 800F7B2C 00000000 */  nop       
