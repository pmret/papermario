.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_800DD04C
/* 0764FC 800DD04C 27BDFF60 */  addiu $sp, $sp, -0xa0
/* 076500 800DD050 AFB20060 */  sw    $s2, 0x60($sp)
/* 076504 800DD054 00A0902D */  daddu $s2, $a1, $zero
/* 076508 800DD058 AFB30064 */  sw    $s3, 0x64($sp)
/* 07650C 800DD05C 00C0982D */  daddu $s3, $a2, $zero
/* 076510 800DD060 AFB40068 */  sw    $s4, 0x68($sp)
/* 076514 800DD064 00E0A02D */  daddu $s4, $a3, $zero
/* 076518 800DD068 AFB00058 */  sw    $s0, 0x58($sp)
/* 07651C 800DD06C 2410FFFF */  addiu $s0, $zero, -1
/* 076520 800DD070 AFBF006C */  sw    $ra, 0x6c($sp)
/* 076524 800DD074 AFB1005C */  sw    $s1, 0x5c($sp)
/* 076528 800DD078 F7BE0098 */  sdc1  $f30, 0x98($sp)
/* 07652C 800DD07C F7BC0090 */  sdc1  $f28, 0x90($sp)
/* 076530 800DD080 F7BA0088 */  sdc1  $f26, 0x88($sp)
/* 076534 800DD084 F7B80080 */  sdc1  $f24, 0x80($sp)
/* 076538 800DD088 F7B60078 */  sdc1  $f22, 0x78($sp)
/* 07653C 800DD08C F7B40070 */  sdc1  $f20, 0x70($sp)
/* 076540 800DD090 C6580000 */  lwc1  $f24, ($s2)
/* 076544 800DD094 C6760000 */  lwc1  $f22, ($s3)
/* 076548 800DD098 C6940000 */  lwc1  $f20, ($s4)
/* 07654C 800DD09C 8FB100B0 */  lw    $s1, 0xb0($sp)
/* 076550 800DD0A0 3C013F80 */  lui   $at, 0x3f80
/* 076554 800DD0A4 44811000 */  mtc1  $at, $f2
/* 076558 800DD0A8 4406B000 */  mfc1  $a2, $f22
/* 07655C 800DD0AC 4407A000 */  mfc1  $a3, $f20
/* 076560 800DD0B0 C6200000 */  lwc1  $f0, ($s1)
/* 076564 800DD0B4 4405C000 */  mfc1  $a1, $f24
/* 076568 800DD0B8 27A20038 */  addiu $v0, $sp, 0x38
/* 07656C 800DD0BC E7A00044 */  swc1  $f0, 0x44($sp)
/* 076570 800DD0C0 AFA2001C */  sw    $v0, 0x1c($sp)
/* 076574 800DD0C4 27A2003C */  addiu $v0, $sp, 0x3c
/* 076578 800DD0C8 AFA20020 */  sw    $v0, 0x20($sp)
/* 07657C 800DD0CC 27A20040 */  addiu $v0, $sp, 0x40
/* 076580 800DD0D0 AFA20024 */  sw    $v0, 0x24($sp)
/* 076584 800DD0D4 27A20044 */  addiu $v0, $sp, 0x44
/* 076588 800DD0D8 AFA20028 */  sw    $v0, 0x28($sp)
/* 07658C 800DD0DC 27A20048 */  addiu $v0, $sp, 0x48
/* 076590 800DD0E0 AFA2002C */  sw    $v0, 0x2c($sp)
/* 076594 800DD0E4 27A2004C */  addiu $v0, $sp, 0x4c
/* 076598 800DD0E8 AFA20030 */  sw    $v0, 0x30($sp)
/* 07659C 800DD0EC 27A20050 */  addiu $v0, $sp, 0x50
/* 0765A0 800DD0F0 AFA00010 */  sw    $zero, 0x10($sp)
/* 0765A4 800DD0F4 E7A20014 */  swc1  $f2, 0x14($sp)
/* 0765A8 800DD0F8 AFA00018 */  sw    $zero, 0x18($sp)
/* 0765AC 800DD0FC 0C017334 */  jal   test_ray_colliders
/* 0765B0 800DD100 AFA20034 */   sw    $v0, 0x34($sp)
/* 0765B4 800DD104 4600C686 */  mov.s $f26, $f24
/* 0765B8 800DD108 4600B706 */  mov.s $f28, $f22
/* 0765BC 800DD10C 0440000C */  bltz  $v0, .L800DD140
/* 0765C0 800DD110 4600A786 */   mov.s $f30, $f20
/* 0765C4 800DD114 C6200000 */  lwc1  $f0, ($s1)
/* 0765C8 800DD118 C7A20044 */  lwc1  $f2, 0x44($sp)
/* 0765CC 800DD11C 4600103C */  c.lt.s $f2, $f0
/* 0765D0 800DD120 00000000 */  nop   
/* 0765D4 800DD124 45020007 */  bc1fl .L800DD144
/* 0765D8 800DD128 4600D606 */   mov.s $f24, $f26
/* 0765DC 800DD12C 0040802D */  daddu $s0, $v0, $zero
/* 0765E0 800DD130 E6220000 */  swc1  $f2, ($s1)
/* 0765E4 800DD134 E6580000 */  swc1  $f24, ($s2)
/* 0765E8 800DD138 E6760000 */  swc1  $f22, ($s3)
/* 0765EC 800DD13C E6940000 */  swc1  $f20, ($s4)
.L800DD140:
/* 0765F0 800DD140 4600D606 */  mov.s $f24, $f26
.L800DD144:
/* 0765F4 800DD144 4600E586 */  mov.s $f22, $f28
/* 0765F8 800DD148 3C014120 */  lui   $at, 0x4120
/* 0765FC 800DD14C 44811000 */  mtc1  $at, $f2
/* 076600 800DD150 44802000 */  mtc1  $zero, $f4
/* 076604 800DD154 3C013F80 */  lui   $at, 0x3f80
/* 076608 800DD158 44810000 */  mtc1  $at, $f0
/* 07660C 800DD15C 27A20038 */  addiu $v0, $sp, 0x38
/* 076610 800DD160 E7A20044 */  swc1  $f2, 0x44($sp)
/* 076614 800DD164 AFA20018 */  sw    $v0, 0x18($sp)
/* 076618 800DD168 27A2003C */  addiu $v0, $sp, 0x3c
/* 07661C 800DD16C AFA2001C */  sw    $v0, 0x1c($sp)
/* 076620 800DD170 27A20040 */  addiu $v0, $sp, 0x40
/* 076624 800DD174 AFA20020 */  sw    $v0, 0x20($sp)
/* 076628 800DD178 27A20044 */  addiu $v0, $sp, 0x44
/* 07662C 800DD17C AFA20024 */  sw    $v0, 0x24($sp)
/* 076630 800DD180 27A20048 */  addiu $v0, $sp, 0x48
/* 076634 800DD184 AFA20028 */  sw    $v0, 0x28($sp)
/* 076638 800DD188 27A2004C */  addiu $v0, $sp, 0x4c
/* 07663C 800DD18C AFA2002C */  sw    $v0, 0x2c($sp)
/* 076640 800DD190 27A20050 */  addiu $v0, $sp, 0x50
/* 076644 800DD194 E7A00010 */  swc1  $f0, 0x10($sp)
/* 076648 800DD198 E7A40014 */  swc1  $f4, 0x14($sp)
/* 07664C 800DD19C AFA20030 */  sw    $v0, 0x30($sp)
/* 076650 800DD1A0 8E860000 */  lw    $a2, ($s4)
/* 076654 800DD1A4 44072000 */  mfc1  $a3, $f4
/* 076658 800DD1A8 C64C0000 */  lwc1  $f12, ($s2)
/* 07665C 800DD1AC C66E0000 */  lwc1  $f14, ($s3)
/* 076660 800DD1B0 0C017512 */  jal   test_ray_entities
/* 076664 800DD1B4 4600F506 */   mov.s $f20, $f30
/* 076668 800DD1B8 0442000D */  bltzl $v0, .L800DD1F0
/* 07666C 800DD1BC 0200102D */   daddu $v0, $s0, $zero
/* 076670 800DD1C0 C6200000 */  lwc1  $f0, ($s1)
/* 076674 800DD1C4 C7A20044 */  lwc1  $f2, 0x44($sp)
/* 076678 800DD1C8 4600103C */  c.lt.s $f2, $f0
/* 07667C 800DD1CC 00000000 */  nop   
/* 076680 800DD1D0 45020007 */  bc1fl .L800DD1F0
/* 076684 800DD1D4 0200102D */   daddu $v0, $s0, $zero
/* 076688 800DD1D8 34504000 */  ori   $s0, $v0, 0x4000
/* 07668C 800DD1DC E6220000 */  swc1  $f2, ($s1)
/* 076690 800DD1E0 E6580000 */  swc1  $f24, ($s2)
/* 076694 800DD1E4 E6760000 */  swc1  $f22, ($s3)
/* 076698 800DD1E8 E6940000 */  swc1  $f20, ($s4)
/* 07669C 800DD1EC 0200102D */  daddu $v0, $s0, $zero
.L800DD1F0:
/* 0766A0 800DD1F0 8FBF006C */  lw    $ra, 0x6c($sp)
/* 0766A4 800DD1F4 8FB40068 */  lw    $s4, 0x68($sp)
/* 0766A8 800DD1F8 8FB30064 */  lw    $s3, 0x64($sp)
/* 0766AC 800DD1FC 8FB20060 */  lw    $s2, 0x60($sp)
/* 0766B0 800DD200 8FB1005C */  lw    $s1, 0x5c($sp)
/* 0766B4 800DD204 8FB00058 */  lw    $s0, 0x58($sp)
/* 0766B8 800DD208 D7BE0098 */  ldc1  $f30, 0x98($sp)
/* 0766BC 800DD20C D7BC0090 */  ldc1  $f28, 0x90($sp)
/* 0766C0 800DD210 D7BA0088 */  ldc1  $f26, 0x88($sp)
/* 0766C4 800DD214 D7B80080 */  ldc1  $f24, 0x80($sp)
/* 0766C8 800DD218 D7B60078 */  ldc1  $f22, 0x78($sp)
/* 0766CC 800DD21C D7B40070 */  ldc1  $f20, 0x70($sp)
/* 0766D0 800DD220 03E00008 */  jr    $ra
/* 0766D4 800DD224 27BD00A0 */   addiu $sp, $sp, 0xa0

