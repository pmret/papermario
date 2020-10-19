.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024025C
/* BBB5DC 8024025C 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* BBB5E0 80240260 AFB1001C */  sw        $s1, 0x1c($sp)
/* BBB5E4 80240264 0080882D */  daddu     $s1, $a0, $zero
/* BBB5E8 80240268 AFB30024 */  sw        $s3, 0x24($sp)
/* BBB5EC 8024026C 3C138015 */  lui       $s3, %hi(D_80151328)
/* BBB5F0 80240270 26731328 */  addiu     $s3, $s3, %lo(D_80151328)
/* BBB5F4 80240274 AFBF0028 */  sw        $ra, 0x28($sp)
/* BBB5F8 80240278 AFB20020 */  sw        $s2, 0x20($sp)
/* BBB5FC 8024027C AFB00018 */  sw        $s0, 0x18($sp)
/* BBB600 80240280 8E30000C */  lw        $s0, 0xc($s1)
/* BBB604 80240284 10A00019 */  beqz      $a1, .L802402EC
/* BBB608 80240288 8E720000 */   lw       $s2, ($s3)
/* BBB60C 8024028C 8E050000 */  lw        $a1, ($s0)
/* BBB610 80240290 0C0B1EAF */  jal       get_variable
/* BBB614 80240294 26100004 */   addiu    $s0, $s0, 4
/* BBB618 80240298 AE220084 */  sw        $v0, 0x84($s1)
/* BBB61C 8024029C 8E050000 */  lw        $a1, ($s0)
/* BBB620 802402A0 26100004 */  addiu     $s0, $s0, 4
/* BBB624 802402A4 0C0B1EAF */  jal       get_variable
/* BBB628 802402A8 0220202D */   daddu    $a0, $s1, $zero
/* BBB62C 802402AC AE220088 */  sw        $v0, 0x88($s1)
/* BBB630 802402B0 8E050000 */  lw        $a1, ($s0)
/* BBB634 802402B4 0C0B1EAF */  jal       get_variable
/* BBB638 802402B8 0220202D */   daddu    $a0, $s1, $zero
/* BBB63C 802402BC AE22008C */  sw        $v0, 0x8c($s1)
/* BBB640 802402C0 924200AC */  lbu       $v0, 0xac($s2)
/* BBB644 802402C4 AE220090 */  sw        $v0, 0x90($s1)
/* BBB648 802402C8 924200AD */  lbu       $v0, 0xad($s2)
/* BBB64C 802402CC AE220094 */  sw        $v0, 0x94($s1)
/* BBB650 802402D0 924200AE */  lbu       $v0, 0xae($s2)
/* BBB654 802402D4 8E630000 */  lw        $v1, ($s3)
/* BBB658 802402D8 AE20009C */  sw        $zero, 0x9c($s1)
/* BBB65C 802402DC AE220098 */  sw        $v0, 0x98($s1)
/* BBB660 802402E0 94620000 */  lhu       $v0, ($v1)
/* BBB664 802402E4 34420001 */  ori       $v0, $v0, 1
/* BBB668 802402E8 A4620000 */  sh        $v0, ($v1)
.L802402EC:
/* BBB66C 802402EC C6200090 */  lwc1      $f0, 0x90($s1)
/* BBB670 802402F0 46800020 */  cvt.s.w   $f0, $f0
/* BBB674 802402F4 44050000 */  mfc1      $a1, $f0
/* BBB678 802402F8 C6200084 */  lwc1      $f0, 0x84($s1)
/* BBB67C 802402FC 46800020 */  cvt.s.w   $f0, $f0
/* BBB680 80240300 8E22009C */  lw        $v0, 0x9c($s1)
/* BBB684 80240304 44060000 */  mfc1      $a2, $f0
/* BBB688 80240308 24420001 */  addiu     $v0, $v0, 1
/* BBB68C 8024030C AE22009C */  sw        $v0, 0x9c($s1)
/* BBB690 80240310 24020014 */  addiu     $v0, $zero, 0x14
/* BBB694 80240314 AFA20010 */  sw        $v0, 0x10($sp)
/* BBB698 80240318 8E27009C */  lw        $a3, 0x9c($s1)
/* BBB69C 8024031C 0C00A8ED */  jal       update_lerp
/* BBB6A0 80240320 0000202D */   daddu    $a0, $zero, $zero
/* BBB6A4 80240324 3C014F00 */  lui       $at, 0x4f00
/* BBB6A8 80240328 44811000 */  mtc1      $at, $f2
/* BBB6AC 8024032C 00000000 */  nop       
/* BBB6B0 80240330 4600103E */  c.le.s    $f2, $f0
/* BBB6B4 80240334 00000000 */  nop       
/* BBB6B8 80240338 45010005 */  bc1t      .L80240350
/* BBB6BC 8024033C 264400AC */   addiu    $a0, $s2, 0xac
/* BBB6C0 80240340 4600010D */  trunc.w.s $f4, $f0
/* BBB6C4 80240344 44032000 */  mfc1      $v1, $f4
/* BBB6C8 80240348 080900DB */  j         .L8024036C
/* BBB6CC 8024034C A0830000 */   sb       $v1, ($a0)
.L80240350:
/* BBB6D0 80240350 46020001 */  sub.s     $f0, $f0, $f2
/* BBB6D4 80240354 3C028000 */  lui       $v0, 0x8000
/* BBB6D8 80240358 4600010D */  trunc.w.s $f4, $f0
/* BBB6DC 8024035C 44032000 */  mfc1      $v1, $f4
/* BBB6E0 80240360 00000000 */  nop       
/* BBB6E4 80240364 00621825 */  or        $v1, $v1, $v0
/* BBB6E8 80240368 A0830000 */  sb        $v1, ($a0)
.L8024036C:
/* BBB6EC 8024036C C6200094 */  lwc1      $f0, 0x94($s1)
/* BBB6F0 80240370 46800020 */  cvt.s.w   $f0, $f0
/* BBB6F4 80240374 44050000 */  mfc1      $a1, $f0
/* BBB6F8 80240378 C6200088 */  lwc1      $f0, 0x88($s1)
/* BBB6FC 8024037C 46800020 */  cvt.s.w   $f0, $f0
/* BBB700 80240380 44060000 */  mfc1      $a2, $f0
/* BBB704 80240384 24020014 */  addiu     $v0, $zero, 0x14
/* BBB708 80240388 AFA20010 */  sw        $v0, 0x10($sp)
/* BBB70C 8024038C 8E27009C */  lw        $a3, 0x9c($s1)
/* BBB710 80240390 0C00A8ED */  jal       update_lerp
/* BBB714 80240394 0000202D */   daddu    $a0, $zero, $zero
/* BBB718 80240398 3C014F00 */  lui       $at, 0x4f00
/* BBB71C 8024039C 44811000 */  mtc1      $at, $f2
/* BBB720 802403A0 00000000 */  nop       
/* BBB724 802403A4 4600103E */  c.le.s    $f2, $f0
/* BBB728 802403A8 00000000 */  nop       
/* BBB72C 802403AC 45010005 */  bc1t      .L802403C4
/* BBB730 802403B0 264400AD */   addiu    $a0, $s2, 0xad
/* BBB734 802403B4 4600010D */  trunc.w.s $f4, $f0
/* BBB738 802403B8 44032000 */  mfc1      $v1, $f4
/* BBB73C 802403BC 080900F8 */  j         .L802403E0
/* BBB740 802403C0 A0830000 */   sb       $v1, ($a0)
.L802403C4:
/* BBB744 802403C4 46020001 */  sub.s     $f0, $f0, $f2
/* BBB748 802403C8 3C028000 */  lui       $v0, 0x8000
/* BBB74C 802403CC 4600010D */  trunc.w.s $f4, $f0
/* BBB750 802403D0 44032000 */  mfc1      $v1, $f4
/* BBB754 802403D4 00000000 */  nop       
/* BBB758 802403D8 00621825 */  or        $v1, $v1, $v0
/* BBB75C 802403DC A0830000 */  sb        $v1, ($a0)
.L802403E0:
/* BBB760 802403E0 C6200098 */  lwc1      $f0, 0x98($s1)
/* BBB764 802403E4 46800020 */  cvt.s.w   $f0, $f0
/* BBB768 802403E8 44050000 */  mfc1      $a1, $f0
/* BBB76C 802403EC C620008C */  lwc1      $f0, 0x8c($s1)
/* BBB770 802403F0 46800020 */  cvt.s.w   $f0, $f0
/* BBB774 802403F4 44060000 */  mfc1      $a2, $f0
/* BBB778 802403F8 24020014 */  addiu     $v0, $zero, 0x14
/* BBB77C 802403FC AFA20010 */  sw        $v0, 0x10($sp)
/* BBB780 80240400 8E27009C */  lw        $a3, 0x9c($s1)
/* BBB784 80240404 0C00A8ED */  jal       update_lerp
/* BBB788 80240408 0000202D */   daddu    $a0, $zero, $zero
/* BBB78C 8024040C 3C014F00 */  lui       $at, 0x4f00
/* BBB790 80240410 44811000 */  mtc1      $at, $f2
/* BBB794 80240414 00000000 */  nop       
/* BBB798 80240418 4600103E */  c.le.s    $f2, $f0
/* BBB79C 8024041C 00000000 */  nop       
/* BBB7A0 80240420 45010005 */  bc1t      .L80240438
/* BBB7A4 80240424 264400AE */   addiu    $a0, $s2, 0xae
/* BBB7A8 80240428 4600010D */  trunc.w.s $f4, $f0
/* BBB7AC 8024042C 44032000 */  mfc1      $v1, $f4
/* BBB7B0 80240430 08090115 */  j         .L80240454
/* BBB7B4 80240434 A0830000 */   sb       $v1, ($a0)
.L80240438:
/* BBB7B8 80240438 46020001 */  sub.s     $f0, $f0, $f2
/* BBB7BC 8024043C 3C028000 */  lui       $v0, 0x8000
/* BBB7C0 80240440 4600010D */  trunc.w.s $f4, $f0
/* BBB7C4 80240444 44032000 */  mfc1      $v1, $f4
/* BBB7C8 80240448 00000000 */  nop       
/* BBB7CC 8024044C 00621825 */  or        $v1, $v1, $v0
/* BBB7D0 80240450 A0830000 */  sb        $v1, ($a0)
.L80240454:
/* BBB7D4 80240454 8E23009C */  lw        $v1, 0x9c($s1)
/* BBB7D8 80240458 24020014 */  addiu     $v0, $zero, 0x14
/* BBB7DC 8024045C 1462000B */  bne       $v1, $v0, .L8024048C
/* BBB7E0 80240460 0000102D */   daddu    $v0, $zero, $zero
/* BBB7E4 80240464 8E230084 */  lw        $v1, 0x84($s1)
/* BBB7E8 80240468 240200FF */  addiu     $v0, $zero, 0xff
/* BBB7EC 8024046C 54620007 */  bnel      $v1, $v0, .L8024048C
/* BBB7F0 80240470 24020002 */   addiu    $v0, $zero, 2
/* BBB7F4 80240474 3C038015 */  lui       $v1, %hi(D_80151328)
/* BBB7F8 80240478 8C631328 */  lw        $v1, %lo(D_80151328)($v1)
/* BBB7FC 8024047C 94620000 */  lhu       $v0, ($v1)
/* BBB800 80240480 3042FFFE */  andi      $v0, $v0, 0xfffe
/* BBB804 80240484 A4620000 */  sh        $v0, ($v1)
/* BBB808 80240488 24020002 */  addiu     $v0, $zero, 2
.L8024048C:
/* BBB80C 8024048C 8FBF0028 */  lw        $ra, 0x28($sp)
/* BBB810 80240490 8FB30024 */  lw        $s3, 0x24($sp)
/* BBB814 80240494 8FB20020 */  lw        $s2, 0x20($sp)
/* BBB818 80240498 8FB1001C */  lw        $s1, 0x1c($sp)
/* BBB81C 8024049C 8FB00018 */  lw        $s0, 0x18($sp)
/* BBB820 802404A0 03E00008 */  jr        $ra
/* BBB824 802404A4 27BD0030 */   addiu    $sp, $sp, 0x30
