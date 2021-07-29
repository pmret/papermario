.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80150E18
.double 0.6

.section .text

glabel update_item_entity_collectable
/* CA950 80134250 3C028015 */  lui       $v0, %hi(D_801565A4)
/* CA954 80134254 844265A4 */  lh        $v0, %lo(D_801565A4)($v0)
/* CA958 80134258 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* CA95C 8013425C AFB20038 */  sw        $s2, 0x38($sp)
/* CA960 80134260 AFB40040 */  sw        $s4, 0x40($sp)
/* CA964 80134264 3C148011 */  lui       $s4, %hi(gPlayerStatus)
/* CA968 80134268 2694EFC8 */  addiu     $s4, $s4, %lo(gPlayerStatus)
/* CA96C 8013426C AFB3003C */  sw        $s3, 0x3c($sp)
/* CA970 80134270 3C138011 */  lui       $s3, %hi(gPlayerData)
/* CA974 80134274 2673F290 */  addiu     $s3, $s3, %lo(gPlayerData)
/* CA978 80134278 AFBF0044 */  sw        $ra, 0x44($sp)
/* CA97C 8013427C AFB10034 */  sw        $s1, 0x34($sp)
/* CA980 80134280 AFB00030 */  sw        $s0, 0x30($sp)
/* CA984 80134284 F7B80058 */  sdc1      $f24, 0x58($sp)
/* CA988 80134288 F7B60050 */  sdc1      $f22, 0x50($sp)
/* CA98C 8013428C F7B40048 */  sdc1      $f20, 0x48($sp)
/* CA990 80134290 144004B7 */  bnez      $v0, .L80135570
/* CA994 80134294 0080902D */   daddu    $s2, $a0, $zero
/* CA998 80134298 9242001C */  lbu       $v0, 0x1c($s2)
/* CA99C 8013429C 10400003 */  beqz      $v0, .L801342AC
/* CA9A0 801342A0 2442FFFF */   addiu    $v0, $v0, -1
/* CA9A4 801342A4 0804D55C */  j         .L80135570
/* CA9A8 801342A8 A242001C */   sb       $v0, 0x1c($s2)
.L801342AC:
/* CA9AC 801342AC 24050017 */  addiu     $a1, $zero, 0x17
/* CA9B0 801342B0 8243001B */  lb        $v1, 0x1b($s2)
/* CA9B4 801342B4 8244001A */  lb        $a0, 0x1a($s2)
/* CA9B8 801342B8 00651026 */  xor       $v0, $v1, $a1
/* CA9BC 801342BC 10800006 */  beqz      $a0, .L801342D8
/* CA9C0 801342C0 2C500001 */   sltiu    $s0, $v0, 1
/* CA9C4 801342C4 24020001 */  addiu     $v0, $zero, 1
/* CA9C8 801342C8 10820203 */  beq       $a0, $v0, .L80134AD8
/* CA9CC 801342CC 24020014 */   addiu    $v0, $zero, 0x14
/* CA9D0 801342D0 0804D44D */  j         .L80135134
/* CA9D4 801342D4 00000000 */   nop
.L801342D8:
/* CA9D8 801342D8 0C04C3EB */  jal       item_entity_enable_shadow
/* CA9DC 801342DC 0240202D */   daddu    $a0, $s2, $zero
/* CA9E0 801342E0 0C00AB39 */  jal       heap_malloc
/* CA9E4 801342E4 24040024 */   addiu    $a0, $zero, 0x24
/* CA9E8 801342E8 0040882D */  daddu     $s1, $v0, $zero
/* CA9EC 801342EC 16200003 */  bnez      $s1, .L801342FC
/* CA9F0 801342F0 AE510014 */   sw       $s1, 0x14($s2)
.L801342F4:
/* CA9F4 801342F4 0804D0BD */  j         .L801342F4
/* CA9F8 801342F8 00000000 */   nop
.L801342FC:
/* CA9FC 801342FC 8E430000 */  lw        $v1, ($s2)
/* CAA00 80134300 3C020100 */  lui       $v0, 0x100
/* CAA04 80134304 00621024 */  and       $v0, $v1, $v0
/* CAA08 80134308 10400005 */  beqz      $v0, .L80134320
/* CAA0C 8013430C 3C020001 */   lui      $v0, 1
/* CAA10 80134310 3C014180 */  lui       $at, 0x4180
/* CAA14 80134314 44810000 */  mtc1      $at, $f0
/* CAA18 80134318 0804D0D1 */  j         .L80134344
/* CAA1C 8013431C 00000000 */   nop
.L80134320:
/* CAA20 80134320 00621024 */  and       $v0, $v1, $v0
/* CAA24 80134324 14400005 */  bnez      $v0, .L8013433C
/* CAA28 80134328 00000000 */   nop
/* CAA2C 8013432C 3C014140 */  lui       $at, 0x4140
/* CAA30 80134330 44810000 */  mtc1      $at, $f0
/* CAA34 80134334 0804D0D1 */  j         .L80134344
/* CAA38 80134338 00000000 */   nop
.L8013433C:
/* CAA3C 8013433C 3C014160 */  lui       $at, 0x4160
/* CAA40 80134340 44810000 */  mtc1      $at, $f0
.L80134344:
/* CAA44 80134344 3C014000 */  lui       $at, 0x4000
/* CAA48 80134348 44811000 */  mtc1      $at, $f2
/* CAA4C 8013434C E6200000 */  swc1      $f0, ($s1)
/* CAA50 80134350 E6220004 */  swc1      $f2, 4($s1)
/* CAA54 80134354 3C0141C0 */  lui       $at, 0x41c0
/* CAA58 80134358 44810000 */  mtc1      $at, $f0
/* CAA5C 8013435C 00000000 */  nop
/* CAA60 80134360 E6200008 */  swc1      $f0, 8($s1)
/* CAA64 80134364 E620000C */  swc1      $f0, 0xc($s1)
/* CAA68 80134368 8642001E */  lh        $v0, 0x1e($s2)
/* CAA6C 8013436C 04410164 */  bgez      $v0, .L80134900
/* CAA70 80134370 00000000 */   nop
/* CAA74 80134374 96430018 */  lhu       $v1, 0x18($s2)
/* CAA78 80134378 2462FFF0 */  addiu     $v0, $v1, -0x10
/* CAA7C 8013437C 2C4200CB */  sltiu     $v0, $v0, 0xcb
/* CAA80 80134380 10400036 */  beqz      $v0, .L8013445C
/* CAA84 80134384 00031400 */   sll      $v0, $v1, 0x10
/* CAA88 80134388 0C00A67F */  jal       rand_int
/* CAA8C 8013438C 24042710 */   addiu    $a0, $zero, 0x2710
/* CAA90 80134390 28421388 */  slti      $v0, $v0, 0x1388
/* CAA94 80134394 10400011 */  beqz      $v0, .L801343DC
/* CAA98 80134398 00000000 */   nop
/* CAA9C 8013439C 0C00A67F */  jal       rand_int
/* CAAA0 801343A0 2404001E */   addiu    $a0, $zero, 0x1e
/* CAAA4 801343A4 00101880 */  sll       $v1, $s0, 2
/* CAAA8 801343A8 00701821 */  addu      $v1, $v1, $s0
/* CAAAC 801343AC 00031880 */  sll       $v1, $v1, 2
/* CAAB0 801343B0 00701823 */  subu      $v1, $v1, $s0
/* CAAB4 801343B4 000320C0 */  sll       $a0, $v1, 3
/* CAAB8 801343B8 00641821 */  addu      $v1, $v1, $a0
/* CAABC 801343BC 000318C0 */  sll       $v1, $v1, 3
/* CAAC0 801343C0 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* CAAC4 801343C4 00230821 */  addu      $at, $at, $v1
/* CAAC8 801343C8 C42C1DEC */  lwc1      $f12, %lo(gCameras+0x6C)($at)
/* CAACC 801343CC 3C0142D2 */  lui       $at, 0x42d2
/* CAAD0 801343D0 44810000 */  mtc1      $at, $f0
/* CAAD4 801343D4 0804D107 */  j         .L8013441C
/* CAAD8 801343D8 46006300 */   add.s    $f12, $f12, $f0
.L801343DC:
/* CAADC 801343DC 0C00A67F */  jal       rand_int
/* CAAE0 801343E0 2404001E */   addiu    $a0, $zero, 0x1e
/* CAAE4 801343E4 00101880 */  sll       $v1, $s0, 2
/* CAAE8 801343E8 00701821 */  addu      $v1, $v1, $s0
/* CAAEC 801343EC 00031880 */  sll       $v1, $v1, 2
/* CAAF0 801343F0 00701823 */  subu      $v1, $v1, $s0
/* CAAF4 801343F4 000320C0 */  sll       $a0, $v1, 3
/* CAAF8 801343F8 00641821 */  addu      $v1, $v1, $a0
/* CAAFC 801343FC 000318C0 */  sll       $v1, $v1, 3
/* CAB00 80134400 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* CAB04 80134404 00230821 */  addu      $at, $at, $v1
/* CAB08 80134408 C42C1DEC */  lwc1      $f12, %lo(gCameras+0x6C)($at)
/* CAB0C 8013440C 3C0142D2 */  lui       $at, 0x42d2
/* CAB10 80134410 44810000 */  mtc1      $at, $f0
/* CAB14 80134414 00000000 */  nop
/* CAB18 80134418 46006301 */  sub.s     $f12, $f12, $f0
.L8013441C:
/* CAB1C 8013441C 44820000 */  mtc1      $v0, $f0
/* CAB20 80134420 00000000 */  nop
/* CAB24 80134424 46800020 */  cvt.s.w   $f0, $f0
/* CAB28 80134428 46006300 */  add.s     $f12, $f12, $f0
/* CAB2C 8013442C 3C014170 */  lui       $at, 0x4170
/* CAB30 80134430 44810000 */  mtc1      $at, $f0
/* CAB34 80134434 0C00A6C9 */  jal       clamp_angle
/* CAB38 80134438 46006301 */   sub.s    $f12, $f12, $f0
/* CAB3C 8013443C E6200018 */  swc1      $f0, 0x18($s1)
/* CAB40 80134440 C6200000 */  lwc1      $f0, ($s1)
/* CAB44 80134444 3C014080 */  lui       $at, 0x4080
/* CAB48 80134448 44811000 */  mtc1      $at, $f2
/* CAB4C 8013444C 00000000 */  nop
/* CAB50 80134450 46020000 */  add.s     $f0, $f0, $f2
/* CAB54 80134454 0804D20B */  j         .L8013482C
/* CAB58 80134458 E6200000 */   swc1     $f0, ($s1)
.L8013445C:
/* CAB5C 8013445C 00021C03 */  sra       $v1, $v0, 0x10
/* CAB60 80134460 24020158 */  addiu     $v0, $zero, 0x158
/* CAB64 80134464 106200D6 */  beq       $v1, $v0, .L801347C0
/* CAB68 80134468 28620159 */   slti     $v0, $v1, 0x159
/* CAB6C 8013446C 10400009 */  beqz      $v0, .L80134494
/* CAB70 80134470 24020156 */   addiu    $v0, $zero, 0x156
/* CAB74 80134474 106200D2 */  beq       $v1, $v0, .L801347C0
/* CAB78 80134478 28620157 */   slti     $v0, $v1, 0x157
/* CAB7C 8013447C 10400029 */  beqz      $v0, .L80134524
/* CAB80 80134480 24020010 */   addiu    $v0, $zero, 0x10
/* CAB84 80134484 1062003C */  beq       $v1, $v0, .L80134578
/* CAB88 80134488 00000000 */   nop
/* CAB8C 8013448C 0804D20B */  j         .L8013482C
/* CAB90 80134490 AE200018 */   sw       $zero, 0x18($s1)
.L80134494:
/* CAB94 80134494 2402015A */  addiu     $v0, $zero, 0x15a
/* CAB98 80134498 106200C9 */  beq       $v1, $v0, .L801347C0
/* CAB9C 8013449C 0062102A */   slt      $v0, $v1, $v0
/* CABA0 801344A0 1440004A */  bnez      $v0, .L801345CC
/* CABA4 801344A4 24020017 */   addiu    $v0, $zero, 0x17
/* CABA8 801344A8 2402015B */  addiu     $v0, $zero, 0x15b
/* CABAC 801344AC 10620005 */  beq       $v1, $v0, .L801344C4
/* CABB0 801344B0 2402015C */   addiu    $v0, $zero, 0x15c
/* CABB4 801344B4 1062008D */  beq       $v1, $v0, .L801346EC
/* CABB8 801344B8 00000000 */   nop
/* CABBC 801344BC 0804D20B */  j         .L8013482C
/* CABC0 801344C0 AE200018 */   sw       $zero, 0x18($s1)
.L801344C4:
/* CABC4 801344C4 0C00A67F */  jal       rand_int
/* CABC8 801344C8 24040078 */   addiu    $a0, $zero, 0x78
/* CABCC 801344CC 00101880 */  sll       $v1, $s0, 2
/* CABD0 801344D0 00701821 */  addu      $v1, $v1, $s0
/* CABD4 801344D4 00031880 */  sll       $v1, $v1, 2
/* CABD8 801344D8 00701823 */  subu      $v1, $v1, $s0
/* CABDC 801344DC 000320C0 */  sll       $a0, $v1, 3
/* CABE0 801344E0 00641821 */  addu      $v1, $v1, $a0
/* CABE4 801344E4 000318C0 */  sll       $v1, $v1, 3
/* CABE8 801344E8 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* CABEC 801344EC 00230821 */  addu      $at, $at, $v1
/* CABF0 801344F0 C42C1DEC */  lwc1      $f12, %lo(gCameras+0x6C)($at)
/* CABF4 801344F4 3C0142B4 */  lui       $at, 0x42b4
/* CABF8 801344F8 44810000 */  mtc1      $at, $f0
/* CABFC 801344FC 00000000 */  nop
/* CAC00 80134500 46006301 */  sub.s     $f12, $f12, $f0
/* CAC04 80134504 44820000 */  mtc1      $v0, $f0
/* CAC08 80134508 00000000 */  nop
/* CAC0C 8013450C 46800020 */  cvt.s.w   $f0, $f0
/* CAC10 80134510 46006300 */  add.s     $f12, $f12, $f0
/* CAC14 80134514 3C014270 */  lui       $at, 0x4270
/* CAC18 80134518 44810000 */  mtc1      $at, $f0
/* CAC1C 8013451C 0804D208 */  j         .L80134820
/* CAC20 80134520 46006300 */   add.s    $f12, $f12, $f0
.L80134524:
/* CAC24 80134524 0C00A67F */  jal       rand_int
/* CAC28 80134528 24042710 */   addiu    $a0, $zero, 0x2710
/* CAC2C 8013452C 28421388 */  slti      $v0, $v0, 0x1388
/* CAC30 80134530 144000A3 */  bnez      $v0, .L801347C0
/* CAC34 80134534 00000000 */   nop
/* CAC38 80134538 0C00A67F */  jal       rand_int
/* CAC3C 8013453C 24040078 */   addiu    $a0, $zero, 0x78
/* CAC40 80134540 00101880 */  sll       $v1, $s0, 2
/* CAC44 80134544 00701821 */  addu      $v1, $v1, $s0
/* CAC48 80134548 00031880 */  sll       $v1, $v1, 2
/* CAC4C 8013454C 00701823 */  subu      $v1, $v1, $s0
/* CAC50 80134550 000320C0 */  sll       $a0, $v1, 3
/* CAC54 80134554 00641821 */  addu      $v1, $v1, $a0
/* CAC58 80134558 000318C0 */  sll       $v1, $v1, 3
/* CAC5C 8013455C 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* CAC60 80134560 00230821 */  addu      $at, $at, $v1
/* CAC64 80134564 C42C1DEC */  lwc1      $f12, %lo(gCameras+0x6C)($at)
/* CAC68 80134568 3C0142B4 */  lui       $at, 0x42b4
/* CAC6C 8013456C 44810000 */  mtc1      $at, $f0
/* CAC70 80134570 0804D200 */  j         .L80134800
/* CAC74 80134574 46006301 */   sub.s    $f12, $f12, $f0
.L80134578:
/* CAC78 80134578 0C00A67F */  jal       rand_int
/* CAC7C 8013457C 24042710 */   addiu    $a0, $zero, 0x2710
/* CAC80 80134580 28421388 */  slti      $v0, $v0, 0x1388
/* CAC84 80134584 1440008E */  bnez      $v0, .L801347C0
/* CAC88 80134588 00000000 */   nop
/* CAC8C 8013458C 0C00A67F */  jal       rand_int
/* CAC90 80134590 24040078 */   addiu    $a0, $zero, 0x78
/* CAC94 80134594 00101880 */  sll       $v1, $s0, 2
/* CAC98 80134598 00701821 */  addu      $v1, $v1, $s0
/* CAC9C 8013459C 00031880 */  sll       $v1, $v1, 2
/* CACA0 801345A0 00701823 */  subu      $v1, $v1, $s0
/* CACA4 801345A4 000320C0 */  sll       $a0, $v1, 3
/* CACA8 801345A8 00641821 */  addu      $v1, $v1, $a0
/* CACAC 801345AC 000318C0 */  sll       $v1, $v1, 3
/* CACB0 801345B0 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* CACB4 801345B4 00230821 */  addu      $at, $at, $v1
/* CACB8 801345B8 C42C1DEC */  lwc1      $f12, %lo(gCameras+0x6C)($at)
/* CACBC 801345BC 3C0142B4 */  lui       $at, 0x42b4
/* CACC0 801345C0 44810000 */  mtc1      $at, $f0
/* CACC4 801345C4 0804D200 */  j         .L80134800
/* CACC8 801345C8 46006301 */   sub.s    $f12, $f12, $f0
.L801345CC:
/* CACCC 801345CC 8243001B */  lb        $v1, 0x1b($s2)
/* CACD0 801345D0 10620011 */  beq       $v1, $v0, .L80134618
/* CACD4 801345D4 00000000 */   nop
/* CACD8 801345D8 0C00A67F */  jal       rand_int
/* CACDC 801345DC 24040078 */   addiu    $a0, $zero, 0x78
/* CACE0 801345E0 00101880 */  sll       $v1, $s0, 2
/* CACE4 801345E4 00701821 */  addu      $v1, $v1, $s0
/* CACE8 801345E8 00031880 */  sll       $v1, $v1, 2
/* CACEC 801345EC 00701823 */  subu      $v1, $v1, $s0
/* CACF0 801345F0 000320C0 */  sll       $a0, $v1, 3
/* CACF4 801345F4 00641821 */  addu      $v1, $v1, $a0
/* CACF8 801345F8 000318C0 */  sll       $v1, $v1, 3
/* CACFC 801345FC 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* CAD00 80134600 00230821 */  addu      $at, $at, $v1
/* CAD04 80134604 C42C1DEC */  lwc1      $f12, %lo(gCameras+0x6C)($at)
/* CAD08 80134608 3C0142B4 */  lui       $at, 0x42b4
/* CAD0C 8013460C 44810000 */  mtc1      $at, $f0
/* CAD10 80134610 0804D200 */  j         .L80134800
/* CAD14 80134614 46006301 */   sub.s    $f12, $f12, $f0
.L80134618:
/* CAD18 80134618 0C00A67F */  jal       rand_int
/* CAD1C 8013461C 24042710 */   addiu    $a0, $zero, 0x2710
/* CAD20 80134620 28421388 */  slti      $v0, $v0, 0x1388
/* CAD24 80134624 10400019 */  beqz      $v0, .L8013468C
/* CAD28 80134628 00000000 */   nop
/* CAD2C 8013462C 0C00A67F */  jal       rand_int
/* CAD30 80134630 2404003C */   addiu    $a0, $zero, 0x3c
/* CAD34 80134634 00101880 */  sll       $v1, $s0, 2
/* CAD38 80134638 00701821 */  addu      $v1, $v1, $s0
/* CAD3C 8013463C 00031880 */  sll       $v1, $v1, 2
/* CAD40 80134640 00701823 */  subu      $v1, $v1, $s0
/* CAD44 80134644 000320C0 */  sll       $a0, $v1, 3
/* CAD48 80134648 00641821 */  addu      $v1, $v1, $a0
/* CAD4C 8013464C 000318C0 */  sll       $v1, $v1, 3
/* CAD50 80134650 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* CAD54 80134654 00230821 */  addu      $at, $at, $v1
/* CAD58 80134658 C42C1DEC */  lwc1      $f12, %lo(gCameras+0x6C)($at)
/* CAD5C 8013465C 3C0142B4 */  lui       $at, 0x42b4
/* CAD60 80134660 44810000 */  mtc1      $at, $f0
/* CAD64 80134664 00000000 */  nop
/* CAD68 80134668 46006300 */  add.s     $f12, $f12, $f0
/* CAD6C 8013466C 44820000 */  mtc1      $v0, $f0
/* CAD70 80134670 00000000 */  nop
/* CAD74 80134674 46800020 */  cvt.s.w   $f0, $f0
/* CAD78 80134678 46006300 */  add.s     $f12, $f12, $f0
/* CAD7C 8013467C 3C0141F0 */  lui       $at, 0x41f0
/* CAD80 80134680 44810000 */  mtc1      $at, $f0
/* CAD84 80134684 0804D208 */  j         .L80134820
/* CAD88 80134688 46006301 */   sub.s    $f12, $f12, $f0
.L8013468C:
/* CAD8C 8013468C 0C00A67F */  jal       rand_int
/* CAD90 80134690 2404003C */   addiu    $a0, $zero, 0x3c
/* CAD94 80134694 00101880 */  sll       $v1, $s0, 2
/* CAD98 80134698 00701821 */  addu      $v1, $v1, $s0
/* CAD9C 8013469C 00031880 */  sll       $v1, $v1, 2
/* CADA0 801346A0 00701823 */  subu      $v1, $v1, $s0
/* CADA4 801346A4 000320C0 */  sll       $a0, $v1, 3
/* CADA8 801346A8 00641821 */  addu      $v1, $v1, $a0
/* CADAC 801346AC 000318C0 */  sll       $v1, $v1, 3
/* CADB0 801346B0 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* CADB4 801346B4 00230821 */  addu      $at, $at, $v1
/* CADB8 801346B8 C42C1DEC */  lwc1      $f12, %lo(gCameras+0x6C)($at)
/* CADBC 801346BC 3C0142B4 */  lui       $at, 0x42b4
/* CADC0 801346C0 44810000 */  mtc1      $at, $f0
/* CADC4 801346C4 00000000 */  nop
/* CADC8 801346C8 46006301 */  sub.s     $f12, $f12, $f0
/* CADCC 801346CC 44820000 */  mtc1      $v0, $f0
/* CADD0 801346D0 00000000 */  nop
/* CADD4 801346D4 46800020 */  cvt.s.w   $f0, $f0
/* CADD8 801346D8 46006300 */  add.s     $f12, $f12, $f0
/* CADDC 801346DC 3C0141F0 */  lui       $at, 0x41f0
/* CADE0 801346E0 44810000 */  mtc1      $at, $f0
/* CADE4 801346E4 0804D208 */  j         .L80134820
/* CADE8 801346E8 46006301 */   sub.s    $f12, $f12, $f0
.L801346EC:
/* CADEC 801346EC 0C00A67F */  jal       rand_int
/* CADF0 801346F0 24042710 */   addiu    $a0, $zero, 0x2710
/* CADF4 801346F4 28421388 */  slti      $v0, $v0, 0x1388
/* CADF8 801346F8 10400019 */  beqz      $v0, .L80134760
/* CADFC 801346FC 00000000 */   nop
/* CAE00 80134700 0C00A67F */  jal       rand_int
/* CAE04 80134704 2404003C */   addiu    $a0, $zero, 0x3c
/* CAE08 80134708 00101880 */  sll       $v1, $s0, 2
/* CAE0C 8013470C 00701821 */  addu      $v1, $v1, $s0
/* CAE10 80134710 00031880 */  sll       $v1, $v1, 2
/* CAE14 80134714 00701823 */  subu      $v1, $v1, $s0
/* CAE18 80134718 000320C0 */  sll       $a0, $v1, 3
/* CAE1C 8013471C 00641821 */  addu      $v1, $v1, $a0
/* CAE20 80134720 000318C0 */  sll       $v1, $v1, 3
/* CAE24 80134724 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* CAE28 80134728 00230821 */  addu      $at, $at, $v1
/* CAE2C 8013472C C42C1DEC */  lwc1      $f12, %lo(gCameras+0x6C)($at)
/* CAE30 80134730 3C0142B4 */  lui       $at, 0x42b4
/* CAE34 80134734 44810000 */  mtc1      $at, $f0
/* CAE38 80134738 00000000 */  nop
/* CAE3C 8013473C 46006300 */  add.s     $f12, $f12, $f0
/* CAE40 80134740 44820000 */  mtc1      $v0, $f0
/* CAE44 80134744 00000000 */  nop
/* CAE48 80134748 46800020 */  cvt.s.w   $f0, $f0
/* CAE4C 8013474C 46006300 */  add.s     $f12, $f12, $f0
/* CAE50 80134750 3C0141F0 */  lui       $at, 0x41f0
/* CAE54 80134754 44810000 */  mtc1      $at, $f0
/* CAE58 80134758 0804D208 */  j         .L80134820
/* CAE5C 8013475C 46006301 */   sub.s    $f12, $f12, $f0
.L80134760:
/* CAE60 80134760 0C00A67F */  jal       rand_int
/* CAE64 80134764 2404003C */   addiu    $a0, $zero, 0x3c
/* CAE68 80134768 00101880 */  sll       $v1, $s0, 2
/* CAE6C 8013476C 00701821 */  addu      $v1, $v1, $s0
/* CAE70 80134770 00031880 */  sll       $v1, $v1, 2
/* CAE74 80134774 00701823 */  subu      $v1, $v1, $s0
/* CAE78 80134778 000320C0 */  sll       $a0, $v1, 3
/* CAE7C 8013477C 00641821 */  addu      $v1, $v1, $a0
/* CAE80 80134780 000318C0 */  sll       $v1, $v1, 3
/* CAE84 80134784 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* CAE88 80134788 00230821 */  addu      $at, $at, $v1
/* CAE8C 8013478C C42C1DEC */  lwc1      $f12, %lo(gCameras+0x6C)($at)
/* CAE90 80134790 3C0142B4 */  lui       $at, 0x42b4
/* CAE94 80134794 44810000 */  mtc1      $at, $f0
/* CAE98 80134798 00000000 */  nop
/* CAE9C 8013479C 46006301 */  sub.s     $f12, $f12, $f0
/* CAEA0 801347A0 44820000 */  mtc1      $v0, $f0
/* CAEA4 801347A4 00000000 */  nop
/* CAEA8 801347A8 46800020 */  cvt.s.w   $f0, $f0
/* CAEAC 801347AC 46006300 */  add.s     $f12, $f12, $f0
/* CAEB0 801347B0 3C0141F0 */  lui       $at, 0x41f0
/* CAEB4 801347B4 44810000 */  mtc1      $at, $f0
/* CAEB8 801347B8 0804D208 */  j         .L80134820
/* CAEBC 801347BC 46006301 */   sub.s    $f12, $f12, $f0
.L801347C0:
/* CAEC0 801347C0 0C00A67F */  jal       rand_int
/* CAEC4 801347C4 24040078 */   addiu    $a0, $zero, 0x78
/* CAEC8 801347C8 00101880 */  sll       $v1, $s0, 2
/* CAECC 801347CC 00701821 */  addu      $v1, $v1, $s0
/* CAED0 801347D0 00031880 */  sll       $v1, $v1, 2
/* CAED4 801347D4 00701823 */  subu      $v1, $v1, $s0
/* CAED8 801347D8 000320C0 */  sll       $a0, $v1, 3
/* CAEDC 801347DC 00641821 */  addu      $v1, $v1, $a0
/* CAEE0 801347E0 000318C0 */  sll       $v1, $v1, 3
/* CAEE4 801347E4 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* CAEE8 801347E8 00230821 */  addu      $at, $at, $v1
/* CAEEC 801347EC C42C1DEC */  lwc1      $f12, %lo(gCameras+0x6C)($at)
/* CAEF0 801347F0 3C0142B4 */  lui       $at, 0x42b4
/* CAEF4 801347F4 44810000 */  mtc1      $at, $f0
/* CAEF8 801347F8 00000000 */  nop
/* CAEFC 801347FC 46006300 */  add.s     $f12, $f12, $f0
.L80134800:
/* CAF00 80134800 44820000 */  mtc1      $v0, $f0
/* CAF04 80134804 00000000 */  nop
/* CAF08 80134808 46800020 */  cvt.s.w   $f0, $f0
/* CAF0C 8013480C 46006300 */  add.s     $f12, $f12, $f0
/* CAF10 80134810 3C014270 */  lui       $at, 0x4270
/* CAF14 80134814 44810000 */  mtc1      $at, $f0
/* CAF18 80134818 00000000 */  nop
/* CAF1C 8013481C 46006301 */  sub.s     $f12, $f12, $f0
.L80134820:
/* CAF20 80134820 0C00A6C9 */  jal       clamp_angle
/* CAF24 80134824 00000000 */   nop
/* CAF28 80134828 E6200018 */  swc1      $f0, 0x18($s1)
.L8013482C:
/* CAF2C 8013482C 8E420000 */  lw        $v0, ($s2)
/* CAF30 80134830 3C030100 */  lui       $v1, 0x100
/* CAF34 80134834 00431024 */  and       $v0, $v0, $v1
/* CAF38 80134838 14400019 */  bnez      $v0, .L801348A0
/* CAF3C 8013483C 00000000 */   nop
/* CAF40 80134840 0C00A67F */  jal       rand_int
/* CAF44 80134844 240407D0 */   addiu    $a0, $zero, 0x7d0
/* CAF48 80134848 C6240018 */  lwc1      $f4, 0x18($s1)
/* CAF4C 8013484C 3C0140C9 */  lui       $at, 0x40c9
/* CAF50 80134850 34210FD0 */  ori       $at, $at, 0xfd0
/* CAF54 80134854 44811000 */  mtc1      $at, $f2
/* CAF58 80134858 3C01447A */  lui       $at, 0x447a
/* CAF5C 8013485C 44810000 */  mtc1      $at, $f0
/* CAF60 80134860 46022102 */  mul.s     $f4, $f4, $f2
/* CAF64 80134864 00000000 */  nop
/* CAF68 80134868 4482C000 */  mtc1      $v0, $f24
/* CAF6C 8013486C 00000000 */  nop
/* CAF70 80134870 4680C620 */  cvt.s.w   $f24, $f24
/* CAF74 80134874 4600C003 */  div.s     $f0, $f24, $f0
/* CAF78 80134878 3C013FF8 */  lui       $at, 0x3ff8
/* CAF7C 8013487C 44811800 */  mtc1      $at, $f3
/* CAF80 80134880 44801000 */  mtc1      $zero, $f2
/* CAF84 80134884 46000021 */  cvt.d.s   $f0, $f0
/* CAF88 80134888 46220000 */  add.d     $f0, $f0, $f2
/* CAF8C 8013488C 3C0143B4 */  lui       $at, 0x43b4
/* CAF90 80134890 44811000 */  mtc1      $at, $f2
/* CAF94 80134894 46200620 */  cvt.s.d   $f24, $f0
/* CAF98 80134898 0804D272 */  j         .L801349C8
/* CAF9C 8013489C 46022503 */   div.s    $f20, $f4, $f2
.L801348A0:
/* CAFA0 801348A0 0C00A67F */  jal       rand_int
/* CAFA4 801348A4 240407D0 */   addiu    $a0, $zero, 0x7d0
/* CAFA8 801348A8 C6240018 */  lwc1      $f4, 0x18($s1)
/* CAFAC 801348AC 3C0140C9 */  lui       $at, 0x40c9
/* CAFB0 801348B0 34210FD0 */  ori       $at, $at, 0xfd0
/* CAFB4 801348B4 44811000 */  mtc1      $at, $f2
/* CAFB8 801348B8 3C01447A */  lui       $at, 0x447a
/* CAFBC 801348BC 44810000 */  mtc1      $at, $f0
/* CAFC0 801348C0 46022102 */  mul.s     $f4, $f4, $f2
/* CAFC4 801348C4 00000000 */  nop
/* CAFC8 801348C8 4482C000 */  mtc1      $v0, $f24
/* CAFCC 801348CC 00000000 */  nop
/* CAFD0 801348D0 4680C620 */  cvt.s.w   $f24, $f24
/* CAFD4 801348D4 4600C003 */  div.s     $f0, $f24, $f0
/* CAFD8 801348D8 3C014000 */  lui       $at, 0x4000
/* CAFDC 801348DC 44811800 */  mtc1      $at, $f3
/* CAFE0 801348E0 44801000 */  mtc1      $zero, $f2
/* CAFE4 801348E4 46000021 */  cvt.d.s   $f0, $f0
/* CAFE8 801348E8 46220000 */  add.d     $f0, $f0, $f2
/* CAFEC 801348EC 3C0143B4 */  lui       $at, 0x43b4
/* CAFF0 801348F0 44811000 */  mtc1      $at, $f2
/* CAFF4 801348F4 46200620 */  cvt.s.d   $f24, $f0
/* CAFF8 801348F8 0804D272 */  j         .L801349C8
/* CAFFC 801348FC 46022503 */   div.s    $f20, $f4, $f2
.L80134900:
/* CB000 80134900 44826000 */  mtc1      $v0, $f12
/* CB004 80134904 00000000 */  nop
/* CB008 80134908 0C00A6C9 */  jal       clamp_angle
/* CB00C 8013490C 46806320 */   cvt.s.w  $f12, $f12
/* CB010 80134910 E6200018 */  swc1      $f0, 0x18($s1)
/* CB014 80134914 8E420000 */  lw        $v0, ($s2)
/* CB018 80134918 3C034000 */  lui       $v1, 0x4000
/* CB01C 8013491C 00431024 */  and       $v0, $v0, $v1
/* CB020 80134920 1440001B */  bnez      $v0, .L80134990
/* CB024 80134924 3C04B60B */   lui      $a0, 0xb60b
/* CB028 80134928 9643001E */  lhu       $v1, 0x1e($s2)
/* CB02C 8013492C 348460B7 */  ori       $a0, $a0, 0x60b7
/* CB030 80134930 00031C00 */  sll       $v1, $v1, 0x10
/* CB034 80134934 00031403 */  sra       $v0, $v1, 0x10
/* CB038 80134938 00440018 */  mult      $v0, $a0
/* CB03C 8013493C 3C018015 */  lui       $at, %hi(D_80150E18)
/* CB040 80134940 D4220E18 */  ldc1      $f2, %lo(D_80150E18)($at)
/* CB044 80134944 00031FC3 */  sra       $v1, $v1, 0x1f
/* CB048 80134948 00004010 */  mfhi      $t0
/* CB04C 8013494C 01021021 */  addu      $v0, $t0, $v0
/* CB050 80134950 00021203 */  sra       $v0, $v0, 8
/* CB054 80134954 00431023 */  subu      $v0, $v0, $v1
/* CB058 80134958 00021400 */  sll       $v0, $v0, 0x10
/* CB05C 8013495C 00021403 */  sra       $v0, $v0, 0x10
/* CB060 80134960 44820000 */  mtc1      $v0, $f0
/* CB064 80134964 00000000 */  nop
/* CB068 80134968 46800021 */  cvt.d.w   $f0, $f0
/* CB06C 8013496C 46220002 */  mul.d     $f0, $f0, $f2
/* CB070 80134970 00000000 */  nop
/* CB074 80134974 3C013FF8 */  lui       $at, 0x3ff8
/* CB078 80134978 44811800 */  mtc1      $at, $f3
/* CB07C 8013497C 44801000 */  mtc1      $zero, $f2
/* CB080 80134980 00000000 */  nop
/* CB084 80134984 46220000 */  add.d     $f0, $f0, $f2
/* CB088 80134988 0804D267 */  j         .L8013499C
/* CB08C 8013498C 46200620 */   cvt.s.d  $f24, $f0
.L80134990:
/* CB090 80134990 3C014006 */  lui       $at, 0x4006
/* CB094 80134994 34216666 */  ori       $at, $at, 0x6666
/* CB098 80134998 4481C000 */  mtc1      $at, $f24
.L8013499C:
/* CB09C 8013499C C6200018 */  lwc1      $f0, 0x18($s1)
/* CB0A0 801349A0 3C0140C9 */  lui       $at, 0x40c9
/* CB0A4 801349A4 34210FD0 */  ori       $at, $at, 0xfd0
/* CB0A8 801349A8 44811000 */  mtc1      $at, $f2
/* CB0AC 801349AC 00000000 */  nop
/* CB0B0 801349B0 46020002 */  mul.s     $f0, $f0, $f2
/* CB0B4 801349B4 00000000 */  nop
/* CB0B8 801349B8 3C0143B4 */  lui       $at, 0x43b4
/* CB0BC 801349BC 44811000 */  mtc1      $at, $f2
/* CB0C0 801349C0 00000000 */  nop
/* CB0C4 801349C4 46020503 */  div.s     $f20, $f0, $f2
.L801349C8:
/* CB0C8 801349C8 0C00A85B */  jal       sin_rad
/* CB0CC 801349CC 4600A306 */   mov.s    $f12, $f20
/* CB0D0 801349D0 46000586 */  mov.s     $f22, $f0
/* CB0D4 801349D4 0C00A874 */  jal       cos_rad
/* CB0D8 801349D8 4600A306 */   mov.s    $f12, $f20
/* CB0DC 801349DC 4616C102 */  mul.s     $f4, $f24, $f22
/* CB0E0 801349E0 00000000 */  nop
/* CB0E4 801349E4 4600C087 */  neg.s     $f2, $f24
/* CB0E8 801349E8 46001082 */  mul.s     $f2, $f2, $f0
/* CB0EC 801349EC 00000000 */  nop
/* CB0F0 801349F0 E6240010 */  swc1      $f4, 0x10($s1)
/* CB0F4 801349F4 E6220014 */  swc1      $f2, 0x14($s1)
/* CB0F8 801349F8 8243001B */  lb        $v1, 0x1b($s2)
/* CB0FC 801349FC 24020017 */  addiu     $v0, $zero, 0x17
/* CB100 80134A00 10620004 */  beq       $v1, $v0, .L80134A14
/* CB104 80134A04 240200B4 */   addiu    $v0, $zero, 0xb4
/* CB108 80134A08 AE22001C */  sw        $v0, 0x1c($s1)
/* CB10C 80134A0C 0804D294 */  j         .L80134A50
/* CB110 80134A10 AE200020 */   sw       $zero, 0x20($s1)
.L80134A14:
/* CB114 80134A14 8E420000 */  lw        $v0, ($s2)
/* CB118 80134A18 3C030040 */  lui       $v1, 0x40
/* CB11C 80134A1C 00431024 */  and       $v0, $v0, $v1
/* CB120 80134A20 14400002 */  bnez      $v0, .L80134A2C
/* CB124 80134A24 24020014 */   addiu    $v0, $zero, 0x14
/* CB128 80134A28 24020011 */  addiu     $v0, $zero, 0x11
.L80134A2C:
/* CB12C 80134A2C AE22001C */  sw        $v0, 0x1c($s1)
/* CB130 80134A30 3C014170 */  lui       $at, 0x4170
/* CB134 80134A34 44810000 */  mtc1      $at, $f0
/* CB138 80134A38 3C013FCC */  lui       $at, 0x3fcc
/* CB13C 80134A3C 3421CCCD */  ori       $at, $at, 0xcccd
/* CB140 80134A40 44811000 */  mtc1      $at, $f2
/* CB144 80134A44 AE200020 */  sw        $zero, 0x20($s1)
/* CB148 80134A48 E6200000 */  swc1      $f0, ($s1)
/* CB14C 80134A4C E6220004 */  swc1      $f2, 4($s1)
.L80134A50:
/* CB150 80134A50 8243001B */  lb        $v1, 0x1b($s2)
/* CB154 80134A54 24020014 */  addiu     $v0, $zero, 0x14
/* CB158 80134A58 14620008 */  bne       $v1, $v0, .L80134A7C
/* CB15C 80134A5C 2402000C */   addiu    $v0, $zero, 0xc
/* CB160 80134A60 2402003C */  addiu     $v0, $zero, 0x3c
/* CB164 80134A64 AE22001C */  sw        $v0, 0x1c($s1)
/* CB168 80134A68 AE200020 */  sw        $zero, 0x20($s1)
/* CB16C 80134A6C AE200010 */  sw        $zero, 0x10($s1)
/* CB170 80134A70 AE200014 */  sw        $zero, 0x14($s1)
/* CB174 80134A74 8243001B */  lb        $v1, 0x1b($s2)
/* CB178 80134A78 2402000C */  addiu     $v0, $zero, 0xc
.L80134A7C:
/* CB17C 80134A7C 14620005 */  bne       $v1, $v0, .L80134A94
/* CB180 80134A80 24020001 */   addiu    $v0, $zero, 1
/* CB184 80134A84 AE200000 */  sw        $zero, ($s1)
/* CB188 80134A88 AE200010 */  sw        $zero, 0x10($s1)
/* CB18C 80134A8C AE200014 */  sw        $zero, 0x14($s1)
/* CB190 80134A90 AE220020 */  sw        $v0, 0x20($s1)
.L80134A94:
/* CB194 80134A94 8243001B */  lb        $v1, 0x1b($s2)
/* CB198 80134A98 24020010 */  addiu     $v0, $zero, 0x10
/* CB19C 80134A9C 14620005 */  bne       $v1, $v0, .L80134AB4
/* CB1A0 80134AA0 24020001 */   addiu    $v0, $zero, 1
/* CB1A4 80134AA4 AE200000 */  sw        $zero, ($s1)
/* CB1A8 80134AA8 AE200010 */  sw        $zero, 0x10($s1)
/* CB1AC 80134AAC AE200014 */  sw        $zero, 0x14($s1)
/* CB1B0 80134AB0 AE220020 */  sw        $v0, 0x20($s1)
.L80134AB4:
/* CB1B4 80134AB4 8E420000 */  lw        $v0, ($s2)
/* CB1B8 80134AB8 30420800 */  andi      $v0, $v0, 0x800
/* CB1BC 80134ABC 1040019C */  beqz      $v0, .L80135130
/* CB1C0 80134AC0 24020001 */   addiu    $v0, $zero, 1
/* CB1C4 80134AC4 86440004 */  lh        $a0, 4($s2)
/* CB1C8 80134AC8 0C051514 */  jal       set_global_flag
/* CB1CC 80134ACC 00000000 */   nop
/* CB1D0 80134AD0 0804D44C */  j         .L80135130
/* CB1D4 80134AD4 24020001 */   addiu    $v0, $zero, 1
.L80134AD8:
/* CB1D8 80134AD8 8E510014 */  lw        $s1, 0x14($s2)
/* CB1DC 80134ADC 1062000A */  beq       $v1, $v0, .L80134B08
/* CB1E0 80134AE0 00000000 */   nop
/* CB1E4 80134AE4 10650008 */  beq       $v1, $a1, .L80134B08
/* CB1E8 80134AE8 00000000 */   nop
/* CB1EC 80134AEC 8E220020 */  lw        $v0, 0x20($s1)
/* CB1F0 80134AF0 10400005 */  beqz      $v0, .L80134B08
/* CB1F4 80134AF4 00000000 */   nop
/* CB1F8 80134AF8 0C04CEC3 */  jal       test_item_player_collision
/* CB1FC 80134AFC 0240202D */   daddu    $a0, $s2, $zero
/* CB200 80134B00 1440018B */  bnez      $v0, .L80135130
/* CB204 80134B04 24020003 */   addiu    $v0, $zero, 3
.L80134B08:
/* CB208 80134B08 8E430000 */  lw        $v1, ($s2)
/* CB20C 80134B0C 30620200 */  andi      $v0, $v1, 0x200
/* CB210 80134B10 14400010 */  bnez      $v0, .L80134B54
/* CB214 80134B14 30622000 */   andi     $v0, $v1, 0x2000
/* CB218 80134B18 3C02800A */  lui       $v0, %hi(gOverrideFlags)
/* CB21C 80134B1C 8C42A650 */  lw        $v0, %lo(gOverrideFlags)($v0)
/* CB220 80134B20 30420300 */  andi      $v0, $v0, 0x300
/* CB224 80134B24 1440000B */  bnez      $v0, .L80134B54
/* CB228 80134B28 30622000 */   andi     $v0, $v1, 0x2000
/* CB22C 80134B2C 3C020020 */  lui       $v0, 0x20
/* CB230 80134B30 00621024 */  and       $v0, $v1, $v0
/* CB234 80134B34 14400007 */  bnez      $v0, .L80134B54
/* CB238 80134B38 30622000 */   andi     $v0, $v1, 0x2000
/* CB23C 80134B3C 8E22001C */  lw        $v0, 0x1c($s1)
/* CB240 80134B40 2442FFFF */  addiu     $v0, $v0, -1
/* CB244 80134B44 04400179 */  bltz      $v0, .L8013512C
/* CB248 80134B48 AE22001C */   sw       $v0, 0x1c($s1)
/* CB24C 80134B4C 8E430000 */  lw        $v1, ($s2)
/* CB250 80134B50 30622000 */  andi      $v0, $v1, 0x2000
.L80134B54:
/* CB254 80134B54 1440001F */  bnez      $v0, .L80134BD4
/* CB258 80134B58 3C020020 */   lui      $v0, 0x20
/* CB25C 80134B5C 00621024 */  and       $v0, $v1, $v0
/* CB260 80134B60 1440001C */  bnez      $v0, .L80134BD4
/* CB264 80134B64 00000000 */   nop
/* CB268 80134B68 C6240000 */  lwc1      $f4, ($s1)
/* CB26C 80134B6C C6200004 */  lwc1      $f0, 4($s1)
/* CB270 80134B70 46002101 */  sub.s     $f4, $f4, $f0
/* CB274 80134B74 3C01C030 */  lui       $at, 0xc030
/* CB278 80134B78 44811800 */  mtc1      $at, $f3
/* CB27C 80134B7C 44801000 */  mtc1      $zero, $f2
/* CB280 80134B80 46002021 */  cvt.d.s   $f0, $f4
/* CB284 80134B84 4622003C */  c.lt.d    $f0, $f2
/* CB288 80134B88 00000000 */  nop
/* CB28C 80134B8C 45000005 */  bc1f      .L80134BA4
/* CB290 80134B90 E6240000 */   swc1     $f4, ($s1)
/* CB294 80134B94 3C01C180 */  lui       $at, 0xc180
/* CB298 80134B98 44810000 */  mtc1      $at, $f0
/* CB29C 80134B9C 00000000 */  nop
/* CB2A0 80134BA0 E6200000 */  swc1      $f0, ($s1)
.L80134BA4:
/* CB2A4 80134BA4 C640000C */  lwc1      $f0, 0xc($s2)
/* CB2A8 80134BA8 C6220000 */  lwc1      $f2, ($s1)
/* CB2AC 80134BAC 46020000 */  add.s     $f0, $f0, $f2
/* CB2B0 80134BB0 E640000C */  swc1      $f0, 0xc($s2)
/* CB2B4 80134BB4 C6400008 */  lwc1      $f0, 8($s2)
/* CB2B8 80134BB8 C6220010 */  lwc1      $f2, 0x10($s1)
/* CB2BC 80134BBC 46020000 */  add.s     $f0, $f0, $f2
/* CB2C0 80134BC0 E6400008 */  swc1      $f0, 8($s2)
/* CB2C4 80134BC4 C6400010 */  lwc1      $f0, 0x10($s2)
/* CB2C8 80134BC8 C6220014 */  lwc1      $f2, 0x14($s1)
/* CB2CC 80134BCC 46020000 */  add.s     $f0, $f0, $f2
/* CB2D0 80134BD0 E6400010 */  swc1      $f0, 0x10($s2)
.L80134BD4:
/* CB2D4 80134BD4 8243001B */  lb        $v1, 0x1b($s2)
/* CB2D8 80134BD8 24020014 */  addiu     $v0, $zero, 0x14
/* CB2DC 80134BDC 14620008 */  bne       $v1, $v0, .L80134C00
/* CB2E0 80134BE0 00000000 */   nop
/* CB2E4 80134BE4 C6220000 */  lwc1      $f2, ($s1)
/* CB2E8 80134BE8 44800000 */  mtc1      $zero, $f0
/* CB2EC 80134BEC 00000000 */  nop
/* CB2F0 80134BF0 4600103E */  c.le.s    $f2, $f0
/* CB2F4 80134BF4 00000000 */  nop
/* CB2F8 80134BF8 4501014D */  bc1t      .L80135130
/* CB2FC 80134BFC 24020003 */   addiu    $v0, $zero, 3
.L80134C00:
/* CB300 80134C00 8E420000 */  lw        $v0, ($s2)
/* CB304 80134C04 3C033000 */  lui       $v1, 0x3000
/* CB308 80134C08 00431024 */  and       $v0, $v0, $v1
/* CB30C 80134C0C 14400088 */  bnez      $v0, .L80134E30
/* CB310 80134C10 24020014 */   addiu    $v0, $zero, 0x14
/* CB314 80134C14 8243001B */  lb        $v1, 0x1b($s2)
/* CB318 80134C18 10620025 */  beq       $v1, $v0, .L80134CB0
/* CB31C 80134C1C 24020017 */   addiu    $v0, $zero, 0x17
/* CB320 80134C20 10620023 */  beq       $v1, $v0, .L80134CB0
/* CB324 80134C24 00000000 */   nop
/* CB328 80134C28 C6220000 */  lwc1      $f2, ($s1)
/* CB32C 80134C2C 44800000 */  mtc1      $zero, $f0
/* CB330 80134C30 00000000 */  nop
/* CB334 80134C34 4602003C */  c.lt.s    $f0, $f2
/* CB338 80134C38 00000000 */  nop
/* CB33C 80134C3C 4500001C */  bc1f      .L80134CB0
/* CB340 80134C40 27A2002C */   addiu    $v0, $sp, 0x2c
/* CB344 80134C44 C6400008 */  lwc1      $f0, 8($s2)
/* CB348 80134C48 C638000C */  lwc1      $f24, 0xc($s1)
/* CB34C 80134C4C E7A00020 */  swc1      $f0, 0x20($sp)
/* CB350 80134C50 C642000C */  lwc1      $f2, 0xc($s2)
/* CB354 80134C54 C6440010 */  lwc1      $f4, 0x10($s2)
/* CB358 80134C58 C6200000 */  lwc1      $f0, ($s1)
/* CB35C 80134C5C 4600C000 */  add.s     $f0, $f24, $f0
/* CB360 80134C60 E7A20024 */  swc1      $f2, 0x24($sp)
/* CB364 80134C64 E7A40028 */  swc1      $f4, 0x28($sp)
/* CB368 80134C68 E7A0002C */  swc1      $f0, 0x2c($sp)
/* CB36C 80134C6C AFA20010 */  sw        $v0, 0x10($sp)
/* CB370 80134C70 3C040002 */  lui       $a0, 2
/* CB374 80134C74 27A50020 */  addiu     $a1, $sp, 0x20
/* CB378 80134C78 27A60024 */  addiu     $a2, $sp, 0x24
/* CB37C 80134C7C 0C03739C */  jal       npc_raycast_up
/* CB380 80134C80 27A70028 */   addiu    $a3, $sp, 0x28
/* CB384 80134C84 1040000A */  beqz      $v0, .L80134CB0
/* CB388 80134C88 00000000 */   nop
/* CB38C 80134C8C C7A0002C */  lwc1      $f0, 0x2c($sp)
/* CB390 80134C90 4618003C */  c.lt.s    $f0, $f24
/* CB394 80134C94 00000000 */  nop
/* CB398 80134C98 45000005 */  bc1f      .L80134CB0
/* CB39C 80134C9C 00000000 */   nop
/* CB3A0 80134CA0 C7A00024 */  lwc1      $f0, 0x24($sp)
/* CB3A4 80134CA4 46180001 */  sub.s     $f0, $f0, $f24
/* CB3A8 80134CA8 E640000C */  swc1      $f0, 0xc($s2)
/* CB3AC 80134CAC AE200000 */  sw        $zero, ($s1)
.L80134CB0:
/* CB3B0 80134CB0 8E420000 */  lw        $v0, ($s2)
/* CB3B4 80134CB4 3C033000 */  lui       $v1, 0x3000
/* CB3B8 80134CB8 00431024 */  and       $v0, $v0, $v1
/* CB3BC 80134CBC 1440005C */  bnez      $v0, .L80134E30
/* CB3C0 80134CC0 24020014 */   addiu    $v0, $zero, 0x14
/* CB3C4 80134CC4 8243001B */  lb        $v1, 0x1b($s2)
/* CB3C8 80134CC8 10620059 */  beq       $v1, $v0, .L80134E30
/* CB3CC 80134CCC 24020017 */   addiu    $v0, $zero, 0x17
/* CB3D0 80134CD0 10620057 */  beq       $v1, $v0, .L80134E30
/* CB3D4 80134CD4 00000000 */   nop
/* CB3D8 80134CD8 C6200010 */  lwc1      $f0, 0x10($s1)
/* CB3DC 80134CDC 44803000 */  mtc1      $zero, $f6
/* CB3E0 80134CE0 00000000 */  nop
/* CB3E4 80134CE4 46060032 */  c.eq.s    $f0, $f6
/* CB3E8 80134CE8 00000000 */  nop
/* CB3EC 80134CEC 45000006 */  bc1f      .L80134D08
/* CB3F0 80134CF0 00000000 */   nop
/* CB3F4 80134CF4 C6200014 */  lwc1      $f0, 0x14($s1)
/* CB3F8 80134CF8 46060032 */  c.eq.s    $f0, $f6
/* CB3FC 80134CFC 00000000 */  nop
/* CB400 80134D00 4501004B */  bc1t      .L80134E30
/* CB404 80134D04 00000000 */   nop
.L80134D08:
/* CB408 80134D08 C6400008 */  lwc1      $f0, 8($s2)
/* CB40C 80134D0C C642000C */  lwc1      $f2, 0xc($s2)
/* CB410 80134D10 C6440010 */  lwc1      $f4, 0x10($s2)
/* CB414 80134D14 8E220020 */  lw        $v0, 0x20($s1)
/* CB418 80134D18 E7A00020 */  swc1      $f0, 0x20($sp)
/* CB41C 80134D1C E7A20024 */  swc1      $f2, 0x24($sp)
/* CB420 80134D20 1440000F */  bnez      $v0, .L80134D60
/* CB424 80134D24 E7A40028 */   swc1     $f4, 0x28($sp)
/* CB428 80134D28 3C040002 */  lui       $a0, 2
/* CB42C 80134D2C E7A60010 */  swc1      $f6, 0x10($sp)
/* CB430 80134D30 C6200018 */  lwc1      $f0, 0x18($s1)
/* CB434 80134D34 27A50020 */  addiu     $a1, $sp, 0x20
/* CB438 80134D38 E7A00014 */  swc1      $f0, 0x14($sp)
/* CB43C 80134D3C C620000C */  lwc1      $f0, 0xc($s1)
/* CB440 80134D40 27A60024 */  addiu     $a2, $sp, 0x24
/* CB444 80134D44 E7A00018 */  swc1      $f0, 0x18($sp)
/* CB448 80134D48 C6200008 */  lwc1      $f0, 8($s1)
/* CB44C 80134D4C 27A70028 */  addiu     $a3, $sp, 0x28
/* CB450 80134D50 0C037765 */  jal       npc_test_move_complex_with_slipping
/* CB454 80134D54 E7A0001C */   swc1     $f0, 0x1c($sp)
/* CB458 80134D58 0804D364 */  j         .L80134D90
/* CB45C 80134D5C 00000000 */   nop
.L80134D60:
/* CB460 80134D60 3C040002 */  lui       $a0, 2
/* CB464 80134D64 E7A60010 */  swc1      $f6, 0x10($sp)
/* CB468 80134D68 C6200018 */  lwc1      $f0, 0x18($s1)
/* CB46C 80134D6C 27A50020 */  addiu     $a1, $sp, 0x20
/* CB470 80134D70 E7A00014 */  swc1      $f0, 0x14($sp)
/* CB474 80134D74 C620000C */  lwc1      $f0, 0xc($s1)
/* CB478 80134D78 27A60024 */  addiu     $a2, $sp, 0x24
/* CB47C 80134D7C E7A00018 */  swc1      $f0, 0x18($sp)
/* CB480 80134D80 C6200008 */  lwc1      $f0, 8($s1)
/* CB484 80134D84 27A70028 */  addiu     $a3, $sp, 0x28
/* CB488 80134D88 0C037711 */  jal       npc_test_move_simple_with_slipping
/* CB48C 80134D8C E7A0001C */   swc1     $f0, 0x1c($sp)
.L80134D90:
/* CB490 80134D90 10400027 */  beqz      $v0, .L80134E30
/* CB494 80134D94 00000000 */   nop
/* CB498 80134D98 C7A00020 */  lwc1      $f0, 0x20($sp)
/* CB49C 80134D9C C7A20024 */  lwc1      $f2, 0x24($sp)
/* CB4A0 80134DA0 C7A40028 */  lwc1      $f4, 0x28($sp)
/* CB4A4 80134DA4 3C014334 */  lui       $at, 0x4334
/* CB4A8 80134DA8 44816000 */  mtc1      $at, $f12
/* CB4AC 80134DAC E6400008 */  swc1      $f0, 8($s2)
/* CB4B0 80134DB0 E642000C */  swc1      $f2, 0xc($s2)
/* CB4B4 80134DB4 E6440010 */  swc1      $f4, 0x10($s2)
/* CB4B8 80134DB8 C6200018 */  lwc1      $f0, 0x18($s1)
/* CB4BC 80134DBC 0C00A6C9 */  jal       clamp_angle
/* CB4C0 80134DC0 460C0300 */   add.s    $f12, $f0, $f12
/* CB4C4 80134DC4 3C0140C9 */  lui       $at, 0x40c9
/* CB4C8 80134DC8 34210FD0 */  ori       $at, $at, 0xfd0
/* CB4CC 80134DCC 44811000 */  mtc1      $at, $f2
/* CB4D0 80134DD0 00000000 */  nop
/* CB4D4 80134DD4 46020082 */  mul.s     $f2, $f0, $f2
/* CB4D8 80134DD8 00000000 */  nop
/* CB4DC 80134DDC 3C0143B4 */  lui       $at, 0x43b4
/* CB4E0 80134DE0 44812000 */  mtc1      $at, $f4
/* CB4E4 80134DE4 E6200018 */  swc1      $f0, 0x18($s1)
/* CB4E8 80134DE8 46041503 */  div.s     $f20, $f2, $f4
/* CB4EC 80134DEC 0C00A85B */  jal       sin_rad
/* CB4F0 80134DF0 4600A306 */   mov.s    $f12, $f20
/* CB4F4 80134DF4 46000586 */  mov.s     $f22, $f0
/* CB4F8 80134DF8 0C00A874 */  jal       cos_rad
/* CB4FC 80134DFC 4600A306 */   mov.s    $f12, $f20
/* CB500 80134E00 3C01C000 */  lui       $at, 0xc000
/* CB504 80134E04 44811800 */  mtc1      $at, $f3
/* CB508 80134E08 44801000 */  mtc1      $zero, $f2
/* CB50C 80134E0C 46000021 */  cvt.d.s   $f0, $f0
/* CB510 80134E10 46220002 */  mul.d     $f0, $f0, $f2
/* CB514 80134E14 00000000 */  nop
/* CB518 80134E18 4600B0A1 */  cvt.d.s   $f2, $f22
/* CB51C 80134E1C 46221080 */  add.d     $f2, $f2, $f2
/* CB520 80134E20 462010A0 */  cvt.s.d   $f2, $f2
/* CB524 80134E24 E6220010 */  swc1      $f2, 0x10($s1)
/* CB528 80134E28 46200020 */  cvt.s.d   $f0, $f0
/* CB52C 80134E2C E6200014 */  swc1      $f0, 0x14($s1)
.L80134E30:
/* CB530 80134E30 8E420000 */  lw        $v0, ($s2)
/* CB534 80134E34 3C031000 */  lui       $v1, 0x1000
/* CB538 80134E38 00431024 */  and       $v0, $v0, $v1
/* CB53C 80134E3C 144000B3 */  bnez      $v0, .L8013510C
/* CB540 80134E40 24020014 */   addiu    $v0, $zero, 0x14
/* CB544 80134E44 8243001B */  lb        $v1, 0x1b($s2)
/* CB548 80134E48 106200B0 */  beq       $v1, $v0, .L8013510C
/* CB54C 80134E4C 00000000 */   nop
/* CB550 80134E50 C6200000 */  lwc1      $f0, ($s1)
/* CB554 80134E54 44801000 */  mtc1      $zero, $f2
/* CB558 80134E58 44801800 */  mtc1      $zero, $f3
/* CB55C 80134E5C 46000021 */  cvt.d.s   $f0, $f0
/* CB560 80134E60 4622003E */  c.le.d    $f0, $f2
/* CB564 80134E64 00000000 */  nop
/* CB568 80134E68 450000A8 */  bc1f      .L8013510C
/* CB56C 80134E6C 24020001 */   addiu    $v0, $zero, 1
/* CB570 80134E70 AE220020 */  sw        $v0, 0x20($s1)
/* CB574 80134E74 8243001B */  lb        $v1, 0x1b($s2)
/* CB578 80134E78 24020017 */  addiu     $v0, $zero, 0x17
/* CB57C 80134E7C 1062002A */  beq       $v1, $v0, .L80134F28
/* CB580 80134E80 00000000 */   nop
/* CB584 80134E84 C642000C */  lwc1      $f2, 0xc($s2)
/* CB588 80134E88 C6200000 */  lwc1      $f0, ($s1)
/* CB58C 80134E8C C6440008 */  lwc1      $f4, 8($s2)
/* CB590 80134E90 46001081 */  sub.s     $f2, $f2, $f0
/* CB594 80134E94 E7A40020 */  swc1      $f4, 0x20($sp)
/* CB598 80134E98 C6200000 */  lwc1      $f0, ($s1)
/* CB59C 80134E9C 3C014140 */  lui       $at, 0x4140
/* CB5A0 80134EA0 44813000 */  mtc1      $at, $f6
/* CB5A4 80134EA4 46000007 */  neg.s     $f0, $f0
/* CB5A8 80134EA8 46060000 */  add.s     $f0, $f0, $f6
/* CB5AC 80134EAC C6440010 */  lwc1      $f4, 0x10($s2)
/* CB5B0 80134EB0 8E220020 */  lw        $v0, 0x20($s1)
/* CB5B4 80134EB4 46061080 */  add.s     $f2, $f2, $f6
/* CB5B8 80134EB8 E7A40028 */  swc1      $f4, 0x28($sp)
/* CB5BC 80134EBC E7A0002C */  swc1      $f0, 0x2c($sp)
/* CB5C0 80134EC0 1440000A */  bnez      $v0, .L80134EEC
/* CB5C4 80134EC4 E7A20024 */   swc1     $f2, 0x24($sp)
/* CB5C8 80134EC8 27A2002C */  addiu     $v0, $sp, 0x2c
/* CB5CC 80134ECC AFA20010 */  sw        $v0, 0x10($sp)
/* CB5D0 80134ED0 3C040002 */  lui       $a0, 2
/* CB5D4 80134ED4 27A50020 */  addiu     $a1, $sp, 0x20
/* CB5D8 80134ED8 27A60024 */  addiu     $a2, $sp, 0x24
/* CB5DC 80134EDC 0C0372DF */  jal       npc_raycast_down_sides
/* CB5E0 80134EE0 27A70028 */   addiu    $a3, $sp, 0x28
/* CB5E4 80134EE4 0804D3E1 */  j         .L80134F84
/* CB5E8 80134EE8 00000000 */   nop
.L80134EEC:
/* CB5EC 80134EEC 3C040002 */  lui       $a0, 2
/* CB5F0 80134EF0 27A50020 */  addiu     $a1, $sp, 0x20
/* CB5F4 80134EF4 27A60024 */  addiu     $a2, $sp, 0x24
/* CB5F8 80134EF8 27A70028 */  addiu     $a3, $sp, 0x28
/* CB5FC 80134EFC 3C014334 */  lui       $at, 0x4334
/* CB600 80134F00 44810000 */  mtc1      $at, $f0
/* CB604 80134F04 3C0141A0 */  lui       $at, 0x41a0
/* CB608 80134F08 44811000 */  mtc1      $at, $f2
/* CB60C 80134F0C 27A2002C */  addiu     $v0, $sp, 0x2c
/* CB610 80134F10 AFA20010 */  sw        $v0, 0x10($sp)
/* CB614 80134F14 E7A00014 */  swc1      $f0, 0x14($sp)
/* CB618 80134F18 0C0371DE */  jal       npc_raycast_down_ahead
/* CB61C 80134F1C E7A20018 */   swc1     $f2, 0x18($sp)
/* CB620 80134F20 0804D3E1 */  j         .L80134F84
/* CB624 80134F24 00000000 */   nop
.L80134F28:
/* CB628 80134F28 C644000C */  lwc1      $f4, 0xc($s2)
/* CB62C 80134F2C C6200000 */  lwc1      $f0, ($s1)
/* CB630 80134F30 C6460008 */  lwc1      $f6, 8($s2)
/* CB634 80134F34 46002101 */  sub.s     $f4, $f4, $f0
/* CB638 80134F38 3C014140 */  lui       $at, 0x4140
/* CB63C 80134F3C 44811000 */  mtc1      $at, $f2
/* CB640 80134F40 44804000 */  mtc1      $zero, $f8
/* CB644 80134F44 46000007 */  neg.s     $f0, $f0
/* CB648 80134F48 46020000 */  add.s     $f0, $f0, $f2
/* CB64C 80134F4C E7A60020 */  swc1      $f6, 0x20($sp)
/* CB650 80134F50 46022100 */  add.s     $f4, $f4, $f2
/* CB654 80134F54 C6420010 */  lwc1      $f2, 0x10($s2)
/* CB658 80134F58 E7A0002C */  swc1      $f0, 0x2c($sp)
/* CB65C 80134F5C 46080180 */  add.s     $f6, $f0, $f8
/* CB660 80134F60 E7A20028 */  swc1      $f2, 0x28($sp)
/* CB664 80134F64 4606203C */  c.lt.s    $f4, $f6
/* CB668 80134F68 00000000 */  nop
/* CB66C 80134F6C 45000004 */  bc1f      .L80134F80
/* CB670 80134F70 E7A40024 */   swc1     $f4, 0x24($sp)
/* CB674 80134F74 E7A80024 */  swc1      $f8, 0x24($sp)
/* CB678 80134F78 0804D3E1 */  j         .L80134F84
/* CB67C 80134F7C 24020001 */   addiu    $v0, $zero, 1
.L80134F80:
/* CB680 80134F80 0000102D */  daddu     $v0, $zero, $zero
.L80134F84:
/* CB684 80134F84 10400061 */  beqz      $v0, .L8013510C
/* CB688 80134F88 00000000 */   nop
/* CB68C 80134F8C C7A00024 */  lwc1      $f0, 0x24($sp)
/* CB690 80134F90 3C013FF4 */  lui       $at, 0x3ff4
/* CB694 80134F94 44811800 */  mtc1      $at, $f3
/* CB698 80134F98 44801000 */  mtc1      $zero, $f2
/* CB69C 80134F9C E640000C */  swc1      $f0, 0xc($s2)
/* CB6A0 80134FA0 C6200000 */  lwc1      $f0, ($s1)
/* CB6A4 80134FA4 3C014008 */  lui       $at, 0x4008
/* CB6A8 80134FA8 44812800 */  mtc1      $at, $f5
/* CB6AC 80134FAC 44802000 */  mtc1      $zero, $f4
/* CB6B0 80134FB0 46000007 */  neg.s     $f0, $f0
/* CB6B4 80134FB4 46000021 */  cvt.d.s   $f0, $f0
/* CB6B8 80134FB8 46220003 */  div.d     $f0, $f0, $f2
/* CB6BC 80134FBC 46200020 */  cvt.s.d   $f0, $f0
/* CB6C0 80134FC0 460000A1 */  cvt.d.s   $f2, $f0
/* CB6C4 80134FC4 4624103C */  c.lt.d    $f2, $f4
/* CB6C8 80134FC8 00000000 */  nop
/* CB6CC 80134FCC 45000009 */  bc1f      .L80134FF4
/* CB6D0 80134FD0 E6200000 */   swc1     $f0, ($s1)
/* CB6D4 80134FD4 AE200000 */  sw        $zero, ($s1)
/* CB6D8 80134FD8 AE200010 */  sw        $zero, 0x10($s1)
/* CB6DC 80134FDC AE200014 */  sw        $zero, 0x14($s1)
/* CB6E0 80134FE0 8E420000 */  lw        $v0, ($s2)
/* CB6E4 80134FE4 3C032000 */  lui       $v1, 0x2000
/* CB6E8 80134FE8 00431025 */  or        $v0, $v0, $v1
/* CB6EC 80134FEC 0804D443 */  j         .L8013510C
/* CB6F0 80134FF0 AE420000 */   sw       $v0, ($s2)
.L80134FF4:
/* CB6F4 80134FF4 96430018 */  lhu       $v1, 0x18($s2)
/* CB6F8 80134FF8 2462FF20 */  addiu     $v0, $v1, -0xe0
/* CB6FC 80134FFC 2C420075 */  sltiu     $v0, $v0, 0x75
/* CB700 80135000 10400004 */  beqz      $v0, .L80135014
/* CB704 80135004 2404021B */   addiu    $a0, $zero, 0x21b
/* CB708 80135008 C6400010 */  lwc1      $f0, 0x10($s2)
/* CB70C 8013500C 0804D43F */  j         .L801350FC
/* CB710 80135010 E7A00010 */   swc1     $f0, 0x10($sp)
.L80135014:
/* CB714 80135014 2462FFF0 */  addiu     $v0, $v1, -0x10
/* CB718 80135018 3042FFFF */  andi      $v0, $v0, 0xffff
/* CB71C 8013501C 2C4200CB */  sltiu     $v0, $v0, 0xcb
/* CB720 80135020 10400004 */  beqz      $v0, .L80135034
/* CB724 80135024 2404021A */   addiu    $a0, $zero, 0x21a
/* CB728 80135028 C6400010 */  lwc1      $f0, 0x10($s2)
/* CB72C 8013502C 0804D43F */  j         .L801350FC
/* CB730 80135030 E7A00010 */   swc1     $f0, 0x10($sp)
.L80135034:
/* CB734 80135034 00031400 */  sll       $v0, $v1, 0x10
/* CB738 80135038 00021C03 */  sra       $v1, $v0, 0x10
/* CB73C 8013503C 24020158 */  addiu     $v0, $zero, 0x158
/* CB740 80135040 1062001F */  beq       $v1, $v0, .L801350C0
/* CB744 80135044 28620159 */   slti     $v0, $v1, 0x159
/* CB748 80135048 10400009 */  beqz      $v0, .L80135070
/* CB74C 8013504C 24020156 */   addiu    $v0, $zero, 0x156
/* CB750 80135050 10620012 */  beq       $v1, $v0, .L8013509C
/* CB754 80135054 28620157 */   slti     $v0, $v1, 0x157
/* CB758 80135058 10400013 */  beqz      $v0, .L801350A8
/* CB75C 8013505C 24020010 */   addiu    $v0, $zero, 0x10
/* CB760 80135060 10620014 */  beq       $v1, $v0, .L801350B4
/* CB764 80135064 00000000 */   nop
/* CB768 80135068 0804D443 */  j         .L8013510C
/* CB76C 8013506C 00000000 */   nop
.L80135070:
/* CB770 80135070 2402015A */  addiu     $v0, $zero, 0x15a
/* CB774 80135074 10620018 */  beq       $v1, $v0, .L801350D8
/* CB778 80135078 0062102A */   slt      $v0, $v1, $v0
/* CB77C 8013507C 14400013 */  bnez      $v0, .L801350CC
/* CB780 80135080 2402015B */   addiu    $v0, $zero, 0x15b
/* CB784 80135084 1062001A */  beq       $v1, $v0, .L801350F0
/* CB788 80135088 2402015C */   addiu    $v0, $zero, 0x15c
/* CB78C 8013508C 10620015 */  beq       $v1, $v0, .L801350E4
/* CB790 80135090 00000000 */   nop
/* CB794 80135094 0804D443 */  j         .L8013510C
/* CB798 80135098 00000000 */   nop
.L8013509C:
/* CB79C 8013509C C6400010 */  lwc1      $f0, 0x10($s2)
/* CB7A0 801350A0 0804D43E */  j         .L801350F8
/* CB7A4 801350A4 24040214 */   addiu    $a0, $zero, 0x214
.L801350A8:
/* CB7A8 801350A8 C6400010 */  lwc1      $f0, 0x10($s2)
/* CB7AC 801350AC 0804D43E */  j         .L801350F8
/* CB7B0 801350B0 24040212 */   addiu    $a0, $zero, 0x212
.L801350B4:
/* CB7B4 801350B4 C6400010 */  lwc1      $f0, 0x10($s2)
/* CB7B8 801350B8 0804D43E */  j         .L801350F8
/* CB7BC 801350BC 24040212 */   addiu    $a0, $zero, 0x212
.L801350C0:
/* CB7C0 801350C0 C6400010 */  lwc1      $f0, 0x10($s2)
/* CB7C4 801350C4 0804D43E */  j         .L801350F8
/* CB7C8 801350C8 24040214 */   addiu    $a0, $zero, 0x214
.L801350CC:
/* CB7CC 801350CC C6400010 */  lwc1      $f0, 0x10($s2)
/* CB7D0 801350D0 0804D43E */  j         .L801350F8
/* CB7D4 801350D4 24040212 */   addiu    $a0, $zero, 0x212
.L801350D8:
/* CB7D8 801350D8 C6400010 */  lwc1      $f0, 0x10($s2)
/* CB7DC 801350DC 0804D43E */  j         .L801350F8
/* CB7E0 801350E0 24040214 */   addiu    $a0, $zero, 0x214
.L801350E4:
/* CB7E4 801350E4 C6400010 */  lwc1      $f0, 0x10($s2)
/* CB7E8 801350E8 0804D43E */  j         .L801350F8
/* CB7EC 801350EC 24040219 */   addiu    $a0, $zero, 0x219
.L801350F0:
/* CB7F0 801350F0 C6400010 */  lwc1      $f0, 0x10($s2)
/* CB7F4 801350F4 24040218 */  addiu     $a0, $zero, 0x218
.L801350F8:
/* CB7F8 801350F8 E7A00010 */  swc1      $f0, 0x10($sp)
.L801350FC:
/* CB7FC 801350FC 8E460008 */  lw        $a2, 8($s2)
/* CB800 80135100 8E47000C */  lw        $a3, 0xc($s2)
/* CB804 80135104 0C052757 */  jal       sfx_play_sound_at_position
/* CB808 80135108 0000282D */   daddu    $a1, $zero, $zero
.L8013510C:
/* CB80C 8013510C C642000C */  lwc1      $f2, 0xc($s2)
/* CB810 80135110 3C01C4FA */  lui       $at, 0xc4fa
/* CB814 80135114 44810000 */  mtc1      $at, $f0
/* CB818 80135118 00000000 */  nop
/* CB81C 8013511C 4600103C */  c.lt.s    $f2, $f0
/* CB820 80135120 00000000 */  nop
/* CB824 80135124 45000003 */  bc1f      .L80135134
/* CB828 80135128 00000000 */   nop
.L8013512C:
/* CB82C 8013512C 24020002 */  addiu     $v0, $zero, 2
.L80135130:
/* CB830 80135130 A242001A */  sb        $v0, 0x1a($s2)
.L80135134:
/* CB834 80135134 8243001A */  lb        $v1, 0x1a($s2)
/* CB838 80135138 24020002 */  addiu     $v0, $zero, 2
/* CB83C 8013513C 14620005 */  bne       $v1, $v0, .L80135154
/* CB840 80135140 24020003 */   addiu    $v0, $zero, 3
/* CB844 80135144 0C04CE4C */  jal       remove_item_entity_by_reference
/* CB848 80135148 0240202D */   daddu    $a0, $s2, $zero
/* CB84C 8013514C 8243001A */  lb        $v1, 0x1a($s2)
/* CB850 80135150 24020003 */  addiu     $v0, $zero, 3
.L80135154:
/* CB854 80135154 146200E6 */  bne       $v1, $v0, .L801354F0
/* CB858 80135158 00000000 */   nop
/* CB85C 8013515C 8E420000 */  lw        $v0, ($s2)
/* CB860 80135160 30420400 */  andi      $v0, $v0, 0x400
/* CB864 80135164 10400003 */  beqz      $v0, .L80135174
/* CB868 80135168 00000000 */   nop
/* CB86C 8013516C 0C051514 */  jal       set_global_flag
/* CB870 80135170 86440004 */   lh       $a0, 4($s2)
.L80135174:
/* CB874 80135174 C644000C */  lwc1      $f4, 0xc($s2)
/* CB878 80135178 3C014180 */  lui       $at, 0x4180
/* CB87C 8013517C 44810000 */  mtc1      $at, $f0
/* CB880 80135180 3C013F80 */  lui       $at, 0x3f80
/* CB884 80135184 44811000 */  mtc1      $at, $f2
/* CB888 80135188 AFA00014 */  sw        $zero, 0x14($sp)
/* CB88C 8013518C 46002100 */  add.s     $f4, $f4, $f0
/* CB890 80135190 E7A20010 */  swc1      $f2, 0x10($sp)
/* CB894 80135194 8E450008 */  lw        $a1, 8($s2)
/* CB898 80135198 8E470010 */  lw        $a3, 0x10($s2)
/* CB89C 8013519C 44062000 */  mfc1      $a2, $f4
/* CB8A0 801351A0 0C01C4FC */  jal       playFX_49
/* CB8A4 801351A4 0000202D */   daddu    $a0, $zero, $zero
/* CB8A8 801351A8 96430018 */  lhu       $v1, 0x18($s2)
/* CB8AC 801351AC 2462FFF0 */  addiu     $v0, $v1, -0x10
/* CB8B0 801351B0 2C4200CB */  sltiu     $v0, $v0, 0xcb
/* CB8B4 801351B4 1440000F */  bnez      $v0, .L801351F4
/* CB8B8 801351B8 2402000A */   addiu    $v0, $zero, 0xa
/* CB8BC 801351BC 2462FF20 */  addiu     $v0, $v1, -0xe0
/* CB8C0 801351C0 3042FFFF */  andi      $v0, $v0, 0xffff
/* CB8C4 801351C4 2C420075 */  sltiu     $v0, $v0, 0x75
/* CB8C8 801351C8 1440000A */  bnez      $v0, .L801351F4
/* CB8CC 801351CC 2402000A */   addiu    $v0, $zero, 0xa
/* CB8D0 801351D0 00031400 */  sll       $v0, $v1, 0x10
/* CB8D4 801351D4 00021403 */  sra       $v0, $v0, 0x10
/* CB8D8 801351D8 2403015C */  addiu     $v1, $zero, 0x15c
/* CB8DC 801351DC 14430007 */  bne       $v0, $v1, .L801351FC
/* CB8E0 801351E0 24020017 */   addiu    $v0, $zero, 0x17
/* CB8E4 801351E4 9662032C */  lhu       $v0, 0x32c($s3)
/* CB8E8 801351E8 24420001 */  addiu     $v0, $v0, 1
/* CB8EC 801351EC A662032C */  sh        $v0, 0x32c($s3)
/* CB8F0 801351F0 2402000A */  addiu     $v0, $zero, 0xa
.L801351F4:
/* CB8F4 801351F4 0804D53C */  j         .L801354F0
/* CB8F8 801351F8 A242001A */   sb       $v0, 0x1a($s2)
.L801351FC:
/* CB8FC 801351FC 8243001B */  lb        $v1, 0x1b($s2)
/* CB900 80135200 14620002 */  bne       $v1, $v0, .L8013520C
/* CB904 80135204 2402FFFF */   addiu    $v0, $zero, -1
/* CB908 80135208 A6420018 */  sh        $v0, 0x18($s2)
.L8013520C:
/* CB90C 8013520C 86430018 */  lh        $v1, 0x18($s2)
/* CB910 80135210 24020157 */  addiu     $v0, $zero, 0x157
/* CB914 80135214 10620075 */  beq       $v1, $v0, .L801353EC
/* CB918 80135218 28620158 */   slti     $v0, $v1, 0x158
/* CB91C 8013521C 10400007 */  beqz      $v0, .L8013523C
/* CB920 80135220 24020010 */   addiu    $v0, $zero, 0x10
/* CB924 80135224 1062008B */  beq       $v1, $v0, .L80135454
/* CB928 80135228 24020156 */   addiu    $v0, $zero, 0x156
/* CB92C 8013522C 10620011 */  beq       $v1, $v0, .L80135274
/* CB930 80135230 0240202D */   daddu    $a0, $s2, $zero
/* CB934 80135234 0804D533 */  j         .L801354CC
/* CB938 80135238 00000000 */   nop
.L8013523C:
/* CB93C 8013523C 2402015A */  addiu     $v0, $zero, 0x15a
/* CB940 80135240 10620096 */  beq       $v1, $v0, .L8013549C
/* CB944 80135244 2862015B */   slti     $v0, $v1, 0x15b
/* CB948 80135248 10400005 */  beqz      $v0, .L80135260
/* CB94C 8013524C 24020159 */   addiu    $v0, $zero, 0x159
/* CB950 80135250 10620086 */  beq       $v1, $v0, .L8013546C
/* CB954 80135254 0240202D */   daddu    $a0, $s2, $zero
/* CB958 80135258 0804D533 */  j         .L801354CC
/* CB95C 8013525C 00000000 */   nop
.L80135260:
/* CB960 80135260 2402015B */  addiu     $v0, $zero, 0x15b
/* CB964 80135264 10620028 */  beq       $v1, $v0, .L80135308
/* CB968 80135268 0240202D */   daddu    $a0, $s2, $zero
/* CB96C 8013526C 0804D533 */  j         .L801354CC
/* CB970 80135270 00000000 */   nop
.L80135274:
/* CB974 80135274 82620002 */  lb        $v0, 2($s3)
/* CB978 80135278 82630003 */  lb        $v1, 3($s3)
/* CB97C 8013527C 0043102A */  slt       $v0, $v0, $v1
/* CB980 80135280 10400014 */  beqz      $v0, .L801352D4
/* CB984 80135284 0000202D */   daddu    $a0, $zero, $zero
/* CB988 80135288 868200B0 */  lh        $v0, 0xb0($s4)
/* CB98C 8013528C C682002C */  lwc1      $f2, 0x2c($s4)
/* CB990 80135290 44820000 */  mtc1      $v0, $f0
/* CB994 80135294 00000000 */  nop
/* CB998 80135298 46800020 */  cvt.s.w   $f0, $f0
/* CB99C 8013529C 46001080 */  add.s     $f2, $f2, $f0
/* CB9A0 801352A0 8E850028 */  lw        $a1, 0x28($s4)
/* CB9A4 801352A4 8E870030 */  lw        $a3, 0x30($s4)
/* CB9A8 801352A8 44061000 */  mfc1      $a2, $f2
/* CB9AC 801352AC 24020001 */  addiu     $v0, $zero, 1
/* CB9B0 801352B0 0C01C424 */  jal       playFX_40
/* CB9B4 801352B4 AFA20010 */   sw       $v0, 0x10($sp)
/* CB9B8 801352B8 C6400010 */  lwc1      $f0, 0x10($s2)
/* CB9BC 801352BC 24042056 */  addiu     $a0, $zero, 0x2056
/* CB9C0 801352C0 E7A00010 */  swc1      $f0, 0x10($sp)
/* CB9C4 801352C4 8E460008 */  lw        $a2, 8($s2)
/* CB9C8 801352C8 8E47000C */  lw        $a3, 0xc($s2)
/* CB9CC 801352CC 0C052757 */  jal       sfx_play_sound_at_position
/* CB9D0 801352D0 0000282D */   daddu    $a1, $zero, $zero
.L801352D4:
/* CB9D4 801352D4 92620002 */  lbu       $v0, 2($s3)
/* CB9D8 801352D8 82630003 */  lb        $v1, 3($s3)
/* CB9DC 801352DC 24420001 */  addiu     $v0, $v0, 1
/* CB9E0 801352E0 A2620002 */  sb        $v0, 2($s3)
/* CB9E4 801352E4 00021600 */  sll       $v0, $v0, 0x18
/* CB9E8 801352E8 00021603 */  sra       $v0, $v0, 0x18
/* CB9EC 801352EC 0062182A */  slt       $v1, $v1, $v0
/* CB9F0 801352F0 92620003 */  lbu       $v0, 3($s3)
/* CB9F4 801352F4 54600001 */  bnel      $v1, $zero, .L801352FC
/* CB9F8 801352F8 A2620002 */   sb       $v0, 2($s3)
.L801352FC:
/* CB9FC 801352FC C6400010 */  lwc1      $f0, 0x10($s2)
/* CBA00 80135300 0804D4E6 */  j         .L80135398
/* CBA04 80135304 24040213 */   addiu    $a0, $zero, 0x213
.L80135308:
/* CBA08 80135308 82620005 */  lb        $v0, 5($s3)
/* CBA0C 8013530C 82630006 */  lb        $v1, 6($s3)
/* CBA10 80135310 0043102A */  slt       $v0, $v0, $v1
/* CBA14 80135314 10400014 */  beqz      $v0, .L80135368
/* CBA18 80135318 24040001 */   addiu    $a0, $zero, 1
/* CBA1C 8013531C 868200B0 */  lh        $v0, 0xb0($s4)
/* CBA20 80135320 C682002C */  lwc1      $f2, 0x2c($s4)
/* CBA24 80135324 44820000 */  mtc1      $v0, $f0
/* CBA28 80135328 00000000 */  nop
/* CBA2C 8013532C 46800020 */  cvt.s.w   $f0, $f0
/* CBA30 80135330 46001080 */  add.s     $f2, $f2, $f0
/* CBA34 80135334 8E850028 */  lw        $a1, 0x28($s4)
/* CBA38 80135338 8E870030 */  lw        $a3, 0x30($s4)
/* CBA3C 8013533C 44061000 */  mfc1      $a2, $f2
/* CBA40 80135340 0080102D */  daddu     $v0, $a0, $zero
/* CBA44 80135344 0C01C424 */  jal       playFX_40
/* CBA48 80135348 AFA20010 */   sw       $v0, 0x10($sp)
/* CBA4C 8013534C C6400010 */  lwc1      $f0, 0x10($s2)
/* CBA50 80135350 24042056 */  addiu     $a0, $zero, 0x2056
/* CBA54 80135354 E7A00010 */  swc1      $f0, 0x10($sp)
/* CBA58 80135358 8E460008 */  lw        $a2, 8($s2)
/* CBA5C 8013535C 8E47000C */  lw        $a3, 0xc($s2)
/* CBA60 80135360 0C052757 */  jal       sfx_play_sound_at_position
/* CBA64 80135364 0000282D */   daddu    $a1, $zero, $zero
.L80135368:
/* CBA68 80135368 92620005 */  lbu       $v0, 5($s3)
/* CBA6C 8013536C 82630006 */  lb        $v1, 6($s3)
/* CBA70 80135370 24420001 */  addiu     $v0, $v0, 1
/* CBA74 80135374 A2620005 */  sb        $v0, 5($s3)
/* CBA78 80135378 00021600 */  sll       $v0, $v0, 0x18
/* CBA7C 8013537C 00021603 */  sra       $v0, $v0, 0x18
/* CBA80 80135380 0062182A */  slt       $v1, $v1, $v0
/* CBA84 80135384 92620006 */  lbu       $v0, 6($s3)
/* CBA88 80135388 54600001 */  bnel      $v1, $zero, .L80135390
/* CBA8C 8013538C A2620005 */   sb       $v0, 5($s3)
.L80135390:
/* CBA90 80135390 C6400010 */  lwc1      $f0, 0x10($s2)
/* CBA94 80135394 24040217 */  addiu     $a0, $zero, 0x217
.L80135398:
/* CBA98 80135398 E7A00010 */  swc1      $f0, 0x10($sp)
/* CBA9C 8013539C 8E460008 */  lw        $a2, 8($s2)
/* CBAA0 801353A0 8E47000C */  lw        $a3, 0xc($s2)
/* CBAA4 801353A4 0C052757 */  jal       sfx_play_sound_at_position
/* CBAA8 801353A8 0000282D */   daddu    $a1, $zero, $zero
/* CBAAC 801353AC 8E850028 */  lw        $a1, 0x28($s4)
/* CBAB0 801353B0 868200B0 */  lh        $v0, 0xb0($s4)
/* CBAB4 801353B4 C682002C */  lwc1      $f2, 0x2c($s4)
/* CBAB8 801353B8 44820000 */  mtc1      $v0, $f0
/* CBABC 801353BC 00000000 */  nop
/* CBAC0 801353C0 46800020 */  cvt.s.w   $f0, $f0
/* CBAC4 801353C4 46001080 */  add.s     $f2, $f2, $f0
/* CBAC8 801353C8 8E870030 */  lw        $a3, 0x30($s4)
/* CBACC 801353CC 3C0141F0 */  lui       $at, 0x41f0
/* CBAD0 801353D0 44810000 */  mtc1      $at, $f0
/* CBAD4 801353D4 44061000 */  mfc1      $a2, $f2
/* CBAD8 801353D8 24040004 */  addiu     $a0, $zero, 4
/* CBADC 801353DC 0C01BFBC */  jal       playFX_11
/* CBAE0 801353E0 E7A00010 */   swc1     $f0, 0x10($sp)
/* CBAE4 801353E4 0804D533 */  j         .L801354CC
/* CBAE8 801353E8 0240202D */   daddu    $a0, $s2, $zero
.L801353EC:
/* CBAEC 801353EC 9662000C */  lhu       $v0, 0xc($s3)
/* CBAF0 801353F0 24420001 */  addiu     $v0, $v0, 1
/* CBAF4 801353F4 A662000C */  sh        $v0, 0xc($s3)
/* CBAF8 801353F8 00021400 */  sll       $v0, $v0, 0x10
/* CBAFC 801353FC 00021403 */  sra       $v0, $v0, 0x10
/* CBB00 80135400 284203E8 */  slti      $v0, $v0, 0x3e8
/* CBB04 80135404 14400002 */  bnez      $v0, .L80135410
/* CBB08 80135408 240203E7 */   addiu    $v0, $zero, 0x3e7
/* CBB0C 8013540C A662000C */  sh        $v0, 0xc($s3)
.L80135410:
/* CBB10 80135410 C6400010 */  lwc1      $f0, 0x10($s2)
/* CBB14 80135414 24040211 */  addiu     $a0, $zero, 0x211
/* CBB18 80135418 E7A00010 */  swc1      $f0, 0x10($sp)
/* CBB1C 8013541C 8E460008 */  lw        $a2, 8($s2)
/* CBB20 80135420 8E47000C */  lw        $a3, 0xc($s2)
/* CBB24 80135424 0C052757 */  jal       sfx_play_sound_at_position
/* CBB28 80135428 0000282D */   daddu    $a1, $zero, $zero
/* CBB2C 8013542C 3C030001 */  lui       $v1, 1
/* CBB30 80135430 8E6202B4 */  lw        $v0, 0x2b4($s3)
/* CBB34 80135434 3463869F */  ori       $v1, $v1, 0x869f
/* CBB38 80135438 24420001 */  addiu     $v0, $v0, 1
/* CBB3C 8013543C AE6202B4 */  sw        $v0, 0x2b4($s3)
/* CBB40 80135440 0062102B */  sltu      $v0, $v1, $v0
/* CBB44 80135444 54400020 */  bnel      $v0, $zero, .L801354C8
/* CBB48 80135448 AE6302B4 */   sw       $v1, 0x2b4($s3)
/* CBB4C 8013544C 0804D533 */  j         .L801354CC
/* CBB50 80135450 0240202D */   daddu    $a0, $s2, $zero
.L80135454:
/* CBB54 80135454 9262000E */  lbu       $v0, 0xe($s3)
/* CBB58 80135458 24420001 */  addiu     $v0, $v0, 1
/* CBB5C 8013545C A262000E */  sb        $v0, 0xe($s3)
/* CBB60 80135460 C6400010 */  lwc1      $f0, 0x10($s2)
/* CBB64 80135464 0804D52D */  j         .L801354B4
/* CBB68 80135468 24040211 */   addiu    $a0, $zero, 0x211
.L8013546C:
/* CBB6C 8013546C 92620010 */  lbu       $v0, 0x10($s3)
/* CBB70 80135470 24420001 */  addiu     $v0, $v0, 1
/* CBB74 80135474 A2620010 */  sb        $v0, 0x10($s3)
/* CBB78 80135478 00021600 */  sll       $v0, $v0, 0x18
/* CBB7C 8013547C 00021603 */  sra       $v0, $v0, 0x18
/* CBB80 80135480 28420065 */  slti      $v0, $v0, 0x65
/* CBB84 80135484 14400002 */  bnez      $v0, .L80135490
/* CBB88 80135488 24020064 */   addiu    $v0, $zero, 0x64
/* CBB8C 8013548C A2620010 */  sb        $v0, 0x10($s3)
.L80135490:
/* CBB90 80135490 C6400010 */  lwc1      $f0, 0x10($s2)
/* CBB94 80135494 0804D52D */  j         .L801354B4
/* CBB98 80135498 24040211 */   addiu    $a0, $zero, 0x211
.L8013549C:
/* CBB9C 8013549C 92620003 */  lbu       $v0, 3($s3)
/* CBBA0 801354A0 92630006 */  lbu       $v1, 6($s3)
/* CBBA4 801354A4 A2620002 */  sb        $v0, 2($s3)
/* CBBA8 801354A8 A2630005 */  sb        $v1, 5($s3)
/* CBBAC 801354AC C6400010 */  lwc1      $f0, 0x10($s2)
/* CBBB0 801354B0 24040213 */  addiu     $a0, $zero, 0x213
.L801354B4:
/* CBBB4 801354B4 E7A00010 */  swc1      $f0, 0x10($sp)
/* CBBB8 801354B8 8E460008 */  lw        $a2, 8($s2)
/* CBBBC 801354BC 8E47000C */  lw        $a3, 0xc($s2)
/* CBBC0 801354C0 0C052757 */  jal       sfx_play_sound_at_position
/* CBBC4 801354C4 0000282D */   daddu    $a1, $zero, $zero
.L801354C8:
/* CBBC8 801354C8 0240202D */  daddu     $a0, $s2, $zero
.L801354CC:
/* CBBCC 801354CC 3C02800A */  lui       $v0, %hi(gOverrideFlags)
/* CBBD0 801354D0 2442A650 */  addiu     $v0, $v0, %lo(gOverrideFlags)
/* CBBD4 801354D4 3C018015 */  lui       $at, %hi(D_801565A8)
/* CBBD8 801354D8 A42065A8 */  sh        $zero, %lo(D_801565A8)($at)
/* CBBDC 801354DC 8C430000 */  lw        $v1, ($v0)
/* CBBE0 801354E0 2405FFBF */  addiu     $a1, $zero, -0x41
/* CBBE4 801354E4 00651824 */  and       $v1, $v1, $a1
/* CBBE8 801354E8 0C04CE4C */  jal       remove_item_entity_by_reference
/* CBBEC 801354EC AC430000 */   sw       $v1, ($v0)
.L801354F0:
/* CBBF0 801354F0 8243001A */  lb        $v1, 0x1a($s2)
/* CBBF4 801354F4 24020004 */  addiu     $v0, $zero, 4
/* CBBF8 801354F8 1462000F */  bne       $v1, $v0, .L80135538
/* CBBFC 801354FC 2402000A */   addiu    $v0, $zero, 0xa
/* CBC00 80135500 3C048015 */  lui       $a0, %hi(D_80155D80)
/* CBC04 80135504 8C845D80 */  lw        $a0, %lo(D_80155D80)($a0)
/* CBC08 80135508 0C0B1059 */  jal       does_script_exist
/* CBC0C 8013550C 00000000 */   nop
/* CBC10 80135510 14400007 */  bnez      $v0, .L80135530
/* CBC14 80135514 00000000 */   nop
/* CBC18 80135518 3C018015 */  lui       $at, %hi(D_801565A8)
/* CBC1C 8013551C A42065A8 */  sh        $zero, %lo(D_801565A8)($at)
/* CBC20 80135520 0C04CE4C */  jal       remove_item_entity_by_reference
/* CBC24 80135524 0240202D */   daddu    $a0, $s2, $zero
/* CBC28 80135528 0C0B1192 */  jal       resume_all_group
/* CBC2C 8013552C 24040002 */   addiu    $a0, $zero, 2
.L80135530:
/* CBC30 80135530 8243001A */  lb        $v1, 0x1a($s2)
/* CBC34 80135534 2402000A */  addiu     $v0, $zero, 0xa
.L80135538:
/* CBC38 80135538 1462000D */  bne       $v1, $v0, .L80135570
/* CBC3C 8013553C 24020001 */   addiu    $v0, $zero, 1
/* CBC40 80135540 3C018015 */  lui       $at, %hi(D_801565A4)
/* CBC44 80135544 A42265A4 */  sh        $v0, %lo(D_801565A4)($at)
/* CBC48 80135548 2402001C */  addiu     $v0, $zero, 0x1c
/* CBC4C 8013554C 3C03800A */  lui       $v1, %hi(gOverrideFlags)
/* CBC50 80135550 2463A650 */  addiu     $v1, $v1, %lo(gOverrideFlags)
/* CBC54 80135554 A242001B */  sb        $v0, 0x1b($s2)
/* CBC58 80135558 A240001A */  sb        $zero, 0x1a($s2)
/* CBC5C 8013555C 8C620000 */  lw        $v0, ($v1)
/* CBC60 80135560 3C018015 */  lui       $at, %hi(D_801565A8)
/* CBC64 80135564 A42065A8 */  sh        $zero, %lo(D_801565A8)($at)
/* CBC68 80135568 34420040 */  ori       $v0, $v0, 0x40
/* CBC6C 8013556C AC620000 */  sw        $v0, ($v1)
.L80135570:
/* CBC70 80135570 8FBF0044 */  lw        $ra, 0x44($sp)
/* CBC74 80135574 8FB40040 */  lw        $s4, 0x40($sp)
/* CBC78 80135578 8FB3003C */  lw        $s3, 0x3c($sp)
/* CBC7C 8013557C 8FB20038 */  lw        $s2, 0x38($sp)
/* CBC80 80135580 8FB10034 */  lw        $s1, 0x34($sp)
/* CBC84 80135584 8FB00030 */  lw        $s0, 0x30($sp)
/* CBC88 80135588 D7B80058 */  ldc1      $f24, 0x58($sp)
/* CBC8C 8013558C D7B60050 */  ldc1      $f22, 0x50($sp)
/* CBC90 80135590 D7B40048 */  ldc1      $f20, 0x48($sp)
/* CBC94 80135594 03E00008 */  jr        $ra
/* CBC98 80135598 27BD0060 */   addiu    $sp, $sp, 0x60
