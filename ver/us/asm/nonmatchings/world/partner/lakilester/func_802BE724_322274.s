.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BE724_322274
/* 322274 802BE724 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* 322278 802BE728 AFB40040 */  sw        $s4, 0x40($sp)
/* 32227C 802BE72C 0080A02D */  daddu     $s4, $a0, $zero
/* 322280 802BE730 3C03FFBF */  lui       $v1, 0xffbf
/* 322284 802BE734 3463FFFF */  ori       $v1, $v1, 0xffff
/* 322288 802BE738 AFB20038 */  sw        $s2, 0x38($sp)
/* 32228C 802BE73C 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* 322290 802BE740 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* 322294 802BE744 AFB50044 */  sw        $s5, 0x44($sp)
/* 322298 802BE748 3C158011 */  lui       $s5, %hi(D_8010EBB0)
/* 32229C 802BE74C 26B5EBB0 */  addiu     $s5, $s5, %lo(D_8010EBB0)
/* 3222A0 802BE750 AFBF0048 */  sw        $ra, 0x48($sp)
/* 3222A4 802BE754 AFB3003C */  sw        $s3, 0x3c($sp)
/* 3222A8 802BE758 AFB10034 */  sw        $s1, 0x34($sp)
/* 3222AC 802BE75C AFB00030 */  sw        $s0, 0x30($sp)
/* 3222B0 802BE760 F7B60058 */  sdc1      $f22, 0x58($sp)
/* 3222B4 802BE764 F7B40050 */  sdc1      $f20, 0x50($sp)
/* 3222B8 802BE768 8E420004 */  lw        $v0, 4($s2)
/* 3222BC 802BE76C 8E91014C */  lw        $s1, 0x14c($s4)
/* 3222C0 802BE770 00431024 */  and       $v0, $v0, $v1
/* 3222C4 802BE774 10A00087 */  beqz      $a1, .L802BE994
/* 3222C8 802BE778 AE420004 */   sw       $v0, 4($s2)
/* 3222CC 802BE77C 0C0AF59E */  jal       func_802BD678_3211C8
/* 3222D0 802BE780 0220202D */   daddu    $a0, $s1, $zero
/* 3222D4 802BE784 8E420004 */  lw        $v0, 4($s2)
/* 3222D8 802BE788 3C030010 */  lui       $v1, 0x10
/* 3222DC 802BE78C 00431024 */  and       $v0, $v0, $v1
/* 3222E0 802BE790 1440034C */  bnez      $v0, .L802BF4C4
/* 3222E4 802BE794 24020002 */   addiu    $v0, $zero, 2
/* 3222E8 802BE798 2403FFBF */  addiu     $v1, $zero, -0x41
/* 3222EC 802BE79C 8E220000 */  lw        $v0, ($s1)
/* 3222F0 802BE7A0 C6200038 */  lwc1      $f0, 0x38($s1)
/* 3222F4 802BE7A4 C622003C */  lwc1      $f2, 0x3c($s1)
/* 3222F8 802BE7A8 C6240040 */  lwc1      $f4, 0x40($s1)
/* 3222FC 802BE7AC 3C048007 */  lui       $a0, %hi(gGameStatusPtr)
/* 322300 802BE7B0 8C84419C */  lw        $a0, %lo(gGameStatusPtr)($a0)
/* 322304 802BE7B4 00431024 */  and       $v0, $v0, $v1
/* 322308 802BE7B8 AE220000 */  sw        $v0, ($s1)
/* 32230C 802BE7BC E6200060 */  swc1      $f0, 0x60($s1)
/* 322310 802BE7C0 E6220064 */  swc1      $f2, 0x64($s1)
/* 322314 802BE7C4 E6240068 */  swc1      $f4, 0x68($s1)
/* 322318 802BE7C8 8082007D */  lb        $v0, 0x7d($a0)
/* 32231C 802BE7CC 14400005 */  bnez      $v0, .L802BE7E4
/* 322320 802BE7D0 3C030020 */   lui      $v1, 0x20
/* 322324 802BE7D4 8E420004 */  lw        $v0, 4($s2)
/* 322328 802BE7D8 00431024 */  and       $v0, $v0, $v1
/* 32232C 802BE7DC 1040000A */  beqz      $v0, .L802BE808
/* 322330 802BE7E0 24020028 */   addiu    $v0, $zero, 0x28
.L802BE7E4:
/* 322334 802BE7E4 8E430004 */  lw        $v1, 4($s2)
/* 322338 802BE7E8 3C020020 */  lui       $v0, 0x20
/* 32233C 802BE7EC 00621024 */  and       $v0, $v1, $v0
/* 322340 802BE7F0 10400004 */  beqz      $v0, .L802BE804
/* 322344 802BE7F4 3C02FFDF */   lui      $v0, 0xffdf
/* 322348 802BE7F8 3442FFFF */  ori       $v0, $v0, 0xffff
/* 32234C 802BE7FC 00621024 */  and       $v0, $v1, $v0
/* 322350 802BE800 AE420004 */  sw        $v0, 4($s2)
.L802BE804:
/* 322354 802BE804 24020064 */  addiu     $v0, $zero, 0x64
.L802BE808:
/* 322358 802BE808 3C01802C */  lui       $at, %hi(D_802BFF14)
/* 32235C 802BE80C AC22FF14 */  sw        $v0, %lo(D_802BFF14)($at)
/* 322360 802BE810 82A20001 */  lb        $v0, 1($s5)
/* 322364 802BE814 14400015 */  bnez      $v0, .L802BE86C
/* 322368 802BE818 24040021 */   addiu    $a0, $zero, 0x21
/* 32236C 802BE81C 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 322370 802BE820 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 322374 802BE824 8042007D */  lb        $v0, 0x7d($v0)
/* 322378 802BE828 1440005A */  bnez      $v0, .L802BE994
/* 32237C 802BE82C 24020021 */   addiu    $v0, $zero, 0x21
/* 322380 802BE830 824300B4 */  lb        $v1, 0xb4($s2)
/* 322384 802BE834 10620009 */  beq       $v1, $v0, .L802BE85C
/* 322388 802BE838 00000000 */   nop
/* 32238C 802BE83C 10600007 */  beqz      $v1, .L802BE85C
/* 322390 802BE840 24020001 */   addiu    $v0, $zero, 1
/* 322394 802BE844 10620005 */  beq       $v1, $v0, .L802BE85C
/* 322398 802BE848 24020002 */   addiu    $v0, $zero, 2
/* 32239C 802BE84C 10620003 */  beq       $v1, $v0, .L802BE85C
/* 3223A0 802BE850 24020008 */   addiu    $v0, $zero, 8
/* 3223A4 802BE854 1462031B */  bne       $v1, $v0, .L802BF4C4
/* 3223A8 802BE858 24020002 */   addiu    $v0, $zero, 2
.L802BE85C:
/* 3223AC 802BE85C 8E420000 */  lw        $v0, ($s2)
/* 3223B0 802BE860 34420100 */  ori       $v0, $v0, 0x100
/* 3223B4 802BE864 080AFA65 */  j         .L802BE994
/* 3223B8 802BE868 AE420000 */   sw       $v0, ($s2)
.L802BE86C:
/* 3223BC 802BE86C A2A00001 */  sb        $zero, 1($s5)
/* 3223C0 802BE870 8E420000 */  lw        $v0, ($s2)
/* 3223C4 802BE874 2403FEFF */  addiu     $v1, $zero, -0x101
/* 3223C8 802BE878 00431024 */  and       $v0, $v0, $v1
/* 3223CC 802BE87C AE420000 */  sw        $v0, ($s2)
/* 3223D0 802BE880 8E220000 */  lw        $v0, ($s1)
/* 3223D4 802BE884 2410FFB7 */  addiu     $s0, $zero, -0x49
/* 3223D8 802BE888 00501024 */  and       $v0, $v0, $s0
/* 3223DC 802BE88C 34420100 */  ori       $v0, $v0, 0x100
/* 3223E0 802BE890 0C039769 */  jal       set_action_state
/* 3223E4 802BE894 AE220000 */   sw       $v0, ($s1)
/* 3223E8 802BE898 3C040008 */  lui       $a0, 8
/* 3223EC 802BE89C 0C037FDE */  jal       func_800DFF78
/* 3223F0 802BE8A0 3484000E */   ori      $a0, $a0, 0xe
/* 3223F4 802BE8A4 3C050008 */  lui       $a1, 8
/* 3223F8 802BE8A8 34A50005 */  ori       $a1, $a1, 5
/* 3223FC 802BE8AC 3C030040 */  lui       $v1, 0x40
/* 322400 802BE8B0 34630100 */  ori       $v1, $v1, 0x100
/* 322404 802BE8B4 8E220000 */  lw        $v0, ($s1)
/* 322408 802BE8B8 3C014040 */  lui       $at, 0x4040
/* 32240C 802BE8BC 44812000 */  mtc1      $at, $f4
/* 322410 802BE8C0 00501024 */  and       $v0, $v0, $s0
/* 322414 802BE8C4 00431025 */  or        $v0, $v0, $v1
/* 322418 802BE8C8 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* 32241C 802BE8CC 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* 322420 802BE8D0 24130001 */  addiu     $s3, $zero, 1
/* 322424 802BE8D4 AE250028 */  sw        $a1, 0x28($s1)
/* 322428 802BE8D8 3C01802C */  lui       $at, %hi(D_802BFF0C)
/* 32242C 802BE8DC AC33FF0C */  sw        $s3, %lo(D_802BFF0C)($at)
/* 322430 802BE8E0 AE220000 */  sw        $v0, ($s1)
/* 322434 802BE8E4 24020008 */  addiu     $v0, $zero, 8
/* 322438 802BE8E8 A2A20003 */  sb        $v0, 3($s5)
/* 32243C 802BE8EC A2B30000 */  sb        $s3, ($s5)
/* 322440 802BE8F0 A060007D */  sb        $zero, 0x7d($v1)
/* 322444 802BE8F4 C6400028 */  lwc1      $f0, 0x28($s2)
/* 322448 802BE8F8 C6220064 */  lwc1      $f2, 0x64($s1)
/* 32244C 802BE8FC 3C040008 */  lui       $a0, 8
/* 322450 802BE900 E6200038 */  swc1      $f0, 0x38($s1)
/* 322454 802BE904 E622003C */  swc1      $f2, 0x3c($s1)
/* 322458 802BE908 46001006 */  mov.s     $f0, $f2
/* 32245C 802BE90C 3C014120 */  lui       $at, 0x4120
/* 322460 802BE910 44811000 */  mtc1      $at, $f2
/* 322464 802BE914 C6460030 */  lwc1      $f6, 0x30($s2)
/* 322468 802BE918 46020000 */  add.s     $f0, $f0, $f2
/* 32246C 802BE91C AE250028 */  sw        $a1, 0x28($s1)
/* 322470 802BE920 E6260040 */  swc1      $f6, 0x40($s1)
/* 322474 802BE924 E640002C */  swc1      $f0, 0x2c($s2)
/* 322478 802BE928 E6240018 */  swc1      $f4, 0x18($s1)
/* 32247C 802BE92C AE200014 */  sw        $zero, 0x14($s1)
/* 322480 802BE930 C6400080 */  lwc1      $f0, 0x80($s2)
/* 322484 802BE934 3484000E */  ori       $a0, $a0, 0xe
/* 322488 802BE938 0C037FDE */  jal       func_800DFF78
/* 32248C 802BE93C E620000C */   swc1     $f0, 0xc($s1)
/* 322490 802BE940 0C039769 */  jal       set_action_state
/* 322494 802BE944 24040021 */   addiu    $a0, $zero, 0x21
/* 322498 802BE948 0C038045 */  jal       disable_player_static_collisions
/* 32249C 802BE94C 00000000 */   nop
/* 3224A0 802BE950 3C10802C */  lui       $s0, %hi(D_802BFF04)
/* 3224A4 802BE954 2610FF04 */  addiu     $s0, $s0, %lo(D_802BFF04)
/* 3224A8 802BE958 8E020000 */  lw        $v0, ($s0)
/* 3224AC 802BE95C 3C01802C */  lui       $at, %hi(D_802BFF08)
/* 3224B0 802BE960 AC33FF08 */  sw        $s3, %lo(D_802BFF08)($at)
/* 3224B4 802BE964 14400004 */  bnez      $v0, .L802BE978
/* 3224B8 802BE968 00000000 */   nop
/* 3224BC 802BE96C 0C03805E */  jal       disable_player_input
/* 3224C0 802BE970 00000000 */   nop
/* 3224C4 802BE974 AE130000 */  sw        $s3, ($s0)
.L802BE978:
/* 3224C8 802BE978 8E220000 */  lw        $v0, ($s1)
/* 3224CC 802BE97C 3C01802C */  lui       $at, %hi(D_802BFF18)
/* 3224D0 802BE980 AC20FF18 */  sw        $zero, %lo(D_802BFF18)($at)
/* 3224D4 802BE984 3C01802C */  lui       $at, %hi(D_802BFF14)
/* 3224D8 802BE988 AC33FF14 */  sw        $s3, %lo(D_802BFF14)($at)
/* 3224DC 802BE98C 34420040 */  ori       $v0, $v0, 0x40
/* 3224E0 802BE990 AE220000 */  sw        $v0, ($s1)
.L802BE994:
/* 3224E4 802BE994 3C10802C */  lui       $s0, %hi(D_802BFF14)
/* 3224E8 802BE998 2610FF14 */  addiu     $s0, $s0, %lo(D_802BFF14)
/* 3224EC 802BE99C 8E030000 */  lw        $v1, ($s0)
/* 3224F0 802BE9A0 24020028 */  addiu     $v0, $zero, 0x28
/* 3224F4 802BE9A4 10620005 */  beq       $v1, $v0, .L802BE9BC
/* 3224F8 802BE9A8 24020029 */   addiu    $v0, $zero, 0x29
/* 3224FC 802BE9AC 10620019 */  beq       $v1, $v0, .L802BEA14
/* 322500 802BE9B0 24020064 */   addiu    $v0, $zero, 0x64
/* 322504 802BE9B4 080AFABA */  j         .L802BEAE8
/* 322508 802BE9B8 00000000 */   nop
.L802BE9BC:
/* 32250C 802BE9BC 8E430000 */  lw        $v1, ($s2)
/* 322510 802BE9C0 30620800 */  andi      $v0, $v1, 0x800
/* 322514 802BE9C4 14400004 */  bnez      $v0, .L802BE9D8
/* 322518 802BE9C8 2402FEFF */   addiu    $v0, $zero, -0x101
/* 32251C 802BE9CC 82420015 */  lb        $v0, 0x15($s2)
/* 322520 802BE9D0 10400005 */  beqz      $v0, .L802BE9E8
/* 322524 802BE9D4 2402FEFF */   addiu    $v0, $zero, -0x101
.L802BE9D8:
/* 322528 802BE9D8 00621024 */  and       $v0, $v1, $v0
/* 32252C 802BE9DC AE420000 */  sw        $v0, ($s2)
.L802BE9E0:
/* 322530 802BE9E0 080AFD31 */  j         .L802BF4C4
/* 322534 802BE9E4 24020002 */   addiu    $v0, $zero, 2
.L802BE9E8:
/* 322538 802BE9E8 24020003 */  addiu     $v0, $zero, 3
/* 32253C 802BE9EC 0C03805E */  jal       disable_player_input
/* 322540 802BE9F0 AE820074 */   sw       $v0, 0x74($s4)
/* 322544 802BE9F4 AE820078 */  sw        $v0, 0x78($s4)
/* 322548 802BE9F8 8E020000 */  lw        $v0, ($s0)
/* 32254C 802BE9FC 24030001 */  addiu     $v1, $zero, 1
/* 322550 802BEA00 3C01802C */  lui       $at, %hi(D_802BFF04)
/* 322554 802BEA04 AC23FF04 */  sw        $v1, %lo(D_802BFF04)($at)
/* 322558 802BEA08 00431021 */  addu      $v0, $v0, $v1
/* 32255C 802BEA0C 080AFAB6 */  j         .L802BEAD8
/* 322560 802BEA10 AE020000 */   sw       $v0, ($s0)
.L802BEA14:
/* 322564 802BEA14 8E440000 */  lw        $a0, ($s2)
/* 322568 802BEA18 30820800 */  andi      $v0, $a0, 0x800
/* 32256C 802BEA1C 1040000B */  beqz      $v0, .L802BEA4C
/* 322570 802BEA20 2402FEFF */   addiu    $v0, $zero, -0x101
/* 322574 802BEA24 3C10802C */  lui       $s0, %hi(D_802BFF04)
/* 322578 802BEA28 2610FF04 */  addiu     $s0, $s0, %lo(D_802BFF04)
/* 32257C 802BEA2C 8E030000 */  lw        $v1, ($s0)
/* 322580 802BEA30 00821024 */  and       $v0, $a0, $v0
/* 322584 802BEA34 1060FFEA */  beqz      $v1, .L802BE9E0
/* 322588 802BEA38 AE420000 */   sw       $v0, ($s2)
/* 32258C 802BEA3C 0C038069 */  jal       enable_player_input
/* 322590 802BEA40 00000000 */   nop
/* 322594 802BEA44 080AFA78 */  j         .L802BE9E0
/* 322598 802BEA48 AE000000 */   sw       $zero, ($s0)
.L802BEA4C:
/* 32259C 802BEA4C 8E420004 */  lw        $v0, 4($s2)
/* 3225A0 802BEA50 3C030010 */  lui       $v1, 0x10
/* 3225A4 802BEA54 00431024 */  and       $v0, $v0, $v1
/* 3225A8 802BEA58 1040000C */  beqz      $v0, .L802BEA8C
/* 3225AC 802BEA5C 00000000 */   nop
/* 3225B0 802BEA60 82430015 */  lb        $v1, 0x15($s2)
/* 3225B4 802BEA64 8E820078 */  lw        $v0, 0x78($s4)
/* 3225B8 802BEA68 0043102A */  slt       $v0, $v0, $v1
/* 3225BC 802BEA6C 1040026C */  beqz      $v0, .L802BF420
/* 3225C0 802BEA70 24020002 */   addiu    $v0, $zero, 2
/* 3225C4 802BEA74 0C038069 */  jal       enable_player_input
/* 3225C8 802BEA78 00000000 */   nop
/* 3225CC 802BEA7C 3C01802C */  lui       $at, %hi(D_802BFF04)
/* 3225D0 802BEA80 AC20FF04 */  sw        $zero, %lo(D_802BFF04)($at)
/* 3225D4 802BEA84 080AFD08 */  j         .L802BF420
/* 3225D8 802BEA88 24020002 */   addiu    $v0, $zero, 2
.L802BEA8C:
/* 3225DC 802BEA8C 8E820074 */  lw        $v0, 0x74($s4)
/* 3225E0 802BEA90 14400010 */  bnez      $v0, .L802BEAD4
/* 3225E4 802BEA94 2442FFFF */   addiu    $v0, $v0, -1
/* 3225E8 802BEA98 82430015 */  lb        $v1, 0x15($s2)
/* 3225EC 802BEA9C 8E820078 */  lw        $v0, 0x78($s4)
/* 3225F0 802BEAA0 0043102A */  slt       $v0, $v0, $v1
/* 3225F4 802BEAA4 10400009 */  beqz      $v0, .L802BEACC
/* 3225F8 802BEAA8 24020064 */   addiu    $v0, $zero, 0x64
/* 3225FC 802BEAAC 0C038069 */  jal       enable_player_input
/* 322600 802BEAB0 00000000 */   nop
/* 322604 802BEAB4 24020002 */  addiu     $v0, $zero, 2
/* 322608 802BEAB8 8E430000 */  lw        $v1, ($s2)
/* 32260C 802BEABC 3C01802C */  lui       $at, %hi(D_802BFF04)
/* 322610 802BEAC0 AC20FF04 */  sw        $zero, %lo(D_802BFF04)($at)
/* 322614 802BEAC4 080AFD0A */  j         .L802BF428
/* 322618 802BEAC8 2404FEFF */   addiu    $a0, $zero, -0x101
.L802BEACC:
/* 32261C 802BEACC 080AFAB6 */  j         .L802BEAD8
/* 322620 802BEAD0 AE020000 */   sw       $v0, ($s0)
.L802BEAD4:
/* 322624 802BEAD4 AE820074 */  sw        $v0, 0x74($s4)
.L802BEAD8:
/* 322628 802BEAD8 3C10802C */  lui       $s0, %hi(D_802BFF14)
/* 32262C 802BEADC 2610FF14 */  addiu     $s0, $s0, %lo(D_802BFF14)
/* 322630 802BEAE0 8E030000 */  lw        $v1, ($s0)
/* 322634 802BEAE4 24020064 */  addiu     $v0, $zero, 0x64
.L802BEAE8:
/* 322638 802BEAE8 1062001E */  beq       $v1, $v0, .L802BEB64
/* 32263C 802BEAEC 28620065 */   slti     $v0, $v1, 0x65
/* 322640 802BEAF0 10400010 */  beqz      $v0, .L802BEB34
/* 322644 802BEAF4 24020003 */   addiu    $v0, $zero, 3
/* 322648 802BEAF8 10620165 */  beq       $v1, $v0, .L802BF090
/* 32264C 802BEAFC 28620004 */   slti     $v0, $v1, 4
/* 322650 802BEB00 10400005 */  beqz      $v0, .L802BEB18
/* 322654 802BEB04 24020001 */   addiu    $v0, $zero, 1
/* 322658 802BEB08 10620129 */  beq       $v1, $v0, .L802BEFB0
/* 32265C 802BEB0C 00000000 */   nop
/* 322660 802BEB10 080AFCD7 */  j         .L802BF35C
/* 322664 802BEB14 00000000 */   nop
.L802BEB18:
/* 322668 802BEB18 24020004 */  addiu     $v0, $zero, 4
/* 32266C 802BEB1C 106201B6 */  beq       $v1, $v0, .L802BF1F8
/* 322670 802BEB20 24020005 */   addiu    $v0, $zero, 5
/* 322674 802BEB24 106201BB */  beq       $v1, $v0, .L802BF214
/* 322678 802BEB28 0240202D */   daddu    $a0, $s2, $zero
/* 32267C 802BEB2C 080AFCD7 */  j         .L802BF35C
/* 322680 802BEB30 00000000 */   nop
.L802BEB34:
/* 322684 802BEB34 24020066 */  addiu     $v0, $zero, 0x66
/* 322688 802BEB38 1062006F */  beq       $v1, $v0, .L802BECF8
/* 32268C 802BEB3C 0062102A */   slt      $v0, $v1, $v0
/* 322690 802BEB40 14400067 */  bnez      $v0, .L802BECE0
/* 322694 802BEB44 24042081 */   addiu    $a0, $zero, 0x2081
/* 322698 802BEB48 24020067 */  addiu     $v0, $zero, 0x67
/* 32269C 802BEB4C 1062006F */  beq       $v1, $v0, .L802BED0C
/* 3226A0 802BEB50 24020068 */   addiu    $v0, $zero, 0x68
/* 3226A4 802BEB54 106200FC */  beq       $v1, $v0, .L802BEF48
/* 3226A8 802BEB58 00000000 */   nop
/* 3226AC 802BEB5C 080AFCD7 */  j         .L802BF35C
/* 3226B0 802BEB60 00000000 */   nop
.L802BEB64:
/* 3226B4 802BEB64 0C038045 */  jal       disable_player_static_collisions
/* 3226B8 802BEB68 24100001 */   addiu    $s0, $zero, 1
/* 3226BC 802BEB6C 3C13802C */  lui       $s3, %hi(D_802BFF04)
/* 3226C0 802BEB70 2673FF04 */  addiu     $s3, $s3, %lo(D_802BFF04)
/* 3226C4 802BEB74 8E620000 */  lw        $v0, ($s3)
/* 3226C8 802BEB78 3C01802C */  lui       $at, %hi(D_802BFF08)
/* 3226CC 802BEB7C AC30FF08 */  sw        $s0, %lo(D_802BFF08)($at)
/* 3226D0 802BEB80 14400005 */  bnez      $v0, .L802BEB98
/* 3226D4 802BEB84 3C050040 */   lui      $a1, 0x40
/* 3226D8 802BEB88 0C03805E */  jal       disable_player_input
/* 3226DC 802BEB8C 00000000 */   nop
/* 3226E0 802BEB90 AE700000 */  sw        $s0, ($s3)
/* 3226E4 802BEB94 3C050040 */  lui       $a1, 0x40
.L802BEB98:
/* 3226E8 802BEB98 34A50100 */  ori       $a1, $a1, 0x100
/* 3226EC 802BEB9C 24040021 */  addiu     $a0, $zero, 0x21
/* 3226F0 802BEBA0 2403FFF7 */  addiu     $v1, $zero, -9
/* 3226F4 802BEBA4 4480A000 */  mtc1      $zero, $f20
/* 3226F8 802BEBA8 8E220000 */  lw        $v0, ($s1)
/* 3226FC 802BEBAC 3C0142B4 */  lui       $at, 0x42b4
/* 322700 802BEBB0 4481B000 */  mtc1      $at, $f22
/* 322704 802BEBB4 00431024 */  and       $v0, $v0, $v1
/* 322708 802BEBB8 00451025 */  or        $v0, $v0, $a1
/* 32270C 802BEBBC 0C039769 */  jal       set_action_state
/* 322710 802BEBC0 AE220000 */   sw       $v0, ($s1)
/* 322714 802BEBC4 3C01802C */  lui       $at, %hi(D_802BFF0C)
/* 322718 802BEBC8 AC30FF0C */  sw        $s0, %lo(D_802BFF0C)($at)
/* 32271C 802BEBCC 0C03BD38 */  jal       func_800EF4E0
/* 322720 802BEBD0 0000802D */   daddu    $s0, $zero, $zero
/* 322724 802BEBD4 C6400028 */  lwc1      $f0, 0x28($s2)
/* 322728 802BEBD8 E6200060 */  swc1      $f0, 0x60($s1)
/* 32272C 802BEBDC C640002C */  lwc1      $f0, 0x2c($s2)
/* 322730 802BEBE0 E6200064 */  swc1      $f0, 0x64($s1)
/* 322734 802BEBE4 C6400030 */  lwc1      $f0, 0x30($s2)
/* 322738 802BEBE8 E6200068 */  swc1      $f0, 0x68($s1)
.L802BEBEC:
/* 32273C 802BEBEC 3C040001 */  lui       $a0, 1
/* 322740 802BEBF0 27A50020 */  addiu     $a1, $sp, 0x20
/* 322744 802BEBF4 C6200060 */  lwc1      $f0, 0x60($s1)
/* 322748 802BEBF8 C6220064 */  lwc1      $f2, 0x64($s1)
/* 32274C 802BEBFC C6240068 */  lwc1      $f4, 0x68($s1)
/* 322750 802BEC00 C6260018 */  lwc1      $f6, 0x18($s1)
/* 322754 802BEC04 27A60024 */  addiu     $a2, $sp, 0x24
/* 322758 802BEC08 E7A00020 */  swc1      $f0, 0x20($sp)
/* 32275C 802BEC0C E7A20024 */  swc1      $f2, 0x24($sp)
/* 322760 802BEC10 E7A40028 */  swc1      $f4, 0x28($sp)
/* 322764 802BEC14 E7A60010 */  swc1      $f6, 0x10($sp)
/* 322768 802BEC18 E7B40014 */  swc1      $f20, 0x14($sp)
/* 32276C 802BEC1C 862200A8 */  lh        $v0, 0xa8($s1)
/* 322770 802BEC20 27A70028 */  addiu     $a3, $sp, 0x28
/* 322774 802BEC24 44820000 */  mtc1      $v0, $f0
/* 322778 802BEC28 00000000 */  nop
/* 32277C 802BEC2C 46800020 */  cvt.s.w   $f0, $f0
/* 322780 802BEC30 E7A00018 */  swc1      $f0, 0x18($sp)
/* 322784 802BEC34 862200A6 */  lh        $v0, 0xa6($s1)
/* 322788 802BEC38 26100001 */  addiu     $s0, $s0, 1
/* 32278C 802BEC3C 44820000 */  mtc1      $v0, $f0
/* 322790 802BEC40 00000000 */  nop
/* 322794 802BEC44 46800020 */  cvt.s.w   $f0, $f0
/* 322798 802BEC48 0C037711 */  jal       func_800DDC44
/* 32279C 802BEC4C E7A0001C */   swc1     $f0, 0x1c($sp)
/* 3227A0 802BEC50 2A020004 */  slti      $v0, $s0, 4
/* 3227A4 802BEC54 C7A00020 */  lwc1      $f0, 0x20($sp)
/* 3227A8 802BEC58 C7A20024 */  lwc1      $f2, 0x24($sp)
/* 3227AC 802BEC5C C7A40028 */  lwc1      $f4, 0x28($sp)
/* 3227B0 802BEC60 4616A500 */  add.s     $f20, $f20, $f22
/* 3227B4 802BEC64 E6200060 */  swc1      $f0, 0x60($s1)
/* 3227B8 802BEC68 E6220064 */  swc1      $f2, 0x64($s1)
/* 3227BC 802BEC6C 1440FFDF */  bnez      $v0, .L802BEBEC
/* 3227C0 802BEC70 E6240068 */   swc1     $f4, 0x68($s1)
/* 3227C4 802BEC74 C62C0038 */  lwc1      $f12, 0x38($s1)
/* 3227C8 802BEC78 C62E0040 */  lwc1      $f14, 0x40($s1)
/* 3227CC 802BEC7C 44060000 */  mfc1      $a2, $f0
/* 3227D0 802BEC80 44072000 */  mfc1      $a3, $f4
/* 3227D4 802BEC84 0C00A720 */  jal       atan2
/* 3227D8 802BEC88 00000000 */   nop
/* 3227DC 802BEC8C 3C030008 */  lui       $v1, 8
/* 3227E0 802BEC90 34630005 */  ori       $v1, $v1, 5
/* 3227E4 802BEC94 3C040001 */  lui       $a0, 1
/* 3227E8 802BEC98 34840006 */  ori       $a0, $a0, 6
/* 3227EC 802BEC9C E620000C */  swc1      $f0, 0xc($s1)
/* 3227F0 802BECA0 3C014100 */  lui       $at, 0x4100
/* 3227F4 802BECA4 44810000 */  mtc1      $at, $f0
/* 3227F8 802BECA8 3C013FB3 */  lui       $at, 0x3fb3
/* 3227FC 802BECAC 34213333 */  ori       $at, $at, 0x3333
/* 322800 802BECB0 44811000 */  mtc1      $at, $f2
/* 322804 802BECB4 2402000C */  addiu     $v0, $zero, 0xc
/* 322808 802BECB8 A622008E */  sh        $v0, 0x8e($s1)
/* 32280C 802BECBC AE230028 */  sw        $v1, 0x28($s1)
/* 322810 802BECC0 E620001C */  swc1      $f0, 0x1c($s1)
/* 322814 802BECC4 0C037FBF */  jal       func_800DFEFC
/* 322818 802BECC8 E6220014 */   swc1     $f2, 0x14($s1)
/* 32281C 802BECCC 24020065 */  addiu     $v0, $zero, 0x65
/* 322820 802BECD0 3C01802C */  lui       $at, %hi(D_802BFF14)
/* 322824 802BECD4 AC22FF14 */  sw        $v0, %lo(D_802BFF14)($at)
/* 322828 802BECD8 080AFCD7 */  j         .L802BF35C
/* 32282C 802BECDC 00000000 */   nop
.L802BECE0:
/* 322830 802BECE0 0000282D */  daddu     $a1, $zero, $zero
/* 322834 802BECE4 0C052742 */  jal       play_sound_at_npc
/* 322838 802BECE8 2406FFFC */   addiu    $a2, $zero, -4
/* 32283C 802BECEC 3C040001 */  lui       $a0, 1
/* 322840 802BECF0 0C037FBF */  jal       func_800DFEFC
/* 322844 802BECF4 34840007 */   ori      $a0, $a0, 7
.L802BECF8:
/* 322848 802BECF8 3C03802C */  lui       $v1, %hi(D_802BFF14)
/* 32284C 802BECFC 2463FF14 */  addiu     $v1, $v1, %lo(D_802BFF14)
/* 322850 802BED00 8C620000 */  lw        $v0, ($v1)
/* 322854 802BED04 24420001 */  addiu     $v0, $v0, 1
/* 322858 802BED08 AC620000 */  sw        $v0, ($v1)
.L802BED0C:
/* 32285C 802BED0C 8E420000 */  lw        $v0, ($s2)
/* 322860 802BED10 30420800 */  andi      $v0, $v0, 0x800
/* 322864 802BED14 1440017A */  bnez      $v0, .L802BF300
/* 322868 802BED18 2402000A */   addiu    $v0, $zero, 0xa
/* 32286C 802BED1C C6200060 */  lwc1      $f0, 0x60($s1)
/* 322870 802BED20 C62A0038 */  lwc1      $f10, 0x38($s1)
/* 322874 802BED24 8622008E */  lh        $v0, 0x8e($s1)
/* 322878 802BED28 460A0001 */  sub.s     $f0, $f0, $f10
/* 32287C 802BED2C C6280040 */  lwc1      $f8, 0x40($s1)
/* 322880 802BED30 44821000 */  mtc1      $v0, $f2
/* 322884 802BED34 00000000 */  nop
/* 322888 802BED38 468010A0 */  cvt.s.w   $f2, $f2
/* 32288C 802BED3C 46020003 */  div.s     $f0, $f0, $f2
/* 322890 802BED40 46005280 */  add.s     $f10, $f10, $f0
/* 322894 802BED44 C6200068 */  lwc1      $f0, 0x68($s1)
/* 322898 802BED48 C626003C */  lwc1      $f6, 0x3c($s1)
/* 32289C 802BED4C 46080001 */  sub.s     $f0, $f0, $f8
/* 3228A0 802BED50 C6220064 */  lwc1      $f2, 0x64($s1)
/* 3228A4 802BED54 46061081 */  sub.s     $f2, $f2, $f6
/* 3228A8 802BED58 44822000 */  mtc1      $v0, $f4
/* 3228AC 802BED5C 00000000 */  nop
/* 3228B0 802BED60 46802120 */  cvt.s.w   $f4, $f4
/* 3228B4 802BED64 46040003 */  div.s     $f0, $f0, $f4
/* 3228B8 802BED68 46004200 */  add.s     $f8, $f8, $f0
/* 3228BC 802BED6C 46002006 */  mov.s     $f0, $f4
/* 3228C0 802BED70 46001083 */  div.s     $f2, $f2, $f0
/* 3228C4 802BED74 46023180 */  add.s     $f6, $f6, $f2
/* 3228C8 802BED78 C622001C */  lwc1      $f2, 0x1c($s1)
/* 3228CC 802BED7C E62A0038 */  swc1      $f10, 0x38($s1)
/* 3228D0 802BED80 E6280040 */  swc1      $f8, 0x40($s1)
/* 3228D4 802BED84 E626003C */  swc1      $f6, 0x3c($s1)
/* 3228D8 802BED88 864200B0 */  lh        $v0, 0xb0($s2)
/* 3228DC 802BED8C C640002C */  lwc1      $f0, 0x2c($s2)
/* 3228E0 802BED90 44828000 */  mtc1      $v0, $f16
/* 3228E4 802BED94 00000000 */  nop
/* 3228E8 802BED98 46808420 */  cvt.s.w   $f16, $f16
/* 3228EC 802BED9C 00021040 */  sll       $v0, $v0, 1
/* 3228F0 802BEDA0 44058000 */  mfc1      $a1, $f16
/* 3228F4 802BEDA4 44828000 */  mtc1      $v0, $f16
/* 3228F8 802BEDA8 00000000 */  nop
/* 3228FC 802BEDAC 46808420 */  cvt.s.w   $f16, $f16
/* 322900 802BEDB0 46020000 */  add.s     $f0, $f0, $f2
/* 322904 802BEDB4 44068000 */  mfc1      $a2, $f16
/* 322908 802BEDB8 0220202D */  daddu     $a0, $s1, $zero
/* 32290C 802BEDBC 0C0AF667 */  jal       func_802BD99C_3214EC
/* 322910 802BEDC0 E640002C */   swc1     $f0, 0x2c($s2)
/* 322914 802BEDC4 C640002C */  lwc1      $f0, 0x2c($s2)
/* 322918 802BEDC8 3C01802C */  lui       $at, %hi(D_802BFF24)
/* 32291C 802BEDCC C422FF24 */  lwc1      $f2, %lo(D_802BFF24)($at)
/* 322920 802BEDD0 468010A0 */  cvt.s.w   $f2, $f2
/* 322924 802BEDD4 46020000 */  add.s     $f0, $f0, $f2
/* 322928 802BEDD8 26300038 */  addiu     $s0, $s1, 0x38
/* 32292C 802BEDDC E640002C */  swc1      $f0, 0x2c($s2)
/* 322930 802BEDE0 C624003C */  lwc1      $f4, 0x3c($s1)
/* 322934 802BEDE4 C6200014 */  lwc1      $f0, 0x14($s1)
/* 322938 802BEDE8 46022100 */  add.s     $f4, $f4, $f2
/* 32293C 802BEDEC C622001C */  lwc1      $f2, 0x1c($s1)
/* 322940 802BEDF0 4480A000 */  mtc1      $zero, $f20
/* 322944 802BEDF4 46001081 */  sub.s     $f2, $f2, $f0
/* 322948 802BEDF8 26330040 */  addiu     $s3, $s1, 0x40
/* 32294C 802BEDFC E624003C */  swc1      $f4, 0x3c($s1)
/* 322950 802BEE00 4614103E */  c.le.s    $f2, $f20
/* 322954 802BEE04 00000000 */  nop
/* 322958 802BEE08 45000004 */  bc1f      .L802BEE1C
/* 32295C 802BEE0C E622001C */   swc1     $f2, 0x1c($s1)
/* 322960 802BEE10 3C040001 */  lui       $a0, 1
/* 322964 802BEE14 0C037FBF */  jal       func_800DFEFC
/* 322968 802BEE18 34840008 */   ori      $a0, $a0, 8
.L802BEE1C:
/* 32296C 802BEE1C 9622008E */  lhu       $v0, 0x8e($s1)
/* 322970 802BEE20 2442FFFF */  addiu     $v0, $v0, -1
/* 322974 802BEE24 A622008E */  sh        $v0, 0x8e($s1)
/* 322978 802BEE28 00021400 */  sll       $v0, $v0, 0x10
/* 32297C 802BEE2C 00021C03 */  sra       $v1, $v0, 0x10
/* 322980 802BEE30 18600015 */  blez      $v1, .L802BEE88
/* 322984 802BEE34 24020001 */   addiu    $v0, $zero, 1
/* 322988 802BEE38 14620148 */  bne       $v1, $v0, .L802BF35C
/* 32298C 802BEE3C 00000000 */   nop
/* 322990 802BEE40 0200202D */  daddu     $a0, $s0, $zero
/* 322994 802BEE44 3C028007 */  lui       $v0, %hi(gCurrentCameraID)
/* 322998 802BEE48 8C427410 */  lw        $v0, %lo(gCurrentCameraID)($v0)
/* 32299C 802BEE4C 3C06C000 */  lui       $a2, 0xc000
/* 3229A0 802BEE50 00021880 */  sll       $v1, $v0, 2
/* 3229A4 802BEE54 00621821 */  addu      $v1, $v1, $v0
/* 3229A8 802BEE58 00031880 */  sll       $v1, $v1, 2
/* 3229AC 802BEE5C 00621823 */  subu      $v1, $v1, $v0
/* 3229B0 802BEE60 000310C0 */  sll       $v0, $v1, 3
/* 3229B4 802BEE64 00621821 */  addu      $v1, $v1, $v0
/* 3229B8 802BEE68 000318C0 */  sll       $v1, $v1, 3
/* 3229BC 802BEE6C 3C07800B */  lui       $a3, %hi(D_800B1DEC)
/* 3229C0 802BEE70 00E33821 */  addu      $a3, $a3, $v1
/* 3229C4 802BEE74 8CE71DEC */  lw        $a3, %lo(D_800B1DEC)($a3)
/* 3229C8 802BEE78 0C00A7E7 */  jal       add_vec2D_polar
/* 3229CC 802BEE7C 0260282D */   daddu    $a1, $s3, $zero
/* 3229D0 802BEE80 080AFCD7 */  j         .L802BF35C
/* 3229D4 802BEE84 00000000 */   nop
.L802BEE88:
/* 3229D8 802BEE88 C622003C */  lwc1      $f2, 0x3c($s1)
/* 3229DC 802BEE8C 3C014120 */  lui       $at, 0x4120
/* 3229E0 802BEE90 44810000 */  mtc1      $at, $f0
/* 3229E4 802BEE94 00000000 */  nop
/* 3229E8 802BEE98 46001080 */  add.s     $f2, $f2, $f0
/* 3229EC 802BEE9C C640005C */  lwc1      $f0, 0x5c($s2)
/* 3229F0 802BEEA0 24040021 */  addiu     $a0, $zero, 0x21
/* 3229F4 802BEEA4 E642002C */  swc1      $f2, 0x2c($s2)
/* 3229F8 802BEEA8 E6200018 */  swc1      $f0, 0x18($s1)
/* 3229FC 802BEEAC E6340014 */  swc1      $f20, 0x14($s1)
/* 322A00 802BEEB0 C6400080 */  lwc1      $f0, 0x80($s2)
/* 322A04 802BEEB4 24020003 */  addiu     $v0, $zero, 3
/* 322A08 802BEEB8 A622008E */  sh        $v0, 0x8e($s1)
/* 322A0C 802BEEBC 0C039769 */  jal       set_action_state
/* 322A10 802BEEC0 E620000C */   swc1     $f0, 0xc($s1)
/* 322A14 802BEEC4 3C040008 */  lui       $a0, 8
/* 322A18 802BEEC8 0C037FDE */  jal       func_800DFF78
/* 322A1C 802BEECC 3484000E */   ori      $a0, $a0, 0xe
/* 322A20 802BEED0 0C038039 */  jal       disable_player_shadow
/* 322A24 802BEED4 00000000 */   nop
/* 322A28 802BEED8 24020008 */  addiu     $v0, $zero, 8
/* 322A2C 802BEEDC A2A20003 */  sb        $v0, 3($s5)
/* 322A30 802BEEE0 24020001 */  addiu     $v0, $zero, 1
/* 322A34 802BEEE4 3C014000 */  lui       $at, 0x4000
/* 322A38 802BEEE8 44816000 */  mtc1      $at, $f12
/* 322A3C 802BEEEC 2403FEFF */  addiu     $v1, $zero, -0x101
/* 322A40 802BEEF0 A2A20000 */  sb        $v0, ($s5)
/* 322A44 802BEEF4 8E420000 */  lw        $v0, ($s2)
/* 322A48 802BEEF8 3C048007 */  lui       $a0, %hi(gGameStatusPtr)
/* 322A4C 802BEEFC 8C84419C */  lw        $a0, %lo(gGameStatusPtr)($a0)
/* 322A50 802BEF00 00431024 */  and       $v0, $v0, $v1
/* 322A54 802BEF04 AE420000 */  sw        $v0, ($s2)
/* 322A58 802BEF08 24020002 */  addiu     $v0, $zero, 2
/* 322A5C 802BEF0C A080007D */  sb        $zero, 0x7d($a0)
/* 322A60 802BEF10 3C01802C */  lui       $at, %hi(D_802BFF18)
/* 322A64 802BEF14 AC20FF18 */  sw        $zero, %lo(D_802BFF18)($at)
/* 322A68 802BEF18 3C01802C */  lui       $at, %hi(D_802BFF0C)
/* 322A6C 802BEF1C AC22FF0C */  sw        $v0, %lo(D_802BFF0C)($at)
/* 322A70 802BEF20 0C0AFED1 */  jal       func_802BFB44_323694
/* 322A74 802BEF24 00000000 */   nop
/* 322A78 802BEF28 24020068 */  addiu     $v0, $zero, 0x68
/* 322A7C 802BEF2C 3C01802C */  lui       $at, %hi(D_802BFF14)
/* 322A80 802BEF30 AC22FF14 */  sw        $v0, %lo(D_802BFF14)($at)
/* 322A84 802BEF34 8E420004 */  lw        $v0, 4($s2)
/* 322A88 802BEF38 3C030040 */  lui       $v1, 0x40
/* 322A8C 802BEF3C 00431025 */  or        $v0, $v0, $v1
/* 322A90 802BEF40 080AFCD7 */  j         .L802BF35C
/* 322A94 802BEF44 AE420004 */   sw       $v0, 4($s2)
.L802BEF48:
/* 322A98 802BEF48 8E420000 */  lw        $v0, ($s2)
/* 322A9C 802BEF4C 30420800 */  andi      $v0, $v0, 0x800
/* 322AA0 802BEF50 10400003 */  beqz      $v0, .L802BEF60
/* 322AA4 802BEF54 2402000A */   addiu    $v0, $zero, 0xa
/* 322AA8 802BEF58 080AFCD7 */  j         .L802BF35C
/* 322AAC 802BEF5C AE020000 */   sw       $v0, ($s0)
.L802BEF60:
/* 322AB0 802BEF60 9622008E */  lhu       $v0, 0x8e($s1)
/* 322AB4 802BEF64 2442FFFF */  addiu     $v0, $v0, -1
/* 322AB8 802BEF68 A622008E */  sh        $v0, 0x8e($s1)
/* 322ABC 802BEF6C 00021400 */  sll       $v0, $v0, 0x10
/* 322AC0 802BEF70 1040000B */  beqz      $v0, .L802BEFA0
/* 322AC4 802BEF74 24030001 */   addiu    $v1, $zero, 1
/* 322AC8 802BEF78 8EA2000C */  lw        $v0, 0xc($s5)
/* 322ACC 802BEF7C 30424004 */  andi      $v0, $v0, 0x4004
/* 322AD0 802BEF80 104000F6 */  beqz      $v0, .L802BF35C
/* 322AD4 802BEF84 00000000 */   nop
/* 322AD8 802BEF88 0C0AF5F7 */  jal       func_802BD7DC
/* 322ADC 802BEF8C 00000000 */   nop
/* 322AE0 802BEF90 104000F2 */  beqz      $v0, .L802BF35C
/* 322AE4 802BEF94 24020003 */   addiu    $v0, $zero, 3
/* 322AE8 802BEF98 080AFCD7 */  j         .L802BF35C
/* 322AEC 802BEF9C AE020000 */   sw       $v0, ($s0)
.L802BEFA0:
/* 322AF0 802BEFA0 8E220000 */  lw        $v0, ($s1)
/* 322AF4 802BEFA4 AE030000 */  sw        $v1, ($s0)
/* 322AF8 802BEFA8 34420040 */  ori       $v0, $v0, 0x40
/* 322AFC 802BEFAC AE220000 */  sw        $v0, ($s1)
.L802BEFB0:
/* 322B00 802BEFB0 0C0AF776 */  jal       func_802BDDD8_321928
/* 322B04 802BEFB4 0220202D */   daddu    $a0, $s1, $zero
/* 322B08 802BEFB8 3C030040 */  lui       $v1, 0x40
/* 322B0C 802BEFBC 3C04802C */  lui       $a0, %hi(D_802BFF18)
/* 322B10 802BEFC0 2484FF18 */  addiu     $a0, $a0, %lo(D_802BFF18)
/* 322B14 802BEFC4 8E420004 */  lw        $v0, 4($s2)
/* 322B18 802BEFC8 3C014000 */  lui       $at, 0x4000
/* 322B1C 802BEFCC 44811000 */  mtc1      $at, $f2
/* 322B20 802BEFD0 00431025 */  or        $v0, $v0, $v1
/* 322B24 802BEFD4 AE420004 */  sw        $v0, 4($s2)
/* 322B28 802BEFD8 8C830000 */  lw        $v1, ($a0)
/* 322B2C 802BEFDC C6200064 */  lwc1      $f0, 0x64($s1)
/* 322B30 802BEFE0 24620001 */  addiu     $v0, $v1, 1
/* 322B34 802BEFE4 46020000 */  add.s     $f0, $f0, $f2
/* 322B38 802BEFE8 AC820000 */  sw        $v0, ($a0)
/* 322B3C 802BEFEC 2842000A */  slti      $v0, $v0, 0xa
/* 322B40 802BEFF0 14400003 */  bnez      $v0, .L802BF000
/* 322B44 802BEFF4 E620003C */   swc1     $f0, 0x3c($s1)
/* 322B48 802BEFF8 2462FFEF */  addiu     $v0, $v1, -0x11
/* 322B4C 802BEFFC AC820000 */  sw        $v0, ($a0)
.L802BF000:
/* 322B50 802BF000 82A20014 */  lb        $v0, 0x14($s5)
/* 322B54 802BF004 14400003 */  bnez      $v0, .L802BF014
/* 322B58 802BF008 00000000 */   nop
/* 322B5C 802BF00C C620000C */  lwc1      $f0, 0xc($s1)
/* 322B60 802BF010 E6400080 */  swc1      $f0, 0x80($s2)
.L802BF014:
/* 322B64 802BF014 8E420000 */  lw        $v0, ($s2)
/* 322B68 802BF018 30420800 */  andi      $v0, $v0, 0x800
/* 322B6C 802BF01C 144000B8 */  bnez      $v0, .L802BF300
/* 322B70 802BF020 2402000A */   addiu    $v0, $zero, 0xa
/* 322B74 802BF024 8EA2000C */  lw        $v0, 0xc($s5)
/* 322B78 802BF028 30424004 */  andi      $v0, $v0, 0x4004
/* 322B7C 802BF02C 104000CB */  beqz      $v0, .L802BF35C
/* 322B80 802BF030 00000000 */   nop
/* 322B84 802BF034 0C0AF5F7 */  jal       func_802BD7DC
/* 322B88 802BF038 00000000 */   nop
/* 322B8C 802BF03C 10400005 */  beqz      $v0, .L802BF054
/* 322B90 802BF040 24020003 */   addiu    $v0, $zero, 3
/* 322B94 802BF044 3C01802C */  lui       $at, %hi(D_802BFF14)
/* 322B98 802BF048 AC22FF14 */  sw        $v0, %lo(D_802BFF14)($at)
/* 322B9C 802BF04C 080AFCD7 */  j         .L802BF35C
/* 322BA0 802BF050 00000000 */   nop
.L802BF054:
/* 322BA4 802BF054 8E420004 */  lw        $v0, 4($s2)
/* 322BA8 802BF058 3C034000 */  lui       $v1, 0x4000
/* 322BAC 802BF05C 00431024 */  and       $v0, $v0, $v1
/* 322BB0 802BF060 14400006 */  bnez      $v0, .L802BF07C
/* 322BB4 802BF064 3C03BFFF */   lui      $v1, 0xbfff
/* 322BB8 802BF068 2404021D */  addiu     $a0, $zero, 0x21d
/* 322BBC 802BF06C 0000282D */  daddu     $a1, $zero, $zero
/* 322BC0 802BF070 0C052742 */  jal       play_sound_at_npc
/* 322BC4 802BF074 2406FFFC */   addiu    $a2, $zero, -4
/* 322BC8 802BF078 3C03BFFF */  lui       $v1, 0xbfff
.L802BF07C:
/* 322BCC 802BF07C 8E420004 */  lw        $v0, 4($s2)
/* 322BD0 802BF080 3463FFFF */  ori       $v1, $v1, 0xffff
/* 322BD4 802BF084 00431024 */  and       $v0, $v0, $v1
/* 322BD8 802BF088 080AFCD7 */  j         .L802BF35C
/* 322BDC 802BF08C AE420004 */   sw       $v0, 4($s2)
.L802BF090:
/* 322BE0 802BF090 8E220000 */  lw        $v0, ($s1)
/* 322BE4 802BF094 2403FFBF */  addiu     $v1, $zero, -0x41
/* 322BE8 802BF098 00431024 */  and       $v0, $v0, $v1
/* 322BEC 802BF09C AE220000 */  sw        $v0, ($s1)
/* 322BF0 802BF0A0 8E420000 */  lw        $v0, ($s2)
/* 322BF4 802BF0A4 34420100 */  ori       $v0, $v0, 0x100
/* 322BF8 802BF0A8 0C0AF5F7 */  jal       func_802BD7DC
/* 322BFC 802BF0AC AE420000 */   sw       $v0, ($s2)
/* 322C00 802BF0B0 3C02800B */  lui       $v0, %hi(gCameras)
/* 322C04 802BF0B4 24421D80 */  addiu     $v0, $v0, %lo(gCameras)
/* 322C08 802BF0B8 C64200A8 */  lwc1      $f2, 0xa8($s2)
/* 322C0C 802BF0BC 3C0142B4 */  lui       $at, 0x42b4
/* 322C10 802BF0C0 44813000 */  mtc1      $at, $f6
/* 322C14 802BF0C4 C444006C */  lwc1      $f4, 0x6c($v0)
/* 322C18 802BF0C8 4602303E */  c.le.s    $f6, $f2
/* 322C1C 802BF0CC 00000000 */  nop
/* 322C20 802BF0D0 4500000E */  bc1f      .L802BF10C
/* 322C24 802BF0D4 00000000 */   nop
/* 322C28 802BF0D8 3C014387 */  lui       $at, 0x4387
/* 322C2C 802BF0DC 44810000 */  mtc1      $at, $f0
/* 322C30 802BF0E0 00000000 */  nop
/* 322C34 802BF0E4 4600103C */  c.lt.s    $f2, $f0
/* 322C38 802BF0E8 00000000 */  nop
/* 322C3C 802BF0EC 45000007 */  bc1f      .L802BF10C
/* 322C40 802BF0F0 00000000 */   nop
/* 322C44 802BF0F4 3C014334 */  lui       $at, 0x4334
/* 322C48 802BF0F8 44810000 */  mtc1      $at, $f0
/* 322C4C 802BF0FC 00000000 */  nop
/* 322C50 802BF100 46002000 */  add.s     $f0, $f4, $f0
/* 322C54 802BF104 080AFC4A */  j         .L802BF128
/* 322C58 802BF108 46060501 */   sub.s    $f20, $f0, $f6
.L802BF10C:
/* 322C5C 802BF10C 44800000 */  mtc1      $zero, $f0
/* 322C60 802BF110 00000000 */  nop
/* 322C64 802BF114 46002000 */  add.s     $f0, $f4, $f0
/* 322C68 802BF118 3C0142B4 */  lui       $at, 0x42b4
/* 322C6C 802BF11C 44811000 */  mtc1      $at, $f2
/* 322C70 802BF120 00000000 */  nop
/* 322C74 802BF124 46020501 */  sub.s     $f20, $f0, $f2
.L802BF128:
/* 322C78 802BF128 E634000C */  swc1      $f20, 0xc($s1)
/* 322C7C 802BF12C C64C0028 */  lwc1      $f12, 0x28($s2)
/* 322C80 802BF130 C64E0030 */  lwc1      $f14, 0x30($s2)
/* 322C84 802BF134 8E260060 */  lw        $a2, 0x60($s1)
/* 322C88 802BF138 0C00A7B5 */  jal       dist2D
/* 322C8C 802BF13C 8E270068 */   lw       $a3, 0x68($s1)
/* 322C90 802BF140 C64C0028 */  lwc1      $f12, 0x28($s2)
/* 322C94 802BF144 C64E0030 */  lwc1      $f14, 0x30($s2)
/* 322C98 802BF148 8E260060 */  lw        $a2, 0x60($s1)
/* 322C9C 802BF14C 8E270068 */  lw        $a3, 0x68($s1)
/* 322CA0 802BF150 0C00A720 */  jal       atan2
/* 322CA4 802BF154 E7A0002C */   swc1     $f0, 0x2c($sp)
/* 322CA8 802BF158 C6240064 */  lwc1      $f4, 0x64($s1)
/* 322CAC 802BF15C C622003C */  lwc1      $f2, 0x3c($s1)
/* 322CB0 802BF160 E620000C */  swc1      $f0, 0xc($s1)
/* 322CB4 802BF164 3C013F99 */  lui       $at, 0x3f99
/* 322CB8 802BF168 3421999A */  ori       $at, $at, 0x999a
/* 322CBC 802BF16C 44810000 */  mtc1      $at, $f0
/* 322CC0 802BF170 2402000E */  addiu     $v0, $zero, 0xe
/* 322CC4 802BF174 A622008E */  sh        $v0, 0x8e($s1)
/* 322CC8 802BF178 4604103C */  c.lt.s    $f2, $f4
/* 322CCC 802BF17C 00000000 */  nop
/* 322CD0 802BF180 45000009 */  bc1f      .L802BF1A8
/* 322CD4 802BF184 E6200014 */   swc1     $f0, 0x14($s1)
/* 322CD8 802BF188 46022001 */  sub.s     $f0, $f4, $f2
/* 322CDC 802BF18C 3C014160 */  lui       $at, 0x4160
/* 322CE0 802BF190 44811000 */  mtc1      $at, $f2
/* 322CE4 802BF194 3C0140C0 */  lui       $at, 0x40c0
/* 322CE8 802BF198 44812000 */  mtc1      $at, $f4
/* 322CEC 802BF19C 46020003 */  div.s     $f0, $f0, $f2
/* 322CF0 802BF1A0 080AFC6D */  j         .L802BF1B4
/* 322CF4 802BF1A4 46040000 */   add.s    $f0, $f0, $f4
.L802BF1A8:
/* 322CF8 802BF1A8 3C0140C0 */  lui       $at, 0x40c0
/* 322CFC 802BF1AC 44810000 */  mtc1      $at, $f0
/* 322D00 802BF1B0 00000000 */  nop
.L802BF1B4:
/* 322D04 802BF1B4 E620001C */  swc1      $f0, 0x1c($s1)
/* 322D08 802BF1B8 3C040001 */  lui       $a0, 1
/* 322D0C 802BF1BC 34840006 */  ori       $a0, $a0, 6
/* 322D10 802BF1C0 8622008E */  lh        $v0, 0x8e($s1)
/* 322D14 802BF1C4 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* 322D18 802BF1C8 44821000 */  mtc1      $v0, $f2
/* 322D1C 802BF1CC 00000000 */  nop
/* 322D20 802BF1D0 468010A0 */  cvt.s.w   $f2, $f2
/* 322D24 802BF1D4 46020003 */  div.s     $f0, $f0, $f2
/* 322D28 802BF1D8 0C037FBF */  jal       func_800DFEFC
/* 322D2C 802BF1DC E6200018 */   swc1     $f0, 0x18($s1)
/* 322D30 802BF1E0 3C03802C */  lui       $v1, %hi(D_802BFF14)
/* 322D34 802BF1E4 2463FF14 */  addiu     $v1, $v1, %lo(D_802BFF14)
/* 322D38 802BF1E8 8C620000 */  lw        $v0, ($v1)
/* 322D3C 802BF1EC 24420001 */  addiu     $v0, $v0, 1
/* 322D40 802BF1F0 080AFCD7 */  j         .L802BF35C
/* 322D44 802BF1F4 AC620000 */   sw       $v0, ($v1)
.L802BF1F8:
/* 322D48 802BF1F8 3C040001 */  lui       $a0, 1
/* 322D4C 802BF1FC 0C037FBF */  jal       func_800DFEFC
/* 322D50 802BF200 34840007 */   ori      $a0, $a0, 7
/* 322D54 802BF204 8E020000 */  lw        $v0, ($s0)
/* 322D58 802BF208 24420001 */  addiu     $v0, $v0, 1
/* 322D5C 802BF20C AE020000 */  sw        $v0, ($s0)
/* 322D60 802BF210 0240202D */  daddu     $a0, $s2, $zero
.L802BF214:
/* 322D64 802BF214 3C08800B */  lui       $t0, %hi(gCameras)
/* 322D68 802BF218 25081D80 */  addiu     $t0, $t0, %lo(gCameras)
/* 322D6C 802BF21C 27A50020 */  addiu     $a1, $sp, 0x20
/* 322D70 802BF220 27B40024 */  addiu     $s4, $sp, 0x24
/* 322D74 802BF224 0280302D */  daddu     $a2, $s4, $zero
/* 322D78 802BF228 27A70028 */  addiu     $a3, $sp, 0x28
/* 322D7C 802BF22C 26500028 */  addiu     $s0, $s2, 0x28
/* 322D80 802BF230 95020002 */  lhu       $v0, 2($t0)
/* 322D84 802BF234 26530030 */  addiu     $s3, $s2, 0x30
/* 322D88 802BF238 34420001 */  ori       $v0, $v0, 1
/* 322D8C 802BF23C A5020002 */  sh        $v0, 2($t0)
/* 322D90 802BF240 C640002C */  lwc1      $f0, 0x2c($s2)
/* 322D94 802BF244 C622001C */  lwc1      $f2, 0x1c($s1)
/* 322D98 802BF248 864200B0 */  lh        $v0, 0xb0($s2)
/* 322D9C 802BF24C C6480028 */  lwc1      $f8, 0x28($s2)
/* 322DA0 802BF250 46020000 */  add.s     $f0, $f0, $f2
/* 322DA4 802BF254 3C013F00 */  lui       $at, 0x3f00
/* 322DA8 802BF258 44811000 */  mtc1      $at, $f2
/* 322DAC 802BF25C 44826000 */  mtc1      $v0, $f12
/* 322DB0 802BF260 00000000 */  nop
/* 322DB4 802BF264 46806320 */  cvt.s.w   $f12, $f12
/* 322DB8 802BF268 46026302 */  mul.s     $f12, $f12, $f2
/* 322DBC 802BF26C 00000000 */  nop
/* 322DC0 802BF270 C64A0030 */  lwc1      $f10, 0x30($s2)
/* 322DC4 802BF274 0040182D */  daddu     $v1, $v0, $zero
/* 322DC8 802BF278 E640002C */  swc1      $f0, 0x2c($s2)
/* 322DCC 802BF27C 44830000 */  mtc1      $v1, $f0
/* 322DD0 802BF280 00000000 */  nop
/* 322DD4 802BF284 46800020 */  cvt.s.w   $f0, $f0
/* 322DD8 802BF288 46020002 */  mul.s     $f0, $f0, $f2
/* 322DDC 802BF28C 00000000 */  nop
/* 322DE0 802BF290 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 322DE4 802BF294 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 322DE8 802BF298 C644002C */  lwc1      $f4, 0x2c($s2)
/* 322DEC 802BF29C 3C0142B4 */  lui       $at, 0x42b4
/* 322DF0 802BF2A0 44811000 */  mtc1      $at, $f2
/* 322DF4 802BF2A4 00031080 */  sll       $v0, $v1, 2
/* 322DF8 802BF2A8 00431021 */  addu      $v0, $v0, $v1
/* 322DFC 802BF2AC 00021080 */  sll       $v0, $v0, 2
/* 322E00 802BF2B0 00431023 */  subu      $v0, $v0, $v1
/* 322E04 802BF2B4 000218C0 */  sll       $v1, $v0, 3
/* 322E08 802BF2B8 00431021 */  addu      $v0, $v0, $v1
/* 322E0C 802BF2BC 000210C0 */  sll       $v0, $v0, 3
/* 322E10 802BF2C0 00481021 */  addu      $v0, $v0, $t0
/* 322E14 802BF2C4 C446006C */  lwc1      $f6, 0x6c($v0)
/* 322E18 802BF2C8 46002100 */  add.s     $f4, $f4, $f0
/* 322E1C 802BF2CC C64000A8 */  lwc1      $f0, 0xa8($s2)
/* 322E20 802BF2D0 27A2002C */  addiu     $v0, $sp, 0x2c
/* 322E24 802BF2D4 E7A80020 */  swc1      $f8, 0x20($sp)
/* 322E28 802BF2D8 46020001 */  sub.s     $f0, $f0, $f2
/* 322E2C 802BF2DC E7AA0028 */  swc1      $f10, 0x28($sp)
/* 322E30 802BF2E0 E7AC002C */  swc1      $f12, 0x2c($sp)
/* 322E34 802BF2E4 46060500 */  add.s     $f20, $f0, $f6
/* 322E38 802BF2E8 E7A40024 */  swc1      $f4, 0x24($sp)
/* 322E3C 802BF2EC AFA20010 */  sw        $v0, 0x10($sp)
/* 322E40 802BF2F0 0C0379F9 */  jal       collision_check_above
/* 322E44 802BF2F4 E7B40014 */   swc1     $f20, 0x14($sp)
/* 322E48 802BF2F8 04400005 */  bltz      $v0, .L802BF310
/* 322E4C 802BF2FC 2402000A */   addiu    $v0, $zero, 0xa
.L802BF300:
/* 322E50 802BF300 3C01802C */  lui       $at, %hi(D_802BFF14)
/* 322E54 802BF304 AC22FF14 */  sw        $v0, %lo(D_802BFF14)($at)
/* 322E58 802BF308 080AFCD7 */  j         .L802BF35C
/* 322E5C 802BF30C 00000000 */   nop
.L802BF310:
/* 322E60 802BF310 0200202D */  daddu     $a0, $s0, $zero
/* 322E64 802BF314 C620001C */  lwc1      $f0, 0x1c($s1)
/* 322E68 802BF318 C6220014 */  lwc1      $f2, 0x14($s1)
/* 322E6C 802BF31C 8E260018 */  lw        $a2, 0x18($s1)
/* 322E70 802BF320 46020001 */  sub.s     $f0, $f0, $f2
/* 322E74 802BF324 8E27000C */  lw        $a3, 0xc($s1)
/* 322E78 802BF328 0260282D */  daddu     $a1, $s3, $zero
/* 322E7C 802BF32C 0C00A7E7 */  jal       add_vec2D_polar
/* 322E80 802BF330 E620001C */   swc1     $f0, 0x1c($s1)
/* 322E84 802BF334 0C0392B6 */  jal       func_800E4AD8
/* 322E88 802BF338 0000202D */   daddu    $a0, $zero, $zero
/* 322E8C 802BF33C 0C0AF9A8 */  jal       func_802BE6A0_3221F0
/* 322E90 802BF340 0280202D */   daddu    $a0, $s4, $zero
/* 322E94 802BF344 04400005 */  bltz      $v0, .L802BF35C
/* 322E98 802BF348 2402000A */   addiu    $v0, $zero, 0xa
/* 322E9C 802BF34C C7A00024 */  lwc1      $f0, 0x24($sp)
/* 322EA0 802BF350 3C01802C */  lui       $at, %hi(D_802BFF14)
/* 322EA4 802BF354 AC22FF14 */  sw        $v0, %lo(D_802BFF14)($at)
/* 322EA8 802BF358 E640002C */  swc1      $f0, 0x2c($s2)
.L802BF35C:
/* 322EAC 802BF35C C6400028 */  lwc1      $f0, 0x28($s2)
/* 322EB0 802BF360 3C02800B */  lui       $v0, %hi(gCameras)
/* 322EB4 802BF364 24421D80 */  addiu     $v0, $v0, %lo(gCameras)
/* 322EB8 802BF368 E4400060 */  swc1      $f0, 0x60($v0)
/* 322EBC 802BF36C C6400030 */  lwc1      $f0, 0x30($s2)
/* 322EC0 802BF370 C6220064 */  lwc1      $f2, 0x64($s1)
/* 322EC4 802BF374 3C10802C */  lui       $s0, %hi(D_802BFF14)
/* 322EC8 802BF378 2610FF14 */  addiu     $s0, $s0, %lo(D_802BFF14)
/* 322ECC 802BF37C E4400068 */  swc1      $f0, 0x68($v0)
/* 322ED0 802BF380 E4420064 */  swc1      $f2, 0x64($v0)
/* 322ED4 802BF384 8E030000 */  lw        $v1, ($s0)
/* 322ED8 802BF388 2402000A */  addiu     $v0, $zero, 0xa
/* 322EDC 802BF38C 14620030 */  bne       $v1, $v0, .L802BF450
/* 322EE0 802BF390 2402000B */   addiu    $v0, $zero, 0xb
/* 322EE4 802BF394 3C02FFBF */  lui       $v0, 0xffbf
/* 322EE8 802BF398 3442FFB7 */  ori       $v0, $v0, 0xffb7
/* 322EEC 802BF39C 8E230000 */  lw        $v1, ($s1)
/* 322EF0 802BF3A0 3C05802C */  lui       $a1, %hi(D_802BFF08)
/* 322EF4 802BF3A4 24A5FF08 */  addiu     $a1, $a1, %lo(D_802BFF08)
/* 322EF8 802BF3A8 3C01802C */  lui       $at, %hi(D_802BFF0C)
/* 322EFC 802BF3AC AC20FF0C */  sw        $zero, %lo(D_802BFF0C)($at)
/* 322F00 802BF3B0 8CA40000 */  lw        $a0, ($a1)
/* 322F04 802BF3B4 00621824 */  and       $v1, $v1, $v0
/* 322F08 802BF3B8 10800003 */  beqz      $a0, .L802BF3C8
/* 322F0C 802BF3BC AE230000 */   sw       $v1, ($s1)
/* 322F10 802BF3C0 0C038050 */  jal       enable_player_static_collisions
/* 322F14 802BF3C4 ACA00000 */   sw       $zero, ($a1)
.L802BF3C8:
/* 322F18 802BF3C8 0C03802C */  jal       enable_player_shadow
/* 322F1C 802BF3CC 00000000 */   nop
/* 322F20 802BF3D0 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 322F24 802BF3D4 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 322F28 802BF3D8 A040007D */  sb        $zero, 0x7d($v0)
/* 322F2C 802BF3DC 8E420000 */  lw        $v0, ($s2)
/* 322F30 802BF3E0 30420800 */  andi      $v0, $v0, 0x800
/* 322F34 802BF3E4 10400013 */  beqz      $v0, .L802BF434
/* 322F38 802BF3E8 00000000 */   nop
/* 322F3C 802BF3EC 3C03802C */  lui       $v1, %hi(D_802BFF04)
/* 322F40 802BF3F0 2463FF04 */  addiu     $v1, $v1, %lo(D_802BFF04)
/* 322F44 802BF3F4 8C620000 */  lw        $v0, ($v1)
/* 322F48 802BF3F8 A2A00003 */  sb        $zero, 3($s5)
/* 322F4C 802BF3FC 10400003 */  beqz      $v0, .L802BF40C
/* 322F50 802BF400 A2A00000 */   sb       $zero, ($s5)
/* 322F54 802BF404 0C038069 */  jal       enable_player_input
/* 322F58 802BF408 AC600000 */   sw       $zero, ($v1)
.L802BF40C:
/* 322F5C 802BF40C 0C03BD17 */  jal       clear_partner_move_history
/* 322F60 802BF410 0220202D */   daddu    $a0, $s1, $zero
/* 322F64 802BF414 0C039769 */  jal       set_action_state
/* 322F68 802BF418 24040015 */   addiu    $a0, $zero, 0x15
/* 322F6C 802BF41C 24020001 */  addiu     $v0, $zero, 1
.L802BF420:
/* 322F70 802BF420 8E430000 */  lw        $v1, ($s2)
/* 322F74 802BF424 2404FEFF */  addiu     $a0, $zero, -0x101
.L802BF428:
/* 322F78 802BF428 00641824 */  and       $v1, $v1, $a0
/* 322F7C 802BF42C 080AFD31 */  j         .L802BF4C4
/* 322F80 802BF430 AE430000 */   sw       $v1, ($s2)
.L802BF434:
/* 322F84 802BF434 0C039769 */  jal       set_action_state
/* 322F88 802BF438 24040008 */   addiu    $a0, $zero, 8
/* 322F8C 802BF43C 0C038C1B */  jal       gravity_use_fall_parms
/* 322F90 802BF440 00000000 */   nop
/* 322F94 802BF444 2402000B */  addiu     $v0, $zero, 0xb
/* 322F98 802BF448 080AFD30 */  j         .L802BF4C0
/* 322F9C 802BF44C AE020000 */   sw       $v0, ($s0)
.L802BF450:
/* 322FA0 802BF450 1462001C */  bne       $v1, $v0, .L802BF4C4
/* 322FA4 802BF454 0000102D */   daddu    $v0, $zero, $zero
/* 322FA8 802BF458 3C03FFBF */  lui       $v1, 0xffbf
/* 322FAC 802BF45C 3463FFB7 */  ori       $v1, $v1, 0xffb7
/* 322FB0 802BF460 2404FEFF */  addiu     $a0, $zero, -0x101
/* 322FB4 802BF464 8E220000 */  lw        $v0, ($s1)
/* 322FB8 802BF468 3C05802C */  lui       $a1, %hi(D_802BFF04)
/* 322FBC 802BF46C 24A5FF04 */  addiu     $a1, $a1, %lo(D_802BFF04)
/* 322FC0 802BF470 00431024 */  and       $v0, $v0, $v1
/* 322FC4 802BF474 AE220000 */  sw        $v0, ($s1)
/* 322FC8 802BF478 A2A00003 */  sb        $zero, 3($s5)
/* 322FCC 802BF47C A2A00000 */  sb        $zero, ($s5)
/* 322FD0 802BF480 8E420000 */  lw        $v0, ($s2)
/* 322FD4 802BF484 8CA30000 */  lw        $v1, ($a1)
/* 322FD8 802BF488 00441024 */  and       $v0, $v0, $a0
/* 322FDC 802BF48C 10600003 */  beqz      $v1, .L802BF49C
/* 322FE0 802BF490 AE420000 */   sw       $v0, ($s2)
/* 322FE4 802BF494 0C038069 */  jal       enable_player_input
/* 322FE8 802BF498 ACA00000 */   sw       $zero, ($a1)
.L802BF49C:
/* 322FEC 802BF49C 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 322FF0 802BF4A0 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 322FF4 802BF4A4 0220202D */  daddu     $a0, $s1, $zero
/* 322FF8 802BF4A8 0C03BD17 */  jal       clear_partner_move_history
/* 322FFC 802BF4AC A040007D */   sb       $zero, 0x7d($v0)
/* 323000 802BF4B0 0C03BCF5 */  jal       func_800EF3D4
/* 323004 802BF4B4 24040002 */   addiu    $a0, $zero, 2
/* 323008 802BF4B8 080AFD31 */  j         .L802BF4C4
/* 32300C 802BF4BC 24020001 */   addiu    $v0, $zero, 1
.L802BF4C0:
/* 323010 802BF4C0 0000102D */  daddu     $v0, $zero, $zero
.L802BF4C4:
/* 323014 802BF4C4 8FBF0048 */  lw        $ra, 0x48($sp)
/* 323018 802BF4C8 8FB50044 */  lw        $s5, 0x44($sp)
/* 32301C 802BF4CC 8FB40040 */  lw        $s4, 0x40($sp)
/* 323020 802BF4D0 8FB3003C */  lw        $s3, 0x3c($sp)
/* 323024 802BF4D4 8FB20038 */  lw        $s2, 0x38($sp)
/* 323028 802BF4D8 8FB10034 */  lw        $s1, 0x34($sp)
/* 32302C 802BF4DC 8FB00030 */  lw        $s0, 0x30($sp)
/* 323030 802BF4E0 D7B60058 */  ldc1      $f22, 0x58($sp)
/* 323034 802BF4E4 D7B40050 */  ldc1      $f20, 0x50($sp)
/* 323038 802BF4E8 03E00008 */  jr        $ra
/* 32303C 802BF4EC 27BD0060 */   addiu    $sp, $sp, 0x60
