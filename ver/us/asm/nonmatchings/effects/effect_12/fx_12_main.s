.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_12_main
/* 32F5F8 E0018078 27BDFF90 */  addiu     $sp, $sp, -0x70
/* 32F5FC E001807C F7BC0060 */  sdc1      $f28, 0x60($sp)
/* 32F600 E0018080 4487E000 */  mtc1      $a3, $f28
/* 32F604 E0018084 27A40010 */  addiu     $a0, $sp, 0x10
/* 32F608 E0018088 F7BE0068 */  sdc1      $f30, 0x68($sp)
/* 32F60C E001808C C7BE0080 */  lwc1      $f30, 0x80($sp)
/* 32F610 E0018090 3C02E002 */  lui       $v0, %hi(func_E00182AC)
/* 32F614 E0018094 244282AC */  addiu     $v0, $v0, %lo(func_E00182AC)
/* 32F618 E0018098 AFA20018 */  sw        $v0, 0x18($sp)
/* 32F61C E001809C 3C02E002 */  lui       $v0, %hi(func_E00182B4)
/* 32F620 E00180A0 244282B4 */  addiu     $v0, $v0, %lo(func_E00182B4)
/* 32F624 E00180A4 AFA2001C */  sw        $v0, 0x1c($sp)
/* 32F628 E00180A8 3C02E002 */  lui       $v0, %hi(func_E0018378)
/* 32F62C E00180AC 24428378 */  addiu     $v0, $v0, %lo(func_E0018378)
/* 32F630 E00180B0 AFA20020 */  sw        $v0, 0x20($sp)
/* 32F634 E00180B4 2402000C */  addiu     $v0, $zero, 0xc
/* 32F638 E00180B8 AFBF0038 */  sw        $ra, 0x38($sp)
/* 32F63C E00180BC AFB30034 */  sw        $s3, 0x34($sp)
/* 32F640 E00180C0 AFB20030 */  sw        $s2, 0x30($sp)
/* 32F644 E00180C4 AFB1002C */  sw        $s1, 0x2c($sp)
/* 32F648 E00180C8 AFB00028 */  sw        $s0, 0x28($sp)
/* 32F64C E00180CC F7BA0058 */  sdc1      $f26, 0x58($sp)
/* 32F650 E00180D0 F7B80050 */  sdc1      $f24, 0x50($sp)
/* 32F654 E00180D4 F7B60048 */  sdc1      $f22, 0x48($sp)
/* 32F658 E00180D8 F7B40040 */  sdc1      $f20, 0x40($sp)
/* 32F65C E00180DC E7AC0070 */  swc1      $f12, 0x70($sp)
/* 32F660 E00180E0 E7AE0074 */  swc1      $f14, 0x74($sp)
/* 32F664 E00180E4 AFA60078 */  sw        $a2, 0x78($sp)
/* 32F668 E00180E8 AFA00010 */  sw        $zero, 0x10($sp)
/* 32F66C E00180EC AFA00024 */  sw        $zero, 0x24($sp)
/* 32F670 E00180F0 0C080124 */  jal       shim_create_effect_instance
/* 32F674 E00180F4 AFA20014 */   sw       $v0, 0x14($sp)
/* 32F678 E00180F8 24040098 */  addiu     $a0, $zero, 0x98
/* 32F67C E00180FC 24130001 */  addiu     $s3, $zero, 1
/* 32F680 E0018100 0040802D */  daddu     $s0, $v0, $zero
/* 32F684 E0018104 0C08012C */  jal       shim_general_heap_malloc
/* 32F688 E0018108 AE130008 */   sw       $s3, 8($s0)
/* 32F68C E001810C 0040882D */  daddu     $s1, $v0, $zero
/* 32F690 E0018110 16200003 */  bnez      $s1, .LE0018120
/* 32F694 E0018114 AE11000C */   sw       $s1, 0xc($s0)
.LE0018118:
/* 32F698 E0018118 08006046 */  j         .LE0018118
/* 32F69C E001811C 00000000 */   nop
.LE0018120:
/* 32F6A0 E0018120 0220202D */  daddu     $a0, $s1, $zero
/* 32F6A4 E0018124 00132880 */  sll       $a1, $s3, 2
/* 32F6A8 E0018128 00B32821 */  addu      $a1, $a1, $s3
/* 32F6AC E001812C 00052880 */  sll       $a1, $a1, 2
/* 32F6B0 E0018130 00B32823 */  subu      $a1, $a1, $s3
/* 32F6B4 E0018134 0C080130 */  jal       shim_mem_clear
/* 32F6B8 E0018138 000528C0 */   sll      $a1, $a1, 3
/* 32F6BC E001813C 0000902D */  daddu     $s2, $zero, $zero
/* 32F6C0 E0018140 0253102A */  slt       $v0, $s2, $s3
/* 32F6C4 E0018144 1040004C */  beqz      $v0, .LE0018278
/* 32F6C8 E0018148 26300008 */   addiu    $s0, $s1, 8
/* 32F6CC E001814C 3C0141F0 */  lui       $at, 0x41f0
/* 32F6D0 E0018150 44810000 */  mtc1      $at, $f0
/* 32F6D4 E0018154 00000000 */  nop
/* 32F6D8 E0018158 4600F002 */  mul.s     $f0, $f30, $f0
/* 32F6DC E001815C 00000000 */  nop
/* 32F6E0 E0018160 3C013F80 */  lui       $at, 0x3f80
/* 32F6E4 E0018164 4481B000 */  mtc1      $at, $f22
/* 32F6E8 E0018168 4600E000 */  add.s     $f0, $f28, $f0
/* 32F6EC E001816C 3C014170 */  lui       $at, 0x4170
/* 32F6F0 E0018170 44811000 */  mtc1      $at, $f2
/* 32F6F4 E0018174 3C0140A0 */  lui       $at, 0x40a0
/* 32F6F8 E0018178 4481C000 */  mtc1      $at, $f24
/* 32F6FC E001817C 46020681 */  sub.s     $f26, $f0, $f2
.LE0018180:
/* 32F700 E0018180 24020001 */  addiu     $v0, $zero, 1
/* 32F704 E0018184 AE220000 */  sw        $v0, ($s1)
/* 32F708 E0018188 AE000074 */  sw        $zero, 0x74($s0)
/* 32F70C E001818C C7A60070 */  lwc1      $f6, 0x70($sp)
/* 32F710 E0018190 E6060004 */  swc1      $f6, 4($s0)
/* 32F714 E0018194 C7A60074 */  lwc1      $f6, 0x74($sp)
/* 32F718 E0018198 4600E306 */  mov.s     $f12, $f28
/* 32F71C E001819C E6060008 */  swc1      $f6, 8($s0)
/* 32F720 E00181A0 C7A60078 */  lwc1      $f6, 0x78($sp)
/* 32F724 E00181A4 240200FF */  addiu     $v0, $zero, 0xff
/* 32F728 E00181A8 A2020000 */  sb        $v0, ($s0)
/* 32F72C E00181AC 24020064 */  addiu     $v0, $zero, 0x64
/* 32F730 E00181B0 E6160010 */  swc1      $f22, 0x10($s0)
/* 32F734 E00181B4 E6160014 */  swc1      $f22, 0x14($s0)
/* 32F738 E00181B8 E6160018 */  swc1      $f22, 0x18($s0)
/* 32F73C E00181BC AE000068 */  sw        $zero, 0x68($s0)
/* 32F740 E00181C0 AE000078 */  sw        $zero, 0x78($s0)
/* 32F744 E00181C4 AE00007C */  sw        $zero, 0x7c($s0)
/* 32F748 E00181C8 A602FFFE */  sh        $v0, -2($s0)
/* 32F74C E00181CC AE00001C */  sw        $zero, 0x1c($s0)
/* 32F750 E00181D0 E61A0020 */  swc1      $f26, 0x20($s0)
/* 32F754 E00181D4 AE000024 */  sw        $zero, 0x24($s0)
/* 32F758 E00181D8 0C08013C */  jal       shim_clamp_angle
/* 32F75C E00181DC E606000C */   swc1     $f6, 0xc($s0)
/* 32F760 E00181E0 46000506 */  mov.s     $f20, $f0
/* 32F764 E00181E4 0C080140 */  jal       shim_sin_deg
/* 32F768 E00181E8 4600A306 */   mov.s    $f12, $f20
/* 32F76C E00181EC 4600A306 */  mov.s     $f12, $f20
/* 32F770 E00181F0 0C080144 */  jal       shim_cos_deg
/* 32F774 E00181F4 E6000088 */   swc1     $f0, 0x88($s0)
/* 32F778 E00181F8 3C014334 */  lui       $at, 0x4334
/* 32F77C E00181FC 44812000 */  mtc1      $at, $f4
/* 32F780 E0018200 00000000 */  nop
/* 32F784 E0018204 4604F102 */  mul.s     $f4, $f30, $f4
/* 32F788 E0018208 00000000 */  nop
/* 32F78C E001820C 3C014234 */  lui       $at, 0x4234
/* 32F790 E0018210 44811000 */  mtc1      $at, $f2
/* 32F794 E0018214 00000000 */  nop
/* 32F798 E0018218 4602A500 */  add.s     $f20, $f20, $f2
/* 32F79C E001821C 4604A501 */  sub.s     $f20, $f20, $f4
/* 32F7A0 E0018220 E600008C */  swc1      $f0, 0x8c($s0)
/* 32F7A4 E0018224 0C080140 */  jal       shim_sin_deg
/* 32F7A8 E0018228 4600A306 */   mov.s    $f12, $f20
/* 32F7AC E001822C 46180002 */  mul.s     $f0, $f0, $f24
/* 32F7B0 E0018230 00000000 */  nop
/* 32F7B4 E0018234 C6020004 */  lwc1      $f2, 4($s0)
/* 32F7B8 E0018238 46001080 */  add.s     $f2, $f2, $f0
/* 32F7BC E001823C 4600A306 */  mov.s     $f12, $f20
/* 32F7C0 E0018240 0C080144 */  jal       shim_cos_deg
/* 32F7C4 E0018244 E6020004 */   swc1     $f2, 4($s0)
/* 32F7C8 E0018248 46180002 */  mul.s     $f0, $f0, $f24
/* 32F7CC E001824C 00000000 */  nop
/* 32F7D0 E0018250 26520001 */  addiu     $s2, $s2, 1
/* 32F7D4 E0018254 26310098 */  addiu     $s1, $s1, 0x98
/* 32F7D8 E0018258 C602000C */  lwc1      $f2, 0xc($s0)
/* 32F7DC E001825C 240200C8 */  addiu     $v0, $zero, 0xc8
/* 32F7E0 E0018260 46001080 */  add.s     $f2, $f2, $f0
/* 32F7E4 E0018264 A2020000 */  sb        $v0, ($s0)
/* 32F7E8 E0018268 0253102A */  slt       $v0, $s2, $s3
/* 32F7EC E001826C E602000C */  swc1      $f2, 0xc($s0)
/* 32F7F0 E0018270 1440FFC3 */  bnez      $v0, .LE0018180
/* 32F7F4 E0018274 26100098 */   addiu    $s0, $s0, 0x98
.LE0018278:
/* 32F7F8 E0018278 8FBF0038 */  lw        $ra, 0x38($sp)
/* 32F7FC E001827C 8FB30034 */  lw        $s3, 0x34($sp)
/* 32F800 E0018280 8FB20030 */  lw        $s2, 0x30($sp)
/* 32F804 E0018284 8FB1002C */  lw        $s1, 0x2c($sp)
/* 32F808 E0018288 8FB00028 */  lw        $s0, 0x28($sp)
/* 32F80C E001828C D7BE0068 */  ldc1      $f30, 0x68($sp)
/* 32F810 E0018290 D7BC0060 */  ldc1      $f28, 0x60($sp)
/* 32F814 E0018294 D7BA0058 */  ldc1      $f26, 0x58($sp)
/* 32F818 E0018298 D7B80050 */  ldc1      $f24, 0x50($sp)
/* 32F81C E001829C D7B60048 */  ldc1      $f22, 0x48($sp)
/* 32F820 E00182A0 D7B40040 */  ldc1      $f20, 0x40($sp)
/* 32F824 E00182A4 03E00008 */  jr        $ra
/* 32F828 E00182A8 27BD0070 */   addiu    $sp, $sp, 0x70
