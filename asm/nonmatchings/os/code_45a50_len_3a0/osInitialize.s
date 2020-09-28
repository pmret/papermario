.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel osInitialize
/* 45B08 8006A708 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 45B0C 8006A70C 24020001 */  addiu     $v0, $zero, 1
/* 45B10 8006A710 AFBF0018 */  sw        $ra, 0x18($sp)
/* 45B14 8006A714 3C01800A */  lui       $at, 0x800a
/* 45B18 8006A718 0C01B19C */  jal       osGetSR
/* 45B1C 8006A71C AC22A660 */   sw       $v0, -0x59a0($at)
/* 45B20 8006A720 3C042000 */  lui       $a0, 0x2000
/* 45B24 8006A724 0C01B1A8 */  jal       osSetSR
/* 45B28 8006A728 00442025 */   or       $a0, $v0, $a0
/* 45B2C 8006A72C 3C040100 */  lui       $a0, 0x100
/* 45B30 8006A730 0C01B1A4 */  jal       osSetFpcCsr
/* 45B34 8006A734 34840800 */   ori      $a0, $a0, 0x800
/* 45B38 8006A738 0C01B1AC */  jal       osSetWatchLo
/* 45B3C 8006A73C 3C040490 */   lui      $a0, 0x490
/* 45B40 8006A740 3C041FC0 */  lui       $a0, 0x1fc0
.L8006A744:
/* 45B44 8006A744 348407FC */  ori       $a0, $a0, 0x7fc
/* 45B48 8006A748 0C01B1F0 */  jal       osSiRawReadIo
/* 45B4C 8006A74C 27A50010 */   addiu    $a1, $sp, 0x10
/* 45B50 8006A750 1440FFFC */  bnez      $v0, .L8006A744
/* 45B54 8006A754 3C041FC0 */   lui      $a0, 0x1fc0
.L8006A758:
/* 45B58 8006A758 8FA50010 */  lw        $a1, 0x10($sp)
/* 45B5C 8006A75C 3C041FC0 */  lui       $a0, 0x1fc0
/* 45B60 8006A760 348407FC */  ori       $a0, $a0, 0x7fc
/* 45B64 8006A764 0C01B204 */  jal       osSiRawWriteIo
/* 45B68 8006A768 34A50008 */   ori      $a1, $a1, 8
/* 45B6C 8006A76C 1440FFFA */  bnez      $v0, .L8006A758
/* 45B70 8006A770 00000000 */   nop      
/* 45B74 8006A774 3C028007 */  lui       $v0, 0x8007
/* 45B78 8006A778 2442A9F0 */  addiu     $v0, $v0, -0x5610
/* 45B7C 8006A77C 3C068000 */  lui       $a2, 0x8000
/* 45B80 8006A780 8C430000 */  lw        $v1, ($v0)
/* 45B84 8006A784 8C440004 */  lw        $a0, 4($v0)
/* 45B88 8006A788 8C450008 */  lw        $a1, 8($v0)
/* 45B8C 8006A78C ACC30000 */  sw        $v1, ($a2)
/* 45B90 8006A790 ACC40004 */  sw        $a0, 4($a2)
/* 45B94 8006A794 ACC50008 */  sw        $a1, 8($a2)
/* 45B98 8006A798 8C43000C */  lw        $v1, 0xc($v0)
/* 45B9C 8006A79C ACC3000C */  sw        $v1, 0xc($a2)
/* 45BA0 8006A7A0 3C068000 */  lui       $a2, 0x8000
/* 45BA4 8006A7A4 34C60080 */  ori       $a2, $a2, 0x80
/* 45BA8 8006A7A8 8C430000 */  lw        $v1, ($v0)
/* 45BAC 8006A7AC 8C440004 */  lw        $a0, 4($v0)
/* 45BB0 8006A7B0 8C450008 */  lw        $a1, 8($v0)
/* 45BB4 8006A7B4 ACC30000 */  sw        $v1, ($a2)
/* 45BB8 8006A7B8 ACC40004 */  sw        $a0, 4($a2)
/* 45BBC 8006A7BC ACC50008 */  sw        $a1, 8($a2)
/* 45BC0 8006A7C0 8C43000C */  lw        $v1, 0xc($v0)
/* 45BC4 8006A7C4 ACC3000C */  sw        $v1, 0xc($a2)
/* 45BC8 8006A7C8 3C068000 */  lui       $a2, 0x8000
/* 45BCC 8006A7CC 34C60100 */  ori       $a2, $a2, 0x100
/* 45BD0 8006A7D0 8C430000 */  lw        $v1, ($v0)
/* 45BD4 8006A7D4 8C440004 */  lw        $a0, 4($v0)
/* 45BD8 8006A7D8 8C450008 */  lw        $a1, 8($v0)
/* 45BDC 8006A7DC ACC30000 */  sw        $v1, ($a2)
/* 45BE0 8006A7E0 ACC40004 */  sw        $a0, 4($a2)
/* 45BE4 8006A7E4 ACC50008 */  sw        $a1, 8($a2)
/* 45BE8 8006A7E8 8C43000C */  lw        $v1, 0xc($v0)
/* 45BEC 8006A7EC ACC3000C */  sw        $v1, 0xc($a2)
/* 45BF0 8006A7F0 3C068000 */  lui       $a2, 0x8000
/* 45BF4 8006A7F4 34C60180 */  ori       $a2, $a2, 0x180
/* 45BF8 8006A7F8 8C430000 */  lw        $v1, ($v0)
/* 45BFC 8006A7FC 8C440004 */  lw        $a0, 4($v0)
/* 45C00 8006A800 8C450008 */  lw        $a1, 8($v0)
/* 45C04 8006A804 ACC30000 */  sw        $v1, ($a2)
/* 45C08 8006A808 ACC40004 */  sw        $a0, 4($a2)
/* 45C0C 8006A80C ACC50008 */  sw        $a1, 8($a2)
/* 45C10 8006A810 8C43000C */  lw        $v1, 0xc($v0)
/* 45C14 8006A814 ACC3000C */  sw        $v1, 0xc($a2)
/* 45C18 8006A818 3C048000 */  lui       $a0, 0x8000
/* 45C1C 8006A81C 0C018614 */  jal       osWritebackDCache
/* 45C20 8006A820 24050190 */   addiu    $a1, $zero, 0x190
/* 45C24 8006A824 3C048000 */  lui       $a0, 0x8000
/* 45C28 8006A828 0C0185F4 */  jal       osInvalICache
/* 45C2C 8006A82C 24050190 */   addiu    $a1, $zero, 0x190
/* 45C30 8006A830 3C05A460 */  lui       $a1, 0xa460
/* 45C34 8006A834 34A50014 */  ori       $a1, $a1, 0x14
/* 45C38 8006A838 3C06A460 */  lui       $a2, 0xa460
/* 45C3C 8006A83C 34C60018 */  ori       $a2, $a2, 0x18
/* 45C40 8006A840 3C07A460 */  lui       $a3, 0xa460
/* 45C44 8006A844 34E7001C */  ori       $a3, $a3, 0x1c
/* 45C48 8006A848 3C08A460 */  lui       $t0, 0xa460
/* 45C4C 8006A84C 35080020 */  ori       $t0, $t0, 0x20
/* 45C50 8006A850 3C09A460 */  lui       $t1, 0xa460
/* 45C54 8006A854 35290024 */  ori       $t1, $t1, 0x24
/* 45C58 8006A858 3C04A460 */  lui       $a0, 0xa460
/* 45C5C 8006A85C 34840028 */  ori       $a0, $a0, 0x28
/* 45C60 8006A860 3C03A460 */  lui       $v1, 0xa460
/* 45C64 8006A864 3463002C */  ori       $v1, $v1, 0x2c
/* 45C68 8006A868 3C02A460 */  lui       $v0, 0xa460
/* 45C6C 8006A86C 34420030 */  ori       $v0, $v0, 0x30
/* 45C70 8006A870 8CA50000 */  lw        $a1, ($a1)
/* 45C74 8006A874 8CC60000 */  lw        $a2, ($a2)
/* 45C78 8006A878 8CE70000 */  lw        $a3, ($a3)
/* 45C7C 8006A87C 8D080000 */  lw        $t0, ($t0)
/* 45C80 8006A880 8D290000 */  lw        $t1, ($t1)
/* 45C84 8006A884 8C840000 */  lw        $a0, ($a0)
/* 45C88 8006A888 8C630000 */  lw        $v1, ($v1)
/* 45C8C 8006A88C 8C4A0000 */  lw        $t2, ($v0)
/* 45C90 8006A890 24020007 */  addiu     $v0, $zero, 7
/* 45C94 8006A894 3C01800B */  lui       $at, 0x800b
/* 45C98 8006A898 A022451C */  sb        $v0, 0x451c($at)
/* 45C9C 8006A89C 3C01800B */  lui       $at, 0x800b
/* 45CA0 8006A8A0 A0221B0C */  sb        $v0, 0x1b0c($at)
/* 45CA4 8006A8A4 3C01800B */  lui       $at, 0x800b
/* 45CA8 8006A8A8 A025451D */  sb        $a1, 0x451d($at)
/* 45CAC 8006A8AC 3C01800B */  lui       $at, 0x800b
/* 45CB0 8006A8B0 A0264520 */  sb        $a2, 0x4520($at)
/* 45CB4 8006A8B4 3C01800B */  lui       $at, 0x800b
/* 45CB8 8006A8B8 A027451E */  sb        $a3, 0x451e($at)
/* 45CBC 8006A8BC 3C01800B */  lui       $at, 0x800b
/* 45CC0 8006A8C0 A028451F */  sb        $t0, 0x451f($at)
/* 45CC4 8006A8C4 3C01800B */  lui       $at, 0x800b
/* 45CC8 8006A8C8 A0291B0D */  sb        $t1, 0x1b0d($at)
/* 45CCC 8006A8CC 3C01800B */  lui       $at, 0x800b
/* 45CD0 8006A8D0 A0241B10 */  sb        $a0, 0x1b10($at)
/* 45CD4 8006A8D4 3C01800B */  lui       $at, 0x800b
/* 45CD8 8006A8D8 A0231B0E */  sb        $v1, 0x1b0e($at)
/* 45CDC 8006A8DC 3C01800B */  lui       $at, 0x800b
/* 45CE0 8006A8E0 0C019A58 */  jal       osUnmapTLBAll
/* 45CE4 8006A8E4 A02A1B0F */   sb       $t2, 0x1b0f($at)
/* 45CE8 8006A8E8 0C01B28C */  jal       osMapTLBRdb
/* 45CEC 8006A8EC 00000000 */   nop      
/* 45CF0 8006A8F0 3C028009 */  lui       $v0, 0x8009
/* 45CF4 8006A8F4 8C4258F0 */  lw        $v0, 0x58f0($v0)
/* 45CF8 8006A8F8 3C038009 */  lui       $v1, 0x8009
/* 45CFC 8006A8FC 8C6358F4 */  lw        $v1, 0x58f4($v1)
/* 45D00 8006A900 00022040 */  sll       $a0, $v0, 1
/* 45D04 8006A904 000337C2 */  srl       $a2, $v1, 0x1f
/* 45D08 8006A908 00862025 */  or        $a0, $a0, $a2
/* 45D0C 8006A90C 00032840 */  sll       $a1, $v1, 1
/* 45D10 8006A910 00A32821 */  addu      $a1, $a1, $v1
/* 45D14 8006A914 00A3302B */  sltu      $a2, $a1, $v1
/* 45D18 8006A918 00822021 */  addu      $a0, $a0, $v0
/* 45D1C 8006A91C 00862021 */  addu      $a0, $a0, $a2
/* 45D20 8006A920 24060000 */  addiu     $a2, $zero, 0
/* 45D24 8006A924 0C01B8C4 */  jal       func_8006E310
/* 45D28 8006A928 24070004 */   addiu    $a3, $zero, 4
/* 45D2C 8006A92C 3C048000 */  lui       $a0, 0x8000
/* 45D30 8006A930 8C84030C */  lw        $a0, 0x30c($a0)
/* 45D34 8006A934 3C018009 */  lui       $at, 0x8009
/* 45D38 8006A938 AC2258F0 */  sw        $v0, 0x58f0($at)
/* 45D3C 8006A93C 3C018009 */  lui       $at, 0x8009
/* 45D40 8006A940 14800005 */  bnez      $a0, .L8006A958
/* 45D44 8006A944 AC2358F4 */   sw       $v1, 0x58f4($at)
/* 45D48 8006A948 3C048000 */  lui       $a0, 0x8000
/* 45D4C 8006A94C 2484031C */  addiu     $a0, $a0, 0x31c
/* 45D50 8006A950 0C01925C */  jal       bzero
/* 45D54 8006A954 24050040 */   addiu    $a1, $zero, 0x40
.L8006A958:
/* 45D58 8006A958 3C038000 */  lui       $v1, 0x8000
/* 45D5C 8006A95C 8C630300 */  lw        $v1, 0x300($v1)
/* 45D60 8006A960 54600004 */  bnel      $v1, $zero, .L8006A974
/* 45D64 8006A964 24020002 */   addiu    $v0, $zero, 2
/* 45D68 8006A968 3C0202F5 */  lui       $v0, 0x2f5
/* 45D6C 8006A96C 0801AA62 */  j         .L8006A988
/* 45D70 8006A970 3442B2D2 */   ori      $v0, $v0, 0xb2d2
.L8006A974:
/* 45D74 8006A974 14620003 */  bne       $v1, $v0, .L8006A984
/* 45D78 8006A978 3C0202E6 */   lui      $v0, 0x2e6
/* 45D7C 8006A97C 0801AA62 */  j         .L8006A988
/* 45D80 8006A980 3442025C */   ori      $v0, $v0, 0x25c
.L8006A984:
/* 45D84 8006A984 3442D354 */  ori       $v0, $v0, 0xd354
.L8006A988:
/* 45D88 8006A988 3C018009 */  lui       $at, 0x8009
/* 45D8C 8006A98C 0C01B198 */  jal       osGetCause
/* 45D90 8006A990 AC2258F8 */   sw       $v0, 0x58f8($at)
/* 45D94 8006A994 30421000 */  andi      $v0, $v0, 0x1000
/* 45D98 8006A998 10400003 */  beqz      $v0, .L8006A9A8
/* 45D9C 8006A99C 3C03A450 */   lui      $v1, 0xa450
.L8006A9A0:
/* 45DA0 8006A9A0 0801AA68 */  j         .L8006A9A0
/* 45DA4 8006A9A4 00000000 */   nop      
.L8006A9A8:
/* 45DA8 8006A9A8 34630008 */  ori       $v1, $v1, 8
/* 45DAC 8006A9AC 3C04A450 */  lui       $a0, 0xa450
/* 45DB0 8006A9B0 34840010 */  ori       $a0, $a0, 0x10
/* 45DB4 8006A9B4 3C05A450 */  lui       $a1, 0xa450
/* 45DB8 8006A9B8 34A50014 */  ori       $a1, $a1, 0x14
/* 45DBC 8006A9BC 24020001 */  addiu     $v0, $zero, 1
/* 45DC0 8006A9C0 AC620000 */  sw        $v0, ($v1)
/* 45DC4 8006A9C4 24023FFF */  addiu     $v0, $zero, 0x3fff
/* 45DC8 8006A9C8 AC820000 */  sw        $v0, ($a0)
/* 45DCC 8006A9CC 2402000F */  addiu     $v0, $zero, 0xf
/* 45DD0 8006A9D0 ACA20000 */  sw        $v0, ($a1)
/* 45DD4 8006A9D4 8FBF0018 */  lw        $ra, 0x18($sp)
/* 45DD8 8006A9D8 03E00008 */  jr        $ra
/* 45DDC 8006A9DC 27BD0020 */   addiu    $sp, $sp, 0x20
