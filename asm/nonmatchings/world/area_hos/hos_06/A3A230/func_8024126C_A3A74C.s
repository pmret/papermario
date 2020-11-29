.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024126C_A3A74C
/* A3A74C 8024126C 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* A3A750 80241270 AFBE0030 */  sw        $fp, 0x30($sp)
/* A3A754 80241274 0080F02D */  daddu     $fp, $a0, $zero
/* A3A758 80241278 0000202D */  daddu     $a0, $zero, $zero
/* A3A75C 8024127C 3C05F5DE */  lui       $a1, 0xf5de
/* A3A760 80241280 34A50180 */  ori       $a1, $a1, 0x180
/* A3A764 80241284 AFBF0034 */  sw        $ra, 0x34($sp)
/* A3A768 80241288 AFB7002C */  sw        $s7, 0x2c($sp)
/* A3A76C 8024128C AFB60028 */  sw        $s6, 0x28($sp)
/* A3A770 80241290 AFB50024 */  sw        $s5, 0x24($sp)
/* A3A774 80241294 AFB40020 */  sw        $s4, 0x20($sp)
/* A3A778 80241298 AFB3001C */  sw        $s3, 0x1c($sp)
/* A3A77C 8024129C AFB20018 */  sw        $s2, 0x18($sp)
/* A3A780 802412A0 AFB10014 */  sw        $s1, 0x14($sp)
/* A3A784 802412A4 0C0B1EAF */  jal       get_variable
/* A3A788 802412A8 AFB00010 */   sw       $s0, 0x10($sp)
/* A3A78C 802412AC 0040B02D */  daddu     $s6, $v0, $zero
/* A3A790 802412B0 0000A02D */  daddu     $s4, $zero, $zero
/* A3A794 802412B4 0280802D */  daddu     $s0, $s4, $zero
/* A3A798 802412B8 3C12F971 */  lui       $s2, 0xf971
/* A3A79C 802412BC 36528883 */  ori       $s2, $s2, 0x8883
/* A3A7A0 802412C0 3C118024 */  lui       $s1, %hi(D_802447D8)
/* A3A7A4 802412C4 263147D8 */  addiu     $s1, $s1, %lo(D_802447D8)
/* A3A7A8 802412C8 AFC00088 */  sw        $zero, 0x88($fp)
.L802412CC:
/* A3A7AC 802412CC 8E220004 */  lw        $v0, 4($s1)
/* A3A7B0 802412D0 02C2102A */  slt       $v0, $s6, $v0
/* A3A7B4 802412D4 5440000C */  bnel      $v0, $zero, .L80241308
/* A3A7B8 802412D8 26100001 */   addiu    $s0, $s0, 1
/* A3A7BC 802412DC 8E240000 */  lw        $a0, ($s1)
/* A3A7C0 802412E0 0C09046F */  jal       func_802411BC_A3A69C
/* A3A7C4 802412E4 00000000 */   nop      
/* A3A7C8 802412E8 54400007 */  bnel      $v0, $zero, .L80241308
/* A3A7CC 802412EC 26100001 */   addiu    $s0, $s0, 1
/* A3A7D0 802412F0 0000202D */  daddu     $a0, $zero, $zero
/* A3A7D4 802412F4 0C0B1EAF */  jal       get_variable
/* A3A7D8 802412F8 02122821 */   addu     $a1, $s0, $s2
/* A3A7DC 802412FC 50400001 */  beql      $v0, $zero, .L80241304
/* A3A7E0 80241300 26940001 */   addiu    $s4, $s4, 1
.L80241304:
/* A3A7E4 80241304 26100001 */  addiu     $s0, $s0, 1
.L80241308:
/* A3A7E8 80241308 2E02004F */  sltiu     $v0, $s0, 0x4f
/* A3A7EC 8024130C 1440FFEF */  bnez      $v0, .L802412CC
/* A3A7F0 80241310 2631000C */   addiu    $s1, $s1, 0xc
/* A3A7F4 80241314 3C118024 */  lui       $s1, %hi(D_802447D4)
/* A3A7F8 80241318 263147D4 */  addiu     $s1, $s1, %lo(D_802447D4)
/* A3A7FC 8024131C 1280002D */  beqz      $s4, .L802413D4
/* A3A800 80241320 0000802D */   daddu    $s0, $zero, $zero
/* A3A804 80241324 0C00A67F */  jal       rand_int
/* A3A808 80241328 2684FFFF */   addiu    $a0, $s4, -1
/* A3A80C 8024132C 0040A82D */  daddu     $s5, $v0, $zero
/* A3A810 80241330 0220982D */  daddu     $s3, $s1, $zero
/* A3A814 80241334 0000A02D */  daddu     $s4, $zero, $zero
/* A3A818 80241338 0280802D */  daddu     $s0, $s4, $zero
/* A3A81C 8024133C 3C17F971 */  lui       $s7, 0xf971
/* A3A820 80241340 36F78883 */  ori       $s7, $s7, 0x8883
/* A3A824 80241344 26720004 */  addiu     $s2, $s3, 4
.L80241348:
/* A3A828 80241348 8E420004 */  lw        $v0, 4($s2)
/* A3A82C 8024134C 02C2102A */  slt       $v0, $s6, $v0
/* A3A830 80241350 5440000F */  bnel      $v0, $zero, .L80241390
/* A3A834 80241354 26100001 */   addiu    $s0, $s0, 1
/* A3A838 80241358 8E440000 */  lw        $a0, ($s2)
/* A3A83C 8024135C 0C09046F */  jal       func_802411BC_A3A69C
/* A3A840 80241360 00000000 */   nop      
/* A3A844 80241364 5440000A */  bnel      $v0, $zero, .L80241390
/* A3A848 80241368 26100001 */   addiu    $s0, $s0, 1
/* A3A84C 8024136C 0000202D */  daddu     $a0, $zero, $zero
/* A3A850 80241370 02178821 */  addu      $s1, $s0, $s7
/* A3A854 80241374 0C0B1EAF */  jal       get_variable
/* A3A858 80241378 0220282D */   daddu    $a1, $s1, $zero
/* A3A85C 8024137C 54400004 */  bnel      $v0, $zero, .L80241390
/* A3A860 80241380 26100001 */   addiu    $s0, $s0, 1
/* A3A864 80241384 12950008 */  beq       $s4, $s5, .L802413A8
/* A3A868 80241388 26940001 */   addiu    $s4, $s4, 1
/* A3A86C 8024138C 26100001 */  addiu     $s0, $s0, 1
.L80241390:
/* A3A870 80241390 2652000C */  addiu     $s2, $s2, 0xc
/* A3A874 80241394 2E02004F */  sltiu     $v0, $s0, 0x4f
/* A3A878 80241398 1440FFEB */  bnez      $v0, .L80241348
/* A3A87C 8024139C 2673000C */   addiu    $s3, $s3, 0xc
/* A3A880 802413A0 0809052D */  j         .L802414B4
/* A3A884 802413A4 24020002 */   addiu    $v0, $zero, 2
.L802413A8:
/* A3A888 802413A8 0000202D */  daddu     $a0, $zero, $zero
/* A3A88C 802413AC 080904EF */  j         .L802413BC
/* A3A890 802413B0 0220282D */   daddu    $a1, $s1, $zero
.L802413B4:
/* A3A894 802413B4 0000202D */  daddu     $a0, $zero, $zero
/* A3A898 802413B8 0240282D */  daddu     $a1, $s2, $zero
.L802413BC:
/* A3A89C 802413BC 8E620000 */  lw        $v0, ($s3)
/* A3A8A0 802413C0 24060001 */  addiu     $a2, $zero, 1
/* A3A8A4 802413C4 0C0B2026 */  jal       set_variable
/* A3A8A8 802413C8 AFC20088 */   sw       $v0, 0x88($fp)
/* A3A8AC 802413CC 0809052D */  j         .L802414B4
/* A3A8B0 802413D0 24020002 */   addiu    $v0, $zero, 2
.L802413D4:
/* A3A8B4 802413D4 24132712 */  addiu     $s3, $zero, 0x2712
/* A3A8B8 802413D8 3C12F971 */  lui       $s2, 0xf971
/* A3A8BC 802413DC 36528883 */  ori       $s2, $s2, 0x8883
/* A3A8C0 802413E0 26310004 */  addiu     $s1, $s1, 4
.L802413E4:
/* A3A8C4 802413E4 8E220004 */  lw        $v0, 4($s1)
/* A3A8C8 802413E8 5453000C */  bnel      $v0, $s3, .L8024141C
/* A3A8CC 802413EC 26100001 */   addiu    $s0, $s0, 1
/* A3A8D0 802413F0 8E240000 */  lw        $a0, ($s1)
/* A3A8D4 802413F4 0C09046F */  jal       func_802411BC_A3A69C
/* A3A8D8 802413F8 00000000 */   nop      
/* A3A8DC 802413FC 54400007 */  bnel      $v0, $zero, .L8024141C
/* A3A8E0 80241400 26100001 */   addiu    $s0, $s0, 1
/* A3A8E4 80241404 0000202D */  daddu     $a0, $zero, $zero
/* A3A8E8 80241408 0C0B1EAF */  jal       get_variable
/* A3A8EC 8024140C 02122821 */   addu     $a1, $s0, $s2
/* A3A8F0 80241410 50400001 */  beql      $v0, $zero, .L80241418
/* A3A8F4 80241414 26940001 */   addiu    $s4, $s4, 1
.L80241418:
/* A3A8F8 80241418 26100001 */  addiu     $s0, $s0, 1
.L8024141C:
/* A3A8FC 8024141C 2E02004F */  sltiu     $v0, $s0, 0x4f
/* A3A900 80241420 1440FFF0 */  bnez      $v0, .L802413E4
/* A3A904 80241424 2631000C */   addiu    $s1, $s1, 0xc
/* A3A908 80241428 12800022 */  beqz      $s4, .L802414B4
/* A3A90C 8024142C 24020002 */   addiu    $v0, $zero, 2
/* A3A910 80241430 0C00A67F */  jal       rand_int
/* A3A914 80241434 2684FFFF */   addiu    $a0, $s4, -1
/* A3A918 80241438 0040A82D */  daddu     $s5, $v0, $zero
/* A3A91C 8024143C 3C138024 */  lui       $s3, %hi(D_802447D4)
/* A3A920 80241440 267347D4 */  addiu     $s3, $s3, %lo(D_802447D4)
/* A3A924 80241444 0000A02D */  daddu     $s4, $zero, $zero
/* A3A928 80241448 0280802D */  daddu     $s0, $s4, $zero
/* A3A92C 8024144C 24172712 */  addiu     $s7, $zero, 0x2712
/* A3A930 80241450 3C16F971 */  lui       $s6, 0xf971
/* A3A934 80241454 36D68883 */  ori       $s6, $s6, 0x8883
/* A3A938 80241458 26710004 */  addiu     $s1, $s3, 4
.L8024145C:
/* A3A93C 8024145C 8E220004 */  lw        $v0, 4($s1)
/* A3A940 80241460 5457000F */  bnel      $v0, $s7, .L802414A0
/* A3A944 80241464 26100001 */   addiu    $s0, $s0, 1
/* A3A948 80241468 8E240000 */  lw        $a0, ($s1)
/* A3A94C 8024146C 0C09046F */  jal       func_802411BC_A3A69C
/* A3A950 80241470 00000000 */   nop      
/* A3A954 80241474 5440000A */  bnel      $v0, $zero, .L802414A0
/* A3A958 80241478 26100001 */   addiu    $s0, $s0, 1
/* A3A95C 8024147C 0000202D */  daddu     $a0, $zero, $zero
/* A3A960 80241480 02169021 */  addu      $s2, $s0, $s6
/* A3A964 80241484 0C0B1EAF */  jal       get_variable
/* A3A968 80241488 0240282D */   daddu    $a1, $s2, $zero
/* A3A96C 8024148C 54400004 */  bnel      $v0, $zero, .L802414A0
/* A3A970 80241490 26100001 */   addiu    $s0, $s0, 1
/* A3A974 80241494 1295FFC7 */  beq       $s4, $s5, .L802413B4
/* A3A978 80241498 26940001 */   addiu    $s4, $s4, 1
/* A3A97C 8024149C 26100001 */  addiu     $s0, $s0, 1
.L802414A0:
/* A3A980 802414A0 2631000C */  addiu     $s1, $s1, 0xc
/* A3A984 802414A4 2E02004F */  sltiu     $v0, $s0, 0x4f
/* A3A988 802414A8 1440FFEC */  bnez      $v0, .L8024145C
/* A3A98C 802414AC 2673000C */   addiu    $s3, $s3, 0xc
/* A3A990 802414B0 24020002 */  addiu     $v0, $zero, 2
.L802414B4:
/* A3A994 802414B4 8FBF0034 */  lw        $ra, 0x34($sp)
/* A3A998 802414B8 8FBE0030 */  lw        $fp, 0x30($sp)
/* A3A99C 802414BC 8FB7002C */  lw        $s7, 0x2c($sp)
/* A3A9A0 802414C0 8FB60028 */  lw        $s6, 0x28($sp)
/* A3A9A4 802414C4 8FB50024 */  lw        $s5, 0x24($sp)
/* A3A9A8 802414C8 8FB40020 */  lw        $s4, 0x20($sp)
/* A3A9AC 802414CC 8FB3001C */  lw        $s3, 0x1c($sp)
/* A3A9B0 802414D0 8FB20018 */  lw        $s2, 0x18($sp)
/* A3A9B4 802414D4 8FB10014 */  lw        $s1, 0x14($sp)
/* A3A9B8 802414D8 8FB00010 */  lw        $s0, 0x10($sp)
/* A3A9BC 802414DC 03E00008 */  jr        $ra
/* A3A9C0 802414E0 27BD0038 */   addiu    $sp, $sp, 0x38
