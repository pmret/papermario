.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00BA620
/* 3B91F0 E00BA620 27BDFF28 */  addiu     $sp, $sp, -0xd8
/* 3B91F4 E00BA624 3C06DB06 */  lui       $a2, 0xdb06
/* 3B91F8 E00BA628 34C60024 */  ori       $a2, $a2, 0x24
/* 3B91FC E00BA62C 3C07FF10 */  lui       $a3, 0xff10
/* 3B9200 E00BA630 34E7013F */  ori       $a3, $a3, 0x13f
/* 3B9204 E00BA634 0000682D */  daddu     $t5, $zero, $zero
/* 3B9208 E00BA638 3C02800A */  lui       $v0, %hi(gMasterGfxPos)
/* 3B920C E00BA63C 2442A66C */  addiu     $v0, $v0, %lo(gMasterGfxPos)
/* 3B9210 E00BA640 0040402D */  daddu     $t0, $v0, $zero
/* 3B9214 E00BA644 AFB200B8 */  sw        $s2, 0xb8($sp)
/* 3B9218 E00BA648 3C12FD10 */  lui       $s2, 0xfd10
/* 3B921C E00BA64C 3652013F */  ori       $s2, $s2, 0x13f
/* 3B9220 E00BA650 3C18800A */  lui       $t8, %hi(nuGfxCfb_ptr)
/* 3B9224 E00BA654 2718A64C */  addiu     $t8, $t8, %lo(nuGfxCfb_ptr)
/* 3B9228 E00BA658 3C0CF510 */  lui       $t4, 0xf510
/* 3B922C E00BA65C 358CA000 */  ori       $t4, $t4, 0xa000
/* 3B9230 E00BA660 AFB700CC */  sw        $s7, 0xcc($sp)
/* 3B9234 E00BA664 3C170700 */  lui       $s7, 0x700
/* 3B9238 E00BA668 AFB500C4 */  sw        $s5, 0xc4($sp)
/* 3B923C E00BA66C 3C15F400 */  lui       $s5, 0xf400
/* 3B9240 E00BA670 AFB100B4 */  sw        $s1, 0xb4($sp)
/* 3B9244 E00BA674 3C11074F */  lui       $s1, 0x74f
/* 3B9248 E00BA678 3631C014 */  ori       $s1, $s1, 0xc014
/* 3B924C E00BA67C 3C0EE700 */  lui       $t6, 0xe700
/* 3B9250 E00BA680 AFB300BC */  sw        $s3, 0xbc($sp)
/* 3B9254 E00BA684 3C13F200 */  lui       $s3, 0xf200
/* 3B9258 E00BA688 AFB000B0 */  sw        $s0, 0xb0($sp)
/* 3B925C E00BA68C 3C10004F */  lui       $s0, 0x4f
/* 3B9260 E00BA690 3610C014 */  ori       $s0, $s0, 0xc014
/* 3B9264 E00BA694 3C0FE44F */  lui       $t7, 0xe44f
/* 3B9268 E00BA698 35EFC000 */  ori       $t7, $t7, 0xc000
/* 3B926C E00BA69C 01A0582D */  daddu     $t3, $t5, $zero
/* 3B9270 E00BA6A0 240A0014 */  addiu     $t2, $zero, 0x14
/* 3B9274 E00BA6A4 01A0482D */  daddu     $t1, $t5, $zero
/* 3B9278 E00BA6A8 01C0102D */  daddu     $v0, $t6, $zero
/* 3B927C E00BA6AC AFBF00D4 */  sw        $ra, 0xd4($sp)
/* 3B9280 E00BA6B0 AFBE00D0 */  sw        $fp, 0xd0($sp)
/* 3B9284 E00BA6B4 AFB600C8 */  sw        $s6, 0xc8($sp)
/* 3B9288 E00BA6B8 AFB400C0 */  sw        $s4, 0xc0($sp)
/* 3B928C E00BA6BC 8D030000 */  lw        $v1, ($t0)
/* 3B9290 E00BA6C0 8C94000C */  lw        $s4, 0xc($a0)
/* 3B9294 E00BA6C4 0060282D */  daddu     $a1, $v1, $zero
/* 3B9298 E00BA6C8 9299001F */  lbu       $t9, 0x1f($s4)
/* 3B929C E00BA6CC 24630008 */  addiu     $v1, $v1, 8
/* 3B92A0 E00BA6D0 AD030000 */  sw        $v1, ($t0)
/* 3B92A4 E00BA6D4 ACA20000 */  sw        $v0, ($a1)
/* 3B92A8 E00BA6D8 24620008 */  addiu     $v0, $v1, 8
/* 3B92AC E00BA6DC ACA00004 */  sw        $zero, 4($a1)
/* 3B92B0 E00BA6E0 AD020000 */  sw        $v0, ($t0)
/* 3B92B4 E00BA6E4 AC660000 */  sw        $a2, ($v1)
/* 3B92B8 E00BA6E8 8C840010 */  lw        $a0, 0x10($a0)
/* 3B92BC E00BA6EC 24620010 */  addiu     $v0, $v1, 0x10
/* 3B92C0 E00BA6F0 AD020000 */  sw        $v0, ($t0)
/* 3B92C4 E00BA6F4 3C05800A */  lui       $a1, %hi(nuGfxZBuffer)
/* 3B92C8 E00BA6F8 8CA5A5DC */  lw        $a1, %lo(nuGfxZBuffer)($a1)
/* 3B92CC E00BA6FC 8C84001C */  lw        $a0, 0x1c($a0)
/* 3B92D0 E00BA700 24620018 */  addiu     $v0, $v1, 0x18
/* 3B92D4 E00BA704 AD020000 */  sw        $v0, ($t0)
/* 3B92D8 E00BA708 3C02DE00 */  lui       $v0, 0xde00
/* 3B92DC E00BA70C AC620010 */  sw        $v0, 0x10($v1)
/* 3B92E0 E00BA710 3C020900 */  lui       $v0, 0x900
/* 3B92E4 E00BA714 24420528 */  addiu     $v0, $v0, 0x528
/* 3B92E8 E00BA718 AC620014 */  sw        $v0, 0x14($v1)
/* 3B92EC E00BA71C 3C028000 */  lui       $v0, 0x8000
/* 3B92F0 E00BA720 AC670008 */  sw        $a3, 8($v1)
/* 3B92F4 E00BA724 AC65000C */  sw        $a1, 0xc($v1)
/* 3B92F8 E00BA728 00822021 */  addu      $a0, $a0, $v0
/* 3B92FC E00BA72C AC640004 */  sw        $a0, 4($v1)
.LE00BA730:
/* 3B9300 E00BA730 3C071000 */  lui       $a3, 0x1000
/* 3B9304 E00BA734 34E70400 */  ori       $a3, $a3, 0x400
/* 3B9308 E00BA738 31660FFF */  andi      $a2, $t3, 0xfff
/* 3B930C E00BA73C 256B0018 */  addiu     $t3, $t3, 0x18
/* 3B9310 E00BA740 31450FFF */  andi      $a1, $t2, 0xfff
/* 3B9314 E00BA744 254A0018 */  addiu     $t2, $t2, 0x18
/* 3B9318 E00BA748 25AD0001 */  addiu     $t5, $t5, 1
/* 3B931C E00BA74C 00AF2825 */  or        $a1, $a1, $t7
/* 3B9320 E00BA750 8D020000 */  lw        $v0, ($t0)
/* 3B9324 E00BA754 8F030000 */  lw        $v1, ($t8)
/* 3B9328 E00BA758 0040202D */  daddu     $a0, $v0, $zero
/* 3B932C E00BA75C 24420008 */  addiu     $v0, $v0, 8
/* 3B9330 E00BA760 00691821 */  addu      $v1, $v1, $t1
/* 3B9334 E00BA764 AD020000 */  sw        $v0, ($t0)
/* 3B9338 E00BA768 AC830004 */  sw        $v1, 4($a0)
/* 3B933C E00BA76C 24430008 */  addiu     $v1, $v0, 8
/* 3B9340 E00BA770 AC920000 */  sw        $s2, ($a0)
/* 3B9344 E00BA774 AD030000 */  sw        $v1, ($t0)
/* 3B9348 E00BA778 24430010 */  addiu     $v1, $v0, 0x10
/* 3B934C E00BA77C 3C16E600 */  lui       $s6, 0xe600
/* 3B9350 E00BA780 AC4C0000 */  sw        $t4, ($v0)
/* 3B9354 E00BA784 AC570004 */  sw        $s7, 4($v0)
/* 3B9358 E00BA788 AD030000 */  sw        $v1, ($t0)
/* 3B935C E00BA78C 24430018 */  addiu     $v1, $v0, 0x18
/* 3B9360 E00BA790 AC560008 */  sw        $s6, 8($v0)
/* 3B9364 E00BA794 AC40000C */  sw        $zero, 0xc($v0)
/* 3B9368 E00BA798 AD030000 */  sw        $v1, ($t0)
/* 3B936C E00BA79C 24430020 */  addiu     $v1, $v0, 0x20
/* 3B9370 E00BA7A0 AC550010 */  sw        $s5, 0x10($v0)
/* 3B9374 E00BA7A4 AC510014 */  sw        $s1, 0x14($v0)
/* 3B9378 E00BA7A8 AD030000 */  sw        $v1, ($t0)
/* 3B937C E00BA7AC 24430028 */  addiu     $v1, $v0, 0x28
/* 3B9380 E00BA7B0 AC4E0018 */  sw        $t6, 0x18($v0)
/* 3B9384 E00BA7B4 AC40001C */  sw        $zero, 0x1c($v0)
/* 3B9388 E00BA7B8 AD030000 */  sw        $v1, ($t0)
/* 3B938C E00BA7BC 24430030 */  addiu     $v1, $v0, 0x30
/* 3B9390 E00BA7C0 AC4C0020 */  sw        $t4, 0x20($v0)
/* 3B9394 E00BA7C4 AC400024 */  sw        $zero, 0x24($v0)
/* 3B9398 E00BA7C8 AD030000 */  sw        $v1, ($t0)
/* 3B939C E00BA7CC 24430038 */  addiu     $v1, $v0, 0x38
/* 3B93A0 E00BA7D0 AC530028 */  sw        $s3, 0x28($v0)
/* 3B93A4 E00BA7D4 AC50002C */  sw        $s0, 0x2c($v0)
/* 3B93A8 E00BA7D8 AD030000 */  sw        $v1, ($t0)
/* 3B93AC E00BA7DC 24430040 */  addiu     $v1, $v0, 0x40
/* 3B93B0 E00BA7E0 AC450030 */  sw        $a1, 0x30($v0)
/* 3B93B4 E00BA7E4 AC460034 */  sw        $a2, 0x34($v0)
/* 3B93B8 E00BA7E8 AD030000 */  sw        $v1, ($t0)
/* 3B93BC E00BA7EC 3C03E100 */  lui       $v1, 0xe100
/* 3B93C0 E00BA7F0 AC430038 */  sw        $v1, 0x38($v0)
/* 3B93C4 E00BA7F4 24430048 */  addiu     $v1, $v0, 0x48
/* 3B93C8 E00BA7F8 AC40003C */  sw        $zero, 0x3c($v0)
/* 3B93CC E00BA7FC AD030000 */  sw        $v1, ($t0)
/* 3B93D0 E00BA800 3C03F100 */  lui       $v1, 0xf100
/* 3B93D4 E00BA804 AC430040 */  sw        $v1, 0x40($v0)
/* 3B93D8 E00BA808 24430050 */  addiu     $v1, $v0, 0x50
/* 3B93DC E00BA80C AC470044 */  sw        $a3, 0x44($v0)
/* 3B93E0 E00BA810 AD030000 */  sw        $v1, ($t0)
/* 3B93E4 E00BA814 AC4E0048 */  sw        $t6, 0x48($v0)
/* 3B93E8 E00BA818 AC40004C */  sw        $zero, 0x4c($v0)
/* 3B93EC E00BA81C 29A20028 */  slti      $v0, $t5, 0x28
/* 3B93F0 E00BA820 1440FFC3 */  bnez      $v0, .LE00BA730
/* 3B93F4 E00BA824 25290F00 */   addiu    $t1, $t1, 0xf00
/* 3B93F8 E00BA828 3C06FF10 */  lui       $a2, 0xff10
/* 3B93FC E00BA82C 34C6013F */  ori       $a2, $a2, 0x13f
/* 3B9400 E00BA830 3C0AE300 */  lui       $t2, 0xe300
/* 3B9404 E00BA834 354A0A01 */  ori       $t2, $t2, 0xa01
/* 3B9408 E00BA838 3C0CFC35 */  lui       $t4, 0xfc35
/* 3B940C E00BA83C 358C7E6A */  ori       $t4, $t4, 0x7e6a
/* 3B9410 E00BA840 3C0BFFFC */  lui       $t3, 0xfffc
/* 3B9414 E00BA844 356BF87C */  ori       $t3, $t3, 0xf87c
/* 3B9418 E00BA848 3C0DFD10 */  lui       $t5, 0xfd10
/* 3B941C E00BA84C 35AD013F */  ori       $t5, $t5, 0x13f
/* 3B9420 E00BA850 3C0FE200 */  lui       $t7, 0xe200
/* 3B9424 E00BA854 35EF001C */  ori       $t7, $t7, 0x1c
/* 3B9428 E00BA858 3C0E0F0A */  lui       $t6, 0xf0a
/* 3B942C E00BA85C 35CE4300 */  ori       $t6, $t6, 0x4300
/* 3B9430 E00BA860 3C11E300 */  lui       $s1, 0xe300
/* 3B9434 E00BA864 36310C00 */  ori       $s1, $s1, 0xc00
/* 3B9438 E00BA868 3C12E300 */  lui       $s2, 0xe300
/* 3B943C E00BA86C 36521201 */  ori       $s2, $s2, 0x1201
/* 3B9440 E00BA870 27A40020 */  addiu     $a0, $sp, 0x20
/* 3B9444 E00BA874 3C130001 */  lui       $s3, 1
/* 3B9448 E00BA878 36731630 */  ori       $s3, $s3, 0x1630
/* 3B944C E00BA87C 3C10800A */  lui       $s0, %hi(gMasterGfxPos)
/* 3B9450 E00BA880 2610A66C */  addiu     $s0, $s0, %lo(gMasterGfxPos)
/* 3B9454 E00BA884 8E080000 */  lw        $t0, ($s0)
/* 3B9458 E00BA888 3C05C2A0 */  lui       $a1, 0xc2a0
/* 3B945C E00BA88C 3C03800A */  lui       $v1, %hi(nuGfxCfb_ptr)
/* 3B9460 E00BA890 8C63A64C */  lw        $v1, %lo(nuGfxCfb_ptr)($v1)
/* 3B9464 E00BA894 3C01C270 */  lui       $at, 0xc270
/* 3B9468 E00BA898 44810000 */  mtc1      $at, $f0
/* 3B946C E00BA89C 3C014320 */  lui       $at, 0x4320
/* 3B9470 E00BA8A0 44811000 */  mtc1      $at, $f2
/* 3B9474 E00BA8A4 3C014420 */  lui       $at, 0x4420
/* 3B9478 E00BA8A8 44812000 */  mtc1      $at, $f4
/* 3B947C E00BA8AC 3C013F80 */  lui       $at, 0x3f80
/* 3B9480 E00BA8B0 44813000 */  mtc1      $at, $f6
/* 3B9484 E00BA8B4 0100102D */  daddu     $v0, $t0, $zero
/* 3B9488 E00BA8B8 25080008 */  addiu     $t0, $t0, 8
/* 3B948C E00BA8BC AE080000 */  sw        $t0, ($s0)
/* 3B9490 E00BA8C0 AC460000 */  sw        $a2, ($v0)
/* 3B9494 E00BA8C4 AC430004 */  sw        $v1, 4($v0)
/* 3B9498 E00BA8C8 25020008 */  addiu     $v0, $t0, 8
/* 3B949C E00BA8CC AE020000 */  sw        $v0, ($s0)
/* 3B94A0 E00BA8D0 3C02FA00 */  lui       $v0, 0xfa00
/* 3B94A4 E00BA8D4 AD020000 */  sw        $v0, ($t0)
/* 3B94A8 E00BA8D8 9289001C */  lbu       $t1, 0x1c($s4)
/* 3B94AC E00BA8DC 9286001D */  lbu       $a2, 0x1d($s4)
/* 3B94B0 E00BA8E0 9287001E */  lbu       $a3, 0x1e($s4)
/* 3B94B4 E00BA8E4 25020010 */  addiu     $v0, $t0, 0x10
/* 3B94B8 E00BA8E8 AE020000 */  sw        $v0, ($s0)
/* 3B94BC E00BA8EC 25020018 */  addiu     $v0, $t0, 0x18
/* 3B94C0 E00BA8F0 AD0A0008 */  sw        $t2, 8($t0)
/* 3B94C4 E00BA8F4 AD00000C */  sw        $zero, 0xc($t0)
/* 3B94C8 E00BA8F8 AE020000 */  sw        $v0, ($s0)
/* 3B94CC E00BA8FC 25020020 */  addiu     $v0, $t0, 0x20
/* 3B94D0 E00BA900 AD0C0010 */  sw        $t4, 0x10($t0)
/* 3B94D4 E00BA904 AD0B0014 */  sw        $t3, 0x14($t0)
/* 3B94D8 E00BA908 AE020000 */  sw        $v0, ($s0)
/* 3B94DC E00BA90C 3C02800A */  lui       $v0, %hi(nuGfxZBuffer)
/* 3B94E0 E00BA910 8C42A5DC */  lw        $v0, %lo(nuGfxZBuffer)($v0)
/* 3B94E4 E00BA914 3C038000 */  lui       $v1, 0x8000
/* 3B94E8 E00BA918 AD0D0018 */  sw        $t5, 0x18($t0)
/* 3B94EC E00BA91C 00431021 */  addu      $v0, $v0, $v1
/* 3B94F0 E00BA920 AD02001C */  sw        $v0, 0x1c($t0)
/* 3B94F4 E00BA924 25020028 */  addiu     $v0, $t0, 0x28
/* 3B94F8 E00BA928 AE020000 */  sw        $v0, ($s0)
/* 3B94FC E00BA92C 25020030 */  addiu     $v0, $t0, 0x30
/* 3B9500 E00BA930 AD0F0020 */  sw        $t7, 0x20($t0)
/* 3B9504 E00BA934 AD0E0024 */  sw        $t6, 0x24($t0)
/* 3B9508 E00BA938 AE020000 */  sw        $v0, ($s0)
/* 3B950C E00BA93C 3C020008 */  lui       $v0, 8
/* 3B9510 E00BA940 AD02002C */  sw        $v0, 0x2c($t0)
/* 3B9514 E00BA944 25020038 */  addiu     $v0, $t0, 0x38
/* 3B9518 E00BA948 AD110028 */  sw        $s1, 0x28($t0)
/* 3B951C E00BA94C AE020000 */  sw        $v0, ($s0)
/* 3B9520 E00BA950 24022000 */  addiu     $v0, $zero, 0x2000
/* 3B9524 E00BA954 00094E00 */  sll       $t1, $t1, 0x18
/* 3B9528 E00BA958 00063400 */  sll       $a2, $a2, 0x10
/* 3B952C E00BA95C 01264825 */  or        $t1, $t1, $a2
/* 3B9530 E00BA960 00073A00 */  sll       $a3, $a3, 8
/* 3B9534 E00BA964 01274825 */  or        $t1, $t1, $a3
/* 3B9538 E00BA968 AD020034 */  sw        $v0, 0x34($t0)
/* 3B953C E00BA96C 00191042 */  srl       $v0, $t9, 1
/* 3B9540 E00BA970 3C0642A0 */  lui       $a2, 0x42a0
/* 3B9544 E00BA974 3C074270 */  lui       $a3, 0x4270
/* 3B9548 E00BA978 01224825 */  or        $t1, $t1, $v0
/* 3B954C E00BA97C AD120030 */  sw        $s2, 0x30($t0)
/* 3B9550 E00BA980 AD090004 */  sw        $t1, 4($t0)
/* 3B9554 E00BA984 E7A00010 */  swc1      $f0, 0x10($sp)
/* 3B9558 E00BA988 E7A20014 */  swc1      $f2, 0x14($sp)
/* 3B955C E00BA98C E7A40018 */  swc1      $f4, 0x18($sp)
/* 3B9560 E00BA990 0C080188 */  jal       func_E0200620
/* 3B9564 E00BA994 E7A6001C */   swc1     $f6, 0x1c($sp)
/* 3B9568 E00BA998 27A40020 */  addiu     $a0, $sp, 0x20
/* 3B956C E00BA99C 3C118007 */  lui       $s1, %hi(gMatrixListPos)
/* 3B9570 E00BA9A0 263141F0 */  addiu     $s1, $s1, %lo(gMatrixListPos)
/* 3B9574 E00BA9A4 3C12800A */  lui       $s2, %hi(gDisplayContext)
/* 3B9578 E00BA9A8 2652A674 */  addiu     $s2, $s2, %lo(gDisplayContext)
/* 3B957C E00BA9AC 96250000 */  lhu       $a1, ($s1)
/* 3B9580 E00BA9B0 8E420000 */  lw        $v0, ($s2)
/* 3B9584 E00BA9B4 00052980 */  sll       $a1, $a1, 6
/* 3B9588 E00BA9B8 00B32821 */  addu      $a1, $a1, $s3
/* 3B958C E00BA9BC 0C080118 */  jal       func_E0200460
/* 3B9590 E00BA9C0 00452821 */   addu     $a1, $v0, $a1
/* 3B9594 E00BA9C4 3C03DA38 */  lui       $v1, 0xda38
/* 3B9598 E00BA9C8 34630007 */  ori       $v1, $v1, 7
/* 3B959C E00BA9CC 3C06D9FD */  lui       $a2, 0xd9fd
/* 3B95A0 E00BA9D0 34C6F9FF */  ori       $a2, $a2, 0xf9ff
/* 3B95A4 E00BA9D4 3C08D9FF */  lui       $t0, 0xd9ff
/* 3B95A8 E00BA9D8 3508FFFF */  ori       $t0, $t0, 0xffff
/* 3B95AC E00BA9DC 3C070020 */  lui       $a3, 0x20
/* 3B95B0 E00BA9E0 34E70004 */  ori       $a3, $a3, 4
/* 3B95B4 E00BA9E4 3C090101 */  lui       $t1, 0x101
/* 3B95B8 E00BA9E8 35290020 */  ori       $t1, $t1, 0x20
/* 3B95BC E00BA9EC 0000702D */  daddu     $t6, $zero, $zero
/* 3B95C0 E00BA9F0 3C150218 */  lui       $s5, 0x218
/* 3B95C4 E00BA9F4 24190018 */  addiu     $t9, $zero, 0x18
/* 3B95C8 E00BA9F8 8E040000 */  lw        $a0, ($s0)
/* 3B95CC E00BA9FC 96220000 */  lhu       $v0, ($s1)
/* 3B95D0 E00BAA00 0080282D */  daddu     $a1, $a0, $zero
/* 3B95D4 E00BAA04 24840008 */  addiu     $a0, $a0, 8
/* 3B95D8 E00BAA08 AE040000 */  sw        $a0, ($s0)
/* 3B95DC E00BAA0C ACA30000 */  sw        $v1, ($a1)
/* 3B95E0 E00BAA10 24430001 */  addiu     $v1, $v0, 1
/* 3B95E4 E00BAA14 3042FFFF */  andi      $v0, $v0, 0xffff
/* 3B95E8 E00BAA18 00021180 */  sll       $v0, $v0, 6
/* 3B95EC E00BAA1C A6230000 */  sh        $v1, ($s1)
/* 3B95F0 E00BAA20 8E430000 */  lw        $v1, ($s2)
/* 3B95F4 E00BAA24 00531021 */  addu      $v0, $v0, $s3
/* 3B95F8 E00BAA28 00621821 */  addu      $v1, $v1, $v0
/* 3B95FC E00BAA2C 24820008 */  addiu     $v0, $a0, 8
/* 3B9600 E00BAA30 ACA30004 */  sw        $v1, 4($a1)
/* 3B9604 E00BAA34 AE020000 */  sw        $v0, ($s0)
/* 3B9608 E00BAA38 24820010 */  addiu     $v0, $a0, 0x10
/* 3B960C E00BAA3C AC860000 */  sw        $a2, ($a0)
/* 3B9610 E00BAA40 AC800004 */  sw        $zero, 4($a0)
/* 3B9614 E00BAA44 AE020000 */  sw        $v0, ($s0)
/* 3B9618 E00BAA48 00991021 */  addu      $v0, $a0, $t9
/* 3B961C E00BAA4C AC880008 */  sw        $t0, 8($a0)
/* 3B9620 E00BAA50 AC87000C */  sw        $a3, 0xc($a0)
/* 3B9624 E00BAA54 AE020000 */  sw        $v0, ($s0)
/* 3B9628 E00BAA58 3C020900 */  lui       $v0, 0x900
/* 3B962C E00BAA5C 24420428 */  addiu     $v0, $v0, 0x428
/* 3B9630 E00BAA60 AC890010 */  sw        $t1, 0x10($a0)
/* 3B9634 E00BAA64 AC820014 */  sw        $v0, 0x14($a0)
.LE00BAA68:
/* 3B9638 E00BAA68 15C00004 */  bnez      $t6, .LE00BAA7C
/* 3B963C E00BAA6C 0000902D */   daddu    $s2, $zero, $zero
/* 3B9640 E00BAA70 2404FFFC */  addiu     $a0, $zero, -4
/* 3B9644 E00BAA74 0802EAA0 */  j         .LE00BAA80
/* 3B9648 E00BAA78 24120001 */   addiu    $s2, $zero, 1
.LE00BAA7C:
/* 3B964C E00BAA7C 0000202D */  daddu     $a0, $zero, $zero
.LE00BAA80:
/* 3B9650 E00BAA80 2402000B */  addiu     $v0, $zero, 0xb
/* 3B9654 E00BAA84 15C20003 */  bne       $t6, $v0, .LE00BAA94
/* 3B9658 E00BAA88 0000182D */   daddu    $v1, $zero, $zero
/* 3B965C E00BAA8C 24030004 */  addiu     $v1, $zero, 4
/* 3B9660 E00BAA90 24120001 */  addiu     $s2, $zero, 1
.LE00BAA94:
/* 3B9664 E00BAA94 0000682D */  daddu     $t5, $zero, $zero
/* 3B9668 E00BAA98 03241021 */  addu      $v0, $t9, $a0
/* 3B966C E00BAA9C 0002C080 */  sll       $t8, $v0, 2
/* 3B9670 E00BAAA0 33020FFF */  andi      $v0, $t8, 0xfff
/* 3B9674 E00BAAA4 3C16F400 */  lui       $s6, 0xf400
/* 3B9678 E00BAAA8 0056B025 */  or        $s6, $v0, $s6
/* 3B967C E00BAAAC AFB600A0 */  sw        $s6, 0xa0($sp)
/* 3B9680 E00BAAB0 03231821 */  addu      $v1, $t9, $v1
/* 3B9684 E00BAAB4 24620010 */  addiu     $v0, $v1, 0x10
/* 3B9688 E00BAAB8 00029880 */  sll       $s3, $v0, 2
/* 3B968C E00BAABC 32620FFF */  andi      $v0, $s3, 0xfff
/* 3B9690 E00BAAC0 3C160700 */  lui       $s6, 0x700
/* 3B9694 E00BAAC4 0056F025 */  or        $fp, $v0, $s6
/* 3B9698 E00BAAC8 2463001F */  addiu     $v1, $v1, 0x1f
/* 3B969C E00BAACC 00031880 */  sll       $v1, $v1, 2
/* 3B96A0 E00BAAD0 30770FFF */  andi      $s7, $v1, 0xfff
/* 3B96A4 E00BAAD4 0012B023 */  negu      $s6, $s2
/* 3B96A8 E00BAAD8 AFB600A8 */  sw        $s6, 0xa8($sp)
.LE00BAADC:
/* 3B96AC E00BAADC 0000502D */  daddu     $t2, $zero, $zero
/* 3B96B0 E00BAAE0 000D1100 */  sll       $v0, $t5, 4
/* 3B96B4 E00BAAE4 15A00004 */  bnez      $t5, .LE00BAAF8
/* 3B96B8 E00BAAE8 244F0010 */   addiu    $t7, $v0, 0x10
/* 3B96BC E00BAAEC 240BFFFC */  addiu     $t3, $zero, -4
/* 3B96C0 E00BAAF0 0802EABF */  j         .LE00BAAFC
/* 3B96C4 E00BAAF4 240A0001 */   addiu    $t2, $zero, 1
.LE00BAAF8:
/* 3B96C8 E00BAAF8 0000582D */  daddu     $t3, $zero, $zero
.LE00BAAFC:
/* 3B96CC E00BAAFC 24020011 */  addiu     $v0, $zero, 0x11
/* 3B96D0 E00BAB00 15A20003 */  bne       $t5, $v0, .LE00BAB10
/* 3B96D4 E00BAB04 0000882D */   daddu    $s1, $zero, $zero
/* 3B96D8 E00BAB08 24110004 */  addiu     $s1, $zero, 4
/* 3B96DC E00BAB0C 240A0001 */  addiu     $t2, $zero, 1
.LE00BAB10:
/* 3B96E0 E00BAB10 3C080709 */  lui       $t0, 0x709
/* 3B96E4 E00BAB14 35088260 */  ori       $t0, $t0, 0x8260
/* 3B96E8 E00BAB18 3C090009 */  lui       $t1, 9
/* 3B96EC E00BAB1C 35298260 */  ori       $t1, $t1, 0x8260
/* 3B96F0 E00BAB20 01F13021 */  addu      $a2, $t7, $s1
/* 3B96F4 E00BAB24 01EB2021 */  addu      $a0, $t7, $t3
/* 3B96F8 E00BAB28 2483FFF0 */  addiu     $v1, $a0, -0x10
/* 3B96FC E00BAB2C 00C31823 */  subu      $v1, $a2, $v1
/* 3B9700 E00BAB30 24630001 */  addiu     $v1, $v1, 1
/* 3B9704 E00BAB34 00031840 */  sll       $v1, $v1, 1
/* 3B9708 E00BAB38 24630007 */  addiu     $v1, $v1, 7
/* 3B970C E00BAB3C 000318C3 */  sra       $v1, $v1, 3
/* 3B9710 E00BAB40 306301FF */  andi      $v1, $v1, 0x1ff
/* 3B9714 E00BAB44 00031A40 */  sll       $v1, $v1, 9
/* 3B9718 E00BAB48 3C02F510 */  lui       $v0, 0xf510
/* 3B971C E00BAB4C 00621825 */  or        $v1, $v1, $v0
/* 3B9720 E00BAB50 00042080 */  sll       $a0, $a0, 2
/* 3B9724 E00BAB54 30840FFF */  andi      $a0, $a0, 0xfff
/* 3B9728 E00BAB58 8E050000 */  lw        $a1, ($s0)
/* 3B972C E00BAB5C 00042300 */  sll       $a0, $a0, 0xc
/* 3B9730 E00BAB60 00A0382D */  daddu     $a3, $a1, $zero
/* 3B9734 E00BAB64 24A50008 */  addiu     $a1, $a1, 8
/* 3B9738 E00BAB68 24A20008 */  addiu     $v0, $a1, 8
/* 3B973C E00BAB6C AE050000 */  sw        $a1, ($s0)
/* 3B9740 E00BAB70 ACE30000 */  sw        $v1, ($a3)
/* 3B9744 E00BAB74 ACE80004 */  sw        $t0, 4($a3)
/* 3B9748 E00BAB78 AE020000 */  sw        $v0, ($s0)
/* 3B974C E00BAB7C 3C02E600 */  lui       $v0, 0xe600
/* 3B9750 E00BAB80 ACA20000 */  sw        $v0, ($a1)
/* 3B9754 E00BAB84 24A20010 */  addiu     $v0, $a1, 0x10
/* 3B9758 E00BAB88 ACA00004 */  sw        $zero, 4($a1)
/* 3B975C E00BAB8C AE020000 */  sw        $v0, ($s0)
/* 3B9760 E00BAB90 24C20010 */  addiu     $v0, $a2, 0x10
/* 3B9764 E00BAB94 00021080 */  sll       $v0, $v0, 2
/* 3B9768 E00BAB98 30420FFF */  andi      $v0, $v0, 0xfff
/* 3B976C E00BAB9C 00021300 */  sll       $v0, $v0, 0xc
/* 3B9770 E00BABA0 8FB600A0 */  lw        $s6, 0xa0($sp)
/* 3B9774 E00BABA4 005E1025 */  or        $v0, $v0, $fp
/* 3B9778 E00BABA8 ACA2000C */  sw        $v0, 0xc($a1)
/* 3B977C E00BABAC 24A20018 */  addiu     $v0, $a1, 0x18
/* 3B9780 E00BABB0 24C6001F */  addiu     $a2, $a2, 0x1f
/* 3B9784 E00BABB4 00063080 */  sll       $a2, $a2, 2
/* 3B9788 E00BABB8 30C60FFF */  andi      $a2, $a2, 0xfff
/* 3B978C E00BABBC 00063300 */  sll       $a2, $a2, 0xc
/* 3B9790 E00BABC0 00D73025 */  or        $a2, $a2, $s7
/* 3B9794 E00BABC4 00962025 */  or        $a0, $a0, $s6
/* 3B9798 E00BABC8 3C16E700 */  lui       $s6, 0xe700
/* 3B979C E00BABCC ACA40008 */  sw        $a0, 8($a1)
/* 3B97A0 E00BABD0 AE020000 */  sw        $v0, ($s0)
/* 3B97A4 E00BABD4 24A20020 */  addiu     $v0, $a1, 0x20
/* 3B97A8 E00BABD8 ACB60010 */  sw        $s6, 0x10($a1)
/* 3B97AC E00BABDC ACA00014 */  sw        $zero, 0x14($a1)
/* 3B97B0 E00BABE0 AE020000 */  sw        $v0, ($s0)
/* 3B97B4 E00BABE4 24A20028 */  addiu     $v0, $a1, 0x28
/* 3B97B8 E00BABE8 ACA30018 */  sw        $v1, 0x18($a1)
/* 3B97BC E00BABEC ACA9001C */  sw        $t1, 0x1c($a1)
/* 3B97C0 E00BABF0 AE020000 */  sw        $v0, ($s0)
/* 3B97C4 E00BABF4 3C02F200 */  lui       $v0, 0xf200
/* 3B97C8 E00BABF8 ACA20020 */  sw        $v0, 0x20($a1)
/* 3B97CC E00BABFC 11400003 */  beqz      $t2, .LE00BAC0C
/* 3B97D0 E00BAC00 ACA60024 */   sw       $a2, 0x24($a1)
/* 3B97D4 E00BAC04 16400005 */  bnez      $s2, .LE00BAC1C
/* 3B97D8 E00BAC08 240C000C */   addiu    $t4, $zero, 0xc
.LE00BAC0C:
/* 3B97DC E00BAC0C 15400003 */  bnez      $t2, .LE00BAC1C
/* 3B97E0 E00BAC10 240C0004 */   addiu    $t4, $zero, 4
/* 3B97E4 E00BAC14 8FB600A8 */  lw        $s6, 0xa8($sp)
/* 3B97E8 E00BAC18 32CC0008 */  andi      $t4, $s6, 8
.LE00BAC1C:
/* 3B97EC E00BAC1C 000D2840 */  sll       $a1, $t5, 1
/* 3B97F0 E00BAC20 00AD2821 */  addu      $a1, $a1, $t5
/* 3B97F4 E00BAC24 00052880 */  sll       $a1, $a1, 2
/* 3B97F8 E00BAC28 00AD2821 */  addu      $a1, $a1, $t5
/* 3B97FC E00BAC2C 25A20001 */  addiu     $v0, $t5, 1
/* 3B9800 E00BAC30 0040682D */  daddu     $t5, $v0, $zero
/* 3B9804 E00BAC34 000C5040 */  sll       $t2, $t4, 1
/* 3B9808 E00BAC38 01551025 */  or        $v0, $t2, $s5
/* 3B980C E00BAC3C 01EB4821 */  addu      $t1, $t7, $t3
/* 3B9810 E00BAC40 00094C80 */  sll       $t1, $t1, 0x12
/* 3B9814 E00BAC44 258B0001 */  addiu     $t3, $t4, 1
/* 3B9818 E00BAC48 000B5840 */  sll       $t3, $t3, 1
/* 3B981C E00BAC4C 25880002 */  addiu     $t0, $t4, 2
/* 3B9820 E00BAC50 00084040 */  sll       $t0, $t0, 1
/* 3B9824 E00BAC54 01F13821 */  addu      $a3, $t7, $s1
/* 3B9828 E00BAC58 24E70010 */  addiu     $a3, $a3, 0x10
/* 3B982C E00BAC5C 00073C80 */  sll       $a3, $a3, 0x12
/* 3B9830 E00BAC60 8E060000 */  lw        $a2, ($s0)
/* 3B9834 E00BAC64 000A5400 */  sll       $t2, $t2, 0x10
/* 3B9838 E00BAC68 00C0202D */  daddu     $a0, $a2, $zero
/* 3B983C E00BAC6C 24C60008 */  addiu     $a2, $a2, 8
/* 3B9840 E00BAC70 AE060000 */  sw        $a2, ($s0)
/* 3B9844 E00BAC74 AC820000 */  sw        $v0, ($a0)
/* 3B9848 E00BAC78 01C51021 */  addu      $v0, $t6, $a1
/* 3B984C E00BAC7C 02821021 */  addu      $v0, $s4, $v0
/* 3B9850 E00BAC80 80430023 */  lb        $v1, 0x23($v0)
/* 3B9854 E00BAC84 24C20008 */  addiu     $v0, $a2, 8
/* 3B9858 E00BAC88 AE020000 */  sw        $v0, ($s0)
/* 3B985C E00BAC8C 01751025 */  or        $v0, $t3, $s5
/* 3B9860 E00BAC90 24A50001 */  addiu     $a1, $a1, 1
/* 3B9864 E00BAC94 01C52821 */  addu      $a1, $t6, $a1
/* 3B9868 E00BAC98 02852821 */  addu      $a1, $s4, $a1
/* 3B986C E00BAC9C 03031821 */  addu      $v1, $t8, $v1
/* 3B9870 E00BACA0 01231825 */  or        $v1, $t1, $v1
/* 3B9874 E00BACA4 AC830004 */  sw        $v1, 4($a0)
/* 3B9878 E00BACA8 000D1840 */  sll       $v1, $t5, 1
/* 3B987C E00BACAC 006D1821 */  addu      $v1, $v1, $t5
/* 3B9880 E00BACB0 00031880 */  sll       $v1, $v1, 2
/* 3B9884 E00BACB4 006D1821 */  addu      $v1, $v1, $t5
/* 3B9888 E00BACB8 ACC20000 */  sw        $v0, ($a2)
/* 3B988C E00BACBC 01C31021 */  addu      $v0, $t6, $v1
/* 3B9890 E00BACC0 02821021 */  addu      $v0, $s4, $v0
/* 3B9894 E00BACC4 80440023 */  lb        $a0, 0x23($v0)
/* 3B9898 E00BACC8 24C20010 */  addiu     $v0, $a2, 0x10
/* 3B989C E00BACCC AE020000 */  sw        $v0, ($s0)
/* 3B98A0 E00BACD0 01151025 */  or        $v0, $t0, $s5
/* 3B98A4 E00BACD4 ACC20008 */  sw        $v0, 8($a2)
/* 3B98A8 E00BACD8 24C20018 */  addiu     $v0, $a2, 0x18
/* 3B98AC E00BACDC 24630001 */  addiu     $v1, $v1, 1
/* 3B98B0 E00BACE0 01C31821 */  addu      $v1, $t6, $v1
/* 3B98B4 E00BACE4 02831821 */  addu      $v1, $s4, $v1
/* 3B98B8 E00BACE8 00084200 */  sll       $t0, $t0, 8
/* 3B98BC E00BACEC 03042021 */  addu      $a0, $t8, $a0
/* 3B98C0 E00BACF0 00E42025 */  or        $a0, $a3, $a0
/* 3B98C4 E00BACF4 ACC40004 */  sw        $a0, 4($a2)
/* 3B98C8 E00BACF8 80A40023 */  lb        $a0, 0x23($a1)
/* 3B98CC E00BACFC 25850003 */  addiu     $a1, $t4, 3
/* 3B98D0 E00BAD00 00052840 */  sll       $a1, $a1, 1
/* 3B98D4 E00BAD04 AE020000 */  sw        $v0, ($s0)
/* 3B98D8 E00BAD08 00B51025 */  or        $v0, $a1, $s5
/* 3B98DC E00BAD0C ACC20010 */  sw        $v0, 0x10($a2)
/* 3B98E0 E00BAD10 24C20020 */  addiu     $v0, $a2, 0x20
/* 3B98E4 E00BAD14 02642021 */  addu      $a0, $s3, $a0
/* 3B98E8 E00BAD18 01244825 */  or        $t1, $t1, $a0
/* 3B98EC E00BAD1C ACC9000C */  sw        $t1, 0xc($a2)
/* 3B98F0 E00BAD20 80640023 */  lb        $a0, 0x23($v1)
/* 3B98F4 E00BAD24 30A500FF */  andi      $a1, $a1, 0xff
/* 3B98F8 E00BAD28 AE020000 */  sw        $v0, ($s0)
/* 3B98FC E00BAD2C 00051200 */  sll       $v0, $a1, 8
/* 3B9900 E00BAD30 01421025 */  or        $v0, $t2, $v0
/* 3B9904 E00BAD34 004B1025 */  or        $v0, $v0, $t3
/* 3B9908 E00BAD38 3C030600 */  lui       $v1, 0x600
/* 3B990C E00BAD3C 00431025 */  or        $v0, $v0, $v1
/* 3B9910 E00BAD40 01485025 */  or        $t2, $t2, $t0
/* 3B9914 E00BAD44 01455025 */  or        $t2, $t2, $a1
/* 3B9918 E00BAD48 ACC20018 */  sw        $v0, 0x18($a2)
/* 3B991C E00BAD4C 24C20028 */  addiu     $v0, $a2, 0x28
/* 3B9920 E00BAD50 3C16E700 */  lui       $s6, 0xe700
/* 3B9924 E00BAD54 ACCA001C */  sw        $t2, 0x1c($a2)
/* 3B9928 E00BAD58 AE020000 */  sw        $v0, ($s0)
/* 3B992C E00BAD5C 29A20012 */  slti      $v0, $t5, 0x12
/* 3B9930 E00BAD60 ACD60020 */  sw        $s6, 0x20($a2)
/* 3B9934 E00BAD64 ACC00024 */  sw        $zero, 0x24($a2)
/* 3B9938 E00BAD68 02642021 */  addu      $a0, $s3, $a0
/* 3B993C E00BAD6C 00E43825 */  or        $a3, $a3, $a0
/* 3B9940 E00BAD70 1440FF5A */  bnez      $v0, .LE00BAADC
/* 3B9944 E00BAD74 ACC70014 */   sw       $a3, 0x14($a2)
/* 3B9948 E00BAD78 25CE0001 */  addiu     $t6, $t6, 1
/* 3B994C E00BAD7C 29C2000C */  slti      $v0, $t6, 0xc
/* 3B9950 E00BAD80 1440FF39 */  bnez      $v0, .LE00BAA68
/* 3B9954 E00BAD84 27390010 */   addiu    $t9, $t9, 0x10
/* 3B9958 E00BAD88 3C06FF10 */  lui       $a2, 0xff10
/* 3B995C E00BAD8C 34C6013F */  ori       $a2, $a2, 0x13f
/* 3B9960 E00BAD90 3C07DA38 */  lui       $a3, 0xda38
/* 3B9964 E00BAD94 3C05800A */  lui       $a1, %hi(gMasterGfxPos)
/* 3B9968 E00BAD98 24A5A66C */  addiu     $a1, $a1, %lo(gMasterGfxPos)
/* 3B996C E00BAD9C 8CA30000 */  lw        $v1, ($a1)
/* 3B9970 E00BADA0 3C04800A */  lui       $a0, %hi(nuGfxZBuffer)
/* 3B9974 E00BADA4 8C84A5DC */  lw        $a0, %lo(nuGfxZBuffer)($a0)
/* 3B9978 E00BADA8 0060102D */  daddu     $v0, $v1, $zero
/* 3B997C E00BADAC 24630008 */  addiu     $v1, $v1, 8
/* 3B9980 E00BADB0 ACA30000 */  sw        $v1, ($a1)
/* 3B9984 E00BADB4 AC460000 */  sw        $a2, ($v0)
/* 3B9988 E00BADB8 AC440004 */  sw        $a0, 4($v0)
/* 3B998C E00BADBC 24620008 */  addiu     $v0, $v1, 8
/* 3B9990 E00BADC0 ACA20000 */  sw        $v0, ($a1)
/* 3B9994 E00BADC4 3C04800A */  lui       $a0, %hi(nuGfxCfb_ptr)
/* 3B9998 E00BADC8 8C84A64C */  lw        $a0, %lo(nuGfxCfb_ptr)($a0)
/* 3B999C E00BADCC 3C02DE00 */  lui       $v0, 0xde00
/* 3B99A0 E00BADD0 AC620000 */  sw        $v0, ($v1)
/* 3B99A4 E00BADD4 3C020900 */  lui       $v0, 0x900
/* 3B99A8 E00BADD8 24420570 */  addiu     $v0, $v0, 0x570
/* 3B99AC E00BADDC AC620004 */  sw        $v0, 4($v1)
/* 3B99B0 E00BADE0 24620010 */  addiu     $v0, $v1, 0x10
/* 3B99B4 E00BADE4 ACA20000 */  sw        $v0, ($a1)
/* 3B99B8 E00BADE8 24620018 */  addiu     $v0, $v1, 0x18
/* 3B99BC E00BADEC AC660008 */  sw        $a2, 8($v1)
/* 3B99C0 E00BADF0 02C0302D */  daddu     $a2, $s6, $zero
/* 3B99C4 E00BADF4 AC64000C */  sw        $a0, 0xc($v1)
/* 3B99C8 E00BADF8 ACA20000 */  sw        $v0, ($a1)
/* 3B99CC E00BADFC 3C048007 */  lui       $a0, %hi(gCurrentCameraID)
/* 3B99D0 E00BAE00 8C847410 */  lw        $a0, %lo(gCurrentCameraID)($a0)
/* 3B99D4 E00BAE04 24620020 */  addiu     $v0, $v1, 0x20
/* 3B99D8 E00BAE08 AC660010 */  sw        $a2, 0x10($v1)
/* 3B99DC E00BAE0C AC600014 */  sw        $zero, 0x14($v1)
/* 3B99E0 E00BAE10 ACA20000 */  sw        $v0, ($a1)
/* 3B99E4 E00BAE14 3C02800A */  lui       $v0, %hi(gDisplayContext)
/* 3B99E8 E00BAE18 8C42A674 */  lw        $v0, %lo(gDisplayContext)($v0)
/* 3B99EC E00BAE1C 34E70007 */  ori       $a3, $a3, 7
/* 3B99F0 E00BAE20 AC670018 */  sw        $a3, 0x18($v1)
/* 3B99F4 E00BAE24 00042180 */  sll       $a0, $a0, 6
/* 3B99F8 E00BAE28 24840030 */  addiu     $a0, $a0, 0x30
/* 3B99FC E00BAE2C 00441021 */  addu      $v0, $v0, $a0
/* 3B9A00 E00BAE30 AC62001C */  sw        $v0, 0x1c($v1)
/* 3B9A04 E00BAE34 24620028 */  addiu     $v0, $v1, 0x28
/* 3B9A08 E00BAE38 ACA20000 */  sw        $v0, ($a1)
/* 3B9A0C E00BAE3C AC660020 */  sw        $a2, 0x20($v1)
/* 3B9A10 E00BAE40 AC600024 */  sw        $zero, 0x24($v1)
/* 3B9A14 E00BAE44 8FBF00D4 */  lw        $ra, 0xd4($sp)
/* 3B9A18 E00BAE48 8FBE00D0 */  lw        $fp, 0xd0($sp)
/* 3B9A1C E00BAE4C 8FB700CC */  lw        $s7, 0xcc($sp)
/* 3B9A20 E00BAE50 8FB600C8 */  lw        $s6, 0xc8($sp)
/* 3B9A24 E00BAE54 8FB500C4 */  lw        $s5, 0xc4($sp)
/* 3B9A28 E00BAE58 8FB400C0 */  lw        $s4, 0xc0($sp)
/* 3B9A2C E00BAE5C 8FB300BC */  lw        $s3, 0xbc($sp)
/* 3B9A30 E00BAE60 8FB200B8 */  lw        $s2, 0xb8($sp)
/* 3B9A34 E00BAE64 8FB100B4 */  lw        $s1, 0xb4($sp)
/* 3B9A38 E00BAE68 8FB000B0 */  lw        $s0, 0xb0($sp)
/* 3B9A3C E00BAE6C 03E00008 */  jr        $ra
/* 3B9A40 E00BAE70 27BD00D8 */   addiu    $sp, $sp, 0xd8
/* 3B9A44 E00BAE74 00000000 */  nop
/* 3B9A48 E00BAE78 00000000 */  nop
/* 3B9A4C E00BAE7C 00000000 */  nop
