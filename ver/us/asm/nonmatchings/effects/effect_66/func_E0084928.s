.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E0084928
/* 3892F8 E0084928 27BDFF58 */  addiu     $sp, $sp, -0xa8
/* 3892FC E008492C 3C06DB06 */  lui       $a2, 0xdb06
/* 389300 E0084930 AFA400A8 */  sw        $a0, 0xa8($sp)
/* 389304 E0084934 8FAA00A8 */  lw        $t2, 0xa8($sp)
/* 389308 E0084938 34C60024 */  ori       $a2, $a2, 0x24
/* 38930C E008493C AFB3007C */  sw        $s3, 0x7c($sp)
/* 389310 E0084940 3C13800A */  lui       $s3, %hi(gMasterGfxPos)
/* 389314 E0084944 2673A66C */  addiu     $s3, $s3, %lo(gMasterGfxPos)
/* 389318 E0084948 AFBF0094 */  sw        $ra, 0x94($sp)
/* 38931C E008494C AFBE0090 */  sw        $fp, 0x90($sp)
/* 389320 E0084950 AFB7008C */  sw        $s7, 0x8c($sp)
/* 389324 E0084954 AFB60088 */  sw        $s6, 0x88($sp)
/* 389328 E0084958 AFB50084 */  sw        $s5, 0x84($sp)
/* 38932C E008495C AFB40080 */  sw        $s4, 0x80($sp)
/* 389330 E0084960 AFB20078 */  sw        $s2, 0x78($sp)
/* 389334 E0084964 AFB10074 */  sw        $s1, 0x74($sp)
/* 389338 E0084968 AFB00070 */  sw        $s0, 0x70($sp)
/* 38933C E008496C F7B600A0 */  sdc1      $f22, 0xa0($sp)
/* 389340 E0084970 F7B40098 */  sdc1      $f20, 0x98($sp)
/* 389344 E0084974 8E650000 */  lw        $a1, ($s3)
/* 389348 E0084978 8D51000C */  lw        $s1, 0xc($t2)
/* 38934C E008497C 00A0182D */  daddu     $v1, $a1, $zero
/* 389350 E0084980 8E360044 */  lw        $s6, 0x44($s1)
/* 389354 E0084984 96220000 */  lhu       $v0, ($s1)
/* 389358 E0084988 24A50008 */  addiu     $a1, $a1, 8
/* 38935C E008498C AE650000 */  sw        $a1, ($s3)
/* 389360 E0084990 0002F080 */  sll       $fp, $v0, 2
/* 389364 E0084994 3C0AE008 */  lui       $t2, %hi(D_E0084E10)
/* 389368 E0084998 015E5021 */  addu      $t2, $t2, $fp
/* 38936C E008499C 8D4A4E10 */  lw        $t2, %lo(D_E0084E10)($t2)
/* 389370 E00849A0 27A40020 */  addiu     $a0, $sp, 0x20
/* 389374 E00849A4 AFAA0060 */  sw        $t2, 0x60($sp)
/* 389378 E00849A8 3C0AE008 */  lui       $t2, %hi(D_E0084E28)
/* 38937C E00849AC 015E5021 */  addu      $t2, $t2, $fp
/* 389380 E00849B0 8D4A4E28 */  lw        $t2, %lo(D_E0084E28)($t2)
/* 389384 E00849B4 3C100001 */  lui       $s0, 1
/* 389388 E00849B8 AFAA0064 */  sw        $t2, 0x64($sp)
/* 38938C E00849BC C6360038 */  lwc1      $f22, 0x38($s1)
/* 389390 E00849C0 C6340040 */  lwc1      $f20, 0x40($s1)
/* 389394 E00849C4 8E2A004C */  lw        $t2, 0x4c($s1)
/* 389398 E00849C8 3C02E700 */  lui       $v0, 0xe700
/* 38939C E00849CC AFAA0068 */  sw        $t2, 0x68($sp)
/* 3893A0 E00849D0 AC620000 */  sw        $v0, ($v1)
/* 3893A4 E00849D4 AC600004 */  sw        $zero, 4($v1)
/* 3893A8 E00849D8 ACA60000 */  sw        $a2, ($a1)
/* 3893AC E00849DC 8FAA00A8 */  lw        $t2, 0xa8($sp)
/* 3893B0 E00849E0 36101630 */  ori       $s0, $s0, 0x1630
/* 3893B4 E00849E4 8D430010 */  lw        $v1, 0x10($t2)
/* 3893B8 E00849E8 24A20008 */  addiu     $v0, $a1, 8
/* 3893BC E00849EC AE620000 */  sw        $v0, ($s3)
/* 3893C0 E00849F0 8C62001C */  lw        $v0, 0x1c($v1)
/* 3893C4 E00849F4 3C038000 */  lui       $v1, 0x8000
/* 3893C8 E00849F8 00431021 */  addu      $v0, $v0, $v1
/* 3893CC E00849FC ACA20004 */  sw        $v0, 4($a1)
/* 3893D0 E0084A00 8E250008 */  lw        $a1, 8($s1)
/* 3893D4 E0084A04 8E26000C */  lw        $a2, 0xc($s1)
/* 3893D8 E0084A08 8E270010 */  lw        $a3, 0x10($s1)
/* 3893DC E0084A0C 0C080108 */  jal       func_E0200420
/* 3893E0 E0084A10 24120001 */   addiu    $s2, $zero, 1
/* 3893E4 E0084A14 27A40020 */  addiu     $a0, $sp, 0x20
/* 3893E8 E0084A18 3C148007 */  lui       $s4, %hi(gMatrixListPos)
/* 3893EC E0084A1C 269441F0 */  addiu     $s4, $s4, %lo(gMatrixListPos)
/* 3893F0 E0084A20 3C15800A */  lui       $s5, %hi(gDisplayContext)
/* 3893F4 E0084A24 26B5A674 */  addiu     $s5, $s5, %lo(gDisplayContext)
/* 3893F8 E0084A28 96850000 */  lhu       $a1, ($s4)
/* 3893FC E0084A2C 8EA20000 */  lw        $v0, ($s5)
/* 389400 E0084A30 00052980 */  sll       $a1, $a1, 6
/* 389404 E0084A34 00B02821 */  addu      $a1, $a1, $s0
/* 389408 E0084A38 0C080118 */  jal       func_E0200460
/* 38940C E0084A3C 00452821 */   addu     $a1, $v0, $a1
/* 389410 E0084A40 0260202D */  daddu     $a0, $s3, $zero
/* 389414 E0084A44 3C02DA38 */  lui       $v0, 0xda38
/* 389418 E0084A48 8E670000 */  lw        $a3, ($s3)
/* 38941C E0084A4C 96860000 */  lhu       $a2, ($s4)
/* 389420 E0084A50 00E0282D */  daddu     $a1, $a3, $zero
/* 389424 E0084A54 ACA20000 */  sw        $v0, ($a1)
/* 389428 E0084A58 30C2FFFF */  andi      $v0, $a2, 0xffff
/* 38942C E0084A5C 00021180 */  sll       $v0, $v0, 6
/* 389430 E0084A60 00501021 */  addu      $v0, $v0, $s0
/* 389434 E0084A64 8EA30000 */  lw        $v1, ($s5)
/* 389438 E0084A68 24E70008 */  addiu     $a3, $a3, 8
/* 38943C E0084A6C 00621821 */  addu      $v1, $v1, $v0
/* 389440 E0084A70 ACA30004 */  sw        $v1, 4($a1)
/* 389444 E0084A74 96250002 */  lhu       $a1, 2($s1)
/* 389448 E0084A78 00D23021 */  addu      $a2, $a2, $s2
/* 38944C E0084A7C AE670000 */  sw        $a3, ($s3)
/* 389450 E0084A80 0C080158 */  jal       func_E0200560
/* 389454 E0084A84 A6860000 */   sh       $a2, ($s4)
/* 389458 E0084A88 8FAA00A8 */  lw        $t2, 0xa8($sp)
/* 38945C E0084A8C 0016B080 */  sll       $s6, $s6, 2
/* 389460 E0084A90 8D420008 */  lw        $v0, 8($t2)
/* 389464 E0084A94 0242102A */  slt       $v0, $s2, $v0
/* 389468 E0084A98 10400051 */  beqz      $v0, .LE0084BE0
/* 38946C E0084A9C 26310050 */   addiu    $s1, $s1, 0x50
/* 389470 E0084AA0 3C170001 */  lui       $s7, 1
/* 389474 E0084AA4 36F71630 */  ori       $s7, $s7, 0x1630
/* 389478 E0084AA8 0260A82D */  daddu     $s5, $s3, $zero
/* 38947C E0084AAC 3C02E008 */  lui       $v0, %hi(D_E0084E1C)
/* 389480 E0084AB0 24424E1C */  addiu     $v0, $v0, %lo(D_E0084E1C)
/* 389484 E0084AB4 03C2F021 */  addu      $fp, $fp, $v0
/* 389488 E0084AB8 2630001C */  addiu     $s0, $s1, 0x1c
/* 38948C E0084ABC 26D40050 */  addiu     $s4, $s6, 0x50
/* 389490 E0084AC0 26D3FFD8 */  addiu     $s3, $s6, -0x28
/* 389494 E0084AC4 26D10082 */  addiu     $s1, $s6, 0x82
.LE0084AC8:
/* 389498 E0084AC8 27A40020 */  addiu     $a0, $sp, 0x20
/* 38949C E0084ACC 44912000 */  mtc1      $s1, $f4
/* 3894A0 E0084AD0 00000000 */  nop
/* 3894A4 E0084AD4 46802120 */  cvt.s.w   $f4, $f4
/* 3894A8 E0084AD8 44052000 */  mfc1      $a1, $f4
/* 3894AC E0084ADC 44932000 */  mtc1      $s3, $f4
/* 3894B0 E0084AE0 00000000 */  nop
/* 3894B4 E0084AE4 46802120 */  cvt.s.w   $f4, $f4
/* 3894B8 E0084AE8 44062000 */  mfc1      $a2, $f4
/* 3894BC E0084AEC 44942000 */  mtc1      $s4, $f4
/* 3894C0 E0084AF0 00000000 */  nop
/* 3894C4 E0084AF4 46802120 */  cvt.s.w   $f4, $f4
/* 3894C8 E0084AF8 44072000 */  mfc1      $a3, $f4
/* 3894CC E0084AFC 26940050 */  addiu     $s4, $s4, 0x50
/* 3894D0 E0084B00 E7B40010 */  swc1      $f20, 0x10($sp)
/* 3894D4 E0084B04 C600FFF8 */  lwc1      $f0, -8($s0)
/* 3894D8 E0084B08 2673FFD8 */  addiu     $s3, $s3, -0x28
/* 3894DC E0084B0C E7A00014 */  swc1      $f0, 0x14($sp)
/* 3894E0 E0084B10 C600FFFC */  lwc1      $f0, -4($s0)
/* 3894E4 E0084B14 26310082 */  addiu     $s1, $s1, 0x82
/* 3894E8 E0084B18 E7A00018 */  swc1      $f0, 0x18($sp)
/* 3894EC E0084B1C C6000000 */  lwc1      $f0, ($s0)
/* 3894F0 E0084B20 26520001 */  addiu     $s2, $s2, 1
/* 3894F4 E0084B24 0C080180 */  jal       func_E0200600
/* 3894F8 E0084B28 E7A0001C */   swc1     $f0, 0x1c($sp)
/* 3894FC E0084B2C 27A40020 */  addiu     $a0, $sp, 0x20
/* 389500 E0084B30 3C058007 */  lui       $a1, %hi(gMatrixListPos)
/* 389504 E0084B34 94A541F0 */  lhu       $a1, %lo(gMatrixListPos)($a1)
/* 389508 E0084B38 3C02800A */  lui       $v0, %hi(gDisplayContext)
/* 38950C E0084B3C 8C42A674 */  lw        $v0, %lo(gDisplayContext)($v0)
/* 389510 E0084B40 00052980 */  sll       $a1, $a1, 6
/* 389514 E0084B44 00B72821 */  addu      $a1, $a1, $s7
/* 389518 E0084B48 0C080118 */  jal       func_E0200460
/* 38951C E0084B4C 00452821 */   addu     $a1, $v0, $a1
/* 389520 E0084B50 3C06D838 */  lui       $a2, 0xd838
/* 389524 E0084B54 8EA40000 */  lw        $a0, ($s5)
/* 389528 E0084B58 34C60002 */  ori       $a2, $a2, 2
/* 38952C E0084B5C 0080282D */  daddu     $a1, $a0, $zero
/* 389530 E0084B60 24840008 */  addiu     $a0, $a0, 8
/* 389534 E0084B64 AEA40000 */  sw        $a0, ($s5)
/* 389538 E0084B68 3C028007 */  lui       $v0, %hi(gMatrixListPos)
/* 38953C E0084B6C 944241F0 */  lhu       $v0, %lo(gMatrixListPos)($v0)
/* 389540 E0084B70 3C03DA38 */  lui       $v1, 0xda38
/* 389544 E0084B74 ACA30000 */  sw        $v1, ($a1)
/* 389548 E0084B78 24430001 */  addiu     $v1, $v0, 1
/* 38954C E0084B7C 3042FFFF */  andi      $v0, $v0, 0xffff
/* 389550 E0084B80 00021180 */  sll       $v0, $v0, 6
/* 389554 E0084B84 3C018007 */  lui       $at, %hi(gMatrixListPos)
/* 389558 E0084B88 A42341F0 */  sh        $v1, %lo(gMatrixListPos)($at)
/* 38955C E0084B8C 3C03800A */  lui       $v1, %hi(gDisplayContext)
/* 389560 E0084B90 8C63A674 */  lw        $v1, %lo(gDisplayContext)($v1)
/* 389564 E0084B94 00571021 */  addu      $v0, $v0, $s7
/* 389568 E0084B98 00621821 */  addu      $v1, $v1, $v0
/* 38956C E0084B9C 3C02DE00 */  lui       $v0, 0xde00
/* 389570 E0084BA0 ACA30004 */  sw        $v1, 4($a1)
/* 389574 E0084BA4 AC820000 */  sw        $v0, ($a0)
/* 389578 E0084BA8 8FC30000 */  lw        $v1, ($fp)
/* 38957C E0084BAC 24820008 */  addiu     $v0, $a0, 8
/* 389580 E0084BB0 AEA20000 */  sw        $v0, ($s5)
/* 389584 E0084BB4 24020040 */  addiu     $v0, $zero, 0x40
/* 389588 E0084BB8 AC860008 */  sw        $a2, 8($a0)
/* 38958C E0084BBC AC82000C */  sw        $v0, 0xc($a0)
/* 389590 E0084BC0 AC830004 */  sw        $v1, 4($a0)
/* 389594 E0084BC4 8FAA00A8 */  lw        $t2, 0xa8($sp)
/* 389598 E0084BC8 26100050 */  addiu     $s0, $s0, 0x50
/* 38959C E0084BCC 8D420008 */  lw        $v0, 8($t2)
/* 3895A0 E0084BD0 24840010 */  addiu     $a0, $a0, 0x10
/* 3895A4 E0084BD4 0242102A */  slt       $v0, $s2, $v0
/* 3895A8 E0084BD8 1440FFBB */  bnez      $v0, .LE0084AC8
/* 3895AC E0084BDC AEA40000 */   sw       $a0, ($s5)
.LE0084BE0:
/* 3895B0 E0084BE0 3C08800A */  lui       $t0, %hi(gMasterGfxPos)
/* 3895B4 E0084BE4 2508A66C */  addiu     $t0, $t0, %lo(gMasterGfxPos)
/* 3895B8 E0084BE8 8D030000 */  lw        $v1, ($t0)
/* 3895BC E0084BEC 3C02DE00 */  lui       $v0, 0xde00
/* 3895C0 E0084BF0 0060202D */  daddu     $a0, $v1, $zero
/* 3895C4 E0084BF4 AC820000 */  sw        $v0, ($a0)
/* 3895C8 E0084BF8 8FAA0064 */  lw        $t2, 0x64($sp)
/* 3895CC E0084BFC AC8A0004 */  sw        $t2, 4($a0)
/* 3895D0 E0084C00 8FAA00A8 */  lw        $t2, 0xa8($sp)
/* 3895D4 E0084C04 24120001 */  addiu     $s2, $zero, 1
/* 3895D8 E0084C08 8D51000C */  lw        $s1, 0xc($t2)
/* 3895DC E0084C0C 24630008 */  addiu     $v1, $v1, 8
/* 3895E0 E0084C10 AD030000 */  sw        $v1, ($t0)
/* 3895E4 E0084C14 8D420008 */  lw        $v0, 8($t2)
/* 3895E8 E0084C18 0242102A */  slt       $v0, $s2, $v0
/* 3895EC E0084C1C 10400062 */  beqz      $v0, .LE0084DA8
/* 3895F0 E0084C20 26310050 */   addiu    $s1, $s1, 0x50
/* 3895F4 E0084C24 0100982D */  daddu     $s3, $t0, $zero
/* 3895F8 E0084C28 4480A000 */  mtc1      $zero, $f20
/* 3895FC E0084C2C 3C17800B */  lui       $s7, %hi(gCameras)
/* 389600 E0084C30 26F71D80 */  addiu     $s7, $s7, %lo(gCameras)
/* 389604 E0084C34 3C16800A */  lui       $s6, %hi(gDisplayContext)
/* 389608 E0084C38 26D6A674 */  addiu     $s6, $s6, %lo(gDisplayContext)
/* 38960C E0084C3C 3C158007 */  lui       $s5, %hi(gMatrixListPos)
/* 389610 E0084C40 26B541F0 */  addiu     $s5, $s5, %lo(gMatrixListPos)
/* 389614 E0084C44 3C140001 */  lui       $s4, 1
/* 389618 E0084C48 36941630 */  ori       $s4, $s4, 0x1630
/* 38961C E0084C4C 26300010 */  addiu     $s0, $s1, 0x10
.LE0084C50:
/* 389620 E0084C50 8E680000 */  lw        $t0, ($s3)
/* 389624 E0084C54 3C02FA00 */  lui       $v0, 0xfa00
/* 389628 E0084C58 0100482D */  daddu     $t1, $t0, $zero
/* 38962C E0084C5C AD220000 */  sw        $v0, ($t1)
/* 389630 E0084C60 8E03003C */  lw        $v1, 0x3c($s0)
/* 389634 E0084C64 8FAA0068 */  lw        $t2, 0x68($sp)
/* 389638 E0084C68 006A0018 */  mult      $v1, $t2
/* 38963C E0084C6C 00001812 */  mflo      $v1
/* 389640 E0084C70 3C028080 */  lui       $v0, 0x8080
/* 389644 E0084C74 34428081 */  ori       $v0, $v0, 0x8081
/* 389648 E0084C78 00620018 */  mult      $v1, $v0
/* 38964C E0084C7C 4405A000 */  mfc1      $a1, $f20
/* 389650 E0084C80 4407A000 */  mfc1      $a3, $f20
/* 389654 E0084C84 3C068007 */  lui       $a2, %hi(gCurrentCameraID)
/* 389658 E0084C88 8CC67410 */  lw        $a2, %lo(gCurrentCameraID)($a2)
/* 38965C E0084C8C 00001010 */  mfhi      $v0
/* 389660 E0084C90 00431021 */  addu      $v0, $v0, $v1
/* 389664 E0084C94 000211C3 */  sra       $v0, $v0, 7
/* 389668 E0084C98 00031FC3 */  sra       $v1, $v1, 0x1f
/* 38966C E0084C9C 00431023 */  subu      $v0, $v0, $v1
/* 389670 E0084CA0 2403FF00 */  addiu     $v1, $zero, -0x100
/* 389674 E0084CA4 00431025 */  or        $v0, $v0, $v1
/* 389678 E0084CA8 AD220004 */  sw        $v0, 4($t1)
/* 38967C E0084CAC 00061080 */  sll       $v0, $a2, 2
/* 389680 E0084CB0 00461021 */  addu      $v0, $v0, $a2
/* 389684 E0084CB4 00021080 */  sll       $v0, $v0, 2
/* 389688 E0084CB8 00461023 */  subu      $v0, $v0, $a2
/* 38968C E0084CBC 000218C0 */  sll       $v1, $v0, 3
/* 389690 E0084CC0 00431021 */  addu      $v0, $v0, $v1
/* 389694 E0084CC4 000210C0 */  sll       $v0, $v0, 3
/* 389698 E0084CC8 00571021 */  addu      $v0, $v0, $s7
/* 38969C E0084CCC C442006C */  lwc1      $f2, 0x6c($v0)
/* 3896A0 E0084CD0 E7B60010 */  swc1      $f22, 0x10($sp)
/* 3896A4 E0084CD4 C600FFF8 */  lwc1      $f0, -8($s0)
/* 3896A8 E0084CD8 25080008 */  addiu     $t0, $t0, 8
/* 3896AC E0084CDC AE680000 */  sw        $t0, ($s3)
/* 3896B0 E0084CE0 46001087 */  neg.s     $f2, $f2
/* 3896B4 E0084CE4 E7A00014 */  swc1      $f0, 0x14($sp)
/* 3896B8 E0084CE8 C600FFFC */  lwc1      $f0, -4($s0)
/* 3896BC E0084CEC 44061000 */  mfc1      $a2, $f2
/* 3896C0 E0084CF0 27A40020 */  addiu     $a0, $sp, 0x20
/* 3896C4 E0084CF4 E7A00018 */  swc1      $f0, 0x18($sp)
/* 3896C8 E0084CF8 C6000000 */  lwc1      $f0, ($s0)
/* 3896CC E0084CFC 26520001 */  addiu     $s2, $s2, 1
/* 3896D0 E0084D00 0C080180 */  jal       func_E0200600
/* 3896D4 E0084D04 E7A0001C */   swc1     $f0, 0x1c($sp)
/* 3896D8 E0084D08 27A40020 */  addiu     $a0, $sp, 0x20
/* 3896DC E0084D0C 96A50000 */  lhu       $a1, ($s5)
/* 3896E0 E0084D10 8EC20000 */  lw        $v0, ($s6)
/* 3896E4 E0084D14 00052980 */  sll       $a1, $a1, 6
/* 3896E8 E0084D18 00B42821 */  addu      $a1, $a1, $s4
/* 3896EC E0084D1C 0C080118 */  jal       func_E0200460
/* 3896F0 E0084D20 00452821 */   addu     $a1, $v0, $a1
/* 3896F4 E0084D24 3C06D838 */  lui       $a2, 0xd838
/* 3896F8 E0084D28 8E640000 */  lw        $a0, ($s3)
/* 3896FC E0084D2C 34C60002 */  ori       $a2, $a2, 2
/* 389700 E0084D30 0080282D */  daddu     $a1, $a0, $zero
/* 389704 E0084D34 24840008 */  addiu     $a0, $a0, 8
/* 389708 E0084D38 AE640000 */  sw        $a0, ($s3)
/* 38970C E0084D3C 96A20000 */  lhu       $v0, ($s5)
/* 389710 E0084D40 3C03DA38 */  lui       $v1, 0xda38
/* 389714 E0084D44 ACA30000 */  sw        $v1, ($a1)
/* 389718 E0084D48 24430001 */  addiu     $v1, $v0, 1
/* 38971C E0084D4C 3042FFFF */  andi      $v0, $v0, 0xffff
/* 389720 E0084D50 00021180 */  sll       $v0, $v0, 6
/* 389724 E0084D54 A6A30000 */  sh        $v1, ($s5)
/* 389728 E0084D58 8EC30000 */  lw        $v1, ($s6)
/* 38972C E0084D5C 00541021 */  addu      $v0, $v0, $s4
/* 389730 E0084D60 00621821 */  addu      $v1, $v1, $v0
/* 389734 E0084D64 24820008 */  addiu     $v0, $a0, 8
/* 389738 E0084D68 ACA30004 */  sw        $v1, 4($a1)
/* 38973C E0084D6C AE620000 */  sw        $v0, ($s3)
/* 389740 E0084D70 3C02DE00 */  lui       $v0, 0xde00
/* 389744 E0084D74 AC820000 */  sw        $v0, ($a0)
/* 389748 E0084D78 8FAA0060 */  lw        $t2, 0x60($sp)
/* 38974C E0084D7C 24020040 */  addiu     $v0, $zero, 0x40
/* 389750 E0084D80 AC860008 */  sw        $a2, 8($a0)
/* 389754 E0084D84 AC82000C */  sw        $v0, 0xc($a0)
/* 389758 E0084D88 AC8A0004 */  sw        $t2, 4($a0)
/* 38975C E0084D8C 8FAA00A8 */  lw        $t2, 0xa8($sp)
/* 389760 E0084D90 26100050 */  addiu     $s0, $s0, 0x50
/* 389764 E0084D94 8D420008 */  lw        $v0, 8($t2)
/* 389768 E0084D98 24840010 */  addiu     $a0, $a0, 0x10
/* 38976C E0084D9C 0242102A */  slt       $v0, $s2, $v0
/* 389770 E0084DA0 1440FFAB */  bnez      $v0, .LE0084C50
/* 389774 E0084DA4 AE640000 */   sw       $a0, ($s3)
.LE0084DA8:
/* 389778 E0084DA8 3C05D838 */  lui       $a1, 0xd838
/* 38977C E0084DAC 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* 389780 E0084DB0 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* 389784 E0084DB4 8C620000 */  lw        $v0, ($v1)
/* 389788 E0084DB8 34A50002 */  ori       $a1, $a1, 2
/* 38978C E0084DBC 0040202D */  daddu     $a0, $v0, $zero
/* 389790 E0084DC0 24420008 */  addiu     $v0, $v0, 8
/* 389794 E0084DC4 AC620000 */  sw        $v0, ($v1)
/* 389798 E0084DC8 24020040 */  addiu     $v0, $zero, 0x40
/* 38979C E0084DCC AC850000 */  sw        $a1, ($a0)
/* 3897A0 E0084DD0 AC820004 */  sw        $v0, 4($a0)
/* 3897A4 E0084DD4 8FBF0094 */  lw        $ra, 0x94($sp)
/* 3897A8 E0084DD8 8FBE0090 */  lw        $fp, 0x90($sp)
/* 3897AC E0084DDC 8FB7008C */  lw        $s7, 0x8c($sp)
/* 3897B0 E0084DE0 8FB60088 */  lw        $s6, 0x88($sp)
/* 3897B4 E0084DE4 8FB50084 */  lw        $s5, 0x84($sp)
/* 3897B8 E0084DE8 8FB40080 */  lw        $s4, 0x80($sp)
/* 3897BC E0084DEC 8FB3007C */  lw        $s3, 0x7c($sp)
/* 3897C0 E0084DF0 8FB20078 */  lw        $s2, 0x78($sp)
/* 3897C4 E0084DF4 8FB10074 */  lw        $s1, 0x74($sp)
/* 3897C8 E0084DF8 8FB00070 */  lw        $s0, 0x70($sp)
/* 3897CC E0084DFC D7B600A0 */  ldc1      $f22, 0xa0($sp)
/* 3897D0 E0084E00 D7B40098 */  ldc1      $f20, 0x98($sp)
/* 3897D4 E0084E04 03E00008 */  jr        $ra
/* 3897D8 E0084E08 27BD00A8 */   addiu    $sp, $sp, 0xa8
/* 3897DC E0084E0C 00000000 */  nop
