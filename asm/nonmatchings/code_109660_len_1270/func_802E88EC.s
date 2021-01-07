.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E88EC
/* 10A16C 802E88EC 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 10A170 802E88F0 AFB20028 */  sw        $s2, 0x28($sp)
/* 10A174 802E88F4 0080902D */  daddu     $s2, $a0, $zero
/* 10A178 802E88F8 AFBF002C */  sw        $ra, 0x2c($sp)
/* 10A17C 802E88FC AFB10024 */  sw        $s1, 0x24($sp)
/* 10A180 802E8900 AFB00020 */  sw        $s0, 0x20($sp)
/* 10A184 802E8904 8E510040 */  lw        $s1, 0x40($s2)
/* 10A188 802E8908 8E230000 */  lw        $v1, ($s1)
/* 10A18C 802E890C 2402FFFF */  addiu     $v0, $zero, -1
/* 10A190 802E8910 10620021 */  beq       $v1, $v0, .L802E8998
/* 10A194 802E8914 3402FFFF */   ori      $v0, $zero, 0xffff
/* 10A198 802E8918 96230004 */  lhu       $v1, 4($s1)
/* 10A19C 802E891C 10620006 */  beq       $v1, $v0, .L802E8938
/* 10A1A0 802E8920 0000802D */   daddu    $s0, $zero, $zero
/* 10A1A4 802E8924 96240004 */  lhu       $a0, 4($s1)
/* 10A1A8 802E8928 0C05152F */  jal       get_global_flag
/* 10A1AC 802E892C 00000000 */   nop      
/* 10A1B0 802E8930 14400002 */  bnez      $v0, .L802E893C
/* 10A1B4 802E8934 00000000 */   nop      
.L802E8938:
/* 10A1B8 802E8938 24100001 */  addiu     $s0, $zero, 1
.L802E893C:
/* 10A1BC 802E893C 12000016 */  beqz      $s0, .L802E8998
/* 10A1C0 802E8940 00000000 */   nop      
/* 10A1C4 802E8944 0C03951B */  jal       func_800E546C
/* 10A1C8 802E8948 00000000 */   nop      
/* 10A1CC 802E894C C642004C */  lwc1      $f2, 0x4c($s2)
/* 10A1D0 802E8950 4600010D */  trunc.w.s $f4, $f0
/* 10A1D4 802E8954 E7A40018 */  swc1      $f4, 0x18($sp)
/* 10A1D8 802E8958 2402000A */  addiu     $v0, $zero, 0xa
/* 10A1DC 802E895C AFA20010 */  sw        $v0, 0x10($sp)
/* 10A1E0 802E8960 AFA00014 */  sw        $zero, 0x14($sp)
/* 10A1E4 802E8964 96220004 */  lhu       $v0, 4($s1)
/* 10A1E8 802E8968 3C01802F */  lui       $at, %hi(D_802EB370)
/* 10A1EC 802E896C D420B370 */  ldc1      $f0, %lo(D_802EB370)($at)
/* 10A1F0 802E8970 460010A1 */  cvt.d.s   $f2, $f2
/* 10A1F4 802E8974 46201080 */  add.d     $f2, $f2, $f0
/* 10A1F8 802E8978 AFA2001C */  sw        $v0, 0x1c($sp)
/* 10A1FC 802E897C 8E240000 */  lw        $a0, ($s1)
/* 10A200 802E8980 8E450048 */  lw        $a1, 0x48($s2)
/* 10A204 802E8984 8E470050 */  lw        $a3, 0x50($s2)
/* 10A208 802E8988 462010A0 */  cvt.s.d   $f2, $f2
/* 10A20C 802E898C 44061000 */  mfc1      $a2, $f2
/* 10A210 802E8990 0C04C4FD */  jal       make_item_entity
/* 10A214 802E8994 00000000 */   nop      
.L802E8998:
/* 10A218 802E8998 8FBF002C */  lw        $ra, 0x2c($sp)
/* 10A21C 802E899C 8FB20028 */  lw        $s2, 0x28($sp)
/* 10A220 802E89A0 8FB10024 */  lw        $s1, 0x24($sp)
/* 10A224 802E89A4 8FB00020 */  lw        $s0, 0x20($sp)
/* 10A228 802E89A8 03E00008 */  jr        $ra
/* 10A22C 802E89AC 27BD0030 */   addiu    $sp, $sp, 0x30