/* 0766D8 800DD228 27BDFF88 */  addiu $sp, $sp, -0x78
/* 0766DC 800DD22C F7B40050 */  sdc1  $f20, 0x50($sp)
/* 0766E0 800DD230 C7B4008C */  lwc1  $f20, 0x8c($sp)
/* 0766E4 800DD234 3C0140C9 */  lui   $at, 0x40c9
/* 0766E8 800DD238 34210FD0 */  ori   $at, $at, 0xfd0
/* 0766EC 800DD23C 44810000 */  mtc1  $at, $f0
/* 0766F0 800DD240 AFB60040 */  sw    $s6, 0x40($sp)
/* 0766F4 800DD244 8FB60088 */  lw    $s6, 0x88($sp)
/* 0766F8 800DD248 F7B60058 */  sdc1  $f22, 0x58($sp)
/* 0766FC 800DD24C C7B60090 */  lwc1  $f22, 0x90($sp)
/* 076700 800DD250 AFB5003C */  sw    $s5, 0x3c($sp)
/* 076704 800DD254 0080A82D */  daddu $s5, $a0, $zero
/* 076708 800DD258 AFB70044 */  sw    $s7, 0x44($sp)
/* 07670C 800DD25C 00A0B82D */  daddu $s7, $a1, $zero
/* 076710 800DD260 AFBE0048 */  sw    $fp, 0x48($sp)
/* 076714 800DD264 4600A502 */  mul.s $f20, $f20, $f0
/* 076718 800DD268 00000000 */  nop   
/* 07671C 800DD26C 3C0143B4 */  lui   $at, 0x43b4
/* 076720 800DD270 44810000 */  mtc1  $at, $f0
/* 076724 800DD274 00C0F02D */  daddu $fp, $a2, $zero
/* 076728 800DD278 AFBF004C */  sw    $ra, 0x4c($sp)
/* 07672C 800DD27C AFB40038 */  sw    $s4, 0x38($sp)
/* 076730 800DD280 AFB30034 */  sw    $s3, 0x34($sp)
/* 076734 800DD284 AFB20030 */  sw    $s2, 0x30($sp)
/* 076738 800DD288 AFB1002C */  sw    $s1, 0x2c($sp)
/* 07673C 800DD28C AFB00028 */  sw    $s0, 0x28($sp)
/* 076740 800DD290 F7BC0070 */  sdc1  $f28, 0x70($sp)
/* 076744 800DD294 F7BA0068 */  sdc1  $f26, 0x68($sp)
/* 076748 800DD298 F7B80060 */  sdc1  $f24, 0x60($sp)
/* 07674C 800DD29C AFA70084 */  sw    $a3, 0x84($sp)
/* 076750 800DD2A0 4600A503 */  div.s $f20, $f20, $f0
/* 076754 800DD2A4 0C00A85B */  jal   sin_rad
/* 076758 800DD2A8 4600A306 */   mov.s $f12, $f20
/* 07675C 800DD2AC 4600B702 */  mul.s $f28, $f22, $f0
/* 076760 800DD2B0 00000000 */  nop   
/* 076764 800DD2B4 2414FFFF */  addiu $s4, $zero, -1
/* 076768 800DD2B8 4600A306 */  mov.s $f12, $f20
/* 07676C 800DD2BC 0C00A874 */  jal   cos_rad
/* 076770 800DD2C0 4600B587 */   neg.s $f22, $f22
/* 076774 800DD2C4 02A0202D */  daddu $a0, $s5, $zero
/* 076778 800DD2C8 27B30018 */  addiu $s3, $sp, 0x18
/* 07677C 800DD2CC 0260282D */  daddu $a1, $s3, $zero
/* 076780 800DD2D0 27B2001C */  addiu $s2, $sp, 0x1c
/* 076784 800DD2D4 0240302D */  daddu $a2, $s2, $zero
/* 076788 800DD2D8 27B10020 */  addiu $s1, $sp, 0x20
/* 07678C 800DD2DC 0220382D */  daddu $a3, $s1, $zero
/* 076790 800DD2E0 4600B682 */  mul.s $f26, $f22, $f0
/* 076794 800DD2E4 00000000 */  nop   
/* 076798 800DD2E8 C6F60000 */  lwc1  $f22, ($s7)
/* 07679C 800DD2EC C7D80000 */  lwc1  $f24, ($fp)
/* 0767A0 800DD2F0 8FA30084 */  lw    $v1, 0x84($sp)
/* 0767A4 800DD2F4 C6C00000 */  lwc1  $f0, ($s6)
/* 0767A8 800DD2F8 C4740000 */  lwc1  $f20, ($v1)
/* 0767AC 800DD2FC 461CB080 */  add.s $f2, $f22, $f28
/* 0767B0 800DD300 27B00024 */  addiu $s0, $sp, 0x24
/* 0767B4 800DD304 E7A00024 */  swc1  $f0, 0x24($sp)
/* 0767B8 800DD308 461AA000 */  add.s $f0, $f20, $f26
/* 0767BC 800DD30C E7B8001C */  swc1  $f24, 0x1c($sp)
/* 0767C0 800DD310 E7A20018 */  swc1  $f2, 0x18($sp)
/* 0767C4 800DD314 E7A00020 */  swc1  $f0, 0x20($sp)
/* 0767C8 800DD318 0C037413 */  jal   func_800DD04C
/* 0767CC 800DD31C AFB00010 */   sw    $s0, 0x10($sp)
/* 0767D0 800DD320 04410025 */  bgez  $v0, .L800DD3B8
/* 0767D4 800DD324 02A0202D */   daddu $a0, $s5, $zero
/* 0767D8 800DD328 0260282D */  daddu $a1, $s3, $zero
/* 0767DC 800DD32C 461CB081 */  sub.s $f2, $f22, $f28
/* 0767E0 800DD330 0240302D */  daddu $a2, $s2, $zero
/* 0767E4 800DD334 0220382D */  daddu $a3, $s1, $zero
/* 0767E8 800DD338 461AA001 */  sub.s $f0, $f20, $f26
/* 0767EC 800DD33C E7B8001C */  swc1  $f24, 0x1c($sp)
/* 0767F0 800DD340 E7A20018 */  swc1  $f2, 0x18($sp)
/* 0767F4 800DD344 E7A00020 */  swc1  $f0, 0x20($sp)
/* 0767F8 800DD348 0C037413 */  jal   func_800DD04C
/* 0767FC 800DD34C AFB00010 */   sw    $s0, 0x10($sp)
/* 076800 800DD350 04410019 */  bgez  $v0, .L800DD3B8
/* 076804 800DD354 02A0202D */   daddu $a0, $s5, $zero
/* 076808 800DD358 0260282D */  daddu $a1, $s3, $zero
/* 07680C 800DD35C 461AB080 */  add.s $f2, $f22, $f26
/* 076810 800DD360 0240302D */  daddu $a2, $s2, $zero
/* 076814 800DD364 0220382D */  daddu $a3, $s1, $zero
/* 076818 800DD368 461CA000 */  add.s $f0, $f20, $f28
/* 07681C 800DD36C E7B8001C */  swc1  $f24, 0x1c($sp)
/* 076820 800DD370 E7A20018 */  swc1  $f2, 0x18($sp)
/* 076824 800DD374 E7A00020 */  swc1  $f0, 0x20($sp)
/* 076828 800DD378 0C037413 */  jal   func_800DD04C
/* 07682C 800DD37C AFB00010 */   sw    $s0, 0x10($sp)
/* 076830 800DD380 0441000D */  bgez  $v0, .L800DD3B8
/* 076834 800DD384 02A0202D */   daddu $a0, $s5, $zero
/* 076838 800DD388 0260282D */  daddu $a1, $s3, $zero
/* 07683C 800DD38C 461AB081 */  sub.s $f2, $f22, $f26
/* 076840 800DD390 0240302D */  daddu $a2, $s2, $zero
/* 076844 800DD394 0220382D */  daddu $a3, $s1, $zero
/* 076848 800DD398 461CA001 */  sub.s $f0, $f20, $f28
/* 07684C 800DD39C E7B8001C */  swc1  $f24, 0x1c($sp)
/* 076850 800DD3A0 E7A20018 */  swc1  $f2, 0x18($sp)
/* 076854 800DD3A4 E7A00020 */  swc1  $f0, 0x20($sp)
/* 076858 800DD3A8 0C037413 */  jal   func_800DD04C
/* 07685C 800DD3AC AFB00010 */   sw    $s0, 0x10($sp)
/* 076860 800DD3B0 0440000B */  bltz  $v0, .L800DD3E0
/* 076864 800DD3B4 00000000 */   nop   
.L800DD3B8:
/* 076868 800DD3B8 C7A00018 */  lwc1  $f0, 0x18($sp)
/* 07686C 800DD3BC E6E00000 */  swc1  $f0, ($s7)
/* 076870 800DD3C0 C7A0001C */  lwc1  $f0, 0x1c($sp)
/* 076874 800DD3C4 E7C00000 */  swc1  $f0, ($fp)
/* 076878 800DD3C8 C7A00020 */  lwc1  $f0, 0x20($sp)
/* 07687C 800DD3CC 8FA30084 */  lw    $v1, 0x84($sp)
/* 076880 800DD3D0 E4600000 */  swc1  $f0, ($v1)
/* 076884 800DD3D4 C7A00024 */  lwc1  $f0, 0x24($sp)
/* 076888 800DD3D8 0040A02D */  daddu $s4, $v0, $zero
/* 07688C 800DD3DC E6C00000 */  swc1  $f0, ($s6)
.L800DD3E0:
/* 076890 800DD3E0 06810009 */  bgez  $s4, .L800DD408
/* 076894 800DD3E4 0280102D */   daddu $v0, $s4, $zero
/* 076898 800DD3E8 C7A00018 */  lwc1  $f0, 0x18($sp)
/* 07689C 800DD3EC E6E00000 */  swc1  $f0, ($s7)
/* 0768A0 800DD3F0 C7A0001C */  lwc1  $f0, 0x1c($sp)
/* 0768A4 800DD3F4 E7C00000 */  swc1  $f0, ($fp)
/* 0768A8 800DD3F8 C7A00020 */  lwc1  $f0, 0x20($sp)
/* 0768AC 800DD3FC 8FA30084 */  lw    $v1, 0x84($sp)
/* 0768B0 800DD400 E4600000 */  swc1  $f0, ($v1)
/* 0768B4 800DD404 AEC00000 */  sw    $zero, ($s6)
.L800DD408:
/* 0768B8 800DD408 8FBF004C */  lw    $ra, 0x4c($sp)
/* 0768BC 800DD40C 8FBE0048 */  lw    $fp, 0x48($sp)
/* 0768C0 800DD410 8FB70044 */  lw    $s7, 0x44($sp)
/* 0768C4 800DD414 8FB60040 */  lw    $s6, 0x40($sp)
/* 0768C8 800DD418 8FB5003C */  lw    $s5, 0x3c($sp)
/* 0768CC 800DD41C 8FB40038 */  lw    $s4, 0x38($sp)
/* 0768D0 800DD420 8FB30034 */  lw    $s3, 0x34($sp)
/* 0768D4 800DD424 8FB20030 */  lw    $s2, 0x30($sp)
/* 0768D8 800DD428 8FB1002C */  lw    $s1, 0x2c($sp)
/* 0768DC 800DD42C 8FB00028 */  lw    $s0, 0x28($sp)
/* 0768E0 800DD430 D7BC0070 */  ldc1  $f28, 0x70($sp)
/* 0768E4 800DD434 D7BA0068 */  ldc1  $f26, 0x68($sp)
/* 0768E8 800DD438 D7B80060 */  ldc1  $f24, 0x60($sp)
/* 0768EC 800DD43C D7B60058 */  ldc1  $f22, 0x58($sp)
/* 0768F0 800DD440 D7B40050 */  ldc1  $f20, 0x50($sp)
/* 0768F4 800DD444 03E00008 */  jr    $ra
/* 0768F8 800DD448 27BD0078 */   addiu $sp, $sp, 0x78

