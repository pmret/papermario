.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel jtbl_8024C018
.word .L80247370_167BD0, .L80247664_167EC4, .L802477F8_168058, .L802474E4_167D44, .L80247A3C_16829C, 0

dlabel jtbl_8024C030
.word .L80247AC4_168324, .L80247AC4_168324, .L80247ADC_16833C, .L80247AC4_168324, .L80247AF8_168358, 0

dlabel jtbl_8024C048
.word .L80247C08_168468, .L80247C08_168468, .L80247C20_168480, .L80247C08_168468, .L80247C3C_16849C, 0

.section .text

glabel filemenu_yesno_handle_input
/* 167A4C 802471EC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 167A50 802471F0 AFB20018 */  sw        $s2, 0x18($sp)
/* 167A54 802471F4 0080902D */  daddu     $s2, $a0, $zero
/* 167A58 802471F8 3C028025 */  lui       $v0, %hi(filemenu_heldButtons)
/* 167A5C 802471FC 8C42C08C */  lw        $v0, %lo(filemenu_heldButtons)($v0)
/* 167A60 80247200 3C030001 */  lui       $v1, 1
/* 167A64 80247204 AFBF001C */  sw        $ra, 0x1c($sp)
/* 167A68 80247208 AFB10014 */  sw        $s1, 0x14($sp)
/* 167A6C 8024720C AFB00010 */  sw        $s0, 0x10($sp)
/* 167A70 80247210 92450003 */  lbu       $a1, 3($s2)
/* 167A74 80247214 00431024 */  and       $v0, $v0, $v1
/* 167A78 80247218 10400007 */  beqz      $v0, .L80247238
/* 167A7C 8024721C 00000000 */   nop
/* 167A80 80247220 92420002 */  lbu       $v0, 2($s2)
/* 167A84 80247224 2442FFFF */  addiu     $v0, $v0, -1
/* 167A88 80247228 A2420002 */  sb        $v0, 2($s2)
/* 167A8C 8024722C 00021600 */  sll       $v0, $v0, 0x18
/* 167A90 80247230 04420001 */  bltzl     $v0, .L80247238
/* 167A94 80247234 A2400002 */   sb       $zero, 2($s2)
.L80247238:
/* 167A98 80247238 3C028025 */  lui       $v0, %hi(filemenu_heldButtons)
/* 167A9C 8024723C 8C42C08C */  lw        $v0, %lo(filemenu_heldButtons)($v0)
/* 167AA0 80247240 3C030002 */  lui       $v1, 2
/* 167AA4 80247244 00431024 */  and       $v0, $v0, $v1
/* 167AA8 80247248 1040000C */  beqz      $v0, .L8024727C
/* 167AAC 8024724C 00000000 */   nop
/* 167AB0 80247250 92420002 */  lbu       $v0, 2($s2)
/* 167AB4 80247254 82430006 */  lb        $v1, 6($s2)
/* 167AB8 80247258 24420001 */  addiu     $v0, $v0, 1
/* 167ABC 8024725C A2420002 */  sb        $v0, 2($s2)
/* 167AC0 80247260 00021600 */  sll       $v0, $v0, 0x18
/* 167AC4 80247264 00021603 */  sra       $v0, $v0, 0x18
/* 167AC8 80247268 0043102A */  slt       $v0, $v0, $v1
/* 167ACC 8024726C 92430006 */  lbu       $v1, 6($s2)
/* 167AD0 80247270 14400002 */  bnez      $v0, .L8024727C
/* 167AD4 80247274 2462FFFF */   addiu    $v0, $v1, -1
/* 167AD8 80247278 A2420002 */  sb        $v0, 2($s2)
.L8024727C:
/* 167ADC 8024727C 82420004 */  lb        $v0, 4($s2)
/* 167AE0 80247280 82430005 */  lb        $v1, 5($s2)
/* 167AE4 80247284 00430018 */  mult      $v0, $v1
/* 167AE8 80247288 00003812 */  mflo      $a3
/* 167AEC 8024728C 82420006 */  lb        $v0, 6($s2)
/* 167AF0 80247290 00000000 */  nop
/* 167AF4 80247294 00E20018 */  mult      $a3, $v0
/* 167AF8 80247298 00002012 */  mflo      $a0
/* 167AFC 8024729C 82420002 */  lb        $v0, 2($s2)
/* 167B00 802472A0 00000000 */  nop
/* 167B04 802472A4 00620018 */  mult      $v1, $v0
/* 167B08 802472A8 00001812 */  mflo      $v1
/* 167B0C 802472AC 00831821 */  addu      $v1, $a0, $v1
/* 167B10 802472B0 82440001 */  lb        $a0, 1($s2)
/* 167B14 802472B4 8E420008 */  lw        $v0, 8($s2)
/* 167B18 802472B8 00641821 */  addu      $v1, $v1, $a0
/* 167B1C 802472BC 00431021 */  addu      $v0, $v0, $v1
/* 167B20 802472C0 90420000 */  lbu       $v0, ($v0)
/* 167B24 802472C4 A2420003 */  sb        $v0, 3($s2)
/* 167B28 802472C8 304200FF */  andi      $v0, $v0, 0xff
/* 167B2C 802472CC 10A20003 */  beq       $a1, $v0, .L802472DC
/* 167B30 802472D0 00000000 */   nop
/* 167B34 802472D4 0C05272D */  jal       sfx_play_sound
/* 167B38 802472D8 240400C7 */   addiu    $a0, $zero, 0xc7
.L802472DC:
/* 167B3C 802472DC 3C108025 */  lui       $s0, %hi(filemenu_pressedButtons)
/* 167B40 802472E0 2610C084 */  addiu     $s0, $s0, %lo(filemenu_pressedButtons)
/* 167B44 802472E4 8E020000 */  lw        $v0, ($s0)
/* 167B48 802472E8 30421000 */  andi      $v0, $v0, 0x1000
/* 167B4C 802472EC 10400009 */  beqz      $v0, .L80247314
/* 167B50 802472F0 24020004 */   addiu    $v0, $zero, 4
/* 167B54 802472F4 82430004 */  lb        $v1, 4($s2)
/* 167B58 802472F8 14620006 */  bne       $v1, $v0, .L80247314
/* 167B5C 802472FC 0240202D */   daddu    $a0, $s2, $zero
/* 167B60 80247300 0000282D */  daddu     $a1, $zero, $zero
/* 167B64 80247304 0C090B65 */  jal       filemenu_set_selected
/* 167B68 80247308 00A0302D */   daddu    $a2, $a1, $zero
/* 167B6C 8024730C 34028000 */  ori       $v0, $zero, 0x8000
/* 167B70 80247310 AE020000 */  sw        $v0, ($s0)
.L80247314:
/* 167B74 80247314 3C028025 */  lui       $v0, %hi(filemenu_pressedButtons)
/* 167B78 80247318 8C42C084 */  lw        $v0, %lo(filemenu_pressedButtons)($v0)
/* 167B7C 8024731C 30428000 */  andi      $v0, $v0, 0x8000
/* 167B80 80247320 10400225 */  beqz      $v0, .L80247BB8
/* 167B84 80247324 00000000 */   nop
/* 167B88 80247328 0C05272D */  jal       sfx_play_sound
/* 167B8C 8024732C 240400C9 */   addiu    $a0, $zero, 0xc9
/* 167B90 80247330 92430003 */  lbu       $v1, 3($s2)
/* 167B94 80247334 10600005 */  beqz      $v1, .L8024734C
/* 167B98 80247338 24020001 */   addiu    $v0, $zero, 1
/* 167B9C 8024733C 106201D8 */  beq       $v1, $v0, .L80247AA0
/* 167BA0 80247340 00000000 */   nop
/* 167BA4 80247344 08091EEE */  j         .L80247BB8
/* 167BA8 80247348 00000000 */   nop
.L8024734C:
/* 167BAC 8024734C 82430004 */  lb        $v1, 4($s2)
/* 167BB0 80247350 2C620005 */  sltiu     $v0, $v1, 5
/* 167BB4 80247354 10400218 */  beqz      $v0, .L80247BB8
/* 167BB8 80247358 00031080 */   sll      $v0, $v1, 2
/* 167BBC 8024735C 3C018025 */  lui       $at, %hi(jtbl_8024C018)
/* 167BC0 80247360 00220821 */  addu      $at, $at, $v0
/* 167BC4 80247364 8C22C018 */  lw        $v0, %lo(jtbl_8024C018)($at)
/* 167BC8 80247368 00400008 */  jr        $v0
/* 167BCC 8024736C 00000000 */   nop
.L80247370_167BD0:
/* 167BD0 80247370 24020002 */  addiu     $v0, $zero, 2
/* 167BD4 80247374 3C038025 */  lui       $v1, %hi(filemenu_menus + 0x8)
/* 167BD8 80247378 8C639B8C */  lw        $v1, %lo(filemenu_menus + 0x8)($v1)
/* 167BDC 8024737C 3C048016 */  lui       $a0, %hi(gWindows)
/* 167BE0 80247380 24849D50 */  addiu     $a0, $a0, %lo(gWindows)
/* 167BE4 80247384 3C018025 */  lui       $at, %hi(filemenu_8024C098)
/* 167BE8 80247388 A022C098 */  sb        $v0, %lo(filemenu_8024C098)($at)
/* 167BEC 8024738C 240200B6 */  addiu     $v0, $zero, 0xb6
/* 167BF0 80247390 A0600004 */  sb        $zero, 4($v1)
/* 167BF4 80247394 808305E3 */  lb        $v1, 0x5e3($a0)
/* 167BF8 80247398 A48205F0 */  sh        $v0, 0x5f0($a0)
/* 167BFC 8024739C 24020019 */  addiu     $v0, $zero, 0x19
/* 167C00 802473A0 A48205F2 */  sh        $v0, 0x5f2($a0)
/* 167C04 802473A4 2402FFFF */  addiu     $v0, $zero, -1
/* 167C08 802473A8 1062000B */  beq       $v1, $v0, .L802473D8
/* 167C0C 802473AC 248505EC */   addiu    $a1, $a0, 0x5ec
/* 167C10 802473B0 00031140 */  sll       $v0, $v1, 5
/* 167C14 802473B4 00441021 */  addu      $v0, $v0, $a0
/* 167C18 802473B8 94420010 */  lhu       $v0, 0x10($v0)
/* 167C1C 802473BC 00021400 */  sll       $v0, $v0, 0x10
/* 167C20 802473C0 00021C03 */  sra       $v1, $v0, 0x10
/* 167C24 802473C4 000217C2 */  srl       $v0, $v0, 0x1f
/* 167C28 802473C8 00621821 */  addu      $v1, $v1, $v0
/* 167C2C 802473CC 00031843 */  sra       $v1, $v1, 1
/* 167C30 802473D0 08091CF9 */  j         .L802473E4
/* 167C34 802473D4 2463FFA5 */   addiu    $v1, $v1, -0x5b
.L802473D8:
/* 167C38 802473D8 24030045 */  addiu     $v1, $zero, 0x45
/* 167C3C 802473DC 3C048016 */  lui       $a0, %hi(gWindows)
/* 167C40 802473E0 24849D50 */  addiu     $a0, $a0, %lo(gWindows)
.L802473E4:
/* 167C44 802473E4 A4A30000 */  sh        $v1, ($a1)
/* 167C48 802473E8 948205F2 */  lhu       $v0, 0x5f2($a0)
/* 167C4C 802473EC 00021400 */  sll       $v0, $v0, 0x10
/* 167C50 802473F0 00021C03 */  sra       $v1, $v0, 0x10
/* 167C54 802473F4 000217C2 */  srl       $v0, $v0, 0x1f
/* 167C58 802473F8 00621821 */  addu      $v1, $v1, $v0
/* 167C5C 802473FC 00032843 */  sra       $a1, $v1, 1
/* 167C60 80247400 808305E3 */  lb        $v1, 0x5e3($a0)
/* 167C64 80247404 2402FFFF */  addiu     $v0, $zero, -1
/* 167C68 80247408 1062000B */  beq       $v1, $v0, .L80247438
/* 167C6C 8024740C 248605EE */   addiu    $a2, $a0, 0x5ee
/* 167C70 80247410 00031140 */  sll       $v0, $v1, 5
/* 167C74 80247414 00441021 */  addu      $v0, $v0, $a0
/* 167C78 80247418 94420012 */  lhu       $v0, 0x12($v0)
/* 167C7C 8024741C 00021400 */  sll       $v0, $v0, 0x10
/* 167C80 80247420 00021C03 */  sra       $v1, $v0, 0x10
/* 167C84 80247424 000217C2 */  srl       $v0, $v0, 0x1f
/* 167C88 80247428 00621821 */  addu      $v1, $v1, $v0
/* 167C8C 8024742C 00031843 */  sra       $v1, $v1, 1
/* 167C90 80247430 08091D10 */  j         .L80247440
/* 167C94 80247434 00651023 */   subu     $v0, $v1, $a1
.L80247438:
/* 167C98 80247438 24020078 */  addiu     $v0, $zero, 0x78
/* 167C9C 8024743C 00451023 */  subu      $v0, $v0, $a1
.L80247440:
/* 167CA0 80247440 2404002F */  addiu     $a0, $zero, 0x2f
/* 167CA4 80247444 24050001 */  addiu     $a1, $zero, 1
/* 167CA8 80247448 0C051F9F */  jal       set_window_update
/* 167CAC 8024744C A4C20000 */   sh       $v0, ($a2)
/* 167CB0 80247450 3C058024 */  lui       $a1, %hi(filemenu_update_hidden_name_confirm)
/* 167CB4 80247454 24A53EEC */  addiu     $a1, $a1, %lo(filemenu_update_hidden_name_confirm)
/* 167CB8 80247458 0C051F9F */  jal       set_window_update
/* 167CBC 8024745C 24040032 */   addiu    $a0, $zero, 0x32
/* 167CC0 80247460 0000202D */  daddu     $a0, $zero, $zero
/* 167CC4 80247464 3C028025 */  lui       $v0, %hi(filemenu_menus)
/* 167CC8 80247468 8C429B84 */  lw        $v0, %lo(filemenu_menus)($v0)
/* 167CCC 8024746C 3C068007 */  lui       $a2, %hi(D_800779C4)
/* 167CD0 80247470 24C679C4 */  addiu     $a2, $a2, %lo(D_800779C4)
/* 167CD4 80247474 90500003 */  lbu       $s0, 3($v0)
/* 167CD8 80247478 240500F7 */  addiu     $a1, $zero, 0xf7
/* 167CDC 8024747C 00101040 */  sll       $v0, $s0, 1
/* 167CE0 80247480 00501021 */  addu      $v0, $v0, $s0
/* 167CE4 80247484 000218C0 */  sll       $v1, $v0, 3
/* 167CE8 80247488 00831021 */  addu      $v0, $a0, $v1
.L8024748C:
/* 167CEC 8024748C 00461021 */  addu      $v0, $v0, $a2
/* 167CF0 80247490 A0450007 */  sb        $a1, 7($v0)
/* 167CF4 80247494 24840001 */  addiu     $a0, $a0, 1
/* 167CF8 80247498 28820008 */  slti      $v0, $a0, 8
/* 167CFC 8024749C 1440FFFB */  bnez      $v0, .L8024748C
/* 167D00 802474A0 00831021 */   addu     $v0, $a0, $v1
/* 167D04 802474A4 0200202D */  daddu     $a0, $s0, $zero
/* 167D08 802474A8 3C038007 */  lui       $v1, %hi(D_800779C4)
/* 167D0C 802474AC 246379C4 */  addiu     $v1, $v1, %lo(D_800779C4)
/* 167D10 802474B0 00101040 */  sll       $v0, $s0, 1
/* 167D14 802474B4 00501021 */  addu      $v0, $v0, $s0
/* 167D18 802474B8 000210C0 */  sll       $v0, $v0, 3
/* 167D1C 802474BC 00431021 */  addu      $v0, $v0, $v1
/* 167D20 802474C0 A0400006 */  sb        $zero, 6($v0)
/* 167D24 802474C4 AC400000 */  sw        $zero, ($v0)
/* 167D28 802474C8 0C00AD0B */  jal       fio_erase_game
/* 167D2C 802474CC A0400004 */   sb       $zero, 4($v0)
/* 167D30 802474D0 3C018007 */  lui       $at, %hi(D_80077A24)
/* 167D34 802474D4 00300821 */  addu      $at, $at, $s0
/* 167D38 802474D8 A0207A24 */  sb        $zero, %lo(D_80077A24)($at)
/* 167D3C 802474DC 08091EEE */  j         .L80247BB8
/* 167D40 802474E0 00000000 */   nop
.L802474E4_167D44:
/* 167D44 802474E4 24020002 */  addiu     $v0, $zero, 2
/* 167D48 802474E8 3C018025 */  lui       $at, %hi(filemenu_8024C098)
/* 167D4C 802474EC A022C098 */  sb        $v0, %lo(filemenu_8024C098)($at)
/* 167D50 802474F0 24020002 */  addiu     $v0, $zero, 2
/* 167D54 802474F4 3C048016 */  lui       $a0, %hi(gWindows)
/* 167D58 802474F8 24849D50 */  addiu     $a0, $a0, %lo(gWindows)
/* 167D5C 802474FC 3C038025 */  lui       $v1, %hi(filemenu_menus + 0x8)
/* 167D60 80247500 8C639B8C */  lw        $v1, %lo(filemenu_menus + 0x8)($v1)
/* 167D64 80247504 A0620004 */  sb        $v0, 4($v1)
/* 167D68 80247508 808305E3 */  lb        $v1, 0x5e3($a0)
/* 167D6C 8024750C 2402009A */  addiu     $v0, $zero, 0x9a
/* 167D70 80247510 A48205F0 */  sh        $v0, 0x5f0($a0)
/* 167D74 80247514 24020027 */  addiu     $v0, $zero, 0x27
/* 167D78 80247518 A48205F2 */  sh        $v0, 0x5f2($a0)
/* 167D7C 8024751C 2402FFFF */  addiu     $v0, $zero, -1
/* 167D80 80247520 1062000B */  beq       $v1, $v0, .L80247550
/* 167D84 80247524 248505EC */   addiu    $a1, $a0, 0x5ec
/* 167D88 80247528 00031140 */  sll       $v0, $v1, 5
/* 167D8C 8024752C 00441021 */  addu      $v0, $v0, $a0
/* 167D90 80247530 94420010 */  lhu       $v0, 0x10($v0)
/* 167D94 80247534 00021400 */  sll       $v0, $v0, 0x10
/* 167D98 80247538 00021C03 */  sra       $v1, $v0, 0x10
/* 167D9C 8024753C 000217C2 */  srl       $v0, $v0, 0x1f
/* 167DA0 80247540 00621821 */  addu      $v1, $v1, $v0
/* 167DA4 80247544 00031843 */  sra       $v1, $v1, 1
/* 167DA8 80247548 08091D57 */  j         .L8024755C
/* 167DAC 8024754C 2463FFB3 */   addiu    $v1, $v1, -0x4d
.L80247550:
/* 167DB0 80247550 24030053 */  addiu     $v1, $zero, 0x53
/* 167DB4 80247554 3C048016 */  lui       $a0, %hi(gWindows)
/* 167DB8 80247558 24849D50 */  addiu     $a0, $a0, %lo(gWindows)
.L8024755C:
/* 167DBC 8024755C A4A30000 */  sh        $v1, ($a1)
/* 167DC0 80247560 948205F2 */  lhu       $v0, 0x5f2($a0)
/* 167DC4 80247564 00021400 */  sll       $v0, $v0, 0x10
/* 167DC8 80247568 00021C03 */  sra       $v1, $v0, 0x10
/* 167DCC 8024756C 000217C2 */  srl       $v0, $v0, 0x1f
/* 167DD0 80247570 00621821 */  addu      $v1, $v1, $v0
/* 167DD4 80247574 00032843 */  sra       $a1, $v1, 1
/* 167DD8 80247578 808305E3 */  lb        $v1, 0x5e3($a0)
/* 167DDC 8024757C 2402FFFF */  addiu     $v0, $zero, -1
/* 167DE0 80247580 1062000B */  beq       $v1, $v0, .L802475B0
/* 167DE4 80247584 248605EE */   addiu    $a2, $a0, 0x5ee
/* 167DE8 80247588 00031140 */  sll       $v0, $v1, 5
/* 167DEC 8024758C 00441021 */  addu      $v0, $v0, $a0
/* 167DF0 80247590 94420012 */  lhu       $v0, 0x12($v0)
/* 167DF4 80247594 00021400 */  sll       $v0, $v0, 0x10
/* 167DF8 80247598 00021C03 */  sra       $v1, $v0, 0x10
/* 167DFC 8024759C 000217C2 */  srl       $v0, $v0, 0x1f
/* 167E00 802475A0 00621821 */  addu      $v1, $v1, $v0
/* 167E04 802475A4 00031843 */  sra       $v1, $v1, 1
/* 167E08 802475A8 08091D6E */  j         .L802475B8
/* 167E0C 802475AC 00651023 */   subu     $v0, $v1, $a1
.L802475B0:
/* 167E10 802475B0 24020078 */  addiu     $v0, $zero, 0x78
/* 167E14 802475B4 00451023 */  subu      $v0, $v0, $a1
.L802475B8:
/* 167E18 802475B8 2404002F */  addiu     $a0, $zero, 0x2f
/* 167E1C 802475BC 24050001 */  addiu     $a1, $zero, 1
/* 167E20 802475C0 0C051F9F */  jal       set_window_update
/* 167E24 802475C4 A4C20000 */   sh       $v0, ($a2)
/* 167E28 802475C8 3C058024 */  lui       $a1, %hi(filemenu_update_hidden_name_confirm)
/* 167E2C 802475CC 24A53EEC */  addiu     $a1, $a1, %lo(filemenu_update_hidden_name_confirm)
/* 167E30 802475D0 0C051F9F */  jal       set_window_update
/* 167E34 802475D4 24040032 */   addiu    $a0, $zero, 0x32
/* 167E38 802475D8 3C118025 */  lui       $s1, %hi(filemenu_loadedFileIdx)
/* 167E3C 802475DC 2631C094 */  addiu     $s1, $s1, %lo(filemenu_loadedFileIdx)
/* 167E40 802475E0 0C00ACB4 */  jal       fio_load_game
/* 167E44 802475E4 8E240000 */   lw       $a0, ($s1)
/* 167E48 802475E8 3C108025 */  lui       $s0, %hi(filemenu_iterFileIdx)
/* 167E4C 802475EC 2610C080 */  addiu     $s0, $s0, %lo(filemenu_iterFileIdx)
/* 167E50 802475F0 3C068007 */  lui       $a2, %hi(D_800779C4)
/* 167E54 802475F4 24C679C4 */  addiu     $a2, $a2, %lo(D_800779C4)
/* 167E58 802475F8 8E040000 */  lw        $a0, ($s0)
/* 167E5C 802475FC 8E250000 */  lw        $a1, ($s1)
/* 167E60 80247600 0080102D */  daddu     $v0, $a0, $zero
/* 167E64 80247604 00021840 */  sll       $v1, $v0, 1
/* 167E68 80247608 00621821 */  addu      $v1, $v1, $v0
/* 167E6C 8024760C 000318C0 */  sll       $v1, $v1, 3
/* 167E70 80247610 00661821 */  addu      $v1, $v1, $a2
/* 167E74 80247614 00051040 */  sll       $v0, $a1, 1
/* 167E78 80247618 00451021 */  addu      $v0, $v0, $a1
/* 167E7C 8024761C 000210C0 */  sll       $v0, $v0, 3
/* 167E80 80247620 00461021 */  addu      $v0, $v0, $a2
/* 167E84 80247624 8C480000 */  lw        $t0, ($v0)
/* 167E88 80247628 8C490004 */  lw        $t1, 4($v0)
/* 167E8C 8024762C 8C4A0008 */  lw        $t2, 8($v0)
/* 167E90 80247630 8C4B000C */  lw        $t3, 0xc($v0)
/* 167E94 80247634 AC680000 */  sw        $t0, ($v1)
/* 167E98 80247638 AC690004 */  sw        $t1, 4($v1)
/* 167E9C 8024763C AC6A0008 */  sw        $t2, 8($v1)
/* 167EA0 80247640 AC6B000C */  sw        $t3, 0xc($v1)
/* 167EA4 80247644 8C480010 */  lw        $t0, 0x10($v0)
/* 167EA8 80247648 8C490014 */  lw        $t1, 0x14($v0)
/* 167EAC 8024764C AC680010 */  sw        $t0, 0x10($v1)
/* 167EB0 80247650 0C00ACDD */  jal       fio_save_game
/* 167EB4 80247654 AC690014 */   sw       $t1, 0x14($v1)
/* 167EB8 80247658 8E030000 */  lw        $v1, ($s0)
/* 167EBC 8024765C 08091DF9 */  j         .L802477E4
/* 167EC0 80247660 24020001 */   addiu    $v0, $zero, 1
.L80247664_167EC4:
/* 167EC4 80247664 24020002 */  addiu     $v0, $zero, 2
/* 167EC8 80247668 3C018025 */  lui       $at, %hi(filemenu_8024C098)
/* 167ECC 8024766C A022C098 */  sb        $v0, %lo(filemenu_8024C098)($at)
/* 167ED0 80247670 24020001 */  addiu     $v0, $zero, 1
/* 167ED4 80247674 3C048016 */  lui       $a0, %hi(gWindows)
/* 167ED8 80247678 24849D50 */  addiu     $a0, $a0, %lo(gWindows)
/* 167EDC 8024767C 3C038025 */  lui       $v1, %hi(filemenu_menus + 0x8)
/* 167EE0 80247680 8C639B8C */  lw        $v1, %lo(filemenu_menus + 0x8)($v1)
/* 167EE4 80247684 A0620004 */  sb        $v0, 4($v1)
/* 167EE8 80247688 808305E3 */  lb        $v1, 0x5e3($a0)
/* 167EEC 8024768C 24020099 */  addiu     $v0, $zero, 0x99
/* 167EF0 80247690 A48205F0 */  sh        $v0, 0x5f0($a0)
/* 167EF4 80247694 24020019 */  addiu     $v0, $zero, 0x19
/* 167EF8 80247698 A48205F2 */  sh        $v0, 0x5f2($a0)
/* 167EFC 8024769C 2402FFFF */  addiu     $v0, $zero, -1
/* 167F00 802476A0 1062000B */  beq       $v1, $v0, .L802476D0
/* 167F04 802476A4 248505EC */   addiu    $a1, $a0, 0x5ec
/* 167F08 802476A8 00031140 */  sll       $v0, $v1, 5
/* 167F0C 802476AC 00441021 */  addu      $v0, $v0, $a0
/* 167F10 802476B0 94420010 */  lhu       $v0, 0x10($v0)
/* 167F14 802476B4 00021400 */  sll       $v0, $v0, 0x10
/* 167F18 802476B8 00021C03 */  sra       $v1, $v0, 0x10
/* 167F1C 802476BC 000217C2 */  srl       $v0, $v0, 0x1f
/* 167F20 802476C0 00621821 */  addu      $v1, $v1, $v0
/* 167F24 802476C4 00031843 */  sra       $v1, $v1, 1
/* 167F28 802476C8 08091DB7 */  j         .L802476DC
/* 167F2C 802476CC 2463FFB4 */   addiu    $v1, $v1, -0x4c
.L802476D0:
/* 167F30 802476D0 24030054 */  addiu     $v1, $zero, 0x54
/* 167F34 802476D4 3C048016 */  lui       $a0, %hi(gWindows)
/* 167F38 802476D8 24849D50 */  addiu     $a0, $a0, %lo(gWindows)
.L802476DC:
/* 167F3C 802476DC A4A30000 */  sh        $v1, ($a1)
/* 167F40 802476E0 948205F2 */  lhu       $v0, 0x5f2($a0)
/* 167F44 802476E4 00021400 */  sll       $v0, $v0, 0x10
/* 167F48 802476E8 00021C03 */  sra       $v1, $v0, 0x10
/* 167F4C 802476EC 000217C2 */  srl       $v0, $v0, 0x1f
/* 167F50 802476F0 00621821 */  addu      $v1, $v1, $v0
/* 167F54 802476F4 00032843 */  sra       $a1, $v1, 1
/* 167F58 802476F8 808305E3 */  lb        $v1, 0x5e3($a0)
/* 167F5C 802476FC 2402FFFF */  addiu     $v0, $zero, -1
/* 167F60 80247700 1062000B */  beq       $v1, $v0, .L80247730
/* 167F64 80247704 248605EE */   addiu    $a2, $a0, 0x5ee
/* 167F68 80247708 00031140 */  sll       $v0, $v1, 5
/* 167F6C 8024770C 00441021 */  addu      $v0, $v0, $a0
/* 167F70 80247710 94420012 */  lhu       $v0, 0x12($v0)
/* 167F74 80247714 00021400 */  sll       $v0, $v0, 0x10
/* 167F78 80247718 00021C03 */  sra       $v1, $v0, 0x10
/* 167F7C 8024771C 000217C2 */  srl       $v0, $v0, 0x1f
/* 167F80 80247720 00621821 */  addu      $v1, $v1, $v0
/* 167F84 80247724 00031843 */  sra       $v1, $v1, 1
/* 167F88 80247728 08091DCE */  j         .L80247738
/* 167F8C 8024772C 00651023 */   subu     $v0, $v1, $a1
.L80247730:
/* 167F90 80247730 24020078 */  addiu     $v0, $zero, 0x78
/* 167F94 80247734 00451023 */  subu      $v0, $v0, $a1
.L80247738:
/* 167F98 80247738 2404002F */  addiu     $a0, $zero, 0x2f
/* 167F9C 8024773C 24050001 */  addiu     $a1, $zero, 1
/* 167FA0 80247740 0C051F9F */  jal       set_window_update
/* 167FA4 80247744 A4C20000 */   sh       $v0, ($a2)
/* 167FA8 80247748 3C058024 */  lui       $a1, %hi(filemenu_update_hidden_name_confirm)
/* 167FAC 8024774C 24A53EEC */  addiu     $a1, $a1, %lo(filemenu_update_hidden_name_confirm)
/* 167FB0 80247750 0C051F9F */  jal       set_window_update
/* 167FB4 80247754 24040032 */   addiu    $a0, $zero, 0x32
/* 167FB8 80247758 3C108025 */  lui       $s0, %hi(filemenu_menus)
/* 167FBC 8024775C 26109B84 */  addiu     $s0, $s0, %lo(filemenu_menus)
/* 167FC0 80247760 8E020000 */  lw        $v0, ($s0)
/* 167FC4 80247764 90420003 */  lbu       $v0, 3($v0)
/* 167FC8 80247768 3C058007 */  lui       $a1, %hi(D_800779C4)
/* 167FCC 8024776C 24A579C4 */  addiu     $a1, $a1, %lo(D_800779C4)
/* 167FD0 80247770 00021840 */  sll       $v1, $v0, 1
/* 167FD4 80247774 00621821 */  addu      $v1, $v1, $v0
/* 167FD8 80247778 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 167FDC 8024777C 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 167FE0 80247780 000318C0 */  sll       $v1, $v1, 3
/* 167FE4 80247784 90440166 */  lbu       $a0, 0x166($v0)
/* 167FE8 80247788 00651821 */  addu      $v1, $v1, $a1
/* 167FEC 8024778C 00041040 */  sll       $v0, $a0, 1
/* 167FF0 80247790 00441021 */  addu      $v0, $v0, $a0
/* 167FF4 80247794 000210C0 */  sll       $v0, $v0, 3
/* 167FF8 80247798 00451021 */  addu      $v0, $v0, $a1
/* 167FFC 8024779C 8C480000 */  lw        $t0, ($v0)
/* 168000 802477A0 8C490004 */  lw        $t1, 4($v0)
/* 168004 802477A4 8C4A0008 */  lw        $t2, 8($v0)
/* 168008 802477A8 8C4B000C */  lw        $t3, 0xc($v0)
/* 16800C 802477AC AC680000 */  sw        $t0, ($v1)
/* 168010 802477B0 AC690004 */  sw        $t1, 4($v1)
/* 168014 802477B4 AC6A0008 */  sw        $t2, 8($v1)
/* 168018 802477B8 AC6B000C */  sw        $t3, 0xc($v1)
/* 16801C 802477BC 8C480010 */  lw        $t0, 0x10($v0)
/* 168020 802477C0 8C490014 */  lw        $t1, 0x14($v0)
/* 168024 802477C4 AC680010 */  sw        $t0, 0x10($v1)
/* 168028 802477C8 AC690014 */  sw        $t1, 0x14($v1)
/* 16802C 802477CC 8E020000 */  lw        $v0, ($s0)
/* 168030 802477D0 0C00ACDD */  jal       fio_save_game
/* 168034 802477D4 90440003 */   lbu      $a0, 3($v0)
/* 168038 802477D8 8E020000 */  lw        $v0, ($s0)
/* 16803C 802477DC 90430003 */  lbu       $v1, 3($v0)
/* 168040 802477E0 24020001 */  addiu     $v0, $zero, 1
.L802477E4:
/* 168044 802477E4 3C018007 */  lui       $at, %hi(D_80077A24)
/* 168048 802477E8 00230821 */  addu      $at, $at, $v1
/* 16804C 802477EC A0227A24 */  sb        $v0, %lo(D_80077A24)($at)
/* 168050 802477F0 08091EEE */  j         .L80247BB8
/* 168054 802477F4 00000000 */   nop
.L802477F8_168058:
/* 168058 802477F8 0C039CE8 */  jal       clear_player_data
/* 16805C 802477FC 00000000 */   nop
/* 168060 80247800 0C0514C8 */  jal       clear_saved_variables
/* 168064 80247804 00000000 */   nop
/* 168068 80247808 0000202D */  daddu     $a0, $zero, $zero
/* 16806C 8024780C 3C05F5DE */  lui       $a1, 0xf5de
/* 168070 80247810 34A50180 */  ori       $a1, $a1, 0x180
/* 168074 80247814 2406FF80 */  addiu     $a2, $zero, -0x80
/* 168078 80247818 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* 16807C 8024781C 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* 168080 80247820 2402000B */  addiu     $v0, $zero, 0xb
/* 168084 80247824 A4600086 */  sh        $zero, 0x86($v1)
/* 168088 80247828 A462008C */  sh        $v0, 0x8c($v1)
/* 16808C 8024782C 0C0B2026 */  jal       evt_set_variable
/* 168090 80247830 A460008E */   sh       $zero, 0x8e($v1)
/* 168094 80247834 0000202D */  daddu     $a0, $zero, $zero
/* 168098 80247838 3C028025 */  lui       $v0, %hi(filemenu_menus)
/* 16809C 8024783C 8C429B84 */  lw        $v0, %lo(filemenu_menus)($v0)
/* 1680A0 80247840 3C078007 */  lui       $a3, %hi(D_800779C4)
/* 1680A4 80247844 24E779C4 */  addiu     $a3, $a3, %lo(D_800779C4)
/* 1680A8 80247848 90510003 */  lbu       $s1, 3($v0)
/* 1680AC 8024784C 3C068025 */  lui       $a2, %hi(D_8024C110)
/* 1680B0 80247850 24C6C110 */  addiu     $a2, $a2, %lo(D_8024C110)
/* 1680B4 80247854 00111040 */  sll       $v0, $s1, 1
/* 1680B8 80247858 00511021 */  addu      $v0, $v0, $s1
/* 1680BC 8024785C 000228C0 */  sll       $a1, $v0, 3
/* 1680C0 80247860 00851021 */  addu      $v0, $a0, $a1
.L80247864:
/* 1680C4 80247864 00861821 */  addu      $v1, $a0, $a2
/* 1680C8 80247868 24840001 */  addiu     $a0, $a0, 1
/* 1680CC 8024786C 90630000 */  lbu       $v1, ($v1)
/* 1680D0 80247870 00471021 */  addu      $v0, $v0, $a3
/* 1680D4 80247874 A0430007 */  sb        $v1, 7($v0)
/* 1680D8 80247878 28820008 */  slti      $v0, $a0, 8
/* 1680DC 8024787C 1440FFF9 */  bnez      $v0, .L80247864
/* 1680E0 80247880 00851021 */   addu     $v0, $a0, $a1
/* 1680E4 80247884 0C00ACDD */  jal       fio_save_game
/* 1680E8 80247888 0220202D */   daddu    $a0, $s1, $zero
/* 1680EC 8024788C 24040030 */  addiu     $a0, $zero, 0x30
/* 1680F0 80247890 3C108024 */  lui       $s0, %hi(filemenu_update_hidden_name_input)
/* 1680F4 80247894 26103628 */  addiu     $s0, $s0, %lo(filemenu_update_hidden_name_input)
/* 1680F8 80247898 24020001 */  addiu     $v0, $zero, 1
/* 1680FC 8024789C 3C018007 */  lui       $at, %hi(D_80077A24)
/* 168100 802478A0 00310821 */  addu      $at, $at, $s1
/* 168104 802478A4 A0227A24 */  sb        $v0, %lo(D_80077A24)($at)
/* 168108 802478A8 0C051F9F */  jal       set_window_update
/* 16810C 802478AC 0200282D */   daddu    $a1, $s0, $zero
/* 168110 802478B0 24040031 */  addiu     $a0, $zero, 0x31
/* 168114 802478B4 0C051F9F */  jal       set_window_update
/* 168118 802478B8 0200282D */   daddu    $a1, $s0, $zero
/* 16811C 802478BC 2404002D */  addiu     $a0, $zero, 0x2d
/* 168120 802478C0 3C108024 */  lui       $s0, %hi(filemenu_update_show_with_rotation)
/* 168124 802478C4 2610381C */  addiu     $s0, $s0, %lo(filemenu_update_show_with_rotation)
/* 168128 802478C8 0C051F9F */  jal       set_window_update
/* 16812C 802478CC 0200282D */   daddu    $a1, $s0, $zero
/* 168130 802478D0 24040033 */  addiu     $a0, $zero, 0x33
/* 168134 802478D4 0C051F9F */  jal       set_window_update
/* 168138 802478D8 0200282D */   daddu    $a1, $s0, $zero
/* 16813C 802478DC 24040034 */  addiu     $a0, $zero, 0x34
/* 168140 802478E0 0C051F9F */  jal       set_window_update
/* 168144 802478E4 0200282D */   daddu    $a1, $s0, $zero
/* 168148 802478E8 24040035 */  addiu     $a0, $zero, 0x35
/* 16814C 802478EC 0C051F9F */  jal       set_window_update
/* 168150 802478F0 0200282D */   daddu    $a1, $s0, $zero
/* 168154 802478F4 24040036 */  addiu     $a0, $zero, 0x36
/* 168158 802478F8 0C051F9F */  jal       set_window_update
/* 16815C 802478FC 0200282D */   daddu    $a1, $s0, $zero
/* 168160 80247900 24040037 */  addiu     $a0, $zero, 0x37
/* 168164 80247904 0C051F9F */  jal       set_window_update
/* 168168 80247908 0200282D */   daddu    $a1, $s0, $zero
/* 16816C 8024790C 24040035 */  addiu     $a0, $zero, 0x35
/* 168170 80247910 0C051F9F */  jal       set_window_update
/* 168174 80247914 0200282D */   daddu    $a1, $s0, $zero
/* 168178 80247918 24040038 */  addiu     $a0, $zero, 0x38
/* 16817C 8024791C 0C051F9F */  jal       set_window_update
/* 168180 80247920 0200282D */   daddu    $a1, $s0, $zero
/* 168184 80247924 24040039 */  addiu     $a0, $zero, 0x39
/* 168188 80247928 0C051F9F */  jal       set_window_update
/* 16818C 8024792C 0200282D */   daddu    $a1, $s0, $zero
/* 168190 80247930 2404003A */  addiu     $a0, $zero, 0x3a
/* 168194 80247934 0C051F9F */  jal       set_window_update
/* 168198 80247938 0200282D */   daddu    $a1, $s0, $zero
/* 16819C 8024793C 2404003B */  addiu     $a0, $zero, 0x3b
/* 1681A0 80247940 0C051F9F */  jal       set_window_update
/* 1681A4 80247944 0200282D */   daddu    $a1, $s0, $zero
/* 1681A8 80247948 3C058024 */  lui       $a1, %hi(filemenu_update_hidden_name_confirm)
/* 1681AC 8024794C 24A53EEC */  addiu     $a1, $a1, %lo(filemenu_update_hidden_name_confirm)
/* 1681B0 80247950 0C051F9F */  jal       set_window_update
/* 1681B4 80247954 24040032 */   addiu    $a0, $zero, 0x32
/* 1681B8 80247958 24020002 */  addiu     $v0, $zero, 2
/* 1681BC 8024795C 3C018025 */  lui       $at, %hi(filemenu_8024C098)
/* 1681C0 80247960 A022C098 */  sb        $v0, %lo(filemenu_8024C098)($at)
/* 1681C4 80247964 24020003 */  addiu     $v0, $zero, 3
/* 1681C8 80247968 3C048016 */  lui       $a0, %hi(gWindows)
/* 1681CC 8024796C 24849D50 */  addiu     $a0, $a0, %lo(gWindows)
/* 1681D0 80247970 3C038025 */  lui       $v1, %hi(filemenu_menus + 0x8)
/* 1681D4 80247974 8C639B8C */  lw        $v1, %lo(filemenu_menus + 0x8)($v1)
/* 1681D8 80247978 A0620004 */  sb        $v0, 4($v1)
/* 1681DC 8024797C 808305E3 */  lb        $v1, 0x5e3($a0)
/* 1681E0 80247980 240200B8 */  addiu     $v0, $zero, 0xb8
/* 1681E4 80247984 A48205F0 */  sh        $v0, 0x5f0($a0)
/* 1681E8 80247988 24020019 */  addiu     $v0, $zero, 0x19
/* 1681EC 8024798C A48205F2 */  sh        $v0, 0x5f2($a0)
/* 1681F0 80247990 2402FFFF */  addiu     $v0, $zero, -1
/* 1681F4 80247994 1062000B */  beq       $v1, $v0, .L802479C4
/* 1681F8 80247998 248505EC */   addiu    $a1, $a0, 0x5ec
/* 1681FC 8024799C 00031140 */  sll       $v0, $v1, 5
/* 168200 802479A0 00441021 */  addu      $v0, $v0, $a0
/* 168204 802479A4 94420010 */  lhu       $v0, 0x10($v0)
/* 168208 802479A8 00021400 */  sll       $v0, $v0, 0x10
/* 16820C 802479AC 00021C03 */  sra       $v1, $v0, 0x10
/* 168210 802479B0 000217C2 */  srl       $v0, $v0, 0x1f
/* 168214 802479B4 00621821 */  addu      $v1, $v1, $v0
/* 168218 802479B8 00031843 */  sra       $v1, $v1, 1
/* 16821C 802479BC 08091E74 */  j         .L802479D0
/* 168220 802479C0 2463FFA4 */   addiu    $v1, $v1, -0x5c
.L802479C4:
/* 168224 802479C4 24030044 */  addiu     $v1, $zero, 0x44
/* 168228 802479C8 3C048016 */  lui       $a0, %hi(gWindows)
/* 16822C 802479CC 24849D50 */  addiu     $a0, $a0, %lo(gWindows)
.L802479D0:
/* 168230 802479D0 A4A30000 */  sh        $v1, ($a1)
/* 168234 802479D4 948205F2 */  lhu       $v0, 0x5f2($a0)
/* 168238 802479D8 00021400 */  sll       $v0, $v0, 0x10
/* 16823C 802479DC 00021C03 */  sra       $v1, $v0, 0x10
/* 168240 802479E0 000217C2 */  srl       $v0, $v0, 0x1f
/* 168244 802479E4 00621821 */  addu      $v1, $v1, $v0
/* 168248 802479E8 00032843 */  sra       $a1, $v1, 1
/* 16824C 802479EC 808305E3 */  lb        $v1, 0x5e3($a0)
/* 168250 802479F0 2402FFFF */  addiu     $v0, $zero, -1
/* 168254 802479F4 1062000B */  beq       $v1, $v0, .L80247A24
/* 168258 802479F8 248605EE */   addiu    $a2, $a0, 0x5ee
/* 16825C 802479FC 00031140 */  sll       $v0, $v1, 5
/* 168260 80247A00 00441021 */  addu      $v0, $v0, $a0
/* 168264 80247A04 94420012 */  lhu       $v0, 0x12($v0)
/* 168268 80247A08 00021400 */  sll       $v0, $v0, 0x10
/* 16826C 80247A0C 00021C03 */  sra       $v1, $v0, 0x10
/* 168270 80247A10 000217C2 */  srl       $v0, $v0, 0x1f
/* 168274 80247A14 00621821 */  addu      $v1, $v1, $v0
/* 168278 80247A18 00031843 */  sra       $v1, $v1, 1
/* 16827C 80247A1C 08091E8B */  j         .L80247A2C
/* 168280 80247A20 00651023 */   subu     $v0, $v1, $a1
.L80247A24:
/* 168284 80247A24 24020078 */  addiu     $v0, $zero, 0x78
/* 168288 80247A28 00451023 */  subu      $v0, $v0, $a1
.L80247A2C:
/* 16828C 80247A2C A4C20000 */  sh        $v0, ($a2)
/* 168290 80247A30 2404002F */  addiu     $a0, $zero, 0x2f
/* 168294 80247A34 08091EEC */  j         .L80247BB0
/* 168298 80247A38 24050001 */   addiu    $a1, $zero, 1
.L80247A3C_16829C:
/* 16829C 80247A3C 3C05800E */  lui       $a1, %hi(D_800D95E8)
/* 1682A0 80247A40 24A595E8 */  addiu     $a1, $a1, %lo(D_800D95E8)
/* 1682A4 80247A44 24060001 */  addiu     $a2, $zero, 1
/* 1682A8 80247A48 8CA20038 */  lw        $v0, 0x38($a1)
/* 1682AC 80247A4C 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* 1682B0 80247A50 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* 1682B4 80247A54 3C048025 */  lui       $a0, %hi(filemenu_menus)
/* 1682B8 80247A58 8C849B84 */  lw        $a0, %lo(filemenu_menus)($a0)
/* 1682BC 80247A5C 00C21023 */  subu      $v0, $a2, $v0
/* 1682C0 80247A60 906300AB */  lbu       $v1, 0xab($v1)
/* 1682C4 80247A64 90900003 */  lbu       $s0, 3($a0)
/* 1682C8 80247A68 14620004 */  bne       $v1, $v0, .L80247A7C
/* 1682CC 80247A6C 00C31023 */   subu     $v0, $a2, $v1
/* 1682D0 80247A70 90A2003F */  lbu       $v0, 0x3f($a1)
/* 1682D4 80247A74 12020004 */  beq       $s0, $v0, .L80247A88
/* 1682D8 80247A78 00C31023 */   subu     $v0, $a2, $v1
.L80247A7C:
/* 1682DC 80247A7C ACA20038 */  sw        $v0, 0x38($a1)
/* 1682E0 80247A80 0C00AC13 */  jal       fio_flush_backups
/* 1682E4 80247A84 ACB0003C */   sw       $s0, 0x3c($a1)
.L80247A88:
/* 1682E8 80247A88 0C00ACB4 */  jal       fio_load_game
/* 1682EC 80247A8C 0200202D */   daddu    $a0, $s0, $zero
/* 1682F0 80247A90 0C00CD3C */  jal       set_game_mode
/* 1682F4 80247A94 2404000F */   addiu    $a0, $zero, 0xf
/* 1682F8 80247A98 08091EEE */  j         .L80247BB8
/* 1682FC 80247A9C 00000000 */   nop
.L80247AA0:
/* 168300 80247AA0 82430004 */  lb        $v1, 4($s2)
/* 168304 80247AA4 2C620005 */  sltiu     $v0, $v1, 5
/* 168308 80247AA8 10400043 */  beqz      $v0, .L80247BB8
/* 16830C 80247AAC 00031080 */   sll      $v0, $v1, 2
/* 168310 80247AB0 3C018025 */  lui       $at, %hi(jtbl_8024C030)
/* 168314 80247AB4 00220821 */  addu      $at, $at, $v0
/* 168318 80247AB8 8C22C030 */  lw        $v0, %lo(jtbl_8024C030)($at)
/* 16831C 80247ABC 00400008 */  jr        $v0
/* 168320 80247AC0 00000000 */   nop
.L80247AC4_168324:
/* 168324 80247AC4 3C018025 */  lui       $at, %hi(filemenu_8024C098)
/* 168328 80247AC8 A020C098 */  sb        $zero, %lo(filemenu_8024C098)($at)
/* 16832C 80247ACC 3C058024 */  lui       $a1, %hi(filemenu_update_hidden_name_confirm)
/* 168330 80247AD0 24A53EEC */  addiu     $a1, $a1, %lo(filemenu_update_hidden_name_confirm)
/* 168334 80247AD4 08091EEC */  j         .L80247BB0
/* 168338 80247AD8 24040032 */   addiu    $a0, $zero, 0x32
.L80247ADC_16833C:
/* 16833C 80247ADC 24020003 */  addiu     $v0, $zero, 3
/* 168340 80247AE0 3C018025 */  lui       $at, %hi(filemenu_8024C098)
/* 168344 80247AE4 A022C098 */  sb        $v0, %lo(filemenu_8024C098)($at)
/* 168348 80247AE8 3C058024 */  lui       $a1, %hi(filemenu_update_hidden_name_confirm)
/* 16834C 80247AEC 24A53EEC */  addiu     $a1, $a1, %lo(filemenu_update_hidden_name_confirm)
/* 168350 80247AF0 08091EEC */  j         .L80247BB0
/* 168354 80247AF4 24040032 */   addiu    $a0, $zero, 0x32
.L80247AF8_168358:
/* 168358 80247AF8 2404002D */  addiu     $a0, $zero, 0x2d
/* 16835C 80247AFC 3C108024 */  lui       $s0, %hi(filemenu_update_show_with_rotation)
/* 168360 80247B00 2610381C */  addiu     $s0, $s0, %lo(filemenu_update_show_with_rotation)
/* 168364 80247B04 3C028025 */  lui       $v0, %hi(filemenu_menus)
/* 168368 80247B08 8C429B84 */  lw        $v0, %lo(filemenu_menus)($v0)
/* 16836C 80247B0C 3C018025 */  lui       $at, %hi(filemenu_8024C098)
/* 168370 80247B10 A020C098 */  sb        $zero, %lo(filemenu_8024C098)($at)
/* 168374 80247B14 90510003 */  lbu       $s1, 3($v0)
/* 168378 80247B18 0C051F9F */  jal       set_window_update
/* 16837C 80247B1C 0200282D */   daddu    $a1, $s0, $zero
/* 168380 80247B20 24040033 */  addiu     $a0, $zero, 0x33
/* 168384 80247B24 0C051F9F */  jal       set_window_update
/* 168388 80247B28 0200282D */   daddu    $a1, $s0, $zero
/* 16838C 80247B2C 24040034 */  addiu     $a0, $zero, 0x34
/* 168390 80247B30 0C051F9F */  jal       set_window_update
/* 168394 80247B34 0200282D */   daddu    $a1, $s0, $zero
/* 168398 80247B38 24040035 */  addiu     $a0, $zero, 0x35
/* 16839C 80247B3C 0C051F9F */  jal       set_window_update
/* 1683A0 80247B40 0200282D */   daddu    $a1, $s0, $zero
/* 1683A4 80247B44 24040036 */  addiu     $a0, $zero, 0x36
/* 1683A8 80247B48 0C051F9F */  jal       set_window_update
/* 1683AC 80247B4C 0200282D */   daddu    $a1, $s0, $zero
/* 1683B0 80247B50 24040037 */  addiu     $a0, $zero, 0x37
/* 1683B4 80247B54 0C051F9F */  jal       set_window_update
/* 1683B8 80247B58 0200282D */   daddu    $a1, $s0, $zero
/* 1683BC 80247B5C 24040035 */  addiu     $a0, $zero, 0x35
/* 1683C0 80247B60 0C051F9F */  jal       set_window_update
/* 1683C4 80247B64 0200282D */   daddu    $a1, $s0, $zero
/* 1683C8 80247B68 24040038 */  addiu     $a0, $zero, 0x38
/* 1683CC 80247B6C 0C051F9F */  jal       set_window_update
/* 1683D0 80247B70 0200282D */   daddu    $a1, $s0, $zero
/* 1683D4 80247B74 24040039 */  addiu     $a0, $zero, 0x39
/* 1683D8 80247B78 0C051F9F */  jal       set_window_update
/* 1683DC 80247B7C 0200282D */   daddu    $a1, $s0, $zero
/* 1683E0 80247B80 2404003A */  addiu     $a0, $zero, 0x3a
/* 1683E4 80247B84 0C051F9F */  jal       set_window_update
/* 1683E8 80247B88 0200282D */   daddu    $a1, $s0, $zero
/* 1683EC 80247B8C 2404003B */  addiu     $a0, $zero, 0x3b
/* 1683F0 80247B90 0C051F9F */  jal       set_window_update
/* 1683F4 80247B94 0200282D */   daddu    $a1, $s0, $zero
/* 1683F8 80247B98 3C058024 */  lui       $a1, %hi(filemenu_update_deselect_file)
/* 1683FC 80247B9C 24A53B10 */  addiu     $a1, $a1, %lo(filemenu_update_deselect_file)
/* 168400 80247BA0 0C051F9F */  jal       set_window_update
/* 168404 80247BA4 26240038 */   addiu    $a0, $s1, 0x38
/* 168408 80247BA8 24040032 */  addiu     $a0, $zero, 0x32
/* 16840C 80247BAC 24050002 */  addiu     $a1, $zero, 2
.L80247BB0:
/* 168410 80247BB0 0C051F9F */  jal       set_window_update
/* 168414 80247BB4 00000000 */   nop
.L80247BB8:
/* 168418 80247BB8 3C028025 */  lui       $v0, %hi(filemenu_pressedButtons)
/* 16841C 80247BBC 8C42C084 */  lw        $v0, %lo(filemenu_pressedButtons)($v0)
/* 168420 80247BC0 30424000 */  andi      $v0, $v0, 0x4000
/* 168424 80247BC4 1040004D */  beqz      $v0, .L80247CFC
/* 168428 80247BC8 00000000 */   nop
/* 16842C 80247BCC 0C05272D */  jal       sfx_play_sound
/* 168430 80247BD0 240400CA */   addiu    $a0, $zero, 0xca
/* 168434 80247BD4 0240202D */  daddu     $a0, $s2, $zero
/* 168438 80247BD8 0000282D */  daddu     $a1, $zero, $zero
/* 16843C 80247BDC 0C090B65 */  jal       filemenu_set_selected
/* 168440 80247BE0 24060001 */   addiu    $a2, $zero, 1
/* 168444 80247BE4 82440004 */  lb        $a0, 4($s2)
/* 168448 80247BE8 2C820005 */  sltiu     $v0, $a0, 5
/* 16844C 80247BEC 10400043 */  beqz      $v0, .L80247CFC
/* 168450 80247BF0 00041080 */   sll      $v0, $a0, 2
/* 168454 80247BF4 3C018025 */  lui       $at, %hi(jtbl_8024C048)
/* 168458 80247BF8 00220821 */  addu      $at, $at, $v0
/* 16845C 80247BFC 8C22C048 */  lw        $v0, %lo(jtbl_8024C048)($at)
/* 168460 80247C00 00400008 */  jr        $v0
/* 168464 80247C04 00000000 */   nop
.L80247C08_168468:
/* 168468 80247C08 3C018025 */  lui       $at, %hi(filemenu_8024C098)
/* 16846C 80247C0C A020C098 */  sb        $zero, %lo(filemenu_8024C098)($at)
/* 168470 80247C10 3C058024 */  lui       $a1, %hi(filemenu_update_hidden_name_confirm)
/* 168474 80247C14 24A53EEC */  addiu     $a1, $a1, %lo(filemenu_update_hidden_name_confirm)
/* 168478 80247C18 08091F3D */  j         .L80247CF4
/* 16847C 80247C1C 24040032 */   addiu    $a0, $zero, 0x32
.L80247C20_168480:
/* 168480 80247C20 24020003 */  addiu     $v0, $zero, 3
/* 168484 80247C24 3C018025 */  lui       $at, %hi(filemenu_8024C098)
/* 168488 80247C28 A022C098 */  sb        $v0, %lo(filemenu_8024C098)($at)
/* 16848C 80247C2C 3C058024 */  lui       $a1, %hi(filemenu_update_hidden_name_confirm)
/* 168490 80247C30 24A53EEC */  addiu     $a1, $a1, %lo(filemenu_update_hidden_name_confirm)
/* 168494 80247C34 08091F3D */  j         .L80247CF4
/* 168498 80247C38 24040032 */   addiu    $a0, $zero, 0x32
.L80247C3C_16849C:
/* 16849C 80247C3C 2404002D */  addiu     $a0, $zero, 0x2d
/* 1684A0 80247C40 3C108024 */  lui       $s0, %hi(filemenu_update_show_with_rotation)
/* 1684A4 80247C44 2610381C */  addiu     $s0, $s0, %lo(filemenu_update_show_with_rotation)
/* 1684A8 80247C48 3C028025 */  lui       $v0, %hi(filemenu_menus)
/* 1684AC 80247C4C 8C429B84 */  lw        $v0, %lo(filemenu_menus)($v0)
/* 1684B0 80247C50 3C018025 */  lui       $at, %hi(filemenu_8024C098)
/* 1684B4 80247C54 A020C098 */  sb        $zero, %lo(filemenu_8024C098)($at)
/* 1684B8 80247C58 90510003 */  lbu       $s1, 3($v0)
/* 1684BC 80247C5C 0C051F9F */  jal       set_window_update
/* 1684C0 80247C60 0200282D */   daddu    $a1, $s0, $zero
/* 1684C4 80247C64 24040033 */  addiu     $a0, $zero, 0x33
/* 1684C8 80247C68 0C051F9F */  jal       set_window_update
/* 1684CC 80247C6C 0200282D */   daddu    $a1, $s0, $zero
/* 1684D0 80247C70 24040034 */  addiu     $a0, $zero, 0x34
/* 1684D4 80247C74 0C051F9F */  jal       set_window_update
/* 1684D8 80247C78 0200282D */   daddu    $a1, $s0, $zero
/* 1684DC 80247C7C 24040035 */  addiu     $a0, $zero, 0x35
/* 1684E0 80247C80 0C051F9F */  jal       set_window_update
/* 1684E4 80247C84 0200282D */   daddu    $a1, $s0, $zero
/* 1684E8 80247C88 24040036 */  addiu     $a0, $zero, 0x36
/* 1684EC 80247C8C 0C051F9F */  jal       set_window_update
/* 1684F0 80247C90 0200282D */   daddu    $a1, $s0, $zero
/* 1684F4 80247C94 24040037 */  addiu     $a0, $zero, 0x37
/* 1684F8 80247C98 0C051F9F */  jal       set_window_update
/* 1684FC 80247C9C 0200282D */   daddu    $a1, $s0, $zero
/* 168500 80247CA0 24040035 */  addiu     $a0, $zero, 0x35
/* 168504 80247CA4 0C051F9F */  jal       set_window_update
/* 168508 80247CA8 0200282D */   daddu    $a1, $s0, $zero
/* 16850C 80247CAC 24040038 */  addiu     $a0, $zero, 0x38
/* 168510 80247CB0 0C051F9F */  jal       set_window_update
/* 168514 80247CB4 0200282D */   daddu    $a1, $s0, $zero
/* 168518 80247CB8 24040039 */  addiu     $a0, $zero, 0x39
/* 16851C 80247CBC 0C051F9F */  jal       set_window_update
/* 168520 80247CC0 0200282D */   daddu    $a1, $s0, $zero
/* 168524 80247CC4 2404003A */  addiu     $a0, $zero, 0x3a
/* 168528 80247CC8 0C051F9F */  jal       set_window_update
/* 16852C 80247CCC 0200282D */   daddu    $a1, $s0, $zero
/* 168530 80247CD0 2404003B */  addiu     $a0, $zero, 0x3b
/* 168534 80247CD4 0C051F9F */  jal       set_window_update
/* 168538 80247CD8 0200282D */   daddu    $a1, $s0, $zero
/* 16853C 80247CDC 3C058024 */  lui       $a1, %hi(filemenu_update_deselect_file)
/* 168540 80247CE0 24A53B10 */  addiu     $a1, $a1, %lo(filemenu_update_deselect_file)
/* 168544 80247CE4 0C051F9F */  jal       set_window_update
/* 168548 80247CE8 26240038 */   addiu    $a0, $s1, 0x38
/* 16854C 80247CEC 24040032 */  addiu     $a0, $zero, 0x32
/* 168550 80247CF0 24050002 */  addiu     $a1, $zero, 2
.L80247CF4:
/* 168554 80247CF4 0C051F9F */  jal       set_window_update
/* 168558 80247CF8 00000000 */   nop
.L80247CFC:
/* 16855C 80247CFC 8FBF001C */  lw        $ra, 0x1c($sp)
/* 168560 80247D00 8FB20018 */  lw        $s2, 0x18($sp)
/* 168564 80247D04 8FB10014 */  lw        $s1, 0x14($sp)
/* 168568 80247D08 8FB00010 */  lw        $s0, 0x10($sp)
/* 16856C 80247D0C 03E00008 */  jr        $ra
/* 168570 80247D10 27BD0020 */   addiu    $sp, $sp, 0x20
