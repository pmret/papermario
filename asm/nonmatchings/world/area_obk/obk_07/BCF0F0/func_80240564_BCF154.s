.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240564_BCF154
/* BCF154 80240564 27BDFF98 */  addiu     $sp, $sp, -0x68
/* BCF158 80240568 AFBE0060 */  sw        $fp, 0x60($sp)
/* BCF15C 8024056C 00C0F02D */  daddu     $fp, $a2, $zero
/* BCF160 80240570 AFBF0064 */  sw        $ra, 0x64($sp)
/* BCF164 80240574 AFB7005C */  sw        $s7, 0x5c($sp)
/* BCF168 80240578 AFB60058 */  sw        $s6, 0x58($sp)
/* BCF16C 8024057C AFB50054 */  sw        $s5, 0x54($sp)
/* BCF170 80240580 AFB40050 */  sw        $s4, 0x50($sp)
/* BCF174 80240584 AFB3004C */  sw        $s3, 0x4c($sp)
/* BCF178 80240588 AFB20048 */  sw        $s2, 0x48($sp)
/* BCF17C 8024058C AFB10044 */  sw        $s1, 0x44($sp)
/* BCF180 80240590 AFB00040 */  sw        $s0, 0x40($sp)
/* BCF184 80240594 AFA40068 */  sw        $a0, 0x68($sp)
/* BCF188 80240598 0C090150 */  jal       func_80240540_BCF130
/* BCF18C 8024059C AFA5006C */   sw       $a1, 0x6c($sp)
/* BCF190 802405A0 8FAB0068 */  lw        $t3, 0x68($sp)
/* BCF194 802405A4 0040A82D */  daddu     $s5, $v0, $zero
/* BCF198 802405A8 256BFFE4 */  addiu     $t3, $t3, -0x1c
/* BCF19C 802405AC AFAB0068 */  sw        $t3, 0x68($sp)
/* BCF1A0 802405B0 8FAB006C */  lw        $t3, 0x6c($sp)
/* BCF1A4 802405B4 8EA30028 */  lw        $v1, 0x28($s5)
/* BCF1A8 802405B8 256BFFFC */  addiu     $t3, $t3, -4
/* BCF1AC 802405BC 00031080 */  sll       $v0, $v1, 2
/* BCF1B0 802405C0 02A21021 */  addu      $v0, $s5, $v0
/* BCF1B4 802405C4 AFAB006C */  sw        $t3, 0x6c($sp)
/* BCF1B8 802405C8 8C420010 */  lw        $v0, 0x10($v0)
/* BCF1BC 802405CC 07C10002 */  bgez      $fp, .L802405D8
/* BCF1C0 802405D0 AFA20020 */   sw       $v0, 0x20($sp)
/* BCF1C4 802405D4 0000F02D */  daddu     $fp, $zero, $zero
.L802405D8:
/* BCF1C8 802405D8 0000802D */  daddu     $s0, $zero, $zero
/* BCF1CC 802405DC 18600021 */  blez      $v1, .L80240664
/* BCF1D0 802405E0 0200902D */   daddu    $s2, $s0, $zero
/* BCF1D4 802405E4 0060302D */  daddu     $a2, $v1, $zero
/* BCF1D8 802405E8 26440001 */  addiu     $a0, $s2, 1
.L802405EC:
/* BCF1DC 802405EC 00041080 */  sll       $v0, $a0, 2
/* BCF1E0 802405F0 02A21021 */  addu      $v0, $s5, $v0
/* BCF1E4 802405F4 8C450010 */  lw        $a1, 0x10($v0)
/* BCF1E8 802405F8 03C5102A */  slt       $v0, $fp, $a1
/* BCF1EC 802405FC 54400001 */  bnel      $v0, $zero, .L80240604
/* BCF1F0 80240600 03C0282D */   daddu    $a1, $fp, $zero
.L80240604:
/* BCF1F4 80240604 00051900 */  sll       $v1, $a1, 4
/* BCF1F8 80240608 00651823 */  subu      $v1, $v1, $a1
/* BCF1FC 8024060C 8FAB0020 */  lw        $t3, 0x20($sp)
/* BCF200 80240610 00031880 */  sll       $v1, $v1, 2
/* BCF204 80240614 15600002 */  bnez      $t3, .L80240620
/* BCF208 80240618 006B001A */   div      $zero, $v1, $t3
/* BCF20C 8024061C 0007000D */  break     7
.L80240620:
/* BCF210 80240620 2401FFFF */   addiu    $at, $zero, -1
/* BCF214 80240624 15610004 */  bne       $t3, $at, .L80240638
/* BCF218 80240628 3C018000 */   lui      $at, 0x8000
/* BCF21C 8024062C 14610002 */  bne       $v1, $at, .L80240638
/* BCF220 80240630 00000000 */   nop      
/* BCF224 80240634 0006000D */  break     6
.L80240638:
/* BCF228 80240638 00001812 */   mflo     $v1
/* BCF22C 8024063C 00031040 */  sll       $v0, $v1, 1
/* BCF230 80240640 00431021 */  addu      $v0, $v0, $v1
/* BCF234 80240644 000210C0 */  sll       $v0, $v0, 3
/* BCF238 80240648 00431021 */  addu      $v0, $v0, $v1
/* BCF23C 8024064C 13C50005 */  beq       $fp, $a1, .L80240664
/* BCF240 80240650 00028080 */   sll      $s0, $v0, 2
/* BCF244 80240654 0080902D */  daddu     $s2, $a0, $zero
/* BCF248 80240658 0246102A */  slt       $v0, $s2, $a2
/* BCF24C 8024065C 1440FFE3 */  bnez      $v0, .L802405EC
/* BCF250 80240660 26440001 */   addiu    $a0, $s2, 1
.L80240664:
/* BCF254 80240664 8EA40008 */  lw        $a0, 8($s5)
/* BCF258 80240668 8EA30000 */  lw        $v1, ($s5)
/* BCF25C 8024066C 02041023 */  subu      $v0, $s0, $a0
/* BCF260 80240670 14600002 */  bnez      $v1, .L8024067C
/* BCF264 80240674 0043001A */   div      $zero, $v0, $v1
/* BCF268 80240678 0007000D */  break     7
.L8024067C:
/* BCF26C 8024067C 2401FFFF */   addiu    $at, $zero, -1
/* BCF270 80240680 14610004 */  bne       $v1, $at, .L80240694
/* BCF274 80240684 3C018000 */   lui      $at, 0x8000
/* BCF278 80240688 14410002 */  bne       $v0, $at, .L80240694
/* BCF27C 8024068C 00000000 */   nop      
/* BCF280 80240690 0006000D */  break     6
.L80240694:
/* BCF284 80240694 00001012 */   mflo     $v0
/* BCF288 80240698 0000A02D */  daddu     $s4, $zero, $zero
/* BCF28C 8024069C 0280902D */  daddu     $s2, $s4, $zero
/* BCF290 802406A0 8EA30028 */  lw        $v1, 0x28($s5)
/* BCF294 802406A4 00822021 */  addu      $a0, $a0, $v0
/* BCF298 802406A8 18600055 */  blez      $v1, .L80240800
/* BCF29C 802406AC AEA40008 */   sw       $a0, 8($s5)
/* BCF2A0 802406B0 8FAB006C */  lw        $t3, 0x6c($sp)
/* BCF2A4 802406B4 000B1400 */  sll       $v0, $t3, 0x10
/* BCF2A8 802406B8 00021403 */  sra       $v0, $v0, 0x10
/* BCF2AC 802406BC AFA20028 */  sw        $v0, 0x28($sp)
/* BCF2B0 802406C0 25620005 */  addiu     $v0, $t3, 5
/* BCF2B4 802406C4 00021400 */  sll       $v0, $v0, 0x10
/* BCF2B8 802406C8 00021403 */  sra       $v0, $v0, 0x10
/* BCF2BC 802406CC AFA2002C */  sw        $v0, 0x2c($sp)
.L802406D0:
/* BCF2C0 802406D0 264B0001 */  addiu     $t3, $s2, 1
/* BCF2C4 802406D4 000B1080 */  sll       $v0, $t3, 2
/* BCF2C8 802406D8 02A21021 */  addu      $v0, $s5, $v0
/* BCF2CC 802406DC AFAB0024 */  sw        $t3, 0x24($sp)
/* BCF2D0 802406E0 8C450010 */  lw        $a1, 0x10($v0)
/* BCF2D4 802406E4 8FAB0020 */  lw        $t3, 0x20($sp)
/* BCF2D8 802406E8 00051900 */  sll       $v1, $a1, 4
/* BCF2DC 802406EC 00651823 */  subu      $v1, $v1, $a1
/* BCF2E0 802406F0 00031880 */  sll       $v1, $v1, 2
/* BCF2E4 802406F4 15600002 */  bnez      $t3, .L80240700
/* BCF2E8 802406F8 006B001A */   div      $zero, $v1, $t3
/* BCF2EC 802406FC 0007000D */  break     7
.L80240700:
/* BCF2F0 80240700 2401FFFF */   addiu    $at, $zero, -1
/* BCF2F4 80240704 15610004 */  bne       $t3, $at, .L80240718
/* BCF2F8 80240708 3C018000 */   lui      $at, 0x8000
/* BCF2FC 8024070C 14610002 */  bne       $v1, $at, .L80240718
/* BCF300 80240710 00000000 */   nop      
/* BCF304 80240714 0006000D */  break     6
.L80240718:
/* BCF308 80240718 00001812 */   mflo     $v1
/* BCF30C 8024071C 8FA7002C */  lw        $a3, 0x2c($sp)
/* BCF310 80240720 00121040 */  sll       $v0, $s2, 1
/* BCF314 80240724 00529821 */  addu      $s3, $v0, $s2
/* BCF318 80240728 26770001 */  addiu     $s7, $s3, 1
/* BCF31C 8024072C 26760002 */  addiu     $s6, $s3, 2
/* BCF320 80240730 8FAB0068 */  lw        $t3, 0x68($sp)
/* BCF324 80240734 8FA50028 */  lw        $a1, 0x28($sp)
/* BCF328 80240738 01743021 */  addu      $a2, $t3, $s4
/* BCF32C 8024073C 00062400 */  sll       $a0, $a2, 0x10
/* BCF330 80240740 00042403 */  sra       $a0, $a0, 0x10
/* BCF334 80240744 3C0B8024 */  lui       $t3, %hi(D_802430A0)
/* BCF338 80240748 256B30A0 */  addiu     $t3, $t3, %lo(D_802430A0)
/* BCF33C 8024074C 02EB1021 */  addu      $v0, $s7, $t3
/* BCF340 80240750 904A0000 */  lbu       $t2, ($v0)
/* BCF344 80240754 02CB1021 */  addu      $v0, $s6, $t3
/* BCF348 80240758 90490000 */  lbu       $t1, ($v0)
/* BCF34C 8024075C 026B1021 */  addu      $v0, $s3, $t3
/* BCF350 80240760 90420000 */  lbu       $v0, ($v0)
/* BCF354 80240764 240B00FF */  addiu     $t3, $zero, 0xff
/* BCF358 80240768 AFAB001C */  sw        $t3, 0x1c($sp)
/* BCF35C 8024076C AFA20010 */  sw        $v0, 0x10($sp)
/* BCF360 80240770 AFAA0014 */  sw        $t2, 0x14($sp)
/* BCF364 80240774 AFA90018 */  sw        $t1, 0x18($sp)
/* BCF368 80240778 00748023 */  subu      $s0, $v1, $s4
/* BCF36C 8024077C 00D03021 */  addu      $a2, $a2, $s0
/* BCF370 80240780 00063400 */  sll       $a2, $a2, 0x10
/* BCF374 80240784 00068C03 */  sra       $s1, $a2, 0x10
/* BCF378 80240788 0C00AAB1 */  jal       func_8002AAC4
/* BCF37C 8024078C 0220302D */   daddu    $a2, $s1, $zero
/* BCF380 80240790 8EA20028 */  lw        $v0, 0x28($s5)
/* BCF384 80240794 2442FFFF */  addiu     $v0, $v0, -1
/* BCF388 80240798 0242102A */  slt       $v0, $s2, $v0
/* BCF38C 8024079C 10400017 */  beqz      $v0, .L802407FC
/* BCF390 802407A0 0220202D */   daddu    $a0, $s1, $zero
/* BCF394 802407A4 0080302D */  daddu     $a2, $a0, $zero
/* BCF398 802407A8 3C0B8024 */  lui       $t3, %hi(D_802430C0)
/* BCF39C 802407AC 256B30C0 */  addiu     $t3, $t3, %lo(D_802430C0)
/* BCF3A0 802407B0 02EB1021 */  addu      $v0, $s7, $t3
/* BCF3A4 802407B4 904A0000 */  lbu       $t2, ($v0)
/* BCF3A8 802407B8 02CB1021 */  addu      $v0, $s6, $t3
/* BCF3AC 802407BC 90490000 */  lbu       $t1, ($v0)
/* BCF3B0 802407C0 026B1021 */  addu      $v0, $s3, $t3
/* BCF3B4 802407C4 8FA50028 */  lw        $a1, 0x28($sp)
/* BCF3B8 802407C8 8FA7002C */  lw        $a3, 0x2c($sp)
/* BCF3BC 802407CC 90420000 */  lbu       $v0, ($v0)
/* BCF3C0 802407D0 240B00FF */  addiu     $t3, $zero, 0xff
/* BCF3C4 802407D4 AFAB001C */  sw        $t3, 0x1c($sp)
/* BCF3C8 802407D8 AFA20010 */  sw        $v0, 0x10($sp)
/* BCF3CC 802407DC AFAA0014 */  sw        $t2, 0x14($sp)
/* BCF3D0 802407E0 0C00AAB1 */  jal       func_8002AAC4
/* BCF3D4 802407E4 AFA90018 */   sw       $t1, 0x18($sp)
/* BCF3D8 802407E8 8EA20028 */  lw        $v0, 0x28($s5)
/* BCF3DC 802407EC 8FB20024 */  lw        $s2, 0x24($sp)
/* BCF3E0 802407F0 0242102A */  slt       $v0, $s2, $v0
/* BCF3E4 802407F4 1440FFB6 */  bnez      $v0, .L802406D0
/* BCF3E8 802407F8 0290A021 */   addu     $s4, $s4, $s0
.L802407FC:
/* BCF3EC 802407FC 0000A02D */  daddu     $s4, $zero, $zero
.L80240800:
/* BCF3F0 80240800 8EA20028 */  lw        $v0, 0x28($s5)
/* BCF3F4 80240804 18400076 */  blez      $v0, .L802409E0
/* BCF3F8 80240808 0280902D */   daddu    $s2, $s4, $zero
/* BCF3FC 8024080C 24160002 */  addiu     $s6, $zero, 2
/* BCF400 80240810 24130001 */  addiu     $s3, $zero, 1
/* BCF404 80240814 8FAB006C */  lw        $t3, 0x6c($sp)
/* BCF408 80240818 3C178024 */  lui       $s7, %hi(D_802430B0)
/* BCF40C 8024081C 26F730B0 */  addiu     $s7, $s7, %lo(D_802430B0)
/* BCF410 80240820 000B1400 */  sll       $v0, $t3, 0x10
/* BCF414 80240824 00021403 */  sra       $v0, $v0, 0x10
/* BCF418 80240828 AFA20030 */  sw        $v0, 0x30($sp)
/* BCF41C 8024082C 25620005 */  addiu     $v0, $t3, 5
/* BCF420 80240830 00021400 */  sll       $v0, $v0, 0x10
/* BCF424 80240834 00021403 */  sra       $v0, $v0, 0x10
/* BCF428 80240838 3C0B8024 */  lui       $t3, %hi(D_802430C0)
/* BCF42C 8024083C 256B30C0 */  addiu     $t3, $t3, %lo(D_802430C0)
/* BCF430 80240840 AFAB0038 */  sw        $t3, 0x38($sp)
/* BCF434 80240844 240B0004 */  addiu     $t3, $zero, 4
/* BCF438 80240848 AFA20034 */  sw        $v0, 0x34($sp)
/* BCF43C 8024084C AFAB003C */  sw        $t3, 0x3c($sp)
.L80240850:
/* BCF440 80240850 3C0B8024 */  lui       $t3, %hi(D_802430B0)
/* BCF444 80240854 256B30B0 */  addiu     $t3, $t3, %lo(D_802430B0)
/* BCF448 80240858 026B1021 */  addu      $v0, $s3, $t3
/* BCF44C 8024085C 904A0000 */  lbu       $t2, ($v0)
/* BCF450 80240860 8FAB003C */  lw        $t3, 0x3c($sp)
/* BCF454 80240864 92E80000 */  lbu       $t0, ($s7)
/* BCF458 80240868 02AB1021 */  addu      $v0, $s5, $t3
/* BCF45C 8024086C 3C0B8024 */  lui       $t3, %hi(D_802430B0)
/* BCF460 80240870 256B30B0 */  addiu     $t3, $t3, %lo(D_802430B0)
/* BCF464 80240874 8C450010 */  lw        $a1, 0x10($v0)
/* BCF468 80240878 02CB1021 */  addu      $v0, $s6, $t3
/* BCF46C 8024087C 90490000 */  lbu       $t1, ($v0)
/* BCF470 80240880 03C5102A */  slt       $v0, $fp, $a1
/* BCF474 80240884 54400001 */  bnel      $v0, $zero, .L8024088C
/* BCF478 80240888 03C0282D */   daddu    $a1, $fp, $zero
.L8024088C:
/* BCF47C 8024088C 00051900 */  sll       $v1, $a1, 4
/* BCF480 80240890 00651823 */  subu      $v1, $v1, $a1
/* BCF484 80240894 8FAB0020 */  lw        $t3, 0x20($sp)
/* BCF488 80240898 00031880 */  sll       $v1, $v1, 2
/* BCF48C 8024089C 15600002 */  bnez      $t3, .L802408A8
/* BCF490 802408A0 006B001A */   div      $zero, $v1, $t3
/* BCF494 802408A4 0007000D */  break     7
.L802408A8:
/* BCF498 802408A8 2401FFFF */   addiu    $at, $zero, -1
/* BCF49C 802408AC 15610004 */  bne       $t3, $at, .L802408C0
/* BCF4A0 802408B0 3C018000 */   lui      $at, 0x8000
/* BCF4A4 802408B4 14610002 */  bne       $v1, $at, .L802408C0
/* BCF4A8 802408B8 00000000 */   nop      
/* BCF4AC 802408BC 0006000D */  break     6
.L802408C0:
/* BCF4B0 802408C0 00001812 */   mflo     $v1
/* BCF4B4 802408C4 8EA40008 */  lw        $a0, 8($s5)
/* BCF4B8 802408C8 3C0251EB */  lui       $v0, 0x51eb
/* BCF4BC 802408CC 3442851F */  ori       $v0, $v0, 0x851f
/* BCF4C0 802408D0 00820018 */  mult      $a0, $v0
/* BCF4C4 802408D4 000427C3 */  sra       $a0, $a0, 0x1f
/* BCF4C8 802408D8 00006010 */  mfhi      $t4
/* BCF4CC 802408DC 000C1143 */  sra       $v0, $t4, 5
/* BCF4D0 802408E0 00441023 */  subu      $v0, $v0, $a0
/* BCF4D4 802408E4 00548023 */  subu      $s0, $v0, $s4
/* BCF4D8 802408E8 0600003D */  bltz      $s0, .L802409E0
/* BCF4DC 802408EC 00748823 */   subu     $s1, $v1, $s4
/* BCF4E0 802408F0 52200007 */  beql      $s1, $zero, .L80240910
/* BCF4E4 802408F4 0200882D */   daddu    $s1, $s0, $zero
/* BCF4E8 802408F8 14BE0003 */  bne       $a1, $fp, .L80240908
/* BCF4EC 802408FC 0230102A */   slt      $v0, $s1, $s0
/* BCF4F0 80240900 08090244 */  j         .L80240910
/* BCF4F4 80240904 0200882D */   daddu    $s1, $s0, $zero
.L80240908:
/* BCF4F8 80240908 54400001 */  bnel      $v0, $zero, .L80240910
/* BCF4FC 8024090C 0220802D */   daddu    $s0, $s1, $zero
.L80240910:
/* BCF500 80240910 8FAB0068 */  lw        $t3, 0x68($sp)
/* BCF504 80240914 8FA50030 */  lw        $a1, 0x30($sp)
/* BCF508 80240918 8FA70034 */  lw        $a3, 0x34($sp)
/* BCF50C 8024091C AFA80010 */  sw        $t0, 0x10($sp)
/* BCF510 80240920 AFAA0014 */  sw        $t2, 0x14($sp)
/* BCF514 80240924 AFA90018 */  sw        $t1, 0x18($sp)
/* BCF518 80240928 01741021 */  addu      $v0, $t3, $s4
/* BCF51C 8024092C 00022400 */  sll       $a0, $v0, 0x10
/* BCF520 80240930 00042403 */  sra       $a0, $a0, 0x10
/* BCF524 80240934 00501021 */  addu      $v0, $v0, $s0
/* BCF528 80240938 00021400 */  sll       $v0, $v0, 0x10
/* BCF52C 8024093C 00028403 */  sra       $s0, $v0, 0x10
/* BCF530 80240940 0200302D */  daddu     $a2, $s0, $zero
/* BCF534 80240944 240B00FF */  addiu     $t3, $zero, 0xff
/* BCF538 80240948 0C00AAB1 */  jal       func_8002AAC4
/* BCF53C 8024094C AFAB001C */   sw       $t3, 0x1c($sp)
/* BCF540 80240950 8EA20028 */  lw        $v0, 0x28($s5)
/* BCF544 80240954 2442FFFF */  addiu     $v0, $v0, -1
/* BCF548 80240958 0242102A */  slt       $v0, $s2, $v0
/* BCF54C 8024095C 10400020 */  beqz      $v0, .L802409E0
/* BCF550 80240960 0200202D */   daddu    $a0, $s0, $zero
/* BCF554 80240964 0080302D */  daddu     $a2, $a0, $zero
/* BCF558 80240968 0291A021 */  addu      $s4, $s4, $s1
/* BCF55C 8024096C 3C0B8024 */  lui       $t3, %hi(D_802430C0)
/* BCF560 80240970 256B30C0 */  addiu     $t3, $t3, %lo(D_802430C0)
/* BCF564 80240974 02CB4021 */  addu      $t0, $s6, $t3
/* BCF568 80240978 26D60003 */  addiu     $s6, $s6, 3
/* BCF56C 8024097C 026B1021 */  addu      $v0, $s3, $t3
/* BCF570 80240980 26730003 */  addiu     $s3, $s3, 3
/* BCF574 80240984 26F70003 */  addiu     $s7, $s7, 3
/* BCF578 80240988 8FAB0038 */  lw        $t3, 0x38($sp)
/* BCF57C 8024098C 8FA50030 */  lw        $a1, 0x30($sp)
/* BCF580 80240990 91630000 */  lbu       $v1, ($t3)
/* BCF584 80240994 256B0003 */  addiu     $t3, $t3, 3
/* BCF588 80240998 AFAB0038 */  sw        $t3, 0x38($sp)
/* BCF58C 8024099C 8FAB003C */  lw        $t3, 0x3c($sp)
/* BCF590 802409A0 8FA70034 */  lw        $a3, 0x34($sp)
/* BCF594 802409A4 256B0004 */  addiu     $t3, $t3, 4
/* BCF598 802409A8 AFAB003C */  sw        $t3, 0x3c($sp)
/* BCF59C 802409AC 904A0000 */  lbu       $t2, ($v0)
/* BCF5A0 802409B0 91090000 */  lbu       $t1, ($t0)
/* BCF5A4 802409B4 240B00FF */  addiu     $t3, $zero, 0xff
/* BCF5A8 802409B8 AFAB001C */  sw        $t3, 0x1c($sp)
/* BCF5AC 802409BC AFA30010 */  sw        $v1, 0x10($sp)
/* BCF5B0 802409C0 AFAA0014 */  sw        $t2, 0x14($sp)
/* BCF5B4 802409C4 0C00AAB1 */  jal       func_8002AAC4
/* BCF5B8 802409C8 AFA90018 */   sw       $t1, 0x18($sp)
/* BCF5BC 802409CC 8EA20028 */  lw        $v0, 0x28($s5)
/* BCF5C0 802409D0 26520001 */  addiu     $s2, $s2, 1
/* BCF5C4 802409D4 0242102A */  slt       $v0, $s2, $v0
/* BCF5C8 802409D8 1440FF9D */  bnez      $v0, .L80240850
/* BCF5CC 802409DC 00000000 */   nop      
.L802409E0:
/* BCF5D0 802409E0 8FBF0064 */  lw        $ra, 0x64($sp)
/* BCF5D4 802409E4 8FBE0060 */  lw        $fp, 0x60($sp)
/* BCF5D8 802409E8 8FB7005C */  lw        $s7, 0x5c($sp)
/* BCF5DC 802409EC 8FB60058 */  lw        $s6, 0x58($sp)
/* BCF5E0 802409F0 8FB50054 */  lw        $s5, 0x54($sp)
/* BCF5E4 802409F4 8FB40050 */  lw        $s4, 0x50($sp)
/* BCF5E8 802409F8 8FB3004C */  lw        $s3, 0x4c($sp)
/* BCF5EC 802409FC 8FB20048 */  lw        $s2, 0x48($sp)
/* BCF5F0 80240A00 8FB10044 */  lw        $s1, 0x44($sp)
/* BCF5F4 80240A04 8FB00040 */  lw        $s0, 0x40($sp)
/* BCF5F8 80240A08 03E00008 */  jr        $ra
/* BCF5FC 80240A0C 27BD0068 */   addiu    $sp, $sp, 0x68
