.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_8010C148
.word L800EBD18_851C8, L800EC148_855F8, L800EC45C_8590C, L800ED2E4_86794, L800ED2E4_86794, L800EC6FC_85BAC, L800ED2E4_86794, L800ED2E4_86794, L800ED2E4_86794, L800ED2E4_86794, L800ED2E4_86794, L800ED2E4_86794, L800ED2E4_86794, L800ED2E4_86794, L800ED2E4_86794, L800ECCC0_86170, L800ED2E4_86794, L800ED2E4_86794, L800ED2E4_86794, L800ED2E4_86794, L800ED0B0_86560, L800ED2E4_86794, L800ED2E4_86794, L800ED2E4_86794, L800ED2E4_86794, L800ED2E4_86794, L800ED2E4_86794, L800ED2E4_86794, L800ED2E4_86794, L800ED2E4_86794, L800ED2E4_86794, L800ED2E4_86794, L800ED2E4_86794, L800ED2E4_86794, L800ED2E4_86794, L800ED2E4_86794, L800ED2E4_86794, L800ED2E4_86794, L800ED2E4_86794, L800ED2E4_86794, L800ED0C4_86574, L800ED2E4_86794, L800ED2E4_86794, L800ED2E4_86794, L800ED2E4_86794, L800ED2E4_86794, L800ED2E4_86794, L800ED2E4_86794, L800ED2E4_86794, L800ED2E4_86794, L800ED2E4_86794, 0

.section .text

