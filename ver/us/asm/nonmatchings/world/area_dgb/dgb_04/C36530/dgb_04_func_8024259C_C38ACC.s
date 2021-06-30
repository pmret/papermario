.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel dgb_04_func_8024259C_C38ACC
/* C38ACC 8024259C 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* C38AD0 802425A0 AFB5002C */  sw        $s5, 0x2c($sp)
/* C38AD4 802425A4 0080A82D */  daddu     $s5, $a0, $zero
/* C38AD8 802425A8 AFBE0038 */  sw        $fp, 0x38($sp)
/* C38ADC 802425AC 3C1E8011 */  lui       $fp, %hi(gPlayerData)
/* C38AE0 802425B0 27DEF290 */  addiu     $fp, $fp, %lo(gPlayerData)
/* C38AE4 802425B4 AFBF003C */  sw        $ra, 0x3c($sp)
/* C38AE8 802425B8 AFB70034 */  sw        $s7, 0x34($sp)
/* C38AEC 802425BC AFB60030 */  sw        $s6, 0x30($sp)
/* C38AF0 802425C0 AFB40028 */  sw        $s4, 0x28($sp)
/* C38AF4 802425C4 AFB30024 */  sw        $s3, 0x24($sp)
/* C38AF8 802425C8 AFB20020 */  sw        $s2, 0x20($sp)
/* C38AFC 802425CC AFB1001C */  sw        $s1, 0x1c($sp)
/* C38B00 802425D0 10A0004F */  beqz      $a1, .L80242710
/* C38B04 802425D4 AFB00018 */   sw       $s0, 0x18($sp)
/* C38B08 802425D8 0C00AB39 */  jal       heap_malloc
/* C38B0C 802425DC 24040330 */   addiu    $a0, $zero, 0x330
/* C38B10 802425E0 0040982D */  daddu     $s3, $v0, $zero
/* C38B14 802425E4 0000B02D */  daddu     $s6, $zero, $zero
/* C38B18 802425E8 02C0902D */  daddu     $s2, $s6, $zero
/* C38B1C 802425EC 3C148024 */  lui       $s4, %hi(dgb_04_D_80243D38_C3A268)
/* C38B20 802425F0 26943D38 */  addiu     $s4, $s4, %lo(dgb_04_D_80243D38_C3A268)
/* C38B24 802425F4 0260882D */  daddu     $s1, $s3, $zero
/* C38B28 802425F8 8EA200B4 */  lw        $v0, 0xb4($s5)
/* C38B2C 802425FC 3C038024 */  lui       $v1, %hi(dgb_04_D_80243D30_C3A260)
/* C38B30 80242600 24633D30 */  addiu     $v1, $v1, %lo(dgb_04_D_80243D30_C3A260)
/* C38B34 80242604 AEB30078 */  sw        $s3, 0x78($s5)
/* C38B38 80242608 00021027 */  nor       $v0, $zero, $v0
/* C38B3C 8024260C 0002BFC2 */  srl       $s7, $v0, 0x1f
/* C38B40 80242610 00171080 */  sll       $v0, $s7, 2
/* C38B44 80242614 00431021 */  addu      $v0, $v0, $v1
/* C38B48 80242618 AFA20010 */  sw        $v0, 0x10($sp)
.L8024261C:
/* C38B4C 8024261C 86900000 */  lh        $s0, ($s4)
/* C38B50 80242620 001010C0 */  sll       $v0, $s0, 3
/* C38B54 80242624 03C21021 */  addu      $v0, $fp, $v0
/* C38B58 80242628 90420014 */  lbu       $v0, 0x14($v0)
/* C38B5C 8024262C 5040002E */  beql      $v0, $zero, .L802426E8
/* C38B60 80242630 26520001 */   addiu    $s2, $s2, 1
/* C38B64 80242634 00101100 */  sll       $v0, $s0, 4
/* C38B68 80242638 3C068009 */  lui       $a2, %hi(D_8008EF20)
/* C38B6C 8024263C 24C6EF20 */  addiu     $a2, $a2, %lo(D_8008EF20)
/* C38B70 80242640 00461021 */  addu      $v0, $v0, $a2
/* C38B74 80242644 0200202D */  daddu     $a0, $s0, $zero
/* C38B78 80242648 AE300108 */  sw        $s0, 0x108($s1)
/* C38B7C 8024264C 8C420000 */  lw        $v0, ($v0)
/* C38B80 80242650 02E0282D */  daddu     $a1, $s7, $zero
/* C38B84 80242654 0C090929 */  jal       dgb_04_UnkFunc37
/* C38B88 80242658 AE220084 */   sw       $v0, 0x84($s1)
/* C38B8C 8024265C 0040202D */  daddu     $a0, $v0, $zero
/* C38B90 80242660 04800011 */  bltz      $a0, .L802426A8
/* C38B94 80242664 00101080 */   sll      $v0, $s0, 2
/* C38B98 80242668 3C06800F */  lui       $a2, %hi(D_800F7F00)
/* C38B9C 8024266C 24C67F00 */  addiu     $a2, $a2, %lo(D_800F7F00)
/* C38BA0 80242670 00461021 */  addu      $v0, $v0, $a2
/* C38BA4 80242674 8C430000 */  lw        $v1, ($v0)
/* C38BA8 80242678 24020001 */  addiu     $v0, $zero, 1
/* C38BAC 8024267C AE22018C */  sw        $v0, 0x18c($s1)
/* C38BB0 80242680 00041080 */  sll       $v0, $a0, 2
/* C38BB4 80242684 3C068024 */  lui       $a2, %hi(dgb_04_D_80243D48_C3A278)
/* C38BB8 80242688 24C63D48 */  addiu     $a2, $a2, %lo(dgb_04_D_80243D48_C3A278)
/* C38BBC 8024268C AE230000 */  sw        $v1, ($s1)
/* C38BC0 80242690 001218C0 */  sll       $v1, $s2, 3
/* C38BC4 80242694 00431021 */  addu      $v0, $v0, $v1
/* C38BC8 80242698 00461021 */  addu      $v0, $v0, $a2
/* C38BCC 8024269C 8C420000 */  lw        $v0, ($v0)
/* C38BD0 802426A0 080909B3 */  j         .L802426CC
/* C38BD4 802426A4 AE220294 */   sw       $v0, 0x294($s1)
.L802426A8:
/* C38BD8 802426A8 3C06800F */  lui       $a2, %hi(D_800F7F40)
/* C38BDC 802426AC 24C67F40 */  addiu     $a2, $a2, %lo(D_800F7F40)
/* C38BE0 802426B0 00461021 */  addu      $v0, $v0, $a2
/* C38BE4 802426B4 8C420000 */  lw        $v0, ($v0)
/* C38BE8 802426B8 AE20018C */  sw        $zero, 0x18c($s1)
/* C38BEC 802426BC AE220000 */  sw        $v0, ($s1)
/* C38BF0 802426C0 8FA60010 */  lw        $a2, 0x10($sp)
/* C38BF4 802426C4 8CC20000 */  lw        $v0, ($a2)
/* C38BF8 802426C8 AE220294 */  sw        $v0, 0x294($s1)
.L802426CC:
/* C38BFC 802426CC 001010C0 */  sll       $v0, $s0, 3
/* C38C00 802426D0 03C21021 */  addu      $v0, $fp, $v0
/* C38C04 802426D4 80420015 */  lb        $v0, 0x15($v0)
/* C38C08 802426D8 26D60001 */  addiu     $s6, $s6, 1
/* C38C0C 802426DC AE220210 */  sw        $v0, 0x210($s1)
/* C38C10 802426E0 26310004 */  addiu     $s1, $s1, 4
/* C38C14 802426E4 26520001 */  addiu     $s2, $s2, 1
.L802426E8:
/* C38C18 802426E8 2A420008 */  slti      $v0, $s2, 8
/* C38C1C 802426EC 1440FFCB */  bnez      $v0, .L8024261C
/* C38C20 802426F0 26940002 */   addiu    $s4, $s4, 2
/* C38C24 802426F4 0260202D */  daddu     $a0, $s3, $zero
/* C38C28 802426F8 24020004 */  addiu     $v0, $zero, 4
/* C38C2C 802426FC AC820318 */  sw        $v0, 0x318($a0)
/* C38C30 80242700 AC960324 */  sw        $s6, 0x324($a0)
/* C38C34 80242704 0C03D390 */  jal       btl_create_popup_menu
/* C38C38 80242708 AC800328 */   sw       $zero, 0x328($a0)
/* C38C3C 8024270C AEA00070 */  sw        $zero, 0x70($s5)
.L80242710:
/* C38C40 80242710 8EA20070 */  lw        $v0, 0x70($s5)
/* C38C44 80242714 8EB30078 */  lw        $s3, 0x78($s5)
/* C38C48 80242718 14400008 */  bnez      $v0, .L8024273C
/* C38C4C 8024271C 24420001 */   addiu    $v0, $v0, 1
/* C38C50 80242720 8662032C */  lh        $v0, 0x32c($s3)
/* C38C54 80242724 10400009 */  beqz      $v0, .L8024274C
/* C38C58 80242728 AEA20074 */   sw       $v0, 0x74($s5)
/* C38C5C 8024272C 0C03C4EC */  jal       hide_popup_menu
/* C38C60 80242730 00000000 */   nop
/* C38C64 80242734 8EA20070 */  lw        $v0, 0x70($s5)
/* C38C68 80242738 24420001 */  addiu     $v0, $v0, 1
.L8024273C:
/* C38C6C 8024273C AEA20070 */  sw        $v0, 0x70($s5)
/* C38C70 80242740 2842000F */  slti      $v0, $v0, 0xf
/* C38C74 80242744 10400003 */  beqz      $v0, .L80242754
/* C38C78 80242748 00000000 */   nop
.L8024274C:
/* C38C7C 8024274C 080909EF */  j         .L802427BC
/* C38C80 80242750 0000102D */   daddu    $v0, $zero, $zero
.L80242754:
/* C38C84 80242754 0C03C54E */  jal       destroy_popup_menu
/* C38C88 80242758 00000000 */   nop
/* C38C8C 8024275C 8EA30074 */  lw        $v1, 0x74($s5)
/* C38C90 80242760 240200FF */  addiu     $v0, $zero, 0xff
/* C38C94 80242764 10620010 */  beq       $v1, $v0, .L802427A8
/* C38C98 80242768 2462FFFF */   addiu    $v0, $v1, -1
/* C38C9C 8024276C 00021080 */  sll       $v0, $v0, 2
/* C38CA0 80242770 02621021 */  addu      $v0, $s3, $v0
/* C38CA4 80242774 8C420108 */  lw        $v0, 0x108($v0)
/* C38CA8 80242778 00021100 */  sll       $v0, $v0, 4
/* C38CAC 8024277C 3C038009 */  lui       $v1, %hi(D_8008EF20)
/* C38CB0 80242780 00621821 */  addu      $v1, $v1, $v0
/* C38CB4 80242784 8C63EF20 */  lw        $v1, %lo(D_8008EF20)($v1)
/* C38CB8 80242788 8EA20074 */  lw        $v0, 0x74($s5)
/* C38CBC 8024278C 2442FFFF */  addiu     $v0, $v0, -1
/* C38CC0 80242790 00021080 */  sll       $v0, $v0, 2
/* C38CC4 80242794 02621021 */  addu      $v0, $s3, $v0
/* C38CC8 80242798 AEA30084 */  sw        $v1, 0x84($s5)
/* C38CCC 8024279C 8C420108 */  lw        $v0, 0x108($v0)
/* C38CD0 802427A0 080909EC */  j         .L802427B0
/* C38CD4 802427A4 AEA20088 */   sw       $v0, 0x88($s5)
.L802427A8:
/* C38CD8 802427A8 2402FFFF */  addiu     $v0, $zero, -1
/* C38CDC 802427AC AEA20084 */  sw        $v0, 0x84($s5)
.L802427B0:
/* C38CE0 802427B0 0C00AB4B */  jal       heap_free
/* C38CE4 802427B4 8EA40078 */   lw       $a0, 0x78($s5)
/* C38CE8 802427B8 24020002 */  addiu     $v0, $zero, 2
.L802427BC:
/* C38CEC 802427BC 8FBF003C */  lw        $ra, 0x3c($sp)
/* C38CF0 802427C0 8FBE0038 */  lw        $fp, 0x38($sp)
/* C38CF4 802427C4 8FB70034 */  lw        $s7, 0x34($sp)
/* C38CF8 802427C8 8FB60030 */  lw        $s6, 0x30($sp)
/* C38CFC 802427CC 8FB5002C */  lw        $s5, 0x2c($sp)
/* C38D00 802427D0 8FB40028 */  lw        $s4, 0x28($sp)
/* C38D04 802427D4 8FB30024 */  lw        $s3, 0x24($sp)
/* C38D08 802427D8 8FB20020 */  lw        $s2, 0x20($sp)
/* C38D0C 802427DC 8FB1001C */  lw        $s1, 0x1c($sp)
/* C38D10 802427E0 8FB00018 */  lw        $s0, 0x18($sp)
/* C38D14 802427E4 03E00008 */  jr        $ra
/* C38D18 802427E8 27BD0040 */   addiu    $sp, $sp, 0x40
