.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E006A580
/* 36D5A0 E006A580 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 36D5A4 E006A584 AFB40020 */  sw        $s4, 0x20($sp)
/* 36D5A8 E006A588 0080A02D */  daddu     $s4, $a0, $zero
/* 36D5AC E006A58C AFBF0024 */  sw        $ra, 0x24($sp)
/* 36D5B0 E006A590 AFB3001C */  sw        $s3, 0x1c($sp)
/* 36D5B4 E006A594 AFB20018 */  sw        $s2, 0x18($sp)
/* 36D5B8 E006A598 AFB10014 */  sw        $s1, 0x14($sp)
/* 36D5BC E006A59C AFB00010 */  sw        $s0, 0x10($sp)
/* 36D5C0 E006A5A0 8E91000C */  lw        $s1, 0xc($s4)
/* 36D5C4 E006A5A4 8E230028 */  lw        $v1, 0x28($s1)
/* 36D5C8 E006A5A8 8E240000 */  lw        $a0, ($s1)
/* 36D5CC E006A5AC 2862000B */  slti      $v0, $v1, 0xb
/* 36D5D0 E006A5B0 10400002 */  beqz      $v0, .LE006A5BC
/* 36D5D4 E006A5B4 2462FFFF */   addiu    $v0, $v1, -1
/* 36D5D8 E006A5B8 AE220028 */  sw        $v0, 0x28($s1)
.LE006A5BC:
/* 36D5DC E006A5BC 8E22002C */  lw        $v0, 0x2c($s1)
/* 36D5E0 E006A5C0 24420001 */  addiu     $v0, $v0, 1
/* 36D5E4 E006A5C4 AE22002C */  sw        $v0, 0x2c($s1)
/* 36D5E8 E006A5C8 8E830000 */  lw        $v1, ($s4)
/* 36D5EC E006A5CC 30620010 */  andi      $v0, $v1, 0x10
/* 36D5F0 E006A5D0 10400005 */  beqz      $v0, .LE006A5E8
/* 36D5F4 E006A5D4 2402FFEF */   addiu    $v0, $zero, -0x11
/* 36D5F8 E006A5D8 00621024 */  and       $v0, $v1, $v0
/* 36D5FC E006A5DC AE820000 */  sw        $v0, ($s4)
/* 36D600 E006A5E0 2402000A */  addiu     $v0, $zero, 0xa
/* 36D604 E006A5E4 AE220028 */  sw        $v0, 0x28($s1)
.LE006A5E8:
/* 36D608 E006A5E8 8E220028 */  lw        $v0, 0x28($s1)
/* 36D60C E006A5EC 04410005 */  bgez      $v0, .LE006A604
/* 36D610 E006A5F0 0040982D */   daddu    $s3, $v0, $zero
/* 36D614 E006A5F4 0C080128 */  jal       func_E02004A0
/* 36D618 E006A5F8 0280202D */   daddu    $a0, $s4, $zero
/* 36D61C E006A5FC 0801A9FD */  j         .LE006A7F4
/* 36D620 E006A600 00000000 */   nop      
.LE006A604:
/* 36D624 E006A604 8E23002C */  lw        $v1, 0x2c($s1)
/* 36D628 E006A608 28820002 */  slti      $v0, $a0, 2
/* 36D62C E006A60C 10400030 */  beqz      $v0, .LE006A6D0
/* 36D630 E006A610 00000000 */   nop      
/* 36D634 E006A614 0480002E */  bltz      $a0, .LE006A6D0
/* 36D638 E006A618 24120001 */   addiu    $s2, $zero, 1
/* 36D63C E006A61C 8E820008 */  lw        $v0, 8($s4)
/* 36D640 E006A620 0242102A */  slt       $v0, $s2, $v0
/* 36D644 E006A624 10400073 */  beqz      $v0, .LE006A7F4
/* 36D648 E006A628 26310094 */   addiu    $s1, $s1, 0x94
/* 36D64C E006A62C 00031080 */  sll       $v0, $v1, 2
/* 36D650 E006A630 00431021 */  addu      $v0, $v0, $v1
/* 36D654 E006A634 02429804 */  sllv      $s3, $v0, $s2
/* 36D658 E006A638 26300028 */  addiu     $s0, $s1, 0x28
.LE006A63C:
/* 36D65C E006A63C 8E020000 */  lw        $v0, ($s0)
/* 36D660 E006A640 8E030004 */  lw        $v1, 4($s0)
/* 36D664 E006A644 2442FFFF */  addiu     $v0, $v0, -1
/* 36D668 E006A648 24630001 */  addiu     $v1, $v1, 1
/* 36D66C E006A64C AE020000 */  sw        $v0, ($s0)
/* 36D670 E006A650 2862000A */  slti      $v0, $v1, 0xa
/* 36D674 E006A654 10400005 */  beqz      $v0, .LE006A66C
/* 36D678 E006A658 AE030004 */   sw       $v1, 4($s0)
/* 36D67C E006A65C 00031040 */  sll       $v0, $v1, 1
/* 36D680 E006A660 00431021 */  addu      $v0, $v0, $v1
/* 36D684 E006A664 00021080 */  sll       $v0, $v0, 2
/* 36D688 E006A668 AE02FFFC */  sw        $v0, -4($s0)
.LE006A66C:
/* 36D68C E006A66C 8E030000 */  lw        $v1, ($s0)
/* 36D690 E006A670 28620005 */  slti      $v0, $v1, 5
/* 36D694 E006A674 10400005 */  beqz      $v0, .LE006A68C
/* 36D698 E006A678 00031040 */   sll      $v0, $v1, 1
/* 36D69C E006A67C 00431021 */  addu      $v0, $v0, $v1
/* 36D6A0 E006A680 000210C0 */  sll       $v0, $v0, 3
/* 36D6A4 E006A684 00431021 */  addu      $v0, $v0, $v1
/* 36D6A8 E006A688 AE02FFFC */  sw        $v0, -4($s0)
.LE006A68C:
/* 36D6AC E006A68C C6000030 */  lwc1      $f0, 0x30($s0)
/* 36D6B0 E006A690 C6020064 */  lwc1      $f2, 0x64($s0)
/* 36D6B4 E006A694 46020000 */  add.s     $f0, $f0, $f2
/* 36D6B8 E006A698 8E020000 */  lw        $v0, ($s0)
/* 36D6BC E006A69C 1C400004 */  bgtz      $v0, .LE006A6B0
/* 36D6C0 E006A6A0 E6000030 */   swc1     $f0, 0x30($s0)
/* 36D6C4 E006A6A4 0220202D */  daddu     $a0, $s1, $zero
/* 36D6C8 E006A6A8 0C01A800 */  jal       func_E006A000
/* 36D6CC E006A6AC 26650001 */   addiu    $a1, $s3, 1
.LE006A6B0:
/* 36D6D0 E006A6B0 26520001 */  addiu     $s2, $s2, 1
/* 36D6D4 E006A6B4 26100094 */  addiu     $s0, $s0, 0x94
/* 36D6D8 E006A6B8 8E820008 */  lw        $v0, 8($s4)
/* 36D6DC E006A6BC 0242102A */  slt       $v0, $s2, $v0
/* 36D6E0 E006A6C0 1440FFDE */  bnez      $v0, .LE006A63C
/* 36D6E4 E006A6C4 26310094 */   addiu    $s1, $s1, 0x94
/* 36D6E8 E006A6C8 0801A9FD */  j         .LE006A7F4
/* 36D6EC E006A6CC 00000000 */   nop      
.LE006A6D0:
/* 36D6F0 E006A6D0 8E820008 */  lw        $v0, 8($s4)
/* 36D6F4 E006A6D4 24120001 */  addiu     $s2, $zero, 1
/* 36D6F8 E006A6D8 0242102A */  slt       $v0, $s2, $v0
/* 36D6FC E006A6DC 10400045 */  beqz      $v0, .LE006A7F4
/* 36D700 E006A6E0 26310094 */   addiu    $s1, $s1, 0x94
/* 36D704 E006A6E4 26300064 */  addiu     $s0, $s1, 0x64
.LE006A6E8:
/* 36D708 E006A6E8 0C01A919 */  jal       func_E006A464
/* 36D70C E006A6EC 0220202D */   daddu    $a0, $s1, $zero
/* 36D710 E006A6F0 8E02FFC4 */  lw        $v0, -0x3c($s0)
/* 36D714 E006A6F4 8E03FFC8 */  lw        $v1, -0x38($s0)
/* 36D718 E006A6F8 2442FFFF */  addiu     $v0, $v0, -1
/* 36D71C E006A6FC 24630001 */  addiu     $v1, $v1, 1
/* 36D720 E006A700 AE02FFC4 */  sw        $v0, -0x3c($s0)
/* 36D724 E006A704 28620005 */  slti      $v0, $v1, 5
/* 36D728 E006A708 10400007 */  beqz      $v0, .LE006A728
/* 36D72C E006A70C AE03FFC8 */   sw       $v1, -0x38($s0)
/* 36D730 E006A710 00031040 */  sll       $v0, $v1, 1
/* 36D734 E006A714 00431021 */  addu      $v0, $v0, $v1
/* 36D738 E006A718 000210C0 */  sll       $v0, $v0, 3
/* 36D73C E006A71C 00431021 */  addu      $v0, $v0, $v1
/* 36D740 E006A720 00021040 */  sll       $v0, $v0, 1
/* 36D744 E006A724 AE02FFC0 */  sw        $v0, -0x40($s0)
.LE006A728:
/* 36D748 E006A728 8E03FFC4 */  lw        $v1, -0x3c($s0)
/* 36D74C E006A72C 28620005 */  slti      $v0, $v1, 5
/* 36D750 E006A730 10400006 */  beqz      $v0, .LE006A74C
/* 36D754 E006A734 00031040 */   sll      $v0, $v1, 1
/* 36D758 E006A738 00431021 */  addu      $v0, $v0, $v1
/* 36D75C E006A73C 000210C0 */  sll       $v0, $v0, 3
/* 36D760 E006A740 00431021 */  addu      $v0, $v0, $v1
/* 36D764 E006A744 00021040 */  sll       $v0, $v0, 1
/* 36D768 E006A748 AE02FFC0 */  sw        $v0, -0x40($s0)
.LE006A74C:
/* 36D76C E006A74C 2A62000A */  slti      $v0, $s3, 0xa
/* 36D770 E006A750 1040000C */  beqz      $v0, .LE006A784
/* 36D774 E006A754 3C026666 */   lui      $v0, 0x6666
/* 36D778 E006A758 8E03FFC0 */  lw        $v1, -0x40($s0)
/* 36D77C E006A75C 00730018 */  mult      $v1, $s3
/* 36D780 E006A760 00001812 */  mflo      $v1
/* 36D784 E006A764 34426667 */  ori       $v0, $v0, 0x6667
/* 36D788 E006A768 00000000 */  nop       
/* 36D78C E006A76C 00620018 */  mult      $v1, $v0
/* 36D790 E006A770 00031FC3 */  sra       $v1, $v1, 0x1f
/* 36D794 E006A774 00001010 */  mfhi      $v0
/* 36D798 E006A778 00021083 */  sra       $v0, $v0, 2
/* 36D79C E006A77C 00431023 */  subu      $v0, $v0, $v1
/* 36D7A0 E006A780 AE02FFC0 */  sw        $v0, -0x40($s0)
.LE006A784:
/* 36D7A4 E006A784 8E02FFC4 */  lw        $v0, -0x3c($s0)
/* 36D7A8 E006A788 1C400003 */  bgtz      $v0, .LE006A798
/* 36D7AC E006A78C 0220202D */   daddu    $a0, $s1, $zero
/* 36D7B0 E006A790 0C01A82F */  jal       func_E006A0BC
/* 36D7B4 E006A794 0240282D */   daddu    $a1, $s2, $zero
.LE006A798:
/* 36D7B8 E006A798 8E02002C */  lw        $v0, 0x2c($s0)
/* 36D7BC E006A79C 18400003 */  blez      $v0, .LE006A7AC
/* 36D7C0 E006A7A0 2442FFFF */   addiu    $v0, $v0, -1
/* 36D7C4 E006A7A4 1C40000D */  bgtz      $v0, .LE006A7DC
/* 36D7C8 E006A7A8 AE02002C */   sw       $v0, 0x2c($s0)
.LE006A7AC:
/* 36D7CC E006A7AC C606FFF8 */  lwc1      $f6, -8($s0)
/* 36D7D0 E006A7B0 C600001C */  lwc1      $f0, 0x1c($s0)
/* 36D7D4 E006A7B4 C604FFFC */  lwc1      $f4, -4($s0)
/* 36D7D8 E006A7B8 46003180 */  add.s     $f6, $f6, $f0
/* 36D7DC E006A7BC C6000020 */  lwc1      $f0, 0x20($s0)
/* 36D7E0 E006A7C0 C6020000 */  lwc1      $f2, ($s0)
/* 36D7E4 E006A7C4 46002100 */  add.s     $f4, $f4, $f0
/* 36D7E8 E006A7C8 C6000024 */  lwc1      $f0, 0x24($s0)
/* 36D7EC E006A7CC 46001080 */  add.s     $f2, $f2, $f0
/* 36D7F0 E006A7D0 E606FFF8 */  swc1      $f6, -8($s0)
/* 36D7F4 E006A7D4 E604FFFC */  swc1      $f4, -4($s0)
/* 36D7F8 E006A7D8 E6020000 */  swc1      $f2, ($s0)
.LE006A7DC:
/* 36D7FC E006A7DC 26520001 */  addiu     $s2, $s2, 1
/* 36D800 E006A7E0 26100094 */  addiu     $s0, $s0, 0x94
/* 36D804 E006A7E4 8E820008 */  lw        $v0, 8($s4)
/* 36D808 E006A7E8 0242102A */  slt       $v0, $s2, $v0
/* 36D80C E006A7EC 1440FFBE */  bnez      $v0, .LE006A6E8
/* 36D810 E006A7F0 26310094 */   addiu    $s1, $s1, 0x94
.LE006A7F4:
/* 36D814 E006A7F4 8FBF0024 */  lw        $ra, 0x24($sp)
/* 36D818 E006A7F8 8FB40020 */  lw        $s4, 0x20($sp)
/* 36D81C E006A7FC 8FB3001C */  lw        $s3, 0x1c($sp)
/* 36D820 E006A800 8FB20018 */  lw        $s2, 0x18($sp)
/* 36D824 E006A804 8FB10014 */  lw        $s1, 0x14($sp)
/* 36D828 E006A808 8FB00010 */  lw        $s0, 0x10($sp)
/* 36D82C E006A80C 03E00008 */  jr        $ra
/* 36D830 E006A810 27BD0028 */   addiu    $sp, $sp, 0x28