glabel partner_walking_follow_player
/* 85124 800EBC74 3C038011 */  lui       $v1, %hi(D_8010CFC8)
/* 85128 800EBC78 8463CFC8 */  lh        $v1, %lo(D_8010CFC8)($v1)
/* 8512C 800EBC7C 27BDFF98 */  addiu     $sp, $sp, -0x68
/* 85130 800EBC80 AFB1003C */  sw        $s1, 0x3c($sp)
/* 85134 800EBC84 AFB30044 */  sw        $s3, 0x44($sp)
/* 85138 800EBC88 3C138011 */  lui       $s3, %hi(gPlayerStatus)
/* 8513C 800EBC8C 2673EFC8 */  addiu     $s3, $s3, %lo(gPlayerStatus)
/* 85140 800EBC90 AFB5004C */  sw        $s5, 0x4c($sp)
/* 85144 800EBC94 3C15800B */  lui       $s5, %hi(gCameras)
/* 85148 800EBC98 26B51D80 */  addiu     $s5, $s5, %lo(gCameras)
/* 8514C 800EBC9C AFBF0050 */  sw        $ra, 0x50($sp)
/* 85150 800EBCA0 AFB40048 */  sw        $s4, 0x48($sp)
/* 85154 800EBCA4 AFB20040 */  sw        $s2, 0x40($sp)
/* 85158 800EBCA8 AFB00038 */  sw        $s0, 0x38($sp)
/* 8515C 800EBCAC F7B60060 */  sdc1      $f22, 0x60($sp)
/* 85160 800EBCB0 F7B40058 */  sdc1      $f20, 0x58($sp)
/* 85164 800EBCB4 2C620033 */  sltiu     $v0, $v1, 0x33
/* 85168 800EBCB8 1040058A */  beqz      $v0, L800ED2E4_86794
/* 8516C 800EBCBC 0080882D */   daddu    $s1, $a0, $zero
/* 85170 800EBCC0 00031080 */  sll       $v0, $v1, 2
/* 85174 800EBCC4 3C018011 */  lui       $at, %hi(jtbl_8010C148)
/* 85178 800EBCC8 00220821 */  addu      $at, $at, $v0
/* 8517C 800EBCCC 8C22C148 */  lw        $v0, %lo(jtbl_8010C148)($at)
/* 85180 800EBCD0 00400008 */  jr        $v0
/* 85184 800EBCD4 00000000 */   nop
.L800EBCD8:
/* 85188 800EBCD8 C634000C */  lwc1      $f20, 0xc($s1)
/* 8518C 800EBCDC 3C038011 */  lui       $v1, %hi(D_8010CFD8)
/* 85190 800EBCE0 8C63CFD8 */  lw        $v1, %lo(D_8010CFD8)($v1)
/* 85194 800EBCE4 AE200018 */  sw        $zero, 0x18($s1)
/* 85198 800EBCE8 AE200014 */  sw        $zero, 0x14($s1)
/* 8519C 800EBCEC 000310C0 */  sll       $v0, $v1, 3
/* 851A0 800EBCF0 00431021 */  addu      $v0, $v0, $v1
/* 851A4 800EBCF4 00021080 */  sll       $v0, $v0, 2
/* 851A8 800EBCF8 3C038010 */  lui       $v1, %hi(gPartnerAnimations+0x14)
/* 851AC 800EBCFC 00621821 */  addu      $v1, $v1, $v0
/* 851B0 800EBD00 8C63835C */  lw        $v1, %lo(gPartnerAnimations+0x14)($v1)
/* 851B4 800EBD04 24020005 */  addiu     $v0, $zero, 5
/* 851B8 800EBD08 3C018011 */  lui       $at, %hi(D_8010CFC8)
/* 851BC 800EBD0C A422CFC8 */  sh        $v0, %lo(D_8010CFC8)($at)
/* 851C0 800EBD10 0803B005 */  j         .L800EC014
/* 851C4 800EBD14 AE230028 */   sw       $v1, 0x28($s1)
glabel L800EBD18_851C8
/* 851C8 800EBD18 3C038011 */  lui       $v1, %hi(D_8010CD38)
/* 851CC 800EBD1C 2463CD38 */  addiu     $v1, $v1, %lo(D_8010CD38)
/* 851D0 800EBD20 C62C0038 */  lwc1      $f12, 0x38($s1)
/* 851D4 800EBD24 C62E0040 */  lwc1      $f14, 0x40($s1)
/* 851D8 800EBD28 3C028011 */  lui       $v0, %hi(D_8010CFBC)
/* 851DC 800EBD2C 8C42CFBC */  lw        $v0, %lo(D_8010CFBC)($v0)
/* 851E0 800EBD30 3C014040 */  lui       $at, 0x4040
/* 851E4 800EBD34 44810000 */  mtc1      $at, $f0
/* 851E8 800EBD38 C622003C */  lwc1      $f2, 0x3c($s1)
/* 851EC 800EBD3C 00021100 */  sll       $v0, $v0, 4
/* 851F0 800EBD40 00438021 */  addu      $s0, $v0, $v1
/* 851F4 800EBD44 C6060004 */  lwc1      $f6, 4($s0)
/* 851F8 800EBD48 C608000C */  lwc1      $f8, 0xc($s0)
/* 851FC 800EBD4C E6200018 */  swc1      $f0, 0x18($s1)
/* 85200 800EBD50 46006006 */  mov.s     $f0, $f12
/* 85204 800EBD54 8E660028 */  lw        $a2, 0x28($s3)
/* 85208 800EBD58 8E670030 */  lw        $a3, 0x30($s3)
/* 8520C 800EBD5C 46007106 */  mov.s     $f4, $f14
/* 85210 800EBD60 E7A00028 */  swc1      $f0, 0x28($sp)
/* 85214 800EBD64 E7A2002C */  swc1      $f2, 0x2c($sp)
/* 85218 800EBD68 E7A40030 */  swc1      $f4, 0x30($sp)
/* 8521C 800EBD6C E7A60020 */  swc1      $f6, 0x20($sp)
/* 85220 800EBD70 0C00A7B5 */  jal       dist2D
/* 85224 800EBD74 E7A80024 */   swc1     $f8, 0x24($sp)
/* 85228 800EBD78 3C014049 */  lui       $at, 0x4049
/* 8522C 800EBD7C 44811800 */  mtc1      $at, $f3
/* 85230 800EBD80 44801000 */  mtc1      $zero, $f2
/* 85234 800EBD84 E7A00034 */  swc1      $f0, 0x34($sp)
/* 85238 800EBD88 46000021 */  cvt.d.s   $f0, $f0
/* 8523C 800EBD8C 4620103E */  c.le.d    $f2, $f0
/* 85240 800EBD90 00000000 */  nop
/* 85244 800EBD94 4500000B */  bc1f      .L800EBDC4
/* 85248 800EBD98 3C030001 */   lui      $v1, 1
/* 8524C 800EBD9C 8E620004 */  lw        $v0, 4($s3)
/* 85250 800EBDA0 3C0140E0 */  lui       $at, 0x40e0
/* 85254 800EBDA4 44810000 */  mtc1      $at, $f0
/* 85258 800EBDA8 00431024 */  and       $v0, $v0, $v1
/* 8525C 800EBDAC 54400005 */  bnel      $v0, $zero, .L800EBDC4
/* 85260 800EBDB0 E6200018 */   swc1     $f0, 0x18($s1)
/* 85264 800EBDB4 3C0140A0 */  lui       $at, 0x40a0
/* 85268 800EBDB8 44810000 */  mtc1      $at, $f0
/* 8526C 800EBDBC 00000000 */  nop
/* 85270 800EBDC0 E6200018 */  swc1      $f0, 0x18($s1)
.L800EBDC4:
/* 85274 800EBDC4 3C018011 */  lui       $at, %hi(D_8010CFC0)
/* 85278 800EBDC8 C420CFC0 */  lwc1      $f0, %lo(D_8010CFC0)($at)
/* 8527C 800EBDCC 3C014034 */  lui       $at, 0x4034
/* 85280 800EBDD0 44811800 */  mtc1      $at, $f3
/* 85284 800EBDD4 44801000 */  mtc1      $zero, $f2
/* 85288 800EBDD8 46000021 */  cvt.d.s   $f0, $f0
/* 8528C 800EBDDC 4622003C */  c.lt.d    $f0, $f2
/* 85290 800EBDE0 00000000 */  nop
/* 85294 800EBDE4 45000005 */  bc1f      .L800EBDFC
/* 85298 800EBDE8 00000000 */   nop
/* 8529C 800EBDEC 3C014080 */  lui       $at, 0x4080
/* 852A0 800EBDF0 44810000 */  mtc1      $at, $f0
/* 852A4 800EBDF4 00000000 */  nop
/* 852A8 800EBDF8 E6200018 */  swc1      $f0, 0x18($s1)
.L800EBDFC:
/* 852AC 800EBDFC 3C038011 */  lui       $v1, %hi(D_8010CFD8)
/* 852B0 800EBE00 8C63CFD8 */  lw        $v1, %lo(D_8010CFD8)($v1)
/* 852B4 800EBE04 3C048010 */  lui       $a0, %hi(gPartnerAnimations)
/* 852B8 800EBE08 24848348 */  addiu     $a0, $a0, %lo(gPartnerAnimations)
/* 852BC 800EBE0C 000310C0 */  sll       $v0, $v1, 3
/* 852C0 800EBE10 00431021 */  addu      $v0, $v0, $v1
/* 852C4 800EBE14 00021080 */  sll       $v0, $v0, 2
/* 852C8 800EBE18 00442021 */  addu      $a0, $v0, $a0
/* 852CC 800EBE1C 8E220000 */  lw        $v0, ($s1)
/* 852D0 800EBE20 8C830018 */  lw        $v1, 0x18($a0)
/* 852D4 800EBE24 30421000 */  andi      $v0, $v0, 0x1000
/* 852D8 800EBE28 14400003 */  bnez      $v0, .L800EBE38
/* 852DC 800EBE2C AE230028 */   sw       $v1, 0x28($s1)
/* 852E0 800EBE30 8C82000C */  lw        $v0, 0xc($a0)
/* 852E4 800EBE34 AE220028 */  sw        $v0, 0x28($s1)
.L800EBE38:
/* 852E8 800EBE38 3C128011 */  lui       $s2, %hi(D_8010CFBC)
/* 852EC 800EBE3C 2652CFBC */  addiu     $s2, $s2, %lo(D_8010CFBC)
/* 852F0 800EBE40 3C148011 */  lui       $s4, %hi(D_8010CD38)
/* 852F4 800EBE44 2694CD38 */  addiu     $s4, $s4, %lo(D_8010CD38)
.L800EBE48:
/* 852F8 800EBE48 C7AC0028 */  lwc1      $f12, 0x28($sp)
/* 852FC 800EBE4C C7AE0030 */  lwc1      $f14, 0x30($sp)
/* 85300 800EBE50 8FA60020 */  lw        $a2, 0x20($sp)
/* 85304 800EBE54 0C00A7B5 */  jal       dist2D
/* 85308 800EBE58 8FA70024 */   lw       $a3, 0x24($sp)
/* 8530C 800EBE5C C7AC0028 */  lwc1      $f12, 0x28($sp)
/* 85310 800EBE60 C7AE0030 */  lwc1      $f14, 0x30($sp)
/* 85314 800EBE64 8FA60020 */  lw        $a2, 0x20($sp)
/* 85318 800EBE68 8FA70024 */  lw        $a3, 0x24($sp)
/* 8531C 800EBE6C 0C00A720 */  jal       atan2
/* 85320 800EBE70 E7A00034 */   swc1     $f0, 0x34($sp)
/* 85324 800EBE74 C6240018 */  lwc1      $f4, 0x18($s1)
/* 85328 800EBE78 C7A20034 */  lwc1      $f2, 0x34($sp)
/* 8532C 800EBE7C 4602203C */  c.lt.s    $f4, $f2
/* 85330 800EBE80 00000000 */  nop
/* 85334 800EBE84 4500003B */  bc1f      .L800EBF74
/* 85338 800EBE88 46000506 */   mov.s    $f20, $f0
/* 8533C 800EBE8C C7AC0028 */  lwc1      $f12, 0x28($sp)
/* 85340 800EBE90 C7AE0030 */  lwc1      $f14, 0x30($sp)
/* 85344 800EBE94 8E660028 */  lw        $a2, 0x28($s3)
/* 85348 800EBE98 0C00A7B5 */  jal       dist2D
/* 8534C 800EBE9C 8E670030 */   lw       $a3, 0x30($s3)
/* 85350 800EBEA0 3C014049 */  lui       $at, 0x4049
/* 85354 800EBEA4 44811800 */  mtc1      $at, $f3
/* 85358 800EBEA8 44801000 */  mtc1      $zero, $f2
/* 8535C 800EBEAC 46000106 */  mov.s     $f4, $f0
/* 85360 800EBEB0 E7A00034 */  swc1      $f0, 0x34($sp)
/* 85364 800EBEB4 46002021 */  cvt.d.s   $f0, $f4
/* 85368 800EBEB8 4620103E */  c.le.d    $f2, $f0
/* 8536C 800EBEBC 00000000 */  nop
/* 85370 800EBEC0 45010054 */  bc1t      .L800EC014
/* 85374 800EBEC4 00000000 */   nop
/* 85378 800EBEC8 3C018011 */  lui       $at, %hi(D_8010CFC0)
/* 8537C 800EBECC C426CFC0 */  lwc1      $f6, %lo(D_8010CFC0)($at)
/* 85380 800EBED0 4604303C */  c.lt.s    $f6, $f4
/* 85384 800EBED4 00000000 */  nop
/* 85388 800EBED8 4500001F */  bc1f      .L800EBF58
/* 8538C 800EBEDC 00000000 */   nop
/* 85390 800EBEE0 46062081 */  sub.s     $f2, $f4, $f6
/* 85394 800EBEE4 3C014008 */  lui       $at, 0x4008
/* 85398 800EBEE8 44810800 */  mtc1      $at, $f1
/* 8539C 800EBEEC 44800000 */  mtc1      $zero, $f0
/* 853A0 800EBEF0 E6220018 */  swc1      $f2, 0x18($s1)
/* 853A4 800EBEF4 460010A1 */  cvt.d.s   $f2, $f2
/* 853A8 800EBEF8 4622003C */  c.lt.d    $f0, $f2
/* 853AC 800EBEFC 00000000 */  nop
/* 853B0 800EBF00 4500000D */  bc1f      .L800EBF38
/* 853B4 800EBF04 00000000 */   nop
/* 853B8 800EBF08 3C0141A0 */  lui       $at, 0x41a0
/* 853BC 800EBF0C 44810000 */  mtc1      $at, $f0
/* 853C0 800EBF10 3C014040 */  lui       $at, 0x4040
/* 853C4 800EBF14 44811000 */  mtc1      $at, $f2
/* 853C8 800EBF18 4600303C */  c.lt.s    $f6, $f0
/* 853CC 800EBF1C 00000000 */  nop
/* 853D0 800EBF20 4500003C */  bc1f      .L800EC014
/* 853D4 800EBF24 E6220018 */   swc1     $f2, 0x18($s1)
/* 853D8 800EBF28 3C014080 */  lui       $at, 0x4080
/* 853DC 800EBF2C 44810000 */  mtc1      $at, $f0
/* 853E0 800EBF30 0803B005 */  j         .L800EC014
/* 853E4 800EBF34 E6200018 */   swc1     $f0, 0x18($s1)
.L800EBF38:
/* 853E8 800EBF38 3C013FF0 */  lui       $at, 0x3ff0
/* 853EC 800EBF3C 44810800 */  mtc1      $at, $f1
/* 853F0 800EBF40 44800000 */  mtc1      $zero, $f0
/* 853F4 800EBF44 00000000 */  nop
/* 853F8 800EBF48 46201000 */  add.d     $f0, $f2, $f0
/* 853FC 800EBF4C 46200020 */  cvt.s.d   $f0, $f0
/* 85400 800EBF50 0803B005 */  j         .L800EC014
/* 85404 800EBF54 E6200018 */   swc1     $f0, 0x18($s1)
.L800EBF58:
/* 85408 800EBF58 C62C0038 */  lwc1      $f12, 0x38($s1)
/* 8540C 800EBF5C C62E0040 */  lwc1      $f14, 0x40($s1)
/* 85410 800EBF60 AE200018 */  sw        $zero, 0x18($s1)
/* 85414 800EBF64 8E660028 */  lw        $a2, 0x28($s3)
/* 85418 800EBF68 0C00A720 */  jal       atan2
/* 8541C 800EBF6C 8E670030 */   lw       $a3, 0x30($s3)
/* 85420 800EBF70 E620000C */  swc1      $f0, 0xc($s1)
.L800EBF74:
/* 85424 800EBF74 8E430000 */  lw        $v1, ($s2)
/* 85428 800EBF78 3C028011 */  lui       $v0, %hi(D_8010CFB8)
/* 8542C 800EBF7C 8C42CFB8 */  lw        $v0, %lo(D_8010CFB8)($v0)
/* 85430 800EBF80 1062FF55 */  beq       $v1, $v0, .L800EBCD8
/* 85434 800EBF84 24620001 */   addiu    $v0, $v1, 1
/* 85438 800EBF88 AE420000 */  sw        $v0, ($s2)
/* 8543C 800EBF8C 28420028 */  slti      $v0, $v0, 0x28
/* 85440 800EBF90 50400001 */  beql      $v0, $zero, .L800EBF98
/* 85444 800EBF94 AE400000 */   sw       $zero, ($s2)
.L800EBF98:
/* 85448 800EBF98 C62C0038 */  lwc1      $f12, 0x38($s1)
/* 8544C 800EBF9C 8E420000 */  lw        $v0, ($s2)
/* 85450 800EBFA0 C62E0040 */  lwc1      $f14, 0x40($s1)
/* 85454 800EBFA4 00021100 */  sll       $v0, $v0, 4
/* 85458 800EBFA8 00548021 */  addu      $s0, $v0, $s4
/* 8545C 800EBFAC C6000004 */  lwc1      $f0, 4($s0)
/* 85460 800EBFB0 C602000C */  lwc1      $f2, 0xc($s0)
/* 85464 800EBFB4 44060000 */  mfc1      $a2, $f0
/* 85468 800EBFB8 44071000 */  mfc1      $a3, $f2
/* 8546C 800EBFBC AFA60020 */  sw        $a2, 0x20($sp)
/* 85470 800EBFC0 0C00A720 */  jal       atan2
/* 85474 800EBFC4 AFA70024 */   sw       $a3, 0x24($sp)
/* 85478 800EBFC8 C62C000C */  lwc1      $f12, 0xc($s1)
/* 8547C 800EBFCC 0C00A70A */  jal       get_clamped_angle_diff
/* 85480 800EBFD0 46000386 */   mov.s    $f14, $f0
/* 85484 800EBFD4 3C0142B4 */  lui       $at, 0x42b4
/* 85488 800EBFD8 44811000 */  mtc1      $at, $f2
/* 8548C 800EBFDC 46000005 */  abs.s     $f0, $f0
/* 85490 800EBFE0 4600103C */  c.lt.s    $f2, $f0
/* 85494 800EBFE4 00000000 */  nop
/* 85498 800EBFE8 45010008 */  bc1t      .L800EC00C
/* 8549C 800EBFEC 24020005 */   addiu    $v0, $zero, 5
/* 854A0 800EBFF0 8E220000 */  lw        $v0, ($s1)
/* 854A4 800EBFF4 30421000 */  andi      $v0, $v0, 0x1000
/* 854A8 800EBFF8 1040FF93 */  beqz      $v0, .L800EBE48
/* 854AC 800EBFFC 00000000 */   nop
/* 854B0 800EC000 82020000 */  lb        $v0, ($s0)
/* 854B4 800EC004 1040FF90 */  beqz      $v0, .L800EBE48
/* 854B8 800EC008 24020001 */   addiu    $v0, $zero, 1
.L800EC00C:
/* 854BC 800EC00C 3C018011 */  lui       $at, %hi(D_8010CFC8)
/* 854C0 800EC010 A422CFC8 */  sh        $v0, %lo(D_8010CFC8)($at)
.L800EC014:
/* 854C4 800EC014 8E220000 */  lw        $v0, ($s1)
/* 854C8 800EC018 30421000 */  andi      $v0, $v0, 0x1000
/* 854CC 800EC01C 14400008 */  bnez      $v0, .L800EC040
/* 854D0 800EC020 00000000 */   nop
/* 854D4 800EC024 C6200018 */  lwc1      $f0, 0x18($s1)
/* 854D8 800EC028 3C013F00 */  lui       $at, 0x3f00
/* 854DC 800EC02C 44811000 */  mtc1      $at, $f2
/* 854E0 800EC030 00000000 */  nop
/* 854E4 800EC034 46020002 */  mul.s     $f0, $f0, $f2
/* 854E8 800EC038 00000000 */  nop
/* 854EC 800EC03C E6200018 */  swc1      $f0, 0x18($s1)
.L800EC040:
/* 854F0 800EC040 8E250018 */  lw        $a1, 0x18($s1)
/* 854F4 800EC044 4406A000 */  mfc1      $a2, $f20
/* 854F8 800EC048 0220202D */  daddu     $a0, $s1, $zero
/* 854FC 800EC04C 0C00EA95 */  jal       npc_move_heading
/* 85500 800EC050 AE26000C */   sw       $a2, 0xc($s1)
/* 85504 800EC054 C6200018 */  lwc1      $f0, 0x18($s1)
/* 85508 800EC058 3C014010 */  lui       $at, 0x4010
/* 8550C 800EC05C 44811800 */  mtc1      $at, $f3
/* 85510 800EC060 44801000 */  mtc1      $zero, $f2
/* 85514 800EC064 46000021 */  cvt.d.s   $f0, $f0
/* 85518 800EC068 4622003C */  c.lt.d    $f0, $f2
/* 8551C 800EC06C 00000000 */  nop
/* 85520 800EC070 45000002 */  bc1f      .L800EC07C
/* 85524 800EC074 24050001 */   addiu    $a1, $zero, 1
/* 85528 800EC078 0000282D */  daddu     $a1, $zero, $zero
.L800EC07C:
/* 8552C 800EC07C 0C00F598 */  jal       func_8003D660
/* 85530 800EC080 0220202D */   daddu    $a0, $s1, $zero
/* 85534 800EC084 86240084 */  lh        $a0, 0x84($s1)
/* 85538 800EC088 0C016F6A */  jal       get_collider_type_by_id
/* 8553C 800EC08C 00000000 */   nop
/* 85540 800EC090 2442FFFE */  addiu     $v0, $v0, -2
/* 85544 800EC094 2C420002 */  sltiu     $v0, $v0, 2
/* 85548 800EC098 14400005 */  bnez      $v0, .L800EC0B0
/* 8554C 800EC09C 24035000 */   addiu    $v1, $zero, 0x5000
/* 85550 800EC0A0 8E220000 */  lw        $v0, ($s1)
/* 85554 800EC0A4 30425000 */  andi      $v0, $v0, 0x5000
/* 85558 800EC0A8 1443048E */  bne       $v0, $v1, L800ED2E4_86794
/* 8555C 800EC0AC 00000000 */   nop
.L800EC0B0:
/* 85560 800EC0B0 0C03A92C */  jal       func_800EA4B0
/* 85564 800EC0B4 86240086 */   lh       $a0, 0x86($s1)
/* 85568 800EC0B8 14400488 */  bnez      $v0, .L800ED2DC
/* 8556C 800EC0BC 24020001 */   addiu    $v0, $zero, 1
/* 85570 800EC0C0 3C038011 */  lui       $v1, %hi(D_8010CFBC)
/* 85574 800EC0C4 2463CFBC */  addiu     $v1, $v1, %lo(D_8010CFBC)
/* 85578 800EC0C8 8C620000 */  lw        $v0, ($v1)
/* 8557C 800EC0CC 24420001 */  addiu     $v0, $v0, 1
/* 85580 800EC0D0 AC620000 */  sw        $v0, ($v1)
/* 85584 800EC0D4 28420028 */  slti      $v0, $v0, 0x28
/* 85588 800EC0D8 50400001 */  beql      $v0, $zero, .L800EC0E0
/* 8558C 800EC0DC AC600000 */   sw       $zero, ($v1)
.L800EC0E0:
/* 85590 800EC0E0 8C620000 */  lw        $v0, ($v1)
/* 85594 800EC0E4 3C038011 */  lui       $v1, %hi(D_8010CD38)
/* 85598 800EC0E8 2463CD38 */  addiu     $v1, $v1, %lo(D_8010CD38)
/* 8559C 800EC0EC C62C0038 */  lwc1      $f12, 0x38($s1)
/* 855A0 800EC0F0 C62E0040 */  lwc1      $f14, 0x40($s1)
/* 855A4 800EC0F4 00021100 */  sll       $v0, $v0, 4
/* 855A8 800EC0F8 00438021 */  addu      $s0, $v0, $v1
/* 855AC 800EC0FC C6000004 */  lwc1      $f0, 4($s0)
/* 855B0 800EC100 C602000C */  lwc1      $f2, 0xc($s0)
/* 855B4 800EC104 44060000 */  mfc1      $a2, $f0
/* 855B8 800EC108 44071000 */  mfc1      $a3, $f2
/* 855BC 800EC10C AFA60020 */  sw        $a2, 0x20($sp)
/* 855C0 800EC110 0C00A720 */  jal       atan2
/* 855C4 800EC114 AFA70024 */   sw       $a3, 0x24($sp)
/* 855C8 800EC118 C62C000C */  lwc1      $f12, 0xc($s1)
/* 855CC 800EC11C 0C00A70A */  jal       get_clamped_angle_diff
/* 855D0 800EC120 46000386 */   mov.s    $f14, $f0
/* 855D4 800EC124 3C0142B4 */  lui       $at, 0x42b4
/* 855D8 800EC128 44811000 */  mtc1      $at, $f2
/* 855DC 800EC12C 46000005 */  abs.s     $f0, $f0
/* 855E0 800EC130 4600103C */  c.lt.s    $f2, $f0
/* 855E4 800EC134 00000000 */  nop
/* 855E8 800EC138 4500046A */  bc1f      L800ED2E4_86794
/* 855EC 800EC13C 24020005 */   addiu    $v0, $zero, 5
/* 855F0 800EC140 0803B4B7 */  j         .L800ED2DC
/* 855F4 800EC144 00000000 */   nop
glabel L800EC148_855F8
/* 855F8 800EC148 0C016F6A */  jal       get_collider_type_by_id
/* 855FC 800EC14C 86240084 */   lh       $a0, 0x84($s1)
/* 85600 800EC150 3C058011 */  lui       $a1, %hi(D_8010CFBC)
/* 85604 800EC154 24A5CFBC */  addiu     $a1, $a1, %lo(D_8010CFBC)
/* 85608 800EC158 8CA40000 */  lw        $a0, ($a1)
/* 8560C 800EC15C 3C038011 */  lui       $v1, %hi(D_8010CFB8)
/* 85610 800EC160 8C63CFB8 */  lw        $v1, %lo(D_8010CFB8)($v1)
/* 85614 800EC164 14830016 */  bne       $a0, $v1, .L800EC1C0
/* 85618 800EC168 0040902D */   daddu    $s2, $v0, $zero
/* 8561C 800EC16C 2642FFFE */  addiu     $v0, $s2, -2
/* 85620 800EC170 2C420002 */  sltiu     $v0, $v0, 2
/* 85624 800EC174 1040045B */  beqz      $v0, L800ED2E4_86794
/* 85628 800EC178 00000000 */   nop
/* 8562C 800EC17C C674002C */  lwc1      $f20, 0x2c($s3)
/* 85630 800EC180 C62C0038 */  lwc1      $f12, 0x38($s1)
/* 85634 800EC184 C62E0040 */  lwc1      $f14, 0x40($s1)
/* 85638 800EC188 8E660028 */  lw        $a2, 0x28($s3)
/* 8563C 800EC18C 8E670030 */  lw        $a3, 0x30($s3)
/* 85640 800EC190 46006006 */  mov.s     $f0, $f12
/* 85644 800EC194 46007086 */  mov.s     $f2, $f14
/* 85648 800EC198 E7A00020 */  swc1      $f0, 0x20($sp)
/* 8564C 800EC19C 0C00A720 */  jal       atan2
/* 85650 800EC1A0 E7A20024 */   swc1     $f2, 0x24($sp)
/* 85654 800EC1A4 27A40020 */  addiu     $a0, $sp, 0x20
/* 85658 800EC1A8 3C0640C0 */  lui       $a2, 0x40c0
/* 8565C 800EC1AC 44070000 */  mfc1      $a3, $f0
/* 85660 800EC1B0 0C00A7E7 */  jal       add_vec2D_polar
/* 85664 800EC1B4 27A50024 */   addiu    $a1, $sp, 0x24
/* 85668 800EC1B8 0803B07F */  j         .L800EC1FC
/* 8566C 800EC1BC 00000000 */   nop
.L800EC1C0:
/* 85670 800EC1C0 24820001 */  addiu     $v0, $a0, 1
/* 85674 800EC1C4 ACA20000 */  sw        $v0, ($a1)
/* 85678 800EC1C8 28420028 */  slti      $v0, $v0, 0x28
/* 8567C 800EC1CC 50400001 */  beql      $v0, $zero, .L800EC1D4
/* 85680 800EC1D0 ACA00000 */   sw       $zero, ($a1)
.L800EC1D4:
/* 85684 800EC1D4 8CA20000 */  lw        $v0, ($a1)
/* 85688 800EC1D8 3C038011 */  lui       $v1, %hi(D_8010CD38)
/* 8568C 800EC1DC 2463CD38 */  addiu     $v1, $v1, %lo(D_8010CD38)
/* 85690 800EC1E0 00021100 */  sll       $v0, $v0, 4
/* 85694 800EC1E4 00438021 */  addu      $s0, $v0, $v1
/* 85698 800EC1E8 C6000004 */  lwc1      $f0, 4($s0)
/* 8569C 800EC1EC C6140008 */  lwc1      $f20, 8($s0)
/* 856A0 800EC1F0 C602000C */  lwc1      $f2, 0xc($s0)
/* 856A4 800EC1F4 E7A00020 */  swc1      $f0, 0x20($sp)
/* 856A8 800EC1F8 E7A20024 */  swc1      $f2, 0x24($sp)
.L800EC1FC:
/* 856AC 800EC1FC C7A00020 */  lwc1      $f0, 0x20($sp)
/* 856B0 800EC200 C62C0038 */  lwc1      $f12, 0x38($s1)
/* 856B4 800EC204 C62E0040 */  lwc1      $f14, 0x40($s1)
/* 856B8 800EC208 3C0140C0 */  lui       $at, 0x40c0
/* 856BC 800EC20C 44811000 */  mtc1      $at, $f2
/* 856C0 800EC210 E6200060 */  swc1      $f0, 0x60($s1)
/* 856C4 800EC214 44060000 */  mfc1      $a2, $f0
/* 856C8 800EC218 C7A00024 */  lwc1      $f0, 0x24($sp)
/* 856CC 800EC21C E6200068 */  swc1      $f0, 0x68($s1)
/* 856D0 800EC220 44070000 */  mfc1      $a3, $f0
/* 856D4 800EC224 3C014040 */  lui       $at, 0x4040
/* 856D8 800EC228 44810000 */  mtc1      $at, $f0
/* 856DC 800EC22C E6340064 */  swc1      $f20, 0x64($s1)
/* 856E0 800EC230 A620008E */  sh        $zero, 0x8e($s1)
/* 856E4 800EC234 E6220018 */  swc1      $f2, 0x18($s1)
/* 856E8 800EC238 0C00A7B5 */  jal       dist2D
/* 856EC 800EC23C E6200014 */   swc1     $f0, 0x14($s1)
/* 856F0 800EC240 C62C0038 */  lwc1      $f12, 0x38($s1)
/* 856F4 800EC244 C62E0040 */  lwc1      $f14, 0x40($s1)
/* 856F8 800EC248 8E260060 */  lw        $a2, 0x60($s1)
/* 856FC 800EC24C 8E270068 */  lw        $a3, 0x68($s1)
/* 85700 800EC250 0C00A720 */  jal       atan2
/* 85704 800EC254 E6200010 */   swc1     $f0, 0x10($s1)
/* 85708 800EC258 E620000C */  swc1      $f0, 0xc($s1)
/* 8570C 800EC25C C6200010 */  lwc1      $f0, 0x10($s1)
/* 85710 800EC260 3C014049 */  lui       $at, 0x4049
/* 85714 800EC264 44811800 */  mtc1      $at, $f3
/* 85718 800EC268 44801000 */  mtc1      $zero, $f2
/* 8571C 800EC26C 46000021 */  cvt.d.s   $f0, $f0
/* 85720 800EC270 4620103C */  c.lt.d    $f2, $f0
/* 85724 800EC274 00000000 */  nop
/* 85728 800EC278 45000005 */  bc1f      .L800EC290
/* 8572C 800EC27C 00000000 */   nop
/* 85730 800EC280 3C014248 */  lui       $at, 0x4248
/* 85734 800EC284 44810000 */  mtc1      $at, $f0
/* 85738 800EC288 00000000 */  nop
/* 8573C 800EC28C E6200010 */  swc1      $f0, 0x10($s1)
.L800EC290:
/* 85740 800EC290 C6220064 */  lwc1      $f2, 0x64($s1)
/* 85744 800EC294 C620003C */  lwc1      $f0, 0x3c($s1)
/* 85748 800EC298 C6240010 */  lwc1      $f4, 0x10($s1)
/* 8574C 800EC29C 46001081 */  sub.s     $f2, $f2, $f0
/* 85750 800EC2A0 3C018011 */  lui       $at, %hi(D_8010CFC0)
/* 85754 800EC2A4 C420CFC0 */  lwc1      $f0, %lo(D_8010CFC0)($at)
/* 85758 800EC2A8 E7A40034 */  swc1      $f4, 0x34($sp)
/* 8575C 800EC2AC 4600203C */  c.lt.s    $f4, $f0
/* 85760 800EC2B0 00000000 */  nop
/* 85764 800EC2B4 45000010 */  bc1f      .L800EC2F8
/* 85768 800EC2B8 E7A2002C */   swc1     $f2, 0x2c($sp)
/* 8576C 800EC2BC 2642FFFE */  addiu     $v0, $s2, -2
/* 85770 800EC2C0 2C420002 */  sltiu     $v0, $v0, 2
/* 85774 800EC2C4 1440000C */  bnez      $v0, .L800EC2F8
/* 85778 800EC2C8 00000000 */   nop
/* 8577C 800EC2CC C62C0038 */  lwc1      $f12, 0x38($s1)
/* 85780 800EC2D0 C62E0040 */  lwc1      $f14, 0x40($s1)
/* 85784 800EC2D4 AE20001C */  sw        $zero, 0x1c($s1)
/* 85788 800EC2D8 8E660028 */  lw        $a2, 0x28($s3)
/* 8578C 800EC2DC 0C00A720 */  jal       atan2
/* 85790 800EC2E0 8E670030 */   lw       $a3, 0x30($s3)
/* 85794 800EC2E4 E620000C */  swc1      $f0, 0xc($s1)
.L800EC2E8:
/* 85798 800EC2E8 3C018011 */  lui       $at, %hi(D_8010CFC8)
/* 8579C 800EC2EC A420CFC8 */  sh        $zero, %lo(D_8010CFC8)($at)
/* 857A0 800EC2F0 0803B4B9 */  j         L800ED2E4_86794
/* 857A4 800EC2F4 00000000 */   nop
.L800EC2F8:
/* 857A8 800EC2F8 C6220018 */  lwc1      $f2, 0x18($s1)
/* 857AC 800EC2FC C7A00034 */  lwc1      $f0, 0x34($sp)
/* 857B0 800EC300 46020003 */  div.s     $f0, $f0, $f2
/* 857B4 800EC304 4600028D */  trunc.w.s $f10, $f0
/* 857B8 800EC308 44025000 */  mfc1      $v0, $f10
/* 857BC 800EC30C 00000000 */  nop
/* 857C0 800EC310 A622008E */  sh        $v0, 0x8e($s1)
/* 857C4 800EC314 00021400 */  sll       $v0, $v0, 0x10
/* 857C8 800EC318 00021403 */  sra       $v0, $v0, 0x10
/* 857CC 800EC31C 2842000A */  slti      $v0, $v0, 0xa
/* 857D0 800EC320 10400002 */  beqz      $v0, .L800EC32C
/* 857D4 800EC324 2402000A */   addiu    $v0, $zero, 0xa
/* 857D8 800EC328 A622008E */  sh        $v0, 0x8e($s1)
.L800EC32C:
/* 857DC 800EC32C 8622008E */  lh        $v0, 0x8e($s1)
/* 857E0 800EC330 C6220014 */  lwc1      $f2, 0x14($s1)
/* 857E4 800EC334 44823000 */  mtc1      $v0, $f6
/* 857E8 800EC338 00000000 */  nop
/* 857EC 800EC33C 468031A0 */  cvt.s.w   $f6, $f6
/* 857F0 800EC340 46061082 */  mul.s     $f2, $f2, $f6
/* 857F4 800EC344 00000000 */  nop
/* 857F8 800EC348 46061082 */  mul.s     $f2, $f2, $f6
/* 857FC 800EC34C 00000000 */  nop
/* 85800 800EC350 3C013F00 */  lui       $at, 0x3f00
/* 85804 800EC354 44810000 */  mtc1      $at, $f0
/* 85808 800EC358 00000000 */  nop
/* 8580C 800EC35C 46001082 */  mul.s     $f2, $f2, $f0
/* 85810 800EC360 00000000 */  nop
/* 85814 800EC364 C7A4002C */  lwc1      $f4, 0x2c($sp)
/* 85818 800EC368 C6200010 */  lwc1      $f0, 0x10($s1)
/* 8581C 800EC36C 46003206 */  mov.s     $f8, $f6
/* 85820 800EC370 46080003 */  div.s     $f0, $f0, $f8
/* 85824 800EC374 46022100 */  add.s     $f4, $f4, $f2
/* 85828 800EC378 E6200018 */  swc1      $f0, 0x18($s1)
/* 8582C 800EC37C 3C014034 */  lui       $at, 0x4034
/* 85830 800EC380 44811800 */  mtc1      $at, $f3
/* 85834 800EC384 44801000 */  mtc1      $zero, $f2
/* 85838 800EC388 46062103 */  div.s     $f4, $f4, $f6
/* 8583C 800EC38C 46002021 */  cvt.d.s   $f0, $f4
/* 85840 800EC390 4620103C */  c.lt.d    $f2, $f0
/* 85844 800EC394 00000000 */  nop
/* 85848 800EC398 45000005 */  bc1f      .L800EC3B0
/* 8584C 800EC39C E624001C */   swc1     $f4, 0x1c($s1)
/* 85850 800EC3A0 3C0141A0 */  lui       $at, 0x41a0
/* 85854 800EC3A4 44810000 */  mtc1      $at, $f0
/* 85858 800EC3A8 00000000 */  nop
/* 8585C 800EC3AC E620001C */  swc1      $f0, 0x1c($s1)
.L800EC3B0:
/* 85860 800EC3B0 C620001C */  lwc1      $f0, 0x1c($s1)
/* 85864 800EC3B4 44801000 */  mtc1      $zero, $f2
/* 85868 800EC3B8 44801800 */  mtc1      $zero, $f3
/* 8586C 800EC3BC 46000021 */  cvt.d.s   $f0, $f0
/* 85870 800EC3C0 4622003C */  c.lt.d    $f0, $f2
/* 85874 800EC3C4 00000000 */  nop
/* 85878 800EC3C8 45030001 */  bc1tl     .L800EC3D0
/* 8587C 800EC3CC AE20001C */   sw       $zero, 0x1c($s1)
.L800EC3D0:
/* 85880 800EC3D0 2642FFFE */  addiu     $v0, $s2, -2
/* 85884 800EC3D4 2C420002 */  sltiu     $v0, $v0, 2
/* 85888 800EC3D8 1440000B */  bnez      $v0, .L800EC408
/* 8588C 800EC3DC 00000000 */   nop
/* 85890 800EC3E0 3C028011 */  lui       $v0, %hi(D_8010CFD8)
/* 85894 800EC3E4 8C42CFD8 */  lw        $v0, %lo(D_8010CFD8)($v0)
/* 85898 800EC3E8 000218C0 */  sll       $v1, $v0, 3
/* 8589C 800EC3EC 00621821 */  addu      $v1, $v1, $v0
/* 858A0 800EC3F0 00031880 */  sll       $v1, $v1, 2
/* 858A4 800EC3F4 3C028010 */  lui       $v0, %hi(gPartnerAnimations+0x8)
/* 858A8 800EC3F8 00431021 */  addu      $v0, $v0, $v1
/* 858AC 800EC3FC 8C428350 */  lw        $v0, %lo(gPartnerAnimations+0x8)($v0)
/* 858B0 800EC400 0803B10B */  j         .L800EC42C
/* 858B4 800EC404 AE220028 */   sw       $v0, 0x28($s1)
.L800EC408:
/* 858B8 800EC408 3C028011 */  lui       $v0, %hi(D_8010CFD8)
/* 858BC 800EC40C 8C42CFD8 */  lw        $v0, %lo(D_8010CFD8)($v0)
/* 858C0 800EC410 000218C0 */  sll       $v1, $v0, 3
/* 858C4 800EC414 00621821 */  addu      $v1, $v1, $v0
/* 858C8 800EC418 00031880 */  sll       $v1, $v1, 2
/* 858CC 800EC41C 3C028010 */  lui       $v0, %hi(gPartnerAnimations+0x20)
/* 858D0 800EC420 00431021 */  addu      $v0, $v0, $v1
/* 858D4 800EC424 8C428368 */  lw        $v0, %lo(gPartnerAnimations+0x20)($v0)
/* 858D8 800EC428 AE220028 */  sw        $v0, 0x28($s1)
.L800EC42C:
/* 858DC 800EC42C C6200038 */  lwc1      $f0, 0x38($s1)
/* 858E0 800EC430 C622003C */  lwc1      $f2, 0x3c($s1)
/* 858E4 800EC434 C6240040 */  lwc1      $f4, 0x40($s1)
/* 858E8 800EC438 8E230000 */  lw        $v1, ($s1)
/* 858EC 800EC43C 24020002 */  addiu     $v0, $zero, 2
/* 858F0 800EC440 3C018011 */  lui       $at, %hi(D_8010CFC8)
/* 858F4 800EC444 A422CFC8 */  sh        $v0, %lo(D_8010CFC8)($at)
/* 858F8 800EC448 34630800 */  ori       $v1, $v1, 0x800
/* 858FC 800EC44C E6200060 */  swc1      $f0, 0x60($s1)
/* 85900 800EC450 E6220064 */  swc1      $f2, 0x64($s1)
/* 85904 800EC454 E6240068 */  swc1      $f4, 0x68($s1)
/* 85908 800EC458 AE230000 */  sw        $v1, ($s1)
glabel L800EC45C_8590C
/* 8590C 800EC45C C620001C */  lwc1      $f0, 0x1c($s1)
/* 85910 800EC460 C6220014 */  lwc1      $f2, 0x14($s1)
/* 85914 800EC464 46020001 */  sub.s     $f0, $f0, $f2
/* 85918 800EC468 C622003C */  lwc1      $f2, 0x3c($s1)
/* 8591C 800EC46C 46001080 */  add.s     $f2, $f2, $f0
/* 85920 800EC470 4480A000 */  mtc1      $zero, $f20
/* 85924 800EC474 00000000 */  nop
/* 85928 800EC478 4614003E */  c.le.s    $f0, $f20
/* 8592C 800EC47C E620001C */  swc1      $f0, 0x1c($s1)
/* 85930 800EC480 4500000A */  bc1f      .L800EC4AC
/* 85934 800EC484 E622003C */   swc1     $f2, 0x3c($s1)
/* 85938 800EC488 3C028011 */  lui       $v0, %hi(D_8010CFD8)
/* 8593C 800EC48C 8C42CFD8 */  lw        $v0, %lo(D_8010CFD8)($v0)
/* 85940 800EC490 000218C0 */  sll       $v1, $v0, 3
/* 85944 800EC494 00621821 */  addu      $v1, $v1, $v0
/* 85948 800EC498 00031880 */  sll       $v1, $v1, 2
/* 8594C 800EC49C 3C028010 */  lui       $v0, %hi(gPartnerAnimations+0xC)
/* 85950 800EC4A0 00431021 */  addu      $v0, $v0, $v1
/* 85954 800EC4A4 8C428354 */  lw        $v0, %lo(gPartnerAnimations+0xC)($v0)
/* 85958 800EC4A8 AE220028 */  sw        $v0, 0x28($s1)
.L800EC4AC:
/* 8595C 800EC4AC C622003C */  lwc1      $f2, 0x3c($s1)
/* 85960 800EC4B0 3C01C4FA */  lui       $at, 0xc4fa
/* 85964 800EC4B4 44810000 */  mtc1      $at, $f0
/* 85968 800EC4B8 00000000 */  nop
/* 8596C 800EC4BC 4600103C */  c.lt.s    $f2, $f0
/* 85970 800EC4C0 00000000 */  nop
/* 85974 800EC4C4 4500001B */  bc1f      .L800EC534
/* 85978 800EC4C8 2404F7FF */   addiu    $a0, $zero, -0x801
/* 8597C 800EC4CC C62C0038 */  lwc1      $f12, 0x38($s1)
/* 85980 800EC4D0 3C028011 */  lui       $v0, %hi(D_8010CFD8)
/* 85984 800EC4D4 8C42CFD8 */  lw        $v0, %lo(D_8010CFD8)($v0)
/* 85988 800EC4D8 C62E0040 */  lwc1      $f14, 0x40($s1)
/* 8598C 800EC4DC 000218C0 */  sll       $v1, $v0, 3
/* 85990 800EC4E0 00621821 */  addu      $v1, $v1, $v0
/* 85994 800EC4E4 00031880 */  sll       $v1, $v1, 2
/* 85998 800EC4E8 8E220000 */  lw        $v0, ($s1)
/* 8599C 800EC4EC 3C018010 */  lui       $at, %hi(gPartnerAnimations+0x10)
/* 859A0 800EC4F0 00230821 */  addu      $at, $at, $v1
/* 859A4 800EC4F4 8C238358 */  lw        $v1, %lo(gPartnerAnimations+0x10)($at)
/* 859A8 800EC4F8 E634001C */  swc1      $f20, 0x1c($s1)
/* 859AC 800EC4FC 00441024 */  and       $v0, $v0, $a0
/* 859B0 800EC500 AE220000 */  sw        $v0, ($s1)
/* 859B4 800EC504 AE230028 */  sw        $v1, 0x28($s1)
/* 859B8 800EC508 8E660028 */  lw        $a2, 0x28($s3)
/* 859BC 800EC50C 0C00A720 */  jal       atan2
/* 859C0 800EC510 8E670030 */   lw       $a3, 0x30($s3)
/* 859C4 800EC514 E620000C */  swc1      $f0, 0xc($s1)
/* 859C8 800EC518 C6600028 */  lwc1      $f0, 0x28($s3)
/* 859CC 800EC51C E6200038 */  swc1      $f0, 0x38($s1)
/* 859D0 800EC520 C660002C */  lwc1      $f0, 0x2c($s3)
/* 859D4 800EC524 E620003C */  swc1      $f0, 0x3c($s1)
/* 859D8 800EC528 C6600030 */  lwc1      $f0, 0x30($s3)
/* 859DC 800EC52C 0803B47C */  j         .L800ED1F0
/* 859E0 800EC530 24020005 */   addiu    $v0, $zero, 5
.L800EC534:
/* 859E4 800EC534 C624001C */  lwc1      $f4, 0x1c($s1)
/* 859E8 800EC538 4614203E */  c.le.s    $f4, $f20
/* 859EC 800EC53C 00000000 */  nop
/* 859F0 800EC540 45000068 */  bc1f      .L800EC6E4
/* 859F4 800EC544 27A50028 */   addiu    $a1, $sp, 0x28
/* 859F8 800EC548 27A20034 */  addiu     $v0, $sp, 0x34
/* 859FC 800EC54C C6200038 */  lwc1      $f0, 0x38($s1)
/* 85A00 800EC550 3C014130 */  lui       $at, 0x4130
/* 85A04 800EC554 44811000 */  mtc1      $at, $f2
/* 85A08 800EC558 27A6002C */  addiu     $a2, $sp, 0x2c
/* 85A0C 800EC55C E7A00028 */  swc1      $f0, 0x28($sp)
/* 85A10 800EC560 46002005 */  abs.s     $f0, $f4
/* 85A14 800EC564 46020000 */  add.s     $f0, $f0, $f2
/* 85A18 800EC568 C622003C */  lwc1      $f2, 0x3c($s1)
/* 85A1C 800EC56C C6240040 */  lwc1      $f4, 0x40($s1)
/* 85A20 800EC570 46001080 */  add.s     $f2, $f2, $f0
/* 85A24 800EC574 E7A40030 */  swc1      $f4, 0x30($sp)
/* 85A28 800EC578 E7A00034 */  swc1      $f0, 0x34($sp)
/* 85A2C 800EC57C E7A2002C */  swc1      $f2, 0x2c($sp)
/* 85A30 800EC580 AFA20010 */  sw        $v0, 0x10($sp)
/* 85A34 800EC584 C620000C */  lwc1      $f0, 0xc($s1)
/* 85A38 800EC588 27A70030 */  addiu     $a3, $sp, 0x30
/* 85A3C 800EC58C E7A00014 */  swc1      $f0, 0x14($sp)
/* 85A40 800EC590 862200A6 */  lh        $v0, 0xa6($s1)
/* 85A44 800EC594 26320038 */  addiu     $s2, $s1, 0x38
/* 85A48 800EC598 44820000 */  mtc1      $v0, $f0
/* 85A4C 800EC59C 00000000 */  nop
/* 85A50 800EC5A0 46800020 */  cvt.s.w   $f0, $f0
/* 85A54 800EC5A4 E7A00018 */  swc1      $f0, 0x18($sp)
/* 85A58 800EC5A8 8E240080 */  lw        $a0, 0x80($s1)
/* 85A5C 800EC5AC 0C0371DE */  jal       npc_raycast_down_ahead
/* 85A60 800EC5B0 26340040 */   addiu    $s4, $s1, 0x40
/* 85A64 800EC5B4 1040004B */  beqz      $v0, .L800EC6E4
/* 85A68 800EC5B8 00000000 */   nop
/* 85A6C 800EC5BC C620001C */  lwc1      $f0, 0x1c($s1)
/* 85A70 800EC5C0 3C0141B0 */  lui       $at, 0x41b0
/* 85A74 800EC5C4 44811000 */  mtc1      $at, $f2
/* 85A78 800EC5C8 46000005 */  abs.s     $f0, $f0
/* 85A7C 800EC5CC 46020000 */  add.s     $f0, $f0, $f2
/* 85A80 800EC5D0 C7A20034 */  lwc1      $f2, 0x34($sp)
/* 85A84 800EC5D4 4600103E */  c.le.s    $f2, $f0
/* 85A88 800EC5D8 00000000 */  nop
/* 85A8C 800EC5DC 45000041 */  bc1f      .L800EC6E4
/* 85A90 800EC5E0 00000000 */   nop
/* 85A94 800EC5E4 C7AC0028 */  lwc1      $f12, 0x28($sp)
/* 85A98 800EC5E8 3C038011 */  lui       $v1, %hi(D_8010CFD8)
/* 85A9C 800EC5EC 8C63CFD8 */  lw        $v1, %lo(D_8010CFD8)($v1)
/* 85AA0 800EC5F0 C7AE0030 */  lwc1      $f14, 0x30($sp)
/* 85AA4 800EC5F4 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* 85AA8 800EC5F8 000310C0 */  sll       $v0, $v1, 3
/* 85AAC 800EC5FC 00431021 */  addu      $v0, $v0, $v1
/* 85AB0 800EC600 00021080 */  sll       $v0, $v0, 2
/* 85AB4 800EC604 3C048010 */  lui       $a0, %hi(gPartnerAnimations+0x10)
/* 85AB8 800EC608 00822021 */  addu      $a0, $a0, $v0
/* 85ABC 800EC60C 8C848358 */  lw        $a0, %lo(gPartnerAnimations+0x10)($a0)
/* 85AC0 800EC610 8E220000 */  lw        $v0, ($s1)
/* 85AC4 800EC614 2403F7FF */  addiu     $v1, $zero, -0x801
/* 85AC8 800EC618 E634001C */  swc1      $f20, 0x1c($s1)
/* 85ACC 800EC61C E620003C */  swc1      $f0, 0x3c($s1)
/* 85AD0 800EC620 00431024 */  and       $v0, $v0, $v1
/* 85AD4 800EC624 AE220000 */  sw        $v0, ($s1)
/* 85AD8 800EC628 AE240028 */  sw        $a0, 0x28($s1)
/* 85ADC 800EC62C 8E660028 */  lw        $a2, 0x28($s3)
/* 85AE0 800EC630 0C00A720 */  jal       atan2
/* 85AE4 800EC634 8E670030 */   lw       $a3, 0x30($s3)
/* 85AE8 800EC638 0220202D */  daddu     $a0, $s1, $zero
/* 85AEC 800EC63C 24050002 */  addiu     $a1, $zero, 2
/* 85AF0 800EC640 0C00F598 */  jal       func_8003D660
/* 85AF4 800EC644 E620000C */   swc1     $f0, 0xc($s1)
/* 85AF8 800EC648 C62C0038 */  lwc1      $f12, 0x38($s1)
/* 85AFC 800EC64C C62E0040 */  lwc1      $f14, 0x40($s1)
/* 85B00 800EC650 8E260060 */  lw        $a2, 0x60($s1)
/* 85B04 800EC654 8E270068 */  lw        $a3, 0x68($s1)
/* 85B08 800EC658 3C108011 */  lui       $s0, %hi(D_8010CFC8)
/* 85B0C 800EC65C 2610CFC8 */  addiu     $s0, $s0, %lo(D_8010CFC8)
/* 85B10 800EC660 0C00A7B5 */  jal       dist2D
/* 85B14 800EC664 A6000000 */   sh       $zero, ($s0)
/* 85B18 800EC668 3C014014 */  lui       $at, 0x4014
/* 85B1C 800EC66C 44811800 */  mtc1      $at, $f3
/* 85B20 800EC670 44801000 */  mtc1      $zero, $f2
/* 85B24 800EC674 E7A00034 */  swc1      $f0, 0x34($sp)
/* 85B28 800EC678 46000021 */  cvt.d.s   $f0, $f0
/* 85B2C 800EC67C 4622003C */  c.lt.d    $f0, $f2
/* 85B30 800EC680 00000000 */  nop
/* 85B34 800EC684 45000317 */  bc1f      L800ED2E4_86794
/* 85B38 800EC688 00000000 */   nop
/* 85B3C 800EC68C C6600028 */  lwc1      $f0, 0x28($s3)
/* 85B40 800EC690 E6200038 */  swc1      $f0, 0x38($s1)
/* 85B44 800EC694 C660002C */  lwc1      $f0, 0x2c($s3)
/* 85B48 800EC698 E620003C */  swc1      $f0, 0x3c($s1)
/* 85B4C 800EC69C C6600030 */  lwc1      $f0, 0x30($s3)
/* 85B50 800EC6A0 E6200040 */  swc1      $f0, 0x40($s1)
/* 85B54 800EC6A4 C6AC006C */  lwc1      $f12, 0x6c($s5)
/* 85B58 800EC6A8 3C0142B4 */  lui       $at, 0x42b4
/* 85B5C 800EC6AC 44810000 */  mtc1      $at, $f0
/* 85B60 800EC6B0 00000000 */  nop
/* 85B64 800EC6B4 46006300 */  add.s     $f12, $f12, $f0
/* 85B68 800EC6B8 C66000A8 */  lwc1      $f0, 0xa8($s3)
/* 85B6C 800EC6BC 0C00A6C9 */  jal       clamp_angle
/* 85B70 800EC6C0 46006301 */   sub.s    $f12, $f12, $f0
/* 85B74 800EC6C4 0240202D */  daddu     $a0, $s2, $zero
/* 85B78 800EC6C8 3C0640A0 */  lui       $a2, 0x40a0
/* 85B7C 800EC6CC 44070000 */  mfc1      $a3, $f0
/* 85B80 800EC6D0 0C00A7E7 */  jal       add_vec2D_polar
/* 85B84 800EC6D4 0280282D */   daddu    $a1, $s4, $zero
/* 85B88 800EC6D8 24020005 */  addiu     $v0, $zero, 5
/* 85B8C 800EC6DC 0803B4B9 */  j         L800ED2E4_86794
/* 85B90 800EC6E0 A6020000 */   sh       $v0, ($s0)
.L800EC6E4:
/* 85B94 800EC6E4 8E250018 */  lw        $a1, 0x18($s1)
/* 85B98 800EC6E8 8E26000C */  lw        $a2, 0xc($s1)
/* 85B9C 800EC6EC 0C00EA95 */  jal       npc_move_heading
/* 85BA0 800EC6F0 0220202D */   daddu    $a0, $s1, $zero
/* 85BA4 800EC6F4 0803B4B9 */  j         L800ED2E4_86794
/* 85BA8 800EC6F8 00000000 */   nop
glabel L800EC6FC_85BAC
/* 85BAC 800EC6FC 3C038011 */  lui       $v1, %hi(D_8010CD38)
/* 85BB0 800EC700 2463CD38 */  addiu     $v1, $v1, %lo(D_8010CD38)
/* 85BB4 800EC704 C62C0038 */  lwc1      $f12, 0x38($s1)
/* 85BB8 800EC708 C62E0040 */  lwc1      $f14, 0x40($s1)
/* 85BBC 800EC70C 8E660028 */  lw        $a2, 0x28($s3)
/* 85BC0 800EC710 8E670030 */  lw        $a3, 0x30($s3)
/* 85BC4 800EC714 3C028011 */  lui       $v0, %hi(D_8010CFBC)
/* 85BC8 800EC718 8C42CFBC */  lw        $v0, %lo(D_8010CFBC)($v0)
/* 85BCC 800EC71C C620003C */  lwc1      $f0, 0x3c($s1)
/* 85BD0 800EC720 00021100 */  sll       $v0, $v0, 4
/* 85BD4 800EC724 00438021 */  addu      $s0, $v0, $v1
/* 85BD8 800EC728 46006106 */  mov.s     $f4, $f12
/* 85BDC 800EC72C C6060004 */  lwc1      $f6, 4($s0)
/* 85BE0 800EC730 C608000C */  lwc1      $f8, 0xc($s0)
/* 85BE4 800EC734 46007086 */  mov.s     $f2, $f14
/* 85BE8 800EC738 E7A40028 */  swc1      $f4, 0x28($sp)
/* 85BEC 800EC73C E7A0002C */  swc1      $f0, 0x2c($sp)
/* 85BF0 800EC740 E7A20030 */  swc1      $f2, 0x30($sp)
/* 85BF4 800EC744 E7A60020 */  swc1      $f6, 0x20($sp)
/* 85BF8 800EC748 0C00A7B5 */  jal       dist2D
/* 85BFC 800EC74C E7A80024 */   swc1     $f8, 0x24($sp)
/* 85C00 800EC750 3C018011 */  lui       $at, %hi(D_8010CFC0)
/* 85C04 800EC754 C422CFC0 */  lwc1      $f2, %lo(D_8010CFC0)($at)
/* 85C08 800EC758 4602003E */  c.le.s    $f0, $f2
/* 85C0C 800EC75C 00000000 */  nop
/* 85C10 800EC760 450000E3 */  bc1f      .L800ECAF0
/* 85C14 800EC764 E7A00034 */   swc1     $f0, 0x34($sp)
/* 85C18 800EC768 3C048011 */  lui       $a0, %hi(D_8010CFCA)
/* 85C1C 800EC76C 2484CFCA */  addiu     $a0, $a0, %lo(D_8010CFCA)
/* 85C20 800EC770 84820000 */  lh        $v0, ($a0)
/* 85C24 800EC774 14400019 */  bnez      $v0, .L800EC7DC
/* 85C28 800EC778 00000000 */   nop
/* 85C2C 800EC77C 3C038011 */  lui       $v1, %hi(D_8010CFD8)
/* 85C30 800EC780 8C63CFD8 */  lw        $v1, %lo(D_8010CFD8)($v1)
/* 85C34 800EC784 AE200018 */  sw        $zero, 0x18($s1)
/* 85C38 800EC788 AE200014 */  sw        $zero, 0x14($s1)
/* 85C3C 800EC78C 000310C0 */  sll       $v0, $v1, 3
/* 85C40 800EC790 00431021 */  addu      $v0, $v0, $v1
/* 85C44 800EC794 00021080 */  sll       $v0, $v0, 2
/* 85C48 800EC798 3C018010 */  lui       $at, %hi(gPartnerAnimations+0x14)
/* 85C4C 800EC79C 00220821 */  addu      $at, $at, $v0
/* 85C50 800EC7A0 8C22835C */  lw        $v0, %lo(gPartnerAnimations+0x14)($at)
/* 85C54 800EC7A4 AE220028 */  sw        $v0, 0x28($s1)
/* 85C58 800EC7A8 826300B4 */  lb        $v1, 0xb4($s3)
/* 85C5C 800EC7AC 2402000C */  addiu     $v0, $zero, 0xc
/* 85C60 800EC7B0 50620001 */  beql      $v1, $v0, .L800EC7B8
/* 85C64 800EC7B4 A4800000 */   sh       $zero, ($a0)
.L800EC7B8:
/* 85C68 800EC7B8 86240084 */  lh        $a0, 0x84($s1)
/* 85C6C 800EC7BC 0C016F6A */  jal       get_collider_type_by_id
/* 85C70 800EC7C0 00000000 */   nop
/* 85C74 800EC7C4 2442FFFE */  addiu     $v0, $v0, -2
/* 85C78 800EC7C8 2C420002 */  sltiu     $v0, $v0, 2
/* 85C7C 800EC7CC 104000C8 */  beqz      $v0, .L800ECAF0
/* 85C80 800EC7D0 00000000 */   nop
/* 85C84 800EC7D4 0803B0BA */  j         .L800EC2E8
/* 85C88 800EC7D8 00000000 */   nop
.L800EC7DC:
/* 85C8C 800EC7DC C66200A8 */  lwc1      $f2, 0xa8($s3)
/* 85C90 800EC7E0 3C014334 */  lui       $at, 0x4334
/* 85C94 800EC7E4 44810000 */  mtc1      $at, $f0
/* 85C98 800EC7E8 C6AC006C */  lwc1      $f12, 0x6c($s5)
/* 85C9C 800EC7EC 4600103C */  c.lt.s    $f2, $f0
/* 85CA0 800EC7F0 3C01C2B4 */  lui       $at, 0xc2b4
/* 85CA4 800EC7F4 44810000 */  mtc1      $at, $f0
/* 85CA8 800EC7F8 45000003 */  bc1f      .L800EC808
/* 85CAC 800EC7FC 00000000 */   nop
/* 85CB0 800EC800 3C0142B4 */  lui       $at, 0x42b4
/* 85CB4 800EC804 44810000 */  mtc1      $at, $f0
.L800EC808:
/* 85CB8 800EC808 0C00A6C9 */  jal       clamp_angle
/* 85CBC 800EC80C 46006300 */   add.s    $f12, $f12, $f0
/* 85CC0 800EC810 44070000 */  mfc1      $a3, $f0
/* 85CC4 800EC814 C6600028 */  lwc1      $f0, 0x28($s3)
/* 85CC8 800EC818 3C018011 */  lui       $at, %hi(D_8010CFC0)
/* 85CCC 800EC81C C424CFC0 */  lwc1      $f4, %lo(D_8010CFC0)($at)
/* 85CD0 800EC820 26240060 */  addiu     $a0, $s1, 0x60
/* 85CD4 800EC824 E6200060 */  swc1      $f0, 0x60($s1)
/* 85CD8 800EC828 3C014120 */  lui       $at, 0x4120
/* 85CDC 800EC82C 44810000 */  mtc1      $at, $f0
/* 85CE0 800EC830 C662002C */  lwc1      $f2, 0x2c($s3)
/* 85CE4 800EC834 46002101 */  sub.s     $f4, $f4, $f0
/* 85CE8 800EC838 E6220064 */  swc1      $f2, 0x64($s1)
/* 85CEC 800EC83C C6600030 */  lwc1      $f0, 0x30($s3)
/* 85CF0 800EC840 44062000 */  mfc1      $a2, $f4
/* 85CF4 800EC844 26250068 */  addiu     $a1, $s1, 0x68
/* 85CF8 800EC848 0C00A7E7 */  jal       add_vec2D_polar
/* 85CFC 800EC84C E6200068 */   swc1     $f0, 0x68($s1)
/* 85D00 800EC850 C62C0038 */  lwc1      $f12, 0x38($s1)
/* 85D04 800EC854 C62E0040 */  lwc1      $f14, 0x40($s1)
/* 85D08 800EC858 8E260060 */  lw        $a2, 0x60($s1)
/* 85D0C 800EC85C 0C00A720 */  jal       atan2
/* 85D10 800EC860 8E270068 */   lw       $a3, 0x68($s1)
/* 85D14 800EC864 C62C0038 */  lwc1      $f12, 0x38($s1)
/* 85D18 800EC868 C62E0040 */  lwc1      $f14, 0x40($s1)
/* 85D1C 800EC86C 8E260060 */  lw        $a2, 0x60($s1)
/* 85D20 800EC870 8E270068 */  lw        $a3, 0x68($s1)
/* 85D24 800EC874 0C00A7B5 */  jal       dist2D
/* 85D28 800EC878 46000506 */   mov.s    $f20, $f0
/* 85D2C 800EC87C 3C014000 */  lui       $at, 0x4000
/* 85D30 800EC880 44811000 */  mtc1      $at, $f2
/* 85D34 800EC884 E7A00034 */  swc1      $f0, 0x34($sp)
/* 85D38 800EC888 4600103C */  c.lt.s    $f2, $f0
/* 85D3C 800EC88C 00000000 */  nop
/* 85D40 800EC890 45000022 */  bc1f      .L800EC91C
/* 85D44 800EC894 E6220018 */   swc1     $f2, 0x18($s1)
/* 85D48 800EC898 3C038011 */  lui       $v1, %hi(D_8010CFD8)
/* 85D4C 800EC89C 8C63CFD8 */  lw        $v1, %lo(D_8010CFD8)($v1)
/* 85D50 800EC8A0 3C048010 */  lui       $a0, %hi(gPartnerAnimations)
/* 85D54 800EC8A4 24848348 */  addiu     $a0, $a0, %lo(gPartnerAnimations)
/* 85D58 800EC8A8 E634000C */  swc1      $f20, 0xc($s1)
/* 85D5C 800EC8AC 000310C0 */  sll       $v0, $v1, 3
/* 85D60 800EC8B0 00431021 */  addu      $v0, $v0, $v1
/* 85D64 800EC8B4 00021080 */  sll       $v0, $v0, 2
/* 85D68 800EC8B8 00442021 */  addu      $a0, $v0, $a0
/* 85D6C 800EC8BC 8E220000 */  lw        $v0, ($s1)
/* 85D70 800EC8C0 8C830018 */  lw        $v1, 0x18($a0)
/* 85D74 800EC8C4 30424000 */  andi      $v0, $v0, 0x4000
/* 85D78 800EC8C8 14400004 */  bnez      $v0, .L800EC8DC
/* 85D7C 800EC8CC AE230028 */   sw       $v1, 0x28($s1)
/* 85D80 800EC8D0 3C018010 */  lui       $at, %hi(D_800F803A)
/* 85D84 800EC8D4 0803B263 */  j         .L800EC98C
/* 85D88 800EC8D8 A420803A */   sh       $zero, %lo(D_800F803A)($at)
.L800EC8DC:
/* 85D8C 800EC8DC 3C038010 */  lui       $v1, %hi(D_800F803A)
/* 85D90 800EC8E0 2463803A */  addiu     $v1, $v1, %lo(D_800F803A)
/* 85D94 800EC8E4 94620000 */  lhu       $v0, ($v1)
/* 85D98 800EC8E8 24420001 */  addiu     $v0, $v0, 1
/* 85D9C 800EC8EC A4620000 */  sh        $v0, ($v1)
/* 85DA0 800EC8F0 00021400 */  sll       $v0, $v0, 0x10
/* 85DA4 800EC8F4 00021403 */  sra       $v0, $v0, 0x10
/* 85DA8 800EC8F8 2842000B */  slti      $v0, $v0, 0xb
/* 85DAC 800EC8FC 14400023 */  bnez      $v0, .L800EC98C
/* 85DB0 800EC900 00000000 */   nop
/* 85DB4 800EC904 C6740080 */  lwc1      $f20, 0x80($s3)
/* 85DB8 800EC908 AE200018 */  sw        $zero, 0x18($s1)
/* 85DBC 800EC90C AE200014 */  sw        $zero, 0x14($s1)
/* 85DC0 800EC910 E6340034 */  swc1      $f20, 0x34($s1)
/* 85DC4 800EC914 0803B258 */  j         .L800EC960
/* 85DC8 800EC918 8C820014 */   lw       $v0, 0x14($a0)
.L800EC91C:
/* 85DCC 800EC91C C62C0038 */  lwc1      $f12, 0x38($s1)
/* 85DD0 800EC920 C62E0040 */  lwc1      $f14, 0x40($s1)
/* 85DD4 800EC924 8E660028 */  lw        $a2, 0x28($s3)
/* 85DD8 800EC928 0C00A720 */  jal       atan2
/* 85DDC 800EC92C 8E670030 */   lw       $a3, 0x30($s3)
/* 85DE0 800EC930 3C038011 */  lui       $v1, %hi(D_8010CFD8)
/* 85DE4 800EC934 8C63CFD8 */  lw        $v1, %lo(D_8010CFD8)($v1)
/* 85DE8 800EC938 46000506 */  mov.s     $f20, $f0
/* 85DEC 800EC93C E634000C */  swc1      $f20, 0xc($s1)
/* 85DF0 800EC940 AE200018 */  sw        $zero, 0x18($s1)
/* 85DF4 800EC944 AE200014 */  sw        $zero, 0x14($s1)
/* 85DF8 800EC948 000310C0 */  sll       $v0, $v1, 3
/* 85DFC 800EC94C 00431021 */  addu      $v0, $v0, $v1
/* 85E00 800EC950 00021080 */  sll       $v0, $v0, 2
/* 85E04 800EC954 3C018010 */  lui       $at, %hi(gPartnerAnimations+0x14)
/* 85E08 800EC958 00220821 */  addu      $at, $at, $v0
/* 85E0C 800EC95C 8C22835C */  lw        $v0, %lo(gPartnerAnimations+0x14)($at)
.L800EC960:
/* 85E10 800EC960 3C048011 */  lui       $a0, %hi(D_8010CFCA)
/* 85E14 800EC964 2484CFCA */  addiu     $a0, $a0, %lo(D_8010CFCA)
/* 85E18 800EC968 AE220028 */  sw        $v0, 0x28($s1)
/* 85E1C 800EC96C 84830000 */  lh        $v1, ($a0)
/* 85E20 800EC970 24020002 */  addiu     $v0, $zero, 2
/* 85E24 800EC974 10620004 */  beq       $v1, $v0, .L800EC988
/* 85E28 800EC978 2402000C */   addiu    $v0, $zero, 0xc
/* 85E2C 800EC97C 826300B4 */  lb        $v1, 0xb4($s3)
/* 85E30 800EC980 14620002 */  bne       $v1, $v0, .L800EC98C
/* 85E34 800EC984 00000000 */   nop
.L800EC988:
/* 85E38 800EC988 A4800000 */  sh        $zero, ($a0)
.L800EC98C:
/* 85E3C 800EC98C 8E250018 */  lw        $a1, 0x18($s1)
/* 85E40 800EC990 4406A000 */  mfc1      $a2, $f20
/* 85E44 800EC994 0220202D */  daddu     $a0, $s1, $zero
/* 85E48 800EC998 0C00EA95 */  jal       npc_move_heading
/* 85E4C 800EC99C E634000C */   swc1     $f20, 0xc($s1)
/* 85E50 800EC9A0 C6200018 */  lwc1      $f0, 0x18($s1)
/* 85E54 800EC9A4 3C014010 */  lui       $at, 0x4010
/* 85E58 800EC9A8 44811800 */  mtc1      $at, $f3
/* 85E5C 800EC9AC 44801000 */  mtc1      $zero, $f2
/* 85E60 800EC9B0 46000021 */  cvt.d.s   $f0, $f0
/* 85E64 800EC9B4 4622003C */  c.lt.d    $f0, $f2
/* 85E68 800EC9B8 00000000 */  nop
/* 85E6C 800EC9BC 45000002 */  bc1f      .L800EC9C8
/* 85E70 800EC9C0 24050001 */   addiu    $a1, $zero, 1
/* 85E74 800EC9C4 0000282D */  daddu     $a1, $zero, $zero
.L800EC9C8:
/* 85E78 800EC9C8 0C00F598 */  jal       func_8003D660
/* 85E7C 800EC9CC 0220202D */   daddu    $a0, $s1, $zero
/* 85E80 800EC9D0 862200A8 */  lh        $v0, 0xa8($s1)
/* 85E84 800EC9D4 3C01447A */  lui       $at, 0x447a
/* 85E88 800EC9D8 44810000 */  mtc1      $at, $f0
/* 85E8C 800EC9DC 44822000 */  mtc1      $v0, $f4
/* 85E90 800EC9E0 00000000 */  nop
/* 85E94 800EC9E4 46802120 */  cvt.s.w   $f4, $f4
/* 85E98 800EC9E8 27A20034 */  addiu     $v0, $sp, 0x34
/* 85E9C 800EC9EC E7A00034 */  swc1      $f0, 0x34($sp)
/* 85EA0 800EC9F0 C6260038 */  lwc1      $f6, 0x38($s1)
/* 85EA4 800EC9F4 C620003C */  lwc1      $f0, 0x3c($s1)
/* 85EA8 800EC9F8 C6220040 */  lwc1      $f2, 0x40($s1)
/* 85EAC 800EC9FC 46040000 */  add.s     $f0, $f0, $f4
/* 85EB0 800ECA00 E7A60028 */  swc1      $f6, 0x28($sp)
/* 85EB4 800ECA04 E7A20030 */  swc1      $f2, 0x30($sp)
/* 85EB8 800ECA08 E7A0002C */  swc1      $f0, 0x2c($sp)
/* 85EBC 800ECA0C AFA20010 */  sw        $v0, 0x10($sp)
/* 85EC0 800ECA10 C620000C */  lwc1      $f0, 0xc($s1)
/* 85EC4 800ECA14 27A50028 */  addiu     $a1, $sp, 0x28
/* 85EC8 800ECA18 E7A00014 */  swc1      $f0, 0x14($sp)
/* 85ECC 800ECA1C 862200A6 */  lh        $v0, 0xa6($s1)
/* 85ED0 800ECA20 27A6002C */  addiu     $a2, $sp, 0x2c
/* 85ED4 800ECA24 44820000 */  mtc1      $v0, $f0
/* 85ED8 800ECA28 00000000 */  nop
/* 85EDC 800ECA2C 46800020 */  cvt.s.w   $f0, $f0
/* 85EE0 800ECA30 E7A00018 */  swc1      $f0, 0x18($sp)
/* 85EE4 800ECA34 8E240080 */  lw        $a0, 0x80($s1)
/* 85EE8 800ECA38 0C0371DE */  jal       npc_raycast_down_ahead
/* 85EEC 800ECA3C 27A70030 */   addiu    $a3, $sp, 0x30
/* 85EF0 800ECA40 10400228 */  beqz      $v0, L800ED2E4_86794
/* 85EF4 800ECA44 00000000 */   nop
/* 85EF8 800ECA48 3C108011 */  lui       $s0, %hi(D_8010C978)
/* 85EFC 800ECA4C 2610C978 */  addiu     $s0, $s0, %lo(D_8010C978)
/* 85F00 800ECA50 0C016F6A */  jal       get_collider_type_by_id
/* 85F04 800ECA54 8E040000 */   lw       $a0, ($s0)
/* 85F08 800ECA58 2442FFFE */  addiu     $v0, $v0, -2
/* 85F0C 800ECA5C 2C420002 */  sltiu     $v0, $v0, 2
/* 85F10 800ECA60 10400020 */  beqz      $v0, .L800ECAE4
/* 85F14 800ECA64 00000000 */   nop
/* 85F18 800ECA68 3C014334 */  lui       $at, 0x4334
/* 85F1C 800ECA6C 44816000 */  mtc1      $at, $f12
/* 85F20 800ECA70 0C00A6C9 */  jal       clamp_angle
/* 85F24 800ECA74 460CA300 */   add.s    $f12, $f20, $f12
/* 85F28 800ECA78 8E250018 */  lw        $a1, 0x18($s1)
/* 85F2C 800ECA7C 44060000 */  mfc1      $a2, $f0
/* 85F30 800ECA80 0220202D */  daddu     $a0, $s1, $zero
/* 85F34 800ECA84 0C00EA95 */  jal       npc_move_heading
/* 85F38 800ECA88 AE26000C */   sw       $a2, 0xc($s1)
/* 85F3C 800ECA8C 3C038011 */  lui       $v1, %hi(D_8010CFD8)
/* 85F40 800ECA90 8C63CFD8 */  lw        $v1, %lo(D_8010CFD8)($v1)
/* 85F44 800ECA94 AE200018 */  sw        $zero, 0x18($s1)
/* 85F48 800ECA98 AE200014 */  sw        $zero, 0x14($s1)
/* 85F4C 800ECA9C 000310C0 */  sll       $v0, $v1, 3
/* 85F50 800ECAA0 00431021 */  addu      $v0, $v0, $v1
/* 85F54 800ECAA4 00021080 */  sll       $v0, $v0, 2
/* 85F58 800ECAA8 3C018010 */  lui       $at, %hi(gPartnerAnimations+0x14)
/* 85F5C 800ECAAC 00220821 */  addu      $at, $at, $v0
/* 85F60 800ECAB0 8C22835C */  lw        $v0, %lo(gPartnerAnimations+0x14)($at)
/* 85F64 800ECAB4 3C048011 */  lui       $a0, %hi(D_8010CFCA)
/* 85F68 800ECAB8 2484CFCA */  addiu     $a0, $a0, %lo(D_8010CFCA)
/* 85F6C 800ECABC AE220028 */  sw        $v0, 0x28($s1)
/* 85F70 800ECAC0 84830000 */  lh        $v1, ($a0)
/* 85F74 800ECAC4 24020002 */  addiu     $v0, $zero, 2
/* 85F78 800ECAC8 10620177 */  beq       $v1, $v0, .L800ED0A8
/* 85F7C 800ECACC 2402000C */   addiu    $v0, $zero, 0xc
/* 85F80 800ECAD0 826300B4 */  lb        $v1, 0xb4($s3)
/* 85F84 800ECAD4 14620203 */  bne       $v1, $v0, L800ED2E4_86794
/* 85F88 800ECAD8 00000000 */   nop
/* 85F8C 800ECADC 0803B4B9 */  j         L800ED2E4_86794
/* 85F90 800ECAE0 A4800000 */   sh       $zero, ($a0)
.L800ECAE4:
/* 85F94 800ECAE4 8E040000 */  lw        $a0, ($s0)
/* 85F98 800ECAE8 0803B2C9 */  j         .L800ECB24
/* 85F9C 800ECAEC 00000000 */   nop
.L800ECAF0:
/* 85FA0 800ECAF0 C62C0038 */  lwc1      $f12, 0x38($s1)
/* 85FA4 800ECAF4 C62E0040 */  lwc1      $f14, 0x40($s1)
/* 85FA8 800ECAF8 8E660028 */  lw        $a2, 0x28($s3)
/* 85FAC 800ECAFC 0C00A7B5 */  jal       dist2D
/* 85FB0 800ECB00 8E670030 */   lw       $a3, 0x30($s3)
/* 85FB4 800ECB04 3C018011 */  lui       $at, %hi(D_8010CFC0)
/* 85FB8 800ECB08 C422CFC0 */  lwc1      $f2, %lo(D_8010CFC0)($at)
/* 85FBC 800ECB0C 4602003E */  c.le.s    $f0, $f2
/* 85FC0 800ECB10 00000000 */  nop
/* 85FC4 800ECB14 4500000B */  bc1f      .L800ECB44
/* 85FC8 800ECB18 E7A00034 */   swc1     $f0, 0x34($sp)
/* 85FCC 800ECB1C 3C048011 */  lui       $a0, %hi(D_8010C978)
/* 85FD0 800ECB20 8C84C978 */  lw        $a0, %lo(D_8010C978)($a0)
.L800ECB24:
/* 85FD4 800ECB24 0C03A92C */  jal       func_800EA4B0
/* 85FD8 800ECB28 00000000 */   nop
/* 85FDC 800ECB2C 144001ED */  bnez      $v0, L800ED2E4_86794
/* 85FE0 800ECB30 24020002 */   addiu    $v0, $zero, 2
/* 85FE4 800ECB34 3C018011 */  lui       $at, %hi(D_8010CFCA)
/* 85FE8 800ECB38 A422CFCA */  sh        $v0, %lo(D_8010CFCA)($at)
/* 85FEC 800ECB3C 0803B4B9 */  j         L800ED2E4_86794
/* 85FF0 800ECB40 00000000 */   nop
.L800ECB44:
/* 85FF4 800ECB44 3C0142B4 */  lui       $at, 0x42b4
/* 85FF8 800ECB48 4481B000 */  mtc1      $at, $f22
/* 85FFC 800ECB4C 3C128011 */  lui       $s2, %hi(D_8010CFBC)
/* 86000 800ECB50 2652CFBC */  addiu     $s2, $s2, %lo(D_8010CFBC)
/* 86004 800ECB54 3C148011 */  lui       $s4, %hi(D_8010CD38)
/* 86008 800ECB58 2694CD38 */  addiu     $s4, $s4, %lo(D_8010CD38)
.L800ECB5C:
/* 8600C 800ECB5C 82020000 */  lb        $v0, ($s0)
/* 86010 800ECB60 14400028 */  bnez      $v0, .L800ECC04
/* 86014 800ECB64 00000000 */   nop
/* 86018 800ECB68 C62C0038 */  lwc1      $f12, 0x38($s1)
/* 8601C 800ECB6C C62E0040 */  lwc1      $f14, 0x40($s1)
/* 86020 800ECB70 8FA60020 */  lw        $a2, 0x20($sp)
/* 86024 800ECB74 0C00A720 */  jal       atan2
/* 86028 800ECB78 8FA70024 */   lw       $a3, 0x24($sp)
/* 8602C 800ECB7C C62C0038 */  lwc1      $f12, 0x38($s1)
/* 86030 800ECB80 C62E0040 */  lwc1      $f14, 0x40($s1)
/* 86034 800ECB84 8E660028 */  lw        $a2, 0x28($s3)
/* 86038 800ECB88 8E670030 */  lw        $a3, 0x30($s3)
/* 8603C 800ECB8C 0C00A720 */  jal       atan2
/* 86040 800ECB90 46000506 */   mov.s    $f20, $f0
/* 86044 800ECB94 4600A306 */  mov.s     $f12, $f20
/* 86048 800ECB98 0C00A70A */  jal       get_clamped_angle_diff
/* 8604C 800ECB9C 46000386 */   mov.s    $f14, $f0
/* 86050 800ECBA0 46000005 */  abs.s     $f0, $f0
/* 86054 800ECBA4 4616003C */  c.lt.s    $f0, $f22
/* 86058 800ECBA8 00000000 */  nop
/* 8605C 800ECBAC 45010012 */  bc1t      .L800ECBF8
/* 86060 800ECBB0 00000000 */   nop
/* 86064 800ECBB4 8E430000 */  lw        $v1, ($s2)
/* 86068 800ECBB8 3C028011 */  lui       $v0, %hi(D_8010CFB8)
/* 8606C 800ECBBC 8C42CFB8 */  lw        $v0, %lo(D_8010CFB8)($v0)
/* 86070 800ECBC0 1062000D */  beq       $v1, $v0, .L800ECBF8
/* 86074 800ECBC4 24620001 */   addiu    $v0, $v1, 1
/* 86078 800ECBC8 AE420000 */  sw        $v0, ($s2)
/* 8607C 800ECBCC 28420028 */  slti      $v0, $v0, 0x28
/* 86080 800ECBD0 50400001 */  beql      $v0, $zero, .L800ECBD8
/* 86084 800ECBD4 AE400000 */   sw       $zero, ($s2)
.L800ECBD8:
/* 86088 800ECBD8 8E420000 */  lw        $v0, ($s2)
/* 8608C 800ECBDC 00021100 */  sll       $v0, $v0, 4
/* 86090 800ECBE0 00548021 */  addu      $s0, $v0, $s4
/* 86094 800ECBE4 C6000004 */  lwc1      $f0, 4($s0)
/* 86098 800ECBE8 C602000C */  lwc1      $f2, 0xc($s0)
/* 8609C 800ECBEC E7A00020 */  swc1      $f0, 0x20($sp)
/* 860A0 800ECBF0 0803B2D7 */  j         .L800ECB5C
/* 860A4 800ECBF4 E7A20024 */   swc1     $f2, 0x24($sp)
.L800ECBF8:
/* 860A8 800ECBF8 82020000 */  lb        $v0, ($s0)
/* 860AC 800ECBFC 1040FDBA */  beqz      $v0, .L800EC2E8
/* 860B0 800ECC00 00000000 */   nop
.L800ECC04:
/* 860B4 800ECC04 3C0142B4 */  lui       $at, 0x42b4
/* 860B8 800ECC08 4481B000 */  mtc1      $at, $f22
/* 860BC 800ECC0C 3C128011 */  lui       $s2, %hi(D_8010CFBC)
/* 860C0 800ECC10 2652CFBC */  addiu     $s2, $s2, %lo(D_8010CFBC)
/* 860C4 800ECC14 3C148011 */  lui       $s4, %hi(D_8010CD38)
/* 860C8 800ECC18 2694CD38 */  addiu     $s4, $s4, %lo(D_8010CD38)
.L800ECC1C:
/* 860CC 800ECC1C 82020000 */  lb        $v0, ($s0)
/* 860D0 800ECC20 104001AE */  beqz      $v0, .L800ED2DC
/* 860D4 800ECC24 24020001 */   addiu    $v0, $zero, 1
/* 860D8 800ECC28 C62C0038 */  lwc1      $f12, 0x38($s1)
/* 860DC 800ECC2C C62E0040 */  lwc1      $f14, 0x40($s1)
/* 860E0 800ECC30 8FA60020 */  lw        $a2, 0x20($sp)
/* 860E4 800ECC34 0C00A720 */  jal       atan2
/* 860E8 800ECC38 8FA70024 */   lw       $a3, 0x24($sp)
/* 860EC 800ECC3C C62C0038 */  lwc1      $f12, 0x38($s1)
/* 860F0 800ECC40 C62E0040 */  lwc1      $f14, 0x40($s1)
/* 860F4 800ECC44 8E660028 */  lw        $a2, 0x28($s3)
/* 860F8 800ECC48 8E670030 */  lw        $a3, 0x30($s3)
/* 860FC 800ECC4C 0C00A720 */  jal       atan2
/* 86100 800ECC50 46000506 */   mov.s    $f20, $f0
/* 86104 800ECC54 4600A306 */  mov.s     $f12, $f20
/* 86108 800ECC58 0C00A70A */  jal       get_clamped_angle_diff
/* 8610C 800ECC5C 46000386 */   mov.s    $f14, $f0
/* 86110 800ECC60 46000005 */  abs.s     $f0, $f0
/* 86114 800ECC64 4616003C */  c.lt.s    $f0, $f22
/* 86118 800ECC68 00000000 */  nop
/* 8611C 800ECC6C 4501019B */  bc1t      .L800ED2DC
/* 86120 800ECC70 24020001 */   addiu    $v0, $zero, 1
/* 86124 800ECC74 8E430000 */  lw        $v1, ($s2)
/* 86128 800ECC78 3C028011 */  lui       $v0, %hi(D_8010CFB8)
/* 8612C 800ECC7C 8C42CFB8 */  lw        $v0, %lo(D_8010CFB8)($v0)
/* 86130 800ECC80 1062000D */  beq       $v1, $v0, .L800ECCB8
/* 86134 800ECC84 24620001 */   addiu    $v0, $v1, 1
/* 86138 800ECC88 AE420000 */  sw        $v0, ($s2)
/* 8613C 800ECC8C 28420028 */  slti      $v0, $v0, 0x28
/* 86140 800ECC90 50400001 */  beql      $v0, $zero, .L800ECC98
/* 86144 800ECC94 AE400000 */   sw       $zero, ($s2)
.L800ECC98:
/* 86148 800ECC98 8E420000 */  lw        $v0, ($s2)
/* 8614C 800ECC9C 00021100 */  sll       $v0, $v0, 4
/* 86150 800ECCA0 00548021 */  addu      $s0, $v0, $s4
/* 86154 800ECCA4 C6000004 */  lwc1      $f0, 4($s0)
/* 86158 800ECCA8 C602000C */  lwc1      $f2, 0xc($s0)
/* 8615C 800ECCAC E7A00020 */  swc1      $f0, 0x20($sp)
/* 86160 800ECCB0 0803B307 */  j         .L800ECC1C
/* 86164 800ECCB4 E7A20024 */   swc1     $f2, 0x24($sp)
.L800ECCB8:
/* 86168 800ECCB8 0803B4B7 */  j         .L800ED2DC
/* 8616C 800ECCBC 24020001 */   addiu    $v0, $zero, 1
glabel L800ECCC0_86170
/* 86170 800ECCC0 3C048011 */  lui       $a0, %hi(D_8010CFCE)
/* 86174 800ECCC4 2484CFCE */  addiu     $a0, $a0, %lo(D_8010CFCE)
/* 86178 800ECCC8 84830000 */  lh        $v1, ($a0)
/* 8617C 800ECCCC 24020001 */  addiu     $v0, $zero, 1
/* 86180 800ECCD0 10620050 */  beq       $v1, $v0, .L800ECE14
/* 86184 800ECCD4 28620002 */   slti     $v0, $v1, 2
/* 86188 800ECCD8 50400005 */  beql      $v0, $zero, .L800ECCF0
/* 8618C 800ECCDC 24020002 */   addiu    $v0, $zero, 2
/* 86190 800ECCE0 10600007 */  beqz      $v1, .L800ECD00
/* 86194 800ECCE4 00000000 */   nop
/* 86198 800ECCE8 0803B4B9 */  j         L800ED2E4_86794
/* 8619C 800ECCEC 00000000 */   nop
.L800ECCF0:
/* 861A0 800ECCF0 106200E2 */  beq       $v1, $v0, .L800ED07C
/* 861A4 800ECCF4 00000000 */   nop
/* 861A8 800ECCF8 0803B4B9 */  j         L800ED2E4_86794
/* 861AC 800ECCFC 00000000 */   nop
.L800ECD00:
/* 861B0 800ECD00 0C0394D2 */  jal       func_800E5348
/* 861B4 800ECD04 00000000 */   nop
/* 861B8 800ECD08 3C014334 */  lui       $at, 0x4334
/* 861BC 800ECD0C 44816000 */  mtc1      $at, $f12
/* 861C0 800ECD10 0C00A6C9 */  jal       clamp_angle
/* 861C4 800ECD14 460C0300 */   add.s    $f12, $f0, $f12
/* 861C8 800ECD18 C6620028 */  lwc1      $f2, 0x28($s3)
/* 861CC 800ECD1C E6220060 */  swc1      $f2, 0x60($s1)
/* 861D0 800ECD20 C662002C */  lwc1      $f2, 0x2c($s3)
/* 861D4 800ECD24 E6220064 */  swc1      $f2, 0x64($s1)
/* 861D8 800ECD28 C6620030 */  lwc1      $f2, 0x30($s3)
/* 861DC 800ECD2C 26240060 */  addiu     $a0, $s1, 0x60
/* 861E0 800ECD30 E6220068 */  swc1      $f2, 0x68($s1)
/* 861E4 800ECD34 866200B2 */  lh        $v0, 0xb2($s3)
/* 861E8 800ECD38 44070000 */  mfc1      $a3, $f0
/* 861EC 800ECD3C 44825000 */  mtc1      $v0, $f10
/* 861F0 800ECD40 00000000 */  nop
/* 861F4 800ECD44 468052A0 */  cvt.s.w   $f10, $f10
/* 861F8 800ECD48 44065000 */  mfc1      $a2, $f10
/* 861FC 800ECD4C 0C00A7E7 */  jal       add_vec2D_polar
/* 86200 800ECD50 26250068 */   addiu    $a1, $s1, 0x68
/* 86204 800ECD54 C62C0038 */  lwc1      $f12, 0x38($s1)
/* 86208 800ECD58 C62E0040 */  lwc1      $f14, 0x40($s1)
/* 8620C 800ECD5C 8E260060 */  lw        $a2, 0x60($s1)
/* 86210 800ECD60 0C00A7B5 */  jal       dist2D
/* 86214 800ECD64 8E270068 */   lw       $a3, 0x68($s1)
/* 86218 800ECD68 3C018010 */  lui       $at, %hi(D_800F802C)
/* 8621C 800ECD6C C422802C */  lwc1      $f2, %lo(D_800F802C)($at)
/* 86220 800ECD70 468010A0 */  cvt.s.w   $f2, $f2
/* 86224 800ECD74 E7A00034 */  swc1      $f0, 0x34($sp)
/* 86228 800ECD78 46020003 */  div.s     $f0, $f0, $f2
/* 8622C 800ECD7C 3C018010 */  lui       $at, %hi(D_800F8030)
/* 86230 800ECD80 E4208030 */  swc1      $f0, %lo(D_800F8030)($at)
/* 86234 800ECD84 E6200018 */  swc1      $f0, 0x18($s1)
/* 86238 800ECD88 46000021 */  cvt.d.s   $f0, $f0
/* 8623C 800ECD8C 26240028 */  addiu     $a0, $s1, 0x28
/* 86240 800ECD90 3C038011 */  lui       $v1, %hi(D_8010CFD8)
/* 86244 800ECD94 8C63CFD8 */  lw        $v1, %lo(D_8010CFD8)($v1)
/* 86248 800ECD98 3C014010 */  lui       $at, 0x4010
/* 8624C 800ECD9C 44811800 */  mtc1      $at, $f3
/* 86250 800ECDA0 44801000 */  mtc1      $zero, $f2
/* 86254 800ECDA4 000310C0 */  sll       $v0, $v1, 3
/* 86258 800ECDA8 00431021 */  addu      $v0, $v0, $v1
/* 8625C 800ECDAC 4620103E */  c.le.d    $f2, $f0
/* 86260 800ECDB0 00000000 */  nop
/* 86264 800ECDB4 45000003 */  bc1f      .L800ECDC4
/* 86268 800ECDB8 00021080 */   sll      $v0, $v0, 2
/* 8626C 800ECDBC 0803B372 */  j         .L800ECDC8
/* 86270 800ECDC0 24430018 */   addiu    $v1, $v0, 0x18
.L800ECDC4:
/* 86274 800ECDC4 24430004 */  addiu     $v1, $v0, 4
.L800ECDC8:
/* 86278 800ECDC8 3C028010 */  lui       $v0, %hi(gPartnerAnimations)
/* 8627C 800ECDCC 24428348 */  addiu     $v0, $v0, %lo(gPartnerAnimations)
/* 86280 800ECDD0 00431021 */  addu      $v0, $v0, $v1
/* 86284 800ECDD4 8C420000 */  lw        $v0, ($v0)
/* 86288 800ECDD8 AC820000 */  sw        $v0, ($a0)
/* 8628C 800ECDDC C62C0038 */  lwc1      $f12, 0x38($s1)
/* 86290 800ECDE0 C62E0040 */  lwc1      $f14, 0x40($s1)
/* 86294 800ECDE4 8E260060 */  lw        $a2, 0x60($s1)
/* 86298 800ECDE8 0C00A720 */  jal       atan2
/* 8629C 800ECDEC 8E270068 */   lw       $a3, 0x68($s1)
/* 862A0 800ECDF0 3C038011 */  lui       $v1, %hi(D_8010CFCE)
/* 862A4 800ECDF4 2463CFCE */  addiu     $v1, $v1, %lo(D_8010CFCE)
/* 862A8 800ECDF8 94620000 */  lhu       $v0, ($v1)
/* 862AC 800ECDFC 46000506 */  mov.s     $f20, $f0
/* 862B0 800ECE00 3C018010 */  lui       $at, %hi(D_800F8034)
/* 862B4 800ECE04 E4348034 */  swc1      $f20, %lo(D_800F8034)($at)
/* 862B8 800ECE08 E634000C */  swc1      $f20, 0xc($s1)
/* 862BC 800ECE0C 24420001 */  addiu     $v0, $v0, 1
/* 862C0 800ECE10 A4620000 */  sh        $v0, ($v1)
.L800ECE14:
/* 862C4 800ECE14 3C108010 */  lui       $s0, %hi(D_800F802C)
/* 862C8 800ECE18 2610802C */  addiu     $s0, $s0, %lo(D_800F802C)
/* 862CC 800ECE1C 8E020000 */  lw        $v0, ($s0)
/* 862D0 800ECE20 10400079 */  beqz      $v0, .L800ED008
/* 862D4 800ECE24 2442FFFF */   addiu    $v0, $v0, -1
/* 862D8 800ECE28 C6220014 */  lwc1      $f2, 0x14($s1)
/* 862DC 800ECE2C 44803000 */  mtc1      $zero, $f6
/* 862E0 800ECE30 00000000 */  nop
/* 862E4 800ECE34 46061032 */  c.eq.s    $f2, $f6
/* 862E8 800ECE38 00000000 */  nop
/* 862EC 800ECE3C 4501005A */  bc1t      .L800ECFA8
/* 862F0 800ECE40 AE020000 */   sw       $v0, ($s0)
/* 862F4 800ECE44 C620001C */  lwc1      $f0, 0x1c($s1)
/* 862F8 800ECE48 46020001 */  sub.s     $f0, $f0, $f2
/* 862FC 800ECE4C C622003C */  lwc1      $f2, 0x3c($s1)
/* 86300 800ECE50 46001080 */  add.s     $f2, $f2, $f0
/* 86304 800ECE54 E620001C */  swc1      $f0, 0x1c($s1)
/* 86308 800ECE58 4606003E */  c.le.s    $f0, $f6
/* 8630C 800ECE5C 00000000 */  nop
/* 86310 800ECE60 4500000A */  bc1f      .L800ECE8C
/* 86314 800ECE64 E622003C */   swc1     $f2, 0x3c($s1)
/* 86318 800ECE68 3C028011 */  lui       $v0, %hi(D_8010CFD8)
/* 8631C 800ECE6C 8C42CFD8 */  lw        $v0, %lo(D_8010CFD8)($v0)
/* 86320 800ECE70 000218C0 */  sll       $v1, $v0, 3
/* 86324 800ECE74 00621821 */  addu      $v1, $v1, $v0
/* 86328 800ECE78 00031880 */  sll       $v1, $v1, 2
/* 8632C 800ECE7C 3C028010 */  lui       $v0, %hi(gPartnerAnimations+0xC)
/* 86330 800ECE80 00431021 */  addu      $v0, $v0, $v1
/* 86334 800ECE84 8C428354 */  lw        $v0, %lo(gPartnerAnimations+0xC)($v0)
/* 86338 800ECE88 AE220028 */  sw        $v0, 0x28($s1)
.L800ECE8C:
/* 8633C 800ECE8C C624001C */  lwc1      $f4, 0x1c($s1)
/* 86340 800ECE90 4606203E */  c.le.s    $f4, $f6
/* 86344 800ECE94 00000000 */  nop
/* 86348 800ECE98 45000043 */  bc1f      .L800ECFA8
/* 8634C 800ECE9C 27A20034 */   addiu    $v0, $sp, 0x34
/* 86350 800ECEA0 C6200038 */  lwc1      $f0, 0x38($s1)
/* 86354 800ECEA4 3C014130 */  lui       $at, 0x4130
/* 86358 800ECEA8 44811000 */  mtc1      $at, $f2
/* 8635C 800ECEAC E7A00028 */  swc1      $f0, 0x28($sp)
/* 86360 800ECEB0 46002005 */  abs.s     $f0, $f4
/* 86364 800ECEB4 46020000 */  add.s     $f0, $f0, $f2
/* 86368 800ECEB8 C622003C */  lwc1      $f2, 0x3c($s1)
/* 8636C 800ECEBC C6240040 */  lwc1      $f4, 0x40($s1)
/* 86370 800ECEC0 46001080 */  add.s     $f2, $f2, $f0
/* 86374 800ECEC4 E7A40030 */  swc1      $f4, 0x30($sp)
/* 86378 800ECEC8 E7A00034 */  swc1      $f0, 0x34($sp)
/* 8637C 800ECECC E7A2002C */  swc1      $f2, 0x2c($sp)
/* 86380 800ECED0 AFA20010 */  sw        $v0, 0x10($sp)
/* 86384 800ECED4 C620000C */  lwc1      $f0, 0xc($s1)
/* 86388 800ECED8 27A50028 */  addiu     $a1, $sp, 0x28
/* 8638C 800ECEDC E7A00014 */  swc1      $f0, 0x14($sp)
/* 86390 800ECEE0 862200A6 */  lh        $v0, 0xa6($s1)
/* 86394 800ECEE4 27A6002C */  addiu     $a2, $sp, 0x2c
/* 86398 800ECEE8 44820000 */  mtc1      $v0, $f0
/* 8639C 800ECEEC 00000000 */  nop
/* 863A0 800ECEF0 46800020 */  cvt.s.w   $f0, $f0
/* 863A4 800ECEF4 E7A00018 */  swc1      $f0, 0x18($sp)
/* 863A8 800ECEF8 8E240080 */  lw        $a0, 0x80($s1)
/* 863AC 800ECEFC 0C0371DE */  jal       npc_raycast_down_ahead
/* 863B0 800ECF00 27A70030 */   addiu    $a3, $sp, 0x30
/* 863B4 800ECF04 10400028 */  beqz      $v0, .L800ECFA8
/* 863B8 800ECF08 00000000 */   nop
/* 863BC 800ECF0C C620001C */  lwc1      $f0, 0x1c($s1)
/* 863C0 800ECF10 3C0141B0 */  lui       $at, 0x41b0
/* 863C4 800ECF14 44811000 */  mtc1      $at, $f2
/* 863C8 800ECF18 46000005 */  abs.s     $f0, $f0
/* 863CC 800ECF1C 46020000 */  add.s     $f0, $f0, $f2
/* 863D0 800ECF20 C7A20034 */  lwc1      $f2, 0x34($sp)
/* 863D4 800ECF24 4600103E */  c.le.s    $f2, $f0
/* 863D8 800ECF28 00000000 */  nop
/* 863DC 800ECF2C 4500001E */  bc1f      .L800ECFA8
/* 863E0 800ECF30 26240028 */   addiu    $a0, $s1, 0x28
/* 863E4 800ECF34 C6200018 */  lwc1      $f0, 0x18($s1)
/* 863E8 800ECF38 3C014010 */  lui       $at, 0x4010
/* 863EC 800ECF3C 44811800 */  mtc1      $at, $f3
/* 863F0 800ECF40 44801000 */  mtc1      $zero, $f2
/* 863F4 800ECF44 3C038011 */  lui       $v1, %hi(D_8010CFD8)
/* 863F8 800ECF48 8C63CFD8 */  lw        $v1, %lo(D_8010CFD8)($v1)
/* 863FC 800ECF4C 46000021 */  cvt.d.s   $f0, $f0
/* 86400 800ECF50 000310C0 */  sll       $v0, $v1, 3
/* 86404 800ECF54 00431021 */  addu      $v0, $v0, $v1
/* 86408 800ECF58 4620103E */  c.le.d    $f2, $f0
/* 8640C 800ECF5C 00000000 */  nop
/* 86410 800ECF60 45000003 */  bc1f      .L800ECF70
/* 86414 800ECF64 00021080 */   sll      $v0, $v0, 2
/* 86418 800ECF68 0803B3DD */  j         .L800ECF74
/* 8641C 800ECF6C 24430018 */   addiu    $v1, $v0, 0x18
.L800ECF70:
/* 86420 800ECF70 24430004 */  addiu     $v1, $v0, 4
.L800ECF74:
/* 86424 800ECF74 3C028010 */  lui       $v0, %hi(gPartnerAnimations)
/* 86428 800ECF78 24428348 */  addiu     $v0, $v0, %lo(gPartnerAnimations)
/* 8642C 800ECF7C 00431021 */  addu      $v0, $v0, $v1
/* 86430 800ECF80 8C420000 */  lw        $v0, ($v0)
/* 86434 800ECF84 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* 86438 800ECF88 AC820000 */  sw        $v0, ($a0)
/* 8643C 800ECF8C 8E220000 */  lw        $v0, ($s1)
/* 86440 800ECF90 2403F7FF */  addiu     $v1, $zero, -0x801
/* 86444 800ECF94 AE200014 */  sw        $zero, 0x14($s1)
/* 86448 800ECF98 AE20001C */  sw        $zero, 0x1c($s1)
/* 8644C 800ECF9C E620003C */  swc1      $f0, 0x3c($s1)
/* 86450 800ECFA0 00431024 */  and       $v0, $v0, $v1
/* 86454 800ECFA4 AE220000 */  sw        $v0, ($s1)
.L800ECFA8:
/* 86458 800ECFA8 3C018010 */  lui       $at, %hi(D_800F8030)
/* 8645C 800ECFAC C4208030 */  lwc1      $f0, %lo(D_800F8030)($at)
/* 86460 800ECFB0 E6200018 */  swc1      $f0, 0x18($s1)
/* 86464 800ECFB4 3C018010 */  lui       $at, %hi(D_800F8034)
/* 86468 800ECFB8 C4208034 */  lwc1      $f0, %lo(D_800F8034)($at)
/* 8646C 800ECFBC 8E250018 */  lw        $a1, 0x18($s1)
/* 86470 800ECFC0 44060000 */  mfc1      $a2, $f0
/* 86474 800ECFC4 0220202D */  daddu     $a0, $s1, $zero
/* 86478 800ECFC8 0C00EA95 */  jal       npc_move_heading
/* 8647C 800ECFCC AE26000C */   sw       $a2, 0xc($s1)
/* 86480 800ECFD0 C6200018 */  lwc1      $f0, 0x18($s1)
/* 86484 800ECFD4 3C014010 */  lui       $at, 0x4010
/* 86488 800ECFD8 44811800 */  mtc1      $at, $f3
/* 8648C 800ECFDC 44801000 */  mtc1      $zero, $f2
/* 86490 800ECFE0 46000021 */  cvt.d.s   $f0, $f0
/* 86494 800ECFE4 4622003C */  c.lt.d    $f0, $f2
/* 86498 800ECFE8 00000000 */  nop
/* 8649C 800ECFEC 45000002 */  bc1f      .L800ECFF8
/* 864A0 800ECFF0 24050001 */   addiu    $a1, $zero, 1
/* 864A4 800ECFF4 0000282D */  daddu     $a1, $zero, $zero
.L800ECFF8:
/* 864A8 800ECFF8 0C00F598 */  jal       func_8003D660
/* 864AC 800ECFFC 0220202D */   daddu    $a0, $s1, $zero
/* 864B0 800ED000 0803B4B9 */  j         L800ED2E4_86794
/* 864B4 800ED004 00000000 */   nop
.L800ED008:
/* 864B8 800ED008 0C03BD17 */  jal       partner_clear_player_tracking
/* 864BC 800ED00C 0220202D */   daddu    $a0, $s1, $zero
/* 864C0 800ED010 3C038011 */  lui       $v1, %hi(D_8010CFD8)
/* 864C4 800ED014 8C63CFD8 */  lw        $v1, %lo(D_8010CFD8)($v1)
/* 864C8 800ED018 3C014387 */  lui       $at, 0x4387
/* 864CC 800ED01C 44810000 */  mtc1      $at, $f0
/* 864D0 800ED020 AE200018 */  sw        $zero, 0x18($s1)
/* 864D4 800ED024 AE200014 */  sw        $zero, 0x14($s1)
/* 864D8 800ED028 000310C0 */  sll       $v0, $v1, 3
/* 864DC 800ED02C 00431021 */  addu      $v0, $v0, $v1
/* 864E0 800ED030 00021080 */  sll       $v0, $v0, 2
/* 864E4 800ED034 3C018010 */  lui       $at, %hi(gPartnerAnimations+0x14)
/* 864E8 800ED038 00220821 */  addu      $at, $at, $v0
/* 864EC 800ED03C 8C22835C */  lw        $v0, %lo(gPartnerAnimations+0x14)($at)
/* 864F0 800ED040 AE220028 */  sw        $v0, 0x28($s1)
/* 864F4 800ED044 C6AC006C */  lwc1      $f12, 0x6c($s5)
/* 864F8 800ED048 46006300 */  add.s     $f12, $f12, $f0
/* 864FC 800ED04C C66000A8 */  lwc1      $f0, 0xa8($s3)
/* 86500 800ED050 0C00A6C9 */  jal       clamp_angle
/* 86504 800ED054 46006301 */   sub.s    $f12, $f12, $f0
/* 86508 800ED058 3C048011 */  lui       $a0, %hi(D_8010CFCE)
/* 8650C 800ED05C 2484CFCE */  addiu     $a0, $a0, %lo(D_8010CFCE)
/* 86510 800ED060 E620000C */  swc1      $f0, 0xc($s1)
/* 86514 800ED064 94820000 */  lhu       $v0, ($a0)
/* 86518 800ED068 2403001E */  addiu     $v1, $zero, 0x1e
/* 8651C 800ED06C AE030000 */  sw        $v1, ($s0)
/* 86520 800ED070 24420001 */  addiu     $v0, $v0, 1
/* 86524 800ED074 0803B4B9 */  j         L800ED2E4_86794
/* 86528 800ED078 A4820000 */   sh       $v0, ($a0)
.L800ED07C:
/* 8652C 800ED07C 3C038010 */  lui       $v1, %hi(D_800F802C)
/* 86530 800ED080 2463802C */  addiu     $v1, $v1, %lo(D_800F802C)
/* 86534 800ED084 8C620000 */  lw        $v0, ($v1)
/* 86538 800ED088 10400003 */  beqz      $v0, .L800ED098
/* 8653C 800ED08C 2442FFFF */   addiu    $v0, $v0, -1
/* 86540 800ED090 0803B4B9 */  j         L800ED2E4_86794
/* 86544 800ED094 AC620000 */   sw       $v0, ($v1)
.L800ED098:
/* 86548 800ED098 3C018011 */  lui       $at, %hi(D_8010CFC8)
/* 8654C 800ED09C A420CFC8 */  sh        $zero, %lo(D_8010CFC8)($at)
/* 86550 800ED0A0 3C018011 */  lui       $at, %hi(D_8010CFCA)
/* 86554 800ED0A4 A420CFCA */  sh        $zero, %lo(D_8010CFCA)($at)
.L800ED0A8:
/* 86558 800ED0A8 0803B4B9 */  j         L800ED2E4_86794
/* 8655C 800ED0AC A4800000 */   sh       $zero, ($a0)
glabel L800ED0B0_86560
/* 86560 800ED0B0 0220202D */  daddu     $a0, $s1, $zero
/* 86564 800ED0B4 0C03BE0B */  jal       partner_move_to_goal
/* 86568 800ED0B8 0000282D */   daddu    $a1, $zero, $zero
/* 8656C 800ED0BC 0803B4B9 */  j         L800ED2E4_86794
/* 86570 800ED0C0 00000000 */   nop
glabel L800ED0C4_86574
/* 86574 800ED0C4 8E220000 */  lw        $v0, ($s1)
/* 86578 800ED0C8 30421000 */  andi      $v0, $v0, 0x1000
/* 8657C 800ED0CC 10400012 */  beqz      $v0, .L800ED118
/* 86580 800ED0D0 00000000 */   nop
/* 86584 800ED0D4 0C03A92C */  jal       func_800EA4B0
/* 86588 800ED0D8 86240084 */   lh       $a0, 0x84($s1)
/* 8658C 800ED0DC 1040007F */  beqz      $v0, .L800ED2DC
/* 86590 800ED0E0 24020001 */   addiu    $v0, $zero, 1
/* 86594 800ED0E4 3C038011 */  lui       $v1, %hi(D_8010CFD8)
/* 86598 800ED0E8 8C63CFD8 */  lw        $v1, %lo(D_8010CFD8)($v1)
/* 8659C 800ED0EC 000310C0 */  sll       $v0, $v1, 3
/* 865A0 800ED0F0 00431021 */  addu      $v0, $v0, $v1
/* 865A4 800ED0F4 00021080 */  sll       $v0, $v0, 2
/* 865A8 800ED0F8 3C038010 */  lui       $v1, %hi(gPartnerAnimations+0x14)
/* 865AC 800ED0FC 00621821 */  addu      $v1, $v1, $v0
/* 865B0 800ED100 8C63835C */  lw        $v1, %lo(gPartnerAnimations+0x14)($v1)
/* 865B4 800ED104 24020032 */  addiu     $v0, $zero, 0x32
/* 865B8 800ED108 3C018011 */  lui       $at, %hi(D_8010CFC8)
/* 865BC 800ED10C A422CFC8 */  sh        $v0, %lo(D_8010CFC8)($at)
/* 865C0 800ED110 0803B4B9 */  j         L800ED2E4_86794
/* 865C4 800ED114 AE230028 */   sw       $v1, 0x28($s1)
.L800ED118:
/* 865C8 800ED118 3C014040 */  lui       $at, 0x4040
/* 865CC 800ED11C 44812000 */  mtc1      $at, $f4
/* 865D0 800ED120 C620001C */  lwc1      $f0, 0x1c($s1)
/* 865D4 800ED124 46040001 */  sub.s     $f0, $f0, $f4
/* 865D8 800ED128 C622003C */  lwc1      $f2, 0x3c($s1)
/* 865DC 800ED12C 4480A000 */  mtc1      $zero, $f20
/* 865E0 800ED130 46001080 */  add.s     $f2, $f2, $f0
/* 865E4 800ED134 E6240014 */  swc1      $f4, 0x14($s1)
/* 865E8 800ED138 4614003E */  c.le.s    $f0, $f20
/* 865EC 800ED13C E620001C */  swc1      $f0, 0x1c($s1)
/* 865F0 800ED140 4500000A */  bc1f      .L800ED16C
/* 865F4 800ED144 E622003C */   swc1     $f2, 0x3c($s1)
/* 865F8 800ED148 3C028011 */  lui       $v0, %hi(D_8010CFD8)
/* 865FC 800ED14C 8C42CFD8 */  lw        $v0, %lo(D_8010CFD8)($v0)
/* 86600 800ED150 000218C0 */  sll       $v1, $v0, 3
/* 86604 800ED154 00621821 */  addu      $v1, $v1, $v0
/* 86608 800ED158 00031880 */  sll       $v1, $v1, 2
/* 8660C 800ED15C 3C028010 */  lui       $v0, %hi(gPartnerAnimations+0xC)
/* 86610 800ED160 00431021 */  addu      $v0, $v0, $v1
/* 86614 800ED164 8C428354 */  lw        $v0, %lo(gPartnerAnimations+0xC)($v0)
/* 86618 800ED168 AE220028 */  sw        $v0, 0x28($s1)
.L800ED16C:
/* 8661C 800ED16C C622003C */  lwc1      $f2, 0x3c($s1)
/* 86620 800ED170 3C01C4FA */  lui       $at, 0xc4fa
/* 86624 800ED174 44810000 */  mtc1      $at, $f0
/* 86628 800ED178 00000000 */  nop
/* 8662C 800ED17C 4600103C */  c.lt.s    $f2, $f0
/* 86630 800ED180 00000000 */  nop
/* 86634 800ED184 4500001E */  bc1f      .L800ED200
/* 86638 800ED188 2404F7FF */   addiu    $a0, $zero, -0x801
/* 8663C 800ED18C C62C0038 */  lwc1      $f12, 0x38($s1)
/* 86640 800ED190 3C028011 */  lui       $v0, %hi(D_8010CFD8)
/* 86644 800ED194 8C42CFD8 */  lw        $v0, %lo(D_8010CFD8)($v0)
/* 86648 800ED198 C62E0040 */  lwc1      $f14, 0x40($s1)
/* 8664C 800ED19C 000218C0 */  sll       $v1, $v0, 3
/* 86650 800ED1A0 00621821 */  addu      $v1, $v1, $v0
/* 86654 800ED1A4 00031880 */  sll       $v1, $v1, 2
/* 86658 800ED1A8 8E220000 */  lw        $v0, ($s1)
/* 8665C 800ED1AC 3C018010 */  lui       $at, %hi(gPartnerAnimations+0x14)
/* 86660 800ED1B0 00230821 */  addu      $at, $at, $v1
/* 86664 800ED1B4 8C23835C */  lw        $v1, %lo(gPartnerAnimations+0x14)($at)
/* 86668 800ED1B8 E634001C */  swc1      $f20, 0x1c($s1)
/* 8666C 800ED1BC 00441024 */  and       $v0, $v0, $a0
/* 86670 800ED1C0 AE220000 */  sw        $v0, ($s1)
/* 86674 800ED1C4 AE230028 */  sw        $v1, 0x28($s1)
/* 86678 800ED1C8 8E660028 */  lw        $a2, 0x28($s3)
/* 8667C 800ED1CC 0C00A720 */  jal       atan2
/* 86680 800ED1D0 8E670030 */   lw       $a3, 0x30($s3)
/* 86684 800ED1D4 E620000C */  swc1      $f0, 0xc($s1)
/* 86688 800ED1D8 C6600028 */  lwc1      $f0, 0x28($s3)
/* 8668C 800ED1DC E6200038 */  swc1      $f0, 0x38($s1)
/* 86690 800ED1E0 C660002C */  lwc1      $f0, 0x2c($s3)
/* 86694 800ED1E4 E620003C */  swc1      $f0, 0x3c($s1)
/* 86698 800ED1E8 C6600030 */  lwc1      $f0, 0x30($s3)
/* 8669C 800ED1EC 24020032 */  addiu     $v0, $zero, 0x32
.L800ED1F0:
/* 866A0 800ED1F0 3C018011 */  lui       $at, %hi(D_8010CFC8)
/* 866A4 800ED1F4 A422CFC8 */  sh        $v0, %lo(D_8010CFC8)($at)
/* 866A8 800ED1F8 0803B4B9 */  j         L800ED2E4_86794
/* 866AC 800ED1FC E6200040 */   swc1     $f0, 0x40($s1)
.L800ED200:
/* 866B0 800ED200 C6200038 */  lwc1      $f0, 0x38($s1)
/* 866B4 800ED204 27A20034 */  addiu     $v0, $sp, 0x34
/* 866B8 800ED208 E7A00028 */  swc1      $f0, 0x28($sp)
/* 866BC 800ED20C C620001C */  lwc1      $f0, 0x1c($s1)
/* 866C0 800ED210 3C014130 */  lui       $at, 0x4130
/* 866C4 800ED214 44811000 */  mtc1      $at, $f2
/* 866C8 800ED218 46000005 */  abs.s     $f0, $f0
/* 866CC 800ED21C 46020000 */  add.s     $f0, $f0, $f2
/* 866D0 800ED220 C622003C */  lwc1      $f2, 0x3c($s1)
/* 866D4 800ED224 C6240040 */  lwc1      $f4, 0x40($s1)
/* 866D8 800ED228 46001080 */  add.s     $f2, $f2, $f0
/* 866DC 800ED22C E7A40030 */  swc1      $f4, 0x30($sp)
/* 866E0 800ED230 E7A00034 */  swc1      $f0, 0x34($sp)
/* 866E4 800ED234 E7A2002C */  swc1      $f2, 0x2c($sp)
/* 866E8 800ED238 AFA20010 */  sw        $v0, 0x10($sp)
/* 866EC 800ED23C C620000C */  lwc1      $f0, 0xc($s1)
/* 866F0 800ED240 27A50028 */  addiu     $a1, $sp, 0x28
/* 866F4 800ED244 E7A00014 */  swc1      $f0, 0x14($sp)
/* 866F8 800ED248 862200A6 */  lh        $v0, 0xa6($s1)
/* 866FC 800ED24C 27A6002C */  addiu     $a2, $sp, 0x2c
/* 86700 800ED250 44820000 */  mtc1      $v0, $f0
/* 86704 800ED254 00000000 */  nop
/* 86708 800ED258 46800020 */  cvt.s.w   $f0, $f0
/* 8670C 800ED25C E7A00018 */  swc1      $f0, 0x18($sp)
/* 86710 800ED260 8E240080 */  lw        $a0, 0x80($s1)
/* 86714 800ED264 0C0371DE */  jal       npc_raycast_down_ahead
/* 86718 800ED268 27A70030 */   addiu    $a3, $sp, 0x30
/* 8671C 800ED26C 1040001D */  beqz      $v0, L800ED2E4_86794
/* 86720 800ED270 00000000 */   nop
/* 86724 800ED274 C7AC0028 */  lwc1      $f12, 0x28($sp)
/* 86728 800ED278 3C038011 */  lui       $v1, %hi(D_8010CFD8)
/* 8672C 800ED27C 8C63CFD8 */  lw        $v1, %lo(D_8010CFD8)($v1)
/* 86730 800ED280 C7AE0030 */  lwc1      $f14, 0x30($sp)
/* 86734 800ED284 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* 86738 800ED288 000310C0 */  sll       $v0, $v1, 3
/* 8673C 800ED28C 00431021 */  addu      $v0, $v0, $v1
/* 86740 800ED290 00021080 */  sll       $v0, $v0, 2
/* 86744 800ED294 3C048010 */  lui       $a0, %hi(gPartnerAnimations+0x14)
/* 86748 800ED298 00822021 */  addu      $a0, $a0, $v0
/* 8674C 800ED29C 8C84835C */  lw        $a0, %lo(gPartnerAnimations+0x14)($a0)
/* 86750 800ED2A0 8E220000 */  lw        $v0, ($s1)
/* 86754 800ED2A4 2403F7FF */  addiu     $v1, $zero, -0x801
/* 86758 800ED2A8 E634001C */  swc1      $f20, 0x1c($s1)
/* 8675C 800ED2AC E620003C */  swc1      $f0, 0x3c($s1)
/* 86760 800ED2B0 00431024 */  and       $v0, $v0, $v1
/* 86764 800ED2B4 AE220000 */  sw        $v0, ($s1)
/* 86768 800ED2B8 AE240028 */  sw        $a0, 0x28($s1)
/* 8676C 800ED2BC 8E660028 */  lw        $a2, 0x28($s3)
/* 86770 800ED2C0 0C00A720 */  jal       atan2
/* 86774 800ED2C4 8E670030 */   lw       $a3, 0x30($s3)
/* 86778 800ED2C8 0220202D */  daddu     $a0, $s1, $zero
/* 8677C 800ED2CC 24050002 */  addiu     $a1, $zero, 2
/* 86780 800ED2D0 0C00F598 */  jal       func_8003D660
/* 86784 800ED2D4 E480000C */   swc1     $f0, 0xc($a0)
/* 86788 800ED2D8 24020032 */  addiu     $v0, $zero, 0x32
.L800ED2DC:
/* 8678C 800ED2DC 3C018011 */  lui       $at, %hi(D_8010CFC8)
/* 86790 800ED2E0 A422CFC8 */  sh        $v0, %lo(D_8010CFC8)($at)
glabel L800ED2E4_86794
/* 86794 800ED2E4 8FBF0050 */  lw        $ra, 0x50($sp)
/* 86798 800ED2E8 8FB5004C */  lw        $s5, 0x4c($sp)
/* 8679C 800ED2EC 8FB40048 */  lw        $s4, 0x48($sp)
/* 867A0 800ED2F0 8FB30044 */  lw        $s3, 0x44($sp)
/* 867A4 800ED2F4 8FB20040 */  lw        $s2, 0x40($sp)
/* 867A8 800ED2F8 8FB1003C */  lw        $s1, 0x3c($sp)
/* 867AC 800ED2FC 8FB00038 */  lw        $s0, 0x38($sp)
/* 867B0 800ED300 D7B60060 */  ldc1      $f22, 0x60($sp)
/* 867B4 800ED304 D7B40058 */  ldc1      $f20, 0x58($sp)
/* 867B8 800ED308 03E00008 */  jr        $ra
/* 867BC 800ED30C 27BD0068 */   addiu    $sp, $sp, 0x68
