.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240310_B06D10
/* B06D10 80240310 27BDFF10 */  addiu     $sp, $sp, -0xf0
/* B06D14 80240314 0000202D */  daddu     $a0, $zero, $zero
/* B06D18 80240318 3C05FD05 */  lui       $a1, 0xfd05
/* B06D1C 8024031C AFBF00DC */  sw        $ra, 0xdc($sp)
/* B06D20 80240320 AFB600D8 */  sw        $s6, 0xd8($sp)
/* B06D24 80240324 AFB500D4 */  sw        $s5, 0xd4($sp)
/* B06D28 80240328 AFB400D0 */  sw        $s4, 0xd0($sp)
/* B06D2C 8024032C AFB300CC */  sw        $s3, 0xcc($sp)
/* B06D30 80240330 AFB200C8 */  sw        $s2, 0xc8($sp)
/* B06D34 80240334 AFB100C4 */  sw        $s1, 0xc4($sp)
/* B06D38 80240338 AFB000C0 */  sw        $s0, 0xc0($sp)
/* B06D3C 8024033C F7B600E8 */  sdc1      $f22, 0xe8($sp)
/* B06D40 80240340 F7B400E0 */  sdc1      $f20, 0xe0($sp)
/* B06D44 80240344 0C0B1EAF */  jal       get_variable
/* B06D48 80240348 34A50F8A */   ori      $a1, $a1, 0xf8a
/* B06D4C 8024034C 3C07E300 */  lui       $a3, 0xe300
/* B06D50 80240350 34E70A01 */  ori       $a3, $a3, 0xa01
/* B06D54 80240354 3C08D9C0 */  lui       $t0, 0xd9c0
/* B06D58 80240358 3508F9FB */  ori       $t0, $t0, 0xf9fb
/* B06D5C 8024035C 3C0AD9FF */  lui       $t2, 0xd9ff
/* B06D60 80240360 354AFFFF */  ori       $t2, $t2, 0xffff
/* B06D64 80240364 3C090020 */  lui       $t1, 0x20
/* B06D68 80240368 35290005 */  ori       $t1, $t1, 5
/* B06D6C 8024036C 3C0BD700 */  lui       $t3, 0xd700
/* B06D70 80240370 356B0002 */  ori       $t3, $t3, 2
/* B06D74 80240374 3C0CE300 */  lui       $t4, 0xe300
/* B06D78 80240378 358C0F00 */  ori       $t4, $t4, 0xf00
/* B06D7C 8024037C 3C0DE300 */  lui       $t5, 0xe300
/* B06D80 80240380 35AD0C00 */  ori       $t5, $t5, 0xc00
/* B06D84 80240384 3C0EE300 */  lui       $t6, 0xe300
/* B06D88 80240388 35CE1201 */  ori       $t6, $t6, 0x1201
/* B06D8C 8024038C 3C0FE300 */  lui       $t7, 0xe300
/* B06D90 80240390 35EF1801 */  ori       $t7, $t7, 0x1801
/* B06D94 80240394 3C10E300 */  lui       $s0, 0xe300
/* B06D98 80240398 36100D01 */  ori       $s0, $s0, 0xd01
/* B06D9C 8024039C 3C12E300 */  lui       $s2, 0xe300
/* B06DA0 802403A0 36521402 */  ori       $s2, $s2, 0x1402
/* B06DA4 802403A4 3C14E300 */  lui       $s4, 0xe300
/* B06DA8 802403A8 36941700 */  ori       $s4, $s4, 0x1700
/* B06DAC 802403AC 3C15E200 */  lui       $s5, 0xe200
/* B06DB0 802403B0 36B51E01 */  ori       $s5, $s5, 0x1e01
/* B06DB4 802403B4 27B30040 */  addiu     $s3, $sp, 0x40
/* B06DB8 802403B8 0260202D */  daddu     $a0, $s3, $zero
/* B06DBC 802403BC 3C160001 */  lui       $s6, 1
/* B06DC0 802403C0 3C11800A */  lui       $s1, %hi(gMasterGfxPos)
/* B06DC4 802403C4 2631A66C */  addiu     $s1, $s1, %lo(gMasterGfxPos)
/* B06DC8 802403C8 36D61630 */  ori       $s6, $s6, 0x1630
/* B06DCC 802403CC 3C05E700 */  lui       $a1, 0xe700
/* B06DD0 802403D0 8E230000 */  lw        $v1, ($s1)
/* B06DD4 802403D4 4480A000 */  mtc1      $zero, $f20
/* B06DD8 802403D8 0060302D */  daddu     $a2, $v1, $zero
/* B06DDC 802403DC 24630008 */  addiu     $v1, $v1, 8
/* B06DE0 802403E0 AE230000 */  sw        $v1, ($s1)
/* B06DE4 802403E4 ACC50000 */  sw        $a1, ($a2)
/* B06DE8 802403E8 24650008 */  addiu     $a1, $v1, 8
/* B06DEC 802403EC ACC00004 */  sw        $zero, 4($a2)
/* B06DF0 802403F0 AE250000 */  sw        $a1, ($s1)
/* B06DF4 802403F4 24650010 */  addiu     $a1, $v1, 0x10
/* B06DF8 802403F8 AC670000 */  sw        $a3, ($v1)
/* B06DFC 802403FC AC600004 */  sw        $zero, 4($v1)
/* B06E00 80240400 AE250000 */  sw        $a1, ($s1)
/* B06E04 80240404 24650018 */  addiu     $a1, $v1, 0x18
/* B06E08 80240408 AC680008 */  sw        $t0, 8($v1)
/* B06E0C 8024040C AC60000C */  sw        $zero, 0xc($v1)
/* B06E10 80240410 AE250000 */  sw        $a1, ($s1)
/* B06E14 80240414 24650020 */  addiu     $a1, $v1, 0x20
/* B06E18 80240418 AC6A0010 */  sw        $t2, 0x10($v1)
/* B06E1C 8024041C AC690014 */  sw        $t1, 0x14($v1)
/* B06E20 80240420 AE250000 */  sw        $a1, ($s1)
/* B06E24 80240424 2405FFFF */  addiu     $a1, $zero, -1
/* B06E28 80240428 AC65001C */  sw        $a1, 0x1c($v1)
/* B06E2C 8024042C 24650028 */  addiu     $a1, $v1, 0x28
/* B06E30 80240430 AC6B0018 */  sw        $t3, 0x18($v1)
/* B06E34 80240434 AE250000 */  sw        $a1, ($s1)
/* B06E38 80240438 24650030 */  addiu     $a1, $v1, 0x30
/* B06E3C 8024043C AC6C0020 */  sw        $t4, 0x20($v1)
/* B06E40 80240440 AC600024 */  sw        $zero, 0x24($v1)
/* B06E44 80240444 AE250000 */  sw        $a1, ($s1)
/* B06E48 80240448 3C050008 */  lui       $a1, 8
/* B06E4C 8024044C AC65002C */  sw        $a1, 0x2c($v1)
/* B06E50 80240450 24650038 */  addiu     $a1, $v1, 0x38
/* B06E54 80240454 AC6D0028 */  sw        $t5, 0x28($v1)
/* B06E58 80240458 AE250000 */  sw        $a1, ($s1)
/* B06E5C 8024045C 24052000 */  addiu     $a1, $zero, 0x2000
/* B06E60 80240460 AC650034 */  sw        $a1, 0x34($v1)
/* B06E64 80240464 24650040 */  addiu     $a1, $v1, 0x40
/* B06E68 80240468 AC6E0030 */  sw        $t6, 0x30($v1)
/* B06E6C 8024046C AE250000 */  sw        $a1, ($s1)
/* B06E70 80240470 240500C0 */  addiu     $a1, $zero, 0xc0
/* B06E74 80240474 AC65003C */  sw        $a1, 0x3c($v1)
/* B06E78 80240478 24650048 */  addiu     $a1, $v1, 0x48
/* B06E7C 8024047C AC6F0038 */  sw        $t7, 0x38($v1)
/* B06E80 80240480 AE250000 */  sw        $a1, ($s1)
/* B06E84 80240484 24650050 */  addiu     $a1, $v1, 0x50
/* B06E88 80240488 AC700040 */  sw        $s0, 0x40($v1)
/* B06E8C 8024048C AC600044 */  sw        $zero, 0x44($v1)
/* B06E90 80240490 AE250000 */  sw        $a1, ($s1)
/* B06E94 80240494 24050C00 */  addiu     $a1, $zero, 0xc00
/* B06E98 80240498 AC720048 */  sw        $s2, 0x48($v1)
/* B06E9C 8024049C 0040902D */  daddu     $s2, $v0, $zero
/* B06EA0 802404A0 24620058 */  addiu     $v0, $v1, 0x58
/* B06EA4 802404A4 AC65004C */  sw        $a1, 0x4c($v1)
/* B06EA8 802404A8 AC740050 */  sw        $s4, 0x50($v1)
/* B06EAC 802404AC AC600054 */  sw        $zero, 0x54($v1)
/* B06EB0 802404B0 AC750058 */  sw        $s5, 0x58($v1)
/* B06EB4 802404B4 AC60005C */  sw        $zero, 0x5c($v1)
/* B06EB8 802404B8 8E450010 */  lw        $a1, 0x10($s2)
/* B06EBC 802404BC 8E460014 */  lw        $a2, 0x14($s2)
/* B06EC0 802404C0 8E470018 */  lw        $a3, 0x18($s2)
/* B06EC4 802404C4 24630060 */  addiu     $v1, $v1, 0x60
/* B06EC8 802404C8 AE220000 */  sw        $v0, ($s1)
/* B06ECC 802404CC 0C019E40 */  jal       guTranslateF
/* B06ED0 802404D0 AE230000 */   sw       $v1, ($s1)
/* B06ED4 802404D4 27B00080 */  addiu     $s0, $sp, 0x80
/* B06ED8 802404D8 E7B40010 */  swc1      $f20, 0x10($sp)
/* B06EDC 802404DC 8E450020 */  lw        $a1, 0x20($s2)
/* B06EE0 802404E0 3C013F80 */  lui       $at, 0x3f80
/* B06EE4 802404E4 4481B000 */  mtc1      $at, $f22
/* B06EE8 802404E8 4406A000 */  mfc1      $a2, $f20
/* B06EEC 802404EC 4407B000 */  mfc1      $a3, $f22
/* B06EF0 802404F0 0C019EC8 */  jal       guRotateF
/* B06EF4 802404F4 0200202D */   daddu    $a0, $s0, $zero
/* B06EF8 802404F8 0200202D */  daddu     $a0, $s0, $zero
/* B06EFC 802404FC 0260282D */  daddu     $a1, $s3, $zero
/* B06F00 80240500 0C019D80 */  jal       guMtxCatF
/* B06F04 80240504 0260302D */   daddu    $a2, $s3, $zero
/* B06F08 80240508 E7B60010 */  swc1      $f22, 0x10($sp)
/* B06F0C 8024050C 8E450024 */  lw        $a1, 0x24($s2)
/* B06F10 80240510 4406A000 */  mfc1      $a2, $f20
/* B06F14 80240514 4407A000 */  mfc1      $a3, $f20
/* B06F18 80240518 0C019EC8 */  jal       guRotateF
/* B06F1C 8024051C 0200202D */   daddu    $a0, $s0, $zero
/* B06F20 80240520 0200202D */  daddu     $a0, $s0, $zero
/* B06F24 80240524 0260282D */  daddu     $a1, $s3, $zero
/* B06F28 80240528 0C019D80 */  jal       guMtxCatF
/* B06F2C 8024052C 0260302D */   daddu    $a2, $s3, $zero
/* B06F30 80240530 E7B40010 */  swc1      $f20, 0x10($sp)
/* B06F34 80240534 8E45001C */  lw        $a1, 0x1c($s2)
/* B06F38 80240538 4406B000 */  mfc1      $a2, $f22
/* B06F3C 8024053C 4407A000 */  mfc1      $a3, $f20
/* B06F40 80240540 0C019EC8 */  jal       guRotateF
/* B06F44 80240544 0200202D */   daddu    $a0, $s0, $zero
/* B06F48 80240548 0200202D */  daddu     $a0, $s0, $zero
/* B06F4C 8024054C 0260282D */  daddu     $a1, $s3, $zero
/* B06F50 80240550 0C019D80 */  jal       guMtxCatF
/* B06F54 80240554 0260302D */   daddu    $a2, $s3, $zero
/* B06F58 80240558 8E450028 */  lw        $a1, 0x28($s2)
/* B06F5C 8024055C 8E46002C */  lw        $a2, 0x2c($s2)
/* B06F60 80240560 8E470030 */  lw        $a3, 0x30($s2)
/* B06F64 80240564 0C019DF0 */  jal       guScaleF
/* B06F68 80240568 0200202D */   daddu    $a0, $s0, $zero
/* B06F6C 8024056C 0200202D */  daddu     $a0, $s0, $zero
/* B06F70 80240570 0260282D */  daddu     $a1, $s3, $zero
/* B06F74 80240574 0C019D80 */  jal       guMtxCatF
/* B06F78 80240578 0260302D */   daddu    $a2, $s3, $zero
/* B06F7C 8024057C 0260202D */  daddu     $a0, $s3, $zero
/* B06F80 80240580 3C108007 */  lui       $s0, %hi(gMatrixListPos)
/* B06F84 80240584 261041F0 */  addiu     $s0, $s0, %lo(gMatrixListPos)
/* B06F88 80240588 3C14800A */  lui       $s4, %hi(gDisplayContext)
/* B06F8C 8024058C 2694A674 */  addiu     $s4, $s4, %lo(gDisplayContext)
/* B06F90 80240590 96050000 */  lhu       $a1, ($s0)
/* B06F94 80240594 8E820000 */  lw        $v0, ($s4)
/* B06F98 80240598 00052980 */  sll       $a1, $a1, 6
/* B06F9C 8024059C 00B62821 */  addu      $a1, $a1, $s6
/* B06FA0 802405A0 0C019D40 */  jal       guMtxF2L
/* B06FA4 802405A4 00452821 */   addu     $a1, $v0, $a1
/* B06FA8 802405A8 3C02DA38 */  lui       $v0, 0xda38
/* B06FAC 802405AC 34420002 */  ori       $v0, $v0, 2
/* B06FB0 802405B0 27A40030 */  addiu     $a0, $sp, 0x30
/* B06FB4 802405B4 8E270000 */  lw        $a3, ($s1)
/* B06FB8 802405B8 96080000 */  lhu       $t0, ($s0)
/* B06FBC 802405BC 00E0282D */  daddu     $a1, $a3, $zero
/* B06FC0 802405C0 ACA20000 */  sw        $v0, ($a1)
/* B06FC4 802405C4 3102FFFF */  andi      $v0, $t0, 0xffff
/* B06FC8 802405C8 00021180 */  sll       $v0, $v0, 6
/* B06FCC 802405CC 00561021 */  addu      $v0, $v0, $s6
/* B06FD0 802405D0 8E830000 */  lw        $v1, ($s4)
/* B06FD4 802405D4 24E70008 */  addiu     $a3, $a3, 8
/* B06FD8 802405D8 00621821 */  addu      $v1, $v1, $v0
/* B06FDC 802405DC 3C028000 */  lui       $v0, 0x8000
/* B06FE0 802405E0 00621821 */  addu      $v1, $v1, $v0
/* B06FE4 802405E4 ACA30004 */  sw        $v1, 4($a1)
/* B06FE8 802405E8 8E450008 */  lw        $a1, 8($s2)
/* B06FEC 802405EC 8E46000C */  lw        $a2, 0xc($s2)
/* B06FF0 802405F0 25080001 */  addiu     $t0, $t0, 1
/* B06FF4 802405F4 AE270000 */  sw        $a3, ($s1)
/* B06FF8 802405F8 0C0B7811 */  jal       spr_get_player_raster_info
/* B06FFC 802405FC A6080000 */   sh       $t0, ($s0)
/* B07000 80240600 8FA30030 */  lw        $v1, 0x30($sp)
/* B07004 80240604 8FA40034 */  lw        $a0, 0x34($sp)
/* B07008 80240608 97A2003A */  lhu       $v0, 0x3a($sp)
/* B0700C 8024060C 3C013F00 */  lui       $at, 0x3f00
/* B07010 80240610 44811000 */  mtc1      $at, $f2
/* B07014 80240614 27A50018 */  addiu     $a1, $sp, 0x18
/* B07018 80240618 A7A20020 */  sh        $v0, 0x20($sp)
/* B0701C 8024061C 3042FFFF */  andi      $v0, $v0, 0xffff
/* B07020 80240620 44820000 */  mtc1      $v0, $f0
/* B07024 80240624 00000000 */  nop
/* B07028 80240628 46800020 */  cvt.s.w   $f0, $f0
/* B0702C 8024062C AFA30018 */  sw        $v1, 0x18($sp)
/* B07030 80240630 AFA4001C */  sw        $a0, 0x1c($sp)
/* B07034 80240634 E6400034 */  swc1      $f0, 0x34($s2)
/* B07038 80240638 97A2003E */  lhu       $v0, 0x3e($sp)
/* B0703C 8024063C 0000302D */  daddu     $a2, $zero, $zero
/* B07040 80240640 A7A20022 */  sh        $v0, 0x22($sp)
/* B07044 80240644 3042FFFF */  andi      $v0, $v0, 0xffff
/* B07048 80240648 44820000 */  mtc1      $v0, $f0
/* B0704C 8024064C 00000000 */  nop
/* B07050 80240650 46800020 */  cvt.s.w   $f0, $f0
/* B07054 80240654 E6400038 */  swc1      $f0, 0x38($s2)
/* B07058 80240658 C7A00038 */  lwc1      $f0, 0x38($sp)
/* B0705C 8024065C 46800020 */  cvt.s.w   $f0, $f0
/* B07060 80240660 46020002 */  mul.s     $f0, $f0, $f2
/* B07064 80240664 00000000 */  nop
/* B07068 80240668 97A3003E */  lhu       $v1, 0x3e($sp)
/* B0706C 8024066C 240200FF */  addiu     $v0, $zero, 0xff
/* B07070 80240670 A3A20028 */  sb        $v0, 0x28($sp)
/* B07074 80240674 A7A30026 */  sh        $v1, 0x26($sp)
/* B07078 80240678 4600010D */  trunc.w.s $f4, $f0
/* B0707C 8024067C 44022000 */  mfc1      $v0, $f4
/* B07080 80240680 00000000 */  nop
/* B07084 80240684 00021023 */  negu      $v0, $v0
/* B07088 80240688 A7A20024 */  sh        $v0, 0x24($sp)
/* B0708C 8024068C 8E440000 */  lw        $a0, ($s2)
/* B07090 80240690 0C04EBDC */  jal       func_8013AF70
/* B07094 80240694 0260382D */   daddu    $a3, $s3, $zero
/* B07098 80240698 3C04D838 */  lui       $a0, 0xd838
/* B0709C 8024069C 8E220000 */  lw        $v0, ($s1)
/* B070A0 802406A0 34840002 */  ori       $a0, $a0, 2
/* B070A4 802406A4 0040182D */  daddu     $v1, $v0, $zero
/* B070A8 802406A8 24420008 */  addiu     $v0, $v0, 8
/* B070AC 802406AC AE220000 */  sw        $v0, ($s1)
/* B070B0 802406B0 24020040 */  addiu     $v0, $zero, 0x40
/* B070B4 802406B4 AC640000 */  sw        $a0, ($v1)
/* B070B8 802406B8 AC620004 */  sw        $v0, 4($v1)
/* B070BC 802406BC 8FBF00DC */  lw        $ra, 0xdc($sp)
/* B070C0 802406C0 8FB600D8 */  lw        $s6, 0xd8($sp)
/* B070C4 802406C4 8FB500D4 */  lw        $s5, 0xd4($sp)
/* B070C8 802406C8 8FB400D0 */  lw        $s4, 0xd0($sp)
/* B070CC 802406CC 8FB300CC */  lw        $s3, 0xcc($sp)
/* B070D0 802406D0 8FB200C8 */  lw        $s2, 0xc8($sp)
/* B070D4 802406D4 8FB100C4 */  lw        $s1, 0xc4($sp)
/* B070D8 802406D8 8FB000C0 */  lw        $s0, 0xc0($sp)
/* B070DC 802406DC D7B600E8 */  ldc1      $f22, 0xe8($sp)
/* B070E0 802406E0 D7B400E0 */  ldc1      $f20, 0xe0($sp)
/* B070E4 802406E4 03E00008 */  jr        $ra
/* B070E8 802406E8 27BD00F0 */   addiu    $sp, $sp, 0xf0
