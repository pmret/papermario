.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003E0C0
/* 194C0 8003E0C0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 194C4 8003E0C4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 194C8 8003E0C8 24050017 */  addiu     $a1, $zero, 0x17
/* 194CC 8003E0CC 3C07800B */  lui       $a3, %hi(D_800B0EF0)
/* 194D0 8003E0D0 24E70EF0 */  addiu     $a3, $a3, %lo(D_800B0EF0)
/* 194D4 8003E0D4 24E2005C */  addiu     $v0, $a3, 0x5c
.L8003E0D8:
/* 194D8 8003E0D8 AC400028 */  sw        $zero, 0x28($v0)
/* 194DC 8003E0DC 24A5FFFF */  addiu     $a1, $a1, -1
/* 194E0 8003E0E0 04A1FFFD */  bgez      $a1, .L8003E0D8
/* 194E4 8003E0E4 2442FFFC */   addiu    $v0, $v0, -4
/* 194E8 8003E0E8 3C028007 */  lui       $v0, %hi(D_8007417C)
/* 194EC 8003E0EC 8C42417C */  lw        $v0, %lo(D_8007417C)($v0)
/* 194F0 8003E0F0 8442008A */  lh        $v0, 0x8a($v0)
/* 194F4 8003E0F4 10400019 */  beqz      $v0, .L8003E15C
/* 194F8 8003E0F8 0000282D */   daddu    $a1, $zero, $zero
/* 194FC 8003E0FC 00A0302D */  daddu     $a2, $a1, $zero
.L8003E100:
/* 19500 8003E100 0000202D */  daddu     $a0, $zero, $zero
/* 19504 8003E104 00C0182D */  daddu     $v1, $a2, $zero
.L8003E108:
/* 19508 8003E108 00E31021 */  addu      $v0, $a3, $v1
/* 1950C 8003E10C AC4000B0 */  sw        $zero, 0xb0($v0)
/* 19510 8003E110 24840001 */  addiu     $a0, $a0, 1
/* 19514 8003E114 2882000C */  slti      $v0, $a0, 0xc
/* 19518 8003E118 1440FFFB */  bnez      $v0, .L8003E108
/* 1951C 8003E11C 24630004 */   addiu    $v1, $v1, 4
/* 19520 8003E120 24A50001 */  addiu     $a1, $a1, 1
/* 19524 8003E124 28A2003C */  slti      $v0, $a1, 0x3c
/* 19528 8003E128 1440FFF5 */  bnez      $v0, .L8003E100
/* 1952C 8003E12C 24C60030 */   addiu    $a2, $a2, 0x30
/* 19530 8003E130 3C028007 */  lui       $v0, %hi(D_8007417C)
/* 19534 8003E134 8C42417C */  lw        $v0, %lo(D_8007417C)($v0)
/* 19538 8003E138 8442008A */  lh        $v0, 0x8a($v0)
/* 1953C 8003E13C 10400007 */  beqz      $v0, .L8003E15C
/* 19540 8003E140 2403FFFF */   addiu    $v1, $zero, -1
/* 19544 8003E144 24050001 */  addiu     $a1, $zero, 1
/* 19548 8003E148 24E20002 */  addiu     $v0, $a3, 2
.L8003E14C:
/* 1954C 8003E14C A4430BF0 */  sh        $v1, 0xbf0($v0)
/* 19550 8003E150 24A5FFFF */  addiu     $a1, $a1, -1
/* 19554 8003E154 04A1FFFD */  bgez      $a1, .L8003E14C
/* 19558 8003E158 2442FFFE */   addiu    $v0, $v0, -2
.L8003E15C:
/* 1955C 8003E15C 3C048007 */  lui       $a0, %hi(D_8007417C)
/* 19560 8003E160 2484417C */  addiu     $a0, $a0, %lo(D_8007417C)
/* 19564 8003E164 8C820000 */  lw        $v0, ($a0)
/* 19568 8003E168 A0E0001C */  sb        $zero, 0x1c($a3)
/* 1956C 8003E16C A0E00004 */  sb        $zero, 4($a3)
/* 19570 8003E170 A0E00005 */  sb        $zero, 5($a3)
/* 19574 8003E174 A0E0000A */  sb        $zero, 0xa($a3)
/* 19578 8003E178 8C830000 */  lw        $v1, ($a0)
/* 1957C 8003E17C 90420087 */  lbu       $v0, 0x87($v0)
/* 19580 8003E180 A0E2001D */  sb        $v0, 0x1d($a3)
/* 19584 8003E184 9062008D */  lbu       $v0, 0x8d($v1)
/* 19588 8003E188 8C830000 */  lw        $v1, ($a0)
/* 1958C 8003E18C A0E2001E */  sb        $v0, 0x1e($a3)
/* 19590 8003E190 9062008F */  lbu       $v0, 0x8f($v1)
/* 19594 8003E194 ACE00024 */  sw        $zero, 0x24($a3)
/* 19598 8003E198 A0E00008 */  sb        $zero, 8($a3)
/* 1959C 8003E19C A0E00012 */  sb        $zero, 0x12($a3)
/* 195A0 8003E1A0 0C0115E0 */  jal       func_80045780
/* 195A4 8003E1A4 A0E2001F */   sb       $v0, 0x1f($a3)
/* 195A8 8003E1A8 3C058004 */  lui       $a1, %hi(func_8003E330)
/* 195AC 8003E1AC 24A5E330 */  addiu     $a1, $a1, %lo(func_8003E330)
/* 195B0 8003E1B0 3C01800A */  lui       $at, %hi(D_8009A5E0)
/* 195B4 8003E1B4 AC20A5E0 */  sw        $zero, %lo(D_8009A5E0)($at)
/* 195B8 8003E1B8 0C04A0DA */  jal       func_80128368
/* 195BC 8003E1BC 0000202D */   daddu    $a0, $zero, $zero
/* 195C0 8003E1C0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 195C4 8003E1C4 03E00008 */  jr        $ra
/* 195C8 8003E1C8 27BD0018 */   addiu    $sp, $sp, 0x18
