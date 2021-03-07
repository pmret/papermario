.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel _use_partner_ability
/* 83B7C 800EA6CC 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 83B80 800EA6D0 AFB3001C */  sw        $s3, 0x1c($sp)
/* 83B84 800EA6D4 3C138011 */  lui       $s3, %hi(gPlayerData)
/* 83B88 800EA6D8 2673F290 */  addiu     $s3, $s3, %lo(gPlayerData)
/* 83B8C 800EA6DC 3C058011 */  lui       $a1, %hi(D_8010EBB0)
/* 83B90 800EA6E0 24A5EBB0 */  addiu     $a1, $a1, %lo(D_8010EBB0)
/* 83B94 800EA6E4 AFBF0020 */  sw        $ra, 0x20($sp)
/* 83B98 800EA6E8 AFB20018 */  sw        $s2, 0x18($sp)
/* 83B9C 800EA6EC AFB10014 */  sw        $s1, 0x14($sp)
/* 83BA0 800EA6F0 AFB00010 */  sw        $s0, 0x10($sp)
/* 83BA4 800EA6F4 80A20014 */  lb        $v0, 0x14($a1)
/* 83BA8 800EA6F8 3C068011 */  lui       $a2, %hi(gPlayerStatus)
/* 83BAC 800EA6FC 24C6EFC8 */  addiu     $a2, $a2, %lo(gPlayerStatus)
/* 83BB0 800EA700 5440001F */  bnel      $v0, $zero, .L800EA780
/* 83BB4 800EA704 A4A00004 */   sh       $zero, 4($a1)
/* 83BB8 800EA708 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* 83BBC 800EA70C 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* 83BC0 800EA710 80620081 */  lb        $v0, 0x81($v1)
/* 83BC4 800EA714 00621021 */  addu      $v0, $v1, $v0
/* 83BC8 800EA718 90420040 */  lbu       $v0, 0x40($v0)
/* 83BCC 800EA71C 00021600 */  sll       $v0, $v0, 0x18
/* 83BD0 800EA720 00021603 */  sra       $v0, $v0, 0x18
/* 83BD4 800EA724 A4A20004 */  sh        $v0, 4($a1)
/* 83BD8 800EA728 80620081 */  lb        $v0, 0x81($v1)
/* 83BDC 800EA72C 00621021 */  addu      $v0, $v1, $v0
/* 83BE0 800EA730 90420044 */  lbu       $v0, 0x44($v0)
/* 83BE4 800EA734 00021600 */  sll       $v0, $v0, 0x18
/* 83BE8 800EA738 00021603 */  sra       $v0, $v0, 0x18
/* 83BEC 800EA73C A4A20006 */  sh        $v0, 6($a1)
/* 83BF0 800EA740 80620081 */  lb        $v0, 0x81($v1)
/* 83BF4 800EA744 00021080 */  sll       $v0, $v0, 2
/* 83BF8 800EA748 00621021 */  addu      $v0, $v1, $v0
/* 83BFC 800EA74C 8C420000 */  lw        $v0, ($v0)
/* 83C00 800EA750 ACA20008 */  sw        $v0, 8($a1)
/* 83C04 800EA754 80620081 */  lb        $v0, 0x81($v1)
/* 83C08 800EA758 00021080 */  sll       $v0, $v0, 2
/* 83C0C 800EA75C 00621021 */  addu      $v0, $v1, $v0
/* 83C10 800EA760 8C420010 */  lw        $v0, 0x10($v0)
/* 83C14 800EA764 ACA2000C */  sw        $v0, 0xc($a1)
/* 83C18 800EA768 80620081 */  lb        $v0, 0x81($v1)
/* 83C1C 800EA76C 00021080 */  sll       $v0, $v0, 2
/* 83C20 800EA770 00621821 */  addu      $v1, $v1, $v0
/* 83C24 800EA774 8C620020 */  lw        $v0, 0x20($v1)
/* 83C28 800EA778 0803A9E4 */  j         .L800EA790
/* 83C2C 800EA77C ACA20010 */   sw       $v0, 0x10($a1)
.L800EA780:
/* 83C30 800EA780 A4A00006 */  sh        $zero, 6($a1)
/* 83C34 800EA784 ACA00008 */  sw        $zero, 8($a1)
/* 83C38 800EA788 ACA0000C */  sw        $zero, 0xc($a1)
/* 83C3C 800EA78C ACA00010 */  sw        $zero, 0x10($a1)
.L800EA790:
/* 83C40 800EA790 8CC40004 */  lw        $a0, 4($a2)
/* 83C44 800EA794 30820004 */  andi      $v0, $a0, 4
/* 83C48 800EA798 1040000A */  beqz      $v0, .L800EA7C4
/* 83C4C 800EA79C 2402FFFB */   addiu    $v0, $zero, -5
/* 83C50 800EA7A0 8CA3000C */  lw        $v1, 0xc($a1)
/* 83C54 800EA7A4 00821024 */  and       $v0, $a0, $v0
/* 83C58 800EA7A8 ACC20004 */  sw        $v0, 4($a2)
/* 83C5C 800EA7AC 34634004 */  ori       $v1, $v1, 0x4004
/* 83C60 800EA7B0 ACA3000C */  sw        $v1, 0xc($a1)
/* 83C64 800EA7B4 8CC20004 */  lw        $v0, 4($a2)
/* 83C68 800EA7B8 3C034000 */  lui       $v1, 0x4000
/* 83C6C 800EA7BC 00431025 */  or        $v0, $v0, $v1
/* 83C70 800EA7C0 ACC20004 */  sw        $v0, 4($a2)
.L800EA7C4:
/* 83C74 800EA7C4 3C038011 */  lui       $v1, %hi(D_8010CFE8)
/* 83C78 800EA7C8 2463CFE8 */  addiu     $v1, $v1, %lo(D_8010CFE8)
/* 83C7C 800EA7CC 8C620000 */  lw        $v0, ($v1)
/* 83C80 800EA7D0 10400006 */  beqz      $v0, .L800EA7EC
/* 83C84 800EA7D4 00000000 */   nop
/* 83C88 800EA7D8 3C018011 */  lui       $at, %hi(D_8010CD30)
/* 83C8C 800EA7DC AC22CD30 */  sw        $v0, %lo(D_8010CD30)($at)
/* 83C90 800EA7E0 3C018011 */  lui       $at, %hi(D_8010CD34)
/* 83C94 800EA7E4 AC20CD34 */  sw        $zero, %lo(D_8010CD34)($at)
/* 83C98 800EA7E8 AC600000 */  sw        $zero, ($v1)
.L800EA7EC:
/* 83C9C 800EA7EC 3C038011 */  lui       $v1, %hi(D_8010CD30)
/* 83CA0 800EA7F0 8C63CD30 */  lw        $v1, %lo(D_8010CD30)($v1)
/* 83CA4 800EA7F4 2C620002 */  sltiu     $v0, $v1, 2
/* 83CA8 800EA7F8 14400009 */  bnez      $v0, .L800EA820
/* 83CAC 800EA7FC 2C62000B */   sltiu    $v0, $v1, 0xb
/* 83CB0 800EA800 24020008 */  addiu     $v0, $zero, 8
/* 83CB4 800EA804 10620006 */  beq       $v1, $v0, .L800EA820
/* 83CB8 800EA808 2C62000B */   sltiu    $v0, $v1, 0xb
/* 83CBC 800EA80C 3C018011 */  lui       $at, %hi(D_8010CFC4)
/* 83CC0 800EA810 AC20CFC4 */  sw        $zero, %lo(D_8010CFC4)($at)
/* 83CC4 800EA814 3C038011 */  lui       $v1, %hi(D_8010CD30)
/* 83CC8 800EA818 8C63CD30 */  lw        $v1, %lo(D_8010CD30)($v1)
/* 83CCC 800EA81C 2C62000B */  sltiu     $v0, $v1, 0xb
.L800EA820:
/* 83CD0 800EA820 1040024A */  beqz      $v0, L800EB14C_845FC
/* 83CD4 800EA824 00031080 */   sll      $v0, $v1, 2
/* 83CD8 800EA828 3C018011 */  lui       $at, %hi(jtbl_8010C118)
/* 83CDC 800EA82C 00220821 */  addu      $at, $at, $v0
/* 83CE0 800EA830 8C22C118 */  lw        $v0, %lo(jtbl_8010C118)($at)
/* 83CE4 800EA834 00400008 */  jr        $v0
/* 83CE8 800EA838 00000000 */   nop
glabel L800EA83C_83CEC
/* 83CEC 800EA83C 24040003 */  addiu     $a0, $zero, 3
/* 83CF0 800EA840 3C118011 */  lui       $s1, %hi(D_8010CD34)
/* 83CF4 800EA844 2631CD34 */  addiu     $s1, $s1, %lo(D_8010CD34)
/* 83CF8 800EA848 3C018011 */  lui       $at, %hi(D_8010CFC4)
/* 83CFC 800EA84C AC24CFC4 */  sw        $a0, %lo(D_8010CFC4)($at)
/* 83D00 800EA850 8E230000 */  lw        $v1, ($s1)
/* 83D04 800EA854 24120001 */  addiu     $s2, $zero, 1
/* 83D08 800EA858 1072002B */  beq       $v1, $s2, .L800EA908
/* 83D0C 800EA85C 28620002 */   slti     $v0, $v1, 2
/* 83D10 800EA860 50400005 */  beql      $v0, $zero, .L800EA878
/* 83D14 800EA864 24020002 */   addiu    $v0, $zero, 2
/* 83D18 800EA868 10600009 */  beqz      $v1, .L800EA890
/* 83D1C 800EA86C 00000000 */   nop
/* 83D20 800EA870 0803AC53 */  j         L800EB14C_845FC
/* 83D24 800EA874 00000000 */   nop
.L800EA878:
/* 83D28 800EA878 1062003F */  beq       $v1, $v0, .L800EA978
/* 83D2C 800EA87C 00000000 */   nop
/* 83D30 800EA880 10640056 */  beq       $v1, $a0, .L800EA9DC
/* 83D34 800EA884 00000000 */   nop
/* 83D38 800EA888 0803AC53 */  j         L800EB14C_845FC
/* 83D3C 800EA88C 00000000 */   nop
.L800EA890:
/* 83D40 800EA890 0C03805E */  jal       disable_player_input
/* 83D44 800EA894 00000000 */   nop
/* 83D48 800EA898 0C05272D */  jal       play_sound
/* 83D4C 800EA89C 2404000D */   addiu    $a0, $zero, 0xd
/* 83D50 800EA8A0 3C108011 */  lui       $s0, %hi(D_8010CFDC)
/* 83D54 800EA8A4 2610CFDC */  addiu     $s0, $s0, %lo(D_8010CFDC)
/* 83D58 800EA8A8 0C0B102B */  jal       kill_script_by_ID
/* 83D5C 800EA8AC 8E040000 */   lw       $a0, ($s0)
/* 83D60 800EA8B0 3C028011 */  lui       $v0, %hi(wPartner)
/* 83D64 800EA8B4 8C42CFEC */  lw        $v0, %lo(wPartner)($v0)
/* 83D68 800EA8B8 24050014 */  addiu     $a1, $zero, 0x14
/* 83D6C 800EA8BC 8C440020 */  lw        $a0, 0x20($v0)
/* 83D70 800EA8C0 0C0B0CF8 */  jal       start_script
/* 83D74 800EA8C4 24060020 */   addiu    $a2, $zero, 0x20
/* 83D78 800EA8C8 8C430144 */  lw        $v1, 0x144($v0)
/* 83D7C 800EA8CC 3C018011 */  lui       $at, %hi(D_8010CFD4)
/* 83D80 800EA8D0 AC22CFD4 */  sw        $v0, %lo(D_8010CFD4)($at)
/* 83D84 800EA8D4 AE030000 */  sw        $v1, ($s0)
/* 83D88 800EA8D8 3C058011 */  lui       $a1, %hi(wPartnerNpc)
/* 83D8C 800EA8DC 8CA5C930 */  lw        $a1, %lo(wPartnerNpc)($a1)
/* 83D90 800EA8E0 2403000A */  addiu     $v1, $zero, 0xa
/* 83D94 800EA8E4 A0430004 */  sb        $v1, 4($v0)
/* 83D98 800EA8E8 8E230000 */  lw        $v1, ($s1)
/* 83D9C 800EA8EC 24040001 */  addiu     $a0, $zero, 1
/* 83DA0 800EA8F0 00641821 */  addu      $v1, $v1, $a0
/* 83DA4 800EA8F4 AC45014C */  sw        $a1, 0x14c($v0)
/* 83DA8 800EA8F8 0C009C22 */  jal       func_80027088
/* 83DAC 800EA8FC AE230000 */   sw       $v1, ($s1)
/* 83DB0 800EA900 0803AC53 */  j         L800EB14C_845FC
/* 83DB4 800EA904 00000000 */   nop
.L800EA908:
/* 83DB8 800EA908 3C048011 */  lui       $a0, %hi(D_8010CFDC)
/* 83DBC 800EA90C 8C84CFDC */  lw        $a0, %lo(D_8010CFDC)($a0)
/* 83DC0 800EA910 0C0B1059 */  jal       does_script_exist
/* 83DC4 800EA914 00000000 */   nop
/* 83DC8 800EA918 1440020C */  bnez      $v0, L800EB14C_845FC
/* 83DCC 800EA91C 00000000 */   nop
/* 83DD0 800EA920 0C009C22 */  jal       func_80027088
/* 83DD4 800EA924 0000202D */   daddu    $a0, $zero, $zero
/* 83DD8 800EA928 0C03A9AA */  jal       func_800EA6A8
/* 83DDC 800EA92C 00000000 */   nop
/* 83DE0 800EA930 3C028011 */  lui       $v0, %hi(D_8010CFE4)
/* 83DE4 800EA934 8C42CFE4 */  lw        $v0, %lo(D_8010CFE4)($v0)
/* 83DE8 800EA938 3C018011 */  lui       $at, %hi(D_8010CFD8)
/* 83DEC 800EA93C AC22CFD8 */  sw        $v0, %lo(D_8010CFD8)($at)
/* 83DF0 800EA940 0C03A974 */  jal       load_partner_npc
/* 83DF4 800EA944 A2620012 */   sb       $v0, 0x12($s3)
/* 83DF8 800EA948 0C05272D */  jal       play_sound
/* 83DFC 800EA94C 2404000E */   addiu    $a0, $zero, 0xe
/* 83E00 800EA950 3C028011 */  lui       $v0, %hi(wPartner)
/* 83E04 800EA954 8C42CFEC */  lw        $v0, %lo(wPartner)($v0)
/* 83E08 800EA958 3C048011 */  lui       $a0, %hi(wPartnerNpc)
/* 83E0C 800EA95C 8C84C930 */  lw        $a0, %lo(wPartnerNpc)($a0)
/* 83E10 800EA960 8C420010 */  lw        $v0, 0x10($v0)
/* 83E14 800EA964 0040F809 */  jalr      $v0
/* 83E18 800EA968 00000000 */   nop
/* 83E1C 800EA96C 8E220000 */  lw        $v0, ($s1)
/* 83E20 800EA970 24420001 */  addiu     $v0, $v0, 1
/* 83E24 800EA974 AE220000 */  sw        $v0, ($s1)
.L800EA978:
/* 83E28 800EA978 3C028011 */  lui       $v0, %hi(wPartner)
/* 83E2C 800EA97C 8C42CFEC */  lw        $v0, %lo(wPartner)($v0)
/* 83E30 800EA980 24050014 */  addiu     $a1, $zero, 0x14
/* 83E34 800EA984 8C440014 */  lw        $a0, 0x14($v0)
/* 83E38 800EA988 0C0B0CF8 */  jal       start_script
/* 83E3C 800EA98C 24060020 */   addiu    $a2, $zero, 0x20
/* 83E40 800EA990 8C430144 */  lw        $v1, 0x144($v0)
/* 83E44 800EA994 3C068011 */  lui       $a2, %hi(wPartnerNpc)
/* 83E48 800EA998 8CC6C930 */  lw        $a2, %lo(wPartnerNpc)($a2)
/* 83E4C 800EA99C 3C058011 */  lui       $a1, %hi(D_8010CD34)
/* 83E50 800EA9A0 24A5CD34 */  addiu     $a1, $a1, %lo(D_8010CD34)
/* 83E54 800EA9A4 3C018011 */  lui       $at, %hi(D_8010CFD4)
/* 83E58 800EA9A8 AC22CFD4 */  sw        $v0, %lo(D_8010CFD4)($at)
/* 83E5C 800EA9AC 3C018011 */  lui       $at, %hi(D_8010CFDC)
/* 83E60 800EA9B0 AC23CFDC */  sw        $v1, %lo(D_8010CFDC)($at)
/* 83E64 800EA9B4 2403000A */  addiu     $v1, $zero, 0xa
/* 83E68 800EA9B8 A0430004 */  sb        $v1, 4($v0)
/* 83E6C 800EA9BC 8CA30000 */  lw        $v1, ($a1)
/* 83E70 800EA9C0 24040001 */  addiu     $a0, $zero, 1
/* 83E74 800EA9C4 AC46014C */  sw        $a2, 0x14c($v0)
/* 83E78 800EA9C8 00641821 */  addu      $v1, $v1, $a0
/* 83E7C 800EA9CC 0C009C22 */  jal       func_80027088
/* 83E80 800EA9D0 ACA30000 */   sw       $v1, ($a1)
/* 83E84 800EA9D4 0803AC53 */  j         L800EB14C_845FC
/* 83E88 800EA9D8 00000000 */   nop
.L800EA9DC:
/* 83E8C 800EA9DC 3C108011 */  lui       $s0, %hi(D_8010CFDC)
/* 83E90 800EA9E0 2610CFDC */  addiu     $s0, $s0, %lo(D_8010CFDC)
/* 83E94 800EA9E4 0C0B1059 */  jal       does_script_exist
/* 83E98 800EA9E8 8E040000 */   lw       $a0, ($s0)
/* 83E9C 800EA9EC 144001D7 */  bnez      $v0, L800EB14C_845FC
/* 83EA0 800EA9F0 24050014 */   addiu    $a1, $zero, 0x14
/* 83EA4 800EA9F4 3C028011 */  lui       $v0, %hi(wPartner)
/* 83EA8 800EA9F8 8C42CFEC */  lw        $v0, %lo(wPartner)($v0)
/* 83EAC 800EA9FC 8C440018 */  lw        $a0, 0x18($v0)
/* 83EB0 800EAA00 0C0B0CF8 */  jal       start_script
/* 83EB4 800EAA04 24060020 */   addiu    $a2, $zero, 0x20
/* 83EB8 800EAA08 3C038011 */  lui       $v1, %hi(wPartnerNpc)
/* 83EBC 800EAA0C 8C63C930 */  lw        $v1, %lo(wPartnerNpc)($v1)
/* 83EC0 800EAA10 8C440144 */  lw        $a0, 0x144($v0)
/* 83EC4 800EAA14 3C018011 */  lui       $at, %hi(D_8010CFD4)
/* 83EC8 800EAA18 AC22CFD4 */  sw        $v0, %lo(D_8010CFD4)($at)
/* 83ECC 800EAA1C AC43014C */  sw        $v1, 0x14c($v0)
/* 83ED0 800EAA20 2403000A */  addiu     $v1, $zero, 0xa
/* 83ED4 800EAA24 AE040000 */  sw        $a0, ($s0)
/* 83ED8 800EAA28 A0430004 */  sb        $v1, 4($v0)
/* 83EDC 800EAA2C 3C018011 */  lui       $at, %hi(D_8010CD30)
/* 83EE0 800EAA30 0C038069 */  jal       enable_player_input
/* 83EE4 800EAA34 AC32CD30 */   sw       $s2, %lo(D_8010CD30)($at)
/* 83EE8 800EAA38 0C009C22 */  jal       func_80027088
/* 83EEC 800EAA3C 0000202D */   daddu    $a0, $zero, $zero
/* 83EF0 800EAA40 0803AC53 */  j         L800EB14C_845FC
/* 83EF4 800EAA44 00000000 */   nop
glabel L800EAA48_83EF8
/* 83EF8 800EAA48 24040003 */  addiu     $a0, $zero, 3
/* 83EFC 800EAA4C 3C108011 */  lui       $s0, %hi(D_8010CD34)
/* 83F00 800EAA50 2610CD34 */  addiu     $s0, $s0, %lo(D_8010CD34)
/* 83F04 800EAA54 3C018011 */  lui       $at, %hi(D_8010CFC4)
/* 83F08 800EAA58 AC24CFC4 */  sw        $a0, %lo(D_8010CFC4)($at)
/* 83F0C 800EAA5C 8E030000 */  lw        $v1, ($s0)
/* 83F10 800EAA60 24110001 */  addiu     $s1, $zero, 1
/* 83F14 800EAA64 10710014 */  beq       $v1, $s1, .L800EAAB8
/* 83F18 800EAA68 28620002 */   slti     $v0, $v1, 2
/* 83F1C 800EAA6C 50400005 */  beql      $v0, $zero, .L800EAA84
/* 83F20 800EAA70 24020002 */   addiu    $v0, $zero, 2
/* 83F24 800EAA74 10600009 */  beqz      $v1, .L800EAA9C
/* 83F28 800EAA78 00000000 */   nop
/* 83F2C 800EAA7C 0803AC53 */  j         L800EB14C_845FC
/* 83F30 800EAA80 00000000 */   nop
.L800EAA84:
/* 83F34 800EAA84 10620170 */  beq       $v1, $v0, .L800EB048
/* 83F38 800EAA88 00000000 */   nop
/* 83F3C 800EAA8C 1064002E */  beq       $v1, $a0, .L800EAB48
/* 83F40 800EAA90 24050014 */   addiu    $a1, $zero, 0x14
/* 83F44 800EAA94 0803AC53 */  j         L800EB14C_845FC
/* 83F48 800EAA98 00000000 */   nop
.L800EAA9C:
/* 83F4C 800EAA9C 3C048011 */  lui       $a0, %hi(D_8010CFDC)
/* 83F50 800EAAA0 8C84CFDC */  lw        $a0, %lo(D_8010CFDC)($a0)
/* 83F54 800EAAA4 0C0B102B */  jal       kill_script_by_ID
/* 83F58 800EAAA8 00000000 */   nop
/* 83F5C 800EAAAC 8E020000 */  lw        $v0, ($s0)
/* 83F60 800EAAB0 24420001 */  addiu     $v0, $v0, 1
/* 83F64 800EAAB4 AE020000 */  sw        $v0, ($s0)
.L800EAAB8:
/* 83F68 800EAAB8 0C03A9AA */  jal       func_800EA6A8
/* 83F6C 800EAABC 00000000 */   nop
/* 83F70 800EAAC0 3C028011 */  lui       $v0, %hi(D_8010CFE4)
/* 83F74 800EAAC4 8C42CFE4 */  lw        $v0, %lo(D_8010CFE4)($v0)
/* 83F78 800EAAC8 3C018011 */  lui       $at, %hi(D_8010CFD8)
/* 83F7C 800EAACC AC22CFD8 */  sw        $v0, %lo(D_8010CFD8)($at)
/* 83F80 800EAAD0 0C03A974 */  jal       load_partner_npc
/* 83F84 800EAAD4 A2620012 */   sb       $v0, 0x12($s3)
/* 83F88 800EAAD8 3C048011 */  lui       $a0, %hi(wPartnerNpc)
/* 83F8C 800EAADC 8C84C930 */  lw        $a0, %lo(wPartnerNpc)($a0)
/* 83F90 800EAAE0 3C018010 */  lui       $at, %hi(D_800F833C)
/* 83F94 800EAAE4 C422833C */  lwc1      $f2, %lo(D_800F833C)($at)
/* 83F98 800EAAE8 3C018010 */  lui       $at, %hi(D_800F8340)
/* 83F9C 800EAAEC C4248340 */  lwc1      $f4, %lo(D_800F8340)($at)
/* 83FA0 800EAAF0 3C018010 */  lui       $at, %hi(D_800F8344)
/* 83FA4 800EAAF4 C4268344 */  lwc1      $f6, %lo(D_800F8344)($at)
/* 83FA8 800EAAF8 3C013F80 */  lui       $at, 0x3f80
/* 83FAC 800EAAFC 44810000 */  mtc1      $at, $f0
/* 83FB0 800EAB00 3C028011 */  lui       $v0, %hi(wPartner)
/* 83FB4 800EAB04 8C42CFEC */  lw        $v0, %lo(wPartner)($v0)
/* 83FB8 800EAB08 E4820038 */  swc1      $f2, 0x38($a0)
/* 83FBC 800EAB0C E484003C */  swc1      $f4, 0x3c($a0)
/* 83FC0 800EAB10 E4860040 */  swc1      $f6, 0x40($a0)
/* 83FC4 800EAB14 AC80001C */  sw        $zero, 0x1c($a0)
/* 83FC8 800EAB18 E4800054 */  swc1      $f0, 0x54($a0)
/* 83FCC 800EAB1C E4800058 */  swc1      $f0, 0x58($a0)
/* 83FD0 800EAB20 E480005C */  swc1      $f0, 0x5c($a0)
/* 83FD4 800EAB24 8C420010 */  lw        $v0, 0x10($v0)
/* 83FD8 800EAB28 0040F809 */  jalr      $v0
/* 83FDC 800EAB2C 00000000 */   nop
/* 83FE0 800EAB30 3C038011 */  lui       $v1, %hi(D_8010CD34)
/* 83FE4 800EAB34 2463CD34 */  addiu     $v1, $v1, %lo(D_8010CD34)
/* 83FE8 800EAB38 8C620000 */  lw        $v0, ($v1)
/* 83FEC 800EAB3C 24420001 */  addiu     $v0, $v0, 1
/* 83FF0 800EAB40 0803AC14 */  j         .L800EB050
/* 83FF4 800EAB44 AC620000 */   sw       $v0, ($v1)
.L800EAB48:
/* 83FF8 800EAB48 3C028011 */  lui       $v0, %hi(wPartner)
/* 83FFC 800EAB4C 8C42CFEC */  lw        $v0, %lo(wPartner)($v0)
/* 84000 800EAB50 8C440018 */  lw        $a0, 0x18($v0)
/* 84004 800EAB54 0C0B0CF8 */  jal       start_script
/* 84008 800EAB58 24060020 */   addiu    $a2, $zero, 0x20
/* 8400C 800EAB5C 3C038011 */  lui       $v1, %hi(wPartnerNpc)
/* 84010 800EAB60 8C63C930 */  lw        $v1, %lo(wPartnerNpc)($v1)
/* 84014 800EAB64 8C440144 */  lw        $a0, 0x144($v0)
/* 84018 800EAB68 3C018011 */  lui       $at, %hi(D_8010CFD4)
/* 8401C 800EAB6C AC22CFD4 */  sw        $v0, %lo(D_8010CFD4)($at)
/* 84020 800EAB70 AC43014C */  sw        $v1, 0x14c($v0)
/* 84024 800EAB74 2403000A */  addiu     $v1, $zero, 0xa
/* 84028 800EAB78 3C018011 */  lui       $at, %hi(D_8010CFDC)
/* 8402C 800EAB7C AC24CFDC */  sw        $a0, %lo(D_8010CFDC)($at)
/* 84030 800EAB80 A0430004 */  sb        $v1, 4($v0)
/* 84034 800EAB84 3C018011 */  lui       $at, %hi(D_8010CD30)
/* 84038 800EAB88 0803AC53 */  j         L800EB14C_845FC
/* 8403C 800EAB8C AC31CD30 */   sw       $s1, %lo(D_8010CD30)($at)
glabel L800EAB90_84040
/* 84040 800EAB90 3C118011 */  lui       $s1, %hi(D_8010CD34)
/* 84044 800EAB94 2631CD34 */  addiu     $s1, $s1, %lo(D_8010CD34)
/* 84048 800EAB98 8E300000 */  lw        $s0, ($s1)
/* 8404C 800EAB9C 12000005 */  beqz      $s0, .L800EABB4
/* 84050 800EABA0 24020001 */   addiu    $v0, $zero, 1
/* 84054 800EABA4 12020010 */  beq       $s0, $v0, .L800EABE8
/* 84058 800EABA8 00000000 */   nop
/* 8405C 800EABAC 0803AC53 */  j         L800EB14C_845FC
/* 84060 800EABB0 00000000 */   nop
.L800EABB4:
/* 84064 800EABB4 0C03805E */  jal       disable_player_input
/* 84068 800EABB8 00000000 */   nop
/* 8406C 800EABBC 0C05272D */  jal       play_sound
/* 84070 800EABC0 2404000D */   addiu    $a0, $zero, 0xd
/* 84074 800EABC4 3C108011 */  lui       $s0, %hi(D_8010CFDC)
/* 84078 800EABC8 2610CFDC */  addiu     $s0, $s0, %lo(D_8010CFDC)
/* 8407C 800EABCC 0C0B102B */  jal       kill_script_by_ID
/* 84080 800EABD0 8E040000 */   lw       $a0, ($s0)
/* 84084 800EABD4 3C028011 */  lui       $v0, %hi(wPartner)
/* 84088 800EABD8 8C42CFEC */  lw        $v0, %lo(wPartner)($v0)
/* 8408C 800EABDC 8C440020 */  lw        $a0, 0x20($v0)
/* 84090 800EABE0 0803ABCE */  j         .L800EAF38
/* 84094 800EABE4 24050014 */   addiu    $a1, $zero, 0x14
.L800EABE8:
/* 84098 800EABE8 3C048011 */  lui       $a0, %hi(D_8010CFDC)
/* 8409C 800EABEC 8C84CFDC */  lw        $a0, %lo(D_8010CFDC)($a0)
/* 840A0 800EABF0 0C0B1059 */  jal       does_script_exist
/* 840A4 800EABF4 00000000 */   nop
/* 840A8 800EABF8 14400154 */  bnez      $v0, L800EB14C_845FC
/* 840AC 800EABFC 00000000 */   nop
/* 840B0 800EAC00 0C03A9AA */  jal       func_800EA6A8
/* 840B4 800EAC04 00000000 */   nop
/* 840B8 800EAC08 3C028011 */  lui       $v0, %hi(D_8010CFE4)
/* 840BC 800EAC0C 8C42CFE4 */  lw        $v0, %lo(D_8010CFE4)($v0)
/* 840C0 800EAC10 3C018011 */  lui       $at, %hi(D_8010CD30)
/* 840C4 800EAC14 AC30CD30 */  sw        $s0, %lo(D_8010CD30)($at)
/* 840C8 800EAC18 3C018011 */  lui       $at, %hi(D_8010CFD8)
/* 840CC 800EAC1C AC22CFD8 */  sw        $v0, %lo(D_8010CFD8)($at)
/* 840D0 800EAC20 0C038069 */  jal       enable_player_input
/* 840D4 800EAC24 A2620012 */   sb       $v0, 0x12($s3)
/* 840D8 800EAC28 0803AC53 */  j         L800EB14C_845FC
/* 840DC 800EAC2C 00000000 */   nop
glabel L800EAC30_840E0
/* 840E0 800EAC30 3C028011 */  lui       $v0, %hi(D_8010CD34)
/* 840E4 800EAC34 8C42CD34 */  lw        $v0, %lo(D_8010CD34)($v0)
/* 840E8 800EAC38 14400144 */  bnez      $v0, L800EB14C_845FC
/* 840EC 800EAC3C 00000000 */   nop
/* 840F0 800EAC40 3C048011 */  lui       $a0, %hi(D_8010CFDC)
/* 840F4 800EAC44 8C84CFDC */  lw        $a0, %lo(D_8010CFDC)($a0)
/* 840F8 800EAC48 0C0B102B */  jal       kill_script_by_ID
/* 840FC 800EAC4C 00000000 */   nop
/* 84100 800EAC50 0C03A9AA */  jal       func_800EA6A8
/* 84104 800EAC54 00000000 */   nop
/* 84108 800EAC58 3C038011 */  lui       $v1, %hi(D_8010CFE4)
/* 8410C 800EAC5C 8C63CFE4 */  lw        $v1, %lo(D_8010CFE4)($v1)
/* 84110 800EAC60 24020001 */  addiu     $v0, $zero, 1
/* 84114 800EAC64 3C018011 */  lui       $at, %hi(D_8010CD30)
/* 84118 800EAC68 AC22CD30 */  sw        $v0, %lo(D_8010CD30)($at)
/* 8411C 800EAC6C 3C018011 */  lui       $at, %hi(D_8010CFD8)
/* 84120 800EAC70 AC23CFD8 */  sw        $v1, %lo(D_8010CFD8)($at)
/* 84124 800EAC74 0803AC53 */  j         L800EB14C_845FC
/* 84128 800EAC78 A2630012 */   sb       $v1, 0x12($s3)
glabel L800EAC7C_8412C
/* 8412C 800EAC7C 3C108011 */  lui       $s0, %hi(D_8010CD34)
/* 84130 800EAC80 2610CD34 */  addiu     $s0, $s0, %lo(D_8010CD34)
/* 84134 800EAC84 8E030000 */  lw        $v1, ($s0)
/* 84138 800EAC88 24110001 */  addiu     $s1, $zero, 1
/* 8413C 800EAC8C 1071001D */  beq       $v1, $s1, .L800EAD04
/* 84140 800EAC90 28620002 */   slti     $v0, $v1, 2
/* 84144 800EAC94 50400005 */  beql      $v0, $zero, .L800EACAC
/* 84148 800EAC98 24020002 */   addiu    $v0, $zero, 2
/* 8414C 800EAC9C 10600007 */  beqz      $v1, .L800EACBC
/* 84150 800EACA0 00000000 */   nop
/* 84154 800EACA4 0803AC53 */  j         L800EB14C_845FC
/* 84158 800EACA8 00000000 */   nop
.L800EACAC:
/* 8415C 800EACAC 1062002B */  beq       $v1, $v0, .L800EAD5C
/* 84160 800EACB0 00000000 */   nop
/* 84164 800EACB4 0803AC53 */  j         L800EB14C_845FC
/* 84168 800EACB8 00000000 */   nop
.L800EACBC:
/* 8416C 800EACBC 0C03805E */  jal       disable_player_input
/* 84170 800EACC0 00000000 */   nop
/* 84174 800EACC4 3C028011 */  lui       $v0, %hi(D_8010CFE4)
/* 84178 800EACC8 8C42CFE4 */  lw        $v0, %lo(D_8010CFE4)($v0)
/* 8417C 800EACCC 3C018011 */  lui       $at, %hi(D_8010CFD8)
/* 84180 800EACD0 AC22CFD8 */  sw        $v0, %lo(D_8010CFD8)($at)
/* 84184 800EACD4 0C03A974 */  jal       load_partner_npc
/* 84188 800EACD8 A2620012 */   sb       $v0, 0x12($s3)
/* 8418C 800EACDC 3C028011 */  lui       $v0, %hi(wPartner)
/* 84190 800EACE0 8C42CFEC */  lw        $v0, %lo(wPartner)($v0)
/* 84194 800EACE4 3C048011 */  lui       $a0, %hi(wPartnerNpc)
/* 84198 800EACE8 8C84C930 */  lw        $a0, %lo(wPartnerNpc)($a0)
/* 8419C 800EACEC 8C420010 */  lw        $v0, 0x10($v0)
/* 841A0 800EACF0 0040F809 */  jalr      $v0
/* 841A4 800EACF4 00000000 */   nop
/* 841A8 800EACF8 8E020000 */  lw        $v0, ($s0)
/* 841AC 800EACFC 24420001 */  addiu     $v0, $v0, 1
/* 841B0 800EAD00 AE020000 */  sw        $v0, ($s0)
.L800EAD04:
/* 841B4 800EAD04 3C028011 */  lui       $v0, %hi(wPartner)
/* 841B8 800EAD08 8C42CFEC */  lw        $v0, %lo(wPartner)($v0)
/* 841BC 800EAD0C 24050014 */  addiu     $a1, $zero, 0x14
/* 841C0 800EAD10 8C440014 */  lw        $a0, 0x14($v0)
/* 841C4 800EAD14 0C0B0CF8 */  jal       start_script
/* 841C8 800EAD18 24060020 */   addiu    $a2, $zero, 0x20
/* 841CC 800EAD1C 8C430144 */  lw        $v1, 0x144($v0)
/* 841D0 800EAD20 3C058011 */  lui       $a1, %hi(wPartnerNpc)
/* 841D4 800EAD24 8CA5C930 */  lw        $a1, %lo(wPartnerNpc)($a1)
/* 841D8 800EAD28 3C048011 */  lui       $a0, %hi(D_8010CD34)
/* 841DC 800EAD2C 2484CD34 */  addiu     $a0, $a0, %lo(D_8010CD34)
/* 841E0 800EAD30 3C018011 */  lui       $at, %hi(D_8010CFD4)
/* 841E4 800EAD34 AC22CFD4 */  sw        $v0, %lo(D_8010CFD4)($at)
/* 841E8 800EAD38 3C018011 */  lui       $at, %hi(D_8010CFDC)
/* 841EC 800EAD3C AC23CFDC */  sw        $v1, %lo(D_8010CFDC)($at)
/* 841F0 800EAD40 2403000A */  addiu     $v1, $zero, 0xa
/* 841F4 800EAD44 A0430004 */  sb        $v1, 4($v0)
/* 841F8 800EAD48 8C830000 */  lw        $v1, ($a0)
/* 841FC 800EAD4C AC45014C */  sw        $a1, 0x14c($v0)
/* 84200 800EAD50 24630001 */  addiu     $v1, $v1, 1
/* 84204 800EAD54 0803AC53 */  j         L800EB14C_845FC
/* 84208 800EAD58 AC830000 */   sw       $v1, ($a0)
.L800EAD5C:
/* 8420C 800EAD5C 3C108011 */  lui       $s0, %hi(D_8010CFDC)
/* 84210 800EAD60 2610CFDC */  addiu     $s0, $s0, %lo(D_8010CFDC)
/* 84214 800EAD64 0C0B1059 */  jal       does_script_exist
/* 84218 800EAD68 8E040000 */   lw       $a0, ($s0)
/* 8421C 800EAD6C 144000F7 */  bnez      $v0, L800EB14C_845FC
/* 84220 800EAD70 24050014 */   addiu    $a1, $zero, 0x14
/* 84224 800EAD74 3C028011 */  lui       $v0, %hi(wPartner)
/* 84228 800EAD78 8C42CFEC */  lw        $v0, %lo(wPartner)($v0)
/* 8422C 800EAD7C 8C440018 */  lw        $a0, 0x18($v0)
/* 84230 800EAD80 0C0B0CF8 */  jal       start_script
/* 84234 800EAD84 24060020 */   addiu    $a2, $zero, 0x20
/* 84238 800EAD88 3C038011 */  lui       $v1, %hi(wPartnerNpc)
/* 8423C 800EAD8C 8C63C930 */  lw        $v1, %lo(wPartnerNpc)($v1)
/* 84240 800EAD90 8C440144 */  lw        $a0, 0x144($v0)
/* 84244 800EAD94 3C018011 */  lui       $at, %hi(D_8010CFD4)
/* 84248 800EAD98 AC22CFD4 */  sw        $v0, %lo(D_8010CFD4)($at)
/* 8424C 800EAD9C AC43014C */  sw        $v1, 0x14c($v0)
/* 84250 800EADA0 2403000A */  addiu     $v1, $zero, 0xa
/* 84254 800EADA4 AE040000 */  sw        $a0, ($s0)
/* 84258 800EADA8 A0430004 */  sb        $v1, 4($v0)
/* 8425C 800EADAC 3C018011 */  lui       $at, %hi(D_8010CD30)
/* 84260 800EADB0 0C038069 */  jal       enable_player_input
/* 84264 800EADB4 AC31CD30 */   sw       $s1, %lo(D_8010CD30)($at)
/* 84268 800EADB8 0803AC53 */  j         L800EB14C_845FC
/* 8426C 800EADBC 00000000 */   nop
glabel L800EADC0_84270
/* 84270 800EADC0 3C118011 */  lui       $s1, %hi(D_8010CD34)
/* 84274 800EADC4 2631CD34 */  addiu     $s1, $s1, %lo(D_8010CD34)
/* 84278 800EADC8 8E300000 */  lw        $s0, ($s1)
/* 8427C 800EADCC 24020002 */  addiu     $v0, $zero, 2
/* 84280 800EADD0 3C018011 */  lui       $at, %hi(D_8010CFC4)
/* 84284 800EADD4 AC22CFC4 */  sw        $v0, %lo(D_8010CFC4)($at)
/* 84288 800EADD8 12000005 */  beqz      $s0, .L800EADF0
/* 8428C 800EADDC 24020001 */   addiu    $v0, $zero, 1
/* 84290 800EADE0 12020025 */  beq       $s0, $v0, .L800EAE78
/* 84294 800EADE4 24050014 */   addiu    $a1, $zero, 0x14
/* 84298 800EADE8 0803AC53 */  j         L800EB14C_845FC
/* 8429C 800EADEC 00000000 */   nop
.L800EADF0:
/* 842A0 800EADF0 0C03805E */  jal       disable_player_input
/* 842A4 800EADF4 00000000 */   nop
/* 842A8 800EADF8 3C028011 */  lui       $v0, %hi(D_8010CFE4)
/* 842AC 800EADFC 8C42CFE4 */  lw        $v0, %lo(D_8010CFE4)($v0)
/* 842B0 800EAE00 3C018011 */  lui       $at, %hi(D_8010CFD8)
/* 842B4 800EAE04 AC22CFD8 */  sw        $v0, %lo(D_8010CFD8)($at)
/* 842B8 800EAE08 0C03A974 */  jal       load_partner_npc
/* 842BC 800EAE0C A2620012 */   sb       $v0, 0x12($s3)
/* 842C0 800EAE10 3C048011 */  lui       $a0, %hi(wPartnerNpc)
/* 842C4 800EAE14 8C84C930 */  lw        $a0, %lo(wPartnerNpc)($a0)
/* 842C8 800EAE18 3C018010 */  lui       $at, %hi(D_800F833C)
/* 842CC 800EAE1C C422833C */  lwc1      $f2, %lo(D_800F833C)($at)
/* 842D0 800EAE20 3C018010 */  lui       $at, %hi(D_800F8340)
/* 842D4 800EAE24 C4248340 */  lwc1      $f4, %lo(D_800F8340)($at)
/* 842D8 800EAE28 3C018010 */  lui       $at, %hi(D_800F8344)
/* 842DC 800EAE2C C4268344 */  lwc1      $f6, %lo(D_800F8344)($at)
/* 842E0 800EAE30 3C013F80 */  lui       $at, 0x3f80
/* 842E4 800EAE34 44810000 */  mtc1      $at, $f0
/* 842E8 800EAE38 3C028011 */  lui       $v0, %hi(wPartner)
/* 842EC 800EAE3C 8C42CFEC */  lw        $v0, %lo(wPartner)($v0)
/* 842F0 800EAE40 E4820038 */  swc1      $f2, 0x38($a0)
/* 842F4 800EAE44 E484003C */  swc1      $f4, 0x3c($a0)
/* 842F8 800EAE48 E4860040 */  swc1      $f6, 0x40($a0)
/* 842FC 800EAE4C AC80001C */  sw        $zero, 0x1c($a0)
/* 84300 800EAE50 E4800054 */  swc1      $f0, 0x54($a0)
/* 84304 800EAE54 E4800058 */  swc1      $f0, 0x58($a0)
/* 84308 800EAE58 E480005C */  swc1      $f0, 0x5c($a0)
/* 8430C 800EAE5C 8C420010 */  lw        $v0, 0x10($v0)
/* 84310 800EAE60 0040F809 */  jalr      $v0
/* 84314 800EAE64 00000000 */   nop
/* 84318 800EAE68 8E220000 */  lw        $v0, ($s1)
/* 8431C 800EAE6C 24420001 */  addiu     $v0, $v0, 1
/* 84320 800EAE70 0803AC53 */  j         L800EB14C_845FC
/* 84324 800EAE74 AE220000 */   sw       $v0, ($s1)
.L800EAE78:
/* 84328 800EAE78 3C028011 */  lui       $v0, %hi(wPartner)
/* 8432C 800EAE7C 8C42CFEC */  lw        $v0, %lo(wPartner)($v0)
/* 84330 800EAE80 8C440018 */  lw        $a0, 0x18($v0)
/* 84334 800EAE84 0C0B0CF8 */  jal       start_script
/* 84338 800EAE88 24060020 */   addiu    $a2, $zero, 0x20
/* 8433C 800EAE8C 8C430144 */  lw        $v1, 0x144($v0)
/* 84340 800EAE90 3C058011 */  lui       $a1, %hi(wPartnerNpc)
/* 84344 800EAE94 24A5C930 */  addiu     $a1, $a1, %lo(wPartnerNpc)
/* 84348 800EAE98 3C018011 */  lui       $at, %hi(D_8010CFD4)
/* 8434C 800EAE9C AC22CFD4 */  sw        $v0, %lo(D_8010CFD4)($at)
/* 84350 800EAEA0 3C018011 */  lui       $at, %hi(D_8010CFDC)
/* 84354 800EAEA4 AC23CFDC */  sw        $v1, %lo(D_8010CFDC)($at)
/* 84358 800EAEA8 8CA40000 */  lw        $a0, ($a1)
/* 8435C 800EAEAC 2403000A */  addiu     $v1, $zero, 0xa
/* 84360 800EAEB0 A0430004 */  sb        $v1, 4($v0)
/* 84364 800EAEB4 3C038011 */  lui       $v1, %hi(D_8010CFD8)
/* 84368 800EAEB8 8C63CFD8 */  lw        $v1, %lo(D_8010CFD8)($v1)
/* 8436C 800EAEBC AC44014C */  sw        $a0, 0x14c($v0)
/* 84370 800EAEC0 000310C0 */  sll       $v0, $v1, 3
/* 84374 800EAEC4 00431021 */  addu      $v0, $v0, $v1
/* 84378 800EAEC8 00021080 */  sll       $v0, $v0, 2
/* 8437C 800EAECC 8CA30000 */  lw        $v1, ($a1)
/* 84380 800EAED0 3C018010 */  lui       $at, %hi(gPartnerAnimations+0x10)
/* 84384 800EAED4 00220821 */  addu      $at, $at, $v0
/* 84388 800EAED8 8C228358 */  lw        $v0, %lo(gPartnerAnimations+0x10)($at)
/* 8438C 800EAEDC 3C018011 */  lui       $at, %hi(D_8010CD30)
/* 84390 800EAEE0 AC30CD30 */  sw        $s0, %lo(D_8010CD30)($at)
/* 84394 800EAEE4 0C038069 */  jal       enable_player_input
/* 84398 800EAEE8 AC620028 */   sw       $v0, 0x28($v1)
/* 8439C 800EAEEC 0803AC53 */  j         L800EB14C_845FC
/* 843A0 800EAEF0 00000000 */   nop
glabel L800EAEF4_843A4
/* 843A4 800EAEF4 3C118011 */  lui       $s1, %hi(D_8010CD34)
/* 843A8 800EAEF8 2631CD34 */  addiu     $s1, $s1, %lo(D_8010CD34)
/* 843AC 800EAEFC 8E300000 */  lw        $s0, ($s1)
/* 843B0 800EAF00 12000005 */  beqz      $s0, .L800EAF18
/* 843B4 800EAF04 24020001 */   addiu    $v0, $zero, 1
/* 843B8 800EAF08 1202001A */  beq       $s0, $v0, .L800EAF74
/* 843BC 800EAF0C 00000000 */   nop
/* 843C0 800EAF10 0803AC53 */  j         L800EB14C_845FC
/* 843C4 800EAF14 00000000 */   nop
.L800EAF18:
/* 843C8 800EAF18 3C108011 */  lui       $s0, %hi(D_8010CFDC)
/* 843CC 800EAF1C 2610CFDC */  addiu     $s0, $s0, %lo(D_8010CFDC)
/* 843D0 800EAF20 0C0B102B */  jal       kill_script_by_ID
/* 843D4 800EAF24 8E040000 */   lw       $a0, ($s0)
/* 843D8 800EAF28 3C028011 */  lui       $v0, %hi(wPartner)
/* 843DC 800EAF2C 8C42CFEC */  lw        $v0, %lo(wPartner)($v0)
/* 843E0 800EAF30 24050014 */  addiu     $a1, $zero, 0x14
/* 843E4 800EAF34 8C44001C */  lw        $a0, 0x1c($v0)
.L800EAF38:
/* 843E8 800EAF38 0C0B0CF8 */  jal       start_script
/* 843EC 800EAF3C 24060020 */   addiu    $a2, $zero, 0x20
/* 843F0 800EAF40 8C430144 */  lw        $v1, 0x144($v0)
/* 843F4 800EAF44 3C018011 */  lui       $at, %hi(D_8010CFD4)
/* 843F8 800EAF48 AC22CFD4 */  sw        $v0, %lo(D_8010CFD4)($at)
/* 843FC 800EAF4C AE030000 */  sw        $v1, ($s0)
/* 84400 800EAF50 3C048011 */  lui       $a0, %hi(wPartnerNpc)
/* 84404 800EAF54 8C84C930 */  lw        $a0, %lo(wPartnerNpc)($a0)
/* 84408 800EAF58 2403000A */  addiu     $v1, $zero, 0xa
/* 8440C 800EAF5C A0430004 */  sb        $v1, 4($v0)
/* 84410 800EAF60 8E230000 */  lw        $v1, ($s1)
/* 84414 800EAF64 24630001 */  addiu     $v1, $v1, 1
/* 84418 800EAF68 AC44014C */  sw        $a0, 0x14c($v0)
/* 8441C 800EAF6C 0803AC53 */  j         L800EB14C_845FC
/* 84420 800EAF70 AE230000 */   sw       $v1, ($s1)
.L800EAF74:
/* 84424 800EAF74 3C118011 */  lui       $s1, %hi(D_8010CFDC)
/* 84428 800EAF78 2631CFDC */  addiu     $s1, $s1, %lo(D_8010CFDC)
/* 8442C 800EAF7C 0C0B1059 */  jal       does_script_exist
/* 84430 800EAF80 8E240000 */   lw       $a0, ($s1)
/* 84434 800EAF84 14400071 */  bnez      $v0, L800EB14C_845FC
/* 84438 800EAF88 24050014 */   addiu    $a1, $zero, 0x14
/* 8443C 800EAF8C 3C028011 */  lui       $v0, %hi(wPartner)
/* 84440 800EAF90 8C42CFEC */  lw        $v0, %lo(wPartner)($v0)
/* 84444 800EAF94 8C440018 */  lw        $a0, 0x18($v0)
/* 84448 800EAF98 0C0B0CF8 */  jal       start_script
/* 8444C 800EAF9C 24060020 */   addiu    $a2, $zero, 0x20
/* 84450 800EAFA0 3C038011 */  lui       $v1, %hi(wPartnerNpc)
/* 84454 800EAFA4 8C63C930 */  lw        $v1, %lo(wPartnerNpc)($v1)
/* 84458 800EAFA8 8C440144 */  lw        $a0, 0x144($v0)
/* 8445C 800EAFAC 3C018011 */  lui       $at, %hi(D_8010CFD4)
/* 84460 800EAFB0 AC22CFD4 */  sw        $v0, %lo(D_8010CFD4)($at)
/* 84464 800EAFB4 AC43014C */  sw        $v1, 0x14c($v0)
/* 84468 800EAFB8 2403000A */  addiu     $v1, $zero, 0xa
/* 8446C 800EAFBC AE240000 */  sw        $a0, ($s1)
/* 84470 800EAFC0 A0430004 */  sb        $v1, 4($v0)
/* 84474 800EAFC4 3C018011 */  lui       $at, %hi(D_8010CD30)
/* 84478 800EAFC8 0803AC53 */  j         L800EB14C_845FC
/* 8447C 800EAFCC AC30CD30 */   sw       $s0, %lo(D_8010CD30)($at)
glabel L800EAFD0_84480
/* 84480 800EAFD0 3C108011 */  lui       $s0, %hi(D_8010CD34)
/* 84484 800EAFD4 2610CD34 */  addiu     $s0, $s0, %lo(D_8010CD34)
/* 84488 800EAFD8 8E030000 */  lw        $v1, ($s0)
/* 8448C 800EAFDC 24110001 */  addiu     $s1, $zero, 1
/* 84490 800EAFE0 3C018011 */  lui       $at, %hi(D_8010CFC4)
/* 84494 800EAFE4 AC31CFC4 */  sw        $s1, %lo(D_8010CFC4)($at)
/* 84498 800EAFE8 10710017 */  beq       $v1, $s1, .L800EB048
/* 8449C 800EAFEC 28620002 */   slti     $v0, $v1, 2
/* 844A0 800EAFF0 50400005 */  beql      $v0, $zero, .L800EB008
/* 844A4 800EAFF4 24020002 */   addiu    $v0, $zero, 2
/* 844A8 800EAFF8 10600007 */  beqz      $v1, .L800EB018
/* 844AC 800EAFFC 00000000 */   nop
/* 844B0 800EB000 0803AC53 */  j         L800EB14C_845FC
/* 844B4 800EB004 00000000 */   nop
.L800EB008:
/* 844B8 800EB008 10620015 */  beq       $v1, $v0, .L800EB060
/* 844BC 800EB00C 00000000 */   nop
/* 844C0 800EB010 0803AC53 */  j         L800EB14C_845FC
/* 844C4 800EB014 00000000 */   nop
.L800EB018:
/* 844C8 800EB018 0C03805E */  jal       disable_player_input
/* 844CC 800EB01C 00000000 */   nop
/* 844D0 800EB020 3C028011 */  lui       $v0, %hi(wPartner)
/* 844D4 800EB024 8C42CFEC */  lw        $v0, %lo(wPartner)($v0)
/* 844D8 800EB028 3C048011 */  lui       $a0, %hi(wPartnerNpc)
/* 844DC 800EB02C 8C84C930 */  lw        $a0, %lo(wPartnerNpc)($a0)
/* 844E0 800EB030 8C420010 */  lw        $v0, 0x10($v0)
/* 844E4 800EB034 0040F809 */  jalr      $v0
/* 844E8 800EB038 00000000 */   nop
/* 844EC 800EB03C 8E020000 */  lw        $v0, ($s0)
/* 844F0 800EB040 24420001 */  addiu     $v0, $v0, 1
/* 844F4 800EB044 AE020000 */  sw        $v0, ($s0)
.L800EB048:
/* 844F8 800EB048 3C038011 */  lui       $v1, %hi(D_8010CD34)
/* 844FC 800EB04C 2463CD34 */  addiu     $v1, $v1, %lo(D_8010CD34)
.L800EB050:
/* 84500 800EB050 8C620000 */  lw        $v0, ($v1)
/* 84504 800EB054 24420001 */  addiu     $v0, $v0, 1
/* 84508 800EB058 0803AC53 */  j         L800EB14C_845FC
/* 8450C 800EB05C AC620000 */   sw       $v0, ($v1)
.L800EB060:
/* 84510 800EB060 80A20000 */  lb        $v0, ($a1)
/* 84514 800EB064 10510019 */  beq       $v0, $s1, .L800EB0CC
/* 84518 800EB068 24050014 */   addiu    $a1, $zero, 0x14
/* 8451C 800EB06C 3C028011 */  lui       $v0, %hi(wPartner)
/* 84520 800EB070 8C42CFEC */  lw        $v0, %lo(wPartner)($v0)
/* 84524 800EB074 C4C00028 */  lwc1      $f0, 0x28($a2)
/* 84528 800EB078 C4C2002C */  lwc1      $f2, 0x2c($a2)
/* 8452C 800EB07C C4C40030 */  lwc1      $f4, 0x30($a2)
/* 84530 800EB080 8C440018 */  lw        $a0, 0x18($v0)
/* 84534 800EB084 3C018010 */  lui       $at, %hi(D_800F833C)
/* 84538 800EB088 E420833C */  swc1      $f0, %lo(D_800F833C)($at)
/* 8453C 800EB08C 3C018010 */  lui       $at, %hi(D_800F8340)
/* 84540 800EB090 E4228340 */  swc1      $f2, %lo(D_800F8340)($at)
/* 84544 800EB094 3C018010 */  lui       $at, %hi(D_800F8344)
/* 84548 800EB098 E4248344 */  swc1      $f4, %lo(D_800F8344)($at)
/* 8454C 800EB09C 0C0B0CF8 */  jal       start_script
/* 84550 800EB0A0 24060020 */   addiu    $a2, $zero, 0x20
/* 84554 800EB0A4 3C038011 */  lui       $v1, %hi(wPartnerNpc)
/* 84558 800EB0A8 8C63C930 */  lw        $v1, %lo(wPartnerNpc)($v1)
/* 8455C 800EB0AC 8C440144 */  lw        $a0, 0x144($v0)
/* 84560 800EB0B0 3C018011 */  lui       $at, %hi(D_8010CFD4)
/* 84564 800EB0B4 AC22CFD4 */  sw        $v0, %lo(D_8010CFD4)($at)
/* 84568 800EB0B8 AC43014C */  sw        $v1, 0x14c($v0)
/* 8456C 800EB0BC 2403000A */  addiu     $v1, $zero, 0xa
/* 84570 800EB0C0 3C018011 */  lui       $at, %hi(D_8010CFDC)
/* 84574 800EB0C4 AC24CFDC */  sw        $a0, %lo(D_8010CFDC)($at)
/* 84578 800EB0C8 A0430004 */  sb        $v1, 4($v0)
.L800EB0CC:
/* 8457C 800EB0CC 0C038069 */  jal       enable_player_input
/* 84580 800EB0D0 00000000 */   nop
/* 84584 800EB0D4 3C018011 */  lui       $at, %hi(D_8010CD30)
/* 84588 800EB0D8 0803AC53 */  j         L800EB14C_845FC
/* 8458C 800EB0DC AC31CD30 */   sw       $s1, %lo(D_8010CD30)($at)
glabel L800EB0E0_84590
/* 84590 800EB0E0 3C108011 */  lui       $s0, %hi(D_8010CD34)
/* 84594 800EB0E4 2610CD34 */  addiu     $s0, $s0, %lo(D_8010CD34)
/* 84598 800EB0E8 8E020000 */  lw        $v0, ($s0)
/* 8459C 800EB0EC 14400017 */  bnez      $v0, L800EB14C_845FC
/* 845A0 800EB0F0 00000000 */   nop
/* 845A4 800EB0F4 3C118011 */  lui       $s1, %hi(D_8010CFDC)
/* 845A8 800EB0F8 2631CFDC */  addiu     $s1, $s1, %lo(D_8010CFDC)
/* 845AC 800EB0FC 0C0B1059 */  jal       does_script_exist
/* 845B0 800EB100 8E240000 */   lw       $a0, ($s1)
/* 845B4 800EB104 10400003 */  beqz      $v0, .L800EB114
/* 845B8 800EB108 00000000 */   nop
/* 845BC 800EB10C 0C0B102B */  jal       kill_script_by_ID
/* 845C0 800EB110 8E240000 */   lw       $a0, ($s1)
.L800EB114:
/* 845C4 800EB114 8E020000 */  lw        $v0, ($s0)
/* 845C8 800EB118 24420001 */  addiu     $v0, $v0, 1
/* 845CC 800EB11C 0803AC53 */  j         L800EB14C_845FC
/* 845D0 800EB120 AE020000 */   sw       $v0, ($s0)
glabel L800EB124_845D4
/* 845D4 800EB124 3C048011 */  lui       $a0, %hi(D_8010CFC4)
/* 845D8 800EB128 2484CFC4 */  addiu     $a0, $a0, %lo(D_8010CFC4)
/* 845DC 800EB12C 3C018011 */  lui       $at, %hi(D_8010CD30)
/* 845E0 800EB130 AC20CD30 */  sw        $zero, %lo(D_8010CD30)($at)
/* 845E4 800EB134 3C018011 */  lui       $at, %hi(D_8010CFE0)
/* 845E8 800EB138 AC20CFE0 */  sw        $zero, %lo(D_8010CFE0)($at)
/* 845EC 800EB13C 8C830000 */  lw        $v1, ($a0)
/* 845F0 800EB140 24020003 */  addiu     $v0, $zero, 3
/* 845F4 800EB144 54620001 */  bnel      $v1, $v0, L800EB14C_845FC
/* 845F8 800EB148 AC800000 */   sw       $zero, ($a0)
glabel L800EB14C_845FC
/* 845FC 800EB14C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 84600 800EB150 8FB3001C */  lw        $s3, 0x1c($sp)
/* 84604 800EB154 8FB20018 */  lw        $s2, 0x18($sp)
/* 84608 800EB158 8FB10014 */  lw        $s1, 0x14($sp)
/* 8460C 800EB15C 8FB00010 */  lw        $s0, 0x10($sp)
/* 84610 800EB160 03E00008 */  jr        $ra
/* 84614 800EB164 27BD0028 */   addiu    $sp, $sp, 0x28
