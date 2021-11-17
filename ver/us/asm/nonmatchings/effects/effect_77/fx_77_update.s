.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_77_update
/* 3966F0 E009A140 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 3966F4 E009A144 AFBF0020 */  sw        $ra, 0x20($sp)
/* 3966F8 E009A148 AFB1001C */  sw        $s1, 0x1c($sp)
/* 3966FC E009A14C AFB00018 */  sw        $s0, 0x18($sp)
/* 396700 E009A150 F7B40028 */  sdc1      $f20, 0x28($sp)
/* 396704 E009A154 8C91000C */  lw        $s1, 0xc($a0)
/* 396708 E009A158 8E220040 */  lw        $v0, 0x40($s1)
/* 39670C E009A15C 2442FFFF */  addiu     $v0, $v0, -1
/* 396710 E009A160 AE220040 */  sw        $v0, 0x40($s1)
/* 396714 E009A164 8E220044 */  lw        $v0, 0x44($s1)
/* 396718 E009A168 8E230040 */  lw        $v1, 0x40($s1)
/* 39671C E009A16C 24420001 */  addiu     $v0, $v0, 1
/* 396720 E009A170 04610005 */  bgez      $v1, .LE009A188
/* 396724 E009A174 AE220044 */   sw       $v0, 0x44($s1)
/* 396728 E009A178 0C080128 */  jal       shim_remove_effect
/* 39672C E009A17C 00000000 */   nop
/* 396730 E009A180 080268E0 */  j         .LE009A380
/* 396734 E009A184 00000000 */   nop
.LE009A188:
/* 396738 E009A188 8E24002C */  lw        $a0, 0x2c($s1)
/* 39673C E009A18C 2C820006 */  sltiu     $v0, $a0, 6
/* 396740 E009A190 1040007B */  beqz      $v0, .LE009A380
/* 396744 E009A194 00041080 */   sll      $v0, $a0, 2
/* 396748 E009A198 3C01E00A */  lui       $at, %hi(jtbl_E009AA60)
/* 39674C E009A19C 00220821 */  addu      $at, $at, $v0
/* 396750 E009A1A0 8C22AA60 */  lw        $v0, %lo(jtbl_E009AA60)($at)
/* 396754 E009A1A4 00400008 */  jr        $v0
/* 396758 E009A1A8 00000000 */   nop
dlabel LE009A1AC_39675C
/* 39675C E009A1AC 8E23003C */  lw        $v1, 0x3c($s1)
/* 396760 E009A1B0 8E220020 */  lw        $v0, 0x20($s1)
/* 396764 E009A1B4 C6200028 */  lwc1      $f0, 0x28($s1)
/* 396768 E009A1B8 00431023 */  subu      $v0, $v0, $v1
/* 39676C E009A1BC 44822000 */  mtc1      $v0, $f4
/* 396770 E009A1C0 00000000 */  nop
/* 396774 E009A1C4 46802120 */  cvt.s.w   $f4, $f4
/* 396778 E009A1C8 46002102 */  mul.s     $f4, $f4, $f0
/* 39677C E009A1CC 00000000 */  nop
/* 396780 E009A1D0 C6220018 */  lwc1      $f2, 0x18($s1)
/* 396784 E009A1D4 C6260024 */  lwc1      $f6, 0x24($s1)
/* 396788 E009A1D8 46061081 */  sub.s     $f2, $f2, $f6
/* 39678C E009A1DC 46001082 */  mul.s     $f2, $f2, $f0
/* 396790 E009A1E0 00000000 */  nop
/* 396794 E009A1E4 C6200034 */  lwc1      $f0, 0x34($s1)
/* 396798 E009A1E8 46023180 */  add.s     $f6, $f6, $f2
/* 39679C E009A1EC 3C01E00A */  lui       $at, %hi(D_E009AA78)
/* 3967A0 E009A1F0 D422AA78 */  ldc1      $f2, %lo(D_E009AA78)($at)
/* 3967A4 E009A1F4 46000021 */  cvt.d.s   $f0, $f0
/* 3967A8 E009A1F8 46220001 */  sub.d     $f0, $f0, $f2
/* 3967AC E009A1FC 44804000 */  mtc1      $zero, $f8
/* 3967B0 E009A200 44831000 */  mtc1      $v1, $f2
/* 3967B4 E009A204 00000000 */  nop
/* 3967B8 E009A208 468010A0 */  cvt.s.w   $f2, $f2
/* 3967BC E009A20C 46041080 */  add.s     $f2, $f2, $f4
/* 3967C0 E009A210 E6260024 */  swc1      $f6, 0x24($s1)
/* 3967C4 E009A214 46200020 */  cvt.s.d   $f0, $f0
/* 3967C8 E009A218 4600128D */  trunc.w.s $f10, $f2
/* 3967CC E009A21C E62A003C */  swc1      $f10, 0x3c($s1)
/* 3967D0 E009A220 4608003C */  c.lt.s    $f0, $f8
/* 3967D4 E009A224 00000000 */  nop
/* 3967D8 E009A228 45000055 */  bc1f      .LE009A380
/* 3967DC E009A22C E6200034 */   swc1     $f0, 0x34($s1)
/* 3967E0 E009A230 2402000A */  addiu     $v0, $zero, 0xa
/* 3967E4 E009A234 AE220030 */  sw        $v0, 0x30($s1)
/* 3967E8 E009A238 24020001 */  addiu     $v0, $zero, 1
/* 3967EC E009A23C E6280034 */  swc1      $f8, 0x34($s1)
/* 3967F0 E009A240 E6280010 */  swc1      $f8, 0x10($s1)
/* 3967F4 E009A244 080268E0 */  j         .LE009A380
/* 3967F8 E009A248 AE22002C */   sw       $v0, 0x2c($s1)
dlabel LE009A24C_3967FC
/* 3967FC E009A24C 8E220030 */  lw        $v0, 0x30($s1)
/* 396800 E009A250 2442FFFF */  addiu     $v0, $v0, -1
/* 396804 E009A254 1C40004A */  bgtz      $v0, .LE009A380
/* 396808 E009A258 AE220030 */   sw       $v0, 0x30($s1)
/* 39680C E009A25C 24020002 */  addiu     $v0, $zero, 2
/* 396810 E009A260 AE22002C */  sw        $v0, 0x2c($s1)
/* 396814 E009A264 2402000A */  addiu     $v0, $zero, 0xa
/* 396818 E009A268 080268E0 */  j         .LE009A380
/* 39681C E009A26C AE220030 */   sw       $v0, 0x30($s1)
dlabel LE009A270_396820
/* 396820 E009A270 8E220030 */  lw        $v0, 0x30($s1)
/* 396824 E009A274 2442FFFF */  addiu     $v0, $v0, -1
/* 396828 E009A278 1C400041 */  bgtz      $v0, .LE009A380
/* 39682C E009A27C AE220030 */   sw       $v0, 0x30($s1)
/* 396830 E009A280 24020003 */  addiu     $v0, $zero, 3
/* 396834 E009A284 080268E0 */  j         .LE009A380
/* 396838 E009A288 AE22002C */   sw       $v0, 0x2c($s1)
dlabel LE009A28C_39683C
/* 39683C E009A28C C6200010 */  lwc1      $f0, 0x10($s1)
/* 396840 E009A290 3C013F80 */  lui       $at, 0x3f80
/* 396844 E009A294 44811000 */  mtc1      $at, $f2
/* 396848 E009A298 00000000 */  nop
/* 39684C E009A29C 46020001 */  sub.s     $f0, $f0, $f2
/* 396850 E009A2A0 C6220008 */  lwc1      $f2, 8($s1)
/* 396854 E009A2A4 44802000 */  mtc1      $zero, $f4
/* 396858 E009A2A8 46001080 */  add.s     $f2, $f2, $f0
/* 39685C E009A2AC E6200010 */  swc1      $f0, 0x10($s1)
/* 396860 E009A2B0 4604103C */  c.lt.s    $f2, $f4
/* 396864 E009A2B4 00000000 */  nop
/* 396868 E009A2B8 45000031 */  bc1f      .LE009A380
/* 39686C E009A2BC E6220008 */   swc1     $f2, 8($s1)
/* 396870 E009A2C0 24040015 */  addiu     $a0, $zero, 0x15
/* 396874 E009A2C4 0C080150 */  jal       shim_load_effect
/* 396878 E009A2C8 E6240008 */   swc1     $f4, 8($s1)
/* 39687C E009A2CC C6200004 */  lwc1      $f0, 4($s1)
/* 396880 E009A2D0 3C0140A0 */  lui       $at, 0x40a0
/* 396884 E009A2D4 4481A000 */  mtc1      $at, $f20
/* 396888 E009A2D8 2410001E */  addiu     $s0, $zero, 0x1e
/* 39688C E009A2DC AFB00010 */  sw        $s0, 0x10($sp)
/* 396890 E009A2E0 46140000 */  add.s     $f0, $f0, $f20
/* 396894 E009A2E4 8E260008 */  lw        $a2, 8($s1)
/* 396898 E009A2E8 8E27000C */  lw        $a3, 0xc($s1)
/* 39689C E009A2EC 44050000 */  mfc1      $a1, $f0
/* 3968A0 E009A2F0 0C00A800 */  jal       fx_21_main
/* 3968A4 E009A2F4 24040002 */   addiu    $a0, $zero, 2
/* 3968A8 E009A2F8 C6200004 */  lwc1      $f0, 4($s1)
/* 3968AC E009A2FC AFB00010 */  sw        $s0, 0x10($sp)
/* 3968B0 E009A300 46140001 */  sub.s     $f0, $f0, $f20
/* 3968B4 E009A304 8E260008 */  lw        $a2, 8($s1)
/* 3968B8 E009A308 8E27000C */  lw        $a3, 0xc($s1)
/* 3968BC E009A30C 44050000 */  mfc1      $a1, $f0
/* 3968C0 E009A310 0C00A800 */  jal       fx_21_main
/* 3968C4 E009A314 24040002 */   addiu    $a0, $zero, 2
/* 3968C8 E009A318 24020004 */  addiu     $v0, $zero, 4
/* 3968CC E009A31C AE22002C */  sw        $v0, 0x2c($s1)
/* 3968D0 E009A320 24020014 */  addiu     $v0, $zero, 0x14
/* 3968D4 E009A324 080268E0 */  j         .LE009A380
/* 3968D8 E009A328 AE220030 */   sw       $v0, 0x30($s1)
dlabel LE009A32C_3968DC
/* 3968DC E009A32C 8E220030 */  lw        $v0, 0x30($s1)
/* 3968E0 E009A330 2442FFFF */  addiu     $v0, $v0, -1
/* 3968E4 E009A334 1C400012 */  bgtz      $v0, .LE009A380
/* 3968E8 E009A338 AE220030 */   sw       $v0, 0x30($s1)
/* 3968EC E009A33C 24020005 */  addiu     $v0, $zero, 5
/* 3968F0 E009A340 080268E0 */  j         .LE009A380
/* 3968F4 E009A344 AE22002C */   sw       $v0, 0x2c($s1)
dlabel LE009A348_3968F8
/* 3968F8 E009A348 2862000A */  slti      $v0, $v1, 0xa
/* 3968FC E009A34C 10400005 */  beqz      $v0, .LE009A364
/* 396900 E009A350 00031040 */   sll      $v0, $v1, 1
/* 396904 E009A354 00431021 */  addu      $v0, $v0, $v1
/* 396908 E009A358 000210C0 */  sll       $v0, $v0, 3
/* 39690C E009A35C 00431021 */  addu      $v0, $v0, $v1
/* 396910 E009A360 AE22003C */  sw        $v0, 0x3c($s1)
.LE009A364:
/* 396914 E009A364 C6200034 */  lwc1      $f0, 0x34($s1)
/* 396918 E009A368 3C01E00A */  lui       $at, %hi(D_E009AA80)
/* 39691C E009A36C D422AA80 */  ldc1      $f2, %lo(D_E009AA80)($at)
/* 396920 E009A370 46000021 */  cvt.d.s   $f0, $f0
/* 396924 E009A374 46220001 */  sub.d     $f0, $f0, $f2
/* 396928 E009A378 46200020 */  cvt.s.d   $f0, $f0
/* 39692C E009A37C E6200034 */  swc1      $f0, 0x34($s1)
.LE009A380:
/* 396930 E009A380 8FBF0020 */  lw        $ra, 0x20($sp)
/* 396934 E009A384 8FB1001C */  lw        $s1, 0x1c($sp)
/* 396938 E009A388 8FB00018 */  lw        $s0, 0x18($sp)
/* 39693C E009A38C D7B40028 */  ldc1      $f20, 0x28($sp)
/* 396940 E009A390 03E00008 */  jr        $ra
/* 396944 E009A394 27BD0030 */   addiu    $sp, $sp, 0x30
