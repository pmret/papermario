.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel get_overriding_player_anim
/* 791F8 800DFD48 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 791FC 800DFD4C AFB00010 */  sw        $s0, 0x10($sp)
/* 79200 800DFD50 0080802D */  daddu     $s0, $a0, $zero
/* 79204 800DFD54 3C058011 */  lui       $a1, %hi(gPlayerStatus)
/* 79208 800DFD58 24A5EFC8 */  addiu     $a1, $a1, %lo(gPlayerStatus)
/* 7920C 800DFD5C 3C048011 */  lui       $a0, %hi(gPartnerActionStatus)
/* 79210 800DFD60 2484EBB0 */  addiu     $a0, $a0, %lo(gPartnerActionStatus)
/* 79214 800DFD64 AFBF0014 */  sw        $ra, 0x14($sp)
/* 79218 800DFD68 80A300B4 */  lb        $v1, 0xb4($a1)
/* 7921C 800DFD6C 2402001D */  addiu     $v0, $zero, 0x1d
/* 79220 800DFD70 14620007 */  bne       $v1, $v0, .L800DFD90
/* 79224 800DFD74 3C020001 */   lui      $v0, 1
/* 79228 800DFD78 3442002B */  ori       $v0, $v0, 0x2b
/* 7922C 800DFD7C 12020004 */  beq       $s0, $v0, .L800DFD90
/* 79230 800DFD80 3C020001 */   lui      $v0, 1
/* 79234 800DFD84 34420007 */  ori       $v0, $v0, 7
/* 79238 800DFD88 16020058 */  bne       $s0, $v0, .L800DFEEC
/* 7923C 800DFD8C 2402FFFF */   addiu    $v0, $zero, -1
.L800DFD90:
/* 79240 800DFD90 80820000 */  lb        $v0, ($a0)
/* 79244 800DFD94 10400017 */  beqz      $v0, .L800DFDF4
/* 79248 800DFD98 24020008 */   addiu    $v0, $zero, 8
/* 7924C 800DFD9C 80830003 */  lb        $v1, 3($a0)
/* 79250 800DFDA0 14620006 */  bne       $v1, $v0, .L800DFDBC
/* 79254 800DFDA4 3C020001 */   lui      $v0, 1
/* 79258 800DFDA8 34420002 */  ori       $v0, $v0, 2
/* 7925C 800DFDAC 16020003 */  bne       $s0, $v0, .L800DFDBC
/* 79260 800DFDB0 00000000 */   nop
/* 79264 800DFDB4 3C100008 */  lui       $s0, 8
/* 79268 800DFDB8 3610000E */  ori       $s0, $s0, 0xe
.L800DFDBC:
/* 7926C 800DFDBC 80820000 */  lb        $v0, ($a0)
/* 79270 800DFDC0 1040000C */  beqz      $v0, .L800DFDF4
/* 79274 800DFDC4 24020009 */   addiu    $v0, $zero, 9
/* 79278 800DFDC8 80830003 */  lb        $v1, 3($a0)
/* 7927C 800DFDCC 1462000A */  bne       $v1, $v0, .L800DFDF8
/* 79280 800DFDD0 3C020001 */   lui      $v0, 1
/* 79284 800DFDD4 34420014 */  ori       $v0, $v0, 0x14
/* 79288 800DFDD8 12020006 */  beq       $s0, $v0, .L800DFDF4
/* 7928C 800DFDDC 3C020001 */   lui      $v0, 1
/* 79290 800DFDE0 34420002 */  ori       $v0, $v0, 2
/* 79294 800DFDE4 12020004 */  beq       $s0, $v0, .L800DFDF8
/* 79298 800DFDE8 3C020001 */   lui      $v0, 1
.L800DFDEC:
/* 7929C 800DFDEC 08037FBB */  j         .L800DFEEC
/* 792A0 800DFDF0 2402FFFF */   addiu    $v0, $zero, -1
.L800DFDF4:
/* 792A4 800DFDF4 3C020001 */  lui       $v0, 1
.L800DFDF8:
/* 792A8 800DFDF8 34420032 */  ori       $v0, $v0, 0x32
/* 792AC 800DFDFC 16020005 */  bne       $s0, $v0, .L800DFE14
/* 792B0 800DFE00 3C020006 */   lui      $v0, 6
/* 792B4 800DFE04 80830000 */  lb        $v1, ($a0)
/* 792B8 800DFE08 24020001 */  addiu     $v0, $zero, 1
/* 792BC 800DFE0C 1062FFF7 */  beq       $v1, $v0, .L800DFDEC
/* 792C0 800DFE10 3C020006 */   lui      $v0, 6
.L800DFE14:
/* 792C4 800DFE14 3442000C */  ori       $v0, $v0, 0xc
/* 792C8 800DFE18 12020007 */  beq       $s0, $v0, .L800DFE38
/* 792CC 800DFE1C 3C02000C */   lui      $v0, 0xc
/* 792D0 800DFE20 34420010 */  ori       $v0, $v0, 0x10
/* 792D4 800DFE24 12020004 */  beq       $s0, $v0, .L800DFE38
/* 792D8 800DFE28 3C020001 */   lui      $v0, 1
/* 792DC 800DFE2C 34420002 */  ori       $v0, $v0, 2
/* 792E0 800DFE30 1602001A */  bne       $s0, $v0, .L800DFE9C
/* 792E4 800DFE34 00000000 */   nop
.L800DFE38:
/* 792E8 800DFE38 8CA30004 */  lw        $v1, 4($a1)
/* 792EC 800DFE3C 30621000 */  andi      $v0, $v1, 0x1000
/* 792F0 800DFE40 14400007 */  bnez      $v0, .L800DFE60
/* 792F4 800DFE44 30622000 */   andi     $v0, $v1, 0x2000
/* 792F8 800DFE48 0C037F3D */  jal       func_800DFCF4
/* 792FC 800DFE4C 00000000 */   nop
/* 79300 800DFE50 1440001E */  bnez      $v0, .L800DFECC
/* 79304 800DFE54 3C020008 */   lui      $v0, 8
/* 79308 800DFE58 08037FBB */  j         .L800DFEEC
/* 7930C 800DFE5C 2402FFFF */   addiu    $v0, $zero, -1
.L800DFE60:
/* 79310 800DFE60 14400003 */  bnez      $v0, .L800DFE70
/* 79314 800DFE64 3C10000C */   lui      $s0, 0xc
/* 79318 800DFE68 08037FB2 */  j         .L800DFEC8
/* 7931C 800DFE6C 36100010 */   ori      $s0, $s0, 0x10
.L800DFE70:
/* 79320 800DFE70 80A3000C */  lb        $v1, 0xc($a1)
/* 79324 800DFE74 00031040 */  sll       $v0, $v1, 1
/* 79328 800DFE78 00431021 */  addu      $v0, $v0, $v1
/* 7932C 800DFE7C 000210C0 */  sll       $v0, $v0, 3
/* 79330 800DFE80 3C04800F */  lui       $a0, %hi(world_actions_peachDisguises+0x14)
/* 79334 800DFE84 00822021 */  addu      $a0, $a0, $v0
/* 79338 800DFE88 8C847C30 */  lw        $a0, %lo(world_actions_peachDisguises+0x14)($a0)
/* 7933C 800DFE8C 0C0398DB */  jal       peach_set_disguise_anim
/* 79340 800DFE90 00000000 */   nop
/* 79344 800DFE94 08037FBB */  j         .L800DFEEC
/* 79348 800DFE98 2402FFFF */   addiu    $v0, $zero, -1
.L800DFE9C:
/* 7934C 800DFE9C 8CA20004 */  lw        $v0, 4($a1)
/* 79350 800DFEA0 30421000 */  andi      $v0, $v0, 0x1000
/* 79354 800DFEA4 10400009 */  beqz      $v0, .L800DFECC
/* 79358 800DFEA8 3C020008 */   lui      $v0, 8
/* 7935C 800DFEAC 80A200C4 */  lb        $v0, 0xc4($a1)
/* 79360 800DFEB0 10400005 */  beqz      $v0, .L800DFEC8
/* 79364 800DFEB4 3C02FFF4 */   lui      $v0, 0xfff4
/* 79368 800DFEB8 02021021 */  addu      $v0, $s0, $v0
/* 7936C 800DFEBC 2C420003 */  sltiu     $v0, $v0, 3
/* 79370 800DFEC0 54400001 */  bnel      $v0, $zero, .L800DFEC8
/* 79374 800DFEC4 3C10000D */   lui      $s0, 0xd
.L800DFEC8:
/* 79378 800DFEC8 3C020008 */  lui       $v0, 8
.L800DFECC:
/* 7937C 800DFECC 34420003 */  ori       $v0, $v0, 3
/* 79380 800DFED0 16020006 */  bne       $s0, $v0, .L800DFEEC
/* 79384 800DFED4 0200102D */   daddu    $v0, $s0, $zero
/* 79388 800DFED8 0000202D */  daddu     $a0, $zero, $zero
/* 7938C 800DFEDC 0080282D */  daddu     $a1, $a0, $zero
/* 79390 800DFEE0 0C0B2D5B */  jal       exec_ShakeCam1
/* 79394 800DFEE4 24060002 */   addiu    $a2, $zero, 2
/* 79398 800DFEE8 0200102D */  daddu     $v0, $s0, $zero
.L800DFEEC:
/* 7939C 800DFEEC 8FBF0014 */  lw        $ra, 0x14($sp)
/* 793A0 800DFEF0 8FB00010 */  lw        $s0, 0x10($sp)
/* 793A4 800DFEF4 03E00008 */  jr        $ra
/* 793A8 800DFEF8 27BD0018 */   addiu    $sp, $sp, 0x18
