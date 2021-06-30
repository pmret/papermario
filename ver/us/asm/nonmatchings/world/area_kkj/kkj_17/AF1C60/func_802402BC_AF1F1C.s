.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802402BC_AF1F1C
/* AF1F1C 802402BC 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* AF1F20 802402C0 AFB3001C */  sw        $s3, 0x1c($sp)
/* AF1F24 802402C4 0080982D */  daddu     $s3, $a0, $zero
/* AF1F28 802402C8 AFBF0034 */  sw        $ra, 0x34($sp)
/* AF1F2C 802402CC AFBE0030 */  sw        $fp, 0x30($sp)
/* AF1F30 802402D0 AFB7002C */  sw        $s7, 0x2c($sp)
/* AF1F34 802402D4 AFB60028 */  sw        $s6, 0x28($sp)
/* AF1F38 802402D8 AFB50024 */  sw        $s5, 0x24($sp)
/* AF1F3C 802402DC AFB40020 */  sw        $s4, 0x20($sp)
/* AF1F40 802402E0 AFB20018 */  sw        $s2, 0x18($sp)
/* AF1F44 802402E4 AFB10014 */  sw        $s1, 0x14($sp)
/* AF1F48 802402E8 10A0004C */  beqz      $a1, .L8024041C
/* AF1F4C 802402EC AFB00010 */   sw       $s0, 0x10($sp)
/* AF1F50 802402F0 0C00AB39 */  jal       heap_malloc
/* AF1F54 802402F4 24040330 */   addiu    $a0, $zero, 0x330
/* AF1F58 802402F8 8E630084 */  lw        $v1, 0x84($s3)
/* AF1F5C 802402FC 0040A82D */  daddu     $s5, $v0, $zero
/* AF1F60 80240300 AE750078 */  sw        $s5, 0x78($s3)
/* AF1F64 80240304 0060202D */  daddu     $a0, $v1, $zero
/* AF1F68 80240308 14800008 */  bnez      $a0, .L8024032C
/* AF1F6C 8024030C AE6300AC */   sw       $v1, 0xac($s3)
/* AF1F70 80240310 3C03F840 */  lui       $v1, 0xf840
/* AF1F74 80240314 34635D64 */  ori       $v1, $v1, 0x5d64
/* AF1F78 80240318 3C02F840 */  lui       $v0, 0xf840
/* AF1F7C 8024031C 34425D69 */  ori       $v0, $v0, 0x5d69
/* AF1F80 80240320 AE62008C */  sw        $v0, 0x8c($s3)
/* AF1F84 80240324 080900D1 */  j         .L80240344
/* AF1F88 80240328 2402000C */   addiu    $v0, $zero, 0xc
.L8024032C:
/* AF1F8C 8024032C 3C03F840 */  lui       $v1, 0xf840
/* AF1F90 80240330 34635D69 */  ori       $v1, $v1, 0x5d69
/* AF1F94 80240334 3C02F840 */  lui       $v0, 0xf840
/* AF1F98 80240338 34425D6E */  ori       $v0, $v0, 0x5d6e
/* AF1F9C 8024033C AE62008C */  sw        $v0, 0x8c($s3)
/* AF1FA0 80240340 24020009 */  addiu     $v0, $zero, 9
.L80240344:
/* AF1FA4 80240344 AE630088 */  sw        $v1, 0x88($s3)
/* AF1FA8 80240348 AEA20318 */  sw        $v0, 0x318($s5)
/* AF1FAC 8024034C 0000B02D */  daddu     $s6, $zero, $zero
/* AF1FB0 80240350 02C0902D */  daddu     $s2, $s6, $zero
/* AF1FB4 80240354 3C1E8009 */  lui       $fp, %hi(D_8008A680)
/* AF1FB8 80240358 27DEA680 */  addiu     $fp, $fp, %lo(D_8008A680)
/* AF1FBC 8024035C 24170001 */  addiu     $s7, $zero, 1
/* AF1FC0 80240360 3C148024 */  lui       $s4, %hi(D_8024092C_AF258C)
/* AF1FC4 80240364 2694092C */  addiu     $s4, $s4, %lo(D_8024092C_AF258C)
/* AF1FC8 80240368 02A0882D */  daddu     $s1, $s5, $zero
.L8024036C:
/* AF1FCC 8024036C 8E650088 */  lw        $a1, 0x88($s3)
/* AF1FD0 80240370 0000202D */  daddu     $a0, $zero, $zero
/* AF1FD4 80240374 0C0B1EAF */  jal       get_variable
/* AF1FD8 80240378 00B22821 */   addu     $a1, $a1, $s2
/* AF1FDC 8024037C 0000202D */  daddu     $a0, $zero, $zero
/* AF1FE0 80240380 8E65008C */  lw        $a1, 0x8c($s3)
/* AF1FE4 80240384 0040802D */  daddu     $s0, $v0, $zero
/* AF1FE8 80240388 0C0B1EAF */  jal       get_variable
/* AF1FEC 8024038C 00B22821 */   addu     $a1, $a1, $s2
/* AF1FF0 80240390 52000016 */  beql      $s0, $zero, .L802403EC
/* AF1FF4 80240394 26520001 */   addiu    $s2, $s2, 1
/* AF1FF8 80240398 54400014 */  bnel      $v0, $zero, .L802403EC
/* AF1FFC 8024039C 26520001 */   addiu    $s2, $s2, 1
/* AF2000 802403A0 8E830000 */  lw        $v1, ($s4)
/* AF2004 802403A4 3C078008 */  lui       $a3, %hi(gItemTable)
/* AF2008 802403A8 24E778E0 */  addiu     $a3, $a3, %lo(gItemTable)
/* AF200C 802403AC 00031940 */  sll       $v1, $v1, 5
/* AF2010 802403B0 00671821 */  addu      $v1, $v1, $a3
/* AF2014 802403B4 84620004 */  lh        $v0, 4($v1)
/* AF2018 802403B8 000210C0 */  sll       $v0, $v0, 3
/* AF201C 802403BC 005E1021 */  addu      $v0, $v0, $fp
/* AF2020 802403C0 8C420000 */  lw        $v0, ($v0)
/* AF2024 802403C4 AE320108 */  sw        $s2, 0x108($s1)
/* AF2028 802403C8 AE37018C */  sw        $s7, 0x18c($s1)
/* AF202C 802403CC AE220000 */  sw        $v0, ($s1)
/* AF2030 802403D0 8C620000 */  lw        $v0, ($v1)
/* AF2034 802403D4 AE220084 */  sw        $v0, 0x84($s1)
/* AF2038 802403D8 8C620014 */  lw        $v0, 0x14($v1)
/* AF203C 802403DC 26D60001 */  addiu     $s6, $s6, 1
/* AF2040 802403E0 AE220294 */  sw        $v0, 0x294($s1)
/* AF2044 802403E4 26310004 */  addiu     $s1, $s1, 4
/* AF2048 802403E8 26520001 */  addiu     $s2, $s2, 1
.L802403EC:
/* AF204C 802403EC 2A420005 */  slti      $v0, $s2, 5
/* AF2050 802403F0 1440FFDE */  bnez      $v0, .L8024036C
/* AF2054 802403F4 26940004 */   addiu    $s4, $s4, 4
/* AF2058 802403F8 16C00004 */  bnez      $s6, .L8024040C
/* AF205C 802403FC 02A0202D */   daddu    $a0, $s5, $zero
/* AF2060 80240400 AE600084 */  sw        $zero, 0x84($s3)
/* AF2064 80240404 08090134 */  j         .L802404D0
/* AF2068 80240408 24020001 */   addiu    $v0, $zero, 1
.L8024040C:
/* AF206C 8024040C AC960324 */  sw        $s6, 0x324($a0)
/* AF2070 80240410 0C03D390 */  jal       btl_create_popup_menu
/* AF2074 80240414 AC800328 */   sw       $zero, 0x328($a0)
/* AF2078 80240418 AE600070 */  sw        $zero, 0x70($s3)
.L8024041C:
/* AF207C 8024041C 8E620070 */  lw        $v0, 0x70($s3)
/* AF2080 80240420 8E750078 */  lw        $s5, 0x78($s3)
/* AF2084 80240424 14400008 */  bnez      $v0, .L80240448
/* AF2088 80240428 24420001 */   addiu    $v0, $v0, 1
/* AF208C 8024042C 86A2032C */  lh        $v0, 0x32c($s5)
/* AF2090 80240430 10400009 */  beqz      $v0, .L80240458
/* AF2094 80240434 AE620074 */   sw       $v0, 0x74($s3)
/* AF2098 80240438 0C03C4EC */  jal       hide_popup_menu
/* AF209C 8024043C 00000000 */   nop
/* AF20A0 80240440 8E620070 */  lw        $v0, 0x70($s3)
/* AF20A4 80240444 24420001 */  addiu     $v0, $v0, 1
.L80240448:
/* AF20A8 80240448 AE620070 */  sw        $v0, 0x70($s3)
/* AF20AC 8024044C 2842000F */  slti      $v0, $v0, 0xf
/* AF20B0 80240450 10400003 */  beqz      $v0, .L80240460
/* AF20B4 80240454 00000000 */   nop
.L80240458:
/* AF20B8 80240458 08090134 */  j         .L802404D0
/* AF20BC 8024045C 0000102D */   daddu    $v0, $zero, $zero
.L80240460:
/* AF20C0 80240460 0C03C54E */  jal       destroy_popup_menu
/* AF20C4 80240464 00000000 */   nop
/* AF20C8 80240468 8E630074 */  lw        $v1, 0x74($s3)
/* AF20CC 8024046C 240200FF */  addiu     $v0, $zero, 0xff
/* AF20D0 80240470 14620004 */  bne       $v1, $v0, .L80240484
/* AF20D4 80240474 2462FFFF */   addiu    $v0, $v1, -1
/* AF20D8 80240478 2402FFFF */  addiu     $v0, $zero, -1
/* AF20DC 8024047C 08090133 */  j         .L802404CC
/* AF20E0 80240480 AE620084 */   sw       $v0, 0x84($s3)
.L80240484:
/* AF20E4 80240484 00021080 */  sll       $v0, $v0, 2
/* AF20E8 80240488 02A21021 */  addu      $v0, $s5, $v0
/* AF20EC 8024048C 8C460108 */  lw        $a2, 0x108($v0)
/* AF20F0 80240490 8E6300AC */  lw        $v1, 0xac($s3)
/* AF20F4 80240494 00061080 */  sll       $v0, $a2, 2
/* AF20F8 80240498 3C018024 */  lui       $at, %hi(D_8024092C_AF258C)
/* AF20FC 8024049C 00220821 */  addu      $at, $at, $v0
/* AF2100 802404A0 8C22092C */  lw        $v0, %lo(D_8024092C_AF258C)($at)
/* AF2104 802404A4 14600006 */  bnez      $v1, .L802404C0
/* AF2108 802404A8 AE620084 */   sw       $v0, 0x84($s3)
/* AF210C 802404AC 8E65008C */  lw        $a1, 0x8c($s3)
/* AF2110 802404B0 0000202D */  daddu     $a0, $zero, $zero
/* AF2114 802404B4 00A62821 */  addu      $a1, $a1, $a2
/* AF2118 802404B8 0C0B2026 */  jal       set_variable
/* AF211C 802404BC 24060001 */   addiu    $a2, $zero, 1
.L802404C0:
/* AF2120 802404C0 8E640078 */  lw        $a0, 0x78($s3)
/* AF2124 802404C4 0C00AB4B */  jal       heap_free
/* AF2128 802404C8 00000000 */   nop
.L802404CC:
/* AF212C 802404CC 24020002 */  addiu     $v0, $zero, 2
.L802404D0:
/* AF2130 802404D0 8FBF0034 */  lw        $ra, 0x34($sp)
/* AF2134 802404D4 8FBE0030 */  lw        $fp, 0x30($sp)
/* AF2138 802404D8 8FB7002C */  lw        $s7, 0x2c($sp)
/* AF213C 802404DC 8FB60028 */  lw        $s6, 0x28($sp)
/* AF2140 802404E0 8FB50024 */  lw        $s5, 0x24($sp)
/* AF2144 802404E4 8FB40020 */  lw        $s4, 0x20($sp)
/* AF2148 802404E8 8FB3001C */  lw        $s3, 0x1c($sp)
/* AF214C 802404EC 8FB20018 */  lw        $s2, 0x18($sp)
/* AF2150 802404F0 8FB10014 */  lw        $s1, 0x14($sp)
/* AF2154 802404F4 8FB00010 */  lw        $s0, 0x10($sp)
/* AF2158 802404F8 03E00008 */  jr        $ra
/* AF215C 802404FC 27BD0038 */   addiu    $sp, $sp, 0x38
