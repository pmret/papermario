.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802DE3D8
/* 1014C8 802DE3D8 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 1014CC 802DE3DC 308900FF */  andi      $t1, $a0, 0xff
/* 1014D0 802DE3E0 3C02802E */  lui       $v0, %hi(D_802DFA48)
/* 1014D4 802DE3E4 2442FA48 */  addiu     $v0, $v0, %lo(D_802DFA48)
/* 1014D8 802DE3E8 00091880 */  sll       $v1, $t1, 2
/* 1014DC 802DE3EC 00691821 */  addu      $v1, $v1, $t1
/* 1014E0 802DE3F0 00031880 */  sll       $v1, $v1, 2
/* 1014E4 802DE3F4 00621821 */  addu      $v1, $v1, $v0
/* 1014E8 802DE3F8 2402FFFF */  addiu     $v0, $zero, -1
/* 1014EC 802DE3FC AFBF003C */  sw        $ra, 0x3c($sp)
/* 1014F0 802DE400 AFB60038 */  sw        $s6, 0x38($sp)
/* 1014F4 802DE404 AFB50034 */  sw        $s5, 0x34($sp)
/* 1014F8 802DE408 AFB40030 */  sw        $s4, 0x30($sp)
/* 1014FC 802DE40C AFB3002C */  sw        $s3, 0x2c($sp)
/* 101500 802DE410 AFB20028 */  sw        $s2, 0x28($sp)
/* 101504 802DE414 AFB10024 */  sw        $s1, 0x24($sp)
/* 101508 802DE418 AFB00020 */  sw        $s0, 0x20($sp)
/* 10150C 802DE41C F7B40040 */  sdc1      $f20, 0x40($sp)
/* 101510 802DE420 8C68000C */  lw        $t0, 0xc($v1)
/* 101514 802DE424 8FB60058 */  lw        $s6, 0x58($sp)
/* 101518 802DE428 1102005C */  beq       $t0, $v0, .L802DE59C
/* 10151C 802DE42C 0000102D */   daddu    $v0, $zero, $zero
/* 101520 802DE430 8C620008 */  lw        $v0, 8($v1)
/* 101524 802DE434 310300FF */  andi      $v1, $t0, 0xff
/* 101528 802DE438 00031880 */  sll       $v1, $v1, 2
/* 10152C 802DE43C 8C550000 */  lw        $s5, ($v0)
/* 101530 802DE440 24420004 */  addiu     $v0, $v0, 4
/* 101534 802DE444 8C540000 */  lw        $s4, ($v0)
/* 101538 802DE448 00431021 */  addu      $v0, $v0, $v1
/* 10153C 802DE44C 8C51000C */  lw        $s1, 0xc($v0)
/* 101540 802DE450 3C02802E */  lui       $v0, %hi(D_802DFEA0)
/* 101544 802DE454 2442FEA0 */  addiu     $v0, $v0, %lo(D_802DFEA0)
/* 101548 802DE458 AC400000 */  sw        $zero, ($v0)
/* 10154C 802DE45C AC450004 */  sw        $a1, 4($v0)
/* 101550 802DE460 AC400008 */  sw        $zero, 8($v0)
/* 101554 802DE464 3C024000 */  lui       $v0, 0x4000
/* 101558 802DE468 00821024 */  and       $v0, $a0, $v0
/* 10155C 802DE46C 1440001B */  bnez      $v0, .L802DE4DC
/* 101560 802DE470 24A2FFA5 */   addiu    $v0, $a1, -0x5b
/* 101564 802DE474 3C03800A */  lui       $v1, %hi(D_8009A634)
/* 101568 802DE478 8463A634 */  lh        $v1, %lo(D_8009A634)($v1)
/* 10156C 802DE47C 00031080 */  sll       $v0, $v1, 2
/* 101570 802DE480 00431021 */  addu      $v0, $v0, $v1
/* 101574 802DE484 00021080 */  sll       $v0, $v0, 2
/* 101578 802DE488 00431023 */  subu      $v0, $v0, $v1
/* 10157C 802DE48C 000218C0 */  sll       $v1, $v0, 3
/* 101580 802DE490 00431021 */  addu      $v0, $v0, $v1
/* 101584 802DE494 000210C0 */  sll       $v0, $v0, 3
/* 101588 802DE498 3C01800B */  lui       $at, %hi(D_800B1DEC)
/* 10158C 802DE49C 00220821 */  addu      $at, $at, $v0
/* 101590 802DE4A0 C4221DEC */  lwc1      $f2, %lo(D_800B1DEC)($at)
/* 101594 802DE4A4 44850000 */  mtc1      $a1, $f0
/* 101598 802DE4A8 00000000 */  nop       
/* 10159C 802DE4AC 46800020 */  cvt.s.w   $f0, $f0
/* 1015A0 802DE4B0 46020000 */  add.s     $f0, $f0, $f2
/* 1015A4 802DE4B4 4600010D */  trunc.w.s $f4, $f0
/* 1015A8 802DE4B8 44052000 */  mfc1      $a1, $f4
/* 1015AC 802DE4BC 00000000 */  nop       
/* 1015B0 802DE4C0 28A20169 */  slti      $v0, $a1, 0x169
/* 1015B4 802DE4C4 50400001 */  beql      $v0, $zero, .L802DE4CC
/* 1015B8 802DE4C8 24A5FE98 */   addiu    $a1, $a1, -0x168
.L802DE4CC:
/* 1015BC 802DE4CC 28A2FE98 */  slti      $v0, $a1, -0x168
/* 1015C0 802DE4D0 54400001 */  bnel      $v0, $zero, .L802DE4D8
/* 1015C4 802DE4D4 24A50168 */   addiu    $a1, $a1, 0x168
.L802DE4D8:
/* 1015C8 802DE4D8 24A2FFA5 */  addiu     $v0, $a1, -0x5b
.L802DE4DC:
/* 1015CC 802DE4DC 2C4200B4 */  sltiu     $v0, $v0, 0xb4
/* 1015D0 802DE4E0 14400004 */  bnez      $v0, .L802DE4F4
/* 1015D4 802DE4E4 24A2010E */   addiu    $v0, $a1, 0x10e
/* 1015D8 802DE4E8 2C4200B4 */  sltiu     $v0, $v0, 0xb4
/* 1015DC 802DE4EC 10400005 */  beqz      $v0, .L802DE504
/* 1015E0 802DE4F0 00000000 */   nop      
.L802DE4F4:
/* 1015E4 802DE4F4 3C01BFC0 */  lui       $at, 0xbfc0
/* 1015E8 802DE4F8 4481A000 */  mtc1      $at, $f20
/* 1015EC 802DE4FC 080B7943 */  j         .L802DE50C
/* 1015F0 802DE500 00000000 */   nop      
.L802DE504:
/* 1015F4 802DE504 3C013FC0 */  lui       $at, 0x3fc0
/* 1015F8 802DE508 4481A000 */  mtc1      $at, $f20
.L802DE50C:
/* 1015FC 802DE50C 04810005 */  bgez      $a0, .L802DE524
/* 101600 802DE510 241300FF */   addiu    $s3, $zero, 0xff
/* 101604 802DE514 14C00003 */  bnez      $a2, .L802DE524
/* 101608 802DE518 30D300FF */   andi     $s3, $a2, 0xff
/* 10160C 802DE51C 080B7967 */  j         .L802DE59C
/* 101610 802DE520 0000102D */   daddu    $v0, $zero, $zero
.L802DE524:
/* 101614 802DE524 00091080 */  sll       $v0, $t1, 2
/* 101618 802DE528 00491021 */  addu      $v0, $v0, $t1
/* 10161C 802DE52C 00021080 */  sll       $v0, $v0, 2
/* 101620 802DE530 3C10802E */  lui       $s0, %hi(D_802DFA4C)
/* 101624 802DE534 02028021 */  addu      $s0, $s0, $v0
/* 101628 802DE538 8E10FA4C */  lw        $s0, %lo(D_802DFA4C)($s0)
/* 10162C 802DE53C 3C022000 */  lui       $v0, 0x2000
/* 101630 802DE540 00821024 */  and       $v0, $a0, $v0
/* 101634 802DE544 54400001 */  bnel      $v0, $zero, .L802DE54C
/* 101638 802DE548 00E0A02D */   daddu    $s4, $a3, $zero
.L802DE54C:
/* 10163C 802DE54C 8E030000 */  lw        $v1, ($s0)
/* 101640 802DE550 2402FFFF */  addiu     $v0, $zero, -1
/* 101644 802DE554 10620010 */  beq       $v1, $v0, .L802DE598
/* 101648 802DE558 0040902D */   daddu    $s2, $v0, $zero
.L802DE55C:
/* 10164C 802DE55C 8E050000 */  lw        $a1, ($s0)
/* 101650 802DE560 0260202D */  daddu     $a0, $s3, $zero
/* 101654 802DE564 AFB40010 */  sw        $s4, 0x10($sp)
/* 101658 802DE568 E7B40014 */  swc1      $f20, 0x14($sp)
/* 10165C 802DE56C AFB60018 */  sw        $s6, 0x18($sp)
/* 101660 802DE570 8E260000 */  lw        $a2, ($s1)
/* 101664 802DE574 0C0B73B7 */  jal       spr_draw_component
/* 101668 802DE578 02A0382D */   daddu    $a3, $s5, $zero
/* 10166C 802DE57C 8E220000 */  lw        $v0, ($s1)
/* 101670 802DE580 10520002 */  beq       $v0, $s2, .L802DE58C
/* 101674 802DE584 26100004 */   addiu    $s0, $s0, 4
/* 101678 802DE588 26310004 */  addiu     $s1, $s1, 4
.L802DE58C:
/* 10167C 802DE58C 8E020000 */  lw        $v0, ($s0)
/* 101680 802DE590 1452FFF2 */  bne       $v0, $s2, .L802DE55C
/* 101684 802DE594 00000000 */   nop      
.L802DE598:
/* 101688 802DE598 24020001 */  addiu     $v0, $zero, 1
.L802DE59C:
/* 10168C 802DE59C 8FBF003C */  lw        $ra, 0x3c($sp)
/* 101690 802DE5A0 8FB60038 */  lw        $s6, 0x38($sp)
/* 101694 802DE5A4 8FB50034 */  lw        $s5, 0x34($sp)
/* 101698 802DE5A8 8FB40030 */  lw        $s4, 0x30($sp)
/* 10169C 802DE5AC 8FB3002C */  lw        $s3, 0x2c($sp)
/* 1016A0 802DE5B0 8FB20028 */  lw        $s2, 0x28($sp)
/* 1016A4 802DE5B4 8FB10024 */  lw        $s1, 0x24($sp)
/* 1016A8 802DE5B8 8FB00020 */  lw        $s0, 0x20($sp)
/* 1016AC 802DE5BC D7B40040 */  ldc1      $f20, 0x40($sp)
/* 1016B0 802DE5C0 03E00008 */  jr        $ra
/* 1016B4 802DE5C4 27BD0048 */   addiu    $sp, $sp, 0x48
