.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800364D4
/* 118D4 800364D4 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 118D8 800364D8 AFB10014 */  sw        $s1, 0x14($sp)
/* 118DC 800364DC 3C118011 */  lui       $s1, %hi(D_8010F450)
/* 118E0 800364E0 2631F450 */  addiu     $s1, $s1, %lo(D_8010F450)
/* 118E4 800364E4 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 118E8 800364E8 8C42417C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 118EC 800364EC 2404FFFF */  addiu     $a0, $zero, -1
/* 118F0 800364F0 AFBF0018 */  sw        $ra, 0x18($sp)
/* 118F4 800364F4 AFB00010 */  sw        $s0, 0x10($sp)
/* 118F8 800364F8 F7B40020 */  sdc1      $f20, 0x20($sp)
/* 118FC 800364FC 804300A8 */  lb        $v1, 0xa8($v0)
/* 11900 80036500 1064002F */  beq       $v1, $a0, .L800365C0
/* 11904 80036504 8C450010 */   lw       $a1, 0x10($v0)
/* 11908 80036508 3C03800A */  lui       $v1, %hi(D_8009E774)
/* 1190C 8003650C 2463E774 */  addiu     $v1, $v1, %lo(D_8009E774)
/* 11910 80036510 8C620000 */  lw        $v0, ($v1)
/* 11914 80036514 14400004 */  bnez      $v0, .L80036528
/* 11918 80036518 30A2F000 */   andi     $v0, $a1, 0xf000
/* 1191C 8003651C 10400002 */  beqz      $v0, .L80036528
/* 11920 80036520 24020001 */   addiu    $v0, $zero, 1
/* 11924 80036524 AC620000 */  sw        $v0, ($v1)
.L80036528:
/* 11928 80036528 3C03800A */  lui       $v1, %hi(D_8009E774)
/* 1192C 8003652C 8C63E774 */  lw        $v1, %lo(D_8009E774)($v1)
/* 11930 80036530 24020001 */  addiu     $v0, $zero, 1
/* 11934 80036534 14620010 */  bne       $v1, $v0, .L80036578
/* 11938 80036538 24020002 */   addiu    $v0, $zero, 2
/* 1193C 8003653C 3C048007 */  lui       $a0, %hi(gGameStatusPtr)
/* 11940 80036540 8C84417C */  lw        $a0, %lo(gGameStatusPtr)($a0)
/* 11944 80036544 908300AC */  lbu       $v1, 0xac($a0)
/* 11948 80036548 2C620002 */  sltiu     $v0, $v1, 2
/* 1194C 8003654C 14400018 */  bnez      $v0, .L800365B0
/* 11950 80036550 24020064 */   addiu    $v0, $zero, 0x64
/* 11954 80036554 00031600 */  sll       $v0, $v1, 0x18
/* 11958 80036558 00021603 */  sra       $v0, $v0, 0x18
/* 1195C 8003655C 24030004 */  addiu     $v1, $zero, 4
/* 11960 80036560 14430003 */  bne       $v0, $v1, .L80036570
/* 11964 80036564 24020002 */   addiu    $v0, $zero, 2
/* 11968 80036568 0800D96C */  j         .L800365B0
/* 1196C 8003656C 24020064 */   addiu    $v0, $zero, 0x64
.L80036570:
/* 11970 80036570 3C03800A */  lui       $v1, %hi(D_8009E774)
/* 11974 80036574 8C63E774 */  lw        $v1, %lo(D_8009E774)($v1)
.L80036578:
/* 11978 80036578 14620011 */  bne       $v1, $v0, .L800365C0
/* 1197C 8003657C 00000000 */   nop
/* 11980 80036580 3C048007 */  lui       $a0, %hi(gGameStatusPtr)
/* 11984 80036584 8C84417C */  lw        $a0, %lo(gGameStatusPtr)($a0)
/* 11988 80036588 908300AC */  lbu       $v1, 0xac($a0)
/* 1198C 8003658C 2C620002 */  sltiu     $v0, $v1, 2
/* 11990 80036590 14400005 */  bnez      $v0, .L800365A8
/* 11994 80036594 00031600 */   sll      $v0, $v1, 0x18
/* 11998 80036598 00021603 */  sra       $v0, $v0, 0x18
/* 1199C 8003659C 24030004 */  addiu     $v1, $zero, 4
/* 119A0 800365A0 14430007 */  bne       $v0, $v1, .L800365C0
/* 119A4 800365A4 00000000 */   nop
.L800365A8:
/* 119A8 800365A8 908200A8 */  lbu       $v0, 0xa8($a0)
/* 119AC 800365AC 24420001 */  addiu     $v0, $v0, 1
.L800365B0:
/* 119B0 800365B0 0C00D8B4 */  jal       func_800362D0
/* 119B4 800365B4 A08200A8 */   sb       $v0, 0xa8($a0)
/* 119B8 800365B8 0800DA92 */  j         .L80036A48
/* 119BC 800365BC 00000000 */   nop
.L800365C0:
/* 119C0 800365C0 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 119C4 800365C4 8C42417C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 119C8 800365C8 804300AC */  lb        $v1, 0xac($v0)
/* 119CC 800365CC 2C620016 */  sltiu     $v0, $v1, 0x16
/* 119D0 800365D0 10400109 */  beqz      $v0, .L800369F8
/* 119D4 800365D4 00031080 */   sll      $v0, $v1, 2
/* 119D8 800365D8 3C01800A */  lui       $at, %hi(D_80098318)
/* 119DC 800365DC 00220821 */  addu      $at, $at, $v0
/* 119E0 800365E0 8C228318 */  lw        $v0, %lo(D_80098318)($at)
/* 119E4 800365E4 00400008 */  jr        $v0
/* 119E8 800365E8 00000000 */   nop
/* 119EC 800365EC 0C016680 */  jal       func_80059A00
/* 119F0 800365F0 00000000 */   nop
/* 119F4 800365F4 0C00B424 */  jal       func_8002D090
/* 119F8 800365F8 00000000 */   nop
/* 119FC 800365FC 3C108007 */  lui       $s0, %hi(gGameStatusPtr)
/* 11A00 80036600 2610417C */  addiu     $s0, $s0, %lo(gGameStatusPtr)
/* 11A04 80036604 8E060000 */  lw        $a2, ($s0)
/* 11A08 80036608 80C300A8 */  lb        $v1, 0xa8($a2)
/* 11A0C 8003660C 2402FFFF */  addiu     $v0, $zero, -1
/* 11A10 80036610 14620010 */  bne       $v1, $v0, .L80036654
/* 11A14 80036614 00000000 */   nop
/* 11A18 80036618 44806000 */  mtc1      $zero, $f12
/* 11A1C 8003661C 0C00AFB5 */  jal       func_8002BED4
/* 11A20 80036620 00000000 */   nop
/* 11A24 80036624 3C04800A */  lui       $a0, %hi(D_8009E766)
/* 11A28 80036628 8484E766 */  lh        $a0, %lo(D_8009E766)($a0)
/* 11A2C 8003662C 0C00CD30 */  jal       func_800334C0
/* 11A30 80036630 00000000 */   nop
/* 11A34 80036634 104000F0 */  beqz      $v0, .L800369F8
/* 11A38 80036638 24020001 */   addiu    $v0, $zero, 1
/* 11A3C 8003663C 0000202D */  daddu     $a0, $zero, $zero
/* 11A40 80036640 8E030000 */  lw        $v1, ($s0)
/* 11A44 80036644 0C00AFB1 */  jal       func_8002BEC4
/* 11A48 80036648 A06200AC */   sb       $v0, 0xac($v1)
/* 11A4C 8003664C 0800DA7E */  j         .L800369F8
/* 11A50 80036650 00000000 */   nop
.L80036654:
/* 11A54 80036654 3C05800A */  lui       $a1, %hi(D_8009E764)
/* 11A58 80036658 24A5E764 */  addiu     $a1, $a1, %lo(D_8009E764)
/* 11A5C 8003665C 94A20000 */  lhu       $v0, ($a1)
/* 11A60 80036660 3C03800A */  lui       $v1, %hi(D_8009E766)
/* 11A64 80036664 9463E766 */  lhu       $v1, %lo(D_8009E766)($v1)
/* 11A68 80036668 00431021 */  addu      $v0, $v0, $v1
/* 11A6C 8003666C A4A20000 */  sh        $v0, ($a1)
/* 11A70 80036670 00021400 */  sll       $v0, $v0, 0x10
/* 11A74 80036674 00021403 */  sra       $v0, $v0, 0x10
/* 11A78 80036678 284200FF */  slti      $v0, $v0, 0xff
/* 11A7C 8003667C 144000DE */  bnez      $v0, .L800369F8
/* 11A80 80036680 240200FF */   addiu    $v0, $zero, 0xff
/* 11A84 80036684 0000202D */  daddu     $a0, $zero, $zero
/* 11A88 80036688 A4A20000 */  sh        $v0, ($a1)
/* 11A8C 8003668C 24020001 */  addiu     $v0, $zero, 1
/* 11A90 80036690 0C00AFB1 */  jal       func_8002BEC4
/* 11A94 80036694 A0C200AC */   sb       $v0, 0xac($a2)
/* 11A98 80036698 0800DA7E */  j         .L800369F8
/* 11A9C 8003669C 00000000 */   nop
/* 11AA0 800366A0 3C04800A */  lui       $a0, %hi(D_8009A630)
/* 11AA4 800366A4 2484A630 */  addiu     $a0, $a0, %lo(D_8009A630)
/* 11AA8 800366A8 8C820000 */  lw        $v0, ($a0)
/* 11AAC 800366AC 24030004 */  addiu     $v1, $zero, 4
/* 11AB0 800366B0 3C01800A */  lui       $at, %hi(D_8009E760)
/* 11AB4 800366B4 AC23E760 */  sw        $v1, %lo(D_8009E760)($at)
/* 11AB8 800366B8 34420008 */  ori       $v0, $v0, 8
/* 11ABC 800366BC AC820000 */  sw        $v0, ($a0)
/* 11AC0 800366C0 3C03800A */  lui       $v1, %hi(D_8009E770)
/* 11AC4 800366C4 8C63E770 */  lw        $v1, %lo(D_8009E770)($v1)
/* 11AC8 800366C8 2402000E */  addiu     $v0, $zero, 0xe
/* 11ACC 800366CC 106200CA */  beq       $v1, $v0, .L800369F8
/* 11AD0 800366D0 00000000 */   nop
/* 11AD4 800366D4 0800D9C3 */  j         .L8003670C
/* 11AD8 800366D8 00000000 */   nop
/* 11ADC 800366DC 3C03800A */  lui       $v1, %hi(D_8009E760)
/* 11AE0 800366E0 2463E760 */  addiu     $v1, $v1, %lo(D_8009E760)
/* 11AE4 800366E4 8C620000 */  lw        $v0, ($v1)
/* 11AE8 800366E8 2442FFFF */  addiu     $v0, $v0, -1
/* 11AEC 800366EC 1C4000C2 */  bgtz      $v0, .L800369F8
/* 11AF0 800366F0 AC620000 */   sw       $v0, ($v1)
/* 11AF4 800366F4 3C04800A */  lui       $a0, %hi(D_8009A630)
/* 11AF8 800366F8 2484A630 */  addiu     $a0, $a0, %lo(D_8009A630)
/* 11AFC 800366FC 8C820000 */  lw        $v0, ($a0)
/* 11B00 80036700 2403FFF7 */  addiu     $v1, $zero, -9
/* 11B04 80036704 00431024 */  and       $v0, $v0, $v1
/* 11B08 80036708 AC820000 */  sw        $v0, ($a0)
.L8003670C:
/* 11B0C 8003670C 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* 11B10 80036710 8C63417C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* 11B14 80036714 24020002 */  addiu     $v0, $zero, 2
/* 11B18 80036718 0800DA7E */  j         .L800369F8
/* 11B1C 8003671C A06200AC */   sb       $v0, 0xac($v1)
/* 11B20 80036720 0C00AFB1 */  jal       func_8002BEC4
/* 11B24 80036724 0000202D */   daddu    $a0, $zero, $zero
/* 11B28 80036728 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* 11B2C 8003672C 2463417C */  addiu     $v1, $v1, %lo(gGameStatusPtr)
/* 11B30 80036730 8C620000 */  lw        $v0, ($v1)
/* 11B34 80036734 A0400070 */  sb        $zero, 0x70($v0)
/* 11B38 80036738 8C620000 */  lw        $v0, ($v1)
/* 11B3C 8003673C A0400076 */  sb        $zero, 0x76($v0)
/* 11B40 80036740 8C620000 */  lw        $v0, ($v1)
/* 11B44 80036744 A0400078 */  sb        $zero, 0x78($v0)
/* 11B48 80036748 8C620000 */  lw        $v0, ($v1)
/* 11B4C 8003674C A040007D */  sb        $zero, 0x7d($v0)
/* 11B50 80036750 8C620000 */  lw        $v0, ($v1)
/* 11B54 80036754 804200A8 */  lb        $v0, 0xa8($v0)
/* 11B58 80036758 2405FFFF */  addiu     $a1, $zero, -1
/* 11B5C 8003675C 14450037 */  bne       $v0, $a1, .L8003683C
/* 11B60 80036760 2404000B */   addiu    $a0, $zero, 0xb
/* 11B64 80036764 0C00AAF0 */  jal       func_8002ABC0
/* 11B68 80036768 00000000 */   nop
/* 11B6C 8003676C 0C048AA8 */  jal       func_80122AA0
/* 11B70 80036770 00000000 */   nop
/* 11B74 80036774 0C04A0B2 */  jal       func_801282C8
/* 11B78 80036778 00000000 */   nop
/* 11B7C 8003677C 0C0B0C77 */  jal       func_802C31DC
/* 11B80 80036780 00000000 */   nop
/* 11B84 80036784 0C00B6E1 */  jal       func_8002DB84
/* 11B88 80036788 00000000 */   nop
/* 11B8C 8003678C 0C044512 */  jal       func_80111448
/* 11B90 80036790 0000202D */   daddu    $a0, $zero, $zero
/* 11B94 80036794 0C049770 */  jal       func_80125DC0
/* 11B98 80036798 00000000 */   nop
/* 11B9C 8003679C 0C048D0D */  jal       func_80123434
/* 11BA0 800367A0 00000000 */   nop
/* 11BA4 800367A4 0C046BD5 */  jal       func_8011AF54
/* 11BA8 800367A8 00000000 */   nop
/* 11BAC 800367AC 0C05343C */  jal       func_8014D0F0
/* 11BB0 800367B0 00000000 */   nop
/* 11BB4 800367B4 0C052BAA */  jal       func_8014AEA8
/* 11BB8 800367B8 00000000 */   nop
/* 11BBC 800367BC 0C05186C */  jal       func_801461B0
/* 11BC0 800367C0 00000000 */   nop
/* 11BC4 800367C4 0C0529CC */  jal       func_8014A730
/* 11BC8 800367C8 00000000 */   nop
/* 11BCC 800367CC 0C04A221 */  jal       func_80128884
/* 11BD0 800367D0 00000000 */   nop
/* 11BD4 800367D4 0C0457B2 */  jal       func_80115EC8
/* 11BD8 800367D8 0000202D */   daddu    $a0, $zero, $zero
/* 11BDC 800367DC 0C04F46E */  jal       func_8013D1B8
/* 11BE0 800367E0 00000000 */   nop
/* 11BE4 800367E4 0C037F0C */  jal       func_800DFC30
/* 11BE8 800367E8 00000000 */   nop
/* 11BEC 800367EC 0C00E05F */  jal       func_8003817C
/* 11BF0 800367F0 00000000 */   nop
/* 11BF4 800367F4 0C039CD0 */  jal       func_800E7340
/* 11BF8 800367F8 00000000 */   nop
/* 11BFC 800367FC 0C01CAC4 */  jal       func_80072B10
/* 11C00 80036800 00000000 */   nop
/* 11C04 80036804 0C00F7FE */  jal       func_8003DFF8
/* 11C08 80036808 00000000 */   nop
/* 11C0C 8003680C 0C016653 */  jal       func_8005994C
/* 11C10 80036810 00000000 */   nop
/* 11C14 80036814 0C04D85C */  jal       func_80136170
/* 11C18 80036818 00000000 */   nop
/* 11C1C 8003681C 0C0528F4 */  jal       func_8014A3D0
/* 11C20 80036820 00000000 */   nop
/* 11C24 80036824 0C016B11 */  jal       func_8005AC44
/* 11C28 80036828 00000000 */   nop
/* 11C2C 8003682C 0C00CC60 */  jal       func_80033180
/* 11C30 80036830 24040002 */   addiu    $a0, $zero, 2
/* 11C34 80036834 0800DA92 */  j         .L80036A48
/* 11C38 80036838 00000000 */   nop
.L8003683C:
/* 11C3C 8003683C 26230058 */  addiu     $v1, $s1, 0x58
/* 11C40 80036840 2402000A */  addiu     $v0, $zero, 0xa
/* 11C44 80036844 A2220002 */  sb        $v0, 2($s1)
/* 11C48 80036848 A2220003 */  sb        $v0, 3($s1)
/* 11C4C 8003684C A2220004 */  sb        $v0, 4($s1)
/* 11C50 80036850 24020005 */  addiu     $v0, $zero, 5
/* 11C54 80036854 A2220005 */  sb        $v0, 5($s1)
/* 11C58 80036858 A2220006 */  sb        $v0, 6($s1)
/* 11C5C 8003685C A2220007 */  sb        $v0, 7($s1)
/* 11C60 80036860 24020002 */  addiu     $v0, $zero, 2
/* 11C64 80036864 A2220008 */  sb        $v0, 8($s1)
/* 11C68 80036868 A2200000 */  sb        $zero, ($s1)
/* 11C6C 8003686C A2250001 */  sb        $a1, 1($s1)
/* 11C70 80036870 A220000E */  sb        $zero, 0xe($s1)
/* 11C74 80036874 A2200009 */  sb        $zero, 9($s1)
.L80036878:
/* 11C78 80036878 A0600014 */  sb        $zero, 0x14($v1)
/* 11C7C 8003687C 2484FFFF */  addiu     $a0, $a0, -1
/* 11C80 80036880 0481FFFD */  bgez      $a0, .L80036878
/* 11C84 80036884 2463FFF8 */   addiu    $v1, $v1, -8
/* 11C88 80036888 3C108007 */  lui       $s0, %hi(gGameStatusPtr)
/* 11C8C 8003688C 2610417C */  addiu     $s0, $s0, %lo(gGameStatusPtr)
/* 11C90 80036890 8E020000 */  lw        $v0, ($s0)
/* 11C94 80036894 A2200012 */  sb        $zero, 0x12($s1)
/* 11C98 80036898 84440086 */  lh        $a0, 0x86($v0)
/* 11C9C 8003689C 8445008C */  lh        $a1, 0x8c($v0)
/* 11CA0 800368A0 0C0168E9 */  jal       func_8005A3A4
/* 11CA4 800368A4 0000302D */   daddu    $a2, $zero, $zero
/* 11CA8 800368A8 8E030000 */  lw        $v1, ($s0)
/* 11CAC 800368AC 24020003 */  addiu     $v0, $zero, 3
/* 11CB0 800368B0 0C038056 */  jal       func_800E0158
/* 11CB4 800368B4 A06200AC */   sb       $v0, 0xac($v1)
/* 11CB8 800368B8 0800DA7E */  j         .L800369F8
/* 11CBC 800368BC 00000000 */   nop
/* 11CC0 800368C0 3C04800A */  lui       $a0, %hi(D_8009E770)
/* 11CC4 800368C4 2484E770 */  addiu     $a0, $a0, %lo(D_8009E770)
/* 11CC8 800368C8 8C830000 */  lw        $v1, ($a0)
/* 11CCC 800368CC 2402000E */  addiu     $v0, $zero, 0xe
/* 11CD0 800368D0 14620004 */  bne       $v1, $v0, .L800368E4
/* 11CD4 800368D4 240200FF */   addiu    $v0, $zero, 0xff
/* 11CD8 800368D8 2402000F */  addiu     $v0, $zero, 0xf
/* 11CDC 800368DC AC820000 */  sw        $v0, ($a0)
/* 11CE0 800368E0 240200FF */  addiu     $v0, $zero, 0xff
.L800368E4:
/* 11CE4 800368E4 3C04800A */  lui       $a0, %hi(D_8009A630)
/* 11CE8 800368E8 2484A630 */  addiu     $a0, $a0, %lo(D_8009A630)
/* 11CEC 800368EC 2405FFF7 */  addiu     $a1, $zero, -9
/* 11CF0 800368F0 3C03800A */  lui       $v1, %hi(D_8009E768)
/* 11CF4 800368F4 9463E768 */  lhu       $v1, %lo(D_8009E768)($v1)
/* 11CF8 800368F8 3C06800B */  lui       $a2, %hi(D_800B1D60)
/* 11CFC 800368FC 24C61D60 */  addiu     $a2, $a2, %lo(D_800B1D60)
/* 11D00 80036900 00431023 */  subu      $v0, $v0, $v1
/* 11D04 80036904 3C01800A */  lui       $at, %hi(D_8009E764)
/* 11D08 80036908 A422E764 */  sh        $v0, %lo(D_8009E764)($at)
/* 11D0C 8003690C 8C830000 */  lw        $v1, ($a0)
/* 11D10 80036910 94C20000 */  lhu       $v0, ($a2)
/* 11D14 80036914 00651824 */  and       $v1, $v1, $a1
/* 11D18 80036918 3042FFFD */  andi      $v0, $v0, 0xfffd
/* 11D1C 8003691C AC830000 */  sw        $v1, ($a0)
/* 11D20 80036920 A4C20000 */  sh        $v0, ($a2)
/* 11D24 80036924 2402FFFD */  addiu     $v0, $zero, -3
/* 11D28 80036928 00621824 */  and       $v1, $v1, $v0
/* 11D2C 8003692C 0C037DC8 */  jal       func_800DF720
/* 11D30 80036930 AC830000 */   sw       $v1, ($a0)
/* 11D34 80036934 0C00F879 */  jal       func_8003E1E4
/* 11D38 80036938 00000000 */   nop
/* 11D3C 8003693C 0C00E57C */  jal       func_800395F0
/* 11D40 80036940 00000000 */   nop
/* 11D44 80036944 0C016680 */  jal       func_80059A00
/* 11D48 80036948 00000000 */   nop
/* 11D4C 8003694C 0C00B424 */  jal       func_8002D090
/* 11D50 80036950 00000000 */   nop
/* 11D54 80036954 3C108007 */  lui       $s0, %hi(gGameStatusPtr)
/* 11D58 80036958 2610417C */  addiu     $s0, $s0, %lo(gGameStatusPtr)
/* 11D5C 8003695C 8E020000 */  lw        $v0, ($s0)
/* 11D60 80036960 0C0B1059 */  jal       func_802C4164
/* 11D64 80036964 8C44006C */   lw       $a0, 0x6c($v0)
/* 11D68 80036968 14400037 */  bnez      $v0, .L80036A48
/* 11D6C 8003696C 24030004 */   addiu    $v1, $zero, 4
/* 11D70 80036970 8E020000 */  lw        $v0, ($s0)
/* 11D74 80036974 94440086 */  lhu       $a0, 0x86($v0)
/* 11D78 80036978 A04300AC */  sb        $v1, 0xac($v0)
/* 11D7C 8003697C 0800DA7E */  j         .L800369F8
/* 11D80 80036980 A4440088 */   sh       $a0, 0x88($v0)
/* 11D84 80036984 0C016680 */  jal       func_80059A00
/* 11D88 80036988 00000000 */   nop
/* 11D8C 8003698C 0C00B424 */  jal       func_8002D090
/* 11D90 80036990 00000000 */   nop
/* 11D94 80036994 0C00E57C */  jal       func_800395F0
/* 11D98 80036998 00000000 */   nop
/* 11D9C 8003699C 3C04800A */  lui       $a0, %hi(D_8009E764)
/* 11DA0 800369A0 2484E764 */  addiu     $a0, $a0, %lo(D_8009E764)
/* 11DA4 800369A4 84820000 */  lh        $v0, ($a0)
/* 11DA8 800369A8 1440000C */  bnez      $v0, .L800369DC
/* 11DAC 800369AC 94830000 */   lhu      $v1, ($a0)
/* 11DB0 800369B0 3C01BF80 */  lui       $at, 0xbf80
/* 11DB4 800369B4 4481A000 */  mtc1      $at, $f20
/* 11DB8 800369B8 00000000 */  nop
/* 11DBC 800369BC 4405A000 */  mfc1      $a1, $f20
/* 11DC0 800369C0 0C04F38E */  jal       func_8013CE38
/* 11DC4 800369C4 240400FF */   addiu    $a0, $zero, 0xff
/* 11DC8 800369C8 4405A000 */  mfc1      $a1, $f20
/* 11DCC 800369CC 0C04F395 */  jal       func_8013CE54
/* 11DD0 800369D0 240400FF */   addiu    $a0, $zero, 0xff
/* 11DD4 800369D4 0800DA7E */  j         .L800369F8
/* 11DD8 800369D8 00000000 */   nop
.L800369DC:
/* 11DDC 800369DC 3C02800A */  lui       $v0, %hi(D_8009E768)
/* 11DE0 800369E0 9442E768 */  lhu       $v0, %lo(D_8009E768)($v0)
/* 11DE4 800369E4 00621023 */  subu      $v0, $v1, $v0
/* 11DE8 800369E8 A4820000 */  sh        $v0, ($a0)
/* 11DEC 800369EC 00021400 */  sll       $v0, $v0, 0x10
/* 11DF0 800369F0 04420001 */  bltzl     $v0, .L800369F8
/* 11DF4 800369F4 A4800000 */   sh       $zero, ($a0)
.L800369F8:
/* 11DF8 800369F8 3C02800A */  lui       $v0, %hi(D_8009E764)
/* 11DFC 800369FC 8442E764 */  lh        $v0, %lo(D_8009E764)($v0)
/* 11E00 80036A00 3C04800A */  lui       $a0, %hi(D_8009E773)
/* 11E04 80036A04 9084E773 */  lbu       $a0, %lo(D_8009E773)($a0)
/* 11E08 80036A08 44820000 */  mtc1      $v0, $f0
/* 11E0C 80036A0C 00000000 */  nop
/* 11E10 80036A10 46800020 */  cvt.s.w   $f0, $f0
/* 11E14 80036A14 44050000 */  mfc1      $a1, $f0
/* 11E18 80036A18 0C04F395 */  jal       func_8013CE54
/* 11E1C 80036A1C 00000000 */   nop
/* 11E20 80036A20 3C05800A */  lui       $a1, %hi(D_8009E76B)
/* 11E24 80036A24 90A5E76B */  lbu       $a1, %lo(D_8009E76B)($a1)
/* 11E28 80036A28 3C06800A */  lui       $a2, %hi(D_8009E76D)
/* 11E2C 80036A2C 90C6E76D */  lbu       $a2, %lo(D_8009E76D)($a2)
/* 11E30 80036A30 3C07800A */  lui       $a3, %hi(D_8009E76F)
/* 11E34 80036A34 90E7E76F */  lbu       $a3, %lo(D_8009E76F)($a3)
/* 11E38 80036A38 0C04F3B0 */  jal       func_8013CEC0
/* 11E3C 80036A3C 24040001 */   addiu    $a0, $zero, 1
/* 11E40 80036A40 0C00CD41 */  jal       func_80033504
/* 11E44 80036A44 00000000 */   nop
.L80036A48:
/* 11E48 80036A48 8FBF0018 */  lw        $ra, 0x18($sp)
/* 11E4C 80036A4C 8FB10014 */  lw        $s1, 0x14($sp)
/* 11E50 80036A50 8FB00010 */  lw        $s0, 0x10($sp)
/* 11E54 80036A54 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 11E58 80036A58 03E00008 */  jr        $ra
/* 11E5C 80036A5C 27BD0028 */   addiu    $sp, $sp, 0x28
