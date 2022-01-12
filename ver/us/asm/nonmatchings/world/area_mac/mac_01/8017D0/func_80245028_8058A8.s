.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80245028_8058A8
/* 8058A8 80245028 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* 8058AC 8024502C AFB70034 */  sw        $s7, 0x34($sp)
/* 8058B0 80245030 0080B82D */  daddu     $s7, $a0, $zero
/* 8058B4 80245034 AFBE0038 */  sw        $fp, 0x38($sp)
/* 8058B8 80245038 3C1E8026 */  lui       $fp, %hi(D_80262C38)
/* 8058BC 8024503C 27DE2C38 */  addiu     $fp, $fp, %lo(D_80262C38)
/* 8058C0 80245040 AFBF003C */  sw        $ra, 0x3c($sp)
/* 8058C4 80245044 AFB60030 */  sw        $s6, 0x30($sp)
/* 8058C8 80245048 AFB5002C */  sw        $s5, 0x2c($sp)
/* 8058CC 8024504C AFB40028 */  sw        $s4, 0x28($sp)
/* 8058D0 80245050 AFB30024 */  sw        $s3, 0x24($sp)
/* 8058D4 80245054 AFB20020 */  sw        $s2, 0x20($sp)
/* 8058D8 80245058 AFB1001C */  sw        $s1, 0x1c($sp)
/* 8058DC 8024505C 10A00045 */  beqz      $a1, .L80245174
/* 8058E0 80245060 AFB00018 */   sw       $s0, 0x18($sp)
/* 8058E4 80245064 0000B02D */  daddu     $s6, $zero, $zero
/* 8058E8 80245068 24150001 */  addiu     $s5, $zero, 1
/* 8058EC 8024506C 02A0282D */  daddu     $a1, $s5, $zero
/* 8058F0 80245070 3C148009 */  lui       $s4, %hi(D_8008EEC4)
/* 8058F4 80245074 2694EEC4 */  addiu     $s4, $s4, %lo(D_8008EEC4)
/* 8058F8 80245078 03C0882D */  daddu     $s1, $fp, $zero
.L8024507C:
/* 8058FC 8024507C 8E900000 */  lw        $s0, ($s4)
/* 805900 80245080 3C068011 */  lui       $a2, %hi(gPlayerData)
/* 805904 80245084 24C6F290 */  addiu     $a2, $a2, %lo(gPlayerData)
/* 805908 80245088 001010C0 */  sll       $v0, $s0, 3
/* 80590C 8024508C 00C29821 */  addu      $s3, $a2, $v0
/* 805910 80245090 92620014 */  lbu       $v0, 0x14($s3)
/* 805914 80245094 50400027 */  beql      $v0, $zero, .L80245134
/* 805918 80245098 26B50001 */   addiu    $s5, $s5, 1
/* 80591C 8024509C 24060005 */  addiu     $a2, $zero, 5
/* 805920 802450A0 52060024 */  beql      $s0, $a2, .L80245134
/* 805924 802450A4 26B50001 */   addiu    $s5, $s5, 1
/* 805928 802450A8 0200202D */  daddu     $a0, $s0, $zero
/* 80592C 802450AC 00101100 */  sll       $v0, $s0, 4
/* 805930 802450B0 3C068009 */  lui       $a2, %hi(gPartnerPopupProperties)
/* 805934 802450B4 24C6EF20 */  addiu     $a2, $a2, %lo(gPartnerPopupProperties)
/* 805938 802450B8 00469021 */  addu      $s2, $v0, $a2
/* 80593C 802450BC 0C0913D7 */  jal       func_80244F5C_8057DC
/* 805940 802450C0 AFA50010 */   sw       $a1, 0x10($sp)
/* 805944 802450C4 0040182D */  daddu     $v1, $v0, $zero
/* 805948 802450C8 8FA50010 */  lw        $a1, 0x10($sp)
/* 80594C 802450CC 50600019 */  beql      $v1, $zero, .L80245134
/* 805950 802450D0 26B50001 */   addiu    $s5, $s5, 1
/* 805954 802450D4 00102080 */  sll       $a0, $s0, 2
/* 805958 802450D8 3C06800F */  lui       $a2, %hi(D_800F7F00)
/* 80595C 802450DC 24C67F00 */  addiu     $a2, $a2, %lo(D_800F7F00)
/* 805960 802450E0 00861021 */  addu      $v0, $a0, $a2
/* 805964 802450E4 8C420000 */  lw        $v0, ($v0)
/* 805968 802450E8 AE300108 */  sw        $s0, 0x108($s1)
/* 80596C 802450EC AE25018C */  sw        $a1, 0x18c($s1)
/* 805970 802450F0 AE220000 */  sw        $v0, ($s1)
/* 805974 802450F4 8E420000 */  lw        $v0, ($s2)
/* 805978 802450F8 AE220084 */  sw        $v0, 0x84($s1)
/* 80597C 802450FC 8E420008 */  lw        $v0, 8($s2)
/* 805980 80245100 AE220294 */  sw        $v0, 0x294($s1)
/* 805984 80245104 82620015 */  lb        $v0, 0x15($s3)
/* 805988 80245108 14650007 */  bne       $v1, $a1, .L80245128
/* 80598C 8024510C AE220210 */   sw       $v0, 0x210($s1)
/* 805990 80245110 3C06800F */  lui       $a2, %hi(D_800F7F40)
/* 805994 80245114 24C67F40 */  addiu     $a2, $a2, %lo(D_800F7F40)
/* 805998 80245118 00861021 */  addu      $v0, $a0, $a2
/* 80599C 8024511C AE20018C */  sw        $zero, 0x18c($s1)
/* 8059A0 80245120 8C420000 */  lw        $v0, ($v0)
/* 8059A4 80245124 AE220000 */  sw        $v0, ($s1)
.L80245128:
/* 8059A8 80245128 26310004 */  addiu     $s1, $s1, 4
/* 8059AC 8024512C 26D60001 */  addiu     $s6, $s6, 1
/* 8059B0 80245130 26B50001 */  addiu     $s5, $s5, 1
.L80245134:
/* 8059B4 80245134 2AA2000C */  slti      $v0, $s5, 0xc
/* 8059B8 80245138 1440FFD0 */  bnez      $v0, .L8024507C
/* 8059BC 8024513C 26940004 */   addiu    $s4, $s4, 4
/* 8059C0 80245140 03C0202D */  daddu     $a0, $fp, $zero
/* 8059C4 80245144 3C038026 */  lui       $v1, %hi(D_80262F68)
/* 8059C8 80245148 8C632F68 */  lw        $v1, %lo(D_80262F68)($v1)
/* 8059CC 8024514C 2402000D */  addiu     $v0, $zero, 0xd
/* 8059D0 80245150 AFC20318 */  sw        $v0, 0x318($fp)
/* 8059D4 80245154 AFD60324 */  sw        $s6, 0x324($fp)
/* 8059D8 80245158 0C03D390 */  jal       create_popup_menu
/* 8059DC 8024515C AFC30328 */   sw       $v1, 0x328($fp)
/* 8059E0 80245160 0C03A631 */  jal       func_800E98C4
/* 8059E4 80245164 00000000 */   nop
/* 8059E8 80245168 0C03A5EE */  jal       close_status_menu
/* 8059EC 8024516C 00000000 */   nop
/* 8059F0 80245170 AEE00070 */  sw        $zero, 0x70($s7)
.L80245174:
/* 8059F4 80245174 8EE20070 */  lw        $v0, 0x70($s7)
/* 8059F8 80245178 14400008 */  bnez      $v0, .L8024519C
/* 8059FC 8024517C 24420001 */   addiu    $v0, $v0, 1
/* 805A00 80245180 87C2032C */  lh        $v0, 0x32c($fp)
/* 805A04 80245184 10400009 */  beqz      $v0, .L802451AC
/* 805A08 80245188 AEE20074 */   sw       $v0, 0x74($s7)
/* 805A0C 8024518C 0C03C4EC */  jal       hide_popup_menu
/* 805A10 80245190 00000000 */   nop
/* 805A14 80245194 8EE20070 */  lw        $v0, 0x70($s7)
/* 805A18 80245198 24420001 */  addiu     $v0, $v0, 1
.L8024519C:
/* 805A1C 8024519C AEE20070 */  sw        $v0, 0x70($s7)
/* 805A20 802451A0 28420014 */  slti      $v0, $v0, 0x14
/* 805A24 802451A4 10400003 */  beqz      $v0, .L802451B4
/* 805A28 802451A8 00000000 */   nop
.L802451AC:
/* 805A2C 802451AC 0809147F */  j         .L802451FC
/* 805A30 802451B0 0000102D */   daddu    $v0, $zero, $zero
.L802451B4:
/* 805A34 802451B4 0C03C54E */  jal       destroy_popup_menu
/* 805A38 802451B8 00000000 */   nop
/* 805A3C 802451BC 8EE30074 */  lw        $v1, 0x74($s7)
/* 805A40 802451C0 240200FF */  addiu     $v0, $zero, 0xff
/* 805A44 802451C4 1062000A */  beq       $v1, $v0, .L802451F0
/* 805A48 802451C8 2462FFFF */   addiu    $v0, $v1, -1
/* 805A4C 802451CC 00021080 */  sll       $v0, $v0, 2
/* 805A50 802451D0 03C21021 */  addu      $v0, $fp, $v0
/* 805A54 802451D4 8C500108 */  lw        $s0, 0x108($v0)
/* 805A58 802451D8 24020002 */  addiu     $v0, $zero, 2
/* 805A5C 802451DC 2463FFFF */  addiu     $v1, $v1, -1
/* 805A60 802451E0 3C018026 */  lui       $at, %hi(D_80262F68)
/* 805A64 802451E4 AC232F68 */  sw        $v1, %lo(D_80262F68)($at)
/* 805A68 802451E8 0809147F */  j         .L802451FC
/* 805A6C 802451EC AEF00088 */   sw       $s0, 0x88($s7)
.L802451F0:
/* 805A70 802451F0 2402FFFF */  addiu     $v0, $zero, -1
/* 805A74 802451F4 AEE20088 */  sw        $v0, 0x88($s7)
/* 805A78 802451F8 24020002 */  addiu     $v0, $zero, 2
.L802451FC:
/* 805A7C 802451FC 8FBF003C */  lw        $ra, 0x3c($sp)
/* 805A80 80245200 8FBE0038 */  lw        $fp, 0x38($sp)
/* 805A84 80245204 8FB70034 */  lw        $s7, 0x34($sp)
/* 805A88 80245208 8FB60030 */  lw        $s6, 0x30($sp)
/* 805A8C 8024520C 8FB5002C */  lw        $s5, 0x2c($sp)
/* 805A90 80245210 8FB40028 */  lw        $s4, 0x28($sp)
/* 805A94 80245214 8FB30024 */  lw        $s3, 0x24($sp)
/* 805A98 80245218 8FB20020 */  lw        $s2, 0x20($sp)
/* 805A9C 8024521C 8FB1001C */  lw        $s1, 0x1c($sp)
/* 805AA0 80245220 8FB00018 */  lw        $s0, 0x18($sp)
/* 805AA4 80245224 03E00008 */  jr        $ra
/* 805AA8 80245228 27BD0040 */   addiu    $sp, $sp, 0x40
