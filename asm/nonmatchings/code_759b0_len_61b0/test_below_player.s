.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel test_below_player
/* 77480 800DDFD0 27BDFF80 */  addiu     $sp, $sp, -0x80
/* 77484 800DDFD4 AFB40038 */  sw        $s4, 0x38($sp)
/* 77488 800DDFD8 8FB40090 */  lw        $s4, 0x90($sp)
/* 7748C 800DDFDC AFB1002C */  sw        $s1, 0x2c($sp)
/* 77490 800DDFE0 8FB10094 */  lw        $s1, 0x94($sp)
/* 77494 800DDFE4 AFB5003C */  sw        $s5, 0x3c($sp)
/* 77498 800DDFE8 8FB50098 */  lw        $s5, 0x98($sp)
/* 7749C 800DDFEC AFB60040 */  sw        $s6, 0x40($sp)
/* 774A0 800DDFF0 8FB6009C */  lw        $s6, 0x9c($sp)
/* 774A4 800DDFF4 AFB20030 */  sw        $s2, 0x30($sp)
/* 774A8 800DDFF8 00C0902D */  daddu     $s2, $a2, $zero
/* 774AC 800DDFFC AFB30034 */  sw        $s3, 0x34($sp)
/* 774B0 800DE000 00E0982D */  daddu     $s3, $a3, $zero
/* 774B4 800DE004 AFB70044 */  sw        $s7, 0x44($sp)
/* 774B8 800DE008 8FB700A0 */  lw        $s7, 0xa0($sp)
/* 774BC 800DE00C 3C0140C9 */  lui       $at, 0x40c9
/* 774C0 800DE010 34210FD0 */  ori       $at, $at, 0xfd0
/* 774C4 800DE014 44810000 */  mtc1      $at, $f0
/* 774C8 800DE018 27A50010 */  addiu     $a1, $sp, 0x10
/* 774CC 800DE01C AFBE0048 */  sw        $fp, 0x48($sp)
/* 774D0 800DE020 8FBE00A4 */  lw        $fp, 0xa4($sp)
/* 774D4 800DE024 46006082 */  mul.s     $f2, $f12, $f0
/* 774D8 800DE028 00000000 */  nop       
/* 774DC 800DE02C 3C0143B4 */  lui       $at, 0x43b4
/* 774E0 800DE030 44816000 */  mtc1      $at, $f12
/* 774E4 800DE034 3C013E8F */  lui       $at, 0x3e8f
/* 774E8 800DE038 34215C29 */  ori       $at, $at, 0x5c29
/* 774EC 800DE03C 44810000 */  mtc1      $at, $f0
/* 774F0 800DE040 27A60014 */  addiu     $a2, $sp, 0x14
/* 774F4 800DE044 AFBF004C */  sw        $ra, 0x4c($sp)
/* 774F8 800DE048 AFB00028 */  sw        $s0, 0x28($sp)
/* 774FC 800DE04C F7BE0078 */  sdc1      $f30, 0x78($sp)
/* 77500 800DE050 F7BC0070 */  sdc1      $f28, 0x70($sp)
/* 77504 800DE054 F7BA0068 */  sdc1      $f26, 0x68($sp)
/* 77508 800DE058 F7B80060 */  sdc1      $f24, 0x60($sp)
/* 7750C 800DE05C F7B60058 */  sdc1      $f22, 0x58($sp)
/* 77510 800DE060 F7B40050 */  sdc1      $f20, 0x50($sp)
/* 77514 800DE064 AEA00000 */  sw        $zero, ($s5)
/* 77518 800DE068 AEC00000 */  sw        $zero, ($s6)
/* 7751C 800DE06C AEE00000 */  sw        $zero, ($s7)
/* 77520 800DE070 AFC00000 */  sw        $zero, ($fp)
/* 77524 800DE074 C63E0000 */  lwc1      $f30, ($s1)
/* 77528 800DE078 46007502 */  mul.s     $f20, $f14, $f0
/* 7752C 800DE07C 00000000 */  nop       
/* 77530 800DE080 0C00A82D */  jal       sin_cos_rad
/* 77534 800DE084 460C1303 */   div.s    $f12, $f2, $f12
/* 77538 800DE088 C7A00010 */  lwc1      $f0, 0x10($sp)
/* 7753C 800DE08C 4600A582 */  mul.s     $f22, $f20, $f0
/* 77540 800DE090 00000000 */  nop       
/* 77544 800DE094 2410FFFF */  addiu     $s0, $zero, -1
/* 77548 800DE098 27A40018 */  addiu     $a0, $sp, 0x18
/* 7754C 800DE09C 27A5001C */  addiu     $a1, $sp, 0x1c
/* 77550 800DE0A0 C7A00014 */  lwc1      $f0, 0x14($sp)
/* 77554 800DE0A4 4600A507 */  neg.s     $f20, $f20
/* 77558 800DE0A8 4600A502 */  mul.s     $f20, $f20, $f0
/* 7755C 800DE0AC 00000000 */  nop       
/* 77560 800DE0B0 27A60020 */  addiu     $a2, $sp, 0x20
/* 77564 800DE0B4 C65C0000 */  lwc1      $f28, ($s2)
/* 77568 800DE0B8 C6780000 */  lwc1      $f24, ($s3)
/* 7756C 800DE0BC C69A0000 */  lwc1      $f26, ($s4)
/* 77570 800DE0C0 4616E080 */  add.s     $f2, $f28, $f22
/* 77574 800DE0C4 27A70024 */  addiu     $a3, $sp, 0x24
/* 77578 800DE0C8 E7BE0024 */  swc1      $f30, 0x24($sp)
/* 7757C 800DE0CC 4614D000 */  add.s     $f0, $f26, $f20
/* 77580 800DE0D0 E7B8001C */  swc1      $f24, 0x1c($sp)
/* 77584 800DE0D4 E7A20018 */  swc1      $f2, 0x18($sp)
/* 77588 800DE0D8 0C037953 */  jal       trace_below_player
/* 7758C 800DE0DC E7A00020 */   swc1     $f0, 0x20($sp)
/* 77590 800DE0E0 0040202D */  daddu     $a0, $v0, $zero
/* 77594 800DE0E4 0482001E */  bltzl     $a0, .L800DE160
/* 77598 800DE0E8 27A40018 */   addiu    $a0, $sp, 0x18
/* 7759C 800DE0EC C6200000 */  lwc1      $f0, ($s1)
/* 775A0 800DE0F0 C7A20024 */  lwc1      $f2, 0x24($sp)
/* 775A4 800DE0F4 46000005 */  abs.s     $f0, $f0
/* 775A8 800DE0F8 4600103E */  c.le.s    $f2, $f0
/* 775AC 800DE0FC 00000000 */  nop       
/* 775B0 800DE100 45020017 */  bc1fl     .L800DE160
/* 775B4 800DE104 27A40018 */   addiu    $a0, $sp, 0x18
/* 775B8 800DE108 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* 775BC 800DE10C 2463419C */  addiu     $v1, $v1, %lo(gGameStatusPtr)
/* 775C0 800DE110 8C620000 */  lw        $v0, ($v1)
/* 775C4 800DE114 C440011C */  lwc1      $f0, 0x11c($v0)
/* 775C8 800DE118 46000007 */  neg.s     $f0, $f0
/* 775CC 800DE11C E6A00000 */  swc1      $f0, ($s5)
/* 775D0 800DE120 8C620000 */  lw        $v0, ($v1)
/* 775D4 800DE124 C4400124 */  lwc1      $f0, 0x124($v0)
/* 775D8 800DE128 46000007 */  neg.s     $f0, $f0
/* 775DC 800DE12C E6C00000 */  swc1      $f0, ($s6)
/* 775E0 800DE130 C7A00018 */  lwc1      $f0, 0x18($sp)
/* 775E4 800DE134 E6400000 */  swc1      $f0, ($s2)
/* 775E8 800DE138 C7A0001C */  lwc1      $f0, 0x1c($sp)
/* 775EC 800DE13C E6600000 */  swc1      $f0, ($s3)
/* 775F0 800DE140 C7A00020 */  lwc1      $f0, 0x20($sp)
/* 775F4 800DE144 E6800000 */  swc1      $f0, ($s4)
/* 775F8 800DE148 C7A00024 */  lwc1      $f0, 0x24($sp)
/* 775FC 800DE14C 0080802D */  daddu     $s0, $a0, $zero
/* 77600 800DE150 E6200000 */  swc1      $f0, ($s1)
/* 77604 800DE154 E6F60000 */  swc1      $f22, ($s7)
/* 77608 800DE158 E7D40000 */  swc1      $f20, ($fp)
/* 7760C 800DE15C 27A40018 */  addiu     $a0, $sp, 0x18
.L800DE160:
/* 77610 800DE160 27A5001C */  addiu     $a1, $sp, 0x1c
/* 77614 800DE164 4616E081 */  sub.s     $f2, $f28, $f22
/* 77618 800DE168 27A60020 */  addiu     $a2, $sp, 0x20
/* 7761C 800DE16C 27A70024 */  addiu     $a3, $sp, 0x24
/* 77620 800DE170 4614D001 */  sub.s     $f0, $f26, $f20
/* 77624 800DE174 E7B8001C */  swc1      $f24, 0x1c($sp)
/* 77628 800DE178 E7BE0024 */  swc1      $f30, 0x24($sp)
/* 7762C 800DE17C E7A20018 */  swc1      $f2, 0x18($sp)
/* 77630 800DE180 0C037953 */  jal       trace_below_player
/* 77634 800DE184 E7A00020 */   swc1     $f0, 0x20($sp)
/* 77638 800DE188 0040202D */  daddu     $a0, $v0, $zero
/* 7763C 800DE18C 04820020 */  bltzl     $a0, .L800DE210
/* 77640 800DE190 27A40018 */   addiu    $a0, $sp, 0x18
/* 77644 800DE194 C6200000 */  lwc1      $f0, ($s1)
/* 77648 800DE198 C7A20024 */  lwc1      $f2, 0x24($sp)
/* 7764C 800DE19C 46000005 */  abs.s     $f0, $f0
/* 77650 800DE1A0 4600103E */  c.le.s    $f2, $f0
/* 77654 800DE1A4 00000000 */  nop       
/* 77658 800DE1A8 45020019 */  bc1fl     .L800DE210
/* 7765C 800DE1AC 27A40018 */   addiu    $a0, $sp, 0x18
/* 77660 800DE1B0 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* 77664 800DE1B4 2463419C */  addiu     $v1, $v1, %lo(gGameStatusPtr)
/* 77668 800DE1B8 8C620000 */  lw        $v0, ($v1)
/* 7766C 800DE1BC C440011C */  lwc1      $f0, 0x11c($v0)
/* 77670 800DE1C0 46000007 */  neg.s     $f0, $f0
/* 77674 800DE1C4 E6A00000 */  swc1      $f0, ($s5)
/* 77678 800DE1C8 8C620000 */  lw        $v0, ($v1)
/* 7767C 800DE1CC C4400124 */  lwc1      $f0, 0x124($v0)
/* 77680 800DE1D0 46000007 */  neg.s     $f0, $f0
/* 77684 800DE1D4 E6C00000 */  swc1      $f0, ($s6)
/* 77688 800DE1D8 C7A00018 */  lwc1      $f0, 0x18($sp)
/* 7768C 800DE1DC E6400000 */  swc1      $f0, ($s2)
/* 77690 800DE1E0 C7A0001C */  lwc1      $f0, 0x1c($sp)
/* 77694 800DE1E4 E6600000 */  swc1      $f0, ($s3)
/* 77698 800DE1E8 C7A00020 */  lwc1      $f0, 0x20($sp)
/* 7769C 800DE1EC E6800000 */  swc1      $f0, ($s4)
/* 776A0 800DE1F0 C7A00024 */  lwc1      $f0, 0x24($sp)
/* 776A4 800DE1F4 0080802D */  daddu     $s0, $a0, $zero
/* 776A8 800DE1F8 E6200000 */  swc1      $f0, ($s1)
/* 776AC 800DE1FC 4600B007 */  neg.s     $f0, $f22
/* 776B0 800DE200 E6E00000 */  swc1      $f0, ($s7)
/* 776B4 800DE204 4600A007 */  neg.s     $f0, $f20
/* 776B8 800DE208 E7C00000 */  swc1      $f0, ($fp)
/* 776BC 800DE20C 27A40018 */  addiu     $a0, $sp, 0x18
.L800DE210:
/* 776C0 800DE210 27A5001C */  addiu     $a1, $sp, 0x1c
/* 776C4 800DE214 4614E080 */  add.s     $f2, $f28, $f20
/* 776C8 800DE218 27A60020 */  addiu     $a2, $sp, 0x20
/* 776CC 800DE21C 27A70024 */  addiu     $a3, $sp, 0x24
/* 776D0 800DE220 4616D000 */  add.s     $f0, $f26, $f22
/* 776D4 800DE224 E7B8001C */  swc1      $f24, 0x1c($sp)
/* 776D8 800DE228 E7BE0024 */  swc1      $f30, 0x24($sp)
/* 776DC 800DE22C E7A20018 */  swc1      $f2, 0x18($sp)
/* 776E0 800DE230 0C037953 */  jal       trace_below_player
/* 776E4 800DE234 E7A00020 */   swc1     $f0, 0x20($sp)
/* 776E8 800DE238 0040202D */  daddu     $a0, $v0, $zero
/* 776EC 800DE23C 0482001E */  bltzl     $a0, .L800DE2B8
/* 776F0 800DE240 27A40018 */   addiu    $a0, $sp, 0x18
/* 776F4 800DE244 C6200000 */  lwc1      $f0, ($s1)
/* 776F8 800DE248 C7A20024 */  lwc1      $f2, 0x24($sp)
/* 776FC 800DE24C 46000005 */  abs.s     $f0, $f0
/* 77700 800DE250 4600103E */  c.le.s    $f2, $f0
/* 77704 800DE254 00000000 */  nop       
/* 77708 800DE258 45020017 */  bc1fl     .L800DE2B8
/* 7770C 800DE25C 27A40018 */   addiu    $a0, $sp, 0x18
/* 77710 800DE260 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* 77714 800DE264 2463419C */  addiu     $v1, $v1, %lo(gGameStatusPtr)
/* 77718 800DE268 8C620000 */  lw        $v0, ($v1)
/* 7771C 800DE26C C440011C */  lwc1      $f0, 0x11c($v0)
/* 77720 800DE270 46000007 */  neg.s     $f0, $f0
/* 77724 800DE274 E6A00000 */  swc1      $f0, ($s5)
/* 77728 800DE278 8C620000 */  lw        $v0, ($v1)
/* 7772C 800DE27C C4400124 */  lwc1      $f0, 0x124($v0)
/* 77730 800DE280 46000007 */  neg.s     $f0, $f0
/* 77734 800DE284 E6C00000 */  swc1      $f0, ($s6)
/* 77738 800DE288 C7A00018 */  lwc1      $f0, 0x18($sp)
/* 7773C 800DE28C E6400000 */  swc1      $f0, ($s2)
/* 77740 800DE290 C7A0001C */  lwc1      $f0, 0x1c($sp)
/* 77744 800DE294 E6600000 */  swc1      $f0, ($s3)
/* 77748 800DE298 C7A00020 */  lwc1      $f0, 0x20($sp)
/* 7774C 800DE29C E6800000 */  swc1      $f0, ($s4)
/* 77750 800DE2A0 C7A00024 */  lwc1      $f0, 0x24($sp)
/* 77754 800DE2A4 0080802D */  daddu     $s0, $a0, $zero
/* 77758 800DE2A8 E6200000 */  swc1      $f0, ($s1)
/* 7775C 800DE2AC E6F60000 */  swc1      $f22, ($s7)
/* 77760 800DE2B0 E7D40000 */  swc1      $f20, ($fp)
/* 77764 800DE2B4 27A40018 */  addiu     $a0, $sp, 0x18
.L800DE2B8:
/* 77768 800DE2B8 27A5001C */  addiu     $a1, $sp, 0x1c
/* 7776C 800DE2BC 4614E081 */  sub.s     $f2, $f28, $f20
/* 77770 800DE2C0 27A60020 */  addiu     $a2, $sp, 0x20
/* 77774 800DE2C4 27A70024 */  addiu     $a3, $sp, 0x24
/* 77778 800DE2C8 4616D001 */  sub.s     $f0, $f26, $f22
/* 7777C 800DE2CC E7B8001C */  swc1      $f24, 0x1c($sp)
/* 77780 800DE2D0 E7BE0024 */  swc1      $f30, 0x24($sp)
/* 77784 800DE2D4 E7A20018 */  swc1      $f2, 0x18($sp)
/* 77788 800DE2D8 0C037953 */  jal       trace_below_player
/* 7778C 800DE2DC E7A00020 */   swc1     $f0, 0x20($sp)
/* 77790 800DE2E0 0040202D */  daddu     $a0, $v0, $zero
/* 77794 800DE2E4 04820020 */  bltzl     $a0, .L800DE368
/* 77798 800DE2E8 27A40018 */   addiu    $a0, $sp, 0x18
/* 7779C 800DE2EC C6200000 */  lwc1      $f0, ($s1)
/* 777A0 800DE2F0 C7A20024 */  lwc1      $f2, 0x24($sp)
/* 777A4 800DE2F4 46000005 */  abs.s     $f0, $f0
/* 777A8 800DE2F8 4600103E */  c.le.s    $f2, $f0
/* 777AC 800DE2FC 00000000 */  nop       
/* 777B0 800DE300 45020019 */  bc1fl     .L800DE368
/* 777B4 800DE304 27A40018 */   addiu    $a0, $sp, 0x18
/* 777B8 800DE308 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* 777BC 800DE30C 2463419C */  addiu     $v1, $v1, %lo(gGameStatusPtr)
/* 777C0 800DE310 8C620000 */  lw        $v0, ($v1)
/* 777C4 800DE314 C440011C */  lwc1      $f0, 0x11c($v0)
/* 777C8 800DE318 46000007 */  neg.s     $f0, $f0
/* 777CC 800DE31C E6A00000 */  swc1      $f0, ($s5)
/* 777D0 800DE320 8C620000 */  lw        $v0, ($v1)
/* 777D4 800DE324 C4400124 */  lwc1      $f0, 0x124($v0)
/* 777D8 800DE328 46000007 */  neg.s     $f0, $f0
/* 777DC 800DE32C E6C00000 */  swc1      $f0, ($s6)
/* 777E0 800DE330 C7A00018 */  lwc1      $f0, 0x18($sp)
/* 777E4 800DE334 E6400000 */  swc1      $f0, ($s2)
/* 777E8 800DE338 C7A0001C */  lwc1      $f0, 0x1c($sp)
/* 777EC 800DE33C E6600000 */  swc1      $f0, ($s3)
/* 777F0 800DE340 C7A00020 */  lwc1      $f0, 0x20($sp)
/* 777F4 800DE344 E6800000 */  swc1      $f0, ($s4)
/* 777F8 800DE348 C7A00024 */  lwc1      $f0, 0x24($sp)
/* 777FC 800DE34C 0080802D */  daddu     $s0, $a0, $zero
/* 77800 800DE350 E6200000 */  swc1      $f0, ($s1)
/* 77804 800DE354 4600B007 */  neg.s     $f0, $f22
/* 77808 800DE358 E6E00000 */  swc1      $f0, ($s7)
/* 7780C 800DE35C 4600A007 */  neg.s     $f0, $f20
/* 77810 800DE360 E7C00000 */  swc1      $f0, ($fp)
/* 77814 800DE364 27A40018 */  addiu     $a0, $sp, 0x18
.L800DE368:
/* 77818 800DE368 27A5001C */  addiu     $a1, $sp, 0x1c
/* 7781C 800DE36C 27A60020 */  addiu     $a2, $sp, 0x20
/* 77820 800DE370 27A70024 */  addiu     $a3, $sp, 0x24
/* 77824 800DE374 E7BC0018 */  swc1      $f28, 0x18($sp)
/* 77828 800DE378 E7B8001C */  swc1      $f24, 0x1c($sp)
/* 7782C 800DE37C E7BA0020 */  swc1      $f26, 0x20($sp)
/* 77830 800DE380 0C037953 */  jal       trace_below_player
/* 77834 800DE384 E7BE0024 */   swc1     $f30, 0x24($sp)
/* 77838 800DE388 0040202D */  daddu     $a0, $v0, $zero
/* 7783C 800DE38C 0480001D */  bltz      $a0, .L800DE404
/* 77840 800DE390 00000000 */   nop      
/* 77844 800DE394 C6200000 */  lwc1      $f0, ($s1)
/* 77848 800DE398 C7A20024 */  lwc1      $f2, 0x24($sp)
/* 7784C 800DE39C 46000005 */  abs.s     $f0, $f0
/* 77850 800DE3A0 4600103E */  c.le.s    $f2, $f0
/* 77854 800DE3A4 00000000 */  nop       
/* 77858 800DE3A8 45000016 */  bc1f      .L800DE404
/* 7785C 800DE3AC 00000000 */   nop      
/* 77860 800DE3B0 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* 77864 800DE3B4 2463419C */  addiu     $v1, $v1, %lo(gGameStatusPtr)
/* 77868 800DE3B8 8C620000 */  lw        $v0, ($v1)
/* 7786C 800DE3BC C440011C */  lwc1      $f0, 0x11c($v0)
/* 77870 800DE3C0 46000007 */  neg.s     $f0, $f0
/* 77874 800DE3C4 E6A00000 */  swc1      $f0, ($s5)
/* 77878 800DE3C8 8C620000 */  lw        $v0, ($v1)
/* 7787C 800DE3CC C4400124 */  lwc1      $f0, 0x124($v0)
/* 77880 800DE3D0 46000007 */  neg.s     $f0, $f0
/* 77884 800DE3D4 E6C00000 */  swc1      $f0, ($s6)
/* 77888 800DE3D8 C7A00018 */  lwc1      $f0, 0x18($sp)
/* 7788C 800DE3DC E6400000 */  swc1      $f0, ($s2)
/* 77890 800DE3E0 C7A0001C */  lwc1      $f0, 0x1c($sp)
/* 77894 800DE3E4 E6600000 */  swc1      $f0, ($s3)
/* 77898 800DE3E8 C7A00020 */  lwc1      $f0, 0x20($sp)
/* 7789C 800DE3EC E6800000 */  swc1      $f0, ($s4)
/* 778A0 800DE3F0 C7A00024 */  lwc1      $f0, 0x24($sp)
/* 778A4 800DE3F4 0080802D */  daddu     $s0, $a0, $zero
/* 778A8 800DE3F8 E6200000 */  swc1      $f0, ($s1)
/* 778AC 800DE3FC AEE00000 */  sw        $zero, ($s7)
/* 778B0 800DE400 AFC00000 */  sw        $zero, ($fp)
.L800DE404:
/* 778B4 800DE404 06010007 */  bgez      $s0, .L800DE424
/* 778B8 800DE408 0200102D */   daddu    $v0, $s0, $zero
/* 778BC 800DE40C C7A00018 */  lwc1      $f0, 0x18($sp)
/* 778C0 800DE410 E6400000 */  swc1      $f0, ($s2)
/* 778C4 800DE414 C7A0001C */  lwc1      $f0, 0x1c($sp)
/* 778C8 800DE418 E6600000 */  swc1      $f0, ($s3)
/* 778CC 800DE41C C7A00020 */  lwc1      $f0, 0x20($sp)
/* 778D0 800DE420 E6800000 */  swc1      $f0, ($s4)
.L800DE424:
/* 778D4 800DE424 8FBF004C */  lw        $ra, 0x4c($sp)
/* 778D8 800DE428 8FBE0048 */  lw        $fp, 0x48($sp)
/* 778DC 800DE42C 8FB70044 */  lw        $s7, 0x44($sp)
/* 778E0 800DE430 8FB60040 */  lw        $s6, 0x40($sp)
/* 778E4 800DE434 8FB5003C */  lw        $s5, 0x3c($sp)
/* 778E8 800DE438 8FB40038 */  lw        $s4, 0x38($sp)
/* 778EC 800DE43C 8FB30034 */  lw        $s3, 0x34($sp)
/* 778F0 800DE440 8FB20030 */  lw        $s2, 0x30($sp)
/* 778F4 800DE444 8FB1002C */  lw        $s1, 0x2c($sp)
/* 778F8 800DE448 8FB00028 */  lw        $s0, 0x28($sp)
/* 778FC 800DE44C D7BE0078 */  ldc1      $f30, 0x78($sp)
/* 77900 800DE450 D7BC0070 */  ldc1      $f28, 0x70($sp)
/* 77904 800DE454 D7BA0068 */  ldc1      $f26, 0x68($sp)
/* 77908 800DE458 D7B80060 */  ldc1      $f24, 0x60($sp)
/* 7790C 800DE45C D7B60058 */  ldc1      $f22, 0x58($sp)
/* 77910 800DE460 D7B40050 */  ldc1      $f20, 0x50($sp)
/* 77914 800DE464 03E00008 */  jr        $ra
/* 77918 800DE468 27BD0080 */   addiu    $sp, $sp, 0x80
