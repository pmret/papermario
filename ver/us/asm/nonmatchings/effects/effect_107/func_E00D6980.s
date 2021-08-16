.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00D6980
/* 3D59A0 E00D6980 27BDFF08 */  addiu     $sp, $sp, -0xf8
/* 3D59A4 E00D6984 3C08DB06 */  lui       $t0, 0xdb06
/* 3D59A8 E00D6988 AFB200B8 */  sw        $s2, 0xb8($sp)
/* 3D59AC E00D698C 3C12800A */  lui       $s2, %hi(gMasterGfxPos)
/* 3D59B0 E00D6990 2652A66C */  addiu     $s2, $s2, %lo(gMasterGfxPos)
/* 3D59B4 E00D6994 AFBF00D4 */  sw        $ra, 0xd4($sp)
/* 3D59B8 E00D6998 AFBE00D0 */  sw        $fp, 0xd0($sp)
/* 3D59BC E00D699C AFB700CC */  sw        $s7, 0xcc($sp)
/* 3D59C0 E00D69A0 AFB600C8 */  sw        $s6, 0xc8($sp)
/* 3D59C4 E00D69A4 AFB500C4 */  sw        $s5, 0xc4($sp)
/* 3D59C8 E00D69A8 AFB400C0 */  sw        $s4, 0xc0($sp)
/* 3D59CC E00D69AC AFB300BC */  sw        $s3, 0xbc($sp)
/* 3D59D0 E00D69B0 AFB100B4 */  sw        $s1, 0xb4($sp)
/* 3D59D4 E00D69B4 AFB000B0 */  sw        $s0, 0xb0($sp)
/* 3D59D8 E00D69B8 F7BA00F0 */  sdc1      $f26, 0xf0($sp)
/* 3D59DC E00D69BC F7B800E8 */  sdc1      $f24, 0xe8($sp)
/* 3D59E0 E00D69C0 F7B600E0 */  sdc1      $f22, 0xe0($sp)
/* 3D59E4 E00D69C4 F7B400D8 */  sdc1      $f20, 0xd8($sp)
/* 3D59E8 E00D69C8 AFA400F8 */  sw        $a0, 0xf8($sp)
/* 3D59EC E00D69CC 8E460000 */  lw        $a2, ($s2)
/* 3D59F0 E00D69D0 8FA900F8 */  lw        $t1, 0xf8($sp)
/* 3D59F4 E00D69D4 4480A000 */  mtc1      $zero, $f20
/* 3D59F8 E00D69D8 8D31000C */  lw        $s1, 0xc($t1)
/* 3D59FC E00D69DC 4405A000 */  mfc1      $a1, $f20
/* 3D5A00 E00D69E0 4407A000 */  mfc1      $a3, $f20
/* 3D5A04 E00D69E4 8E290024 */  lw        $t1, 0x24($s1)
/* 3D5A08 E00D69E8 35080024 */  ori       $t0, $t0, 0x24
/* 3D5A0C E00D69EC AFA900A0 */  sw        $t1, 0xa0($sp)
/* 3D5A10 E00D69F0 8E290000 */  lw        $t1, ($s1)
/* 3D5A14 E00D69F4 3C02E700 */  lui       $v0, 0xe700
/* 3D5A18 E00D69F8 AFA900A4 */  sw        $t1, 0xa4($sp)
/* 3D5A1C E00D69FC C6200034 */  lwc1      $f0, 0x34($s1)
/* 3D5A20 E00D6A00 C6220044 */  lwc1      $f2, 0x44($s1)
/* 3D5A24 E00D6A04 8E360018 */  lw        $s6, 0x18($s1)
/* 3D5A28 E00D6A08 8E3E001C */  lw        $fp, 0x1c($s1)
/* 3D5A2C E00D6A0C 8E290020 */  lw        $t1, 0x20($s1)
/* 3D5A30 E00D6A10 00C0182D */  daddu     $v1, $a2, $zero
/* 3D5A34 E00D6A14 AFA900A8 */  sw        $t1, 0xa8($sp)
/* 3D5A38 E00D6A18 C63A0038 */  lwc1      $f26, 0x38($s1)
/* 3D5A3C E00D6A1C 24C60008 */  addiu     $a2, $a2, 8
/* 3D5A40 E00D6A20 AC620000 */  sw        $v0, ($v1)
/* 3D5A44 E00D6A24 AC600004 */  sw        $zero, 4($v1)
/* 3D5A48 E00D6A28 ACC80000 */  sw        $t0, ($a2)
/* 3D5A4C E00D6A2C 8FA900F8 */  lw        $t1, 0xf8($sp)
/* 3D5A50 E00D6A30 3C088000 */  lui       $t0, 0x8000
/* 3D5A54 E00D6A34 8D220010 */  lw        $v0, 0x10($t1)
/* 3D5A58 E00D6A38 46020002 */  mul.s     $f0, $f0, $f2
/* 3D5A5C E00D6A3C 00000000 */  nop
/* 3D5A60 E00D6A40 8C42001C */  lw        $v0, 0x1c($v0)
/* 3D5A64 E00D6A44 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 3D5A68 E00D6A48 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 3D5A6C E00D6A4C 00481021 */  addu      $v0, $v0, $t0
/* 3D5A70 E00D6A50 ACC20004 */  sw        $v0, 4($a2)
/* 3D5A74 E00D6A54 00031080 */  sll       $v0, $v1, 2
/* 3D5A78 E00D6A58 00431021 */  addu      $v0, $v0, $v1
/* 3D5A7C E00D6A5C 00021080 */  sll       $v0, $v0, 2
/* 3D5A80 E00D6A60 00431023 */  subu      $v0, $v0, $v1
/* 3D5A84 E00D6A64 000218C0 */  sll       $v1, $v0, 3
/* 3D5A88 E00D6A68 00431021 */  addu      $v0, $v0, $v1
/* 3D5A8C E00D6A6C 000210C0 */  sll       $v0, $v0, 3
/* 3D5A90 E00D6A70 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* 3D5A94 E00D6A74 00220821 */  addu      $at, $at, $v0
/* 3D5A98 E00D6A78 C4221DEC */  lwc1      $f2, %lo(gCameras+0x6C)($at)
/* 3D5A9C E00D6A7C 27A40020 */  addiu     $a0, $sp, 0x20
/* 3D5AA0 E00D6A80 E7A00010 */  swc1      $f0, 0x10($sp)
/* 3D5AA4 E00D6A84 C6200004 */  lwc1      $f0, 4($s1)
/* 3D5AA8 E00D6A88 3C100001 */  lui       $s0, 1
/* 3D5AAC E00D6A8C AE460000 */  sw        $a2, ($s2)
/* 3D5AB0 E00D6A90 24C60008 */  addiu     $a2, $a2, 8
/* 3D5AB4 E00D6A94 E7A00014 */  swc1      $f0, 0x14($sp)
/* 3D5AB8 E00D6A98 C6200008 */  lwc1      $f0, 8($s1)
/* 3D5ABC E00D6A9C 46001087 */  neg.s     $f2, $f2
/* 3D5AC0 E00D6AA0 AE460000 */  sw        $a2, ($s2)
/* 3D5AC4 E00D6AA4 44061000 */  mfc1      $a2, $f2
/* 3D5AC8 E00D6AA8 36101630 */  ori       $s0, $s0, 0x1630
/* 3D5ACC E00D6AAC E7A00018 */  swc1      $f0, 0x18($sp)
/* 3D5AD0 E00D6AB0 C620000C */  lwc1      $f0, 0xc($s1)
/* 3D5AD4 E00D6AB4 24140001 */  addiu     $s4, $zero, 1
/* 3D5AD8 E00D6AB8 0C080180 */  jal       func_E0200600
/* 3D5ADC E00D6ABC E7A0001C */   swc1     $f0, 0x1c($sp)
/* 3D5AE0 E00D6AC0 27A40020 */  addiu     $a0, $sp, 0x20
/* 3D5AE4 E00D6AC4 3C158007 */  lui       $s5, %hi(gMatrixListPos)
/* 3D5AE8 E00D6AC8 26B541F0 */  addiu     $s5, $s5, %lo(gMatrixListPos)
/* 3D5AEC E00D6ACC 3C17800A */  lui       $s7, %hi(gDisplayContext)
/* 3D5AF0 E00D6AD0 26F7A674 */  addiu     $s7, $s7, %lo(gDisplayContext)
/* 3D5AF4 E00D6AD4 96A50000 */  lhu       $a1, ($s5)
/* 3D5AF8 E00D6AD8 8EE20000 */  lw        $v0, ($s7)
/* 3D5AFC E00D6ADC 00052980 */  sll       $a1, $a1, 6
/* 3D5B00 E00D6AE0 00B02821 */  addu      $a1, $a1, $s0
/* 3D5B04 E00D6AE4 0C080118 */  jal       func_E0200460
/* 3D5B08 E00D6AE8 00452821 */   addu     $a1, $v0, $a1
/* 3D5B0C E00D6AEC 3C03DA38 */  lui       $v1, 0xda38
/* 3D5B10 E00D6AF0 34630002 */  ori       $v1, $v1, 2
/* 3D5B14 E00D6AF4 8E440000 */  lw        $a0, ($s2)
/* 3D5B18 E00D6AF8 96A20000 */  lhu       $v0, ($s5)
/* 3D5B1C E00D6AFC 0080282D */  daddu     $a1, $a0, $zero
/* 3D5B20 E00D6B00 24840008 */  addiu     $a0, $a0, 8
/* 3D5B24 E00D6B04 AE440000 */  sw        $a0, ($s2)
/* 3D5B28 E00D6B08 ACA30000 */  sw        $v1, ($a1)
/* 3D5B2C E00D6B0C 00541821 */  addu      $v1, $v0, $s4
/* 3D5B30 E00D6B10 3042FFFF */  andi      $v0, $v0, 0xffff
/* 3D5B34 E00D6B14 00021180 */  sll       $v0, $v0, 6
/* 3D5B38 E00D6B18 A6A30000 */  sh        $v1, ($s5)
/* 3D5B3C E00D6B1C 8EE30000 */  lw        $v1, ($s7)
/* 3D5B40 E00D6B20 00501021 */  addu      $v0, $v0, $s0
/* 3D5B44 E00D6B24 00621821 */  addu      $v1, $v1, $v0
/* 3D5B48 E00D6B28 24820008 */  addiu     $v0, $a0, 8
/* 3D5B4C E00D6B2C ACA30004 */  sw        $v1, 4($a1)
/* 3D5B50 E00D6B30 AE420000 */  sw        $v0, ($s2)
/* 3D5B54 E00D6B34 3C02FA00 */  lui       $v0, 0xfa00
/* 3D5B58 E00D6B38 AC820000 */  sw        $v0, ($a0)
/* 3D5B5C E00D6B3C 9222001B */  lbu       $v0, 0x1b($s1)
/* 3D5B60 E00D6B40 9225001F */  lbu       $a1, 0x1f($s1)
/* 3D5B64 E00D6B44 92260023 */  lbu       $a2, 0x23($s1)
/* 3D5B68 E00D6B48 24830010 */  addiu     $v1, $a0, 0x10
/* 3D5B6C E00D6B4C AE430000 */  sw        $v1, ($s2)
/* 3D5B70 E00D6B50 3C03FB00 */  lui       $v1, 0xfb00
/* 3D5B74 E00D6B54 AC830008 */  sw        $v1, 8($a0)
/* 3D5B78 E00D6B58 8FA900A0 */  lw        $t1, 0xa0($sp)
/* 3D5B7C E00D6B5C 00021600 */  sll       $v0, $v0, 0x18
/* 3D5B80 E00D6B60 00052C00 */  sll       $a1, $a1, 0x10
/* 3D5B84 E00D6B64 00451025 */  or        $v0, $v0, $a1
/* 3D5B88 E00D6B68 00063200 */  sll       $a2, $a2, 8
/* 3D5B8C E00D6B6C 00461025 */  or        $v0, $v0, $a2
/* 3D5B90 E00D6B70 312300FF */  andi      $v1, $t1, 0xff
/* 3D5B94 E00D6B74 00431025 */  or        $v0, $v0, $v1
/* 3D5B98 E00D6B78 AC820004 */  sw        $v0, 4($a0)
/* 3D5B9C E00D6B7C 9223002B */  lbu       $v1, 0x2b($s1)
/* 3D5BA0 E00D6B80 9225002F */  lbu       $a1, 0x2f($s1)
/* 3D5BA4 E00D6B84 92260033 */  lbu       $a2, 0x33($s1)
/* 3D5BA8 E00D6B88 3C02DE00 */  lui       $v0, 0xde00
/* 3D5BAC E00D6B8C AC820010 */  sw        $v0, 0x10($a0)
/* 3D5BB0 E00D6B90 3C020900 */  lui       $v0, 0x900
/* 3D5BB4 E00D6B94 24420200 */  addiu     $v0, $v0, 0x200
/* 3D5BB8 E00D6B98 AC820014 */  sw        $v0, 0x14($a0)
/* 3D5BBC E00D6B9C 00031E00 */  sll       $v1, $v1, 0x18
/* 3D5BC0 E00D6BA0 00052C00 */  sll       $a1, $a1, 0x10
/* 3D5BC4 E00D6BA4 00651825 */  or        $v1, $v1, $a1
/* 3D5BC8 E00D6BA8 00063200 */  sll       $a2, $a2, 8
/* 3D5BCC E00D6BAC 00661825 */  or        $v1, $v1, $a2
/* 3D5BD0 E00D6BB0 AC83000C */  sw        $v1, 0xc($a0)
/* 3D5BD4 E00D6BB4 8FA900F8 */  lw        $t1, 0xf8($sp)
/* 3D5BD8 E00D6BB8 26310048 */  addiu     $s1, $s1, 0x48
/* 3D5BDC E00D6BBC 8D220008 */  lw        $v0, 8($t1)
/* 3D5BE0 E00D6BC0 24840018 */  addiu     $a0, $a0, 0x18
/* 3D5BE4 E00D6BC4 0282102A */  slt       $v0, $s4, $v0
/* 3D5BE8 E00D6BC8 10400080 */  beqz      $v0, .LE00D6DCC
/* 3D5BEC E00D6BCC AE440000 */   sw       $a0, ($s2)
/* 3D5BF0 E00D6BD0 0240982D */  daddu     $s3, $s2, $zero
/* 3D5BF4 E00D6BD4 00161E00 */  sll       $v1, $s6, 0x18
/* 3D5BF8 E00D6BD8 33C200FF */  andi      $v0, $fp, 0xff
/* 3D5BFC E00D6BDC 00021400 */  sll       $v0, $v0, 0x10
/* 3D5C00 E00D6BE0 00621825 */  or        $v1, $v1, $v0
/* 3D5C04 E00D6BE4 4600A606 */  mov.s     $f24, $f20
/* 3D5C08 E00D6BE8 27B20060 */  addiu     $s2, $sp, 0x60
/* 3D5C0C E00D6BEC 02E0F02D */  daddu     $fp, $s7, $zero
/* 3D5C10 E00D6BF0 02A0B82D */  daddu     $s7, $s5, $zero
/* 3D5C14 E00D6BF4 3C150001 */  lui       $s5, 1
/* 3D5C18 E00D6BF8 36B51630 */  ori       $s5, $s5, 0x1630
/* 3D5C1C E00D6BFC 26300004 */  addiu     $s0, $s1, 4
/* 3D5C20 E00D6C00 8FA900A8 */  lw        $t1, 0xa8($sp)
/* 3D5C24 E00D6C04 3C013F80 */  lui       $at, 0x3f80
/* 3D5C28 E00D6C08 4481B000 */  mtc1      $at, $f22
/* 3D5C2C E00D6C0C 312200FF */  andi      $v0, $t1, 0xff
/* 3D5C30 E00D6C10 00021200 */  sll       $v0, $v0, 8
/* 3D5C34 E00D6C14 8FA900A4 */  lw        $t1, 0xa4($sp)
/* 3D5C38 E00D6C18 00621825 */  or        $v1, $v1, $v0
/* 3D5C3C E00D6C1C AFA300AC */  sw        $v1, 0xac($sp)
/* 3D5C40 E00D6C20 3C03E00D */  lui       $v1, %hi(D_E00D6E40)
/* 3D5C44 E00D6C24 24636E40 */  addiu     $v1, $v1, %lo(D_E00D6E40)
/* 3D5C48 E00D6C28 00091080 */  sll       $v0, $t1, 2
/* 3D5C4C E00D6C2C 0043B021 */  addu      $s6, $v0, $v1
.LE00D6C30:
/* 3D5C50 E00D6C30 3C02FA00 */  lui       $v0, 0xfa00
/* 3D5C54 E00D6C34 8E680000 */  lw        $t0, ($s3)
/* 3D5C58 E00D6C38 C6140030 */  lwc1      $f20, 0x30($s0)
/* 3D5C5C E00D6C3C 0100282D */  daddu     $a1, $t0, $zero
/* 3D5C60 E00D6C40 ACA20000 */  sw        $v0, ($a1)
/* 3D5C64 E00D6C44 8E030020 */  lw        $v1, 0x20($s0)
/* 3D5C68 E00D6C48 8FA900A0 */  lw        $t1, 0xa0($sp)
/* 3D5C6C E00D6C4C 01230018 */  mult      $t1, $v1
/* 3D5C70 E00D6C50 00001812 */  mflo      $v1
/* 3D5C74 E00D6C54 3C028080 */  lui       $v0, 0x8080
/* 3D5C78 E00D6C58 34428081 */  ori       $v0, $v0, 0x8081
/* 3D5C7C E00D6C5C 00620018 */  mult      $v1, $v0
/* 3D5C80 E00D6C60 27A40020 */  addiu     $a0, $sp, 0x20
/* 3D5C84 E00D6C64 4406C000 */  mfc1      $a2, $f24
/* 3D5C88 E00D6C68 4407C000 */  mfc1      $a3, $f24
/* 3D5C8C E00D6C6C 8FA900AC */  lw        $t1, 0xac($sp)
/* 3D5C90 E00D6C70 00001010 */  mfhi      $v0
/* 3D5C94 E00D6C74 00431021 */  addu      $v0, $v0, $v1
/* 3D5C98 E00D6C78 000211C3 */  sra       $v0, $v0, 7
/* 3D5C9C E00D6C7C 00031FC3 */  sra       $v1, $v1, 0x1f
/* 3D5CA0 E00D6C80 00431023 */  subu      $v0, $v0, $v1
/* 3D5CA4 E00D6C84 304200FF */  andi      $v0, $v0, 0xff
/* 3D5CA8 E00D6C88 01221025 */  or        $v0, $t1, $v0
/* 3D5CAC E00D6C8C ACA20004 */  sw        $v0, 4($a1)
/* 3D5CB0 E00D6C90 E7B60010 */  swc1      $f22, 0x10($sp)
/* 3D5CB4 E00D6C94 8E050038 */  lw        $a1, 0x38($s0)
/* 3D5CB8 E00D6C98 25080008 */  addiu     $t0, $t0, 8
/* 3D5CBC E00D6C9C 0C080104 */  jal       func_E0200410
/* 3D5CC0 E00D6CA0 AE680000 */   sw       $t0, ($s3)
/* 3D5CC4 E00D6CA4 C6000000 */  lwc1      $f0, ($s0)
/* 3D5CC8 E00D6CA8 461A0000 */  add.s     $f0, $f0, $f26
/* 3D5CCC E00D6CAC 4406C000 */  mfc1      $a2, $f24
/* 3D5CD0 E00D6CB0 4407C000 */  mfc1      $a3, $f24
/* 3D5CD4 E00D6CB4 44050000 */  mfc1      $a1, $f0
/* 3D5CD8 E00D6CB8 0C080108 */  jal       func_E0200420
/* 3D5CDC E00D6CBC 0240202D */   daddu    $a0, $s2, $zero
/* 3D5CE0 E00D6CC0 0240202D */  daddu     $a0, $s2, $zero
/* 3D5CE4 E00D6CC4 27A50020 */  addiu     $a1, $sp, 0x20
/* 3D5CE8 E00D6CC8 0C080114 */  jal       func_E0200450
/* 3D5CEC E00D6CCC 00A0302D */   daddu    $a2, $a1, $zero
/* 3D5CF0 E00D6CD0 8EC30000 */  lw        $v1, ($s6)
/* 3D5CF4 E00D6CD4 3C020900 */  lui       $v0, 0x900
/* 3D5CF8 E00D6CD8 24420688 */  addiu     $v0, $v0, 0x688
/* 3D5CFC E00D6CDC 10620005 */  beq       $v1, $v0, .LE00D6CF4
/* 3D5D00 E00D6CE0 00000000 */   nop
/* 3D5D04 E00D6CE4 3C020900 */  lui       $v0, 0x900
/* 3D5D08 E00D6CE8 24420808 */  addiu     $v0, $v0, 0x808
/* 3D5D0C E00D6CEC 14620006 */  bne       $v1, $v0, .LE00D6D08
/* 3D5D10 E00D6CF0 0240202D */   daddu    $a0, $s2, $zero
.LE00D6CF4:
/* 3D5D14 E00D6CF4 4405A000 */  mfc1      $a1, $f20
/* 3D5D18 E00D6CF8 4406B000 */  mfc1      $a2, $f22
/* 3D5D1C E00D6CFC 4407B000 */  mfc1      $a3, $f22
/* 3D5D20 E00D6D00 08035B45 */  j         .LE00D6D14
/* 3D5D24 E00D6D04 0240202D */   daddu    $a0, $s2, $zero
.LE00D6D08:
/* 3D5D28 E00D6D08 4405A000 */  mfc1      $a1, $f20
/* 3D5D2C E00D6D0C 4407B000 */  mfc1      $a3, $f22
/* 3D5D30 E00D6D10 00A0302D */  daddu     $a2, $a1, $zero
.LE00D6D14:
/* 3D5D34 E00D6D14 0C080110 */  jal       func_E0200440
/* 3D5D38 E00D6D18 26940001 */   addiu    $s4, $s4, 1
/* 3D5D3C E00D6D1C 27A40060 */  addiu     $a0, $sp, 0x60
/* 3D5D40 E00D6D20 27A50020 */  addiu     $a1, $sp, 0x20
/* 3D5D44 E00D6D24 0C080114 */  jal       func_E0200450
/* 3D5D48 E00D6D28 00A0302D */   daddu    $a2, $a1, $zero
/* 3D5D4C E00D6D2C 27A40020 */  addiu     $a0, $sp, 0x20
/* 3D5D50 E00D6D30 96E50000 */  lhu       $a1, ($s7)
/* 3D5D54 E00D6D34 8FC20000 */  lw        $v0, ($fp)
/* 3D5D58 E00D6D38 00052980 */  sll       $a1, $a1, 6
/* 3D5D5C E00D6D3C 00B52821 */  addu      $a1, $a1, $s5
/* 3D5D60 E00D6D40 0C080118 */  jal       func_E0200460
/* 3D5D64 E00D6D44 00452821 */   addu     $a1, $v0, $a1
/* 3D5D68 E00D6D48 3C06D838 */  lui       $a2, 0xd838
/* 3D5D6C E00D6D4C 8E640000 */  lw        $a0, ($s3)
/* 3D5D70 E00D6D50 34C60002 */  ori       $a2, $a2, 2
/* 3D5D74 E00D6D54 0080282D */  daddu     $a1, $a0, $zero
/* 3D5D78 E00D6D58 24840008 */  addiu     $a0, $a0, 8
/* 3D5D7C E00D6D5C AE640000 */  sw        $a0, ($s3)
/* 3D5D80 E00D6D60 96E20000 */  lhu       $v0, ($s7)
/* 3D5D84 E00D6D64 3C03DA38 */  lui       $v1, 0xda38
/* 3D5D88 E00D6D68 ACA30000 */  sw        $v1, ($a1)
/* 3D5D8C E00D6D6C 24430001 */  addiu     $v1, $v0, 1
/* 3D5D90 E00D6D70 3042FFFF */  andi      $v0, $v0, 0xffff
/* 3D5D94 E00D6D74 00021180 */  sll       $v0, $v0, 6
/* 3D5D98 E00D6D78 A6E30000 */  sh        $v1, ($s7)
/* 3D5D9C E00D6D7C 8FC30000 */  lw        $v1, ($fp)
/* 3D5DA0 E00D6D80 00551021 */  addu      $v0, $v0, $s5
/* 3D5DA4 E00D6D84 00621821 */  addu      $v1, $v1, $v0
/* 3D5DA8 E00D6D88 3C02DE00 */  lui       $v0, 0xde00
/* 3D5DAC E00D6D8C ACA30004 */  sw        $v1, 4($a1)
/* 3D5DB0 E00D6D90 AC820000 */  sw        $v0, ($a0)
/* 3D5DB4 E00D6D94 8EC30000 */  lw        $v1, ($s6)
/* 3D5DB8 E00D6D98 24820008 */  addiu     $v0, $a0, 8
/* 3D5DBC E00D6D9C AE620000 */  sw        $v0, ($s3)
/* 3D5DC0 E00D6DA0 24020040 */  addiu     $v0, $zero, 0x40
/* 3D5DC4 E00D6DA4 AC860008 */  sw        $a2, 8($a0)
/* 3D5DC8 E00D6DA8 AC82000C */  sw        $v0, 0xc($a0)
/* 3D5DCC E00D6DAC AC830004 */  sw        $v1, 4($a0)
/* 3D5DD0 E00D6DB0 8FA900F8 */  lw        $t1, 0xf8($sp)
/* 3D5DD4 E00D6DB4 26100048 */  addiu     $s0, $s0, 0x48
/* 3D5DD8 E00D6DB8 8D220008 */  lw        $v0, 8($t1)
/* 3D5DDC E00D6DBC 24840010 */  addiu     $a0, $a0, 0x10
/* 3D5DE0 E00D6DC0 0282102A */  slt       $v0, $s4, $v0
/* 3D5DE4 E00D6DC4 1440FF9A */  bnez      $v0, .LE00D6C30
/* 3D5DE8 E00D6DC8 AE640000 */   sw       $a0, ($s3)
.LE00D6DCC:
/* 3D5DEC E00D6DCC 3C05D838 */  lui       $a1, 0xd838
/* 3D5DF0 E00D6DD0 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* 3D5DF4 E00D6DD4 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* 3D5DF8 E00D6DD8 8C620000 */  lw        $v0, ($v1)
/* 3D5DFC E00D6DDC 34A50002 */  ori       $a1, $a1, 2
/* 3D5E00 E00D6DE0 0040202D */  daddu     $a0, $v0, $zero
/* 3D5E04 E00D6DE4 24420008 */  addiu     $v0, $v0, 8
/* 3D5E08 E00D6DE8 AC620000 */  sw        $v0, ($v1)
/* 3D5E0C E00D6DEC 24020040 */  addiu     $v0, $zero, 0x40
/* 3D5E10 E00D6DF0 AC850000 */  sw        $a1, ($a0)
/* 3D5E14 E00D6DF4 AC820004 */  sw        $v0, 4($a0)
/* 3D5E18 E00D6DF8 8FBF00D4 */  lw        $ra, 0xd4($sp)
/* 3D5E1C E00D6DFC 8FBE00D0 */  lw        $fp, 0xd0($sp)
/* 3D5E20 E00D6E00 8FB700CC */  lw        $s7, 0xcc($sp)
/* 3D5E24 E00D6E04 8FB600C8 */  lw        $s6, 0xc8($sp)
/* 3D5E28 E00D6E08 8FB500C4 */  lw        $s5, 0xc4($sp)
/* 3D5E2C E00D6E0C 8FB400C0 */  lw        $s4, 0xc0($sp)
/* 3D5E30 E00D6E10 8FB300BC */  lw        $s3, 0xbc($sp)
/* 3D5E34 E00D6E14 8FB200B8 */  lw        $s2, 0xb8($sp)
/* 3D5E38 E00D6E18 8FB100B4 */  lw        $s1, 0xb4($sp)
/* 3D5E3C E00D6E1C 8FB000B0 */  lw        $s0, 0xb0($sp)
/* 3D5E40 E00D6E20 D7BA00F0 */  ldc1      $f26, 0xf0($sp)
/* 3D5E44 E00D6E24 D7B800E8 */  ldc1      $f24, 0xe8($sp)
/* 3D5E48 E00D6E28 D7B600E0 */  ldc1      $f22, 0xe0($sp)
/* 3D5E4C E00D6E2C D7B400D8 */  ldc1      $f20, 0xd8($sp)
/* 3D5E50 E00D6E30 03E00008 */  jr        $ra
/* 3D5E54 E00D6E34 27BD00F8 */   addiu    $sp, $sp, 0xf8
/* 3D5E58 E00D6E38 00000000 */  nop
/* 3D5E5C E00D6E3C 00000000 */  nop
