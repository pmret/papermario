.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel update_targeting_enemies
/* 41F418 802AA688 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 41F41C 802AA68C AFB40020 */  sw        $s4, 0x20($sp)
/* 41F420 802AA690 3C14800E */  lui       $s4, 0x800e
/* 41F424 802AA694 2694C070 */  addiu     $s4, $s4, -0x3f90
/* 41F428 802AA698 AFBF0028 */  sw        $ra, 0x28($sp)
/* 41F42C 802AA69C AFB50024 */  sw        $s5, 0x24($sp)
/* 41F430 802AA6A0 AFB3001C */  sw        $s3, 0x1c($sp)
/* 41F434 802AA6A4 AFB20018 */  sw        $s2, 0x18($sp)
/* 41F438 802AA6A8 AFB10014 */  sw        $s1, 0x14($sp)
/* 41F43C 802AA6AC AFB00010 */  sw        $s0, 0x10($sp)
/* 41F440 802AA6B0 8E820000 */  lw        $v0, ($s4)
/* 41F444 802AA6B4 3C030008 */  lui       $v1, 8
/* 41F448 802AA6B8 00431024 */  and       $v0, $v0, $v1
/* 41F44C 802AA6BC 14400004 */  bnez      $v0, .L802AA6D0
/* 41F450 802AA6C0 3C02F7FF */   lui      $v0, 0xf7ff
/* 41F454 802AA6C4 8E9200D8 */  lw        $s2, 0xd8($s4)
/* 41F458 802AA6C8 080AA9B6 */  j         .L802AA6D8
/* 41F45C 802AA6CC 3442FFFF */   ori      $v0, $v0, 0xffff
.L802AA6D0:
/* 41F460 802AA6D0 8E9200DC */  lw        $s2, 0xdc($s4)
/* 41F464 802AA6D4 3442FFFF */  ori       $v0, $v0, 0xffff
.L802AA6D8:
/* 41F468 802AA6D8 8253040C */  lb        $s3, 0x40c($s2)
/* 41F46C 802AA6DC 8E430000 */  lw        $v1, ($s2)
/* 41F470 802AA6E0 82500425 */  lb        $s0, 0x425($s2)
/* 41F474 802AA6E4 00621824 */  and       $v1, $v1, $v0
/* 41F478 802AA6E8 AE430000 */  sw        $v1, ($s2)
/* 41F47C 802AA6EC 3C03800E */  lui       $v1, 0x800e
/* 41F480 802AA6F0 8C63C4DC */  lw        $v1, -0x3b24($v1)
/* 41F484 802AA6F4 24020001 */  addiu     $v0, $zero, 1
/* 41F488 802AA6F8 10620085 */  beq       $v1, $v0, .L802AA910
/* 41F48C 802AA6FC 2655040D */   addiu    $s5, $s2, 0x40d
/* 41F490 802AA700 28620002 */  slti      $v0, $v1, 2
/* 41F494 802AA704 50400005 */  beql      $v0, $zero, .L802AA71C
/* 41F498 802AA708 24020002 */   addiu    $v0, $zero, 2
/* 41F49C 802AA70C 10600009 */  beqz      $v1, .L802AA734
/* 41F4A0 802AA710 24040015 */   addiu    $a0, $zero, 0x15
/* 41F4A4 802AA714 080AAB2D */  j         .L802AACB4
/* 41F4A8 802AA718 00000000 */   nop      
.L802AA71C:
/* 41F4AC 802AA71C 106200D7 */  beq       $v1, $v0, .L802AAA7C
/* 41F4B0 802AA720 2402000A */   addiu    $v0, $zero, 0xa
/* 41F4B4 802AA724 1062011B */  beq       $v1, $v0, .L802AAB94
/* 41F4B8 802AA728 00000000 */   nop      
/* 41F4BC 802AA72C 080AAB2D */  j         .L802AACB4
/* 41F4C0 802AA730 00000000 */   nop      
.L802AA734:
/* 41F4C4 802AA734 240200FF */  addiu     $v0, $zero, 0xff
/* 41F4C8 802AA738 3C01802B */  lui       $at, 0x802b
/* 41F4CC 802AA73C AC22CC64 */  sw        $v0, -0x339c($at)
/* 41F4D0 802AA740 2402FF9C */  addiu     $v0, $zero, -0x64
/* 41F4D4 802AA744 3C10800E */  lui       $s0, 0x800e
/* 41F4D8 802AA748 2610C070 */  addiu     $s0, $s0, -0x3f90
/* 41F4DC 802AA74C 3C01802B */  lui       $at, 0x802b
/* 41F4E0 802AA750 AC22CC68 */  sw        $v0, -0x3398($at)
/* 41F4E4 802AA754 8E020000 */  lw        $v0, ($s0)
/* 41F4E8 802AA758 2403FFFD */  addiu     $v1, $zero, -3
/* 41F4EC 802AA75C 00431024 */  and       $v0, $v0, $v1
/* 41F4F0 802AA760 0C03A752 */  jal       is_ability_active
/* 41F4F4 802AA764 AE020000 */   sw       $v0, ($s0)
/* 41F4F8 802AA768 10400005 */  beqz      $v0, .L802AA780
/* 41F4FC 802AA76C 3C030008 */   lui      $v1, 8
/* 41F500 802AA770 8E020000 */  lw        $v0, ($s0)
/* 41F504 802AA774 00431024 */  and       $v0, $v0, $v1
/* 41F508 802AA778 1040000D */  beqz      $v0, .L802AA7B0
/* 41F50C 802AA77C 00000000 */   nop      
.L802AA780:
/* 41F510 802AA780 8683017C */  lh        $v1, 0x17c($s4)
/* 41F514 802AA784 1060000A */  beqz      $v1, .L802AA7B0
/* 41F518 802AA788 00031080 */   sll      $v0, $v1, 2
/* 41F51C 802AA78C 00431021 */  addu      $v0, $v0, $v1
/* 41F520 802AA790 00021080 */  sll       $v0, $v0, 2
/* 41F524 802AA794 3C048009 */  lui       $a0, 0x8009
/* 41F528 802AA798 00822021 */  addu      $a0, $a0, $v0
/* 41F52C 802AA79C 8084F073 */  lb        $a0, -0xf8d($a0)
/* 41F530 802AA7A0 04800003 */  bltz      $a0, .L802AA7B0
/* 41F534 802AA7A4 2484002E */   addiu    $a0, $a0, 0x2e
/* 41F538 802AA7A8 0C093E58 */  jal       show_battle_message
/* 41F53C 802AA7AC 2405003C */   addiu    $a1, $zero, 0x3c
.L802AA7B0:
/* 41F540 802AA7B0 0C098C0B */  jal       player_create_target_list
/* 41F544 802AA7B4 0240202D */   daddu    $a0, $s2, $zero
/* 41F548 802AA7B8 8E820184 */  lw        $v0, 0x184($s4)
/* 41F54C 802AA7BC 8253040C */  lb        $s3, 0x40c($s2)
/* 41F550 802AA7C0 30420001 */  andi      $v0, $v0, 1
/* 41F554 802AA7C4 10400018 */  beqz      $v0, .L802AA828
/* 41F558 802AA7C8 00000000 */   nop      
/* 41F55C 802AA7CC 2655040D */  addiu     $s5, $s2, 0x40d
/* 41F560 802AA7D0 1A600015 */  blez      $s3, .L802AA828
/* 41F564 802AA7D4 0000802D */   daddu    $s0, $zero, $zero
/* 41F568 802AA7D8 02B01021 */  addu      $v0, $s5, $s0
.L802AA7DC:
/* 41F56C 802AA7DC 80430000 */  lb        $v1, ($v0)
/* 41F570 802AA7E0 00031080 */  sll       $v0, $v1, 2
/* 41F574 802AA7E4 00431021 */  addu      $v0, $v0, $v1
/* 41F578 802AA7E8 00021080 */  sll       $v0, $v0, 2
/* 41F57C 802AA7EC 2442022C */  addiu     $v0, $v0, 0x22c
/* 41F580 802AA7F0 02428821 */  addu      $s1, $s2, $v0
/* 41F584 802AA7F4 0C09A75B */  jal       get_actor
/* 41F588 802AA7F8 86240000 */   lh       $a0, ($s1)
/* 41F58C 802AA7FC 86250002 */  lh        $a1, 2($s1)
/* 41F590 802AA800 0C099117 */  jal       get_actor_part
/* 41F594 802AA804 0040202D */   daddu    $a0, $v0, $zero
/* 41F598 802AA808 8C420000 */  lw        $v0, ($v0)
/* 41F59C 802AA80C 30420008 */  andi      $v0, $v0, 8
/* 41F5A0 802AA810 54400005 */  bnel      $v0, $zero, .L802AA828
/* 41F5A4 802AA814 A2500425 */   sb       $s0, 0x425($s2)
/* 41F5A8 802AA818 26100001 */  addiu     $s0, $s0, 1
/* 41F5AC 802AA81C 0213102A */  slt       $v0, $s0, $s3
/* 41F5B0 802AA820 1440FFEE */  bnez      $v0, .L802AA7DC
/* 41F5B4 802AA824 02B01021 */   addu     $v0, $s5, $s0
.L802AA828:
/* 41F5B8 802AA828 8E820184 */  lw        $v0, 0x184($s4)
/* 41F5BC 802AA82C 04410015 */  bgez      $v0, .L802AA884
/* 41F5C0 802AA830 3C030008 */   lui      $v1, 8
/* 41F5C4 802AA834 3C04800E */  lui       $a0, 0x800e
/* 41F5C8 802AA838 2484C070 */  addiu     $a0, $a0, -0x3f90
/* 41F5CC 802AA83C 8C820000 */  lw        $v0, ($a0)
/* 41F5D0 802AA840 00431024 */  and       $v0, $v0, $v1
/* 41F5D4 802AA844 14400006 */  bnez      $v0, .L802AA860
/* 41F5D8 802AA848 00000000 */   nop      
.L802AA84C:
/* 41F5DC 802AA84C 8683006E */  lh        $v1, 0x6e($s4)
/* 41F5E0 802AA850 3C01800E */  lui       $at, 0x800e
/* 41F5E4 802AA854 AC23C4DC */  sw        $v1, -0x3b24($at)
/* 41F5E8 802AA858 080AAACE */  j         .L802AAB38
/* 41F5EC 802AA85C 00000000 */   nop      
.L802AA860:
/* 41F5F0 802AA860 8C820004 */  lw        $v0, 4($a0)
/* 41F5F4 802AA864 8683006E */  lh        $v1, 0x6e($s4)
/* 41F5F8 802AA868 30420040 */  andi      $v0, $v0, 0x40
/* 41F5FC 802AA86C 3C01800E */  lui       $at, 0x800e
/* 41F600 802AA870 AC23C4DC */  sw        $v1, -0x3b24($at)
/* 41F604 802AA874 104000C1 */  beqz      $v0, .L802AAB7C
/* 41F608 802AA878 00000000 */   nop      
/* 41F60C 802AA87C 080AAADB */  j         .L802AAB6C
/* 41F610 802AA880 00000000 */   nop      
.L802AA884:
/* 41F614 802AA884 16600009 */  bnez      $s3, .L802AA8AC
/* 41F618 802AA888 00000000 */   nop      
/* 41F61C 802AA88C 3C04800E */  lui       $a0, 0x800e
/* 41F620 802AA890 2484C070 */  addiu     $a0, $a0, -0x3f90
/* 41F624 802AA894 8C820000 */  lw        $v0, ($a0)
/* 41F628 802AA898 00431024 */  and       $v0, $v0, $v1
/* 41F62C 802AA89C 1040FFEB */  beqz      $v0, .L802AA84C
/* 41F630 802AA8A0 00000000 */   nop      
/* 41F634 802AA8A4 080AAA18 */  j         .L802AA860
/* 41F638 802AA8A8 00000000 */   nop      
.L802AA8AC:
/* 41F63C 802AA8AC 1A600013 */  blez      $s3, .L802AA8FC
/* 41F640 802AA8B0 0000802D */   daddu    $s0, $zero, $zero
/* 41F644 802AA8B4 3C12802B */  lui       $s2, 0x802b
/* 41F648 802AA8B8 2652CC70 */  addiu     $s2, $s2, -0x3390
.L802AA8BC:
/* 41F64C 802AA8BC 3C048008 */  lui       $a0, 0x8008
/* 41F650 802AA8C0 2484FF20 */  addiu     $a0, $a0, -0xe0
/* 41F654 802AA8C4 0C050529 */  jal       create_icon
/* 41F658 802AA8C8 26100001 */   addiu    $s0, $s0, 1
/* 41F65C 802AA8CC 0040882D */  daddu     $s1, $v0, $zero
/* 41F660 802AA8D0 AE510000 */  sw        $s1, ($s2)
/* 41F664 802AA8D4 0220202D */  daddu     $a0, $s1, $zero
/* 41F668 802AA8D8 0C051277 */  jal       func_801449DC
/* 41F66C 802AA8DC 0000282D */   daddu    $a1, $zero, $zero
/* 41F670 802AA8E0 0220202D */  daddu     $a0, $s1, $zero
/* 41F674 802AA8E4 0000282D */  daddu     $a1, $zero, $zero
/* 41F678 802AA8E8 0C051261 */  jal       set_icon_render_pos
/* 41F67C 802AA8EC 2406FF9C */   addiu    $a2, $zero, -0x64
/* 41F680 802AA8F0 0213102A */  slt       $v0, $s0, $s3
/* 41F684 802AA8F4 1440FFF1 */  bnez      $v0, .L802AA8BC
/* 41F688 802AA8F8 26520004 */   addiu    $s2, $s2, 4
.L802AA8FC:
/* 41F68C 802AA8FC 24020001 */  addiu     $v0, $zero, 1
/* 41F690 802AA900 3C01800E */  lui       $at, 0x800e
/* 41F694 802AA904 AC22C4DC */  sw        $v0, -0x3b24($at)
/* 41F698 802AA908 080AAB2D */  j         .L802AACB4
/* 41F69C 802AA90C 00000000 */   nop      
.L802AA910:
/* 41F6A0 802AA910 3C03802B */  lui       $v1, 0x802b
/* 41F6A4 802AA914 2463CC68 */  addiu     $v1, $v1, -0x3398
/* 41F6A8 802AA918 8C620000 */  lw        $v0, ($v1)
/* 41F6AC 802AA91C 04410004 */  bgez      $v0, .L802AA930
/* 41F6B0 802AA920 24420014 */   addiu    $v0, $v0, 0x14
/* 41F6B4 802AA924 18400002 */  blez      $v0, .L802AA930
/* 41F6B8 802AA928 AC620000 */   sw       $v0, ($v1)
/* 41F6BC 802AA92C AC600000 */  sw        $zero, ($v1)
.L802AA930:
/* 41F6C0 802AA930 8E830214 */  lw        $v1, 0x214($s4)
/* 41F6C4 802AA934 30624000 */  andi      $v0, $v1, 0x4000
/* 41F6C8 802AA938 10400008 */  beqz      $v0, .L802AA95C
/* 41F6CC 802AA93C 30628000 */   andi     $v0, $v1, 0x8000
/* 41F6D0 802AA940 0C05272D */  jal       play_sound
/* 41F6D4 802AA944 240400CA */   addiu    $a0, $zero, 0xca
/* 41F6D8 802AA948 2402000A */  addiu     $v0, $zero, 0xa
/* 41F6DC 802AA94C 3C01800E */  lui       $at, 0x800e
/* 41F6E0 802AA950 AC22C4DC */  sw        $v0, -0x3b24($at)
/* 41F6E4 802AA954 080AAB2D */  j         .L802AACB4
/* 41F6E8 802AA958 00000000 */   nop      
.L802AA95C:
/* 41F6EC 802AA95C 1040000E */  beqz      $v0, .L802AA998
/* 41F6F0 802AA960 00000000 */   nop      
/* 41F6F4 802AA964 0C05272D */  jal       play_sound
/* 41F6F8 802AA968 240400C9 */   addiu    $a0, $zero, 0xc9
/* 41F6FC 802AA96C 24020008 */  addiu     $v0, $zero, 8
/* 41F700 802AA970 3C01802B */  lui       $at, 0x802b
/* 41F704 802AA974 AC22CC60 */  sw        $v0, -0x33a0($at)
/* 41F708 802AA978 24020004 */  addiu     $v0, $zero, 4
/* 41F70C 802AA97C 3C01802B */  lui       $at, 0x802b
/* 41F710 802AA980 AC22CC6C */  sw        $v0, -0x3394($at)
/* 41F714 802AA984 24020002 */  addiu     $v0, $zero, 2
/* 41F718 802AA988 3C01800E */  lui       $at, 0x800e
/* 41F71C 802AA98C AC22C4DC */  sw        $v0, -0x3b24($at)
/* 41F720 802AA990 080AAB2D */  j         .L802AACB4
/* 41F724 802AA994 00000000 */   nop      
.L802AA998:
/* 41F728 802AA998 3C04800E */  lui       $a0, 0x800e
/* 41F72C 802AA99C 2484C070 */  addiu     $a0, $a0, -0x3f90
/* 41F730 802AA9A0 8C830000 */  lw        $v1, ($a0)
/* 41F734 802AA9A4 8E820210 */  lw        $v0, 0x210($s4)
/* 41F738 802AA9A8 34630002 */  ori       $v1, $v1, 2
/* 41F73C 802AA9AC 30422010 */  andi      $v0, $v0, 0x2010
/* 41F740 802AA9B0 10400005 */  beqz      $v0, .L802AA9C8
/* 41F744 802AA9B4 AC830000 */   sw       $v1, ($a0)
/* 41F748 802AA9B8 2402FFFD */  addiu     $v0, $zero, -3
/* 41F74C 802AA9BC 00621024 */  and       $v0, $v1, $v0
/* 41F750 802AA9C0 080AAB2D */  j         .L802AACB4
/* 41F754 802AA9C4 AC820000 */   sw       $v0, ($a0)
.L802AA9C8:
/* 41F758 802AA9C8 8E820184 */  lw        $v0, 0x184($s4)
/* 41F75C 802AA9CC 30420001 */  andi      $v0, $v0, 1
/* 41F760 802AA9D0 104000B8 */  beqz      $v0, .L802AACB4
/* 41F764 802AA9D4 3C020004 */   lui      $v0, 4
/* 41F768 802AA9D8 8E830218 */  lw        $v1, 0x218($s4)
/* 41F76C 802AA9DC 00621024 */  and       $v0, $v1, $v0
/* 41F770 802AA9E0 10400002 */  beqz      $v0, .L802AA9EC
/* 41F774 802AA9E4 0200202D */   daddu    $a0, $s0, $zero
/* 41F778 802AA9E8 2610FFFF */  addiu     $s0, $s0, -1
.L802AA9EC:
/* 41F77C 802AA9EC 3C020008 */  lui       $v0, 8
/* 41F780 802AA9F0 00621024 */  and       $v0, $v1, $v0
/* 41F784 802AA9F4 54400001 */  bnel      $v0, $zero, .L802AA9FC
/* 41F788 802AA9F8 26100001 */   addiu    $s0, $s0, 1
.L802AA9FC:
/* 41F78C 802AA9FC 06020001 */  bltzl     $s0, .L802AAA04
/* 41F790 802AAA00 2670FFFF */   addiu    $s0, $s3, -1
.L802AAA04:
/* 41F794 802AAA04 0213102A */  slt       $v0, $s0, $s3
/* 41F798 802AAA08 50400001 */  beql      $v0, $zero, .L802AAA10
/* 41F79C 802AAA0C 0000802D */   daddu    $s0, $zero, $zero
.L802AAA10:
/* 41F7A0 802AAA10 12040018 */  beq       $s0, $a0, .L802AAA74
/* 41F7A4 802AAA14 02B01021 */   addu     $v0, $s5, $s0
/* 41F7A8 802AAA18 80430000 */  lb        $v1, ($v0)
/* 41F7AC 802AAA1C 00031080 */  sll       $v0, $v1, 2
/* 41F7B0 802AAA20 00431021 */  addu      $v0, $v0, $v1
/* 41F7B4 802AAA24 00021080 */  sll       $v0, $v0, 2
/* 41F7B8 802AAA28 00528821 */  addu      $s1, $v0, $s2
/* 41F7BC 802AAA2C 0C09A75B */  jal       get_actor
/* 41F7C0 802AAA30 8624022C */   lh       $a0, 0x22c($s1)
/* 41F7C4 802AAA34 8C420000 */  lw        $v0, ($v0)
/* 41F7C8 802AAA38 3C11802B */  lui       $s1, 0x802b
/* 41F7CC 802AAA3C 8E31CC70 */  lw        $s1, -0x3390($s1)
/* 41F7D0 802AAA40 30420800 */  andi      $v0, $v0, 0x800
/* 41F7D4 802AAA44 10400005 */  beqz      $v0, .L802AAA5C
/* 41F7D8 802AAA48 0220202D */   daddu    $a0, $s1, $zero
/* 41F7DC 802AAA4C 3C058008 */  lui       $a1, 0x8008
/* 41F7E0 802AAA50 24A50208 */  addiu     $a1, $a1, 0x208
/* 41F7E4 802AAA54 080AAA99 */  j         .L802AAA64
/* 41F7E8 802AAA58 00000000 */   nop      
.L802AAA5C:
/* 41F7EC 802AAA5C 3C058008 */  lui       $a1, 0x8008
/* 41F7F0 802AAA60 24A5FF20 */  addiu     $a1, $a1, -0xe0
.L802AAA64:
/* 41F7F4 802AAA64 0C0511FF */  jal       set_menu_icon_script
/* 41F7F8 802AAA68 00000000 */   nop      
/* 41F7FC 802AAA6C 0C05272D */  jal       play_sound
/* 41F800 802AAA70 240400C7 */   addiu    $a0, $zero, 0xc7
.L802AAA74:
/* 41F804 802AAA74 080AAB2D */  j         .L802AACB4
/* 41F808 802AAA78 A2500425 */   sb       $s0, 0x425($s2)
.L802AAA7C:
/* 41F80C 802AAA7C 3C04800E */  lui       $a0, 0x800e
/* 41F810 802AAA80 2484C070 */  addiu     $a0, $a0, -0x3f90
/* 41F814 802AAA84 8C820000 */  lw        $v0, ($a0)
/* 41F818 802AAA88 2403FFFD */  addiu     $v1, $zero, -3
/* 41F81C 802AAA8C 00431024 */  and       $v0, $v0, $v1
/* 41F820 802AAA90 AC820000 */  sw        $v0, ($a0)
/* 41F824 802AAA94 82420425 */  lb        $v0, 0x425($s2)
/* 41F828 802AAA98 02A21021 */  addu      $v0, $s5, $v0
/* 41F82C 802AAA9C 80430000 */  lb        $v1, ($v0)
/* 41F830 802AAAA0 00031080 */  sll       $v0, $v1, 2
/* 41F834 802AAAA4 00431021 */  addu      $v0, $v0, $v1
/* 41F838 802AAAA8 00021080 */  sll       $v0, $v0, 2
/* 41F83C 802AAAAC 2442022C */  addiu     $v0, $v0, 0x22c
/* 41F840 802AAAB0 02428821 */  addu      $s1, $s2, $v0
/* 41F844 802AAAB4 96220000 */  lhu       $v0, ($s1)
/* 41F848 802AAAB8 A6420428 */  sh        $v0, 0x428($s2)
/* 41F84C 802AAABC 92220003 */  lbu       $v0, 3($s1)
/* 41F850 802AAAC0 0000802D */  daddu     $s0, $zero, $zero
/* 41F854 802AAAC4 1A60000C */  blez      $s3, .L802AAAF8
/* 41F858 802AAAC8 A2420426 */   sb       $v0, 0x426($s2)
/* 41F85C 802AAACC 3C11802B */  lui       $s1, 0x802b
/* 41F860 802AAAD0 2631CC70 */  addiu     $s1, $s1, -0x3390
.L802AAAD4:
/* 41F864 802AAAD4 8E240000 */  lw        $a0, ($s1)
/* 41F868 802AAAD8 26310004 */  addiu     $s1, $s1, 4
/* 41F86C 802AAADC 0C05123D */  jal       free_icon
/* 41F870 802AAAE0 26100001 */   addiu    $s0, $s0, 1
/* 41F874 802AAAE4 0213102A */  slt       $v0, $s0, $s3
/* 41F878 802AAAE8 1440FFFA */  bnez      $v0, .L802AAAD4
/* 41F87C 802AAAEC 00000000 */   nop      
/* 41F880 802AAAF0 3C04800E */  lui       $a0, 0x800e
/* 41F884 802AAAF4 2484C070 */  addiu     $a0, $a0, -0x3f90
.L802AAAF8:
/* 41F888 802AAAF8 8C820000 */  lw        $v0, ($a0)
/* 41F88C 802AAAFC 3C030008 */  lui       $v1, 8
/* 41F890 802AAB00 00431024 */  and       $v0, $v0, $v1
/* 41F894 802AAB04 14400012 */  bnez      $v0, .L802AAB50
/* 41F898 802AAB08 00000000 */   nop      
/* 41F89C 802AAB0C 8C820004 */  lw        $v0, 4($a0)
/* 41F8A0 802AAB10 8683006E */  lh        $v1, 0x6e($s4)
/* 41F8A4 802AAB14 30420040 */  andi      $v0, $v0, 0x40
/* 41F8A8 802AAB18 3C01800E */  lui       $at, 0x800e
/* 41F8AC 802AAB1C AC23C4DC */  sw        $v1, -0x3b24($at)
/* 41F8B0 802AAB20 10400005 */  beqz      $v0, .L802AAB38
/* 41F8B4 802AAB24 00000000 */   nop      
/* 41F8B8 802AAB28 0C0AA6D1 */  jal       func_802A9B44
/* 41F8BC 802AAB2C 00000000 */   nop      
/* 41F8C0 802AAB30 080AAAD0 */  j         .L802AAB40
/* 41F8C4 802AAB34 00000000 */   nop      
.L802AAB38:
/* 41F8C8 802AAB38 0C0A9662 */  jal       update_player_menu
/* 41F8CC 802AAB3C 00000000 */   nop      
.L802AAB40:
/* 41F8D0 802AAB40 0C090464 */  jal       func_80241190
/* 41F8D4 802AAB44 24040012 */   addiu    $a0, $zero, 0x12
/* 41F8D8 802AAB48 080AAB2D */  j         .L802AACB4
/* 41F8DC 802AAB4C 00000000 */   nop      
.L802AAB50:
/* 41F8E0 802AAB50 8C820004 */  lw        $v0, 4($a0)
/* 41F8E4 802AAB54 8683006E */  lh        $v1, 0x6e($s4)
/* 41F8E8 802AAB58 30420040 */  andi      $v0, $v0, 0x40
/* 41F8EC 802AAB5C 3C01800E */  lui       $at, 0x800e
/* 41F8F0 802AAB60 AC23C4DC */  sw        $v1, -0x3b24($at)
/* 41F8F4 802AAB64 10400005 */  beqz      $v0, .L802AAB7C
/* 41F8F8 802AAB68 00000000 */   nop      
.L802AAB6C:
/* 41F8FC 802AAB6C 0C0AA82E */  jal       func_802AA0B8
/* 41F900 802AAB70 00000000 */   nop      
/* 41F904 802AAB74 080AAAE1 */  j         .L802AAB84
/* 41F908 802AAB78 00000000 */   nop      
.L802AAB7C:
/* 41F90C 802AAB7C 0C0AA072 */  jal       update_partner_menu
/* 41F910 802AAB80 00000000 */   nop      
.L802AAB84:
/* 41F914 802AAB84 0C090464 */  jal       func_80241190
/* 41F918 802AAB88 24040013 */   addiu    $a0, $zero, 0x13
/* 41F91C 802AAB8C 080AAB2D */  j         .L802AACB4
/* 41F920 802AAB90 00000000 */   nop      
.L802AAB94:
/* 41F924 802AAB94 1A60000A */  blez      $s3, .L802AABC0
/* 41F928 802AAB98 0000802D */   daddu    $s0, $zero, $zero
/* 41F92C 802AAB9C 3C11802B */  lui       $s1, 0x802b
/* 41F930 802AABA0 2631CC70 */  addiu     $s1, $s1, -0x3390
.L802AABA4:
/* 41F934 802AABA4 8E240000 */  lw        $a0, ($s1)
/* 41F938 802AABA8 26310004 */  addiu     $s1, $s1, 4
/* 41F93C 802AABAC 0C05123D */  jal       free_icon
/* 41F940 802AABB0 26100001 */   addiu    $s0, $s0, 1
/* 41F944 802AABB4 0213102A */  slt       $v0, $s0, $s3
/* 41F948 802AABB8 1440FFFA */  bnez      $v0, .L802AABA4
/* 41F94C 802AABBC 00000000 */   nop      
.L802AABC0:
/* 41F950 802AABC0 3C030001 */  lui       $v1, 1
/* 41F954 802AABC4 3C10800E */  lui       $s0, 0x800e
/* 41F958 802AABC8 2610C070 */  addiu     $s0, $s0, -0x3f90
/* 41F95C 802AABCC 8E020000 */  lw        $v0, ($s0)
/* 41F960 802AABD0 34630002 */  ori       $v1, $v1, 2
/* 41F964 802AABD4 00431025 */  or        $v0, $v0, $v1
/* 41F968 802AABD8 AE020000 */  sw        $v0, ($s0)
/* 41F96C 802AABDC 8E420000 */  lw        $v0, ($s2)
/* 41F970 802AABE0 3C030800 */  lui       $v1, 0x800
/* 41F974 802AABE4 00431025 */  or        $v0, $v0, $v1
/* 41F978 802AABE8 AE420000 */  sw        $v0, ($s2)
/* 41F97C 802AABEC 82820088 */  lb        $v0, 0x88($s4)
/* 41F980 802AABF0 1040000C */  beqz      $v0, .L802AAC24
/* 41F984 802AABF4 3C030008 */   lui      $v1, 8
/* 41F988 802AABF8 0C090464 */  jal       func_80241190
/* 41F98C 802AABFC 2404000D */   addiu    $a0, $zero, 0xd
/* 41F990 802AAC00 8E020004 */  lw        $v0, 4($s0)
/* 41F994 802AAC04 8683006C */  lh        $v1, 0x6c($s4)
/* 41F998 802AAC08 30420040 */  andi      $v0, $v0, 0x40
/* 41F99C 802AAC0C 3C01800E */  lui       $at, 0x800e
/* 41F9A0 802AAC10 AC23C4DC */  sw        $v1, -0x3b24($at)
/* 41F9A4 802AAC14 10400014 */  beqz      $v0, .L802AAC68
/* 41F9A8 802AAC18 00000000 */   nop      
/* 41F9AC 802AAC1C 080AAB16 */  j         .L802AAC58
/* 41F9B0 802AAC20 00000000 */   nop      
.L802AAC24:
/* 41F9B4 802AAC24 8E020000 */  lw        $v0, ($s0)
/* 41F9B8 802AAC28 00431024 */  and       $v0, $v0, $v1
/* 41F9BC 802AAC2C 14400012 */  bnez      $v0, .L802AAC78
/* 41F9C0 802AAC30 00000000 */   nop      
/* 41F9C4 802AAC34 0C090464 */  jal       func_80241190
/* 41F9C8 802AAC38 2404000D */   addiu    $a0, $zero, 0xd
/* 41F9CC 802AAC3C 8E020004 */  lw        $v0, 4($s0)
/* 41F9D0 802AAC40 8683006C */  lh        $v1, 0x6c($s4)
/* 41F9D4 802AAC44 30420040 */  andi      $v0, $v0, 0x40
/* 41F9D8 802AAC48 3C01800E */  lui       $at, 0x800e
/* 41F9DC 802AAC4C AC23C4DC */  sw        $v1, -0x3b24($at)
/* 41F9E0 802AAC50 10400005 */  beqz      $v0, .L802AAC68
/* 41F9E4 802AAC54 00000000 */   nop      
.L802AAC58:
/* 41F9E8 802AAC58 0C0AA6D1 */  jal       func_802A9B44
/* 41F9EC 802AAC5C 00000000 */   nop      
/* 41F9F0 802AAC60 080AAB2D */  j         .L802AACB4
/* 41F9F4 802AAC64 00000000 */   nop      
.L802AAC68:
/* 41F9F8 802AAC68 0C0A9662 */  jal       update_player_menu
/* 41F9FC 802AAC6C 00000000 */   nop      
/* 41FA00 802AAC70 080AAB2D */  j         .L802AACB4
/* 41FA04 802AAC74 00000000 */   nop      
.L802AAC78:
/* 41FA08 802AAC78 0C090464 */  jal       func_80241190
/* 41FA0C 802AAC7C 2404000E */   addiu    $a0, $zero, 0xe
/* 41FA10 802AAC80 8E020004 */  lw        $v0, 4($s0)
/* 41FA14 802AAC84 8683006C */  lh        $v1, 0x6c($s4)
/* 41FA18 802AAC88 30420040 */  andi      $v0, $v0, 0x40
/* 41FA1C 802AAC8C 3C01800E */  lui       $at, 0x800e
/* 41FA20 802AAC90 AC23C4DC */  sw        $v1, -0x3b24($at)
/* 41FA24 802AAC94 10400005 */  beqz      $v0, .L802AACAC
/* 41FA28 802AAC98 00000000 */   nop      
/* 41FA2C 802AAC9C 0C0AA82E */  jal       func_802AA0B8
/* 41FA30 802AACA0 00000000 */   nop      
/* 41FA34 802AACA4 080AAB2D */  j         .L802AACB4
/* 41FA38 802AACA8 00000000 */   nop      
.L802AACAC:
/* 41FA3C 802AACAC 0C0AA072 */  jal       update_partner_menu
/* 41FA40 802AACB0 00000000 */   nop      
.L802AACB4:
/* 41FA44 802AACB4 8FBF0028 */  lw        $ra, 0x28($sp)
/* 41FA48 802AACB8 8FB50024 */  lw        $s5, 0x24($sp)
/* 41FA4C 802AACBC 8FB40020 */  lw        $s4, 0x20($sp)
/* 41FA50 802AACC0 8FB3001C */  lw        $s3, 0x1c($sp)
/* 41FA54 802AACC4 8FB20018 */  lw        $s2, 0x18($sp)
/* 41FA58 802AACC8 8FB10014 */  lw        $s1, 0x14($sp)
/* 41FA5C 802AACCC 8FB00010 */  lw        $s0, 0x10($sp)
/* 41FA60 802AACD0 03E00008 */  jr        $ra
/* 41FA64 802AACD4 27BD0030 */   addiu    $sp, $sp, 0x30
