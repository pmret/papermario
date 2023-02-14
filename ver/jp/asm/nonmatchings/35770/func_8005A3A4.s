.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005A3A4
/* 357A4 8005A3A4 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 357A8 8005A3A8 AFB00038 */  sw        $s0, 0x38($sp)
/* 357AC 8005A3AC 00C0802D */  daddu     $s0, $a2, $zero
/* 357B0 8005A3B0 AFB1003C */  sw        $s1, 0x3c($sp)
/* 357B4 8005A3B4 0080882D */  daddu     $s1, $a0, $zero
/* 357B8 8005A3B8 AFB30044 */  sw        $s3, 0x44($sp)
/* 357BC 8005A3BC 00A0982D */  daddu     $s3, $a1, $zero
/* 357C0 8005A3C0 AFB40048 */  sw        $s4, 0x48($sp)
/* 357C4 8005A3C4 0000A02D */  daddu     $s4, $zero, $zero
/* 357C8 8005A3C8 AFBF004C */  sw        $ra, 0x4c($sp)
/* 357CC 8005A3CC 0C053A3A */  jal       func_8014E8E8
/* 357D0 8005A3D0 AFB20040 */   sw       $s2, 0x40($sp)
/* 357D4 8005A3D4 3C05800A */  lui       $a1, %hi(D_8009A630)
/* 357D8 8005A3D8 24A5A630 */  addiu     $a1, $a1, %lo(D_8009A630)
/* 357DC 8005A3DC 2402FFBF */  addiu     $v0, $zero, -0x41
/* 357E0 8005A3E0 3C128007 */  lui       $s2, %hi(gGameStatusPtr)
/* 357E4 8005A3E4 2652417C */  addiu     $s2, $s2, %lo(gGameStatusPtr)
/* 357E8 8005A3E8 8CA30000 */  lw        $v1, ($a1)
/* 357EC 8005A3EC 8E440000 */  lw        $a0, ($s2)
/* 357F0 8005A3F0 00621824 */  and       $v1, $v1, $v0
/* 357F4 8005A3F4 2402FF7F */  addiu     $v0, $zero, -0x81
/* 357F8 8005A3F8 00621824 */  and       $v1, $v1, $v0
/* 357FC 8005A3FC ACA30000 */  sw        $v1, ($a1)
/* 35800 8005A400 0C00B280 */  jal       load_obfuscation_shims
/* 35804 8005A404 A0800084 */   sb       $zero, 0x84($a0)
/* 35808 8005A408 0C0AC81E */  jal       func_802B2078
/* 3580C 8005A40C 00108400 */   sll      $s0, $s0, 0x10
/* 35810 8005A410 0C00A3E8 */  jal       func_80028FA0
/* 35814 8005A414 00108403 */   sra      $s0, $s0, 0x10
/* 35818 8005A418 0C048AA8 */  jal       func_80122AA0
/* 3581C 8005A41C 00000000 */   nop
/* 35820 8005A420 0C04A0B2 */  jal       func_801282C8
/* 35824 8005A424 00000000 */   nop
/* 35828 8005A428 0C0B0C77 */  jal       func_802C31DC
/* 3582C 8005A42C 00000000 */   nop
/* 35830 8005A430 12000005 */  beqz      $s0, .L8005A448
/* 35834 8005A434 24020001 */   addiu    $v0, $zero, 1
/* 35838 8005A438 12020008 */  beq       $s0, $v0, .L8005A45C
/* 3583C 8005A43C 00000000 */   nop
/* 35840 8005A440 0801691E */  j         .L8005A478
/* 35844 8005A444 00000000 */   nop
.L8005A448:
/* 35848 8005A448 0C052910 */  jal       func_8014A440
/* 3584C 8005A44C 00000000 */   nop
/* 35850 8005A450 8E420000 */  lw        $v0, ($s2)
/* 35854 8005A454 0801691E */  j         .L8005A478
/* 35858 8005A458 A0400167 */   sb       $zero, 0x167($v0)
.L8005A45C:
/* 3585C 8005A45C 0C00AD14 */  jal       func_8002B450
/* 35860 8005A460 00000000 */   nop
/* 35864 8005A464 8E420000 */  lw        $v0, ($s2)
/* 35868 8005A468 94510086 */  lhu       $s1, 0x86($v0)
/* 3586C 8005A46C 9453008C */  lhu       $s3, 0x8c($v0)
/* 35870 8005A470 A0500167 */  sb        $s0, 0x167($v0)
/* 35874 8005A474 A4510088 */  sh        $s1, 0x88($v0)
.L8005A478:
/* 35878 8005A478 3C04800E */  lui       $a0, %hi(D_800D9210)
/* 3587C 8005A47C 24849210 */  addiu     $a0, $a0, %lo(D_800D9210)
/* 35880 8005A480 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 35884 8005A484 8C42417C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 35888 8005A488 00131C00 */  sll       $v1, $s3, 0x10
/* 3588C 8005A48C AC400144 */  sw        $zero, 0x144($v0)
/* 35890 8005A490 00111400 */  sll       $v0, $s1, 0x10
/* 35894 8005A494 00021303 */  sra       $v0, $v0, 0xc
/* 35898 8005A498 3C018009 */  lui       $at, %hi(D_800934C4)
/* 3589C 8005A49C 00220821 */  addu      $at, $at, $v0
/* 358A0 8005A4A0 8C2234C4 */  lw        $v0, %lo(D_800934C4)($at)
/* 358A4 8005A4A4 00031AC3 */  sra       $v1, $v1, 0xb
/* 358A8 8005A4A8 00439021 */  addu      $s2, $v0, $v1
/* 358AC 8005A4AC 8E460000 */  lw        $a2, ($s2)
/* 358B0 8005A4B0 3C05800A */  lui       $a1, %hi(D_800989F0)
/* 358B4 8005A4B4 0C019530 */  jal       func_800654C0
/* 358B8 8005A4B8 24A589F0 */   addiu    $a1, $a1, %lo(D_800989F0)
/* 358BC 8005A4BC 3C04800E */  lui       $a0, %hi(D_800D91C0)
/* 358C0 8005A4C0 248491C0 */  addiu     $a0, $a0, %lo(D_800D91C0)
/* 358C4 8005A4C4 8E460000 */  lw        $a2, ($s2)
/* 358C8 8005A4C8 3C05800A */  lui       $a1, %hi(D_800989FC)
/* 358CC 8005A4CC 0C019530 */  jal       func_800654C0
/* 358D0 8005A4D0 24A589FC */   addiu    $a1, $a1, %lo(D_800989FC)
/* 358D4 8005A4D4 8E450000 */  lw        $a1, ($s2)
/* 358D8 8005A4D8 0C01BB48 */  jal       func_8006ED20
/* 358DC 8005A4DC 27A40018 */   addiu    $a0, $sp, 0x18
/* 358E0 8005A4E0 3C04800B */  lui       $a0, %hi(D_800B0CD0)
/* 358E4 8005A4E4 24840CD0 */  addiu     $a0, $a0, %lo(D_800B0CD0)
/* 358E8 8005A4E8 3C05800A */  lui       $a1, %hi(D_80098A04)
/* 358EC 8005A4EC 24A58A04 */  addiu     $a1, $a1, %lo(D_80098A04)
/* 358F0 8005A4F0 27A60018 */  addiu     $a2, $sp, 0x18
/* 358F4 8005A4F4 0C019530 */  jal       func_800654C0
/* 358F8 8005A4F8 A3A0001B */   sb       $zero, 0x1b($sp)
/* 358FC 8005A4FC 8E450014 */  lw        $a1, 0x14($s2)
/* 35900 8005A500 3C01800A */  lui       $at, %hi(D_800A1FF0)
/* 35904 8005A504 AC321FF0 */  sw        $s2, %lo(D_800A1FF0)($at)
/* 35908 8005A508 10A00005 */  beqz      $a1, .L8005A520
/* 3590C 8005A50C 00000000 */   nop
/* 35910 8005A510 3C04800E */  lui       $a0, %hi(D_800D9648)
/* 35914 8005A514 24849648 */  addiu     $a0, $a0, %lo(D_800D9648)
/* 35918 8005A518 0C01BB48 */  jal       func_8006ED20
/* 3591C 8005A51C 00000000 */   nop
.L8005A520:
/* 35920 8005A520 0C0168DC */  jal       func_8005A370
/* 35924 8005A524 00000000 */   nop
/* 35928 8005A528 8E440008 */  lw        $a0, 8($s2)
/* 3592C 8005A52C 10800004 */  beqz      $a0, .L8005A540
/* 35930 8005A530 00000000 */   nop
/* 35934 8005A534 8E45000C */  lw        $a1, 0xc($s2)
/* 35938 8005A538 0C00A5BF */  jal       func_800296FC
/* 3593C 8005A53C 8E460010 */   lw       $a2, 0x10($s2)
.L8005A540:
/* 35940 8005A540 8E420004 */  lw        $v0, 4($s2)
/* 35944 8005A544 3C03800A */  lui       $v1, %hi(D_800A1FF8)
/* 35948 8005A548 24631FF8 */  addiu     $v1, $v1, %lo(D_800A1FF8)
/* 3594C 8005A54C 24440040 */  addiu     $a0, $v0, 0x40
.L8005A550:
/* 35950 8005A550 8C480000 */  lw        $t0, ($v0)
/* 35954 8005A554 8C490004 */  lw        $t1, 4($v0)
/* 35958 8005A558 8C4A0008 */  lw        $t2, 8($v0)
/* 3595C 8005A55C 8C4B000C */  lw        $t3, 0xc($v0)
/* 35960 8005A560 AC680000 */  sw        $t0, ($v1)
/* 35964 8005A564 AC690004 */  sw        $t1, 4($v1)
/* 35968 8005A568 AC6A0008 */  sw        $t2, 8($v1)
/* 3596C 8005A56C AC6B000C */  sw        $t3, 0xc($v1)
/* 35970 8005A570 24420010 */  addiu     $v0, $v0, 0x10
/* 35974 8005A574 1444FFF6 */  bne       $v0, $a0, .L8005A550
/* 35978 8005A578 24630010 */   addiu    $v1, $v1, 0x10
/* 3597C 8005A57C 8E420018 */  lw        $v0, 0x18($s2)
/* 35980 8005A580 3C13800A */  lui       $s3, %hi(D_800A1FF8)
/* 35984 8005A584 26731FF8 */  addiu     $s3, $s3, %lo(D_800A1FF8)
/* 35988 8005A588 10400004 */  beqz      $v0, .L8005A59C
/* 3598C 8005A58C 00000000 */   nop
/* 35990 8005A590 0040F809 */  jalr      $v0
/* 35994 8005A594 00000000 */   nop
/* 35998 8005A598 0040A02D */  daddu     $s4, $v0, $zero
.L8005A59C:
/* 3599C 8005A59C 16800015 */  bnez      $s4, .L8005A5F4
/* 359A0 8005A5A0 00000000 */   nop
/* 359A4 8005A5A4 3C04800E */  lui       $a0, %hi(D_800D9210)
/* 359A8 8005A5A8 24849210 */  addiu     $a0, $a0, %lo(D_800D9210)
/* 359AC 8005A5AC 0C016A68 */  jal       func_8005A9A0
/* 359B0 8005A5B0 27A50030 */   addiu    $a1, $sp, 0x30
/* 359B4 8005A5B4 0040882D */  daddu     $s1, $v0, $zero
/* 359B8 8005A5B8 0220202D */  daddu     $a0, $s1, $zero
/* 359BC 8005A5BC 3C108021 */  lui       $s0, %hi(D_80210000)
/* 359C0 8005A5C0 26100000 */  addiu     $s0, $s0, %lo(D_80210000)
/* 359C4 8005A5C4 0C01BB74 */  jal       func_8006EDD0
/* 359C8 8005A5C8 0200282D */   daddu    $a1, $s0, $zero
/* 359CC 8005A5CC 0C00AB0E */  jal       func_8002AC38
/* 359D0 8005A5D0 0220202D */   daddu    $a0, $s1, $zero
/* 359D4 8005A5D4 8E020000 */  lw        $v0, ($s0)
/* 359D8 8005A5D8 8E030008 */  lw        $v1, 8($s0)
/* 359DC 8005A5DC 8E04000C */  lw        $a0, 0xc($s0)
/* 359E0 8005A5E0 8E050010 */  lw        $a1, 0x10($s0)
/* 359E4 8005A5E4 AE620000 */  sw        $v0, ($s3)
/* 359E8 8005A5E8 AE630028 */  sw        $v1, 0x28($s3)
/* 359EC 8005A5EC AE64002C */  sw        $a0, 0x2c($s3)
/* 359F0 8005A5F0 AE650030 */  sw        $a1, 0x30($s3)
.L8005A5F4:
/* 359F4 8005A5F4 8E420014 */  lw        $v0, 0x14($s2)
/* 359F8 8005A5F8 10400005 */  beqz      $v0, .L8005A610
/* 359FC 8005A5FC 00000000 */   nop
/* 35A00 8005A600 3C04800E */  lui       $a0, %hi(D_800D9648)
/* 35A04 8005A604 24849648 */  addiu     $a0, $a0, %lo(D_800D9648)
/* 35A08 8005A608 0C052B88 */  jal       func_8014AE20
/* 35A0C 8005A60C 00000000 */   nop
.L8005A610:
/* 35A10 8005A610 0C00B280 */  jal       load_obfuscation_shims
/* 35A14 8005A614 00000000 */   nop
/* 35A18 8005A618 0C0AC81E */  jal       func_802B2078
/* 35A1C 8005A61C 00000000 */   nop
/* 35A20 8005A620 0C0539C8 */  jal       func_8014E720
/* 35A24 8005A624 0000202D */   daddu    $a0, $zero, $zero
/* 35A28 8005A628 0C04A0B2 */  jal       func_801282C8
/* 35A2C 8005A62C 00000000 */   nop
/* 35A30 8005A630 0C0B0C77 */  jal       func_802C31DC
/* 35A34 8005A634 00000000 */   nop
/* 35A38 8005A638 0C00B6E1 */  jal       func_8002DB84
/* 35A3C 8005A63C 00000000 */   nop
/* 35A40 8005A640 3C108007 */  lui       $s0, %hi(gGameStatusPtr)
/* 35A44 8005A644 2610417C */  addiu     $s0, $s0, %lo(gGameStatusPtr)
/* 35A48 8005A648 8E020000 */  lw        $v0, ($s0)
/* 35A4C 8005A64C 0C044512 */  jal       func_80111448
/* 35A50 8005A650 80440084 */   lb       $a0, 0x84($v0)
/* 35A54 8005A654 0C048D0D */  jal       func_80123434
/* 35A58 8005A658 00000000 */   nop
/* 35A5C 8005A65C 0C049770 */  jal       func_80125DC0
/* 35A60 8005A660 00000000 */   nop
/* 35A64 8005A664 0C00E05F */  jal       func_8003817C
/* 35A68 8005A668 00000000 */   nop
/* 35A6C 8005A66C 0C05186C */  jal       func_801461B0
/* 35A70 8005A670 00000000 */   nop
/* 35A74 8005A674 0C0529CC */  jal       func_8014A730
/* 35A78 8005A678 00000000 */   nop
/* 35A7C 8005A67C 0C046BD5 */  jal       func_8011AF54
/* 35A80 8005A680 00000000 */   nop
/* 35A84 8005A684 0C05343C */  jal       func_8014D0F0
/* 35A88 8005A688 00000000 */   nop
/* 35A8C 8005A68C 0C052BAA */  jal       func_8014AEA8
/* 35A90 8005A690 00000000 */   nop
/* 35A94 8005A694 8E020000 */  lw        $v0, ($s0)
/* 35A98 8005A698 804300A8 */  lb        $v1, 0xa8($v0)
/* 35A9C 8005A69C 2402FFFF */  addiu     $v0, $zero, -1
/* 35AA0 8005A6A0 14620003 */  bne       $v1, $v0, .L8005A6B0
/* 35AA4 8005A6A4 00000000 */   nop
/* 35AA8 8005A6A8 0C04F48E */  jal       func_8013D238
/* 35AAC 8005A6AC 00000000 */   nop
.L8005A6B0:
/* 35AB0 8005A6B0 16800005 */  bnez      $s4, .L8005A6C8
/* 35AB4 8005A6B4 00000000 */   nop
/* 35AB8 8005A6B8 0C016B11 */  jal       func_8005AC44
/* 35ABC 8005A6BC 00000000 */   nop
/* 35AC0 8005A6C0 0C016B1C */  jal       func_8005AC70
/* 35AC4 8005A6C4 00000000 */   nop
.L8005A6C8:
/* 35AC8 8005A6C8 0C01CAC4 */  jal       func_80072B10
/* 35ACC 8005A6CC 00000000 */   nop
/* 35AD0 8005A6D0 0C00F830 */  jal       func_8003E0C0
/* 35AD4 8005A6D4 00000000 */   nop
/* 35AD8 8005A6D8 0C0457B2 */  jal       func_80115EC8
/* 35ADC 8005A6DC 24040001 */   addiu    $a0, $zero, 1
/* 35AE0 8005A6E0 0C016653 */  jal       func_8005994C
/* 35AE4 8005A6E4 00000000 */   nop
/* 35AE8 8005A6E8 0C037F0C */  jal       func_800DFC30
/* 35AEC 8005A6EC 00000000 */   nop
/* 35AF0 8005A6F0 0C037F15 */  jal       func_800DFC54
/* 35AF4 8005A6F4 00000000 */   nop
/* 35AF8 8005A6F8 0C03AD02 */  jal       func_800EB408
/* 35AFC 8005A6FC 00000000 */   nop
/* 35B00 8005A700 0C04A221 */  jal       func_80128884
/* 35B04 8005A704 00000000 */   nop
/* 35B08 8005A708 0C04D85C */  jal       func_80136170
/* 35B0C 8005A70C 00000000 */   nop
/* 35B10 8005A710 3C028011 */  lui       $v0, %hi(D_8010F188)
/* 35B14 8005A714 2442F188 */  addiu     $v0, $v0, %lo(D_8010F188)
/* 35B18 8005A718 C4400084 */  lwc1      $f0, 0x84($v0)
/* 35B1C 8005A71C E4400080 */  swc1      $f0, 0x80($v0)
/* 35B20 8005A720 8E42001C */  lw        $v0, 0x1c($s2)
/* 35B24 8005A724 30420003 */  andi      $v0, $v0, 3
/* 35B28 8005A728 00021080 */  sll       $v0, $v0, 2
/* 35B2C 8005A72C 3C048009 */  lui       $a0, %hi(D_8008FF30)
/* 35B30 8005A730 00822021 */  addu      $a0, $a0, $v0
/* 35B34 8005A734 0C053A2B */  jal       func_8014E8AC
/* 35B38 8005A738 8C84FF30 */   lw       $a0, %lo(D_8008FF30)($a0)
/* 35B3C 8005A73C 0C0539AC */  jal       func_8014E6B0
/* 35B40 8005A740 00000000 */   nop
/* 35B44 8005A744 1680000B */  bnez      $s4, .L8005A774
/* 35B48 8005A748 00000000 */   nop
/* 35B4C 8005A74C 3C04800B */  lui       $a0, %hi(D_800B0CD0)
/* 35B50 8005A750 24840CD0 */  addiu     $a0, $a0, %lo(D_800B0CD0)
/* 35B54 8005A754 0C016AA2 */  jal       func_8005AA88
/* 35B58 8005A758 27A50030 */   addiu    $a1, $sp, 0x30
/* 35B5C 8005A75C 8E640000 */  lw        $a0, ($s3)
/* 35B60 8005A760 10800004 */  beqz      $a0, .L8005A774
/* 35B64 8005A764 00000000 */   nop
/* 35B68 8005A768 8FA60030 */  lw        $a2, 0x30($sp)
/* 35B6C 8005A76C 0C047FD6 */  jal       func_8011FF58
/* 35B70 8005A770 0040282D */   daddu    $a1, $v0, $zero
.L8005A774:
/* 35B74 8005A774 8E640038 */  lw        $a0, 0x38($s3)
/* 35B78 8005A778 50800005 */  beql      $a0, $zero, .L8005A790
/* 35B7C 8005A77C 24040128 */   addiu    $a0, $zero, 0x128
/* 35B80 8005A780 0C052BB6 */  jal       func_8014AED8
/* 35B84 8005A784 00000000 */   nop
/* 35B88 8005A788 080169E8 */  j         .L8005A7A0
/* 35B8C 8005A78C 00000000 */   nop
.L8005A790:
/* 35B90 8005A790 240500C8 */  addiu     $a1, $zero, 0xc8
/* 35B94 8005A794 2406000C */  addiu     $a2, $zero, 0xc
/* 35B98 8005A798 0C052BC8 */  jal       func_8014AF20
/* 35B9C 8005A79C 24070014 */   addiu    $a3, $zero, 0x14
.L8005A7A0:
/* 35BA0 8005A7A0 3C04800B */  lui       $a0, %hi(D_800B1D60)
/* 35BA4 8005A7A4 24841D60 */  addiu     $a0, $a0, %lo(D_800B1D60)
/* 35BA8 8005A7A8 94820000 */  lhu       $v0, ($a0)
/* 35BAC 8005A7AC 94830AB0 */  lhu       $v1, 0xab0($a0)
/* 35BB0 8005A7B0 3C018007 */  lui       $at, %hi(D_800773E0)
/* 35BB4 8005A7B4 AC2073E0 */  sw        $zero, %lo(D_800773E0)($at)
/* 35BB8 8005A7B8 34420002 */  ori       $v0, $v0, 2
/* 35BBC 8005A7BC A4820000 */  sh        $v0, ($a0)
/* 35BC0 8005A7C0 94820558 */  lhu       $v0, 0x558($a0)
/* 35BC4 8005A7C4 34630002 */  ori       $v1, $v1, 2
/* 35BC8 8005A7C8 A4830AB0 */  sh        $v1, 0xab0($a0)
/* 35BCC 8005A7CC 34420002 */  ori       $v0, $v0, 2
/* 35BD0 8005A7D0 A4820558 */  sh        $v0, 0x558($a0)
/* 35BD4 8005A7D4 94821008 */  lhu       $v0, 0x1008($a0)
/* 35BD8 8005A7D8 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* 35BDC 8005A7DC 8C63417C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* 35BE0 8005A7E0 34420002 */  ori       $v0, $v0, 2
/* 35BE4 8005A7E4 A4821008 */  sh        $v0, 0x1008($a0)
/* 35BE8 8005A7E8 806300A8 */  lb        $v1, 0xa8($v1)
/* 35BEC 8005A7EC 2402FFFF */  addiu     $v0, $zero, -1
/* 35BF0 8005A7F0 14620008 */  bne       $v1, $v0, .L8005A814
/* 35BF4 8005A7F4 240200A2 */   addiu    $v0, $zero, 0xa2
/* 35BF8 8005A7F8 240200C8 */  addiu     $v0, $zero, 0xc8
/* 35BFC 8005A7FC AFA20010 */  sw        $v0, 0x10($sp)
/* 35C00 8005A800 0000202D */  daddu     $a0, $zero, $zero
/* 35C04 8005A804 2405000C */  addiu     $a1, $zero, 0xc
/* 35C08 8005A808 24060014 */  addiu     $a2, $zero, 0x14
/* 35C0C 8005A80C 08016A0A */  j         .L8005A828
/* 35C10 8005A810 24070128 */   addiu    $a3, $zero, 0x128
.L8005A814:
/* 35C14 8005A814 AFA20010 */  sw        $v0, 0x10($sp)
/* 35C18 8005A818 0000202D */  daddu     $a0, $zero, $zero
/* 35C1C 8005A81C 2405001D */  addiu     $a1, $zero, 0x1d
/* 35C20 8005A820 2406001C */  addiu     $a2, $zero, 0x1c
/* 35C24 8005A824 24070106 */  addiu     $a3, $zero, 0x106
.L8005A828:
/* 35C28 8005A828 0C00B7E9 */  jal       func_8002DFA4
/* 35C2C 8005A82C 00000000 */   nop
/* 35C30 8005A830 0C039E35 */  jal       func_800E78D4
/* 35C34 8005A834 00000000 */   nop
/* 35C38 8005A838 0000282D */  daddu     $a1, $zero, $zero
/* 35C3C 8005A83C 00A0302D */  daddu     $a2, $a1, $zero
/* 35C40 8005A840 3C108007 */  lui       $s0, %hi(gGameStatusPtr)
/* 35C44 8005A844 2610417C */  addiu     $s0, $s0, %lo(gGameStatusPtr)
/* 35C48 8005A848 8E030000 */  lw        $v1, ($s0)
/* 35C4C 8005A84C 240203E8 */  addiu     $v0, $zero, 0x3e8
/* 35C50 8005A850 A4620090 */  sh        $v0, 0x90($v1)
/* 35C54 8005A854 A4620092 */  sh        $v0, 0x92($v1)
/* 35C58 8005A858 8E640010 */  lw        $a0, 0x10($s3)
/* 35C5C 8005A85C 0C0B0D74 */  jal       func_802C35D0
/* 35C60 8005A860 00A0382D */   daddu    $a3, $a1, $zero
/* 35C64 8005A864 8E030000 */  lw        $v1, ($s0)
/* 35C68 8005A868 8C420144 */  lw        $v0, 0x144($v0)
/* 35C6C 8005A86C AC62006C */  sw        $v0, 0x6c($v1)
/* 35C70 8005A870 8FBF004C */  lw        $ra, 0x4c($sp)
/* 35C74 8005A874 8FB40048 */  lw        $s4, 0x48($sp)
/* 35C78 8005A878 8FB30044 */  lw        $s3, 0x44($sp)
/* 35C7C 8005A87C 8FB20040 */  lw        $s2, 0x40($sp)
/* 35C80 8005A880 8FB1003C */  lw        $s1, 0x3c($sp)
/* 35C84 8005A884 8FB00038 */  lw        $s0, 0x38($sp)
/* 35C88 8005A888 03E00008 */  jr        $ra
/* 35C8C 8005A88C 27BD0050 */   addiu    $sp, $sp, 0x50
