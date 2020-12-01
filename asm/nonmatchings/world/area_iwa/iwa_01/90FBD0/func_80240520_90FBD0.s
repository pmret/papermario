.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240520_90FBD0
/* 90FBD0 80240520 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 90FBD4 80240524 AFB10014 */  sw        $s1, 0x14($sp)
/* 90FBD8 80240528 0080882D */  daddu     $s1, $a0, $zero
/* 90FBDC 8024052C 3C05800B */  lui       $a1, %hi(gCameras)
/* 90FBE0 80240530 24A51D80 */  addiu     $a1, $a1, %lo(gCameras)
/* 90FBE4 80240534 AFBF0020 */  sw        $ra, 0x20($sp)
/* 90FBE8 80240538 AFB3001C */  sw        $s3, 0x1c($sp)
/* 90FBEC 8024053C AFB20018 */  sw        $s2, 0x18($sp)
/* 90FBF0 80240540 AFB00010 */  sw        $s0, 0x10($sp)
/* 90FBF4 80240544 F7B40028 */  sdc1      $f20, 0x28($sp)
/* 90FBF8 80240548 8E330148 */  lw        $s3, 0x148($s1)
/* 90FBFC 8024054C 3C03800A */  lui       $v1, %hi(D_8009A634)
/* 90FC00 80240550 8463A634 */  lh        $v1, %lo(D_8009A634)($v1)
/* 90FC04 80240554 8E30000C */  lw        $s0, 0xc($s1)
/* 90FC08 80240558 00031080 */  sll       $v0, $v1, 2
/* 90FC0C 8024055C 00431021 */  addu      $v0, $v0, $v1
/* 90FC10 80240560 00021080 */  sll       $v0, $v0, 2
/* 90FC14 80240564 00431023 */  subu      $v0, $v0, $v1
/* 90FC18 80240568 000218C0 */  sll       $v1, $v0, 3
/* 90FC1C 8024056C 00431021 */  addu      $v0, $v0, $v1
/* 90FC20 80240570 000210C0 */  sll       $v0, $v0, 3
/* 90FC24 80240574 86640008 */  lh        $a0, 8($s3)
/* 90FC28 80240578 0C00EABB */  jal       get_npc_unsafe
/* 90FC2C 8024057C 00459021 */   addu     $s2, $v0, $a1
/* 90FC30 80240580 0220202D */  daddu     $a0, $s1, $zero
/* 90FC34 80240584 8E050000 */  lw        $a1, ($s0)
/* 90FC38 80240588 0C0B1EAF */  jal       get_variable
/* 90FC3C 8024058C 0040802D */   daddu    $s0, $v0, $zero
/* 90FC40 80240590 0260202D */  daddu     $a0, $s3, $zero
/* 90FC44 80240594 8C460024 */  lw        $a2, 0x24($v0)
/* 90FC48 80240598 8C470028 */  lw        $a3, 0x28($v0)
/* 90FC4C 8024059C 0C0124FB */  jal       func_800493EC
/* 90FC50 802405A0 0000282D */   daddu    $a1, $zero, $zero
/* 90FC54 802405A4 10400052 */  beqz      $v0, .L802406F0
/* 90FC58 802405A8 2402FFFF */   addiu    $v0, $zero, -1
/* 90FC5C 802405AC C64C006C */  lwc1      $f12, 0x6c($s2)
/* 90FC60 802405B0 C60E000C */  lwc1      $f14, 0xc($s0)
/* 90FC64 802405B4 3C014387 */  lui       $at, 0x4387
/* 90FC68 802405B8 4481A000 */  mtc1      $at, $f20
/* 90FC6C 802405BC 0C00A70A */  jal       get_clamped_angle_diff
/* 90FC70 802405C0 00000000 */   nop      
/* 90FC74 802405C4 0C00A6C9 */  jal       clamp_angle
/* 90FC78 802405C8 46000306 */   mov.s    $f12, $f0
/* 90FC7C 802405CC 3C018024 */  lui       $at, %hi(D_80246390)
/* 90FC80 802405D0 D4226390 */  ldc1      $f2, %lo(D_80246390)($at)
/* 90FC84 802405D4 46000021 */  cvt.d.s   $f0, $f0
/* 90FC88 802405D8 4622003C */  c.lt.d    $f0, $f2
/* 90FC8C 802405DC 00000000 */  nop       
/* 90FC90 802405E0 45000003 */  bc1f      .L802405F0
/* 90FC94 802405E4 00000000 */   nop      
/* 90FC98 802405E8 3C0142B4 */  lui       $at, 0x42b4
/* 90FC9C 802405EC 4481A000 */  mtc1      $at, $f20
.L802405F0:
/* 90FCA0 802405F0 3C11800F */  lui       $s1, %hi(gPlayerStatusPtr)
/* 90FCA4 802405F4 26317B30 */  addiu     $s1, $s1, %lo(gPlayerStatusPtr)
/* 90FCA8 802405F8 C60C0038 */  lwc1      $f12, 0x38($s0)
/* 90FCAC 802405FC 8E220000 */  lw        $v0, ($s1)
/* 90FCB0 80240600 C60E0040 */  lwc1      $f14, 0x40($s0)
/* 90FCB4 80240604 8C460028 */  lw        $a2, 0x28($v0)
/* 90FCB8 80240608 0C00A720 */  jal       atan2
/* 90FCBC 8024060C 8C470030 */   lw       $a3, 0x30($v0)
/* 90FCC0 80240610 4600A306 */  mov.s     $f12, $f20
/* 90FCC4 80240614 0C00A70A */  jal       get_clamped_angle_diff
/* 90FCC8 80240618 46000386 */   mov.s    $f14, $f0
/* 90FCCC 8024061C 46000005 */  abs.s     $f0, $f0
/* 90FCD0 80240620 3C018024 */  lui       $at, %hi(D_80246398)
/* 90FCD4 80240624 D4226398 */  ldc1      $f2, %lo(D_80246398)($at)
/* 90FCD8 80240628 46000021 */  cvt.d.s   $f0, $f0
/* 90FCDC 8024062C 4620103C */  c.lt.d    $f2, $f0
/* 90FCE0 80240630 00000000 */  nop       
/* 90FCE4 80240634 4501002E */  bc1t      .L802406F0
/* 90FCE8 80240638 2402FFFF */   addiu    $v0, $zero, -1
/* 90FCEC 8024063C 8E220000 */  lw        $v0, ($s1)
/* 90FCF0 80240640 C600003C */  lwc1      $f0, 0x3c($s0)
/* 90FCF4 80240644 C442002C */  lwc1      $f2, 0x2c($v0)
/* 90FCF8 80240648 860200A8 */  lh        $v0, 0xa8($s0)
/* 90FCFC 8024064C 46020001 */  sub.s     $f0, $f0, $f2
/* 90FD00 80240650 44821000 */  mtc1      $v0, $f2
/* 90FD04 80240654 00000000 */  nop       
/* 90FD08 80240658 468010A1 */  cvt.d.w   $f2, $f2
/* 90FD0C 8024065C 46221080 */  add.d     $f2, $f2, $f2
/* 90FD10 80240660 46000005 */  abs.s     $f0, $f0
/* 90FD14 80240664 46000021 */  cvt.d.s   $f0, $f0
/* 90FD18 80240668 4620103E */  c.le.d    $f2, $f0
/* 90FD1C 8024066C 00000000 */  nop       
/* 90FD20 80240670 4501001F */  bc1t      .L802406F0
/* 90FD24 80240674 2402FFFF */   addiu    $v0, $zero, -1
/* 90FD28 80240678 3C038011 */  lui       $v1, %hi(D_8010EBB3)
/* 90FD2C 8024067C 8063EBB3 */  lb        $v1, %lo(D_8010EBB3)($v1)
/* 90FD30 80240680 24020009 */  addiu     $v0, $zero, 9
/* 90FD34 80240684 10620019 */  beq       $v1, $v0, .L802406EC
/* 90FD38 80240688 24020007 */   addiu    $v0, $zero, 7
/* 90FD3C 8024068C 14620005 */  bne       $v1, $v0, .L802406A4
/* 90FD40 80240690 2402FFFF */   addiu    $v0, $zero, -1
/* 90FD44 80240694 080901BC */  j         .L802406F0
/* 90FD48 80240698 00000000 */   nop      
.L8024069C:
/* 90FD4C 8024069C 080901BC */  j         .L802406F0
/* 90FD50 802406A0 0240102D */   daddu    $v0, $s2, $zero
.L802406A4:
/* 90FD54 802406A4 8E620078 */  lw        $v0, 0x78($s3)
/* 90FD58 802406A8 18400010 */  blez      $v0, .L802406EC
/* 90FD5C 802406AC 0000882D */   daddu    $s1, $zero, $zero
.L802406B0:
/* 90FD60 802406B0 86620008 */  lh        $v0, 8($s3)
/* 90FD64 802406B4 00511021 */  addu      $v0, $v0, $s1
/* 90FD68 802406B8 24520001 */  addiu     $s2, $v0, 1
/* 90FD6C 802406BC 0C00FB3A */  jal       get_enemy
/* 90FD70 802406C0 0240202D */   daddu    $a0, $s2, $zero
/* 90FD74 802406C4 0240202D */  daddu     $a0, $s2, $zero
/* 90FD78 802406C8 0C00EABB */  jal       get_npc_unsafe
/* 90FD7C 802406CC 0040802D */   daddu    $s0, $v0, $zero
/* 90FD80 802406D0 8E02006C */  lw        $v0, 0x6c($s0)
/* 90FD84 802406D4 1040FFF1 */  beqz      $v0, .L8024069C
/* 90FD88 802406D8 26310001 */   addiu    $s1, $s1, 1
/* 90FD8C 802406DC 8E620078 */  lw        $v0, 0x78($s3)
/* 90FD90 802406E0 0222102A */  slt       $v0, $s1, $v0
/* 90FD94 802406E4 1440FFF2 */  bnez      $v0, .L802406B0
/* 90FD98 802406E8 00000000 */   nop      
.L802406EC:
/* 90FD9C 802406EC 2402FFFF */  addiu     $v0, $zero, -1
.L802406F0:
/* 90FDA0 802406F0 8FBF0020 */  lw        $ra, 0x20($sp)
/* 90FDA4 802406F4 8FB3001C */  lw        $s3, 0x1c($sp)
/* 90FDA8 802406F8 8FB20018 */  lw        $s2, 0x18($sp)
/* 90FDAC 802406FC 8FB10014 */  lw        $s1, 0x14($sp)
/* 90FDB0 80240700 8FB00010 */  lw        $s0, 0x10($sp)
/* 90FDB4 80240704 D7B40028 */  ldc1      $f20, 0x28($sp)
/* 90FDB8 80240708 03E00008 */  jr        $ra
/* 90FDBC 8024070C 27BD0030 */   addiu    $sp, $sp, 0x30
