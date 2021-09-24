.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_47_main
/* 3625C0 E005E000 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* 3625C4 E005E004 F7B40040 */  sdc1      $f20, 0x40($sp)
/* 3625C8 E005E008 4485A000 */  mtc1      $a1, $f20
/* 3625CC E005E00C F7B60048 */  sdc1      $f22, 0x48($sp)
/* 3625D0 E005E010 4486B000 */  mtc1      $a2, $f22
/* 3625D4 E005E014 AFB30034 */  sw        $s3, 0x34($sp)
/* 3625D8 E005E018 0080982D */  daddu     $s3, $a0, $zero
/* 3625DC E005E01C F7B80050 */  sdc1      $f24, 0x50($sp)
/* 3625E0 E005E020 4487C000 */  mtc1      $a3, $f24
/* 3625E4 E005E024 27A40010 */  addiu     $a0, $sp, 0x10
/* 3625E8 E005E028 AFB1002C */  sw        $s1, 0x2c($sp)
/* 3625EC E005E02C 8FB1006C */  lw        $s1, 0x6c($sp)
/* 3625F0 E005E030 3C02E006 */  lui       $v0, %hi(func_E005E1B0)
/* 3625F4 E005E034 2442E1B0 */  addiu     $v0, $v0, %lo(func_E005E1B0)
/* 3625F8 E005E038 AFA20018 */  sw        $v0, 0x18($sp)
/* 3625FC E005E03C 3C02E006 */  lui       $v0, %hi(func_E005E1B8)
/* 362600 E005E040 2442E1B8 */  addiu     $v0, $v0, %lo(func_E005E1B8)
/* 362604 E005E044 AFA2001C */  sw        $v0, 0x1c($sp)
/* 362608 E005E048 3C02E006 */  lui       $v0, %hi(func_E005E310)
/* 36260C E005E04C 2442E310 */  addiu     $v0, $v0, %lo(func_E005E310)
/* 362610 E005E050 AFA20020 */  sw        $v0, 0x20($sp)
/* 362614 E005E054 3C02E006 */  lui       $v0, %hi(func_E005E318)
/* 362618 E005E058 2442E318 */  addiu     $v0, $v0, %lo(func_E005E318)
/* 36261C E005E05C AFA20024 */  sw        $v0, 0x24($sp)
/* 362620 E005E060 2402002F */  addiu     $v0, $zero, 0x2f
/* 362624 E005E064 AFBF0038 */  sw        $ra, 0x38($sp)
/* 362628 E005E068 AFB20030 */  sw        $s2, 0x30($sp)
/* 36262C E005E06C AFB00028 */  sw        $s0, 0x28($sp)
/* 362630 E005E070 AFA00010 */  sw        $zero, 0x10($sp)
/* 362634 E005E074 AFA20014 */  sw        $v0, 0x14($sp)
/* 362638 E005E078 0C080124 */  jal       shim_create_effect_instance
/* 36263C E005E07C 26310001 */   addiu    $s1, $s1, 1
/* 362640 E005E080 00112040 */  sll       $a0, $s1, 1
/* 362644 E005E084 00912021 */  addu      $a0, $a0, $s1
/* 362648 E005E088 00042080 */  sll       $a0, $a0, 2
/* 36264C E005E08C 00912023 */  subu      $a0, $a0, $s1
/* 362650 E005E090 00042080 */  sll       $a0, $a0, 2
/* 362654 E005E094 0040902D */  daddu     $s2, $v0, $zero
/* 362658 E005E098 0C08012C */  jal       shim_general_heap_malloc
/* 36265C E005E09C AE510008 */   sw       $s1, 8($s2)
/* 362660 E005E0A0 0040802D */  daddu     $s0, $v0, $zero
/* 362664 E005E0A4 16000003 */  bnez      $s0, .LE005E0B4
/* 362668 E005E0A8 AE50000C */   sw       $s0, 0xc($s2)
.LE005E0AC:
/* 36266C E005E0AC 0801782B */  j         .LE005E0AC
/* 362670 E005E0B0 00000000 */   nop
.LE005E0B4:
/* 362674 E005E0B4 0200202D */  daddu     $a0, $s0, $zero
/* 362678 E005E0B8 00112840 */  sll       $a1, $s1, 1
/* 36267C E005E0BC 00B12821 */  addu      $a1, $a1, $s1
/* 362680 E005E0C0 00052880 */  sll       $a1, $a1, 2
/* 362684 E005E0C4 00B12823 */  subu      $a1, $a1, $s1
/* 362688 E005E0C8 0C080130 */  jal       shim_mem_clear
/* 36268C E005E0CC 00052880 */   sll      $a1, $a1, 2
/* 362690 E005E0D0 24020001 */  addiu     $v0, $zero, 1
/* 362694 E005E0D4 AE130000 */  sw        $s3, ($s0)
/* 362698 E005E0D8 E6140004 */  swc1      $f20, 4($s0)
/* 36269C E005E0DC E6160008 */  swc1      $f22, 8($s0)
/* 3626A0 E005E0E0 E618000C */  swc1      $f24, 0xc($s0)
/* 3626A4 E005E0E4 AE000010 */  sw        $zero, 0x10($s0)
/* 3626A8 E005E0E8 AE000024 */  sw        $zero, 0x24($s0)
/* 3626AC E005E0EC C7A00068 */  lwc1      $f0, 0x68($sp)
/* 3626B0 E005E0F0 0040302D */  daddu     $a2, $v0, $zero
/* 3626B4 E005E0F4 AE020028 */  sw        $v0, 0x28($s0)
/* 3626B8 E005E0F8 00D1102A */  slt       $v0, $a2, $s1
/* 3626BC E005E0FC E6000014 */  swc1      $f0, 0x14($s0)
/* 3626C0 E005E100 1040001F */  beqz      $v0, .LE005E180
/* 3626C4 E005E104 2610002C */   addiu    $s0, $s0, 0x2c
/* 3626C8 E005E108 2627FFFF */  addiu     $a3, $s1, -1
/* 3626CC E005E10C 3C0141A0 */  lui       $at, 0x41a0
/* 3626D0 E005E110 44811000 */  mtc1      $at, $f2
/* 3626D4 E005E114 26040024 */  addiu     $a0, $s0, 0x24
/* 3626D8 E005E118 0000282D */  daddu     $a1, $zero, $zero
.LE005E11C:
/* 3626DC E005E11C 14E00002 */  bnez      $a3, .LE005E128
/* 3626E0 E005E120 00A7001A */   div      $zero, $a1, $a3
/* 3626E4 E005E124 0007000D */  break     7
.LE005E128:
/* 3626E8 E005E128 2401FFFF */   addiu    $at, $zero, -1
/* 3626EC E005E12C 14E10004 */  bne       $a3, $at, .LE005E140
/* 3626F0 E005E130 3C018000 */   lui      $at, 0x8000
/* 3626F4 E005E134 14A10002 */  bne       $a1, $at, .LE005E140
/* 3626F8 E005E138 00000000 */   nop
/* 3626FC E005E13C 0006000D */  break     6
.LE005E140:
/* 362700 E005E140 00001812 */   mflo     $v1
/* 362704 E005E144 24A50168 */  addiu     $a1, $a1, 0x168
/* 362708 E005E148 24C60001 */  addiu     $a2, $a2, 1
/* 36270C E005E14C 00D1102A */  slt       $v0, $a2, $s1
/* 362710 E005E150 AC80FFE0 */  sw        $zero, -0x20($a0)
/* 362714 E005E154 AC80FFE4 */  sw        $zero, -0x1c($a0)
/* 362718 E005E158 AC80FFE8 */  sw        $zero, -0x18($a0)
/* 36271C E005E15C E482FFF8 */  swc1      $f2, -8($a0)
/* 362720 E005E160 AC80FFFC */  sw        $zero, -4($a0)
/* 362724 E005E164 44830000 */  mtc1      $v1, $f0
/* 362728 E005E168 00000000 */  nop
/* 36272C E005E16C 46800020 */  cvt.s.w   $f0, $f0
/* 362730 E005E170 E480FFF4 */  swc1      $f0, -0xc($a0)
/* 362734 E005E174 AC830000 */  sw        $v1, ($a0)
/* 362738 E005E178 1440FFE8 */  bnez      $v0, .LE005E11C
/* 36273C E005E17C 2484002C */   addiu    $a0, $a0, 0x2c
.LE005E180:
/* 362740 E005E180 8FA20070 */  lw        $v0, 0x70($sp)
/* 362744 E005E184 AC520000 */  sw        $s2, ($v0)
/* 362748 E005E188 8FBF0038 */  lw        $ra, 0x38($sp)
/* 36274C E005E18C 8FB30034 */  lw        $s3, 0x34($sp)
/* 362750 E005E190 8FB20030 */  lw        $s2, 0x30($sp)
/* 362754 E005E194 8FB1002C */  lw        $s1, 0x2c($sp)
/* 362758 E005E198 8FB00028 */  lw        $s0, 0x28($sp)
/* 36275C E005E19C D7B80050 */  ldc1      $f24, 0x50($sp)
/* 362760 E005E1A0 D7B60048 */  ldc1      $f22, 0x48($sp)
/* 362764 E005E1A4 D7B40040 */  ldc1      $f20, 0x40($sp)
/* 362768 E005E1A8 03E00008 */  jr        $ra
/* 36276C E005E1AC 27BD0058 */   addiu    $sp, $sp, 0x58
