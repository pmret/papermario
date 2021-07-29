.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel npc_raycast_up_corner
/* 764FC 800DD04C 27BDFF60 */  addiu     $sp, $sp, -0xa0
/* 76500 800DD050 AFB20060 */  sw        $s2, 0x60($sp)
/* 76504 800DD054 00A0902D */  daddu     $s2, $a1, $zero
/* 76508 800DD058 AFB30064 */  sw        $s3, 0x64($sp)
/* 7650C 800DD05C 00C0982D */  daddu     $s3, $a2, $zero
/* 76510 800DD060 AFB40068 */  sw        $s4, 0x68($sp)
/* 76514 800DD064 00E0A02D */  daddu     $s4, $a3, $zero
/* 76518 800DD068 AFB00058 */  sw        $s0, 0x58($sp)
/* 7651C 800DD06C 2410FFFF */  addiu     $s0, $zero, -1
/* 76520 800DD070 AFBF006C */  sw        $ra, 0x6c($sp)
/* 76524 800DD074 AFB1005C */  sw        $s1, 0x5c($sp)
/* 76528 800DD078 F7BE0098 */  sdc1      $f30, 0x98($sp)
/* 7652C 800DD07C F7BC0090 */  sdc1      $f28, 0x90($sp)
/* 76530 800DD080 F7BA0088 */  sdc1      $f26, 0x88($sp)
/* 76534 800DD084 F7B80080 */  sdc1      $f24, 0x80($sp)
/* 76538 800DD088 F7B60078 */  sdc1      $f22, 0x78($sp)
/* 7653C 800DD08C F7B40070 */  sdc1      $f20, 0x70($sp)
/* 76540 800DD090 C6580000 */  lwc1      $f24, ($s2)
/* 76544 800DD094 C6760000 */  lwc1      $f22, ($s3)
/* 76548 800DD098 C6940000 */  lwc1      $f20, ($s4)
/* 7654C 800DD09C 8FB100B0 */  lw        $s1, 0xb0($sp)
/* 76550 800DD0A0 3C013F80 */  lui       $at, 0x3f80
/* 76554 800DD0A4 44811000 */  mtc1      $at, $f2
/* 76558 800DD0A8 4406B000 */  mfc1      $a2, $f22
/* 7655C 800DD0AC 4407A000 */  mfc1      $a3, $f20
/* 76560 800DD0B0 C6200000 */  lwc1      $f0, ($s1)
/* 76564 800DD0B4 4405C000 */  mfc1      $a1, $f24
/* 76568 800DD0B8 27A20038 */  addiu     $v0, $sp, 0x38
/* 7656C 800DD0BC E7A00044 */  swc1      $f0, 0x44($sp)
/* 76570 800DD0C0 AFA2001C */  sw        $v0, 0x1c($sp)
/* 76574 800DD0C4 27A2003C */  addiu     $v0, $sp, 0x3c
/* 76578 800DD0C8 AFA20020 */  sw        $v0, 0x20($sp)
/* 7657C 800DD0CC 27A20040 */  addiu     $v0, $sp, 0x40
/* 76580 800DD0D0 AFA20024 */  sw        $v0, 0x24($sp)
/* 76584 800DD0D4 27A20044 */  addiu     $v0, $sp, 0x44
/* 76588 800DD0D8 AFA20028 */  sw        $v0, 0x28($sp)
/* 7658C 800DD0DC 27A20048 */  addiu     $v0, $sp, 0x48
/* 76590 800DD0E0 AFA2002C */  sw        $v0, 0x2c($sp)
/* 76594 800DD0E4 27A2004C */  addiu     $v0, $sp, 0x4c
/* 76598 800DD0E8 AFA20030 */  sw        $v0, 0x30($sp)
/* 7659C 800DD0EC 27A20050 */  addiu     $v0, $sp, 0x50
/* 765A0 800DD0F0 AFA00010 */  sw        $zero, 0x10($sp)
/* 765A4 800DD0F4 E7A20014 */  swc1      $f2, 0x14($sp)
/* 765A8 800DD0F8 AFA00018 */  sw        $zero, 0x18($sp)
/* 765AC 800DD0FC 0C017334 */  jal       test_ray_colliders
/* 765B0 800DD100 AFA20034 */   sw       $v0, 0x34($sp)
/* 765B4 800DD104 4600C686 */  mov.s     $f26, $f24
/* 765B8 800DD108 4600B706 */  mov.s     $f28, $f22
/* 765BC 800DD10C 0440000C */  bltz      $v0, .L800DD140
/* 765C0 800DD110 4600A786 */   mov.s    $f30, $f20
/* 765C4 800DD114 C6200000 */  lwc1      $f0, ($s1)
/* 765C8 800DD118 C7A20044 */  lwc1      $f2, 0x44($sp)
/* 765CC 800DD11C 4600103C */  c.lt.s    $f2, $f0
/* 765D0 800DD120 00000000 */  nop
/* 765D4 800DD124 45020007 */  bc1fl     .L800DD144
/* 765D8 800DD128 4600D606 */   mov.s    $f24, $f26
/* 765DC 800DD12C 0040802D */  daddu     $s0, $v0, $zero
/* 765E0 800DD130 E6220000 */  swc1      $f2, ($s1)
/* 765E4 800DD134 E6580000 */  swc1      $f24, ($s2)
/* 765E8 800DD138 E6760000 */  swc1      $f22, ($s3)
/* 765EC 800DD13C E6940000 */  swc1      $f20, ($s4)
.L800DD140:
/* 765F0 800DD140 4600D606 */  mov.s     $f24, $f26
.L800DD144:
/* 765F4 800DD144 4600E586 */  mov.s     $f22, $f28
/* 765F8 800DD148 3C014120 */  lui       $at, 0x4120
/* 765FC 800DD14C 44811000 */  mtc1      $at, $f2
/* 76600 800DD150 44802000 */  mtc1      $zero, $f4
/* 76604 800DD154 3C013F80 */  lui       $at, 0x3f80
/* 76608 800DD158 44810000 */  mtc1      $at, $f0
/* 7660C 800DD15C 27A20038 */  addiu     $v0, $sp, 0x38
/* 76610 800DD160 E7A20044 */  swc1      $f2, 0x44($sp)
/* 76614 800DD164 AFA20018 */  sw        $v0, 0x18($sp)
/* 76618 800DD168 27A2003C */  addiu     $v0, $sp, 0x3c
/* 7661C 800DD16C AFA2001C */  sw        $v0, 0x1c($sp)
/* 76620 800DD170 27A20040 */  addiu     $v0, $sp, 0x40
/* 76624 800DD174 AFA20020 */  sw        $v0, 0x20($sp)
/* 76628 800DD178 27A20044 */  addiu     $v0, $sp, 0x44
/* 7662C 800DD17C AFA20024 */  sw        $v0, 0x24($sp)
/* 76630 800DD180 27A20048 */  addiu     $v0, $sp, 0x48
/* 76634 800DD184 AFA20028 */  sw        $v0, 0x28($sp)
/* 76638 800DD188 27A2004C */  addiu     $v0, $sp, 0x4c
/* 7663C 800DD18C AFA2002C */  sw        $v0, 0x2c($sp)
/* 76640 800DD190 27A20050 */  addiu     $v0, $sp, 0x50
/* 76644 800DD194 E7A00010 */  swc1      $f0, 0x10($sp)
/* 76648 800DD198 E7A40014 */  swc1      $f4, 0x14($sp)
/* 7664C 800DD19C AFA20030 */  sw        $v0, 0x30($sp)
/* 76650 800DD1A0 8E860000 */  lw        $a2, ($s4)
/* 76654 800DD1A4 44072000 */  mfc1      $a3, $f4
/* 76658 800DD1A8 C64C0000 */  lwc1      $f12, ($s2)
/* 7665C 800DD1AC C66E0000 */  lwc1      $f14, ($s3)
/* 76660 800DD1B0 0C017512 */  jal       test_ray_entities
/* 76664 800DD1B4 4600F506 */   mov.s    $f20, $f30
/* 76668 800DD1B8 0442000D */  bltzl     $v0, .L800DD1F0
/* 7666C 800DD1BC 0200102D */   daddu    $v0, $s0, $zero
/* 76670 800DD1C0 C6200000 */  lwc1      $f0, ($s1)
/* 76674 800DD1C4 C7A20044 */  lwc1      $f2, 0x44($sp)
/* 76678 800DD1C8 4600103C */  c.lt.s    $f2, $f0
/* 7667C 800DD1CC 00000000 */  nop
/* 76680 800DD1D0 45020007 */  bc1fl     .L800DD1F0
/* 76684 800DD1D4 0200102D */   daddu    $v0, $s0, $zero
/* 76688 800DD1D8 34504000 */  ori       $s0, $v0, 0x4000
/* 7668C 800DD1DC E6220000 */  swc1      $f2, ($s1)
/* 76690 800DD1E0 E6580000 */  swc1      $f24, ($s2)
/* 76694 800DD1E4 E6760000 */  swc1      $f22, ($s3)
/* 76698 800DD1E8 E6940000 */  swc1      $f20, ($s4)
/* 7669C 800DD1EC 0200102D */  daddu     $v0, $s0, $zero
.L800DD1F0:
/* 766A0 800DD1F0 8FBF006C */  lw        $ra, 0x6c($sp)
/* 766A4 800DD1F4 8FB40068 */  lw        $s4, 0x68($sp)
/* 766A8 800DD1F8 8FB30064 */  lw        $s3, 0x64($sp)
/* 766AC 800DD1FC 8FB20060 */  lw        $s2, 0x60($sp)
/* 766B0 800DD200 8FB1005C */  lw        $s1, 0x5c($sp)
/* 766B4 800DD204 8FB00058 */  lw        $s0, 0x58($sp)
/* 766B8 800DD208 D7BE0098 */  ldc1      $f30, 0x98($sp)
/* 766BC 800DD20C D7BC0090 */  ldc1      $f28, 0x90($sp)
/* 766C0 800DD210 D7BA0088 */  ldc1      $f26, 0x88($sp)
/* 766C4 800DD214 D7B80080 */  ldc1      $f24, 0x80($sp)
/* 766C8 800DD218 D7B60078 */  ldc1      $f22, 0x78($sp)
/* 766CC 800DD21C D7B40070 */  ldc1      $f20, 0x70($sp)
/* 766D0 800DD220 03E00008 */  jr        $ra
/* 766D4 800DD224 27BD00A0 */   addiu    $sp, $sp, 0xa0
