.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006A6E8
/* 45AE8 8006A6E8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 45AEC 8006A6EC 24020001 */  addiu     $v0, $zero, 1
/* 45AF0 8006A6F0 AFBF0018 */  sw        $ra, 0x18($sp)
/* 45AF4 8006A6F4 3C01800A */  lui       $at, %hi(D_8009A640)
/* 45AF8 8006A6F8 0C01B194 */  jal       func_8006C650
/* 45AFC 8006A6FC AC22A640 */   sw       $v0, %lo(D_8009A640)($at)
/* 45B00 8006A700 3C042000 */  lui       $a0, 0x2000
/* 45B04 8006A704 0C01B1A0 */  jal       func_8006C680
/* 45B08 8006A708 00442025 */   or       $a0, $v0, $a0
/* 45B0C 8006A70C 3C040100 */  lui       $a0, 0x100
/* 45B10 8006A710 0C01B19C */  jal       func_8006C670
/* 45B14 8006A714 34840800 */   ori      $a0, $a0, 0x800
/* 45B18 8006A718 0C01B1A4 */  jal       func_8006C690
/* 45B1C 8006A71C 3C040490 */   lui      $a0, 0x490
/* 45B20 8006A720 3C041FC0 */  lui       $a0, 0x1fc0
.L8006A724:
/* 45B24 8006A724 348407FC */  ori       $a0, $a0, 0x7fc
/* 45B28 8006A728 0C01B1E8 */  jal       func_8006C7A0
/* 45B2C 8006A72C 27A50010 */   addiu    $a1, $sp, 0x10
/* 45B30 8006A730 1440FFFC */  bnez      $v0, .L8006A724
/* 45B34 8006A734 3C041FC0 */   lui      $a0, 0x1fc0
.L8006A738:
/* 45B38 8006A738 8FA50010 */  lw        $a1, 0x10($sp)
/* 45B3C 8006A73C 3C041FC0 */  lui       $a0, 0x1fc0
/* 45B40 8006A740 348407FC */  ori       $a0, $a0, 0x7fc
/* 45B44 8006A744 0C01B1FC */  jal       func_8006C7F0
/* 45B48 8006A748 34A50008 */   ori      $a1, $a1, 8
/* 45B4C 8006A74C 1440FFFA */  bnez      $v0, .L8006A738
/* 45B50 8006A750 00000000 */   nop
/* 45B54 8006A754 3C028007 */  lui       $v0, %hi(D_8006A9D0)
/* 45B58 8006A758 2442A9D0 */  addiu     $v0, $v0, %lo(D_8006A9D0)
/* 45B5C 8006A75C 3C068000 */  lui       $a2, 0x8000
/* 45B60 8006A760 8C430000 */  lw        $v1, ($v0)
/* 45B64 8006A764 8C440004 */  lw        $a0, 4($v0)
/* 45B68 8006A768 8C450008 */  lw        $a1, 8($v0)
/* 45B6C 8006A76C ACC30000 */  sw        $v1, ($a2)
/* 45B70 8006A770 ACC40004 */  sw        $a0, 4($a2)
/* 45B74 8006A774 ACC50008 */  sw        $a1, 8($a2)
/* 45B78 8006A778 8C43000C */  lw        $v1, 0xc($v0)
/* 45B7C 8006A77C ACC3000C */  sw        $v1, 0xc($a2)
/* 45B80 8006A780 3C068000 */  lui       $a2, 0x8000
/* 45B84 8006A784 34C60080 */  ori       $a2, $a2, 0x80
/* 45B88 8006A788 8C430000 */  lw        $v1, ($v0)
/* 45B8C 8006A78C 8C440004 */  lw        $a0, 4($v0)
/* 45B90 8006A790 8C450008 */  lw        $a1, 8($v0)
/* 45B94 8006A794 ACC30000 */  sw        $v1, ($a2)
/* 45B98 8006A798 ACC40004 */  sw        $a0, 4($a2)
/* 45B9C 8006A79C ACC50008 */  sw        $a1, 8($a2)
/* 45BA0 8006A7A0 8C43000C */  lw        $v1, 0xc($v0)
/* 45BA4 8006A7A4 ACC3000C */  sw        $v1, 0xc($a2)
/* 45BA8 8006A7A8 3C068000 */  lui       $a2, 0x8000
/* 45BAC 8006A7AC 34C60100 */  ori       $a2, $a2, 0x100
/* 45BB0 8006A7B0 8C430000 */  lw        $v1, ($v0)
/* 45BB4 8006A7B4 8C440004 */  lw        $a0, 4($v0)
/* 45BB8 8006A7B8 8C450008 */  lw        $a1, 8($v0)
/* 45BBC 8006A7BC ACC30000 */  sw        $v1, ($a2)
/* 45BC0 8006A7C0 ACC40004 */  sw        $a0, 4($a2)
/* 45BC4 8006A7C4 ACC50008 */  sw        $a1, 8($a2)
/* 45BC8 8006A7C8 8C43000C */  lw        $v1, 0xc($v0)
/* 45BCC 8006A7CC ACC3000C */  sw        $v1, 0xc($a2)
/* 45BD0 8006A7D0 3C068000 */  lui       $a2, 0x8000
/* 45BD4 8006A7D4 34C60180 */  ori       $a2, $a2, 0x180
/* 45BD8 8006A7D8 8C430000 */  lw        $v1, ($v0)
/* 45BDC 8006A7DC 8C440004 */  lw        $a0, 4($v0)
/* 45BE0 8006A7E0 8C450008 */  lw        $a1, 8($v0)
/* 45BE4 8006A7E4 ACC30000 */  sw        $v1, ($a2)
/* 45BE8 8006A7E8 ACC40004 */  sw        $a0, 4($a2)
/* 45BEC 8006A7EC ACC50008 */  sw        $a1, 8($a2)
/* 45BF0 8006A7F0 8C43000C */  lw        $v1, 0xc($v0)
/* 45BF4 8006A7F4 ACC3000C */  sw        $v1, 0xc($a2)
/* 45BF8 8006A7F8 3C048000 */  lui       $a0, 0x8000
/* 45BFC 8006A7FC 0C018608 */  jal       func_80061820
/* 45C00 8006A800 24050190 */   addiu    $a1, $zero, 0x190
/* 45C04 8006A804 3C048000 */  lui       $a0, 0x8000
/* 45C08 8006A808 0C0185E8 */  jal       func_800617A0
/* 45C0C 8006A80C 24050190 */   addiu    $a1, $zero, 0x190
/* 45C10 8006A810 3C05A460 */  lui       $a1, 0xa460
/* 45C14 8006A814 34A50014 */  ori       $a1, $a1, 0x14
/* 45C18 8006A818 3C06A460 */  lui       $a2, 0xa460
/* 45C1C 8006A81C 34C60018 */  ori       $a2, $a2, 0x18
/* 45C20 8006A820 3C07A460 */  lui       $a3, 0xa460
/* 45C24 8006A824 34E7001C */  ori       $a3, $a3, 0x1c
/* 45C28 8006A828 3C08A460 */  lui       $t0, 0xa460
/* 45C2C 8006A82C 35080020 */  ori       $t0, $t0, 0x20
/* 45C30 8006A830 3C09A460 */  lui       $t1, 0xa460
/* 45C34 8006A834 35290024 */  ori       $t1, $t1, 0x24
/* 45C38 8006A838 3C04A460 */  lui       $a0, 0xa460
/* 45C3C 8006A83C 34840028 */  ori       $a0, $a0, 0x28
/* 45C40 8006A840 3C03A460 */  lui       $v1, 0xa460
/* 45C44 8006A844 3463002C */  ori       $v1, $v1, 0x2c
/* 45C48 8006A848 3C02A460 */  lui       $v0, 0xa460
/* 45C4C 8006A84C 34420030 */  ori       $v0, $v0, 0x30
/* 45C50 8006A850 8CA50000 */  lw        $a1, ($a1)
/* 45C54 8006A854 8CC60000 */  lw        $a2, ($a2)
/* 45C58 8006A858 8CE70000 */  lw        $a3, ($a3)
/* 45C5C 8006A85C 8D080000 */  lw        $t0, ($t0)
/* 45C60 8006A860 8D290000 */  lw        $t1, ($t1)
/* 45C64 8006A864 8C840000 */  lw        $a0, ($a0)
/* 45C68 8006A868 8C630000 */  lw        $v1, ($v1)
/* 45C6C 8006A86C 8C4A0000 */  lw        $t2, ($v0)
/* 45C70 8006A870 24020007 */  addiu     $v0, $zero, 7
/* 45C74 8006A874 3C01800B */  lui       $at, %hi(D_800B44FC)
/* 45C78 8006A878 A02244FC */  sb        $v0, %lo(D_800B44FC)($at)
/* 45C7C 8006A87C 3C01800B */  lui       $at, %hi(D_800B1AEC)
/* 45C80 8006A880 A0221AEC */  sb        $v0, %lo(D_800B1AEC)($at)
/* 45C84 8006A884 3C01800B */  lui       $at, %hi(D_800B44FD)
/* 45C88 8006A888 A02544FD */  sb        $a1, %lo(D_800B44FD)($at)
/* 45C8C 8006A88C 3C01800B */  lui       $at, %hi(D_800B4500)
/* 45C90 8006A890 A0264500 */  sb        $a2, %lo(D_800B4500)($at)
/* 45C94 8006A894 3C01800B */  lui       $at, %hi(D_800B44FE)
/* 45C98 8006A898 A02744FE */  sb        $a3, %lo(D_800B44FE)($at)
/* 45C9C 8006A89C 3C01800B */  lui       $at, %hi(D_800B44FF)
/* 45CA0 8006A8A0 A02844FF */  sb        $t0, %lo(D_800B44FF)($at)
/* 45CA4 8006A8A4 3C01800B */  lui       $at, %hi(D_800B1AED)
/* 45CA8 8006A8A8 A0291AED */  sb        $t1, %lo(D_800B1AED)($at)
/* 45CAC 8006A8AC 3C01800B */  lui       $at, %hi(D_800B1AF0)
/* 45CB0 8006A8B0 A0241AF0 */  sb        $a0, %lo(D_800B1AF0)($at)
/* 45CB4 8006A8B4 3C01800B */  lui       $at, %hi(D_800B1AEE)
/* 45CB8 8006A8B8 A0231AEE */  sb        $v1, %lo(D_800B1AEE)($at)
/* 45CBC 8006A8BC 3C01800B */  lui       $at, %hi(D_800B1AEF)
/* 45CC0 8006A8C0 0C019A4C */  jal       func_80066930
/* 45CC4 8006A8C4 A02A1AEF */   sb       $t2, %lo(D_800B1AEF)($at)
/* 45CC8 8006A8C8 0C01B284 */  jal       func_8006CA10
/* 45CCC 8006A8CC 00000000 */   nop
/* 45CD0 8006A8D0 3C028009 */  lui       $v0, %hi(D_80095880)
/* 45CD4 8006A8D4 8C425880 */  lw        $v0, %lo(D_80095880)($v0)
/* 45CD8 8006A8D8 3C038009 */  lui       $v1, %hi(D_80095884)
/* 45CDC 8006A8DC 8C635884 */  lw        $v1, %lo(D_80095884)($v1)
/* 45CE0 8006A8E0 00022040 */  sll       $a0, $v0, 1
/* 45CE4 8006A8E4 000337C2 */  srl       $a2, $v1, 0x1f
/* 45CE8 8006A8E8 00862025 */  or        $a0, $a0, $a2
/* 45CEC 8006A8EC 00032840 */  sll       $a1, $v1, 1
/* 45CF0 8006A8F0 00A32821 */  addu      $a1, $a1, $v1
/* 45CF4 8006A8F4 00A3302B */  sltu      $a2, $a1, $v1
/* 45CF8 8006A8F8 00822021 */  addu      $a0, $a0, $v0
/* 45CFC 8006A8FC 00862021 */  addu      $a0, $a0, $a2
/* 45D00 8006A900 24060000 */  addiu     $a2, $zero, 0
/* 45D04 8006A904 0C01B8BC */  jal       func_8006E2F0
/* 45D08 8006A908 24070004 */   addiu    $a3, $zero, 4
/* 45D0C 8006A90C 3C048000 */  lui       $a0, %hi(D_8000030C)
/* 45D10 8006A910 8C84030C */  lw        $a0, %lo(D_8000030C)($a0)
/* 45D14 8006A914 3C018009 */  lui       $at, %hi(D_80095880)
/* 45D18 8006A918 AC225880 */  sw        $v0, %lo(D_80095880)($at)
/* 45D1C 8006A91C 3C018009 */  lui       $at, %hi(D_80095884)
/* 45D20 8006A920 14800005 */  bnez      $a0, .L8006A938
/* 45D24 8006A924 AC235884 */   sw       $v1, %lo(D_80095884)($at)
/* 45D28 8006A928 3C048000 */  lui       $a0, %hi(D_8000031C)
/* 45D2C 8006A92C 2484031C */  addiu     $a0, $a0, %lo(D_8000031C)
/* 45D30 8006A930 0C019250 */  jal       func_80064940
/* 45D34 8006A934 24050040 */   addiu    $a1, $zero, 0x40
.L8006A938:
/* 45D38 8006A938 3C038000 */  lui       $v1, %hi(D_80000300)
/* 45D3C 8006A93C 8C630300 */  lw        $v1, %lo(D_80000300)($v1)
/* 45D40 8006A940 54600004 */  bnel      $v1, $zero, .L8006A954
/* 45D44 8006A944 24020002 */   addiu    $v0, $zero, 2
/* 45D48 8006A948 3C0202F5 */  lui       $v0, 0x2f5
/* 45D4C 8006A94C 0801AA5A */  j         .L8006A968
/* 45D50 8006A950 3442B2D2 */   ori      $v0, $v0, 0xb2d2
.L8006A954:
/* 45D54 8006A954 14620003 */  bne       $v1, $v0, .L8006A964
/* 45D58 8006A958 3C0202E6 */   lui      $v0, 0x2e6
/* 45D5C 8006A95C 0801AA5A */  j         .L8006A968
/* 45D60 8006A960 3442025C */   ori      $v0, $v0, 0x25c
.L8006A964:
/* 45D64 8006A964 3442D354 */  ori       $v0, $v0, 0xd354
.L8006A968:
/* 45D68 8006A968 3C018009 */  lui       $at, %hi(D_80095888)
/* 45D6C 8006A96C 0C01B190 */  jal       func_8006C640
/* 45D70 8006A970 AC225888 */   sw       $v0, %lo(D_80095888)($at)
/* 45D74 8006A974 30421000 */  andi      $v0, $v0, 0x1000
/* 45D78 8006A978 10400003 */  beqz      $v0, .L8006A988
/* 45D7C 8006A97C 3C03A450 */   lui      $v1, 0xa450
.L8006A980:
/* 45D80 8006A980 0801AA60 */  j         .L8006A980
/* 45D84 8006A984 00000000 */   nop
.L8006A988:
/* 45D88 8006A988 34630008 */  ori       $v1, $v1, 8
/* 45D8C 8006A98C 3C04A450 */  lui       $a0, 0xa450
/* 45D90 8006A990 34840010 */  ori       $a0, $a0, 0x10
/* 45D94 8006A994 3C05A450 */  lui       $a1, 0xa450
/* 45D98 8006A998 34A50014 */  ori       $a1, $a1, 0x14
/* 45D9C 8006A99C 24020001 */  addiu     $v0, $zero, 1
/* 45DA0 8006A9A0 AC620000 */  sw        $v0, ($v1)
/* 45DA4 8006A9A4 24023FFF */  addiu     $v0, $zero, 0x3fff
/* 45DA8 8006A9A8 AC820000 */  sw        $v0, ($a0)
/* 45DAC 8006A9AC 2402000F */  addiu     $v0, $zero, 0xf
/* 45DB0 8006A9B0 ACA20000 */  sw        $v0, ($a1)
/* 45DB4 8006A9B4 8FBF0018 */  lw        $ra, 0x18($sp)
/* 45DB8 8006A9B8 03E00008 */  jr        $ra
/* 45DBC 8006A9BC 27BD0020 */   addiu    $sp, $sp, 0x20
