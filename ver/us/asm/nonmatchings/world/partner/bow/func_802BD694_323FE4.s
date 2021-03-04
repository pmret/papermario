.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BD694_323FE4
/* 323FE4 802BD694 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 323FE8 802BD698 AFB40030 */  sw        $s4, 0x30($sp)
/* 323FEC 802BD69C 0080A02D */  daddu     $s4, $a0, $zero
/* 323FF0 802BD6A0 AFB3002C */  sw        $s3, 0x2c($sp)
/* 323FF4 802BD6A4 3C138011 */  lui       $s3, %hi(gPlayerStatus)
/* 323FF8 802BD6A8 2673EFC8 */  addiu     $s3, $s3, %lo(gPlayerStatus)
/* 323FFC 802BD6AC AFB50034 */  sw        $s5, 0x34($sp)
/* 324000 802BD6B0 3C158011 */  lui       $s5, %hi(D_8010EBB0)
/* 324004 802BD6B4 26B5EBB0 */  addiu     $s5, $s5, %lo(D_8010EBB0)
/* 324008 802BD6B8 AFB10024 */  sw        $s1, 0x24($sp)
/* 32400C 802BD6BC 3C118016 */  lui       $s1, %hi(gCollisionStatus)
/* 324010 802BD6C0 2631A550 */  addiu     $s1, $s1, %lo(gCollisionStatus)
/* 324014 802BD6C4 AFBF0038 */  sw        $ra, 0x38($sp)
/* 324018 802BD6C8 AFB20028 */  sw        $s2, 0x28($sp)
/* 32401C 802BD6CC AFB00020 */  sw        $s0, 0x20($sp)
/* 324020 802BD6D0 F7B40040 */  sdc1      $f20, 0x40($sp)
/* 324024 802BD6D4 10A0001C */  beqz      $a1, .L802BD748
/* 324028 802BD6D8 8E92014C */   lw       $s2, 0x14c($s4)
/* 32402C 802BD6DC 0C0AF53F */  jal       func_802BD4FC_323E4C
/* 324030 802BD6E0 0240202D */   daddu    $a0, $s2, $zero
/* 324034 802BD6E4 8E620004 */  lw        $v0, 4($s3)
/* 324038 802BD6E8 3C030010 */  lui       $v1, 0x10
/* 32403C 802BD6EC 00431024 */  and       $v0, $v0, $v1
/* 324040 802BD6F0 144001B5 */  bnez      $v0, .L802BDDC8
/* 324044 802BD6F4 24020002 */   addiu    $v0, $zero, 2
/* 324048 802BD6F8 0C03A94B */  jal       func_800EA52C
/* 32404C 802BD6FC 24040009 */   addiu    $a0, $zero, 9
/* 324050 802BD700 1040001C */  beqz      $v0, .L802BD774
/* 324054 802BD704 3C020020 */   lui      $v0, 0x20
/* 324058 802BD708 8E630004 */  lw        $v1, 4($s3)
/* 32405C 802BD70C 00621024 */  and       $v0, $v1, $v0
/* 324060 802BD710 1040000B */  beqz      $v0, .L802BD740
/* 324064 802BD714 3C02FFDF */   lui      $v0, 0xffdf
/* 324068 802BD718 3442FFFF */  ori       $v0, $v0, 0xffff
/* 32406C 802BD71C 00621024 */  and       $v0, $v1, $v0
/* 324070 802BD720 0C03805E */  jal       disable_player_input
/* 324074 802BD724 AE620004 */   sw       $v0, 4($s3)
/* 324078 802BD728 AE820078 */  sw        $v0, 0x78($s4)
/* 32407C 802BD72C 24020001 */  addiu     $v0, $zero, 1
/* 324080 802BD730 3C01802C */  lui       $at, %hi(D_802BE0C4)
/* 324084 802BD734 AC22E0C4 */  sw        $v0, %lo(D_802BE0C4)($at)
/* 324088 802BD738 080AF5D1 */  j         .L802BD744
/* 32408C 802BD73C 24020014 */   addiu    $v0, $zero, 0x14
.L802BD740:
/* 324090 802BD740 24020028 */  addiu     $v0, $zero, 0x28
.L802BD744:
/* 324094 802BD744 AE820070 */  sw        $v0, 0x70($s4)
.L802BD748:
/* 324098 802BD748 8E830070 */  lw        $v1, 0x70($s4)
/* 32409C 802BD74C 24020028 */  addiu     $v0, $zero, 0x28
/* 3240A0 802BD750 10620005 */  beq       $v1, $v0, .L802BD768
/* 3240A4 802BD754 24020029 */   addiu    $v0, $zero, 0x29
/* 3240A8 802BD758 10620015 */  beq       $v1, $v0, .L802BD7B0
/* 3240AC 802BD75C 00000000 */   nop
/* 3240B0 802BD760 080AF61B */  j         .L802BD86C
/* 3240B4 802BD764 00000000 */   nop
.L802BD768:
/* 3240B8 802BD768 82620015 */  lb        $v0, 0x15($s3)
/* 3240BC 802BD76C 10400003 */  beqz      $v0, .L802BD77C
/* 3240C0 802BD770 00000000 */   nop
.L802BD774:
/* 3240C4 802BD774 080AF772 */  j         .L802BDDC8
/* 3240C8 802BD778 24020002 */   addiu    $v0, $zero, 2
.L802BD77C:
/* 3240CC 802BD77C 8E620000 */  lw        $v0, ($s3)
/* 3240D0 802BD780 34420100 */  ori       $v0, $v0, 0x100
/* 3240D4 802BD784 AE620000 */  sw        $v0, ($s3)
/* 3240D8 802BD788 24020003 */  addiu     $v0, $zero, 3
/* 3240DC 802BD78C 0C03805E */  jal       disable_player_input
/* 3240E0 802BD790 AE820074 */   sw       $v0, 0x74($s4)
/* 3240E4 802BD794 AE820078 */  sw        $v0, 0x78($s4)
/* 3240E8 802BD798 8E820070 */  lw        $v0, 0x70($s4)
/* 3240EC 802BD79C 24030001 */  addiu     $v1, $zero, 1
/* 3240F0 802BD7A0 3C01802C */  lui       $at, %hi(D_802BE0C4)
/* 3240F4 802BD7A4 AC23E0C4 */  sw        $v1, %lo(D_802BE0C4)($at)
/* 3240F8 802BD7A8 080AF61A */  j         .L802BD868
/* 3240FC 802BD7AC 00431021 */   addu     $v0, $v0, $v1
.L802BD7B0:
/* 324100 802BD7B0 0C03A94B */  jal       func_800EA52C
/* 324104 802BD7B4 24040009 */   addiu    $a0, $zero, 9
/* 324108 802BD7B8 10400005 */  beqz      $v0, .L802BD7D0
/* 32410C 802BD7BC 00000000 */   nop
/* 324110 802BD7C0 0C011052 */  jal       is_starting_conversation
/* 324114 802BD7C4 00000000 */   nop
/* 324118 802BD7C8 10400010 */  beqz      $v0, .L802BD80C
/* 32411C 802BD7CC 00000000 */   nop
.L802BD7D0:
/* 324120 802BD7D0 82630015 */  lb        $v1, 0x15($s3)
/* 324124 802BD7D4 8E820078 */  lw        $v0, 0x78($s4)
/* 324128 802BD7D8 0043102A */  slt       $v0, $v0, $v1
/* 32412C 802BD7DC 1040000B */  beqz      $v0, .L802BD80C
/* 324130 802BD7E0 00000000 */   nop
/* 324134 802BD7E4 3C10802C */  lui       $s0, %hi(D_802BE0C4)
/* 324138 802BD7E8 2610E0C4 */  addiu     $s0, $s0, %lo(D_802BE0C4)
/* 32413C 802BD7EC 8E020000 */  lw        $v0, ($s0)
/* 324140 802BD7F0 10400006 */  beqz      $v0, .L802BD80C
/* 324144 802BD7F4 00000000 */   nop
/* 324148 802BD7F8 0C038069 */  jal       enable_player_input
/* 32414C 802BD7FC 00000000 */   nop
/* 324150 802BD800 24020002 */  addiu     $v0, $zero, 2
/* 324154 802BD804 080AF615 */  j         .L802BD854
/* 324158 802BD808 AE000000 */   sw       $zero, ($s0)
.L802BD80C:
/* 32415C 802BD80C 8E820074 */  lw        $v0, 0x74($s4)
/* 324160 802BD810 2442FFFF */  addiu     $v0, $v0, -1
/* 324164 802BD814 14400015 */  bnez      $v0, .L802BD86C
/* 324168 802BD818 AE820074 */   sw       $v0, 0x74($s4)
/* 32416C 802BD81C 82630015 */  lb        $v1, 0x15($s3)
/* 324170 802BD820 8E820078 */  lw        $v0, 0x78($s4)
/* 324174 802BD824 0043102A */  slt       $v0, $v0, $v1
/* 324178 802BD828 1040000F */  beqz      $v0, .L802BD868
/* 32417C 802BD82C 24020014 */   addiu    $v0, $zero, 0x14
/* 324180 802BD830 3C10802C */  lui       $s0, %hi(D_802BE0C4)
/* 324184 802BD834 2610E0C4 */  addiu     $s0, $s0, %lo(D_802BE0C4)
/* 324188 802BD838 8E020000 */  lw        $v0, ($s0)
/* 32418C 802BD83C 10400005 */  beqz      $v0, .L802BD854
/* 324190 802BD840 24020002 */   addiu    $v0, $zero, 2
/* 324194 802BD844 0C038069 */  jal       enable_player_input
/* 324198 802BD848 00000000 */   nop
/* 32419C 802BD84C AE000000 */  sw        $zero, ($s0)
/* 3241A0 802BD850 24020002 */  addiu     $v0, $zero, 2
.L802BD854:
/* 3241A4 802BD854 8E630000 */  lw        $v1, ($s3)
/* 3241A8 802BD858 2404FEFF */  addiu     $a0, $zero, -0x101
/* 3241AC 802BD85C 00641824 */  and       $v1, $v1, $a0
/* 3241B0 802BD860 080AF772 */  j         .L802BDDC8
/* 3241B4 802BD864 AE630000 */   sw       $v1, ($s3)
.L802BD868:
/* 3241B8 802BD868 AE820070 */  sw        $v0, 0x70($s4)
.L802BD86C:
/* 3241BC 802BD86C 8E820070 */  lw        $v0, 0x70($s4)
/* 3241C0 802BD870 2443FFFF */  addiu     $v1, $v0, -1
/* 3241C4 802BD874 2C620015 */  sltiu     $v0, $v1, 0x15
/* 3241C8 802BD878 10400152 */  beqz      $v0, L802BDDC4_324714
/* 3241CC 802BD87C 00031080 */   sll      $v0, $v1, 2
/* 3241D0 802BD880 3C01802C */  lui       $at, %hi(jtbl_802BE068_3249B8)
/* 3241D4 802BD884 00220821 */  addu      $at, $at, $v0
/* 3241D8 802BD888 8C22E068 */  lw        $v0, %lo(jtbl_802BE068_3249B8)($at)
/* 3241DC 802BD88C 00400008 */  jr        $v0
/* 3241E0 802BD890 00000000 */   nop
glabel L802BD894_3241E4
/* 3241E4 802BD894 8E640000 */  lw        $a0, ($s3)
/* 3241E8 802BD898 30820800 */  andi      $v0, $a0, 0x800
/* 3241EC 802BD89C 1040000B */  beqz      $v0, .L802BD8CC
/* 3241F0 802BD8A0 2402FEFF */   addiu    $v0, $zero, -0x101
/* 3241F4 802BD8A4 3C10802C */  lui       $s0, %hi(D_802BE0C4)
/* 3241F8 802BD8A8 2610E0C4 */  addiu     $s0, $s0, %lo(D_802BE0C4)
/* 3241FC 802BD8AC 8E030000 */  lw        $v1, ($s0)
/* 324200 802BD8B0 00821024 */  and       $v0, $a0, $v0
/* 324204 802BD8B4 1060FFAF */  beqz      $v1, .L802BD774
/* 324208 802BD8B8 AE620000 */   sw       $v0, ($s3)
/* 32420C 802BD8BC 0C038069 */  jal       enable_player_input
/* 324210 802BD8C0 00000000 */   nop
/* 324214 802BD8C4 080AF5DD */  j         .L802BD774
/* 324218 802BD8C8 AE000000 */   sw       $zero, ($s0)
.L802BD8CC:
/* 32421C 802BD8CC 8E820078 */  lw        $v0, 0x78($s4)
/* 324220 802BD8D0 10400003 */  beqz      $v0, .L802BD8E0
/* 324224 802BD8D4 24020001 */   addiu    $v0, $zero, 1
/* 324228 802BD8D8 3C01802C */  lui       $at, %hi(D_802BE0C4)
/* 32422C 802BD8DC AC22E0C4 */  sw        $v0, %lo(D_802BE0C4)($at)
.L802BD8E0:
/* 324230 802BD8E0 24040001 */  addiu     $a0, $zero, 1
/* 324234 802BD8E4 8E420000 */  lw        $v0, ($s2)
/* 324238 802BD8E8 2403F5FF */  addiu     $v1, $zero, -0xa01
/* 32423C 802BD8EC 3C01802C */  lui       $at, %hi(D_802BE0C0)
/* 324240 802BD8F0 AC24E0C0 */  sw        $a0, %lo(D_802BE0C0)($at)
/* 324244 802BD8F4 00431024 */  and       $v0, $v0, $v1
/* 324248 802BD8F8 AE420000 */  sw        $v0, ($s2)
/* 32424C 802BD8FC A2A40000 */  sb        $a0, ($s5)
/* 324250 802BD900 8E620000 */  lw        $v0, ($s3)
/* 324254 802BD904 24030009 */  addiu     $v1, $zero, 9
/* 324258 802BD908 A2A30003 */  sb        $v1, 3($s5)
/* 32425C 802BD90C 34428000 */  ori       $v0, $v0, 0x8000
/* 324260 802BD910 0C03BD38 */  jal       func_800EF4E0
/* 324264 802BD914 AE620000 */   sw       $v0, ($s3)
/* 324268 802BD918 C6600028 */  lwc1      $f0, 0x28($s3)
/* 32426C 802BD91C 26510060 */  addiu     $s1, $s2, 0x60
/* 324270 802BD920 E6400060 */  swc1      $f0, 0x60($s2)
/* 324274 802BD924 866200B0 */  lh        $v0, 0xb0($s3)
/* 324278 802BD928 3C013F00 */  lui       $at, 0x3f00
/* 32427C 802BD92C 4481A000 */  mtc1      $at, $f20
/* 324280 802BD930 44820000 */  mtc1      $v0, $f0
/* 324284 802BD934 00000000 */  nop
/* 324288 802BD938 46800020 */  cvt.s.w   $f0, $f0
/* 32428C 802BD93C 46140002 */  mul.s     $f0, $f0, $f20
/* 324290 802BD940 00000000 */  nop
/* 324294 802BD944 0220202D */  daddu     $a0, $s1, $zero
/* 324298 802BD948 26500068 */  addiu     $s0, $s2, 0x68
/* 32429C 802BD94C C662002C */  lwc1      $f2, 0x2c($s3)
/* 3242A0 802BD950 3C06C000 */  lui       $a2, 0xc000
/* 3242A4 802BD954 46001080 */  add.s     $f2, $f2, $f0
/* 3242A8 802BD958 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 3242AC 802BD95C 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 3242B0 802BD960 3C020005 */  lui       $v0, 5
/* 3242B4 802BD964 E6420064 */  swc1      $f2, 0x64($s2)
/* 3242B8 802BD968 C6600030 */  lwc1      $f0, 0x30($s3)
/* 3242BC 802BD96C 34420002 */  ori       $v0, $v0, 2
/* 3242C0 802BD970 AE420028 */  sw        $v0, 0x28($s2)
/* 3242C4 802BD974 00031080 */  sll       $v0, $v1, 2
/* 3242C8 802BD978 00431021 */  addu      $v0, $v0, $v1
/* 3242CC 802BD97C 00021080 */  sll       $v0, $v0, 2
/* 3242D0 802BD980 00431023 */  subu      $v0, $v0, $v1
/* 3242D4 802BD984 000218C0 */  sll       $v1, $v0, 3
/* 3242D8 802BD988 00431021 */  addu      $v0, $v0, $v1
/* 3242DC 802BD98C E6400068 */  swc1      $f0, 0x68($s2)
/* 3242E0 802BD990 C6600080 */  lwc1      $f0, 0x80($s3)
/* 3242E4 802BD994 000210C0 */  sll       $v0, $v0, 3
/* 3242E8 802BD998 E640000C */  swc1      $f0, 0xc($s2)
/* 3242EC 802BD99C 3C07800B */  lui       $a3, %hi(gCameras+0x6C)
/* 3242F0 802BD9A0 00E23821 */  addu      $a3, $a3, $v0
/* 3242F4 802BD9A4 8CE71DEC */  lw        $a3, %lo(gCameras+0x6C)($a3)
/* 3242F8 802BD9A8 0C00A7E7 */  jal       add_vec2D_polar
/* 3242FC 802BD9AC 0200282D */   daddu    $a1, $s0, $zero
/* 324300 802BD9B0 866200B2 */  lh        $v0, 0xb2($s3)
/* 324304 802BD9B4 44820000 */  mtc1      $v0, $f0
/* 324308 802BD9B8 00000000 */  nop
/* 32430C 802BD9BC 46800020 */  cvt.s.w   $f0, $f0
/* 324310 802BD9C0 46140002 */  mul.s     $f0, $f0, $f20
/* 324314 802BD9C4 00000000 */  nop
/* 324318 802BD9C8 0220202D */  daddu     $a0, $s1, $zero
/* 32431C 802BD9CC 8E47000C */  lw        $a3, 0xc($s2)
/* 324320 802BD9D0 44060000 */  mfc1      $a2, $f0
/* 324324 802BD9D4 0C00A7E7 */  jal       add_vec2D_polar
/* 324328 802BD9D8 0200282D */   daddu    $a1, $s0, $zero
/* 32432C 802BD9DC C64C0038 */  lwc1      $f12, 0x38($s2)
/* 324330 802BD9E0 C64E0040 */  lwc1      $f14, 0x40($s2)
/* 324334 802BD9E4 24020005 */  addiu     $v0, $zero, 5
/* 324338 802BD9E8 A642008E */  sh        $v0, 0x8e($s2)
/* 32433C 802BD9EC 8E660028 */  lw        $a2, 0x28($s3)
/* 324340 802BD9F0 0C00A720 */  jal       atan2
/* 324344 802BD9F4 8E670030 */   lw       $a3, 0x30($s3)
/* 324348 802BD9F8 24040021 */  addiu     $a0, $zero, 0x21
/* 32434C 802BD9FC 0C039769 */  jal       set_action_state
/* 324350 802BDA00 E640000C */   swc1     $f0, 0xc($s2)
/* 324354 802BDA04 3C040001 */  lui       $a0, 1
/* 324358 802BDA08 0C037FBF */  jal       func_800DFEFC
/* 32435C 802BDA0C 34840002 */   ori      $a0, $a0, 2
/* 324360 802BDA10 8E820070 */  lw        $v0, 0x70($s4)
/* 324364 802BDA14 24420001 */  addiu     $v0, $v0, 1
/* 324368 802BDA18 080AF771 */  j         L802BDDC4_324714
/* 32436C 802BDA1C AE820070 */   sw       $v0, 0x70($s4)
glabel L802BDA20_324370
/* 324370 802BDA20 86220002 */  lh        $v0, 2($s1)
/* 324374 802BDA24 04400092 */  bltz      $v0, .L802BDC70
/* 324378 802BDA28 3C030010 */   lui      $v1, 0x10
/* 32437C 802BDA2C 8E620004 */  lw        $v0, 4($s3)
/* 324380 802BDA30 00431024 */  and       $v0, $v0, $v1
/* 324384 802BDA34 1440008E */  bnez      $v0, .L802BDC70
/* 324388 802BDA38 00000000 */   nop
/* 32438C 802BDA3C C6600028 */  lwc1      $f0, 0x28($s3)
/* 324390 802BDA40 E6400060 */  swc1      $f0, 0x60($s2)
/* 324394 802BDA44 866200B0 */  lh        $v0, 0xb0($s3)
/* 324398 802BDA48 3C013F00 */  lui       $at, 0x3f00
/* 32439C 802BDA4C 44811000 */  mtc1      $at, $f2
/* 3243A0 802BDA50 44820000 */  mtc1      $v0, $f0
/* 3243A4 802BDA54 00000000 */  nop
/* 3243A8 802BDA58 46800020 */  cvt.s.w   $f0, $f0
/* 3243AC 802BDA5C 46020002 */  mul.s     $f0, $f0, $f2
/* 3243B0 802BDA60 00000000 */  nop
/* 3243B4 802BDA64 C64A0038 */  lwc1      $f10, 0x38($s2)
/* 3243B8 802BDA68 C648003C */  lwc1      $f8, 0x3c($s2)
/* 3243BC 802BDA6C C6420060 */  lwc1      $f2, 0x60($s2)
/* 3243C0 802BDA70 C6460040 */  lwc1      $f6, 0x40($s2)
/* 3243C4 802BDA74 460A1081 */  sub.s     $f2, $f2, $f10
/* 3243C8 802BDA78 C664002C */  lwc1      $f4, 0x2c($s3)
/* 3243CC 802BDA7C 8642008E */  lh        $v0, 0x8e($s2)
/* 3243D0 802BDA80 46002100 */  add.s     $f4, $f4, $f0
/* 3243D4 802BDA84 44820000 */  mtc1      $v0, $f0
/* 3243D8 802BDA88 00000000 */  nop
/* 3243DC 802BDA8C 46800020 */  cvt.s.w   $f0, $f0
/* 3243E0 802BDA90 46001083 */  div.s     $f2, $f2, $f0
/* 3243E4 802BDA94 46025280 */  add.s     $f10, $f10, $f2
/* 3243E8 802BDA98 E6440064 */  swc1      $f4, 0x64($s2)
/* 3243EC 802BDA9C 46002006 */  mov.s     $f0, $f4
/* 3243F0 802BDAA0 C6620030 */  lwc1      $f2, 0x30($s3)
/* 3243F4 802BDAA4 46080001 */  sub.s     $f0, $f0, $f8
/* 3243F8 802BDAA8 E6420068 */  swc1      $f2, 0x68($s2)
/* 3243FC 802BDAAC 46061081 */  sub.s     $f2, $f2, $f6
/* 324400 802BDAB0 44822000 */  mtc1      $v0, $f4
/* 324404 802BDAB4 00000000 */  nop
/* 324408 802BDAB8 46802120 */  cvt.s.w   $f4, $f4
/* 32440C 802BDABC 46040003 */  div.s     $f0, $f0, $f4
/* 324410 802BDAC0 46004200 */  add.s     $f8, $f8, $f0
/* 324414 802BDAC4 46002006 */  mov.s     $f0, $f4
/* 324418 802BDAC8 9642008E */  lhu       $v0, 0x8e($s2)
/* 32441C 802BDACC 46001083 */  div.s     $f2, $f2, $f0
/* 324420 802BDAD0 46023180 */  add.s     $f6, $f6, $f2
/* 324424 802BDAD4 E64A0038 */  swc1      $f10, 0x38($s2)
/* 324428 802BDAD8 E648003C */  swc1      $f8, 0x3c($s2)
/* 32442C 802BDADC E6460040 */  swc1      $f6, 0x40($s2)
/* 324430 802BDAE0 C6640028 */  lwc1      $f4, 0x28($s3)
/* 324434 802BDAE4 46005006 */  mov.s     $f0, $f10
/* 324438 802BDAE8 460A2101 */  sub.s     $f4, $f4, $f10
/* 32443C 802BDAEC C662002C */  lwc1      $f2, 0x2c($s3)
/* 324440 802BDAF0 46004006 */  mov.s     $f0, $f8
/* 324444 802BDAF4 46081081 */  sub.s     $f2, $f2, $f8
/* 324448 802BDAF8 C6600030 */  lwc1      $f0, 0x30($s3)
/* 32444C 802BDAFC 2442FFFF */  addiu     $v0, $v0, -1
/* 324450 802BDB00 A642008E */  sh        $v0, 0x8e($s2)
/* 324454 802BDB04 00021400 */  sll       $v0, $v0, 0x10
/* 324458 802BDB08 46060001 */  sub.s     $f0, $f0, $f6
/* 32445C 802BDB0C 4600240D */  trunc.w.s $f16, $f4
/* 324460 802BDB10 3C01802C */  lui       $at, %hi(D_802BE0E4)
/* 324464 802BDB14 E430E0E4 */  swc1      $f16, %lo(D_802BE0E4)($at)
/* 324468 802BDB18 4600140D */  trunc.w.s $f16, $f2
/* 32446C 802BDB1C 3C01802C */  lui       $at, %hi(D_802BE0E8)
/* 324470 802BDB20 E430E0E8 */  swc1      $f16, %lo(D_802BE0E8)($at)
/* 324474 802BDB24 4600040D */  trunc.w.s $f16, $f0
/* 324478 802BDB28 3C01802C */  lui       $at, %hi(D_802BE0EC)
/* 32447C 802BDB2C E430E0EC */  swc1      $f16, %lo(D_802BE0EC)($at)
/* 324480 802BDB30 144000A5 */  bnez      $v0, .L802BDDC8
/* 324484 802BDB34 0000102D */   daddu    $v0, $zero, $zero
/* 324488 802BDB38 0240202D */  daddu     $a0, $s2, $zero
/* 32448C 802BDB3C C6600080 */  lwc1      $f0, 0x80($s3)
/* 324490 802BDB40 24050007 */  addiu     $a1, $zero, 7
/* 324494 802BDB44 E480000C */  swc1      $f0, 0xc($a0)
/* 324498 802BDB48 9266000E */  lbu       $a2, 0xe($s3)
/* 32449C 802BDB4C 0000382D */  daddu     $a3, $zero, $zero
/* 3244A0 802BDB50 AFA00010 */  sw        $zero, 0x10($sp)
/* 3244A4 802BDB54 AFA00014 */  sw        $zero, 0x14($sp)
/* 3244A8 802BDB58 0C00F589 */  jal       func_8003D624
/* 3244AC 802BDB5C AFA00018 */   sw       $zero, 0x18($sp)
/* 3244B0 802BDB60 3C040001 */  lui       $a0, 1
/* 3244B4 802BDB64 0C037FDE */  jal       func_800DFF78
/* 3244B8 802BDB68 34840014 */   ori      $a0, $a0, 0x14
/* 3244BC 802BDB6C 2404200E */  addiu     $a0, $zero, 0x200e
/* 3244C0 802BDB70 0000282D */  daddu     $a1, $zero, $zero
/* 3244C4 802BDB74 0C052742 */  jal       play_sound_at_npc
/* 3244C8 802BDB78 2406FFFC */   addiu    $a2, $zero, -4
/* 3244CC 802BDB7C 24020001 */  addiu     $v0, $zero, 1
/* 3244D0 802BDB80 080AF771 */  j         L802BDDC4_324714
/* 3244D4 802BDB84 AE820070 */   sw       $v0, 0x70($s4)
glabel L802BDB88_3244D8
/* 3244D8 802BDB88 86220002 */  lh        $v0, 2($s1)
/* 3244DC 802BDB8C 04400038 */  bltz      $v0, .L802BDC70
/* 3244E0 802BDB90 00000000 */   nop
/* 3244E4 802BDB94 9262000E */  lbu       $v0, 0xe($s3)
/* 3244E8 802BDB98 2442FFF8 */  addiu     $v0, $v0, -8
/* 3244EC 802BDB9C A262000E */  sb        $v0, 0xe($s3)
/* 3244F0 802BDBA0 304200FF */  andi      $v0, $v0, 0xff
/* 3244F4 802BDBA4 2C420081 */  sltiu     $v0, $v0, 0x81
/* 3244F8 802BDBA8 1040000E */  beqz      $v0, .L802BDBE4
/* 3244FC 802BDBAC 24020080 */   addiu    $v0, $zero, 0x80
/* 324500 802BDBB0 A262000E */  sb        $v0, 0xe($s3)
/* 324504 802BDBB4 24020016 */  addiu     $v0, $zero, 0x16
/* 324508 802BDBB8 A24200AA */  sb        $v0, 0xaa($s2)
/* 32450C 802BDBBC 8E820070 */  lw        $v0, 0x70($s4)
/* 324510 802BDBC0 24420001 */  addiu     $v0, $v0, 1
/* 324514 802BDBC4 AE820070 */  sw        $v0, 0x70($s4)
/* 324518 802BDBC8 8E620000 */  lw        $v0, ($s3)
/* 32451C 802BDBCC 2403FEFF */  addiu     $v1, $zero, -0x101
/* 324520 802BDBD0 00431024 */  and       $v0, $v0, $v1
/* 324524 802BDBD4 AE620000 */  sw        $v0, ($s3)
/* 324528 802BDBD8 8E420000 */  lw        $v0, ($s2)
/* 32452C 802BDBDC 34420040 */  ori       $v0, $v0, 0x40
/* 324530 802BDBE0 AE420000 */  sw        $v0, ($s2)
.L802BDBE4:
/* 324534 802BDBE4 0C044181 */  jal       get_shadow_by_index
/* 324538 802BDBE8 8E440078 */   lw       $a0, 0x78($s2)
/* 32453C 802BDBEC 0240202D */  daddu     $a0, $s2, $zero
/* 324540 802BDBF0 9263000E */  lbu       $v1, 0xe($s3)
/* 324544 802BDBF4 24050007 */  addiu     $a1, $zero, 7
/* 324548 802BDBF8 00031842 */  srl       $v1, $v1, 1
/* 32454C 802BDBFC A0430005 */  sb        $v1, 5($v0)
/* 324550 802BDC00 9266000E */  lbu       $a2, 0xe($s3)
/* 324554 802BDC04 0000382D */  daddu     $a3, $zero, $zero
/* 324558 802BDC08 AFA00010 */  sw        $zero, 0x10($sp)
/* 32455C 802BDC0C AFA00014 */  sw        $zero, 0x14($sp)
/* 324560 802BDC10 0C00F589 */  jal       func_8003D624
/* 324564 802BDC14 AFA00018 */   sw       $zero, 0x18($sp)
/* 324568 802BDC18 C6600028 */  lwc1      $f0, 0x28($s3)
/* 32456C 802BDC1C 3C01802C */  lui       $at, %hi(D_802BE0E4)
/* 324570 802BDC20 C422E0E4 */  lwc1      $f2, %lo(D_802BE0E4)($at)
/* 324574 802BDC24 468010A0 */  cvt.s.w   $f2, $f2
/* 324578 802BDC28 46020001 */  sub.s     $f0, $f0, $f2
/* 32457C 802BDC2C E6400038 */  swc1      $f0, 0x38($s2)
/* 324580 802BDC30 C660002C */  lwc1      $f0, 0x2c($s3)
/* 324584 802BDC34 3C01802C */  lui       $at, %hi(D_802BE0E8)
/* 324588 802BDC38 C422E0E8 */  lwc1      $f2, %lo(D_802BE0E8)($at)
/* 32458C 802BDC3C 468010A0 */  cvt.s.w   $f2, $f2
/* 324590 802BDC40 46020001 */  sub.s     $f0, $f0, $f2
/* 324594 802BDC44 E640003C */  swc1      $f0, 0x3c($s2)
/* 324598 802BDC48 C6600030 */  lwc1      $f0, 0x30($s3)
/* 32459C 802BDC4C 3C01802C */  lui       $at, %hi(D_802BE0EC)
/* 3245A0 802BDC50 C422E0EC */  lwc1      $f2, %lo(D_802BE0EC)($at)
/* 3245A4 802BDC54 468010A0 */  cvt.s.w   $f2, $f2
/* 3245A8 802BDC58 46020001 */  sub.s     $f0, $f0, $f2
/* 3245AC 802BDC5C 080AF771 */  j         L802BDDC4_324714
/* 3245B0 802BDC60 E6400040 */   swc1     $f0, 0x40($s2)
glabel L802BDC64_3245B4
/* 3245B4 802BDC64 86220002 */  lh        $v0, 2($s1)
/* 3245B8 802BDC68 04410005 */  bgez      $v0, .L802BDC80
/* 3245BC 802BDC6C 00000000 */   nop
.L802BDC70:
/* 3245C0 802BDC70 0C0AF77C */  jal       func_802BDDF0_324740
/* 3245C4 802BDC74 0240202D */   daddu    $a0, $s2, $zero
/* 3245C8 802BDC78 080AF772 */  j         .L802BDDC8
/* 3245CC 802BDC7C 24020002 */   addiu    $v0, $zero, 2
.L802BDC80:
/* 3245D0 802BDC80 C6600028 */  lwc1      $f0, 0x28($s3)
/* 3245D4 802BDC84 3C01802C */  lui       $at, %hi(D_802BE0E4)
/* 3245D8 802BDC88 C422E0E4 */  lwc1      $f2, %lo(D_802BE0E4)($at)
/* 3245DC 802BDC8C 468010A0 */  cvt.s.w   $f2, $f2
/* 3245E0 802BDC90 46020001 */  sub.s     $f0, $f0, $f2
/* 3245E4 802BDC94 E6400038 */  swc1      $f0, 0x38($s2)
/* 3245E8 802BDC98 C660002C */  lwc1      $f0, 0x2c($s3)
/* 3245EC 802BDC9C 3C01802C */  lui       $at, %hi(D_802BE0E8)
/* 3245F0 802BDCA0 C422E0E8 */  lwc1      $f2, %lo(D_802BE0E8)($at)
/* 3245F4 802BDCA4 468010A0 */  cvt.s.w   $f2, $f2
/* 3245F8 802BDCA8 46020001 */  sub.s     $f0, $f0, $f2
/* 3245FC 802BDCAC E640003C */  swc1      $f0, 0x3c($s2)
/* 324600 802BDCB0 C6600030 */  lwc1      $f0, 0x30($s3)
/* 324604 802BDCB4 3C01802C */  lui       $at, %hi(D_802BE0EC)
/* 324608 802BDCB8 C422E0EC */  lwc1      $f2, %lo(D_802BE0EC)($at)
/* 32460C 802BDCBC 468010A0 */  cvt.s.w   $f2, $f2
/* 324610 802BDCC0 46020001 */  sub.s     $f0, $f0, $f2
/* 324614 802BDCC4 44806000 */  mtc1      $zero, $f12
/* 324618 802BDCC8 E6400040 */  swc1      $f0, 0x40($s2)
/* 32461C 802BDCCC 86A20004 */  lh        $v0, 4($s5)
/* 324620 802BDCD0 86A30006 */  lh        $v1, 6($s5)
/* 324624 802BDCD4 44828000 */  mtc1      $v0, $f16
/* 324628 802BDCD8 00000000 */  nop
/* 32462C 802BDCDC 46808420 */  cvt.s.w   $f16, $f16
/* 324630 802BDCE0 44068000 */  mfc1      $a2, $f16
/* 324634 802BDCE4 44838000 */  mtc1      $v1, $f16
/* 324638 802BDCE8 00000000 */  nop
/* 32463C 802BDCEC 46808420 */  cvt.s.w   $f16, $f16
/* 324640 802BDCF0 44078000 */  mfc1      $a3, $f16
/* 324644 802BDCF4 0C00A7B5 */  jal       dist2D
/* 324648 802BDCF8 46006386 */   mov.s    $f14, $f12
/* 32464C 802BDCFC 86220002 */  lh        $v0, 2($s1)
/* 324650 802BDD00 04400010 */  bltz      $v0, .L802BDD44
/* 324654 802BDD04 46000086 */   mov.s    $f2, $f0
/* 324658 802BDD08 3C014120 */  lui       $at, 0x4120
/* 32465C 802BDD0C 44810000 */  mtc1      $at, $f0
/* 324660 802BDD10 00000000 */  nop
/* 324664 802BDD14 4602003C */  c.lt.s    $f0, $f2
/* 324668 802BDD18 00000000 */  nop
/* 32466C 802BDD1C 45010009 */  bc1t      .L802BDD44
/* 324670 802BDD20 00000000 */   nop
/* 324674 802BDD24 8EA2000C */  lw        $v0, 0xc($s5)
/* 324678 802BDD28 30424004 */  andi      $v0, $v0, 0x4004
/* 32467C 802BDD2C 14400005 */  bnez      $v0, .L802BDD44
/* 324680 802BDD30 00000000 */   nop
/* 324684 802BDD34 8E620000 */  lw        $v0, ($s3)
/* 324688 802BDD38 30420800 */  andi      $v0, $v0, 0x800
/* 32468C 802BDD3C 10400022 */  beqz      $v0, .L802BDDC8
/* 324690 802BDD40 0000102D */   daddu    $v0, $zero, $zero
.L802BDD44:
/* 324694 802BDD44 0C0AF550 */  jal       func_802BD540_323E90
/* 324698 802BDD48 00000000 */   nop
/* 32469C 802BDD4C 0441001E */  bgez      $v0, .L802BDDC8
/* 3246A0 802BDD50 0000102D */   daddu    $v0, $zero, $zero
/* 3246A4 802BDD54 8E820070 */  lw        $v0, 0x70($s4)
/* 3246A8 802BDD58 24030003 */  addiu     $v1, $zero, 3
/* 3246AC 802BDD5C AE830074 */  sw        $v1, 0x74($s4)
/* 3246B0 802BDD60 24420001 */  addiu     $v0, $v0, 1
/* 3246B4 802BDD64 AE820070 */  sw        $v0, 0x70($s4)
/* 3246B8 802BDD68 82620015 */  lb        $v0, 0x15($s3)
/* 3246BC 802BDD6C 080AF771 */  j         L802BDDC4_324714
/* 3246C0 802BDD70 AE820078 */   sw       $v0, 0x78($s4)
glabel L802BDD74_3246C4
/* 3246C4 802BDD74 8E820074 */  lw        $v0, 0x74($s4)
/* 3246C8 802BDD78 14400008 */  bnez      $v0, .L802BDD9C
/* 3246CC 802BDD7C 2442FFFF */   addiu    $v0, $v0, -1
/* 3246D0 802BDD80 82630015 */  lb        $v1, 0x15($s3)
/* 3246D4 802BDD84 8E820078 */  lw        $v0, 0x78($s4)
/* 3246D8 802BDD88 0043102A */  slt       $v0, $v0, $v1
/* 3246DC 802BDD8C 10400005 */  beqz      $v0, .L802BDDA4
/* 3246E0 802BDD90 24020002 */   addiu    $v0, $zero, 2
/* 3246E4 802BDD94 080AF771 */  j         L802BDDC4_324714
/* 3246E8 802BDD98 AE820070 */   sw       $v0, 0x70($s4)
.L802BDD9C:
/* 3246EC 802BDD9C 080AF771 */  j         L802BDDC4_324714
/* 3246F0 802BDDA0 AE820074 */   sw       $v0, 0x74($s4)
.L802BDDA4:
/* 3246F4 802BDDA4 2404200F */  addiu     $a0, $zero, 0x200f
/* 3246F8 802BDDA8 0000282D */  daddu     $a1, $zero, $zero
/* 3246FC 802BDDAC 0C052742 */  jal       play_sound_at_npc
/* 324700 802BDDB0 2406FFFC */   addiu    $a2, $zero, -4
/* 324704 802BDDB4 0C0AF77C */  jal       func_802BDDF0_324740
/* 324708 802BDDB8 0240202D */   daddu    $a0, $s2, $zero
/* 32470C 802BDDBC 080AF772 */  j         .L802BDDC8
/* 324710 802BDDC0 24020001 */   addiu    $v0, $zero, 1
glabel L802BDDC4_324714
/* 324714 802BDDC4 0000102D */  daddu     $v0, $zero, $zero
.L802BDDC8:
/* 324718 802BDDC8 8FBF0038 */  lw        $ra, 0x38($sp)
/* 32471C 802BDDCC 8FB50034 */  lw        $s5, 0x34($sp)
/* 324720 802BDDD0 8FB40030 */  lw        $s4, 0x30($sp)
/* 324724 802BDDD4 8FB3002C */  lw        $s3, 0x2c($sp)
/* 324728 802BDDD8 8FB20028 */  lw        $s2, 0x28($sp)
/* 32472C 802BDDDC 8FB10024 */  lw        $s1, 0x24($sp)
/* 324730 802BDDE0 8FB00020 */  lw        $s0, 0x20($sp)
/* 324734 802BDDE4 D7B40040 */  ldc1      $f20, 0x40($sp)
/* 324738 802BDDE8 03E00008 */  jr        $ra
/* 32473C 802BDDEC 27BD0048 */   addiu    $sp, $sp, 0x48
